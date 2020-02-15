MACHINE When8

INCLUDES Node_1.invoked_node, Node_2.invoked_node, Node_3.invoked_node

VARIABLES When8_is_initialisation, When8_var_res1, When8_var_clock2, When8_var_clock1, When8_var_res, When8_var_tmp_0, When8_var_res2, When8_var_tmp_1

SETS When8_clocks = {When8_clock___basic__, When8_clock_clock1, When8_clock_clock2}; When8_refs = {When8_ref}

INVARIANT ((When8_is_initialisation : When8_clocks --> BOOL) & ((When8_var_res1 : When8_refs +-> INTEGER) & ((When8_var_clock2 : When8_refs +-> BOOL) & ((When8_var_clock1 : When8_refs +-> BOOL) & ((When8_var_res : When8_refs +-> INTEGER) & ((When8_var_tmp_0 : When8_refs +-> INTEGER) & ((When8_var_res2 : When8_refs +-> INTEGER) & ((When8_var_tmp_1 : When8_refs +-> INTEGER) & (((When8_is_initialisation(When8_clock___basic__) = FALSE) => (When8_var_res /= {})) & (((When8_is_initialisation(When8_clock_clock1) = FALSE) => (When8_var_res1 /= {})) & (((When8_is_initialisation(When8_clock_clock2) = FALSE) => (When8_var_res2 /= {})) & (((When8_is_initialisation(When8_clock_clock1) = FALSE) => (When8_var_clock1 /= {})) & ((When8_is_initialisation(When8_clock_clock2) = FALSE) => (When8_var_clock2 /= {}))))))))))))))

INITIALISATION 
    When8_is_initialisation := (When8_clocks * {TRUE}); 
    When8_var_res1 := {}; 
    When8_var_clock2 := {}; 
    When8_var_clock1 := {}; 
    When8_var_res := {}; 
    When8_var_tmp_0 := {}; 
    When8_var_res2 := {}; 
    When8_var_tmp_1 := {}


OPERATIONS 

    When8_clock_step(When8_param_clock1, When8_param_clock2) = 
        PRE
            ((When8_param_clock1 : BOOL) & (When8_param_clock2 : BOOL))
        THEN
            When8_var_clock1(When8_ref) := bool((When8_param_clock1 = TRUE)); 
            When8_var_clock2(When8_ref) := bool((When8_param_clock2 = TRUE)); 
            Node_1.invoked_node_clock_step(TRUE); 
            IF (Node_1.invoked_node_var_res /= {}) THEN 
                When8_var_res(When8_ref) := Node_1.invoked_node_var_res(invoked_node_ref)
            ELSE 
                When8_var_res := {}
            END; 
            Node_2.invoked_node_clock_step(TRUE); 
            IF (Node_2.invoked_node_var_res /= {}) THEN 
                When8_var_tmp_0(When8_ref) := Node_2.invoked_node_var_res(invoked_node_ref)
            ELSE 
                When8_var_tmp_0 := {}
            END; 
            IF (When8_var_clock1(When8_ref) = TRUE) THEN 
                IF (When8_var_tmp_0 /= {}) THEN 
                    When8_var_res1(When8_ref) := When8_var_tmp_0(When8_ref)
                ELSE 
                    When8_var_res1 := {}
                END
            END; 
            Node_3.invoked_node_clock_step(TRUE); 
            IF (Node_3.invoked_node_var_res /= {}) THEN 
                When8_var_tmp_1(When8_ref) := Node_3.invoked_node_var_res(invoked_node_ref)
            ELSE 
                When8_var_tmp_1 := {}
            END; 
            IF (When8_var_clock2(When8_ref) = TRUE) THEN 
                IF (When8_var_tmp_1 /= {}) THEN 
                    When8_var_res2(When8_ref) := When8_var_tmp_1(When8_ref)
                ELSE 
                    When8_var_res2 := {}
                END
            END; 
            IF (When8_var_clock1(When8_ref) = TRUE) THEN 
                When8_is_initialisation(When8_clock_clock1) := FALSE
            END; 
            When8_is_initialisation(When8_clock___basic__) := FALSE; 
            IF (When8_var_clock2(When8_ref) = TRUE) THEN 
                When8_is_initialisation(When8_clock_clock2) := FALSE
            END

        END;

        out <-- getRes = BEGIN out := When8_var_res END;
        out <-- getRes1 = BEGIN out := When8_var_res1 END;
        out <-- getRes2 = BEGIN out := When8_var_res2 END



END