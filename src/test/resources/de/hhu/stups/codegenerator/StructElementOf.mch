MACHINE StructElementOf

VARIABLES  x

INVARIANT  x : struct(a: INT, b: INT, c: INT)

INITIALISATION x := rec(a:1, b:2, c:3)

OPERATIONS

	op = SELECT x : struct(a: INT, b: INT, c: INT) THEN x := rec(a:1, b:2, c:4) END;
    out <-- getRes = out := x

END