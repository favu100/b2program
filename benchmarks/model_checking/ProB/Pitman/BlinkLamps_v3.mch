MACHINE BlinkLamps_v3
// Manage Blinking Lights Actuators (blinkLeft, blinkRight)
// and manage timing cycles
// v2: added cycleOn variable so that current cycle is not lost when all blinkers turned off
//     (previous version used max({blinkLeft,blinkRight}), which forgot cycle when all blinkers turned off
// v3: once cycleOn is off and nothing happens we remain in off so that we can start on cycle asap when needed
// Note: it is still unclear to me whether this is the right thing to do,
// it can lead to many light changes in a cycle when the other actuators change
SETS
  DIRECTIONS = {left_blink,right_blink,neutral_blink}
CONSTANTS
  BLINK_DIRECTION,
  LAMP_STATUS /* "Status of blinkLeft, blinkRight" */,
  lamp_on,
  lamp_off,
  
  BLINK_CYCLE_COUNTER,
  
  cycleMaxLampStatus
PROPERTIES
  BLINK_DIRECTION = {left_blink, right_blink} &
  LAMP_STATUS = {0,100} &
  lamp_off = 0 & lamp_on = 100 &
  BLINK_CYCLE_COUNTER = -1..3 &
  cycleMaxLampStatus : BOOL --> LAMP_STATUS &
  cycleMaxLampStatus = {FALSE |-> lamp_off, TRUE |-> lamp_on}
VARIABLES
  active_blinkers /* "set of active blinkers" */,
  remaining_blinks /* "how many cycles remain" */,
  onCycle /* "TRUE if we are currently in the lamp_on cycle" */,
  
  
  /* ACTUATORS */
  blinkLeft /* "Actuator for left blink lamps (0-100)" */,
  blinkRight /* "Actuator for right blink lamps (0-100)" */


INVARIANT
  active_blinkers <: BLINK_DIRECTION &
  remaining_blinks : BLINK_CYCLE_COUNTER &

  blinkLeft: LAMP_STATUS & blinkRight : LAMP_STATUS &
  onCycle: BOOL &
  
  /* "SAF1" */ ((remaining_blinks=0 & (blinkLeft=lamp_off & blinkRight=lamp_off)) <=> active_blinkers ={}) &
  /* "SAF2" */ (blinkRight/=lamp_off => right_blink:active_blinkers) & // strengthened after finding issue with VisB
  /* "SAF3" */ (blinkLeft/=lamp_off  => left_blink:active_blinkers) & // ditto
  
  /* "SAF4" */ (active_blinkers=BLINK_DIRECTION => blinkLeft=blinkRight) // invariant added after finding issue with VisB
  &
   /* "SAF5" */ (onCycle=FALSE => (blinkLeft=lamp_off & blinkRight=lamp_off))
  &
   /* "SAF6" */ (onCycle=TRUE & active_blinkers /={} => not((blinkLeft=lamp_off & blinkRight=lamp_off)))
  
INITIALISATION
  active_blinkers := {} ||
  blinkLeft,blinkRight := lamp_off,lamp_off ||
  remaining_blinks := 0 ||
  onCycle := FALSE

OPERATIONS
  
  SET_AllBlinkersOff = 
  BEGIN
    active_blinkers := {} ||
    remaining_blinks := 0 ||
    blinkLeft,blinkRight := lamp_off, lamp_off
  END;
  
  SET_AllBlinkersOn =
  BEGIN
    active_blinkers := BLINK_DIRECTION ||
    remaining_blinks := -1 ||
    blinkLeft := cycleMaxLampStatus(onCycle) ||
    blinkRight := cycleMaxLampStatus(onCycle) // if onCyle=TRUE then turn both blinkers on
  END;
  
  SET_BlinkersOn(direction,rem) = PRE direction: BLINK_DIRECTION & rem:BLINK_CYCLE_COUNTER & rem /= 0
  THEN
    active_blinkers := {direction} ||
    remaining_blinks := rem ||
    IF direction=right_blink THEN
        blinkLeft := lamp_off ||
        blinkRight := cycleMaxLampStatus(onCycle)
    ELSE
        blinkLeft := cycleMaxLampStatus(onCycle) ||
        blinkRight := lamp_off
    END
  END;
  
  SET_RemainingBlinks(rem) = PRE rem:BLINK_CYCLE_COUNTER & rem /= 0 &
    remaining_blinks /= 0
  THEN
    remaining_blinks := rem
  END;
  
   // TIME-PASSING Events; in the ValidationSequences these events happen every 500 ms
 TIME_BlinkerOn = SELECT (blinkLeft=lamp_off & blinkRight=lamp_off) & remaining_blinks /= 0 THEN
    onCycle := TRUE ||
    IF left_blink:active_blinkers THEN
       blinkLeft := lamp_on 
    END ||
    IF right_blink:active_blinkers THEN
       blinkRight := lamp_on
    END ||
    IF remaining_blinks>0 THEN
       remaining_blinks := remaining_blinks - 1
       // for ELS-7 we already decrement here; setting remaining_blinks now to 3 will complete cycle and then do 3 new blinks
    END
 END;
 
 TIME_BlinkerOff = SELECT not((blinkLeft=lamp_off & blinkRight=lamp_off)) THEN
    blinkLeft,blinkRight := lamp_off, lamp_off ||
    onCycle := FALSE ||
    IF remaining_blinks=0 THEN
       active_blinkers := {}
    END
 END;
 
 TIME_Nothing(newOnCycle) = SELECT newOnCycle = FALSE & (blinkLeft=lamp_off & blinkRight=lamp_off) & active_blinkers={} THEN
    onCycle := newOnCycle
  END
 
END
