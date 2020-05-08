MACHINE M_microbenchmarks_assertion

SEES LibraryLustre

VARIABLES is_initialisation, var_res

INVARIANT ((var_res : LUSTRE_BOOL) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))

INITIALISATION 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_BOOL_NOT_NIL) & (param_y : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR var_x, var_y IN
                var_x := param_x; 
                var_y := param_y; 
                var_res := l_and(var_x |-> var_y); 
                ASSERT (var_res /= {}) THEN skip END; 
                SELECT (var_res = {ref |-> TRUE}) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

