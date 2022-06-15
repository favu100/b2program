package de.hhu.stups.codegenerator.json.simb;

import com.google.gson.Gson;
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
import java.io.FileWriter;
import java.io.IOException;
import java.util.Map;

import static de.prob.parser.antlr.Antlr4BParser.parseExpression;

public class SimulationRewriter {

    private static final JSONASTBuilder jsonASTBuilder = new JSONASTBuilder();

    public static void rewriteConfigurationFromJSON(File inputFile, File outputFile) throws IOException, JsonSyntaxException {
        Gson gson = new Gson();
        JsonReader reader = new JsonReader(new FileReader(inputFile));
        JsonObject simulationFile = gson.fromJson(reader, JsonObject.class);
        FileWriter writer = new FileWriter(outputFile);
        writer.write(simulationFile.toString());
        rewriteActivationConfigurations(simulationFile.get("activations"));
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
        JsonObject activationAsObject = activationElement.getAsJsonObject();

        if (activationAsObject.get("additionalGuards") != null && !activationAsObject.get("additionalGuards").isJsonNull()) {
            Map<String, Object> additionalGuards = jsonASTBuilder.visitExpression(createExpressionNode(activationAsObject.get("additionalGuards").getAsString()));
            activationAsObject.addProperty("additionalGuards", additionalGuards.toString());
        }
        rewriteParameters(activationAsObject.get("fixedVariables"));
        rewriteProbability(activationAsObject.get("probabilisticVariables"));
    }

    private static void rewriteActivationConfiguration(JsonElement activationElement) {
        if(activationElement.getAsJsonObject().has("execute")) {
            rewriteOperationConfiguration(activationElement);
        }
    }

    private static void rewriteParameters(JsonElement jsonElement) {
        if(jsonElement != null && !jsonElement.isJsonNull()) {
            JsonObject parametersAsObject = jsonElement.getAsJsonObject();
            for (String parameter : parametersAsObject.keySet()) {
                Map<String, Object> parameterValue = jsonASTBuilder.visitExpression(createExpressionNode(parametersAsObject.get(parameter).getAsString()));
                parametersAsObject.addProperty(parameter, parameterValue.toString());
            }
        }
    }

    private static void rewriteProbability(JsonElement jsonElement) {
        if(jsonElement != null && !jsonElement.isJsonNull() && !jsonElement.isJsonPrimitive()) {
            JsonObject probabilityObject = jsonElement.getAsJsonObject();
            JsonObject probabilityVariableObject = probabilityObject.getAsJsonObject();
            for (String variable : probabilityVariableObject.keySet()) {
                JsonObject probabilityValueObject = probabilityVariableObject.get(variable).getAsJsonObject();
                for (String parameter : probabilityValueObject.keySet()) {
                    Map<String, Object> parameterValue = jsonASTBuilder.visitExpression(createExpressionNode(probabilityValueObject.get(parameter).getAsString()));
                    probabilityValueObject.addProperty(parameter, parameterValue.toString());
                }
            }
        }
    }

}
