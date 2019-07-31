MACHINE RecordAccessNested2

VARIABLES x, y, res

INVARIANT
    x : struct(a : struct(b : struct(c : INTEGER))) &
    y : INTEGER &
    res : INTEGER

INITIALISATION
	x := rec(a:rec(b:rec(c:2)));
	y := 0;
	res := -1

OPERATIONS
	calculate = BEGIN
	    y := x'a'b'c;
		x'a'b'c := 10
	END;

	out <-- getRes = BEGIN
	    out := x'a'b'c
	END



END