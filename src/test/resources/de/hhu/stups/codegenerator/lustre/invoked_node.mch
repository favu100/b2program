MACHINE invoked_node

SEES LibraryLustre

VARIABLES invoked_node_is_initialisation, invoked_node_var_tmp_0, invoked_node_var_res, invoked_node_var_x, invoked_node_var_tmp_1

SETS invoked_node_clocks = {invoked_node_clock___basic__}

INVARIANT ((invoked_node_is_initialisation : invoked_node_clocks --> BOOL) & ((invoked_node_var_tmp_0 : REF +-> INTEGER) & ((invoked_node_var_res : REF +-> INTEGER) & ((invoked_node_var_x : REF +-> BOOL) & (invoked_node_var_tmp_1 : REF +-> INTEGER)))))

INITIALISATION 
    invoked_node_is_initialisation := (invoked_node_clocks * {TRUE}); 
    invoked_node_var_tmp_0 := {}; 
    invoked_node_var_res := {}; 
    invoked_node_var_x := {}; 
    invoked_node_var_tmp_1 := {}


OPERATIONS 

    invoked_node_clock_step(invoked_node_param_x) = 
        PRE
            (invoked_node_param_x : REF +-> BOOL)
        THEN
            VAR invoked_node_tmp_0_history IN
                invoked_node_tmp_0_history := invoked_node_var_tmp_0; 
                invoked_node_var_x := invoked_node_param_x; 
                invoked_node_var_tmp_1 := invoked_node_tmp_0_history; 
                invoked_node_var_res := l_plus(l_fby_integer(invoked_node_is_initialisation(invoked_node_clock___basic__) |-> {ref |-> 0} |-> invoked_node_var_tmp_1) |-> {ref |-> 1}); 
                invoked_node_var_tmp_0 := invoked_node_var_res; 
                invoked_node_is_initialisation(invoked_node_clock___basic__) := FALSE

            END

        END



END