package de.hhu.stups.codegenerator.java;

import org.junit.Test;

public class TestOtherConstructs extends TestJava {

    @Test
    public void testWhile() throws Exception {
        testJava("While", "While", "WhileAddition.stjava", true);
    }

    @Test
    public void testEquivalence() throws Exception {
        testJava("Equivalence", "Equivalence", "EquivalenceAddition.stjava", true);
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testJava("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stjava", true);
    }

    @Test
    public void testNondeterminism() throws Exception {
        testJava("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stjava", true);
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testJava("Nondeterminism2", "Nondeterminism2", "Nondeterminism2Addition.stjava", true);
    }

    @Test
    public void testMapFunction() throws Exception {
        testJava("MapFunction", "MapFunction", "MapFunctionAddition.stjava", true);
    }

    @Test
    public void testSetUnion() throws Exception {
        testJava("SetUnion");
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testJava("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stjava", true);
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testJava("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stjava", true);
    }

    @Test
    public void testAssert() throws Exception {
        testJava("Assert");
    }

    @Test
    public void testChoice() throws Exception {
        testJava("Choice", "Choice", "ChoiceAddition.stjava", true);
    }

    @Test
    public void testDanglingElse() throws Exception {
        testJava("DanglingElse", "DanglingElse", "DanglingElseAddition.stjava", true);
    }


    @Test
    public void testIfAndPredicates() throws Exception {
        testJava("IfAndPredicates");
    }

    @Test
    public void testNameCollision() throws Exception {
        testJava("NameCollision", "NameCollision", "NameCollisionAddition.stjava", true);
    }

    @Test
    public void testSwap() throws Exception {
        testJava("Swap", "Swap", "SwapAddition.stjava", true);
    }


    @Test
    public void testSwap2() throws Exception {
        testJava("Swap2", "Swap2", "Swap2Addition.stjava", true);
    }

    @Test
    public void testUnion() throws Exception {
        testJava("Union", "Union", "UnionAddition.stjava", true);
    }

    @Test
    public void testIfExpression() throws Exception {
        testJava("IfExpression", "IfExpression", "IfExpressionAddition.stjava", true);
    }

    @Test
    public void testIfPredicate() throws Exception {
        testJava("IfPredicate", "IfPredicate", "IfPredicateAddition.stjava", true);
    }


    @Test
    public void testRecords() throws Exception {
        testJava("Records");
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testJava("RecordsAccess");
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testJava("RecordsAccess2");
    }

    @Test
    public void testRecordsAccess3() throws Exception {
        testJava("RecordsAccess3", "RecordsAccess3", "RecordsAccess3.stjava", true);
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testJava("RecordAccessNested", "RecordAccessNested", "RecordAccessNested.stjava", true);
    }

    @Test
    public void testRecordAccessNested2() throws Exception {
        testJava("RecordAccessNested2", "RecordAccessNested2", "RecordAccessNested2.stjava", true);
    }

    @Test
    public void testRecordAccessNested3() throws Exception {
        testJava("RecordAccessNested3", "RecordAccessNested3", "RecordAccessNested3.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testJava("FunctionCallAccessNested", "FunctionCallAccessNested", "FunctionCallAccessNested.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testJava("FunctionCallAccessNested2", "FunctionCallAccessNested2", "FunctionCallAccessNested2.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testJava("FunctionCallAccessNested3", "FunctionCallAccessNested3", "FunctionCallAccessNested3.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested4() throws Exception {
        testJava("FunctionCallAccessNested4", "FunctionCallAccessNested4", "FunctionCallAccessNested4.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested5() throws Exception {
        testJava("FunctionCallAccessNested5", "FunctionCallAccessNested5", "FunctionCallAccessNested5.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested6() throws Exception {
        testJava("FunctionCallAccessNested6", "FunctionCallAccessNested6", "FunctionCallAccessNested6.stjava", true);
    }

    @Test
    public void testFunctionCallAccessNested7() throws Exception {
        testJava("FunctionCallAccessNested7", "FunctionCallAccessNested7", "FunctionCallAccessNested7.stjava", true);
    }

    @Test
    public void testDeferredSet() throws Exception {
        testJava("DeferredSet");
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testJava("DeferredSet2");
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testJava("DeferredSet3");
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testJava("DeferredSet4");
    }

}
