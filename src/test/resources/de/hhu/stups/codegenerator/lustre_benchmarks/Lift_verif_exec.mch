MACHINE Lift_verif_exec

INCLUDES Lift_verif

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..1000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 1000 DO
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});
              Lift_verif_clock_step({ref |-> TRUE}, {ref |-> FALSE});

              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});
              Lift_verif_clock_step({ref |-> FALSE}, {ref |-> TRUE});

            	counter := counter + 1
            INVARIANT 1 = 1
            VARIANT 1000 - counter
            END

END
