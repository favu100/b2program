MACHINE
    DeferredSet4

CONSTANTS
    a,b,c

SETS
    USERS

PROPERTIES
    USERS = {a,b,c} &
    card(USERS) = 3

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
