MACHINE StructSubset

VARIABLES  x

INVARIANT  x <: struct(a: INT, b: INT, c: INT)

INITIALISATION x := {rec(a:1, b:2, c:3)}

OPERATIONS

	op1 = SELECT x <: struct(a: INT, b: INT, c: INT) THEN x := {} END

END