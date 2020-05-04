MACHINE M_microbenchmarks_when_integer

SEES LibraryLustre

VARIABLES is_initialisation_y, is_initialisation, var_res, var_x, var_y

INVARIANT ((var_x : LUSTRE_INT) & ((var_y : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation_y : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_y = FALSE) => (var_res /= {})))))))

INITIALISATION 
    is_initialisation_y := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_x := {}; 
    var_y := {}


OPERATIONS 

    clock_step(param_y, param_x) = 
        PRE
            ((param_y : LUSTRE_BOOL_NOT_NIL) & (param_x : LUSTRE_INT_NOT_NIL))
        THEN
            var_y := param_y; 
            var_x := param_x; 
            IF (var_y = {ref |-> TRUE}) THEN 
                var_res := var_x
            END; 
            IF (var_y = {ref |-> TRUE}) THEN 
                is_initialisation_y := FALSE
            END; 
            is_initialisation := FALSE

        END



END

