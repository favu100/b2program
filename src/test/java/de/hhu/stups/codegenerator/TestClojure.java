package de.hhu.stups.codegenerator;


import org.junit.Ignore;
import org.junit.Test;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

@Ignore
public class TestClojure {

    public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
        int size;
        byte[] buffer = new byte[1024];
        while ((size = inputStream.read(buffer)) != -1)
            outputStream.write(buffer, 0, size);
    }

    public void testClojure(String machine) throws Exception {
        Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
                .getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
        CodeGenerator codeGenerator = new CodeGenerator();
        List<Path> cljFilePaths =
                codeGenerator.generate(mchPath,
                        GeneratorMode.CLJ,
                        false,
                        String.valueOf(Integer.MIN_VALUE),
                        String.valueOf(Integer.MAX_VALUE),
                        "10",
                        false,
                        false,
                        true,
                        null,
                        false,
                        false,
                        null,
                        null);

        //cljFilePaths.forEach(path -> cleanUp(path.toString()));
    }

    @Test
    public void testExample() throws Exception {
        testClojure("Example");
    }

    @Test
    public void testOperation() throws Exception {
        testClojure("Operation");
    }

    @Test
    public void testLocalDeclaration() throws Exception {
        testClojure("LocalDeclaration");
    }

    @Test
    public void testEnumSets() throws Exception {
        testClojure("EnumSets");
    }

    @Test
    public void testNameCollision() throws Exception {
        testClojure("NameCollision");
    }

    @Test
    public void testWhile() throws Exception {
        testClojure("While");
    }

    @Test
    public void testInterval() throws Exception {
        testClojure("Interval");
    }


    @Test
    public void testPair() throws Exception {
        testClojure("Pair");
    }

    @Test
    public void testIfAndPredicates() throws Exception {
        testClojure("IfAndPredicates");
    }

    @Test
    public void testImplies() throws Exception {
        testClojure("Implies");
    }

    @Test
    public void testEquivalence() throws Exception {
        testClojure("Equivalence");
    }

    @Test
    public void testBooleanPredicate() throws Exception {
        testClojure("BooleanPredicate");
    }

    @Ignore
    @Test
    public void testRecords() throws Exception {
        testClojure("Records");
    }

    @Ignore
    @Test
    public void testNondeterminism() throws Exception {
        testClojure("Nondeterminism");
    }

    @Test
    public void testMapFunction() throws Exception {
        testClojure("MapFunction");
    }

    @Test
    public void testRelationImage() throws Exception {
        testClojure("RelationImage");
    }

    @Test
    public void testEmptySet() throws Exception {
        testClojure("EmptySet");
    }

    @Test
    public void testSetUnion() throws Exception {
        testClojure("SetUnion");
    }


    @Test
    public void testCounter() throws Exception {
        testClojure("Counter");
    }

    @Test
    public void testBakery0() throws Exception {
        testClojure("Bakery0");
    }

    @Test
    public void testGCD() throws Exception {
        testClojure("GCD");
    }

    @Test
    public void testACounter() throws Exception {
        testClojure("ACounter");
    }

    @Test
    public void testLift() throws Exception {
        testClojure("Lift");
    }

    @Ignore
    @Test
    public void testTravelAgency() throws Exception {
        testClojure("TravelAgency");
    }

    @Test
    public void testPhonebook() throws Exception {
        testClojure("phonebook");
    }

    @Test
    public void testPhonebook6() throws Exception {
        testClojure("phonebook6");
    }

    @Ignore
    @Test
    public void testSum() throws Exception {
        testClojure("Sum");
    }

    @Ignore
    @Test
    public void testRecursion() throws Exception {
        //Correct exception
        testClojure("recursion/Sum1");
    }

    @Test
    public void testProject() throws Exception {
        testClojure("project1/A");
    }

    @Test
    public void testLiftBenchmarks() throws Exception {
        testClojure("liftbenchmarks/LiftExec");
    }


    @Test
    public void testSieveBenchmarks() throws Exception {
        testClojure("sievebenchmarks/Sieve");
    }

    @Test
    public void testTrafficLightBenchmarks() throws Exception {
        testClojure("trafficlightbenchmarks/TrafficLightExec");
    }

    @Test
    public void testIncreasingSet() throws Exception {
        testClojure("setoperationbenchmarks/IncreasingSet");
    }

    @Test
    public void testSetOperation() throws Exception {
        testClojure("setoperationbenchmarks/SetOperation");
    }


    @Test
    public void testProject2() throws Exception {
        testClojure("project2/MachineA");
    }

    @Test
    public void testSieve() throws Exception {
        testClojure("Sieve");
    }

    @Test
    public void testSieveParallel() throws Exception {
        testClojure("SieveParallel");
    }

    @Test
    public void testSwap() throws Exception {
        testClojure("Swap");
    }

    @Test
    public void testReset() throws Exception {
        testClojure("Reset");
    }

    @Test
    public void testManyLocalDeclarations() throws Exception {
        testClojure("ManyLocalDeclarations");
    }

    @Test
    public void testManyLocalDeclarations2() throws Exception {
        testClojure("ManyLocalDeclarations2");
    }

    @Test
    public void testPlus() throws Exception {
        testClojure("arithmetic/Plus");
    }

    @Test
    public void testMinus() throws Exception {
        testClojure("arithmetic/Minus");
    }

    @Test
    public void testMultiply() throws Exception {
        testClojure("arithmetic/Multiply");
    }

    @Test
    public void testDivide() throws Exception {
        testClojure("arithmetic/Divide");
    }


    @Test
    public void testModulo() throws Exception {
        testClojure("arithmetic/Modulo");
    }

    @Test
    public void testNegative() throws Exception {
        testClojure("arithmetic/Negative");
    }

    @Ignore
    @Test
    public void testPositive() throws Exception {
        testClojure("arithmetic/Positive");
    }

    @Test
    public void testSmallNumbers() throws Exception {
        testClojure("integers/SmallNumbers");
    }

    @Test
    public void testBigNumbers() throws Exception {
        testClojure("integers/BigNumbers");
    }

    @Test
    public void testAnd() throws Exception {
        testClojure("logical/And");
    }


    @Test
    public void testOr() throws Exception {
        testClojure("logical/Or");
    }


    @Test
    public void testImpliesPerformance() throws Exception {
        testClojure("logical/Implies");
    }


    @Ignore
    @Test
    public void testNot() throws Exception {
        testClojure("logical/Not");
    }

    @Test
    public void testEquivalent() throws Exception {
        testClojure("logical/Equivalent");
    }

    @Test
    public void testLess() throws Exception {
        testClojure("comparison/Less");
    }

    @Test
    public void testLessEqual() throws Exception {
        testClojure("comparison/LessEqual");
    }

    @Test
    public void testGreater() throws Exception {
        testClojure("comparison/Greater");
    }


    @Test
    public void testGreaterEqual() throws Exception {
        testClojure("comparison/GreaterEqual");
    }


    @Test
    public void tessEqual() throws Exception {
        testClojure("comparison/Equal");
    }


    @Test
    public void testUnequal() throws Exception {
        testClojure("comparison/Unequal");
    }

    @Test
    public void testCardBig() throws Exception {
        testClojure("setoperation_big/SetCardBig");
    }

    @Test
    public void testDifferenceBig() throws Exception {
        testClojure("setoperation_big/SetDifferenceBig");
    }

    @Test
    public void testElementOfBig() throws Exception {
        testClojure("setoperation_big/SetElementOfBig");
    }

    @Test
    public void testIntersectionBig() throws Exception {
        testClojure("setoperation_big/SetIntersectionBig");
    }

    @Test
    public void testUnionBig() throws Exception {
        testClojure("setoperation_big/SetUnionBig");
    }

    @Test
    public void testCardSmall() throws Exception {
        testClojure("setoperation_small/SetCardSmall");
    }

    @Test
    public void testDifferenceSmall() throws Exception {
        testClojure("setoperation_small/SetDifferenceSmall");
    }

    @Test
    public void testElementOfSmall() throws Exception {
        testClojure("setoperation_small/SetElementOfSmall");
    }

    @Test
    public void testIntersectionSmall() throws Exception {
        testClojure("setoperation_small/SetIntersectionSmall");
    }

    @Test
    public void testUnionSmall() throws Exception {
        testClojure("setoperation_small/SetUnionSmall");
    }

    @Test
    public void testRangeBig() throws Exception {
        testClojure("range_big/RangeBig");
    }


    @Test
    public void testRangeCardBig() throws Exception {
        testClojure("range_big/RangeCardBig");
    }

    @Test
    public void testRangeDifferenceBig() throws Exception {
        testClojure("range_big/RangeDifferenceBig");
    }

    @Test
    public void testRangeElementOfBig() throws Exception {
        testClojure("range_big/RangeElementOfBig");
    }

    @Test
    public void testRangeIntersectionBig() throws Exception {
        testClojure("range_big/RangeIntersectionBig");
    }

    @Test
    public void testRangeUnionBig() throws Exception {
        testClojure("range_big/RangeUnionBig");
    }

    @Test
    public void testRangeSmall() throws Exception {
        testClojure("range_small/RangeSmall");
    }


    @Test
    public void testRangeCardSmall() throws Exception {
        testClojure("range_small/RangeCardSmall");
    }

    @Test
    public void testRangeDifferenceSmall() throws Exception {
        testClojure("range_small/RangeDifferenceSmall");
    }

    @Test
    public void testRangeElementOfSmall() throws Exception {
        testClojure("range_small/RangeElementOfSmall");
    }

    @Test
    public void testRangeIntersectionSmall() throws Exception {
        testClojure("range_small/RangeIntersectionSmall");
    }

    @Test
    public void testRangeUnionSmall() throws Exception {
        testClojure("range_small/RangeUnionSmall");
    }

    @Test
    public void testCardBig2() throws Exception {
        testClojure("setoperation_big/SetCardBig2");
    }

    @Test
    public void testDifferenceBig2() throws Exception {
        testClojure("setoperation_big/SetDifferenceBig2");
    }

    @Test
    public void testElementOfBig2() throws Exception {
        testClojure("setoperation_big/SetElementOfBig2");
    }

    @Test
    public void testIntersectionBig2() throws Exception {
        testClojure("setoperation_big/SetIntersectionBig2");
    }

    @Test
    public void testUnionBig2() throws Exception {
        testClojure("setoperation_big/SetUnionBig2");
    }

    @Test
    public void testCardSmall2() throws Exception {
        testClojure("setoperation_small/SetCardSmall2");
    }

    @Test
    public void testDifferenceSmall2() throws Exception {
        testClojure("setoperation_small/SetDifferenceSmall2");
    }

    @Test
    public void testElementOfSmall2() throws Exception {
        testClojure("setoperation_small/SetElementOfSmall2");
    }

    @Test
    public void testIntersectionSmall2() throws Exception {
        testClojure("setoperation_small/SetIntersectionSmall2");
    }

    @Test
    public void testUnionSmall2() throws Exception {
        testClojure("setoperation_small/SetUnionSmall2");
    }

    @Test
    public void testRangeCardBig2() throws Exception {
        testClojure("range_big/RangeCardBig2");
    }

    @Test
    public void testRangeDifferenceBig2() throws Exception {
        testClojure("range_big/RangeDifferenceBig2");
    }

    @Test
    public void testRangeElementOfBig2() throws Exception {
        testClojure("range_big/RangeElementOfBig2");
    }

    @Test
    public void testRangeIntersectionBig2() throws Exception {
        testClojure("range_big/RangeIntersectionBig2");
    }

    @Test
    public void testRangeUnionBig2() throws Exception {
        testClojure("range_big/RangeUnionBig2");
    }

    @Test
    public void testRangeCardSmall2() throws Exception {
        testClojure("range_small/RangeCardSmall2");
    }

    @Test
    public void testRangeDifferenceSmall2() throws Exception {
        testClojure("range_small/RangeDifferenceSmall2");
    }

    @Test
    public void testRangeElementOfSmall2() throws Exception {
        testClojure("range_small/RangeElementOfSmall2");
    }

    @Test
    public void testRangeIntersectionSmall2() throws Exception {
        testClojure("range_small/RangeIntersectionSmall2");
    }

    @Test
    public void testRangeUnionSmall2() throws Exception {
        testClojure("range_small/RangeUnionSmall2");
    }


    @Test
    public void testTrafficLight() throws Exception {
        testClojure("TrafficLight");
    }

    @Test
    public void testChoice() throws Exception {
        testClojure("Choice");
    }

    @Test
    public void testAssert() throws Exception {
        testClojure("Assert");
    }

    @Test
    public void testCruiseController1() throws Exception {
        testClojure("Cruise_finite1");
    }

    @Test
    public void testCruiseControllerk() throws Exception {
        testClojure("Cruise_finite_k");
    }
    
    private void cleanUp(String path) {
        File file = new File(path);
        if (file.exists()) {
            file.delete();
        }
    }

}
