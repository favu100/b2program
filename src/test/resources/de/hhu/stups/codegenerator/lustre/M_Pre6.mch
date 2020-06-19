MACHINE M_Pre6

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_B, is_initialisation, var_res1, var_res2, var_tmp_2, var_X, var_tmp_3, var_B, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_B : BOOL) & ((is_initialisation : BOOL) & ((var_B : LUSTRE_BOOL) & ((var_res2 : LUSTRE_INT) & ((var_res1 : LUSTRE_INT) & ((var_tmp_3 : LUSTRE_INT) & ((var_tmp_2 : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_X : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_res2 /= {})) & ((is_initialisation = FALSE) => (var_res1 /= {})))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_B := TRUE; 
    is_initialisation := TRUE; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_tmp_2 := {}; 
    var_X := {}; 
    var_tmp_3 := {}; 
    var_B := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_B) = 
        PRE
            (param_B : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_tmp_0 IN
                var_B := param_B; 
                PRE (var_B /= {}) THEN skip END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    var_tmp_3 := var_tmp_2
                END; 
                var_tmp_0 := var_X; 
                var_X := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> l_plus(var_X |-> {ref |-> 1})); 
                var_res2 := var_tmp_3; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    var_tmp_1 := var_tmp_0
                END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    var_tmp_2 := var_X
                END; 
                var_res1 := var_tmp_1; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    is_initialisation_B := FALSE
                END; 
                is_initialisation := FALSE

            END

        END;



    out <-- getRes1 = BEGIN out := var_res1 END;
    out <-- getRes2 = BEGIN out := var_res2 END



END

/*
tmp_0: pre(X)
tmp_1: (pre(X) when B)
tmp_2: (X when B)
tmp_3: pre((X when B))
*/
