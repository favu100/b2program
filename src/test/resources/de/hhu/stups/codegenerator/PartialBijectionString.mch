MACHINE PartialBijectionString

VARIABLES  x

INVARIANT  x : STRING <-> STRING

INITIALISATION x := {"1"|->"2", "2"|->"3"}

OPERATIONS

	op1 = SELECT x : STRING >+>> STRING THEN x := {"1"|->"2"} END

END