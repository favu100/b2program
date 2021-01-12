package de.hhu.stups.codegenerator.python;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestProjects extends TestPython {

    @Test
    public void testProject() throws Exception {
        //This might be a bug in the parser in the scoping part
        testPython("project1/A", "A", "AAddition.stpy", true);
    }

    @Test
    public void testProject2() throws Exception {
        testPython("project2/MachineA", "MachineA", "MachineAAddition.stpy", true);
    }

    @Test
    public void testProject3() throws Exception {
        testPython("project3/A");
    }

    @Test(expected = CodeGenerationException.class)
    public void testProject4() throws Exception {
        testPython("project4/A");
    }

    @Test
    public void testProject5() throws Exception {
        testPython("project5/Lift2");
    }

    @Test
    public void testProject6() throws Exception {
        testPython("project6/Lift2");
    }

    @Test
    public void testProject7() throws Exception {
        testPython("project7/Lift2");
    }

    @Test
    public void testProject8() throws Exception {
        testPython("project8/Lift2");
    }

    @Test
    public void testProject9() throws Exception {
        testPython("project9/Lift2");
    }

    @Test
    public void testProject10() throws Exception {
        testPython("project10/Lift2");
    }

    @Test
    public void testRefinement() throws Exception {
        //TODO: Type checking of variables from abstract machine
        testPython("refinement/RefinementMachine");
    }
}
