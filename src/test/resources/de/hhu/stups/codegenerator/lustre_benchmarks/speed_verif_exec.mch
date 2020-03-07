MACHINE speed_verif_exec

INCLUDES speed_verif

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..500

INITIALISATION counter := 0

OPERATIONS

	simulate = 	BEGIN
							WHILE counter < 500 DO
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> FALSE});

								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});

								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});

								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								speed_verif_clock_step({ref |-> TRUE}, {ref |-> TRUE});
								counter := counter + 1
							INVARIANT 1 = 1
							VARIANT 500 - counter
							END
						END

END
