MACHINE node_call_pre2

INCLUDES Node_3.node_call_pre3

VARIABLES node_call_pre2_is_initialisation, node_call_pre2_var_x, node_call_pre2_var_tmp_0, node_call_pre2_var_z

SETS node_call_pre2_clocks = {node_call_pre2_clock___basic__}; node_call_pre2_refs = {node_call_pre2_ref}

INVARIANT ((node_call_pre2_is_initialisation : node_call_pre2_clocks --> BOOL) & ((node_call_pre2_var_x : node_call_pre2_refs +-> INTEGER) & ((node_call_pre2_var_tmp_0 : node_call_pre2_refs +-> INTEGER) & (node_call_pre2_var_z : node_call_pre2_refs +-> INTEGER))))

INITIALISATION 
    node_call_pre2_is_initialisation := (node_call_pre2_clocks * {TRUE}); 
    node_call_pre2_var_x := {}; 
    node_call_pre2_var_tmp_0 := {}; 
    node_call_pre2_var_z := {}


OPERATIONS 

    node_call_pre2_clock_step(node_call_pre2_param_x) = 
        PRE
            (node_call_pre2_param_x : INTEGER)
        THEN
            VAR node_call_pre2_x_history, node_call_pre2_tmp_0_history, node_call_pre2_z_history IN
                node_call_pre2_x_history := node_call_pre2_var_x; 
                node_call_pre2_tmp_0_history := node_call_pre2_var_tmp_0; 
                node_call_pre2_z_history := node_call_pre2_var_z; 
                node_call_pre2_var_x(node_call_pre2_ref) := node_call_pre2_param_x; 
                IF (node_call_pre2_var_x /= {}) THEN 
                    Node_3.node_call_pre3_clock_step(node_call_pre2_var_x(node_call_pre2_ref))
                END; 
                IF (not((node_call_pre2_is_initialisation(node_call_pre2_clock___basic__) = TRUE)) => (Node_3.node_call_pre3_var_z /= {})) THEN 
                    node_call_pre2_var_tmp_0(node_call_pre2_ref) := IF (node_call_pre2_is_initialisation(node_call_pre2_clock___basic__) = TRUE) THEN 2 ELSE Node_3.node_call_pre3_var_z(node_call_pre3_ref) END
                ELSE 
                    node_call_pre2_var_tmp_0 := {}
                END; 
                IF (node_call_pre2_tmp_0_history /= {}) THEN 
                    node_call_pre2_var_z(node_call_pre2_ref) := node_call_pre2_tmp_0_history(node_call_pre2_ref)
                ELSE 
                    node_call_pre2_var_z := {}
                END; 
                node_call_pre2_is_initialisation(node_call_pre2_clock___basic__) := FALSE

            END

        END



END