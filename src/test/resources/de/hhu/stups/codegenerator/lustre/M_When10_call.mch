MACHINE M_When10_call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_clock, var_res, var_val

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_val : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & (var_res : LUSTRE_INT))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_clock := {}; 
    var_res := {}; 
    var_val := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL) & (param_val : LUSTRE_INT))
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_val := param_val
            END; 
            var_res := var_val; 
            is_initialisation := FALSE; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END

        END



END

