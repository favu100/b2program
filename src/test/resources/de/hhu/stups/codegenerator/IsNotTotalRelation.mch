MACHINE IsNotTotalRelation

VARIABLES  x

INVARIANT  x : {1,2,3} <-> {1,2,3}

INITIALISATION x := {1|->2, 2|->3, 3 |-> 2}

OPERATIONS

	op = SELECT x /: {1,2,3,4} <<-> {1,2,3} THEN x := {1|->2} END;
	out <-- getRes = out := card(x)

END