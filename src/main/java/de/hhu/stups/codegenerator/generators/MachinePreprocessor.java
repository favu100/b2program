package de.hhu.stups.codegenerator.generators;

import de.prob.parser.ast.SourceCodePosition;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
import de.prob.parser.ast.nodes.expression.RealNumberNode;
import de.prob.parser.ast.nodes.expression.RecordFieldAccessNode;
import de.prob.parser.ast.nodes.expression.RecordNode;
import de.prob.parser.ast.nodes.expression.SetComprehensionNode;
import de.prob.parser.ast.nodes.expression.StringNode;
import de.prob.parser.ast.nodes.expression.StructNode;
import de.prob.parser.ast.nodes.ltl.LTLBPredicateNode;
import de.prob.parser.ast.nodes.ltl.LTLInfixOperatorNode;
import de.prob.parser.ast.nodes.ltl.LTLKeywordNode;
import de.prob.parser.ast.nodes.ltl.LTLPrefixOperatorNode;
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.nodes.substitution.AnySubstitutionNode;
import de.prob.parser.ast.nodes.substitution.AssignSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesElementOfSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.BecomesSuchThatSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ChoiceSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ConditionSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.IfOrSelectSubstitutionsNode;
import de.prob.parser.ast.nodes.substitution.LetSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.ListSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.OperationCallSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.SkipSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.visitors.AbstractVisitor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class MachinePreprocessor implements AbstractVisitor<Node, Void> {

    private boolean inEnumeration;

    public MachinePreprocessor() {
        this.inEnumeration = false;
    }

    public void visitMachineNode(MachineNode machineNode) {
        // TODO: Process other constructs
        if(machineNode.getProperties() != null) {
            machineNode.setProperties(visitPredicateNode(machineNode.getProperties()));
        }
        if(machineNode.getInvariant() != null) {
            machineNode.setInvariant(visitPredicateNode(machineNode.getInvariant()));
        }
    }

    public PredicateNode visitPredicateNode(PredicateNode predicateNode) {
        if(predicateNode instanceof PredicateOperatorWithExprArgsNode) {
            return (PredicateNode) visitPredicateOperatorWithExprArgs((PredicateOperatorWithExprArgsNode) predicateNode, null);
        } else if(predicateNode instanceof PredicateOperatorNode) {
            return (PredicateNode) visitPredicateOperatorNode((PredicateOperatorNode) predicateNode, null);
        }
        return predicateNode;
    }
    
    @Override
    public Node visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitNumberNode(NumberNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRealNumberNode(RealNumberNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLambdaNode(LambdaNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetExpressionNode(LetExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfExpressionNode(IfExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitStringNode(StringNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRecordNode(RecordNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitStructNode(StructNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLPrefixOperatorNode(LTLPrefixOperatorNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        return new PredicateOperatorNode(node.getSourceCodePosition(), node.getOperator(), node.getPredicateArguments().stream()
                .map(this::visitPredicateNode)
                .collect(Collectors.toList()));
    }

    @Override
    public Node visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        SourceCodePosition sourceCodePosition = node.getSourceCodePosition();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
            ExprNode lhs = node.getExpressionNodes().get(0);
            ExprNode rhs = node.getExpressionNodes().get(1);

            ExprNode newRhs = rhs;
            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode rhsAsExpression = ((ExpressionOperatorNode) rhs);
                ExpressionOperatorNode.ExpressionOperator rhsOperator = rhsAsExpression.getOperator();
                if(rhsOperator == ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION) {
                    if(rhsAsExpression.getExpressionNodes().size() == 1) {
                        newRhs = rhsAsExpression.getExpressionNodes().get(0);
                        List<ExprNode> expressions = new ArrayList<>();
                        expressions.add(lhs);
                        expressions.add(newRhs);
                        return new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL, expressions);
                    }
                } else if(rhsOperator == ExpressionOperatorNode.ExpressionOperator.INTERVAL) {
                    List<PredicateNode> predicates = new ArrayList<>();
                    predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.GREATER_EQUAL, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                    predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.LESS_EQUAL, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                    return new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                }
            }
        }
        return node;
    }

    @Override
    public Node visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetPredicateNode(LetPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfPredicateNode(IfPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        return node;
    }
}
