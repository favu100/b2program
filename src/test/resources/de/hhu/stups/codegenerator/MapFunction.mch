MACHINE
    MapFunction

VARIABLES xx, yy, aa, switch

INVARIANT xx : INT & yy: POW(INT * INT) & aa : INT & switch : BOOL
INITIALISATION xx := 1; yy := {1 |-> 2, 2 |-> 3, 3|-> 4}; switch := TRUE; aa := yy(1)

OPERATIONS
out <-- Inc(pp) =
    IF xx = 1 & xx < 10 THEN
        xx := xx + pp; out := xx
    ELSIF xx < 2 THEN
        xx := xx - pp; out := xx + 1
    ELSIF xx > 3 THEN
        xx := 1; out := xx
    ELSE
        xx := 2; out := xx
    END;

out <-- getYY =
    BEGIN
        out := yy
    END

END
