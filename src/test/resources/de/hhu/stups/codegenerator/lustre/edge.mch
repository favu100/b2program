MACHINE edge

VARIABLES edge_is_initialisation, edge_var_X, edge_var_EDGE, edge_var_tmp_0, edge_var_tmp_1

SETS edge_clocks = {edge_clock___basic__}; edge_refs = {edge_ref}

INVARIANT ((edge_is_initialisation : edge_clocks --> BOOL) & ((edge_var_X : edge_refs +-> BOOL) & ((edge_var_EDGE : edge_refs +-> BOOL) & ((edge_var_tmp_0 : edge_refs +-> BOOL) & (edge_var_tmp_1 : edge_refs +-> BOOL)))))

INITIALISATION 
    edge_is_initialisation := (edge_clocks * {TRUE}); 
    edge_var_X := {}; 
    edge_var_EDGE := {}; 
    edge_var_tmp_0 := {}; 
    edge_var_tmp_1 := {}


OPERATIONS 

    edge_clock_step(edge_param_X) = 
        PRE
            (edge_param_X : BOOL)
        THEN
            VAR edge_tmp_0_history IN
                edge_tmp_0_history := edge_var_tmp_0; 
                edge_var_X(edge_ref) := bool((edge_param_X = TRUE)); 
                IF (edge_var_X /= {}) THEN 
                    edge_var_tmp_0(edge_ref) := bool((edge_var_X(edge_ref) = TRUE))
                ELSE 
                    edge_var_tmp_0 := {}
                END; 
                IF (edge_tmp_0_history /= {}) THEN 
                    edge_var_tmp_1(edge_ref) := bool((edge_tmp_0_history(edge_ref) = TRUE))
                ELSE 
                    edge_var_tmp_1 := {}
                END; 
                IF (((edge_is_initialisation(edge_clock___basic__) = TRUE) => (edge_var_X /= {})) or (not((edge_is_initialisation(edge_clock___basic__) = TRUE)) => ((edge_var_X /= {}) & (edge_var_tmp_1 /= {})))) THEN 
                    edge_var_EDGE(edge_ref) := bool((IF (edge_is_initialisation(edge_clock___basic__) = TRUE) THEN bool((edge_var_X(edge_ref) = TRUE)) ELSE bool(((edge_var_X(edge_ref) = TRUE) & not((edge_var_tmp_1(edge_ref) = TRUE)))) END = TRUE))
                ELSE 
                    edge_var_EDGE := {}
                END; 
                edge_is_initialisation(edge_clock___basic__) := FALSE

            END

        END



END