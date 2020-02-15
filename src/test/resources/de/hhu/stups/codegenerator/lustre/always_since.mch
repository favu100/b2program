MACHINE always_since

INCLUDES Node_19.after

VARIABLES always_since_is_initialisation, always_since_var_B, always_since_var_A, always_since_var_tmp_0, always_since_var_alwaysBsinceA, always_since_var_tmp_1

SETS always_since_clocks = {always_since_clock___basic__}; always_since_refs = {always_since_ref}

INVARIANT ((always_since_is_initialisation : always_since_clocks --> BOOL) & ((always_since_var_B : always_since_refs +-> BOOL) & ((always_since_var_A : always_since_refs +-> BOOL) & ((always_since_var_tmp_0 : always_since_refs +-> BOOL) & ((always_since_var_alwaysBsinceA : always_since_refs +-> BOOL) & (always_since_var_tmp_1 : always_since_refs +-> BOOL))))))

INITIALISATION 
    always_since_is_initialisation := (always_since_clocks * {TRUE}); 
    always_since_var_B := {}; 
    always_since_var_A := {}; 
    always_since_var_tmp_0 := {}; 
    always_since_var_alwaysBsinceA := {}; 
    always_since_var_tmp_1 := {}


OPERATIONS 

    always_since_clock_step(always_since_param_B, always_since_param_A) = 
        PRE
            ((always_since_param_B : BOOL) & (always_since_param_A : BOOL))
        THEN
            VAR always_since_B_history, always_since_A_history, always_since_tmp_0_history, always_since_alwaysBsinceA_history, always_since_tmp_1_history IN
                always_since_B_history := always_since_var_B; 
                always_since_A_history := always_since_var_A; 
                always_since_tmp_0_history := always_since_var_tmp_0; 
                always_since_alwaysBsinceA_history := always_since_var_alwaysBsinceA; 
                always_since_tmp_1_history := always_since_var_tmp_1; 
                always_since_var_B(always_since_ref) := bool((always_since_param_B = TRUE)); 
                always_since_var_A(always_since_ref) := bool((always_since_param_A = TRUE)); 
                IF (always_since_tmp_0_history /= {}) THEN 
                    always_since_var_tmp_1(always_since_ref) := bool((always_since_tmp_0_history(always_since_ref) = TRUE))
                ELSE 
                    always_since_var_tmp_1 := {}
                END; 
                IF (always_since_var_A /= {}) THEN 
                    Node_19.after_clock_step(always_since_var_A(always_since_ref))
                END; 
                IF ((always_since_var_A /= {}) & (((always_since_var_A(always_since_ref) = TRUE) => (always_since_var_B /= {})) or (not((always_since_var_A(always_since_ref) = TRUE)) => ((Node_19.after_var_afterA /= {}) & ((Node_19.after_var_afterA(after_ref) = TRUE) => ((always_since_var_B /= {}) & (always_since_var_tmp_1 /= {}))))))) THEN 
                    always_since_var_alwaysBsinceA(always_since_ref) := bool((IF (always_since_var_A(always_since_ref) = TRUE) THEN bool((always_since_var_B(always_since_ref) = TRUE)) ELSE bool((IF (Node_19.after_var_afterA(after_ref) = TRUE) THEN bool(((always_since_var_B(always_since_ref) = TRUE) & (always_since_var_tmp_1(always_since_ref) = TRUE))) ELSE TRUE END = TRUE)) END = TRUE))
                ELSE 
                    always_since_var_alwaysBsinceA := {}
                END; 
                IF (always_since_var_alwaysBsinceA /= {}) THEN 
                    always_since_var_tmp_0(always_since_ref) := bool((always_since_var_alwaysBsinceA(always_since_ref) = TRUE))
                ELSE 
                    always_since_var_tmp_0 := {}
                END; 
                always_since_is_initialisation(always_since_clock___basic__) := FALSE

            END

        END



END