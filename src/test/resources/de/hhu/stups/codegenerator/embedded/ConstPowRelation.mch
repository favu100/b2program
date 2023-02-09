MACHINE ConstPowRelation

SETS
  Counters={C1, C2, C3}
  ;Persons={P1, P2}

CONCRETE_CONSTANTS
  Counter2Person

PROPERTIES
   Counter2Person : POW(Counters <-> Persons)
   & Counter2Person = {{(C1|->P1), (C3|->P2)}, {(C1|->P1), (C2|->P2)}}

INVARIANT /* Machine without Invariant crashes MC-generator (even if MC is disabled...) */
  1 = 1


OPERATIONS

  out <-- relCount = out := card(Counter2Person)
END
