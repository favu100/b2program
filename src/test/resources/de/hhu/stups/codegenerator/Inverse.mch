MACHINE Inverse

VARIABLES  f, r

INVARIANT  f : POW(INT * INT) & r : POW(INT * INT)

INITIALISATION f := {(1 |-> 2), (2 |-> 3), (3 |-> 4), (4 |-> 5)}; r := {}

OPERATIONS

	calculate = BEGIN r := f~ END;
	out <-- getRes = out := card(r)

END