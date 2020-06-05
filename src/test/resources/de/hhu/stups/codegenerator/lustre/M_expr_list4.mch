MACHINE M_expr_list4

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_b, var_x, var_y

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_y : LUSTRE_INT) & ((var_x : LUSTRE_INT) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_b /= {})) & ((is_initialisation = FALSE) => (var_a /= {})))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}; 
    var_x := {}; 
    var_y := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & (param_y : LUSTRE_INT_NOT_NIL))
        THEN
            VAR hvar_x, hvar_y IN
                hvar_x := var_x; 
                hvar_y := var_y; 
                var_x := param_x; 
                var_y := param_y; 
                var_a := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> hvar_x); 
                var_b := l_fby_integer(is_initialisation |-> {ref |-> 2} |-> hvar_y); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

       out <-- getA = BEGIN out := var_a END;
       out <-- getB = BEGIN out := var_b END



END

