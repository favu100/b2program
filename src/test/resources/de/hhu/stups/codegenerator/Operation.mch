/* Operation
 * Author: 
 * Creation date: 13.04.18
 */
MACHINE Operation

VARIABLES xx
   
INVARIANT xx : INT
INITIALISATION xx := 0

OPERATIONS
out <-- Inc(pp) =
    PRE pp : 1..10 THEN xx := xx + pp; out := xx END

END
