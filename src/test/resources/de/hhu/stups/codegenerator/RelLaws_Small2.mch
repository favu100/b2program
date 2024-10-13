MACHINE RelLaws_Small2
SETS setY = {y1,y2}
VARIABLES
  ff
INVARIANT
  ff : POW(BOOL * setY)
  & ff~ = {b,a| a : dom(ff) & b : ran(ff) & (a,b):ff}

INITIALISATION
    BEGIN
      ff := {(TRUE|->y1), (FALSE|->y2)}
    END
OPERATIONS
  continue = skip
END
