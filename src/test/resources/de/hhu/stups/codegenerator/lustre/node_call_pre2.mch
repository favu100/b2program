MACHINE node_call_pre2

INCLUDES Node_3.node_call_pre3

SEES LibraryLustre

VARIABLES node_call_pre2_is_initialisation, node_call_pre2_var_x, node_call_pre2_var_tmp_0, node_call_pre2_var_z

SETS node_call_pre2_clocks = {node_call_pre2_clock___basic__}

INVARIANT ((node_call_pre2_is_initialisation : node_call_pre2_clocks --> BOOL) & ((node_call_pre2_var_x : REF +-> INTEGER) & ((node_call_pre2_var_tmp_0 : REF +-> INTEGER) & (node_call_pre2_var_z : REF +-> INTEGER))))

INITIALISATION 
    node_call_pre2_is_initialisation := (node_call_pre2_clocks * {TRUE}); 
    node_call_pre2_var_x := {}; 
    node_call_pre2_var_tmp_0 := {}; 
    node_call_pre2_var_z := {}


OPERATIONS 

    node_call_pre2_clock_step(node_call_pre2_param_x) = 
        PRE
            (node_call_pre2_param_x : REF +-> INTEGER)
        THEN
            VAR node_call_pre2_tmp_0_history IN
                node_call_pre2_tmp_0_history := node_call_pre2_var_tmp_0; 
                node_call_pre2_var_x := node_call_pre2_param_x; 
                Node_3.node_call_pre3_clock_step(node_call_pre2_var_x); 
                node_call_pre2_var_tmp_0 := l_fby_integer(node_call_pre2_is_initialisation(node_call_pre2_clock___basic__) |-> {ref |-> 2} |-> Node_3.node_call_pre3_var_z); 
                node_call_pre2_var_z := node_call_pre2_tmp_0_history; 
                node_call_pre2_is_initialisation(node_call_pre2_clock___basic__) := FALSE

            END

        END



END