MACHINE TotalRelationInteger

VARIABLES  x

INVARIANT  x : INTEGER <-> {1,2,3}

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op1 = SELECT x : INTEGER <<-> {1,2,3} THEN x := {1|->2} END

END