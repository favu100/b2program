MACHINE M_Clock8

INCLUDES Node_1.M_Clock8_aux

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, is_initialisation, var_res, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_val : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_clock, var_val IN
                var_clock := param_clock; 
                PRE (var_clock /= {}) THEN skip END; 
                var_val := param_val; 
                Node_1.clock_step(var_clock, var_val); 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    var_tmp_0 := Node_1.var_res
                END; 
                var_res := var_tmp_0; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                IF (var_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_clock := FALSE
                END; 
                is_initialisation := FALSE

            END

        END;


     out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: Clock8_aux(clock, val)
tmp_0: Clock8_aux(clock, val)
*/
