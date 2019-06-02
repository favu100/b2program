MACHINE TotalInjectionString

VARIABLES  x

INVARIANT  x : STRING <-> {"1","2","3"}

INITIALISATION x := {"1"|->"2", "2"|->"3"}

OPERATIONS

	op1 = SELECT x : STRING >-> {"1","2","3"} THEN x := {"1"|->"2"} END

END