MACHINE Lift2

INCLUDES Lift

PROMOTES inc, dec

VARIABLES  door_open

INVARIANT  door_open : BOOL

INITIALISATION door_open := FALSE

OPERATIONS

	open_door = PRE door_open=FALSE THEN door_open := TRUE END ;
	close_door = PRE door_open=TRUE THEN door_open := FALSE END

END