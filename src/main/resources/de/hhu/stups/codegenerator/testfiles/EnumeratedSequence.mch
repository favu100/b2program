MACHINE EnumeratedSequence

VARIABLES  f

INVARIANT  f : seq(INT)

INITIALISATION f := [1,2,3]

OPERATIONS

	calculate = BEGIN f := [1,2] END

END