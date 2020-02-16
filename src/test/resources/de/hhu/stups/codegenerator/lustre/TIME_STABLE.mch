MACHINE TIME_STABLE

INCLUDES Node_1.STABLE

SEES LibraryLustre

VARIABLES TIME_STABLE_is_initialisation, TIME_STABLE_var_second, TIME_STABLE_var_delay, TIME_STABLE_var_ck, TIME_STABLE_var_level, TIME_STABLE_var_tmp_2, TIME_STABLE_var_tmp_0, TIME_STABLE_var_set, TIME_STABLE_var_tmp_1, TIME_STABLE_var_tmp_4, TIME_STABLE_var_tmp_3

SETS TIME_STABLE_clocks = {TIME_STABLE_clock___basic__, TIME_STABLE_clock_ck}

INVARIANT ((TIME_STABLE_is_initialisation : TIME_STABLE_clocks --> BOOL) & ((TIME_STABLE_var_second : REF +-> BOOL) & ((TIME_STABLE_var_delay : REF +-> INTEGER) & ((TIME_STABLE_var_ck : REF +-> BOOL) & ((TIME_STABLE_var_level : REF +-> BOOL) & ((TIME_STABLE_var_tmp_2 : REF +-> INTEGER) & ((TIME_STABLE_var_tmp_0 : REF +-> BOOL) & ((TIME_STABLE_var_set : REF +-> BOOL) & ((TIME_STABLE_var_tmp_1 : REF +-> BOOL) & ((TIME_STABLE_var_tmp_4 : REF +-> BOOL) & ((TIME_STABLE_var_tmp_3 : REF +-> INTEGER) & (((TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) = FALSE) => (TIME_STABLE_var_level /= {})) & ((TIME_STABLE_is_initialisation(TIME_STABLE_clock_ck) = FALSE) => (TIME_STABLE_var_ck /= {}))))))))))))))

INITIALISATION 
    TIME_STABLE_is_initialisation := (TIME_STABLE_clocks * {TRUE}); 
    TIME_STABLE_var_second := {}; 
    TIME_STABLE_var_delay := {}; 
    TIME_STABLE_var_ck := {}; 
    TIME_STABLE_var_level := {}; 
    TIME_STABLE_var_tmp_2 := {}; 
    TIME_STABLE_var_tmp_0 := {}; 
    TIME_STABLE_var_set := {}; 
    TIME_STABLE_var_tmp_1 := {}; 
    TIME_STABLE_var_tmp_4 := {}; 
    TIME_STABLE_var_tmp_3 := {}


OPERATIONS 

    TIME_STABLE_clock_step(TIME_STABLE_param_set, TIME_STABLE_param_second, TIME_STABLE_param_delay) = 
        PRE
            ((TIME_STABLE_param_set : REF --> BOOL) & ((TIME_STABLE_param_second : REF --> BOOL) & (TIME_STABLE_param_delay : REF --> INTEGER)))
        THEN
            TIME_STABLE_var_set := TIME_STABLE_param_set; 
            TIME_STABLE_var_second := TIME_STABLE_param_second; 
            TIME_STABLE_var_delay := TIME_STABLE_param_delay; 
            TIME_STABLE_var_tmp_0 := TIME_STABLE_var_set; 
            TIME_STABLE_var_tmp_2 := TIME_STABLE_var_delay; 
            TIME_STABLE_var_ck := l_fby_boolean(TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) |-> {ref |-> TRUE} |-> l_or(TIME_STABLE_var_set |-> TIME_STABLE_var_second)); 
            IF (TIME_STABLE_var_ck = {ref |-> TRUE}) THEN 
                TIME_STABLE_var_tmp_1 := TIME_STABLE_var_tmp_0
            END; 
            IF (TIME_STABLE_var_ck = {ref |-> TRUE}) THEN 
                TIME_STABLE_var_tmp_3 := TIME_STABLE_var_tmp_2
            END; 
            Node_1.STABLE_clock_step(TIME_STABLE_var_tmp_1, TIME_STABLE_var_tmp_3); 
            IF (TIME_STABLE_var_ck = {ref |-> TRUE}) THEN 
                TIME_STABLE_var_tmp_4 := Node_1.STABLE_var_level
            END; 
            TIME_STABLE_var_level := TIME_STABLE_var_tmp_4; 
            TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) := FALSE; 
            IF (TIME_STABLE_var_ck = {ref |-> TRUE}) THEN 
                TIME_STABLE_is_initialisation(TIME_STABLE_clock_ck) := FALSE
            END

        END;

        out <-- getLevel = BEGIN out := TIME_STABLE_var_level END



END