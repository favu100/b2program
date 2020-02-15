MACHINE after

VARIABLES after_is_initialisation, after_var_afterA, after_var_A, after_var_tmp_0, after_var_tmp_1

SETS after_clocks = {after_clock___basic__}; after_refs = {after_ref}

INVARIANT ((after_is_initialisation : after_clocks --> BOOL) & ((after_var_afterA : after_refs +-> BOOL) & ((after_var_A : after_refs +-> BOOL) & ((after_var_tmp_0 : after_refs +-> BOOL) & (after_var_tmp_1 : after_refs +-> BOOL)))))

INITIALISATION 
    after_is_initialisation := (after_clocks * {TRUE}); 
    after_var_afterA := {}; 
    after_var_A := {}; 
    after_var_tmp_0 := {}; 
    after_var_tmp_1 := {}


OPERATIONS 

    after_clock_step(after_param_A) = 
        PRE
            (after_param_A : BOOL)
        THEN
            VAR after_tmp_0_history IN
                after_tmp_0_history := after_var_tmp_0; 
                after_var_A(after_ref) := bool((after_param_A = TRUE)); 
                IF (after_tmp_0_history /= {}) THEN 
                    after_var_tmp_1(after_ref) := bool((after_tmp_0_history(after_ref) = TRUE))
                ELSE 
                    after_var_tmp_1 := {}
                END; 
                IF (not((after_is_initialisation(after_clock___basic__) = TRUE)) => (after_var_tmp_1 /= {})) THEN 
                    after_var_afterA(after_ref) := bool((IF (after_is_initialisation(after_clock___basic__) = TRUE) THEN FALSE ELSE bool((after_var_tmp_1(after_ref) = TRUE)) END = TRUE))
                ELSE 
                    after_var_afterA := {}
                END; 
                IF ((after_var_A /= {}) & (after_var_afterA /= {})) THEN 
                    after_var_tmp_0(after_ref) := bool(((after_var_A(after_ref) = TRUE) or (after_var_afterA(after_ref) = TRUE)))
                ELSE 
                    after_var_tmp_0 := {}
                END; 
                after_is_initialisation(after_clock___basic__) := FALSE

            END

        END



END