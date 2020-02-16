MACHINE Pre4

INCLUDES Node_1.node_call_pre

SEES LibraryLustre

VARIABLES Pre4_is_initialisation, Pre4_var_x, Pre4_var_z

SETS Pre4_clocks = {Pre4_clock___basic__}

INVARIANT ((Pre4_is_initialisation : Pre4_clocks --> BOOL) & ((Pre4_var_x : REF +-> INTEGER) & ((Pre4_var_z : REF +-> INTEGER) & ((Pre4_is_initialisation(Pre4_clock___basic__) = FALSE) => (Pre4_var_z /= {})))))

INITIALISATION 
    Pre4_is_initialisation := (Pre4_clocks * {TRUE}); 
    Pre4_var_x := {}; 
    Pre4_var_z := {}


OPERATIONS 

    Pre4_clock_step(Pre4_param_x) = 
        PRE
            (Pre4_param_x : REF --> INTEGER)
        THEN
            Pre4_var_x := Pre4_param_x; 
            Node_1.node_call_pre_clock_step(Pre4_var_x); 
            Pre4_var_z := l_fby_integer(Pre4_is_initialisation(Pre4_clock___basic__) |-> {ref |-> 0} |-> Node_1.node_call_pre_var_z); 
            Pre4_is_initialisation(Pre4_clock___basic__) := FALSE

        END;

        out <-- getZ = BEGIN out := Pre4_var_z END



END