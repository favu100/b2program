package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * Created by fabian on 18.04.21.
 */
public class TransitionIterationGenerator {

    private final STGroup group;

    private final NameHandler nameHandler;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;


    public TransitionIterationGenerator(final STGroup group, final NameHandler nameHandler, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                        final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.nameHandler = nameHandler;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    /*
    * This function generates code for evaluating transitions from the belonging AST node
    */
    public String generateTransition(PredicateNode conditionalPredicate, OperationNode node, List<DeclarationNode> declarations, PredicateNode predicate) {
        ST template = group.getInstanceOf("transition");
        boolean noParameters = declarations.size() == 0;
        TemplateHandler.add(template, "noParameters", noParameters);
        TemplateHandler.add(template, "operationName", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES));

        if(noParameters) {
            if(predicate == null) {
                TemplateHandler.add(template,"noPredicate", true);
            } else {
                TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicate, null));
            }
            String result = template.render();
            iterationConstructGenerator.addGeneration(node.toString(), declarations, result);
            return result;
        } else {
            machineGenerator.inIterationConstruct(declarations);
            int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
            String identifier = "_ic_set_" + iterationConstructCounter;

            iterationConstructGenerator.prepareGeneration(predicate, declarations, false);
            List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, false);
            Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

            generateBody(template, otherConstructs, enumerationTemplates, conditionalPredicate, predicate, node.getName(), identifier, declarations);

            String result = template.render();
            iterationConstructGenerator.addGeneration(node.toString(), declarations, result);
            machineGenerator.leaveIterationConstruct(declarations);
            return result;
        }
    }

    /*
    * This function generates code for the inner body of evaluating transitions
    */
    private String generateTransitionBody(Collection<String> otherConstructs, PredicateNode conditionalPredicate, PredicateNode predicateNode, String setName, String elementName, List<DeclarationNode> declarations) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, declarations, false);
        ST template = group.getInstanceOf("parameter_combination_predicate");
        BType type = extractTypeFromDeclarations(declarations);
        TemplateHandler.add(template, "subType", typeGenerator.generate(type));
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "element", elementName);
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        return template.render();
    }

    /*
    * This function generates code for other iteration constructs within evaluation of transitions from the given predicate
    */
    private Collection<String> generateOtherIterationConstructs(PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.getNewIterationConstructGenerator();
        otherConstructsGenerator.getAllBoundedVariables().addAll(iterationConstructGenerator.getAllBoundedVariables());
        for (String key : iterationConstructGenerator.getIterationsMapIdentifier().keySet()) {
            otherConstructsGenerator.getIterationsMapIdentifier().put(key, iterationConstructGenerator.getIterationsMapIdentifier().get(key));
        }
        iterationConstructHandler.inspectPredicate(otherConstructsGenerator, predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        return otherConstructsGenerator.getIterationsMapCode().values();
    }

    /*
    * This function generates code for the body of evaluating transitions
    */
    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode conditionalPredicate, PredicateNode predicate, String operationName, String setName, List<DeclarationNode> declarations) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String elementName = getElementFromBoundedVariables(declarations);
        String innerBody = generateTransitionBody(otherConstructs, conditionalPredicate, predicate, setName, elementName, declarations);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        generateSubType(template, declarations);
        TemplateHandler.add(template, "isJavaScript", machineGenerator.getMode() == GeneratorMode.JS);
        TemplateHandler.add(template, "identifier", setName);
        TemplateHandler.add(template, "combination", body);
    }

    /*
     * This function generates code for the type of the set comprehension from the given semantic information
     */
    private void generateSubType(ST template, List<DeclarationNode> declarations) {
        BType type = extractTypeFromDeclarations(declarations);
        TemplateHandler.add(template, "subType", typeGenerator.generate(type));
    }

    /*
     * This function extracts the couple type from a list of declarations
     */
    public BType extractTypeFromDeclarations(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            return declarations.get(0).getType();
        }
        CoupleType result = new CoupleType(declarations.get(0).getType(), declarations.get(1).getType());
        for(int i = 2; i < declarations.size(); i++) {
            result = new CoupleType(result, declarations.get(i).getType());
        }
        return result;
    }

    private String getElementFromBoundedVariables(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            String name = declarations.get(0).getName();
            return "_ic_" + name  + "_" + machineGenerator.getBoundedVariablesDepth().get(name);
        } else {
            String result = "";

            BType type = extractTypeFromDeclarations(declarations);
            List<CoupleType> types = new ArrayList<>();

            while(type instanceof CoupleType) {
                types.add(0, (CoupleType) type);
                type = ((CoupleType) type).getLeft();
            }

            for(int i = 0; i < types.size(); i++) {
                ST tuple = group.getInstanceOf("tuple_create");
                BType leftType = types.get(i).getLeft();
                BType rightType = types.get(i).getRight();
                TemplateHandler.add(tuple, "leftType", typeGenerator.generate(leftType));
                TemplateHandler.add(tuple, "rightType", typeGenerator.generate(rightType));
                if(i == 0) {
                    String name = declarations.get(i).getName();
                    TemplateHandler.add(tuple, "arg1", "_ic_" + name + "_" + machineGenerator.getBoundedVariablesDepth().get(name));
                } else {
                    TemplateHandler.add(tuple, "arg1", result);
                }
                String name = declarations.get(i+1).getName();
                TemplateHandler.add(tuple, "arg2", "_ic_" + name  + "_" + machineGenerator.getBoundedVariablesDepth().get(name));
                result = tuple.render();
            }
            return result;
        }
    }

}
