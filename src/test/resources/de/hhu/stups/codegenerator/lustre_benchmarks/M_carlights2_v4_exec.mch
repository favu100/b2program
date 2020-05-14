MACHINE M_carlights2_v4_exec

INCLUDES M_carlights2_v4

SEES LibraryLustre

VARIABLES  counter

INVARIANT  counter : 0..1000

INITIALISATION counter := 0

OPERATIONS

	simulate = 	BEGIN
							WHILE counter < 1000 DO
								clock_step({ref |-> 0}, {ref |-> 0});
								clock_step({ref |-> 0}, {ref |-> 1});
								clock_step({ref |-> 0}, {ref |-> 2});
								clock_step({ref |-> 0}, {ref |-> 3});
								clock_step({ref |-> 0}, {ref |-> 4});
								clock_step({ref |-> 0}, {ref |-> 5});
								clock_step({ref |-> 0}, {ref |-> 6});
								clock_step({ref |-> 0}, {ref |-> 7});
								clock_step({ref |-> 0}, {ref |-> 8});
								clock_step({ref |-> 0}, {ref |-> 9});
								clock_step({ref |-> 0}, {ref |-> 10});
								clock_step({ref |-> 1}, {ref |-> 0});
								clock_step({ref |-> 1}, {ref |-> 1});
								clock_step({ref |-> 1}, {ref |-> 2});
								clock_step({ref |-> 1}, {ref |-> 3});
								clock_step({ref |-> 1}, {ref |-> 4});
								clock_step({ref |-> 1}, {ref |-> 5});
								clock_step({ref |-> 1}, {ref |-> 6});
								clock_step({ref |-> 1}, {ref |-> 7});
								clock_step({ref |-> 1}, {ref |-> 8});
								clock_step({ref |-> 1}, {ref |-> 9});
								clock_step({ref |-> 1}, {ref |-> 10});
								clock_step({ref |-> 2}, {ref |-> 0});
								clock_step({ref |-> 2}, {ref |-> 1});
								clock_step({ref |-> 2}, {ref |-> 2});
								clock_step({ref |-> 2}, {ref |-> 3});
								clock_step({ref |-> 2}, {ref |-> 4});
								clock_step({ref |-> 2}, {ref |-> 5});
								clock_step({ref |-> 2}, {ref |-> 6});
								clock_step({ref |-> 2}, {ref |-> 7});
								clock_step({ref |-> 2}, {ref |-> 8});
								clock_step({ref |-> 2}, {ref |-> 9});
								clock_step({ref |-> 2}, {ref |-> 10});
								counter := counter + 1
							INVARIANT 1 = 1
							VARIANT 1000 - counter
							END
						END

END
