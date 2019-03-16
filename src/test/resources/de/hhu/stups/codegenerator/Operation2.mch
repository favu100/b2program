MACHINE Operation2

VARIABLES xx
   
INVARIANT xx : INT
INITIALISATION xx := 1

OPERATIONS
out, xx <-- Inc(pp) =
    PRE pp : 1..10 THEN xx := xx + pp; out := xx END

END
