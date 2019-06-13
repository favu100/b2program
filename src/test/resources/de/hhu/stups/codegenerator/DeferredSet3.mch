MACHINE
    DeferredSet3

SETS
    USERS;
    ACCOUNTS;
    ADMINS


PROPERTIES
    card(USERS) = 3 &
    card(ACCOUNTS) = 4

VARIABLES
    Users,
    Accounts,
    Admins


INVARIANT
    Users <: USERS &
    Accounts <: ACCOUNTS &
    Admins <: ADMINS



INITIALISATION
    Users := {} ||
    Accounts := {} ||
    Admins := {}


OPERATIONS
    AddUser (user) =
    PRE
        user:USERS & user/:Users
    THEN
        Users := Users \/ {user}
    END

END
