MACHINE M_once_since

INCLUDES Node_20.M_after

SEES LibraryLustre

VARIABLES is_initialisation, var_onceCsinceA

INVARIANT ((var_onceCsinceA : LUSTRE_BOOL) & (is_initialisation : BOOL))

INITIALISATION 
    is_initialisation := TRUE; 
    var_onceCsinceA := {}


OPERATIONS 

    clock_step(param_C, param_A) = 
        PRE
            ((param_C : LUSTRE_BOOL) & (param_A : LUSTRE_BOOL))
        THEN
            VAR var_C, var_A IN
                var_C := param_C; 
                var_A := param_A; 
                Node_20.clock_step(var_A); 
                var_onceCsinceA := l_ite_boolean(var_A |-> var_C |-> l_ite_boolean(Node_20.var_afterA |-> l_or(var_C |-> var_onceCsinceA) |-> {ref |-> TRUE})); 
                is_initialisation := FALSE

            END

        END



END