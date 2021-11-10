MACHINE And
CONSTANTS interval
VARIABLES  counter
PROPERTIES interval = 0..1000000
INVARIANT  counter : interval

INITIALISATION counter := 0

OPERATIONS
	simulate = WHILE counter < 5000000 & 1=1 DO
	        counter := counter + 1
		  INVARIANT 1 = 1
		  VARIANT 5000000 - counter
	      END;

	out <-- getCounter =
	      BEGIN
	        out := counter
	      END

END