MACHINE MachineA

INCLUDES MachineB

CONSTANTS k2

PROPERTIES k2 : INTEGER

VALUES k2 = 1

VARIABLES a

INVARIANT a : INTEGER

INITIALISATION a := 1

OPERATIONS
    IncX1 = SELECT a < 10 THEN IncX END;

    IncX2 = IF a < 10 THEN IncX ELSE IncX END


END