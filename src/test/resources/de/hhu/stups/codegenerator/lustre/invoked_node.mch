MACHINE invoked_node

VARIABLES invoked_node_is_initialisation, invoked_node_var_tmp_0, invoked_node_var_res, invoked_node_var_x, invoked_node_var_tmp_1

SETS invoked_node_clocks = {invoked_node_clock___basic__}; invoked_node_refs = {invoked_node_ref}

INVARIANT ((invoked_node_is_initialisation : invoked_node_clocks --> BOOL) & ((invoked_node_var_tmp_0 : invoked_node_refs +-> INTEGER) & ((invoked_node_var_res : invoked_node_refs +-> INTEGER) & ((invoked_node_var_x : invoked_node_refs +-> BOOL) & (invoked_node_var_tmp_1 : invoked_node_refs +-> INTEGER)))))

INITIALISATION 
    invoked_node_is_initialisation := (invoked_node_clocks * {TRUE}); 
    invoked_node_var_tmp_0 := {}; 
    invoked_node_var_res := {}; 
    invoked_node_var_x := {}; 
    invoked_node_var_tmp_1 := {}


OPERATIONS 

    invoked_node_clock_step(invoked_node_param_x) = 
        PRE
            (invoked_node_param_x : BOOL)
        THEN
            VAR invoked_node_tmp_0_history IN
                invoked_node_tmp_0_history := invoked_node_var_tmp_0; 
                invoked_node_var_x(invoked_node_ref) := bool((invoked_node_param_x = TRUE)); 
                IF (invoked_node_tmp_0_history /= {}) THEN 
                    invoked_node_var_tmp_1(invoked_node_ref) := invoked_node_tmp_0_history(invoked_node_ref)
                ELSE 
                    invoked_node_var_tmp_1 := {}
                END; 
                IF (not((invoked_node_is_initialisation(invoked_node_clock___basic__) = TRUE)) => (invoked_node_var_tmp_1 /= {})) THEN 
                    invoked_node_var_res(invoked_node_ref) := (IF (invoked_node_is_initialisation(invoked_node_clock___basic__) = TRUE) THEN 0 ELSE invoked_node_var_tmp_1(invoked_node_ref) END + 1)
                ELSE 
                    invoked_node_var_res := {}
                END; 
                IF (invoked_node_var_res /= {}) THEN 
                    invoked_node_var_tmp_0(invoked_node_ref) := invoked_node_var_res(invoked_node_ref)
                ELSE 
                    invoked_node_var_tmp_0 := {}
                END; 
                invoked_node_is_initialisation(invoked_node_clock___basic__) := FALSE

            END

        END



END