MACHINE PartialSurjection

VARIABLES  x

INVARIANT  x : {1,2,3} <-> {1,2,3}

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op1 = SELECT x : {1,2,3} +->> {1,2,3} THEN x := {1|->2} END

END