package de.hhu.stups.codegenerator.json;

import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class JSONASTBuilder {

    private final ExpressionJSONASTBuilder expressionJSONASTBuilder;

    private final PredicateJSONASTBuilder predicateJSONASTBuilder;

    public JSONASTBuilder() {
        this.expressionJSONASTBuilder = new ExpressionJSONASTBuilder();
        this.predicateJSONASTBuilder = new PredicateJSONASTBuilder();
        this.expressionJSONASTBuilder.setJsonASTBuilder(this);
        this.predicateJSONASTBuilder.setJsonASTBuilder(this);
    }

    public Map<String, Object> visitExpression(ExprNode exprNode) {
        return expressionJSONASTBuilder.visitExpression(exprNode);
    }

    public Map<String, Object> visitPredicate(PredicateNode predicateNode) {
        return predicateJSONASTBuilder.visitPredicate(predicateNode);
    }

    public List<String> visitDeclarations(List<DeclarationNode> declarations) {
        return declarations.stream().map(DeclarationNode::getName).collect(Collectors.toList());
    }


    public Map<String, Object> visitDeclaration(DeclarationNode node) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "identifier");
        result.put("val", node.getName());
        return result;
    }

}
