/*
Formal Model and VisB Visualization from
M. Leuschel, M. Mutz, and M. Werth. Modelling and Validating an Automotive System in Classical B and Event-B. In Proceedings ABZ, LNCS 12071, pages 335–350, 2020.
*/
MACHINE PitmanController_TIME_MC_v4

INCLUDES BlinkLamps_v3, Sensors, GenericTimersMC
/*
 The BlinkLamps machine takes care of flashing the lights and the
 remaining blinks (for tip blinking).
 The main machine only has to worry about setting active_blinkers and
 for setting the blinkers to continuous or tip-blinking
 v5 uses v3 BlinkLamps
*/


CONSTANTS
  pitman_direction /* "Convert Pitman position into blink direction" */
PROPERTIES
  pitman_direction = {Neutral |-> neutral_blink, Downward5 |-> left_blink, Downward7 |-> left_blink,
                      Upward5 |-> right_blink, Upward7 |-> right_blink}

INVARIANT
 /* "SAF-H1" */ (hazardWarningSwitchOn = switch_on => active_blinkers=BLINK_DIRECTION)
 /* "ELS-8: As long as the hazard warning light switch is pressed (active), all
          direction indicators flash synchronously. " */ &
 
  /* "SAF-H2" */ (hazardWarningSwitchOn = switch_off & remaining_blinks = -1
   => active_blinkers = {pitman_direction(pitmanArmUpDown)} ) &

  /* "SAF-H3" */ (pitmanArmUpDown:PITMAN_DIRECTION_BLINKING & engineOn=TRUE
   => {pitman_direction(pitmanArmUpDown)} <: active_blinkers) &
   
    /* "SAF-H4" */ (engineOn=FALSE & hazardWarningSwitchOn = switch_off => active_blinkers={})
   &
// new invariants required for Rodin Proof:

 /* "SAF-H0" */ (hazardWarningSwitchOn = switch_on ⇒ remaining_blinks = -1) &
 
 /* "SAF-H3b"*/ (pitmanArmUpDown ∈ PITMAN_DIRECTION_BLINKING & engineOn=TRUE
        ⇒ remaining_blinks = -1)

ASSERTIONS
/* "thm1" */ pitman_direction : PITMAN_POSITION --> DIRECTIONS

INITIALISATION
  AbsoluteSetDeadline(blink_deadline,500)
OPERATIONS
  ENV_Pitman_Tip_blinking_start(newPos) = 
  SELECT newPos : PITMAN_TIP_BLINKING &
     newPos /= pitmanArmUpDown THEN
     // ELS-2, ELS-5
     SET_Pitman_Tip_blinking_short(newPos);
     IF hazardWarningSwitchOn = switch_off
        /* "ELS-13: If the warning light is activated,
                 any tip-blinking will be ignored ..." */
        & engineOn = TRUE
       THEN
          SET_BlinkersOn(pitman_direction(newPos),3)
      END;
     AddDeadline(tip_deadline,500)
  END;
  

  RTIME_Tip_blinking_Timeout(delta) =
   SELECT
     /* "grdTip" */ delta ∈ 0‥500
   THEN
     IF pitmanArmUpDown : PITMAN_TIP_BLINKING & remaining_blinks > 1 &
        active_blinkers = {pitman_direction(pitmanArmUpDown)} THEN
        // after 0.5 seconds a Tip blinking is cancelled and replaced by a continuous blinking
        // ELS-4: If the driver holds the pitman arm for more than 0.5 seconds in position "tip-blinking left",
        // flashing cycles are initiated for all direction
        // indicators on the left (see Req. ELS-1) until the pitman arm leaves the position "tip-blinking left".
       SET_RemainingBlinks(-1)
     END;
     IncreaseTimeUntilDeadline(tip_deadline,delta)
  END;
  
  RTIME_BlinkerOn(delta) =
   SELECT
     /* "grdTip" */ delta ∈ 0‥500
   THEN
     TIME_BlinkerOn;
     IncreaseTimeUntilCyclicDeadline(blink_deadline,delta,500)
  END;
  
  RTIME_BlinkerOff(delta) =
   SELECT
     /* "grdTip" */ delta ∈ 0‥500
   THEN
     TIME_BlinkerOff;
     IncreaseTimeUntilCyclicDeadline(blink_deadline,delta,500)
  END;
  
  RTIME_Nothing(delta,newOnCycle) =
   SELECT
     /* "grdDelta" */ delta ∈ 0‥500 &
     newOnCycle : BOOL
   THEN
     TIME_Nothing(newOnCycle);
     IncreaseTimeUntilCyclicDeadline(blink_deadline,delta,100)
  END;
  
  RTIME_Passes(delta) = SELECT delta : {100}
   THEN
    IncreaseTime(delta)
  END;
  
  ENV_Turn_EngineOn =
  BEGIN
    SET_EngineOn;
    IF pitmanArmUpDown :PITMAN_DIRECTION_BLINKING &
       hazardWarningSwitchOn = switch_off THEN
       SET_BlinkersOn(pitman_direction(pitmanArmUpDown), -1)
    END
  END;
  
  ENV_Turn_EngineOff =
  BEGIN
    SET_EngineOff;
    IF hazardWarningSwitchOn = switch_off
     /* "ELS-8 As long as the hazard warning light switch is pressed (active),
              all direction indicators flash synchronously." */
              // TO DO: pluse ratio 1:2 if ignition key is in lock
    THEN
         SET_AllBlinkersOff
    END
  END;
  
  ENV_Pitman_DirectionBlinking (newPos) =
  // corresponds to pitmanArmUpDown = 2 or 4 (Upward/Downward7)
  // ELS-1, ELS-5
  PRE newPos : PITMAN_POSITION & newPos /= pitmanArmUpDown THEN
     IF hazardWarningSwitchOn = switch_off & engineOn = TRUE THEN
         SET_BlinkersOn(pitman_direction(newPos), -1)
     END;
     SET_Pitman_DirectionBlinking(newPos)
  END;
  
  ENV_Pitman_Reset_to_Neutral =
  // ELS-1, ELS-5
  BEGIN
     SET_Pitman_Reset_to_Neutral;
     IF hazardWarningSwitchOn = switch_off & remaining_blinks = -1 THEN
         SET_AllBlinkersOff
     END
  END;
  
  
  
  ENV_Hazard_blinking(newSwitchPos) = SELECT newSwitchPos : SWITCH_STATUS & newSwitchPos /= hazardWarningSwitchOn THEN
  // ELS-1, ELS-5
      IF newSwitchPos = switch_on // hazardWarningSwitchOn = switch_off
      THEN
         SET_AllBlinkersOn
       ELSIF newSwitchPos = switch_off // hazardWarningSwitchOn = switch_on
       THEN
         IF pitmanArmUpDown = Neutral or engineOn = FALSE THEN
            SET_AllBlinkersOff
         ELSIF  pitmanArmUpDown /: PITMAN_DIRECTION_BLINKING THEN
            // ELS-12 : When hazard warning is deactivated again, the pitman arm is in
            //  position \direction blinking left" or \direction blinking right" ignition is On,
            //  the direction blinking cycle should be started (see Req. ELS-1).
            SET_AllBlinkersOff
         ELSE
            SET_BlinkersOn(pitman_direction(pitmanArmUpDown),remaining_blinks) // remaining_blinks must be ≠ 0
         END
      END;
      SET_Hazard_blinking(newSwitchPos)
  END
  
END
