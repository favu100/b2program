MACHINE SurjectionRelationNatural1

VARIABLES  x

INVARIANT  x : {1,2,3} <-> INTEGER

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op1 = SELECT x : {1,2,3} <->> NATURAL1 THEN x := {1|->2} END

END