package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestInteger extends TestRSE {
    public TestInteger() throws URISyntaxException, IOException {}

    @Test
    public void testGreater() throws Exception {
        testRSE("Greater", "GreaterAddition.strs");
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testRSE("GreaterEqual", "GreaterEqualAddition.strs");
    }

    @Test
    public void testLess() throws Exception {
        testRSE("Less", "LessAddition.strs");
    }

    @Test
    public void testLessEqual() throws Exception {
        testRSE("LessEqual", "LessEqualAddition.strs");
    }

    @Test
    public void testPlus() throws Exception {
        testRSE("Plus", "PlusAddition.strs");
    }

    @Test
    public void testMinus() throws Exception {
        testRSE("Minus", "MinusAddition.strs");
    }

    @Test
    public void testMultiply() throws Exception {
        testRSE("Multiply", "MultiplyAddition.strs");
    }

    @Test
    public void testDivide() throws Exception {
        testRSE("Divide", "DivideAddition.strs");
    }

    @Test
    public void testPower() throws Exception {
        testRSE("IntegerPower", "IntegerPowerAdditions.strs");
    }

    @Test
    public void testModulo() throws Exception {
        testRSE("Modulo", "ModuloAddition.strs");
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testRSE("UnaryMinus", "UnaryMinusAddition.strs");
    }

    @Test
    public void testPred() throws Exception {
        testRSE("Pred", "PredAddition.strs");
    }

    @Test
    public void testSucc() throws Exception {
        testRSE("Succ", "SuccAddition.strs");
    }
}
