MACHINE M_expr_list3

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation_clock, is_initialisation, var_a, var_b, var_x, var_y, var_clock

INVARIANT ((assert_ok : BOOL) & ((is_initialisation_clock : BOOL) & ((is_initialisation : BOOL) & ((var_clock : LUSTRE_BOOL) & ((var_y : LUSTRE_INT) & ((var_x : LUSTRE_INT) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & (((is_initialisation_clock = FALSE) => (var_b /= {})) & ((is_initialisation_clock = FALSE) => (var_a /= {})))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation_clock := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}; 
    var_x := {}; 
    var_y := {}; 
    var_clock := {}


OPERATIONS 

    clock_step(param_x, param_y, param_clock) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & ((param_y : LUSTRE_INT_NOT_NIL) & (param_clock : LUSTRE_BOOL_NOT_NIL)))
        THEN
            var_x := param_x; 
            var_y := param_y; 
            var_clock := param_clock; 
            PRE (var_clock /= {}) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_a := var_x
            END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                var_b := var_y
            END; 
            SELECT (assert_ok = TRUE) THEN skip END; 
            IF (var_clock = {ref |-> TRUE}) THEN 
                is_initialisation_clock := FALSE
            END; 
            is_initialisation := FALSE

        END;

        out <-- getA = BEGIN out := var_a END;
        out <-- getB = BEGIN out := var_b END



END

