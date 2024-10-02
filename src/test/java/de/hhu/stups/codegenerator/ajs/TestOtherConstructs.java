package de.hhu.stups.codegenerator.ajs;

import org.junit.Test;

public class TestOtherConstructs extends TestJs {

    @Test
    public void testWhile() throws Exception {
        testJs("While", "While", "WhileAddition.stjs", true);
    }

    @Test
    public void testEquivalence() throws Exception {
        testJs("Equivalence", "Equivalence", "EquivalenceAddition.stjs", true);
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testJs("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stjs", true);
    }

    @Test
    public void testNondeterminism() throws Exception {
        testJs("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stjs", true);
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testJs("Nondeterminism2", "Nondeterminism2", "Nondeterminism2Addition.stjs", true);
    }

    @Test
    public void testMapFunction() throws Exception {
        testJs("MapFunction", "MapFunction", "MapFunctionAddition.stjs", true);
    }

    @Test
    public void testSetUnion() throws Exception {
        testJs("SetUnion");
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testJs("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stjs", true);
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testJs("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stjs", true);
    }

    @Test
    public void testAssert() throws Exception {
        testJs("Assert");
    }

    @Test
    public void testChoice() throws Exception {
        testJs("Choice", "Choice", "ChoiceAddition.stjs", true);
    }

    @Test
    public void testDanglingElse() throws Exception {
        testJs("DanglingElse", "DanglingElse", "DanglingElseAddition.stjs", true);
    }


    @Test
    public void testIfAndPredicates() throws Exception {
        testJs("IfAndPredicates");
    }

    @Test
    public void testNameCollision() throws Exception {
        testJs("NameCollision", "NameCollision", "NameCollisionAddition.stjs", true);
    }

    @Test
    public void testSwap() throws Exception {
        testJs("Swap", "Swap", "SwapAddition.stjs", true);
    }


    @Test
    public void testSwap2() throws Exception {
        testJs("Swap2", "Swap2", "Swap2Addition.stjs", true);
    }

    @Test
    public void testUnion() throws Exception {
        testJs("Union", "Union", "UnionAddition.stjs", true);
    }

    @Test
    public void testIfExpression() throws Exception {
        testJs("IfExpression", "IfExpression", "IfExpressionAddition.stjs", true);
    }

    @Test
    public void testIfPredicate() throws Exception {
        testJs("IfPredicate", "IfPredicate", "IfPredicateAddition.stjs", true);
    }


    @Test
    public void testRecords() throws Exception {
        testJs("Records");
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testJs("RecordsAccess");
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testJs("RecordsAccess2");
    }

    @Test
    public void testRecordsAccess3() throws Exception {
        testJs("RecordsAccess3", "RecordsAccess3", "RecordsAccess3.stjs", true);
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testJs("RecordAccessNested", "RecordAccessNested", "RecordAccessNested.stjs", true);
    }

    @Test
    public void testRecordAccessNested2() throws Exception {
        testJs("RecordAccessNested2", "RecordAccessNested2", "RecordAccessNested2.stjs", true);
    }

    @Test
    public void testRecordAccessNested3() throws Exception {
        testJs("RecordAccessNested3", "RecordAccessNested3", "RecordAccessNested3.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testJs("FunctionCallAccessNested", "FunctionCallAccessNested", "FunctionCallAccessNested.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testJs("FunctionCallAccessNested2", "FunctionCallAccessNested2", "FunctionCallAccessNested2.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testJs("FunctionCallAccessNested3", "FunctionCallAccessNested3", "FunctionCallAccessNested3.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested4() throws Exception {
        testJs("FunctionCallAccessNested4", "FunctionCallAccessNested4", "FunctionCallAccessNested4.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested5() throws Exception {
        testJs("FunctionCallAccessNested5", "FunctionCallAccessNested5", "FunctionCallAccessNested5.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested6() throws Exception {
        testJs("FunctionCallAccessNested6", "FunctionCallAccessNested6", "FunctionCallAccessNested6.stjs", true);
    }

    @Test
    public void testFunctionCallAccessNested7() throws Exception {
        testJs("FunctionCallAccessNested7", "FunctionCallAccessNested7", "FunctionCallAccessNested7.stjs", true);
    }

    @Test
    public void testDeferredSet() throws Exception {
        testJs("DeferredSet");
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testJs("DeferredSet2");
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testJs("DeferredSet3");
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testJs("DeferredSet4");
    }

}
