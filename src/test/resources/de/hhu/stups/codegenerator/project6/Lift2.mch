REFINEMENT Lift2

REFINES Lift

VARIABLES  level, door_open

INVARIANT  level : 0..100 & door_open : BOOL

INITIALISATION level := 0 || door_open := FALSE

OPERATIONS

	inc = PRE level<100 THEN level := level + 1 END ;
	dec = PRE level>0 THEN level := level - 1 END;
	open_door = PRE door_open=FALSE THEN door_open := TRUE END ;
	close_door = PRE door_open=TRUE THEN door_open := FALSE END

END