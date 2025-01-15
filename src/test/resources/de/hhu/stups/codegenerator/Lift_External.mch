MACHINE Lift_External

VARIABLES  level

INVARIANT  level : 0..100 /* NAT */

INITIALISATION level := 0

OPERATIONS

	inc = PRE level<100 THEN level := level + 1 END ;
	dec = PRE level>0 THEN level := level - 1 END;
	EXTERNAL_SEND = skip

END