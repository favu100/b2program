package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.Arrays;
import java.util.List;

/**
 * Created by fabian on 21.05.19.
 */
public class RelationSetGenerator {

    private static final List<PredicateOperatorWithExprArgsNode.PredOperatorExprArgs> RELATION_FUNCTION_PREDICATE_OPERATORS =
            Arrays.asList(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF);

    private static final List<ExpressionOperatorNode.ExpressionOperator> RELATION_FUNCTION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SET_RELATION, ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION,
                    ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION,
                    ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION);

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    public RelationSetGenerator(STGroup group, MachineGenerator machineGenerator, NameHandler nameHandler) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
    }

    public boolean checkRelation(PredicateOperatorWithExprArgsNode node) {
        List<ExprNode> expressions = node.getExpressionNodes();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(expressions.size() == 2 && RELATION_FUNCTION_PREDICATE_OPERATORS.contains(operator)) {
            ExprNode rhs = node.getExpressionNodes().get(1);
            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
                if(RELATION_FUNCTION_EXPRESSIONS.contains(rhsOperator)) {
                    return true;
                }
            }
        }
        return false;
    }

    private String generateRelationPredicate(ExpressionOperatorNode.ExpressionOperator operator) {
        String operatorName;
        switch (operator) {
            case SET_RELATION:
                operatorName = "isRelation";
                break;
            case PARTIAL_INJECTION:
                operatorName = "isPartialInjection";
                break;
            case PARTIAL_SURJECTION:
                operatorName = "isPartialSurjection";
                break;
            case PARTIAL_BIJECTION:
                operatorName = "isPartialBijection";
                break;
            case PARTIAL_FUNCTION:
                operatorName = "isPartialFunction";
                break;
            case TOTAL_RELATION:
                operatorName = "isTotalRelation";
                break;
            case TOTAL_INJECTION:
                operatorName = "isTotalInjection";
                break;
            case TOTAL_SURJECTION:
                operatorName = "isTotalSurjection";
                break;
            case TOTAL_SURJECTION_RELATION:
                operatorName = "isTotalSurjectionRelation";
                break;
            case TOTAL_BIJECTION:
                operatorName = "isTotalBijection";
                break;
            case TOTAL_FUNCTION:
                operatorName = "isTotalFunction";
                break;
            case SURJECTION_RELATION:
                operatorName = "isSurjectionRelation";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    public String generateRelation(PredicateOperatorWithExprArgsNode node) {
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        ST template = currentGroup.getInstanceOf("relation_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
        String operatorName = generateRelationPredicate(rhsOperator);
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template.render();
    }

}
