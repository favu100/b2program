MACHINE implies

VARIABLES implies_is_initialisation, implies_var_AimpliesB, implies_var_A, implies_var_B

SETS implies_clocks = {implies_clock___basic__}; implies_refs = {implies_ref}

INVARIANT ((implies_is_initialisation : implies_clocks --> BOOL) & ((implies_var_AimpliesB : implies_refs +-> BOOL) & ((implies_var_A : implies_refs +-> BOOL) & (implies_var_B : implies_refs +-> BOOL))))

INITIALISATION 
    implies_is_initialisation := (implies_clocks * {TRUE}); 
    implies_var_AimpliesB := {}; 
    implies_var_A := {}; 
    implies_var_B := {}


OPERATIONS 

    implies_clock_step(implies_param_A, implies_param_B) = 
        PRE
            ((implies_param_A : BOOL) & (implies_param_B : BOOL))
        THEN
            VAR implies_AimpliesB_history, implies_A_history, implies_B_history IN
                implies_AimpliesB_history := implies_var_AimpliesB; 
                implies_A_history := implies_var_A; 
                implies_B_history := implies_var_B; 
                implies_var_A(implies_ref) := bool((implies_param_A = TRUE)); 
                implies_var_B(implies_ref) := bool((implies_param_B = TRUE)); 
                IF ((implies_var_A /= {}) & (implies_var_B /= {})) THEN 
                    implies_var_AimpliesB(implies_ref) := bool((not((implies_var_A(implies_ref) = TRUE)) or (implies_var_B(implies_ref) = TRUE)))
                ELSE 
                    implies_var_AimpliesB := {}
                END; 
                implies_is_initialisation(implies_clock___basic__) := FALSE

            END

        END



END