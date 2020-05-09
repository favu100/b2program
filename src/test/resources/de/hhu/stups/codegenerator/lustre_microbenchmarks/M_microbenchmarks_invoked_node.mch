MACHINE M_microbenchmarks_invoked_node

SEES LibraryLustre

VARIABLES is_initialisation, var_res

INVARIANT ((var_res : LUSTRE_BOOL) & (is_initialisation : BOOL))

INITIALISATION 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_BOOL) & (param_y : LUSTRE_BOOL))
        THEN
            VAR var_x, var_y IN
                var_x := param_x; 
                var_y := param_y; 
                var_res := l_and(var_x |-> var_y); 
                is_initialisation := FALSE

            END

        END



END

