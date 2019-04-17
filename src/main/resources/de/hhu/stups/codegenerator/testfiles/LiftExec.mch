MACHINE LiftExec

INCLUDES Lift

VARIABLES  counter

INVARIANT  counter : 0..1500000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 1500000 DO
		    VAR i IN
		       i := 0;
		       WHILE i < 100 DO
			 inc;
			 i := i+1
			INVARIANT 1 = 1
			VARIANT 100-i
		       END	
		    END;
	            VAR i IN
		       i := 0;
		       WHILE i < 100 DO
			 dec;
			 i := i+1
			INVARIANT 1 = 1
			VARIANT 100 - i
		       END
		    END;
	            counter := counter + 1
		  INVARIANT 1 = 1
		  VARIANT 1500000 - counter
	          END;

	out <-- getCounter =
	      BEGIN
	        out := counter
	      END

END