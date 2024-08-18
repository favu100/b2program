package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
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
import de.prob.parser.ast.nodes.predicate.PredicateNode;
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
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class LambdaFunctionGenerator implements AbstractVisitor<Void, Void> {

    private final STGroup group;

    private final ExpressionGenerator expressionGenerator;

    private final PredicateGenerator predicateGenerator;

    private final TypeGenerator typeGenerator;

    private final DeclarationGenerator declarationGenerator;

    private Set<String> constantsOnlyUsedInFunctionCall;

    public LambdaFunctionGenerator(final STGroup group, final ExpressionGenerator expressionGenerator, final PredicateGenerator predicateGenerator,
                                   final TypeGenerator typeGenerator, final DeclarationGenerator declarationGenerator) {
        this.group = group;
        this.expressionGenerator = expressionGenerator;
        this.predicateGenerator = predicateGenerator;
        this.typeGenerator = typeGenerator;
        this.declarationGenerator = declarationGenerator;
    }

    public void computeConstantsOnlyUsedInFunctionCall(MachineNode machineNode) {
        this.constantsOnlyUsedInFunctionCall = new HashSet<>();
        visitPredicateNode(machineNode.getInvariant(), null);
        machineNode.getOperations()
                .forEach(op -> visitSubstitutionNode(op.getSubstitution(), null));
    }

    public List<String> generateFunctions(MachineNode node) {
        if(node.getInitialisation() != null || !node.getOperations().isEmpty()) {
            return new ArrayList<>();
        }
        return node.getConstants().stream()
                .map(constant -> generateFunction(node, constant))
                .collect(Collectors.toList());
    }

    public List<String> getLambdaFunctions(MachineNode node) {
        if(node.getInitialisation() != null || !node.getOperations().isEmpty()) {
            return new ArrayList<>();
        }
        return node.getConstants().stream()
                .filter(constant -> isLambdaFunction(node, constant))
                .map(DeclarationNode::getName)
                .collect(Collectors.toList());
    }

    public boolean isLambdaFunction(MachineNode node, DeclarationNode constant) {
        List<PredicateNode> equalProperties = predicateGenerator.extractEqualProperties(node, constant);
        if(equalProperties.isEmpty()) {
            return false;
        }
        ExprNode expression = ((PredicateOperatorWithExprArgsNode) equalProperties.get(0)).getExpressionNodes().get(1);
        if(!(expression instanceof LambdaNode)) {
            return false;
        } else if(!checkPredicate((LambdaNode) expression, node)) {
            return false;
        }
        return constantsOnlyUsedInFunctionCall.contains(constant.getName());
    }

    public String generateFunction(MachineNode node, DeclarationNode constant) {
        if(node.getInitialisation() != null || !node.getOperations().isEmpty()) {
            return "";
        }
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

    public boolean checkPredicate(LambdaNode node, MachineNode machineNode) {
        if(machineNode.getInitialisation() != null || !machineNode.getOperations().isEmpty()) {
            return false;
        }
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

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    /*
     * This function checks whether the given identifier is primed. If yes, then it is added to the list of primed identifiers
     */
    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        constantsOnlyUsedInFunctionCall.remove(node.getName());
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
    public Void visitRealNumberNode(RealNumberNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        visitExprNode(node.getExpressionNode(), expected);
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitLambdaNode(LambdaNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitLetExpressionNode(LetExpressionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitExprNode(node.getExpression(), expected);
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
    public Void visitStringNode(StringNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLPrefixOperatorNode(LTLPrefixOperatorNode ltlPrefixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLKeywordNode(LTLKeywordNode ltlKeywordNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLInfixOperatorNode(LTLInfixOperatorNode ltlInfixOperatorNode, Void expected) {
        return null;
    }

    @Override
    public Void visitLTLBPredicateNode(LTLBPredicateNode ltlbPredicateNode, Void expected) {
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
        visitPredicateNode(node.getPredicateNode(), expected);
        return null;
    }

    @Override
    public Void visitLetPredicateNode(LetPredicateNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), expected);
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitIfPredicateNode(IfPredicateNode node, Void expected) {
        visitPredicateNode(node.getCondition(), expected);
        visitPredicateNode(node.getThenPredicate(), expected);
        visitPredicateNode(node.getElsePredicate(), expected);
        return null;
    }

    @Override
    public Void visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        visitSubstitutionNode(node.getBody(), expected);
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
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
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
    public Void visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        node.getLeftSide().forEach(lhs -> {
            if(lhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode.ExpressionOperator operator = ((ExpressionOperatorNode) lhs).getOperator();
                if(operator == ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL) {
                    ExprNode first = ((ExpressionOperatorNode) lhs).getExpressionNodes().get(0);
                    if(first instanceof IdentifierExprNode) {
                        constantsOnlyUsedInFunctionCall.remove(((IdentifierExprNode) first).getName());
                    }
                }
            }
            visitExprNode(lhs, expected);
        });
        node.getRightSide().forEach(rhs -> visitExprNode(rhs, expected));
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

    @Override
    public Void visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        visitPredicateNode(node.getWherePredicate(), expected);
        visitSubstitutionNode(node.getThenSubstitution(), expected);
        return null;
    }

    @Override
    public Void visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        visitSubstitutionNode(node.getBody(), expected);
        return null;
    }

    @Override
    public Void visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        visitExprNode(node.getExpression(), expected);
        return null;
    }

    @Override
    public Void visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        visitPredicateNode(node.getPredicate(), expected);
        return null;
    }

    @Override
    public Void visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        node.getArguments().forEach(arg -> visitExprNode(arg, expected));
        return null;
    }

    @Override
    public Void visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        node.getSubstitutions().forEach(substitution -> visitSubstitutionNode(substitution, expected));
        return null;
    }

    @Override
    public Void visitRecordNode(RecordNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitStructNode(StructNode node, Void expected) {
        return null;
    }

    @Override
    public Void visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return null;
    }

}
