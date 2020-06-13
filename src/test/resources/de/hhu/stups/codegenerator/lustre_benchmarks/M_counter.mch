//generated from Lustre
//taken from N. Halbwachs, P Raymond A Tutorial of Lustre, 2002

MACHINE M_counter

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_c

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & (var_c : LUSTRE_INT)))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_c := {}


OPERATIONS 

    clock_step(param_init, param_incr, param_x, param_reset) = 
        PRE
            ((param_init : LUSTRE_INT) & ((param_incr : LUSTRE_INT) & ((param_x : LUSTRE_BOOL) & (param_reset : LUSTRE_BOOL))))
        THEN
            VAR var_init, var_incr, var_x, var_reset, var_pc IN
                var_init := param_init; 
                var_incr := param_incr; 
                var_x := param_x; 
                var_reset := param_reset; 
                var_pc := l_fby_integer(is_initialisation |-> var_init |-> var_c); 
                var_c := l_ite_integer(var_reset |-> var_init |-> l_ite_integer(l_and(l_and(var_x |-> l_greater(var_pc |-> l_unary_minus({ref |-> 1000}))) |-> l_less(var_pc |-> {ref |-> 1000})) |-> l_plus(var_pc |-> var_incr) |-> var_pc)); 
                is_initialisation := FALSE

            END

        END



END

