MACHINE M_expr_list5

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_b

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_b /= {})) & ((is_initialisation = FALSE) => (var_a /= {})))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_b := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> var_x); 
                var_a := var_b; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

      out <-- getA = BEGIN out := var_a END;
      out <-- getB = BEGIN out := var_b END



END

