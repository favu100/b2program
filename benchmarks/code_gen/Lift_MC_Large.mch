MACHINE Lift_MC_Large

VARIABLES  level

INVARIANT  level >= 0 & level <= 1000000

INITIALISATION level := 0

OPERATIONS

	inc = PRE level<1000000 THEN level := level + 1 END ;
	dec = PRE level>0 THEN level := level - 1 END

END