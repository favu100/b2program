MACHINE
    IfAndPredicates

VARIABLES xx

INVARIANT xx : INT
INITIALISATION xx := 1

OPERATIONS
out <-- Inc(pp) =
    IF xx < 10 & xx < 5 THEN
        xx := xx + pp; out := xx
    ELSIF xx < 2 THEN
        xx := xx - pp; out := xx + 1
    ELSIF xx > 3 THEN
        xx := 1; out := xx
    ELSE
        xx := 2; out := xx
    END;

out <-- getRes = out := xx

END
