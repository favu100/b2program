package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.expression.RecordFieldAccessNode;
import de.prob.parser.ast.nodes.expression.RecordNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.RecordType;
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
public class RecordGenerator {

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private Map<String, String> nodeToClassName;

    private List<RecordType> structs;

    private List<RecordType> generatedStructs;

    private int counter;

    public RecordGenerator(STGroup group, MachineGenerator machineGenerator, TypeGenerator typeGenerator, ImportGenerator importGenerator) {
        this.currentGroup = group;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.typeGenerator.setRecordGenerator(this);
        this.importGenerator = importGenerator;
        this.structs = new ArrayList<>();
        this.generatedStructs = new ArrayList<>();
        this.nodeToClassName = new HashMap<>();
        this.counter = 0;

    }

    public String visitRecordNode(RecordNode node) {
        ST record = currentGroup.getInstanceOf("record");
        BType type = node.getType();
        createNewStruct((RecordType) type);
        String struct = getStruct(type);
        TemplateHandler.add(record, "struct", struct);
        TemplateHandler.add(record, "parameters", node.getExpressions().stream()
            .map(expression -> machineGenerator.visitExprNode(expression, null))
            .collect(Collectors.toList()));
        return record.render();
    }

    public String visitRecordFieldAccessNode(RecordFieldAccessNode node) {
        ST fieldAccess = currentGroup.getInstanceOf("record_field_access");
        TemplateHandler.add(fieldAccess, "record", machineGenerator.visitExprNode(node.getRecord(), null));
        TemplateHandler.add(fieldAccess, "field", machineGenerator.visitExprNode(node.getIdentifier(), null));
        return fieldAccess.render();
    }


    public List<String> generateStructs() {
        return generatedStructs.stream()
                .map(this::generateStruct)
                .collect(Collectors.toList());
    }

    private String generateStruct(RecordType recordType) {
        ST struct = currentGroup.getInstanceOf("struct");
        TemplateHandler.add(struct, "name", nodeToClassName.get(recordType.toString()));
        List<String> declarations = new ArrayList<>();
        List<String> parameters = new ArrayList<>();
        List<String> initializations = new ArrayList<>();
        List<String> functions = new ArrayList<>();
        List<String> assignments = new ArrayList<>();
        List<String> equalPredicates = new ArrayList<>();
        List<String> unequalPredicates = new ArrayList<>();
        List<String> fieldToStrings = new ArrayList<>();
        List<String> fields = new ArrayList<>();
        for(int i = 0; i < recordType.getIdentifiers().size(); i++) {
            BType type = recordType.getSubtypes().get(i);
            String identifier = recordType.getIdentifiers().get(i);
            declarations.add(generateDeclaration(type, identifier));
            functions.add(generateGetFunction(type, identifier));
            parameters.add(generateStructParameter(type, identifier));
            initializations.add(generateInitialization(identifier));
            assignments.add(generateAssignment(identifier));
            equalPredicates.add(generateEqualPredicate(identifier));
            unequalPredicates.add(generateUnequalPredicate(identifier));
            fieldToStrings.add(generateFieldToStrings(identifier));
            fields.add(identifier);
        }
        functions.addAll(generateOverwriteFunctions(recordType, nodeToClassName.get(recordType.toString())));
        TemplateHandler.add(struct, "declarations", declarations);
        TemplateHandler.add(struct, "parameters", parameters);
        TemplateHandler.add(struct, "initializations", initializations);
        TemplateHandler.add(struct, "functions", functions);
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

    private String generateGetFunction(BType type, String identifier) {
        ST function = currentGroup.getInstanceOf("record_field_get");
        TemplateHandler.add(function, "type", typeGenerator.generate(type));
        TemplateHandler.add(function, "field", identifier);
        return function.render();
    }

    private List<String> generateOverwriteFunctions(RecordType recordType, String name) {
        List<String> functions = new ArrayList<>();
        List<String> identifiers = recordType.getIdentifiers();
        for(int i = 0; i < identifiers.size(); i++) {
            ST function = currentGroup.getInstanceOf("record_field_override");
            TemplateHandler.add(function, "name", name);
            TemplateHandler.add(function, "field", identifiers.get(i));
            TemplateHandler.add(function, "type", typeGenerator.generate(recordType.getSubtypes().get(i)));
            TemplateHandler.add(function,"parameters", identifiers);
            functions.add(function.render());
        }
        return functions;
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
        generatedStructs.add(type);
        counter++;
    }

    public void createNewStruct(OperationNode node) {
        if(nodeToClassName.containsKey(node.toString())) {
            return;
        }
        RecordType recordType = getRecordTypeFromOperation(node);
        importGenerator.addImport(recordType);
        String name = "_Struct" + counter;
        structs.add(recordType);
        generatedStructs.add(recordType);
        nodeToClassName.put(recordType.toString(), name);
        counter++;
    }

    public String getStruct(BType recordType) {
        return nodeToClassName.get(recordType.toString());
    }

    public String getStruct(OperationNode node) {
        return nodeToClassName.get(getRecordTypeFromOperation(node).toString());
    }

    private RecordType getRecordTypeFromOperation(OperationNode node) {
        List<String> identifiers = node.getOutputParams()
                .stream()
                .map(DeclarationNode::getName).collect(Collectors.toList());
        List<BType> types = node.getOutputParams()
                .stream()
                .map(DeclarationNode::getType)
                .collect(Collectors.toList());
        return new RecordType(identifiers, types);
    }

    public List<RecordType> getStructs() {
        return structs;
    }

    public Map<String, String> getNodeToClassName() {
        return nodeToClassName;
    }
}
