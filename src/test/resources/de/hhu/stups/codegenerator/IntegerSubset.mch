MACHINE IntegerSubset

VARIABLES  x

INVARIANT  x : POW(INTEGER)

INITIALISATION x := {1,2,3}

OPERATIONS

	op1 = SELECT x <: INTEGER THEN x := {1} END

END