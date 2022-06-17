package de.hhu.stups.codegenerator.json.simb;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonSyntaxException;
import com.google.gson.stream.JsonReader;
import de.hhu.stups.codegenerator.json.JSONASTBuilder;
import de.prob.parser.antlr.MachineASTCreator;
import de.prob.parser.ast.nodes.expression.ExprNode;
import files.BParser;
import org.antlr.v4.runtime.CharStreams;
import org.antlr.v4.runtime.CodePointCharStream;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Map;

import static de.prob.parser.antlr.Antlr4BParser.parseExpression;
import static java.nio.file.StandardOpenOption.TRUNCATE_EXISTING;

public class SimulationRewriter {

    private static final JSONASTBuilder jsonASTBuilder = new JSONASTBuilder();

    public static void rewriteConfigurationFromJSON(File inputFile, File outputFile) throws IOException, JsonSyntaxException {
        Gson gson = new Gson();
        JsonReader reader = new JsonReader(new FileReader(inputFile));
        JsonObject simulationFile = gson.fromJson(reader, JsonObject.class);

        //BufferedWriter writer = Files.newBufferedWriter(Paths.get(outputFile.getAbsolutePath()), StandardCharsets.UTF_8);
        rewriteActivationConfigurations(simulationFile.get("activations"));
        GsonBuilder gsonBuilder = new GsonBuilder();
        Files.write(Paths.get(outputFile.getPath()), gsonBuilder.setPrettyPrinting().create().toJson(simulationFile).getBytes(), TRUNCATE_EXISTING);
    }

    private static void rewriteActivationConfigurations(JsonElement jsonElement) {
        JsonArray activationConfigurationsAsArray = jsonElement.getAsJsonArray();
        for (JsonElement activationElement : activationConfigurationsAsArray) {
            rewriteActivationConfiguration(activationElement);
        }
    }

    private static ExprNode createExpressionNode(String expression) {
        CodePointCharStream stream = CharStreams.fromString(expression);
        BParser.ExpressionContext expressionContext = parseExpression(stream);
        return MachineASTCreator.createExpressionAST(expressionContext);
    }

    private static void rewriteOperationConfiguration(JsonElement activationElement) {
        Gson gson = new Gson();
        JsonObject activationAsObject = activationElement.getAsJsonObject();

        if (activationAsObject.get("additionalGuards") != null && !activationAsObject.get("additionalGuards").isJsonNull()) {
            Map<String, Object> additionalGuards = jsonASTBuilder.visitExpression(createExpressionNode(activationAsObject.get("additionalGuards").getAsString()));
            activationAsObject.add("additionalGuards", gson.toJsonTree(additionalGuards));
        }
        rewriteParameters(activationAsObject.get("fixedVariables"));
        rewriteProbability(activationAsObject.get("probabilisticVariables"));
    }

    private static void rewriteChoiceActivationConfiguration(JsonElement activationElement) {
        Gson gson = new Gson();
        JsonObject activationAsObject = activationElement.getAsJsonObject();
        JsonObject map = activationAsObject.get("chooseActivation").getAsJsonObject();
        for(String key : map.keySet()) {
            Map<String, Object> probability = jsonASTBuilder.visitExpression(createExpressionNode(map.get(key).getAsString()));
            map.add(key, gson.toJsonTree(probability));
        }
    }

    private static void rewriteActivationConfiguration(JsonElement activationElement) {
        if(activationElement.getAsJsonObject().has("execute")) {
            rewriteOperationConfiguration(activationElement);
        } else if(activationElement.getAsJsonObject().has("chooseActivation")) {
            rewriteChoiceActivationConfiguration(activationElement);
        }
    }

    private static void rewriteParameters(JsonElement jsonElement) {
        Gson gson = new Gson();
        if(jsonElement != null && !jsonElement.isJsonNull()) {
            JsonObject parametersAsObject = jsonElement.getAsJsonObject();
            for (String parameter : parametersAsObject.keySet()) {
                Map<String, Object> parameterValue = jsonASTBuilder.visitExpression(createExpressionNode(parametersAsObject.get(parameter).getAsString()));
                parametersAsObject.add(parameter, gson.toJsonTree(parameterValue));
            }
        }
    }

    private static void rewriteProbability(JsonElement jsonElement) {
        Gson gson = new Gson();
        if(jsonElement != null && !jsonElement.isJsonNull() && !jsonElement.isJsonPrimitive()) {
            JsonObject probabilityObject = jsonElement.getAsJsonObject();
            JsonObject probabilityVariableObject = probabilityObject.getAsJsonObject();
            for (String variable : probabilityVariableObject.keySet()) {
                JsonObject probabilityValueObject = probabilityVariableObject.get(variable).getAsJsonObject();
                for (String parameter : probabilityValueObject.keySet()) {
                    Map<String, Object> parameterValue = jsonASTBuilder.visitExpression(createExpressionNode(probabilityValueObject.get(parameter).getAsString()));
                    probabilityValueObject.add(parameter, gson.toJsonTree(parameterValue));
                }
            }
        }
    }

}
