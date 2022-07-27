package de.hhu.stups.codegenerator.generators;

import java.util.*;
import java.util.stream.Collectors;

import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.hhu.stups.codegenerator.json.visb.VisBEvent;
import de.hhu.stups.codegenerator.json.visb.VisBItem;
import de.hhu.stups.codegenerator.json.visb.VisBProject;
import de.prob.parser.ast.nodes.*;
import de.prob.parser.ast.nodes.expression.IdentifierExprNode;
import de.prob.parser.ast.nodes.predicate.PredicateNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode;
import de.prob.parser.ast.nodes.predicate.PredicateOperatorWithExprArgsNode.PredOperatorExprArgs;
import de.prob.parser.ast.types.BType;
import de.prob.parser.ast.types.DeferredSetElementType;
import de.prob.parser.ast.types.EnumeratedSetElementType;
import de.prob.parser.ast.types.SetElementType;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;
import org.stringtemplate.v4.STGroupFile;

/*
 * The code generator is implemented by using the visitor pattern
 */

public class VisualisationGenerator{
  private final ImportGenerator importGenerator;
  private final ExpressionGenerator expressionGenerator;
  private final InvariantGenerator invariantGenerator;

  private final STGroup htmlGroup;
  private final STGroup visualisationGroup;

  public VisualisationGenerator(ImportGenerator importGenerator, ExpressionGenerator expressionGenerator, InvariantGenerator invariantGenerator) {
    this.htmlGroup = new STGroupFile("de/hhu/stups/codegenerator/HTMLTemplate.stg");
    this.visualisationGroup = new STGroupFile("de/hhu/stups/codegenerator/VisualisationTemplate.stg");
    this.importGenerator = importGenerator;
    this.expressionGenerator = expressionGenerator;
    this.invariantGenerator = invariantGenerator;
  }

  /*
   * This function generates code for the whole machine with the given AST node.
   */
  public String generateVisualisation(VisBProject visBProject) {
    ST visualisation = visualisationGroup.getInstanceOf("visualisation");
    boolean withoutSvg = visBProject.getVisualisation().getSvgPath() == null;
    TemplateHandler.add(visualisation, "machineName", visBProject.getProject().getMainMachine().getName());
    TemplateHandler.add(visualisation, "svgName", withoutSvg? false: visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0]);
    TemplateHandler.add(visualisation, "svgElements", visBProject.getVisualisation().getVisBItems().stream().map((VisBItem::getId)).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "events", visBProject.getProject().getMainMachine().getOperations().stream().map(machineEvent -> this.generateMachineEvent(machineEvent, withoutSvg? null: visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0], visBProject.getVisualisation().getVisBEvents())).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "visualUpdates", visBProject.getVisualisation().getVisBItems().stream().map((VisBItem item) -> generateVisualUpdate(item, visBProject)).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "machineEnums", expressionGenerator.getNameHandler().getEnumTypes().keySet().stream().filter((String machineEnum) -> expressionGenerator.getNameHandler().getEnumToMachine().get(machineEnum).equals(visBProject.getProject().getMainMachine().getName())).collect(Collectors.toSet()));
    TemplateHandler.add(visualisation, "importedEnums", importGenerator.getImportedEnums());
    TemplateHandler.add(visualisation, "includedMachines", generateIncludedMachines(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "variables", generateVariables(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "constants", generateConstants(visBProject.getProject().getMainMachine()));
    TemplateHandler.add(visualisation, "sets", generateSets(visBProject.getProject().getMainMachine()));
    List<String> invariantList = generateInvariant(visBProject.getProject().getMainMachine());
    TemplateHandler.add(visualisation, "invariant", invariantList);
    TemplateHandler.add(visualisation, "invariantCount", invariantList.size());
    TemplateHandler.add(visualisation, "variableUpdates", generateVariableUpdates(visBProject.getProject().getMainMachine()));
    //Adding imports last to ensure all needed types are imported.
    TemplateHandler.add(visualisation, "imports", importGenerator.getImportedTypes().stream().map(this::generateVisualisationImport).collect(Collectors.toSet()));

    return visualisation.render();
  }

  private List<String> generateInvariant(MachineNode mainMachine) {
    List<PredicateNode> invariants = invariantGenerator.splitInvariant(mainMachine.getInvariant());
    List<String> invariantList = new ArrayList<>();
    int invariantCounter = 1;

    for (PredicateNode invariant: invariants) {
      String functionName = "_check_inv_" + invariantCounter;
      ST invariantTemplate = visualisationGroup.getInstanceOf("invariant");
      TemplateHandler.add(invariantTemplate, "invariantFunction", functionName);
      TemplateHandler.add(invariantTemplate, "machineName", mainMachine.getName());
      TemplateHandler.add(invariantTemplate, "invariantFormula", invariant.getSourceCodePosition().getText());
      invariantList.add(invariantTemplate.render());
      invariantCounter++;
    }

    return invariantList;
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
    TemplateHandler.add(visualUpdate, "expression", expressionGenerator.visitExprNode(item.getExprNode()).replaceAll("BRelation<.*>", "BRelation").replaceAll("this.", "_machine.").replaceAll("_machine." + visBProject.getProject().getMainMachine().getName() + ".", "_machine.")+ ".getValue()");

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
    } else if (type instanceof DeferredSetElementType) {
      valueTemplate = visualisationGroup.getInstanceOf("enumValue");
      TemplateHandler.add(valueTemplate, "enum", ((DeferredSetElementType) type).getSetName());
    } else {
      throw new RuntimeException("Parameters of type " + type.toString() + " are not yet supported for visualisations.");
    }
    TemplateHandler.add(valueTemplate, "name", param.getName());
    TemplateHandler.add(paramTemplate, "getValueMethod", valueTemplate.render());
    TemplateHandler.add(paramTemplate, "name", param.getName());
    TemplateHandler.add(paramTemplate, "eventName", eventName);

    return paramTemplate.render();
  }

  public String generateMachineEvent(OperationNode operation, String svgName, List<VisBEvent> events) {
    List<DeclarationNode> params = operation.getParams();

    //Generate onclicks for VisB-Events
    List<VisBEvent> eventsWithOperation = events.stream().filter(event -> event.getEvent().equals(operation.getName())).collect(Collectors.toList());
    List<String> svgEvents = new ArrayList<>();
    for (VisBEvent event : eventsWithOperation) {
      ST onclickEventTemplate = visualisationGroup.getInstanceOf("svg_event");
      TemplateHandler.add(onclickEventTemplate, "machineEvent", event.getEvent());
      TemplateHandler.add(onclickEventTemplate, "machineEventId", event.getId());
      TemplateHandler.add(onclickEventTemplate, "svgName", svgName);
      TemplateHandler.add(onclickEventTemplate, "parameterMap", generateParameterMap(event.getPredicateNodes()));
      TemplateHandler.add(onclickEventTemplate, "parameterNames", params.stream().map(DeclarationNode::getName).collect(Collectors.toList()));
      svgEvents.add(onclickEventTemplate.render());
    }

    //Generate the machine Event
    ST eventTemplate = visualisationGroup.getInstanceOf("event");
    TemplateHandler.add(eventTemplate, "machineEvent", operation.getName());
    TemplateHandler.add(eventTemplate, "svgName", svgName);
    TemplateHandler.add(eventTemplate, "parameterCreation", params.stream().map(param -> generateEventParameter(param, operation.getName())).collect(Collectors.toList()));
    TemplateHandler.add(eventTemplate, "parameterNames", params.stream().map(DeclarationNode::getName).collect(Collectors.toList()));
    TemplateHandler.add(eventTemplate, "svgEvents", svgEvents);

    return eventTemplate.render();
  }

  private String generateParameterMap(List<PredicateNode> parameters) {
    List<String> parameterList = new ArrayList<>();
    parameters.forEach(parameter -> {
      if(! (parameter instanceof PredicateOperatorWithExprArgsNode)
      || ! ((PredicateOperatorWithExprArgsNode) parameter).getOperator().equals(PredOperatorExprArgs.EQUAL)
      || ((PredicateOperatorWithExprArgsNode) parameter).getExpressionNodes().size() != 2
      || ! (((PredicateOperatorWithExprArgsNode) parameter).getExpressionNodes().get(0) instanceof IdentifierExprNode)) {
        throw new CodeGenerationException("Predicates for Parameters must be an assignment for a single parameter.");
      }
      PredicateOperatorWithExprArgsNode param = (PredicateOperatorWithExprArgsNode) parameter;

      ST parameterTemplate = visualisationGroup.getInstanceOf("parameterMapPredicate");
      TemplateHandler.add(parameterTemplate, "name", ((IdentifierExprNode) param.getExpressionNodes().get(0)).getName());
      TemplateHandler.add(parameterTemplate, "predicate", expressionGenerator.visitExprNode(param.getExpressionNodes().get(1)));
      parameterList.add(parameterTemplate.render());
    });
    ST parameterMap = visualisationGroup.getInstanceOf("parameterMap");
    TemplateHandler.add(parameterMap, "parameters", parameterList);
    return parameterMap.render();
  }

  public String generateHTML(VisBProject visBProject) {
    ST html = htmlGroup.getInstanceOf("html");
    TemplateHandler.add(html, "machineName", visBProject.getProject().getMainMachine().getName());
    TemplateHandler.add(html, "svgName", visBProject.getVisualisation().getSvgPath() == null? false: visBProject.getVisualisation().getSvgPath().getFileName().toString().split("\\.")[0]);
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
