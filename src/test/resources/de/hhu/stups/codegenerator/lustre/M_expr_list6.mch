MACHINE M_expr_list6

INCLUDES Node_1.M_other_node

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_b, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_c : LUSTRE_INT) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_c /= {})) & (((is_initialisation = FALSE) => (var_b /= {})) & ((is_initialisation = FALSE) => (var_a /= {})))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}; 
    var_c := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                Node_1.clock_step(var_x); 
                var_a := Node_1.var_a; 
                var_b := Node_1.var_b; 
                var_c := var_x; 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getA = BEGIN out := var_a END;
     out <-- getB = BEGIN out := var_b END;
     out <-- getC = BEGIN out := var_c END



END

/*
Node_1: other_node(x)
*/
