package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.types.BType;
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

    public QuantifiedPredicateGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                           final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator, final ImportGenerator importGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.importGenerator = importGenerator;
    }

    private void prepareGeneration(PredicateNode predicate, List<DeclarationNode> declarations, BType type) {
        iterationConstructGenerator.addBoundedVariables(declarations);
        iterationPredicateGenerator.checkPredicate(predicate, declarations);
        importGenerator.addImportInIteration(type);
    }

    public String generateQuantifiedPredicate(QuantifiedPredicateNode node) {
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        BType type = node.getType();
        prepareGeneration(predicate, declarations, type);
        boolean forAll = node.getOperator() == QuantifiedPredicateNode.QuantifiedPredicateOperator.UNIVERSAL_QUANTIFICATION;

        ST template = group.getInstanceOf("quantified_predicate");
        generateOtherIterationConstructs(template, predicate);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String identifier = "_ic_boolean_"+ iterationConstructCounter;
        generateBody(template, identifier, forAll, predicate, declarations);

        String result = template.render();
        addGeneration(node.toString(), identifier, declarations, result);
        return result;
    }

    private void generateOtherIterationConstructs(ST template, PredicateNode predicate) {
        IterationConstructGenerator otherConstructsGenerator = iterationConstructHandler.inspectPredicate(predicate);
        for (String key : otherConstructsGenerator.getIterationsMapIdentifier().keySet()) {
            iterationConstructGenerator.getIterationsMapIdentifier().put(key, otherConstructsGenerator.getIterationsMapIdentifier().get(key));
        }
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructsGenerator.getIterationsMapCode().values());
    }

    private void generateBody(ST template, String identifier, boolean forAll, PredicateNode predicate, List<DeclarationNode> declarations) {
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(declarations, predicate);

        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String innerBody = generateQuantifiedPredicateEvaluation(predicate, identifier, forAll);
        String predicateString = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "forall", forAll);
        TemplateHandler.add(template, "predicate", predicateString);
    }

    private void addGeneration(String node, String identifier, List<DeclarationNode> declarations, String result) {
        iterationConstructGenerator.addIteration(node, identifier, result);
        iterationConstructGenerator.clearBoundedVariables(declarations);
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
