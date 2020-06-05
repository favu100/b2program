MACHINE M_TIME_STABLE

INCLUDES Node_1.M_STABLE

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, is_initialisation_ck, var_level, var_set, var_delay, var_ck, var_tmp_0

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_ck : BOOL) & ((var_delay : LUSTRE_INT) & ((var_set : LUSTRE_BOOL) & ((var_level : LUSTRE_BOOL) & ((var_tmp_0 : LUSTRE_BOOL) & ((var_ck : LUSTRE_BOOL) & ((is_initialisation = FALSE) => (var_level /= {}))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    is_initialisation_ck := TRUE; 
    var_level := {}; 
    var_set := {}; 
    var_delay := {}; 
    var_ck := {}; 
    var_tmp_0 := {}


OPERATIONS 

    clock_step(param_set, param_second, param_delay) = 
        PRE
            ((param_set : LUSTRE_BOOL_NOT_NIL) & ((param_second : LUSTRE_BOOL_NOT_NIL) & (param_delay : LUSTRE_INT_NOT_NIL)))
        THEN
            VAR var_second IN
                var_set := param_set; 
                var_second := param_second; 
                var_delay := param_delay; 
                var_ck := l_fby_boolean(is_initialisation |-> {ref |-> TRUE} |-> l_or(var_set |-> var_second)); 
                PRE (var_ck /= {}) THEN skip END; 
                IF (var_ck = {ref |-> TRUE}) THEN 
                    Node_1.clock_step(var_set, var_delay)
                END; 
                IF (var_ck = {ref |-> TRUE}) THEN 
                    var_tmp_0 := Node_1.var_level
                END; 
                var_level := var_tmp_0; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE; 
                IF (var_ck = {ref |-> TRUE}) THEN 
                    is_initialisation_ck := FALSE
                END

            END

        END;

    out <-- getLevel = BEGIN out := var_level END



END

/*
Node_1: STABLE((set, delay when ck))
tmp_0: STABLE((set when ck), (delay when ck))
*/
