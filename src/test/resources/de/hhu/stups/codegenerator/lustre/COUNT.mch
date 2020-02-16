MACHINE COUNT

SEES LibraryLustre

VARIABLES COUNT_is_initialisation, COUNT_var_n, COUNT_var_incr, COUNT_var_tmp_0, COUNT_var_tmp_1

SETS COUNT_clocks = {COUNT_clock___basic__}

INVARIANT ((COUNT_is_initialisation : COUNT_clocks --> BOOL) & ((COUNT_var_n : REF +-> INTEGER) & ((COUNT_var_incr : REF +-> INTEGER) & ((COUNT_var_tmp_0 : REF +-> INTEGER) & ((COUNT_var_tmp_1 : REF +-> INTEGER) & ((COUNT_is_initialisation(COUNT_clock___basic__) = FALSE) => (COUNT_var_n /= {})))))))

INITIALISATION 
    COUNT_is_initialisation := (COUNT_clocks * {TRUE}); 
    COUNT_var_n := {}; 
    COUNT_var_incr := {}; 
    COUNT_var_tmp_0 := {}; 
    COUNT_var_tmp_1 := {}


OPERATIONS 

    COUNT_clock_step(COUNT_param_incr) = 
        PRE
            (COUNT_param_incr : REF --> INTEGER)
        THEN
            VAR COUNT_tmp_0_history IN
                COUNT_tmp_0_history := COUNT_var_tmp_0; 
                COUNT_var_incr := COUNT_param_incr; 
                COUNT_var_tmp_1 := COUNT_tmp_0_history; 
                COUNT_var_n := l_plus(l_fby_integer(COUNT_is_initialisation(COUNT_clock___basic__) |-> {ref |-> 0} |-> COUNT_var_tmp_1) |-> COUNT_var_incr); 
                COUNT_var_tmp_0 := COUNT_var_n; 
                COUNT_is_initialisation(COUNT_clock___basic__) := FALSE

            END

        END;

        out <-- getRes = BEGIN out := COUNT_var_n END

END