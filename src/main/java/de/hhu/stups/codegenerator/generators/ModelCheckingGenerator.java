package de.hhu.stups.codegenerator.generators;

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

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class ModelCheckingGenerator {

    private ModelCheckingInfo modelCheckingInfo;

    private final STGroup currentGroup;

    private final NameHandler nameHandler;

    private final TypeGenerator typeGenerator;

    private final BacktrackingGenerator backtrackingGenerator;

    private Map<String, Integer> invariantIDs;

    private Map<String, Integer> operationIDs;

    private Map<String, Integer> evalTransitionsIDs;

    public ModelCheckingGenerator(final STGroup currentGroup, final NameHandler nameHandler,
                                  final TypeGenerator typeGenerator, final BacktrackingGenerator backtrackingGenerator) {
        this.currentGroup = currentGroup;
        this.nameHandler = nameHandler;
        this.typeGenerator = typeGenerator;
        this.backtrackingGenerator = backtrackingGenerator;
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
//            ST template = currentGroup.getInstanceOf("model_check");
//            TemplateHandler.add(template, "addCachedInfos", generateAddCachedInfos(machineNode));
//            TemplateHandler.add(template, "nextStates", generateNextStates(machineNode));
//            TemplateHandler.add(template, "evalState", generateEvalState(machineNode));
//            TemplateHandler.add(template, "invariantViolated", generateModelCheckInvariantsFunction(machineNode));
//            TemplateHandler.add(template, "printResult", generatePrintResult(machineNode));
//            TemplateHandler.add(template, "main", generateMain(machineNode));

            ST template = currentGroup.getInstanceOf("modelchecker");
            TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
            TemplateHandler.add(template, "addCachedInfos", generateAddCachedInfos(machineNode));
            TemplateHandler.add(template, "main", generateMain(machineNode));
            TemplateHandler.add(template, "nextStates", generateNextStates(machineNode));
            TemplateHandler.add(template, "invariantViolated", generateModelCheckInvariantsFunction(machineNode));
            TemplateHandler.add(template, "printResult", generatePrintResult(machineNode));

            typeGenerator.setFromOutside(false);
            return template.render();
        }
        return "";
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
        TemplateHandler.add(template, "execTransitions", generateTransitionBody(machineNode, operationNode, tupleType, isCaching));
        TemplateHandler.add(template, "isCaching", isCaching);
        return template.render();
    }

    private String generateAddCachedInfos(MachineNode machineNode) {
        ST template = currentGroup.getInstanceOf("model_check_add_cached_infos");
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        return template.render();
    }

    public String generateTransitionBody(MachineNode machineNode, OperationNode opNode, BType tupleType, boolean isCaching) {
        ST template = currentGroup.getInstanceOf("model_check_transition_body");
        boolean hasParameters = !opNode.getParams().isEmpty();
        TemplateHandler.add(template, "machine", nameHandler.handle(machineNode.getName()));
        TemplateHandler.add(template, "operation", nameHandler.handle(opNode.getName()));
        TemplateHandler.add(template, "isNondeterministic", backtrackingGenerator.isNondeterministic(opNode.getName()));
        //TemplateHandler.add(template, "operationID", operationIDs.get(nameHandler.handle(opNode.getName())));
        TemplateHandler.add(template, "hasParameters", hasParameters);
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
        for(String var : modelCheckingInfo.getVariables()) {
            ST assignmentTemplate = currentGroup.getInstanceOf("machine_hash_assignment");
            TemplateHandler.add(assignmentTemplate, "primeNumber", 1543);
            TemplateHandler.add(assignmentTemplate, "var", var);
            assignments1.add(assignmentTemplate.render());
        }

        List<String> assignments2 = new ArrayList<>();
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
        ST template = currentGroup.getInstanceOf("machine_string");
        TemplateHandler.add(template, "machine", modelCheckingInfo.getMachineName());
        TemplateHandler.add(template, "variables", modelCheckingInfo.getVariables());
        return template.render();
    }



    public void setModelCheckingInfo(ModelCheckingInfo modelCheckingInfo) {
        this.modelCheckingInfo = modelCheckingInfo;
        this.invariantIDs = new HashMap<>();
        this.operationIDs = new HashMap<>();
        this.evalTransitionsIDs = new HashMap<>();
        initIDMaps();
    }
}