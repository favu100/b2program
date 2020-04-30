MACHINE M_microbenchmarks_ite_boolean

SEES LibraryLustre

VARIABLES is_initialisation, var_res

INVARIANT ((var_res : LUSTRE_BOOL) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))

INITIALISATION 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x, param_y, param_z) = 
        PRE
            ((param_x : LUSTRE_BOOL_NOT_NIL) & ((param_y : LUSTRE_BOOL_NOT_NIL) & (param_z : LUSTRE_BOOL_NOT_NIL)))
        THEN
            VAR var_x, var_y, var_z IN
                var_x := param_x; 
                var_y := param_y; 
                var_z := param_z; 
                var_res := l_ite_boolean(var_x |-> var_y |-> var_z); 
                is_initialisation := FALSE

            END

        END



END