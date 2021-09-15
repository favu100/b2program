MACHINE Button
DEFINITIONS 
     "LibraryMeta.def";
      VISB_JSON_FILE == "button.json"
VARIABLES
  button
INVARIANT
  button:BOOL
INITIALISATION
  button := FALSE
OPERATIONS
  press_button = PRE button=FALSE THEN
    button:=TRUE
  END;
  toggle_button = BEGIN
    button:= bool(button=FALSE)
  END;
  set_button(newVal, P2, P3, P4) = PRE newVal:BOOL & P2: BOOL & P3: BOOL & P4: BOOL THEN
     button := bool(newVal=TRUE)
  END
END