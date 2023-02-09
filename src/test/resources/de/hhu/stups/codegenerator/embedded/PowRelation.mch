MACHINE PowRelation

SETS
  Counters={C1, C2, C3}
  ;Persons={P1, P2}

VARIABLES
  Counter2Person

INVARIANT
  Counter2Person : POW(Counters <-> Persons)

INITIALISATION
  Counter2Person := {}

OPERATIONS

  ManCounter(c, p) =
    PRE
      /* @grd1 */ c : Counters
      & /* @grd2 */ p : Persons
      & {(c |-> p)} /: Counter2Person
    THEN
      Counter2Person := Counter2Person \/ {{(c |-> p)}}
  END
END
