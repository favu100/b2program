MACHINE
    Choice

VARIABLES xx

INVARIANT xx : INT
INITIALISATION xx := 1

OPERATIONS
calculate(pp) =
    CHOICE xx := xx + pp
        OR xx := xx - pp
        OR xx := 1
        OR xx := 2
    END;

out <-- getRes = out := card({xx} /\ {-1,1,2,4})

END
