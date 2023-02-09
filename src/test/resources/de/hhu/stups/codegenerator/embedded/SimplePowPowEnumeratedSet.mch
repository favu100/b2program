MACHINE SimplePowPowEnumeratedSet

SETS
  Counters={C1, C2}

VARIABLES
  AvailableCounters

INVARIANT
  AvailableCounters <: POW(POW(Counters))

INITIALISATION
  AvailableCounters := {}

OPERATIONS

  AddCounter(c) =
    PRE
      /* @grd1 */ c <: POW(Counters)
    THEN
      AvailableCounters := AvailableCounters \/ { c }
  END
END
