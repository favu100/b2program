package de.hhu.stups.codegenerator.json.modelchecker;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

import java.util.List;
import java.util.Map;

public class ModelCheckingInfo {

    private final String machineName;

    private final List<String> variables;

    private final List<String> constants;

    private final List<OperationFunctionInfo> operationFunctions;

    private final Map<String, String> transitionEvaluationFunctions;

    private final List<String> invariantFunctions;

    private final Map<String, List<String>> invariantDependency;

    private final Map<String, List<String>> guardDependency;

    public ModelCheckingInfo(final String machineName, final List<String> variables, final List<String> constants, final Map<String, String> transitionEvaluationFunctions,
                             final List<OperationFunctionInfo> operationFunctions, final List<String> invariantFunctions,
                             final Map<String, List<String>> invariantDependency, final Map<String, List<String>> guardDependency) {
        this.machineName = machineName;
        this.variables = variables;
        this.constants = constants;
        this.transitionEvaluationFunctions = transitionEvaluationFunctions;
        this.operationFunctions = operationFunctions;
        this.invariantFunctions = invariantFunctions;
        this.invariantDependency = invariantDependency;
        this.guardDependency = guardDependency;
    }

    public String getMachineName() {
        return machineName;
    }

    public List<String> getVariables() {
        return variables;
    }

    public List<String> getConstants() {
        return constants;
    }

    public Map<String, String> getTransitionEvaluationFunctions() {
        return transitionEvaluationFunctions;
    }

    public List<OperationFunctionInfo> getOperationFunctions() {
        return operationFunctions;
    }

    public List<String> getInvariantFunctions() {
        return invariantFunctions;
    }

    public Map<String, List<String>> getInvariantDependency() {
        return invariantDependency;
    }

    public Map<String, List<String>> getGuardDependency() {
        return guardDependency;
    }

    @Override
    public String toString() {
        return "ModelCheckingInfo{" +
                "machineName='" + machineName + '\'' +
                ", variables=" + variables +
                ", operationFunctions=" + operationFunctions +
                ", transitionEvaluationFunctions=" + transitionEvaluationFunctions +
                ", invariantFunctions=" + invariantFunctions +
                ", invariantDependency=" + invariantDependency +
                ", guardDependency=" + guardDependency +
                '}';
    }

    public JsonObject toJsonObject() {
        JsonObject jsonObject = new JsonObject();
        jsonObject.addProperty("machineName", machineName);

        JsonArray variablesArray = new JsonArray();
        variables.forEach(variablesArray::add);
        jsonObject.add("variables", variablesArray);

        JsonArray operationFunctionsArray = new JsonArray();
        for(OperationFunctionInfo opInfo : operationFunctions) {
            JsonObject opInfoObject = new JsonObject();
            opInfoObject.addProperty("opName", opInfo.getOpName());

            JsonArray typesArray = new JsonArray();
            for(String type : opInfo.getParameterTypes()) {
                typesArray.add(type);
            }
            opInfoObject.add("parameterTypes", typesArray);
            operationFunctionsArray.add(opInfoObject);
        }
        jsonObject.add("operationFunctions", operationFunctionsArray);

        JsonObject transitionEvaluationObject = new JsonObject();
        for(String key : transitionEvaluationFunctions.keySet()) {
            transitionEvaluationObject.addProperty(key, transitionEvaluationFunctions.get(key));
        }
        jsonObject.add("transitionEvaluationFunctions", transitionEvaluationObject);

        JsonArray invariantsArray = new JsonArray();
        invariantFunctions.forEach(invariantsArray::add);
        jsonObject.add("invariants", invariantsArray);


        JsonObject writeInformationObject = new JsonObject();
        for(String key : invariantDependency.keySet()) {
            JsonArray invariantDependencyArray = new JsonArray();
            invariantDependency.get(key).forEach(invariantDependencyArray::add);
            writeInformationObject.add(key, invariantDependencyArray);
        }
        jsonObject.add("invariantDependency", writeInformationObject);

        JsonObject invariantReadsObject = new JsonObject();
        for(String key : guardDependency.keySet()) {
            JsonArray guardReadsArray = new JsonArray();
            guardDependency.get(key).forEach(guardReadsArray::add);
            invariantReadsObject.add(key, guardReadsArray);
        }
        jsonObject.add("guardDependency", invariantReadsObject);

        return jsonObject;
    }
}
