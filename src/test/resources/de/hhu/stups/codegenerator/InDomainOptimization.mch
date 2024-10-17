MACHINE InDomainOptimization

VARIABLES  c

INVARIANT  c : INTEGER <-> INTEGER

INITIALISATION c := {0 |-> 0}

OPERATIONS

	op(a) = PRE a : dom(c) & 1 : dom(c) THEN c := {1 |-> 1} END;
	op2 = BEGIN skip END

END