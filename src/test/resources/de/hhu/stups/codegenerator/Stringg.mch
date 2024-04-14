MACHINE Stringg

VARIABLES  str

INVARIANT  str : STRING

INITIALISATION str := "Hallo"

OPERATIONS

	op = SELECT str : STRING THEN str := "Welt" END;
    out <-- getRes = out := str

END