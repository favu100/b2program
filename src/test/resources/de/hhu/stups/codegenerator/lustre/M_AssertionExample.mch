MACHINE M_AssertionExample

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_r

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_r : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_r /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_r := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                PRE (l_and(l_greater_equal(var_x |-> {ref |-> 0}) |-> l_less_equal(var_x |-> {ref |-> 2})) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_and(l_greater_equal(var_x |-> {ref |-> 0}) |-> l_less_equal(var_x |-> {ref |-> 2})) = {ref |-> TRUE}))); 
                var_r := l_plus(var_x |-> {ref |-> 1}); 
                PRE (l_and(l_greater_equal(var_r |-> {ref |-> 0}) |-> l_less_equal(var_r |-> {ref |-> 2})) /= {}) THEN skip END; 
                assert_ok := bool(((assert_ok = TRUE) & (l_and(l_greater_equal(var_r |-> {ref |-> 0}) |-> l_less_equal(var_r |-> {ref |-> 2})) = {ref |-> TRUE}))); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getR = BEGIN out := var_r END



END

