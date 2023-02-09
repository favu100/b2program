MACHINE ConstPowSet

SETS
  Persons={P1, P2, P3}

CONCRETE_CONSTANTS
  Groups

PROPERTIES
   Groups <: POW(Persons)
   & Groups = {{P1, P3}, {P2}}

INVARIANT /* Machine without Invariant crashes MC-generater (even if MC is disabled...) */
  1 = 1


OPERATIONS

  out <-- groupsCount = out := card(Groups)
END
