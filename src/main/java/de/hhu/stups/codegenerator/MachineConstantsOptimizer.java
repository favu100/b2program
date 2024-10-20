package de.hhu.stups.codegenerator;

import de.hhu.stups.codegenerator.analyzers.IdentifierAnalyzer;
import de.prob.parser.ast.SourceCodePosition;
import de.prob.parser.ast.nodes.DeclarationNode;
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
import de.prob.parser.ast.types.BoolType;
import de.prob.parser.ast.visitors.AbstractVisitor;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class MachineConstantsOptimizer implements AbstractVisitor<Node, Void> {

    private final MachineNode machineNode;

    private final MachineConstantsPreprocessor preprocessor;

    private final List<PredicateOperatorWithExprArgsNode> newProperties;

    private final boolean forModelChecking;

    private final boolean forVisualization;

    private List<String> boundedVariables;

    public MachineConstantsOptimizer(MachineNode machineNode, boolean forModelChecking, boolean forVisualization) {
        this.newProperties = new ArrayList<>();
        this.preprocessor = new MachineConstantsPreprocessor(machineNode, forModelChecking, forVisualization);
        this.machineNode = machineNode;
        preprocessor.visitMachineNode();
        this.forModelChecking = forModelChecking;
        this.forVisualization = forVisualization;
        this.boundedVariables = new ArrayList<>();
    }

    public MachineNode visitMachineNode() {
        if(forModelChecking || forVisualization) {
            if (machineNode.getInvariant() != null) {
                machineNode.setInvariant((PredicateNode) visitPredicateNode(machineNode.getInvariant(), null));
            }
        }
        preprocessor.getReplacementsExpressions().forEach((key, value) -> createNewProperty(preprocessor.getReplacements().get(key), preprocessor.getReplacementsExpressions().get(key)));
        machineNode.setOperations(machineNode.getOperations().stream()
                .map(this::visitOperationNode)
                .collect(Collectors.toList()));
        machineNode.addConstants(new ArrayList<>(preprocessor.getReplacements().values()));
        if(!newProperties.isEmpty()) {
            PredicateNode newPropertiesAsPredicate = buildNewProperties(machineNode.getProperties(), newProperties);
            machineNode.setProperties(newPropertiesAsPredicate);
        }
        return machineNode;
    }


    private PredicateNode buildNewProperties(PredicateNode machineProperties, List<PredicateOperatorWithExprArgsNode> newProperties) {
        SourceCodePosition position = newProperties.get(0).getSourceCodePosition();
        if(machineProperties == null) {
            List<PredicateNode> newConjuncts = new ArrayList<>(newProperties);
            PredicateOperatorNode result = new PredicateOperatorNode(position, PredicateOperatorNode.PredicateOperator.AND, newConjuncts);
            result.setType(BoolType.getInstance());
            return result;
        }
        if(!(machineProperties instanceof PredicateOperatorNode) || ((PredicateOperatorNode) machineProperties).getOperator() != PredicateOperatorNode.PredicateOperator.AND) {
            List<PredicateNode> newConjuncts = new ArrayList<>();
            newConjuncts.add(machineProperties);
            newConjuncts.addAll(newProperties);
            PredicateOperatorNode result = new PredicateOperatorNode(position, PredicateOperatorNode.PredicateOperator.AND, newConjuncts);
            result.setType(BoolType.getInstance());
            return result;
        }

        List<PredicateNode> machinePropertiesConjuncts = ((PredicateOperatorNode) machineProperties).getPredicateArguments();
        List<PredicateNode> newConjuncts = new ArrayList<>(machinePropertiesConjuncts);
        newConjuncts.addAll(newProperties);
        PredicateOperatorNode result = new PredicateOperatorNode(position, PredicateOperatorNode.PredicateOperator.AND, newConjuncts);
        result.setType(BoolType.getInstance());
        return result;
    }



    private OperationNode visitOperationNode(OperationNode operationNode) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(operationNode.getParams().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        OperationNode result = new OperationNode(operationNode.getSourceCodePosition(), operationNode.getName(), operationNode.getOutputParams(), (SubstitutionNode) visitSubstitutionNode(operationNode.getSubstitution(), null), operationNode.getParams());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    public void createNewProperty(DeclarationNode declaration, ExprNode expr) {
        IdentifierExprNode lhs = new IdentifierExprNode(machineNode.getSourceCodePosition(), declaration.getName(), false);
        lhs.setType(declaration.getType());
        lhs.setDeclarationNode(declaration);
        PredicateOperatorWithExprArgsNode newProperty = new PredicateOperatorWithExprArgsNode(declaration.getSourceCodePosition(), PredicateOperatorWithExprArgsNode.PredOperatorExprArgs.EQUAL, Arrays.asList(lhs, expr));
        newProperty.setType(BoolType.getInstance());
        newProperties.add(newProperty);
    }

    @Override
    public Node visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            identifierAnalyzer.setInnerIdentifiers(boundedVariables.stream().collect(Collectors.toSet()));
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                declarationNode.setType(node.getType());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(node.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        ExpressionOperatorNode result = new ExpressionOperatorNode(node.getSourceCodePosition(), node.getExpressionNodes()
                .stream()
                .map(expr -> (ExprNode) visitExprNode(expr, null))
                .collect(Collectors.toList()), node.getOperator());
        result.setType(node.getType());
        return result;
    }

    @Override
    public Node visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitCastPredicateExpressionNode(CastPredicateExpressionNode node, Void expected) {
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        CastPredicateExpressionNode result = new CastPredicateExpressionNode(node.getSourceCodePosition(), (PredicateNode) visitPredicateNode(node.getPredicate(), null));
        result.setType(node.getType());
        return result;
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
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getDeclarationList().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        QuantifiedExpressionNode result = new QuantifiedExpressionNode(node.getSourceCodePosition(), node.getOperator(), node.getDeclarationList(), (PredicateNode) visitPredicateNode(node.getPredicateNode(), null), (ExprNode) visitExprNode(node.getExpressionNode(), null));
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitSetComprehensionNode(SetComprehensionNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getDeclarationList().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        SetComprehensionNode result = new SetComprehensionNode(node.getSourceCodePosition(), node.getDeclarationList(), (PredicateNode) visitPredicateNode(node.getPredicateNode(), null));
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitLambdaNode(LambdaNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getDeclarations().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        LambdaNode result = new LambdaNode(node.getSourceCodePosition(), node.getDeclarations(), (PredicateNode) visitPredicateNode(node.getPredicate(), null), (ExprNode) visitExprNode(node.getExpression(), null));
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitLetExpressionNode(LetExpressionNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        LetExpressionNode result = new LetExpressionNode(node.getSourceCodePosition(), node.getLocalIdentifiers(), (PredicateNode) visitPredicateNode(node.getPredicate(), null), (ExprNode) visitExprNode(node.getExpression(), null));
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitIfExpressionNode(IfExpressionNode node, Void expected) {
        if(preprocessor.getReplacements().containsKey(node.toString())) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitNode(node, null);
            if(boundedVariables.stream().noneMatch(identifierAnalyzer::containsIdentifier)) {
                DeclarationNode declarationNode = preprocessor.getReplacements().get(node.toString());
                IdentifierExprNode result = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
                result.setType(declarationNode.getType());
                result.setDeclarationNode(declarationNode);
                return result;
            }
        }
        IfExpressionNode result = new IfExpressionNode(node.getSourceCodePosition(), (PredicateNode) visitPredicateNode(node.getCondition(), null), (ExprNode) visitExprNode(node.getThenExpression(), null), (ExprNode) visitExprNode(node.getElseExpression(), null));
        result.setType(node.getType());
        return result;
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
        PredicateOperatorNode result = new PredicateOperatorNode(node.getSourceCodePosition(), node.getOperator(), node.getPredicateArguments().stream()
                .map(pred -> (PredicateNode) visitPredicateNode(pred, null))
                .collect(Collectors.toList()));
        result.setType(node.getType());
        return result;
    }

    @Override
    public Node visitPredicateOperatorWithExprArgs(PredicateOperatorWithExprArgsNode node, Void expected) {
        PredicateOperatorWithExprArgsNode result = new PredicateOperatorWithExprArgsNode(node.getSourceCodePosition(), node.getOperator(), node.getExpressionNodes().stream()
                .map(expr -> (ExprNode) visitExprNode(expr, null))
                .collect(Collectors.toList()));
        result.setType(node.getType());
        return result;
    }

    @Override
    public Node visitQuantifiedPredicateNode(QuantifiedPredicateNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getDeclarationList().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        QuantifiedPredicateNode result = new QuantifiedPredicateNode(node.getSourceCodePosition(), node.getDeclarationList(), (PredicateNode) visitPredicateNode(node.getPredicateNode(), null), node.getOperator());
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitLetPredicateNode(LetPredicateNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        LetPredicateNode result = new LetPredicateNode(node.getSourceCodePosition(), node.getLocalIdentifiers(), (PredicateNode) visitPredicateNode(node.getWherePredicate(), null), (PredicateNode) visitPredicateNode(node.getPredicate(), null));
        result.setType(node.getType());
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitIfPredicateNode(IfPredicateNode node, Void expected) {
        IfPredicateNode result = new IfPredicateNode(node.getSourceCodePosition(), (PredicateNode) visitPredicateNode(node.getCondition(), null), (PredicateNode) visitPredicateNode(node.getThenPredicate(), null), (PredicateNode) visitPredicateNode(node.getElsePredicate(), null));
        result.setType(node.getType());
        return result;
    }

    @Override
    public Node visitVarSubstitutionNode(VarSubstitutionNode node, Void expected) {
        return new VarSubstitutionNode(node.getSourceCodePosition(), node.getLocalIdentifiers(), (SubstitutionNode) visitSubstitutionNode(node.getBody(), null));
    }

    @Override
    public Node visitWhileSubstitutionNode(WhileSubstitutionNode node, Void expected) {
        return new WhileSubstitutionNode(node.getSourceCodePosition(), (PredicateNode) visitPredicateNode(node.getCondition(), null), (SubstitutionNode) visitSubstitutionNode(node.getBody(), null), (PredicateNode) visitPredicateNode(node.getInvariant(), null), (ExprNode) visitExprNode(node.getVariant(), null));
    }

    @Override
    public Node visitListSubstitutionNode(ListSubstitutionNode node, Void expected) {
        return new ListSubstitutionNode(node.getSourceCodePosition(), node.getOperator(), node.getSubstitutions()
                .stream()
                .map(subs -> (SubstitutionNode) visitSubstitutionNode(subs, null)).collect(Collectors.toList()));
    }

    @Override
    public Node visitIfOrSelectSubstitutionsNode(IfOrSelectSubstitutionsNode node, Void expected) {
        return new IfOrSelectSubstitutionsNode(node.getSourceCodePosition(), node.getOperator(),
                node.getConditions()
                        .stream()
                        .map(cond -> (PredicateNode) visitPredicateNode(cond, null))
                        .collect(Collectors.toList()),
                node.getSubstitutions()
                        .stream()
                        .map(subs -> (SubstitutionNode) visitSubstitutionNode(subs, null))
                        .collect(Collectors.toList()),
                node.getElseSubstitution() == null ? null : (SubstitutionNode) visitSubstitutionNode(node.getElseSubstitution(), null));
    }

    @Override
    public Node visitAssignSubstitutionNode(AssignSubstitutionNode node, Void expected) {
        return new AssignSubstitutionNode(node.getSourceCodePosition(), node.getLeftSide(), node.getRightSide()
                .stream()
                .map(expr -> (ExprNode) visitExprNode(expr, null))
                .collect(Collectors.toList()));
    }

    @Override
    public Node visitSkipSubstitutionNode(SkipSubstitutionNode node, Void expected) {
        return node;
    }

    @Override
    public Node visitConditionSubstitutionNode(ConditionSubstitutionNode node, Void expected) {
        return new ConditionSubstitutionNode(node.getSourceCodePosition(), node.getKind(), (PredicateNode) visitPredicateNode(node.getCondition(), null), (SubstitutionNode) visitSubstitutionNode(node.getSubstitution(), null));
    }

    @Override
    public Node visitAnySubstitution(AnySubstitutionNode node, Void expected) {
        return new AnySubstitutionNode(node.getSourceCodePosition(), node.getParameters(), (PredicateNode) visitPredicateNode(node.getWherePredicate(), null), (SubstitutionNode) visitSubstitutionNode(node.getThenSubstitution(), null));
    }

    @Override
    public Node visitLetSubstitution(LetSubstitutionNode node, Void expected) {
        List<String> oldBoundedVariables = new ArrayList<>(this.boundedVariables);
        this.boundedVariables.addAll(node.getLocalIdentifiers().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        LetSubstitutionNode result = new LetSubstitutionNode(node.getSourceCodePosition(), node.getLocalIdentifiers(), (PredicateNode) visitPredicateNode(node.getPredicate(), null), (SubstitutionNode) visitSubstitutionNode(node.getBody(), null));
        this.boundedVariables = oldBoundedVariables;
        return result;
    }

    @Override
    public Node visitBecomesElementOfSubstitutionNode(BecomesElementOfSubstitutionNode node, Void expected) {
        return new BecomesElementOfSubstitutionNode(node.getSourceCodePosition(), node.getIdentifiers(), (ExprNode) visitExprNode(node.getExpression(), null));
    }

    @Override
    public Node visitBecomesSuchThatSubstitutionNode(BecomesSuchThatSubstitutionNode node, Void expected) {
        return new BecomesSuchThatSubstitutionNode(node.getSourceCodePosition(), node.getIdentifiers(), (PredicateNode) visitPredicateNode(node.getPredicate(), null));
    }

    @Override
    public Node visitSubstitutionIdentifierCallNode(OperationCallSubstitutionNode node, Void expected) {
        OperationCallSubstitutionNode result = new OperationCallSubstitutionNode(node.getSourceCodePosition(), node.getNames(), node.getArguments()
                .stream()
                .map(expr -> (ExprNode) visitExprNode(expr, null))
                .collect(Collectors.toList()), node.getAssignedVariables());
        result.setOperationsNode(node.getOperationNode());
        return result;
    }

    @Override
    public Node visitChoiceSubstitutionNode(ChoiceSubstitutionNode node, Void expected) {
        return new ChoiceSubstitutionNode(node.getSourceCodePosition(), node.getSubstitutions()
                .stream()
                .map(subs -> (SubstitutionNode) visitSubstitutionNode(subs, null)).collect(Collectors.toList()));
    }

}
