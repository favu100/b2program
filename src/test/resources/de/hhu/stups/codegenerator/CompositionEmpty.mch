MACHINE CompositionEmpty
VARIABLES
  ff
INVARIANT
  ff : POW(INTEGER * INTEGER)
  & ({}; ff) = {}

INITIALISATION
    BEGIN
      ff := {(1|->2)}
    END
OPERATIONS
  continue = skip
END
