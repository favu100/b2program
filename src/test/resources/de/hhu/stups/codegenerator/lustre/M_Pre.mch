MACHINE M_Pre

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_a, var_b, var_c, var_d, var_e, var_tmp_1, var_x, var_tmp_0, var_tmp_2, var_tmp_3, var_y

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_y : LUSTRE_INT) & ((var_x : LUSTRE_INT) & ((var_e : LUSTRE_INT) & ((var_d : LUSTRE_INT) & ((var_c : LUSTRE_INT) & ((var_b : LUSTRE_INT) & ((var_a : LUSTRE_INT) & ((var_tmp_3 : LUSTRE_INT) & ((var_tmp_2 : LUSTRE_INT) & ((var_tmp_1 : LUSTRE_INT) & ((var_tmp_0 : LUSTRE_INT) & (((is_initialisation = FALSE) => (var_e /= {})) & (((is_initialisation = FALSE) => (var_d /= {})) & (((is_initialisation = FALSE) => (var_c /= {})) & (((is_initialisation = FALSE) => (var_b /= {})) & ((is_initialisation = FALSE) => (var_a /= {})))))))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_a := {}; 
    var_b := {}; 
    var_c := {}; 
    var_d := {}; 
    var_e := {}; 
    var_tmp_1 := {}; 
    var_x := {}; 
    var_tmp_0 := {}; 
    var_tmp_2 := {}; 
    var_tmp_3 := {}; 
    var_y := {}


OPERATIONS 

    clock_step(param_x, param_y) = 
        PRE
            ((param_x : LUSTRE_INT_NOT_NIL) & (param_y : LUSTRE_INT_NOT_NIL))
        THEN
            VAR hvar_x, hvar_y, hvar_tmp_0, hvar_tmp_2, hvar_tmp_3 IN
                hvar_x := var_x; 
                hvar_y := var_y; 
                hvar_tmp_0 := var_tmp_0; 
                hvar_tmp_2 := var_tmp_2; 
                hvar_tmp_3 := var_tmp_3; 
                var_x := param_x; 
                var_y := param_y; 
                var_tmp_3 := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> hvar_x); 
                var_tmp_2 := l_fby_integer(is_initialisation |-> {ref |-> 1} |-> var_tmp_1); 
                var_tmp_1 := l_fby_integer(is_initialisation |-> {ref |-> 2} |-> hvar_x); 
                var_tmp_0 := l_plus(var_x |-> var_y); 
                var_a := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> hvar_x); 
                var_b := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> l_plus(hvar_x |-> hvar_y)); 
                var_c := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> hvar_tmp_0); 
                var_d := l_fby_integer(is_initialisation |-> {ref |-> 0} |-> hvar_tmp_2); 
                var_e := l_fby_integer(is_initialisation |-> l_fby_integer(is_initialisation |-> {ref |-> 0} |-> l_plus(hvar_tmp_3 |-> {ref |-> 0})) |-> hvar_y); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END;

     out <-- getD = BEGIN out := var_d END



END

/*
tmp_0: (x + y)
tmp_1: (2 -> pre(x))
tmp_2: (1 -> pre((2 -> pre(x))))
tmp_3: (1 -> pre(x))
*/
