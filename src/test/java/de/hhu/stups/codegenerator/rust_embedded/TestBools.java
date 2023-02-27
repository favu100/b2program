package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestBools extends TestRSE {
    public TestBools() throws URISyntaxException, IOException {}

    @Test
    public void testAnd() throws Exception {
        testRSE("And", "AndAddition.strs");
    }

    @Test
    public void testOr() throws Exception {
        testRSE("Or", "OrAddition.strs");
    }

    @Test
    public void testImplies() throws Exception {
        testRSE("Implies", "ImpliesAddition.strs");
    }

    @Test
    public void testEquivalent() throws Exception {
        testRSE("Equivalent", "EquivalentAddition.strs");
    }

    @Test
    public void testNot() throws Exception {
        testRSE("Not", "NotAddition.strs");
    }

    @Test
    public void testEqual() throws Exception {
        testRSE("Equal", "EqualAddition.strs");
    }

    @Test
    public void testUnequal() throws Exception {
        testRSE("Unequal", "UnequalAddition.strs");
    }
}
