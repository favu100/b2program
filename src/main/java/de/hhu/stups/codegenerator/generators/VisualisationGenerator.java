package de.hhu.stups.codegenerator.generators;

import java.util.*;
import java.util.stream.Collectors;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.visb.VisBEvent;
import de.hhu.stups.codegenerator.json.visb.VisBItem;
import de.hhu.stups.codegenerator.json.visb.VisBProject;
import de.prob.parser.ast.nodes.DeclarationNode;
import de.prob.parser.ast.nodes.OperationNode;
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
    //Adding imports last to ensure all needed types are imported.
    TemplateHandler.add(visualisation, "imports", importGenerator.getImportedTypes().stream().map(this::generateVisualisationImport).collect(Collectors.toSet()));

    return visualisation.render();
  }

  public String generateVisualUpdate(VisBItem item, VisBProject visBProject) {
    ST visualUpdate = visualisationGroup.getInstanceOf("visualUpdate");
    TemplateHandler.add(visualUpdate, "machineVar", item.getId());
    TemplateHandler.add(visualUpdate, "attribute", item.getAttribute());
    TemplateHandler.add(visualUpdate, "expression", expressionGenerator.visitExprNode(item.getExprNode()).replaceAll("this.", "_machine.").replaceAll("_machine." + visBProject.getProject().getMainMachine().getName() + ".", "_machine.")+ ".getValue()");

    return visualUpdate.render();
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
