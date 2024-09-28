package de.hhu.stups.codegenerator.cpp;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Ignore;
import org.junit.Test;

public class TestProjects extends TestCpp {

    @Test
    public void testProject() throws Exception {
        //This might be a bug in the parser in the scoping part
        testCpp("project1/A", "A", "AAddition.stcpp", true);
    }

    @Test
    public void testProject2() throws Exception {
        testCpp("project2/MachineA", "MachineA", "MachineAAddition.stcpp", true);
    }

    @Test
    public void testProject3() throws Exception {
        testCpp("project3/A");
    }

    @Test(expected = CodeGenerationException.class)
    public void testProject4() throws Exception {
        testCpp("project4/A");
    }

    @Test
    public void testProject5() throws Exception {
        testCpp("project5/Lift2");
    }

    @Test
    public void testProject6() throws Exception {
        testCpp("project6/Lift2");
    }

    @Test
    public void testProject7() throws Exception {
        testCpp("project7/Lift2");
    }

    @Test
    public void testProject8() throws Exception {
        testCpp("project8/Lift2");
    }

    @Test
    public void testProject9() throws Exception {
        testCpp("project9/Lift2");
    }

    @Test
    public void testProject10() throws Exception {
        testCpp("project10/Lift2");
    }

    @Ignore
    @Test
    public void testRefinement() throws Exception {
        //TODO: Type checking of variables from abstract machine
        testCpp("refinement/RefinementMachine");
    }
}
