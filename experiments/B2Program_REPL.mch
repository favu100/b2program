MACHINE B2Program_REPL
SETS COLOURS = {red,green,blue}
VARIABLES pc, result
INVARIANT pc<1 & result <: ((1..4)*(1..4))
INITIALISATION pc:=0 || result := {}
OPERATIONS
  ComputeExpression(res) = SELECT
        res <: (1..4)*(1..4) &  closure1(res)=(1..4)*(1..4)
     THEN
    pc := pc+1 || result := res
  END
END 

/*
$ make B2Program_REPL LANGUAGE=java DIRECTORY=experiments 
java -jar B2Program-all-0.1.0-SNAPSHOT.jar -l java -mc true -f experiments/B2Program_REPL.mch
javac -cp .:btypes.jar B2Program_REPL.java
java -cp .:btypes.jar B2Program_REPL mixed 1 false
Starting Model Checking, Search: MIXED, Threads: 1, Caching: false
INVARIANT CONJUNCT VIOLATED: _check_inv_1
INVARIANT VIOLATED
COUNTER EXAMPLE TRACE: 

* Step 0:
_get_pc: 1
_get_result: {(1 |-> 4), (2 |-> 1), (2 |-> 2), (3 |-> 2), (4 |-> 1), (4 |-> 3)}
Number of States: 51393
Number of Transitions: 51392
Model Checking Time: 118194 ms

>>> res <: (1..4)*(1..4) &  closure1(res)=(1..4)*(1..4)
Existentially Quantified Predicate over res is TRUE
Solution:
       res = {(1|->1),(1|->2),(2|->1),(2|->2),(2|->3),(3|->1),(3|->2),(3|->3),(3|->4),(4|->1)}

>>> $
% Type: pred
% Eval Time: 2194 ms (2204 ms walltime) + Normalisation: 0 ms (0 ms walltime) + State expansion: 0 ms walltime


>>> :clingo-double-check res <: (1..4)*(1..4) &  closure1(res)=(1..4)*(1..4)
! Restricting infinite integer base type to:-1,4
 CLINGO walltime: 36 ms, exit(10)
Parsed clingo model 1 with 6 relevant atoms
double check ok
% Solve using solver double_check(clingo): 1 ms (39 ms walltime).
PREDICATE is TRUE
Solution: 
       res = {(1|->3),(2|->3),(3|->2),(3|->4),(4|->1),(4|->2)}
       
       
*/