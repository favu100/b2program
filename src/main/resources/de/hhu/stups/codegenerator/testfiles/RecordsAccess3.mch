MACHINE
    RecordsAccess3

VARIABLES xx, yy, switch

INVARIANT xx : INT & yy : struct(a: INT, b: struct(x:INT, y:INT), c: INT) & switch : BOOL
INITIALISATION xx := 1; yy := rec(a:1,b:rec(x:3,y:2),c:3); switch := TRUE

OPERATIONS
calc = yy'a'x := 2

END
