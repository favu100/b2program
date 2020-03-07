MACHINE edge

SEES LibraryLustre

VARIABLES edge_is_initialisation, edge_var_EDGE, edge_var_X

SETS edge_clocks = {edge_clock___basic__}

INVARIANT ((edge_is_initialisation : edge_clocks --> BOOL) & ((edge_var_X : REF +-> BOOL) & (edge_var_EDGE : REF +-> BOOL)))

INITIALISATION 
    edge_is_initialisation := (edge_clocks * {TRUE}); 
    edge_var_EDGE := {}; 
    edge_var_X := {}


OPERATIONS 

    edge_clock_step(edge_param_X) = 
        PRE
            (edge_param_X : REF +-> BOOL)
        THEN
            edge_var_X := edge_param_X; 
            edge_var_EDGE := l_fby_boolean(edge_is_initialisation(edge_clock___basic__) |-> edge_var_X |-> l_and(edge_var_X |-> l_not(edge_var_X))); 
            edge_is_initialisation(edge_clock___basic__) := FALSE

        END



END