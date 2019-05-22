MACHINE BijectionRelationInteger

VARIABLES  x

INVARIANT  x : {1,2,3} <-> INTEGER

INITIALISATION x := {1|->2, 2|->3}

OPERATIONS

	op1 = SELECT x : {1,2,3} <<->> INTEGER THEN x := {1|->2} END

END