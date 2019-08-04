package de.hhu.stups.codegenerator.analyzers;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import de.hhu.stups.codegenerator.generators.IdentifierGenerator;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
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
import java.util.stream.Collectors;

/**
 * Created by fabian on 03.03.19.
 */
public class ParallelConstructAnalyzer implements AbstractVisitor<Void, Void> {

    private final List<IdentifierExprNode> identifierOnLhsInParallel;

    private final List<IdentifierExprNode> identifierOnRhsInParallel;

    private final List<IdentifierExprNode> definedIdentifiersInParallel;

    private final List<IdentifierExprNode> definedLoadsInParallel;

    private final List<String> definedIdentifiersInCode;

    private final List<String> ignoredVariables;

    private final IdentifierGenerator identifierGenerator;

    private boolean onLeftHandSide;

    private boolean onRightHandSide;

    public ParallelConstructAnalyzer(final IdentifierGenerator identifierGenerator) {
        this.identifierGenerator = identifierGenerator;
        this.identifierOnLhsInParallel = new ArrayList<>();
        this.identifierOnRhsInParallel = new ArrayList<>();
        this.definedIdentifiersInParallel = new ArrayList<>();
        this.definedLoadsInParallel = new ArrayList<>();
        this.definedIdentifiersInCode = new ArrayList<>();
        this.ignoredVariables = new ArrayList<>();
        this.onLeftHandSide = false;
        this.onRightHandSide = true;
    }

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    /*
    * This function adds an identifier to the list of relevant identifiers on the left-hand side or right-hand side of a parallel substitution.
    * This information is needed to analyze parallel constructs for parallel substitutions
    */
    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        if(ignoredVariables.contains(node.getName())) {
            return null;
        }
        if(onLeftHandSide) {
            identifierOnLhsInParallel.add(node);
        } else if(onRightHandSide) {
            identifierOnRhsInParallel.add(node);
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
    public Void visitStringNode(StringNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        visitPredicateNode(node.getPredicateNode(), expected);
        visitExprNode(node.getExpressionNode(), expected);
        return null;
    }

    @Override
    public Void visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        List<String> locals = node.getDeclarationList().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getPredicateNode(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void expected) {
        List<String> locals = node.getDeclarations().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    @Override
    public Void visitLTLPrefixOperatorNode(LTLPrefixOperatorNode ltlPrefixOperatorNode, Void aVoid) {
        return null;
    }

    @Override
    public Void visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
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
        List<String> locals = node.getDeclarationList().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getPredicateNode(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    /*
    * When visiting a VAR substitution, local variables are added to ignored variables as they are not relevant for variables in a parallel substitution.
    * This is done by this function.
    */
    @Override
    public Void visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        List<String> locals = node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitSubstitutionNode(node.getBody(), expected);
        ignoredVariables.removeAll(locals);
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
        if(node.getOperator() == ListSubstitutionNode.ListOperator.Sequential) {
            return null;
        }
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, expected));
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
    public Void visitIfExpressionNode(IfExpressionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitExprNode(node.getThenExpression(), expected);
        visitExprNode(node.getElseExpression(), expected);
        return null;
    }

    @Override
    public Void visitIfPredicateNode(IfPredicateNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitPredicateNode(node.getThenPredicate(), expected);
        visitPredicateNode(node.getElsePredicate(), expected);
        return null;
    }

    /*
    * This function analyzes identifiers on the left-hand side and right-hand side of an assignment from the belonging AST node.
    */
    @Override
    public Void visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        this.onLeftHandSide = true;
        node.getLeftSide().forEach(lhs -> visitExprNode(lhs, expected));
        this.onLeftHandSide = false;
        this.onRightHandSide = true;
        node.getRightSide().forEach(rhs -> visitExprNode(rhs, expected));
        this.onRightHandSide = false;
        definedLoadsInParallel.addAll(identifierOnLhsInParallel.stream()
                .filter(lhs -> identifierOnRhsInParallel.stream()
                        .map(IdentifierExprNode::getName)
                        .collect(Collectors.toList())
                        .contains(lhs.getName()))
                .filter(lhs -> !identifierGenerator.getInputParams()
                        .stream()
                        .map(DeclarationNode::getName)
                        .collect(Collectors.toList())
                        .contains(lhs.getName()))
                .collect(Collectors.toList()));
        definedIdentifiersInParallel.addAll(definedLoadsInParallel);
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

    /*
    * When visiting an ANY substitution, bounded variables are added to ignored variables as they are not relevant for variables in a parallel substitution.
    * This is done by this function.
    */
    @Override
    public Void visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        List<String> locals = node.getParameters().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getWherePredicate(), expected);
        visitSubstitutionNode(node.getThenSubstitution(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    /*
    * When visiting a LET substitution, bounded variables are added to ignored variables as they are not relevant for variables in a parallel substitution.
    * This is done by this function.
    */
    @Override
    public Void visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        List<String> locals = node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getPredicate(), expected);
        visitSubstitutionNode(node.getBody(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    /*
    * When visiting a LET expression, bounded variables are added to ignored variables as they are not relevant for variables in a parallel substitution.
    * This is done by this function.
    */
    @Override
    public Void visitLetExpressionNode(LetExpressionNode node, Void expected) {
        List<String> locals = node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    /*
    * When visiting a LET predicate, bounded variables are added to ignored variables as they are not relevant for variables in a parallel substitution.
    * This is done by this function.
    */
    @Override
    public Void visitLetPredicateNode(LetPredicateNode node, Void expected) {
        List<String> locals = node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        visitPredicateNode(node.getWherePredicate(), expected);
        visitPredicateNode(node.getPredicate(), expected);
        ignoredVariables.removeAll(locals);
        return null;
    }

    @Override
    public Void visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        node.getIdentifiers().forEach(id -> visitExprNode(id, expected));
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        node.getIdentifiers().forEach(id -> visitExprNode(id, expected));
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        throw new CodeGenerationException("Operation call in parallel substitution is not allowed");
    }

    @Override
    public Void visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, expected));
        return null;
    }

    @Override
    public Void visitRecordNode(RecordNode node, Void expected) {
        List<String> locals = node.getDeclarations().stream().map(DeclarationNode::getName).collect(Collectors.toList());
        ignoredVariables.addAll(locals);
        node.getExpressions().forEach(expr -> visitExprNode(expr, expected));
        ignoredVariables.removeAll(locals);
        return null;
    }

    @Override
    public Void visitStructNode(StructNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        visitExprNode(node.getRecord(), expected);
        return null;
    }

    /*
    * This function is invoked when all parallel constructs are left during visiting AST nodes
    */
    public void resetParallel() {
        definedLoadsInParallel.clear();
    }

    public List<IdentifierExprNode> getDefinedLoadsInParallel() {
        return definedLoadsInParallel;
    }

    public List<IdentifierExprNode> getDefinedIdentifiersInParallel() {
        return definedIdentifiersInParallel;
    }

    public List<String> definedIdentifiersInCode() {
        return definedIdentifiersInCode;
    }

}
