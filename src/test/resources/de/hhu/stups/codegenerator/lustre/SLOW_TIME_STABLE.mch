MACHINE SLOW_TIME_STABLE

INCLUDES Node_1.SLOW_STABLE

SEES LibraryLustre

VARIABLES SLOW_TIME_STABLE_is_initialisation, SLOW_TIME_STABLE_var_second, SLOW_TIME_STABLE_var_delay, SLOW_TIME_STABLE_var_level, SLOW_TIME_STABLE_var_tmp_0, SLOW_TIME_STABLE_var_set, SLOW_TIME_STABLE_var_tmp_2, SLOW_TIME_STABLE_var_tmp_1, SLOW_TIME_STABLE_var_tmp_3

SETS SLOW_TIME_STABLE_clocks = {SLOW_TIME_STABLE_clock___basic__, SLOW_TIME_STABLE_clock_second}

INVARIANT ((SLOW_TIME_STABLE_is_initialisation : SLOW_TIME_STABLE_clocks --> BOOL) & ((SLOW_TIME_STABLE_var_second : REF +-> BOOL) & ((SLOW_TIME_STABLE_var_delay : REF +-> INTEGER) & ((SLOW_TIME_STABLE_var_level : REF +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_0 : REF +-> BOOL) & ((SLOW_TIME_STABLE_var_set : REF +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_2 : REF +-> INTEGER) & ((SLOW_TIME_STABLE_var_tmp_1 : REF +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_3 : REF +-> INTEGER) & (((SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) = FALSE) => (SLOW_TIME_STABLE_var_level /= {})) & ((SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) = FALSE) => (SLOW_TIME_STABLE_var_second /= {}))))))))))))

INITIALISATION 
    SLOW_TIME_STABLE_is_initialisation := (SLOW_TIME_STABLE_clocks * {TRUE}); 
    SLOW_TIME_STABLE_var_second := {}; 
    SLOW_TIME_STABLE_var_delay := {}; 
    SLOW_TIME_STABLE_var_level := {}; 
    SLOW_TIME_STABLE_var_tmp_0 := {}; 
    SLOW_TIME_STABLE_var_set := {}; 
    SLOW_TIME_STABLE_var_tmp_2 := {}; 
    SLOW_TIME_STABLE_var_tmp_1 := {}; 
    SLOW_TIME_STABLE_var_tmp_3 := {}


OPERATIONS 

    SLOW_TIME_STABLE_clock_step(SLOW_TIME_STABLE_param_set, SLOW_TIME_STABLE_param_second, SLOW_TIME_STABLE_param_delay) = 
        PRE
            ((SLOW_TIME_STABLE_param_set : REF --> BOOL) & ((SLOW_TIME_STABLE_param_second : REF --> BOOL) & (SLOW_TIME_STABLE_param_delay : REF --> INTEGER)))
        THEN
            SLOW_TIME_STABLE_var_set := SLOW_TIME_STABLE_param_set; 
            SLOW_TIME_STABLE_var_second := SLOW_TIME_STABLE_param_second; 
            SLOW_TIME_STABLE_var_delay := SLOW_TIME_STABLE_param_delay; 
            SLOW_TIME_STABLE_var_tmp_0 := SLOW_TIME_STABLE_var_set; 
            IF (SLOW_TIME_STABLE_var_second = {ref |-> TRUE}) THEN 
                SLOW_TIME_STABLE_var_tmp_1 := SLOW_TIME_STABLE_var_tmp_0
            END; 
            SLOW_TIME_STABLE_var_tmp_2 := SLOW_TIME_STABLE_var_delay; 
            IF (SLOW_TIME_STABLE_var_second = {ref |-> TRUE}) THEN 
                SLOW_TIME_STABLE_var_tmp_3 := SLOW_TIME_STABLE_var_tmp_2
            END; 
            Node_1.SLOW_STABLE_clock_step(SLOW_TIME_STABLE_var_tmp_1, SLOW_TIME_STABLE_var_tmp_3); 
            IF (SLOW_TIME_STABLE_var_second = {ref |-> TRUE}) THEN 
                SLOW_TIME_STABLE_var_level := Node_1.SLOW_STABLE_var_level
            END; 
            SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock___basic__) := FALSE; 
            IF (SLOW_TIME_STABLE_var_second = {ref |-> TRUE}) THEN 
                SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) := FALSE
            END

        END;

        out <-- getLevel = BEGIN out := SLOW_TIME_STABLE_var_level END



END