MACHINE StructUnequal

VARIABLES  x

INVARIANT  x : POW(struct(a: INT, b: INT, c: INT))

INITIALISATION x := {}

OPERATIONS

	op1 = SELECT x /= struct(a: INT, b: INT, c: INT) THEN x := {} END

END