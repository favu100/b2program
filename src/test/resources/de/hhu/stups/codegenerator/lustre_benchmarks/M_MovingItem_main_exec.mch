MACHINE M_MovingItem_main_exec

INCLUDES M_MovingItem_main

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..5000

INITIALISATION counter := 0

OPERATIONS

	simulate = 	BEGIN
							WHILE counter < 5000 DO
								clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE}, {ref |-> TRUE});
								counter := counter + 1
							INVARIANT 1 = 1
							VARIANT 5000 - counter
							END
						END

END
