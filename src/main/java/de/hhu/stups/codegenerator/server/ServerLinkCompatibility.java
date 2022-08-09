package de.hhu.stups.codegenerator.server;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ServerLinkCompatibility {

    private final STGroup compatibilityGroup;

    private final MachineGenerator machineGenerator;

    public ServerLinkCompatibility(final STGroup compatibilityGroup, final MachineGenerator machineGenerator) {
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

    public List<String> generateReplacements() {
        List<String> result = new ArrayList<>();
        ST template = compatibilityGroup.getInstanceOf("replacement");
        TemplateHandler.add(template, "serverLink", machineGenerator.getServerLink());
        TemplateHandler.add(template, "path", null);
        TemplateHandler.add(template, "file", null);
        return result;
    }

}
