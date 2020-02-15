MACHINE expr_list4

VARIABLES expr_list4_is_initialisation, expr_list4_var_tmp_0, expr_list4_var_b, expr_list4_var_a, expr_list4_var_x, expr_list4_var_tmp_2, expr_list4_var_tmp_1, expr_list4_var_tmp_3, expr_list4_var_y

SETS expr_list4_clocks = {expr_list4_clock___basic__}; expr_list4_refs = {expr_list4_ref}

INVARIANT ((expr_list4_is_initialisation : expr_list4_clocks --> BOOL) & ((expr_list4_var_tmp_0 : expr_list4_refs +-> INTEGER) & ((expr_list4_var_b : expr_list4_refs +-> INTEGER) & ((expr_list4_var_a : expr_list4_refs +-> INTEGER) & ((expr_list4_var_x : expr_list4_refs +-> INTEGER) & ((expr_list4_var_tmp_2 : expr_list4_refs +-> INTEGER) & ((expr_list4_var_tmp_1 : expr_list4_refs +-> INTEGER) & ((expr_list4_var_tmp_3 : expr_list4_refs +-> INTEGER) & ((expr_list4_var_y : expr_list4_refs +-> INTEGER) & (((expr_list4_is_initialisation(expr_list4_clock___basic__) = FALSE) => (expr_list4_var_a /= {})) & ((expr_list4_is_initialisation(expr_list4_clock___basic__) = FALSE) => (expr_list4_var_b /= {}))))))))))))

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
            ((expr_list4_param_x : INTEGER) & (expr_list4_param_y : INTEGER))
        THEN
            VAR expr_list4_tmp_0_history, expr_list4_tmp_2_history IN
                expr_list4_tmp_0_history := expr_list4_var_tmp_0; 
                expr_list4_tmp_2_history := expr_list4_var_tmp_2; 
                expr_list4_var_x(expr_list4_ref) := expr_list4_param_x; 
                expr_list4_var_y(expr_list4_ref) := expr_list4_param_y; 
                IF (expr_list4_var_x /= {}) THEN 
                    expr_list4_var_tmp_0(expr_list4_ref) := expr_list4_var_x(expr_list4_ref)
                ELSE 
                    expr_list4_var_tmp_0 := {}
                END; 
                IF (expr_list4_tmp_0_history /= {}) THEN 
                    expr_list4_var_tmp_1(expr_list4_ref) := expr_list4_tmp_0_history(expr_list4_ref)
                ELSE 
                    expr_list4_var_tmp_1 := {}
                END; 
                IF (not((expr_list4_is_initialisation(expr_list4_clock___basic__) = TRUE)) => (expr_list4_var_tmp_1 /= {})) THEN 
                    expr_list4_var_a(expr_list4_ref) := IF (expr_list4_is_initialisation(expr_list4_clock___basic__) = TRUE) THEN 1 ELSE expr_list4_var_tmp_1(expr_list4_ref) END
                ELSE 
                    expr_list4_var_a := {}
                END; 
                IF (expr_list4_var_y /= {}) THEN 
                    expr_list4_var_tmp_2(expr_list4_ref) := expr_list4_var_y(expr_list4_ref)
                ELSE 
                    expr_list4_var_tmp_2 := {}
                END; 
                IF (expr_list4_tmp_2_history /= {}) THEN 
                    expr_list4_var_tmp_3(expr_list4_ref) := expr_list4_tmp_2_history(expr_list4_ref)
                ELSE 
                    expr_list4_var_tmp_3 := {}
                END; 
                IF (not((expr_list4_is_initialisation(expr_list4_clock___basic__) = TRUE)) => (expr_list4_var_tmp_3 /= {})) THEN 
                    expr_list4_var_b(expr_list4_ref) := IF (expr_list4_is_initialisation(expr_list4_clock___basic__) = TRUE) THEN 2 ELSE expr_list4_var_tmp_3(expr_list4_ref) END
                ELSE 
                    expr_list4_var_b := {}
                END; 
                expr_list4_is_initialisation(expr_list4_clock___basic__) := FALSE

            END

        END;

        out <-- getA = BEGIN out := expr_list4_var_a END;
        out <-- getB = BEGIN out := expr_list4_var_b END



END