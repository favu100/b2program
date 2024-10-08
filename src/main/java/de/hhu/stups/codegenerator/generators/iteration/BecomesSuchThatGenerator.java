package de.hhu.stups.codegenerator.generators.iteration;

import de.hhu.stups.codegenerator.analyzers.PrimedIdentifierAnalyzer;
import de.hhu.stups.codegenerator.generators.BacktrackingGenerator;
import de.hhu.stups.codegenerator.generators.BacktrackingVisitor;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by fabian on 28.04.19.
 */
public class BecomesSuchThatGenerator {

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final IterationConstructGenerator iterationConstructGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    private final IterationPredicateGenerator iterationPredicateGenerator;

    private final BacktrackingGenerator backtrackingGenerator;

    public BecomesSuchThatGenerator(final STGroup group, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator,
                                    final IterationConstructGenerator iterationConstructGenerator,
                                    final IterationConstructHandler iterationConstructHandler, final IterationPredicateGenerator iterationPredicateGenerator,
                                    final BacktrackingGenerator backtrackingGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.iterationConstructGenerator = iterationConstructGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
        this.iterationPredicateGenerator = iterationPredicateGenerator;
        this.backtrackingGenerator = backtrackingGenerator;
    }

    /*
    * This function generates code for the becomes such that substitution
    */
    public String generateBecomesSuchThat(PredicateNode conditionalPredicate, BecomesSuchThatSubstitutionNode node) {
        machineGenerator.inIterationConstruct();
        PredicateNode predicate = node.getPredicate();

        List<DeclarationNode> declarations = node.getIdentifiers()
                .stream()
                .map(IdentifierExprNode::getDeclarationNode)
                .collect(Collectors.toList());

        ST template = group.getInstanceOf("becomes_such_that");
        TemplateHandler.add(template, "forModelChecking", machineGenerator.isForModelChecking());

        generateLoads(template, predicate);

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

        generateBody(template, otherConstructs, enumerationTemplates, conditionalPredicate, predicate, node.getIdentifiers(), counter, operation, isLastChoicePoint);

        String result = template.render();
        iterationConstructGenerator.addGeneration(node.toString(), declarations, result);

        machineGenerator.leaveIterationConstruct();
        return result;
    }

    /*
    * This function generates code for the inner body of the becomes such that substitution
    */
    private String generateBecomesSuchThatBody(Collection<String> otherConstructs, List<IdentifierExprNode> identifiers, PredicateNode conditionalPredicate, PredicateNode predicateNode, int counter, String operation, boolean isLastChoicePoint) {
        PredicateNode subpredicate = iterationPredicateGenerator.subpredicate(predicateNode, identifiers.stream()
                .map(IdentifierExprNode::getDeclarationNode)
                .collect(Collectors.toList()), false);

        ST template = group.getInstanceOf("becomes_such_that_body");
        TemplateHandler.add(template, "otherIterationConstructs", otherConstructs);

        TemplateHandler.add(template, "emptyPredicate", subpredicate == null || ((PredicateOperatorNode) subpredicate).getPredicateArguments().size() == 0);
        TemplateHandler.add(template, "hasCondition", conditionalPredicate != null);
        if(conditionalPredicate != null) {
            TemplateHandler.add(template, "conditionalPredicate", machineGenerator.visitPredicateNode(conditionalPredicate, null));
        }
        if(subpredicate != null) {
            TemplateHandler.add(template, "predicate", machineGenerator.visitPredicateNode(subpredicate, null));
        }

        List<String> stores = identifiers.stream().map(this::generateStore).collect(Collectors.toList());
        TemplateHandler.add(template, "stores", stores);
        TemplateHandler.add(template, "forModelChecking", machineGenerator.isForModelChecking());
        TemplateHandler.add(template, "choicePoint", counter);
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "isLastChoicePoint", isLastChoicePoint);

        return template.render();
    }

    /*
    * This function generates code for other iteration constructs within the becomes such that substitution from the given predicate
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
    * This function generates code for the body of the becomes such that substitution
    */
    private void generateBody(ST template, Collection<String> otherConstructs, List<ST> enumerationTemplates, PredicateNode conditionalPredicate, PredicateNode predicate, List<IdentifierExprNode> identifiers, int counter, String operation, boolean isLastChoicePoint) {
        iterationConstructHandler.setIterationConstructGenerator(iterationConstructGenerator);
        String innerBody = generateBecomesSuchThatBody(otherConstructs, identifiers, conditionalPredicate, predicate, counter, operation, isLastChoicePoint);
        String body = iterationPredicateGenerator.evaluateEnumerationTemplates(enumerationTemplates, innerBody, conditionalPredicate).render();
        TemplateHandler.add(template, "body", body);
    }

    /*
    * This function generates code for loads of all primed identifiers used in the becomes such that substitution from the given template and predicate
    */
    private void generateLoads(ST template, PredicateNode predicate) {
        PrimedIdentifierAnalyzer primedAnalyzer = new PrimedIdentifierAnalyzer();
        primedAnalyzer.visitPredicateNode(predicate, null);
        List<String> loads = primedAnalyzer.getPrimedIdentifiers().stream().map(this::generateLoad).collect(Collectors.toList());
        TemplateHandler.add(template, "loads", loads);
    }

    /*
    * This function generates code for loading a pried identifier used in the becomes such that substitution from the given AST node for an identifier
    */
    private String generateLoad(IdentifierExprNode node) {
        IdentifierExprNode rhs = new IdentifierExprNode(node.getSourceCodePosition(), node.getName(), false);
        rhs.setDeclarationNode(node.getDeclarationNode());
        rhs.setType(node.getType());
        rhs.setParent(node.getParent());
        ST template = group.getInstanceOf("becomes_such_that_load");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(template, "lhs", machineGenerator.visitExprNode(node, null));
        TemplateHandler.add(template, "rhs", machineGenerator.visitExprNode(rhs, null));
        return template.render();
    }

    /*
    * This function generates code for storing a value to an identifier at the end of the becomes such that substitution from the given AST node for an identifier
    */
    private String generateStore(IdentifierExprNode node) {
        ST template = group.getInstanceOf("becomes_such_that_store");
        TemplateHandler.add(template, "type", typeGenerator.generate(node.getType()));
        int depth = machineGenerator.getIterationConstructDepth();
        machineGenerator.resetIterationConstruct();
        TemplateHandler.add(template, "lhs", machineGenerator.visitExprNode(node, null));
        machineGenerator.setIterationConstructDepth(depth);
        TemplateHandler.add(template, "rhs", machineGenerator.visitExprNode(node, null));
        return template.render();
    }
}
