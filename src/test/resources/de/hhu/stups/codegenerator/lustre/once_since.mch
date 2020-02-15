MACHINE once_since

INCLUDES Node_20.after

VARIABLES once_since_is_initialisation, once_since_var_C, once_since_var_A, once_since_var_tmp_0, once_since_var_onceCsinceA, once_since_var_tmp_1

SETS once_since_clocks = {once_since_clock___basic__}; once_since_refs = {once_since_ref}

INVARIANT ((once_since_is_initialisation : once_since_clocks --> BOOL) & ((once_since_var_C : once_since_refs +-> BOOL) & ((once_since_var_A : once_since_refs +-> BOOL) & ((once_since_var_tmp_0 : once_since_refs +-> BOOL) & ((once_since_var_onceCsinceA : once_since_refs +-> BOOL) & (once_since_var_tmp_1 : once_since_refs +-> BOOL))))))

INITIALISATION 
    once_since_is_initialisation := (once_since_clocks * {TRUE}); 
    once_since_var_C := {}; 
    once_since_var_A := {}; 
    once_since_var_tmp_0 := {}; 
    once_since_var_onceCsinceA := {}; 
    once_since_var_tmp_1 := {}


OPERATIONS 

    once_since_clock_step(once_since_param_C, once_since_param_A) = 
        PRE
            ((once_since_param_C : BOOL) & (once_since_param_A : BOOL))
        THEN
            VAR once_since_C_history, once_since_A_history, once_since_tmp_0_history, once_since_onceCsinceA_history, once_since_tmp_1_history IN
                once_since_C_history := once_since_var_C; 
                once_since_A_history := once_since_var_A; 
                once_since_tmp_0_history := once_since_var_tmp_0; 
                once_since_onceCsinceA_history := once_since_var_onceCsinceA; 
                once_since_tmp_1_history := once_since_var_tmp_1; 
                once_since_var_C(once_since_ref) := bool((once_since_param_C = TRUE)); 
                once_since_var_A(once_since_ref) := bool((once_since_param_A = TRUE)); 
                IF (once_since_tmp_0_history /= {}) THEN 
                    once_since_var_tmp_1(once_since_ref) := bool((once_since_tmp_0_history(once_since_ref) = TRUE))
                ELSE 
                    once_since_var_tmp_1 := {}
                END; 
                IF (once_since_var_A /= {}) THEN 
                    Node_20.after_clock_step(once_since_var_A(once_since_ref))
                END; 
                IF ((once_since_var_A /= {}) & (((once_since_var_A(once_since_ref) = TRUE) => (once_since_var_C /= {})) or (not((once_since_var_A(once_since_ref) = TRUE)) => ((Node_20.after_var_afterA /= {}) & ((Node_20.after_var_afterA(after_ref) = TRUE) => ((once_since_var_C /= {}) & (once_since_var_tmp_1 /= {}))))))) THEN 
                    once_since_var_onceCsinceA(once_since_ref) := bool((IF (once_since_var_A(once_since_ref) = TRUE) THEN bool((once_since_var_C(once_since_ref) = TRUE)) ELSE bool((IF (Node_20.after_var_afterA(after_ref) = TRUE) THEN bool(((once_since_var_C(once_since_ref) = TRUE) or (once_since_var_tmp_1(once_since_ref) = TRUE))) ELSE TRUE END = TRUE)) END = TRUE))
                ELSE 
                    once_since_var_onceCsinceA := {}
                END; 
                IF (once_since_var_onceCsinceA /= {}) THEN 
                    once_since_var_tmp_0(once_since_ref) := bool((once_since_var_onceCsinceA(once_since_ref) = TRUE))
                ELSE 
                    once_since_var_tmp_0 := {}
                END; 
                once_since_is_initialisation(once_since_clock___basic__) := FALSE

            END

        END



END