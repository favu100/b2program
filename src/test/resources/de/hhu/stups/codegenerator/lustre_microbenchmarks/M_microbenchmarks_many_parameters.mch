MACHINE M_microbenchmarks_many_parameters

SEES LibraryLustre

VARIABLES assert_ok, is_initialisation, var_res1, var_res2, var_res3, var_res4, var_res5

INVARIANT ((assert_ok : BOOL) & ((is_initialisation : BOOL) & ((var_res5 : LUSTRE_BOOL) & ((var_res4 : LUSTRE_BOOL) & ((var_res3 : LUSTRE_BOOL) & ((var_res2 : LUSTRE_BOOL) & ((var_res1 : LUSTRE_BOOL) & (((is_initialisation = FALSE) => (var_res5 /= {})) & (((is_initialisation = FALSE) => (var_res4 /= {})) & (((is_initialisation = FALSE) => (var_res3 /= {})) & (((is_initialisation = FALSE) => (var_res2 /= {})) & ((is_initialisation = FALSE) => (var_res1 /= {})))))))))))))

INITIALISATION 
    assert_ok := TRUE; 
    is_initialisation := TRUE; 
    var_res1 := {}; 
    var_res2 := {}; 
    var_res3 := {}; 
    var_res4 := {}; 
    var_res5 := {}


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
                var_res1 := var_var1; 
                var_res2 := var_var2; 
                var_res3 := var_var3; 
                var_res4 := var_var4; 
                var_res5 := var_var5; 
                SELECT (assert_ok = TRUE) THEN skip END; 
                is_initialisation := FALSE

            END

        END



END

