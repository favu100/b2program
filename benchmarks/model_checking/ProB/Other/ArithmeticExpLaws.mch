MACHINE ArithmeticExpLaws
// some specific laws about exponentiation
// kept separate from other laws because of CLP(FD) overflow issues
// and thus using smaller ranges for x,y,z
VARIABLES x,y,z
INVARIANT
 x:INTEGER & y:INTEGER & z:INTEGER &

 x**2 = x*x &
 (x>=0 => 1**x = 1) &
 (x>0 => 2**x = 2*(2**(x-1))) &
 (x>0 => 2**(10*x) = 2*(2**(10*x-1))) &
 (x>0 => 3**(10*x) = 3*(3**(10*x-1))) &

 x**3 = x*x*x &
 (z>0 => x**z = x*(x**(z-1))) &
 {v|v:0..(9**4) & y**z=v} = {y**z} &
 (y>1 => card({v|v:0..4 & y**v:1..(y**z)}) = z+1) &
 ((y>1 & z>0) => card({v|v:1..9 & v**z:1..(y**z)}) = y) &
 card({xx|xx:1..x & card({a,b|a:1..9 & b:2..4 & a**b=xx})=2}) < 2
ASSERTIONS
 {xx|xx:1..81 & card({a,b|a:1..9 & b:2..4 & a**b=xx})=2} = {16,64,81}
INITIALISATION x,y,z := -2,0,0
OPERATIONS
  IncX = PRE x<50 THEN x := x+1 END;
  IncY = PRE y<9 THEN y := y+1 END;
  IncZ = PRE z<4 THEN z := z+1 END /* ;
  AddToZ(a) = PRE a:NATURAL THEN z := z+a END */
END
