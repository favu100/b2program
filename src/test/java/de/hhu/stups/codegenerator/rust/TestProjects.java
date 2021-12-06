package de.hhu.stups.codegenerator.rust;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestProjects extends TestRS {

    @Test
    public void testProject() throws Exception {
        //This might be a bug in the parser in the scoping part
        testRS("project1/A", "A", "AAddition.strs", true);
    }

    @Test
    public void testProject2() throws Exception {
        testRS("project2/MachineA", "MachineA", "MachineAAddition.strs", true);
    }

    @Test
    public void testProject3() throws Exception {
        testRS("project3/A");
    }

    @Test(expected = CodeGenerationException.class)
    public void testProject4() throws Exception {
        testRS("project4/A");
    }

    @Test
    public void testProject5() throws Exception {
        testRS("project5/Lift2");
    }

    @Test
    public void testProject6() throws Exception {
        testRS("project6/Lift2");
    }

    @Test
    public void testProject7() throws Exception {
        testRS("project7/Lift2");
    }

    @Test
    public void testProject8() throws Exception {
        testRS("project8/Lift2");
    }

    @Test
    public void testProject9() throws Exception {
        testRS("project9/Lift2");
    }

    @Test
    public void testProject10() throws Exception {
        testRS("project10/Lift2");
    }

    // does not work for java as well
    @Test
    public void testRefinement() throws Exception {
        //TODO: Type checking of variables from abstract machine
        testRS("refinement/RefinementMachine");
    }
}
