MACHINE LargeFunction0
CONSTANTS n, fun
PROPERTIES n=1000 &
 fun = %(x,y).(x:0..n & y:0..n | (x+y) mod n)
VARIABLES x
INVARIANT
 x: 0..n &
 (x,x) : dom(fun)  // this slows down B2Program
INITIALISATION
  x:= 1
OPERATIONS
  //incx = x:= (x+1) mod n;
  //setf = BEGIN x:= fun(x,x) END;
  setpara(p) = SELECT p:0..n & fun(x,p) = 0 THEN
    x := p
  END;
  setcomplex = BEGIN x:= first( [x,0,1,2] ; (%xx.(xx:0..n|fun(xx,xx)))) END
END

/*
$ time probcli --model-check benchmarks/model_checking/ProB/micro/LargeFunction0.mch -disable_time_out
% Runtime for SOLUTION for SETUP_CONSTANTS: 52 ms (walltime: 53 ms)
% Runtime to FINALISE SETUP_CONSTANTS: 0 ms (walltime: 0 ms)

ALL OPERATIONS COVERED
% Model checking finished, all open states visited
Model checking time: 783 ms (788 ms walltime)
States analysed: 107
Transitions fired: 214
No counter example found. ALL states visited.


real	0m2.289s
user	0m2.193s
sys	0m0.137s

$ time make LargeFunction0 LANGUAGE=java DIRECTORY=benchmarks/model_checking/ProB/micro
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -mc true -f benchmarks/model_checking/ProB/micro/LargeFunction0.mch
cp benchmarks/model_checking/ProB/micro/*.java .
javac -cp .:btypes.jar LargeFunction0.java
java -cp .:btypes.jar LargeFunction0 mixed 1 false
MODEL CHECKING SUCCESSFUL
Number of States: 106
Number of Transitions: 212

real	2m5.491s
user	2m12.072s
sys	0m1.271s

*/