MACHINE M_microbenchmarks_many_clocks

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_c1, is_initialisation_c2, is_initialisation_c3, is_initialisation_c4, is_initialisation_c5, var_res, var_c1, var_tmp_1, var_c2, var_tmp_2, var_c3, var_tmp_3, var_c4, var_tmp_4, var_c5, var_tmp_5, var_tmp_6, var_tmp_7, var_tmp_8, var_tmp_9

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_c1 : BOOL) & ((is_initialisation_c2 : BOOL) & ((is_initialisation_c3 : BOOL) & ((is_initialisation_c4 : BOOL) & ((is_initialisation_c5 : BOOL) & ((var_c5 : LUSTRE_BOOL) & ((var_c4 : LUSTRE_BOOL) & ((var_c3 : LUSTRE_BOOL) & ((var_c2 : LUSTRE_BOOL) & ((var_c1 : LUSTRE_BOOL) & ((var_res : LUSTRE_BOOL) & ((var_tmp_5 : LUSTRE_BOOL) & ((var_tmp_6 : LUSTRE_BOOL) & ((var_tmp_4 : LUSTRE_BOOL) & ((var_tmp_7 : LUSTRE_BOOL) & ((var_tmp_3 : LUSTRE_BOOL) & ((var_tmp_8 : LUSTRE_BOOL) & ((var_tmp_2 : LUSTRE_BOOL) & ((var_tmp_9 : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))))))))))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_c1 := TRUE; 
    is_initialisation_c2 := TRUE; 
    is_initialisation_c3 := TRUE; 
    is_initialisation_c4 := TRUE; 
    is_initialisation_c5 := TRUE; 
    var_res := {}; 
    var_c1 := {}; 
    var_tmp_1 := {}; 
    var_c2 := {}; 
    var_tmp_2 := {}; 
    var_c3 := {}; 
    var_tmp_3 := {}; 
    var_c4 := {}; 
    var_tmp_4 := {}; 
    var_c5 := {}; 
    var_tmp_5 := {}; 
    var_tmp_6 := {}; 
    var_tmp_7 := {}; 
    var_tmp_8 := {}; 
    var_tmp_9 := {}


OPERATIONS 

    clock_step(param_c1, param_c2, param_c3, param_c4, param_c5) = 
        PRE
            ((param_c1 : LUSTRE_BOOL_NOT_NIL) & ((param_c2 : LUSTRE_BOOL_NOT_NIL) & ((param_c3 : LUSTRE_BOOL_NOT_NIL) & ((param_c4 : LUSTRE_BOOL_NOT_NIL) & (param_c5 : LUSTRE_BOOL_NOT_NIL)))))
        THEN
            VAR var_tmp_0 IN
                var_c1 := param_c1; 
                PRE (var_c1 /= {}) THEN skip END; 
                IF (var_c1 = {ref |-> TRUE}) THEN 
                    var_c2 := param_c2; 
                    PRE (var_c2 /= {}) THEN skip END

                END; 
                IF ((var_c1 = {ref |-> TRUE}) & (var_c2 = {ref |-> TRUE})) THEN 
                    var_c3 := param_c3; 
                    PRE (var_c3 /= {}) THEN skip END

                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & (var_c3 = {ref |-> TRUE}))) THEN 
                    var_c4 := param_c4; 
                    PRE (var_c4 /= {}) THEN skip END

                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & (var_c4 = {ref |-> TRUE})))) THEN 
                    var_c5 := param_c5; 
                    PRE (var_c5 /= {}) THEN skip END

                END; 
                var_tmp_0 := {ref |-> TRUE}; 
                IF (var_c1 = {ref |-> TRUE}) THEN 
                    var_tmp_1 := var_tmp_0
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & (var_c2 = {ref |-> TRUE})) THEN 
                    var_tmp_2 := var_tmp_1
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & (var_c3 = {ref |-> TRUE}))) THEN 
                    var_tmp_3 := var_tmp_2
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & (var_c4 = {ref |-> TRUE})))) THEN 
                    var_tmp_4 := var_tmp_3
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & ((var_c4 = {ref |-> TRUE}) & (var_c5 = {ref |-> TRUE}))))) THEN 
                    var_tmp_5 := var_tmp_4
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & (var_c4 = {ref |-> TRUE})))) THEN 
                    var_tmp_6 := var_tmp_5
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & (var_c3 = {ref |-> TRUE}))) THEN 
                    var_tmp_7 := var_tmp_6
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & (var_c2 = {ref |-> TRUE})) THEN 
                    var_tmp_8 := var_tmp_7
                END; 
                IF (var_c1 = {ref |-> TRUE}) THEN 
                    var_tmp_9 := var_tmp_8
                END; 
                var_res := var_tmp_9; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_c1 = {ref |-> TRUE}) THEN 
                    is_initialisation_c1 := FALSE
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & (var_c2 = {ref |-> TRUE})) THEN 
                    is_initialisation_c2 := FALSE
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & (var_c3 = {ref |-> TRUE}))) THEN 
                    is_initialisation_c3 := FALSE
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & (var_c4 = {ref |-> TRUE})))) THEN 
                    is_initialisation_c4 := FALSE
                END; 
                IF ((var_c1 = {ref |-> TRUE}) & ((var_c2 = {ref |-> TRUE}) & ((var_c3 = {ref |-> TRUE}) & ((var_c4 = {ref |-> TRUE}) & (var_c5 = {ref |-> TRUE}))))) THEN 
                    is_initialisation_c5 := FALSE
                END

            END

        END



END

/*
tmp_0: true
tmp_1: (true when c1)
tmp_2: ((true when c1) when c2)
tmp_3: (((true when c1) when c2) when c3)
tmp_4: ((((true when c1) when c2) when c3) when c4)
tmp_5: (((((true when c1) when c2) when c3) when c4) when c5)
tmp_6: current((((((true when c1) when c2) when c3) when c4) when c5))
tmp_7: current(current((((((true when c1) when c2) when c3) when c4) when c5)))
tmp_8: current(current(current((((((true when c1) when c2) when c3) when c4) when c5))))
tmp_9: current(current(current(current((((((true when c1) when c2) when c3) when c4) when c5)))))
*/
