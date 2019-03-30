MACHINE
    B

VARIABLES aa, bb
   
INVARIANT aa : INT & bb : INT
INITIALISATION aa := 0 || bb := 1

OPERATIONS
  operateAA = aa := bb;
  operateBB = bb := aa

END
