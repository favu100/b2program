package de.hhu.stups.codegenerator.java;

import org.junit.Ignore;
import org.junit.Test;

public class TestOptimizations extends TestJava {

    @Test
    public void testNatural() throws Exception {
        testJava("Natural", "Natural", "NaturalAddition.stjava", true);
    }

    @Test
    public void testNatural1() throws Exception {
        testJava("Natural1", "Natural1", "Natural1Addition.stjava", true);
    }

    @Test
    public void testNotNatural() throws Exception {
        testJava("NotNatural", "NotNatural", "NotNaturalAddition.stjava", true);
    }

    @Test
    public void testNotNatural1() throws Exception {
        testJava("NotNatural1", "NotNatural1", "NotNatural1Addition.stjava", true);
    }

    @Test
    public void testInteger() throws Exception {
        testJava("Integer", "Integer", "IntegerAddition.stjava", true);
    }

    @Test
    public void testNotInteger() throws Exception {
        testJava("NotInteger", "NotInteger", "NotIntegerAddition.stjava", true);
    }

    @Test
    public void testInt() throws Exception {
        testJava("Int", "Int", "IntAddition.stjava", true);
    }

    @Test
    public void testNotInt() throws Exception {
        testJava("NotInt", "NotInt", "NotIntAddition.stjava", true);
    }

    @Test
    public void testString() throws Exception {
        testJava("Stringg", "Stringg", "StringAddition.stjava", true);
    }

    @Test
    public void testNotString() throws Exception {
        testJava("NotString", "NotString", "NotStringAddition.stjava", true);
    }

    @Test
    public void testBoolean() throws Exception {
        testJava("Booleann", "Booleann", "BooleanAddition.stjava", true);
    }

    @Test
    public void testNotBoolean() throws Exception {
        testJava("NotBoolean", "NotBoolean", "NotBooleanAddition.stjava", true);
    }

    @Test
    public void testIsInInterval() throws Exception {
        testJava("IsInInterval", "IsInInterval", "IsInIntervalAddition.stjava", true);
    }

    @Test
    public void testIsNotInInterval() throws Exception {
        testJava("IsNotInInterval", "IsNotInInterval", "IsNotInIntervalAddition.stjava", true);
    }

    @Test
    public void testIsInUnion() throws Exception {
        testJava("IsInUnion", "IsInUnion", "IsInUnionAddition.stjava", true);
    }

    @Test
    public void testIsNotInUnion() throws Exception {
        testJava("IsNotInUnion", "IsNotInUnion", "IsNotInUnionAddition.stjava", true);
    }

    @Test
    public void testIsInIntersection() throws Exception {
        testJava("IsInIntersection", "IsInIntersection", "IsInIntersectionAddition.stjava", true);
    }

    @Test
    public void testIsNotInIntersection() throws Exception {
        testJava("IsNotInIntersection", "IsNotInIntersection", "IsNotInIntersectionAddition.stjava", true);
    }

    @Test
    public void testIsInDifference() throws Exception {
        testJava("IsInDifference", "IsInDifference", "IsInDifferenceAddition.stjava", true);
    }

    @Test
    public void testIsNotInDifference() throws Exception {
        testJava("IsNotInDifference", "IsNotInDifference", "IsNotInDifferenceAddition.stjava", true);
    }

    @Test
    public void testPowEmptySet() throws Exception {
        testJava("PowEmptySet", "PowEmptySet", "PowEmptySetAddition.stjava", true);
    }

    @Test
    public void testPowElementOf() throws Exception {
        testJava("PowElementOf", "PowElementOf", "PowElementOfAddition.stjava", true);
    }

    @Test
    public void testPowNotElementOf() throws Exception {
        testJava("PowNotElementOf", "PowNotElementOf", "PowNotElementOfAddition.stjava", true);
    }

    @Test
    public void testPow1ElementOf() throws Exception {
        testJava("Pow1ElementOf", "Pow1ElementOf", "Pow1ElementOfAddition.stjava", true);
    }

    @Test
    public void testPow1NotElementOf() throws Exception {
        testJava("Pow1NotElementOf", "Pow1NotElementOf", "Pow1NotElementOfAddition.stjava", true);
    }

    @Test
    public void testFinElementOf() throws Exception {
        testJava("FinElementOf", "FinElementOf", "FinElementOfAddition.stjava", true);
    }

    @Test
    public void testFinNotElementOf() throws Exception {
        testJava("FinNotElementOf", "FinNotElementOf", "FinNotElementOfAddition.stjava", true);
    }

    @Test
    public void testFin1ElementOf() throws Exception {
        testJava("Fin1ElementOf", "Fin1ElementOf", "Fin1ElementOfAddition.stjava", true);
    }

    @Test
    public void testFin1NotElementOf() throws Exception {
        testJava("Fin1NotElementOf", "Fin1NotElementOf", "Fin1NotElementOfAddition.stjava", true);
    }

    @Test
    public void testNat() throws Exception {
        testJava("Nat", "Nat", "NatAddition.stjava", true);
    }

    @Test
    public void testNotNat() throws Exception {
        testJava("NotNat", "NotNat", "NotNatAddition.stjava", true);
    }

    @Test
    public void testNat1() throws Exception {
        testJava("Nat1", "Nat1", "Nat1Addition.stjava", true);
    }

    @Test
    public void testNotNat1() throws Exception {
        testJava("NotNat1", "NotNat1", "NotNat1Addition.stjava", true);
    }

    @Test
    public void testPartialFunctionEmptySet() throws Exception {
        testJava("PartialFunctionEmptySet", "PartialFunctionEmptySet", "PartialFunctionEmptySetAddition.stjava", true);
    }

    @Test
    public void testPartialBijectionEmptySet() throws Exception {
        testJava("PartialBijectionEmptySet", "PartialBijectionEmptySet", "PartialBijectionEmptySetEmptySetAddition.stjava", true);
    }

}
