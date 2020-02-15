MACHINE SLOW_TIME_STABLE

INCLUDES Node_1.SLOW_STABLE

VARIABLES SLOW_TIME_STABLE_is_initialisation, SLOW_TIME_STABLE_var_second, SLOW_TIME_STABLE_var_delay, SLOW_TIME_STABLE_var_level, SLOW_TIME_STABLE_var_tmp_0, SLOW_TIME_STABLE_var_set, SLOW_TIME_STABLE_var_tmp_2, SLOW_TIME_STABLE_var_tmp_1, SLOW_TIME_STABLE_var_tmp_3

SETS SLOW_TIME_STABLE_clocks = {SLOW_TIME_STABLE_clock___basic__, SLOW_TIME_STABLE_clock_second}; SLOW_TIME_STABLE_refs = {SLOW_TIME_STABLE_ref}

INVARIANT ((SLOW_TIME_STABLE_is_initialisation : SLOW_TIME_STABLE_clocks --> BOOL) & ((SLOW_TIME_STABLE_var_second : SLOW_TIME_STABLE_refs +-> BOOL) & ((SLOW_TIME_STABLE_var_delay : SLOW_TIME_STABLE_refs +-> INTEGER) & ((SLOW_TIME_STABLE_var_level : SLOW_TIME_STABLE_refs +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_0 : SLOW_TIME_STABLE_refs +-> BOOL) & ((SLOW_TIME_STABLE_var_set : SLOW_TIME_STABLE_refs +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_2 : SLOW_TIME_STABLE_refs +-> INTEGER) & ((SLOW_TIME_STABLE_var_tmp_1 : SLOW_TIME_STABLE_refs +-> BOOL) & ((SLOW_TIME_STABLE_var_tmp_3 : SLOW_TIME_STABLE_refs +-> INTEGER) & (((SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) = FALSE) => (SLOW_TIME_STABLE_var_level /= {})) & ((SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) = FALSE) => (SLOW_TIME_STABLE_var_second /= {}))))))))))))

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
            ((SLOW_TIME_STABLE_param_set : BOOL) & ((SLOW_TIME_STABLE_param_second : BOOL) & (SLOW_TIME_STABLE_param_delay : INTEGER)))
        THEN
            SLOW_TIME_STABLE_var_set(SLOW_TIME_STABLE_ref) := bool((SLOW_TIME_STABLE_param_set = TRUE)); 
            SLOW_TIME_STABLE_var_second(SLOW_TIME_STABLE_ref) := bool((SLOW_TIME_STABLE_param_second = TRUE)); 
            SLOW_TIME_STABLE_var_delay(SLOW_TIME_STABLE_ref) := SLOW_TIME_STABLE_param_delay; 
            IF (SLOW_TIME_STABLE_var_set /= {}) THEN 
                SLOW_TIME_STABLE_var_tmp_0(SLOW_TIME_STABLE_ref) := bool((SLOW_TIME_STABLE_var_set(SLOW_TIME_STABLE_ref) = TRUE))
            ELSE 
                SLOW_TIME_STABLE_var_tmp_0 := {}
            END; 
            IF (SLOW_TIME_STABLE_var_second(SLOW_TIME_STABLE_ref) = TRUE) THEN 
                IF (SLOW_TIME_STABLE_var_tmp_0 /= {}) THEN 
                    SLOW_TIME_STABLE_var_tmp_1(SLOW_TIME_STABLE_ref) := bool((SLOW_TIME_STABLE_var_tmp_0(SLOW_TIME_STABLE_ref) = TRUE))
                ELSE 
                    SLOW_TIME_STABLE_var_tmp_1 := {}
                END
            END; 
            IF (SLOW_TIME_STABLE_var_delay /= {}) THEN 
                SLOW_TIME_STABLE_var_tmp_2(SLOW_TIME_STABLE_ref) := SLOW_TIME_STABLE_var_delay(SLOW_TIME_STABLE_ref)
            ELSE 
                SLOW_TIME_STABLE_var_tmp_2 := {}
            END; 
            IF (SLOW_TIME_STABLE_var_second(SLOW_TIME_STABLE_ref) = TRUE) THEN 
                IF (SLOW_TIME_STABLE_var_tmp_2 /= {}) THEN 
                    SLOW_TIME_STABLE_var_tmp_3(SLOW_TIME_STABLE_ref) := SLOW_TIME_STABLE_var_tmp_2(SLOW_TIME_STABLE_ref)
                ELSE 
                    SLOW_TIME_STABLE_var_tmp_3 := {}
                END
            END; 
            IF ((SLOW_TIME_STABLE_var_tmp_1 /= {}) & (SLOW_TIME_STABLE_var_tmp_3 /= {})) THEN 
                Node_1.SLOW_STABLE_clock_step(SLOW_TIME_STABLE_var_tmp_1(SLOW_TIME_STABLE_ref), SLOW_TIME_STABLE_var_tmp_3(SLOW_TIME_STABLE_ref))
            END; 
            IF (SLOW_TIME_STABLE_var_second(SLOW_TIME_STABLE_ref) = TRUE) THEN 
                IF (Node_1.SLOW_STABLE_var_level /= {}) THEN 
                    SLOW_TIME_STABLE_var_level(SLOW_TIME_STABLE_ref) := bool((Node_1.SLOW_STABLE_var_level(SLOW_STABLE_ref) = TRUE))
                ELSE 
                    SLOW_TIME_STABLE_var_level := {}
                END
            END; 
            SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock___basic__) := FALSE; 
            IF (SLOW_TIME_STABLE_var_second(SLOW_TIME_STABLE_ref) = TRUE) THEN 
                SLOW_TIME_STABLE_is_initialisation(SLOW_TIME_STABLE_clock_second) := FALSE
            END

        END;

        out <-- getLevel = BEGIN out := SLOW_TIME_STABLE_var_level END



END