MACHINE LargeFunction
CONSTANTS n, fun
PROPERTIES n=100 &
 fun = %(x,y).(x:0..n & y:0..n | (x+y) mod n)
VARIABLES x
INVARIANT
 x: 0..n
INITIALISATION
  x:= 1
OPERATIONS
  //incx = x:= (x+1) mod n;
  setf = BEGIN x:= fun(x,x) END
END
