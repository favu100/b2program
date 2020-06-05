MACHINE M_Pre3

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_a : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_a /= {}))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR hvar_tmp_0, var_x IN
                hvar_tmp_0 := var_tmp_0; 
                var_x := param_x; 
                var_tmp_0 := {ref |-> 1}; 
                var_a := hvar_tmp_0; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;


     out <-- getA = BEGIN out := var_a END



END

/*
tmp_0: 1
*/
