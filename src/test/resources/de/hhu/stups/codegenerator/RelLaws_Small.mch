MACHINE RelLaws_Small
VARIABLES
  ff
INVARIANT
  ff : POW(INTEGER * INTEGER)
  & id(ff) = {xx,yy|xx : ff & yy : ff & xx = yy}

INITIALISATION
    BEGIN
      ff := {(1|->2)}
    END
OPERATIONS
  continue = skip
END
