MACHINE
    RecordsAccess

VARIABLES xx, yy, switch

INVARIANT xx : INT & yy : struct(a: INT, b: INT, c: INT) & switch : BOOL
INITIALISATION xx := 1; yy := rec(a:1,b:2,c:3); switch := TRUE

OPERATIONS
out <-- calc = xx := yy'a

END
