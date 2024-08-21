package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.analyzers.CheckReachabilityAnalyzer;
import de.hhu.stups.codegenerator.handlers.NameHandler;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.modelchecker.ModelCheckingInfo;
import de.hhu.stups.codegenerator.json.modelchecker.OperationFunctionInfo;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.CoupleType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.*;
import java.util.stream.Collectors;

public class ModelCheckingGenerator {

    private ModelCheckingInfo modelCheckingInfo;

    private final STGroup currentGroup;

    private final NameHandler nameHandler;

    private final TypeGenerator typeGenerator;

    private final BacktrackingGenerator backtrackingGenerator;

    private final CheckReachabilityAnalyzer checkReachabilityAnalyzer;

    private Map<String, Integer> invariantIDs;

    private Map<String, Integer> operationIDs;

    private Map<String, Integer> evalTransitionsIDs;

    public ModelCheckingGenerator(final STGroup currentGroup, final NameHandler nameHandler,
                                  final TypeGenerator typeGenerator, final BacktrackingGenerator backtrackingGenerator,
                                  final CheckReachabilityAnalyzer checkReachabilityAnalyzer) {
        this.currentGroup = currentGroup;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.backtrackingGenerator = backtrackingGenerator;
        this.checkReachabilityAnalyzer = checkReachabilityAnalyzer;
    }

    // If we use IDs to implement caching, then this code will be helpful
    private void initIDMaps() {
        int invariantID = 1;
        for(String invariant : modelCheckingInfo.getInvariantFunctions()) {
            invariantIDs.put(invariant, invariantID);
            invariantID++;
        }

        int operationID = 1;
        for(OperationFunctionInfo operationFunctionInfo : modelCheckingInfo.getOperationFunctions()) {
            operationIDs.put(operationFunctionInfo.getOpName(), operationID);
            operationID++;
        }

        int transitionID = 1;
        for(Map.Entry<String, String> entry : modelCheckingInfo.getTransitionEvaluationFunctions().entrySet()) {
            evalTransitionsIDs.put(entry.getValue(), transitionID);
            transitionID++;
        }
    }

    public String generate(MachineNode machineNode, boolean forModelChecking, boolean isIncludedMachine, boolean forVisualisation) {
        if((forModelChecking || forVisualisation) && !isIncludedMachine) {
            typeGenerator.setFromOutside(true);

            ST template = currentGroup.getInstanceOf("modelchecker");
            TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
            List<String> initializeCaches = new ArrayList<>(generateOpCaches(machineNode));
            initializeCaches.addAll(generateInvCaches());
            TemplateHandler.add(template, "initializeCaches", initializeCaches);
            TemplateHandler.add(template, "main", generateMain(machineNode));
            TemplateHandler.add(template, "nextStates", generateNextStates(machineNode));
            TemplateHandler.add(template, "invariantViolated", generateModelCheckInvariantsFunction(machineNode));
            TemplateHandler.add(template, "printResult", generatePrintResult(machineNode));

            typeGenerator.setFromOutside(false);
            return template.render();
        }
        return "";
    }

    private List<String> generateOpCaches(MachineNode machineNode) {
        List<String> opCaches = new ArrayList<>();
        for(OperationNode operationNode : machineNode.getOperations()) {
            boolean hasParameters = !operationNode.getParams().isEmpty();
            ST template = currentGroup.getInstanceOf("opreuse_initialize_opcaches");
            TemplateHandler.add(template, "operation", nameHandler.handle(operationNode.getName()));
            TemplateHandler.add(template, "hasParameters", hasParameters);
            BType tupleType;
            if(!hasParameters) {
                tupleType = null;
            } else {
                tupleType = this.extractTypeFromDeclarations(operationNode.getParams());
            }
            if(hasParameters) {
                TemplateHandler.add(template, "tupleType", typeGenerator.generate(tupleType));
            }
            opCaches.add(template.render());
        }
        return opCaches;
    }

    private List<String> generateInvCaches() {
        List<String> invariantCaches = new ArrayList<>();
        for(String invariant : modelCheckingInfo.getInvariantFunctions()) {
            ST template = currentGroup.getInstanceOf("opreuse_initialize_invariant_caches");
            TemplateHandler.add(template, "invariant", invariant);
            TemplateHandler.add(template, "readType", "_ProjectionRead_");
            invariantCaches.add(template.render());
        }
        return invariantCaches;
    }

    public String generateNextStates(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_next_states");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "transitionsWithCaching", generateTransitions(machineNode, true));
        TemplateHandler.add(template, "transitionsWithoutCaching", generateTransitions(machineNode, false));
        return template.render();
    }

    public List<String> generateTransitions(MachineNode machineNode, boolean isCaching) {
        List<String> transitions = new ArrayList<>();
        List<OperationNode> operations = machineNode.getOperations();
        for(int i = 0; i < operations.size(); i++) {
            transitions.add(generateTransition(machineNode, operations.get(i), i+1, isCaching));
        }
        return transitions;
    }

    public String generateTransition(MachineNode machineNode, OperationNode operationNode, int index, boolean isCaching) {
        ST template = currentGroup.getInstanceOf("model_check_transition");
        String opName = nameHandler.handle(operationNode.getName());
        boolean hasParameters = !operationNode.getParams().isEmpty();
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "hasParameters", hasParameters);
        BType tupleType;
        if(!hasParameters) {
            tupleType = null;
        } else {
            tupleType = this.extractTypeFromDeclarations(operationNode.getParams());
        }
        if(hasParameters) {
            TemplateHandler.add(template, "tupleType", typeGenerator.generate(tupleType));
        }
        TemplateHandler.add(template, "transitionIdentifier", "_trid_" + index);

        TemplateHandler.add(template, "evalTransitions", modelCheckingInfo.getTransitionEvaluationFunctions().get(opName));
        //TemplateHandler.add(template, "evalTransitionsID", evalTransitionsIDs.get(modelCheckingInfo.getTransitionEvaluationFunctions().get(opName)));
        TemplateHandler.add(template, "execTransitions", generateTransitionBody(machineNode, operationNode, tupleType, isCaching, "_trid_" + index));
        TemplateHandler.add(template, "isCaching", isCaching);
        return template.render();
    }

    private String generateDeclarationForOpReuse(DeclarationNode declarationNode, String variable) {
        String type = typeGenerator.generate(declarationNode.getType());
        ST declaration = currentGroup.getInstanceOf("opreuse_declaration");
        TemplateHandler.add(declaration, "type", type);
        TemplateHandler.add(declaration, "variable", variable);
        return declaration.render();
    }

    private String generateParameterForOpReuse(DeclarationNode declarationNode, String variable) {
        String type = typeGenerator.generate(declarationNode.getType());
        ST parameter = currentGroup.getInstanceOf("opreuse_parameter");
        TemplateHandler.add(parameter, "type", type);
        TemplateHandler.add(parameter, "variable", variable);
        return parameter.render();
    }

    public String generateClassesForOpReuse(MachineNode machineNode, boolean isRead, boolean isGuard, boolean isInvariant, String operation) {
        ST classes = currentGroup.getInstanceOf("opreuse_class");

        List<String> variables = new ArrayList<>();

        if(isRead) {
            if(isGuard) {
                variables = modelCheckingInfo.getGuardsRead().get("_tr_" + nameHandler.handle(operation));
            } else if(isInvariant) {
                variables = modelCheckingInfo.getInvariantsRead().get(nameHandler.handle(operation));
            } else {
                variables = modelCheckingInfo.getOperationsRead().get(nameHandler.handle(operation));
            }
        } else { // Write
            variables = modelCheckingInfo.getOperationsWrite().get(nameHandler.handle(operation));
        }

        TemplateHandler.add(classes, "isRead", isRead);
        TemplateHandler.add(classes, "isGuard", isGuard);
        TemplateHandler.add(classes, "isInvariant", isInvariant);
        TemplateHandler.add(classes, "name", nameHandler.handle(operation));

        List<String> declarations = new ArrayList<>();
        List<String> parameters = new ArrayList<>();

        List<DeclarationNode> constantNodes = machineNode.getConstants();
        List<DeclarationNode> variableNodes = machineNode.getVariables();

        for(String var : variables) {
            for(DeclarationNode constantNode : constantNodes) {
                if(constantNode.getName().equals(var)) {
                    declarations.add(generateDeclarationForOpReuse(constantNode, nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES)));
                    parameters.add(generateParameterForOpReuse(constantNode, nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES)));
                }
            }
            for(DeclarationNode variableNode : variableNodes) {
                if(variableNode.getName().equals(var)) {
                    declarations.add(generateDeclarationForOpReuse(variableNode, nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES)));
                    parameters.add(generateParameterForOpReuse(variableNode, nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES)));
                }
            }
        }


        TemplateHandler.add(classes, "declarations", declarations);
        TemplateHandler.add(classes, "parameters", parameters);
        TemplateHandler.add(classes, "variables", variables.stream()
                .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                .collect(Collectors.toList()));
        return classes.render();
    }

    public List<String> generateProjection() {
        List<String> result = new ArrayList<>();
        result.addAll(generateReadProjection(modelCheckingInfo.getOperationsRead()));
        result.addAll(generateReadGrdProjection(modelCheckingInfo.getGuardsRead()));
        result.addAll(generateReadInvProjection(modelCheckingInfo.getInvariantsRead()));
        result.addAll(generateWriteProjection(modelCheckingInfo.getOperationsWrite()));
        result.addAll(generateApplyWriteProjection(modelCheckingInfo.getOperationsWrite()));
        return result;
    }

    private List<String> generateReadProjection(Map<String, List<String>> operationReads) {
        List<String> result = new ArrayList<>();
        for(String operation : operationReads.keySet()) {
            result.add(generateReadProjectionForOperation(operation, operationReads.get(operation).stream()
                    .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                    .collect(Collectors.toList())));
        }
        return result;
    }

    private String generateReadProjectionForOperation(String operation, List<String> reads) {
        ST template = currentGroup.getInstanceOf("opreuse_read_projection");
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "projectState", reads);
        return template.render();
    }

    private List<String> generateReadGrdProjection(Map<String, List<String>> operationGrdReads) {
        List<String> result = new ArrayList<>();
        for(String operation : operationGrdReads.keySet()) {
            result.add(generateReadGrdProjectionForOperation(operation, operationGrdReads.get(operation).stream()
                    .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                    .collect(Collectors.toList())));
        }
        return result;
    }

    private String generateReadGrdProjectionForOperation(String operation, List<String> reads) {
        ST template = currentGroup.getInstanceOf("opreuse_grd_read_projection");
        TemplateHandler.add(template, "operation", nameHandler.handle(operation));
        TemplateHandler.add(template, "projectState", reads);
        return template.render();
    }

    private List<String> generateReadInvProjection(Map<String, List<String>> operationInvReads) {
        List<String> result = new ArrayList<>();
        for(String invariant : operationInvReads.keySet()) {
            result.add(generateReadInvProjectionForOperation(invariant, operationInvReads.get(invariant).stream()
                    .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                    .collect(Collectors.toList())));
        }
        return result;
    }

    private String generateReadInvProjectionForOperation(String invariant, List<String> reads) {
        ST template = currentGroup.getInstanceOf("opreuse_inv_read_projection");
        TemplateHandler.add(template, "invariant", invariant);
        TemplateHandler.add(template, "projectState", reads);
        return template.render();
    }

    private List<String> generateWriteProjection(Map<String, List<String>> operationWrites) {
        List<String> result = new ArrayList<>();
        for(String operation : operationWrites.keySet()) {
            result.add(generateWriteProjectionForOperation(operation, operationWrites.get(operation).stream()
                    .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                    .collect(Collectors.toList())));
        }
        return result;
    }

    private List<String> generateApplyWriteProjection(Map<String, List<String>> operationWrites) {
        List<String> result = new ArrayList<>();
        for(String operation : operationWrites.keySet()) {
            result.add(generateApplyWriteProjectionForOperation(operation, operationWrites.get(operation).stream()
                    .map(var -> nameHandler.handleIdentifier(var, NameHandler.IdentifierHandlingEnum.FUNCTION_NAMES))
                    .collect(Collectors.toList())));
        }
        return result;
    }

    private String generateWriteProjectionForOperation(String operation, List<String> writes) {
        ST template = currentGroup.getInstanceOf("opreuse_write_projection");
        TemplateHandler.add(template, "operation", nameHandler.handle(operation));
        TemplateHandler.add(template, "projectState", writes);
        return template.render();
    }


    private String generateApplyWriteProjectionForOperation(String operation, List<String> writes) {
        ST template = currentGroup.getInstanceOf("opreuse_apply_update");
        TemplateHandler.add(template, "operation", nameHandler.handle(operation));
        TemplateHandler.add(template, "projectState", writes);
        return template.render();
    }

    public String generateTransitionBody(MachineNode machineNode, OperationNode opNode, BType tupleType, boolean isCaching, String transitionIdentifier) {
        ST template = currentGroup.getInstanceOf("model_check_transition_body");
        boolean hasParameters = !opNode.getParams().isEmpty();
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "operation", nameHandler.handle(opNode.getName()));
        TemplateHandler.add(template, "isCaching", isCaching);
        //TemplateHandler.add(template, "isNondeterministic", backtrackingGenerator.isNondeterministic(opNode.getName())); // TODO: Fix
        TemplateHandler.add(template, "isNondeterministic", false);
        //TemplateHandler.add(template, "operationID", operationIDs.get(nameHandler.handle(opNode.getName())));
        TemplateHandler.add(template, "hasParameters", hasParameters);
        TemplateHandler.add(template, "checkReachability", checkReachabilityAnalyzer.visitOperation(opNode));

        String evalName = hasParameters ? "param" : transitionIdentifier;
        List<String> readParameters = new ArrayList<>();
        List<String> parameters = new ArrayList<>();


        if(hasParameters) {

            BType currentType = tupleType;

            List<DeclarationNode> declarationParams = opNode.getParams();

            if (declarationParams.size() == 1) {
                ST paramTemplateLhs = currentGroup.getInstanceOf("model_check_transition_param_assignment");
                TemplateHandler.add(paramTemplateLhs, "type", typeGenerator.generate(currentType));
                TemplateHandler.add(paramTemplateLhs, "param", "_tmp_" + 1);
                TemplateHandler.add(paramTemplateLhs, "val", "param");
                TemplateHandler.add(paramTemplateLhs, "isLhs", false);
                TemplateHandler.add(paramTemplateLhs, "oneParameter", true);
                String lhsParameter = paramTemplateLhs.render();
                readParameters.add(lhsParameter);
                parameters.add("_tmp_" + 1);
            } else {
                int j = 1;
                for (int i = 0; i < declarationParams.size(); i++) {
                    DeclarationNode paramNode = opNode.getParams().get(declarationParams.size() - 1 - i);


                    if (i < opNode.getParams().size() - 1) {
                        // Access rhs were it is not the left-most parameter

                        ST paramTemplateLhs = currentGroup.getInstanceOf("model_check_transition_param_assignment");
                        TemplateHandler.add(paramTemplateLhs, "type", typeGenerator.generate(paramNode.getType()));
                        TemplateHandler.add(paramTemplateLhs, "param", "_tmp_" + j);
                        TemplateHandler.add(paramTemplateLhs, "val", j == 1 ? "param" : "_tmp_" + (j - 1));
                        TemplateHandler.add(paramTemplateLhs, "isLhs", false);
                        TemplateHandler.add(paramTemplateLhs, "oneParameter", false);
                        String lhsParameter = paramTemplateLhs.render();
                        readParameters.add(lhsParameter);
                        parameters.add(0, "_tmp_" + j);

                        j++;



                        if(i < opNode.getParams().size() - 2) {
                            // Store temporary tuples im necessary
                            currentType = ((CoupleType) currentType).getLeft();
                            ST paramTemplateRhs = currentGroup.getInstanceOf("model_check_transition_param_assignment");
                            TemplateHandler.add(paramTemplateRhs, "type", typeGenerator.generate(currentType));
                            TemplateHandler.add(paramTemplateRhs, "param", "_tmp_" + j);
                            TemplateHandler.add(paramTemplateRhs, "val", j == 2 ? "param" : "_tmp_" + (j - 2));
                            TemplateHandler.add(paramTemplateRhs, "isLhs", true);
                            TemplateHandler.add(paramTemplateRhs, "oneParameter", false);
                            readParameters.add(paramTemplateRhs.render());
                            j++;
                        }
                    } else {
                        // Access left-most parameter
                        ST paramTemplateLhs = currentGroup.getInstanceOf("model_check_transition_param_assignment");
                        TemplateHandler.add(paramTemplateLhs, "type", typeGenerator.generate(paramNode.getType()));
                        TemplateHandler.add(paramTemplateLhs, "param", "_tmp_" + j);
                        TemplateHandler.add(paramTemplateLhs, "val", j == 2 ? "param" : "_tmp_" + (j - 2));
                        TemplateHandler.add(paramTemplateLhs, "isLhs", true);
                        TemplateHandler.add(paramTemplateLhs, "oneParameter", false);
                        String lhsParameter = paramTemplateLhs.render();
                        readParameters.add(lhsParameter);
                        parameters.add(0, "_tmp_" + j);
                        j++;
                    }

                }
            }
        }
        TemplateHandler.add(template, "transitionEval", evalName);
        TemplateHandler.add(template, "readParameters", readParameters);
        TemplateHandler.add(template, "parameters", parameters);
        return template.render();
    }

    public String generateEvalState(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_evaluate_state");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "variables", generateEvaluateVariables());
        return template.render();
    }

    public List<String> generateEvaluateVariables() {
        List<String> variables = new ArrayList<>();
        for(String variable : modelCheckingInfo.getVariables()) {
            ST template = currentGroup.getInstanceOf("model_check_evaluate_variable");
            TemplateHandler.add(template, "getter", variable);
            variables.add(template.render());
        }
        return variables;
    }

    public String generatePrintResult(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_print");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        return template.render();
    }

    public String generateMain(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_main");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "invariants", modelCheckingInfo.getInvariantFunctions());

        Map<Integer, List<Integer>> invariantDependencyIDs = new HashMap<>();
        Map<Integer, List<Integer>> guardDependencyIDs = new HashMap<>();

        for(String key : modelCheckingInfo.getInvariantDependency().keySet()) {
            invariantDependencyIDs.put(operationIDs.get(key), modelCheckingInfo.getInvariantDependency().get(key).stream().map(id -> invariantIDs.get(id)).collect(Collectors.toList()));
        }

        for(String key : modelCheckingInfo.getInvariantDependency().keySet()) {
            guardDependencyIDs.put(operationIDs.get(key), modelCheckingInfo.getGuardDependency().get(key).stream().map(id -> evalTransitionsIDs.get(id)).collect(Collectors.toList()));
        }

        TemplateHandler.add(template, "invariantDependency", generateStaticInformation("invariantDependency", modelCheckingInfo.getInvariantDependency()));
        TemplateHandler.add(template, "guardDependency", generateStaticInformation("guardDependency", modelCheckingInfo.getGuardDependency()));
        return template.render();
    }

    public String generateMainMethod(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_main_method");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        return template.render();
    }

    private List<String> generateStaticInformation(String mapName, Map<String, List<String>> map) {
        List<String> information = new ArrayList<>();
        for(String key : map.keySet()) {
            information.add(generateStaticEntry(mapName, key, map.get(key)));
        }
        return information;
    }

    private String generateStaticEntry(String map, String key, List<String> entries) {
        ST template = currentGroup.getInstanceOf("model_check_init_static");
        TemplateHandler.add(template, "map", map);
        TemplateHandler.add(template, "keyy", key);
        TemplateHandler.add(template, "entries", entries);
        return template.render();
    }

    public String generateModelCheckInvariantsFunction(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_invariants");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "invariantViolated", generateModelCheckInvariants());
        TemplateHandler.add(template, "invariants", modelCheckingInfo.getInvariantFunctions());
        return template.render();
    }

    public List<String> generateModelCheckInvariants() {
        List<String> invariants = new ArrayList<>();
        for(String invariant : modelCheckingInfo.getInvariantFunctions()) {
            ST template = currentGroup.getInstanceOf("model_check_invariant");
            TemplateHandler.add(template, "invariant", invariant);
            //TemplateHandler.add(template, "invariantID", invariantIDs.get(invariant));
            invariants.add(template.render());
        }
        return invariants;
    }

    public String generateModelCheckingProBProp(MachineNode machineNode) {

        List<String> invariantFunctions = modelCheckingInfo.getInvariantFunctions().stream()
                .map(inv -> inv = inv.startsWith("_") ? inv.replaceFirst("_", "") : inv)
                .collect(Collectors.toList());

        ST template = currentGroup.getInstanceOf("props");
        TemplateHandler.add(template, "invariants", invariantFunctions);
        return template.render();
    }


    /*
     * This function extracts the couple type from a list of declarations
     */
    public BType extractTypeFromDeclarations(List<DeclarationNode> declarations) {
        if(declarations.size() == 1) {
            return declarations.get(0).getType();
        }
        CoupleType result = new CoupleType(declarations.get(0).getType(), declarations.get(1).getType());
        for(int i = 2; i < declarations.size(); i++) {
            result = new CoupleType(result, declarations.get(i).getType());
        }
        return result;
    }

    public List<String> generateHashEqualToString() {
        return Arrays.asList(generateEqual(), generateUnequal(), generateHash(), generateToString());
    }

    public String generateEqual() {
        ST template = currentGroup.getInstanceOf("machine_equal");
        TemplateHandler.add(template, "machine", modelCheckingInfo.getMachineName());
        List<String> predicates = new ArrayList<>();
        for(String var : modelCheckingInfo.getIncludedMachines()) {
            ST predicateTemplate = currentGroup.getInstanceOf("machine_equal_predicate");
            TemplateHandler.add(predicateTemplate, "var", var);
            predicates.add(predicateTemplate.render());
        }
        for(String var : modelCheckingInfo.getVariables()) {
            ST predicateTemplate = currentGroup.getInstanceOf("machine_equal_predicate");
            TemplateHandler.add(predicateTemplate, "var", var);
            predicates.add(predicateTemplate.render());
        }
        TemplateHandler.add(template, "predicates", predicates);
        return template.render();
    }

    public String generateUnequal() {
        ST template = currentGroup.getInstanceOf("machine_unequal");
        TemplateHandler.add(template, "machine", modelCheckingInfo.getMachineName());
        List<String> predicates = new ArrayList<>();
        for(String var : modelCheckingInfo.getIncludedMachines()) {
            ST predicateTemplate = currentGroup.getInstanceOf("machine_unequal_predicate");
            TemplateHandler.add(predicateTemplate, "var", var);
            predicates.add(predicateTemplate.render());
        }
        for(String var : modelCheckingInfo.getVariables()) {
            ST predicateTemplate = currentGroup.getInstanceOf("machine_unequal_predicate");
            TemplateHandler.add(predicateTemplate, "var", var);
            predicates.add(predicateTemplate.render());
        }
        TemplateHandler.add(template, "predicates", predicates);
        return template.render();
    }

    public String generateHash() {
        ST template = currentGroup.getInstanceOf("machine_hash");
        List<String> assignments1 = new ArrayList<>();
        for(String var : modelCheckingInfo.getIncludedMachines()) {
            ST assignmentTemplate = currentGroup.getInstanceOf("machine_hash_assignment");
            TemplateHandler.add(assignmentTemplate, "primeNumber", 1543);
            TemplateHandler.add(assignmentTemplate, "var", var);
            assignments1.add(assignmentTemplate.render());
        }
        for(String var : modelCheckingInfo.getVariables()) {
            ST assignmentTemplate = currentGroup.getInstanceOf("machine_hash_assignment");
            TemplateHandler.add(assignmentTemplate, "primeNumber", 1543);
            TemplateHandler.add(assignmentTemplate, "var", var);
            assignments1.add(assignmentTemplate.render());
        }

        List<String> assignments2 = new ArrayList<>();
        for(String var : modelCheckingInfo.getIncludedMachines()) {
            ST assignmentTemplate = currentGroup.getInstanceOf("machine_hash_assignment");
            TemplateHandler.add(assignmentTemplate, "primeNumber", 6151);
            TemplateHandler.add(assignmentTemplate, "var", var);
            assignments2.add(assignmentTemplate.render());
        }
        for(String var : modelCheckingInfo.getVariables()) {
            ST assignmentTemplate = currentGroup.getInstanceOf("machine_hash_assignment");
            TemplateHandler.add(assignmentTemplate, "primeNumber", 6151);
            TemplateHandler.add(assignmentTemplate, "var", var);
            assignments2.add(assignmentTemplate.render());
        }

        TemplateHandler.add(template, "assignments1", assignments1);
        TemplateHandler.add(template, "assignments2", assignments2);
        return template.render();
    }

    public String generateToString() {
        List<String> variablesForToString = new ArrayList<>();
        variablesForToString.addAll(modelCheckingInfo.getIncludedMachines());
        variablesForToString.addAll(modelCheckingInfo.getVariables());

        ST template = currentGroup.getInstanceOf("machine_string");
        TemplateHandler.add(template, "machine", modelCheckingInfo.getMachineName());
        TemplateHandler.add(template, "variables", variablesForToString);
        return template.render();
    }


    public void setModelCheckingInfo(ModelCheckingInfo modelCheckingInfo) {
        this.modelCheckingInfo = modelCheckingInfo;
        this.invariantIDs = new HashMap<>();
        this.operationIDs = new HashMap<>();
        this.evalTransitionsIDs = new HashMap<>();
        initIDMaps();
    }

    public ModelCheckingInfo getModelCheckingInfo() {
        return modelCheckingInfo;
    }
}