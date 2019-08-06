package de.hhu.stups.codegenerator.java;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestProjects extends TestJava {

    @Test
    public void testProject() throws Exception {
        //This might be a bug in the parser in the scoping part
        testJava("project1/A", "A", "AAddition.stjava", true);
    }

    @Test
    public void testProject2() throws Exception {
        testJava("project2/MachineA", "MachineA", "MachineAAddition.stjava", true);
    }

    @Test
    public void testProject3() throws Exception {
        testJava("project3/A");
    }

    @Test(expected = CodeGenerationException.class)
    public void testProject4() throws Exception {
        testJava("project4/A");
    }

    @Test
    public void testProject5() throws Exception {
        testJava("project5/Lift2");
    }

    @Test
    public void testProject6() throws Exception {
        testJava("project6/Lift2");
    }

    @Test
    public void testProject7() throws Exception {
        testJava("project7/Lift2");
    }

    @Test
    public void testProject8() throws Exception {
        testJava("project8/Lift2");
    }

    @Test
    public void testProject9() throws Exception {
        testJava("project9/Lift2");
    }

    @Test
    public void testProject10() throws Exception {
        testJava("project10/Lift2");
    }

    @Test
    public void testRefinement() throws Exception {
        //TODO: Type checking of variables from abstract machine
        testJava("refinement/RefinementMachine");
    }
}
