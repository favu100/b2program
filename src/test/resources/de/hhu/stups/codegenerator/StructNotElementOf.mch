MACHINE StructNotElementOf

VARIABLES  x

INVARIANT  x : struct(a: INT, b: INT, c: INT)

INITIALISATION x := rec(a:1, b:2, c:3)

OPERATIONS

	op = IF x /: struct(a: INT, b: INT, c: INT) THEN x := rec(a:1, b:2, c:4) ELSE x := rec(a:1, b:2, c:5) END;
	out <-- getRes = out := x

END