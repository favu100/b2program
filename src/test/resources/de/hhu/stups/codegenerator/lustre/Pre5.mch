MACHINE Pre5

VARIABLES Pre5_is_initialisation, Pre5_var_tmp_2, Pre5_var_res1, Pre5_var_B, Pre5_var_X, Pre5_var_tmp_0, Pre5_var_res2, Pre5_var_tmp_1, Pre5_var_tmp_4, Pre5_var_tmp_3, Pre5_var_tmp_6, Pre5_var_tmp_5, Pre5_var_tmp_7

SETS Pre5_clocks = {Pre5_clock_B, Pre5_clock___basic__}; Pre5_refs = {Pre5_ref}

INVARIANT ((Pre5_is_initialisation : Pre5_clocks --> BOOL) & ((Pre5_var_tmp_2 : Pre5_refs +-> INTEGER) & ((Pre5_var_res1 : Pre5_refs +-> INTEGER) & ((Pre5_var_B : Pre5_refs +-> BOOL) & ((Pre5_var_X : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_0 : Pre5_refs +-> INTEGER) & ((Pre5_var_res2 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_1 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_4 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_3 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_6 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_5 : Pre5_refs +-> INTEGER) & ((Pre5_var_tmp_7 : Pre5_refs +-> INTEGER) & (((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_res1 /= {})) & (((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_res2 /= {})) & ((Pre5_is_initialisation(Pre5_clock_B) = FALSE) => (Pre5_var_B /= {})))))))))))))))))

INITIALISATION 
    Pre5_is_initialisation := (Pre5_clocks * {TRUE}); 
    Pre5_var_tmp_2 := {}; 
    Pre5_var_res1 := {}; 
    Pre5_var_B := {}; 
    Pre5_var_X := {}; 
    Pre5_var_tmp_0 := {}; 
    Pre5_var_res2 := {}; 
    Pre5_var_tmp_1 := {}; 
    Pre5_var_tmp_4 := {}; 
    Pre5_var_tmp_3 := {}; 
    Pre5_var_tmp_6 := {}; 
    Pre5_var_tmp_5 := {}; 
    Pre5_var_tmp_7 := {}


OPERATIONS 

    Pre5_clock_step(Pre5_param_B) = 
        PRE
            (Pre5_param_B : BOOL)
        THEN
            VAR Pre5_tmp_0_history, Pre5_tmp_2_history, Pre5_tmp_7_history IN
                Pre5_tmp_0_history := Pre5_var_tmp_0; 
                Pre5_tmp_2_history := Pre5_var_tmp_2; 
                Pre5_tmp_7_history := Pre5_var_tmp_7; 
                Pre5_var_B(Pre5_ref) := bool((Pre5_param_B = TRUE)); 
                IF (Pre5_tmp_0_history /= {}) THEN 
                    Pre5_var_tmp_1(Pre5_ref) := Pre5_tmp_0_history(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_1 := {}
                END; 
                IF (not((Pre5_is_initialisation(Pre5_clock___basic__) = TRUE)) => (Pre5_var_tmp_1 /= {})) THEN 
                    Pre5_var_X(Pre5_ref) := IF (Pre5_is_initialisation(Pre5_clock___basic__) = TRUE) THEN 1 ELSE (Pre5_var_tmp_1(Pre5_ref) + 1) END
                ELSE 
                    Pre5_var_X := {}
                END; 
                IF (Pre5_var_X /= {}) THEN 
                    Pre5_var_tmp_2(Pre5_ref) := Pre5_var_X(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_2 := {}
                END; 
                IF (Pre5_tmp_2_history /= {}) THEN 
                    Pre5_var_tmp_3(Pre5_ref) := Pre5_tmp_2_history(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_3 := {}
                END; 
                IF (Pre5_var_tmp_3 /= {}) THEN 
                    Pre5_var_tmp_4(Pre5_ref) := Pre5_var_tmp_3(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_4 := {}
                END; 
                IF (Pre5_var_B(Pre5_ref) = TRUE) THEN 
                    IF (Pre5_var_tmp_4 /= {}) THEN 
                        Pre5_var_res1(Pre5_ref) := Pre5_var_tmp_4(Pre5_ref)
                    ELSE 
                        Pre5_var_res1 := {}
                    END
                END; 
                IF (Pre5_var_X /= {}) THEN 
                    Pre5_var_tmp_5(Pre5_ref) := Pre5_var_X(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_5 := {}
                END; 
                IF (Pre5_var_B(Pre5_ref) = TRUE) THEN 
                    IF (Pre5_var_tmp_5 /= {}) THEN 
                        Pre5_var_tmp_6(Pre5_ref) := Pre5_var_tmp_5(Pre5_ref)
                    ELSE 
                        Pre5_var_tmp_6 := {}
                    END
                END; 
                IF (Pre5_var_B(Pre5_ref) = TRUE) THEN 
                    IF (Pre5_var_tmp_6 /= {}) THEN 
                        Pre5_var_tmp_7(Pre5_ref) := Pre5_var_tmp_6(Pre5_ref)
                    ELSE 
                        Pre5_var_tmp_7 := {}
                    END
                END; 
                IF (Pre5_var_B(Pre5_ref) = TRUE) THEN 
                    IF (Pre5_tmp_7_history /= {}) THEN 
                        Pre5_var_res2(Pre5_ref) := Pre5_tmp_7_history(Pre5_ref)
                    ELSE 
                        Pre5_var_res2 := {}
                    END
                END; 
                IF (Pre5_var_X /= {}) THEN 
                    Pre5_var_tmp_0(Pre5_ref) := Pre5_var_X(Pre5_ref)
                ELSE 
                    Pre5_var_tmp_0 := {}
                END; 
                Pre5_is_initialisation(Pre5_clock___basic__) := FALSE; 
                IF (Pre5_var_B(Pre5_ref) = TRUE) THEN 
                    Pre5_is_initialisation(Pre5_clock_B) := FALSE
                END

            END

        END;

        out <-- getRes1 = BEGIN out := Pre5_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre5_var_res2 END



END