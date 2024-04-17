MACHINE IsNotInDomainSubstraction

VARIABLES  x

INVARIANT  x : INTEGER * INTEGER

INITIALISATION x := 1 |-> 1

OPERATIONS

	op = SELECT x /: {1,4} <<| {1 |-> 1, 2 |-> 3} THEN x := 2 |-> 2 END;
	out <-- getRes = out := x

END