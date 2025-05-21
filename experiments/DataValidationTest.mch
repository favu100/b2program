MACHINE DataValidationTest
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
   counter :0..n &
   error : BOOL &
   checked : BOOL
INITIALISATION counter := 0 || error := FALSE || checked := FALSE
OPERATIONS
  Validate = BEGIN
     WHILE counter < n DO
        counter := counter + 1;
        IF counter /: ids THEN
           error := TRUE
        //ELSIF counter: 0..n & (counter mod 100) /: 0..99 THEN
        ELSIF counter|->100 : value  THEN
        //ELSIF value(counter) /: 0..99 THEN
           error := TRUE
        ELSIF card(ids_for_value[{value(counter)}]) < n/100 THEN
           error := TRUE
        END
        INVARIANT counter:INTEGER
        VARIANT n-counter
    END ;
        checked := TRUE
  END
END

/*

PROB:
$ make probmc
time probcli DataValidationTest.mch --model-check -disable-timeout -p MAX_OPERATIONS 100 -p MAX_INITIALISATIONS 100
% Runtime for SOLUTION for SETUP_CONSTANTS: 1 ms (walltime: 0 ms)
% Runtime to FINALISE SETUP_CONSTANTS: 0 ms (walltime: 0 ms)

ALL OPERATIONS COVERED
% Model checking finished, all open states visited
Model checking time: 2539 ms (2728 ms walltime)
States analysed: 3
Transitions fired: 4
No counter example found. ALL states visited.


        3.49 real         3.08 user         0.04 sys
        
B2PROGRAM BIGINT=true:
$ make javamc
Generating Java Model Checker file DataValidationTest.java from B file DataValidationTest.mch, BIGINT=true
#java -jar B2Program-all-0.1.0-SNAPSHOT.jar java true -2147483648 2147483647 10 false true DataValidationTest.mch
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -bi true -min -2147483648 --max 2147483647 -dss 10 -cs false -mc true -f DataValidationTest.mch
cd ../btypes_big_integer && ./gradlew fatJar && cp build/libs/btypes_big_integer-all.jar ../experiments/btypes.jar && cd ../experiments

BUILD SUCCESSFUL in 374ms
2 actionable tasks: 2 up-to-date
Compiling Java Model Checker file DataValidationTest.java
time javac -cp .:btypes.jar DataValidationTest.java
        0.47 real         1.43 user         0.04 sys
Running Java Model Checker file DataValidationTest.java, THREADS=1, CACHING=false
time java -cp .:btypes.jar DataValidationTest.java df 1 false
Starting Model Checking, Search: DFS, Threads: 1, Caching: false
MODEL CHECKING SUCCESSFUL
Number of States: 2
Number of Transitions: 2
Model Checking Time: 32573 ms
       33.44 real        36.13 user         0.39 sys

*/