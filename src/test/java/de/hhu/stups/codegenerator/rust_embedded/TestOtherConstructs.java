package de.hhu.stups.codegenerator.rust_embedded;

import de.hhu.stups.codegenerator.rust.TestRS;
import org.junit.Test;

import java.io.IOException;
import java.net.URISyntaxException;

public class TestOtherConstructs extends TestRSE {
    public TestOtherConstructs() throws URISyntaxException, IOException {}

    @Test
    public void testWhile() throws Exception {
        testRSE("While", "WhileAddition.strs");
    }

    @Test
    public void testEquivalence() throws Exception {
        testRSE("Equivalence", "EquivalenceAddition.strs");
    }

    @Test()
    public void testBooleanPredicate() throws Exception {
        testRSE("BooleanPredicate", "BooleanPredicateAddition.strs");
    }

    @Test
    public void testBooleanPredicateWD() throws Exception {
        testRSE("BooleanPredicateWD", "BooleanPredicateAdditionWD.strs");
    }

    @Test
    public void testNondeterminism() throws Exception {
        testRSE("Nondeterminism", "NondeterminismAddition.strs");
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testRSE("Nondeterminism2", "Nondeterminism2Addition.strs");
    }

    @Test
    public void testMapFunction() throws Exception {
        testRSE("MapFunction", "MapFunctionAddition.strs");
    }

    @Test
    public void testSetUnion() throws Exception {
        testRSE("SetUnion", null);
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testRSE("ManyLocalDeclarations", "ManyLocalDeclarationsAddition.strs");
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testRSE("ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.strs");
    }

    @Test
    public void testAssert() throws Exception {
        testRSE("Assert", null);
    }

    @Test
    public void testChoice() throws Exception {
        testRSE("Choice", "ChoiceAddition.strs");
    }

    @Test
    public void testDanglingElseWD() throws Exception {
        testRSE("DanglingElseWD", "DanglingElseAdditionWD.strs");
    }

    @Test
    public void testIfAndPredicates() throws Exception {
        testRSE("IfAndPredicates", "IfAndPredicatesAddition.strs");
    }

    @Test
    public void testNameCollision() throws Exception {
        testRSE("NameCollision", "NameCollisionAddition.strs");
    }

    @Test
    public void testSwap() throws Exception {
        testRSE("Swap", "SwapAddition.strs");
    }


    @Test
    public void testSwap2() throws Exception {
        testRSE("Swap2", "Swap2Addition.strs");
    }

    @Test
    public void testUnion() throws Exception {
        testRSE("Union", "UnionAddition.strs");
    }

    @Test
    public void testIfExpression() throws Exception {
        testRSE("IfExpression", "IfExpressionAddition.strs");
    }

    @Test
    public void testIfPredicate() throws Exception {
        testRSE("IfPredicate", "IfPredicateAddition.strs");
    }


    @Test
    public void testRecords() throws Exception {
        testRSE("Records", null);
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testRSE("RecordsAccess", null);
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testRSE("RecordsAccess2", null);
    }

    @Test
    public void testRecordsAccess3() throws Exception {
        testRSE("RecordsAccess3", "RecordsAccess3.strs");
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testRSE("RecordAccessNested", "RecordAccessNested.strs");
    }

    @Test
    public void testRecordAccessNested2() throws Exception {
        testRSE("RecordAccessNested2", "RecordAccessNested2.strs");
    }

    @Test
    public void testRecordAccessNested3() throws Exception {
        testRSE("RecordAccessNested3", "RecordAccessNested3.strs");
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testRSE("FunctionCallAccessNested", "FunctionCallAccessNested.strs");
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testRSE("FunctionCallAccessNested2", "FunctionCallAccessNested2.strs");
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testRSE("FunctionCallAccessNested3", "FunctionCallAccessNested3.strs");
    }

    @Test
    public void testFunctionCallAccessNested4() throws Exception {
        testRSE("FunctionCallAccessNested4", "FunctionCallAccessNested4.strs");
    }

    @Test
    public void testFunctionCallAccessNested5() throws Exception {
        testRSE("FunctionCallAccessNested5", "FunctionCallAccessNested5.strs");
    }

    @Test
    public void testFunctionCallAccessNested6() throws Exception {
        testRSE("FunctionCallAccessNested6", "FunctionCallAccessNested6.strs");
    }

    @Test
    public void testFunctionCallAccessNested7() throws Exception {
        testRSE("FunctionCallAccessNested7", "FunctionCallAccessNested7.strs");
    }

    @Test
    public void testDeferredSet() throws Exception {
        testRSE("DeferredSet", null);
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testRSE("DeferredSet2", null);
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testRSE("DeferredSet3", null);
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testRSE("DeferredSet4", null);
    }

}
