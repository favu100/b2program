MACHINE TrafficLightExec

INCLUDES TrafficLight

VARIABLES  counter

INVARIANT  counter : 0..300000000

INITIALISATION counter := 0

OPERATIONS

	simulate = WHILE counter < 300000000 DO
	            cars_ry;
	            cars_g;
	            cars_y;
	            cars_r;
	            peds_g;
	            peds_r;
	            counter := counter + 1
		       INVARIANT 1 = 1
		       VARIANT 300000000 - counter
	           END;

	out <-- getCounter =
	      BEGIN
	        out := counter
	      END

END