MACHINE M_When5

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock1, is_initialisation_clock2, var_res1, var_res2, var_tmp, var_clock1, var_clock2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_INT) & ((var_tmp : LUSTRE_INT) & (((is_initialisation_clock2 = FALSE) => (var_res2 /= {})) & ((is_initialisation_clock1 = FALSE) => (var_res1 /= {}))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation_clock2 := TRUE; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_tmp := {}; 
    var_clock1 := {}; 
    var_clock2 := {}


OPERATIONS 

    clock_step(param_clock1, param_clock2) = 
        PRE
            ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & (param_clock2 : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock1 := param_clock1; 
            PRE (var_clock1 /= {}) THEN skip END; 
            var_clock2 := param_clock2; 
            PRE (var_clock2 /= {}) THEN skip END; 
            var_tmp := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> l_plus(var_tmp |-> {ref |-> 1})); 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_res1 := var_tmp
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                var_res2 := var_tmp
            END; 
            SELECT (assert_ok = TRUE) THEN skip END; 
            is_initialisation := FALSE; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                is_initialisation_clock1 := FALSE
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                is_initialisation_clock2 := FALSE
            END

        END;

    out <-- getRes1 = BEGIN out := var_res1 END;
    out <-- getRes2 = BEGIN out := var_res2 END


END

