MACHINE Pre4

INCLUDES Node_1.node_call_pre

VARIABLES Pre4_is_initialisation, Pre4_var_x, Pre4_var_z

SETS Pre4_clocks = {Pre4_clock___basic__}; Pre4_refs = {Pre4_ref}

INVARIANT ((Pre4_is_initialisation : Pre4_clocks --> BOOL) & ((Pre4_var_x : Pre4_refs +-> INTEGER) & ((Pre4_var_z : Pre4_refs +-> INTEGER) & ((Pre4_is_initialisation(Pre4_clock___basic__) = FALSE) => (Pre4_var_z /= {})))))

INITIALISATION 
    Pre4_is_initialisation := (Pre4_clocks * {TRUE}); 
    Pre4_var_x := {}; 
    Pre4_var_z := {}


OPERATIONS 

    Pre4_clock_step(Pre4_param_x) = 
        PRE
            (Pre4_param_x : INTEGER)
        THEN
            Pre4_var_x(Pre4_ref) := Pre4_param_x; 
            IF (Pre4_var_x /= {}) THEN 
                Node_1.node_call_pre_clock_step(Pre4_var_x(Pre4_ref))
            END; 
            IF (not((Pre4_is_initialisation(Pre4_clock___basic__) = TRUE)) => (Node_1.node_call_pre_var_z /= {})) THEN 
                Pre4_var_z(Pre4_ref) := IF (Pre4_is_initialisation(Pre4_clock___basic__) = TRUE) THEN 0 ELSE Node_1.node_call_pre_var_z(node_call_pre_ref) END
            ELSE 
                Pre4_var_z := {}
            END; 
            Pre4_is_initialisation(Pre4_clock___basic__) := FALSE

        END;

        out <-- getZ = BEGIN out := Pre4_var_z END



END