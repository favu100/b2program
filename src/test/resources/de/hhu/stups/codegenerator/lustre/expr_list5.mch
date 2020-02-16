MACHINE expr_list5

SEES LibraryLustre

VARIABLES expr_list5_is_initialisation, expr_list5_var_b, expr_list5_var_a, expr_list5_var_x

SETS expr_list5_clocks = {expr_list5_clock___basic__}

INVARIANT ((expr_list5_is_initialisation : expr_list5_clocks --> BOOL) & ((expr_list5_var_b : REF +-> INTEGER) & ((expr_list5_var_a : REF +-> INTEGER) & ((expr_list5_var_x : REF +-> INTEGER) & (((expr_list5_is_initialisation(expr_list5_clock___basic__) = FALSE) => (expr_list5_var_a /= {})) & ((expr_list5_is_initialisation(expr_list5_clock___basic__) = FALSE) => (expr_list5_var_b /= {})))))))

INITIALISATION 
    expr_list5_is_initialisation := (expr_list5_clocks * {TRUE}); 
    expr_list5_var_b := {}; 
    expr_list5_var_a := {}; 
    expr_list5_var_x := {}


OPERATIONS 

    expr_list5_clock_step(expr_list5_param_x) = 
        PRE
            (expr_list5_param_x : REF --> INTEGER)
        THEN
            expr_list5_var_x := expr_list5_param_x; 
            expr_list5_var_b := l_fby_integer(expr_list5_is_initialisation(expr_list5_clock___basic__) |-> {ref |-> 1} |-> expr_list5_var_x); 
            expr_list5_var_a := expr_list5_var_b; 
            expr_list5_is_initialisation(expr_list5_clock___basic__) := FALSE

        END;

        out <-- getA = BEGIN out := expr_list5_var_a END;
        out <-- getB = BEGIN out := expr_list5_var_b END

END