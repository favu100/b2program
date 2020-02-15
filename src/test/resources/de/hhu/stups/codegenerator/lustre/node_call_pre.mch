MACHINE node_call_pre

INCLUDES Node_2.node_call_pre2

VARIABLES node_call_pre_is_initialisation, node_call_pre_var_x, node_call_pre_var_tmp_0, node_call_pre_var_z

SETS node_call_pre_clocks = {node_call_pre_clock___basic__}; node_call_pre_refs = {node_call_pre_ref}

INVARIANT ((node_call_pre_is_initialisation : node_call_pre_clocks --> BOOL) & ((node_call_pre_var_x : node_call_pre_refs +-> INTEGER) & ((node_call_pre_var_tmp_0 : node_call_pre_refs +-> INTEGER) & (node_call_pre_var_z : node_call_pre_refs +-> INTEGER))))

INITIALISATION 
    node_call_pre_is_initialisation := (node_call_pre_clocks * {TRUE}); 
    node_call_pre_var_x := {}; 
    node_call_pre_var_tmp_0 := {}; 
    node_call_pre_var_z := {}


OPERATIONS 

    node_call_pre_clock_step(node_call_pre_param_x) = 
        PRE
            (node_call_pre_param_x : INTEGER)
        THEN
            VAR node_call_pre_tmp_0_history IN
                node_call_pre_tmp_0_history := node_call_pre_var_tmp_0; 
                node_call_pre_var_x(node_call_pre_ref) := node_call_pre_param_x; 
                IF (node_call_pre_var_x /= {}) THEN 
                    Node_2.node_call_pre2_clock_step(node_call_pre_var_x(node_call_pre_ref))
                END; 
                IF (not((node_call_pre_is_initialisation(node_call_pre_clock___basic__) = TRUE)) => (Node_2.node_call_pre2_var_z /= {})) THEN 
                    node_call_pre_var_tmp_0(node_call_pre_ref) := IF (node_call_pre_is_initialisation(node_call_pre_clock___basic__) = TRUE) THEN 1 ELSE Node_2.node_call_pre2_var_z(node_call_pre2_ref) END
                ELSE 
                    node_call_pre_var_tmp_0 := {}
                END; 
                IF (node_call_pre_tmp_0_history /= {}) THEN 
                    node_call_pre_var_z(node_call_pre_ref) := node_call_pre_tmp_0_history(node_call_pre_ref)
                ELSE 
                    node_call_pre_var_z := {}
                END; 
                node_call_pre_is_initialisation(node_call_pre_clock___basic__) := FALSE

            END

        END



END