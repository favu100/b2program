MACHINE M_implies

SEES LibraryLustre

VARIABLES is_initialisation, var_AimpliesB

INVARIANT ((var_AimpliesB : LUSTRE_BOOL) & (is_initialisation : BOOL))

INITIALISATION 
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

