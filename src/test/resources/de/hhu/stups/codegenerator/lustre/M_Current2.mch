MACHINE M_Current2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock1, is_initialisation_clock2, var_res1, var_res2, var_clock1, var_res, var_clock2, var_tmp_0, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_res2 /= {})) & (((is_initialisation = FALSE) => (var_res1 /= {})) & ((is_initialisation = FALSE) => (var_res /= {})))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation_clock2 := TRUE; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_clock1 := {}; 
    var_res := {}; 
    var_clock2 := {}; 
    var_tmp_0 := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_clock1, param_clock2) = 
        PRE
            ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & (param_clock2 : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock1 := param_clock1; 
            PRE (var_clock1 /= {}) THEN skip END; 
            var_clock2 := param_clock2; 
            PRE (var_clock2 /= {}) THEN skip END; 
            var_res := l_plus(l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_res) |-> {ref |-> 1}); 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_tmp_0 := var_res
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                var_tmp_1 := var_res
            END; 
            var_res1 := var_tmp_0; 
            var_res2 := var_tmp_1; 
            SELECT (assert_ok = TRUE) THEN skip END; 
            is_initialisation := FALSE; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                is_initialisation_clock1 := FALSE
            END; 
            IF (var_clock2 = {ref |-> TRUE}) THEN 
                is_initialisation_clock2 := FALSE
            END

        END;

        out <-- getRes = BEGIN out := var_res END;
        out <-- getRes1 = BEGIN out := var_res1 END;
        out <-- getRes2 = BEGIN out := var_res2 END



END

/*
tmp_0: (res when clock1)
tmp_1: (res when clock2)
*/
