package de.hhu.stups.codegenerator;

import de.hhu.stups.codegenerator.analyzers.IdentifierAnalyzer;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.Node;
import de.prob.parser.ast.nodes.OperationNode;
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

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class MachineConstantsPreprocessor implements AbstractVisitor<Node, Void> {

    private static final List<ExpressionOperatorNode.ExpressionOperator> IGNORED_OPERATORS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PERM, ExpressionOperatorNode.ExpressionOperator.SEQ, ExpressionOperatorNode.ExpressionOperator.SEQ1, ExpressionOperatorNode.ExpressionOperator.ISEQ1, ExpressionOperatorNode.ExpressionOperator.ISEQ,
                    ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION,
                    ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION,
                    ExpressionOperatorNode.ExpressionOperator.INTEGER, ExpressionOperatorNode.ExpressionOperator.STRING, ExpressionOperatorNode.ExpressionOperator.BOOL, ExpressionOperatorNode.ExpressionOperator.NATURAL, ExpressionOperatorNode.ExpressionOperator.NATURAL1,
                    ExpressionOperatorNode.ExpressionOperator.REAL,  ExpressionOperatorNode.ExpressionOperator.EMPTY_SET, ExpressionOperatorNode.ExpressionOperator.EMPTY_SEQUENCE, ExpressionOperatorNode.ExpressionOperator.TRUE, ExpressionOperatorNode.ExpressionOperator.FALSE,
                    ExpressionOperatorNode.ExpressionOperator.MININT, ExpressionOperatorNode.ExpressionOperator.MAXINT, ExpressionOperatorNode.ExpressionOperator.NAT, ExpressionOperatorNode.ExpressionOperator.NAT1, ExpressionOperatorNode.ExpressionOperator.PRJ1, ExpressionOperatorNode.ExpressionOperator.PRJ2);

    private final MachineNode machineNode;

    private final List<String> constants;

    private final Map<String, DeclarationNode> replacements;

    private final Map<String, ExprNode> replacementsExpressions;

    private int constantsCounter;

    public MachineConstantsPreprocessor(MachineNode machineNode) {
        this.machineNode = machineNode;
        this.constants = machineNode.getConstants().stream()
                .map(DeclarationNode::getName)
                .collect(Collectors.toList());
        this.replacements = new HashMap<>();
        this.replacementsExpressions = new HashMap<>();
        this.constantsCounter = 1;
    }

    public boolean checkIfConstantsOnly(ExprNode exprNode) {
        IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
        identifierAnalyzer.visitNode(exprNode, null);
        return constants.containsAll(identifierAnalyzer.getIdentifiers());
    }

    public void visitMachineNode(MachineNode node) {
        if(machineNode.getInvariant() != null) {
            visitPredicateNode(machineNode.getInvariant(), null);
        }
        machineNode.getOperations().forEach(this::visitOperationNode);
    }

    public void visitOperationNode(OperationNode operationNode) {
        visitSubstitutionNode(operationNode.getSubstitution(), null);
    }

    @Override
    public Node visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        if(checkIfConstantsOnly(node) && !IGNORED_OPERATORS.contains(node.getOperator())) {
            if(node.getOperator() != ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION || node.getExpressionNodes().size() > 0) {
                if (!replacements.containsKey(node.toString())) {
                    replacements.put(node.toString(), generateNewDeclarationNode(node));
                    replacementsExpressions.put(node.toString(), node);
                    return null;
                }
            }
        }
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, null));
        return null;
    }

    @Override
    public Node visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitPredicateNode(node.getPredicate(), null);
        return null;
    }

    @Override
    public Node visitNumberNode(NumberNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitRealNumberNode(RealNumberNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitPredicateNode(node.getPredicateNode(), null);
        visitExprNode(node.getExpressionNode(), null);
        return null;
    }

    @Override
    public Node visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitPredicateNode(node.getPredicateNode(), null);
        return null;
    }

    private DeclarationNode generateNewDeclarationNode(ExprNode node) {
        DeclarationNode newNode = new DeclarationNode(node.getSourceCodePosition(), "__aux_constant_" + constantsCounter, DeclarationNode.Kind.VARIABLE, machineNode);
        newNode.setType(node.getType());
        constantsCounter++;
        return newNode;
    }

    @Override
    public Node visitLambdaNode(LambdaNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitPredicateNode(node.getPredicate(), null);
        visitExprNode(node.getExpression(), null);
        return null;
    }

    @Override
    public Node visitLetExpressionNode(LetExpressionNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitExprNode(node.getExpression(), null);
        visitPredicateNode(node.getPredicate(), null);
        return null;
    }

    @Override
    public Node visitIfExpressionNode(IfExpressionNode node, Void expected) {
        if(checkIfConstantsOnly(node)) {
            if(!replacements.containsKey(node.toString())) {
                replacements.put(node.toString(), generateNewDeclarationNode(node));
                replacementsExpressions.put(node.toString(), node);
                return null;
            }
        }
        visitPredicateNode(node.getCondition(), null);
        visitExprNode(node.getThenExpression(), null);
        visitExprNode(node.getElseExpression(), null);
        return null;
    }

    @Override
    public Node visitStringNode(StringNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitRecordNode(RecordNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitStructNode(StructNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitLTLPrefixOperatorNode(LTLPrefixOperatorNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        node.getPredicateArguments().forEach(pred -> visitPredicateNode(pred, null));
        return null;
    }

    @Override
    public Node visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, null));
        return null;
    }

    @Override
    public Node visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        visitPredicateNode(node.getPredicateNode(), null);
        return null;
    }

    @Override
    public Node visitLetPredicateNode(LetPredicateNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), null);
        visitPredicateNode(node.getPredicate(), null);
        return null;
    }

    @Override
    public Node visitIfPredicateNode(IfPredicateNode node, Void expected) {
        visitPredicateNode(node.getCondition(), null);
        visitPredicateNode(node.getThenPredicate(), null);
        visitPredicateNode(node.getElsePredicate(), null);
        return null;
    }

    @Override
    public Node visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        visitSubstitutionNode(node.getBody(), null);
        return null;
    }

    @Override
    public Node visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), null);
        visitSubstitutionNode(node.getBody(), null);
        visitPredicateNode(node.getInvariant(), null);
        visitExprNode(node.getVariant(), null);
        return null;
    }

    @Override
    public Node visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, null));
        return null;
    }

    @Override
    public Node visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        node.getConditions().forEach(cond -> visitPredicateNode(cond, null));
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, null));
        if(node.getElseSubstitution() != null) {
            visitSubstitutionNode(node.getElseSubstitution(), null);
        }
        return null;
    }

    @Override
    public Node visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        node.getRightSide().forEach(rhs -> visitExprNode(rhs, null));
        return null;
    }

    @Override
    public Node visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return null;
    }

    @Override
    public Node visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getCondition(), null);
        visitSubstitutionNode(node.getSubstitution(), null);
        return null;
    }

    @Override
    public Node visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), null);
        visitSubstitutionNode(node.getThenSubstitution(), null);
        return null;
    }

    @Override
    public Node visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), null);
        visitSubstitutionNode(node.getBody(), null);
        return null;
    }

    @Override
    public Node visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        visitExprNode(node.getExpression(), null);
        return null;
    }

    @Override
    public Node visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), null);
        return null;
    }

    @Override
    public Node visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        node.getArguments().forEach(expr -> visitExprNode(expr, null));
        return null;
    }

    @Override
    public Node visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(subs -> visitSubstitutionNode(subs, null));
        return null;
    }

    public Map<String, DeclarationNode> getReplacements() {
        return replacements;
    }

    public Map<String, ExprNode> getReplacementsExpressions() {
        return replacementsExpressions;
    }

    public List<String> getConstants() {
        return constants;
    }
}
