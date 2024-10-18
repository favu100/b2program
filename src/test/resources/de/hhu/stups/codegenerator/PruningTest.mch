MACHINE PruningTest
VARIABLES x
INVARIANT x : NATURAL
    & !a.((a /: {1,2} & a : 1..3) => a=3)
    & #a.((a /: {1,2} & a : 1..3) & a=3)

INITIALISATION
    BEGIN
        x := 0
    END
OPERATIONS
  test(a) =
    PRE
        a /: {1,2}
        & a : 1..3
    THEN
         x := a
    END
END
