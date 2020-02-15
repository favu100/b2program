MACHINE When4

VARIABLES When4_is_initialisation, When4_var_clock, When4_var_a, When4_var_b, When4_var_res, When4_var_tmp_0

SETS When4_clocks = {When4_clock___basic__, When4_clock_clock}; When4_refs = {When4_ref}

INVARIANT ((When4_is_initialisation : When4_clocks --> BOOL) & ((When4_var_clock : When4_refs +-> BOOL) & ((When4_var_a : When4_refs +-> INTEGER) & ((When4_var_b : When4_refs +-> INTEGER) & ((When4_var_res : When4_refs +-> INTEGER) & ((When4_var_tmp_0 : When4_refs +-> INTEGER) & (((When4_is_initialisation(When4_clock_clock) = FALSE) => (When4_var_res /= {})) & ((When4_is_initialisation(When4_clock_clock) = FALSE) => (When4_var_clock /= {})))))))))

INITIALISATION 
    When4_is_initialisation := (When4_clocks * {TRUE}); 
    When4_var_clock := {}; 
    When4_var_a := {}; 
    When4_var_b := {}; 
    When4_var_res := {}; 
    When4_var_tmp_0 := {}


OPERATIONS 

    When4_clock_step(When4_param_clock) = 
        PRE
            (When4_param_clock : BOOL)
        THEN
            When4_var_clock(When4_ref) := bool((When4_param_clock = TRUE)); 
            When4_var_a(When4_ref) := 1; 
            When4_var_b(When4_ref) := 2; 
            IF (((When4_is_initialisation(When4_clock___basic__) = TRUE) => (When4_var_a /= {})) or (not((When4_is_initialisation(When4_clock___basic__) = TRUE)) => (When4_var_b /= {}))) THEN 
                When4_var_tmp_0(When4_ref) := IF (When4_is_initialisation(When4_clock___basic__) = TRUE) THEN When4_var_a(When4_ref) ELSE When4_var_b(When4_ref) END
            ELSE 
                When4_var_tmp_0 := {}
            END; 
            IF (When4_var_clock(When4_ref) = TRUE) THEN 
                IF (When4_var_tmp_0 /= {}) THEN 
                    When4_var_res(When4_ref) := When4_var_tmp_0(When4_ref)
                ELSE 
                    When4_var_res := {}
                END
            END; 
            When4_is_initialisation(When4_clock___basic__) := FALSE; 
            IF (When4_var_clock(When4_ref) = TRUE) THEN 
                When4_is_initialisation(When4_clock_clock) := FALSE
            END

        END;

        out <-- getRes = BEGIN out := When4_var_res END



END