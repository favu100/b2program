MACHINE node_call_pre5

VARIABLES node_call_pre5_is_initialisation, node_call_pre5_var_x, node_call_pre5_var_tmp_0, node_call_pre5_var_z

SETS node_call_pre5_clocks = {node_call_pre5_clock___basic__}; node_call_pre5_refs = {node_call_pre5_ref}

INVARIANT ((node_call_pre5_is_initialisation : node_call_pre5_clocks --> BOOL) & ((node_call_pre5_var_x : node_call_pre5_refs +-> INTEGER) & ((node_call_pre5_var_tmp_0 : node_call_pre5_refs +-> INTEGER) & (node_call_pre5_var_z : node_call_pre5_refs +-> INTEGER))))

INITIALISATION 
    node_call_pre5_is_initialisation := (node_call_pre5_clocks * {TRUE}); 
    node_call_pre5_var_x := {}; 
    node_call_pre5_var_tmp_0 := {}; 
    node_call_pre5_var_z := {}


OPERATIONS 

    node_call_pre5_clock_step(node_call_pre5_param_x) = 
        PRE
            (node_call_pre5_param_x : INTEGER)
        THEN
            VAR node_call_pre5_x_history, node_call_pre5_tmp_0_history, node_call_pre5_z_history IN
                node_call_pre5_x_history := node_call_pre5_var_x; 
                node_call_pre5_tmp_0_history := node_call_pre5_var_tmp_0; 
                node_call_pre5_z_history := node_call_pre5_var_z; 
                node_call_pre5_var_x(node_call_pre5_ref) := node_call_pre5_param_x; 
                IF (node_call_pre5_var_x /= {}) THEN 
                    node_call_pre5_var_tmp_0(node_call_pre5_ref) := node_call_pre5_var_x(node_call_pre5_ref)
                ELSE 
                    node_call_pre5_var_tmp_0 := {}
                END; 
                IF (node_call_pre5_tmp_0_history /= {}) THEN 
                    node_call_pre5_var_z(node_call_pre5_ref) := node_call_pre5_tmp_0_history(node_call_pre5_ref)
                ELSE 
                    node_call_pre5_var_z := {}
                END; 
                node_call_pre5_is_initialisation(node_call_pre5_clock___basic__) := FALSE

            END

        END



END