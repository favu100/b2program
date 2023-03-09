package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestLogical extends TestRSE {
    public TestLogical() throws URISyntaxException, IOException {}

    @Test
    public void testAnd2() throws Exception {
        testRSE("logical/And","AndAddition.strs");
    }

    @Test
    public void testOr2() throws Exception {
        testRSE("logical/Or", "OrAddition.strs");
    }

    @Test
    public void testImpliesPerformance() throws Exception {
        testRSE("logical/Implies", "ImpliesAddition.strs");
    }

    @Test
    public void testNot2() throws Exception {
        testRSE("logical/Not", "NotAddition.strs");
    }

    @Test
    public void testEquivalent2() throws Exception {
        testRSE("logical/Equivalent", "EquivalentAddition.strs");
    }

    @Test
    public void testBooleanExpression() throws Exception {
        testRSE("logical/BooleanExpression", "BooleanExpressionAddition.strs");
    }

    @Test
    public void testBooleanConstant() throws Exception {
        testRSE("logical/BooleanConstant", "BooleanConstantAddition.strs");
    }
}
