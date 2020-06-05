MACHINE M_NilChecking5

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res, var_tmp_0, var_x, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_INT) & ((var_res : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}; 
    var_x := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR hvar_x, hvar_tmp_1 IN
                hvar_x := var_x; 
                hvar_tmp_1 := var_tmp_1; 
                var_x := param_x; 
                var_tmp_1 := var_tmp_0; 
                var_tmp_0 := l_plus(var_x |-> hvar_x); 
                var_res := hvar_tmp_1; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;


    out <-- getRes = BEGIN out := var_res END



END

/*
tmp_0: (x + pre(x))
tmp_1: pre((x + pre(x)))
*/
