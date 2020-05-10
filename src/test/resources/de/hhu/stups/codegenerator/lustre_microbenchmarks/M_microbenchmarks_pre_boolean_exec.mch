MACHINE M_microbenchmarks_pre_boolean_exec

INCLUDES M_microbenchmarks_pre_boolean

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..500000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 500000 DO
              clock_step({ref |-> TRUE});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 500000 - counter
            END

END
