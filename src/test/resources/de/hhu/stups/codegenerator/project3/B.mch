MACHINE
    B

VARIABLES aa, bb
   
INVARIANT aa : INT & bb : BOOL
INITIALISATION aa := 0 || bb := bool(1=1)

OPERATIONS
  aa, bb <-- operateRet = aa := 1 || bb := bool(1=2)

END
