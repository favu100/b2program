package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;
import java.util.stream.Collectors;

public class LambdaFunctionGenerator {

    private final STGroup group;

    private final ExpressionGenerator expressionGenerator;

    private final PredicateGenerator predicateGenerator;

    private final TypeGenerator typeGenerator;

    private final DeclarationGenerator declarationGenerator;

    public LambdaFunctionGenerator(final STGroup group, final ExpressionGenerator expressionGenerator, final PredicateGenerator predicateGenerator,
                                   final TypeGenerator typeGenerator, final DeclarationGenerator declarationGenerator) {
        this.group = group;
        this.expressionGenerator = expressionGenerator;
        this.predicateGenerator = predicateGenerator;
        this.typeGenerator = typeGenerator;
        this.declarationGenerator = declarationGenerator;
        this.declarationGenerator.setLambdaFunctionGenerator(this);
    }

    public List<String> generateFunctions(MachineNode node) {
        return node.getConstants().stream()
                .map(constant -> generateFunction(node, constant))
                .collect(Collectors.toList());
    }

    public List<String> getLambdaFunctions(MachineNode node) {
        return node.getConstants().stream()
                .filter(constant -> isLambdaFunction(node, constant))
                .map(DeclarationNode::getName)
                .collect(Collectors.toList());
    }

    private boolean isLambdaFunction(MachineNode node, DeclarationNode constant) {
        List<PredicateNode> equalProperties = predicateGenerator.extractEqualProperties(node, constant);
        if(equalProperties.isEmpty()) {
            return false;
        }
        ExprNode expression = ((PredicateOperatorWithExprArgsNode) equalProperties.get(0)).getExpressionNodes().get(1);
        if(!(expression instanceof LambdaNode)) {
            return false;
        } else if(!checkPredicate((LambdaNode) expression)) {
            return false;
        }
        return true;
    }

    public String generateFunction(MachineNode node, DeclarationNode constant) {
        if(!isLambdaFunction(node, constant)) {
            return "";
        }
        List<PredicateNode> equalProperties = predicateGenerator.extractEqualProperties(node, constant);
        ExprNode expression = ((PredicateOperatorWithExprArgsNode) equalProperties.get(0)).getExpressionNodes().get(1);
        LambdaNode lambda = (LambdaNode) expression;
        ST template = group.getInstanceOf("lambda_function");
        TemplateHandler.add(template, "function", constant.getName());
        TemplateHandler.add(template, "parameters", declarationGenerator.generateDeclarations(lambda.getDeclarations(), OperationGenerator.DeclarationType.PARAMETER, false));
        TemplateHandler.add(template, "returnType", typeGenerator.generate(lambda.getExpression().getType()));
        TemplateHandler.add(template, "expression", expressionGenerator.visitExprNode(lambda.getExpression()));
        return template.render();
    }

    public boolean checkPredicate(LambdaNode node) {
        PredicateNode predicate = node.getPredicate();
        List<DeclarationNode> declarations = node.getDeclarations();
        if(!(predicate instanceof PredicateOperatorNode)) {
            if(declarations.size() != 1) {
                return false;
            }
        } else {
            PredicateOperatorNode predicateOperatorNode = ((PredicateOperatorNode) predicate);
            if(predicateOperatorNode.getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
                return false;
            }
            return checkPredicateTyping(declarations, predicateOperatorNode);
        }
        return true;
    }

    private boolean checkPredicateType(ExprNode expression) {
        if(expression instanceof ExpressionOperatorNode) {
            ExpressionOperatorNode.ExpressionOperator operator = ((ExpressionOperatorNode) expression).getOperator();
            List<ExprNode> subexpressions = ((ExpressionOperatorNode) expression).getExpressionNodes();
            switch (operator) {
                case POW:
                    return checkPredicateType(subexpressions.get(0));
                case CARTESIAN_PRODUCT:
                    return checkPredicateType(subexpressions.get(0)) && checkPredicateType(subexpressions.get(1));
                case BOOL:
                    return true;
                case INTEGER:
                    return true;
                default:
                    break;
            }
        }
        return false;
    }

    private boolean checkPredicateTyping(List<DeclarationNode> declarations, PredicateOperatorNode predicate) {
        for(int i = 0; i < declarations.size(); i++) {
            PredicateNode innerPredicate = predicate.getPredicateArguments().get(i);
            if(!(innerPredicate instanceof PredicateOperatorWithExprArgsNode)) {
                return false;
            } else {
                List<ExprNode> expressions = ((PredicateOperatorWithExprArgsNode) innerPredicate).getExpressionNodes();
                checkPredicateType(expressions.get(1));
            }
        }
        return true;
    }

}
