package de.hhu.stups.codegenerator.analyzers;

import de.hhu.stups.codegenerator.generators.ImportGenerator;
import de.hhu.stups.codegenerator.generators.TypeGenerator;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.expression.ExpressionOperatorNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.expression.IfExpressionNode;
import de.prob.parser.ast.nodes.expression.LambdaNode;
import de.prob.parser.ast.nodes.expression.LetExpressionNode;
import de.prob.parser.ast.nodes.expression.NumberNode;
import de.prob.parser.ast.nodes.expression.QuantifiedExpressionNode;
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
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.RecordType;
import de.prob.parser.ast.types.SetType;
import de.prob.parser.ast.visitors.AbstractVisitor;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Created by fabian on 29.05.19.
 */
public class RecordStructAnalyzer implements AbstractVisitor<Void, Void> {

    private final STGroup currentGroup;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private Map<String, String> nodeToClassName;

    private List<RecordType> structs;

    private int counter = 0;

    public RecordStructAnalyzer(STGroup group, TypeGenerator typeGenerator, ImportGenerator importGenerator) {
        this.currentGroup = group;
        this.typeGenerator = typeGenerator;
        this.typeGenerator.setRecordStructAnalyzer(this);
        this.importGenerator = importGenerator;
        this.nodeToClassName = new HashMap<>();
        this.structs = new ArrayList<>();
    }

    public void visitMachineNode(MachineNode node) {
        node.getVariables().forEach(variable -> {
            //TODO: Check recursively for RecordType
            if(variable.getType() instanceof RecordType) {
                createNewStruct((RecordType) variable.getType());
            }
        });

        node.getConstants().forEach(constant -> {
            //TODO: Check recursively for RecordType
            if(constant.getType() instanceof RecordType) {
                createNewStruct((RecordType) constant.getType());
            }
        });

        visitSubstitutionNode(node.getInitialisation(), null);
        node.getOperations().forEach(this::visitOperationNode);
        node.getValues().forEach(substitution -> visitSubstitutionNode(substitution, null));
        if(node.getProperties() != null) {
            visitPredicateNode(node.getProperties(), null);
        }
        visitPredicateNode(node.getInvariant(), null);
    }

    public void visitOperationNode(OperationNode node) {
        visitSubstitutionNode(node.getSubstitution(), null);
    }

    @Override
    public Void visitExprOperatorNode(ExpressionOperatorNode node, Void expected) {
        node.getExpressionNodes().forEach(expr -> visitExprNode(expr, expected));
        return null;
    }

    @Override
    public Void visitIdentifierExprNode(IdentifierExprNode node, Void expected) {
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
        node.getLeftSide().forEach(lhs -> visitExprNode(lhs, expected));
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
        String type = node.getType().toString();
        if(!nodeToClassName.containsKey(type)) {
            createNewStruct((RecordType) node.getType());
        }
        return null;
    }

    @Override
    public Void visitStructNode(StructNode node, Void expected) {
        RecordType recordType = (RecordType)((SetType)node.getType()).getSubType();
        createNewStruct(recordType);
        return null;
    }

    @Override
    public Void visitRecordFieldAccessNode(RecordFieldAccessNode node, Void expected) {
        return null;
    }

    public List<String> generateStructs() {
        return structs.stream()
                .map(this::generateStruct)
                .collect(Collectors.toList());
    }

    private String generateStruct(RecordType recordType) {
        ST struct = currentGroup.getInstanceOf("struct");
        TemplateHandler.add(struct, "name", nodeToClassName.get(recordType.toString()));
        List<String> declarations = new ArrayList<>();
        List<String> parameters = new ArrayList<>();
        List<String> initializations = new ArrayList<>();
        List<String> assignments = new ArrayList<>();
        List<String> equalPredicates = new ArrayList<>();
        List<String> unequalPredicates = new ArrayList<>();
        List<String> fieldToStrings = new ArrayList<>();
        List<String> fields = new ArrayList<>();
        for(int i = 0; i < recordType.getIdentifiers().size(); i++) {
            BType type = recordType.getSubtypes().get(i);
            String identifier = recordType.getIdentifiers().get(i);
            declarations.add(generateDeclaration(type, identifier));
            parameters.add(generateStructParameter(type, identifier));
            initializations.add(generateInitialization(identifier));
            assignments.add(generateAssignment(identifier));
            equalPredicates.add(generateEqualPredicate(identifier));
            unequalPredicates.add(generateUnequalPredicate(identifier));
            fieldToStrings.add(generateFieldToStrings(identifier));
            fields.add(identifier);
        }
        TemplateHandler.add(struct, "declarations", declarations);
        TemplateHandler.add(struct, "parameters", parameters);
        TemplateHandler.add(struct, "initializations", initializations);
        TemplateHandler.add(struct, "assignments", assignments);
        TemplateHandler.add(struct, "equalPredicates", equalPredicates);
        TemplateHandler.add(struct, "unequalPredicates", unequalPredicates);
        TemplateHandler.add(struct, "values", fieldToStrings);
        TemplateHandler.add(struct, "fields", fields);
        return struct.render();
    }

    private String generateDeclaration(BType type, String identifier) {
        ST declaration = currentGroup.getInstanceOf("global_declaration");
        TemplateHandler.add(declaration, "type", typeGenerator.generate(type));
        //TODO: Rewrite String to IdentifierExprNode
        TemplateHandler.add(declaration, "identifier", identifier);
        return declaration.render();
    }

    private String generateStructParameter(BType type, String identifier) {
        ST parameter = currentGroup.getInstanceOf("parameter");
        TemplateHandler.add(parameter, "type", typeGenerator.generate(type));
        TemplateHandler.add(parameter, "identifier", identifier);
        return parameter.render();
    }

    private String generateInitialization(String identifier) {
        ST initialization = currentGroup.getInstanceOf("record_field_initialization");
        TemplateHandler.add(initialization, "identifier", identifier);
        return initialization.render();
    }

    private String generateAssignment(String identifier) {
        ST assignment = currentGroup.getInstanceOf("record_assignment");
        TemplateHandler.add(assignment, "identifier", identifier);
        return assignment.render();
    }

    private String generateEqualPredicate(String identifier) {
        ST binary = currentGroup.getInstanceOf("record_equal_predicate");
        TemplateHandler.add(binary, "field", identifier);
        return binary.render();
    }

    private String generateUnequalPredicate(String identifier) {
        ST binary = currentGroup.getInstanceOf("record_unequal_predicate");
        TemplateHandler.add(binary, "field", identifier);
        return binary.render();
    }

    private String generateFieldToStrings(String identifier) {
        ST fieldToString = currentGroup.getInstanceOf("record_field_to_string");
        TemplateHandler.add(fieldToString, "identifier", identifier);
        return fieldToString.render();
    }

    public void createNewStruct(RecordType type) {
        if(nodeToClassName.containsKey(type.toString())) {
            return;
        }
        importGenerator.addImport(type);
        String name = "_Struct" + counter;
        nodeToClassName.put(type.toString(), name);
        structs.add(type);
        counter++;
    }

    public String getStruct(BType recordType) {
        return nodeToClassName.get(recordType.toString());
    }
}
