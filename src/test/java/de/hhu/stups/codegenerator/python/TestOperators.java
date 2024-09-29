package de.hhu.stups.codegenerator.python;

import org.junit.Ignore;
import org.junit.Test;

@Ignore
public class TestOperators extends TestPython {

    @Test
    public void testAnd() throws Exception {
        testPython("And", "And", "AndAddition.stpy", true);
    }

    @Test
    public void testCard() throws Exception {
        testPython("Card", "Card", "CardAddition.stpy", true);
    }

    @Test
    public void testDifference() throws Exception {
        testPython("Difference", "Difference", "DifferenceAddition.stpy", true);
    }

    @Test
    public void testDivide() throws Exception {
        testPython("Divide", "Divide", "DivideAddition.stpy", true);
    }

    @Test
    public void testDomain() throws Exception {
        testPython("Domain", "Domain", "DomainAddition.stpy", true);
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testPython("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stpy", true);
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testPython("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stpy", true);
    }

    @Test
    public void testElementOf() throws Exception {
        testPython("ElementOf", "ElementOf", "ElementOfAddition.stpy", true);
    }

    @Test
    public void testEmptySet() throws Exception {
        testPython("EmptySet", "EmptySet", "EmptySetAddition.stpy", true);
    }

    @Test
    public void testEqual() throws Exception {
        testPython("Equal", "Equal", "EqualAddition.stpy", true);
    }

    @Test
    public void testEquivalent() throws Exception {
        testPython("Equivalent", "Equivalent", "EquivalentAddition.stpy", true);
    }

    @Test
    public void testGreater() throws Exception {
        testPython("Greater", "Greater", "GreaterAddition.stpy", true);
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testPython("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stpy", true);
    }

    @Test
    public void testImplies() throws Exception {
        testPython("Implies", "Implies", "ImpliesAddition.stpy", true);
    }

    @Test
    public void testIntersection() throws Exception {
        testPython("Intersection", "Intersection", "IntersectionAddition.stpy", true);
    }

    @Test
    public void testInterval() throws Exception {
        testPython("Interval", "Interval", "IntervalAddition.stpy", true);
    }

    @Test
    public void testInverse() throws Exception {
        testPython("Inverse", "Inverse", "InverseAddition.stpy", true);
    }

    @Test
    public void testLess() throws Exception {
        testPython("Less", "Less", "LessAddition.stpy", true);
    }

    @Test
    public void testLessEqual() throws Exception {
        testPython("LessEqual", "LessEqual", "LessEqualAddition.stpy", true);
    }

    @Test
    public void testMax() throws Exception {
        testPython("Max", "Max", "MaxAddition.stpy", true);
    }

    @Test
    public void testMin() throws Exception {
        testPython("Min", "Min", "MinAddition.stpy", true);
    }

    @Test
    public void testMinus() throws Exception {
        testPython("Minus", "Minus", "MinusAddition.stpy", true);
    }

    @Test
    public void testModulo() throws Exception {
        testPython("Modulo", "Modulo", "ModuloAddition.stpy", true);
    }

    @Test
    public void testMultiply() throws Exception {
        testPython("Multiply", "Multiply", "MultiplyAddition.stpy", true);
    }
    @Test
    public void testNot() throws Exception {
        testPython("Not", "Not", "NotAddition.stpy", true);
    }

    @Test
    public void testNotElementOf() throws Exception {
        testPython("NotElementOf", "NotElementOf", "NotElementOfAddition.stpy", true);
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testPython("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stpy", true);
    }

    @Test
    public void testNotSubset() throws Exception {
        testPython("NotSubset", "NotSubset", "NotSubsetAddition.stpy", true);
    }

    @Test
    public void testOr() throws Exception {
        testPython("Or", "Or", "OrAddition.stpy", true);
    }

    @Test
    public void testPlus2() throws Exception {
        testPython("Plus", "Plus", "PlusAddition.stpy", true);
    }

    @Test
    public void testRange() throws Exception {
        testPython("Range", "Range", "RangeAddition.stpy", true);
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testPython("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stpy", true);
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testPython("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stpy", true);
    }

    @Test
    public void testRelationalImage() throws Exception {
        testPython("RelationalImage", "RelationalImage", "RelationalImageAddition.stpy", true);
    }

    @Test
    public void testStrictSubset() throws Exception {
        testPython("StrictSubset", "StrictSubset", "StrictSubsetAddition.stpy", true);
    }

    @Test
    public void testSubset() throws Exception {
        testPython("Subset", "Subset", "SubsetAddition.stpy", true);
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testPython("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stpy", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testPython("Unequal", "Unequal", "UnequalAddition.stpy", true);
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testPython("GeneralizedUnion", "GeneralizedUnion", "GeneralizedUnionAddition.stpy", true);
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testPython("GeneralizedUnionEmpty", "GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.stpy", true);
    }

    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testPython("RelationGeneralizedUnion", "RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.stpy", true);
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testPython("RelationGeneralizedIntersection", "RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.stpy", true);
    }


    @Test
    public void testGeneralizedIntersection() throws Exception {
        testPython("GeneralizedIntersection", "GeneralizedIntersection", "GeneralizedIntersectionAddition.stpy", true);
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testPython("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.stpy", true);
    }


    @Test
    public void testFunctionalOverride() throws Exception {
        testPython("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stpy", true);
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testPython("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stpy", true);
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testPython("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stpy", true);
    }

    @Test
    public void testOverride() throws Exception {
        testPython("Override", "Override", "OverrideAddition.stpy", true);
    }

    @Test
    public void testPow() throws Exception {
        testPython("Pow", "Pow", "PowAddition.stpy", true);
    }

    @Test
    public void testRelationPow() throws Exception {
        testPython("RelationPow", "RelationPow", "RelationPowAddition.stpy", true);
    }

    @Test
    public void testRelationPow1() throws Exception {
        testPython("RelationPow1", "RelationPow1", "RelationPow1Addition.stpy", true);
    }

    @Test
    public void testPow1() throws Exception {
        testPython("Pow1", "Pow1", "Pow1Addition.stpy", true);
    }

    @Test
    public void testFin() throws Exception {
        testPython("Fin", "Fin", "FinAddition.stpy", true);
    }

    @Test
    public void testFin1() throws Exception {
        testPython("Fin1", "Fin1", "Fin1Addition.stpy", true);
    }

    @Test
    public void testId() throws Exception {
        testPython("Id", "Id", "IdAddition.stpy", true);
    }

    @Test
    public void testParallelProduct() throws Exception {
        testPython("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stpy", true);
    }

    @Test
    public void testDirectProduct() throws Exception {
        testPython("DirectProduct", "DirectProduct", "DirectProductAddition.stpy", true);
    }

    @Test
    public void testComposition() throws Exception {
        testPython("Composition", "Composition", "CompositionAddition.stpy", true);
    }

    @Test
    public void testProjection1() throws Exception {
        testPython("Projection1", "Projection1", "Projection1Addition.stpy", true);
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testPython("TupleProjection1", "TupleProjection1", "TupleProjection1Addition.stpy", true);
    }

    @Test
    public void testProjection2() throws Exception {
        testPython("Projection2", "Projection2", "Projection2Addition.stpy", true);
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testPython("TupleProjection2", "TupleProjection2", "TupleProjection2Addition.stpy", true);
    }

    @Test
    public void testAppend() throws Exception {
        testPython("Append", "Append", "AppendAddition.stpy", true);
    }


    @Test
    public void testConc() throws Exception {
        testPython("Conc", "Conc", "ConcAddition.stpy", true);
    }

    @Test
    public void testConcat() throws Exception {
        testPython("Concat", "Concat", "ConcatAddition.stpy", true);
    }

    @Test
    public void testDrop() throws Exception {
        testPython("Drop", "Drop", "DropAddition.stpy", true);
    }

    @Test
    public void testEmptySequence() throws Exception {
        testPython("EmptySequence", "EmptySequence", "EmptySequenceAddition.stpy", true);
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testPython("EnumeratedSequence");
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testPython("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stpy", true);
    }

    @Test
    public void testFrontSequence() throws Exception {
        testPython("FrontSequence", "FrontSequence", "FrontSequenceAddition.stpy", true);
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testPython("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stpy", true);
    }

    @Test
    public void testPrepend() throws Exception {
        testPython("Prepend", "Prepend", "PrependAddition.stpy", true);
    }

    @Test
    public void testReverse() throws Exception {
        testPython("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stpy", true);
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testPython("SizeOfSequence");
    }

    @Test
    public void testTailSequence() throws Exception {
        testPython("TailSequence", "TailSequence", "TailSequenceAddition.stpy", true);
    }

    @Test
    public void testTake() throws Exception {
        testPython("Take", "Take", "TakeAddition.stpy", true);
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testPython("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stpy", true);
    }

    @Test
    public void testPred() throws Exception {
        testPython("Pred", "Pred", "PredAddition.stpy", true);
    }

    @Test
    public void testSucc() throws Exception {
        testPython("Succ", "Succ", "SuccAddition.stpy", true);
    }

    @Test
    public void testIterate() throws Exception {
        testPython("Iterate", "Iterate", "IterateAddition.stpy", true);
    }

    @Test
    public void testClosure() throws Exception {
        testPython("Closure", "Closure", "ClosureAddition.stpy", true);
    }

    @Test
    public void testClosure1() throws Exception {
        testPython("Closure1", "Closure1", "Closure1Addition.stpy", true);
    }

    @Test
    public void testFnc() throws Exception {
        testPython("Fnc", "Fnc", "FncAddition.stpy", true);
    }

    @Test
    public void testRel() throws Exception {
        testPython("Rel", "Rel", "RelAddition.stpy", true);
    }
}
