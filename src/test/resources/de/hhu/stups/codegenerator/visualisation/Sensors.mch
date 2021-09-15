MACHINE Sensors
/*
 Sensors and sensor value updates
*/
SETS
  SWITCH_STATUS = {switch_on,switch_off};
  PITMAN_POSITION = {Neutral, Downward5, Downward7, Upward5, Upward7};
  KEY_STATE = {NoKeyInserted, KeyInserted,KeyInsertedOnPosition}
CONSTANTS
  PITMAN_DIRECTION_BLINKING /* "Positions which correspond to direction blinking" */,
  PITMAN_TIP_BLINKING /* "Positions which correspond to direction blinking" */
PROPERTIES
  PITMAN_DIRECTION_BLINKING = {Downward7, Upward7} &
  PITMAN_TIP_BLINKING = {Downward5, Upward5} 
VARIABLES
  
  /* SENSORS */
  hazardWarningSwitchOn /* "Actuator: TRUE when Hazard warning light switch is pressed" */,
  pitmanArmUpDown /* "Actuator: Vertical position of the Pitman Arm" */,
  keyState /* "Actuator: position of the Key (NoKeyInserted, KeyInserted,KeyInsertedOnPosition)" */,
  engineOn /* "Actuator: TRUE when the engine is on" */
  
INVARIANT
  
  hazardWarningSwitchOn : SWITCH_STATUS &
  pitmanArmUpDown : PITMAN_POSITION &
  keyState: KEY_STATE &
  engineOn : BOOL 
INITIALISATION
  hazardWarningSwitchOn := switch_off ||
  pitmanArmUpDown := Neutral ||
  keyState := KeyInsertedOnPosition ||
  engineOn := FALSE
OPERATIONS
  
 SET_EngineOn = SELECT engineOn=FALSE & keyState = KeyInsertedOnPosition THEN
   engineOn := TRUE
 END;
 
 SET_EngineOff = SELECT engineOn=TRUE THEN
   engineOn := FALSE
 END;
 
 SET_Pitman_DirectionBlinking (newPos) = 
 // corresponds to pitmanArmUpDown = 2 or 4 (Upward/Downward7)
 // ELS-1, ELS-5
 SELECT newPos : PITMAN_DIRECTION_BLINKING &
     newPos /= pitmanArmUpDown THEN
    pitmanArmUpDown := newPos
 END;
 
 SET_Pitman_Reset_to_Neutral = 
 SELECT pitmanArmUpDown /= Neutral THEN
    pitmanArmUpDown := Neutral
 END;
 
 SET_Pitman_Tip_blinking_short(newPos) = 
 SELECT newPos : PITMAN_TIP_BLINKING &
     newPos /= pitmanArmUpDown  THEN
       pitmanArmUpDown := newPos
 END;
 
 
 SET_Hazard_blinking(newSwitchPos) = SELECT newSwitchPos : SWITCH_STATUS &
    newSwitchPos /= hazardWarningSwitchOn THEN
		hazardWarningSwitchOn := newSwitchPos 
 END
 

 
END

