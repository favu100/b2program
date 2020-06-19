MACHINE M_When10

INCLUDES Node_1.M_When10_call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {}))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_clock, param_val) = 
        PRE
            ((param_clock : LUSTRE_BOOL_NOT_NIL) & (param_val : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_val IN
                var_clock := param_clock; 
                var_val := param_val; 
                Node_1.clock_step(var_clock, var_val); 
                var_res := Node_1.var_res; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

    out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: When10_call(clock, (val when clock))
*/
