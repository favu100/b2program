MACHINE Fby2

INCLUDES Node_1.fby_node_call, Node_2.fby_node_call2

VARIABLES Fby2_is_initialisation, Fby2_var_x, Fby2_var_z

SETS Fby2_clocks = {Fby2_clock___basic__}; Fby2_refs = {Fby2_ref}

INVARIANT ((Fby2_is_initialisation : Fby2_clocks --> BOOL) & ((Fby2_var_x : Fby2_refs +-> INTEGER) & ((Fby2_var_z : Fby2_refs +-> INTEGER) & ((Fby2_is_initialisation(Fby2_clock___basic__) = FALSE) => (Fby2_var_z /= {})))))

INITIALISATION 
    Fby2_is_initialisation := (Fby2_clocks * {TRUE}); 
    Fby2_var_x := {}; 
    Fby2_var_z := {}


OPERATIONS 

    Fby2_clock_step(Fby2_param_x) = 
        PRE
            (Fby2_param_x : INTEGER)
        THEN
            Fby2_var_x(Fby2_ref) := Fby2_param_x; 
            IF (Fby2_var_x /= {}) THEN 
                Node_1.fby_node_call_clock_step(Fby2_var_x(Fby2_ref))
            END; 
            IF (Fby2_var_x /= {}) THEN 
                Node_2.fby_node_call2_clock_step(Fby2_var_x(Fby2_ref))
            END; 
            IF (((Fby2_is_initialisation(Fby2_clock___basic__) = TRUE) => (Node_1.fby_node_call_var_z /= {})) or (not((Fby2_is_initialisation(Fby2_clock___basic__) = TRUE)) => (Node_2.fby_node_call2_var_z /= {}))) THEN 
                Fby2_var_z(Fby2_ref) := IF (Fby2_is_initialisation(Fby2_clock___basic__) = TRUE) THEN Node_1.fby_node_call_var_z(fby_node_call_ref) ELSE Node_2.fby_node_call2_var_z(fby_node_call2_ref) END
            ELSE 
                Fby2_var_z := {}
            END; 
            Fby2_is_initialisation(Fby2_clock___basic__) := FALSE

        END;

        out <-- getZ = BEGIN out := Fby2_var_z END



END