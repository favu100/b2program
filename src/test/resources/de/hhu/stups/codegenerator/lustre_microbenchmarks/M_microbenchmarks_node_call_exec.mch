MACHINE M_microbenchmarks_node_call_exec

INCLUDES M_microbenchmarks_node_call

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..100000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 100000 DO
              clock_step({ref |-> TRUE}, {ref |-> TRUE});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 100000 - counter
            END

END
