MACHINE expr_list5

VARIABLES expr_list5_is_initialisation, expr_list5_var_b, expr_list5_var_a, expr_list5_var_x

SETS expr_list5_clocks = {expr_list5_clock___basic__}; expr_list5_refs = {expr_list5_ref}

INVARIANT ((expr_list5_is_initialisation : expr_list5_clocks --> BOOL) & ((expr_list5_var_b : expr_list5_refs +-> INTEGER) & ((expr_list5_var_a : expr_list5_refs +-> INTEGER) & ((expr_list5_var_x : expr_list5_refs +-> INTEGER) & (((expr_list5_is_initialisation(expr_list5_clock___basic__) = FALSE) => (expr_list5_var_a /= {})) & ((expr_list5_is_initialisation(expr_list5_clock___basic__) = FALSE) => (expr_list5_var_b /= {})))))))

INITIALISATION 
    expr_list5_is_initialisation := (expr_list5_clocks * {TRUE}); 
    expr_list5_var_b := {}; 
    expr_list5_var_a := {}; 
    expr_list5_var_x := {}


OPERATIONS 

    expr_list5_clock_step(expr_list5_param_x) = 
        PRE
            (expr_list5_param_x : INTEGER)
        THEN
            expr_list5_var_x(expr_list5_ref) := expr_list5_param_x; 
            IF (not((expr_list5_is_initialisation(expr_list5_clock___basic__) = TRUE)) => (expr_list5_var_x /= {})) THEN 
                expr_list5_var_b(expr_list5_ref) := IF (expr_list5_is_initialisation(expr_list5_clock___basic__) = TRUE) THEN 1 ELSE expr_list5_var_x(expr_list5_ref) END
            ELSE 
                expr_list5_var_b := {}
            END; 
            IF (expr_list5_var_b /= {}) THEN 
                expr_list5_var_a(expr_list5_ref) := expr_list5_var_b(expr_list5_ref)
            ELSE 
                expr_list5_var_a := {}
            END; 
            expr_list5_is_initialisation(expr_list5_clock___basic__) := FALSE

        END;

        out <-- getA = BEGIN out := expr_list5_var_a END;
        out <-- getB = BEGIN out := expr_list5_var_b END



END