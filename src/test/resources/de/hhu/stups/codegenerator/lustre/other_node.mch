MACHINE other_node

VARIABLES other_node_is_initialisation, other_node_var_b, other_node_var_a, other_node_var_x

SETS other_node_clocks = {other_node_clock___basic__}; other_node_refs = {other_node_ref}

INVARIANT ((other_node_is_initialisation : other_node_clocks --> BOOL) & ((other_node_var_b : other_node_refs +-> INTEGER) & ((other_node_var_a : other_node_refs +-> INTEGER) & (other_node_var_x : other_node_refs +-> INTEGER))))

INITIALISATION 
    other_node_is_initialisation := (other_node_clocks * {TRUE}); 
    other_node_var_b := {}; 
    other_node_var_a := {}; 
    other_node_var_x := {}


OPERATIONS 

    other_node_clock_step(other_node_param_x) = 
        PRE
            (other_node_param_x : INTEGER)
        THEN
            other_node_var_x(other_node_ref) := other_node_param_x; 
            IF (other_node_var_x /= {}) THEN 
                other_node_var_a(other_node_ref) := other_node_var_x(other_node_ref)
            ELSE 
                other_node_var_a := {}
            END; 
            IF (other_node_var_x /= {}) THEN 
                other_node_var_b(other_node_ref) := other_node_var_x(other_node_ref)
            ELSE 
                other_node_var_b := {}
            END; 
            other_node_is_initialisation(other_node_clock___basic__) := FALSE

        END



END