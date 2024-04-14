MACHINE NotBoolean

VARIABLES  b

INVARIANT  b : BOOL

INITIALISATION b := TRUE

OPERATIONS

	op = IF b /: BOOL THEN b := FALSE ELSE b := TRUE END;
    out <-- getRes = out := b

END