MACHINE Counter
CONSTANTS offset
PROPERTIES offset : INTEGER & offset = 1
VARIABLES count
INVARIANT
 count:NATURAL
INITIALISATION count := 0
OPERATIONS
  Reset = BEGIN count := 0 END;
  Inc = BEGIN count := count+offset END;
  Even = SELECT count mod 2 = 0 THEN skip END;
  Odd = SELECT count mod 2 = 1 THEN skip END;
  out <-- getCount = BEGIN out := count END
END

