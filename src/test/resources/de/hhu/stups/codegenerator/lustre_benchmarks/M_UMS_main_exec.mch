MACHINE M_UMS_main_exec

INCLUDES M_UMS_main

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..5000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 5000 DO
							clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE});
							clock_step({ref |-> TRUE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE});
							clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE});
							clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> TRUE});
							clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE}, {ref |-> TRUE});
							clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE});
            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 5000 - counter
            END

END
