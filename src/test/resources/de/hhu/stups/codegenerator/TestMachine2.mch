MACHINE TestMachine2

INCLUDES TestMachine

VARIABLES
	counter

INVARIANT counter : INTEGER

INITIALISATION
	counter := 1

OPERATIONS
	op2 = BEGIN 
		op;
	      	counter := 2
	      END
END