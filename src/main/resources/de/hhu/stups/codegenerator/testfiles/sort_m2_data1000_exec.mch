MACHINE sort_m2_data1000_exec

INCLUDES sort_m2_data1000

VARIABLES counter, sorted

INVARIANT counter : INTEGER & sorted : INTEGER

INITIALISATION
	counter := 0 || sorted := 0

OPERATIONS
	simulate = BEGIN
		WHILE sorted < 1000 DO
			WHILE counter < 1000 - sorted DO
				prog2;
				counter := counter + 1
			INVARIANT 1 = 1
			VARIANT 1000 - sorted - counter
			END;
			counter := 0;
			WHILE counter < sorted DO
				prog1;
				counter := counter + 1
			INVARIANT 1 = 1
			VARIANT sorted - counter
			END;
			progress;
			sorted := sorted + 1
		INVARIANT 1=1
        	VARIANT 1000 - sorted
		END;
		final_evt
	END
	

END