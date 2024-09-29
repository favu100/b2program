package de.hhu.stups.codegenerator.python;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestSetComprehension extends TestPython {

    @Test
    public void testSetComprehensionInteger() throws Exception {
        testPython("set_comprehension/SetComprehensionInteger", "SetComprehensionInteger", "SetComprehensionIntegerAddition.stpy", true);
    }

    @Test
    public void testSetComprehensionInteger2() throws Exception {
        testPython("set_comprehension/SetComprehensionInteger2", "SetComprehensionInteger2", "SetComprehensionInteger2Addition.stpy", true);
    }

    @Test
    public void testSetComprehensionInteger3() throws Exception {
        testPython("set_comprehension/SetComprehensionInteger3", "SetComprehensionInteger3", "SetComprehensionInteger3Addition.stpy", true);
    }

    @Test
    public void testSetComprehensionBool() throws Exception {
        testPython("set_comprehension/SetComprehensionBool", "SetComprehensionBool", "SetComprehensionBoolAddition.stpy", true);
    }

    @Test
    public void testSetComprehensionBool2() throws Exception {
        testPython("set_comprehension/SetComprehensionBool2", "SetComprehensionBool2", "SetComprehensionBool2Addition.stpy", true);
    }

    @Test
    public void testSetComprehensionExists() throws Exception {
        testPython("set_comprehension/SetComprehensionExists", "SetComprehensionExists", "SetComprehensionExistsAddition.stpy", true);
    }
}
