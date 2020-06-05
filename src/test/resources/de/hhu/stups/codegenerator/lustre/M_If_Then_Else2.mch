MACHINE M_If_Then_Else2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_z, var_x

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_x : LUSTRE_BOOL) & ((var_z : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_z /= {}))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_z := {}; 
    var_x := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_BOOL_NOT_NIL)
        THEN
            VAR hvar_x IN
                hvar_x := var_x; 
                var_x := param_x; 
                var_z := l_ite_integer(hvar_x |-> {ref |-> 1} |-> {ref |-> 0}); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

    out <-- getZ = BEGIN out := var_z END



END

