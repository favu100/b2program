MACHINE scheduler_deterministic_exec

INCLUDES scheduler_deterministic

VARIABLES counter

INVARIANT counter : INTEGER

INITIALISATION counter := 0

OPERATIONS
	simulate =
	      WHILE counter < 100000 DO
            new(process1);
            new(process2);
            new(process3);
            del(process1);
            new(process1);
            del(process2);
            del(process1);
            del(process3);
            new(process1);
            new(process2);
            del(process1);
            ready(process2);
            new(process1);
            new(process3);
            del(process1);
            ready(process3);
            new(process1);
            ready(process1);
            swap(process1);
            del(process2);
            swap(process3);
            new(process2);
            del(process1);
            del(process2);
            swap(process1);
            new(process1);
            new(process2);
            del(process1);
            del(process3);
            new(process1);
            del(process2);
            del(process1);
            counter := counter + 1
         INVARIANT 1=1
         VARIANT 100000 - counter
	     END

END