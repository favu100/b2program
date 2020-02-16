MACHINE node_call_pre

INCLUDES Node_2.node_call_pre2

SEES LibraryLustre

VARIABLES node_call_pre_is_initialisation, node_call_pre_var_x, node_call_pre_var_tmp_0, node_call_pre_var_z

SETS node_call_pre_clocks = {node_call_pre_clock___basic__}

INVARIANT ((node_call_pre_is_initialisation : node_call_pre_clocks --> BOOL) & ((node_call_pre_var_x : REF +-> INTEGER) & ((node_call_pre_var_tmp_0 : REF +-> INTEGER) & (node_call_pre_var_z : REF +-> INTEGER))))

INITIALISATION 
    node_call_pre_is_initialisation := (node_call_pre_clocks * {TRUE}); 
    node_call_pre_var_x := {}; 
    node_call_pre_var_tmp_0 := {}; 
    node_call_pre_var_z := {}


OPERATIONS 

    node_call_pre_clock_step(node_call_pre_param_x) = 
        PRE
            (node_call_pre_param_x : REF +-> INTEGER)
        THEN
            VAR node_call_pre_tmp_0_history IN
                node_call_pre_tmp_0_history := node_call_pre_var_tmp_0; 
                node_call_pre_var_x := node_call_pre_param_x; 
                Node_2.node_call_pre2_clock_step(node_call_pre_var_x); 
                node_call_pre_var_tmp_0 := l_fby_integer(node_call_pre_is_initialisation(node_call_pre_clock___basic__) |-> {ref |-> 1} |-> Node_2.node_call_pre2_var_z); 
                node_call_pre_var_z := node_call_pre_tmp_0_history; 
                node_call_pre_is_initialisation(node_call_pre_clock___basic__) := FALSE

            END

        END



END