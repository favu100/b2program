MACHINE Less

VARIABLES  counter

INVARIANT  counter : INT

INITIALISATION counter := 0

OPERATIONS
	simulate = WHILE counter < 5000000 & 1<2 DO
	        counter := counter + 1
		  INVARIANT 1 = 1
		  VARIANT 5000000 - counter
	      END;

	out <-- getCounter =
	      BEGIN
	        out := counter
	      END

END