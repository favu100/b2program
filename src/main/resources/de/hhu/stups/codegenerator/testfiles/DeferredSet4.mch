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
    Users, current


INVARIANT
    Users <: USERS &
    current : USERS



INITIALISATION
    Users := {} ||
    current := a


OPERATIONS
    AddUser (user) =
    PRE
        user:USERS & user/:Users
    THEN
        Users := Users \/ {user} ||
        current := b
    END

END