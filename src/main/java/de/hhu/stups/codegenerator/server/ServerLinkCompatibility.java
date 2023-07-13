package de.hhu.stups.codegenerator.server;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import de.prob.parser.antlr.BProject;
import de.prob.parser.ast.nodes.MachineNode;
import de.prob.parser.ast.nodes.MachineReferenceNode;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ServerLinkCompatibility {

    private final BProject project;

    private final STGroup compatibilityGroup;

    private final MachineGenerator machineGenerator;

    public ServerLinkCompatibility(final BProject project, final STGroup compatibilityGroup, final MachineGenerator machineGenerator) {
        this.project = project;
        this.compatibilityGroup = compatibilityGroup;
        this.machineGenerator = machineGenerator;
    }

    public String generateFile() {
        if(machineGenerator.getServerLink() == null || machineGenerator.getServerLink().isEmpty()) {
            return "";
        }
        ST template = compatibilityGroup.getInstanceOf("html_compatibility");

        List<String> replacements = new ArrayList<>();
        replacements.addAll(generateBTypeReplacements());
        replacements.addAll(generateMachineReplacements());
        TemplateHandler.add(template, "replacements", replacements);
        return template.render();
    }

    private List<String> generateBTypeReplacements() {
        List<String> result = new ArrayList<>();
        String[] bTypes = compatibilityGroup.getInstanceOf("btypes_paths").render().split("\n");
        for(String bType : bTypes) {
            result.add(generateCompatibilitySingle(bType, Collections.singletonList(generateBTypeReplacement(true))));
        }
        return result;
    }

    private List<String> generateMachineReplacements() {
        List<String> result = new ArrayList<>();
        for(MachineNode machineNode : project.getMachines()) {
            String machineFile = "./" + machineGenerator.getNameHandler().handle(machineNode.getName()) + ".js";
            List<String> replacements = new ArrayList<>();
            replacements.add(generateBTypeReplacement(false));
            for(MachineReferenceNode reference : machineNode.getMachineReferences()) {
                replacements.add(generateMachineReplacement(machineGenerator.getNameHandler().handle(reference.getMachineName()) + ".js"));
            }
            result.add(generateCompatibilitySingle(machineFile, replacements));
        }
        if(machineGenerator.isForVisualisation()) {
            String machineFile = "./" + machineGenerator.getNameHandler().handle(project.getMainMachine().getName()) + "-visualisation.js";
            List<String> replacements = new ArrayList<>();
            replacements.add(generateBTypeReplacement(false));
            for(MachineNode machine : project.getMachines()) {
                replacements.add(generateMachineReplacement(machineGenerator.getNameHandler().handle(machine.getName()) + ".js"));
            }
            result.add(generateCompatibilitySingle(machineFile, replacements));

            String htmlFile = "./" + machineGenerator.getNameHandler().handle(project.getMainMachine().getName()) + ".html";
            List<String> htmlReplacements = new ArrayList<>();
            htmlReplacements.add(generateBTypeReplacement(false));
            for(MachineNode machine : project.getMachines()) {
                htmlReplacements.add(generateMachineReplacement(machineGenerator.getNameHandler().handle(machine.getName()) + ".js"));
                htmlReplacements.add(generateMachineReplacement(machineGenerator.getNameHandler().handle(machine.getName()) + "-visualisation.js"));
            }
            result.add(generateCompatibilitySingle(htmlFile, htmlReplacements));
        }
        return result;
    }

    private String generateBTypeReplacement(boolean inBType) {
        ST template = compatibilityGroup.getInstanceOf("replacements_btypes");
        TemplateHandler.add(template, "inBType", inBType);
        TemplateHandler.add(template, "serverLink", machineGenerator.getServerLink());
        return template.render();
    }

    public String generateCompatibilitySingle(String file, List<String> replacements) {
        ST template = compatibilityGroup.getInstanceOf("html_compatibility_single");
        TemplateHandler.add(template, "file", file);
        TemplateHandler.add(template, "replacements", replacements);
        return template.render();
    }

    public String generateMachineReplacement(String file) {
        ST template = compatibilityGroup.getInstanceOf("replacement");
        TemplateHandler.add(template, "serverLink", machineGenerator.getServerLink());
        TemplateHandler.add(template, "file", file);
        return template.render();
    }

}
