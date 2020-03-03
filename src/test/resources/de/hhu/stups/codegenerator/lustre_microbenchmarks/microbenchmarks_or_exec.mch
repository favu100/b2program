MACHINE microbenchmarks_or_exec

INCLUDES microbenchmarks_or

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..100000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 100000 DO
              microbenchmarks_or_clock_step({ref |-> TRUE}, {ref |-> FALSE});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 100000 - counter
            END

END
