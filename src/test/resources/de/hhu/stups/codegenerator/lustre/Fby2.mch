MACHINE Fby2

INCLUDES Node_1.fby_node_call, Node_2.fby_node_call2

SEES LibraryLustre

VARIABLES Fby2_is_initialisation, Fby2_var_x, Fby2_var_z

SETS Fby2_clocks = {Fby2_clock___basic__}

INVARIANT ((Fby2_is_initialisation : Fby2_clocks --> BOOL) & ((Fby2_var_x : REF +-> INTEGER) & ((Fby2_var_z : REF +-> INTEGER) & ((Fby2_is_initialisation(Fby2_clock___basic__) = FALSE) => (Fby2_var_z /= {})))))

INITIALISATION 
    Fby2_is_initialisation := (Fby2_clocks * {TRUE}); 
    Fby2_var_x := {}; 
    Fby2_var_z := {}


OPERATIONS 

    Fby2_clock_step(Fby2_param_x) = 
        PRE
            (Fby2_param_x : REF --> INTEGER)
        THEN
            Fby2_var_x := Fby2_param_x; 
            Node_1.fby_node_call_clock_step(Fby2_var_x); 
            Node_2.fby_node_call2_clock_step(Fby2_var_x); 
            Fby2_var_z := l_fby_integer(Fby2_is_initialisation(Fby2_clock___basic__) |-> Node_1.fby_node_call_var_z |-> Node_2.fby_node_call2_var_z); 
            Fby2_is_initialisation(Fby2_clock___basic__) := FALSE

        END;

        out <-- getZ = BEGIN out := Fby2_var_z END

END