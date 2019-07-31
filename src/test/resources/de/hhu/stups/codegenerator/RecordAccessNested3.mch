MACHINE RecordAccessNested3

VARIABLES x, y, res

INVARIANT
    x : struct(a : struct(b : struct(c : struct(d : INTEGER)))) &
    y : INTEGER &
    res : INTEGER

INITIALISATION
	x := rec(a:rec(b:rec(c:rec(d:3))));
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x'a'b'c'd;
		x'a'b'c'd := 15
	END;

	out <-- getRes = BEGIN
	    out := x'a'b'c'd
	END



END