MACHINE expr_list6

INCLUDES Node_1.other_node

VARIABLES expr_list6_is_initialisation, expr_list6_var_b, expr_list6_var_a, expr_list6_var_x, expr_list6_var_c

SETS expr_list6_clocks = {expr_list6_clock___basic__}; expr_list6_refs = {expr_list6_ref}

INVARIANT ((expr_list6_is_initialisation : expr_list6_clocks --> BOOL) & ((expr_list6_var_b : expr_list6_refs +-> INTEGER) & ((expr_list6_var_a : expr_list6_refs +-> INTEGER) & ((expr_list6_var_x : expr_list6_refs +-> INTEGER) & ((expr_list6_var_c : expr_list6_refs +-> INTEGER) & (((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_a /= {})) & (((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_b /= {})) & ((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_c /= {})))))))))

INITIALISATION 
    expr_list6_is_initialisation := (expr_list6_clocks * {TRUE}); 
    expr_list6_var_b := {}; 
    expr_list6_var_a := {}; 
    expr_list6_var_x := {}; 
    expr_list6_var_c := {}


OPERATIONS 

    expr_list6_clock_step(expr_list6_param_x) = 
        PRE
            (expr_list6_param_x : INTEGER)
        THEN
            VAR expr_list6_b_history, expr_list6_a_history, expr_list6_x_history, expr_list6_c_history IN
                expr_list6_b_history := expr_list6_var_b; 
                expr_list6_a_history := expr_list6_var_a; 
                expr_list6_x_history := expr_list6_var_x; 
                expr_list6_c_history := expr_list6_var_c; 
                expr_list6_var_x(expr_list6_ref) := expr_list6_param_x; 
                IF (expr_list6_var_x /= {}) THEN 
                    Node_1.other_node_clock_step(expr_list6_var_x(expr_list6_ref))
                END; 
                IF ((Node_1.other_node_var_a /= {}) & (Node_1.other_node_var_b /= {})) THEN 
                    expr_list6_var_a(expr_list6_ref) := Node_1.other_node_var_a(other_node_ref)
                ELSE 
                    expr_list6_var_a := {}
                END; 
                IF ((Node_1.other_node_var_a /= {}) & (Node_1.other_node_var_b /= {})) THEN 
                    expr_list6_var_b(expr_list6_ref) := Node_1.other_node_var_b(other_node_ref)
                ELSE 
                    expr_list6_var_b := {}
                END; 
                IF (expr_list6_var_x /= {}) THEN 
                    expr_list6_var_c(expr_list6_ref) := expr_list6_var_x(expr_list6_ref)
                ELSE 
                    expr_list6_var_c := {}
                END; 
                expr_list6_is_initialisation(expr_list6_clock___basic__) := FALSE

            END

        END;

        out <-- getA = BEGIN out := expr_list6_var_a END;
        out <-- getB = BEGIN out := expr_list6_var_b END;
        out <-- getC = BEGIN out := expr_list6_var_c END



END