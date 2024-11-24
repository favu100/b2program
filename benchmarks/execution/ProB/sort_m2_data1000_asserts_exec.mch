/*
Original Model:
V. Rivera, N. Catano, T. Wahls, and C. Rueda. Code generation for Event-B. STTT, 19(1):31–52, 2017.
*/
MACHINE sort_m2_data1000_asserts_exec

INCLUDES sort_m2_data1000_asserts

VARIABLES counter, sorted

INVARIANT counter : INTEGER & sorted : INTEGER

INITIALISATION
	counter := 0 || sorted := 0

OPERATIONS
	simulate = BEGIN
		WHILE sorted < 500 DO
			counter := 0;
			WHILE counter < 999 - 2*sorted DO
				prog2;
				counter := counter + 1
			INVARIANT 1 = 1
			VARIANT 999 - 2*sorted - counter
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
        	VARIANT 500 - sorted
		END;
		WHILE sorted < 999 DO
			counter := 0;
			WHILE counter < 999 - sorted DO
				prog1;
				counter := counter + 1
			INVARIANT 1 = 1
			VARIANT 999 - sorted - counter
			END;
			progress;
			sorted := sorted + 1
		INVARIANT 1 = 1
		VARIANT 999 - sorted
		END;
		final_evt
	END
	

END