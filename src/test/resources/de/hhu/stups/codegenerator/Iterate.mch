MACHINE Iterate

VARIABLES  f, s

INVARIANT  f : BOOL --> BOOL & s : BOOL --> BOOL

INITIALISATION f := {TRUE, FALSE}; s := {}

OPERATIONS

	calculate = BEGIN s := iterate(f,5) END;
	out <-- getRes = out := card(s)

END