MACHINE M_SLOW_TIME_STABLE_exec

INCLUDES M_SLOW_TIME_STABLE

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..100000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 100000 DO
								clock_step({ref |-> TRUE}, {ref |-> TRUE}, {ref |-> 3});
								clock_step({ref |-> TRUE}, {ref |-> FALSE}, {ref |-> 3});
								clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> 3});
								clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> 3});
								clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> 3});
								clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> 3});
            		counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 100000 - counter
            END

END
