MACHINE PowStruct

VARIABLES  x

INVARIANT  x : POW(struct(a: INT, b : INT, c : INT))

INITIALISATION x := {rec(a:1, b:2, c:3)}

OPERATIONS

	op1 = SELECT x : POW(struct(a: INT, b : INT, c : INT)) THEN x := {rec(a:1, b:2, c:4)} END

END