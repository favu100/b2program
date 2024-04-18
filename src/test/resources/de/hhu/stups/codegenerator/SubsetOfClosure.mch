MACHINE SubsetOfClosure

VARIABLES  x

INVARIANT  x <: INTEGER * INTEGER

INITIALISATION x := {1 |-> 4}

OPERATIONS

	op = SELECT x <: closure({1 |-> 2, 2 |-> 3, 3 |-> 4}) THEN x := {2 |-> 2} END;
	out <-- getRes = out := x

END