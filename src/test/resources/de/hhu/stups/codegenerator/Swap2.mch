MACHINE Swap2

VARIABLES  xx,yy

INVARIANT  xx : INT & yy : INT

INITIALISATION xx,yy := 0,1

OPERATIONS
    swap = xx,yy := yy,xx;
    out <-- getXX = out := xx;
    out <-- getYY = out := yy

END