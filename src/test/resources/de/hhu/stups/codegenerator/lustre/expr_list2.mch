MACHINE expr_list2

VARIABLES expr_list2_is_initialisation, expr_list2_var_tmp_3, expr_list2_var_clock, expr_list2_var_b, expr_list2_var_a, expr_list2_var_tmp_1, expr_list2_var_tmp_0, expr_list2_var_tmp_2, expr_list2_var_x, expr_list2_var_tmp_4, expr_list2_var_tmp_5, expr_list2_var_y

SETS expr_list2_clocks = {expr_list2_clock___basic__, expr_list2_clock_clock}; expr_list2_refs = {expr_list2_ref}

INVARIANT ((expr_list2_is_initialisation : expr_list2_clocks --> BOOL) & ((expr_list2_var_tmp_3 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_clock : expr_list2_refs +-> BOOL) & ((expr_list2_var_b : expr_list2_refs +-> INTEGER) & ((expr_list2_var_a : expr_list2_refs +-> INTEGER) & ((expr_list2_var_tmp_1 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_tmp_0 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_tmp_2 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_x : expr_list2_refs +-> INTEGER) & ((expr_list2_var_tmp_4 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_tmp_5 : expr_list2_refs +-> INTEGER) & ((expr_list2_var_y : expr_list2_refs +-> INTEGER) & (((expr_list2_is_initialisation(expr_list2_clock___basic__) = FALSE) => (expr_list2_var_a /= {})) & (((expr_list2_is_initialisation(expr_list2_clock___basic__) = FALSE) => (expr_list2_var_b /= {})) & ((expr_list2_is_initialisation(expr_list2_clock_clock) = FALSE) => (expr_list2_var_clock /= {}))))))))))))))))

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
            ((expr_list2_param_x : INTEGER) & ((expr_list2_param_y : INTEGER) & (expr_list2_param_clock : BOOL)))
        THEN
            expr_list2_var_x(expr_list2_ref) := expr_list2_param_x; 
            expr_list2_var_y(expr_list2_ref) := expr_list2_param_y; 
            expr_list2_var_clock(expr_list2_ref) := bool((expr_list2_param_clock = TRUE)); 
            IF (expr_list2_var_x /= {}) THEN 
                expr_list2_var_tmp_0(expr_list2_ref) := expr_list2_var_x(expr_list2_ref)
            ELSE 
                expr_list2_var_tmp_0 := {}
            END; 
            IF (expr_list2_var_clock(expr_list2_ref) = TRUE) THEN 
                IF (expr_list2_var_tmp_0 /= {}) THEN 
                    expr_list2_var_tmp_1(expr_list2_ref) := expr_list2_var_tmp_0(expr_list2_ref)
                ELSE 
                    expr_list2_var_tmp_1 := {}
                END
            END; 
            IF (expr_list2_var_clock(expr_list2_ref) = TRUE) THEN 
                IF (expr_list2_var_tmp_1 /= {}) THEN 
                    expr_list2_var_tmp_2(expr_list2_ref) := expr_list2_var_tmp_1(expr_list2_ref)
                ELSE 
                    expr_list2_var_tmp_2 := {}
                END
            END; 
            IF (expr_list2_var_tmp_2 /= {}) THEN 
                expr_list2_var_a(expr_list2_ref) := expr_list2_var_tmp_2(expr_list2_ref)
            ELSE 
                expr_list2_var_a := {}
            END; 
            IF (expr_list2_var_y /= {}) THEN 
                expr_list2_var_tmp_3(expr_list2_ref) := expr_list2_var_y(expr_list2_ref)
            ELSE 
                expr_list2_var_tmp_3 := {}
            END; 
            IF (expr_list2_var_clock(expr_list2_ref) = TRUE) THEN 
                IF (expr_list2_var_tmp_3 /= {}) THEN 
                    expr_list2_var_tmp_4(expr_list2_ref) := expr_list2_var_tmp_3(expr_list2_ref)
                ELSE 
                    expr_list2_var_tmp_4 := {}
                END
            END; 
            IF (expr_list2_var_clock(expr_list2_ref) = TRUE) THEN 
                IF (expr_list2_var_tmp_4 /= {}) THEN 
                    expr_list2_var_tmp_5(expr_list2_ref) := expr_list2_var_tmp_4(expr_list2_ref)
                ELSE 
                    expr_list2_var_tmp_5 := {}
                END
            END; 
            IF (expr_list2_var_tmp_5 /= {}) THEN 
                expr_list2_var_b(expr_list2_ref) := expr_list2_var_tmp_5(expr_list2_ref)
            ELSE 
                expr_list2_var_b := {}
            END; 
            expr_list2_is_initialisation(expr_list2_clock___basic__) := FALSE; 
            IF (expr_list2_var_clock(expr_list2_ref) = TRUE) THEN 
                expr_list2_is_initialisation(expr_list2_clock_clock) := FALSE
            END

        END;

        out <-- getA = BEGIN out := expr_list2_var_a END;
        out <-- getB = BEGIN out := expr_list2_var_b END



END