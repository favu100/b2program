MACHINE
    A

INCLUDES B

VARIABLES cc, dd

INVARIANT cc : INT & dd : BOOL

INITIALISATION cc := 5 || dd := bool(1=1)

OPERATIONS
    operate = cc, dd <-- operateRet

END