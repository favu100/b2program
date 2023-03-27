MACHINE Assert

VARIABLES  floor

INVARIANT  floor : 0..10 /* NAT */

INITIALISATION floor := 0

OPERATIONS

	inc = ASSERT floor<10 THEN floor := floor + 1 END ;

	dec = ASSERT floor>0 THEN floor := floor - 1 END

END