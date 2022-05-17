package de.hhu.stups.codegenerator;

import org.stringtemplate.v4.STGroup;
import org.stringtemplate.v4.STGroupFile;

import java.util.HashMap;
import java.util.Map;

import static de.hhu.stups.codegenerator.GeneratorMode.*;

/**
 * Created by fabian on 21.10.18.
 */
public class CodeGeneratorUtils {

    /*
    * Template groups for the supported programming languages
    */
    private static final STGroup JAVA_GROUP;
    private static final STGroup C_GROUP;
    private static final STGroup CPP_GROUP;
    private static final STGroup PYTHON_GROUP;
    private static final STGroup CLJ_GROUP;
    private static final STGroup TS_GROUP;
    private static final STGroup PL_GROUP;

    private static final Map<GeneratorMode, STGroup> TEMPLATE_MAP = new HashMap<>();

    static {
        JAVA_GROUP = new STGroupFile("de/hhu/stups/codegenerator/JavaTemplate.stg");
        C_GROUP = new STGroupFile("de/hhu/stups/codegenerator/CTemplate.stg");
        CPP_GROUP = new STGroupFile("de/hhu/stups/codegenerator/CppTemplate.stg");
        PYTHON_GROUP = new STGroupFile("de/hhu/stups/codegenerator/PythonTemplate.stg");
        CLJ_GROUP = new STGroupFile("de/hhu/stups/codegenerator/ClojureTemplate.stg");
        TS_GROUP = new STGroupFile("de/hhu/stups/codegenerator/TsTemplate.stg");
        PL_GROUP = new STGroupFile("de/hhu/stups/codegenerator/PrologTemplate.stg");
        TEMPLATE_MAP.put(JAVA, JAVA_GROUP);
        TEMPLATE_MAP.put(C, C_GROUP);
        TEMPLATE_MAP.put(CPP, CPP_GROUP);
        TEMPLATE_MAP.put(PY, PYTHON_GROUP);
        TEMPLATE_MAP.put(CLJ, CLJ_GROUP);
        TEMPLATE_MAP.put(TS, TS_GROUP);
        TEMPLATE_MAP.put(PL, PL_GROUP);
    }

    public static STGroup getGroup(GeneratorMode mode) {
        return TEMPLATE_MAP.get(mode);
    }
}
