package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.generators.BacktrackingGenerator;
import de.hhu.stups.codegenerator.generators.BacktrackingVisitor;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.modelchecker.OperationFunctionInfo;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
import java.util.List;
import java.util.Map;

/**
 * Created by fabian on 28.04.19.
 */
public class AnySubstitutionGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    private final BacktrackingGenerator backtrackingGenerator;


    public AnySubstitutionGenerator(final STGroup group, final MachineGenerator machineGenerator, final IterationConstructGenerator iterationConstructGenerator,
                                    final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator,
                                    final BacktrackingGenerator backtrackingGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.backtrackingGenerator = backtrackingGenerator;
    }

    /*
    * This function generates code for the ANY substitution from the belonging AST node
    */
    public String generateAnySubstitution(PredicateNode conditionalPredicate, AnySubstitutionNode node) {
        machineGenerator.inIterationConstruct(node.getParameters());
        PredicateNode predicate = node.getWherePredicate();
        SubstitutionNode substitution = node.getThenSubstitution();
        List<DeclarationNode> declarations = node.getParameters();

        ST template = group.getInstanceOf("any");
        TemplateHandler.add(template, "forModelChecking", machineGenerator.isForModelChecking());

        iterationConstructGenerator.prepareGeneration(predicate, declarations, false);
        List<ST> enumerationTemplates = iterationPredicateGenerator.getEnumerationTemplates(iterationConstructGenerator, declarations, predicate, false);
        Collection<String> otherConstructs = generateOtherIterationConstructs(predicate);

        int counter = 0;
        String operation = null;
        boolean isLastChoicePoint = false;
        for(Map.Entry<String, BacktrackingVisitor> entry : backtrackingGenerator.getBacktrackingVisitorMap().entrySet()) {
            BacktrackingVisitor visitor = entry.getValue();
            Map<Node, Integer> choicePointMap = visitor.getChoicePointMap();

            if(choicePointMap.containsKey(node)) {
                counter = choicePointMap.get(node);
                operation = entry.getKey();
                isLastChoicePoint = counter == choicePointMap.size();
            }
        }
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "usePreviousChoicePoint", counter > 1);
        if(counter > 1) {
            TemplateHandler.add(template, "previousChoicePoint", counter - 1);
        }
        TemplateHandler.add(template, "choicePoint", counter);

        generateBody(template, otherConstructs, enumerationTemplates, conditionalPredicate, predicate, substitution, declarations, counter, operation, isLastChoicePoint);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), declarations, result);

        machineGenerator.leaveIterationConstruct(node.getParameters());
        return result;
    }

    /*
    * This function generates code for the inner body of the ANY substitution
    */
    private String generateAnyBody(Collection<String> otherConstructs, PredicateNode conditionalPredicate, PredicateNode predicateNode, SubstitutionNode substitutionNode, List<DeclarationNode> declarations, int counter, String operation, boolean isLastChoicePoint) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, declarations, false);
        ST template = group.getInstanceOf("any_body");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);
        TemplateHandler.add(template, "emptyPredicate", subpredicate == null || ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        if(subpredicate != null) {
            TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        }
        TemplateHandler.add(template, "body", machineGenerator.visitSubstitutionNode(substitutionNode, null));
        TemplateHandler.add(template, "forModelChecking", machineGenerator.isForModelChecking());
        TemplateHandler.add(template, "choicePoint", counter);
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "isLastChoicePoint", isLastChoicePoint);
        return template.render();
    }

    /*
    * This function generates code for other iteration constructs within the ANY substitution from the given predicate
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
    * This function generates code for the body of the ANY substitution
    */
    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode conditionalPredicate, PredicateNode predicate, SubstitutionNode substitution, List<DeclarationNode> declarations, int counter, String operation, boolean isLastChoicePoint) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String innerBody = generateAnyBody(otherConstructs, conditionalPredicate, predicate, substitution, declarations, counter, operation, isLastChoicePoint);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody, conditionalPredicate).render();
        TemplateHandler.add(template, "body", body);
    }

}
