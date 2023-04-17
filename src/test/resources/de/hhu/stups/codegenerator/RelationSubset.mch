MACHINE RelationSubset

SETS FOO = {F1, F2, F3, F4}

VARIABLES r1, r2, res

INVARIANT
    r1 : FOO <-> FOO
  & r2 : FOO <-> FOO
  & res : BOOL

INITIALISATION
  r1 := {F1 |-> F2, F3 |-> F2}
  ; r2 := {F1 |-> F2, F2 |-> F4, F3 |-> F2, F3 |-> F4}
  ; res := FALSE

OPERATIONS
  calculate = BEGIN IF r1 <: r2 THEN res := TRUE ELSE res := FALSE END END;
  out <-- getRes = out := res

END