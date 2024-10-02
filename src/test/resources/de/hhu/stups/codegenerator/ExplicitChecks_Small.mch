MACHINE ExplicitChecks_Small
VARIABLES
  x
INVARIANT
  x : NATURAL &
  #(f,y).(y=1000 & f = %x.(x : 0..100|x + y) & f(5) = 1005)  /* 19/10/2011 9:34 */  // Symbol not found error when commented in:
INITIALISATION
  x := 0
END