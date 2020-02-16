MACHINE STABLE

SEES LibraryLustre

VARIABLES STABLE_is_initialisation, STABLE_var_level, STABLE_var_delay, STABLE_var_count, STABLE_var_tmp_0, STABLE_var_set, STABLE_var_tmp_2, STABLE_var_tmp_1, STABLE_var_tmp_3

SETS STABLE_clocks = {STABLE_clock___basic__}

INVARIANT ((STABLE_is_initialisation : STABLE_clocks --> BOOL) & ((STABLE_var_level : REF +-> BOOL) & ((STABLE_var_delay : REF +-> INTEGER) & ((STABLE_var_count : REF +-> INTEGER) & ((STABLE_var_tmp_0 : REF +-> BOOL) & ((STABLE_var_set : REF +-> BOOL) & ((STABLE_var_tmp_2 : REF +-> INTEGER) & ((STABLE_var_tmp_1 : REF +-> BOOL) & (STABLE_var_tmp_3 : REF +-> INTEGER)))))))))

INITIALISATION 
    STABLE_is_initialisation := (STABLE_clocks * {TRUE}); 
    STABLE_var_level := {}; 
    STABLE_var_delay := {}; 
    STABLE_var_count := {}; 
    STABLE_var_tmp_0 := {}; 
    STABLE_var_set := {}; 
    STABLE_var_tmp_2 := {}; 
    STABLE_var_tmp_1 := {}; 
    STABLE_var_tmp_3 := {}


OPERATIONS 

    STABLE_clock_step(STABLE_param_set, STABLE_param_delay) = 
        PRE
            ((STABLE_param_set : REF +-> BOOL) & (STABLE_param_delay : REF +-> INTEGER))
        THEN
            VAR STABLE_tmp_0_history, STABLE_tmp_2_history IN
                STABLE_tmp_0_history := STABLE_var_tmp_0; 
                STABLE_tmp_2_history := STABLE_var_tmp_2; 
                STABLE_var_set := STABLE_param_set; 
                STABLE_var_delay := STABLE_param_delay; 
                STABLE_var_tmp_1 := STABLE_tmp_0_history; 
                STABLE_var_tmp_3 := STABLE_tmp_2_history; 
                STABLE_var_count := l_if_then_else_integer(STABLE_var_set |-> STABLE_var_delay |-> l_if_then_else_integer(l_fby_boolean(STABLE_is_initialisation(STABLE_clock___basic__) |-> {ref |-> FALSE} |-> STABLE_var_tmp_1) |-> l_minus(STABLE_var_tmp_3 |-> {ref |-> 1}) |-> {ref |-> 0})); 
                STABLE_var_level := l_greater(STABLE_var_count |-> {ref |-> 0}); 
                STABLE_var_tmp_0 := STABLE_var_level; 
                STABLE_var_tmp_2 := STABLE_var_count; 
                STABLE_is_initialisation(STABLE_clock___basic__) := FALSE

            END

        END



END