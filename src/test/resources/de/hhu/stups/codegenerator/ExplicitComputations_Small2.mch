MACHINE ExplicitComputations_Small2
SETS
  PROC = {p1}
INVARIANT
  !x.(x:PROC & card(PROC) = 1 => x=p1)
OPERATIONS
    test = BEGIN skip END
END