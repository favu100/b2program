MACHINE LargeFunction1
CONSTANTS n, fun
PROPERTIES n=20000 &
 fun = %(x).(x:0..n| (x+x) mod n)
VARIABLES x
INVARIANT
 x: 0..n
INITIALISATION
  x:= 1
OPERATIONS
  incx = x:= (x+2) mod n;
  setf = BEGIN x:= fun(x) END
END

/*
probcli --model-check benchmarks/model_checking/ProB/micro/LargeFunction1.mch -disable_time_out

Model checking time: 1188 ms (1218 ms walltime)
States analysed: 20001
Transitions fired: 40002

total time:	0m2.446s


time make LargeFunction1 LANGUAGE=java DIRECTORY=benchmarks/model_checking/ProB/micro

Number of States: 20000
Number of Transitions: 40000

real	0m57.713s

for n=10000 it was about 10 seconds

*/