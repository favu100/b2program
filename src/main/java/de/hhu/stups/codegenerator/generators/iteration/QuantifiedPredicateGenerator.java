package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;

/**
 * Created by fabian on 04.03.19.
 */
public class QuantifiedPredicateGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    private final ImportGenerator importGenerator;

    private final TypeGenerator typeGenerator;

    public QuantifiedPredicateGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
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

    public String generateQuantifiedPredicate(QuantifiedPredicateNode node) {
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        iterationConstructGenerator.addBoundedVariables(declarations);

        iterationPredicateGenerator.checkPredicate(predicate, declarations);
        boolean forAll = node.getOperator() == QuantifiedPredicateNode.QuantifiedPredicateOperator.UNIVERSAL_QUANTIFICATION;
        importGenerator.addImportInIteration(node.getType());

        ST template = group.getInstanceOf("quantified_predicate");

        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }

        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());

        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String innerBody = generateQuantifiedPredicateEvaluation(predicate, "_ic_boolean_" + iterationConstructCounter, forAll);
        String predicateString = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "identifier", "_ic_boolean_" + iterationConstructCounter);
        TemplateHandler.add(template, "forall", forAll);
        TemplateHandler.add(template, "predicate", predicateString);
        String result = template.render();
        iterationConstructGenerator.addIteration(node.toString(), "_ic_boolean_"+ iterationConstructCounter, result);
        iterationConstructGenerator.clearBoundedVariables(declarations);
        return result;
    }

    public String generateQuantifiedPredicateEvaluation(PredicateNode predicateNode, String identifier, boolean forAll) {
        //TODO only take end of predicate arguments
        ST template = group.getInstanceOf("quantified_evaluation");
        machineGenerator.inIterationConstruct();
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "forall", forAll);
        machineGenerator.leaveIterationConstruct();
        return template.render();
    }

}
