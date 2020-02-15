MACHINE fby_node_call2

VARIABLES fby_node_call2_is_initialisation, fby_node_call2_var_x, fby_node_call2_var_z

SETS fby_node_call2_clocks = {fby_node_call2_clock___basic__}; fby_node_call2_refs = {fby_node_call2_ref}

INVARIANT ((fby_node_call2_is_initialisation : fby_node_call2_clocks --> BOOL) & ((fby_node_call2_var_x : fby_node_call2_refs +-> INTEGER) & (fby_node_call2_var_z : fby_node_call2_refs +-> INTEGER)))

INITIALISATION 
    fby_node_call2_is_initialisation := (fby_node_call2_clocks * {TRUE}); 
    fby_node_call2_var_x := {}; 
    fby_node_call2_var_z := {}


OPERATIONS 

    fby_node_call2_clock_step(fby_node_call2_param_x) = 
        PRE
            (fby_node_call2_param_x : INTEGER)
        THEN
            VAR fby_node_call2_x_history, fby_node_call2_z_history IN
                fby_node_call2_x_history := fby_node_call2_var_x; 
                fby_node_call2_z_history := fby_node_call2_var_z; 
                fby_node_call2_var_x(fby_node_call2_ref) := fby_node_call2_param_x; 
                fby_node_call2_var_z(fby_node_call2_ref) := 0; 
                fby_node_call2_is_initialisation(fby_node_call2_clock___basic__) := FALSE

            END

        END



END