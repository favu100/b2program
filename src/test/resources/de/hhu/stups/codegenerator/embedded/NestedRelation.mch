MACHINE NestedRelation

SETS
  Counters={C1, C2}
  ;Persons={P1, P2}
  ;Shift={S1, S2}

VARIABLES
  Shift2Counter2Person

INVARIANT
  Shift2Counter2Person : Shift <-> (Counters <-> Persons)

INITIALISATION
  Shift2Counter2Person := {}

OPERATIONS

  ManCounter(c, p, s) =
    PRE
      /* @grd1 */ c : Counters
      & /* @grd2 */ p : Persons
      & s : Shift
      & s : dom(Shift2Counter2Person) => (
           c /: dom(Shift2Counter2Person(s))
         & p /: ran(Shift2Counter2Person(s))
        )
    THEN
      Shift2Counter2Person(s) := {(c |-> p)}
  END
END
