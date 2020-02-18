MACHINE once_since

INCLUDES Node_20.after

SEES LibraryLustre

VARIABLES once_since_is_initialisation, once_since_var_C, once_since_var_A, once_since_var_tmp_0, once_since_var_onceCsinceA, once_since_var_tmp_1

SETS once_since_clocks = {once_since_clock___basic__}

INVARIANT ((once_since_is_initialisation : once_since_clocks --> BOOL) & ((once_since_var_C : REF +-> BOOL) & ((once_since_var_A : REF +-> BOOL) & ((once_since_var_tmp_0 : REF +-> BOOL) & ((once_since_var_onceCsinceA : REF +-> BOOL) & (once_since_var_tmp_1 : REF +-> BOOL))))))

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
            ((once_since_param_C : REF +-> BOOL) & (once_since_param_A : REF +-> BOOL))
        THEN
            VAR once_since_tmp_0_history IN
                once_since_tmp_0_history := once_since_var_tmp_0; 
                once_since_var_C := once_since_param_C; 
                once_since_var_A := once_since_param_A; 
                once_since_var_tmp_1 := once_since_tmp_0_history; 
                Node_20.after_clock_step(once_since_var_A); 
                once_since_var_onceCsinceA := l_ite_boolean(once_since_var_A |-> once_since_var_C |-> l_ite_boolean(Node_20.after_var_afterA |-> l_or(once_since_var_C |-> once_since_var_tmp_1) |-> {ref |-> TRUE})); 
                once_since_var_tmp_0 := once_since_var_onceCsinceA; 
                once_since_is_initialisation(once_since_clock___basic__) := FALSE

            END

        END



END