package de.hhu.stups.codegenerator.js;

import de.hhu.stups.codegenerator.generators.CodeGenerationException;
import org.junit.Test;

public class TestOperators extends TestJs {

    @Test
    public void testAnd() throws Exception {
        testJs("And", "And", "AndAddition.stjs", true);
    }

    @Test
    public void testCard() throws Exception {
        testJs("Card", "Card", "CardAddition.stjs", true);
    }

    @Test
    public void testDifference() throws Exception {
        testJs("Difference", "Difference", "DifferenceAddition.stjs", true);
    }

    @Test
    public void testDivide() throws Exception {
        testJs("Divide", "Divide", "DivideAddition.stjs", true);
    }

    @Test
    public void testDomain() throws Exception {
        testJs("Domain", "Domain", "DomainAddition.stjs", true);
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testJs("DomainRestriction", "DomainRestriction", "DomainRestrictionAddition.stjs", true);
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testJs("DomainSubstraction", "DomainSubstraction", "DomainSubstractionAddition.stjs", true);
    }

    @Test
    public void testElementOf() throws Exception {
        testJs("ElementOf", "ElementOf", "ElementOfAddition.stjs", true);
    }

    @Test
    public void testEmptySet() throws Exception {
        testJs("EmptySet", "EmptySet", "EmptySetAddition.stjs", true);
    }

    @Test
    public void testEqual() throws Exception {
        testJs("Equal", "Equal", "EqualAddition.stjs", true);
    }

    @Test
    public void testEquivalent() throws Exception {
        testJs("Equivalent", "Equivalent", "EquivalentAddition.stjs", true);
    }

    @Test
    public void testGreater() throws Exception {
        testJs("Greater", "Greater", "GreaterAddition.stjs", true);
    }

    @Test
    public void testGreaterEqual() throws Exception {
        testJs("GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjs", true);
    }

    @Test
    public void testImplies() throws Exception {
        testJs("Implies", "Implies", "ImpliesAddition.stjs", true);
    }

    @Test
    public void testIntersection() throws Exception {
        testJs("Intersection", "Intersection", "IntersectionAddition.stjs", true);
    }

    @Test
    public void testInterval() throws Exception {
        testJs("Interval", "Interval", "IntervalAddition.stjs", true);
    }

    @Test
    public void testInverse() throws Exception {
        testJs("Inverse", "Inverse", "InverseAddition.stjs", true);
    }

    @Test
    public void testLess() throws Exception {
        testJs("Less", "Less", "LessAddition.stjs", true);
    }

    @Test
    public void testLessEqual() throws Exception {
        testJs("LessEqual", "LessEqual", "LessEqualAddition.stjs", true);
    }

    @Test
    public void testMax() throws Exception {
        testJs("Max", "Max", "MaxAddition.stjs", true);
    }

    @Test
    public void testMin() throws Exception {
        testJs("Min", "Min", "MinAddition.stjs", true);
    }

    @Test
    public void testMinus() throws Exception {
        testJs("Minus", "Minus", "MinusAddition.stjs", true);
    }

    @Test
    public void testModulo() throws Exception {
        testJs("Modulo", "Modulo", "ModuloAddition.stjs", true);
    }

    @Test
    public void testMultiply() throws Exception {
        testJs("Multiply", "Multiply", "MultiplyAddition.stjs", true);
    }
    @Test
    public void testNot() throws Exception {
        testJs("Not", "Not", "NotAddition.stjs", true);
    }

    @Test
    public void testNotElementOf() throws Exception {
        testJs("NotElementOf", "NotElementOf", "NotElementOfAddition.stjs", true);
    }

    @Test
    public void testNotStrictSubset() throws Exception {
        testJs("NotStrictSubset", "NotStrictSubset", "NotStrictSubsetAddition.stjs", true);
    }

    @Test
    public void testNotSubset() throws Exception {
        testJs("NotSubset", "NotSubset", "NotSubsetAddition.stjs", true);
    }

    @Test
    public void testOr() throws Exception {
        testJs("Or", "Or", "OrAddition.stjs", true);
    }

    @Test
    public void testPlus2() throws Exception {
        testJs("Plus", "Plus", "PlusAddition.stjs", true);
    }

    @Test
    public void testRange() throws Exception {
        testJs("Range", "Range", "RangeAddition.stjs", true);
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testJs("RangeRestriction", "RangeRestriction", "RangeRestrictionAddition.stjs", true);
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testJs("RangeSubstraction", "RangeSubstraction", "RangeSubstractionAddition.stjs", true);
    }

    @Test
    public void testRelationalImage() throws Exception {
        testJs("RelationalImage", "RelationalImage", "RelationalImageAddition.stjs", true);
    }

    @Test
    public void testStrictSubset() throws Exception {
        testJs("StrictSubset", "StrictSubset", "StrictSubsetAddition.stjs", true);
    }

    @Test
    public void testSubset() throws Exception {
        testJs("Subset", "Subset", "SubsetAddition.stjs", true);
    }

    @Test
    public void testUnaryMinus() throws Exception {
        testJs("UnaryMinus", "UnaryMinus", "UnaryMinusAddition.stjs", true);
    }

    @Test
    public void testUnequal() throws Exception {
        testJs("Unequal", "Unequal", "UnequalAddition.stjs", true);
    }

    @Test
    public void testGeneralizedUnion() throws Exception {
        testJs("GeneralizedUnion", "GeneralizedUnion", "GeneralizedUnionAddition.stjs", true);
    }

    @Test
    public void testGeneralizedUnionEmpty() throws Exception {
        testJs("GeneralizedUnionEmpty", "GeneralizedUnionEmpty", "GeneralizedUnionEmptyAddition.stjs", true);
    }

    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testJs("RelationGeneralizedUnion", "RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.stjs", true);
    }

    @Test
    public void testRelationGeneralizedUnionEmpty() throws Exception {
        testJs("RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmptyAddition.stjs", true);
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testJs("RelationGeneralizedIntersection", "RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.stjs", true);
    }

    @Test
    public void testRelationGeneralizedIntersectionEmpty() throws Exception {
        testJs("RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmptyAddition.stjs", true);
    }


    @Test
    public void testGeneralizedIntersection() throws Exception {
        testJs("GeneralizedIntersection", "GeneralizedIntersection", "GeneralizedIntersectionAddition.stjs", true);
    }

    @Test
    public void testGeneralizedIntersectionEmpty() throws Exception {
        testJs("GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmpty", "GeneralizedIntersectionEmptyAddition.stjs", true);
    }


    @Test
    public void testFunctionalOverride() throws Exception {
        testJs("FunctionalOverride", "FunctionalOverride", "FunctionalOverrideAddition.stjs", true);
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testJs("FunctionalOverride2", "FunctionalOverride2", "FunctionalOverride2Addition.stjs", true);
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testJs("FunctionalOverride3", "FunctionalOverride3", "FunctionalOverride3Addition.stjs", true);
    }

    @Test
    public void testOverride() throws Exception {
        testJs("OOverride", "OOverride", "OverrideAddition.stjs", true);
    }

    @Test
    public void testPow() throws Exception {
        testJs("Pow", "Pow", "PowAddition.stjs", true);
    }

    @Test
    public void testRelationPow() throws Exception {
        testJs("RelationPow", "RelationPow", "RelationPowAddition.stjs", true);
    }

    @Test
    public void testRelationPow1() throws Exception {
        testJs("RelationPow1", "RelationPow1", "RelationPow1Addition.stjs", true);
    }

    @Test
    public void testPow1() throws Exception {
        testJs("Pow1", "Pow1", "Pow1Addition.stjs", true);
    }

    @Test
    public void testFin() throws Exception {
        testJs("Fin", "Fin", "FinAddition.stjs", true);
    }

    @Test
    public void testFin1() throws Exception {
        testJs("Fin1", "Fin1", "Fin1Addition.stjs", true);
    }

    @Test
    public void testId() throws Exception {
        testJs("Id", "Id", "IdAddition.stjs", true);
    }

    @Test
    public void testParallelProduct() throws Exception {
        testJs("ParallelProduct", "ParallelProduct", "ParallelProductAddition.stjs", true);
    }

    @Test
    public void testDirectProduct() throws Exception {
        testJs("DirectProduct", "DirectProduct", "DirectProductAddition.stjs", true);
    }

    @Test
    public void testComposition() throws Exception {
        testJs("Composition", "Composition", "CompositionAddition.stjs", true);
    }

    @Test
    public void testProjection1() throws Exception {
        testJs("Projection1", "Projection1", "Projection1Addition.stjs", true);
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testJs("TupleProjection1", "TupleProjection1", "TupleProjection1Addition.stjs", true);
    }

    @Test
    public void testProjection2() throws Exception {
        testJs("Projection2", "Projection2", "Projection2Addition.stjs", true);
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testJs("TupleProjection2", "TupleProjection2", "TupleProjection2Addition.stjs", true);
    }

    @Test
    public void testAppend() throws Exception {
        testJs("Append", "Append", "AppendAddition.stjs", true);
    }


    @Test
    public void testConc() throws Exception {
        testJs("Conc", "Conc", "ConcAddition.stjs", true);
    }

    @Test
    public void testConcat() throws Exception {
        testJs("Concat", "Concat", "ConcatAddition.stjs", true);
    }

    @Test
    public void testDrop() throws Exception {
        testJs("Drop", "Drop", "DropAddition.stjs", true);
    }

    @Test
    public void testEmptySequence() throws Exception {
        testJs("EmptySequence", "EmptySequence", "EmptySequenceAddition.stjs", true);
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testJs("EnumeratedSequence");
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testJs("FirstElementSequence", "FirstElementSequence", "FirstElementSequenceAddition.stjs", true);
    }

    @Test
    public void testFrontSequence() throws Exception {
        testJs("FrontSequence", "FrontSequence", "FrontSequenceAddition.stjs", true);
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testJs("LastElementSequence", "LastElementSequence", "LastElementSequenceAddition.stjs", true);
    }

    @Test
    public void testPrepend() throws Exception {
        testJs("Prepend", "Prepend", "PrependAddition.stjs", true);
    }

    @Test
    public void testReverse() throws Exception {
        testJs("ReverseSequence", "ReverseSequence", "ReverseSequenceAddition.stjs", true);
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testJs("SizeOfSequence");
    }

    @Test
    public void testTailSequence() throws Exception {
        testJs("TailSequence", "TailSequence", "TailSequenceAddition.stjs", true);
    }

    @Test
    public void testTake() throws Exception {
        testJs("Take", "Take", "TakeAddition.stjs", true);
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testJs("SequenceOperateRelation", "SequenceOperateRelation", "SequenceOperateRelationAddition.stjs", true);
    }

    @Test
    public void testPred() throws Exception {
        testJs("Pred", "Pred", "PredAddition.stjs", true);
    }

    @Test
    public void testSucc() throws Exception {
        testJs("Succ", "Succ", "SuccAddition.stjs", true);
    }

    @Test
    public void testIterate() throws Exception {
        testJs("Iterate", "Iterate", "IterateAddition.stjs", true);
    }

    @Test(expected = CodeGenerationException.class)
    public void testClosure() throws Exception {
        testJs("Closure", "Closure", "ClosureAddition.stjs", true);
    }

    @Test
    public void testClosureBool() throws Exception {
        testJs("ClosureBool", "ClosureBool", "ClosureBoolAddition.stjs", true);
    }

    @Test
    public void testClosure1() throws Exception {
        testJs("Closure1", "Closure1", "Closure1Addition.stjs", true);
    }

    @Test
    public void testFnc() throws Exception {
        testJs("Fnc", "Fnc", "FncAddition.stjs", true);
    }

    @Test
    public void testRel() throws Exception {
        testJs("Rel", "Rel", "RelAddition.stjs", true);
    }
}
