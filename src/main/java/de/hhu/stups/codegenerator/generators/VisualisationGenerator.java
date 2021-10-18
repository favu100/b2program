package de.hhu.stups.codegenerator.generators;

import java.util.*;
import java.util.stream.Collectors;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.visb.VisBEvent;
import de.hhu.stups.codegenerator.json.visb.VisBItem;
import de.hhu.stups.codegenerator.json.visb.VisBProject;
import de.prob.parser.ast.nodes.*;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;
import org.stringtemplate.v4.STGroupFile;

/*
 * The code generator is implemented by using the visitor pattern
 */

public class VisualisationGenerator{
  private final ImportGenerator importGenerator;

  private final ExpressionGenerator expressionGenerator;

  private final STGroup htmlGroup;
  private final STGroup visualisationGroup;

  private final Set<String> generatedEvents = new HashSet<>();

  public VisualisationGenerator(ImportGenerator importGenerator, ExpressionGenerator expressionGenerator) {
    this.htmlGroup = new STGroupFile("de/hhu/stups/codegenerator/HTMLTemplate.stg");
    this.visualisationGroup = new STGroupFile("de/hhu/stups/codegenerator/VisualisationTemplate.stg");
    this.importGenerator = importGenerator;
    this.expressionGenerator = expressionGenerator;
  }

  /*
   * This function generates code for the whole machine with the given AST node.
   */
  public String generateVisualisation(VisBProject visBProject) {
    ST visualisation = visualisationGroup.getInstanceOf("visulisation");

    TemplateHandler.add(visualisation, "machineName", visBProject.getProject().getMainMachine().getName());
    TemplateHandler.add(visualisation, "svgName", visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0]);
    TemplateHandler.add(visualisation, "machineVars", visBProject.getVisualisation().getVisBItems().stream().map((VisBItem::getId)).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "machineEvents", visBProject.getVisualisation().getVisBEvents().stream().map(visBEvent -> this.generateMachineEvent(visBEvent, visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0], visBProject.getProject().getMainMachine().getOperations())).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "visualUpdates", visBProject.getVisualisation().getVisBItems().stream().map((VisBItem item) -> generateVisualUpdate(item, visBProject)).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "machineEnums", expressionGenerator.getNameHandler().getEnumTypes().keySet().stream().filter((String machineEnum) -> expressionGenerator.getNameHandler().getEnumToMachine().get(machineEnum).equals(visBProject.getProject().getMainMachine().getName())).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "importedEnums", importGenerator.getImportedEnums());
    TemplateHandler.add(visualisation, "includedMachines", generateIncludedMachines(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "variables", generateVariables(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "constants", generateConstants(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "sets", generateSets(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "invariant", generateInvariant(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "variableUpdates", generateVariableUpdates(visBProject.getProject().getMainMachine()));
    //Adding imports last to ensure all needed types are imported.
    TemplateHandler.add(visualisation, "imports", importGenerator.getImportedTypes().stream().map(this::generateVisualisationImport).collect(Collectors.toSet()));

    return visualisation.render();
  }

  private String generateInvariant(MachineNode mainMachine) {
    ST invariantTemplate = visualisationGroup.getInstanceOf("invariant");
    TemplateHandler.add(invariantTemplate, "machineName", mainMachine.getName());
    TemplateHandler.add(invariantTemplate, "invariantFormula", mainMachine.getInvariant().getSourceCodePosition().getText());
    return invariantTemplate.render();
  }

  private List<String> generateIncludedMachines(MachineNode mainMachine) {
    List<List<String>> includedMachines = new ArrayList<>();
    for (MachineReferenceNode included : mainMachine.getMachineReferences()) {
      List<List<String>> nestedIncludes = generateCurrentIncludedMachine(included.getMachineNode());
      nestedIncludes.forEach(includeList -> includeList.add(0, visualisationGroup.getInstanceOf("initialMachineVar").render()));
      includedMachines.addAll(nestedIncludes);
    }
    List<String> savedMachines = new ArrayList<>();
    includedMachines.forEach((List<String> includedList) -> {
      ST mapIncludedMachineName = visualisationGroup.getInstanceOf("mapIncludedMachineName");
      TemplateHandler.add(mapIncludedMachineName, "machineName", includedList.get(includedList.size()-1));
      String pathFromMain = includedList.stream().reduce((String accPath, String currentMachineNode) -> {
        ST generatedPath = visualisationGroup.getInstanceOf("getMachineFromMachine");
        TemplateHandler.add(generatedPath, "machine", accPath);
        TemplateHandler.add(generatedPath, "includedMachine", currentMachineNode);
        return generatedPath.render();
      }).get();
      TemplateHandler.add(mapIncludedMachineName, "pathFromMainMachine", pathFromMain);
      savedMachines.add(mapIncludedMachineName.render());
    });
    return savedMachines;
  }

  private List<List<String>> generateCurrentIncludedMachine(MachineNode includedMachine) {
    List<List<String>> includedMachines = new ArrayList<>();
    for (MachineReferenceNode included : includedMachine.getMachineReferences()) {
      List<List<String>> nestedIncludes = generateCurrentIncludedMachine(included.getMachineNode());
      nestedIncludes.forEach(includeList -> includeList.add(0, includedMachine.getName()));
      includedMachines.addAll(nestedIncludes);
    }
    List<String> includedMachinePath = new ArrayList<>();
    includedMachinePath.add(includedMachine.getName());
    includedMachines.add(0, includedMachinePath);
    return includedMachines;
  }

  private List<String> generateVariables(MachineNode machine) {
    List<String> ownVariables = machine.getVariables().stream().map(var -> generateVariable(var, machine)).collect(Collectors.toList());
    List<String> otherVariables = new ArrayList<>();

    for (MachineReferenceNode includedMachine : machine.getMachineReferences()) {
      List<String> strings = generateVariables(includedMachine.getMachineNode());
      otherVariables.addAll(strings);
    }
    ownVariables.addAll(otherVariables);
    return ownVariables;
  }

  private String generateVariable(DeclarationNode var, MachineNode machine) {
    ST variable = visualisationGroup.getInstanceOf("variable");
    TemplateHandler.add(variable, "var", var.getName());
    TemplateHandler.add(variable, "machineName", machine.getName());
    return variable.render();
  }

  private List<String> generateConstants(MachineNode machine) {
    List<String> ownConstants = machine.getConstants().stream().map(var -> generateConstant(var, machine)).collect(Collectors.toList());
    List<String> otherConstants = new ArrayList<>();

    for (MachineReferenceNode includedMachine : machine.getMachineReferences()) {
      List<String> strings = generateConstants(includedMachine.getMachineNode());
      otherConstants.addAll(strings);
    }
    ownConstants.addAll(otherConstants);
    return ownConstants;
  }

  private String generateConstant(DeclarationNode var, MachineNode machine) {
    ST constant = visualisationGroup.getInstanceOf("constant");
    TemplateHandler.add(constant, "var", var.getName());
    TemplateHandler.add(constant, "machineName", machine.getName());
    return constant.render();
  }

  private List<String> generateSets(MachineNode machine) {
    List<String> ownSets = machine.getEnumeratedSets().stream().map(var -> generateSet(var, machine)).collect(Collectors.toList());
    List<String> othherSets = new ArrayList<>();

    for (MachineReferenceNode includedMachine : machine.getMachineReferences()) {
      List<String> strings = generateSets(includedMachine.getMachineNode());
      othherSets.addAll(strings);
    }
    ownSets.addAll(othherSets);
    return ownSets;
  }

  private String generateSet(EnumeratedSetDeclarationNode var, MachineNode machine) {
    ST set = visualisationGroup.getInstanceOf("set");
    TemplateHandler.add(set, "var", var.getSetDeclarationNode().getName());
    TemplateHandler.add(set, "machineName", machine.getName());
    return set.render();
  }

  public String generateVisualUpdate(VisBItem item, VisBProject visBProject) {
    ST visualUpdate = visualisationGroup.getInstanceOf("visualUpdate");
    TemplateHandler.add(visualUpdate, "machineVar", item.getId());
    TemplateHandler.add(visualUpdate, "attribute", item.getAttribute());
    TemplateHandler.add(visualUpdate, "expression", expressionGenerator.visitExprNode(item.getExprNode()).replaceAll("this.", "_machine.").replaceAll("_machine." + visBProject.getProject().getMainMachine().getName() + ".", "_machine.")+ ".getValue()");

    return visualUpdate.render();
  }

  private List<String> generateVariableUpdates(MachineNode machine) {
    List<String> ownVariables = machine.getVariables().stream().map(var -> generateVariableUpdate(var, machine)).collect(Collectors.toList());
    List<String> otherVariables = new ArrayList<>();

    for (MachineReferenceNode includedMachine : machine.getMachineReferences()) {
      List<String> strings = generateVariableUpdates(includedMachine.getMachineNode());
      otherVariables.addAll(strings);
    }
    ownVariables.addAll(otherVariables);
    return ownVariables;
  }

  private String generateVariableUpdate(DeclarationNode var, MachineNode machine) {
    ST variable = visualisationGroup.getInstanceOf("variableUpdate");
    TemplateHandler.add(variable, "variable", var.getName());
    TemplateHandler.add(variable, "machineName", machine.getName());
    return variable.render();
  }

  public String generateEventParameter(DeclarationNode param, String eventName) {
    ST paramTemplate = visualisationGroup.getInstanceOf("parameter");

    BType type = param.getType();
    ST valueTemplate;
    if (type instanceof de.prob.parser.ast.types.BoolType) {
      valueTemplate = visualisationGroup.getInstanceOf("boolValue");

    } else if (type instanceof de.prob.parser.ast.types.IntegerType) {
      valueTemplate = visualisationGroup.getInstanceOf("intValue");
    } else if (type instanceof de.prob.parser.ast.types.EnumeratedSetElementType) {
      valueTemplate = visualisationGroup.getInstanceOf("enumValue");
      TemplateHandler.add(valueTemplate, "enum", ((EnumeratedSetElementType) type).getSetName());
    } else {
      throw new RuntimeException("Parameters of type " + type.toString() + " are not yet supported for visualisations.");
    }
    TemplateHandler.add(valueTemplate, "name", param.getName());
    TemplateHandler.add(paramTemplate, "getValueMethod", valueTemplate.render());
    TemplateHandler.add(paramTemplate, "name", param.getName());
    TemplateHandler.add(paramTemplate, "eventName", eventName);

    return paramTemplate.render();
  }

  public String generateMachineEvent(VisBEvent event, String svgName, List<OperationNode> operations) {
    Optional<OperationNode> operation = operations.stream().filter(operationNode -> operationNode.getName().equals(event.getEvent())).findFirst();
    if(!operation.isPresent()) {
      throw new RuntimeException("Operation " + event.getEvent() + " used in visualisation but not present in machine.");
    }
    List<DeclarationNode> params = operation.get().getParams();

    String result = "";
    if (!generatedEvents.contains(event.getEvent())) {
      ST eventTemplate = visualisationGroup.getInstanceOf("event");
      TemplateHandler.add(eventTemplate, "machineEvent", event.getEvent());
      TemplateHandler.add(eventTemplate, "svgName", svgName);
      TemplateHandler.add(eventTemplate, "parameterCreation", params.stream().map((DeclarationNode param) -> generateEventParameter(param, event.getEvent())).collect(Collectors.toList()));
      TemplateHandler.add(eventTemplate, "parameterNames", params.stream().map(DeclarationNode::getName).collect(Collectors.toList()));
      result += eventTemplate.render();
      generatedEvents.add(event.getEvent());
    }
    ST onclickEventTemplate = visualisationGroup.getInstanceOf("onclick_event");
    TemplateHandler.add(onclickEventTemplate, "machineEvent", event.getEvent());
    TemplateHandler.add(onclickEventTemplate, "machineEventId", event.getId());
    TemplateHandler.add(onclickEventTemplate, "svgName", svgName);
    TemplateHandler.add(onclickEventTemplate, "parameterNames", params.stream().map(DeclarationNode::getName).collect(Collectors.toList()));
    result += onclickEventTemplate.render();
    return result;
  }

  public String generateHTML(VisBProject visBProject) {
    ST html = htmlGroup.getInstanceOf("html");
    TemplateHandler.add(html, "machineName", visBProject.getProject().getMainMachine().getName());
    TemplateHandler.add(html, "svgName", visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0]);
    TemplateHandler.add(html, "btypeImports", importGenerator.getImportedTypes().stream().map(this::generateHTMLImport).collect(Collectors.toSet()));
    return html.render();
  }

  public String generateVisualisationImport(String type) {
    ST visualisationImport = visualisationGroup.getInstanceOf("btype_import");
    TemplateHandler.add(visualisationImport, "type", type);
    return visualisationImport.render();
  }

  public String generateHTMLImport(String type) {
    ST htmlImport = htmlGroup.getInstanceOf("btypeImport");
    TemplateHandler.add(htmlImport, "name", type);
    return htmlImport.render();
  }

}
