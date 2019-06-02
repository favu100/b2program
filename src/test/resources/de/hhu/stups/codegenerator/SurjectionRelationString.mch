MACHINE SurjectionRelationString

VARIABLES  x

INVARIANT  x : {"1","2","3"} <-> STRING

INITIALISATION x := {"1"|->"2", "2"|->"3"}

OPERATIONS

	op1 = SELECT x : {"1","2","3"} <->> STRING THEN x := {"1"|->"2"} END

END