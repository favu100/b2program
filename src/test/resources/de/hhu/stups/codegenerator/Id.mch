MACHINE Id

VARIABLES  f, r

INVARIANT  f : POW(INT) & r : INT --> INT

INITIALISATION f := {1,2,3}; r := {}

OPERATIONS

	calculate = BEGIN r := id(f) END

END