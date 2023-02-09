MACHINE RedundantConstRelation

SETS
  Persons={P1, P2, P3}
  ;Counters={C1, C2}

CONCRETE_CONSTANTS
  Counter2Persons

PROPERTIES
   Counter2Persons : Counters <-> Persons
   & Counter2Persons = {(C1|->P1), (C2|->P3)}

INVARIANT /* Machine without Invariant crashes MC-generator (even if MC is disabled...) */
  1 = 1


OPERATIONS

  out <-- relCount = out := card(Counter2Persons)
END
