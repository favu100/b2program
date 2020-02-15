MACHINE COUNT

VARIABLES COUNT_is_initialisation, COUNT_var_n, COUNT_var_incr, COUNT_var_tmp_0, COUNT_var_tmp_1

SETS COUNT_clocks = {COUNT_clock___basic__}; COUNT_refs = {COUNT_ref}

INVARIANT ((COUNT_is_initialisation : COUNT_clocks --> BOOL) & ((COUNT_var_n : COUNT_refs +-> INTEGER) & ((COUNT_var_incr : COUNT_refs +-> INTEGER) & ((COUNT_var_tmp_0 : COUNT_refs +-> INTEGER) & ((COUNT_var_tmp_1 : COUNT_refs +-> INTEGER) & ((COUNT_is_initialisation(COUNT_clock___basic__) = FALSE) => (COUNT_var_n /= {})))))))

INITIALISATION 
    COUNT_is_initialisation := (COUNT_clocks * {TRUE}); 
    COUNT_var_n := {}; 
    COUNT_var_incr := {}; 
    COUNT_var_tmp_0 := {}; 
    COUNT_var_tmp_1 := {}


OPERATIONS 

    COUNT_clock_step(COUNT_param_incr) = 
        PRE
            (COUNT_param_incr : INTEGER)
        THEN
            VAR COUNT_n_history, COUNT_incr_history, COUNT_tmp_0_history, COUNT_tmp_1_history IN
                COUNT_n_history := COUNT_var_n; 
                COUNT_incr_history := COUNT_var_incr; 
                COUNT_tmp_0_history := COUNT_var_tmp_0; 
                COUNT_tmp_1_history := COUNT_var_tmp_1; 
                COUNT_var_incr(COUNT_ref) := COUNT_param_incr; 
                IF (COUNT_tmp_0_history /= {}) THEN 
                    COUNT_var_tmp_1(COUNT_ref) := COUNT_tmp_0_history(COUNT_ref)
                ELSE 
                    COUNT_var_tmp_1 := {}
                END; 
                IF ((not((COUNT_is_initialisation(COUNT_clock___basic__) = TRUE)) => (COUNT_var_tmp_1 /= {})) & (COUNT_var_incr /= {})) THEN 
                    COUNT_var_n(COUNT_ref) := (IF (COUNT_is_initialisation(COUNT_clock___basic__) = TRUE) THEN 0 ELSE COUNT_var_tmp_1(COUNT_ref) END + COUNT_var_incr(COUNT_ref))
                ELSE 
                    COUNT_var_n := {}
                END; 
                IF (COUNT_var_n /= {}) THEN 
                    COUNT_var_tmp_0(COUNT_ref) := COUNT_var_n(COUNT_ref)
                ELSE 
                    COUNT_var_tmp_0 := {}
                END; 
                COUNT_is_initialisation(COUNT_clock___basic__) := FALSE

            END

        END;

        out <-- getRes = BEGIN out := COUNT_var_n END



END