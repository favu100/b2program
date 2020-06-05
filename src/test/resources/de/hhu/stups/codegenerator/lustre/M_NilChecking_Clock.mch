MACHINE M_NilChecking_Clock

INCLUDES Node_1.M_NilChecking_Clock_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_pre_clock, var_res, var_clock, var_x, var_pre_clock, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_pre_clock : BOOL) & ((var_x : LUSTRE_INT) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & ((var_pre_clock : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_pre_clock := TRUE; 
    var_res := {}; 
    var_clock := {}; 
    var_x := {}; 
    var_pre_clock := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_clock, param_x) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_x : LUSTRE_INT_NOT_NIL))
        THEN
            VAR hvar_clock IN
                hvar_clock := var_clock; 
                var_clock := param_clock; 
                var_x := param_x; 
                var_pre_clock := hvar_clock; 
                PRE (var_pre_clock /= {}) THEN skip END; 
                Node_1.clock_step(var_pre_clock, var_x); 
                IF (var_pre_clock = {ref |-> TRUE}) THEN 
                    var_tmp_0 := Node_1.var_res
                END; 
                var_res := var_tmp_0; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_pre_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_pre_clock := FALSE
                END

            END

        END



END

/*
Node_1: NilChecking_Clock_Call(pre_clock, (x when pre_clock))
tmp_0: NilChecking_Clock_Call(pre_clock, (x when pre_clock))
*/
