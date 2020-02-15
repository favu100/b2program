MACHINE Clock4

VARIABLES Clock4_is_initialisation, Clock4_var_tmp_0, Clock4_var_clock2, Clock4_var_clock1, Clock4_var_res, Clock4_var_tmp_2, Clock4_var_tmp_1, Clock4_var_val

SETS Clock4_clocks = {Clock4_clock___basic__, Clock4_clock_clock1, Clock4_clock_clock2}; Clock4_refs = {Clock4_ref}

INVARIANT ((Clock4_is_initialisation : Clock4_clocks --> BOOL) & ((Clock4_var_tmp_0 : Clock4_refs +-> INTEGER) & ((Clock4_var_clock2 : Clock4_refs +-> BOOL) & ((Clock4_var_clock1 : Clock4_refs +-> BOOL) & ((Clock4_var_res : Clock4_refs +-> INTEGER) & ((Clock4_var_tmp_2 : Clock4_refs +-> INTEGER) & ((Clock4_var_tmp_1 : Clock4_refs +-> INTEGER) & ((Clock4_var_val : Clock4_refs +-> INTEGER) & (((Clock4_is_initialisation(Clock4_clock_clock2) = FALSE) => (Clock4_var_res /= {})) & (((Clock4_is_initialisation(Clock4_clock_clock1) = FALSE) => (Clock4_var_clock1 /= {})) & ((Clock4_is_initialisation(Clock4_clock_clock2) = FALSE) => (Clock4_var_clock2 /= {}))))))))))))

INITIALISATION 
    Clock4_is_initialisation := (Clock4_clocks * {TRUE}); 
    Clock4_var_tmp_0 := {}; 
    Clock4_var_clock2 := {}; 
    Clock4_var_clock1 := {}; 
    Clock4_var_res := {}; 
    Clock4_var_tmp_2 := {}; 
    Clock4_var_tmp_1 := {}; 
    Clock4_var_val := {}


OPERATIONS 

    Clock4_clock_step(Clock4_param_val, Clock4_param_clock1, Clock4_param_clock2) = 
        PRE
            ((Clock4_param_val : INTEGER) & ((Clock4_param_clock1 : BOOL) & (Clock4_param_clock2 : BOOL)))
        THEN
            Clock4_var_val(Clock4_ref) := Clock4_param_val; 
            Clock4_var_clock1(Clock4_ref) := bool((Clock4_param_clock1 = TRUE)); 
            IF (Clock4_var_clock1(Clock4_ref) = TRUE) THEN 
                Clock4_var_clock2(Clock4_ref) := bool((Clock4_param_clock2 = TRUE))
            END; 
            IF (Clock4_var_val /= {}) THEN 
                Clock4_var_tmp_0(Clock4_ref) := Clock4_var_val(Clock4_ref)
            ELSE 
                Clock4_var_tmp_0 := {}
            END; 
            IF (Clock4_var_clock1(Clock4_ref) = TRUE) THEN 
                IF (Clock4_var_tmp_0 /= {}) THEN 
                    Clock4_var_tmp_1(Clock4_ref) := Clock4_var_tmp_0(Clock4_ref)
                ELSE 
                    Clock4_var_tmp_1 := {}
                END
            END; 
            IF (Clock4_var_clock1(Clock4_ref) = TRUE) THEN 
                IF (Clock4_var_tmp_1 /= {}) THEN 
                    Clock4_var_tmp_2(Clock4_ref) := Clock4_var_tmp_1(Clock4_ref)
                ELSE 
                    Clock4_var_tmp_2 := {}
                END
            END; 
            IF ((Clock4_var_clock1(Clock4_ref) = TRUE) & (Clock4_var_clock2(Clock4_ref) = TRUE)) THEN 
                IF (Clock4_var_tmp_2 /= {}) THEN 
                    Clock4_var_res(Clock4_ref) := Clock4_var_tmp_2(Clock4_ref)
                ELSE 
                    Clock4_var_res := {}
                END
            END; 
            IF (Clock4_var_clock1(Clock4_ref) = TRUE) THEN 
                Clock4_is_initialisation(Clock4_clock_clock1) := FALSE
            END; 
            Clock4_is_initialisation(Clock4_clock___basic__) := FALSE; 
            IF ((Clock4_var_clock1(Clock4_ref) = TRUE) & (Clock4_var_clock2(Clock4_ref) = TRUE)) THEN 
                Clock4_is_initialisation(Clock4_clock_clock2) := FALSE
            END

        END



END