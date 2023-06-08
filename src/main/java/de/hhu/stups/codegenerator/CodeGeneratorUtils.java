package de.hhu.stups.codegenerator;

import org.stringtemplate.v4.STGroup;
import org.stringtemplate.v4.STGroupFile;
import org.stringtemplate.v4.StringRenderer;

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
    private static final STGroup RS_GROUP;
    private static final STGroup RL_GROUP;

    private static final Map<GeneratorMode, STGroup> TEMPLATE_MAP = new HashMap<>();

    static {
        JAVA_GROUP = new STGroupFile("de/hhu/stups/codegenerator/JavaTemplate.stg");
        C_GROUP = new STGroupFile("de/hhu/stups/codegenerator/CTemplate.stg");
        CPP_GROUP = new STGroupFile("de/hhu/stups/codegenerator/CppTemplate.stg");
        PYTHON_GROUP = new STGroupFile("de/hhu/stups/codegenerator/PythonTemplate.stg");
        CLJ_GROUP = new STGroupFile("de/hhu/stups/codegenerator/ClojureTemplate.stg");
        TS_GROUP = new STGroupFile("de/hhu/stups/codegenerator/TsTemplate.stg");
        PL_GROUP = new STGroupFile("de/hhu/stups/codegenerator/PrologTemplate.stg");
        RS_GROUP = new STGroupFile("de/hhu/stups/codegenerator/RustTemplate.stg");
        RS_GROUP.registerRenderer(String.class, new StringRenderer());
        RL_GROUP = new STGroupFile("de/hhu/stups/codegenerator/RLTemplate.stg");
        TEMPLATE_MAP.put(JAVA, JAVA_GROUP);
        TEMPLATE_MAP.put(C, C_GROUP);
        TEMPLATE_MAP.put(CPP, CPP_GROUP);
        TEMPLATE_MAP.put(PY, PYTHON_GROUP);
        TEMPLATE_MAP.put(CLJ, CLJ_GROUP);
        TEMPLATE_MAP.put(TS, TS_GROUP);
        TEMPLATE_MAP.put(PL, PL_GROUP);
        TEMPLATE_MAP.put(RS, RS_GROUP);
        TEMPLATE_MAP.put(RL, RL_GROUP);
    }

    public static STGroup getGroup(GeneratorMode mode) {
        return TEMPLATE_MAP.get(mode);
    }
}
