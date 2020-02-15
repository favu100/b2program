MACHINE node_call_pre3

INCLUDES Node_4.node_call_pre4

VARIABLES node_call_pre3_is_initialisation, node_call_pre3_var_x, node_call_pre3_var_tmp_0, node_call_pre3_var_z

SETS node_call_pre3_clocks = {node_call_pre3_clock___basic__}; node_call_pre3_refs = {node_call_pre3_ref}

INVARIANT ((node_call_pre3_is_initialisation : node_call_pre3_clocks --> BOOL) & ((node_call_pre3_var_x : node_call_pre3_refs +-> INTEGER) & ((node_call_pre3_var_tmp_0 : node_call_pre3_refs +-> INTEGER) & (node_call_pre3_var_z : node_call_pre3_refs +-> INTEGER))))

INITIALISATION 
    node_call_pre3_is_initialisation := (node_call_pre3_clocks * {TRUE}); 
    node_call_pre3_var_x := {}; 
    node_call_pre3_var_tmp_0 := {}; 
    node_call_pre3_var_z := {}


OPERATIONS 

    node_call_pre3_clock_step(node_call_pre3_param_x) = 
        PRE
            (node_call_pre3_param_x : INTEGER)
        THEN
            VAR node_call_pre3_tmp_0_history IN
                node_call_pre3_tmp_0_history := node_call_pre3_var_tmp_0; 
                node_call_pre3_var_x(node_call_pre3_ref) := node_call_pre3_param_x; 
                IF (node_call_pre3_var_x /= {}) THEN 
                    Node_4.node_call_pre4_clock_step(node_call_pre3_var_x(node_call_pre3_ref))
                END; 
                IF (not((node_call_pre3_is_initialisation(node_call_pre3_clock___basic__) = TRUE)) => (Node_4.node_call_pre4_var_z /= {})) THEN 
                    node_call_pre3_var_tmp_0(node_call_pre3_ref) := IF (node_call_pre3_is_initialisation(node_call_pre3_clock___basic__) = TRUE) THEN 3 ELSE Node_4.node_call_pre4_var_z(node_call_pre4_ref) END
                ELSE 
                    node_call_pre3_var_tmp_0 := {}
                END; 
                IF (node_call_pre3_tmp_0_history /= {}) THEN 
                    node_call_pre3_var_z(node_call_pre3_ref) := node_call_pre3_tmp_0_history(node_call_pre3_ref)
                ELSE 
                    node_call_pre3_var_z := {}
                END; 
                node_call_pre3_is_initialisation(node_call_pre3_clock___basic__) := FALSE

            END

        END



END