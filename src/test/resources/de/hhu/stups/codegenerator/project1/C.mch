MACHINE
    C

INCLUDES switch

VARIABLES aa

INVARIANT aa:INT
INITIALISATION aa := 5

OPERATIONS
    op1(switch) =
        PRE switch : INT THEN
            aa := switch
        END
END