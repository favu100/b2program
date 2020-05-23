MACHINE M_SubmodeExample_exec

INCLUDES M_SubmodeExample

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..1000

INITIALISATION counter := 0

OPERATIONS

	simulate = 	BEGIN
							WHILE counter < 1000 DO
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
							VARIANT 1000 - counter
							END
						END

END
