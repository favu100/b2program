MACHINE DataValidationTestSmallStep
 // Rather than one big WHILE loop we have individual validation steps
 // Can be checked by TLC

DEFINITIONS
  SET_PREF_TIME_OUT == 120000
CONSTANTS
  n,
  ids, value, ids_for_value
PROPERTIES
  n = 20001 & // with n>20000 value is kept symbolic
  ids = 1..n &
  value = %x.(x:1..n | x mod 100) &
  ids_for_value = value~
VARIABLES counter, error, checked
INVARIANT
   counter :1..n &
   error : BOOL &
   checked : BOOL
INITIALISATION counter := 1 || error := FALSE || checked := FALSE
OPERATIONS
  Validate =
     SELECT counter < n THEN
        counter := counter + 1 ||
        IF counter /: ids THEN
           error := TRUE
        //ELSIF counter: 0..n & (counter mod 100) /: 0..99 THEN
        ELSIF counter|->100 : value  THEN
        //ELSIF value(counter) /: 0..99 THEN
           error := TRUE
        ELSIF card(ids_for_value[{value(counter)}]) < n/100 THEN
           error := TRUE
        END
     END;
   Finished = SELECT counter >= n THEN
        checked := TRUE
  END
END

/*
$ make probmc
time probcli DataValidationTestSmallStep.mch --model-check -disable-timeout -p MAX_OPERATIONS 100 -p MAX_INITIALISATIONS 100
% Runtime for SOLUTION for SETUP_CONSTANTS: 1 ms (walltime: 0 ms)
% Runtime to FINALISE SETUP_CONSTANTS: 0 ms (walltime: 0 ms)

ALL OPERATIONS COVERED
% Model checking finished, all open states visited
Model checking time: 3588 ms (3609 ms walltime)
States analysed: 20003
Transitions fired: 20004
No counter example found. ALL states visited.

        4.37 real         3.96 user         0.04 sys

$ probcli -execute_all /Users/leuschel/git_root/prob_examples/public_examples/B/PerformanceTests/DataValidationTestSmallStep.mch
% Runtime for SOLUTION for SETUP_CONSTANTS: 69 ms (walltime: 71 ms)
Infinite loop reached after 20005 steps (looping on Finished).
% Runtime for -execute: 5207 ms (with gc: 27297 ms, walltime: 27624 ms); time since start: 29316 ms
$ probcli -execute_all /Users/leuschel/git_root/prob_examples/public_examples/B/PerformanceTests/DataValidationTestSmallStep.mch -noinv
% Runtime for SOLUTION for SETUP_CONSTANTS: 73 ms (walltime: 75 ms)
Infinite loop reached after 20005 steps (looping on Finished).
% Runtime for -execute: 4703 ms (with gc: 26740 ms, walltime: 27034 ms); time since start: 28730 ms

      23.126 sec. for 126 garbage collections which collected 919 356 496 bytes

Result with TLC:

Parsing time: 454 ms
Translation time: 61 ms
Model checking time: 102 sec
States analysed: 20002
Transitions fired: 20003
Result: NoError

With B2Program BIGINT=true

$ make javamc
Creating B2Program JAR
cd .. && ./gradlew fatJar && cd experiments

BUILD SUCCESSFUL in 1s
3 actionable tasks: 1 executed, 2 up-to-date
Copying B2Program JAR
cp ../build/libs/B2Program-all-0.1.0-SNAPSHOT.jar .
Generating Java Model Checker file DataValidationTestSmallStep.java from B file DataValidationTestSmallStep.mch, BIGINT=true
#java -jar B2Program-all-0.1.0-SNAPSHOT.jar java true -2147483648 2147483647 10 false true DataValidationTestSmallStep.mch
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -bi true -min -2147483648 --max 2147483647 -dss 10 -cs false -mc true -f DataValidationTestSmallStep.mch
Compiling Java Model Checker file DataValidationTestSmallStep.java
time javac -cp .:btypes.jar DataValidationTestSmallStep.java
        0.48 real         1.53 user         0.05 sys
Running Java Model Checker file DataValidationTestSmallStep.java, THREADS=1, CACHING=false
time java -cp .:btypes.jar DataValidationTestSmallStep.java df 1 false
Starting Model Checking, Search: DFS, Threads: 1, Caching: false
MODEL CHECKING SUCCESSFUL
Number of States: 20002
Number of Transitions: 20002
Model Checking Time: 31474 ms
       32.35 real        35.30 user         0.39 sys
*/
