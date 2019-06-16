MACHINE
    DeferredSet

SETS
    USERS


VARIABLES
    Users


INVARIANT
    Users <: USERS



INITIALISATION
    Users := {}


OPERATIONS
    AddUser (user) =
    PRE
        user:USERS & user/:Users
    THEN
        Users := Users \/ {user}
    END

END
