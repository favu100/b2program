MACHINE M_microbenchmarks_invoked_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_res : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
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

