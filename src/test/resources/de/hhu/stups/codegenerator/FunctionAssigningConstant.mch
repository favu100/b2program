MACHINE FunctionAssigningConstant

CONSTANTS T0

PROPERTIES
  T0 : 0..6 --> 1..27 &
  T0(0)= 1 & T0(1)= 9 & T0(2)=10 & T0(3)=13 & T0(4)=15 & T0(5)=20 & T0(6)=23

VARIABLES x

INVARIANT
  x : INTEGER

INITIALISATION
  x := 0

OPERATIONS
  event = BEGIN x := T0(2) END
END