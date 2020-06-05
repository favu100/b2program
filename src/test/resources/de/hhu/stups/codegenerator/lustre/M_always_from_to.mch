MACHINE M_always_from_to

INCLUDES Node_15.M_implies, Node_18.M_once_since, Node_17.M_always_since, Node_16.M_after

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_X

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_X : LUSTRE_BOOL)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_X := {}


OPERATIONS 

    clock_step(param_B, param_A, param_C) = 
        PRE
            ((param_B : LUSTRE_BOOL) & ((param_A : LUSTRE_BOOL) & (param_C : LUSTRE_BOOL)))
        THEN
            VAR var_B, var_A, var_C IN
                var_B := param_B; 
                var_A := param_A; 
                var_C := param_C; 
                Node_16.clock_step(var_A); 
                Node_17.clock_step(var_B, var_A); 
                Node_18.clock_step(var_C, var_A); 
                Node_15.clock_step(Node_16.var_afterA, l_or(Node_17.var_alwaysBsinceA |-> Node_18.var_onceCsinceA)); 
                var_X := Node_15.var_AimpliesB; 
                is_initialisation := FALSE

            END

        END



END

/*
Node_15: implies(after(A), (always_since(B, A) or once_since(C, A)))
Node_16: after(A)
Node_17: always_since(B, A)
Node_18: once_since(C, A)
*/
