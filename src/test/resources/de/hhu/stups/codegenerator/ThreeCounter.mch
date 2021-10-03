MACHINE ThreeCounter
 // Test on a simple machine how the performance compares against CAN_BUS
CONSTANTS maxv
PROPERTIES maxv = 132599
VARIABLES x,y,z
INVARIANT
  {x,y,z} <: 0..maxv
INITIALISATION
 x,y,z := 0,0,0
OPERATIONS
  Inc1 = SELECT x<maxv THEN x,y,z := x+1,y+1,z+1 END;
  Inc2 = SELECT x+1<maxv THEN x,y,z := x+2,y+2,z+2 END;
  Inc3 = SELECT x+2<maxv THEN x,y,z := x+3,y+3,z+3 END;
  Reset = SELECT x=maxv THEN x,y,z := 0,0,0 END
END
