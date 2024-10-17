MACHINE IntervalInterval

VARIABLES  c

INVARIANT  c : NATURAL

INITIALISATION c := 0

OPERATIONS

	op(a) = PRE a : 1..3 & a : 1..5 THEN c := a END

END