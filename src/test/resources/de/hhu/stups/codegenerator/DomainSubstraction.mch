MACHINE DomainSubstraction

VARIABLES  f, g, r

INVARIANT  f : POW(INT * INT) & g : POW(INT) & r : POW(INT*INT)

INITIALISATION f := {(1 |-> 2), (2 |-> 3), (3 |-> 4), (4 |-> 5)}; g := {1,2}; r := {}

OPERATIONS

	calculate = BEGIN r := g <<| f END;
	out <-- getRes = out := card(r)

END