MACHINE Lift_MC

VARIABLES  c_floor

INVARIANT  c_floor >= 0 & c_floor <= 100

INITIALISATION c_floor := 0

OPERATIONS

	inc = PRE c_floor<100 THEN c_floor := c_floor + 1 END ;
	dec = PRE c_floor>0 THEN c_floor := c_floor - 1 END

END