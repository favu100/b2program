package de.hhu.stups.codegenerator.analyzers;

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

import java.util.ArrayList;
import java.util.List;

/**
 * Created by fabian on 05.05.19.
 */
public class PrimedIdentifierAnalyzer implements AbstractVisitor<Void, Void> {

    private List<IdentifierExprNode> primedIdentifiers;

    public PrimedIdentifierAnalyzer() {
        this.primedIdentifiers = new ArrayList<>();
    }

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    /*
    * This function checks whether the given identifier is primed. If yes, then it is added to the list of primed identifiers
    */
    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        if(node.isPrimed()) {
            primedIdentifiers.add(node);
        }
        return null;
    }

    @Override
    public Void visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitNumberNode(NumberNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitRealNumberNode(RealNumberNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        visitExprNode(node.getExpressionNode(), expected);
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitLetExpressionNode(LetExpressionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitIfExpressionNode(IfExpressionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitExprNode(node.getThenExpression(), expected);
        visitExprNode(node.getElseExpression(), expected);
        return null;
    }

    @Override
    public Void visitStringNode(StringNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLPrefixOperatorNode(LTLPrefixOperatorNode ltlPrefixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLKeywordNode(LTLKeywordNode ltlKeywordNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLInfixOperatorNode(LTLInfixOperatorNode ltlInfixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLBPredicateNode(LTLBPredicateNode ltlbPredicateNode, Void expected) {
        return null;
    }

    @Override
    public Void visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        node.getPredicateArguments().forEach(pred -> visitPredicateNode(pred, expected));
        return null;
    }

    @Override
    public Void visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitLetPredicateNode(LetPredicateNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), expected);
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitIfPredicateNode(IfPredicateNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitPredicateNode(node.getThenPredicate(), expected);
        visitPredicateNode(node.getElsePredicate(), expected);
        return null;
    }

    @Override
    public Void visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
        return null;
    }

    @Override
    public Void visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        node.getConditions().forEach(cond -> visitPredicateNode(cond, expected));
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, expected));
        if(node.getElseSubstitution() != null) {
            visitSubstitutionNode(node.getElseSubstitution(), expected);
        }
        return null;
    }

    @Override
    public Void visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        node.getLeftSide().forEach(lhs -> visitExprNode(lhs, expected));
        node.getRightSide().forEach(rhs -> visitExprNode(rhs, expected));
        return null;
    }

    @Override
    public Void visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitSubstitutionNode(node.getSubstitution(), expected);
        return null;
    }

    @Override
    public Void visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), expected);
        visitSubstitutionNode(node.getThenSubstitution(), expected);
        return null;
    }

    @Override
    public Void visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        node.getArguments().forEach(arg -> visitExprNode(arg, expected));
        return null;
    }

    @Override
    public Void visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
        return null;
    }

    @Override
    public Void visitRecordNode(RecordNode node, Void expected) {
        node.getExpressions().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitStructNode(StructNode node, Void expected) {
        node.getExpressions().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        visitExprNode(node.getRecord(), expected);
        return null;
    }

    public List<IdentifierExprNode> getPrimedIdentifiers() {
        return primedIdentifiers;
    }
}
