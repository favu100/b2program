/*
From ProB examples
*/
MACHINE WDCheck
VARIABLES
   SS
INVARIANT
  SS = {} &
  (SS /= {} => ({min(SS)} <: SS))
INITIALISATION
   SS := {}
OPERATIONS
    default = BEGIN skip END
END




