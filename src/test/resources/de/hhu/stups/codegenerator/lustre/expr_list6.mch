MACHINE expr_list6

INCLUDES Node_1.other_node

SEES LibraryLustre

VARIABLES expr_list6_is_initialisation, expr_list6_var_b, expr_list6_var_a, expr_list6_var_x, expr_list6_var_c

SETS expr_list6_clocks = {expr_list6_clock___basic__}

INVARIANT ((expr_list6_is_initialisation : expr_list6_clocks --> BOOL) & ((expr_list6_var_b : REF +-> INTEGER) & ((expr_list6_var_a : REF +-> INTEGER) & ((expr_list6_var_x : REF +-> INTEGER) & ((expr_list6_var_c : REF +-> INTEGER) & (((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_a /= {})) & (((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_b /= {})) & ((expr_list6_is_initialisation(expr_list6_clock___basic__) = FALSE) => (expr_list6_var_c /= {})))))))))

INITIALISATION 
    expr_list6_is_initialisation := (expr_list6_clocks * {TRUE}); 
    expr_list6_var_b := {}; 
    expr_list6_var_a := {}; 
    expr_list6_var_x := {}; 
    expr_list6_var_c := {}


OPERATIONS 

    expr_list6_clock_step(expr_list6_param_x) = 
        PRE
            (expr_list6_param_x : REF --> INTEGER)
        THEN
            expr_list6_var_x := expr_list6_param_x; 
            Node_1.other_node_clock_step(expr_list6_var_x); 
            expr_list6_var_a := Node_1.other_node_var_a; 
            expr_list6_var_b := Node_1.other_node_var_b; 
            expr_list6_var_c := expr_list6_var_x; 
            expr_list6_is_initialisation(expr_list6_clock___basic__) := FALSE

        END;

        out <-- getA = BEGIN out := expr_list6_var_a END;
        out <-- getB = BEGIN out := expr_list6_var_b END;
        out <-- getC = BEGIN out := expr_list6_var_c END


END