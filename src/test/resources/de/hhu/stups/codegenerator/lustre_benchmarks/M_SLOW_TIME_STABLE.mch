MACHINE M_SLOW_TIME_STABLE

INCLUDES Node_1.M_SLOW_STABLE

SEES LibraryLustre

VARIABLES is_initialisation_second, is_initialisation, var_level, var_set, var_delay, var_second

INVARIANT ((var_delay : LUSTRE_INT) & ((var_second : LUSTRE_BOOL) & ((var_set : LUSTRE_BOOL) & ((var_level : LUSTRE_BOOL) & ((is_initialisation_second : BOOL) & ((is_initialisation : BOOL) & ((is_initialisation_second = FALSE) => (var_level /= {}))))))))

INITIALISATION 
    is_initialisation_second := TRUE; 
    is_initialisation := TRUE; 
    var_level := {}; 
    var_set := {}; 
    var_delay := {}; 
    var_second := {}


OPERATIONS 

    clock_step(param_set, param_second, param_delay) = 
        PRE
            ((param_set : LUSTRE_BOOL_NOT_NIL) & ((param_second : LUSTRE_BOOL_NOT_NIL) & (param_delay : LUSTRE_INT_NOT_NIL)))
        THEN
            var_set := param_set; 
            var_second := param_second; 
            var_delay := param_delay; 
            IF (var_second = {ref |-> TRUE}) THEN 
                Node_1.clock_step(var_set, var_delay)
            END; 
            IF (var_second = {ref |-> TRUE}) THEN 
                var_level := Node_1.var_level
            END; 
            IF (var_second = {ref |-> TRUE}) THEN 
                is_initialisation_second := FALSE
            END; 
            is_initialisation := FALSE

        END



END