MACHINE Pre6

VARIABLES Pre6_is_initialisation, Pre6_var_tmp_2, Pre6_var_res1, Pre6_var_B, Pre6_var_X, Pre6_var_tmp_0, Pre6_var_res2, Pre6_var_tmp_10, Pre6_var_tmp_1, Pre6_var_tmp_11, Pre6_var_tmp_6, Pre6_var_tmp_4, Pre6_var_tmp_3, Pre6_var_tmp_5, Pre6_var_tmp_8, Pre6_var_tmp_7, Pre6_var_tmp_9

SETS Pre6_clocks = {Pre6_clock_B, Pre6_clock___basic__}; Pre6_refs = {Pre6_ref}

INVARIANT ((Pre6_is_initialisation : Pre6_clocks --> BOOL) & ((Pre6_var_tmp_2 : Pre6_refs +-> INTEGER) & ((Pre6_var_res1 : Pre6_refs +-> INTEGER) & ((Pre6_var_B : Pre6_refs +-> BOOL) & ((Pre6_var_X : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_0 : Pre6_refs +-> INTEGER) & ((Pre6_var_res2 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_10 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_1 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_11 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_6 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_4 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_3 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_5 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_8 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_7 : Pre6_refs +-> INTEGER) & ((Pre6_var_tmp_9 : Pre6_refs +-> INTEGER) & (((Pre6_is_initialisation(Pre6_clock___basic__) = FALSE) => (Pre6_var_res1 /= {})) & (((Pre6_is_initialisation(Pre6_clock___basic__) = FALSE) => (Pre6_var_res2 /= {})) & ((Pre6_is_initialisation(Pre6_clock_B) = FALSE) => (Pre6_var_B /= {})))))))))))))))))))))

INITIALISATION 
    Pre6_is_initialisation := (Pre6_clocks * {TRUE}); 
    Pre6_var_tmp_2 := {}; 
    Pre6_var_res1 := {}; 
    Pre6_var_B := {}; 
    Pre6_var_X := {}; 
    Pre6_var_tmp_0 := {}; 
    Pre6_var_res2 := {}; 
    Pre6_var_tmp_10 := {}; 
    Pre6_var_tmp_1 := {}; 
    Pre6_var_tmp_11 := {}; 
    Pre6_var_tmp_6 := {}; 
    Pre6_var_tmp_4 := {}; 
    Pre6_var_tmp_3 := {}; 
    Pre6_var_tmp_5 := {}; 
    Pre6_var_tmp_8 := {}; 
    Pre6_var_tmp_7 := {}; 
    Pre6_var_tmp_9 := {}


OPERATIONS 

    Pre6_clock_step(Pre6_param_B) = 
        PRE
            (Pre6_param_B : BOOL)
        THEN
            VAR Pre6_tmp_0_history, Pre6_tmp_2_history, Pre6_tmp_9_history IN
                Pre6_tmp_0_history := Pre6_var_tmp_0; 
                Pre6_tmp_2_history := Pre6_var_tmp_2; 
                Pre6_tmp_9_history := Pre6_var_tmp_9; 
                Pre6_var_B(Pre6_ref) := bool((Pre6_param_B = TRUE)); 
                IF (Pre6_tmp_0_history /= {}) THEN 
                    Pre6_var_tmp_1(Pre6_ref) := Pre6_tmp_0_history(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_1 := {}
                END; 
                IF (not((Pre6_is_initialisation(Pre6_clock___basic__) = TRUE)) => (Pre6_var_tmp_1 /= {})) THEN 
                    Pre6_var_X(Pre6_ref) := IF (Pre6_is_initialisation(Pre6_clock___basic__) = TRUE) THEN 1 ELSE (Pre6_var_tmp_1(Pre6_ref) + 1) END
                ELSE 
                    Pre6_var_X := {}
                END; 
                IF (Pre6_var_X /= {}) THEN 
                    Pre6_var_tmp_2(Pre6_ref) := Pre6_var_X(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_2 := {}
                END; 
                IF (Pre6_tmp_2_history /= {}) THEN 
                    Pre6_var_tmp_3(Pre6_ref) := Pre6_tmp_2_history(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_3 := {}
                END; 
                IF (Pre6_var_tmp_3 /= {}) THEN 
                    Pre6_var_tmp_4(Pre6_ref) := Pre6_var_tmp_3(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_4 := {}
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_var_tmp_4 /= {}) THEN 
                        Pre6_var_tmp_5(Pre6_ref) := Pre6_var_tmp_4(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_5 := {}
                    END
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_var_tmp_5 /= {}) THEN 
                        Pre6_var_tmp_6(Pre6_ref) := Pre6_var_tmp_5(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_6 := {}
                    END
                END; 
                IF (Pre6_var_tmp_6 /= {}) THEN 
                    Pre6_var_res1(Pre6_ref) := Pre6_var_tmp_6(Pre6_ref)
                ELSE 
                    Pre6_var_res1 := {}
                END; 
                IF (Pre6_var_X /= {}) THEN 
                    Pre6_var_tmp_7(Pre6_ref) := Pre6_var_X(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_7 := {}
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_var_tmp_7 /= {}) THEN 
                        Pre6_var_tmp_8(Pre6_ref) := Pre6_var_tmp_7(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_8 := {}
                    END
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_var_tmp_8 /= {}) THEN 
                        Pre6_var_tmp_9(Pre6_ref) := Pre6_var_tmp_8(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_9 := {}
                    END
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_tmp_9_history /= {}) THEN 
                        Pre6_var_tmp_10(Pre6_ref) := Pre6_tmp_9_history(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_10 := {}
                    END
                END; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    IF (Pre6_var_tmp_10 /= {}) THEN 
                        Pre6_var_tmp_11(Pre6_ref) := Pre6_var_tmp_10(Pre6_ref)
                    ELSE 
                        Pre6_var_tmp_11 := {}
                    END
                END; 
                IF (Pre6_var_tmp_11 /= {}) THEN 
                    Pre6_var_res2(Pre6_ref) := Pre6_var_tmp_11(Pre6_ref)
                ELSE 
                    Pre6_var_res2 := {}
                END; 
                IF (Pre6_var_X /= {}) THEN 
                    Pre6_var_tmp_0(Pre6_ref) := Pre6_var_X(Pre6_ref)
                ELSE 
                    Pre6_var_tmp_0 := {}
                END; 
                Pre6_is_initialisation(Pre6_clock___basic__) := FALSE; 
                IF (Pre6_var_B(Pre6_ref) = TRUE) THEN 
                    Pre6_is_initialisation(Pre6_clock_B) := FALSE
                END

            END

        END;

        out <-- getRes1 = BEGIN out := Pre6_var_res1 END;
        out <-- getRes2 = BEGIN out := Pre6_var_res2 END



END