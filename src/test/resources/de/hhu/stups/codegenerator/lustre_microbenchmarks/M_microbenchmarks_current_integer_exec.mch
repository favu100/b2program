MACHINE M_microbenchmarks_current_integer_exec

INCLUDES M_microbenchmarks_current_integer

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..500000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 500000 DO
              clock_step({ref |-> TRUE}, {ref |-> 2});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 500000 - counter
            END

END
