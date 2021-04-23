MACHINE SimpleParameters

VARIABLES  counter

INVARIANT  counter : INTEGER

INITIALISATION counter := 0

OPERATIONS

	inc(x,y) = PRE x : -5..5 & y : -5..5 & counter <= 6 & counter >= -6 & (x = 2 or (x = 3 => x = y)) THEN counter := counter + x + y END

END