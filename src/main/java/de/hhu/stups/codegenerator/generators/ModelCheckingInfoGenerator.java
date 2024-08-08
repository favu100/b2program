package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.analyzers.IdentifierAnalyzer;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.hhu.stups.codegenerator.json.modelchecker.OperationFunctionInfo;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.DeferredSetElementType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Collectors;

import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.INCLUDED_MACHINES;
import static de.hhu.stups.codegenerator.handlers.NameHandler.IdentifierHandlingEnum.MACHINES;

public class ModelCheckingInfoGenerator {

    private final STGroup currentGroup;

    private final NameHandler nameHandler;

    private final InvariantGenerator invariantGenerator;

    private final TransitionGenerator transitionGenerator;

    private final TypeGenerator typeGenerator;


    public ModelCheckingInfoGenerator(final STGroup currentGroup, final NameHandler nameHandler, final InvariantGenerator invariantGenerator,
                                      final TransitionGenerator transitionGenerator, final TypeGenerator typeGenerator) {
        this.currentGroup = currentGroup;
        this.nameHandler = nameHandler;
        this.invariantGenerator = invariantGenerator;
        this.transitionGenerator = transitionGenerator;
        this.typeGenerator = typeGenerator;
    }

    private List<String> generateIncludedMachines(MachineNode node) {
        return node.getMachineReferences().stream()
                .map(MachineReferenceNode::getMachineName)
                .map(machine -> "_get_" + nameHandler.handleIdentifier(machine, MACHINES))
                .collect(Collectors.toList());
    }


    private List<String> generateVariables(MachineNode node) {
        return node.getVariables().stream()
                .map(variable -> "_get_" + nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                .collect(Collectors.toList());
    }

    private List<String> generateConstants(MachineNode node) {
        return node.getConstants().stream()
                .map(variable -> "_get_" + nameHandler.handleIdentifier(variable.getName(), NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                .collect(Collectors.toList());
    }

    private Map<String, String> generateTransitionEvaluationFunctions(MachineNode node) {
        Map<String, String> transitionEvaluationFunctions = new HashMap<>();
        for(OperationNode operation : node.getOperations()) {
            String opName = nameHandler.handleIdentifier(operation.getName(), INCLUDED_MACHINES);
            String transitionName = "_tr_" + opName;
            transitionEvaluationFunctions.put(opName, transitionName);
        }
        return transitionEvaluationFunctions;
    }

    private List<OperationFunctionInfo> generateOperationFunctions(String machineName, MachineNode node) {
        List<OperationFunctionInfo> operationFunctions = new ArrayList<>();
        for(OperationNode operation : node.getOperations()) {
            String opName = nameHandler.handleIdentifier(operation.getName(), INCLUDED_MACHINES);
            List<String> parameterTypes = new ArrayList<>();
            for(DeclarationNode param : operation.getParams()) {
                BType type = param.getType();
                ST typeTemplate = currentGroup.getInstanceOf("mc_info_type");
                TemplateHandler.add(typeTemplate, "isSet", type instanceof EnumeratedSetElementType || type instanceof DeferredSetElementType);
                TemplateHandler.add(typeTemplate, "machine", machineName);
                TemplateHandler.add(typeTemplate, "type", typeGenerator.generate(type));
                parameterTypes.add(typeTemplate.render());
            }
            operationFunctions.add(new OperationFunctionInfo(opName, parameterTypes));
        }
        return operationFunctions;
    }

    private List<String> generateInvariantFunctions(MachineNode node) {
        List<String> invariantFunctions = new ArrayList<>();
        int invariantSize = invariantGenerator.splitInvariant(node.getInvariant()).size();
        for(int i = 1; i <= invariantSize; i++) {
            invariantFunctions.add("_check_inv_" + i);
        }
        return invariantFunctions;
    }

    public ModelCheckingInfo generateModelCheckingInfo(MachineNode node) {
        String machineName = nameHandler.handle(node.getName());
        List<String> includedMachines = generateIncludedMachines(node);
        List<String> variables = generateVariables(node);
        List<String> constants = generateConstants(node);
        Map<String, String> transitionEvaluationFunctions = generateTransitionEvaluationFunctions(node);
        List<OperationFunctionInfo> operationFunctions = generateOperationFunctions(machineName, node);
        List<String> invariantFunctions = generateInvariantFunctions(node);

        Map<String, List<String>> operationWrites = generateWriteInformation(node.getOperations(), node.getVariables());
        Map<String, List<String>> operationReads = generateReadInformation(node.getOperations(), node.getVariables());
        Map<String, List<String>> invariantReads = generateInvariantReads(node.getInvariant(), node.getVariables());
        Map<String, List<String>> guardsReads = generateGuardsRead(node.getOperations(), node.getVariables());

        // Map from event to invariant conjunct
        Map<String, List<String>> invariantDependency = new HashMap<>();

        for(String writeKey : operationWrites.keySet()) {
            Set<String> dependentInvariant = new HashSet<>();
            for(String invariantReadKey : invariantReads.keySet()) {
                Set<String> writtenVariables = new HashSet<>(operationWrites.get(writeKey));
                Set<String> readVariables = new HashSet<>(invariantReads.get(invariantReadKey));

                for(String writtenVar : writtenVariables) {
                    if(readVariables.contains(writtenVar)) {
                        dependentInvariant.add(invariantReadKey);
                    }
                }
            }
            invariantDependency.put(writeKey, new ArrayList<>(dependentInvariant));
        }


        Map<String, List<String>> guardDependency = new HashMap<>();

        for(String writeKey : operationWrites.keySet()) {
            Set<String> dependentGuard = new HashSet<>();
            for(String guardReadKey : guardsReads.keySet()) {
                Set<String> writtenVariables = new HashSet<>(operationWrites.get(writeKey));
                Set<String> readVariables = new HashSet<>(guardsReads.get(guardReadKey));

                for(String writtenVar : writtenVariables) {
                    if(readVariables.contains(writtenVar)) {
                        dependentGuard.add(guardReadKey);
                    }
                }
            }
            guardDependency.put(writeKey, new ArrayList<>(dependentGuard));
        }

        // TODO: Split guards conjuncts
        return new ModelCheckingInfo(machineName, includedMachines, variables, constants, transitionEvaluationFunctions, operationFunctions, invariantFunctions,
                invariantDependency, guardDependency, guardsReads, operationReads, operationWrites, invariantReads);
    }

    public Map<String, List<String>> generateWriteInformation(List<OperationNode> operations, List<DeclarationNode> variables) {
        List<String> variablesAsString = variables.stream().map(DeclarationNode::toString).collect(Collectors.toList());
        Map<String, List<String>> writeInformation = new HashMap<>();
        for (OperationNode operation : operations) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.WRITE);
            identifierAnalyzer.visitSubstitutionNode(operation.getSubstitution(), null);
            List<String> identifiers = identifierAnalyzer.getIdentifiers()
                    .stream()
                    .filter(variablesAsString::contains)
                    .collect(Collectors.toList());
            String opName = nameHandler.handle(operation.getName());
            writeInformation.put(opName, identifiers);
        }
        return writeInformation;
    }

    public Map<String, List<String>> generateReadInformation(List<OperationNode> operations, List<DeclarationNode> variables) {
        List<String> variablesAsString = variables.stream().map(DeclarationNode::toString).collect(Collectors.toList());
        Map<String, List<String>> readInformation = new HashMap<>();
        for (OperationNode operation : operations) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitSubstitutionNode(operation.getSubstitution(), null);
            List<String> identifiers = identifierAnalyzer.getIdentifiers()
                    .stream()
                    .filter(variablesAsString::contains)
                    .collect(Collectors.toList());
            String opName = nameHandler.handle(operation.getName());
            readInformation.put(opName, identifiers);
        }
        return readInformation;
    }

    public Map<String, List<String>> generateInvariantReads(PredicateNode invariant, List<DeclarationNode> variables) {
        List<PredicateNode> invariantConjuncts = invariantGenerator.splitInvariant(invariant);
        List<String> variablesAsString = variables.stream().map(DeclarationNode::toString).collect(Collectors.toList());
        Map<String, List<String>> invariantReads = new HashMap<>();
        for(int i = 0; i < invariantConjuncts.size(); i++) {
            PredicateNode conj = invariantConjuncts.get(i);
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            identifierAnalyzer.visitPredicateNode(conj, null);
            List<String> identifiers = identifierAnalyzer.getIdentifiers()
                    .stream()
                    .filter(variablesAsString::contains)
                    .collect(Collectors.toList());
            invariantReads.put("_check_inv_" + (i + 1), identifiers);
        }
        return invariantReads;
    }

    public Map<String, List<String>> generateGuardsRead(List<OperationNode> operations, List<DeclarationNode> variables) {
        List<String> variablesAsString = variables.stream().map(DeclarationNode::toString).collect(Collectors.toList());
        Map<String, List<String>> writeInformation = new HashMap<>();
        for (OperationNode operation : operations) {
            IdentifierAnalyzer identifierAnalyzer = new IdentifierAnalyzer(IdentifierAnalyzer.Kind.READ);
            PredicateNode guard = transitionGenerator.extractGuard(operation);
            String opName = "_tr_" + nameHandler.handle(operation.getName());
            List<String> identifiers = new ArrayList<>();
            if(guard != null) {
                identifierAnalyzer.visitPredicateNode(guard, null);
                identifiers.addAll(identifierAnalyzer.getIdentifiers()
                        .stream()
                        .filter(variablesAsString::contains)
                        .collect(Collectors.toList()));
            }
            writeInformation.put(opName, identifiers);
        }
        return writeInformation;
    }


}
