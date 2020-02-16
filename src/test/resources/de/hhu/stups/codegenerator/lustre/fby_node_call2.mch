MACHINE fby_node_call2

SEES LibraryLustre

VARIABLES fby_node_call2_is_initialisation, fby_node_call2_var_x, fby_node_call2_var_z

SETS fby_node_call2_clocks = {fby_node_call2_clock___basic__}

INVARIANT ((fby_node_call2_is_initialisation : fby_node_call2_clocks --> BOOL) & ((fby_node_call2_var_x : REF +-> INTEGER) & (fby_node_call2_var_z : REF +-> INTEGER)))

INITIALISATION 
    fby_node_call2_is_initialisation := (fby_node_call2_clocks * {TRUE}); 
    fby_node_call2_var_x := {}; 
    fby_node_call2_var_z := {}


OPERATIONS 

    fby_node_call2_clock_step(fby_node_call2_param_x) = 
        PRE
            (fby_node_call2_param_x : REF +-> INTEGER)
        THEN
            fby_node_call2_var_x := fby_node_call2_param_x; 
            fby_node_call2_var_z := {ref |-> 0}; 
            fby_node_call2_is_initialisation(fby_node_call2_clock___basic__) := FALSE

        END



END