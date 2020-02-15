MACHINE SLOW_STABLE

VARIABLES SLOW_STABLE_is_initialisation, SLOW_STABLE_var_level, SLOW_STABLE_var_delay, SLOW_STABLE_var_count, SLOW_STABLE_var_tmp_0, SLOW_STABLE_var_set, SLOW_STABLE_var_tmp_2, SLOW_STABLE_var_tmp_1, SLOW_STABLE_var_tmp_3

SETS SLOW_STABLE_clocks = {SLOW_STABLE_clock___basic__}; SLOW_STABLE_refs = {SLOW_STABLE_ref}

INVARIANT ((SLOW_STABLE_is_initialisation : SLOW_STABLE_clocks --> BOOL) & ((SLOW_STABLE_var_level : SLOW_STABLE_refs +-> BOOL) & ((SLOW_STABLE_var_delay : SLOW_STABLE_refs +-> INTEGER) & ((SLOW_STABLE_var_count : SLOW_STABLE_refs +-> INTEGER) & ((SLOW_STABLE_var_tmp_0 : SLOW_STABLE_refs +-> BOOL) & ((SLOW_STABLE_var_set : SLOW_STABLE_refs +-> BOOL) & ((SLOW_STABLE_var_tmp_2 : SLOW_STABLE_refs +-> INTEGER) & ((SLOW_STABLE_var_tmp_1 : SLOW_STABLE_refs +-> BOOL) & (SLOW_STABLE_var_tmp_3 : SLOW_STABLE_refs +-> INTEGER)))))))))

INITIALISATION 
    SLOW_STABLE_is_initialisation := (SLOW_STABLE_clocks * {TRUE}); 
    SLOW_STABLE_var_level := {}; 
    SLOW_STABLE_var_delay := {}; 
    SLOW_STABLE_var_count := {}; 
    SLOW_STABLE_var_tmp_0 := {}; 
    SLOW_STABLE_var_set := {}; 
    SLOW_STABLE_var_tmp_2 := {}; 
    SLOW_STABLE_var_tmp_1 := {}; 
    SLOW_STABLE_var_tmp_3 := {}


OPERATIONS 

    SLOW_STABLE_clock_step(SLOW_STABLE_param_set, SLOW_STABLE_param_delay) = 
        PRE
            ((SLOW_STABLE_param_set : BOOL) & (SLOW_STABLE_param_delay : INTEGER))
        THEN
            VAR SLOW_STABLE_level_history, SLOW_STABLE_delay_history, SLOW_STABLE_count_history, SLOW_STABLE_tmp_0_history, SLOW_STABLE_set_history, SLOW_STABLE_tmp_2_history, SLOW_STABLE_tmp_1_history, SLOW_STABLE_tmp_3_history IN
                SLOW_STABLE_level_history := SLOW_STABLE_var_level; 
                SLOW_STABLE_delay_history := SLOW_STABLE_var_delay; 
                SLOW_STABLE_count_history := SLOW_STABLE_var_count; 
                SLOW_STABLE_tmp_0_history := SLOW_STABLE_var_tmp_0; 
                SLOW_STABLE_set_history := SLOW_STABLE_var_set; 
                SLOW_STABLE_tmp_2_history := SLOW_STABLE_var_tmp_2; 
                SLOW_STABLE_tmp_1_history := SLOW_STABLE_var_tmp_1; 
                SLOW_STABLE_tmp_3_history := SLOW_STABLE_var_tmp_3; 
                SLOW_STABLE_var_set(SLOW_STABLE_ref) := bool((SLOW_STABLE_param_set = TRUE)); 
                SLOW_STABLE_var_delay(SLOW_STABLE_ref) := SLOW_STABLE_param_delay; 
                IF (SLOW_STABLE_tmp_0_history /= {}) THEN 
                    SLOW_STABLE_var_tmp_1(SLOW_STABLE_ref) := bool((SLOW_STABLE_tmp_0_history(SLOW_STABLE_ref) = TRUE))
                ELSE 
                    SLOW_STABLE_var_tmp_1 := {}
                END; 
                IF (SLOW_STABLE_tmp_2_history /= {}) THEN 
                    SLOW_STABLE_var_tmp_3(SLOW_STABLE_ref) := SLOW_STABLE_tmp_2_history(SLOW_STABLE_ref)
                ELSE 
                    SLOW_STABLE_var_tmp_3 := {}
                END; 
                IF ((SLOW_STABLE_var_set /= {}) & (((SLOW_STABLE_var_set(SLOW_STABLE_ref) = TRUE) => (SLOW_STABLE_var_delay /= {})) or (not((SLOW_STABLE_var_set(SLOW_STABLE_ref) = TRUE)) => ((not((SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) = TRUE)) => (SLOW_STABLE_var_tmp_1 /= {})) & ((IF (SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) = TRUE) THEN FALSE ELSE bool((SLOW_STABLE_var_tmp_1(SLOW_STABLE_ref) = TRUE)) END = TRUE) => (SLOW_STABLE_var_tmp_3 /= {})))))) THEN 
                    SLOW_STABLE_var_count(SLOW_STABLE_ref) := IF (SLOW_STABLE_var_set(SLOW_STABLE_ref) = TRUE) THEN SLOW_STABLE_var_delay(SLOW_STABLE_ref) ELSE IF (IF (SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) = TRUE) THEN FALSE ELSE bool((SLOW_STABLE_var_tmp_1(SLOW_STABLE_ref) = TRUE)) END = TRUE) THEN (SLOW_STABLE_var_tmp_3(SLOW_STABLE_ref) - 1) ELSE 0 END END
                ELSE 
                    SLOW_STABLE_var_count := {}
                END; 
                IF (SLOW_STABLE_var_count /= {}) THEN 
                    SLOW_STABLE_var_level(SLOW_STABLE_ref) := bool((SLOW_STABLE_var_count(SLOW_STABLE_ref) > 0))
                ELSE 
                    SLOW_STABLE_var_level := {}
                END; 
                IF (SLOW_STABLE_var_level /= {}) THEN 
                    SLOW_STABLE_var_tmp_0(SLOW_STABLE_ref) := bool((SLOW_STABLE_var_level(SLOW_STABLE_ref) = TRUE))
                ELSE 
                    SLOW_STABLE_var_tmp_0 := {}
                END; 
                IF (SLOW_STABLE_var_count /= {}) THEN 
                    SLOW_STABLE_var_tmp_2(SLOW_STABLE_ref) := SLOW_STABLE_var_count(SLOW_STABLE_ref)
                ELSE 
                    SLOW_STABLE_var_tmp_2 := {}
                END; 
                SLOW_STABLE_is_initialisation(SLOW_STABLE_clock___basic__) := FALSE

            END

        END



END