MACHINE NotString

VARIABLES  str

INVARIANT  str : STRING

INITIALISATION str := "Hallo"

OPERATIONS

	op = IF str /: STRING THEN str := "Welt" ELSE str := "Hallo" END;
    out <-- getRes = out := str

END