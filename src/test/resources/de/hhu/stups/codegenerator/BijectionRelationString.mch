MACHINE BijectionRelationString

VARIABLES  x

INVARIANT  x : {"A", "B", "C"} <-> STRING

INITIALISATION x := {"A"|->"2", "B"|->"3"}

OPERATIONS

	op1 = SELECT x : {"1","2","3"} <<->> STRING THEN x := {"1"|->"2"} END

END