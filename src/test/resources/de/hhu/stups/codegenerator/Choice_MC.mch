MACHINE
    Choice_MC

VARIABLES xx, yy

INVARIANT xx : INTEGER & yy : INTEGER
INITIALISATION xx := 0 || yy := 5

OPERATIONS
calculate =
    CHOICE xx := min({xx, yy})
        OR xx := max({xx, yy})
        OR xx := 1
        OR xx := 2
    END

END
