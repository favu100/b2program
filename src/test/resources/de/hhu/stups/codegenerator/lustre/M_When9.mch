MACHINE M_When9

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock1, is_initialisation_clock2, var_res, var_tmp_0, var_tmp_2, var_clock1, var_tmp_1, var_tmp_3, var_clock2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock1 : BOOL) & ((is_initialisation_clock2 : BOOL) & ((var_clock2 : LUSTRE_BOOL) & ((var_clock1 : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_3 : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_2 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation_clock2 = FALSE) => (var_res /= {})))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock1 := TRUE; 
    is_initialisation_clock2 := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_tmp_2 := {}; 
    var_clock1 := {}; 
    var_tmp_1 := {}; 
    var_tmp_3 := {}; 
    var_clock2 := {}


OPERATIONS 

    clock_step(param_clock1, param_clock2) = 
        PRE
            ((param_clock1 : LUSTRE_BOOL_NOT_NIL) & (param_clock2 : LUSTRE_BOOL_NOT_NIL))
        THEN
            var_clock1 := param_clock1; 
            PRE (var_clock1 /= {}) THEN skip END; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_clock2 := param_clock2; 
                PRE (var_clock2 /= {}) THEN skip END

            END; 
            var_tmp_2 := {ref |-> 2}; 
            var_tmp_0 := {ref |-> 1}; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_tmp_1 := var_tmp_0
            END; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                var_tmp_3 := var_tmp_2
            END; 
            IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN 
                var_res := l_plus(var_tmp_1 |-> var_tmp_3)
            END; 
            SELECT (assert_ok = TRUE) THEN skip END; 
            is_initialisation := FALSE; 
            IF (var_clock1 = {ref |-> TRUE}) THEN 
                is_initialisation_clock1 := FALSE
            END; 
            IF ((var_clock1 = {ref |-> TRUE}) & (var_clock2 = {ref |-> TRUE})) THEN 
                is_initialisation_clock2 := FALSE
            END

        END;

     out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: 1
tmp_1: (1 when clock1)
tmp_2: 2
tmp_3: (2 when clock1)
*/
