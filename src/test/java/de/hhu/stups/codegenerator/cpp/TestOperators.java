package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestOperators extends TestCpp {

    @Test
    public void testAnd() throws Exception {
        testCpp("And", "And", "AndAddition.stcpp", true);
    }

    @Test
    public void testCard() throws Exception {
        testCpp("Card", "Card", "CardAddition.stcpp", true);
    }

    @Test
    public void testDifference() throws Exception {
        testCpp("Difference", "Difference", "DifferenceAddition.stcpp", true);
    }

    @Test
    public void testDivide() throws Exception {
        testCpp("Divide", "Divide", "DivideAddition.stcpp", true);
    }

    @Test
    public void testDomain() throws Exception {
        testCpp("Domain", "Domain", "DomainAddition.stcpp", true);
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testCpp("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stcpp", true);
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testCpp("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stcpp", true);
    }

    @Test
    public void testElementOf() throws Exception {
        testCpp("ElementOf", "ElementOf", "ElementOfAddition.stcpp", true);
    }

    @Test
    public void testEmptySet() throws Exception {
        testCpp("EmptySet", "EmptySet", "EmptySetAddition.stcpp", true);
    }

    @Test
    public void testEqual() throws Exception {
        testCpp("Equal", "Equal", "EqualAddition.stcpp", true);
    }

    @Test
    public void testEquivalent() throws Exception {
        testCpp("Equivalent", "Equivalent", "EquivalentAddition.stcpp", true);
    }

    @Test
    public void testGreater() throws Exception {
        testCpp("Greater", "Greater", "GreaterAddition.stcpp", true);
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testCpp("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stcpp", true);
    }

    @Test
    public void testImplies() throws Exception {
        testCpp("Implies", "Implies", "ImpliesAddition.stcpp", true);
    }

    @Test
    public void testIntersection() throws Exception {
        testCpp("Intersection", "Intersection", "IntersectionAddition.stcpp", true);
    }

    @Test
    public void testInterval() throws Exception {
        testCpp("Interval", "Interval", "IntervalAddition.stcpp", true);
    }

    @Test
    public void testInverse() throws Exception {
        testCpp("Inverse", "Inverse", "InverseAddition.stcpp", true);
    }

    @Test
    public void testLess() throws Exception {
        testCpp("Less", "Less", "LessAddition.stcpp", true);
    }

    @Test
    public void testLessEqual() throws Exception {
        testCpp("LessEqual", "LessEqual", "LessEqualAddition.stcpp", true);
    }

    @Test
    public void testMax() throws Exception {
        testCpp("Max", "Max", "MaxAddition.stcpp", true);
    }

    @Test
    public void testMin() throws Exception {
        testCpp("Min", "Min", "MinAddition.stcpp", true);
    }

    @Test
    public void testMinus() throws Exception {
        testCpp("Minus", "Minus", "MinusAddition.stcpp", true);
    }

    @Test
    public void testModulo() throws Exception {
        testCpp("Modulo", "Modulo", "ModuloAddition.stcpp", true);
    }

    @Test
    public void testMultiply() throws Exception {
        testCpp("Multiply", "Multiply", "MultiplyAddition.stcpp", true);
    }
    @Test
    public void testNot() throws Exception {
        testCpp("Not", "Not", "NotAddition.stcpp", true);
    }

    @Test
    public void testNotElementOf() throws Exception {
        testCpp("NotElementOf", "NotElementOf", "NotElementOfAddition.stcpp", true);
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testCpp("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stcpp", true);
    }

    @Test
    public void testNotSubset() throws Exception {
        testCpp("NotSubset", "NotSubset", "NotSubsetAddition.stcpp", true);
    }

    @Test
    public void testOr() throws Exception {
        testCpp("Or", "Or", "OrAddition.stcpp", true);
    }

    @Test
    public void testPlus2() throws Exception {
        testCpp("Plus", "Plus", "PlusAddition.stcpp", true);
    }

    @Test
    public void testRange() throws Exception {
        testCpp("Range", "Range", "RangeAddition.stcpp", true);
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testCpp("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stcpp", true);
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testCpp("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stcpp", true);
    }

    @Test
    public void testRelationalImage() throws Exception {
        testCpp("RelationalImage", "RelationalImage", "RelationalImageAddition.stcpp", true);
    }

    @Test
    public void testStrictSubset() throws Exception {
        testCpp("StrictSubset", "StrictSubset", "StrictSubsetAddition.stcpp", true);
    }

    @Test
    public void testSubset() throws Exception {
        testCpp("Subset", "Subset", "SubsetAddition.stcpp", true);
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testCpp("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stcpp", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testCpp("Unequal", "Unequal", "UnequalAddition.stcpp", true);
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testCpp("GeneralizedUnion", "GeneralizedUnion", "GeneralizedUnionAddition.stcpp", true);
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testCpp("GeneralizedUnionEmpty", "GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.stcpp", true);
    }

    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testCpp("RelationGeneralizedUnion", "RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.stcpp", true);
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testCpp("RelationGeneralizedIntersection", "RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.stcpp", true);
    }


    @Test
    public void testGeneralizedIntersection() throws Exception {
        testCpp("GeneralizedIntersection", "GeneralizedIntersection", "GeneralizedIntersectionAddition.stcpp", true);
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testCpp("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.stcpp", true);
    }


    @Test
    public void testFunctionalOverride() throws Exception {
        testCpp("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stcpp", true);
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testCpp("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stcpp", true);
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testCpp("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stcpp", true);
    }

    @Test
    public void testOverride() throws Exception {
        testCpp("OOverride", "OOverride", "OverrideAddition.stcpp", true);
    }

    @Test
    public void testPow() throws Exception {
        testCpp("Pow", "Pow", "PowAddition.stcpp", true);
    }

    @Test
    public void testRelationPow() throws Exception {
        testCpp("RelationPow", "RelationPow", "RelationPowAddition.stcpp", true);
    }

    @Test
    public void testRelationPow1() throws Exception {
        testCpp("RelationPow1", "RelationPow1", "RelationPow1Addition.stcpp", true);
    }

    @Test
    public void testPow1() throws Exception {
        testCpp("Pow1", "Pow1", "Pow1Addition.stcpp", true);
    }

    @Test
    public void testFin() throws Exception {
        testCpp("Fin", "Fin", "FinAddition.stcpp", true);
    }

    @Test
    public void testFin1() throws Exception {
        testCpp("Fin1", "Fin1", "Fin1Addition.stcpp", true);
    }

    @Test
    public void testId() throws Exception {
        testCpp("Id", "Id", "IdAddition.stcpp", true);
    }

    @Test
    public void testParallelProduct() throws Exception {
        testCpp("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stcpp", true);
    }

    @Test
    public void testDirectProduct() throws Exception {
        testCpp("DirectProduct", "DirectProduct", "DirectProductAddition.stcpp", true);
    }

    @Test
    public void testComposition() throws Exception {
        testCpp("Composition", "Composition", "CompositionAddition.stcpp", true);
    }

    @Test
    public void testProjection1() throws Exception {
        testCpp("Projection1", "Projection1", "Projection1Addition.stcpp", true);
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testCpp("TupleProjection1", "TupleProjection1", "TupleProjection1Addition.stcpp", true);
    }

    @Test
    public void testProjection2() throws Exception {
        testCpp("Projection2", "Projection2", "Projection2Addition.stcpp", true);
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testCpp("TupleProjection2", "TupleProjection2", "TupleProjection2Addition.stcpp", true);
    }

    @Test
    public void testAppend() throws Exception {
        testCpp("Append", "Append", "AppendAddition.stcpp", true);
    }


    @Test
    public void testConc() throws Exception {
        testCpp("Conc", "Conc", "ConcAddition.stcpp", true);
    }

    @Test
    public void testConcat() throws Exception {
        testCpp("Concat", "Concat", "ConcatAddition.stcpp", true);
    }

    @Test
    public void testDrop() throws Exception {
        testCpp("Drop", "Drop", "DropAddition.stcpp", true);
    }

    @Test
    public void testEmptySequence() throws Exception {
        testCpp("EmptySequence", "EmptySequence", "EmptySequenceAddition.stcpp", true);
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testCpp("EnumeratedSequence");
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testCpp("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stcpp", true);
    }

    @Test
    public void testFrontSequence() throws Exception {
        testCpp("FrontSequence", "FrontSequence", "FrontSequenceAddition.stcpp", true);
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testCpp("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stcpp", true);
    }

    @Test
    public void testPrepend() throws Exception {
        testCpp("Prepend", "Prepend", "PrependAddition.stcpp", true);
    }

    @Test
    public void testReverse() throws Exception {
        testCpp("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stcpp", true);
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testCpp("SizeOfSequence");
    }

    @Test
    public void testTailSequence() throws Exception {
        testCpp("TailSequence", "TailSequence", "TailSequenceAddition.stcpp", true);
    }

    @Test
    public void testTake() throws Exception {
        testCpp("Take", "Take", "TakeAddition.stcpp", true);
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testCpp("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stcpp", true);
    }

    @Test
    public void testPred() throws Exception {
        testCpp("Pred", "Pred", "PredAddition.stcpp", true);
    }

    @Test
    public void testSucc() throws Exception {
        testCpp("Succ", "Succ", "SuccAddition.stcpp", true);
    }

    @Test
    public void testIterate() throws Exception {
        testCpp("Iterate", "Iterate", "IterateAddition.stcpp", true);
    }

    @Test
    public void testClosure() throws Exception {
        testCpp("Closure", "Closure", "ClosureAddition.stcpp", true);
    }

    @Test
    public void testClosure1() throws Exception {
        testCpp("Closure1", "Closure1", "Closure1Addition.stcpp", true);
    }

    @Test
    public void testFnc() throws Exception {
        testCpp("Fnc", "Fnc", "FncAddition.stcpp", true);
    }

    @Test
    public void testRel() throws Exception {
        testCpp("Rel", "Rel", "RelAddition.stcpp", true);
    }
}
