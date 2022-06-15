package de.hhu.stups.codegenerator.json;

import de.prob.parser.ast.nodes.expression.ExprNode;
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
import de.prob.parser.ast.nodes.predicate.CastPredicateExpressionNode;
import de.prob.parser.ast.visitors.generic.ParametrisedExpressionVisitor;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class ExpressionJSONASTBuilder implements ParametrisedExpressionVisitor<Map<String, Object>, Void> {

    private JSONASTBuilder jsonASTBuilder;

    public ExpressionJSONASTBuilder() {
    }

    public void setJsonASTBuilder(JSONASTBuilder jsonASTBuilder) {
        this.jsonASTBuilder = jsonASTBuilder;
    }

    public Map<String, Object> visitExpression(ExprNode exprNode) {
        if(exprNode instanceof ExpressionOperatorNode) {
            return visitExprOperatorNode((ExpressionOperatorNode) exprNode, null);
        } else if(exprNode instanceof IdentifierExprNode) {
            return visitIdentifierExprNode((IdentifierExprNode) exprNode, null);
        } else if(exprNode instanceof CastPredicateExpressionNode) {
            return visitCastPredicateExpressionNode((CastPredicateExpressionNode) exprNode, null);
        } else if(exprNode instanceof NumberNode) {
            return visitNumberNode((NumberNode) exprNode, null);
        } else if(exprNode instanceof QuantifiedExpressionNode) {
            return visitQuantifiedExpressionNode((QuantifiedExpressionNode) exprNode, null);
        } else if(exprNode instanceof SetComprehensionNode) {
            return visitSetComprehensionNode((SetComprehensionNode) exprNode, null);
        } else if(exprNode instanceof LambdaNode) {
            return visitLambdaNode((LambdaNode) exprNode, null);
        } else if(exprNode instanceof LetExpressionNode) {
            return visitLetExpressionNode((LetExpressionNode) exprNode, null);
        } else if(exprNode instanceof IfExpressionNode) {
            return visitIfExpressionNode((IfExpressionNode) exprNode, null);
        } else if(exprNode instanceof StringNode) {
            return visitStringNode((StringNode) exprNode, null);
        } else if(exprNode instanceof RecordNode) {
            return visitRecordNode((RecordNode) exprNode, null);
        } else if(exprNode instanceof StructNode) {
            return visitStructNode((StructNode) exprNode, null);
        } else if(exprNode instanceof RecordFieldAccessNode) {
            return visitRecordFieldAccessNode((RecordFieldAccessNode) exprNode, null);
        } else {
            throw new RuntimeException("Expression node unknown: " + exprNode.getClass());
        }
    }

    @Override
    public Map<String, Object> visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        return null;
    }

    @Override
    public Map<String, Object> visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "identifier");
        result.put("val", node.getName());
        return result;
    }

    @Override
    public Map<String, Object> visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "cast");
        result.put("val", jsonASTBuilder.visitPredicate(node.getPredicate()));
        return result;
    }

    @Override
    public Map<String, Object> visitNumberNode(NumberNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "number");
        result.put("val", node.getValue().toString());
        return result;
    }

    @Override
    public Map<String, Object> visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "quantified_expression");
        result.put("operator", node.getOperator().toString());
        result.put("val", visitExpression(node.getExpressionNode()));
        return result;
    }

    @Override
    public Map<String, Object> visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "set_comprehension");
        result.put("bounded_variables", jsonASTBuilder.visitDeclarations(node.getDeclarationList()));
        result.put("predicate", jsonASTBuilder.visitPredicate(node.getPredicateNode()));
        return result;
    }

    @Override
    public Map<String, Object> visitLambdaNode(LambdaNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "lambda");
        result.put("bounded_variables", jsonASTBuilder.visitDeclarations(node.getDeclarations()));
        result.put("predicate", jsonASTBuilder.visitPredicate(node.getPredicate()));
        result.put("expression", visitExpression(node.getExpression()));
        return result;
    }

    @Override
    public Map<String, Object> visitLetExpressionNode(LetExpressionNode node, Void expected) {
        return null;
    }

    @Override
    public Map<String, Object> visitIfExpressionNode(IfExpressionNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "if_expression");
        result.put("condition", jsonASTBuilder.visitPredicate(node.getCondition()));
        result.put("then", visitExpression(node.getThenExpression()));
        result.put("else", visitExpression(node.getElseExpression()));
        return result;
    }

    @Override
    public Map<String, Object> visitStringNode(StringNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "string");
        result.put("val", node.getValue());
        return result;
    }

    @Override
    public Map<String, Object> visitRecordNode(RecordNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "record");
        result.put("variables", jsonASTBuilder.visitDeclarations(node.getDeclarations()));
        result.put("expressions", node.getExpressions().stream()
                .map(this::visitExpression)
                .collect(Collectors.toList()));
        return result;
    }

    @Override
    public Map<String, Object> visitStructNode(StructNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "struct");
        result.put("variables", jsonASTBuilder.visitDeclarations(node.getDeclarations()));
        result.put("expressions", node.getExpressions().stream()
                .map(this::visitExpression)
                .collect(Collectors.toList()));
        return result;
    }

    @Override
    public Map<String, Object> visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return null;
    }

}
