MACHINE M_Nil

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res, var_tmp_0, var_tmp_1, var_tmp_2

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_2 : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_tmp_1 := {}; 
    var_tmp_2 := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR hvar_tmp_0, hvar_tmp_1, hvar_tmp_2, var_x, var_y IN
                hvar_tmp_0 := var_tmp_0; 
                hvar_tmp_1 := var_tmp_1; 
                hvar_tmp_2 := var_tmp_2; 
                var_x := param_x; 
                var_tmp_2 := {ref |-> 2}; 
                var_tmp_1 := {ref |-> 3}; 
                var_tmp_0 := {ref |-> 2}; 
                var_y := l_plus(hvar_tmp_0 |-> hvar_tmp_1); 
                var_res := l_plus(var_x |-> hvar_tmp_2); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: 2
tmp_1: 3
tmp_2: 2
*/
