package de.hhu.stups.codegenerator.analyzers;

import de.prob.parser.ast.nodes.OperationNode;
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


public class CheckReachabilityAnalyzer implements AbstractVisitor<Boolean, Void> {

    public boolean visitOperation(OperationNode operationNode) {
        return visitSubstitutionNode(operationNode.getSubstitution(), null);
    }

    @Override
    public Boolean visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitNumberNode(NumberNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitRealNumberNode(RealNumberNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLambdaNode(LambdaNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLetExpressionNode(LetExpressionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitIfExpressionNode(IfExpressionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitStringNode(StringNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitRecordNode(RecordNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitStructNode(StructNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLTLPrefixOperatorNode(LTLPrefixOperatorNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLetPredicateNode(LetPredicateNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitIfPredicateNode(IfPredicateNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        return visitSubstitutionNode(node.getBody(), expected);
    }

    @Override
    public Boolean visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        return true;
    }

    @Override
    public Boolean visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        return node.getSubstitutions().stream()
                .map(sub -> visitSubstitutionNode(sub, null))
                .reduce(false, (a,e) -> a || e);
    }

    @Override
    public Boolean visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        IfOrSelectSubstitutionsNode.Operator operator = node.getOperator();
        if(operator == IfOrSelectSubstitutionsNode.Operator.SELECT) {
            if(node.getParent() instanceof OperationNode) {
                return node.getSubstitutions()
                        .stream()
                        .map(sub -> visitSubstitutionNode(sub, null))
                        .reduce(false, (a,e) -> a || e);
            }
            return true;
        }
        return false;
    }

    @Override
    public Boolean visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        if(node.getParent() instanceof OperationNode) {
            return visitSubstitutionNode(node.getSubstitution(), expected);
        }
        return false;
    }

    @Override
    public Boolean visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        return false;
    }

    @Override
    public Boolean visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        return true;
    }

    @Override
    public Boolean visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        return false;
    }
}
