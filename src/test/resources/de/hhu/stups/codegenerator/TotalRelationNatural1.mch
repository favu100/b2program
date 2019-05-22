MACHINE TotalRelationNatural1

VARIABLES  x

INVARIANT  x : NATURAL1 <-> {1,2,3}

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op1 = SELECT x : NATURAL1 <<-> {1,2,3} THEN x := {1|->2} END

END