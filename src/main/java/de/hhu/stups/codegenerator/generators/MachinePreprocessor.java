package de.hhu.stups.codegenerator.generators;

import de.prob.parser.antlr.Antlr4BParser;
import de.prob.parser.antlr.MachineASTCreator;
import de.prob.parser.ast.SourceCodePosition;
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
import de.prob.parser.ast.nodes.substitution.SubstitutionNode;
import de.prob.parser.ast.nodes.substitution.VarSubstitutionNode;
import de.prob.parser.ast.nodes.substitution.WhileSubstitutionNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.BoolType;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.UntypedType;
import de.prob.parser.ast.visitors.AbstractVisitor;
import de.prob.parser.ast.visitors.TypeChecker;
import de.prob.parser.ast.visitors.TypeErrorException;
import files.BParser;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CodePointCharStream;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;

import static de.prob.parser.antlr.Antlr4BParser.parseExpression;

public class MachinePreprocessor implements AbstractVisitor<Node, Void> {

    private boolean inEnumeration;

    private TypeChecker typeChecker;

    public MachinePreprocessor() {
        this.inEnumeration = false;
    }

    public MachineNode visitMachineNode(MachineNode machineNode) {
        try {
            typeChecker = new TypeChecker(machineNode);
        } catch (TypeErrorException e) {
            throw new RuntimeException(e.getMessage());
        }
        
        // TODO: Process other constructs
        if(machineNode.getProperties() != null) {
            machineNode.setProperties(visitPredicateNode(machineNode.getProperties()));
        }
        if(machineNode.getInvariant() != null) {
            machineNode.setInvariant(visitPredicateNode(machineNode.getInvariant()));
        }
        machineNode.setOperations(machineNode.getOperations().stream()
                .map(this::visitOperationNode)
                .collect(Collectors.toList()));
        return machineNode;
    }

    public OperationNode visitOperationNode(OperationNode operationNode) {
        SubstitutionNode substitution = (SubstitutionNode) visitSubstitutionNode(operationNode.getSubstitution(), null);
        return new OperationNode(operationNode.getSourceCodePosition(), operationNode.getName(), operationNode.getOutputParams(), substitution, operationNode.getParams());
    }

    public PredicateNode visitPredicateNode(PredicateNode predicateNode) {
        if(predicateNode instanceof PredicateOperatorWithExprArgsNode) {
            return (PredicateNode) visitPredicateOperatorWithExprArgs((PredicateOperatorWithExprArgsNode) predicateNode, null);
        } else if(predicateNode instanceof PredicateOperatorNode) {
            return (PredicateNode) visitPredicateOperatorNode((PredicateOperatorNode) predicateNode, null);
        }
        return predicateNode;
    }

    @Override
    public Node visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
       ExpressionOperatorNode.ExpressionOperator operator = node.getOperator();
       switch (operator) {
           case POW:
           case FIN:
           case SEQ:
           case ISEQ1:
               ExpressionOperatorNode expressionNode = new ExpressionOperatorNode(node.getSourceCodePosition(), Collections.emptyList(), ExpressionOperatorNode.ExpressionOperator.EMPTY_SET);
               typeChecker.checkExprNode(expressionNode);
               return expressionNode;
           default:
               break;
       }
       return new ExpressionOperatorNode(node.getSourceCodePosition(), node.getExpressionNodes().stream()
                .map(expr -> (ExprNode) visitExprNode(expr, null))
                .collect(Collectors.toList()), node.getOperator());
    }

    @Override
    public Node visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitNumberNode(NumberNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRealNumberNode(RealNumberNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitQuantifiedExpressionNode(QuantifiedExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLambdaNode(LambdaNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetExpressionNode(LetExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfExpressionNode(IfExpressionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitStringNode(StringNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRecordNode(RecordNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitStructNode(StructNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLPrefixOperatorNode(LTLPrefixOperatorNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLKeywordNode(LTLKeywordNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLInfixOperatorNode(LTLInfixOperatorNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLTLBPredicateNode(LTLBPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIdentifierPredicateNode(IdentifierPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitPredicateOperatorNode(PredicateOperatorNode node, Void expected) {
        return new PredicateOperatorNode(node.getSourceCodePosition(), node.getOperator(), node.getPredicateArguments().stream()
                .map(this::visitPredicateNode)
                .collect(Collectors.toList()));
    }

    @Override
    public Node visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        SourceCodePosition sourceCodePosition = node.getSourceCodePosition();
        PredicateOperatorWithExprArgsNode.PredOperatorExprArgs operator = node.getOperator();
        if(operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF) {
            ExprNode lhs = node.getExpressionNodes().get(0);
            ExprNode rhs = node.getExpressionNodes().get(1);

            ExprNode newRhs = rhs;
            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode rhsAsExpression = ((ExpressionOperatorNode) rhs);
                ExpressionOperatorNode.ExpressionOperator rhsOperator = rhsAsExpression.getOperator();
                switch(rhsOperator) {
                    case NAT: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new NumberNode(sourceCodePosition, new BigInteger(String.valueOf(0))),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case NAT1: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new NumberNode(sourceCodePosition, new BigInteger(String.valueOf(1))),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INT: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MININT),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case SET_ENUMERATION: {
                        if (rhsAsExpression.getExpressionNodes().size() == 1) {
                            newRhs = rhsAsExpression.getExpressionNodes().get(0);
                            List<ExprNode> expressions = new ArrayList<>();
                            expressions.add(lhs);
                            expressions.add(newRhs);
                            PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL, expressions);
                            predicateNode.setType(new UntypedType());
                            typeChecker.checkPredicateNode(predicateNode);
                            predicateNode = visitPredicateNode(predicateNode);
                            return predicateNode;
                        }
                        return node;
                    }
                    case INTERVAL: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.GREATER_EQUAL, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.LESS_EQUAL, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case UNION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INTERSECTION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case SET_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case FIN:
                    case POW: {
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0)));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case FIN1:
                    case POW1: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        ExpressionOperatorNode emptySetNode = new ExpressionOperatorNode(node.getSourceCodePosition(), ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION);
                        typeChecker.checkExprNode(lhs);
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_EQUAL, Arrays.asList(lhs, emptySetNode)));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.INCLUSION, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case ID: {
                        List<PredicateNode> predicates = new ArrayList<>();


                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL, Arrays.asList(projection1, projection2)));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INVERSE_RELATION: {
                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        ExpressionOperatorNode mapletProjection = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection2, projection1), ExpressionOperatorNode.ExpressionOperator.COUPLE);

                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(mapletProjection, rhsAsExpression.getExpressionNodes().get(0)));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case CARTESIAN_PRODUCT: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case RANGE_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case RANGE_RESTRICTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case DOMAIN_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case DOMAIN_RESTRICTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case PARALLEL_PRODUCT: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftTypeTopLevel = ((CoupleType) lhs.getType()).getLeft();
                        BType rightTypeTopLevel = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNodeTopLevel = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftTypeTopLevel.toString())));
                        ExprNode rightNodeTopLevel = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightTypeTopLevel.toString())));

                        ExpressionOperatorNode innerLhs = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNodeTopLevel, rightNodeTopLevel), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode innerRhs = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNodeTopLevel, rightNodeTopLevel), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        BType leftType1 = ((CoupleType) ((CoupleType) lhs.getType()).getLeft()).getLeft();
                        BType rightType1 = ((CoupleType) ((CoupleType) lhs.getType()).getLeft()).getRight();

                        ExprNode leftNode1 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType1.toString())));
                        ExprNode rightNode1 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType1.toString())));

                        ExpressionOperatorNode projection11 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode1, rightNode1), ExpressionOperatorNode.ExpressionOperator.PRJ1), innerLhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection12 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode1, rightNode1), ExpressionOperatorNode.ExpressionOperator.PRJ2), innerLhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        BType leftType2 = ((CoupleType) ((CoupleType) lhs.getType()).getRight()).getLeft();
                        BType rightType2 = ((CoupleType) ((CoupleType) lhs.getType()).getRight()).getRight();

                        ExprNode leftNode2 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType2.toString())));
                        ExprNode rightNode2 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType2.toString())));

                        ExpressionOperatorNode projection21 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode2, rightNode2), ExpressionOperatorNode.ExpressionOperator.PRJ1), innerRhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection22 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode2, rightNode2), ExpressionOperatorNode.ExpressionOperator.PRJ2), innerRhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection11, projection21), ExpressionOperatorNode.ExpressionOperator.COUPLE);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection12, projection22), ExpressionOperatorNode.ExpressionOperator.COUPLE);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    default:
                        break;
                }
            }
        } else if(operator == PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING) {
            ExprNode lhs = node.getExpressionNodes().get(0);
            ExprNode rhs = node.getExpressionNodes().get(1);

            if(rhs instanceof ExpressionOperatorNode) {
                ExpressionOperatorNode rhsAsExpression = ((ExpressionOperatorNode) rhs);
                ExpressionOperatorNode.ExpressionOperator rhsOperator = rhsAsExpression.getOperator();
                switch(rhsOperator) {
                    case NAT: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new NumberNode(sourceCodePosition, new BigInteger(String.valueOf(0))),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case NAT1: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new NumberNode(sourceCodePosition, new BigInteger(String.valueOf(1))),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INT: {
                        ExprNode newExpression = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MININT),
                                new ExpressionOperatorNode(sourceCodePosition, ExpressionOperatorNode.ExpressionOperator.MAXINT)
                        ), ExpressionOperatorNode.ExpressionOperator.INTERVAL);
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, newExpression));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INTERVAL: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.LESS, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.GREATER, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case UNION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.AND, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);return predicateNode;
                    }
                    case INTERSECTION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case SET_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case FIN:
                    case POW: {
                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NON_INCLUSION, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0)));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case FIN1:
                    case POW1: {
                        List<PredicateNode> predicates = new ArrayList<>();
                        ExpressionOperatorNode emptySetNode = new ExpressionOperatorNode(node.getSourceCodePosition(), ExpressionOperatorNode.ExpressionOperator.SET_ENUMERATION);
                        typeChecker.checkExprNode(lhs);
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL, Arrays.asList(lhs, emptySetNode)));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NON_INCLUSION, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));
                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case ID: {
                        List<PredicateNode> predicates = new ArrayList<>();


                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_EQUAL, Arrays.asList(projection1, projection2)));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case INVERSE_RELATION: {
                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        ExpressionOperatorNode mapletProjection = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection2, projection1), ExpressionOperatorNode.ExpressionOperator.COUPLE);

                        PredicateNode predicateNode = new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(mapletProjection, rhsAsExpression.getExpressionNodes().get(0)));
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case CARTESIAN_PRODUCT: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case RANGE_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case RANGE_RESTRICTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(0))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case DOMAIN_SUBTRACTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.ELEMENT_OF, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case DOMAIN_RESTRICTION: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftType = ((CoupleType) lhs.getType()).getLeft();
                        BType rightType = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType.toString())));
                        ExprNode rightNode = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType.toString())));

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode, rightNode), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(lhs, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    case PARALLEL_PRODUCT: {
                        List<PredicateNode> predicates = new ArrayList<>();

                        BType leftTypeTopLevel = ((CoupleType) lhs.getType()).getLeft();
                        BType rightTypeTopLevel = ((CoupleType) lhs.getType()).getRight();

                        ExprNode leftNodeTopLevel = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftTypeTopLevel.toString())));
                        ExprNode rightNodeTopLevel = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightTypeTopLevel.toString())));

                        ExpressionOperatorNode innerLhs = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNodeTopLevel, rightNodeTopLevel), ExpressionOperatorNode.ExpressionOperator.PRJ1), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode innerRhs = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNodeTopLevel, rightNodeTopLevel), ExpressionOperatorNode.ExpressionOperator.PRJ2), lhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        BType leftType1 = ((CoupleType) ((CoupleType) lhs.getType()).getLeft()).getLeft();
                        BType rightType1 = ((CoupleType) ((CoupleType) lhs.getType()).getLeft()).getRight();

                        ExprNode leftNode1 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType1.toString())));
                        ExprNode rightNode1 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType1.toString())));

                        ExpressionOperatorNode projection11 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode1, rightNode1), ExpressionOperatorNode.ExpressionOperator.PRJ1), innerLhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection12 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode1, rightNode1), ExpressionOperatorNode.ExpressionOperator.PRJ2), innerLhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        BType leftType2 = ((CoupleType) ((CoupleType) lhs.getType()).getRight()).getLeft();
                        BType rightType2 = ((CoupleType) ((CoupleType) lhs.getType()).getRight()).getRight();

                        ExprNode leftNode2 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(leftType2.toString())));
                        ExprNode rightNode2 = MachineASTCreator.createExpressionAST(parseExpression(CharStreams.fromString(rightType2.toString())));

                        ExpressionOperatorNode projection21 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode2, rightNode2), ExpressionOperatorNode.ExpressionOperator.PRJ1), innerRhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);
                        ExpressionOperatorNode projection22 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(leftNode2, rightNode2), ExpressionOperatorNode.ExpressionOperator.PRJ2), innerRhs), ExpressionOperatorNode.ExpressionOperator.FUNCTION_CALL);

                        ExpressionOperatorNode projection1 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection11, projection21), ExpressionOperatorNode.ExpressionOperator.COUPLE);
                        ExpressionOperatorNode projection2 = new ExpressionOperatorNode(sourceCodePosition, Arrays.asList(projection12, projection22), ExpressionOperatorNode.ExpressionOperator.COUPLE);

                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection1, rhsAsExpression.getExpressionNodes().get(0))));
                        predicates.add(new PredicateOperatorWithExprArgsNode(sourceCodePosition, PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.NOT_BELONGING, Arrays.asList(projection2, rhsAsExpression.getExpressionNodes().get(1))));

                        PredicateNode predicateNode = new PredicateOperatorNode(sourceCodePosition, PredicateOperatorNode.PredicateOperator.OR, predicates);
                        predicateNode.setType(new UntypedType());
                        typeChecker.checkPredicateNode(predicateNode);
                        predicateNode = visitPredicateNode(predicateNode);
                        return predicateNode;
                    }
                    default:
                        break;
                }
            }
        }
        return node;
    }

    @Override
    public Node visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetPredicateNode(LetPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfPredicateNode(IfPredicateNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        return new IfOrSelectSubstitutionsNode(node.getSourceCodePosition(), node.getOperator(),
                node.getConditions().stream().map(this::visitPredicateNode).collect(Collectors.toList()),
                node.getSubstitutions().stream().map(subs -> (SubstitutionNode) this.visitSubstitutionNode(subs, null)).collect(Collectors.toList()),
                node.getElseSubstitution() == null ? null : (SubstitutionNode) visitSubstitutionNode(node.getElseSubstitution(), null));
    }

    @Override
    public Node visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        return node;
    }
}
