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
public class InfiniteNumberSetGenerator {

    private static final List<PredicateOperatorWithExprArgsNode.PredOperatorExprArgs> INFINITE_PREDICATE_OPERATORS =
            Arrays.asList(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION,
                    PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_INCLUSION, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NON_INCLUSION, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.STRICT_NON_INCLUSION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> INFINITE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.INTEGER, ExpressionOperatorNode.ExpressionOperator.NATURAL, ExpressionOperatorNode.ExpressionOperator.NATURAL1);

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    public InfiniteNumberSetGenerator(STGroup group, MachineGenerator machineGenerator, NameHandler nameHandler) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
    }

    public boolean checkInfinite(PredicateOperatorWithExprArgsNode node) {
        List<ExprNode> expressions = node.getExpressionNodes();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(expressions.size() == 2 && INFINITE_PREDICATE_OPERATORS.contains(operator)) {
            ExprNode rhs = node.getExpressionNodes().get(1);
            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
                if(INFINITE_EXPRESSIONS.contains(rhsOperator)) {
                    return true;
                } else if(rhsOperator == ExpressionOperatorNode.ExpressionOperator.POW) {
                    ExprNode innerRhs = ((ExpressionOperatorNode) rhs).getExpressionNodes().get(0);
                    if(innerRhs instanceof ExpressionOperatorNode && INFINITE_EXPRESSIONS.contains(((ExpressionOperatorNode) innerRhs).getOperator()) && operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public boolean isInfiniteExpression(ExpressionOperatorNode.ExpressionOperator operator) {
        return INFINITE_EXPRESSIONS.contains(operator);
    }

    private String generateInfiniteInteger(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isInteger";
                break;
            case NOT_BELONGING:
                operatorName = "isNotInteger";
                break;
            case INCLUSION:
                operatorName = "subsetOfInteger";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfInteger";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfInteger";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfInteger";
                break;
            case EQUAL:
                operatorName = "equalInteger";
                break;
            case NOT_EQUAL:
                operatorName = "unequalInteger";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    private String generateInfiniteNatural(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isNatural";
                break;
            case NOT_BELONGING:
                operatorName = "isNotNatural";
                break;
            case INCLUSION:
                operatorName = "subsetOfNatural";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfNatural";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfNatural";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfNatural";
                break;
            case EQUAL:
                operatorName = "equalNatural";
                break;
            case NOT_EQUAL:
                operatorName = "unequalNatural";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    private String generateInfiniteNatural1(PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator) {
        String operatorName;
        switch (operator) {
            case ELEMENT_OF:
                operatorName = "isNatural1";
                break;
            case NOT_BELONGING:
                operatorName = "isNotNatural1";
                break;
            case INCLUSION:
                operatorName = "subsetOfNatural1";
                break;
            case NON_INCLUSION:
                operatorName = "notSubsetOfNatural1";
                break;
            case STRICT_INCLUSION:
                operatorName = "strictSubsetOfNatural1";
                break;
            case STRICT_NON_INCLUSION:
                operatorName = "notStrictSubsetOfNatural1";
                break;
            case EQUAL:
                operatorName = "equalNatural1";
                break;
            case NOT_EQUAL:
                operatorName = "unequalNatural1";
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        return operatorName;
    }

    public String generateInfinite(PredicateOperatorWithExprArgsNode node) {
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
        String operatorName;
        if (rhsOperator == ExpressionOperatorNode.ExpressionOperator.POW) {
            operator = PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION;
            rhsOperator = ((ExpressionOperatorNode) ((ExpressionOperatorNode) rhs).getExpressionNodes().get(0)).getOperator();
        }
        switch(rhsOperator) {
            case INTEGER:
                operatorName = generateInfiniteInteger(operator);
                break;
            case NATURAL:
                operatorName = generateInfiniteNatural(operator);
                break;
            case NATURAL1:
                operatorName = generateInfiniteNatural1(operator);
                break;
            default:
                throw new RuntimeException("Given node is not implemented: " + operator);
        }
        TemplateHandler.add(template, "operator", nameHandler.handle(operatorName));
        return template.render();
    }

    private String generateInfiniteTotalRelation(ExpressionOperatorNode.ExpressionOperator domainOperator) {
        String operatorName;
        switch(domainOperator) {
            case INTEGER:
                operatorName = "isTotalInteger";
                break;
            case NATURAL:
                operatorName = "isTotalNatural";
                break;
            case NATURAL1:
                operatorName = "isTotalNatural1";
                break;
            default:
                throw new RuntimeException("Argument of relation expressions are not supported");
        }
        return operatorName;
    }

    private String generateInfinitePartialRelation(ExpressionOperatorNode.ExpressionOperator domainOperator) {
        String operatorName;
        switch(domainOperator) {
            case INTEGER:
                operatorName = "isPartialInteger";
                break;
            case NATURAL:
                operatorName = "isPartialNatural";
                break;
            case NATURAL1:
                operatorName = "isPartialNatural1";
                break;
            default:
                throw new RuntimeException("Argument of relation expressions are not supported");
        }
        return operatorName;
    }

    public String generateInfiniteTotalPartial(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator, ExpressionOperatorNode.ExpressionOperator domainOperator) {
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(RelationSetGenerator.TOTAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteTotalRelation(domainOperator));
        } else if(RelationSetGenerator.PARTIAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfinitePartialRelation(domainOperator));
        } else {
            return "";
        }
        return template.render();
    }

    private String generateInfiniteSurjection(ExpressionOperatorNode.ExpressionOperator rangeOperator) {
        String operatorName;
        switch(rangeOperator) {
            case INTEGER:
                operatorName = "isSurjectionInteger";
                break;
            case NATURAL:
                operatorName = "isSurjectionNatural";
                break;
            case NATURAL1:
                operatorName = "isSurjectionNatural1";
                break;
            default:
                throw new RuntimeException("Argument of relation expressions are not supported");
        }
        return operatorName;
    }

    private String generateInfiniteBijection(ExpressionOperatorNode.ExpressionOperator rangeOperator) {
        String operatorName;
        switch(rangeOperator) {
            case INTEGER:
                operatorName = "isBijectionInteger";
                break;
            case NATURAL:
                operatorName = "isBijectionNatural";
                break;
            case NATURAL1:
                operatorName = "isBijectionNatural1";
                break;
            default:
                throw new RuntimeException("Argument of relation expressions are not supported");
        }
        return operatorName;
    }

    public String generateInfiniteSurjectionInjectionBijection(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator, ExpressionOperatorNode.ExpressionOperator rangeOperator) {
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(RelationSetGenerator.SURJECTIVE_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteSurjection(rangeOperator));
        } else if(RelationSetGenerator.BIJECTIVE_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteBijection(rangeOperator));
        } else {
            return "";
        }
        return template.render();
    }

}
