MACHINE
    While2

VARIABLES xx

INVARIANT xx : INTEGER
INITIALISATION xx := 1

OPERATIONS
Inc =
    WHILE xx >= 1 & xx <= 10 DO
      xx := xx + 1
    INVARIANT 1=1
    VARIANT 10 - xx
    END
END
