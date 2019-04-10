MACHINE NameCollision

VARIABLES switch

INVARIANT switch:INT
INITIALISATION switch := 5

OPERATIONS
    xx <-- op1(bb, switch) =
        PRE bb : 1..10 & switch : INT THEN
	        xx := switch + bb
        END;
    out <-- getRes = out := switch

END