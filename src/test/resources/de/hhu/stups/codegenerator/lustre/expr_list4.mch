MACHINE expr_list4

SEES LibraryLustre

VARIABLES expr_list4_is_initialisation, expr_list4_var_tmp_0, expr_list4_var_b, expr_list4_var_a, expr_list4_var_x, expr_list4_var_tmp_2, expr_list4_var_tmp_1, expr_list4_var_tmp_3, expr_list4_var_y

SETS expr_list4_clocks = {expr_list4_clock___basic__}

INVARIANT ((expr_list4_is_initialisation : expr_list4_clocks --> BOOL) & ((expr_list4_var_tmp_0 : REF +-> INTEGER) & ((expr_list4_var_b : REF +-> INTEGER) & ((expr_list4_var_a : REF +-> INTEGER) & ((expr_list4_var_x : REF +-> INTEGER) & ((expr_list4_var_tmp_2 : REF +-> INTEGER) & ((expr_list4_var_tmp_1 : REF +-> INTEGER) & ((expr_list4_var_tmp_3 : REF +-> INTEGER) & ((expr_list4_var_y : REF +-> INTEGER) & (((expr_list4_is_initialisation(expr_list4_clock___basic__) = FALSE) => (expr_list4_var_a /= {})) & ((expr_list4_is_initialisation(expr_list4_clock___basic__) = FALSE) => (expr_list4_var_b /= {}))))))))))))

INITIALISATION 
    expr_list4_is_initialisation := (expr_list4_clocks * {TRUE}); 
    expr_list4_var_tmp_0 := {}; 
    expr_list4_var_b := {}; 
    expr_list4_var_a := {}; 
    expr_list4_var_x := {}; 
    expr_list4_var_tmp_2 := {}; 
    expr_list4_var_tmp_1 := {}; 
    expr_list4_var_tmp_3 := {}; 
    expr_list4_var_y := {}


OPERATIONS 

    expr_list4_clock_step(expr_list4_param_x, expr_list4_param_y) = 
        PRE
            ((expr_list4_param_x : REF --> INTEGER) & (expr_list4_param_y : REF --> INTEGER))
        THEN
            VAR expr_list4_tmp_0_history, expr_list4_tmp_2_history IN
                expr_list4_tmp_0_history := expr_list4_var_tmp_0; 
                expr_list4_tmp_2_history := expr_list4_var_tmp_2; 
                expr_list4_var_x := expr_list4_param_x; 
                expr_list4_var_y := expr_list4_param_y; 
                expr_list4_var_tmp_0 := expr_list4_var_x; 
                expr_list4_var_tmp_1 := expr_list4_tmp_0_history; 
                expr_list4_var_a := l_fby_integer(expr_list4_is_initialisation(expr_list4_clock___basic__) |-> {ref |-> 1} |-> expr_list4_var_tmp_1); 
                expr_list4_var_tmp_2 := expr_list4_var_y; 
                expr_list4_var_tmp_3 := expr_list4_tmp_2_history; 
                expr_list4_var_b := l_fby_integer(expr_list4_is_initialisation(expr_list4_clock___basic__) |-> {ref |-> 2} |-> expr_list4_var_tmp_3); 
                expr_list4_is_initialisation(expr_list4_clock___basic__) := FALSE

            END

        END;

        out <-- getA = BEGIN out := expr_list4_var_a END;
        out <-- getB = BEGIN out := expr_list4_var_b END

END