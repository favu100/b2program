package de.hhu.stups.codegenerator;


import org.junit.Ignore;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;

/**
 * Created by fabian on 30.08.18.
 */

public class TestCpp {

	public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
		int size;
		byte[] buffer = new byte[1024];
		while ((size = inputStream.read(buffer)) != -1)
			outputStream.write(buffer, 0, size);
	}

	public static void writeInputToSystem(InputStream inputStream) throws IOException {
		writeInputToOutput(inputStream, System.err);
	}

	private static String streamToString(InputStream inputStream) throws IOException {
		ByteArrayOutputStream result = new ByteArrayOutputStream();
		byte[] buffer = new byte[1024];
		int length;
		while ((length = inputStream.read(buffer)) != -1) {
			result.write(buffer, 0, length);
		}
		return result.toString();
	}


	public void testCpp(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> cppFilePaths = codeGenerator.generate(mchPath, GeneratorMode.CPP, false, true, null);


		cppFilePaths.forEach(path -> {
			try {
				Process process = Runtime.getRuntime()
						.exec("g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -c " + path.toFile().getAbsoluteFile().toString());
				writeInputToSystem(process.getErrorStream());
				writeInputToOutput(process.getErrorStream(), process.getOutputStream());
				process.waitFor();
			} catch (IOException | InterruptedException e) {
				e.printStackTrace();
			}
		});

		Set<File> oFiles = cppFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".o"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
		//cFilePaths.forEach(path -> cleanUp(path.toString()));
	}


	public void testCpp(String machine, String machineName, String addition, boolean execute) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> cppFilePaths = codeGenerator.generate(mchPath, GeneratorMode.CPP, false, true, null);

		Runtime runtime = Runtime.getRuntime();

		Path mainPath = cppFilePaths.get(cppFilePaths.size() - 1);

		Process compileProcess = runtime
				.exec("g++ -std=c++14 -O2 -march=native -g -DIMMER_NO_THREAD_SAFETY -o " + machineName + ".exec" + " build/resources/test/de/hhu/stups/codegenerator/" + machine + ".cpp");
		compileProcess.waitFor();

		String error = streamToString(compileProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		if(!execute) {
			return;
		}

		Process executeProcess = runtime.exec("./" + machineName + ".exec");
		executeProcess.waitFor();

		error = streamToString(executeProcess.getErrorStream());
		if(!error.isEmpty()) {
			throw new RuntimeException(error);
		}

		String result = streamToString(executeProcess.getInputStream()).replaceAll("\n", "");
		String expectedOutput = streamToString(new FileInputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".cpp", ".out"))).replaceAll("\n", "");

		System.out.println("Assert: " + result + " = " + expectedOutput);

		assertEquals(result, expectedOutput);

		Set<File> execFiles = cppFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".exec"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
		//cFilePaths.forEach(path -> cleanUp(path.toString()));
	}

	@Test
	public void testExample() throws Exception {
		testCpp("Example");
	}

	@Test
	public void testOperation() throws Exception {
		testCpp("Operation", "Operation", "OperationAddition.stjava", true);
	}

	@Test
	public void testOperation2() throws Exception {
		testCpp("Operation2");
	}

	@Test
	public void testLocalDeclaration() throws Exception {
		testCpp("LocalDeclaration");
	}

	@Ignore
	@Test
	public void testRefinement() throws Exception {
		// TODO VAR-Node
		testCpp("RefinementMachine");
	}

	@Test
	public void testEnumSets() throws Exception {
		testCpp("EnumSets", "EnumSets", "EnumSetsAddition.stjava", true);
	}

	@Test
	public void testNameCollision() throws Exception {
		testCpp("NameCollision", "NameCollision", "NameCollisionAddition.stjava", true);
	}

	@Test
	public void testWhile() throws Exception {
		testCpp("While", "While", "WhileAddition.stjava", true);
	}

	@Test
	public void testInterval() throws Exception {
		testCpp("Interval", "Interval", "IntervalAddition.stjava", true);
	}


	@Test
	public void testPair() throws Exception {
		testCpp("Pair", "Pair", "PairAddition.stjava", true);
	}

	@Test
	public void testIfAndPredicates() throws Exception {
		testCpp("IfAndPredicates");
	}

	@Test
	public void testDanglingElse() throws Exception {
		testCpp("DanglingElse", "DanglingElse", "DanglingElseAddition.stjava", true);
	}

	@Test
	public void testImplies() throws Exception {
		testCpp("Implies", "Implies", "ImpliesAddition.stjava", true);
	}

	@Test
	public void testEquivalence() throws Exception {
		testCpp("Equivalence", "Equivalence", "EquivalenceAddition.stjava", true);
	}

	@Test
	public void testBooleanPredicate() throws Exception {
		testCpp("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testRecords() throws Exception {
		testCpp("Records");
	}

	@Test
	public void testNondeterminism() throws Exception {
		testCpp("Nondeterminism", "Nondeterminism", "NondeterminismAddition.stjava", true);
	}

	@Test
	public void testMapFunction() throws Exception {
		testCpp("MapFunction", "MapFunction", "MapFunctionAddition.stjava", true);
	}

	@Test
	public void testRelationImage() throws Exception {
		testCpp("RelationImage", "RelationImage", "RelationImageAddition.stjava", true);
	}

	@Test
	public void testEmptySet() throws Exception {
		testCpp("EmptySet", "EmptySet", "EmptySetAddition.stjava", true);
	}

	@Test
	public void testSetUnion() throws Exception {
		testCpp("SetUnion");
	}


	@Test
	public void testCounter() throws Exception {
		testCpp("Counter", "Counter", "CounterAddition.stjava", true);
	}

	@Test
	public void testBakery0() throws Exception {
		testCpp("Bakery0", "Bakery0", "Bakery0Addition.stjava", true);
	}

	@Test
	public void testGCD() throws Exception {
		testCpp("GCD");
	}

	@Test
	public void testACounter() throws Exception {
		testCpp("ACounter", "ACounter", "ACounterAddition.stjava", true);
	}

	@Test
	public void testLift() throws Exception {
		testCpp("Lift", "Lift", "LiftAddition.stjava", true);
	}

	@Test
	public void testTravelAgency() throws Exception {
		testCpp("TravelAgency");
	}

	@Test
	public void testTrafficLight() throws Exception {
		testCpp("TrafficLight", "TrafficLight", "TrafficLightAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testPhonebook() throws Exception {
		// TODO
		testCpp("phonebook");
	}

	@Ignore
	@Test
	public void testPhonebook6() throws Exception {
		// TODO
		testCpp("phonebook6");
	}

	@Test
	public void testProject() throws Exception {
		//This might be a bug in the parser in the scoping part
		testCpp("project1/A", "A", "AAddition.stjava", true);
	}

	@Test
	public void testProject3() throws Exception {
		testCpp("project3/A");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testCpp("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.stjava", true);
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testCpp("sievebenchmarks/Sieve", "Sieve", "SieveAddition.stjava", true);
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testCpp("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.stjava", true);
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testCpp("setoperationbenchmarks/IncreasingSet");
	}

	@Test
	public void testSetOperation() throws Exception {
		testCpp("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.stjava", true);
	}

	@Test
	public void testProject2() throws Exception {
		testCpp("project2/MachineA", "MachineA", "MachineAAddition.stjava", true);
	}

	@Test
	public void testSieve() throws Exception {
		testCpp("Sieve", "Sieve", "SieveAddition.stjava", true);
	}

	@Test
	public void testSieveParallel() throws Exception {
		testCpp("SieveParallel", "SieveParallel", "SieveParallelAddition.stjava", true);
	}

	@Test
	public void testReset() throws Exception {
		testCpp("Reset");
	}

	@Test
	public void testSwap() throws Exception {
		testCpp("Swap", "Swap", "SwapAddition.stjava", true);
	}


	@Test
	public void testSwap2() throws Exception {
		testCpp("Swap2");
	}

	@Test
	public void testManyLocalDeclarations() throws Exception {
		testCpp("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.stjava", true);
	}

	@Test
	public void testManyLocalDeclarations2() throws Exception {
		testCpp("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2Addition.stjava", true);
	}

	@Test
	public void testPlus() throws Exception {
		testCpp("arithmetic/Plus", "Plus", "PlusAddition.stjava", true);
	}

	@Test
	public void testMinus() throws Exception {
		testCpp("arithmetic/Minus", "Minus", "MinusAddition.stjava", true);
	}

	@Test
	public void testMultiply() throws Exception {
		testCpp("arithmetic/Multiply", "Multiply", "MultiplyAddition.stjava", true);
	}

	@Test
	public void testDivide() throws Exception {
		testCpp("arithmetic/Divide", "Divide", "DivideAddition.stjava", true);
	}


	@Test
	public void testModulo() throws Exception {
		testCpp("arithmetic/Modulo", "Modulo", "ModuloAddition.stjava", true);
	}

	@Test
	public void testNegative() throws Exception {
		testCpp("arithmetic/Negative", "Negative", "NegativeAddition.stjava", true);
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testCpp("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testCpp("integers/SmallNumbers", "SmallNumbersAddition.stjava", true);
	}

	@Test
	public void testBigNumbers() throws Exception {
		testCpp("integers/BigNumbers", "BigNumbersAddition.stjava", true);
	}*/

	@Test
	public void testAnd() throws Exception {
		testCpp("logical/And", "And", "AndAddition.stjava", true);
	}


	@Test
	public void testOr() throws Exception {
		testCpp("logical/Or", "Or", "OrAddition.stjava", true);
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testCpp("logical/Implies", "Implies", "ImpliesAddition.stjava", true);
	}

	@Test
	public void testNot() throws Exception {
		testCpp("logical/Not");
	}

	@Test
	public void testEquivalent() throws Exception {
		testCpp("logical/Equivalent", "Equivalent", "EquivalentAddition.stjava", true);
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testCpp("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testCpp("logical/BooleanConstant");
	}

	@Test
	public void testLess() throws Exception {
		testCpp("comparison/Less", "Less", "LessAddition.stjava", true);
	}

	@Test
	public void testLessEqual() throws Exception {
		testCpp("comparison/LessEqual", "LessEqual", "LessEqualAddition.stjava", true);
	}

	@Test
	public void testGreater() throws Exception {
		testCpp("comparison/Greater", "Greater", "GreaterAddition.stjava", true);
	}


	@Test
	public void testGreaterEqual() throws Exception {
		testCpp("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.stjava", true);
	}


	@Test
	public void tessEqual() throws Exception {
		testCpp("comparison/Equal", "Equal", "EqualAddition.stjava", true);
	}


	@Test
	public void testUnequal() throws Exception {
		testCpp("comparison/Unequal", "Unequal", "UnequalAddition.stjava", true);
	}

	@Test
	public void testCardBig() throws Exception {
		testCpp("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.stjava", false);
	}

	@Test
	public void testCardBig2() throws Exception {
		testCpp("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testCpp("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceBigAddition.stjava", true);
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testCpp("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testCpp("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfBigAddition.stjava", true);
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testCpp("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testCpp("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.stjava", true);
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testCpp("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testCpp("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.stjava", false);
	}

	@Test
	public void testUnionBig2() throws Exception {
		testCpp("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testCpp("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.stjava", true);
	}

	@Test
	public void testCardSmall2() throws Exception {
		testCpp("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testCpp("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetDifferenceSmallAddition.stjava", true);
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testCpp("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testCpp("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.stjava", true);
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testCpp("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testCpp("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.stjava", true);
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testCpp("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testCpp("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.stjava", true);
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testCpp("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testCpp("range_big/RangeBig", "RangeBig", "RangeBigAddition.stjava", true);
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testCpp("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.stjava", false);
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testCpp("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testCpp("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.stjava", true);
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testCpp("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testCpp("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.stjava", true);
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testCpp("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testCpp("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.stjava", true);
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testCpp("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testCpp("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.stjava", false);
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testCpp("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testCpp("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.stjava", true);
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testCpp("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.stjava", true);
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testCpp("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testCpp("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.stjava", true);
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testCpp("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testCpp("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.stjava", true);
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testCpp("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testCpp("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.stjava", true);
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testCpp("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testCpp("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.stjava", true);
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testCpp("range_small/RangeUnionSmall2");
	}

	@Test
	public void testChoice() throws Exception {
		testCpp("Choice");
	}

	@Test
	public void testAssert() throws Exception {
		testCpp("Assert");
	}

	@Test
	public void testCruiseController1() throws Exception {
		testCpp("Cruise_finite1");
	}

	@Test
	public void testCruiseControllerk() throws Exception {
		testCpp("Cruise_finite_k");
	}

	@Test
	public void testCruiseControllerDeterministic() throws Exception {
		testCpp("Cruise_finite_Deterministic");
	}

	@Test
	public void testScheduler() throws Exception {
		testCpp("scheduler");
	}

	@Test
	public void testCanBusTLC() throws Exception {
		testCpp("CAN_BUS_tlc");
	}

	@Ignore
	@Test
	public void testCore() throws Exception {
		testCpp("Core");
	}

	@Ignore
	@Test
	public void testSetLawsNAT() throws Exception {
		testCpp("SetLawsNAT");
	}

	@Test
	public void SimpsonFourSlot() throws Exception {
		testCpp("Simpson_Four_Slot");
	}

	@Test
	public void Train1BeebookTLC() throws Exception {
		testCpp("Train_1_beebook_TLC");
	}

	@Test
	public void Train1() throws Exception {
		testCpp("train_1");
	}

	@Ignore
	@Test
	public void testEarley2() throws Exception {
		testCpp("earley_2");
	}

	@Ignore
	@Test
	public void testOBSW_M001() throws Exception {
		testCpp("obsw_M001");
	}

	@Ignore
	@Test
	public void testRef5Switch() throws Exception {
		testCpp("Ref5_Switch");
	}

	@Ignore
	@Test
	public void testrether_mch1() throws Exception {
		testCpp("rether_mch1");
	}


	@Test
	public void testSetComprehension1() throws Exception {
		testCpp("SetComprehension1");
	}

	@Test
	public void testSetComprehension2() throws Exception {
		testCpp("SetComprehension2");
	}

	@Test
	public void testSetComprehension3() throws Exception {
		testCpp("SetComprehension3");
	}

	@Test
	public void testSetComprehension4() throws Exception {
		testCpp("SetComprehension4");
	}

	@Ignore
	@Test
	public void testSetComprehension5() throws Exception {
		//Does not work because of bounded variables from outer scope
		testCpp("SetComprehension5");
	}

	@Test
	public void testLambda() throws Exception {
		testCpp("Lambda");
	}

	@Test
	public void testLambda2() throws Exception {
		testCpp("Lambda2");
	}

	@Test
	public void testQuantifiedPredicate() throws Exception {
		testCpp("QuantifiedPredicate");
	}

	@Test
	public void testQuantifiedPredicate2() throws Exception {
		testCpp("QuantifiedPredicate2");
	}

	@Test
	public void testQuantifiedPredicate3() throws Exception {
		testCpp("QuantifiedPredicate3");
	}

	@Test
	public void testQuantifiedExpression1() throws Exception {
		testCpp("QuantifiedExpression1");
	}

	@Test
	public void testQuantifiedExpression2() throws Exception {
		testCpp("QuantifiedExpression2");
	}

	@Test
	public void testQuantifiedExpression3() throws Exception {
		testCpp("QuantifiedExpression3");
	}

	@Test
	public void testQuantifiedExpression4() throws Exception {
		testCpp("QuantifiedExpression4");
	}

	@Test
	public void testQuantifiedExpression5() throws Exception {
		testCpp("QuantifiedExpression5");
	}


	@Test
	public void testGeneralizedUnion() throws Exception {
		testCpp("GeneralizedUnion");
	}

	@Test
	public void testGeneralizedIntersection() throws Exception {
		testCpp("GeneralizedIntersection");
	}


	@Test
	public void testFunctionalOverride() throws Exception {
		testCpp("FunctionalOverride");
	}

	@Test
	public void testFunctionalOverride2() throws Exception {
		testCpp("FunctionalOverride2");
	}

	@Test
	public void testFunctionalOverride3() throws Exception {
		testCpp("FunctionalOverride3");
	}

	@Test
	public void testOverride() throws Exception {
		testCpp("Override");
	}

	@Test
	public void testPow() throws Exception {
		testCpp("Pow");
	}

	@Test
	public void testPow1() throws Exception {
		testCpp("Pow1");
	}

	@Test
	public void testFin() throws Exception {
		testCpp("Fin");
	}

	@Test
	public void testFin1() throws Exception {
		testCpp("Fin1");
	}

	@Test
	public void testId() throws Exception {
		testCpp("Id");
	}

	@Test
	public void testParallelProduct() throws Exception {
		testCpp("ParallelProduct");
	}

	@Test
	public void testDirectProduct() throws Exception {
		testCpp("DirectProduct");
	}

	@Test
	public void testComposition() throws Exception {
		testCpp("Composition");
	}

	@Test
	public void testProjection1() throws Exception {
		testCpp("Projection1");
	}

	@Test
	public void testProjection2() throws Exception {
		testCpp("Projection2");
	}

	@Test
	public void testAppend() throws Exception {
		testCpp("Append");
	}


	@Ignore
	@Test
	public void testConc() throws Exception {
		testCpp("Conc");
	}

	@Test
	public void testConcat() throws Exception {
		testCpp("Concat");
	}

	@Test
	public void testDrop() throws Exception {
		testCpp("Drop");
	}

	@Test
	public void testEmptySequence() throws Exception {
		testCpp("EmptySequence");
	}

	@Test
	public void testEnumeratedSequence() throws Exception {
		testCpp("EnumeratedSequence");
	}

	@Test
	public void testFirstElementSequence() throws Exception {
		testCpp("FirstElementSequence");
	}

	@Test
	public void testFrontSequence() throws Exception {
		testCpp("FrontSequence");
	}

	@Test
	public void testLastElementSequence() throws Exception {
		testCpp("LastElementSequence");
	}

	@Test
	public void testPrepend() throws Exception {
		testCpp("Prepend");
	}

	@Test
	public void testReverse() throws Exception {
		testCpp("ReverseSequence");
	}

	@Test
	public void testSizeOfSequence() throws Exception {
		testCpp("SizeOfSequence");
	}

	@Test
	public void testTailSequence() throws Exception {
		testCpp("TailSequence");
	}

	@Test
	public void testTake() throws Exception {
		testCpp("Take");
	}

	@Test
	public void testSequenceOperateRelation() throws Exception {
		testCpp("SequenceOperateRelation");
	}

	@Test
	public void testPred() throws Exception {
		testCpp("Pred");
	}

	@Test
	public void testSucc() throws Exception {
		testCpp("Succ");
	}

	@Test
	public void testIterate() throws Exception {
		testCpp("Iterate");
	}

	@Test
	public void testClosure() throws Exception {
		testCpp("Closure");
	}

	@Test
	public void testClosure1() throws Exception {
		testCpp("Closure1");
	}

	@Test
	public void testFnc() throws Exception {
		testCpp("Fnc");
	}

	@Test
	public void testRel() throws Exception {
		testCpp("Rel");
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			file.delete();
		}
	}

}
