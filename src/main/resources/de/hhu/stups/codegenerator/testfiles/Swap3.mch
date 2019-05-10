MACHINE Swap3

VARIABLES  xx,yy

INVARIANT  xx : INT & yy : INT

INITIALISATION xx,yy := 0,1

OPERATIONS
    swap = xx := yy + 1 || yy := xx + 1

END