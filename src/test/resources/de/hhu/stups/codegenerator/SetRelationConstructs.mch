/*
From ProB Examples, originally used to test ProB
*/
MACHINE SetRelationConstructs
VARIABLES basea, a, baseb, b, basec, c
INVARIANT
 basea : POW(BOOL * BOOL * BOOL) &
 a: basea &
 baseb:  POW(BOOL * (BOOL * BOOL)) &
 b: baseb &
 basec:  POW((BOOL * BOOL) * (BOOL * BOOL)) &
 c: basec


INITIALISATION
   basea:=BOOL*BOOL*BOOL; a:=(TRUE |-> FALSE) |-> TRUE;
   baseb:=BOOL*(BOOL*BOOL); b:=TRUE |-> (FALSE |-> TRUE);
   basec:=(BOOL*BOOL)*(BOOL*BOOL); c:=(TRUE |-> FALSE) |-> (TRUE |-> TRUE)

OPERATIONS
  AssertionsOK = PRE ( TRUE : BOOL) THEN skip END
END

