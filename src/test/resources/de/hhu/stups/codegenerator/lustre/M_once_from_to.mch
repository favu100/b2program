MACHINE M_once_from_to

INCLUDES Node_1.M_switch, Node_2.M_jafter

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_OK

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_OK : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_OK := {}


OPERATIONS 

    clock_step(param_A, param_B, param_X) = 
        PRE
            ((param_A : LUSTRE_BOOL) & ((param_B : LUSTRE_BOOL) & (param_X : LUSTRE_BOOL)))
        THEN
            VAR var_A, var_B, var_X, var_between_A_and_X IN
                var_A := param_A; 
                var_B := param_B; 
                var_X := param_X; 
                Node_2.clock_step(var_X); 
                Node_1.clock_step({ref |-> FALSE}, var_A, Node_2.var_after); 
                var_between_A_and_X := Node_1.var_value; 
                var_OK := l_not(l_and(var_between_A_and_X |-> var_B)); 
                is_initialisation := FALSE

            END

        END



END

/*
Node_1: switch(false, A, jafter(X))
Node_2: jafter(X)
*/
