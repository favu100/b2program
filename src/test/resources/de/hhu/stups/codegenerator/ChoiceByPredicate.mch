MACHINE ChoiceByPredicate

VARIABLES  x,y

INVARIANT  x : INTEGER & y : INTEGER

INITIALISATION x := 1 || y := 2

OPERATIONS

	calculate = BEGIN x : (x : 1..min({x$0 + 1, y})) END

END