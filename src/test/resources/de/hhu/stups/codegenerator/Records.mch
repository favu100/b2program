MACHINE
    Records

VARIABLES xx, yy, switch

INVARIANT xx : INT & yy : struct(a: INT, b: INT, c: INT) & switch : BOOL
INITIALISATION xx := 1; yy := rec(a:1,b:2,c:3); switch := TRUE

OPERATIONS
out <-- Inc(pp) =
    IF xx < 10 THEN
        xx := xx + pp; out := xx
    ELSIF xx < 2 THEN
        xx := xx - pp; out := xx + 1
    ELSIF xx > 3 THEN
        xx := 1; out := xx
    ELSE
        xx := 2; out := xx
    END

END
