package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.types.BType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;

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

    public SetComprehensionGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator,
                                     final TypeGenerator typeGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.typeGenerator = typeGenerator;
    }

    public String generateSetComprehension(SetComprehensionNode node) {
        machineGenerator.inIterationConstruct();
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        BType type = node.getType();

        ST template = group.getInstanceOf("set_comprehension");
        generateOtherIterationConstructs(template, predicate);

        iterationConstructGenerator.prepareGeneration(predicate, declarations, type);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_set_" + iterationConstructCounter;
        boolean isRelation = node.getDeclarationList().size() > 1;
        generateBody(template, identifier, isRelation, predicate, declarations, type);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    private String generateSetComprehensionPredicate(PredicateNode predicateNode, String type, String setName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("set_comprehension_predicate");
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "type", type);
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "isRelation", iterationConstructGenerator.getBoundedVariables().size() > 1);
        TemplateHandler.add(template, "element", elementName);
        return template.render();
    }

    private void generateOtherIterationConstructs(ST template, PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
    }

    private void generateBody(ST template, String identifier, boolean isRelation, PredicateNode predicate, List<DeclarationNode> declarations, BType type) {
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String elementName = getElementFromBoundedVariables(declarations);

        String generatedType = typeGenerator.generate(type);

        String innerBody = generateSetComprehensionPredicate(predicate, generatedType, identifier, elementName);
        String comprehension = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "type", generatedType);
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "isRelation", isRelation);
        TemplateHandler.add(template, "comprehension", comprehension);
    }

    private String getElementFromBoundedVariables(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            return "_ic_" + declarations.get(declarations.size() - 1).getName();
        } else {
            ST firstCouple = group.getInstanceOf("couple_create");
            DeclarationNode left = declarations.get(0);
            DeclarationNode right = declarations.get(1);
            TemplateHandler.add(firstCouple, "leftType", typeGenerator.generate(left.getType()));
            TemplateHandler.add(firstCouple, "rightType", typeGenerator.generate(right.getType()));
            TemplateHandler.add(firstCouple, "arg1", "_ic_" + left.getName());
            TemplateHandler.add(firstCouple, "arg2", "_ic_" + right.getName());
            return declarations.subList(2, declarations.size()).stream()
                    .map(DeclarationNode::getName)
                    .reduce(firstCouple.render(), (a,e) -> {
                        //TODO: implement type placeholder for C++
                        ST couple = group.getInstanceOf("couple_create");
                        TemplateHandler.add(couple, "arg1", a);
                        TemplateHandler.add(couple, "arg2", "_ic_" + e);
                        return couple.render();
                    });
        }
    }

}
