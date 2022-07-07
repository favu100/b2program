MACHINE ExplicitChecks
VARIABLES
  x
INVARIANT
  x:NATURAL &
  
  // from TLC Tests
  {xx|xx:1..81 & card({a,b|a:2..9 & b:2..4 & a**b=xx})=2} = {16,64,81}
  &

  { {1,2,3} , {3,2,1}, 1..3, {x|x:-1..100 & x>0 & x<4}} = {1..3}
  
  
  &
  // REPL Unit Tests
    ( (%x.(x : 1 .. 9000|{x + 1}) \/ {0 |-> {0}} ; %y.(y <: {0,3}|y) \/ {{0} |-> {0}}) = {(0|->{0}),(2|->{3})} ) /* 15/10/2011 9:20 */
 &
  ( {1 |-> (1 .. 2000000) - {2222},2 |-> {3}}(1 + 1) = {3} ) /* 18/10/2011 6:9 */
// &
 // ( #(f,y).((f = %x.(x : 0..100|x + y) & y=1000 & f(5) = 1005)) ) /* 19/10/2011 9:34 */  // Symbol not found error when commented in:
   // ExplicitChecks.java:156: error: cannot find symbol
   //         _ic_set_7 = _ic_set_7.union(new BRelation<BInteger, BInteger>(new BTuple<>(_ic_x_1, _ic_x_1.plus(y))));
// &
//  ( {1 |-> 2,3 |-> 4,4 |-> 4}[INTEGER] = {2,4} ) /* 19/10/2011 16:9 */
// &
//  ( {1 |-> 2,3 |-> 4,4 |-> 4,-1 |-> 33,1 |-> 22}[{x|x : INTEGER & x < 2}] = {2,22,33} ) /* 19/10/2011 16:11 */
 &
  ( {1 |-> 2,3 |-> 4,4 |-> 4,-1 |-> 33,1 |-> 22}[3 .. 10000000] = {4} ) /* 19/10/2011 16:11 */
// &
 // ( #(r).(r[NATURAL1] <: 1 .. 10 & r : 1 .. 115 --> 0 .. 1) ) /* 11/12/2011 8:0 */

  & // from REPL Unit Tests 1
   ( card(%x.(x : 1 .. 2000000|x * 2)) = 2000000 ) /* 18/6/2011 9:13 */
 &
  ( dom(%x.(x : 1 .. 2000000|x * 2)) = 1 .. 2000000 ) /* 18/6/2011 9:14 */
INITIALISATION
  x:= 0
OPERATIONS
  incX = SELECT x<1000 THEN x:= x+1 END;
  reset = BEGIN x:=0 END
END