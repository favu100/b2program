MACHINE TotalInjectionStruct

VARIABLES  x

INVARIANT  x : {rec(a:1), rec(a:2), rec(a:3)} <-> struct(a:INT)

INITIALISATION x := {rec(a:2) |-> rec(a:3), rec(a:3) |-> rec(a:2)}

OPERATIONS

	op1 = SELECT x : {rec(a:1), rec(a:2), rec(a:3)} >-> struct(a:INT) THEN x := {rec(a:1) |-> rec(a:3), rec(a:2) |-> rec(a:2)} END

END