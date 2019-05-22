package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.expression.ExprNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

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

    private static final List<ExpressionOperatorNode.ExpressionOperator> TOTAL_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> PARTIAL_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> SURJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION, ExpressionOperatorNode.ExpressionOperator.PARTIAL_SURJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> INJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_INJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_INJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> BIJECTIVE_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_BIJECTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_BIJECTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> FUNCTION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.PARTIAL_FUNCTION, ExpressionOperatorNode.ExpressionOperator.TOTAL_FUNCTION);

    private static final List<ExpressionOperatorNode.ExpressionOperator> RELATION_EXPRESSIONS =
            Arrays.asList(ExpressionOperatorNode.ExpressionOperator.SET_RELATION, ExpressionOperatorNode.ExpressionOperator.SURJECTION_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_RELATION, ExpressionOperatorNode.ExpressionOperator.TOTAL_SURJECTION_RELATION);

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final NameHandler nameHandler;

    private final InfiniteNumberSetGenerator infiniteNumberSetGenerator;

    public RelationSetGenerator(STGroup group, MachineGenerator machineGenerator, NameHandler nameHandler, InfiniteNumberSetGenerator infiniteNumberSetGenerator) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.nameHandler = nameHandler;
        this.infiniteNumberSetGenerator = infiniteNumberSetGenerator;
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

    public String generateRelation(PredicateOperatorWithExprArgsNode node) {
        List<String> predicates = new ArrayList<>();
        ST template = currentGroup.getInstanceOf("relation_predicate");
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode.ExpressionOperator rhsOperator = ((ExpressionOperatorNode) rhs).getOperator();
        predicates.add(generateTotalPartial(node, rhsOperator));
        predicates.add(generateRelationFunction(node, rhsOperator));
        predicates.add(generateSurjectionInjectionBijection(node, rhsOperator));
        predicates = predicates.stream()
                .filter(str -> !str.isEmpty())
                .collect(Collectors.toList());
        String firstPredicate = predicates.get(0);
        TemplateHandler.add(template, "predicates", predicates.subList(1, predicates.size()).stream()
                                .reduce(firstPredicate, (a,e) -> {
                                    ST binary = currentGroup.getInstanceOf("binary");
                                    TemplateHandler.add(binary, "arg1", a);
                                    TemplateHandler.add(binary, "operator", nameHandler.handle("and"));
                                    TemplateHandler.add(binary, "arg2", e);
                                    return binary.render();
                                }));
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

    private String generateInfiniteTotalPartial(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator, ExpressionOperatorNode.ExpressionOperator domainOperator) {
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(TOTAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteTotalRelation(domainOperator));
        } else if(PARTIAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfinitePartialRelation(domainOperator));
        } else {
            return "";
        }
        return template.render();
    }

    private String generateTotalPartial(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode domain = relation.getExpressionNodes().get(0);
        if(domain instanceof ExpressionOperatorNode) {
            ExpressionOperatorNode.ExpressionOperator domainOperator = ((ExpressionOperatorNode) domain).getOperator();
            if(infiniteNumberSetGenerator.isInfiniteExpression(domainOperator)) {
                return generateInfiniteTotalPartial(node, operator, domainOperator);
            }
        }

        ST template = currentGroup.getInstanceOf("relation_total_partial");
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(TOTAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isTotal");
        } else if(PARTIAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isPartial");
        } else {
            return "";
        }

        TemplateHandler.add(template, "domain", machineGenerator.visitExprNode(domain, null));
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

    private String generateInfiniteSurjectionInjectionBijection(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator, ExpressionOperatorNode.ExpressionOperator rangeOperator) {
        ST template = currentGroup.getInstanceOf("infinite_predicate");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if(SURJECTIVE_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteSurjection(rangeOperator));
        } else if(BIJECTIVE_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", generateInfiniteBijection(rangeOperator));
        } else {
            return "";
        }
        return template.render();
    }

    private String generateSurjectionInjectionBijection(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        ExprNode range = relation.getExpressionNodes().get(1);
        if(range instanceof ExpressionOperatorNode) {
            ExpressionOperatorNode.ExpressionOperator rangeOperator = ((ExpressionOperatorNode) range).getOperator();
            if(infiniteNumberSetGenerator.isInfiniteExpression(rangeOperator)) {
                return generateInfiniteSurjectionInjectionBijection(node, operator, rangeOperator);
            }
        }

        ST template;
        if(SURJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_surjection");
        } else if(INJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_injection");
        } else if(BIJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_bijection");
        } else {
            return "";
        }
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        TemplateHandler.add(template, "range", machineGenerator.visitExprNode(relation.getExpressionNodes().get(1), null));
        return template.render();
    }

    private String generateRelationFunction(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ST template = currentGroup.getInstanceOf("relation_function");
        ExprNode lhs = node.getExpressionNodes().get(0);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if (RELATION_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isRelation");
        } else if(FUNCTION_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isFunction");
        } else {
            return "";
        }
        return template.render();
    }

}
