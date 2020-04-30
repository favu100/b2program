MACHINE M_microbenchmarks_pre_integer_exec

INCLUDES M_microbenchmarks_pre_integer

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..100000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 100000 DO
              clock_step({ref |-> 1});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 100000 - counter
            END

END
