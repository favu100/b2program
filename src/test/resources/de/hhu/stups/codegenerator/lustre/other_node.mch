MACHINE other_node

SEES LibraryLustre

VARIABLES other_node_is_initialisation, other_node_var_b, other_node_var_a, other_node_var_x

SETS other_node_clocks = {other_node_clock___basic__}

INVARIANT ((other_node_is_initialisation : other_node_clocks --> BOOL) & ((other_node_var_b : REF +-> INTEGER) & ((other_node_var_a : REF +-> INTEGER) & (other_node_var_x : REF +-> INTEGER))))

INITIALISATION 
    other_node_is_initialisation := (other_node_clocks * {TRUE}); 
    other_node_var_b := {}; 
    other_node_var_a := {}; 
    other_node_var_x := {}


OPERATIONS 

    other_node_clock_step(other_node_param_x) = 
        PRE
            (other_node_param_x : REF +-> INTEGER)
        THEN
            other_node_var_x := other_node_param_x; 
            other_node_var_a := other_node_var_x; 
            other_node_var_b := other_node_var_x; 
            other_node_is_initialisation(other_node_clock___basic__) := FALSE

        END



END