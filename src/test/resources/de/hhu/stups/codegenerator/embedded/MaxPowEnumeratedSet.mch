MACHINE MaxPowEnumeratedSet

SETS
  Counters={C1}

VARIABLES
  AvailableCounters

INVARIANT
  AvailableCounters : POW(POW(POW(POW(Counters))))

INITIALISATION
  AvailableCounters := {}

OPERATIONS

  AddCounter(c) =
    PRE
      /* @grd1 */ c <: POW(POW(Counters))
    THEN
      AvailableCounters := AvailableCounters \/ { c }
  END

END
