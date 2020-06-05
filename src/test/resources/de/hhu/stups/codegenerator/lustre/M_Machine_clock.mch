MACHINE M_Machine_clock

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_res, var_tmp_0, var_clock, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & (var_tmp_0 : LUSTRE_BOOL)))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_clock := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL)
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            var_tmp_0 := {ref |-> TRUE}; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_tmp_1 := var_tmp_0
            END; 
            var_res := var_tmp_1; 
            is_initialisation := FALSE; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END

        END



END

/*
tmp_0: true
tmp_1: (true when clock)
*/
