MACHINE phonebook7_err_enum

SETS
	Name = {n1,n2,n3}  ; Code = {c5,c6}

VARIABLES db, active, activec


INVARIANT
		db : Name +-> Code & active:POW(Name) & activec:POW(Code) &
                dom(db) = active & ran(db) = activec
INITIALISATION  
	db := {} || active := {} || activec := {}
	
OPERATIONS

cc <-- lookup(nn) =
	PRE
		nn : Name & nn : active 
	THEN
		cc:=db(nn)
	END;
   

add(nn,cc) =
	PRE
		nn:Name & cc:Code & nn /: active 
	THEN
		db := db \/ { nn |-> cc} || active := active \/ {nn} || activec := activec \/ {cc}
	END;

delete(nn,cc) =
        PRE
                nn:Name & cc:Code & nn: active & cc: activec /* MISSING: & db(nn) = cc  */
        THEN
               db := db - { nn |-> cc} || active := dom(db - { nn |-> cc}) || activec := db[(active - {nn})]
        END
	
END
