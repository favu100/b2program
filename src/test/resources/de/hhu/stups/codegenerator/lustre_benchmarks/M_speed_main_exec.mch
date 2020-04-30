MACHINE M_speed_main_exec

INCLUDES M_speed_main

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..500

INITIALISATION counter := 0

OPERATIONS

	simulate = 	BEGIN
							WHILE counter < 500 DO
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});
								clock_step({ref |-> FALSE}, {ref |-> FALSE});

								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});
								clock_step({ref |-> FALSE}, {ref |-> TRUE});

								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});
								clock_step({ref |-> TRUE}, {ref |-> FALSE});

								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								clock_step({ref |-> TRUE}, {ref |-> TRUE});
								counter := counter + 1
							INVARIANT 1 = 1
							VARIANT 500 - counter
							END
						END

END
