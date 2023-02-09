MACHINE RedundantConstSet

SETS
  Persons={P1, P2, P3}

CONCRETE_CONSTANTS
  Managers

PROPERTIES
   Managers <: Persons
   & Managers = {P1, P3}

INVARIANT /* Machine without Invariant crashes MC-generator (even if MC is disabled...) */
  1 = 1


OPERATIONS

  out <-- workerCount = out := card(Persons - Managers)
END
