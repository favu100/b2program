MACHINE FinitenessLaws
CONSTANTS
  f1,f6,f7
PROPERTIES
  /* finite sets and relations */
  f1 = {a,e| a = 1 & e : {TRUE}} &
  f6 = %x.(x : 11..19|100) &
  f7 = {a,b| a:1..20 & b=a}

INVARIANT
  f1:FIN(f1) & f6:FIN(f6) & f7:FIN(f7) &
  f1(1)=TRUE &
  card(f6) = 9 & f6(11)=100 &
  card(f7) = 20 & f7(20)=20
OPERATIONS
    test = BEGIN skip END
END
