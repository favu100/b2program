MACHINE LargeRelation1
CONSTANTS n, rel1
PROPERTIES n=500 &
 rel1 = {x,y | x:0..n & y:0..n & ( y = (x+x) mod n or y = x mod n)}
VARIABLES x
INVARIANT
 x: 0..n
INITIALISATION
  x:= 1
OPERATIONS
  incx = x:= (x+2) mod n;
  setr = BEGIN x:= max(rel1[{x}]) END;
  setri = BEGIN x:= min({n} \/ rel1~[{x}]) END;
  setrr = BEGIN x:= max(rel1[rel1[{x}]]) END;
  setrri = BEGIN x:= max({0} \/ (rel1 \/ rel1~)[{x,x+1}]) END;
  setrri2(p) = SELECT p : (rel1 \/ rel1~)[{x,x+1}] THEN
     x := p
  END
END

/*
$ time probcli --model-check benchmarks/model_checking/ProB/micro/LargeRelation1.mch -disable_time_out
% Runtime for SOLUTION for SETUP_CONSTANTS: 710 ms (walltime: 714 ms)
% Runtime to FINALISE SETUP_CONSTANTS: 0 ms (walltime: 0 ms)

ALL OPERATIONS COVERED
% Model checking finished, all open states visited
Model checking time: 840 ms (845 ms walltime)
States analysed: 502
Transitions fired: 5498
No counter example found. ALL states visited.


real	0m2.736s
user	0m2.538s
sys	0m0.115s

$ time make LargeRelation1 LANGUAGE=java DIRECTORY=benchmarks/model_checking/ProB/micro
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -mc true -f benchmarks/model_checking/ProB/micro/LargeRelation1.mch
cp benchmarks/model_checking/ProB/micro/*.java .
javac -cp .:btypes.jar LargeRelation1.java
java -cp .:btypes.jar LargeRelation1 mixed 1 false
MODEL CHECKING SUCCESSFUL
Number of States: 501
Number of Transitions: 5496

real	0m3.669s
user	0m7.909s
sys	0m0.528s


*/