MACHINE TIME_STABLE

INCLUDES Node_1.STABLE

VARIABLES TIME_STABLE_is_initialisation, TIME_STABLE_var_second, TIME_STABLE_var_delay, TIME_STABLE_var_ck, TIME_STABLE_var_level, TIME_STABLE_var_tmp_2, TIME_STABLE_var_tmp_0, TIME_STABLE_var_set, TIME_STABLE_var_tmp_1, TIME_STABLE_var_tmp_4, TIME_STABLE_var_tmp_3

SETS TIME_STABLE_clocks = {TIME_STABLE_clock___basic__, TIME_STABLE_clock_ck}; TIME_STABLE_refs = {TIME_STABLE_ref}

INVARIANT ((TIME_STABLE_is_initialisation : TIME_STABLE_clocks --> BOOL) & ((TIME_STABLE_var_second : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_delay : TIME_STABLE_refs +-> INTEGER) & ((TIME_STABLE_var_ck : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_level : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_tmp_2 : TIME_STABLE_refs +-> INTEGER) & ((TIME_STABLE_var_tmp_0 : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_set : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_tmp_1 : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_tmp_4 : TIME_STABLE_refs +-> BOOL) & ((TIME_STABLE_var_tmp_3 : TIME_STABLE_refs +-> INTEGER) & (((TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) = FALSE) => (TIME_STABLE_var_level /= {})) & ((TIME_STABLE_is_initialisation(TIME_STABLE_clock_ck) = FALSE) => (TIME_STABLE_var_ck /= {}))))))))))))))

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
            ((TIME_STABLE_param_set : BOOL) & ((TIME_STABLE_param_second : BOOL) & (TIME_STABLE_param_delay : INTEGER)))
        THEN
            TIME_STABLE_var_set(TIME_STABLE_ref) := bool((TIME_STABLE_param_set = TRUE)); 
            TIME_STABLE_var_second(TIME_STABLE_ref) := bool((TIME_STABLE_param_second = TRUE)); 
            TIME_STABLE_var_delay(TIME_STABLE_ref) := TIME_STABLE_param_delay; 
            IF (TIME_STABLE_var_set /= {}) THEN 
                TIME_STABLE_var_tmp_0(TIME_STABLE_ref) := bool((TIME_STABLE_var_set(TIME_STABLE_ref) = TRUE))
            ELSE 
                TIME_STABLE_var_tmp_0 := {}
            END; 
            IF (TIME_STABLE_var_delay /= {}) THEN 
                TIME_STABLE_var_tmp_2(TIME_STABLE_ref) := TIME_STABLE_var_delay(TIME_STABLE_ref)
            ELSE 
                TIME_STABLE_var_tmp_2 := {}
            END; 
            IF (not((TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) = TRUE)) => ((TIME_STABLE_var_set /= {}) & (TIME_STABLE_var_second /= {}))) THEN 
                TIME_STABLE_var_ck(TIME_STABLE_ref) := bool((IF (TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) = TRUE) THEN TRUE ELSE bool(((TIME_STABLE_var_set(TIME_STABLE_ref) = TRUE) or (TIME_STABLE_var_second(TIME_STABLE_ref) = TRUE))) END = TRUE))
            ELSE 
                TIME_STABLE_var_ck := {}
            END; 
            IF (TIME_STABLE_var_ck(TIME_STABLE_ref) = TRUE) THEN 
                IF (TIME_STABLE_var_tmp_0 /= {}) THEN 
                    TIME_STABLE_var_tmp_1(TIME_STABLE_ref) := bool((TIME_STABLE_var_tmp_0(TIME_STABLE_ref) = TRUE))
                ELSE 
                    TIME_STABLE_var_tmp_1 := {}
                END
            END; 
            IF (TIME_STABLE_var_ck(TIME_STABLE_ref) = TRUE) THEN 
                IF (TIME_STABLE_var_tmp_2 /= {}) THEN 
                    TIME_STABLE_var_tmp_3(TIME_STABLE_ref) := TIME_STABLE_var_tmp_2(TIME_STABLE_ref)
                ELSE 
                    TIME_STABLE_var_tmp_3 := {}
                END
            END; 
            IF ((TIME_STABLE_var_tmp_1 /= {}) & (TIME_STABLE_var_tmp_3 /= {})) THEN 
                Node_1.STABLE_clock_step(TIME_STABLE_var_tmp_1(TIME_STABLE_ref), TIME_STABLE_var_tmp_3(TIME_STABLE_ref))
            END; 
            IF (TIME_STABLE_var_ck(TIME_STABLE_ref) = TRUE) THEN 
                IF (Node_1.STABLE_var_level /= {}) THEN 
                    TIME_STABLE_var_tmp_4(TIME_STABLE_ref) := bool((Node_1.STABLE_var_level(STABLE_ref) = TRUE))
                ELSE 
                    TIME_STABLE_var_tmp_4 := {}
                END
            END; 
            IF (TIME_STABLE_var_tmp_4 /= {}) THEN 
                TIME_STABLE_var_level(TIME_STABLE_ref) := bool((TIME_STABLE_var_tmp_4(TIME_STABLE_ref) = TRUE))
            ELSE 
                TIME_STABLE_var_level := {}
            END; 
            TIME_STABLE_is_initialisation(TIME_STABLE_clock___basic__) := FALSE; 
            IF (TIME_STABLE_var_ck(TIME_STABLE_ref) = TRUE) THEN 
                TIME_STABLE_is_initialisation(TIME_STABLE_clock_ck) := FALSE
            END

        END;

        out <-- getLevel = BEGIN out := TIME_STABLE_var_level END



END