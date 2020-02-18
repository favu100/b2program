MACHINE always_since

INCLUDES Node_19.after

SEES LibraryLustre

VARIABLES always_since_is_initialisation, always_since_var_B, always_since_var_A, always_since_var_tmp_0, always_since_var_alwaysBsinceA, always_since_var_tmp_1

SETS always_since_clocks = {always_since_clock___basic__}

INVARIANT ((always_since_is_initialisation : always_since_clocks --> BOOL) & ((always_since_var_B : REF +-> BOOL) & ((always_since_var_A : REF +-> BOOL) & ((always_since_var_tmp_0 : REF +-> BOOL) & ((always_since_var_alwaysBsinceA : REF +-> BOOL) & (always_since_var_tmp_1 : REF +-> BOOL))))))

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
            ((always_since_param_B : REF +-> BOOL) & (always_since_param_A : REF +-> BOOL))
        THEN
            VAR always_since_tmp_0_history IN
                always_since_tmp_0_history := always_since_var_tmp_0; 
                always_since_var_B := always_since_param_B; 
                always_since_var_A := always_since_param_A; 
                always_since_var_tmp_1 := always_since_tmp_0_history; 
                Node_19.after_clock_step(always_since_var_A); 
                always_since_var_alwaysBsinceA := l_ite_boolean(always_since_var_A |-> always_since_var_B |-> l_ite_boolean(Node_19.after_var_afterA |-> l_and(always_since_var_B |-> always_since_var_tmp_1) |-> {ref |-> TRUE})); 
                always_since_var_tmp_0 := always_since_var_alwaysBsinceA; 
                always_since_is_initialisation(always_since_clock___basic__) := FALSE

            END

        END



END