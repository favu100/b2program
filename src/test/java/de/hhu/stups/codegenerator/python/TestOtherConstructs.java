package de.hhu.stups.codegenerator.python;

import org.junit.Test;

public class TestOtherConstructs extends TestPython {

    @Test
    public void testWhile() throws Exception {
        testPython("While", "While", "WhileAddition.stpy", true);
    }

    @Test
    public void testEquivalence() throws Exception {
        testPython("Equivalence", "Equivalence", "EquivalenceAddition.stpy", true);
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testPython("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stpy", true);
    }

    @Test
    public void testNondeterminism() throws Exception {
        testPython("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stpy", true);
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testPython("Nondeterminism2", "Nondeterminism2", "Nondeterminism2Addition.stpy", true);
    }

    @Test
    public void testMapFunction() throws Exception {
        testPython("MapFunction", "MapFunction", "MapFunctionAddition.stpy", true);
    }

    @Test
    public void testSetUnion() throws Exception {
        testPython("SetUnion");
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testPython("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stpy", true);
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testPython("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stpy", true);
    }

    @Test
    public void testAssert() throws Exception {
        testPython("Assert");
    }

    @Test
    public void testChoice() throws Exception {
        testPython("Choice", "Choice", "ChoiceAddition.stpy", true);
    }

    @Test
    public void testDanglingElse() throws Exception {
        testPython("DanglingElse", "DanglingElse", "DanglingElseAddition.stpy", true);
    }


    @Test
    public void testIfAndPredicates() throws Exception {
        testPython("IfAndPredicates");
    }

    @Test
    public void testNameCollision() throws Exception {
        testPython("NameCollision", "NameCollision", "NameCollisionAddition.stpy", true);
    }

    @Test
    public void testSwap() throws Exception {
        testPython("Swap", "Swap", "SwapAddition.stpy", true);
    }


    @Test
    public void testSwap2() throws Exception {
        testPython("Swap2", "Swap2", "Swap2Addition.stpy", true);
    }

    @Test
    public void testUnion() throws Exception {
        testPython("Union", "Union", "UnionAddition.stpy", true);
    }

    @Test
    public void testIfExpression() throws Exception {
        testPython("IfExpression", "IfExpression", "IfExpressionAddition.stpy", true);
    }

    @Test
    public void testIfPredicate() throws Exception {
        testPython("IfPredicate", "IfPredicate", "IfPredicateAddition.stpy", true);
    }


    @Test
    public void testRecords() throws Exception {
        testPython("Records");
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testPython("RecordsAccess");
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testPython("RecordsAccess2");
    }

    @Test
    public void testRecordsAccess3() throws Exception {
        testPython("RecordsAccess3", "RecordsAccess3", "RecordsAccess3.stpy", true);
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testPython("RecordAccessNested", "RecordAccessNested", "RecordAccessNested.stpy", true);
    }

    @Test
    public void testRecordAccessNested2() throws Exception {
        testPython("RecordAccessNested2", "RecordAccessNested2", "RecordAccessNested2.stpy", true);
    }

    @Test
    public void testRecordAccessNested3() throws Exception {
        testPython("RecordAccessNested3", "RecordAccessNested3", "RecordAccessNested3.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testPython("FunctionCallAccessNested", "FunctionCallAccessNested", "FunctionCallAccessNested.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testPython("FunctionCallAccessNested2", "FunctionCallAccessNested2", "FunctionCallAccessNested2.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testPython("FunctionCallAccessNested3", "FunctionCallAccessNested3", "FunctionCallAccessNested3.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested4() throws Exception {
        testPython("FunctionCallAccessNested4", "FunctionCallAccessNested4", "FunctionCallAccessNested4.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested5() throws Exception {
        testPython("FunctionCallAccessNested5", "FunctionCallAccessNested5", "FunctionCallAccessNested5.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested6() throws Exception {
        testPython("FunctionCallAccessNested6", "FunctionCallAccessNested6", "FunctionCallAccessNested6.stpy", true);
    }

    @Test
    public void testFunctionCallAccessNested7() throws Exception {
        testPython("FunctionCallAccessNested7", "FunctionCallAccessNested7", "FunctionCallAccessNested7.stpy", true);
    }

    @Test
    public void testDeferredSet() throws Exception {
        testPython("DeferredSet");
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testPython("DeferredSet2");
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testPython("DeferredSet3");
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testPython("DeferredSet4");
    }

}
