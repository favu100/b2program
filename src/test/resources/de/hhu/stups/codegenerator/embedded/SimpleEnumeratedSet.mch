MACHINE SimpleEnumeratedSet

SETS
  Counters={C1, C2, C3}

VARIABLES
  AvailableCounters

INVARIANT
  AvailableCounters <: Counters

INITIALISATION
  AvailableCounters := {}

OPERATIONS

  AddCounter(c) =
    PRE
      /* @grd1 */ c : Counters
    THEN
      AvailableCounters := AvailableCounters \/ { c }
  END
END
