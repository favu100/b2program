package de.hhu.stups.codegenerator.cpp;

import org.junit.Test;

public class TestOtherConstructs extends TestCpp {

    @Test
    public void testWhile() throws Exception {
        testCpp("While", "While", "WhileAddition.stCpp", true);
    }

    @Test
    public void testEquivalence() throws Exception {
        testCpp("Equivalence", "Equivalence", "EquivalenceAddition.stCpp", true);
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testCpp("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stCpp", true);
    }

    @Test
    public void testNondeterminism() throws Exception {
        testCpp("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stCpp", true);
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testCpp("Nondeterminism2", "Nondeterminism2", "Nondeterminism2Addition.stCpp", true);
    }

    @Test
    public void testMapFunction() throws Exception {
        testCpp("MapFunction", "MapFunction", "MapFunctionAddition.stCpp", true);
    }

    @Test
    public void testSetUnion() throws Exception {
        testCpp("SetUnion");
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testCpp("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stCpp", true);
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testCpp("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stCpp", true);
    }

    @Test
    public void testAssert() throws Exception {
        testCpp("Assert");
    }

    @Test
    public void testChoice() throws Exception {
        testCpp("Choice", "Choice", "ChoiceAddition.stcpp", true);
    }

    @Test
    public void testDanglingElse() throws Exception {
        testCpp("DanglingElse", "DanglingElse", "DanglingElseAddition.stcpp", true);
    }


    @Test
    public void testIfAndPredicates() throws Exception {
        testCpp("IfAndPredicates");
    }

    @Test
    public void testNameCollision() throws Exception {
        testCpp("NameCollision", "NameCollision", "NameCollisionAddition.stcpp", true);
    }

    @Test
    public void testSwap() throws Exception {
        testCpp("Swap", "Swap", "SwapAddition.stcpp", true);
    }


    @Test
    public void testSwap2() throws Exception {
        testCpp("Swap2", "Swap2", "Swap2Addition.stcpp", true);
    }

    @Test
    public void testUnion() throws Exception {
        testCpp("Union", "Union", "UnionAddition.stcpp", true);
    }

    @Test
    public void testIfExpression() throws Exception {
        testCpp("IfExpression", "IfExpression", "IfExpressionAddition.stcpp", true);
    }

    @Test
    public void testIfPredicate() throws Exception {
        testCpp("IfPredicate", "IfPredicate", "IfPredicateAddition.stcpp", true);
    }


    @Test
    public void testRecords() throws Exception {
        testCpp("Records");
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testCpp("RecordsAccess");
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testCpp("RecordsAccess2");
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testCpp("RecordAccessNested");
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testCpp("FunctionCallAccessNested", "FunctionCallAccessNested", "FunctionCallAccessNested.stcpp", true);
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testCpp("FunctionCallAccessNested2", "FunctionCallAccessNested2", "FunctionCallAccessNested2.stcpp", true);
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testCpp("FunctionCallAccessNested3", "FunctionCallAccessNested3", "FunctionCallAccessNested3.stcpp", true);
    }


    @Test
    public void testDeferredSet() throws Exception {
        testCpp("DeferredSet");
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testCpp("DeferredSet2");
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testCpp("DeferredSet3");
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testCpp("DeferredSet4");
    }

}
