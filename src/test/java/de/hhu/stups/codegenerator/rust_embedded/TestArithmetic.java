package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestArithmetic extends TestRSE {

    public TestArithmetic() throws URISyntaxException, IOException {}

    @Test
    public void testPlus() throws Exception {
        testRSE("arithmetic/Plus", "PlusAddition.strs");
    }

    @Test
    public void testMinus2() throws Exception {
        testRSE("arithmetic/Minus", "MinusAddition.strs");
    }

    @Test
    public void testMultiply2() throws Exception {
        testRSE("arithmetic/Multiply","MultiplyAddition.strs");
    }

    @Test
    public void testDivide2() throws Exception {
        testRSE("arithmetic/Divide", "DivideAddition.strs");
    }


    @Test
    public void testModulo2() throws Exception {
        testRSE("arithmetic/Modulo", "ModuloAddition.strs");
    }

    @Test
    public void testNegative() throws Exception {
        testRSE("arithmetic/Negative", "NegativeAddition.strs");
    }
}
