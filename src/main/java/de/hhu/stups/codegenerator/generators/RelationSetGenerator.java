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

    private String generateTotalPartial(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ST template = currentGroup.getInstanceOf("relation_total_partial");
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        if (TOTAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isTotal");
        } else if(PARTIAL_EXPRESSIONS.contains(operator)) {
            TemplateHandler.add(template, "operator", "isPartial");
        } else {
            return "";
        }
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        TemplateHandler.add(template, "domain", machineGenerator.visitExprNode(relation.getExpressionNodes().get(0), null));
        return template.render();
    }

    private String generateSurjectionInjectionBijection(PredicateOperatorWithExprArgsNode node, ExpressionOperatorNode.ExpressionOperator operator) {
        ST template = null;
        if(SURJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_surjection");
        } else if(INJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_injection");
        } else if(BIJECTIVE_EXPRESSIONS.contains(operator)) {
            template = currentGroup.getInstanceOf("relation_bijection");
        } else {
            return "";
        }
        ExprNode lhs = node.getExpressionNodes().get(0);
        ExprNode rhs = node.getExpressionNodes().get(1);
        TemplateHandler.add(template, "arg", machineGenerator.visitExprNode(lhs, null));
        ExpressionOperatorNode relation = (ExpressionOperatorNode) rhs;
        TemplateHandler.add(template, "domain", machineGenerator.visitExprNode(relation.getExpressionNodes().get(0), null));
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
