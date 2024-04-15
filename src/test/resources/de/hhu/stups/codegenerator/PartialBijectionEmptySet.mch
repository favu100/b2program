MACHINE PartialSurjectionEmptySet

VARIABLES  x

INVARIANT  x : {1,2,3} <-> {1,2,3}

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op = SELECT {} : {1,2,3} >+>> {1,2,3} THEN x := {1|->2} END;
    out <-- getRes = out := card(x)

END