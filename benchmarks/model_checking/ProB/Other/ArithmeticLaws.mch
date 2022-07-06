
MACHINE ArithmeticLaws
ABSTRACT_VARIABLES
  x,
  y,
  z
INVARIANT
    x : INTEGER
  & y : INTEGER
  & z : INTEGER
  & x * y = y * x
  & x * (y + z) = x * y + x * z
  & x * 1 = x
  & 1 * x = x
  & x * 0 = 0
  & 0 * x = 0
  & x + y + z = x + (y + z)
  & x * y * z = x * (y * z)
  & 2 * x = x + x
  & x ** 2 = x * x
  & (
     x >= 0
     =>
     1 ** x = 1
    )
  & (
     x >= 0
     =>
     (
      ((x / 2) * 2 = x)
      <=>
      (x mod 2 = 0)
     )
    )
  & (
     x > 0
     =>
     2 ** x = 2 * 2 ** (x - 1)
    )
  & (
     x > 0
     =>
     2 ** (10 * x) = 2 * 2 ** (10 * x - 1)
    )
  & (
     x > 0
     =>
     3 ** (10 * x) = 3 * 3 ** (10 * x - 1)
    )
  & (
     y /= 0
     =>
     (
      - x / y = - (x / y)
      &
      x / - y = - (x / y)
      &
      (
       (
        x >= 0
        &
        y > 0
       )
       =>
       (
        x mod y = x - y * (x / y)
        &
        x / y = min({q|q : 0 .. x & x < y * (q + 1)})
       )
      )
     )
    )
  & (
     x > y
     or
     x <= y
    )
  & (
     x > y
     or
     x = y
     or
     x < y
    )
  & (
     x >= y
     or
     x < y
    )
  & (
     x >= y
     or
     x <= y
    )
  & not(
     x > y
     &
     x <= y
    )
  & not(
     x < y
     &
     y < x
    )
  & x - x = 0
  & (
     (x = y)
     <=>
     (x - y = 0)
    )
  & (
     x > y
     <=>
     x >= y + 1
    )
  & (
     x < y
     <=>
     x <= y - 1
    )
  & (
     (
      x < y
      or
      y < x
     )
     <=>
     x /= y
    )
  & (
     (
      x < y
      &
      y <= z
     )
     =>
     x < z
    )
  & (
     (
      x < y
      &
      y < z
     )
     =>
     x < z
    )
  & (
     (
      x <= y
      &
      y < z
     )
     =>
     x < z
    )
  & (
     (
      x <= y
      &
      y <= z
     )
     =>
     x <= z
    )
  & (
     (
      x <= y
      &
      y <= x
     )
     =>
     x = y
    )
  & (
     (x = y)
     <=>
     (y = x)
    )
  & (
     x /= y
     <=>
     y /= x
    )
  & (
     x < y
     <=>
     y > x
    )
  & (
     x > y
     <=>
     y < x
    )
  & (
     x <= y
     <=>
     y >= x
    )
  & (
     x >= y
     <=>
     y <= x
    )
  & (
     not(x < y)
     <=>
     x >= y
    )
  & (
     not(x <= y)
     <=>
     x > y
    )
  & (
     x : {y,z}
     =>
     x : {y,z}
    )
  & (
     (x : {y,z})
     <=>
     (x : {y,z})
    )
  & (
     (
      (x = y)
      <=>
      (x = z)
     )
     =>
     (
      y = z
      or
      x /= y
     )
    )
  & (x - y - x) + y = 0
  & x * x >= 0
  & (
     (x * x = 0)
     <=>
     (x = 0)
    )
  & x * x = - x * - x
  & (
     x <= y
     <=>
     (min({x,y}) = x)
    )
  & (
     x <= y
     <=>
     (max({x,y}) = y)
    )
  & (
     x < y
     <=>
     max({x,y}) /= x
    )
  & (
     x < y
     <=>
     min({x,y}) /= y
    )
  & (
     (
      x >= 0
      &
      y > 0
     )
     =>
     (x / y) * y = x - x mod y
    )
  & (
     (
      x /= y
      &
      x /= z
      &
      y /= z
     )
     =>
     SIGMA(zz).(zz : {x,y,z}|zz) = x + y + z
    )
  & (
     (
      x /= y
      &
      x /= z
      &
      y /= z
     )
     =>
     PI(zz).(zz : {x,y,z}|zz) = x * y * z
    )
  & SIGMA(zz).(zz = x|zz) = x
  & PI(zz).(zz = x|zz) = x
  & x < x + 1
  & x > x - 1
  & (x + 1) - 1 = x
  & x + (y + 1) = x + y + 1
  & x * (y + 1) = x + x * y
  & (
     x >= 0
     =>
     1 ** x = 1
    )
  & x ** 1 = x
  & x ** 0 = 1
  & (
     x > 0
     =>
     0 ** x = 0
    )
  & (
     z >= 0
     =>
     (x * y) ** z = x ** z * y ** z
    )
  & (
     (
      y >= 0
      &
      z >= 0
     )
     =>
     x ** (y + z) = x ** y * x ** z
    )
  & (
     (
      y >= 0
      &
      z >= 0
     )
     =>
     x ** (y * z) = (x ** y) ** z
    )
  & 
    #x.(
     x : 0..5
     &
     {1,2} \/ {x} = {1,2}
    )
  & min({x}) = x
  & (
     x <= y
     =>
     min({x,y}) = x
    )
  & (
     y <= x
     =>
     min({x,y}) = y
    )
  & min({y,z} \/ {x}) = min({min({x}),min({y,z})})
  & min({y,z} \/ {x}) = min({min({y,z}),x})
  & max({x}) = x
  & (
     y <= x
     =>
     max({x,y}) = x
    )
  & (
     x <= y
     =>
     max({x,y}) = y
    )
  & max({y,z} \/ {x}) = max({max({x}),max({y,z})})
  & max({y,z} \/ {x}) = max({max({y,z}),x})
  & (
     (x : y .. z)
     <=>
     (
      y <= x
      &
      x <= z
     )
    )
  & (
     (x : y .. z)
     <=>
     (
      y <= x
      &
      x <= z
      &
      y <= z
     )
    )
INITIALISATION
    BEGIN
      x,y,z := -3,-3,-3
    END
OPERATIONS
  IncX = 
    PRE 
        x < 50
    THEN
      x := x + 1
    END;
  
  IncY = 
    PRE 
        y < 9
    THEN
      y := y + 1
    END;
  
  IncZ = 
    PRE 
        z < 4
    THEN
      z := z + 1
    END
 ; Reset = 
    BEGIN
      x,y,z := -3,-3,-3
    END
END
