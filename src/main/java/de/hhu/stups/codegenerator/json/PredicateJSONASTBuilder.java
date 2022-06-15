package de.hhu.stups.codegenerator.json;

import de.prob.parser.ast.nodes.predicate.IdentifierPredicateNode;
import de.prob.parser.ast.nodes.predicate.IfPredicateNode;
import de.prob.parser.ast.nodes.predicate.LetPredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.QuantifiedPredicateNode;
import de.prob.parser.ast.visitors.generic.ParametrisedPredicateVisitor;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class PredicateJSONASTBuilder implements ParametrisedPredicateVisitor<Map<String, Object>, Void> {

    private JSONASTBuilder jsonASTBuilder;

    public PredicateJSONASTBuilder() {
    }

    public void setJsonASTBuilder(JSONASTBuilder jsonASTBuilder) {
        this.jsonASTBuilder = jsonASTBuilder;
    }

    public Map<String, Object> visitPredicate(PredicateNode predicateNode) {
        if(predicateNode instanceof IdentifierPredicateNode) {
            return visitIdentifierPredicateNode((IdentifierPredicateNode) predicateNode, null);
        } else if(predicateNode instanceof PredicateOperatorNode) {
            return visitPredicateOperatorNode((PredicateOperatorNode) predicateNode, null);
        } else if(predicateNode instanceof PredicateOperatorWithExprArgsNode) {
            return visitPredicateOperatorWithExprArgs((PredicateOperatorWithExprArgsNode) predicateNode, null);
        } else if(predicateNode instanceof QuantifiedPredicateNode) {
            return visitQuantifiedPredicateNode((QuantifiedPredicateNode) predicateNode, null);
        } else if(predicateNode instanceof LetPredicateNode) {
            return visitLetPredicateNode((LetPredicateNode) predicateNode, null);
        } else if(predicateNode instanceof IfPredicateNode) {
            return visitIfPredicateNode((IfPredicateNode) predicateNode, null);
        } else {
            throw new RuntimeException("Predicate node unknown: " + predicateNode.getClass());
        }
    }


    @Override
    public Map<String, Object> visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "identifier");
        result.put("val", node.getName());
        return result;
    }

    @Override
    public Map<String, Object> visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "predicate");
        result.put("operator", node.getOperator());
        result.put("predicates", node.getPredicateArguments().stream()
                .map(this::visitPredicate)
                .collect(Collectors.toList()));
        return result;
    }

    @Override
    public Map<String, Object> visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "predicate");
        result.put("operator", node.getOperator());
        result.put("predicates", node.getExpressionNodes().stream()
                .map(jsonASTBuilder::visitExpression)
                .collect(Collectors.toList()));
        return result;
    }

    @Override
    public Map<String, Object> visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "quantified_predicate");
        result.put("operator", node.getOperator());
        result.put("bounded_variables", jsonASTBuilder.visitDeclarations(node.getDeclarationList()));
        result.put("predicate", visitPredicate(node.getPredicateNode()));
        return result;
    }

    @Override
    public Map<String, Object> visitLetPredicateNode(LetPredicateNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "let_predicate");
        result.put("bounded_variables", jsonASTBuilder.visitDeclarations(node.getLocalIdentifiers()));
        result.put("predicate", visitPredicate(node.getPredicate()));
        result.put("where_predicate", visitPredicate(node.getWherePredicate()));
        return result;
    }

    @Override
    public Map<String, Object> visitIfPredicateNode(IfPredicateNode node, Void expected) {
        Map<String, Object> result = new HashMap<>();
        result.put("type", "if_predicate");
        result.put("condition", visitPredicate(node.getCondition()));
        result.put("then", visitPredicate(node.getThenPredicate()));
        result.put("else", visitPredicate(node.getElsePredicate()));
        return result;
    }
}
