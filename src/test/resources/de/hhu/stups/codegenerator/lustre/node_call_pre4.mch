MACHINE node_call_pre4

INCLUDES Node_5.node_call_pre5

SEES LibraryLustre

VARIABLES node_call_pre4_is_initialisation, node_call_pre4_var_x, node_call_pre4_var_tmp_0, node_call_pre4_var_z

SETS node_call_pre4_clocks = {node_call_pre4_clock___basic__}

INVARIANT ((node_call_pre4_is_initialisation : node_call_pre4_clocks --> BOOL) & ((node_call_pre4_var_x : REF +-> INTEGER) & ((node_call_pre4_var_tmp_0 : REF +-> INTEGER) & (node_call_pre4_var_z : REF +-> INTEGER))))

INITIALISATION 
    node_call_pre4_is_initialisation := (node_call_pre4_clocks * {TRUE}); 
    node_call_pre4_var_x := {}; 
    node_call_pre4_var_tmp_0 := {}; 
    node_call_pre4_var_z := {}


OPERATIONS 

    node_call_pre4_clock_step(node_call_pre4_param_x) = 
        PRE
            (node_call_pre4_param_x : REF +-> INTEGER)
        THEN
            VAR node_call_pre4_tmp_0_history IN
                node_call_pre4_tmp_0_history := node_call_pre4_var_tmp_0; 
                node_call_pre4_var_x := node_call_pre4_param_x; 
                Node_5.node_call_pre5_clock_step(node_call_pre4_var_x); 
                node_call_pre4_var_tmp_0 := l_fby_integer(node_call_pre4_is_initialisation(node_call_pre4_clock___basic__) |-> {ref |-> 4} |-> Node_5.node_call_pre5_var_z); 
                node_call_pre4_var_z := node_call_pre4_tmp_0_history; 
                node_call_pre4_is_initialisation(node_call_pre4_clock___basic__) := FALSE

            END

        END



END