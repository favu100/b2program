MACHINE M_Machine

INCLUDES Node_1.M_Machine_clock

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_clock_clock, var_res, var_res1, var_clock_clock, var_tmp_1

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_clock_clock : BOOL) & ((var_clock_clock : LUSTRE_BOOL) & ((var_res1 : LUSTRE_BOOL) & ((var_res : LUSTRE_BOOL) & ((var_tmp_1 : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_res1 /= {})) & ((is_initialisation = FALSE) => (var_res /= {}))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_clock_clock := TRUE; 
    var_res := {}; 
    var_res1 := {}; 
    var_clock_clock := {}; 
    var_tmp_1 := {}


OPERATIONS 

    clock_step(param_clock_clock) = 
        PRE
            (param_clock_clock : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR var_tmp_0 IN
                var_clock_clock := param_clock_clock; 
                PRE (var_clock_clock /= {}) THEN skip END; 
                var_tmp_0 := {ref |-> TRUE}; 
                Node_1.clock_step(var_clock_clock); 
                var_res := Node_1.var_res; 
                IF (var_clock_clock = {ref |-> TRUE}) THEN 
                    var_tmp_1 := var_tmp_0
                END; 
                var_res1 := var_tmp_1; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_clock_clock = {ref |-> TRUE}) THEN 
                    is_initialisation_clock_clock := FALSE
                END

            END

        END;

     out <-- getRes = BEGIN out := var_res END;
     out <-- getRes1 = BEGIN out := var_res1 END



END

/*
Node_1: Machine_clock(clock_clock)
tmp_0: true
tmp_1: (true when clock_clock)
*/
