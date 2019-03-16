package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.UntypedType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES;
import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES;


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

    private final ImportGenerator importGenerator;

    private final Map<String, String> machineFromOperation;


    public OperationGenerator(final STGroup group, final MachineGenerator machineGenerator, final SubstitutionGenerator substitutionGenerator,
                              final DeclarationGenerator declarationGenerator, final IdentifierGenerator identifierGenerator,
                              final NameHandler nameHandler, final TypeGenerator typeGenerator, final ImportGenerator importGenerator) {
        this.group = group;
        this.machineGenerator = machineGenerator;
        this.declarationGenerator = declarationGenerator;
        this.substitutionGenerator = substitutionGenerator;
        this.substitutionGenerator.setOperationGenerator(this);
        this.identifierGenerator = identifierGenerator;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.importGenerator = importGenerator;
        this.machineFromOperation = new HashMap<>();
    }

    /*
    * This function maps operations to machines for identifying the included machine where the operation is called from.
    */
    public void mapOperationsToMachine(MachineNode node) {
        node.getMachineReferences()
                .forEach(reference -> reference.getMachineNode().getOperations()
                        .forEach(operation -> machineFromOperation.put(operation.getName(), reference.getMachineName())));
    }

    /*
    * This function generates code for all operations in a machine.
    */
    public List<String> visitOperations(List<OperationNode> operations) {
        return operations.stream()
                .map(this::visitOperation)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for one operation with the given AST node for an operation.
    */
    private String visitOperation(OperationNode node) {
        identifierGenerator.setParams(node.getParams(), node.getOutputParams());
        ST operation = generate(node);
        TemplateHandler.add(operation,  "machine", nameHandler.handle(machineGenerator.getMachineName()));
        TemplateHandler.add(operation, "body", machineGenerator.visitSubstitutionNode(node.getSubstitution(), null));
        return operation.render();
    }

    /*
    * This function generates code for an operation from the given AST node
    */
    private ST generate(OperationNode node) {
        ST operation = group.getInstanceOf("operation");

        TemplateHandler.add(operation, "locals", declarationGenerator.generateDeclarations(node.getOutputParams()
                .stream()
                .collect(Collectors.toList()), DeclarationType.LOCAL_DECLARATION, false));
        BType type = null;
        String returnString = null;
        List<DeclarationNode> outputs = node.getOutputParams();
        if(outputs.size() > 1) {
            //TODO: Introduce RecordType in ANTLR Parser
            importGenerator.addRecordImport();

            TemplateHandler.add(operation, "returnType", "BRecord");

            List<String> identifiers = outputs.stream()
                    .map(DeclarationNode::getName)
                    .map(identifier -> nameHandler.handleIdentifier(identifier, FUNCTION_NAMES))
                    .collect(Collectors.toList());

            ST recordTemplate = group.getInstanceOf("record_create");
            TemplateHandler.add(recordTemplate, "elements", identifiers);
            ST returnTemplate = group.getInstanceOf("return");
            TemplateHandler.add(returnTemplate, "identifier", recordTemplate.render());
            returnString = returnTemplate.render();
        } else if(outputs.size() == 1) {
            type = outputs.get(0).getType();
            String identifier = outputs.get(0).getName();
            TemplateHandler.add(operation, "returnType", typeGenerator.generate(type));
            ST returnTemplate = group.getInstanceOf("return");
            TemplateHandler.add(returnTemplate, "identifier", nameHandler.handleIdentifier(identifier, FUNCTION_NAMES));
            TemplateHandler.add(returnTemplate, "machine", nameHandler.handle(machineGenerator.getMachineName()));
            returnString = returnTemplate.render();
        } else if(outputs.size() == 0) {
            TemplateHandler.add(operation, "returnType", typeGenerator.generate(new UntypedType()));
            returnString = group.getInstanceOf("no_return").render();
        }
        TemplateHandler.add(operation, "isTyped", !(type instanceof UntypedType));
        TemplateHandler.add(operation, "return", returnString);
        TemplateHandler.add(operation, "operationName", nameHandler.handleIdentifier(node.getName(), INCLUDED_MACHINES));
        TemplateHandler.add(operation, "parameters", declarationGenerator.generateDeclarations(node.getParams(), DeclarationType.PARAMETER, false));
        TemplateHandler.add(operation, "returnParameters", declarationGenerator.generateDeclarations(node.getOutputParams(), DeclarationType.PARAMETER, true));
        return operation;
    }

    public Map<String, String> getMachineFromOperation() {
        return machineFromOperation;
    }
}
