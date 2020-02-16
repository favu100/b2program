MACHINE expr_list3

SEES LibraryLustre

VARIABLES expr_list3_is_initialisation, expr_list3_var_clock, expr_list3_var_b, expr_list3_var_a, expr_list3_var_x, expr_list3_var_tmp_0, expr_list3_var_tmp_1, expr_list3_var_y

SETS expr_list3_clocks = {expr_list3_clock___basic__, expr_list3_clock_clock}

INVARIANT ((expr_list3_is_initialisation : expr_list3_clocks --> BOOL) & ((expr_list3_var_clock : REF +-> BOOL) & ((expr_list3_var_b : REF +-> INTEGER) & ((expr_list3_var_a : REF +-> INTEGER) & ((expr_list3_var_x : REF +-> INTEGER) & ((expr_list3_var_tmp_0 : REF +-> INTEGER) & ((expr_list3_var_tmp_1 : REF +-> INTEGER) & ((expr_list3_var_y : REF +-> INTEGER) & (((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_a /= {})) & (((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_b /= {})) & ((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_clock /= {}))))))))))))

INITIALISATION 
    expr_list3_is_initialisation := (expr_list3_clocks * {TRUE}); 
    expr_list3_var_clock := {}; 
    expr_list3_var_b := {}; 
    expr_list3_var_a := {}; 
    expr_list3_var_x := {}; 
    expr_list3_var_tmp_0 := {}; 
    expr_list3_var_tmp_1 := {}; 
    expr_list3_var_y := {}


OPERATIONS 

    expr_list3_clock_step(expr_list3_param_x, expr_list3_param_y, expr_list3_param_clock) = 
        PRE
            ((expr_list3_param_x : REF --> INTEGER) & ((expr_list3_param_y : REF --> INTEGER) & (expr_list3_param_clock : REF --> BOOL)))
        THEN
            expr_list3_var_x := expr_list3_param_x; 
            expr_list3_var_y := expr_list3_param_y; 
            expr_list3_var_clock := expr_list3_param_clock; 
            expr_list3_var_tmp_0 := expr_list3_var_x; 
            IF (expr_list3_var_clock = {ref |-> TRUE}) THEN 
                expr_list3_var_a := expr_list3_var_tmp_0
            END; 
            expr_list3_var_tmp_1 := expr_list3_var_y; 
            IF (expr_list3_var_clock = {ref |-> TRUE}) THEN 
                expr_list3_var_b := expr_list3_var_tmp_1
            END; 
            expr_list3_is_initialisation(expr_list3_clock___basic__) := FALSE; 
            IF (expr_list3_var_clock = {ref |-> TRUE}) THEN 
                expr_list3_is_initialisation(expr_list3_clock_clock) := FALSE
            END

        END;

        out <-- getA = BEGIN out := expr_list3_var_a END;
        out <-- getB = BEGIN out := expr_list3_var_b END

END