MACHINE M_COUNT

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_n

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_n : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_n /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_n := {}


OPERATIONS 

    clock_step(param_incr) = 
        PRE
            (param_incr : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_incr IN
                var_incr := param_incr; 
                var_n := l_plus(l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_n) |-> var_incr); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getRes = BEGIN out := var_n END



END

