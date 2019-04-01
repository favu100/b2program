package de.hhu.stups.codegenerator;

import org.junit.Ignore;
import org.junit.Test;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * Created by fabian on 31.05.18.
 */

public class TestJava {

	public static void writeInputToSystem(InputStream inputStream) throws IOException {
		writeInputToOutput(inputStream, System.out);
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

	public static void writeInputToOutput(InputStream inputStream, OutputStream outputStream) throws IOException {
		int size;
		byte[] buffer = new byte[1024];
		while ((size = inputStream.read(buffer)) != -1)
			outputStream.write(buffer, 0, size);
	}

	public void testJava(String machine) throws Exception {
		Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machine + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> javaFilePaths = codeGenerator.generate(mchPath, GeneratorMode.JAVA, false,true, null);
		Process process = Runtime.getRuntime()
				.exec("javac -classpath btypes_persistent.jar " + String.join(" ", javaFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));

		writeInputToSystem(process.getErrorStream());
		writeInputToOutput(process.getErrorStream(), process.getOutputStream());
		process.waitFor();

		Set<File> classFiles = javaFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machine + ".class"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));
	}

	public void testJava(String machinePath, String machineName, String addition) throws Exception {
		testJava(machinePath);
		/*Path mchPath = Paths.get(CodeGenerator.class.getClassLoader()
				.getResource("de/hhu/stups/codegenerator/" + machinePath + ".mch").toURI());
		CodeGenerator codeGenerator = new CodeGenerator();
		List<Path> javaFilePaths = codeGenerator.generate(mchPath, GeneratorMode.JAVA, false,true, addition);
		Runtime runtime = Runtime.getRuntime();
		Process compileProcess = runtime.exec("javac -cp btypes_persistent.jar " +
				String.join(" ", javaFilePaths.stream()
						.map(path -> path.toFile().getAbsoluteFile().toString())
						.collect(Collectors.toSet())));
		compileProcess.waitFor();

		writeInputToSystem(compileProcess.getErrorStream());
		writeInputToOutput(compileProcess.getErrorStream(), compileProcess.getOutputStream());

		Path mainPath = javaFilePaths.get(0);

		List<String> cmds = new ArrayList<>();
		cmds.add("java");
		cmds.add("-cp");
		cmds.add(":btypes_persistent.jar");
		cmds.add(machineName);

		ProcessBuilder executeProcessBuilder = new ProcessBuilder().command(cmds).directory(mainPath.getParent().toFile());
		Process executeProcess = executeProcessBuilder.start();
		executeProcess.waitFor();
		Path outPath = mainPath.toFile().getAbsoluteFile().toPath();

		writeInputToSystem(executeProcess.getErrorStream());
		//writeInputToOutput(executeProcess.getInputStream(), new FileOutputStream(mainPath.toFile().getAbsoluteFile().toString().replaceAll(".java", ".abc")));

		String result = streamToString(executeProcess.getInputStream());
		String expectedOutput = streamToString(new FileInputStream(outPath.toString()));

		//assertEquals(result, expectedOutput);

		Set<File> classFiles = javaFilePaths.stream()
				.map(path -> new File(path.getParent().toFile(), machinePath + ".class"))
				.collect(Collectors.toSet());

		//javaFilePaths.forEach(path -> cleanUp(path.toString()));
		//classFiles.forEach(path -> cleanUp(path.getAbsolutePath().toString()));*/
	}

	@Test
	public void testExample() throws Exception {
		testJava("Example", "Example", "ExampleAddition.st");
	}

	@Test
	public void testOperation() throws Exception {
		testJava("Operation", "Operation", "OperationAddition.st");
	}

	@Test
	public void testOperation2() throws Exception {
		testJava("Operation2");
	}

	@Test
	public void testLocalDeclaration() throws Exception {
		testJava("LocalDeclaration", "LocalDeclaration", "LocalDeclarationAddition.st");
	}

	@Ignore
	@Test
	public void testRefinement() throws Exception {
		// TODO VAR-Node
		testJava("RefinementMachine");
	}

	@Test
	public void testEnumSets() throws Exception {
		testJava("EnumSets", "EnumSets", "EnumSetsAddition.st");
	}

	@Test
	public void testNameCollision() throws Exception {
		testJava("NameCollision", "NameCollision", "NameCollisionAddition.st");
	}

	@Test
	public void testWhile() throws Exception {
		testJava("While", "While", "WhileAddition.st");
	}

	@Test
	public void testInterval() throws Exception {
		testJava("Interval", "Interval", "IntervalAddition.st");
	}


	@Test
	public void testPair() throws Exception {
		testJava("Pair", "Pair", "PairAddition.st");
	}

	@Test
	public void testIfAndPredicates() throws Exception {
		testJava("IfAndPredicates", "IfAndPredicates", "IfAndPredicates.st");
	}

	@Test
	public void testDanglingElse() throws Exception {
		testJava("DanglingElse", "DanglingElse", "DanglingElseAddition.st");
	}

	@Test
	public void testImplies() throws Exception {
		testJava("Implies", "Implies", "ImpliesAddition.st");
	}

	@Test
	public void testEquivalence() throws Exception {
		testJava("Equivalence", "Equivalence", "EquivalenceAddition.st");
	}

	@Test
	public void testBooleanPredicate() throws Exception {
		testJava("BooleanPredicate", "BooleanPredicate", "BooleanPredicateAddition.st");
	}

	@Ignore
	@Test
	public void testRecords() throws Exception {
		testJava("Records");
	}

	@Test
	public void testNondeterminism() throws Exception {
		testJava("Nondeterminism", "Nondeterminism", "NondeterminismAddition.st");
	}

	@Test
	public void testMapFunction() throws Exception {
		testJava("MapFunction", "MapFunction", "MapFunctionAddition.st");
	}

	@Test
	public void testRelationImage() throws Exception {
		testJava("RelationImage", "RelationImage", "RelationImageAddition.st");
	}

	@Test
	public void testEmptySet() throws Exception {
		testJava("EmptySet", "EmptySet", "EmptySetAddition.st");
	}

	@Test
	public void testSetUnion() throws Exception {
		testJava("SetUnion", "SetUnion", "SetUnionAddition.st");
	}


	@Test
	public void testCounter() throws Exception {
		testJava("Counter", "Counter", "CounterAddition.st");
	}

	@Test
	public void testBakery0() throws Exception {
		testJava("Bakery0", "Bakery0", "Bakery0Addition.st");
	}

	@Test
	public void testGCD() throws Exception {
		// TODO
		testJava("GCD");
	}

	@Test
	public void testACounter() throws Exception {
		testJava("ACounter", "ACounter", "ACounterAddition.st");
	}

	@Test
	public void testLift() throws Exception {
		testJava("Lift", "Lift", "LiftAddition.st");
	}

	@Test
	public void testTravelAgency() throws Exception {
		testJava("TravelAgency");
	}

	@Test
	public void testTrafficLight() throws Exception {
		testJava("TrafficLight", "TrafficLight", "TrafficLightAddition.st");
	}

	@Ignore
	@Test
	public void testPhonebook() throws Exception {
		// TODO
		testJava("phonebook");
	}

	@Ignore
	@Test
	public void testPhonebook6() throws Exception {
		// TODO
		testJava("phonebook6");
	}

	@Test
	public void testProject() throws Exception {
		testJava("project1/A", "A", "AAdidtion.st");
	}

	@Test
	public void testProject3() throws Exception {
		testJava("project3/A");
	}

	@Test
	public void testLiftBenchmarks() throws Exception {
		testJava("liftbenchmarks/LiftExec", "LiftExec", "LiftExecAddition.st");
	}


	@Test
	public void testSieveBenchmarks() throws Exception {
		testJava("sievebenchmarks/Sieve", "Sieve", "SieveAddition.st");
	}

	@Test
	public void testTrafficLightBenchmarks() throws Exception {
		testJava("trafficlightbenchmarks/TrafficLightExec", "TrafficLightExec", "TrafficLightExecAddition.st");
	}

	@Test
	public void testIncreasingSet() throws Exception {
		testJava("setoperationbenchmarks/IncreasingSet", "IncreasingSet", "IncreasingSetAddition.st");
	}

	@Test
	public void testSetOperation() throws Exception {
		testJava("setoperationbenchmarks/SetOperation", "SetOperation", "SetOperationAddition.st");
	}

	@Test
	public void testProject2() throws Exception {
		testJava("project2/MachineA", "MachineA", "MachineAAddition.st");
	}

	@Test
	public void testSieve() throws Exception {
		testJava("Sieve", "Sieve", "SieveAddition.st");
	}

	@Test
	public void testSieveParallel() throws Exception {
		testJava("SieveParallel", "SieveParallel", "SieveParallelAddition.st");
	}

	@Test
	public void testReset() throws Exception {
		testJava("Reset", "Reset", "ResetAddition.st");
	}

	@Test
	public void testSwap() throws Exception {
		testJava("Swap", "Swap", "SwapAddition.st");
	}


	@Test
	public void testSwap2() throws Exception {
		testJava("Swap2");
	}

	@Test
	public void testManyLocalDeclarations() throws Exception {
		testJava("ManyLocalDeclarations", "ManyLocalDeclarations", "ManyLocalDeclarationsAddition.st");
	}

	@Test
	public void testManyLocalDeclarations2() throws Exception {
		testJava("ManyLocalDeclarations2", "ManyLocalDeclarations2", "ManyLocalDeclarations2.st");
	}

	@Test
	public void testPlus() throws Exception {
		testJava("arithmetic/Plus", "Plus", "PlusAddition.st");
	}

	@Test
	public void testMinus() throws Exception {
		testJava("arithmetic/Minus", "Minus", "MinusAddition.st");
	}

	@Test
	public void testMultiply() throws Exception {
		testJava("arithmetic/Multiply", "Multiply", "MultiplyAddition.st");
	}

	@Test
	public void testDivide() throws Exception {
		testJava("arithmetic/Divide", "Divide", "DivideAddition.st");
	}


	@Test
	public void testModulo() throws Exception {
		testJava("arithmetic/Modulo", "Modulo", "ModuloAddition.st");
	}

	@Test
	public void testNegative() throws Exception {
		testJava("arithmetic/Negative", "Negative", "NegativeAddition.st");
	}

	@Ignore
	@Test
	public void testPositive() throws Exception {
		testJava("arithmetic/Positive");
	}

	/*@Test
	public void testSmallNumbers() throws Exception {
		testJava("integers/SmallNumbers", "SmallNumbersAddition.st");
	}

	@Test
	public void testBigNumbers() throws Exception {
		testJava("integers/BigNumbers", "BigNumbersAddition.st");
	}*/

	@Test
	public void testAnd() throws Exception {
		testJava("logical/And", "And", "AndAddition.st");
	}


	@Test
	public void testOr() throws Exception {
		testJava("logical/Or", "Or", "OrAddition.st");
	}


	@Test
	public void testImpliesPerformance() throws Exception {
		testJava("logical/Implies", "Implies", "ImpliesAddition.st");
	}

	@Test
	public void testNot() throws Exception {
		testJava("logical/Not");
	}

	@Test
	public void testEquivalent() throws Exception {
		testJava("logical/Equivalent", "Equivalent", "EquivalentAddition.st");
	}

	@Test
	public void testBooleanExpression() throws Exception {
		testJava("logical/BooleanExpression");
	}

	@Test
	public void testBooleanConstant() throws Exception {
		testJava("logical/BooleanConstant");
	}

	@Test
	public void testLess() throws Exception {
		testJava("comparison/Less", "Less", "LessAddition.st");
	}

	@Test
	public void testLessEqual() throws Exception {
		testJava("comparison/LessEqual", "LessEqual", "LessEqualAddition.st");
	}

	@Test
	public void testGreater() throws Exception {
		testJava("comparison/Greater", "Greater", "GreaterAddition.st");
	}


	@Test
	public void testGreaterEqual() throws Exception {
		testJava("comparison/GreaterEqual", "GreaterEqual", "GreaterEqualAddition.st");
	}


	@Test
	public void tessEqual() throws Exception {
		testJava("comparison/Equal", "Equal", "EqualAddition.st");
	}


	@Test
	public void testUnequal() throws Exception {
		testJava("comparison/Unequal", "Unequal", "UnequalAddition.st");
	}

	@Test
	public void testCardBig() throws Exception {
		testJava("setoperation_big/SetCardBig", "SetCardBig", "SetCardBigAddition.st");
	}

	@Test
	public void testCardBig2() throws Exception {
		testJava("setoperation_big/SetCardBig2");
	}


	@Test
	public void testDifferenceBig() throws Exception {
		testJava("setoperation_big/SetDifferenceBig", "SetDifferenceBig", "SetDifferenceAddition.st");
	}

	@Test
	public void testDifferenceBig2() throws Exception {
		testJava("setoperation_big/SetDifferenceBig2");
	}

	@Test
	public void testElementOfBig() throws Exception {
		testJava("setoperation_big/SetElementOfBig", "SetElementOfBig", "SetElementOfAddition.st");
	}

	@Test
	public void testElementOfBig2() throws Exception {
		testJava("setoperation_big/SetElementOfBig2");
	}

	@Test
	public void testIntersectionBig() throws Exception {
		testJava("setoperation_big/SetIntersectionBig", "SetIntersectionBig", "SetIntersectionBigAddition.st");
	}

	@Test
	public void testIntersectionBig2() throws Exception {
		testJava("setoperation_big/SetIntersectionBig2");
	}

	@Test
	public void testUnionBig() throws Exception {
		testJava("setoperation_big/SetUnionBig", "SetUnionBig", "SetUnionBigAddition.st");
	}

	@Test
	public void testUnionBig2() throws Exception {
		testJava("setoperation_big/SetUnionBig2");
	}


	@Test
	public void testCardSmall() throws Exception {
		testJava("setoperation_small/SetCardSmall", "SetCardSmall", "SetCardSmallAddition.st");
	}

	@Test
	public void testCardSmall2() throws Exception {
		testJava("setoperation_small/SetCardSmall2");
	}


	@Test
	public void testDifferenceSmall() throws Exception {
		testJava("setoperation_small/SetDifferenceSmall", "SetDifferenceSmall", "SetComülementSmallAddition.st");
	}

	@Test
	public void testDifferenceSmall2() throws Exception {
		testJava("setoperation_small/SetDifferenceSmall2");
	}


	@Test
	public void testElementOfSmall() throws Exception {
		testJava("setoperation_small/SetElementOfSmall", "SetElementOfSmall", "SetElementOfSmallAddition.st");
	}

	@Test
	public void testElementOfSmall2() throws Exception {
		testJava("setoperation_small/SetElementOfSmall2");
	}


	@Test
	public void testIntersectionSmall() throws Exception {
		testJava("setoperation_small/SetIntersectionSmall", "SetIntersectionSmall", "SetIntersectionSmallAddition.st");
	}

	@Test
	public void testIntersectionSmall2() throws Exception {
		testJava("setoperation_small/SetIntersectionSmall2");
	}

	@Test
	public void testUnionSmall() throws Exception {
		testJava("setoperation_small/SetUnionSmall", "SetUnionSmall", "SetUnionSmallAddition.st");
	}

	@Test
	public void testUnionSmall2() throws Exception {
		testJava("setoperation_small/SetUnionSmall2");
	}

	@Test
	public void testRangeBig() throws Exception {
		testJava("range_big/RangeBig", "RangeBig", "RangeBigAddition.st");
	}

	@Test
	public void testRangeCardBig() throws Exception {
		testJava("range_big/RangeCardBig", "RangeCardBig", "RangeCardBigAddition.st");
	}

	@Test
	public void testRangeCardBig2() throws Exception {
		testJava("range_big/RangeCardBig2");
	}


	@Test
	public void testRangeDifferenceBig() throws Exception {
		testJava("range_big/RangeDifferenceBig", "RangeDifferenceBig", "RangeDifferenceBigAddition.st");
	}

	@Test
	public void testRangeDifferenceBig2() throws Exception {
		testJava("range_big/RangeDifferenceBig2");
	}


	@Test
	public void testRangeElementOfBig() throws Exception {
		testJava("range_big/RangeElementOfBig", "RangeElementOfBig", "RangeElementOfBigAddition.st");
	}

	@Test
	public void testRangeElementOfBig2() throws Exception {
		testJava("range_big/RangeElementOfBig2");
	}


	@Test
	public void testRangeIntersectionBig() throws Exception {
		testJava("range_big/RangeIntersectionBig", "RangeIntersectionBig", "RangeIntersectionBigAddition.st");
	}

	@Test
	public void testRangeIntersectionBig2() throws Exception {
		testJava("range_big/RangeIntersectionBig2");
	}


	@Test
	public void testRangeUnionBig() throws Exception {
		testJava("range_big/RangeUnionBig", "RangeUnionBig", "RangeUnionBigAddition.st");
	}

	@Test
	public void testRangeUnionBig2() throws Exception {
		testJava("range_big/RangeUnionBig2");
	}


	@Test
	public void testRangeSmall() throws Exception {
		testJava("range_small/RangeSmall", "RangeSmall", "RangeSmallAddition.st");
	}


	@Test
	public void testRangeCardSmall() throws Exception {
		testJava("range_small/RangeCardSmall", "RangeCardSmall", "RangeCardSmallAddition.st");
	}

	@Test
	public void testRangeCardSmall2() throws Exception {
		testJava("range_small/RangeCardSmall2");
	}


	@Test
	public void testRangeDifferenceSmall() throws Exception {
		testJava("range_small/RangeDifferenceSmall", "RangeDifferenceSmall", "RangeDifferenceSmallAddition.st");
	}

	@Test
	public void testRangeDifferenceSmall2() throws Exception {
		testJava("range_small/RangeDifferenceSmall2");
	}

	@Test
	public void testRangeElementOfSmall() throws Exception {
		testJava("range_small/RangeElementOfSmall", "RangeElementOfSmall", "RangeElementOfSmallAddition.st");
	}

	@Test
	public void testRangeElementOfSmall2() throws Exception {
		testJava("range_small/RangeElementOfSmall2");
	}

	@Test
	public void testRangeIntersectionSmall() throws Exception {
		testJava("range_small/RangeIntersectionSmall", "RangeIntersectionSmall", "RangeIntersectionSmallAddition.st");
	}

	@Test
	public void testRangeIntersectionSmall2() throws Exception {
		testJava("range_small/RangeIntersectionSmall2");
	}

	@Test
	public void testRangeUnionSmall() throws Exception {
		testJava("range_small/RangeUnionSmall", "RangeUnionSmall", "RangeUnionSmallAddition.st");
	}

	@Test
	public void testRangeUnionSmall2() throws Exception {
		testJava("range_small/RangeUnionSmall2");
	}

	@Test
	public void testChoice() throws Exception {
		testJava("Choice", "Choice", "ChoiceAddition.st");
	}

	@Test
	public void testAssert() throws Exception {
		testJava("Assert");
	}

	@Test
	public void testCruiseController1() throws Exception {
		testJava("Cruise_finite1");
	}

	@Test
	public void testCruiseControllerk() throws Exception {
		testJava("Cruise_finite_k");
	}

	@Test
	public void testCruiseControllerDeterministic() throws Exception {
		testJava("Cruise_finite_Deterministic");
	}

	@Test
	public void testScheduler() throws Exception {
		testJava("scheduler");
	}

	@Test
	public void testCanBusTLC() throws Exception {
		testJava("CAN_BUS_tlc");
	}

	@Ignore
	@Test
	public void testCore() throws Exception {
		testJava("Core");
	}

	@Ignore
	@Test
	public void testSetLawsNAT() throws Exception {
		testJava("SetLawsNAT");
	}

	@Test
	public void SimpsonFourSlot() throws Exception {
		testJava("Simpson_Four_Slot");
	}

	@Test
	public void Train1BeebookTLC() throws Exception {
		testJava("Train_1_beebook_TLC");
	}

	@Test
	public void Train1() throws Exception {
		testJava("train_1");
	}

	@Ignore
	@Test
	public void testEarley2() throws Exception {
		testJava("earley_2");
	}

	@Ignore
	@Test
	public void testOBSW_M001() throws Exception {
		testJava("obsw_M001");
	}

	@Ignore
	@Test
	public void testRef5Switch() throws Exception {
		testJava("Ref5_Switch");
	}

	@Ignore
	@Test
	public void testrether_mch1() throws Exception {
		testJava("rether_mch1");
	}


	@Test
	public void testSetComprehension1() throws Exception {
		testJava("SetComprehension1");
	}

	@Test
	public void testSetComprehension2() throws Exception {
		testJava("SetComprehension2");
	}

	@Test
	public void testSetComprehension3() throws Exception {
		testJava("SetComprehension3");
	}

	@Test
	public void testSetComprehension4() throws Exception {
		testJava("SetComprehension4");
	}

	@Ignore
	@Test
	public void testSetComprehension5() throws Exception {
		//Does not work because of bounded variables from outer scope
		testJava("SetComprehension5");
	}

	@Test
	public void testLambda() throws Exception {
		testJava("Lambda");
	}

	@Test
	public void testLambda2() throws Exception {
		testJava("Lambda2");
	}

	@Test
	public void testQuantifiedPredicate() throws Exception {
		testJava("QuantifiedPredicate");
	}

	@Test
	public void testQuantifiedPredicate2() throws Exception {
		testJava("QuantifiedPredicate2");
	}

	@Test
	public void testQuantifiedPredicate3() throws Exception {
		testJava("QuantifiedPredicate3");
	}

	@Test
	public void testQuantifiedExpression1() throws Exception {
		testJava("QuantifiedExpression1");
	}

	@Test
	public void testQuantifiedExpression2() throws Exception {
		testJava("QuantifiedExpression2");
	}

	@Test
	public void testQuantifiedExpression3() throws Exception {
		testJava("QuantifiedExpression3");
	}

	@Test
	public void testQuantifiedExpression4() throws Exception {
		testJava("QuantifiedExpression4");
	}

	@Test
	public void testQuantifiedExpression5() throws Exception {
		testJava("QuantifiedExpression5");
	}


	@Test
	public void testGeneralizedUnion() throws Exception {
		testJava("GeneralizedUnion");
	}

	@Test
	public void testGeneralizedIntersection() throws Exception {
		testJava("GeneralizedIntersection");
	}


	@Test
	public void testFunctionalOverride() throws Exception {
		testJava("FunctionalOverride");
	}

	@Test
	public void testFunctionalOverride2() throws Exception {
		testJava("FunctionalOverride2");
	}

	@Test
	public void testFunctionalOverride3() throws Exception {
		testJava("FunctionalOverride3");
	}

	@Test
	public void testOverride() throws Exception {
		testJava("Override");
	}

	@Test
	public void testPow() throws Exception {
		testJava("Pow");
	}

	@Test
	public void testPow1() throws Exception {
		testJava("Pow1");
	}

	@Test
	public void testFin() throws Exception {
		testJava("Fin");
	}

	@Test
	public void testFin1() throws Exception {
		testJava("Fin1");
	}

	@Test
	public void testId() throws Exception {
		testJava("Id");
	}

	@Test
	public void testParallelProduct() throws Exception {
		testJava("ParallelProduct");
	}

	@Test
	public void testDirectProduct() throws Exception {
		testJava("DirectProduct");
	}

	@Test
	public void testComposition() throws Exception {
		testJava("Composition");
	}

	@Test
	public void testProjection1() throws Exception {
		testJava("Projection1");
	}

	@Test
	public void testProjection2() throws Exception {
		testJava("Projection2");
	}

	@Test
	public void testAppend() throws Exception {
		testJava("Append");
	}


	@Ignore
	@Test
	public void testConc() throws Exception {
		testJava("Conc");
	}

	@Test
	public void testConcat() throws Exception {
		testJava("Concat");
	}

	@Test
	public void testDrop() throws Exception {
		testJava("Drop");
	}

	@Test
	public void testEmptySequence() throws Exception {
		testJava("EmptySequence");
	}

	@Test
	public void testEnumeratedSequence() throws Exception {
		testJava("EnumeratedSequence");
	}

	@Test
	public void testFirstElementSequence() throws Exception {
		testJava("FirstElementSequence");
	}

	@Test
	public void testFrontSequence() throws Exception {
		testJava("FrontSequence");
	}

	@Test
	public void testLastElementSequence() throws Exception {
		testJava("LastElementSequence");
	}

	@Test
	public void testPrepend() throws Exception {
		testJava("Prepend");
	}

	@Test
	public void testReverse() throws Exception {
		testJava("ReverseSequence");
	}

	@Test
	public void testSizeOfSequence() throws Exception {
		testJava("SizeOfSequence");
	}

	@Test
	public void testTailSequence() throws Exception {
		testJava("TailSequence");
	}

	@Test
	public void testTake() throws Exception {
		testJava("Take");
	}

	@Test
	public void testSequenceOperateRelation() throws Exception {
		testJava("SequenceOperateRelation");
	}

	@Test
	public void testPred() throws Exception {
		testJava("Pred");
	}

	@Test
	public void testSucc() throws Exception {
		testJava("Succ");
	}

	@Test
	public void testIterate() throws Exception {
		testJava("Iterate");
	}

	@Test
	public void testClosure() throws Exception {
		testJava("Closure");
	}

	@Test
	public void testClosure1() throws Exception {
		testJava("Closure1");
	}

	private void cleanUp(String path) {
		File file = new File(path);
		if (file.exists()) {
			file.delete();
		}
	}

}
