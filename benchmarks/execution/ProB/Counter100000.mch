MACHINE Counter100000

VARIABLES counter

INVARIANT counter : INTEGER

INITIALISATION counter := 0

OPERATIONS
	simulate =
	WHILE counter < 100000 DO
	    counter := counter + 1
	INVARIANT 1 = 1
	VARIANT 100000 - counter
	      END

END
