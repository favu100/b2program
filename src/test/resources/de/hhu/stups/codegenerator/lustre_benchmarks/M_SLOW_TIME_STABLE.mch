//generated from Lustre
//taken from Lustre V6 Language Manual

MACHINE M_SLOW_TIME_STABLE

INCLUDES Node_1.M_SLOW_STABLE

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_second, is_initialisation, var_level, var_second

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_second : BOOL) & ((is_initialisation : BOOL) & ((var_second : LUSTRE_BOOL) & ((var_level : LUSTRE_BOOL) & ((is_initialisation_second = FALSE) => (var_level /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_second := TRUE; 
    is_initialisation := TRUE; 
    var_level := {}; 
    var_second := {}


OPERATIONS 

    clock_step(param_set, param_second, param_delay) = 
        PRE
            ((param_set : LUSTRE_BOOL_NOT_NIL) & ((param_second : LUSTRE_BOOL_NOT_NIL) & (param_delay : LUSTRE_INT_NOT_NIL)))
        THEN
            VAR var_set, var_delay IN
                var_set := param_set; 
                var_second := param_second; 
                PRE (var_second /= {}) THEN skip END; 
                var_delay := param_delay; 
                IF (var_second = {ref |-> TRUE}) THEN 
                    Node_1.clock_step(var_set, var_delay)
                END; 
                IF (var_second = {ref |-> TRUE}) THEN 
                    var_level := Node_1.var_level
                END; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                IF (var_second = {ref |-> TRUE}) THEN 
                    is_initialisation_second := FALSE
                END; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: SLOW_STABLE((set, delay when second))
*/
