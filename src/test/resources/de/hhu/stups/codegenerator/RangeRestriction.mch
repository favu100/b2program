MACHINE RangeRestriction

VARIABLES  f, g, r

INVARIANT  f : POW(INT * INT) & g : POW(INT) & r : POW(INT*INT)

INITIALISATION f := {(1 |-> 2), (2 |-> 3), (3 |-> 4), (4 |-> 5)}; g := {1,2}; r := {}

OPERATIONS

	calculate = BEGIN r := f |> g END;
	out <-- getRes = out := r

END