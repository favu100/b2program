package de.hhu.stups.codegenerator.generators;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.visb.VisBEvent;
import de.hhu.stups.codegenerator.json.visb.VisBItem;
import de.hhu.stups.codegenerator.json.visb.VisBProject;
import de.prob.parser.ast.nodes.MachineNode;
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
    TemplateHandler.add(visualisation, "machineEvents", visBProject.getVisualisation().getVisBEvents().stream().map(visBEvent -> this.generateMachineEvent(visBEvent, visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0])).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "visualUpdates", visBProject.getVisualisation().getVisBItems().stream().map(this::generateVisualUpdate).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "enums", importGenerator.getImportedEnums());
    //Adding imports last to ensure all needed types are imported.
    TemplateHandler.add(visualisation, "imports", importGenerator.getImportedTypes().stream().map(this::generateVisualisationImport).collect(Collectors.toSet()));

    return visualisation.render();
  }

  public String generateVisualUpdate(VisBItem item) {
    ST visualUpdate = visualisationGroup.getInstanceOf("visualUpdate");
    TemplateHandler.add(visualUpdate, "machineVar", item.getId());
    TemplateHandler.add(visualUpdate, "attribute", item.getAttribute());
    TemplateHandler.add(visualUpdate, "expression", expressionGenerator.visitExprNode(item.getExprNode()).replaceAll("this.([a-zA-Z]+)", "_machine")+ ".getValue()");

    return visualUpdate.render();
  }

  public String generateMachineEvent(VisBEvent event, String svgName) {
    ST eventTemplate = visualisationGroup.getInstanceOf("event");
    TemplateHandler.add(eventTemplate, "machineEvent", event.getEvent());
    TemplateHandler.add(eventTemplate, "machineEventId", event.getId());
    TemplateHandler.add(eventTemplate, "svgName", svgName);
    return eventTemplate.render();
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
