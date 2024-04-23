package de.hhu.stups.codegenerator.json.modelchecker;

import com.google.gson.JsonArray;
import com.google.gson.JsonObject;

import java.util.List;
import java.util.Map;
import java.util.StringJoiner;

public class ModelCheckingInfo {

    private final String machineName;

    private final List<String> includedMachines;

    private final List<String> variables;

    private final List<String> constants;

    private final List<OperationFunctionInfo> operationFunctions;

    private final Map<String, String> transitionEvaluationFunctions;

    private final List<String> invariantFunctions;

    private final Map<String, List<String>> invariantDependency;

    private final Map<String, List<String>> guardDependency;

    private final Map<String, List<String>> guardsRead;

    private final Map<String, List<String>> operationsRead;

    private final Map<String, List<String>> operationsWrite;

    public ModelCheckingInfo(final String machineName, final List<String> includedMachines, final List<String> variables, final List<String> constants, final Map<String, String> transitionEvaluationFunctions,
                             final List<OperationFunctionInfo> operationFunctions, final List<String> invariantFunctions,
                             final Map<String, List<String>> invariantDependency, final Map<String, List<String>> guardDependency,
                             final Map<String, List<String>> guardsRead,
                             final Map<String, List<String>> operationsRead, final Map<String, List<String>> operationsWrite) {
        this.machineName = machineName;
        this.includedMachines = includedMachines;
        this.variables = variables;
        this.constants = constants;
        this.transitionEvaluationFunctions = transitionEvaluationFunctions;
        this.operationFunctions = operationFunctions;
        this.invariantFunctions = invariantFunctions;
        this.invariantDependency = invariantDependency;
        this.guardDependency = guardDependency;
        this.guardsRead = guardsRead;
        this.operationsRead = operationsRead;
        this.operationsWrite = operationsWrite;
    }

    public String getMachineName() {
        return machineName;
    }

    public List<String> getIncludedMachines() {
        return includedMachines;
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

    public Map<String, List<String>> getGuardsRead() {
        return guardsRead;
    }

    public Map<String, List<String>> getOperationsRead() {
        return operationsRead;
    }

    public Map<String, List<String>> getOperationsWrite() {
        return operationsWrite;
    }

    @Override
    public String toString() {
        return new StringJoiner(", ", ModelCheckingInfo.class.getSimpleName() + "[", "]")
                .add("machineName='" + machineName + "'")
                .add("includedMachines=" + includedMachines)
                .add("variables=" + variables)
                .add("constants=" + constants)
                .add("operationFunctions=" + operationFunctions)
                .add("transitionEvaluationFunctions=" + transitionEvaluationFunctions)
                .add("invariantFunctions=" + invariantFunctions)
                .add("invariantDependency=" + invariantDependency)
                .add("guardDependency=" + guardDependency)
                .add("guardsRead=" + guardsRead)
                .add("operationsRead=" + operationsRead)
                .add("operationsWrite=" + operationsWrite)
                .toString();
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

        JsonArray includedMachinesArray = new JsonArray();
        includedMachines.forEach(includedMachinesArray::add);
        jsonObject.add("includedMachines", includedMachinesArray);


        JsonObject writeInformationObject = new JsonObject();
        for(String key : invariantDependency.keySet()) {
            JsonArray invariantDependencyArray = new JsonArray();
            invariantDependency.get(key).forEach(invariantDependencyArray::add);
            writeInformationObject.add(key, invariantDependencyArray);
        }
        jsonObject.add("invariantDependency", writeInformationObject);

        JsonObject guardReadsObject = new JsonObject();
        for(String key : guardDependency.keySet()) {
            JsonArray guardReadsArray = new JsonArray();
            guardDependency.get(key).forEach(guardReadsArray::add);
            guardReadsObject.add(key, guardReadsArray);
        }
        jsonObject.add("guardDependency", guardReadsObject);

        JsonObject readGuardsObject = new JsonObject();
        for(String key : guardsRead.keySet()) {
            JsonArray guardsReadArray = new JsonArray();
            guardsRead.get(key).forEach(guardsReadArray::add);
            readGuardsObject.add(key, guardsReadArray);
        }
        jsonObject.add("guardsRead", readGuardsObject);

        JsonObject operationReadsObject = new JsonObject();
        for(String key : operationsRead.keySet()) {
            JsonArray operationsReadsArray = new JsonArray();
            operationsRead.get(key).forEach(operationsReadsArray::add);
            operationReadsObject.add(key, operationsReadsArray);
        }
        jsonObject.add("operationsRead", operationReadsObject);

        JsonObject operationWriteObject = new JsonObject();
        for(String key : operationsWrite.keySet()) {
            JsonArray operationsWriteArray = new JsonArray();
            operationsWrite.get(key).forEach(operationsWriteArray::add);
            operationWriteObject.add(key, operationsWriteArray);
        }
        jsonObject.add("operationsWrite", operationWriteObject);

        return jsonObject;
    }
}
