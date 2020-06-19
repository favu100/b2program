MACHINE M_NilChecking_Clock_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, var_res, var_clock, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((var_x : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & (var_res : LUSTRE_INT)))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_clock, param_x) = 
        PRE
            ((param_clock : LUSTRE_BOOL) & (param_x : LUSTRE_INT))
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_x := param_x
            END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_res := var_x
            END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END

        END



END

