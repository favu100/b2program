REFINEMENT Lift2

REFINES Lift

VARIABLES  floor, door_open

INVARIANT  floor : 0..100 & door_open : BOOL

INITIALISATION floor := 0 || door_open := FALSE

OPERATIONS

	inc = PRE floor<100 THEN floor := floor + 1 END ;
	dec = PRE floor>0 THEN floor := floor - 1 END;
	open_door = PRE door_open=FALSE THEN door_open := TRUE END ;
	close_door = PRE door_open=TRUE THEN door_open := FALSE END

END