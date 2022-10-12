package de.hhu.stups.codegenerator.generators;


import de.hhu.stups.codegenerator.analyzers.DeferredSetAnalyzer;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.EnumeratedSetDeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.types.CoupleType;
import de.prob.parser.ast.types.SetType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class DeclarationGenerator {

    private final STGroup currentGroup;

    private final MachineGenerator machineGenerator;

    private final TypeGenerator typeGenerator;

    private final ImportGenerator importGenerator;

    private final NameHandler nameHandler;

    private final Map<String, List<String>> setToEnum;

    private final Map<String, String> enumToMachine;

    private final DeferredSetAnalyzer deferredSetAnalyzer;


    public DeclarationGenerator(final STGroup currentGroup, final MachineGenerator machineGenerator, final TypeGenerator typeGenerator,
                                final ImportGenerator importGenerator, final NameHandler nameHandler, final DeferredSetAnalyzer deferredSetAnalyzer) {
        this.currentGroup = currentGroup;
        this.machineGenerator = machineGenerator;
        this.typeGenerator = typeGenerator;
        this.typeGenerator.setDeclarationGenerator(this);
        this.importGenerator = importGenerator;
        this.nameHandler = nameHandler;
        this.deferredSetAnalyzer = deferredSetAnalyzer;
        this.setToEnum = new HashMap<>();
        this.enumToMachine = new HashMap<>();
    }

    /*
    * This function generates code from the VARIABLES clause
    */
    public List<String> visitDeclarations(List<DeclarationNode> declarations) {
        return declarations.stream()
                .map(this::generateGlobalDeclaration)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for each declaration from the VARIABLES clause
    */
    private String generateGlobalDeclaration(DeclarationNode node) {
        ST declaration = currentGroup.getInstanceOf("global_declaration");
        TemplateHandler.add(declaration, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return declaration.render();
    }

    /*
    * This function generates code for a list of local declarations or parameters in the generated code
    */
    public List<String> generateDeclarations(List<DeclarationNode> declarations, OperationGenerator.DeclarationType type, boolean isReturn) {
        return declarations.stream()
                .map(declaration -> type == OperationGenerator.DeclarationType.LOCAL_DECLARATION ?
                        generateLocalDeclaration(declaration) : generateParameter(declaration, isReturn))
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for a local declaration with the given node from the AST
    */
    public String generateLocalDeclaration(DeclarationNode node) {
        ST declaration = currentGroup.getInstanceOf("local_declaration");
        TemplateHandler.add(declaration, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return declaration.render();
    }

    /*
    * This function generates code for a parameter with the given node from the AST and the information whether it is an output parameter
    */
    private String generateParameter(DeclarationNode node, boolean isReturn) {
        ST declaration = currentGroup.getInstanceOf("parameter");
        TemplateHandler.add(declaration, "isReturn", isReturn);
        TemplateHandler.add(declaration, "type", typeGenerator.generate(node.getType()));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return declaration.render();
    }

    /*
    * This function generates code for declarations of all constants from the given MachineNode
    */
    public List<String> generateConstantsDeclarations(MachineNode node) {
        Set<String> lambdaFunctions = machineGenerator.getLambdaFunctions();
        Set<String> infiniteSets = machineGenerator.getInfiniteSets();
        return node.getConstants().stream()
                .filter(constant -> !lambdaFunctions.contains(constant.getName()))
                .filter(constant -> !infiniteSets.contains(constant.getName()))
                .map(this::generateConstantDeclaration)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for a constant declaration from the belonging given DeclarationNode
    */
    public String generateConstantDeclaration(DeclarationNode constant) {
        ST declaration = currentGroup.getInstanceOf("constant_declaration");
        TemplateHandler.add(declaration, "type", typeGenerator.generate(constant.getType()));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(constant.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        return declaration.render();
    }

    /*
    * This function generates code for all including other machines with the given AST node of the main machine.
    */
    public List<String> generateIncludes(MachineNode node) {
        return node.getMachineReferences().stream()
                .map(this::generateIncludeDeclaration)
                .collect(Collectors.toList());
    }
    public List<String> generateIncludesInitialization(MachineNode node) {
        return node.getMachineReferences().stream()
                .map(this::generateIncludeInitialization)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for one included machine with the given AST node and the template.
    */
    private String generateIncludeDeclaration(MachineReferenceNode reference) {
        ST declaration = currentGroup.getInstanceOf("include_declaration");
        String machine = reference.getMachineName();
        String referenceName = reference.getPrefix() != null ? reference.getPrefix() : reference.getMachineName();
        TemplateHandler.add(declaration, "type", nameHandler.handle(machine));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(referenceName, NameHandler.IdentifierHandlingEnum.MACHINES));
        return declaration.render();
    }
    private String generateIncludeInitialization(MachineReferenceNode reference) {
        ST declaration = currentGroup.getInstanceOf("include_initialization");
        String machine = reference.getMachineName();
        String referenceName = reference.getPrefix() != null ? reference.getPrefix() : reference.getMachineName();
        TemplateHandler.add(declaration, "type", nameHandler.handle(machine));
        TemplateHandler.add(declaration, "identifier", nameHandler.handleIdentifier(referenceName, NameHandler.IdentifierHandlingEnum.MACHINES));
        return declaration.render();
    }

    /*
    * This function generates code for sets within a machine.
    */
    public List<String> generateEnumDeclarations(MachineNode node, Set<String> identifier) {
        List<String> enumeratedEnums = generateEnumeratedSetEnums(node, identifier);
        List<String> deferredSetEnums = generateDeferredSetEnums(node, identifier);
        List<String> result = new ArrayList<>();
        result.addAll(enumeratedEnums);
        result.addAll(deferredSetEnums);
        return result;
    }

    /*
    * This function generates code for declarations of all enumerated set elements
    */
    private List<String> generateEnumeratedSetEnums(MachineNode node, Set<String> identifier) {
        node.getEnumeratedSets().forEach(set -> {
            setToEnum.put(set.getSetDeclarationNode().getName(), set.getElements().stream()
                    .map(DeclarationNode::getName)
                    .collect(Collectors.toList()));
            enumToMachine.put(set.getSetDeclarationNode().getName(), node.getName());
            identifier.add(set.getSetDeclarationNode().getName());
        });
        return node.getEnumeratedSets().stream()
                .map(this::declareEnums)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for declarations of all deferred set elements
    */
    private List<String> generateDeferredSetEnums(MachineNode node, Set<String> identifier) {
        node.getDeferredSets().forEach(set -> {
            enumToMachine.put(set.getName(), node.getName());
            setToEnum.put(set.getName(), extractEnumsOfDeferredSet(set).stream()
                    .map(declaration -> callEnum(set.getName(), declaration))
                    .collect(Collectors.toList()));
            identifier.add(set.getName());
        });
        return node.getDeferredSets().stream()
                .map(this::declareEnums)
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for all declarations of enums for sets from the node of the machine.
    */
    public List<String> generateSetDeclarations(MachineNode node) { return generateSetDeclarations(node, "set_declaration"); }
    public List<String> generateSetDeclarations(MachineNode node, String templateName) {
        List<String> enumeratedSets = generateEnumeratedSetDeclarations(node, templateName);
        List<String> deferredSets = generateDeferredSetDeclarations(node, templateName);
        List<String> result = new ArrayList<>();
        result.addAll(enumeratedSets);
        result.addAll(deferredSets);
        return result;
    }

    /*
    * This function generates code for all enumerated set declarations from the given MachineNode
    */
    private List<String> generateEnumeratedSetDeclarations(MachineNode node, String templateName) {
        return node.getEnumeratedSets().stream()
                .map(set -> visitEnumeratedSetDeclarationNode(set, templateName))
                .collect(Collectors.toList());
    }

    /*
    * This function generates code for all deferred set declarations from the given MachineNode
    */
    private List<String> generateDeferredSetDeclarations(MachineNode node, String templateName) {
        return node.getDeferredSets().stream()
                .map(set -> visitDeferredSetDeclaration(set, templateName))
                .collect(Collectors.toList());
    }

    /*
    * This function generates code declaring an enum for an enumerated set from the belonging AST node and the belonging template.
    */
    private String declareEnums(EnumeratedSetDeclarationNode node) {
        importGenerator.addImport(node.getElements().get(0).getType());
        ST enumDeclaration = currentGroup.getInstanceOf("set_enum_declaration");
        TemplateHandler.add(enumDeclaration, "name", nameHandler.handleIdentifier(node.getSetDeclarationNode().getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        List<String> enums = node.getElements().stream()
                .map(element -> nameHandler.handleEnum(element.getName(), node.getElements().stream().map(DeclarationNode::getName).collect(Collectors.toList())))
                .collect(Collectors.toList());
        TemplateHandler.add(enumDeclaration, "enums", enums);

        Map<Integer, String> enumsCounted = enums.stream().collect(Collectors.toMap(enums::indexOf, Function.identity()));
        TemplateHandler.add(enumDeclaration, "enumsCounted", enumsCounted);
        TemplateHandler.add(enumDeclaration, "exprCount", machineGenerator.getAndIncCurrentExpressionCount());
        return enumDeclaration.render();
    }

    /*
    * This function generates code for declaring an enum for a deferred set from the belonging AST node and the belonging template.
    */
    private String declareEnums(DeclarationNode node) {
        importGenerator.addImport(((SetType) node.getType()).getSubType());
        ST enumDeclaration = currentGroup.getInstanceOf("set_enum_declaration");
        TemplateHandler.add(enumDeclaration, "name", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        List<String> elements = extractEnumsOfDeferredSet(node);
        List<String> enums = elements.stream()
                .map(element -> nameHandler.handleEnum(element, elements))
                .collect(Collectors.toList());
        TemplateHandler.add(enumDeclaration, "enums", enums);
        return enumDeclaration.render();
    }

    /*
    * This function generates code with creating a BSet for an enumerated set from the belonging AST node and the belonging template.
    */
    public String visitEnumeratedSetDeclarationNode(EnumeratedSetDeclarationNode node, String templateName) {
        importGenerator.addImport(node.getSetDeclarationNode().getType());
        ST setDeclaration = currentGroup.getInstanceOf(templateName);
        TemplateHandler.add(setDeclaration, "type", nameHandler.handleIdentifier(node.getSetDeclarationNode().getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        TemplateHandler.add(setDeclaration, "identifier", nameHandler.handleIdentifier(node.getSetDeclarationNode().getName(), NameHandler.IdentifierHandlingEnum.VARIABLES));
        List<String> enums = node.getElements().stream()
                .map(declaration -> callEnum(node.getSetDeclarationNode().getName(), declaration))
                .collect(Collectors.toList());
        TemplateHandler.add(setDeclaration, "enums", enums);
        return setDeclaration.render();
    }

    /*
    * This function generates code with creating a BSet for a deferred set from the belonging AST node and teh belonging template.
    */
    private String visitDeferredSetDeclaration(DeclarationNode node, String templateName) {
        importGenerator.addImport(node.getType());
        ST setDeclaration = currentGroup.getInstanceOf(templateName);
        TemplateHandler.add(setDeclaration, "type", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES));
        TemplateHandler.add(setDeclaration, "identifier", nameHandler.handleIdentifier(node.getName(), NameHandler.IdentifierHandlingEnum.VARIABLES));
        List<String> enums = extractEnumsOfDeferredSet(node).stream()
                .map(declaration -> callEnum(node.getName(), declaration))
                .collect(Collectors.toList());
        TemplateHandler.add(setDeclaration, "enums", enums);
        return setDeclaration.render();
    }

    /*
    * This function extracts all enum elements of a deferred set from the given DeclarationNode
    */
    private List<String> extractEnumsOfDeferredSet(DeclarationNode node) {
        List<String> enums = new ArrayList<>();
        String deferredSetName = node.getName();
        if(deferredSetAnalyzer.isDeclaredByEnumeration(node)) {
            enums.addAll(deferredSetAnalyzer.getElements(node));
        } else {
            for (int i = 1; i <= deferredSetAnalyzer.getSetSize(node); i++) {
                enums.add(deferredSetName + i);
            }
        }
        return enums;
    }

    /*
    * This function generates code for calling enums from an enumerated set/deferred set from the belonging AST node,
    * template and the name of the enumerated set/deferred set the enum belongs to.
    */
    public String callEnum(String setName, DeclarationNode enumNode) {
        ST enumST = currentGroup.getInstanceOf("enum_call");
        TemplateHandler.add(enumST, "machine", enumToMachine.get(setName));
        TemplateHandler.add(enumST, "class", nameHandler.handleIdentifier(setName, NameHandler.IdentifierHandlingEnum.MACHINES));
        TemplateHandler.add(enumST, "identifier", nameHandler.handleEnum(enumNode.getName(), setToEnum.get(setName)));
        TemplateHandler.add(enumST, "isCurrentMachine", enumToMachine.get(setName).equals(machineGenerator.getMachineName()));
        return enumST.render();
    }

    /*
    * This function generates code for calling enums from the name of an enumerated set from the belonging AST node, template and the name of the enumerated set the enum belongs to.
    */
    public String callEnum(String setName, String enumName) {
        ST enumST = currentGroup.getInstanceOf("enum_call");;
        TemplateHandler.add(enumST, "machine", enumToMachine.get(setName));
        TemplateHandler.add(enumST, "class", nameHandler.handleIdentifier(setName, NameHandler.IdentifierHandlingEnum.MACHINES));
        TemplateHandler.add(enumST, "identifier", nameHandler.handleEnum(enumName, setToEnum.get(setName)));
        TemplateHandler.add(enumST, "isCurrentMachine", enumToMachine.get(setName).equals(machineGenerator.getMachineName()));
        return enumST.render();
    }

    public Map<String, List<String>> getSetToEnum() {
        return setToEnum;
    }

    public Map<String, String> getEnumToMachine() {
        return enumToMachine;
    }

}
