MACHINE STABLE

VARIABLES STABLE_is_initialisation, STABLE_var_level, STABLE_var_delay, STABLE_var_count, STABLE_var_tmp_0, STABLE_var_set, STABLE_var_tmp_2, STABLE_var_tmp_1, STABLE_var_tmp_3

SETS STABLE_clocks = {STABLE_clock___basic__}; STABLE_refs = {STABLE_ref}

INVARIANT ((STABLE_is_initialisation : STABLE_clocks --> BOOL) & ((STABLE_var_level : STABLE_refs +-> BOOL) & ((STABLE_var_delay : STABLE_refs +-> INTEGER) & ((STABLE_var_count : STABLE_refs +-> INTEGER) & ((STABLE_var_tmp_0 : STABLE_refs +-> BOOL) & ((STABLE_var_set : STABLE_refs +-> BOOL) & ((STABLE_var_tmp_2 : STABLE_refs +-> INTEGER) & ((STABLE_var_tmp_1 : STABLE_refs +-> BOOL) & (STABLE_var_tmp_3 : STABLE_refs +-> INTEGER)))))))))

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
            ((STABLE_param_set : BOOL) & (STABLE_param_delay : INTEGER))
        THEN
            VAR STABLE_level_history, STABLE_delay_history, STABLE_count_history, STABLE_tmp_0_history, STABLE_set_history, STABLE_tmp_2_history, STABLE_tmp_1_history, STABLE_tmp_3_history IN
                STABLE_level_history := STABLE_var_level; 
                STABLE_delay_history := STABLE_var_delay; 
                STABLE_count_history := STABLE_var_count; 
                STABLE_tmp_0_history := STABLE_var_tmp_0; 
                STABLE_set_history := STABLE_var_set; 
                STABLE_tmp_2_history := STABLE_var_tmp_2; 
                STABLE_tmp_1_history := STABLE_var_tmp_1; 
                STABLE_tmp_3_history := STABLE_var_tmp_3; 
                STABLE_var_set(STABLE_ref) := bool((STABLE_param_set = TRUE)); 
                STABLE_var_delay(STABLE_ref) := STABLE_param_delay; 
                IF (STABLE_tmp_0_history /= {}) THEN 
                    STABLE_var_tmp_1(STABLE_ref) := bool((STABLE_tmp_0_history(STABLE_ref) = TRUE))
                ELSE 
                    STABLE_var_tmp_1 := {}
                END; 
                IF (STABLE_tmp_2_history /= {}) THEN 
                    STABLE_var_tmp_3(STABLE_ref) := STABLE_tmp_2_history(STABLE_ref)
                ELSE 
                    STABLE_var_tmp_3 := {}
                END; 
                IF ((STABLE_var_set /= {}) & (((STABLE_var_set(STABLE_ref) = TRUE) => (STABLE_var_delay /= {})) or (not((STABLE_var_set(STABLE_ref) = TRUE)) => ((not((STABLE_is_initialisation(STABLE_clock___basic__) = TRUE)) => (STABLE_var_tmp_1 /= {})) & ((IF (STABLE_is_initialisation(STABLE_clock___basic__) = TRUE) THEN FALSE ELSE bool((STABLE_var_tmp_1(STABLE_ref) = TRUE)) END = TRUE) => (STABLE_var_tmp_3 /= {})))))) THEN 
                    STABLE_var_count(STABLE_ref) := IF (STABLE_var_set(STABLE_ref) = TRUE) THEN STABLE_var_delay(STABLE_ref) ELSE IF (IF (STABLE_is_initialisation(STABLE_clock___basic__) = TRUE) THEN FALSE ELSE bool((STABLE_var_tmp_1(STABLE_ref) = TRUE)) END = TRUE) THEN (STABLE_var_tmp_3(STABLE_ref) - 1) ELSE 0 END END
                ELSE 
                    STABLE_var_count := {}
                END; 
                IF (STABLE_var_count /= {}) THEN 
                    STABLE_var_level(STABLE_ref) := bool((STABLE_var_count(STABLE_ref) > 0))
                ELSE 
                    STABLE_var_level := {}
                END; 
                IF (STABLE_var_level /= {}) THEN 
                    STABLE_var_tmp_0(STABLE_ref) := bool((STABLE_var_level(STABLE_ref) = TRUE))
                ELSE 
                    STABLE_var_tmp_0 := {}
                END; 
                IF (STABLE_var_count /= {}) THEN 
                    STABLE_var_tmp_2(STABLE_ref) := STABLE_var_count(STABLE_ref)
                ELSE 
                    STABLE_var_tmp_2 := {}
                END; 
                STABLE_is_initialisation(STABLE_clock___basic__) := FALSE

            END

        END



END