MACHINE Button
DEFINITIONS 
     "LibraryMeta.def";
      VISB_JSON_FILE == "button.json"
VARIABLES
  button
INVARIANT
  button∈BOOL
INITIALISATION
  button := FALSE
OPERATIONS
  press_button = PRE button=FALSE THEN
    button:=TRUE
  END;
  toggle_button = BEGIN
    button:= bool(button=FALSE)
  END;
  set_button(newVal) = PRE newVal:BOOL & newVal /= button THEN
     button := bool(newVal=TRUE)
  END
END