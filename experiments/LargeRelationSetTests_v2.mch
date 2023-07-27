MACHINE LargeRelationSetTests_v2 // a smaller version checking performance of closure1
VARIABLES f,g, s,t
INVARIANT
 f: INTEGER <-> INTEGER & g: INTEGER <-> INTEGER & s<:INTEGER & t<:INTEGER
INITIALISATION
  f := %x.(x:0..99-1|(x+1) mod (99+1)) ||
  g  := %x.(x:0..99|(x+2) mod (99+1)) ||
  s := 2..99-2||
  t := 4..99-4
OPERATIONS
  //ComposeFG = BEGIN f := (f;g) END;
  InvertF = BEGIN f := f~ END;
  Closure1F = f:= closure1(f)

END

