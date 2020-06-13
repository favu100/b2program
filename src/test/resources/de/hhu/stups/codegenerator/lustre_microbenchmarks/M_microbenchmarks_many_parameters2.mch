MACHINE M_microbenchmarks_many_parameters2

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res1, var_res2, var_res3, var_res4, var_res5, var_res6, var_res7, var_res8, var_res9, var_res10, var_res11, var_res12, var_res13, var_res14, var_res15

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res15 : LUSTRE_BOOL) & ((var_res14 : LUSTRE_BOOL) & ((var_res13 : LUSTRE_BOOL) & ((var_res12 : LUSTRE_BOOL) & ((var_res11 : LUSTRE_BOOL) & ((var_res10 : LUSTRE_BOOL) & ((var_res9 : LUSTRE_BOOL) & ((var_res8 : LUSTRE_BOOL) & ((var_res7 : LUSTRE_BOOL) & ((var_res6 : LUSTRE_BOOL) & ((var_res5 : LUSTRE_BOOL) & ((var_res4 : LUSTRE_BOOL) & ((var_res3 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_BOOL) & ((var_res1 : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_res15 /= {})) & (((is_initialisation = FALSE) => (var_res14 /= {})) & (((is_initialisation = FALSE) => (var_res13 /= {})) & (((is_initialisation = FALSE) => (var_res12 /= {})) & (((is_initialisation = FALSE) => (var_res11 /= {})) & (((is_initialisation = FALSE) => (var_res10 /= {})) & (((is_initialisation = FALSE) => (var_res9 /= {})) & (((is_initialisation = FALSE) => (var_res8 /= {})) & (((is_initialisation = FALSE) => (var_res7 /= {})) & (((is_initialisation = FALSE) => (var_res6 /= {})) & (((is_initialisation = FALSE) => (var_res5 /= {})) & (((is_initialisation = FALSE) => (var_res4 /= {})) & (((is_initialisation = FALSE) => (var_res3 /= {})) & (((is_initialisation = FALSE) => (var_res2 /= {})) & ((is_initialisation = FALSE) => (var_res1 /= {})))))))))))))))))))))))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_res3 := {}; 
    var_res4 := {}; 
    var_res5 := {}; 
    var_res6 := {}; 
    var_res7 := {}; 
    var_res8 := {}; 
    var_res9 := {}; 
    var_res10 := {}; 
    var_res11 := {}; 
    var_res12 := {}; 
    var_res13 := {}; 
    var_res14 := {}; 
    var_res15 := {}


OPERATIONS 

    clock_step(param_var1, param_var2, param_var3, param_var4, param_var5) = 
        PRE
            ((param_var1 : LUSTRE_BOOL_NOT_NIL) & ((param_var2 : LUSTRE_BOOL_NOT_NIL) & ((param_var3 : LUSTRE_BOOL_NOT_NIL) & ((param_var4 : LUSTRE_BOOL_NOT_NIL) & (param_var5 : LUSTRE_BOOL_NOT_NIL)))))
        THEN
            VAR var_var1, var_var2, var_var3, var_var4, var_var5 IN
                var_var1 := param_var1; 
                var_var2 := param_var2; 
                var_var3 := param_var3; 
                var_var4 := param_var4; 
                var_var5 := param_var5; 
                var_res1 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res2 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res3 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res4 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res5 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res6 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res7 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res8 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res9 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res10 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res11 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res12 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res13 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res14 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                var_res15 := l_and(l_and(l_and(l_and(var_var1 |-> var_var2) |-> var_var3) |-> var_var4) |-> var_var5); 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

