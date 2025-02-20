package de.hhu.stups.codegenerator.handlers;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;

import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES;
import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES;
import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.MACHINES;

/**
 * Created by fabian on 01.06.18.
 */
public class NameHandler {

    /*
    * Enum for handling levels for the collision problem between identifiers and keywords
    */
    public enum IdentifierHandlingEnum {
        MACHINES,
        INCLUDED_MACHINES,
        FUNCTION_NAMES,
        VARIABLES;
    }

    private final MachineGenerator machineGenerator;

    private final STGroup group;

    private List<String> globals;

    private List<String> reservedMachines;

    private List<String> reservedMachinesWithIncludedMachines;

    private List<String> reservedMachinesAndFunctions;

    private List<String> reservedMachinesAndFunctionsAndVariables;

    private Map<String, List<String>> enumTypes;

    private List<String> deferredTypes;

    private Map<String, List<String>> freeTypes;

    public NameHandler(final MachineGenerator machineGenerator, final STGroup group) {
        this.machineGenerator = machineGenerator;
        this.group = group;
        this.globals = new ArrayList<>();
        this.enumTypes = new HashMap<>();
        this.deferredTypes = new ArrayList<>();
        this.freeTypes = new HashMap<>();
        this.reservedMachines = new ArrayList<>();
        this.reservedMachinesWithIncludedMachines = new ArrayList<>();
        this.reservedMachinesAndFunctions = new ArrayList<>();
        this.reservedMachinesAndFunctionsAndVariables = new ArrayList<>();
    }

    /*
    * This functions initializes different levels for handling collisions between identifiers and keywords
    */
    public void initialize(MachineNode node) {
        node.getEnumeratedSets().forEach(set -> {
            if(node.getPrefix() != null && !node.equals(machineGenerator.getMachineNode())) {
                enumTypes.put(node.getPrefix() + "." + set.getSetDeclarationNode().getName(), set.getElementsAsStrings());
            } else {
                enumTypes.put(set.getSetDeclarationNode().getName(), set.getElementsAsStrings());
            }
        });
        deferredTypes.addAll(node.getDeferredSets().stream().map(DeclarationNode::getName).collect(Collectors.toList()));
        node.getFreetypes().forEach(ft -> {
            List<String> elementsAsString = ft.getElements().stream().map(DeclarationNode::getName).collect(Collectors.toList());
            if (node.getPrefix() != null && !node.equals(machineGenerator.getMachineNode())) {
                freeTypes.put(node.getPrefix() + "." + ft.getFreetypeDeclarationNode().getName(), elementsAsString);
            } else {
                freeTypes.put(ft.getFreetypeDeclarationNode().getName(), elementsAsString);
            }
        });
        reservedMachines.addAll(node.getMachineReferences().stream()
                .map(reference -> handle(reference.getMachineName()))
                .collect(Collectors.toList()));
        reservedMachinesWithIncludedMachines.addAll(reservedMachines);
        reservedMachinesWithIncludedMachines.addAll(node.getMachineReferences().stream()
                .map(reference -> handleIdentifier(reference.getMachineName(), MACHINES))
                .collect(Collectors.toList()));

        reservedMachinesAndFunctions.addAll(reservedMachinesWithIncludedMachines);
        reservedMachinesAndFunctions.addAll(node.getOperations().stream()
                .map(operation -> handleIdentifier(operation.getName(), INCLUDED_MACHINES))
                .collect(Collectors.toList()));

        reservedMachinesAndFunctionsAndVariables.addAll(reservedMachinesAndFunctions);
        reservedMachinesAndFunctionsAndVariables.addAll(node.getVariables().stream()
                .map(variable -> handleIdentifier(variable.getName(), FUNCTION_NAMES))
                .collect(Collectors.toList()));

        reservedMachinesAndFunctionsAndVariables.addAll(node.getEnumeratedSets().stream()
                .map(set -> handleIdentifier(set.getSetDeclarationNode().getName(), FUNCTION_NAMES))
                .collect(Collectors.toList()));
        reservedMachinesAndFunctionsAndVariables.addAll(node.getDeferredSets().stream()
                .map(set -> handleIdentifier(set.getName(), FUNCTION_NAMES))
                .collect(Collectors.toList()));

        globals.addAll(reservedMachinesAndFunctionsAndVariables);
        globals.addAll(node.getEnumeratedSets().stream()
                .map(set -> handleIdentifier(set.getSetDeclarationNode().getName(), NameHandler.IdentifierHandlingEnum.VARIABLES))
                .collect(Collectors.toList()));
    }


    /*
    * This function handles collision between identifiers and keywords from the belonging template.
    */
    public String handle(String string) {
        ST keywords = group.getInstanceOf("keywords");
        List<String> words = Arrays.asList(keywords.render().replaceAll(" ","").replaceAll("\n","").split(","));
        if(words.contains(string)) {
            return "_" + string;
        }
        return string;
    }

    /*
    * This function handles collision between identifiers and keywords for all levels
    */
    public String handleIdentifier(String identifier, IdentifierHandlingEnum identifierHandling) {
        StringBuilder result = new StringBuilder(handle(identifier));
        if (machineGenerator.getMode() == GeneratorMode.PL) return result.toString();
        while(getVariables(identifierHandling).contains(result.toString())) {
            result.insert(0, "_");
        }
        return result.toString();
    }


    /*
    * This function handles collisions between keywords and identifiers for enums
    */
    public String handleEnum(String identifier, List<String> enums) {
        ST keywords = group.getInstanceOf("keywords");
        List<String> words = Arrays.asList(keywords.render().replaceAll(" ","").replaceAll("\n","").split(","));
        StringBuilder result = new StringBuilder(identifier);
        if(words.contains(identifier)) {
            while (enums.contains(result.toString())) {
                result.append("_");
            }
        }
        return result.toString();
    }

    /*
    * This function gets the list of reserved variables from a given level that is represented by identifierHandling
    */
    private List<String> getVariables(IdentifierHandlingEnum identifierHandling) {
        List<String> variables = null;
        switch (identifierHandling) {
            case MACHINES:
                variables = reservedMachines;
                break;
            case INCLUDED_MACHINES:
                variables = reservedMachinesWithIncludedMachines;
                break;
            case FUNCTION_NAMES:
                variables = reservedMachinesAndFunctions;
                break;
            case VARIABLES:
                variables = reservedMachinesAndFunctionsAndVariables;
                break;
            default:
                break;
        }
        return variables;
    }

    public List<String> getGlobals() {
        return globals;
    }

    public List<String> getReservedMachines() {
        return reservedMachines;
    }

    public List<String> getReservedMachinesAndFunctions() {
        return reservedMachinesAndFunctions;
    }

    public List<String> getReservedMachinesAndFunctionsAndVariables() {
        return reservedMachinesAndFunctionsAndVariables;
    }

    public List<String> getReservedMachinesWithIncludedMachines() {
        return reservedMachinesWithIncludedMachines;
    }

    public Map<String, List<String>> getEnumTypes() {
        return enumTypes;
    }

    public List<String> getDeferredTypes() {
        return deferredTypes;
    }

    public Map<String, List<String>> getFreeTypes() {
        return freeTypes;
    }

    public Map<String, String> getEnumToMachine() {
        return machineGenerator.getDeclarationGenerator().getEnumToMachine();
    }

    public String getMachineName() {
        return machineGenerator.getMachineName();
    }
}
