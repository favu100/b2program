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
    public void testPowEmptySet2() throws Exception {
        testJava("PowEmptySet2", "PowEmptySet2", "PowEmptySet2Addition.stjava", true);
    }

    @Test
    public void testFinEmptySet() throws Exception {
        testJava("FinEmptySet", "FinEmptySet", "FinEmptySetAddition.stjava", true);
    }

    @Test
    public void testFinEmptySet2() throws Exception {
        testJava("FinEmptySet2", "FinEmptySet2", "FinEmptySet2Addition.stjava", true);
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
        testJava("PartialBijectionEmptySet", "PartialBijectionEmptySet", "PartialBijectionEmptySetAddition.stjava", true);
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
    public void testRelationEmptySet() throws Exception {
        testJava("RelationEmptySet", "RelationEmptySet", "RelationEmptySetAddition.stjava", true);
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

    @Test
    public void testIsInIdentity() throws Exception {
        testJava("IsInIdentity", "IsInIdentity", "IsInIdentityAddition.stjava", true);
    }

    @Test
    public void testIsNotInIdentity() throws Exception {
        testJava("IsNotInIdentity", "IsNotInIdentity", "IsNotInIdentityAddition.stjava", true);
    }

    @Test
    public void testIsInInverse() throws Exception {
        testJava("IsInInverse", "IsInInverse", "IsInInverseAddition.stjava", true);
    }

    @Test
    public void testIsNotInInverse() throws Exception {
        testJava("IsNotInInverse", "IsNotInInverse", "IsNotInInverseAddition.stjava", true);
    }

    @Test
    public void testIsInCartesianProduct() throws Exception {
        testJava("IsInCartesianProduct", "IsInCartesianProduct", "IsInCartesianProductAddition.stjava", true);
    }

    @Test
    public void testIsNotInCartesianProduct() throws Exception {
        testJava("IsNotInCartesianProduct", "IsNotInCartesianProduct", "IsNotInCartesianProductAddition.stjava", true);
    }

    @Test
    public void testIsInRangeSubstraction() throws Exception {
        testJava("IsInRangeSubstraction", "IsInRangeSubstraction", "IsInRangeSubstractionAddition.stjava", true);
    }

    @Test
    public void testIsNotInRangeSubstraction() throws Exception {
        testJava("IsNotInRangeSubstraction", "IsNotInRangeSubstraction", "IsNotInRangeSubstractionAddition.stjava", true);
    }

    @Test
    public void testIsInRangeRestriction() throws Exception {
        testJava("IsInRangeRestriction", "IsInRangeRestriction", "IsInRangeRestrictionAddition.stjava", true);
    }

    @Test
    public void testIsNotInRangeRestriction() throws Exception {
        testJava("IsNotInRangeRestriction", "IsNotInRangeRestriction", "IsNotInRangeRestrictionAddition.stjava", true);
    }

    @Test
    public void testIsInDomainRestriction() throws Exception {
        testJava("IsInDomainRestriction", "IsInDomainRestriction", "IsInDomainRestrictionAddition.stjava", true);
    }

    @Test
    public void testIsNotInDomainRestriction() throws Exception {
        testJava("IsNotInDomainRestriction", "IsNotInDomainRestriction", "IsNotInDomainRestrictionAddition.stjava", true);
    }

    @Test
    public void testIsInDomainSubstraction() throws Exception {
        testJava("IsInDomainSubstraction", "IsInDomainSubstraction", "IsInDomainSubstractionAddition.stjava", true);
    }

    @Test
    public void testIsNotInDomainSubstraction() throws Exception {
        testJava("IsNotInDomainSubstraction", "IsNotInDomainSubstraction", "IsNotInDomainSubstractionAddition.stjava", true);
    }

    @Test
    public void testIsInParallelProduct() throws Exception {
        testJava("IsInParallelProduct", "IsInParallelProduct", "IsInParallelProductAddition.stjava", true);
    }

    @Test
    public void testIsNotInParallelProduct() throws Exception {
        testJava("IsNotInParallelProduct", "IsNotInParallelProduct", "IsNotInParallelProductAddition.stjava", true);
    }

    @Test
    public void testIsInDirectProduct() throws Exception {
        testJava("IsInDirectProduct", "IsInDirectProduct", "IsInDirectProductAddition.stjava", true);
    }

    @Test
    public void testIsNotInDirectProduct() throws Exception {
        testJava("IsNotInDirectProduct", "IsNotInDirectProduct", "IsNotInDirectProductAddition.stjava", true);
    }

    @Test
    public void testIsInDomain() throws Exception {
        testJava("IsInDomain", "IsInDomain", "IsInDomainAddition.stjava", true);
    }

    @Test
    public void testIsNotInDomain() throws Exception {
        testJava("IsNotInDomain", "IsNotInDomain", "IsNotInDomainAddition.stjava", true);
    }

    @Test
    public void testIsInRange() throws Exception {
        testJava("IsInRange", "IsInRange", "IsInRangeAddition.stjava", true);
    }

    @Test
    public void testIsNotInRange() throws Exception {
        testJava("IsNotInRange", "IsNotInRange", "IsNotInRangeAddition.stjava", true);
    }

    @Test
    public void testIsInRelationalImage() throws Exception {
        testJava("IsInRelationalImage", "IsInRelationalImage", "IsInRelationalImageAddition.stjava", true);
    }

    @Test
    public void testIsNotInRelationalImage() throws Exception {
        testJava("IsNotInRelationalImage", "IsNotInRelationalImage", "IsNotInRelationalImageAddition.stjava", true);
    }

    @Test
    public void testStructElementOf() throws Exception {
        testJava("StructElementOf", "StructElementOf", "StructElementOfAddition.stjava", true);
    }

    @Test
    public void testStructNotElementOf() throws Exception {
        testJava("StructNotElementOf", "StructNotElementOf", "StructNotElementOfAddition.stjava", true);
    }

    @Test
    public void testIsInComposition() throws Exception {
        testJava("IsInComposition", "IsInComposition", "IsInCompositionAddition.stjava", true);
    }

    @Test
    public void testIsNotInComposition() throws Exception {
        testJava("IsNotInComposition", "IsNotInComposition", "IsNotInCompositionAddition.stjava", true);
    }

    @Test
    public void testIsInClosure() throws Exception {
        testJava("IsInClosure", "IsInClosure", "IsInClosureAddition.stjava", true);
    }

    @Test
    public void testIsNotInClosure() throws Exception {
        testJava("IsNotInClosure", "IsNotInClosure", "IsNotInClosureAddition.stjava", true);
    }

    @Test
    public void testIsInClosure1() throws Exception {
        testJava("IsInClosure1", "IsInClosure1", "IsInClosure1Addition.stjava", true);
    }

    @Test
    public void testIsNotInClosure1() throws Exception {
        testJava("IsNotInClosure1", "IsNotInClosure1", "IsNotInClosure1Addition.stjava", true);
    }

    @Test
    public void testSubsetOfInterval() throws Exception {
        testJava("SubsetOfInterval", "SubsetOfInterval", "SubsetOfIntervalAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfInterval() throws Exception {
        testJava("NotSubsetOfInterval", "NotSubsetOfInterval", "NotSubsetOfIntervalAddition.stjava", true);
    }

    @Test
    public void testSubsetOfUnion() throws Exception {
        testJava("SubsetOfUnion", "SubsetOfUnion", "SubsetOfUnionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfUnion() throws Exception {
        testJava("NotSubsetOfUnion", "NotSubsetOfUnion", "NotSubsetOfUnionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfIntersection() throws Exception {
        testJava("SubsetOfIntersection", "SubsetOfIntersection", "SubsetOfIntersectionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfIntersection() throws Exception {
        testJava("NotSubsetOfIntersection", "NotSubsetOfIntersection", "NotSubsetOfIntersectionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfDifference() throws Exception {
        testJava("SubsetOfDifference", "SubsetOfDifference", "SubsetOfDifferenceAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfDifference() throws Exception {
        testJava("NotSubsetOfDifference", "NotSubsetOfDifference", "NotSubsetOfDifferenceAddition.stjava", true);
    }

    @Test
    public void testSubsetOfInverse() throws Exception {
        testJava("SubsetOfInverse", "SubsetOfInverse", "SubsetOfInverseAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfInverse() throws Exception {
        testJava("NotSubsetOfInverse", "NotSubsetOfInverse", "NotSubsetOfInverseAddition.stjava", true);
    }

    @Test
    public void testSubsetOfDomain() throws Exception {
        testJava("SubsetOfDomain", "SubsetOfDomain", "SubsetOfDomainAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfDomain() throws Exception {
        testJava("NotSubsetOfDomain", "NotSubsetOfDomain", "NotSubsetOfDomainAddition.stjava", true);
    }

    @Test
    public void testSubsetOfRange() throws Exception {
        testJava("SubsetOfRange", "SubsetOfRange", "SubsetOfRangeAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfRange() throws Exception {
        testJava("NotSubsetOfRange", "NotSubsetOfRange", "NotSubsetOfRangeAddition.stjava", true);
    }

    @Test
    public void testSubsetOfRelationalImage() throws Exception {
        testJava("SubsetOfRelationalImage", "SubsetOfRelationalImage", "SubsetOfRelationalImageAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfRelationalImage() throws Exception {
        testJava("NotSubsetOfRelationalImage", "NotSubsetOfRelationalImage", "NotSubsetOfRelationalImageAddition.stjava", true);
    }

    @Test
    public void testSubsetOfRangeRestriction() throws Exception {
        testJava("SubsetOfRangeRestriction", "SubsetOfRangeRestriction", "SubsetOfRangeRestrictionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfRangeRestriction() throws Exception {
        testJava("NotSubsetOfRangeRestriction", "NotSubsetOfRangeRestriction", "NotSubsetOfRangeRestrictionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfRangeSubstraction() throws Exception {
        testJava("SubsetOfRangeSubstraction", "SubsetOfRangeSubstraction", "SubsetOfRangeSubstractionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfRangeSubstraction() throws Exception {
        testJava("NotSubsetOfRangeSubstraction", "NotSubsetOfRangeSubstraction", "NotSubsetOfRangeSubstractionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfDomainRestriction() throws Exception {
        testJava("SubsetOfDomainRestriction", "SubsetOfDomainRestriction", "SubsetOfDomainRestrictionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfDomainRestriction() throws Exception {
        testJava("NotSubsetOfDomainRestriction", "NotSubsetOfDomainRestriction", "NotSubsetOfDomainRestrictionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfDomainSubstraction() throws Exception {
        testJava("SubsetOfDomainSubstraction", "SubsetOfDomainSubstraction", "SubsetOfDomainSubstractionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfDomainSubstraction() throws Exception {
        testJava("NotSubsetOfDomainSubstraction", "NotSubsetOfDomainSubstraction", "NotSubsetOfDomainSubstractionAddition.stjava", true);
    }

    @Test
    public void testSubsetOfParallelProduct() throws Exception {
        testJava("SubsetOfParallelProduct", "SubsetOfParallelProduct", "SubsetOfParallelProductAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfParallelProduct() throws Exception {
        testJava("NotSubsetOfParallelProduct", "NotSubsetOfParallelProduct", "NotSubsetOfParallelProductAddition.stjava", true);
    }

    @Test
    public void testSubsetOfComposition() throws Exception {
        testJava("SubsetOfComposition", "SubsetOfComposition", "SubsetOfCompositionAddition.stjava", true);
    }

    @Test
    public void testNotSubsetOfComposition() throws Exception {
        testJava("NotSubsetOfComposition", "NotSubsetOfComposition", "NotSubsetOfCompositionAddition.stjava", true);
    }


}
