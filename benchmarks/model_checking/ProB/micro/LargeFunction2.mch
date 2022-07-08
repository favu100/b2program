MACHINE LargeFunction2
CONSTANTS n, fun
PROPERTIES n=1500 &
 fun = %(x).(x:0..n| (x+x) mod n)
VARIABLES x, f
INVARIANT
 x:0..n &
 f: 0..n --> 0..n
INITIALISATION
  x:= 0 || f := fun
OPERATIONS
  incx = BEGIN f(x) := 0 || x := (x+1) mod n END
END

/*
$ time probcli --model-check benchmarks/model_checking/ProB/micro/LargeFunction2.mch -disable_time_out
% Runtime for SOLUTION for SETUP_CONSTANTS: 103 ms (walltime: 106 ms)
% Runtime to FINALISE SETUP_CONSTANTS: 0 ms (walltime: 0 ms)

ALL OPERATIONS COVERED
% Model checking finished, all open states visited
Model checking time: 3101 ms (3371 ms walltime)
States analysed: 3001
Transitions fired: 3002
No counter example found. ALL states visited.


real	0m5.085s
user	0m4.828s
sys	0m0.262s

$ time make LargeFunction2 LANGUAGE=java DIRECTORY=benchmarks/model_checking/ProB/micro
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -mc true -f benchmarks/model_checking/ProB/micro/LargeFunction2.mch
cp benchmarks/model_checking/ProB/micro/*.java .
javac -cp .:btypes.jar LargeFunction2.java
java -cp .:btypes.jar LargeFunction2 mixed 1 false
MODEL CHECKING SUCCESSFUL
Number of States: 3000
Number of Transitions: 3000

real	0m9.959s
user	0m14.681s
sys	0m0.633s

*/