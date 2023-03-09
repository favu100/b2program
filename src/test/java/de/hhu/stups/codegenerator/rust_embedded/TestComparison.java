package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestComparison extends TestRSE {
    public TestComparison() throws URISyntaxException, IOException {}

    @Test
    public void testLess() throws Exception {
        testRSE("comparison/Less", "LessAddition.strs");
    }

    @Test
    public void testLessEqual() throws Exception {
        testRSE("comparison/LessEqual", "LessEqualAddition.strs");
    }

    @Test
    public void testGreater() throws Exception {
        testRSE("comparison/Greater", "GreaterAddition.strs");
    }


    @Test
    public void testGreaterEqual() throws Exception {
        testRSE("comparison/GreaterEqual", "GreaterEqualAddition.strs");
    }


    @Test
    public void tessEqual() throws Exception {
        testRSE("comparison/Equal", "EqualAddition.strs");
    }


    @Test
    public void testUnequal() throws Exception {
        testRSE("comparison/Unequal", "UnequalAddition.strs");
    }
}
