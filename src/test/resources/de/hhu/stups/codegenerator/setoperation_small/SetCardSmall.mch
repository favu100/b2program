MACHINE SetCardSmall

VARIABLES  counter, result

INVARIANT  counter : 0..5000000 & result : INTEGER

INITIALISATION counter := 0; result := 0

OPERATIONS

	simulate = WHILE counter < 5000000 DO
	      result := card({1});
	      counter := counter + 1
		  INVARIANT 1 = 1
		  VARIANT 5000000 - counter
	      END;

	out <-- getResult =
	      BEGIN
	        out := result
	      END

END