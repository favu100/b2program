MACHINE M_other_when_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock, var_res, var_tmp, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & (var_tmp : LUSTRE_INT))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock := TRUE; 
    var_res := {}; 
    var_tmp := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock) = 
        PRE
            (param_clock : LUSTRE_BOOL)
        THEN
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            var_tmp := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> l_plus(var_tmp |-> {ref |-> 1})); 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_res := var_tmp
            END; 
            is_initialisation := FALSE; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END

        END



END

