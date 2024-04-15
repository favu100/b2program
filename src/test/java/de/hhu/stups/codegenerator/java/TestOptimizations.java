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

    @Test
    public void testPartialFunction() throws Exception {
        testJava("PartialFunction", "PartialFunction", "PartialFunctionAddition.stjava", true);
    }

    @Test
    public void testIsNotPartialFunction() throws Exception {
        testJava("IsNotPartialFunction", "IsNotPartialFunction", "IsNotPartialFunctionAddition.stjava", true);
    }

    @Test
    public void testTotalFunction() throws Exception {
        testJava("TotalFunction", "TotalFunction", "TotalFunctionAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalFunction() throws Exception {
        testJava("IsNotTotalFunction", "IsNotTotalFunction", "IsNotTotalFunctionAddition.stjava", true);
    }

    @Test
    public void testPartialSurjection() throws Exception {
        testJava("PartialSurjection", "PartialSurjection", "PartialSurjectionAddition.stjava", true);
    }

    @Test
    public void testIsNotPartialSurjection() throws Exception {
        testJava("IsNotPartialSurjection", "IsNotPartialSurjection", "IsNotPartialSurjectionAddition.stjava", true);
    }

    @Test
    public void testTotalSurjection() throws Exception {
        testJava("TotalSurjection", "TotalSurjection", "TotalSurjectionAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalSurjection() throws Exception {
        testJava("IsNotTotalSurjection", "IsNotTotalSurjection", "IsNotTotalSurjectionAddition.stjava", true);
    }

    @Test
    public void testTotalInjection() throws Exception {
        testJava("TotalInjection", "TotalInjection", "TotalInjectionAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalInjection() throws Exception {
        testJava("IsNotTotalInjection", "IsNotTotalInjection", "IsNotTotalInjectionAddition.stjava", true);
    }

    @Test
    public void testPartialInjection() throws Exception {
        testJava("PartialInjection", "PartialInjection", "PartialInjectionAddition.stjava", true);
    }

    @Test
    public void testIsNotPartialInjection() throws Exception {
        testJava("IsNotPartialInjection", "IsNotPartialInjection", "IsNotPartialInjectionAddition.stjava", true);
    }

    @Test
    public void testPartialBijection() throws Exception {
        testJava("PartialBijection", "PartialBijection", "PartialBijectionAddition.stjava", true);
    }

    @Test
    public void testIsNotPartialBijection() throws Exception {
        testJava("IsNotPartialBijection", "IsNotPartialBijection", "IsNotPartialBijectionAddition.stjava", true);
    }

    @Test
    public void testTotalBijection() throws Exception {
        testJava("TotalBijection", "TotalBijection", "TotalBijectionAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalBijection() throws Exception {
        testJava("IsNotTotalBijection", "IsNotTotalBijection", "IsNotTotalBijectionAddition.stjava", true);
    }

    @Test
    public void testRelation() throws Exception {
        testJava("Relation", "Relation", "RelationAddition.stjava", true);
    }

    @Test
    public void testIsNotRelation() throws Exception {
        testJava("IsNotRelation", "IsNotRelation", "IsNotRelationAddition.stjava", true);
    }

    @Test
    public void testTotalRelation() throws Exception {
        testJava("TotalRelation", "TotalRelation", "TotalRelationAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalRelation() throws Exception {
        testJava("IsNotTotalRelation", "IsNotTotalRelation", "IsNotTotalRelationAddition.stjava", true);
    }

    @Test
    public void testSurjectiveRelation() throws Exception {
        testJava("SurjectionRelation", "SurjectionRelation", "SurjectionRelationAddition.stjava", true);
    }

    @Test
    public void testIsNotSurjectiveRelation() throws Exception {
        testJava("IsNotSurjectionRelation", "IsNotSurjectionRelation", "IsNotSurjectionRelationAddition.stjava", true);
    }

    @Test
    public void testTotalSurjectiveRelation() throws Exception {
        testJava("TotalSurjectionRelation", "TotalSurjectionRelation", "TotalSurjectionRelationAddition.stjava", true);
    }

    @Test
    public void testIsNotTotalSurjectiveRelation() throws Exception {
        testJava("IsNotTotalSurjectionRelation", "IsNotTotalSurjectionRelation", "IsNotTotalSurjectionRelationAddition.stjava", true);
    }

}
