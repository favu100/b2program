//generated from Lustre
//taken from Programming and verifying real-time systems by means of the synchronous data-flow language LUSTRE, N.Halbwachs et. al


MACHINE M_implies

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_AimpliesB

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_AimpliesB : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_AimpliesB := {}


OPERATIONS 

    clock_step(param_A, param_B) = 
        PRE
            ((param_A : LUSTRE_BOOL) & (param_B : LUSTRE_BOOL))
        THEN
            VAR var_A, var_B IN
                var_A := param_A; 
                var_B := param_B; 
                var_AimpliesB := l_or(l_not(var_A) |-> var_B); 
                is_initialisation := FALSE

            END

        END



END

