package de.hhu.stups.codegenerator.generators;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.OperationNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class BacktrackingGenerator {

    private final STGroup currentGroup;

    private final Set<String> nondeterministicOperations;

    private final List<String> choicePointDeclarations;

    private final List<String> choicePointGetters;

    private final List<String> choicePointOperationFlagDeclarations;

    private final List<String> choicePointOperationFlagGetters;

    private final List<String> choicePointOperationFlagResets;

    private final List<String> choicePointOperationApplies;

    private final List<String> choicePointOperationTriggeredFlags;

    private final List<String> choicePointOperationTriggered;

    private final List<String> choicePointOperationTriggeredResets;

    private final Map<String, BacktrackingVisitor> backtrackingVisitorMap;

    public BacktrackingGenerator(final STGroup currentGroup) {
        this.currentGroup = currentGroup;
        this.nondeterministicOperations = new HashSet<>();
        this.backtrackingVisitorMap = new HashMap<>();
        this.choicePointDeclarations = new ArrayList<>();
        this.choicePointGetters = new ArrayList<>();
        this.choicePointOperationFlagDeclarations = new ArrayList<>();
        this.choicePointOperationFlagGetters = new ArrayList<>();
        this.choicePointOperationFlagResets = new ArrayList<>();
        this.choicePointOperationApplies = new ArrayList<>();
        this.choicePointOperationTriggeredFlags = new ArrayList<>();
        this.choicePointOperationTriggered = new ArrayList<>();
        this.choicePointOperationTriggeredResets = new ArrayList<>();
    }

    public void calculateChoicePoints(MachineNode machineNode) {
        for(OperationNode operation : machineNode.getOperations()) {
            String opName = operation.getName();
            BacktrackingVisitor visitor = new BacktrackingVisitor(opName);
            backtrackingVisitorMap.put(opName, visitor);

            visitor.visitSubstitutionNode(operation.getSubstitution(), null);

            if(visitor.getChoicePointCounter() > 0) {
                nondeterministicOperations.add(opName);
                for(int i = 1; i <= visitor.getChoicePointCounter(); i++) {
                    choicePointDeclarations.add(this.generateChoicePointVariable(opName, i));
                    choicePointGetters.add(this.generateChoicePointGetter(opName, i));
                }
                choicePointOperationFlagDeclarations.add(this.generateChoicePointOperationFlag(opName));
                choicePointOperationFlagGetters.add(this.generateChoicePointOperationGetter(opName));
                choicePointOperationFlagResets.add(this.generateChoicePointOperationReset(opName));
                choicePointOperationApplies.add(this.generateChoicePointOperationApply(machineNode.getName(), opName));
                choicePointOperationTriggeredFlags.add(this.generateChoicePointOperationTriggeredDeclaration(opName));
                choicePointOperationTriggered.add(this.generateChoicePointOperationTriggered(opName));
                choicePointOperationTriggeredResets.add(this.generateChoiceOperationTriggeredReset(opName));
            }
        }
    }

    public String generateChoicePointVariable(String operation, int id) {
        ST template = currentGroup.getInstanceOf("choice_point_declaration");
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "choicePoint", id);
        return template.render();
    }

    public String generateChoicePointGetter(String operation, int id) {
        ST template = currentGroup.getInstanceOf("choice_point_getter");
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "choicePoint", id);
        return template.render();
    }

    public String generateChoicePointOperationFlag(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_flag_declaration");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoicePointOperationGetter(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_flag_getter");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoicePointOperationReset(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_flag_reset");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoicePointOperationApply(String machine, String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_apply");
        TemplateHandler.add(template, "machine", machine);
        TemplateHandler.add(template, "operation", operation);
        BacktrackingVisitor visitor = backtrackingVisitorMap.get(operation);
        List<String> applyChoicePoints = new ArrayList<>();
        for(int i = 1; i <= visitor.getChoicePointCounter(); i++) {
            applyChoicePoints.add(generateChoicePointOperationApplyChoicePoint(operation, i));
        }
        TemplateHandler.add(template, "applyChoicePoints", applyChoicePoints);
        TemplateHandler.add(template, "applyChoicePointFlag", generateChoicePointOperationApplyChoicePointFlag(operation));
        return template.render();
    }

    public String generateChoicePointOperationApplyChoicePoint(String operation, int choicePoint) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_apply_choice_point");
        TemplateHandler.add(template, "operation", operation);
        TemplateHandler.add(template, "choicePoint", choicePoint);
        return template.render();
    }

    public String generateChoicePointOperationApplyChoicePointFlag(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_apply_choice_point_flag");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoicePointOperationTriggeredDeclaration(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_triggered_declaration");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoicePointOperationTriggered(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_triggered");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public String generateChoiceOperationTriggeredReset(String operation) {
        ST template = currentGroup.getInstanceOf("choice_point_operation_triggered_reset");
        TemplateHandler.add(template, "operation", operation);
        return template.render();
    }

    public List<String> getChoicePointDeclarations() {
        return choicePointDeclarations;
    }

    public List<String> getChoicePointGetters() {
        return choicePointGetters;
    }

    public List<String> getChoicePointOperationFlagDeclarations() {
        return choicePointOperationFlagDeclarations;
    }

    public List<String> getChoicePointOperationFlagGetters() {
        return choicePointOperationFlagGetters;
    }

    public List<String> getChoicePointOperationFlagResets() {
        return choicePointOperationFlagResets;
    }

    public List<String> getChoicePointOperationApplies() {
        return choicePointOperationApplies;
    }

    public List<String> getChoicePointOperationTriggeredFlags() {
        return choicePointOperationTriggeredFlags;
    }

    public List<String> getChoicePointOperationTriggered() {
        return choicePointOperationTriggered;
    }

    public List<String> getChoicePointOperationTriggeredResets() {
        return choicePointOperationTriggeredResets;
    }

    public Set<String> getNondeterministicOperations() {
        return nondeterministicOperations;
    }

    public Map<String, BacktrackingVisitor> getBacktrackingVisitorMap() {
        return backtrackingVisitorMap;
    }

    public boolean isNondeterministic(String operation) {
        return nondeterministicOperations.contains(operation);
    }
}
