package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.ExpressionGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.PredicateGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Created by fabian on 04.03.19.
 */
public class SetComprehensionGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    private final TypeGenerator typeGenerator;

    private final PredicateGenerator predicateGenerator;

    private final ExpressionGenerator expressionGenerator;

    public SetComprehensionGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator,
                                     final TypeGenerator typeGenerator, final ExpressionGenerator expressionGenerator, final PredicateGenerator predicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.typeGenerator = typeGenerator;
        this.predicateGenerator = predicateGenerator;
        this.expressionGenerator = expressionGenerator;
    }

    /*
    * This function generates code for a set comprehension from the belonging AST node
    */
    public String generateSetComprehension(PredicateNode conditionalPredicate, SetComprehensionNode node) {
        machineGenerator.inIterationConstruct(node.getDeclarationList());
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        BType type = node.getType();

        ST template = group.getInstanceOf("set_comprehension");

        iterationConstructGenerator.prepareGeneration(predicate, declarations, type, false);

        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, false);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_set_" + iterationConstructCounter;
        boolean isRelation = node.getDeclarationList().size() > 1;
        generateBody(template, enumerationTemplates, otherConstructs, identifier, isRelation, conditionalPredicate, predicate, declarations, type);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);

        machineGenerator.leaveIterationConstruct(node.getDeclarationList());
        return result;
    }

    /*
     * This function generates code for a set comprehension by constraint solving from the belonging AST node
     */
    public String generateConstraintSet(SetComprehensionNode node) {
        machineGenerator.inIterationConstruct(node.getDeclarationList());
        List<DeclarationNode> declarations = node.getDeclarationList();

        ST template = group.getInstanceOf("constraint_solving");

        List<ST> declarationTemplates = new ArrayList<>();
        for (DeclarationNode declaration: declarations) {
            declarationTemplates.add(generateConstraintVariableDeclaration(declaration));
        }

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_cs_set_" + iterationConstructCounter;
        String problemIdentifier = "_cs_problem_" + iterationConstructCounter;

        boolean isRelation = node.getDeclarationList().size() > 1;
        //generateBody(template, enumerationTemplates, otherConstructs, identifier, isRelation, predicate, declarations, type);

        template.add("identifier", identifier);
        template.add("isRelation", isRelation);
        template.add("problemIdentifier", problemIdentifier);
        template.add("variableDeclarations", declarationTemplates);
        template.add("constraint", generateConstraint((PredicateOperatorNode) node.getPredicateNode(), declarations));

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);

        machineGenerator.leaveIterationConstruct(node.getDeclarationList());
        return result;
    }

    public ST generateConstraintVariableDeclaration(DeclarationNode declaration) {
        ST range = group.getInstanceOf("constraint_type");
        switch (declaration.getType().toString()){
            case "INTEGER":
                range.add("isInteger", true);
                range.add("minInt", expressionGenerator.generateMinInt());
                range.add("maxInt", expressionGenerator.generateMaxInt());
                break;
            case "BOOL":
                range.add("isBoolean", true);
                break;
            default:
                throw new CodeGenerationException("Type " + declaration.getType().toString() + " not supported for constraint solving!");
        }

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String problemIdentifier = "_cs_problem_" + iterationConstructCounter;

        ST template = group.getInstanceOf("constraint_variable_declaration");
        template.add("identifier", declaration.getName());
        template.add("range", range.render());
        template.add("problemIdentifier", problemIdentifier);
        return template;
    }

    public String generateConstraint(PredicateOperatorNode predicate, List<DeclarationNode> declarations) {
        ST constraint = group.getInstanceOf("constraint");

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String problemIdentifier = "_cs_problem_" + iterationConstructCounter;

        constraint.add("problemIdentifier", problemIdentifier);
        constraint.add("var1", declarations.get(0).getName());
        constraint.add("var2",declarations.subList(1,declarations.size()).stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        constraint.add("constraintFunction", predicateGenerator.visitPredicateOperatorNode(predicate));

        return constraint.render();
    }

    /*
    * This function generates code for the predicate of a set comprehension
    */
    private String generateSetComprehensionPredicate(Collection<String> otherConstructs, PredicateNode conditionalPredicate, PredicateNode predicateNode, String type, String setName, String elementName, List<DeclarationNode> declarations) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, declarations.size(), false);
        ST template = group.getInstanceOf("set_comprehension_predicate");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        TemplateHandler.add(template, "type", type);
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "isRelation", iterationConstructGenerator.getBoundedVariables().size() > 1);
        generateSubType(template, declarations);
        TemplateHandler.add(template, "element", elementName);
        return template.render();
    }

    /*
    * This function generates code for other iteration constructs within a set comprehension
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
    * This function generates code for the body of a set comprehension
    */
    private void generateBody(ST template, List<ST> enumerationTemplates, Collection<String> otherConstructs, String identifier, boolean isRelation, PredicateNode conditionalPredicate, PredicateNode predicate, List<DeclarationNode> declarations, BType type) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String elementName = getElementFromBoundedVariables(declarations);

        String generatedType = typeGenerator.generate(type);

        String innerBody = generateSetComprehensionPredicate(otherConstructs, conditionalPredicate, predicate, generatedType, identifier, elementName, declarations);
        String comprehension = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();
        generateSubType(template, declarations);
        TemplateHandler.add(template, "isJavaScript", machineGenerator.getMode() == GeneratorMode.JS);
        TemplateHandler.add(template, "type", generatedType);
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "isRelation", isRelation);
        TemplateHandler.add(template, "comprehension", comprehension);
    }

    /*
    * This function generates code for the type of the set comprehension from the given semantic information
    */
    private void generateSubType(ST template, List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            DeclarationNode declarationNode = declarations.get(0);
            TemplateHandler.add(template, "subType", typeGenerator.generate(declarationNode.getType()));
        } else {
            CoupleType type = extractTypeFromDeclarations(declarations);
            BType leftType = type.getLeft();
            BType rightType = type.getRight();
            TemplateHandler.add(template, "leftType", typeGenerator.generate(leftType));
            TemplateHandler.add(template, "rightType", typeGenerator.generate(rightType));
        }
    }

    /*
    * This function extracts the couple type from a list of declarations
    */
    private CoupleType extractTypeFromDeclarations(List<DeclarationNode> declarations) {
        CoupleType result = new CoupleType(declarations.get(0).getType(), declarations.get(1).getType());
        for(int i = 2; i < declarations.size(); i++) {
            result = new CoupleType(result, declarations.get(i).getType());
        }
        return result;
    }

    /*
    * This function extracts the resulted element of a set comprehension from the given semantic information
    */
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
                if(i+1 >= types.size()) {
                    continue;
                }
                String name = declarations.get(i+1).getName();
                TemplateHandler.add(tuple, "arg2", "_ic_" + name  + "_" + machineGenerator.getBoundedVariablesDepth().get(name));
                result = tuple.render();
            }
            return result;
        }
    }

}
