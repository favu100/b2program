MACHINE RecordAccessNested

VARIABLES x, y, res

INVARIANT
    x : struct(a : struct(b : INTEGER)) &
    y : INTEGER &
    res : INTEGER

INITIALISATION
	x := rec(a:rec(b:2));
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x'a'b;
		x'a'b := 4
	END;

	out <-- getRes = BEGIN
	    out := x'a'b
	END



END