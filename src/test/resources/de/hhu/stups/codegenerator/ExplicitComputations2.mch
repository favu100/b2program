MACHINE ExplicitComputations2
/* A machine with some explicitly given results for certain computations */
SETS
  PROC = {p1,p2,p3}
CONSTANTS
  r
PROPERTIES
  r = {p1 |-> p2, p2|-> p3}
INVARIANT
  r >< r = { p1|->(p2,p2), p2|->(p3,p3) } &
  (r || r) = { (p1,p1)|->(p2,p2), (p1,p2)|->(p2,p3), (p2,p1)|->(p3,p2), (p2,p2)|->(p3,p3) }
OPERATIONS
    test = BEGIN skip END
END