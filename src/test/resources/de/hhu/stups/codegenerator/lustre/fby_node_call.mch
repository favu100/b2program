MACHINE fby_node_call

VARIABLES fby_node_call_is_initialisation, fby_node_call_var_x, fby_node_call_var_z

SETS fby_node_call_clocks = {fby_node_call_clock___basic__}; fby_node_call_refs = {fby_node_call_ref}

INVARIANT ((fby_node_call_is_initialisation : fby_node_call_clocks --> BOOL) & ((fby_node_call_var_x : fby_node_call_refs +-> INTEGER) & (fby_node_call_var_z : fby_node_call_refs +-> INTEGER)))

INITIALISATION 
    fby_node_call_is_initialisation := (fby_node_call_clocks * {TRUE}); 
    fby_node_call_var_x := {}; 
    fby_node_call_var_z := {}


OPERATIONS 

    fby_node_call_clock_step(fby_node_call_param_x) = 
        PRE
            (fby_node_call_param_x : INTEGER)
        THEN
            fby_node_call_var_x(fby_node_call_ref) := fby_node_call_param_x; 
            IF (fby_node_call_var_x /= {}) THEN 
                fby_node_call_var_z(fby_node_call_ref) := fby_node_call_var_x(fby_node_call_ref)
            ELSE 
                fby_node_call_var_z := {}
            END; 
            fby_node_call_is_initialisation(fby_node_call_clock___basic__) := FALSE

        END



END