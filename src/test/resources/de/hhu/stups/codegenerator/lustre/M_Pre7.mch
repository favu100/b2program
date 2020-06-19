MACHINE M_Pre7

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_B, is_initialisation, var_Y, var_B, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_B : BOOL) & ((is_initialisation : BOOL) & ((var_B : LUSTRE_BOOL) & ((var_Y : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation_B = FALSE) => (var_Y /= {}))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_B := TRUE; 
    is_initialisation := TRUE; 
    var_Y := {}; 
    var_B := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_X, param_B) = 
        PRE
            ((param_X : LUSTRE_INT_NOT_NIL) & (param_B : LUSTRE_BOOL_NOT_NIL))
        THEN
            VAR hvar_tmp_0, var_X IN
                hvar_tmp_0 := var_tmp_0; 
                var_X := param_X; 
                var_B := param_B; 
                PRE (var_B /= {}) THEN skip END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    var_tmp_0 := var_X
                END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    var_Y := hvar_tmp_0
                END; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                IF (var_B = {ref |-> TRUE}) THEN 
                    is_initialisation_B := FALSE
                END; 
                is_initialisation := FALSE

            END

        END;


    out <-- getY = BEGIN out := var_Y END



END

/*
tmp_0: (X when B)
*/
