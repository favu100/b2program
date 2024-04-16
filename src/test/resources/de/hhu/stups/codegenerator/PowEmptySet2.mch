MACHINE PowEmptySet2

VARIABLES  f

INVARIANT  f <: INTEGER

INITIALISATION f := {}

OPERATIONS

	calculate = SELECT {} : POW(INT) THEN f := {1,2} END;
	out <-- getRes = out := card(f)

END