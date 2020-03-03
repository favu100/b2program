MACHINE microbenchmarks_current_integer_exec

INCLUDES microbenchmarks_current_integer

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..100000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 100000 DO
              microbenchmarks_current_integer_clock_step({ref |-> 2});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 100000 - counter
            END

END
