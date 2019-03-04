package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
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

    private final ImportGenerator importGenerator;

    private final TypeGenerator typeGenerator;

    public SetComprehensionGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                     final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator, final ImportGenerator importGenerator,
                                     final TypeGenerator typeGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.importGenerator = importGenerator;
        this.typeGenerator = typeGenerator;
    }

    public String generateSetComprehension(SetComprehensionNode node) {
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        iterationConstructGenerator.addBoundedVariables(declarations);
        iterationPredicateGenerator.checkPredicate(predicate, declarations);
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("set_comprehension");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();

        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String elementName = getElementFromBoundedVariables(declarations);
        String innerBody = generateSetComprehensionPredicate(predicate, "_ic_set_" + iterationConstructCounter, elementName);
        String comprehension = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "identifier", "_ic_set_" + iterationConstructCounter);
        TemplateHandler.add(template, "isRelation", node.getDeclarationList().size() > 1);
        TemplateHandler.add(template, "comprehension", comprehension);
        String result = template.render();
        iterationConstructGenerator.addIteration(node.toString(), "_ic_set_"+ iterationConstructCounter, result);
        iterationConstructGenerator.clearBoundedVariables(declarations);
        return result;
    }

    public String generateSetComprehensionPredicate(PredicateNode predicateNode, String setName, String elementName) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("set_comprehension_predicate");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "set", setName);
        TemplateHandler.add(template, "isRelation", iterationConstructGenerator.getBoundedVariables().size() > 1);
        TemplateHandler.add(template, "element", elementName);
        machineGenerator.leaveIterationConstruct();
        return template.render();
    }

    public String getElementFromBoundedVariables(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            return "_ic_" + declarations.get(declarations.size() - 1).getName();
        } else {
            ST firstCouple = group.getInstanceOf("couple_create");
            TemplateHandler.add(firstCouple, "arg1", "_ic_" + declarations.get(0).getName());
            TemplateHandler.add(firstCouple, "arg2", "_ic_" + declarations.get(1).getName());
            return declarations.subList(2, declarations.size()).stream()
                    .map(DeclarationNode::getName)
                    .reduce(firstCouple.render(), (a,e) -> {
                        ST couple = group.getInstanceOf("couple_create");
                        TemplateHandler.add(couple, "arg1", a);
                        TemplateHandler.add(couple, "arg2", "_ic_" + e);
                        return couple.render();
                    });
        }
    }

}
