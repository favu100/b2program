MACHINE M_microbenchmarks_unary_minus_integer

SEES LibraryLustre

VARIABLES is_initialisation, var_res

INVARIANT ((var_res : LUSTRE_INT) & ((is_initialisation : BOOL) & ((is_initialisation = FALSE) => (var_res /= {}))))

INITIALISATION 
    is_initialisation := TRUE; 
    var_res := {}


OPERATIONS 

    clock_step(param_x) = 
        PRE
            (param_x : LUSTRE_INT_NOT_NIL)
        THEN
            VAR var_x IN
                var_x := param_x; 
                var_res := l_unary_minus(var_x); 
                is_initialisation := FALSE

            END

        END



END

