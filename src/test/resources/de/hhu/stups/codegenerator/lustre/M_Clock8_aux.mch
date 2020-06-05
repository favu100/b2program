MACHINE M_Clock8_aux

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, is_initialisation, var_res, var_val, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((var_val : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & (var_res : LUSTRE_INT))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_val := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL) & (param_val : LUSTRE_INT))
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            var_val := param_val; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_res := var_val
            END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END; 
            is_initialisation := FALSE

        END



END

