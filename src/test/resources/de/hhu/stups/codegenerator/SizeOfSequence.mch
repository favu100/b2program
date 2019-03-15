MACHINE SizeOfSequence

VARIABLES  f, s

INVARIANT  f : seq(INT) & s : INT

INITIALISATION f := [1,2,3]; s := 0

OPERATIONS

	calculate = BEGIN f := [1,2]; s:= size(f) END

END