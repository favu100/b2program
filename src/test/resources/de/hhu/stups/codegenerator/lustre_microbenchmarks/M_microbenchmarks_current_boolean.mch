MACHINE M_microbenchmarks_current_boolean

SEES LibraryLustre

VARIABLES is_initialisation_clock, is_initialisation, var_res, var_x, var_clock, var_tmp_0

INVARIANT ((var_x : LUSTRE_BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_BOOL) & ((var_tmp_0 : LUSTRE_BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_x := {}; 
    var_clock := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_clock, param_x) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_x : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock := param_clock; 
            var_x := param_x; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_tmp_0 := var_x
            END; 
            var_res := var_tmp_0; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END; 
            is_initialisation := FALSE

        END



END