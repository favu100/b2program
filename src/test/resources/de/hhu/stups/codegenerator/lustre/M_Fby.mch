MACHINE M_Fby

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_z : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_z /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_z := l_fby_integer(is_initialisation |-> var_x |-> {ref |-> 0}); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;


     out <-- getZ = BEGIN out := var_z END



END

