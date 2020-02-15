MACHINE expr_list3

VARIABLES expr_list3_is_initialisation, expr_list3_var_clock, expr_list3_var_b, expr_list3_var_a, expr_list3_var_x, expr_list3_var_tmp_0, expr_list3_var_tmp_1, expr_list3_var_y

SETS expr_list3_clocks = {expr_list3_clock___basic__, expr_list3_clock_clock}; expr_list3_refs = {expr_list3_ref}

INVARIANT ((expr_list3_is_initialisation : expr_list3_clocks --> BOOL) & ((expr_list3_var_clock : expr_list3_refs +-> BOOL) & ((expr_list3_var_b : expr_list3_refs +-> INTEGER) & ((expr_list3_var_a : expr_list3_refs +-> INTEGER) & ((expr_list3_var_x : expr_list3_refs +-> INTEGER) & ((expr_list3_var_tmp_0 : expr_list3_refs +-> INTEGER) & ((expr_list3_var_tmp_1 : expr_list3_refs +-> INTEGER) & ((expr_list3_var_y : expr_list3_refs +-> INTEGER) & (((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_a /= {})) & (((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_b /= {})) & ((expr_list3_is_initialisation(expr_list3_clock_clock) = FALSE) => (expr_list3_var_clock /= {}))))))))))))

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
            ((expr_list3_param_x : INTEGER) & ((expr_list3_param_y : INTEGER) & (expr_list3_param_clock : BOOL)))
        THEN
            expr_list3_var_x(expr_list3_ref) := expr_list3_param_x; 
            expr_list3_var_y(expr_list3_ref) := expr_list3_param_y; 
            expr_list3_var_clock(expr_list3_ref) := bool((expr_list3_param_clock = TRUE)); 
            IF (expr_list3_var_x /= {}) THEN 
                expr_list3_var_tmp_0(expr_list3_ref) := expr_list3_var_x(expr_list3_ref)
            ELSE 
                expr_list3_var_tmp_0 := {}
            END; 
            IF (expr_list3_var_clock(expr_list3_ref) = TRUE) THEN 
                IF (expr_list3_var_tmp_0 /= {}) THEN 
                    expr_list3_var_a(expr_list3_ref) := expr_list3_var_tmp_0(expr_list3_ref)
                ELSE 
                    expr_list3_var_a := {}
                END
            END; 
            IF (expr_list3_var_y /= {}) THEN 
                expr_list3_var_tmp_1(expr_list3_ref) := expr_list3_var_y(expr_list3_ref)
            ELSE 
                expr_list3_var_tmp_1 := {}
            END; 
            IF (expr_list3_var_clock(expr_list3_ref) = TRUE) THEN 
                IF (expr_list3_var_tmp_1 /= {}) THEN 
                    expr_list3_var_b(expr_list3_ref) := expr_list3_var_tmp_1(expr_list3_ref)
                ELSE 
                    expr_list3_var_b := {}
                END
            END; 
            expr_list3_is_initialisation(expr_list3_clock___basic__) := FALSE; 
            IF (expr_list3_var_clock(expr_list3_ref) = TRUE) THEN 
                expr_list3_is_initialisation(expr_list3_clock_clock) := FALSE
            END

        END;

        out <-- getA = BEGIN out := expr_list3_var_a END;
        out <-- getB = BEGIN out := expr_list3_var_b END



END