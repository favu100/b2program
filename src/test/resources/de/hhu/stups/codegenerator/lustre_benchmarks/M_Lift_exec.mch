MACHINE M_Lift_exec

INCLUDES M_Lift

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..2000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 2000 DO
			  clock_step({ref |-> FALSE}, {ref |-> FALSE});
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

            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 2000 - counter
            END

END
