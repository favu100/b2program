package de.hhu.stups.codegenerator.rust;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestOperators extends TestRS {

    @Test
    public void testAnd() throws Exception {
        testRS("And", "And", "AndAddition.strs", true);
    }

    @Test
    public void testCard() throws Exception {
        testRS("Card", "Card", "CardAddition.strs", true);
    }

    @Test
    public void testDifference() throws Exception {
        testRS("Difference", "Difference", "DifferenceAddition.strs", true);
    }

    @Test
    public void testDivide() throws Exception {
        testRS("Divide", "Divide", "DivideAddition.strs", true);
    }

    @Test
    public void testDomain() throws Exception {
        testRS("Domain", "Domain", "DomainAddition.strs", true);
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testRS("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.strs", true);
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testRS("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.strs", true);
    }

    @Test
    public void testElementOf() throws Exception {
        testRS("ElementOf", "ElementOf", "ElementOfAddition.strs", true);
    }

    @Test
    public void testEmptySet() throws Exception {
        testRS("EmptySet", "EmptySet", "EmptySetAddition.strs", true);
    }

    @Test
    public void testEqual() throws Exception {
        testRS("Equal", "Equal", "EqualAddition.strs", true);
    }

    @Test
    public void testEquivalent() throws Exception {
        testRS("Equivalent", "Equivalent", "EquivalentAddition.strs", true);
    }

    @Test
    public void testGreater() throws Exception {
        testRS("Greater", "Greater", "GreaterAddition.strs", true);
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testRS("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.strs", true);
    }

    @Test
    public void testImplies() throws Exception {
        testRS("Implies", "Implies", "ImpliesAddition.strs", true);
    }

    @Test
    public void testIntersection() throws Exception {
        testRS("Intersection", "Intersection", "IntersectionAddition.strs", true);
    }

    @Test
    public void testInterval() throws Exception {
        testRS("Interval", "Interval", "IntervalAddition.strs", true);
    }

    @Test
    public void testInverse() throws Exception {
        testRS("Inverse", "Inverse", "InverseAddition.strs", true);
    }

    @Test
    public void testLess() throws Exception {
        testRS("Less", "Less", "LessAddition.strs", true);
    }

    @Test
    public void testLessEqual() throws Exception {
        testRS("LessEqual", "LessEqual", "LessEqualAddition.strs", true);
    }

    @Test
    public void testMax() throws Exception {
        testRS("Max", "Max", "MaxAddition.strs", true);
    }

    @Test
    public void testMin() throws Exception {
        testRS("Min", "Min", "MinAddition.strs", true);
    }

    @Test
    public void testMinus() throws Exception {
        testRS("Minus", "Minus", "MinusAddition.strs", true);
    }

    @Test
    public void testModulo() throws Exception {
        testRS("Modulo", "Modulo", "ModuloAddition.strs", true);
    }

    @Test
    public void testMultiply() throws Exception {
        testRS("Multiply", "Multiply", "MultiplyAddition.strs", true);
    }
    @Test
    public void testNot() throws Exception {
        testRS("Not", "Not", "NotAddition.strs", true);
    }

    @Test
    public void testNotElementOf() throws Exception {
        testRS("NotElementOf", "NotElementOf", "NotElementOfAddition.strs", true);
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testRS("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.strs", true);
    }

    @Test
    public void testNotSubset() throws Exception {
        testRS("NotSubset", "NotSubset", "NotSubsetAddition.strs", true);
    }

    @Test
    public void testOr() throws Exception {
        testRS("Or", "Or", "OrAddition.strs", true);
    }

    @Test
    public void testPlus2() throws Exception {
        testRS("Plus", "Plus", "PlusAddition.strs", true);
    }

    @Test
    public void testRange() throws Exception {
        testRS("Range", "Range", "RangeAddition.strs", true);
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testRS("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.strs", true);
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testRS("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.strs", true);
    }

    @Test
    public void testRelationalImage() throws Exception {
        testRS("RelationalImage", "RelationalImage", "RelationalImageAddition.strs", true);
    }

    @Test
    public void testStrictSubset() throws Exception {
        testRS("StrictSubset", "StrictSubset", "StrictSubsetAddition.strs", true);
    }

    @Test
    public void testSubset() throws Exception {
        testRS("Subset", "Subset", "SubsetAddition.strs", true);
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testRS("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.strs", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testRS("Unequal", "Unequal", "UnequalAddition.strs", true);
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testRS("GeneralizedUnion", "GeneralizedUnion", "GeneralizedUnionAddition.strs", true);
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testRS("GeneralizedUnionEmpty", "GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.strs", true);
    }

    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testRS("RelationGeneralizedUnion", "RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.strs", true);
    }

    @Test
    public void testRelationGeneralizedUnionEmpty() throws Exception {
        testRS("RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmptyAddition.strs", true);
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testRS("RelationGeneralizedIntersection", "RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.strs", true);
    }

    @Test
    public void testRelationGeneralizedIntersectionEmpty() throws Exception {
        testRS("RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmptyAddition.strs", true);
    }


    @Test
    public void testGeneralizedIntersection() throws Exception {
        testRS("GeneralizedIntersection", "GeneralizedIntersection", "GeneralizedIntersectionAddition.strs", true);
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testRS("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.strs", true);
    }


    @Test
    public void testFunctionalOverride() throws Exception {
        testRS("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.strs", true);
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testRS("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.strs", true);
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testRS("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.strs", true);
    }

    @Test
    public void testOverride() throws Exception {
        testRS("Override", "Override", "OverrideAddition.strs", true);
    }

    @Test
    public void testPow() throws Exception {
        testRS("Pow", "Pow", "PowAddition.strs", true);
    }

    @Test
    public void testRelationPow() throws Exception {
        testRS("RelationPow", "RelationPow", "RelationPowAddition.strs", true);
    }

    @Test
    public void testRelationPow1() throws Exception {
        testRS("RelationPow1", "RelationPow1", "RelationPow1Addition.strs", true);
    }

    @Test
    public void testPow1() throws Exception {
        testRS("Pow1", "Pow1", "Pow1Addition.strs", true);
    }

    @Test
    public void testFin() throws Exception {
        testRS("Fin", "Fin", "FinAddition.strs", true);
    }

    @Test
    public void testFin1() throws Exception {
        testRS("Fin1", "Fin1", "Fin1Addition.strs", true);
    }

    @Test
    public void testId() throws Exception {
        testRS("Id", "Id", "IdAddition.strs", true);
    }

    @Test
    public void testParallelProduct() throws Exception {
        testRS("ParallelProduct", "ParallelProduct", "ParallelProductAddition.strs", true);
    }

    @Test
    public void testDirectProduct() throws Exception {
        testRS("DirectProduct", "DirectProduct", "DirectProductAddition.strs", true);
    }

    @Test
    public void testComposition() throws Exception {
        testRS("Composition", "Composition", "CompositionAddition.strs", true);
    }

    @Test
    public void testProjection1() throws Exception {
        testRS("Projection1", "Projection1", "Projection1Addition.strs", true);
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testRS("TupleProjection1", "TupleProjection1", "TupleProjection1Addition.strs", true);
    }

    @Test
    public void testProjection2() throws Exception {
        testRS("Projection2", "Projection2", "Projection2Addition.strs", true);
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testRS("TupleProjection2", "TupleProjection2", "TupleProjection2Addition.strs", true);
    }

    @Test
    public void testAppend() throws Exception {
        testRS("Append", "Append", "AppendAddition.strs", true);
    }


    @Test
    public void testConc() throws Exception {
        testRS("Conc", "Conc", "ConcAddition.strs", true);
    }

    @Test
    public void testConcat() throws Exception {
        testRS("Concat", "Concat", "ConcatAddition.strs", true);
    }

    @Test
    public void testDrop() throws Exception {
        testRS("Drop", "Drop", "DropAddition.strs", true);
    }

    @Test
    public void testEmptySequence() throws Exception {
        testRS("EmptySequence", "EmptySequence", "EmptySequenceAddition.strs", true);
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testRS("EnumeratedSequence");
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testRS("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.strs", true);
    }

    @Test
    public void testFrontSequence() throws Exception {
        testRS("FrontSequence", "FrontSequence", "FrontSequenceAddition.strs", true);
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testRS("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.strs", true);
    }

    @Test
    public void testPrepend() throws Exception {
        testRS("Prepend", "Prepend", "PrependAddition.strs", true);
    }

    @Test
    public void testReverse() throws Exception {
        testRS("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.strs", true);
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testRS("SizeOfSequence");
    }

    @Test
    public void testTailSequence() throws Exception {
        testRS("TailSequence", "TailSequence", "TailSequenceAddition.strs", true);
    }

    @Test
    public void testTake() throws Exception {
        testRS("Take", "Take", "TakeAddition.strs", true);
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testRS("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.strs", true);
    }

    @Test
    public void testPred() throws Exception {
        testRS("Pred", "Pred", "PredAddition.strs", true);
    }

    @Test
    public void testSucc() throws Exception {
        testRS("Succ", "Succ", "SuccAddition.strs", true);
    }

    @Test
    public void testIterate() throws Exception {
        testRS("Iterate", "Iterate", "IterateAddition.strs", true);
    }

    @Test
    public void testClosure() throws Exception {
        testRS("Closure", "Closure", "ClosureAddition.strs", true);
    }

    @Test
    public void testClosure1() throws Exception {
        testRS("Closure1", "Closure1", "Closure1Addition.strs", true);
    }

    @Test
    public void testFnc() throws Exception {
        testRS("Fnc", "Fnc", "FncAddition.strs", true);
    }

    @Test
    public void testRel() throws Exception {
        testRS("Rel", "Rel", "RelAddition.strs", true);
    }
}
