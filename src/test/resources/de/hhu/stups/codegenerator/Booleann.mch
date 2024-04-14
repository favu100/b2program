MACHINE Booleann

VARIABLES  b

INVARIANT  b : BOOL

INITIALISATION b := TRUE

OPERATIONS

	op = SELECT b : BOOL THEN b := FALSE END;
    out <-- getRes = out := b

END