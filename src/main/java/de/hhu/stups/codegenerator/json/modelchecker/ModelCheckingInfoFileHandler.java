package de.hhu.stups.codegenerator.json.modelchecker;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonSyntaxException;
import com.google.gson.stream.JsonReader;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ModelCheckingInfoFileHandler {

    public static ModelCheckingInfo constructConfigurationFromJSON(File inputFile) throws IOException, JsonSyntaxException {
        Gson gson = new Gson();
        JsonReader reader = new JsonReader(new FileReader(inputFile));
        JsonObject modelCheckingInfoObject = gson.fromJson(reader, JsonObject.class);

        String machineName = modelCheckingInfoObject.get("machineName").getAsString();
        List<String> variables = new ArrayList<>();
        Map<String, String> transitionEvaluationFunctions = new HashMap<>();
        List<OperationFunctionInfo> operationFunctions = new ArrayList<>();

        JsonArray variablesArray = modelCheckingInfoObject.getAsJsonArray("variables");
        for(int i = 0; i < variablesArray.size(); i++) {
            variables.add(variablesArray.get(i).getAsString());
        }

        JsonObject transitionEvaluationFunctionsObject = modelCheckingInfoObject.getAsJsonObject("transitionEvaluationFunctions");
        for (String op : transitionEvaluationFunctionsObject.keySet()) {
            transitionEvaluationFunctions.put(op, transitionEvaluationFunctionsObject.get(op).getAsString());
        }

        JsonArray operationsArray = modelCheckingInfoObject.getAsJsonArray("operationFunctions");
        for(int i = 0; i < operationsArray.size(); i++) {
            JsonObject operationObject = operationsArray.get(i).getAsJsonObject();
            String operationName = operationObject.get("opName").getAsString();
            JsonArray parametersArray = operationObject.get("parameterTypes").getAsJsonArray();

            List<String> parameters = new ArrayList<>();
            for(int j = 0; j < parametersArray.size(); j++) {
                String parameterType = parametersArray.get(j).getAsString();
                parameters.add(parameterType);
            }

            operationFunctions.add(new OperationFunctionInfo(operationName, parameters));
        }

        List<String> invariants = new ArrayList<>();
        JsonArray invariantsArray = modelCheckingInfoObject.getAsJsonArray("invariants");
        for(int i = 0; i < invariantsArray.size(); i++) {
            invariants.add(invariantsArray.get(i).getAsString());
        }


        Map<String, List<String>> writeInformation = new HashMap<>();
        JsonObject writeInformationObject = modelCheckingInfoObject.getAsJsonObject("writeInformation");
        for(String writeKey : writeInformationObject.keySet()) {
            List<String> writes = new ArrayList<>();
            JsonArray writesArray = writeInformationObject.get(writeKey).getAsJsonArray();
            for(int i = 0; i < writesArray.size(); i++) {
                writes.add(writesArray.get(i).getAsString());
            }
            writeInformation.put(writeKey, writes);
        }

        Map<String, List<String>> invariantReads = new HashMap<>();
        JsonObject invariantReadsObject = modelCheckingInfoObject.getAsJsonObject("invariantReads");
        for(String readKey : invariantReadsObject.keySet()) {
            List<String> reads = new ArrayList<>();
            JsonArray readsArray = invariantReadsObject.get(readKey).getAsJsonArray();
            for(int i = 0; i < readsArray.size(); i++) {
                reads.add(readsArray.get(i).getAsString());
            }
            invariantReads.put(readKey, reads);
        }

        Map<String, List<String>> guardsReads = new HashMap<>();
        JsonObject guardsReadsObject = modelCheckingInfoObject.getAsJsonObject("guardsReads");
        for(String readKey : guardsReadsObject.keySet()) {
            List<String> reads = new ArrayList<>();
            JsonArray readsArray = guardsReadsObject.get(readKey).getAsJsonArray();
            for(int i = 0; i < readsArray.size(); i++) {
                reads.add(readsArray.get(i).getAsString());
            }
            guardsReads.put(readKey, reads);
        }

        return new ModelCheckingInfo(machineName, variables, transitionEvaluationFunctions,  operationFunctions, invariants,
                                    writeInformation, invariantReads, guardsReads);
    }

}
