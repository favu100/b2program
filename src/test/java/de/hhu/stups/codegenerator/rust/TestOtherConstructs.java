package de.hhu.stups.codegenerator.rust;

import org.junit.Test;

public class TestOtherConstructs extends TestRS {

    @Test
    public void testWhile() throws Exception {
        testRS("While", "While", "WhileAddition.strs", true);
    }

    @Test
    public void testEquivalence() throws Exception {
        testRS("Equivalence", "Equivalence", "EquivalenceAddition.strs", true);
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testRS("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.strs", true);
    }

    @Test
    public void testNondeterminism() throws Exception {
        testRS("Nondeterminism", "Nondeterminism", "NondeterminismAddition.strs", true);
    }

    @Test
    public void testNondeterminism2() throws Exception {
        testRS("Nondeterminism2", "Nondeterminism2", "Nondeterminism2Addition.strs", true);
    }

    @Test
    public void testMapFunction() throws Exception {
        testRS("MapFunction", "MapFunction", "MapFunctionAddition.strs", true);
    }

    @Test
    public void testSetUnion() throws Exception {
        testRS("SetUnion");
    }


    @Test
    public void testManyLocalDeclarations() throws Exception {
        testRS("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.strs", true);
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testRS("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.strs", true);
    }

    @Test
    public void testAssert() throws Exception {
        testRS("Assert");
    }

    @Test
    public void testChoice() throws Exception {
        testRS("Choice", "Choice", "ChoiceAddition.strs", true);
    }

    @Test
    public void testDanglingElseWD() throws Exception {
        testRS("DanglingElseWD", "DanglingElseWD", "DanglingElseAdditionWD.strs", true);
    }

    /**
     * This machines 'calculate'-method may not set a value for the output.
     * Other languages handle this by instantiating any variable with {@code null}, if necessary.
     * While technically possible to set some initial default value for such cases in Rust as well,
     * it is generally not advised to do so and has no merit whatsoever. (It is actually quite surprising,
     * that this is even possible in B, as undefined values would be problematic there as well).
     * For this reason, generated rust-code from such B-machines will not support this case,
     * and will therefore not compile.
     */
    @Test(expected = Exception.class)
    public void testDanglingElse() throws Exception {
        testRS("DanglingElse", "DanglingElse", "DanglingElseAddition.strs", true);
    }


    @Test
    public void testIfAndPredicates() throws Exception {
        testRS("IfAndPredicates");
    }

    @Test
    public void testNameCollision() throws Exception {
        testRS("NameCollision", "NameCollision", "NameCollisionAddition.strs", true);
    }

    @Test
    public void testSwap() throws Exception {
        testRS("Swap", "Swap", "SwapAddition.strs", true);
    }


    @Test
    public void testSwap2() throws Exception {
        testRS("Swap2", "Swap2", "Swap2Addition.strs", true);
    }

    @Test
    public void testUnion() throws Exception {
        testRS("Union", "Union", "UnionAddition.strs", true);
    }

    @Test
    public void testIfExpression() throws Exception {
        testRS("IfExpression", "IfExpression", "IfExpressionAddition.strs", true);
    }

    @Test
    public void testIfPredicate() throws Exception {
        testRS("IfPredicate", "IfPredicate", "IfPredicateAddition.strs", true);
    }


    @Test
    public void testRecords() throws Exception {
        testRS("Records");
    }

    @Test
    public void testRecordsAccess() throws Exception {
        testRS("RecordsAccess");
    }

    @Test
    public void testRecordsAccess2() throws Exception {
        testRS("RecordsAccess2");
    }

    @Test
    public void testRecordsAccess3() throws Exception {
        testRS("RecordsAccess3", "RecordsAccess3", "RecordsAccess3.strs", true);
    }

    @Test
    public void testRecordAccessNested() throws Exception {
        testRS("RecordAccessNested", "RecordAccessNested", "RecordAccessNested.strs", true);
    }

    @Test
    public void testRecordAccessNested2() throws Exception {
        testRS("RecordAccessNested2", "RecordAccessNested2", "RecordAccessNested2.strs", true);
    }

    @Test
    public void testRecordAccessNested3() throws Exception {
        testRS("RecordAccessNested3", "RecordAccessNested3", "RecordAccessNested3.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested() throws Exception {
        testRS("FunctionCallAccessNested", "FunctionCallAccessNested", "FunctionCallAccessNested.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested2() throws Exception {
        testRS("FunctionCallAccessNested2", "FunctionCallAccessNested2", "FunctionCallAccessNested2.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested3() throws Exception {
        testRS("FunctionCallAccessNested3", "FunctionCallAccessNested3", "FunctionCallAccessNested3.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested4() throws Exception {
        testRS("FunctionCallAccessNested4", "FunctionCallAccessNested4", "FunctionCallAccessNested4.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested5() throws Exception {
        testRS("FunctionCallAccessNested5", "FunctionCallAccessNested5", "FunctionCallAccessNested5.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested6() throws Exception {
        testRS("FunctionCallAccessNested6", "FunctionCallAccessNested6", "FunctionCallAccessNested6.strs", true);
    }

    @Test
    public void testFunctionCallAccessNested7() throws Exception {
        testRS("FunctionCallAccessNested7", "FunctionCallAccessNested7", "FunctionCallAccessNested7.strs", true);
    }

    @Test
    public void testDeferredSet() throws Exception {
        testRS("DeferredSet");
    }

    @Test
    public void testDeferredSet2() throws Exception {
        testRS("DeferredSet2");
    }

    @Test
    public void testDeferredSet3() throws Exception {
        testRS("DeferredSet3");
    }

    @Test
    public void testDeferredSet4() throws Exception {
        testRS("DeferredSet4");
    }

}
