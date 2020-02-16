MACHINE edge

SEES LibraryLustre

VARIABLES edge_is_initialisation, edge_var_X, edge_var_EDGE, edge_var_tmp_0, edge_var_tmp_1

SETS edge_clocks = {edge_clock___basic__}

INVARIANT ((edge_is_initialisation : edge_clocks --> BOOL) & ((edge_var_X : REF +-> BOOL) & ((edge_var_EDGE : REF +-> BOOL) & ((edge_var_tmp_0 : REF +-> BOOL) & (edge_var_tmp_1 : REF +-> BOOL)))))

INITIALISATION 
    edge_is_initialisation := (edge_clocks * {TRUE}); 
    edge_var_X := {}; 
    edge_var_EDGE := {}; 
    edge_var_tmp_0 := {}; 
    edge_var_tmp_1 := {}


OPERATIONS 

    edge_clock_step(edge_param_X) = 
        PRE
            (edge_param_X : REF +-> BOOL)
        THEN
            VAR edge_tmp_0_history IN
                edge_tmp_0_history := edge_var_tmp_0; 
                edge_var_X := edge_param_X; 
                edge_var_tmp_0 := edge_var_X; 
                edge_var_tmp_1 := edge_tmp_0_history; 
                edge_var_EDGE := l_fby_boolean(edge_is_initialisation(edge_clock___basic__) |-> edge_var_X |-> l_and(edge_var_X |-> l_not(edge_var_tmp_1))); 
                edge_is_initialisation(edge_clock___basic__) := FALSE

            END

        END



END