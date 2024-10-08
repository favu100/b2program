MACHINE ClosureBool

VARIABLES  f, s

INVARIANT  f : BOOL --> BOOL & s : BOOL --> BOOL

INITIALISATION f := {TRUE |-> FALSE}; s := {}

OPERATIONS

	calculate = BEGIN s := closure(f) END;
	out <-- getRes = out := card(s)

END