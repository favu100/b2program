MACHINE ConstNestedRelation

SETS
  Counters={C1, C2, C3, C4, C5, C6}
  ;Persons={P1, P2}

CONCRETE_CONSTANTS
  nxt

PROPERTIES
   nxt : Persons --> (Counters >+> Counters)
   & nxt = {P1 |-> { C1 |-> C3, C3 |-> C5 }, P2 |-> {C2 |-> C6, C6 |-> C2}}

INVARIANT /* Machine without Invariant crashes MC-generator (even if MC is disabled...) */
  1 = 1


OPERATIONS

  out <-- relCount = out := card(nxt)
END
