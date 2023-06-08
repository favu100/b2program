package de.hhu.stups.codegenerator.blackbox.traces;

import de.hhu.stups.codegenerator.CodeGeneratorUtils;
import de.hhu.stups.codegenerator.GeneratorMode;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

/*
* This class generates a trace generator for a reinforcement learning agent
*/
public class TraceGenerator {

    private final String name;

    private final String modelPath;

    private final String learningTechnique;

    private final int episodes;

    private final STGroup group;

    private List<String> operationNames;

    private List<String> variables;

    public TraceGenerator(final String name, final String modelPath, final String learningTechnique, final int episodes) {
        this.group = CodeGeneratorUtils.getGroup(GeneratorMode.RL);
        this.name = name;
        this.modelPath = modelPath;
        this.learningTechnique = learningTechnique;
        this.episodes = episodes;
    }

    public String generate(MachineNode machineNode) {
        this.operationNames = machineNode.getOperations().stream().map(OperationNode::getName).collect(Collectors.toList());
        this.variables = machineNode.getVariables().stream().map(DeclarationNode::getName).collect(Collectors.toList());

        ST template = group.getInstanceOf("trace_generator");
        TemplateHandler.add(template, "name", name);
        TemplateHandler.add(template, "modelPath", modelPath);
        TemplateHandler.add(template, "learningTechnique", learningTechnique);
        TemplateHandler.add(template, "episodes", episodes);
        TemplateHandler.add(template, "hasSetupConstants", machineNode.getProperties() != null);
        TemplateHandler.add(template, "actionMapping", IntStream.range(0, operationNames.size())
                .mapToObj(this::generateActionMap)
                .collect(Collectors.toList()));
        TemplateHandler.add(template, "setup", generateTransitionAppend(true, false));
        TemplateHandler.add(template, "initialization", generateTransitionAppend(false, true));
        TemplateHandler.add(template, "action", generateTransitionAppend(false, false));
        TemplateHandler.add(template, "getters", variables.stream()
                .map(this::generateVariableGetter)
                .collect(Collectors.toList()));

        return template.render();
    }

    private String generateTransitionAppend(boolean isSetupConstants, boolean isInitialisation) {
        ST template = group.getInstanceOf("transition_append");
        TemplateHandler.add(template, "isSetupConstants", isSetupConstants);
        TemplateHandler.add(template, "isInitialisation", isInitialisation);
        TemplateHandler.add(template, "variables", generateState());
        return template.render();
    }

    private String generateState() {
        ST template = group.getInstanceOf("state");
        TemplateHandler.add(template, "state", variables.stream()
                .map(this::generateVariableMap)
                .collect(Collectors.toList()));
        return template.render();
    }

    private String generateVariableGetter(String variable) {
        ST template = group.getInstanceOf("variable_getter");
        TemplateHandler.add(template, "variable", variable);
        return template.render();
    }

    private String generateVariableMap(String variable) {
        ST template = group.getInstanceOf("variable_map");
        TemplateHandler.add(template, "variable", variable);
        return template.render();
    }

    private String generateActionMap(int id) {
        ST template = group.getInstanceOf("action_map");
        TemplateHandler.add(template, "id", id);
        return template.render();
    }

}
