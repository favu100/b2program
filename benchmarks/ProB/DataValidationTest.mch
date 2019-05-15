MACHINE DataValidationTest
DEFINITIONS
  SET_PREF_TIME_OUT == 120000
CONSTANTS
  n,
  ids, value, ids_for_value
PROPERTIES
  n = 20000 & // with n>20000 value is kept symbolic; investigate; run time jumps from 0.5 to 25 secs
  ids = 1..n &
  value = %x.(x:1..n | x mod 100) &
  ids_for_value = value~
VARIABLES counter, error, checked
INVARIANT
   counter :0..n &
   error : BOOL &
   checked : BOOL
INITIALISATION counter := 0 || error := FALSE || checked := FALSE
OPERATIONS
  Validate = BEGIN
     WHILE counter < n DO
        counter := counter + 1;
        IF counter /: ids THEN
           error := FALSE
        ELSIF value(counter) /: 0..9 THEN
           error := FALSE
        ELSIF card(ids_for_value[{value(counter)}]) < n/100 THEN
           error := FALSE
        END
        INVARIANT counter:INTEGER
        VARIANT n-counter
    END ;
        checked := TRUE
  END
END
