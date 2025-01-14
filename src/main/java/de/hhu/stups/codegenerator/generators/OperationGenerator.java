package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;

import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.*;


public class OperationGenerator {

    /*
    * Enum for identifying whether the given declaration is a local declaration or a parameter
    */
    public enum DeclarationType {
        LOCAL_DECLARATION,
        PARAMETER
    }

    private final STGroup group;

    private final MachineGenerator machineGenerator;

    private final DeclarationGenerator declarationGenerator;

    private final IdentifierGenerator identifierGenerator;

    private final NameHandler nameHandler;

    private final SubstitutionGenerator substitutionGenerator;

    private final TypeGenerator typeGenerator;

    private final RecordStructGenerator recordStructGenerator;

    private final Map<String, String> machineFromOperation;

    public OperationGenerator(final STGroup group, final MachineGenerator machineGenerator, final SubstitutionGenerator substitutionGenerator,
                              final DeclarationGenerator declarationGenerator, final IdentifierGenerator identifierGenerator,
                              final NameHandler nameHandler, final TypeGenerator typeGenerator, final RecordStructGenerator recordStructGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.declarationGenerator = declarationGenerator;
        this.substitutionGenerator = substitutionGenerator;
        this.substitutionGenerator.setOperationGenerator(this);
        this.identifierGenerator = identifierGenerator;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.recordStructGenerator = recordStructGenerator;
        this.machineFromOperation = new HashMap<>();
    }

    /*
    * This function maps operations to machines for identifying the included machine where the operation is called from.
    */
    public void mapOperationsToMachine(MachineNode node) {
        node.getMachineReferences()
                .forEach(reference -> reference.getMachineNode().getOperations()
                .forEach(operation -> {
                    if(reference.getPrefix() == null) {
                        machineFromOperation.put(operation.getName(), reference.getMachineName());
                    }
                }));
    }

    /*
    * This function generates code for all operations in a machine.
    */
    public List<String> visitOperations(List<OperationNode> operations, List<String> globals) {
        return operations.stream()
                .map(op -> visitOperation(op, globals))
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for one operation with the given AST node for an operation.
    */
    private String visitOperation(OperationNode node, List<String> globals) {
        identifierGenerator.setParams(node.getParams(), node.getOutputParams());
        machineGenerator.resetCurrentExpressionCount();
        machineGenerator.resetCurrentStateCount();
        ST operation = generate(node, globals);
        TemplateHandler.add(operation, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        if (machineGenerator.getMode() == GeneratorMode.PL) { // prevents rendering of getter operations
            String body = machineGenerator.visitSubstitutionNode(node.getSubstitution(), null);
            if (body.split("\n").length > 1 || !body.startsWith("update")) {
                TemplateHandler.add(operation, "body", body);
            } else {
                return "";
            }
        } else {
            if(!node.getName().startsWith("EXTERNAL_")) {
                TemplateHandler.add(operation, "body", machineGenerator.visitSubstitutionNode(node.getSubstitution(), null));
            }
        }
        TemplateHandler.add(operation, "lastStateCount", machineGenerator.getCurrentStateCount());
        return operation.render();
    }

    /*
    * This function generates code for an operation from the given AST node
    */
    private ST generate(OperationNode node, List<String> globals) {
        ST operation = group.getInstanceOf("operation");
        generateReturn(operation, node);
        TemplateHandler.add(operation, "locals", declarationGenerator.generateDeclarations(node.getOutputParams()
                .stream()
                .filter(identifier -> !globals.contains(identifier.getName()))
                .collect(Collectors.toList()), DeclarationType.LOCAL_DECLARATION, false));
        TemplateHandler.add(operation, "operationName", nameHandler.handleIdentifier(node.getName(), INCLUDED_MACHINES));
        TemplateHandler.add(operation, "isExternal", node.getName().startsWith("EXTERNAL_"));
        TemplateHandler.add(operation, "parameters", declarationGenerator.generateDeclarations(node.getParams(), DeclarationType.PARAMETER, false));
        TemplateHandler.add(operation, "parameterNames", node.getParams().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        TemplateHandler.add(operation, "returnParameters", declarationGenerator.generateDeclarations(node.getOutputParams(), DeclarationType.PARAMETER, true));
        TemplateHandler.add(operation, "hasReturnParameters", !node.getOutputParams().isEmpty());
        return operation;
    }

    /*
    * This function generates code for returning output parameters
    */
    private void generateReturn(ST operation, OperationNode node) {
        List<DeclarationNode> outputs = node.getOutputParams();
        if(outputs.size() > 1) {
            generateReturnStatementRecord(operation, node);
        } else if(outputs.size() == 1) {
            generateReturnStatementIdentifier(operation, outputs);
        } else {
            generateVoidReturnStatement(operation);
        }
    }

    public String generateReturnType(OperationNode node) {
        List<DeclarationNode> outputs = node.getOutputParams();
        if(outputs.size() > 1) {
            return recordStructGenerator.getStruct(node);
        } else if(outputs.size() == 1) {
            return typeGenerator.generate(outputs.get(0).getType());
        } else {
            return typeGenerator.generateVoid();
        }
    }

    /*
    * This function generates code for empty output parameters
    */
    private void generateVoidReturnStatement(ST operation) {
        TemplateHandler.add(operation, "returnType", typeGenerator.generateVoid());
        TemplateHandler.add(operation, "return", group.getInstanceOf("no_return").render());
        TemplateHandler.add(operation, "isTyped", false);
    }

    /*
    * This function generates code for returning output parameters with one parameter
    */
    private void generateReturnStatementIdentifier(ST operation, List<DeclarationNode> outputs) {
        BType type = outputs.get(0).getType();
        String identifier = outputs.get(0).getName();
        //TODO: render identifier via template instead of transforming it here
        boolean isGlobal = false;
        if (nameHandler.getGlobals().contains(identifier)) {
            isGlobal = true;
            String privateVariablePrefix = group.getInstanceOf("record_private_variable_prefix").render();
            identifier = privateVariablePrefix + identifier;
        }
        TemplateHandler.add(operation, "returnType", typeGenerator.generate(type));
        ST returnTemplate = group.getInstanceOf("return");
        TemplateHandler.add(returnTemplate, "identifier", nameHandler.handleIdentifier(identifier, FUNCTION_NAMES));
        TemplateHandler.add(returnTemplate, "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(returnTemplate, "isLocal", !isGlobal);
        TemplateHandler.add(operation, "isTyped", true);
        TemplateHandler.add(operation, "return", returnTemplate.render());
    }

    /*
    * This function generates code for returning output parameters with more than one parameter
    */
    private void generateReturnStatementRecord(ST operation, OperationNode node) {
        List<DeclarationNode> outputs = node.getOutputParams();
        String struct = recordStructGenerator.getStruct(node);
        TemplateHandler.add(operation, "returnType", struct);

        List <String> identifiers = outputs.stream().map(declarationNode -> {
            IdentifierExprNode asIdExpr = new IdentifierExprNode(declarationNode.getSourceCodePosition(), declarationNode.getName(), false);
            asIdExpr.setDeclarationNode(declarationNode);
            asIdExpr.setParent(declarationNode.getParent());
            return identifierGenerator.generate(asIdExpr);
        }).collect(Collectors.toList());

        ST recordTemplate = group.getInstanceOf("record");
        TemplateHandler.add(recordTemplate, "struct", struct);
        TemplateHandler.add(recordTemplate, "parameters", identifiers);
        ST returnTemplate = group.getInstanceOf("return");
        TemplateHandler.add(returnTemplate, "identifier", recordTemplate.render());
        TemplateHandler.add(operation, "isTyped", true);
        TemplateHandler.add(operation, "return", returnTemplate.render());
    }

    public Map<String, String> getMachineFromOperation() {
        return machineFromOperation;
    }
}
