MACHINE expr_list

SEES LibraryLustre

VARIABLES expr_list_is_initialisation, expr_list_var_x, expr_list_var_a, expr_list_var_b, expr_list_var_y

SETS expr_list_clocks = {expr_list_clock___basic__}

INVARIANT ((expr_list_is_initialisation : expr_list_clocks --> BOOL) & ((expr_list_var_x : REF +-> INTEGER) & ((expr_list_var_a : REF +-> INTEGER) & ((expr_list_var_b : REF +-> INTEGER) & ((expr_list_var_y : REF +-> INTEGER) & (((expr_list_is_initialisation(expr_list_clock___basic__) = FALSE) => (expr_list_var_a /= {})) & ((expr_list_is_initialisation(expr_list_clock___basic__) = FALSE) => (expr_list_var_b /= {}))))))))

INITIALISATION 
    expr_list_is_initialisation := (expr_list_clocks * {TRUE}); 
    expr_list_var_x := {}; 
    expr_list_var_a := {}; 
    expr_list_var_b := {}; 
    expr_list_var_y := {}


OPERATIONS 

    expr_list_clock_step(expr_list_param_x, expr_list_param_y) = 
        PRE
            ((expr_list_param_x : REF --> INTEGER) & (expr_list_param_y : REF --> INTEGER))
        THEN
            expr_list_var_x := expr_list_param_x; 
            expr_list_var_y := expr_list_param_y; 
            expr_list_var_a := expr_list_var_x; 
            expr_list_var_b := expr_list_var_y; 
            expr_list_is_initialisation(expr_list_clock___basic__) := FALSE

        END;

        out <-- getA = BEGIN out := expr_list_var_a END;
        out <-- getB = BEGIN out := expr_list_var_b END

END