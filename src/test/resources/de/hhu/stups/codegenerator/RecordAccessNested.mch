MACHINE RecordAccessNested

VARIABLES x, y

INVARIANT
	x : INTEGER +-> (INTEGER +-> INTEGER) &
	y : INTEGER

INITIALISATION
	x := {1|->{2|->3}, 2|->{3|->4}};
	y := 0

OPERATIONS
	test = BEGIN
	    y := x(1)(2);
		x(1)(2) := 4
	END

END