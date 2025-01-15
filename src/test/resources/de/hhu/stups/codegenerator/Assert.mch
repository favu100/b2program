MACHINE Assert

VARIABLES  level

INVARIANT  level : 0..99 /* NAT */

INITIALISATION level := 0

OPERATIONS

	inc = ASSERT level<99 THEN level := level + 1 END ;

	dec = ASSERT level>0 THEN level := level - 1 END

END