MACHINE
    DanglingElseWD

VARIABLES xx

INVARIANT xx : INT
INITIALISATION xx := 1

OPERATIONS
out <-- calculate =
    IF xx = 1 THEN
        IF xx = 1 THEN
            xx := 42
        END;
        out := xx
    ELSE
        xx := 42;
        out := xx
    END;

out <-- getRes = out := xx

END
