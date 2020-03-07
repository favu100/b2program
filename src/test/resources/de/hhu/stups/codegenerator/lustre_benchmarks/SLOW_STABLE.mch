MACHINE SLOW_STABLE

SEES LibraryLustre

VARIABLES SLOW_STABLE_is_initialisation, SLOW_STABLE_var_level, SLOW_STABLE_var_count

SETS SLOW_STABLE_clocks = {SLOW_STABLE_clock___basic__}

INVARIANT ((SLOW_STABLE_is_initialisation : SLOW_STABLE_clocks --> BOOL) & ((SLOW_STABLE_var_count : REF +-> INTEGER) & (SLOW_STABLE_var_level : REF +-> BOOL)))

INITIALISATION 
    SLOW_STABLE_is_initialisation := (SLOW_STABLE_clocks * {TRUE}); 
    SLOW_STABLE_var_level := {}; 
    SLOW_STABLE_var_count := {}


OPERATIONS 

    SLOW_STABLE_clock_step(SLOW_STABLE_param_set, SLOW_STABLE_param_delay) = 
        PRE
            ((SLOW_STABLE_param_set : REF +-> BOOL) & (SLOW_STABLE_param_delay : REF +-> INTEGER))
        THEN
            VAR SLOW_STABLE_var_delay, SLOW_STABLE_var_set IN
                SLOW_STABLE_var_set := SLOW_STABLE_param_set; 
                SLOW_STABLE_var_delay := SLOW_STABLE_param_delay; 
                SLOW_STABLE_var_count := l_ite_integer(SLOW_STABLE_var_set |-> SLOW_STABLE_var_delay |-> l_ite_integer(l_fby_boolean(SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) |-> {ref |-> FALSE} |-> SLOW_STABLE_var_level) |-> l_minus(SLOW_STABLE_var_count |-> {ref |-> 1}) |-> {ref |-> 0})); 
                SLOW_STABLE_var_level := l_greater(SLOW_STABLE_var_count |-> {ref |-> 0}); 
                SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) := FALSE

            END

        END



END