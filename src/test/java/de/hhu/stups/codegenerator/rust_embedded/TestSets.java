package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestSets extends TestRSE {
    public TestSets() throws URISyntaxException, IOException {}

    @Test
    public void testEmptySet() throws Exception {
        testRSE("EmptySet", "EmptySetAddition.strs");
    }

    @Test
    public void testPow() throws Exception {
        testRSE("Pow", "PowAddition.strs");
    }

    @Test
    public void testPow1() throws Exception {
        testRSE("Pow1", "Pow1Addition.strs");
    }

    @Test
    public void testFin() throws Exception {
        testRSE("Fin", "FinAddition.strs");
    }

    @Test
    public void testFin1() throws Exception {
        testRSE("Fin1", "Fin1Addition.strs");
    }

    @Test
    public void testCard() throws Exception {
        testRSE("Card", "CardAddition.strs");
    }

    @Test
    public void testUnion() throws Exception {
        testRSE("Union", "UnionAddition.strs");
    }

    @Test
    public void testIntersection() throws Exception {
        testRSE("Intersection", "IntersectionAddition.strs");
    }

    @Test
    public void testDifference() throws Exception {
        testRSE("Difference", "DifferenceAddition.strs");
    }

    @Test
    public void testElementOf() throws Exception {
        testRSE("ElementOf", "ElementOfAddition.strs");
    }

    @Test
    public void testNotElementOf() throws Exception {
        testRSE("NotElementOf", "NotElementOfAddition.strs");
    }

    @Test
    public void testSubset() throws Exception {
        testRSE("Subset", "SubsetAddition.strs");
    }

    @Test
    public void testNotSubset() throws Exception {
        testRSE("NotSubset", "NotSubsetAddition.strs");
    }

    @Test
    public void testStrictSubset() throws Exception {
        testRSE("StrictSubset", "StrictSubsetAddition.strs");
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testRSE("NotStrictSubset", "NotStrictSubsetAddition.strs");
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testRSE("GeneralizedUnion", "GeneralizedUnionAddition.strs");
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testRSE("GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.strs");
    }

    @Test
    public void testGeneralizedIntersection() throws Exception {
        testRSE("GeneralizedIntersection", "GeneralizedIntersectionAddition.strs");
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testRSE("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.strs");
    }



// These tests won't work, because they require Integer-Sets, which embedded code-gen cannot do (for now)
    @Test(expected = RuntimeException.class)
    public void testInterval() throws Exception {
        testRSE("Interval", "IntervalAddition.strs");
    }

    @Test(expected = RuntimeException.class)
    public void testMax() throws Exception {
        testRSE("Max", "MaxAddition.strs");
    }

    @Test(expected = RuntimeException.class)
    public void testMin() throws Exception {
        testRSE("Min", "MinAddition.strs");
    }
}
