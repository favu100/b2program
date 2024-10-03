package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.types.BType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
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

    public QuantifiedPredicateGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                           final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
    }

    /*
    * This function generates code for a quantified predicate from the belonging AST node
    */
    public String generateQuantifiedPredicate(PredicateNode conditionalPredicate, QuantifiedPredicateNode node) {
        machineGenerator.inIterationConstruct(node.getDeclarationList());
        PredicateNode predicate = node.getPredicateNode();
        List<DeclarationNode> declarations = node.getDeclarationList();
        BType type = node.getType();
        ST template = group.getInstanceOf("quantified_predicate");

        boolean forAll = node.getOperator() == QuantifiedPredicateNode.QuantifiedPredicateOperator.UNIVERSAL_QUANTIFICATION;

        iterationConstructGenerator.prepareGeneration(predicate, declarations, type, forAll);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, forAll);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        int iterationConstructCounter = iterationConstructHandler.getIterationConstructCounter();
        String prefix = machineGenerator.getMode().equals(GeneratorMode.PL) ? "PL" : "";
        String identifier = prefix + "_ic_boolean_"+ iterationConstructCounter;
        generateBody(template, enumerationTemplates, otherConstructs, identifier, forAll, conditionalPredicate, predicate, declarations);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), identifier, declarations, result);
        machineGenerator.leaveIterationConstruct(node.getDeclarationList());
        return result;
    }

    /*
    * This function generates code for other iteration constructs used within the quantified predicate
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
    * This function generates code for the body of a quantified predicate
    */
    private void generateBody(ST template, List<ST> enumerationTemplates, Collection<String> otherConstructs, String identifier, boolean forAll, PredicateNode conditionalPredicate, PredicateNode predicate, List<DeclarationNode> declarations) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);

        String innerBody = generateQuantifiedPredicateEvaluation(otherConstructs, conditionalPredicate, predicate, identifier, forAll, declarations);
        String predicateString = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody).render();

        TemplateHandler.add(template, "isJavaScript", machineGenerator.getMode() == GeneratorMode.JS);
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "forall", forAll);
        TemplateHandler.add(template, "predicate", predicateString);
    }

    /*
    * This function generates code for the evaluation of a quantified predicate
    */
    private String generateQuantifiedPredicateEvaluation(Collection<String> otherConstructs, PredicateNode conditionalPredicate, PredicateNode predicateNode, String identifier, boolean forAll, List<DeclarationNode> declarations) {
        ST template = group.getInstanceOf("quantified_predicate_evaluation");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", predicateNode instanceof PredicateOperatorNode && ((PredicateOperatorNode) predicateNode).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        System.out.println(conditionalPredicate);
        System.out.println(predicateNode);
        System.out.println("----------");
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(predicateNode, null));
        TemplateHandler.add(template, "identifier", identifier);
        TemplateHandler.add(template, "forall", forAll);
        return template.render();
    }

}
