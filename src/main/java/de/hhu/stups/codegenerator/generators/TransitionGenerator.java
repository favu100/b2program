package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.generators.iteration.IterationConstructGenerator;
import de.hhu.stups.codegenerator.handlers.IterationConstructHandler;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ChoiceSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ConditionSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.IfOrSelectSubstitutionsNode;
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TransitionGenerator {

    private static final List<Class<?>> nondeterministicSubstitutions = Arrays.asList(AnySubstitutionNode.class, ChoiceSubstitutionNode.class,
            BecomesSuchThatSubstitutionNode.class, BecomesElementOfSubstitutionNode.class);

    private final MachineGenerator machineGenerator;

    private final IterationConstructHandler iterationConstructHandler;

    public TransitionGenerator(final MachineGenerator machineGenerator, final IterationConstructHandler iterationConstructHandler) {
        this.machineGenerator = machineGenerator;
        this.iterationConstructHandler = iterationConstructHandler;
    }

    public PredicateNode extractGuard(OperationNode operation) {
        SubstitutionNode bodySubstitution = operation.getSubstitution();
        if(bodySubstitution instanceof IfOrSelectSubstitutionsNode) {
            if(((IfOrSelectSubstitutionsNode) bodySubstitution).getOperator() == IfOrSelectSubstitutionsNode.Operator.SELECT) {
                return ((IfOrSelectSubstitutionsNode) bodySubstitution).getConditions().get(0);
            }
        } else if(bodySubstitution instanceof ConditionSubstitutionNode) {
            if (((ConditionSubstitutionNode) bodySubstitution).getKind() == ConditionSubstitutionNode.Kind.PRECONDITION) {
                return ((ConditionSubstitutionNode) bodySubstitution).getCondition();
            }
        }
        return null;
    }

    public List<String> generateTransitions(List<OperationNode> operations) {
        List<String> transitions = new ArrayList<>();
        if((machineGenerator.isForModelChecking() || machineGenerator.isForVisualisation()) && !machineGenerator.isIncludedMachine()) {
            for (OperationNode operation : operations) {
                transitions.add(generateTransition(operation));
            }
        }
        return transitions;
    }

    // todo: probably move this somewhere else so that we can use it for other error messages
    public static String GetNodeLocationAndText (Node node) {
      return 
            "at line " + node.getSourceCodePosition().getStartLine() + 
            " and column " + node.getSourceCodePosition().getStartColumn() + 
            ": " + node.getSourceCodePosition().getText();
    }
    
    private String generateTransition(OperationNode operation) {
        SubstitutionNode bodySubstitution = operation.getSubstitution();
        IterationConstructGenerator iterationConstructGenerator = iterationConstructHandler.getNewIterationConstructGenerator();
        if(bodySubstitution instanceof IfOrSelectSubstitutionsNode) {
            if(((IfOrSelectSubstitutionsNode) bodySubstitution).getOperator() == IfOrSelectSubstitutionsNode.Operator.SELECT) {
                PredicateNode predicate = extractGuard(operation);
                iterationConstructGenerator.visitOperationNode(operation, operation.getParams(), predicate);
                return iterationConstructGenerator.getIterationsMapCode().get(operation.toString());
            } else {
                throw new RuntimeException("Top-level substitution must either be a SELECT or a PRE substitution when there are parameters " + GetNodeLocationAndText(bodySubstitution));
            }
        } else if(bodySubstitution instanceof ConditionSubstitutionNode) {
            if (((ConditionSubstitutionNode) bodySubstitution).getKind() == ConditionSubstitutionNode.Kind.PRECONDITION) {
                PredicateNode predicate = extractGuard(operation);
                iterationConstructGenerator.visitOperationNode(operation, operation.getParams(), predicate);
                return iterationConstructGenerator.getIterationsMapCode().get(operation.toString());
            } else {
                throw new RuntimeException("Top-level substitution must either be a SELECT or a PRE substitution when there are parameters "+ GetNodeLocationAndText(bodySubstitution));
            }
        //} else if(nondeterministicSubstitutions.contains(bodySubstitution.getClass())) {
        //    throw new RuntimeException("Non-deterministic assignments and ANY substitution are not allowed in model checking mode " + GetNodeLocationAndText(bodySubstitution));
        } else {
            if(operation.getParams().size() == 0) {
                iterationConstructGenerator.visitOperationNode(operation, operation.getParams(), null);
                return iterationConstructGenerator.getIterationsMapCode().get(operation.toString());
            } else {
                throw new RuntimeException("Top-level substitution must either be a SELECT or a PRE substitution "
                                           + GetNodeLocationAndText(bodySubstitution));
            }
        }
    }

}
