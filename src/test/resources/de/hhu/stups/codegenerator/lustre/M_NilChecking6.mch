MACHINE M_NilChecking6

INCLUDES Node_1.M_NilChecking6_Call

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res : LUSTRE_INT) & ((is_initialisation = FALSE) => (var_res /= {})))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x, var_loc IN
                var_x := param_x; 
                Node_1.clock_step(var_x); 
                var_loc := Node_1.var_res; 
                var_res := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> var_x); 
                SELECT ((assert_ok = TRUE) & (Node_1.assert_ok = TRUE)) THEN skip END; 
                is_initialisation := FALSE

            END

        END;


     out <-- getRes = BEGIN out := var_res END



END

/*
Node_1: NilChecking6_Call(x)
*/
