/*
Original Model:
V. Rivera, N. Catano, T. Wahls, and C. Rueda. Code generation for Event-B. STTT, 19(1):31–52, 2017.
*/
MACHINE sort_m2_data1000_asserts
DEFINITIONS GOAL == k = n
CONCRETE_CONSTANTS
  f,
  n
ABSTRACT_VARIABLES
  j,
  k,
  l,
  g
/* PROMOTED OPERATIONS
  progress,
  prog1,
  prog2,
  final_evt */
PROPERTIES
    n : INTEGER
  & /* @sort_c0:axm1  */ n > 0
  & /* @sort_c0:axm2  */ f : 1 .. n >-> NATURAL
  & /* @sort_c0_data400:prob_f  */ f = %i.(i : 1 .. 1000|1500 - i)
  & n = 1000 // for TLC
INVARIANT
    /* @sort_m2:inv1_m2  */ j : k .. n
  & /* @sort_m2:inv2_m2  */ l : k .. j
  & /* @sort_m2:inv3_m2  */ g(l) = min(g[k .. j])
  & /* @sort_m1:inv1_m1  */ g : 1 .. n >-> NATURAL
  & /* @sort_m1:inv2_m1  */ ran(g) = ran(f)
  & /* @sort_m1:inv3_m1  */ k : 1 .. n
//  & /* @sort_m1:inv4_m1  */ !(i_f,j_f).(i_f : 1 .. k - 1 & j_f : i_f + 1 .. n => g(i_f) < g(j_f))
  & /* @sort_m1:inv5_m1  */ l : NATURAL
  & /* @sort_m0:inv1  */ g : NATURAL <-> NATURAL
ASSERTIONS
  /* @sort_m1:thm1_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => g <+ ({a_f |-> g(b_f)} <+ {b_f |-> g(a_f)}) = ({a_f,b_f} <<| g) \/ {a_f |-> g(b_f),b_f |-> g(a_f)});
  /* @sort_m1:thm2_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => {a_f |-> g(b_f),b_f |-> g(a_f)} : 1 .. n >+> NATURAL);
  /* @sort_m1:thm3_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => {a_f,b_f} <<| g : 1 .. n >+> NATURAL);
  /* @sort_m1:thm4_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => dom(({a_f,b_f} <<| g) \/ {a_f |-> g(b_f),b_f |-> g(a_f)}) = 1 .. n);
  /* @sort_m1:thm5_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => dom({a_f,b_f} <<| g) /\ dom({a_f |-> g(b_f),b_f |-> g(a_f)}) = {});
  /* @sort_m1:thm6_m1  */ !(a_f,b_f).(a_f : 1 .. n & (b_f : 1 .. n & a_f /= b_f) => ran({a_f,b_f} <<| g) /\ ran({a_f |-> g(b_f),b_f |-> g(a_f)}) = {})
INITIALISATION
    BEGIN
         g := f
      ||
         k := 1
      ||
         l := 1
      ||
         j := 1
    END
OPERATIONS
  progress = 
    SELECT 
        /* @sort_m2_data400:grd1  */ k /= n
      & /* @sort_m2_data400:grd2  */ j = n
    THEN 
         g := g <+ ({k |-> g(l)} <+ {l |-> g(k)})
      ||
         k := k + 1
      ||
         j := k + 1
      ||
         l := k + 1
    END;
  
  prog1 = 
    SELECT 
        /* @sort_m2_data400:grd1  */ k /= n
      & /* @sort_m2_data400:grd2  */ j /= n
      & /* @sort_m2_data400:grd3  */ g(l) <= g(j + 1)
    THEN 
         l := l
      ||
         j := j + 1
    END;
  
  prog2 = 
    SELECT 
        /* @sort_m2_data400:grd1  */ k /= n
      & /* @sort_m2_data400:grd2  */ j /= n
      & /* @sort_m2_data400:grd3  */ g(l) > g(j + 1)
    THEN 
         j := j + 1
      ||
         l := j + 1
    END;
  
  final_evt = 
    SELECT 
        /* @sort_m2_data400:grd1  */ k = n
    THEN 
      skip
    END
END