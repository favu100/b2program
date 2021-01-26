package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestOperators extends TestJava {

    @Test
    public void testAnd() throws Exception {
        testJava("And", "And", "AndAddition.stjava", true);
    }

    @Test
    public void testCard() throws Exception {
        testJava("Card", "Card", "CardAddition.stjava", true);
    }

    @Test
    public void testDifference() throws Exception {
        testJava("Difference", "Difference", "DifferenceAddition.stjava", true);
    }

    @Test
    public void testDivide() throws Exception {
        testJava("Divide", "Divide", "DivideAddition.stjava", true);
    }

    @Test
    public void testDomain() throws Exception {
        testJava("Domain", "Domain", "DomainAddition.stjava", true);
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testJava("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stjava", true);
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testJava("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stjava", true);
    }

    @Test
    public void testElementOf() throws Exception {
        testJava("ElementOf", "ElementOf", "ElementOfAddition.stjava", true);
    }

    @Test
    public void testEmptySet() throws Exception {
        testJava("EmptySet", "EmptySet", "EmptySetAddition.stjava", true);
    }

    @Test
    public void testEqual() throws Exception {
        testJava("Equal", "Equal", "EqualAddition.stjava", true);
    }

    @Test
    public void testEquivalent() throws Exception {
        testJava("Equivalent", "Equivalent", "EquivalentAddition.stjava", true);
    }

    @Test
    public void testGreater() throws Exception {
        testJava("Greater", "Greater", "GreaterAddition.stjava", true);
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testJava("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjava", true);
    }

    @Test
    public void testImplies() throws Exception {
        testJava("Implies", "Implies", "ImpliesAddition.stjava", true);
    }

    @Test
    public void testIntersection() throws Exception {
        testJava("Intersection", "Intersection", "IntersectionAddition.stjava", true);
    }

    @Test
    public void testInterval() throws Exception {
        testJava("Interval", "Interval", "IntervalAddition.stjava", true);
    }

    @Test
    public void testInverse() throws Exception {
        testJava("Inverse", "Inverse", "InverseAddition.stjava", true);
    }

    @Test
    public void testLess() throws Exception {
        testJava("Less", "Less", "LessAddition.stjava", true);
    }

    @Test
    public void testLessEqual() throws Exception {
        testJava("LessEqual", "LessEqual", "LessEqualAddition.stjava", true);
    }

    @Test
    public void testMax() throws Exception {
        testJava("Max", "Max", "MaxAddition.stjava", true);
    }

    @Test
    public void testMin() throws Exception {
        testJava("Min", "Min", "MinAddition.stjava", true);
    }

    @Test
    public void testMinus() throws Exception {
        testJava("Minus", "Minus", "MinusAddition.stjava", true);
    }

    @Test
    public void testModulo() throws Exception {
        testJava("Modulo", "Modulo", "ModuloAddition.stjava", true);
    }

    @Test
    public void testMultiply() throws Exception {
        testJava("Multiply", "Multiply", "MultiplyAddition.stjava", true);
    }
    @Test
    public void testNot() throws Exception {
        testJava("Not", "Not", "NotAddition.stjava", true);
    }

    @Test
    public void testNotElementOf() throws Exception {
        testJava("NotElementOf", "NotElementOf", "NotElementOfAddition.stjava", true);
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testJava("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stjava", true);
    }

    @Test
    public void testNotSubset() throws Exception {
        testJava("NotSubset", "NotSubset", "NotSubsetAddition.stjava", true);
    }

    @Test
    public void testOr() throws Exception {
        testJava("Or", "Or", "OrAddition.stjava", true);
    }

    @Test
    public void testPlus2() throws Exception {
        testJava("Plus", "Plus", "PlusAddition.stjava", true);
    }

    @Test
    public void testRange() throws Exception {
        testJava("Range", "Range", "RangeAddition.stjava", true);
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testJava("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stjava", true);
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testJava("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stjava", true);
    }

    @Test
    public void testRelationalImage() throws Exception {
        testJava("RelationalImage", "RelationalImage", "RelationalImageAddition.stjava", true);
    }

    @Test
    public void testStrictSubset() throws Exception {
        testJava("StrictSubset", "StrictSubset", "StrictSubsetAddition.stjava", true);
    }

    @Test
    public void testSubset() throws Exception {
        testJava("Subset", "Subset", "SubsetAddition.stjava", true);
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testJava("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stjava", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testJava("Unequal", "Unequal", "UnequalAddition.stjava", true);
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testJava("GeneralizedUnion", "GeneralizedUnion", "GeneralizedUnionAddition.stjava", true);
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testJava("GeneralizedUnionEmpty", "GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.stjava", true);
    }

    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testJava("RelationGeneralizedUnion", "RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.stjava", true);
    }

    @Test
    public void testRelationGeneralizedUnionEmpty() throws Exception {
        testJava("RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmptyAddition.stjava", true);
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testJava("RelationGeneralizedIntersection", "RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.stjava", true);
    }

    @Test
    public void testRelationGeneralizedIntersectionEmpty() throws Exception {
        testJava("RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmptyAddition.stjava", true);
    }


    @Test
    public void testGeneralizedIntersection() throws Exception {
        testJava("GeneralizedIntersection", "GeneralizedIntersection", "GeneralizedIntersectionAddition.stjava", true);
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testJava("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.stjava", true);
    }


    @Test
    public void testFunctionalOverride() throws Exception {
        testJava("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stjava", true);
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testJava("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stjava", true);
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testJava("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stjava", true);
    }

    @Test
    public void testOverride() throws Exception {
        testJava("Override", "Override", "OverrideAddition.stjava", true);
    }

    @Test
    public void testPow() throws Exception {
        testJava("Pow", "Pow", "PowAddition.stjava", true);
    }

    @Test
    public void testRelationPow() throws Exception {
        testJava("RelationPow", "RelationPow", "RelationPowAddition.stjava", true);
    }

    @Test
    public void testRelationPow1() throws Exception {
        testJava("RelationPow1", "RelationPow1", "RelationPow1Addition.stjava", true);
    }

    @Test
    public void testPow1() throws Exception {
        testJava("Pow1", "Pow1", "Pow1Addition.stjava", true);
    }

    @Test
    public void testFin() throws Exception {
        testJava("Fin", "Fin", "FinAddition.stjava", true);
    }

    @Test
    public void testFin1() throws Exception {
        testJava("Fin1", "Fin1", "Fin1Addition.stjava", true);
    }

    @Test
    public void testId() throws Exception {
        testJava("Id", "Id", "IdAddition.stjava", true);
    }

    @Test
    public void testParallelProduct() throws Exception {
        testJava("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stjava", true);
    }

    @Test
    public void testDirectProduct() throws Exception {
        testJava("DirectProduct", "DirectProduct", "DirectProductAddition.stjava", true);
    }

    @Test
    public void testComposition() throws Exception {
        testJava("Composition", "Composition", "CompositionAddition.stjava", true);
    }

    @Test
    public void testProjection1() throws Exception {
        testJava("Projection1", "Projection1", "Projection1Addition.stjava", true);
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testJava("TupleProjection1", "TupleProjection1", "TupleProjection1Addition.stjava", true);
    }

    @Test
    public void testProjection2() throws Exception {
        testJava("Projection2", "Projection2", "Projection2Addition.stjava", true);
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testJava("TupleProjection2", "TupleProjection2", "TupleProjection2Addition.stjava", true);
    }

    @Test
    public void testAppend() throws Exception {
        testJava("Append", "Append", "AppendAddition.stjava", true);
    }


    @Test
    public void testConc() throws Exception {
        testJava("Conc", "Conc", "ConcAddition.stjava", true);
    }

    @Test
    public void testConcat() throws Exception {
        testJava("Concat", "Concat", "ConcatAddition.stjava", true);
    }

    @Test
    public void testDrop() throws Exception {
        testJava("Drop", "Drop", "DropAddition.stjava", true);
    }

    @Test
    public void testEmptySequence() throws Exception {
        testJava("EmptySequence", "EmptySequence", "EmptySequenceAddition.stjava", true);
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testJava("EnumeratedSequence");
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testJava("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stjava", true);
    }

    @Test
    public void testFrontSequence() throws Exception {
        testJava("FrontSequence", "FrontSequence", "FrontSequenceAddition.stjava", true);
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testJava("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stjava", true);
    }

    @Test
    public void testPrepend() throws Exception {
        testJava("Prepend", "Prepend", "PrependAddition.stjava", true);
    }

    @Test
    public void testReverse() throws Exception {
        testJava("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stjava", true);
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testJava("SizeOfSequence");
    }

    @Test
    public void testTailSequence() throws Exception {
        testJava("TailSequence", "TailSequence", "TailSequenceAddition.stjava", true);
    }

    @Test
    public void testTake() throws Exception {
        testJava("Take", "Take", "TakeAddition.stjava", true);
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testJava("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stjava", true);
    }

    @Test
    public void testPred() throws Exception {
        testJava("Pred", "Pred", "PredAddition.stjava", true);
    }

    @Test
    public void testSucc() throws Exception {
        testJava("Succ", "Succ", "SuccAddition.stjava", true);
    }

    @Test
    public void testIterate() throws Exception {
        testJava("Iterate", "Iterate", "IterateAddition.stjava", true);
    }

    @Test
    public void testClosure() throws Exception {
        testJava("Closure", "Closure", "ClosureAddition.stjava", true);
    }

    @Test
    public void testClosure1() throws Exception {
        testJava("Closure1", "Closure1", "Closure1Addition.stjava", true);
    }

    @Test
    public void testFnc() throws Exception {
        testJava("Fnc", "Fnc", "FncAddition.stjava", true);
    }

    @Test
    public void testRel() throws Exception {
        testJava("Rel", "Rel", "RelAddition.stjava", true);
    }
}
