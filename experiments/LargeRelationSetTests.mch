MACHINE LargeRelationSetTests
VARIABLES f,g, s,t
INVARIANT
 f: INTEGER <-> INTEGER & g: INTEGER <-> INTEGER & s<:INTEGER & t<:INTEGER
INITIALISATION
  f := %x.(x:0..20-1|(x+1) mod (20+1)) ||
  g  := %x.(x:0..20|(x+2) mod (20+1)) ||
  s := 2..20-2||
  t := 4..20-4
OPERATIONS
  res <-- ImageFS = res := f[s];
  res <-- ImageGS = res := g[s];
  ComposeFG = BEGIN f := (f;g) END;
  //UnionST = BEGIN s := s \/ t END;
  res <-- DomF = BEGIN res := dom(f) END;
  res <-- RanF = BEGIN res := ran(f) END;
  res <-- DomRestrSF = BEGIN res := s<|f END;
  res <-- DomSubtrSF = BEGIN res := s<<|f END;
  res <-- RanRestrSF = BEGIN res := f|>s END;
  res <-- RanSubtrSF = BEGIN res := f|>>s END;
  InvertF = BEGIN f := f~ END;
  RightOverrideFG = f:= f<+g;
  Closure1F = f:= closure1(f)

END

