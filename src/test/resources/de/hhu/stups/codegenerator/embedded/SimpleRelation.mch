MACHINE SimpleRelation

SETS
  Counters={C1, C2, C3}
  ;Persons={P1, P2}

VARIABLES
  Counter2Person

INVARIANT
  Counter2Person : Counters <-> Persons

INITIALISATION
  Counter2Person := {}

OPERATIONS

  ManCounter(c, p) =
    PRE
      /* @grd1 */ c : Counters
      & /* @grd2 */ p : Persons
      & c /: dom(Counter2Person)
      & p /: ran(Counter2Person)
    THEN
      Counter2Person(c) := p
  END
END
