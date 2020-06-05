MACHINE M_expr_list

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_b

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_b /= {})) & ((is_initialisation = FALSE) => (var_a /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & (param_y : LUSTRE_INT_NOT_NIL))
        THEN
            VAR var_x, var_y IN
                var_x := param_x; 
                var_y := param_y; 
                var_a := var_x; 
                var_b := var_y; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getA = BEGIN out := var_a END;
     out <-- getB = BEGIN out := var_b END



END

