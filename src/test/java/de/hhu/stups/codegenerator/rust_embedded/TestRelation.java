package de.hhu.stups.codegenerator.rust_embedded;

import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestRelation extends TestRSE {
    public TestRelation() throws URISyntaxException, IOException {}

    @Test
    public void testDomain() throws Exception {
        testRSE("Domain", "DomainAddition.strs");
    }

    @Test
    public void testRange() throws Exception {
        testRSE("Range", "RangeAddition.strs");
    }

    @Test
    public void testId() throws Exception {
        testRSE("Id", "IdAddition.strs");
    }

    @Test
    public void testDomainRestriction() throws Exception {
        testRSE("DomainRestriction", "DomainRestrictionAddition.strs");
    }

    @Test
    public void testDomainSubstraction() throws Exception {
        testRSE("DomainSubstraction", "DomainSubstractionAddition.strs");
    }

    @Test
    public void testRangeRestriction() throws Exception {
        testRSE("RangeRestriction", "RangeRestrictionAddition.strs");
    }

    @Test
    public void testRangeSubstraction() throws Exception {
        testRSE("RangeSubstraction", "RangeSubstractionAddition.strs");
    }

    @Test
    public void testInverse() throws Exception {
        testRSE("Inverse", "InverseAddition.strs");
    }

    @Test
    public void testRelationalImage() throws Exception {
        testRSE("RelationalImage", "RelationalImageAddition.strs");
    }

    @Test // relational override/ r1<+r2
    public void testOverride() throws Exception {
        testRSE("Override", "OverrideAddition.strs");
    }

    @Test(expected = RuntimeException.class) // SetItem is not implemented for Tuples (yet)
    public void testDirectProduct() throws Exception {
        testRSE("DirectProduct", "DirectProductAddition.strs");
    }

    @Test
    public void testComposition() throws Exception {
        testRSE("Composition", "CompositionAddition.strs");
    }

    @Test(expected = RuntimeException.class) // SetItem is not implemented for Tuples (yet)
    public void testParallelProduct() throws Exception {
        testRSE("ParallelProduct", "ParallelProductAddition.strs");
    }

    @Test(expected = RuntimeException.class) // SetItem is not implemented for Tuples (yet)
    public void testProjection1() throws Exception {
        testRSE("Projection1", "Projection1Addition.strs");
    }

    @Test(expected = RuntimeException.class) // SetItem is not implemented for Tuples (yet)
    public void testProjection2() throws Exception {
        testRSE("Projection2", "Projection2Addition.strs");
    }

    @Test
    public void testClosure1() throws Exception {
        testRSE("Closure1", "Closure1Addition.strs");
    }

    @Test
    public void testClosure() throws Exception {
        testRSE("Closure", "ClosureAddition.strs");
    }

    @Test
    public void testIterate() throws Exception {
        testRSE("Iterate", "IterateAddition.strs");
    }

    @Test
    public void testFnc() throws Exception {
        testRSE("Fnc", "FncAddition.strs");
    }

    @Test(expected = RuntimeException.class) // currently difficult to implement in Rust...
    public void testRel() throws Exception {
        testRSE("Rel", "RelAddition.strs");
    }



    @Test
    public void testRelationGeneralizedUnion() throws Exception {
        testRSE("RelationGeneralizedUnion", "RelationGeneralizedUnionAddition.strs");
    }

    @Test
    public void testRelationGeneralizedUnionEmpty() throws Exception {
        testRSE("RelationGeneralizedUnionEmpty", "RelationGeneralizedUnionEmptyAddition.strs");
    }

    @Test
    public void testRelationGeneralizedIntersection() throws Exception {
        testRSE("RelationGeneralizedIntersection", "RelationGeneralizedIntersectionAddition.strs");
    }

    @Test
    public void testRelationGeneralizedIntersectionEmpty() throws Exception {
        testRSE("RelationGeneralizedIntersectionEmpty", "RelationGeneralizedIntersectionEmptyAddition.strs");
    }

    @Test
    public void testFunctionalOverride() throws Exception {
        testRSE("FunctionalOverride", "FunctionalOverrideAddition.strs");
    }

    @Test
    public void testFunctionalOverride2() throws Exception {
        testRSE("FunctionalOverride2", "FunctionalOverride2Addition.strs");
    }

    @Test
    public void testFunctionalOverride3() throws Exception {
        testRSE("FunctionalOverride3", "FunctionalOverride3Addition.strs");
    }

    @Test
    public void testRelationPow() throws Exception {
        testRSE("RelationPow", "RelationPowAddition.strs");
    }

    @Test
    public void testRelationPow1() throws Exception {
        testRSE("RelationPow1", "RelationPow1Addition.strs");
    }

    @Test
    public void testTupleProjection1() throws Exception {
        testRSE("TupleProjection1", "TupleProjection1Addition.strs");
    }

    @Test
    public void testTupleProjection2() throws Exception {
        testRSE("TupleProjection2", "TupleProjection2Addition.strs");
    }



    @Test
    public void testTake() throws Exception {
        testRSE("Take", "TakeAddition.strs");
    }

    @Test
    public void testAppend() throws Exception {
        testRSE("Append", "AppendAddition.strs");
    }

    @Test
    public void testConc() throws Exception {
        testRSE("Conc", "ConcAddition.strs");
    }

    @Test
    public void testConcat() throws Exception {
        testRSE("Concat", "ConcatAddition.strs");
    }

    @Test
    public void testDrop() throws Exception {
        testRSE("Drop", "DropAddition.strs");
    }

    @Test
    public void testEmptySequence() throws Exception {
        testRSE("EmptySequence", "EmptySequenceAddition.strs");
    }

    @Test
    public void testEnumeratedSequence() throws Exception {
        testRSE("EnumeratedSequence", null);
    }

    @Test
    public void testFirstElementSequence() throws Exception {
        testRSE("FirstElementSequence", "FirstElementSequenceAddition.strs");
    }

    @Test
    public void testFrontSequence() throws Exception {
        testRSE("FrontSequence", "FrontSequenceAddition.strs");
    }

    @Test
    public void testLastElementSequence() throws Exception {
        testRSE("LastElementSequence", "LastElementSequenceAddition.strs");
    }

    @Test
    public void testPrepend() throws Exception {
        testRSE("Prepend", "PrependAddition.strs");
    }

    @Test
    public void testReverse() throws Exception {
        testRSE("ReverseSequence", "ReverseSequenceAddition.strs");
    }

    @Test
    public void testSizeOfSequence() throws Exception {
        testRSE("SizeOfSequence", null);
    }

    @Test
    public void testTailSequence() throws Exception {
        testRSE("TailSequence", "TailSequenceAddition.strs");
    }

    @Test
    public void testSequenceOperateRelation() throws Exception {
        testRSE("SequenceOperateRelation", "SequenceOperateRelationAddition.strs");
    }
}
