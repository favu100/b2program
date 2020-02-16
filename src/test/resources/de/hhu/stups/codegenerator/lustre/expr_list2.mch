MACHINE expr_list2

SEES LibraryLustre

VARIABLES expr_list2_is_initialisation, expr_list2_var_tmp_3, expr_list2_var_clock, expr_list2_var_b, expr_list2_var_a, expr_list2_var_tmp_1, expr_list2_var_tmp_0, expr_list2_var_tmp_2, expr_list2_var_x, expr_list2_var_tmp_4, expr_list2_var_tmp_5, expr_list2_var_y

SETS expr_list2_clocks = {expr_list2_clock___basic__, expr_list2_clock_clock}

INVARIANT ((expr_list2_is_initialisation : expr_list2_clocks --> BOOL) & ((expr_list2_var_tmp_3 : REF +-> INTEGER) & ((expr_list2_var_clock : REF +-> BOOL) & ((expr_list2_var_b : REF +-> INTEGER) & ((expr_list2_var_a : REF +-> INTEGER) & ((expr_list2_var_tmp_1 : REF +-> INTEGER) & ((expr_list2_var_tmp_0 : REF +-> INTEGER) & ((expr_list2_var_tmp_2 : REF +-> INTEGER) & ((expr_list2_var_x : REF +-> INTEGER) & ((expr_list2_var_tmp_4 : REF +-> INTEGER) & ((expr_list2_var_tmp_5 : REF +-> INTEGER) & ((expr_list2_var_y : REF +-> INTEGER) & (((expr_list2_is_initialisation(expr_list2_clock___basic__) = FALSE) => (expr_list2_var_a /= {})) & (((expr_list2_is_initialisation(expr_list2_clock___basic__) = FALSE) => (expr_list2_var_b /= {})) & ((expr_list2_is_initialisation(expr_list2_clock_clock) = FALSE) => (expr_list2_var_clock /= {}))))))))))))))))

INITIALISATION 
    expr_list2_is_initialisation := (expr_list2_clocks * {TRUE}); 
    expr_list2_var_tmp_3 := {}; 
    expr_list2_var_clock := {}; 
    expr_list2_var_b := {}; 
    expr_list2_var_a := {}; 
    expr_list2_var_tmp_1 := {}; 
    expr_list2_var_tmp_0 := {}; 
    expr_list2_var_tmp_2 := {}; 
    expr_list2_var_x := {}; 
    expr_list2_var_tmp_4 := {}; 
    expr_list2_var_tmp_5 := {}; 
    expr_list2_var_y := {}


OPERATIONS 

    expr_list2_clock_step(expr_list2_param_x, expr_list2_param_y, expr_list2_param_clock) = 
        PRE
            ((expr_list2_param_x : REF --> INTEGER) & ((expr_list2_param_y : REF --> INTEGER) & (expr_list2_param_clock : REF --> BOOL)))
        THEN
            expr_list2_var_x := expr_list2_param_x; 
            expr_list2_var_y := expr_list2_param_y; 
            expr_list2_var_clock := expr_list2_param_clock; 
            expr_list2_var_tmp_0 := expr_list2_var_x; 
            IF (expr_list2_var_clock = {ref |-> TRUE}) THEN 
                expr_list2_var_tmp_1 := expr_list2_var_tmp_0
            END; 
            IF (expr_list2_var_clock = {ref |-> TRUE}) THEN 
                expr_list2_var_tmp_2 := expr_list2_var_tmp_1
            END; 
            expr_list2_var_a := expr_list2_var_tmp_2; 
            expr_list2_var_tmp_3 := expr_list2_var_y; 
            IF (expr_list2_var_clock = {ref |-> TRUE}) THEN 
                expr_list2_var_tmp_4 := expr_list2_var_tmp_3
            END; 
            IF (expr_list2_var_clock = {ref |-> TRUE}) THEN 
                expr_list2_var_tmp_5 := expr_list2_var_tmp_4
            END; 
            expr_list2_var_b := expr_list2_var_tmp_5; 
            expr_list2_is_initialisation(expr_list2_clock___basic__) := FALSE; 
            IF (expr_list2_var_clock = {ref |-> TRUE}) THEN 
                expr_list2_is_initialisation(expr_list2_clock_clock) := FALSE
            END

        END;

        out <-- getA = BEGIN out := expr_list2_var_a END;
        out <-- getB = BEGIN out := expr_list2_var_b END

END