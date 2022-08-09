package de.hhu.stups.codegenerator.server;

import de.hhu.stups.codegenerator.generators.MachineGenerator;
import de.hhu.stups.codegenerator.handlers.TemplateHandler;
import org.stringtemplate.v4.ST;
import org.stringtemplate.v4.STGroup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ServerLinkCompatibility {

    private static final List<String> bTypes;

    private static final Map<String, String> bTypesReplacementMap;

    static {
        bTypes = Arrays.asList("./btypes/BInteger.js", "./btypes/BBoolean.js", "./btypes/BObject.js",
                "./btypes/BRelation.js", "./btypes/BSet.js", "./btypes/BString.js", "./btypes/BStruct.js",
                "./btypes/BTuple.js", "./btypes/BTuple.js");
        bTypesReplacementMap = new HashMap<>();
        bTypesReplacementMap.put("./BInteger.js", "/btypes/BInteger.js");
        bTypesReplacementMap.put("./BBoolean.js", "/btypes/BBoolean.js");
        bTypesReplacementMap.put("./BObject.js", "/btypes/BObject.js");
        bTypesReplacementMap.put("./BRelation.js", "/btypes/BRelation.js");
        bTypesReplacementMap.put("./BSet.js", "/btypes/BSet.js");
        bTypesReplacementMap.put("./BString.js", "/btypes/BString.js");
        bTypesReplacementMap.put("./BStruct.js", "/btypes/BStruct.js");
        bTypesReplacementMap.put("./BTuple.js", "/btypes/BTuple.js");
        bTypesReplacementMap.put("./BUtils.js", "/btypes/BUtils.js");
        bTypesReplacementMap.put("../immutable/dist/immutable.es.js", "/immutable/dist/immutable.es.js");
    }

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
        TemplateHandler.add(template, "replacements", null);
        return template.render();
    }

    public String generateCompatibilitySingle() {
        ST template = compatibilityGroup.getInstanceOf("html_compatibility_single");
        TemplateHandler.add(template, "file", null);
        TemplateHandler.add(template, "replacements", null);
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
