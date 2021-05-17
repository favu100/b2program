package de.hhu.stups.codegenerator.json.modelchecker;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

import java.util.List;
import java.util.Map;

public class ModelCheckingInfo {

    private final String machineName;

    private final List<String> variables;

    private final List<OperationFunctionInfo> operationFunctions;

    private final Map<String, String> transitionEvaluationFunctions;

    public ModelCheckingInfo(final String machineName, final List<String> variables, final Map<String, String> transitionEvaluationFunctions,
                             final List<OperationFunctionInfo> operationFunctions) {
        this.machineName = machineName;
        this.variables = variables;
        this.transitionEvaluationFunctions = transitionEvaluationFunctions;
        this.operationFunctions = operationFunctions;
    }

    public String getMachineName() {
        return machineName;
    }

    public List<String> getVariables() {
        return variables;
    }

    public Map<String, String> getTransitionEvaluationFunctions() {
        return transitionEvaluationFunctions;
    }

    public List<OperationFunctionInfo> getOperationFunctions() {
        return operationFunctions;
    }

    @Override
    public String toString() {
        return "ModelCheckingInfo{" +
                "machineName='" + machineName + '\'' +
                ", variables=" + variables +
                ", operationFunctions=" + operationFunctions +
                ", transitionEvaluationFunctions=" + transitionEvaluationFunctions +
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

        return jsonObject;
    }
}
