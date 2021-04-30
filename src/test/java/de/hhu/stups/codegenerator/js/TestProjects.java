package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestProjects extends TestJs {

    @Test
    public void testProject() throws Exception {
        //This might be a bug in the parser in the scoping part
        testJs("project1/A", "A", "AAddition.stjs", true);
    }

    @Test
    public void testProject2() throws Exception {
        testJs("project2/MachineA", "MachineA", "MachineAAddition.stjs", true);
    }

    @Test
    public void testProject3() throws Exception {
        testJs("project3/A");
    }

    @Test(expected = CodeGenerationException.class)
    public void testProject4() throws Exception {
        testJs("project4/A");
    }

    @Test
    public void testProject5() throws Exception {
        testJs("project5/Lift2");
    }

    @Test
    public void testProject6() throws Exception {
        testJs("project6/Lift2");
    }

    @Test
    public void testProject7() throws Exception {
        testJs("project7/Lift2");
    }

    @Test
    public void testProject8() throws Exception {
        testJs("project8/Lift2");
    }

    @Test
    public void testProject9() throws Exception {
        testJs("project9/Lift2");
    }

    @Test
    public void testProject10() throws Exception {
        testJs("project10/Lift2");
    }

    @Test
    public void testRefinement() throws Exception {
        //TODO: Type checking of variables from abstract machine
        testJs("refinement/RefinementMachine");
    }
}
