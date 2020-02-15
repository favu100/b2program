MACHINE always_from_to

INCLUDES Node_18.implies, Node_15.after, Node_16.always_since, Node_17.once_since

VARIABLES always_from_to_is_initialisation, always_from_to_var_B, always_from_to_var_A, always_from_to_var_C, always_from_to_var_X

SETS always_from_to_clocks = {always_from_to_clock___basic__}; always_from_to_refs = {always_from_to_ref}

INVARIANT ((always_from_to_is_initialisation : always_from_to_clocks --> BOOL) & ((always_from_to_var_B : always_from_to_refs +-> BOOL) & ((always_from_to_var_A : always_from_to_refs +-> BOOL) & ((always_from_to_var_C : always_from_to_refs +-> BOOL) & (always_from_to_var_X : always_from_to_refs +-> BOOL)))))

INITIALISATION 
    always_from_to_is_initialisation := (always_from_to_clocks * {TRUE}); 
    always_from_to_var_B := {}; 
    always_from_to_var_A := {}; 
    always_from_to_var_C := {}; 
    always_from_to_var_X := {}


OPERATIONS 

    always_from_to_clock_step(always_from_to_param_B, always_from_to_param_A, always_from_to_param_C) = 
        PRE
            ((always_from_to_param_B : BOOL) & ((always_from_to_param_A : BOOL) & (always_from_to_param_C : BOOL)))
        THEN
            VAR always_from_to_B_history, always_from_to_A_history, always_from_to_C_history, always_from_to_X_history IN
                always_from_to_B_history := always_from_to_var_B; 
                always_from_to_A_history := always_from_to_var_A; 
                always_from_to_C_history := always_from_to_var_C; 
                always_from_to_X_history := always_from_to_var_X; 
                always_from_to_var_B(always_from_to_ref) := bool((always_from_to_param_B = TRUE)); 
                always_from_to_var_A(always_from_to_ref) := bool((always_from_to_param_A = TRUE)); 
                always_from_to_var_C(always_from_to_ref) := bool((always_from_to_param_C = TRUE)); 
                IF (always_from_to_var_A /= {}) THEN 
                    Node_15.after_clock_step(always_from_to_var_A(always_from_to_ref))
                END; 
                IF ((always_from_to_var_B /= {}) & (always_from_to_var_A /= {})) THEN 
                    Node_16.always_since_clock_step(always_from_to_var_B(always_from_to_ref), always_from_to_var_A(always_from_to_ref))
                END; 
                IF ((always_from_to_var_C /= {}) & (always_from_to_var_A /= {})) THEN 
                    Node_17.once_since_clock_step(always_from_to_var_C(always_from_to_ref), always_from_to_var_A(always_from_to_ref))
                END; 
                IF ((Node_15.after_var_afterA /= {}) & ((Node_16.always_since_var_alwaysBsinceA /= {}) & (Node_17.once_since_var_onceCsinceA /= {}))) THEN 
                    Node_18.implies_clock_step(bool((Node_15.after_var_afterA(after_ref) = TRUE)), bool(((Node_16.always_since_var_alwaysBsinceA(always_since_ref) = TRUE) or (Node_17.once_since_var_onceCsinceA(once_since_ref) = TRUE))))
                END; 
                IF (Node_18.implies_var_AimpliesB /= {}) THEN 
                    always_from_to_var_X(always_from_to_ref) := bool((Node_18.implies_var_AimpliesB(implies_ref) = TRUE))
                ELSE 
                    always_from_to_var_X := {}
                END; 
                always_from_to_is_initialisation(always_from_to_clock___basic__) := FALSE

            END

        END



END