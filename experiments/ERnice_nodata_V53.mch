
MACHINE ERnice_nodata_V53

SETS 

Timer_STATES = {
   Timer_s0, 
   Timer_s1, 
   Timer_s2, 
   Timer_s3, 
   Timer_s4, 
   Timer_s5, 
   Timer_s6, 
   Timer_s7};

IRBC_STATES = {
   IRBC_wait, 
   IRBC_connected, 
   IRBC_sending};

ICSL_STATES = {
   ICSL_NOCOMMSready, 
   ICSL_NOCOMMSconnecting, 
   ICSL_COMMS, 
   ICSL_NOCOMMSwait, 
   ICSL_tbcr6, 
   ICSL_tbcr6a, 
   ICSL_tbcr7};

ISAI_STATES = {
   ISAI_Disconnected, 
   ISAI_Connecting, 
   ISAI_Initializing, 
   ISAI_tbcrt, 
   ISAI_tbcr7a, 
   ISAI_Connected, 
   ISAI_tbcr12, 
   ISAI_tbcr15, 
   ISAI_tbcr15b, 
   ISAI_tbcr15d, 
   ISAI_tbcrta, 
   ISAI_tbcrack};

EUR_STATES = {
   EUR_s0};

CSAI_STATES = {
   CSAI_Disconnected, 
   CSAI_Connecting, 
   CSAI_Initializing, 
   CSAI_tbcrta, 
   CSAI_tbcr6, 
   CSAI_tbcr9, 
   CSAI_tbcr9a, 
   CSAI_Connected, 
   CSAI_tbcr9b, 
   CSAI_tbcr9ba, 
   CSAI_tbcr10, 
   CSAI_tbcr12, 
   CSAI_tbcr14, 
   CSAI_tbcr14b, 
   CSAI_tbcr14d, 
   CSAI_tbcrtc, 
   CSAI_tbcrack};

CCSL_STATES = {
   CCSL_NOCOMMS, 
   CCSL_COMMS, 
   CCSL_tbcr5, 
   CCSL_tbcr9, 
   CCSL_tbcr9a};

CRBC_STATES = {
   CRBC_wait, 
   CRBC_sending};

Timer_SIGNALS = {
   ok_irbc, 
   ok_icsl, 
   ok_isai, 
   ok_eur, 
   ok_csai, 
   ok_ccsl, 
   ok_crbc};

IRBC_SIGNALS = {
   IRBC_User_Connect_indication, 
   IRBC_User_Disconnect_indication, 
   IRBC_User_Data_indication, 
   irbc_tick};

ICSL_SIGNALS = {
   IRBC_User_Data_request, 
   ISAI_CONNECT_confirm, 
   ISAI_DISCONNECT_indication, 
   ISAI_Error_report, 
   ISAI_DATA_indication, 
   icsl_tick};

ISAI_SIGNALS = {
   ISAI_CONNECT_request, 
   ISAI_DISCONNECT_request, 
   ISAI_DATA_request, 
   ISAI_SA_Connect_confirm, 
   ISAI_SA_Disconnect_indication, 
   ISAI_SA_Data_indication, 
   ISAI_SA_Execution_Cycle_Start, 
   isai_tick};

EUR_SIGNALS = {
   ISAI_SA_Connect_request, 
   ISAI_SA_Disconnect_request, 
   ISAI_SA_Data_request, 
   ISAI_SA_Execution_Cycle, 
   CSAI_SA_Disconnect_request, 
   CSAI_SA_Data_request, 
   CSAI_SA_Connect_response, 
   CSAI_SA_Execution_Cycle, 
   EUR_tick};

CSAI_SIGNALS = {
   CSAI_SA_Connect_indication, 
   CSAI_SA_Disconnect_indication, 
   CSAI_SA_Data_indication, 
   CSAI_SA_Execution_Cycle_Start, 
   CSAI_DISCONNECT_request, 
   CSAI_DATA_request, 
   csai_tick};

CCSL_SIGNALS = {
   CRBC_User_Data_request, 
   CSAI_CONNECT_indication, 
   CSAI_DISCONNECT_indication, 
   CSAI_DATA_indication, 
   CSAI_Error_report, 
   ccsl_tick};

CRBC_SIGNALS = {
   CRBC_User_Connect_indication, 
   CRBC_User_Disconnect_indication, 
   CRBC_User_Data_indication, 
   crbc_tick}

DEFINITIONS 

SET_PREF_MAXINT == 30;
SET_PREF_MININT == -30;

CONSTANTS 
LifeSign,
RBCdata

PROPERTIES 
LifeSign = 2 &
RBCdata = 3

VARIABLES 

// Timer
Timer_eventsfifobuff,
Timer_eventsdatabuff,
Timer_STATE,

// IRBC
IRBC_n,
IRBC_nmax,
IRBC_eventsfifobuff,
IRBC_eventsdatabuff,
IRBC_STATE,

// ICSL
ICSL_max_receiveTimer,
ICSL_max_sendTimer,
ICSL_max_connectTimer,
ICSL_receiveTimer,
ICSL_sendTimer,
ICSL_connectTimer,
ICSL_eventsfifobuff,
ICSL_eventsdatabuff,
ICSL_STATE,

// ISAI
ISAI_K,
ISAI_max_initTimer,
ISAI_N,
ISAI_M,
ISAI_max_ack_requestTimer,
ISAI_max_ack_responseTimer,
ISAI_Mec,
ISAI_sarg1,
ISAI_sarg2,
ISAI_sarg4,
ISAI_initTimer,
ISAI_OFFSET,
ISAI_EC_expected,
ISAI_DELTA,
ISAI_currentEC,
ISAI_last_in,
ISAI_next_out,
ISAI_dist,
ISAI_ack_requestTimer,
ISAI_ack_responseTimer,
ISAI_ack_reply,
ISAI_ack_request,
ISAI_outdatabuff,
ISAI_waitnextcycle,
ISAI_eventsfifobuff,
ISAI_eventsdatabuff,
ISAI_STATE,

// EUR
EUR_eventsfifobuff,
EUR_eventsdatabuff,
EUR_STATE,

// CSAI
CSAI_K,
CSAI_max_initTimer,
CSAI_N,
CSAI_M,
CSAI_max_ack_requestTimer,
CSAI_max_ack_responseTimer,
CSAI_Mec,
CSAI_sarg1,
CSAI_sarg2,
CSAI_sarg3,
CSAI_sarg4,
CSAI_initTimer,
CSAI_OFFSET,
CSAI_EC_expected,
CSAI_DELTA,
CSAI_currentEC,
CSAI_last_in,
CSAI_next_out,
CSAI_dist,
CSAI_ack_requestTimer,
CSAI_ack_responseTimer,
CSAI_ack_reply,
CSAI_ack_request,
CSAI_outdatabuff,
CSAI_waitnextcycle,
CSAI_eventsfifobuff,
CSAI_eventsdatabuff,
CSAI_STATE,

// CCSL
CCSL_max_receiveTimer,
CCSL_max_sendTimer,
CCSL_receiveTimer,
CCSL_sendTimer,
CCSL_eventsfifobuff,
CCSL_eventsdatabuff,
CCSL_STATE,

// CRBC
CRBC_eventsfifobuff,
CRBC_eventsdatabuff,
CRBC_STATE

INVARIANT 

// Timer
Timer_eventsfifobuff: seq(Timer_SIGNALS) &
Timer_eventsdatabuff: seq(MININT..MAXINT) &
Timer_STATE: Timer_STATES &

// IRBC
IRBC_n: MININT..MAXINT &
IRBC_nmax: MININT..MAXINT &
IRBC_eventsfifobuff: seq(IRBC_SIGNALS) &
IRBC_eventsdatabuff: seq(MININT..MAXINT) &
IRBC_STATE: IRBC_STATES &

// ICSL
ICSL_max_receiveTimer: MININT..MAXINT &
ICSL_max_sendTimer: MININT..MAXINT &
ICSL_max_connectTimer: MININT..MAXINT &
ICSL_receiveTimer: MININT..MAXINT &
ICSL_sendTimer: MININT..MAXINT &
ICSL_connectTimer: MININT..MAXINT &
ICSL_eventsfifobuff: seq(ICSL_SIGNALS) &
ICSL_eventsdatabuff: seq(MININT..MAXINT) &
ICSL_STATE: ICSL_STATES &

// ISAI
ISAI_K: MININT..MAXINT &
ISAI_max_initTimer: MININT..MAXINT &
ISAI_N: MININT..MAXINT &
ISAI_M: MININT..MAXINT &
ISAI_max_ack_requestTimer: MININT..MAXINT &
ISAI_max_ack_responseTimer: MININT..MAXINT &
ISAI_Mec: MININT..MAXINT &
ISAI_sarg1: MININT..MAXINT &
ISAI_sarg2: MININT..MAXINT &
ISAI_sarg4: MININT..MAXINT &
ISAI_initTimer: MININT..MAXINT &
ISAI_OFFSET: MININT..MAXINT &
ISAI_EC_expected: MININT..MAXINT &
ISAI_DELTA: MININT..MAXINT &
ISAI_currentEC: MININT..MAXINT &
ISAI_last_in: MININT..MAXINT &
ISAI_next_out: MININT..MAXINT &
ISAI_dist: MININT..MAXINT &
ISAI_ack_requestTimer: MININT..MAXINT &
ISAI_ack_responseTimer: MININT..MAXINT &
ISAI_ack_reply: MININT..MAXINT &
ISAI_ack_request: MININT..MAXINT &
ISAI_outdatabuff: seq(MININT..MAXINT) &
ISAI_waitnextcycle: BOOL &
ISAI_eventsfifobuff: seq(ISAI_SIGNALS) &
ISAI_eventsdatabuff: seq(MININT..MAXINT) &
ISAI_STATE: ISAI_STATES &

// EUR
EUR_eventsfifobuff: seq(EUR_SIGNALS) &
EUR_eventsdatabuff: seq(MININT..MAXINT) &
EUR_STATE: EUR_STATES &

// CSAI
CSAI_K: MININT..MAXINT &
CSAI_max_initTimer: MININT..MAXINT &
CSAI_N: MININT..MAXINT &
CSAI_M: MININT..MAXINT &
CSAI_max_ack_requestTimer: MININT..MAXINT &
CSAI_max_ack_responseTimer: MININT..MAXINT &
CSAI_Mec: MININT..MAXINT &
CSAI_sarg1: MININT..MAXINT &
CSAI_sarg2: MININT..MAXINT &
CSAI_sarg3: MININT..MAXINT &
CSAI_sarg4: MININT..MAXINT &
CSAI_initTimer: MININT..MAXINT &
CSAI_OFFSET: MININT..MAXINT &
CSAI_EC_expected: MININT..MAXINT &
CSAI_DELTA: MININT..MAXINT &
CSAI_currentEC: MININT..MAXINT &
CSAI_last_in: MININT..MAXINT &
CSAI_next_out: MININT..MAXINT &
CSAI_dist: MININT..MAXINT &
CSAI_ack_requestTimer: MININT..MAXINT &
CSAI_ack_responseTimer: MININT..MAXINT &
CSAI_ack_reply: MININT..MAXINT &
CSAI_ack_request: MININT..MAXINT &
CSAI_outdatabuff: seq(MININT..MAXINT) &
CSAI_waitnextcycle: BOOL &
CSAI_eventsfifobuff: seq(CSAI_SIGNALS) &
CSAI_eventsdatabuff: seq(MININT..MAXINT) &
CSAI_STATE: CSAI_STATES &

// CCSL
CCSL_max_receiveTimer: MININT..MAXINT &
CCSL_max_sendTimer: MININT..MAXINT &
CCSL_receiveTimer: MININT..MAXINT &
CCSL_sendTimer: MININT..MAXINT &
CCSL_eventsfifobuff: seq(CCSL_SIGNALS) &
CCSL_eventsdatabuff: seq(MININT..MAXINT) &
CCSL_STATE: CCSL_STATES &

// CRBC
CRBC_eventsfifobuff: seq(CRBC_SIGNALS) &
CRBC_eventsdatabuff: seq(MININT..MAXINT) &
CRBC_STATE: CRBC_STATES

INITIALISATION 

// Timer
Timer_eventsfifobuff := [];
Timer_eventsdatabuff :=  [];
Timer_STATE := Timer_s0;

// IRBC
IRBC_n := 1;
IRBC_nmax := 0;
IRBC_eventsfifobuff := [];
IRBC_eventsdatabuff :=  [];
IRBC_STATE := IRBC_wait;

// ICSL
ICSL_max_receiveTimer := 20;
ICSL_max_sendTimer := 1;
ICSL_max_connectTimer := 15;
ICSL_receiveTimer := 0;
ICSL_sendTimer := 0;
ICSL_connectTimer := 0;
ICSL_eventsfifobuff := [];
ICSL_eventsdatabuff :=  [];
ICSL_STATE := ICSL_NOCOMMSready;

// ISAI
ISAI_K := 3;
ISAI_max_initTimer := 15;
ISAI_N := 1;
ISAI_M := 3;
ISAI_max_ack_requestTimer := 3;
ISAI_max_ack_responseTimer := 10;
ISAI_Mec := 5;
ISAI_sarg1 := 0;
ISAI_sarg2 := 0;
ISAI_sarg4 := 0;
ISAI_initTimer := 0;
ISAI_OFFSET := 0;
ISAI_EC_expected := 0;
ISAI_DELTA := 0;
ISAI_currentEC := 0;
ISAI_last_in := 0;
ISAI_next_out := 0;
ISAI_dist := 0;
ISAI_ack_requestTimer := 0;
ISAI_ack_responseTimer := 0;
ISAI_ack_reply := 0;
ISAI_ack_request := 0;
ISAI_outdatabuff := [];
ISAI_waitnextcycle := FALSE;
ISAI_eventsfifobuff := [];
ISAI_eventsdatabuff :=  [];
ISAI_STATE := ISAI_Disconnected;

// EUR
EUR_eventsfifobuff := [];
EUR_eventsdatabuff :=  [];
EUR_STATE := EUR_s0;

// CSAI
CSAI_K := 3;
CSAI_max_initTimer := 15;
CSAI_N := 1;
CSAI_M := 3;
CSAI_max_ack_requestTimer := 3;
CSAI_max_ack_responseTimer := 10;
CSAI_Mec := 5;
CSAI_sarg1 := 0;
CSAI_sarg2 := 0;
CSAI_sarg3 := 0;
CSAI_sarg4 := 0;
CSAI_initTimer := 0;
CSAI_OFFSET := 0;
CSAI_EC_expected := 0;
CSAI_DELTA := 0;
CSAI_currentEC := 0;
CSAI_last_in := 0;
CSAI_next_out := 0;
CSAI_dist := 0;
CSAI_ack_requestTimer := 0;
CSAI_ack_responseTimer := 0;
CSAI_ack_reply := 0;
CSAI_ack_request := 0;
CSAI_outdatabuff := [];
CSAI_waitnextcycle := FALSE;
CSAI_eventsfifobuff := [];
CSAI_eventsdatabuff :=  [];
CSAI_STATE := CSAI_Disconnected;

// CCSL
CCSL_max_receiveTimer := 20;
CCSL_max_sendTimer := 3;
CCSL_receiveTimer := 0;
CCSL_sendTimer := 0;
CCSL_eventsfifobuff := [];
CCSL_eventsdatabuff :=  [];
CCSL_STATE := CCSL_NOCOMMS;

// CRBC
CRBC_eventsfifobuff := [];
CRBC_eventsdatabuff :=  [];
CRBC_STATE := CRBC_wait

OPERATIONS 

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine Timer
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

R0_Timer_IRBC =
PRE
  Timer_STATE = Timer_s0
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- irbc_tick;
  //
  Timer_STATE := Timer_s1
END;

R1_Timer_ICSL =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_irbc & 
  Timer_STATE = Timer_s1
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- icsl_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s2
END;

R2_Timer_ISAI =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_icsl & 
  Timer_STATE = Timer_s2
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- isai_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s3
END;

R3_Timer_EUR =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_isai & 
  Timer_STATE = Timer_s3
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- EUR_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s4
END;

R4_Timer_ISAI =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_eur & 
  Timer_STATE = Timer_s4
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- csai_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s5
END;

R5_Timer_ISAI =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_csai & 
  Timer_STATE = Timer_s5
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- ccsl_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s6
END;

R6_Timer_ISAI =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_ccsl & 
  Timer_STATE = Timer_s6
THEN
  CRBC_eventsfifobuff := CRBC_eventsfifobuff <- crbc_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s7
END;

R7_Timer_ISAI =
PRE
  Timer_eventsfifobuff /= [] & 
  first(Timer_eventsfifobuff) = ok_crbc & 
  Timer_STATE = Timer_s7
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- irbc_tick;
  //
  Timer_eventsfifobuff := tail(Timer_eventsfifobuff);
  Timer_STATE := Timer_s1
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine IRBC
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

R1a_IRBCS_tick =
PRE
  IRBC_eventsfifobuff /= [] & 
  first(IRBC_eventsfifobuff) = irbc_tick & 
  IRBC_STATE = IRBC_wait
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_irbc;
  //
  IRBC_eventsfifobuff := tail(IRBC_eventsfifobuff);
  IRBC_STATE := IRBC_wait
END;

R1d_IRBC =
PRE
  IRBC_eventsfifobuff /= [] & 
  first(IRBC_eventsfifobuff) = IRBC_User_Connect_indication & 
  IRBC_STATE = IRBC_wait
THEN
  skip;
  //
  IRBC_eventsfifobuff := tail(IRBC_eventsfifobuff);
  IRBC_STATE := IRBC_connected
END;

R2a_IRBC =
PRE
  IRBC_eventsfifobuff /= [] & 
  first(IRBC_eventsfifobuff) = irbc_tick & 
  IRBC_STATE = IRBC_connected
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_irbc;
  //
  IRBC_eventsfifobuff := tail(IRBC_eventsfifobuff);
  IRBC_STATE := IRBC_sending
END;

R2b_IRBC(arg1) =
PRE
  IRBC_eventsfifobuff /= [] & 
  first(IRBC_eventsfifobuff) = IRBC_User_Data_indication & 
  arg1 = first(IRBC_eventsdatabuff) &
  IRBC_STATE = IRBC_connected
THEN
  skip;
  //
  IRBC_eventsfifobuff := tail(IRBC_eventsfifobuff);
  IRBC_eventsdatabuff := tail(IRBC_eventsdatabuff);
  IRBC_STATE := IRBC_connected
END;

R2c_IRBC =
PRE
 ( IRBC_n <= IRBC_nmax) &
  IRBC_STATE = IRBC_sending
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- IRBC_User_Data_request;
  ICSL_eventsdatabuff := ICSL_eventsdatabuff <- IRBC_n;
  IRBC_n := IRBC_n + 1;
  //
  IRBC_STATE := IRBC_connected
END;

R2f_IRBC =
PRE
 ( IRBC_n > IRBC_nmax) &
  IRBC_STATE = IRBC_sending
THEN
  skip;
  //
  IRBC_STATE := IRBC_connected
END;

R3_IRBC =
PRE
  IRBC_eventsfifobuff /= [] & 
  first(IRBC_eventsfifobuff) = IRBC_User_Disconnect_indication & 
  IRBC_STATE = IRBC_connected
THEN
  skip;
  //
  IRBC_eventsfifobuff := tail(IRBC_eventsfifobuff);
  IRBC_STATE := IRBC_wait
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine ICSL
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// --------------------------------------------------------
// -- R2: When in Disconnected state, the CSL immediately 
// --     sends a SAI_CONNECT.request to the SAI component,
// --     starts a connTimer, and moves to Connecting state
// --------------------------------------------------------
R2_ICSL_connecting =
PRE
  ICSL_STATE = ICSL_NOCOMMSready
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_CONNECT_request;
  ICSL_connectTimer := 0;
  //
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

// ----------------------------------------------------------
// -- R3: When in Connecting state the connTimer expires, the
// --     CSL moves to Disconnected state
// ----------------------------------------------------------
// -- while connecting in case of timeout become ready to retry
R3_ICSL_okicsl_connect =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
 ( ICSL_connectTimer = ICSL_max_connectTimer) &
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSready
END;

// ------------------------------------------------------------------------    
// -- R4: When in Connecting state is received a SAI_CONNECT.confirm from 
// --     the SAI component, the CSL sends a RBC_User_Connect.indication
// --     to the RBC component, starts both the sendTimer and the recTimer,
// --     and moves to Connected state
// ------------------------------------------------------------------------
R4_ICSL_userconnind =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_CONNECT_confirm & 
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- IRBC_User_Connect_indication;
  ICSL_connectTimer := ICSL_max_connectTimer;
  ICSL_receiveTimer := 0;
  ICSL_sendTimer := ICSL_max_sendTimer;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_COMMS
END;

// --------------------------------------------------------------------
// -- R5: When in Waiting state is received a SAI_DISCONNECT.indication 
// --     from the SAI component, the CSL moves to Disconnected state
// --------------------------------------------------------------------
R5_ICSL_becomeready =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DISCONNECT_indication & 
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSready
END;

// ---------------------------------------------------------------------
// -- R6: When in Connected state the recTimer expires, the CSL sends a SAI_DISCONNECT.request 
// --     to the SAI component, a RBC_User_Disconnect.indication to the RBC and moves to 
// --     Waiting state
// ---------------------------------------------------------------------
R6_ICSL_okicsl =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
 ( ICSL_receiveTimer = ICSL_max_receiveTimer) &
  ICSL_STATE = ICSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_tbcr6
END;

R6_ICSL_saidisconnreq =
PRE
  ICSL_STATE = ICSL_tbcr6
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_DISCONNECT_request;
  ICSL_receiveTimer := 0;
  ICSL_sendTimer := 0;
  //
  ICSL_STATE := ICSL_tbcr6a
END;

R6_ICSL_userdisconnind =
PRE
  ICSL_STATE = ICSL_tbcr6a
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- IRBC_User_Disconnect_indication;
  //
  ICSL_STATE := ICSL_NOCOMMSwait
END;

// ----------------------------------------------------------------        
// -- R7: Each time that in Connected state the sendTimer expires,
// --     the CSL sends a SAI_DATA.request with a life_sign to the
// --     SAI component
// ----------------------------------------------------------------        
R7_ICSL_okicsl =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
 ( (ICSL_receiveTimer < ICSL_max_receiveTimer) & (ICSL_sendTimer = ICSL_max_sendTimer)) &
  ICSL_STATE = ICSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  ICSL_sendTimer := 0;
  ICSL_receiveTimer := ICSL_receiveTimer + 1;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_tbcr7
END;

R7_ICSL_saidatareq =
PRE
  ICSL_STATE = ICSL_tbcr7
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_DATA_request;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- LifeSign;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- 0;
  //
  ICSL_STATE := ICSL_COMMS
END;

// ------------------------------------------------------------------
// -- R8: When in Connected state is received a RBC_User_Data.request
// --     with RBC_data from the RBC component, the CSL sends a 
// --     SAI_DATA.request with such RBC_data to the SAI component
// ------------------------------------------------------------------
R8_ICSL_saidatareq(arg1) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = IRBC_User_Data_request & 
  arg1 = first(ICSL_eventsdatabuff) &
  ICSL_STATE = ICSL_COMMS
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_DATA_request;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- RBCdata;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg1;
  ICSL_sendTimer := 0;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(ICSL_eventsdatabuff);
  ICSL_STATE := ICSL_COMMS
END;

// ----------------------------------------------------------------
// -- R9: When in Connected state is received a SAI_DATA.indication with SAI_data
// --     from the SAI component, the CSL sends a RBC_User_Data.indication with 
// --     such SAI_data to the RBC component and restarts the recTimer
// ----------------------------------------------------------------
R9_ICSL_userdataind(arg1,arg2) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DATA_indication & 
  arg1 = first(ICSL_eventsdatabuff) &
  arg2 = first(tail(ICSL_eventsdatabuff)) &
 ( arg1 /= LifeSign) &
  ICSL_STATE = ICSL_COMMS
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- IRBC_User_Data_indication;
  IRBC_eventsdatabuff := IRBC_eventsdatabuff <- arg2;
  ICSL_receiveTimer := 0;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(tail(ICSL_eventsdatabuff));
  ICSL_STATE := ICSL_COMMS
END;

// -----------------------------------------------------------------
// -- R10: When in Connected state is received a SAI_DATA.indication with a 
// --      life_sign from the SAI component, the CSL restarts the recTimer
// -----------------------------------------------------------------
R10_ICSL_handlelifesign(arg1,arg2) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DATA_indication & 
  arg1 = first(ICSL_eventsdatabuff) &
  arg2 = first(tail(ICSL_eventsdatabuff)) &
 ( arg1 = LifeSign) &
  ICSL_STATE = ICSL_COMMS
THEN
  ICSL_receiveTimer := 0;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(tail(ICSL_eventsdatabuff));
  ICSL_STATE := ICSL_COMMS
END;

// -----------------------------------------------------------------
// -- R11: When in Connected state is received a SAI_DISCONNECT.indication from the 
// --      SAI component, the  CSL sends a RBC_User_Disconnect.indication to the RBC 
// --      component and moves to Disconnected state
// -----------------------------------------------------------------
R11_ICSL_userdisconnind =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DISCONNECT_indication & 
  ICSL_STATE = ICSL_COMMS
THEN
  IRBC_eventsfifobuff := IRBC_eventsfifobuff <- IRBC_User_Disconnect_indication;
  ICSL_receiveTimer := 0;
  ICSL_sendTimer := 0;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSready
END;

// ------------------------------------------------------------------
// -- RD1: When in Disconnected state the CSL does not accept any 
// --      kind of message
// --
// -- RD2: When in Connecting state, the CSL discards any message
// --      except for SAI_CONNECT.confirm from the SAI component
// --
// -- RD3: When in Waiting state, the CSL discards any message except
// --      for SAI_DISCONNECT.indication from the SAI component
// --
// -- RD4: When in Connected state, the CSL component discards only 
// --      SAI_CONNECT.confirm and SAI_ERROR.report messages from 
// --      the SAI component
// ------------------------------------------------------------------
RD2a_ICSL_discuserdata(arg1) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = IRBC_User_Data_request & 
  arg1 = first(ICSL_eventsdatabuff) &
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(ICSL_eventsdatabuff);
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

RD2b_ICSL_discdisconnind =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DISCONNECT_indication & 
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

RD2c_ICSL_discerrorreport =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_Error_report & 
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

RD2d_ICSL_discdataind(arg1,arg2) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DATA_indication & 
  arg1 = first(ICSL_eventsdatabuff) &
  arg2 = first(tail(ICSL_eventsdatabuff)) &
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(tail(ICSL_eventsdatabuff));
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

RD3a_ICSL_discuserdata(arg1) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = IRBC_User_Data_request & 
  arg1 = first(ICSL_eventsdatabuff) &
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(ICSL_eventsdatabuff);
  ICSL_STATE := ICSL_NOCOMMSwait
END;

RD3b_ICSL_discerrorreport =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_Error_report & 
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSwait
END;

RD3c_ICSL_discdataind(arg1,arg2) =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_DATA_indication & 
  arg1 = first(ICSL_eventsdatabuff) &
  arg2 = first(tail(ICSL_eventsdatabuff)) &
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_eventsdatabuff := tail(tail(ICSL_eventsdatabuff));
  ICSL_STATE := ICSL_NOCOMMSwait
END;

RD3d_ICSL_discconfirm =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_CONNECT_confirm & 
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSwait
END;

RD4a_ICSL_disccommconfirm =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_CONNECT_confirm & 
  ICSL_STATE = ICSL_COMMS
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_COMMS
END;

RD4b_ICSL_usererror =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = ISAI_Error_report & 
  ICSL_STATE = ICSL_COMMS
THEN
  skip;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_COMMS
END;

// ------------------------
// -- clock cycles handling 
// ------------------------
RTa_ICSL_okicsl_incr =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
 ( ICSL_connectTimer < ICSL_max_connectTimer) &
  ICSL_STATE = ICSL_NOCOMMSconnecting
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  ICSL_connectTimer := ICSL_connectTimer + 1;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSconnecting
END;

RTb_ICSL_okicsl_incr =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
  ICSL_STATE = ICSL_NOCOMMSwait
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_NOCOMMSwait
END;

RTc_ICSL_okicsl =
PRE
  ICSL_eventsfifobuff /= [] & 
  first(ICSL_eventsfifobuff) = icsl_tick & 
 ( (ICSL_receiveTimer < ICSL_max_receiveTimer) & (ICSL_sendTimer < ICSL_max_sendTimer)) &
  ICSL_STATE = ICSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_icsl;
  ICSL_sendTimer := ICSL_sendTimer + 1;
  ICSL_receiveTimer := ICSL_receiveTimer + 1;
  //
  ICSL_eventsfifobuff := tail(ICSL_eventsfifobuff);
  ICSL_STATE := ICSL_COMMS
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine ISAI
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// -------------------------------------------------------------------
// -- R2: When in Disconnected state is received a SAI_CONNECT.request 
// --     from the CSL component, the SAI sends a Sa_CONNECT.request 
// --     to the ER-SL and moves to Connecting state
// -------------------------------------------------------------------
R2_ISAI_connreq =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_CONNECT_request & 
  ISAI_STATE = ISAI_Disconnected
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Connect_request;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connecting
END;

// ----------------------------------------------------------------------
// -- R3: When in Disconnected state is received a SAI_DISCONNECT.request
// --     from the CSL component, the SAI replies with a 
// --     SAI_DISCONNECT.indication to the CSL component
// ----------------------------------------------------------------------
R3_ISAI_disconndiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DISCONNECT_request & 
  ISAI_STATE = ISAI_Disconnected
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DISCONNECT_indication;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

// ----------------------------------------------------------------------
// -- R4: When in Connecting state is received a Sa_DISCONNECT.indication
// --     from the ER-SL, the SAI moves to Disconnected state
// ----------------------------------------------------------------------
R4_ISAI_abortconn =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Disconnect_indication & 
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

// --------------------------------------------------------------------
// -- R5: When in Connecting state is received a SAI_DISCONNECT.request
// --     the message is discarded (it should never happen)
// --------------------------------------------------------------------
R5_ISAI_CSLdisconnind =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DISCONNECT_request & 
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connecting
END;

// -------------------------------------------------------------------
// -- R6: When in Connecting state is received a Sa_CONNECT.confirm from the ER-SL, 
// --     the SAI replies with a Sa_ExecutionCycle(seqnum, ecnum) to the ER-SL and
// --     moves to the Initializing state, waiting for a Sa_ExecutionCycleStart
// --     message from the ER-SL within a maximum initialization delay. 
// --     For the management of the Sa_ExecutionCycleStart parameters see the
// --     SEQ_NUMs and REQ_ECNUMs Management sections
// -------------------------------------------------------------------
R6_ISAI_confinitproc =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Connect_confirm & 
  ISAI_STATE = ISAI_Connecting
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Execution_Cycle;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_currentEC;
  ISAI_next_out := (ISAI_next_out + 1) mod ISAI_M;
  ISAI_initTimer := 0;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Initializing
END;

// -------------------------------------------------------------------
// -- R7: When in Initializing state the maximum initialization delay expires, 
// --     the SAI sends an SAI_ERROR.report to the CSL component, a 
// --     Sa_DISCONNECT.request to the ER-SL and moves to Disconnected state
// -------------------------------------------------------------------
RTa_ISAI_confinitprocwait =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = isai_tick & 
  ISAI_STATE = ISAI_Initializing
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_isai;
  ISAI_initTimer := ISAI_initTimer + 1;
  ISAI_currentEC := (ISAI_currentEC + 1) mod ISAI_Mec;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_tbcrt
END;

R7_ISAI_confinitprocwaiterrorr =
PRE
 ( ISAI_initTimer = ISAI_max_initTimer) &
  ISAI_STATE = ISAI_tbcrt
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_Error_report;
  //
  ISAI_STATE := ISAI_tbcr7a
END;

R7_ISAI_confinitprocwaitdisconn =
PRE
  ISAI_STATE = ISAI_tbcr7a
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Disconnect_request;
  ISAI_initTimer := 0;
  ISAI_currentEC := 0;
  //
  ISAI_STATE := ISAI_Disconnected
END;

RTb_ISAI_connreqdiscard =
PRE
 ( ISAI_initTimer < ISAI_max_initTimer) &
  ISAI_STATE = ISAI_tbcrt
THEN
  skip;
  //
  ISAI_STATE := ISAI_Initializing
END;

// -------------------------------------------------------------------
// -- R8: When in Initializing state is received a SAI_DISCONNECT.request from the
// --     CSL component, the message is discarded (it should never happen).
// -------------------------------------------------------------------
R8_ISAI_CSLdisconnind =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DISCONNECT_request & 
  ISAI_STATE = ISAI_Initializing
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Initializing
END;

// -------------------------------------------------------------------
// -- R9: When in Initializing state is received a Sa_DISCONNECT.indication 
// --     from the ER-SL the SAI moves to Disconnected state
// -------------------------------------------------------------------
R9_ISAI_abortconn =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Disconnect_indication & 
  ISAI_STATE = ISAI_Initializing
THEN
  ISAI_initTimer := 0;
  ISAI_currentEC := 0;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R10: When in Initializing state is received a SAI_CONNECT.request from 
// --      the CSL component, the message is discarded 
// -------------------------------------------------------------------
R10_ISAI_connreqdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_CONNECT_request & 
  ISAI_STATE = ISAI_Initializing
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Initializing
END;

// -------------------------------------------------------------------
// -- R11: When in Initializing state is received a Sa_ExecutionCycleStart(seqnum, ecnum)
// --      from the ER-SL, the SAI sends a SAI_CONNECT.confirm to the CSL component and
// --      moves to Connected state. The received seqnum is accepted as initial remote
// --      sequence number and the ecnum is accepted as initial value of the remote
// --      execution cycle counter. The execution_cycle_OFFSET variable is set as the
// --      difference between the current execution cycle counter and the received
// --      execution cycle counter. While the last_received_sequence_number variable is
// --      set to the received sequence number
// -------------------------------------------------------------------
R11_ISAI_confinitproc(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Execution_Cycle_Start & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Initializing
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_CONNECT_confirm;
  ISAI_OFFSET := ISAI_currentEC - arg2;
  ISAI_initTimer := 0;
  ISAI_ack_requestTimer := 0;
  ISAI_ack_responseTimer := ISAI_max_ack_responseTimer + 1;
  ISAI_ack_reply := 0;
  ISAI_last_in := arg1;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// -- R12: When in Connected state is received a SAI_DISCONNECT.request from the CSL 
// --      component,the SAI replies with a SAI_DISCONNECT.indication to the CSL component, 
// --      sends a Sa_DISCONNECT.request to the ER-SL, and moves to Disconnected state
// -------------------------------------------------------------------
R12_ISAI_CSLdisconnind =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DISCONNECT_request & 
  ISAI_STATE = ISAI_Connected
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DISCONNECT_indication;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_tbcr12
END;

R12_ISAI_CSLdisconnreq =
PRE
  ISAI_STATE = ISAI_tbcr12
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Disconnect_request;
  ISAI_ack_requestTimer := ISAI_max_ack_requestTimer;
  ISAI_ack_responseTimer := 0;
  ISAI_ack_reply := 0;
  ISAI_currentEC := 0;
  ISAI_outdatabuff := [];
  ISAI_ack_request := 0;
  ISAI_waitnextcycle := FALSE;
  //
  ISAI_STATE := ISAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R13a: When in Connected state is received a SAI_DATA_request(msgtype, data) from the 
// --       CSL component, and yet no other data message has been sent in this cycle, the  
// --       SAI sends aSa_DATA.request(msgtype, data, ackreq, ackresp, seqnum, ecnum) 
// --       to the ER-SL. The ackreq  and  ackresp parameters are set  according to REQ_ACKs.
// --       The seqnum parameter isset according to SEQ_NUMs and the ecnum parameter 
// --is set according to REQ_ECNUMs Management
// -------------------------------------------------------------------
R13a_ISAI_datareqforward(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DATA_request & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
 ( ISAI_waitnextcycle = FALSE) &
  ISAI_STATE = ISAI_Connected
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Data_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- arg1;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- arg2;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_ack_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_ack_reply;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_currentEC;
  ISAI_waitnextcycle := TRUE;
  ISAI_next_out := (ISAI_next_out + 1) mod ISAI_M;
  IF ISAI_ack_request = 1  THEN
    ISAI_ack_request := 0;
    ISAI_ack_requestTimer := 0;
    ISAI_ack_responseTimer := 0
  ELSE
    skip
  END;
  ISAI_ack_reply := 0;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// -- R13b: When in Connected state is received a SAI_DATA.request(msgtype, data) from the 
// -- CSL component,but another data message has already been sent in this cycle, 
// -- the SAI_DATA.request is  saved in a FIFO dataout buffer 
// --   (see also the REQ_OUTDATABUFFs Management)
// -------------------------------------------------------------------
R13b_ISAI_datareqstore(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DATA_request & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
 ( ISAI_waitnextcycle = TRUE) &
  ISAI_STATE = ISAI_Connected
THEN
  ISAI_outdatabuff := ISAI_outdatabuff ^ [arg1,arg2];
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// -- R14: When in Connected state is received a Sa_DISCONNECT.indication from
// --      the ER-SL, the SAI sends a SAI_DISCONNECT.indication to the CSL
// --      component and moves to Disconnected state
// -------------------------------------------------------------------
R14_ISAI_abortconn =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Disconnect_indication & 
  ISAI_STATE = ISAI_Connected
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DISCONNECT_indication;
  ISAI_ack_requestTimer := ISAI_max_ack_requestTimer;
  ISAI_ack_responseTimer := 0;
  ISAI_ack_reply := 0;
  ISAI_outdatabuff := [];
  ISAI_ack_request := 0;
  ISAI_waitnextcycle := FALSE;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R15: When in Connected state is received a 
// --      Sa_DATA.indication(msgtype, data, ackreq, ackresp, seqnum, ecnum) from the ER-SL
// --      we can have four cases, depending on the received seqnum and ecnum values 
// --(see SEQ_NUMs and REC_ECNUMs Management): *
// -------------------------------------------------------------------
R15_ISAI_datareceive(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Data_indication & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  arg3 = first(tail(tail(ISAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(ISAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(ISAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(ISAI_eventsdatabuff)))))) &
  ISAI_STATE = ISAI_Connected
THEN
  ISAI_dist := arg5 - ISAI_last_in;
  IF ISAI_dist < 0 - (ISAI_M) / 2  THEN
    ISAI_dist := ISAI_dist + ISAI_M
  ELSE
    skip
  END;
  IF ISAI_dist > (ISAI_M) / 2  THEN
    ISAI_dist := ISAI_dist - ISAI_M
  ELSE
    skip
  END;
  IF (ISAI_dist > 0) & (ISAI_dist <= ISAI_N)  THEN
    ISAI_last_in := arg5
  ELSE
    skip
  END;
  ISAI_sarg1 := arg1;
  ISAI_sarg2 := arg2;
  ISAI_ack_reply := ISAI_ack_reply + arg3 - (ISAI_ack_reply) * arg3;
  ISAI_sarg4 := arg4;
  ISAI_EC_expected := (ISAI_currentEC + ISAI_Mec - ISAI_OFFSET) mod ISAI_Mec;
  ISAI_DELTA := ISAI_EC_expected - arg6;
  IF ISAI_DELTA < 0 - (ISAI_Mec) / 2  THEN
    ISAI_DELTA := ISAI_DELTA + ISAI_Mec
  ELSE
    skip
  END;
  IF ISAI_DELTA > (ISAI_Mec) / 2  THEN
    ISAI_DELTA := ISAI_DELTA - ISAI_Mec
  ELSE
    skip
  END;
  ISAI_EC_expected := 0;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(ISAI_eventsdatabuff))))));
  ISAI_STATE := ISAI_tbcr15
END;

// -------------------------------------------------------------------
// --    Case 1
// -- *  The seqnum is the one EXPECTED and ecnum is VALID: In this case the SAI sends a 
// --SAI_DATA.indication(msgtype, data) to the CSL component
// -------------------------------------------------------------------
R15a_ISAI_dataindforward =
PRE
 ( (ISAI_dist = 1) & (ISAI_DELTA < ISAI_K)) &
  ISAI_STATE = ISAI_tbcr15
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DATA_indication;
  ICSL_eventsdatabuff := ICSL_eventsdatabuff <- ISAI_sarg1;
  ICSL_eventsdatabuff := ICSL_eventsdatabuff <- ISAI_sarg2;
  IF (ISAI_sarg4 = 1) & (ISAI_ack_responseTimer < ISAI_max_ack_responseTimer)  THEN
    ISAI_ack_responseTimer := ISAI_max_ack_responseTimer + 1
  ELSE
    skip
  END;
  ISAI_sarg1 := 0;
  ISAI_sarg2 := 0;
  ISAI_sarg4 := 0;
  ISAI_dist := 0;
  ISAI_DELTA := 0;
  //
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// --    Case 2
// -- *  The seqnum is ACCEPTABLE and the ecnum is VALID: in this case the SAI sends a  
// --      SAI_DATA.indication(msgtype, data) and a SAI_ERROR.report to the CSL component
// -------------------------------------------------------------------
R15b_ISAI_dataindforward =
PRE
 ( (ISAI_dist > 1) & ((ISAI_dist <= ISAI_N) & (ISAI_DELTA < ISAI_K))) &
  ISAI_STATE = ISAI_tbcr15
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DATA_indication;
  ICSL_eventsdatabuff := ICSL_eventsdatabuff <- ISAI_sarg1;
  ICSL_eventsdatabuff := ICSL_eventsdatabuff <- ISAI_sarg2;
  IF (ISAI_sarg4 = 1) & (ISAI_ack_responseTimer < ISAI_max_ack_responseTimer)  THEN
    ISAI_ack_responseTimer := ISAI_max_ack_responseTimer + 1
  ELSE
    skip
  END;
  ISAI_sarg1 := 0;
  ISAI_sarg2 := 0;
  ISAI_sarg4 := 0;
  ISAI_dist := 0;
  ISAI_DELTA := 0;
  //
  ISAI_STATE := ISAI_tbcr15b
END;

R15b_ISAI_datainderror =
PRE
  ISAI_STATE = ISAI_tbcr15b
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_Error_report;
  ISAI_sarg1 := 0;
  ISAI_sarg2 := 0;
  ISAI_sarg4 := 0;
  ISAI_dist := 0;
  ISAI_DELTA := 0;
  //
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// --    Case 3
// -- *  The seqnum is OLD or (the seqnum is ACCEPTABLE and the ecnum is VALID): 
// --   In this case the SAI sends a SAI_ERROR.report to the CSL component and discards 
// --   the Sa_DATA.indication message
// -------------------------------------------------------------------
R15c_ISAI_datainvalid_or_old =
PRE
 ( (ISAI_dist < 1) or ((ISAI_dist <= ISAI_N) & (ISAI_DELTA >= ISAI_K))) &
  ISAI_STATE = ISAI_tbcr15
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_Error_report;
  ISAI_sarg1 := 0;
  ISAI_sarg2 := 0;
  ISAI_sarg4 := 0;
  ISAI_dist := 0;
  ISAI_DELTA := 0;
  //
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// --    Case 4
// -- *  The seqnum is NOT_ACCEPTABLE: In this case the SAI component sends a 
// --    Sa_DISCONNECT.request to ER-SL and a SAI_DISCONNECT.indication to the CSL component,
// --    and then moves to Disconnected state
// -------------------------------------------------------------------
R15d_ISAI_abortconn =
PRE
 ( ISAI_dist > ISAI_N) &
  ISAI_STATE = ISAI_tbcr15
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Disconnect_request;
  //
  ISAI_STATE := ISAI_tbcr15d
END;

R15d_ISAI_notifyfatal =
PRE
  ISAI_STATE = ISAI_tbcr15d
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_DISCONNECT_indication;
  ISAI_ack_responseTimer := 0;
  ISAI_sarg1 := 0;
  ISAI_sarg2 := 0;
  ISAI_sarg4 := 0;
  ISAI_next_out := 0;
  ISAI_dist := 0;
  ISAI_DELTA := 0;
  ISAI_outdatabuff := [];
  ISAI_ack_request := 0;
  ISAI_waitnextcycle := FALSE;
  //
  ISAI_STATE := ISAI_Disconnected
END;

RD1a_ISAI_datadiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DATA_request & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Disconnected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Disconnected
END;

RD1b_ISAI_connconfdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Connect_confirm & 
  ISAI_STATE = ISAI_Disconnected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

RD1c_ISAI_discinddiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Disconnect_indication & 
  ISAI_STATE = ISAI_Disconnected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

RD1d_ISAI_datainddiscard(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Data_indication & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  arg3 = first(tail(tail(ISAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(ISAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(ISAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(ISAI_eventsdatabuff)))))) &
  ISAI_STATE = ISAI_Disconnected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(ISAI_eventsdatabuff))))));
  ISAI_STATE := ISAI_Disconnected
END;

RD1e_ISAI_disconndiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Execution_Cycle_Start & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Disconnected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Disconnected
END;

RD2a_ISAI_datainddiscard(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Data_indication & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  arg3 = first(tail(tail(ISAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(ISAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(ISAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(ISAI_eventsdatabuff)))))) &
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(ISAI_eventsdatabuff))))));
  ISAI_STATE := ISAI_Connecting
END;

RD2b_ISAI_datareqdiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DATA_request & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connecting
END;

RD2c_ISAI_connreqdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_CONNECT_request & 
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connecting
END;

RD2d_ISAI_ecsdiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Execution_Cycle_Start & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Connecting
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connecting
END;

RD3a_ISAI_datainddiscard(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Data_indication & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  arg3 = first(tail(tail(ISAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(ISAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(ISAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(ISAI_eventsdatabuff)))))) &
  ISAI_STATE = ISAI_Initializing
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(ISAI_eventsdatabuff))))));
  ISAI_STATE := ISAI_Initializing
END;

RD3b_ISAI_datareqdiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_DATA_request & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Initializing
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Initializing
END;

RD3c_ISAI_connconfdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Connect_confirm & 
  ISAI_STATE = ISAI_Initializing
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Initializing
END;

RD4a_ISAI_connconfdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Connect_confirm & 
  ISAI_STATE = ISAI_Connected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connected
END;

RD4b_ISAI_connreqdiscard =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_CONNECT_request & 
  ISAI_STATE = ISAI_Connected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connected
END;

RD4c_ISAI_ecsdiscard(arg1,arg2) =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = ISAI_SA_Execution_Cycle_Start & 
  arg1 = first(ISAI_eventsdatabuff) &
  arg2 = first(tail(ISAI_eventsdatabuff)) &
  ISAI_STATE = ISAI_Connected
THEN
  skip;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_eventsdatabuff := tail(tail(ISAI_eventsdatabuff));
  ISAI_STATE := ISAI_Connected
END;

// -------------------------------------------------------------------
// --  Each time that in Connected state the set_ack_response expires,
// --  the SAI sends a SAI_ERROR.report to the CSL component
// --  (for further details see REQ_ACKs)
// -------------------------------------------------------------------
RTc_ISAI_okisai =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = isai_tick & 
  ISAI_STATE = ISAI_Connected
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_isai;
  IF ISAI_ack_responseTimer < ISAI_max_ack_responseTimer  THEN
    ISAI_ack_responseTimer := ISAI_ack_responseTimer + 1
  ELSE
    skip
  END;
  IF ISAI_ack_requestTimer < ISAI_max_ack_requestTimer  THEN
    ISAI_ack_requestTimer := ISAI_ack_requestTimer + 1
  ELSE
    skip
  END;
  IF (ISAI_ack_requestTimer = ISAI_max_ack_requestTimer) & (ISAI_ack_responseTimer >= ISAI_max_ack_responseTimer)  THEN
    ISAI_ack_request := 1
  ELSE
    skip
  END;
  ISAI_currentEC := (ISAI_currentEC + 1) mod ISAI_Mec;
  ISAI_waitnextcycle := FALSE;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_tbcrta
END;

RACK2_ISAI_ackresponserror =
PRE
 ( ISAI_ack_responseTimer = ISAI_max_ack_responseTimer) &
  ISAI_STATE = ISAI_tbcrta
THEN
  ICSL_eventsfifobuff := ICSL_eventsfifobuff <- ISAI_Error_report;
  ISAI_ack_responseTimer := ISAI_max_ack_responseTimer + 1;
  //
  ISAI_STATE := ISAI_tbcrack
END;

ROUTDATABUFF_ISAI_sendbuffered =
PRE
 ( ISAI_outdatabuff /= []) &
  ISAI_STATE = ISAI_tbcrack
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- ISAI_SA_Data_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- first(ISAI_outdatabuff);
  EUR_eventsdatabuff := EUR_eventsdatabuff <- first(tail(ISAI_outdatabuff));
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_ack_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_ack_reply;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- ISAI_currentEC;
  ISAI_outdatabuff := tail(tail(ISAI_outdatabuff));
  ISAI_waitnextcycle := TRUE;
  ISAI_next_out := (ISAI_next_out + 1) mod ISAI_M;
  IF ISAI_ack_request = 1  THEN
    ISAI_ack_request := 0;
    ISAI_ack_requestTimer := 0;
    ISAI_ack_responseTimer := 0
  ELSE
    skip
  END;
  ISAI_ack_reply := 0;
  //
  ISAI_STATE := ISAI_Connected
END;

RTd_ISAI_continue =
PRE
 ( ISAI_ack_responseTimer /= ISAI_max_ack_responseTimer) &
  ISAI_STATE = ISAI_tbcrta
THEN
  skip;
  //
  ISAI_STATE := ISAI_tbcrack
END;

RTe_ISAI_okisai =
PRE
 ( ISAI_outdatabuff = []) &
  ISAI_STATE = ISAI_tbcrack
THEN
  skip;
  //
  ISAI_STATE := ISAI_Connected
END;

// ------------------------
// -- clock cycles handling 
// ------------------------
RTf_ISAI_okisai =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = isai_tick & 
  ISAI_STATE = ISAI_Disconnected
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_isai;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Disconnected
END;

RTg_ISAI_okisai =
PRE
  ISAI_eventsfifobuff /= [] & 
  first(ISAI_eventsfifobuff) = isai_tick & 
  ISAI_STATE = ISAI_Connecting
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_isai;
  //
  ISAI_eventsfifobuff := tail(ISAI_eventsfifobuff);
  ISAI_STATE := ISAI_Connecting
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine EUR
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// --------------------------
// -- handle time slots
// --------------------------
R1_EUR_okier =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = EUR_tick & 
  EUR_STATE = EUR_s0
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_eur;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_STATE := EUR_s0
END;

// --------------------------
// -- handle inoming ISAI requests
// --------------------------
R2i_EUR_newconnection =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = ISAI_SA_Connect_request & 
  EUR_STATE = EUR_s0
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_SA_Connect_indication;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_STATE := EUR_s0
END;

R3i_EUR_disconnection =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = ISAI_SA_Disconnect_request & 
  EUR_STATE = EUR_s0
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_SA_Disconnect_indication;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_STATE := EUR_s0
END;

R4i_EUR_acceptdata(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = ISAI_SA_Data_request & 
  arg1 = first(EUR_eventsdatabuff) &
  arg2 = first(tail(EUR_eventsdatabuff)) &
  arg3 = first(tail(tail(EUR_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(EUR_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(EUR_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(EUR_eventsdatabuff)))))) &
  EUR_STATE = EUR_s0
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_SA_Data_indication;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg1;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg2;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg3;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg4;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg5;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg6;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_eventsdatabuff := tail(tail(tail(tail(tail(tail(EUR_eventsdatabuff))))));
  EUR_STATE := EUR_s0
END;

// --R5i_EUR_losedata:
// --s0 -> s0 
// --{ ISAI_SA_Data_request(arg1,arg2,arg3,arg4,arg5,arg6) }
// --------------------------------
// -- handle incoming CSAI requests
// --------------------------------
// -- 
R2c_EUR_confirm =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = CSAI_SA_Connect_response & 
  EUR_STATE = EUR_s0
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_SA_Connect_confirm;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_STATE := EUR_s0
END;

// -- 
R3c_EUR_disconnection =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = CSAI_SA_Disconnect_request & 
  EUR_STATE = EUR_s0
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_SA_Disconnect_indication;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_STATE := EUR_s0
END;

// --
R4c_EUR_acceptdata(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = CSAI_SA_Data_request & 
  arg1 = first(EUR_eventsdatabuff) &
  arg2 = first(tail(EUR_eventsdatabuff)) &
  arg3 = first(tail(tail(EUR_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(EUR_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(EUR_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(EUR_eventsdatabuff)))))) &
  EUR_STATE = EUR_s0
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_SA_Data_indication;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg1;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg2;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg3;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg4;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg5;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg6;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_eventsdatabuff := tail(tail(tail(tail(tail(tail(EUR_eventsdatabuff))))));
  EUR_STATE := EUR_s0
END;

// -- R5c_EUR_losedata:
// -- s0 -> s0 
// --{ CSAI_SA_Data_request(arg1,arg2,arg3,arg4,arg5,arg6) }
// -- when ISAI responding with execution cycle start 
R6a_EUR_execcycstart_call(arg1,arg2) =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = ISAI_SA_Execution_Cycle & 
  arg1 = first(EUR_eventsdatabuff) &
  arg2 = first(tail(EUR_eventsdatabuff)) &
  EUR_STATE = EUR_s0
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_SA_Execution_Cycle_Start;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg1;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg2;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_eventsdatabuff := tail(tail(EUR_eventsdatabuff));
  EUR_STATE := EUR_s0
END;

// -- when CSAI performing execution cycle start 
R6b_EUR_execcycstart_response(arg1,arg2) =
PRE
  EUR_eventsfifobuff /= [] & 
  first(EUR_eventsfifobuff) = CSAI_SA_Execution_Cycle & 
  arg1 = first(EUR_eventsdatabuff) &
  arg2 = first(tail(EUR_eventsdatabuff)) &
  EUR_STATE = EUR_s0
THEN
  ISAI_eventsfifobuff := ISAI_eventsfifobuff <- ISAI_SA_Execution_Cycle_Start;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg1;
  ISAI_eventsdatabuff := ISAI_eventsdatabuff <- arg2;
  //
  EUR_eventsfifobuff := tail(EUR_eventsfifobuff);
  EUR_eventsdatabuff := tail(tail(EUR_eventsdatabuff));
  EUR_STATE := EUR_s0
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine CSAI
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// -------------------------------------------------------------------
// -- R2: When in Disconnected state is received a Sa_CONNECT.indication from
// --     the ER-SL, the SAI replies with a Sa_CONNECT.response to the ER-SL
// --     and moves to Connecting state
// -------------------------------------------------------------------
R2_CSAI_connreq =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Connect_indication & 
  CSAI_STATE = CSAI_Disconnected
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Connect_response;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Connecting
END;

// -------------------------------------------------------------------
// -- R3: When in Connecting state is received a Sa_DISCONNECT.indication from
// --     the ER-SL, the SAI moves to Disconnected state
// -------------------------------------------------------------------
R3_CSAI_abortconn =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Disconnect_indication & 
  CSAI_STATE = CSAI_Connecting
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R4: When in Connecting state is received a SAI_DISCONNECT.request from the
// --     CSL component, the message is discarded (it should never happen).
// -------------------------------------------------------------------
R4_CSAI_CSLdisconnind =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DISCONNECT_request & 
  CSAI_STATE = CSAI_Connecting
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Connecting
END;

// -------------------------------------------------------------------
// -- R2b: When in Connecting state is received a SAI_SA_Connect.request from the
// --     ER sublayer, the connection process is restarted.
// -------------------------------------------------------------------
R2b_CSAI_restartconnect =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Connect_indication & 
  CSAI_STATE = CSAI_Connecting
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Connect_response;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Connecting
END;

// -------------------------------------------------------------------
// -- R5: When in Connecting state is received a Sa_ExecutionCycleStart(seqnum, ecnum)
// --     from the ER-SL, the SAI replies with a Sa_ExecutionCycle(seqnum, ecnum) to the
// --     ER-SL, starts an initTimer set to the maximum initialization delay, and moves 
// --     to Initializing state. For the management of the Sa_ExecutionCycleStart
// --     parameters see the following Sequence Numbers Management and Execution Cycle
// --     Counters Management sections
// -------------------------------------------------------------------
R5_CSAI_confinitproc(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Execution_Cycle_Start & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Connecting
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Execution_Cycle;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_currentEC;
  CSAI_OFFSET := CSAI_currentEC - arg2;
  CSAI_initTimer := 0;
  CSAI_last_in := arg1;
  CSAI_next_out := (CSAI_next_out + 1) mod CSAI_M;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Initializing
END;

// -------------------------------------------------------------------
// -- R6: When in Initializing state the maximum initialization delay expires, the SAI 
// --     sends a SAI_ERROR.report to the CSL component, Sa_Disconnect_request to ER,
// --     and moves to Disconnected state
// -------------------------------------------------------------------
RTa_CSAI_confinitprocwait =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = csai_tick & 
  CSAI_STATE = CSAI_Initializing
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_csai;
  CSAI_initTimer := CSAI_initTimer + 1;
  CSAI_currentEC := (CSAI_currentEC + 1) mod CSAI_Mec;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_tbcrta
END;

R6_CSAI_confinitfail =
PRE
 ( CSAI_initTimer = CSAI_max_initTimer) &
  CSAI_STATE = CSAI_tbcrta
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Disconnect_request;
  //
  CSAI_STATE := CSAI_tbcr6
END;

R6_CSAI_confinitprocwait =
PRE
  CSAI_STATE = CSAI_tbcr6
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_STATE := CSAI_Disconnected
END;

// -- when initializing wait first data
RTb_CSAI_waitdata =
PRE
 ( CSAI_initTimer < CSAI_max_initTimer) &
  CSAI_STATE = CSAI_tbcrta
THEN
  skip;
  //
  CSAI_STATE := CSAI_Initializing
END;

// -------------------------------------------------------------------
// -- R2c: When in Connecting state is received a SAI_SA_Connect.request from the
// --     ER sublayer, the connection process is restarted.
// -------------------------------------------------------------------
R2c_CSAI_restartconnect =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Connect_indication & 
  CSAI_STATE = CSAI_Initializing
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Connect_response;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Connecting
END;

// -------------------------------------------------------------------
// -- R7: When in Initializing state is received a SAI_DISCONNECT.request from the CSL 
// --     component, the message is discarded (it should never happen)
// -------------------------------------------------------------------
R7_CSAI_CSLdisconnind =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DISCONNECT_request & 
  CSAI_STATE = CSAI_Initializing
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Initializing
END;

// -------------------------------------------------------------------
// -- R8: When in Initializing state is received a Sa_DISCONNECT.indication from the ER-SL,
// --     the SAI  moves to the Disconnected state
// -------------------------------------------------------------------
R8_CSAI_abortconn =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Disconnect_indication & 
  CSAI_STATE = CSAI_Initializing
THEN
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R9: When in Initializing state is received a Sa_DATA.indication
// --     from the ER-SL may have four cases, depending on the received seqnum 
// --    and ecnum values (see REQ SEQ_NUMs and REC_ECNUMs): *
// -------------------------------------------------------------------
R9_CSAI_confinitproc(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Data_indication & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  arg3 = first(tail(tail(CSAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(CSAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(CSAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(CSAI_eventsdatabuff)))))) &
  CSAI_STATE = CSAI_Initializing
THEN
  CSAI_dist := arg5 - CSAI_last_in;
  IF CSAI_dist < 0 - (CSAI_M) / 2  THEN
    CSAI_dist := CSAI_dist + CSAI_M
  ELSE
    skip
  END;
  IF CSAI_dist > (CSAI_M) / 2  THEN
    CSAI_dist := CSAI_dist - CSAI_M
  ELSE
    skip
  END;
  IF (CSAI_dist > 0) & (CSAI_dist <= CSAI_N)  THEN
    CSAI_last_in := arg5
  ELSE
    skip
  END;
  CSAI_sarg1 := arg1;
  CSAI_sarg2 := arg2;
  CSAI_sarg3 := arg3;
  CSAI_EC_expected := (CSAI_currentEC + CSAI_Mec - CSAI_OFFSET) mod CSAI_Mec;
  CSAI_DELTA := CSAI_EC_expected - arg6;
  IF CSAI_DELTA < 0 - (CSAI_Mec) / 2  THEN
    CSAI_DELTA := CSAI_DELTA + CSAI_Mec
  ELSE
    skip
  END;
  IF CSAI_DELTA > (CSAI_Mec) / 2  THEN
    CSAI_DELTA := CSAI_DELTA - CSAI_Mec
  ELSE
    skip
  END;
  CSAI_EC_expected := 0;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(CSAI_eventsdatabuff))))));
  CSAI_STATE := CSAI_tbcr9
END;

// -------------------------------------------------------------------
// --    Case 1
// --  The seqnum is the one EXPECTED and ecnum is VALID : In this case the SAI moves 
// --   to Connected state and sends both a SAI_CONNECT.indication and a 
// --   SAI_DATA.indication(msgtype, data) to the CSL component
// -------------------------------------------------------------------
R9a_CSAI_connecting =
PRE
 ( (CSAI_dist = 1) & (CSAI_DELTA < CSAI_K)) &
  CSAI_STATE = CSAI_tbcr9
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_CONNECT_indication;
  CSAI_ack_reply := CSAI_sarg3;
  CSAI_sarg3 := 0;
  CSAI_initTimer := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_tbcr9a
END;

R9a_CSAI_forwarding =
PRE
  CSAI_STATE = CSAI_tbcr9a
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DATA_indication;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg1;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg2;
  CSAI_ack_requestTimer := 0;
  CSAI_ack_responseTimer := CSAI_max_ack_responseTimer + 1;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  //
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --   Case 2
// -- The seqnum is ACCEPTABLE and the ecnum is VALID: in this case the SAI moves to 
// --  Connected state and sends a SAI_CONNECT.indication, a SAI_DATA.indication
// --   and a SAI_ERROR.report to the CSL component
// -------------------------------------------------------------------
R9b_CSAI_connecting =
PRE
 ( (CSAI_dist > 1) & ((CSAI_dist <= CSAI_N) & (CSAI_DELTA < CSAI_K))) &
  CSAI_STATE = CSAI_tbcr9
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_CONNECT_indication;
  CSAI_ack_reply := CSAI_sarg3;
  CSAI_sarg3 := 0;
  CSAI_initTimer := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_tbcr9b
END;

R9b_CSAI_forwarding =
PRE
  CSAI_STATE = CSAI_tbcr9b
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DATA_indication;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg1;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg2;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  //
  CSAI_STATE := CSAI_tbcr9ba
END;

R9b_CSAI_reportingding =
PRE
  CSAI_STATE = CSAI_tbcr9ba
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_ack_requestTimer := 0;
  CSAI_ack_responseTimer := CSAI_max_ack_responseTimer + 1;
  //
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --   Case 3
// -- The seqnum is OLD or (the seqnum is ACCEPTABLE and the ecnum is VALID): 
// --  In this case the SAI sends a SAI_ERROR.report to the CSL component and discards 
// --  the Sa_DATA.indication message
// -------------------------------------------------------------------
R9c_CSAI_discarding =
PRE
 ( (CSAI_dist < 1) or ((CSAI_dist <= CSAI_N) & (CSAI_DELTA >= CSAI_K))) &
  CSAI_STATE = CSAI_tbcr9
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg3 := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_Initializing
END;

// -------------------------------------------------------------------
// --   Case 4
// -- * The seqnum is NOT_ACCEPTABLE: in this case the SAI component sends a 
// --   Sa_DISCONNECT.request  to ER-SL and  moves to Disconnected state
// -------------------------------------------------------------------
R9d_CSAI_disconnecting =
PRE
 ( CSAI_dist > CSAI_N) &
  CSAI_STATE = CSAI_tbcr9
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Disconnect_request;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg3 := 0;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_STATE := CSAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R10: When in Connected state is received a SAI_DISCONNECT.request from the CSL 
// --   component, the SAI replies with   a SAI_DISCONNECT.indication to the CSL component, 
// --   sends a Sa_DISCONNECT.request to the ER-SL, and movesto Disconnected state
// -------------------------------------------------------------------
R10_CSAI_CSLdisconnind =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DISCONNECT_request & 
  CSAI_STATE = CSAI_Connected
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DISCONNECT_indication;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_tbcr10
END;

R10_CSAI_CSLdisconnreq =
PRE
  CSAI_STATE = CSAI_tbcr10
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Disconnect_request;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_STATE := CSAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R11: When in Connected state is received a Sa_DISCONNECT.indication from the ER-SL, 
// --  the SAI sends a SAI_DISCONNECT.indication to the CSL component and moves 
// --  to Disconnected state
// -------------------------------------------------------------------
R11_CSAI_abortconn =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Disconnect_indication & 
  CSAI_STATE = CSAI_Connected
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DISCONNECT_indication;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_dist := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

// -------------------------------------------------------------------
// -- R12: When in Connected state is received a Sa_CONNECT.indication from the ER-SL, 
// --  the SAI replies with a Sa_CONNECT.response to the ER-SL, sends a 
// --  SAI_DISCONNECT.indication to the CSL component, and moves to Connecting state
// -------------------------------------------------------------------
R12_CSAI_connconfresp =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Connect_indication & 
  CSAI_STATE = CSAI_Connected
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Connect_response;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_tbcr12
END;

R12_CSAI_connconfdiscard =
PRE
  CSAI_STATE = CSAI_tbcr12
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DISCONNECT_indication;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_dist := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_STATE := CSAI_Connecting
END;

// -------------------------------------------------------------------
// -- R13a: When in Connected state is received a SAI_DATA_request(msgtype, data) from 
// --  the CSL component, and yet no other data message has been sent in this cycle, 
// --  the SAI sends a Sa_DATA.request(msgtype, data, ackreq, ackresp, seqnum, ecnum) 
// --  to the ER-SL. The ackreq  and  ackresp parameters are set  according to REQ_ACKs. 
// --  The seqnum parameter is set according to SEQ_NUMs and the ecnum parameter is set 
// -- according to REQ_ECNUMs
// -------------------------------------------------------------------
R13a_CSAI_datareqforward(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DATA_request & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
 ( CSAI_waitnextcycle = FALSE) &
  CSAI_STATE = CSAI_Connected
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Data_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- arg1;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- arg2;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- 1;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_ack_reply;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_currentEC;
  CSAI_waitnextcycle := TRUE;
  CSAI_next_out := (CSAI_next_out + 1) mod CSAI_M;
  IF CSAI_ack_request = 1  THEN
    CSAI_ack_request := 0;
    CSAI_ack_requestTimer := 0;
    CSAI_ack_responseTimer := 0
  ELSE
    skip
  END;
  CSAI_ack_reply := 0;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// -- R13b: When in Connected state is received a SAI_DATA.request(msgtype, data) from 
// -- the CSL component, but another data message has already been sent in this cycle, 
// -- the SAI_DATA.request is  saved in a FIFO dataout buffer (see also REQ_OUTDATABUFF)
// -------------------------------------------------------------------
R13b_CSAI_datareqstore(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DATA_request & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
 ( CSAI_waitnextcycle = TRUE) &
  CSAI_STATE = CSAI_Connected
THEN
  CSAI_outdatabuff := CSAI_outdatabuff ^ [arg1,arg2];
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// -- R14: When in Connected state is received a Sa_DATA.indication from the ER-SL we can
// --  have four cases, depending on the received seqnum and ecnum values
// --      (see SEQ_NUMs and REC_ECNUMs):
// -------------------------------------------------------------------
R14_CSAI_datareceive(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Data_indication & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  arg3 = first(tail(tail(CSAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(CSAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(CSAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(CSAI_eventsdatabuff)))))) &
  CSAI_STATE = CSAI_Connected
THEN
  CSAI_dist := arg5 - CSAI_last_in;
  IF CSAI_dist < 0 - (CSAI_M) / 2  THEN
    CSAI_dist := CSAI_dist + CSAI_M
  ELSE
    skip
  END;
  IF CSAI_dist > (CSAI_M) / 2  THEN
    CSAI_dist := CSAI_dist - CSAI_M
  ELSE
    skip
  END;
  IF (CSAI_dist > 0) & (CSAI_dist <= CSAI_N)  THEN
    CSAI_last_in := arg5
  ELSE
    skip
  END;
  CSAI_sarg1 := arg1;
  CSAI_sarg2 := arg2;
  CSAI_ack_reply := CSAI_ack_reply + arg3 - (CSAI_ack_reply) * arg3;
  CSAI_sarg4 := arg4;
  CSAI_EC_expected := (CSAI_currentEC + CSAI_Mec - CSAI_OFFSET) mod CSAI_Mec;
  CSAI_DELTA := CSAI_EC_expected - arg6;
  IF CSAI_DELTA < 0 - (CSAI_Mec) / 2  THEN
    CSAI_DELTA := CSAI_DELTA + CSAI_Mec
  ELSE
    skip
  END;
  IF CSAI_DELTA > (CSAI_Mec) / 2  THEN
    CSAI_DELTA := CSAI_DELTA - CSAI_Mec
  ELSE
    skip
  END;
  CSAI_EC_expected := 0;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(CSAI_eventsdatabuff))))));
  CSAI_STATE := CSAI_tbcr14
END;

// -------------------------------------------------------------------
// --   Case 1
// -- * The seqnum is the one EXPECTED and ecnum is VALID: In this case the SAI sends a 
// --   SAI_DATA.indication(msgtype, data) to the CSL component.
// --   Depending on the received values of the ackreq and ackresp parameters, 
// --  appropriate actions are performed (see REQ_ACKs)
// -------------------------------------------------------------------
R14a_CSAI_dataindforward =
PRE
 ( (CSAI_dist = 1) & (CSAI_DELTA < CSAI_K)) &
  CSAI_STATE = CSAI_tbcr14
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DATA_indication;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg1;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg2;
  IF (CSAI_sarg4 = 1) & (CSAI_ack_responseTimer < CSAI_max_ack_responseTimer)  THEN
    CSAI_ack_responseTimer := CSAI_max_ack_responseTimer + 1
  ELSE
    skip
  END;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg4 := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --   Case 2
// -- * The seqnum is ACCEPTABLE and the ecnum is VALID: in this case the SAI sends 
// -- a SAI_DATA.indication(msgtype, data) and a SAI_ERROR.report to the CSL component.
// --   Depending on the received values of the ackreq and ackresp parameters, 
// --  appropriate actions are performed (see REQ_ACKs)
// -------------------------------------------------------------------
R14b_CSAI_dataindforward =
PRE
 ( (CSAI_dist > 1) & ((CSAI_dist <= CSAI_N) & (CSAI_DELTA < CSAI_K))) &
  CSAI_STATE = CSAI_tbcr14
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DATA_indication;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg1;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- CSAI_sarg2;
  IF (CSAI_sarg4 = 1) & (CSAI_ack_responseTimer < CSAI_max_ack_responseTimer)  THEN
    CSAI_ack_responseTimer := CSAI_max_ack_responseTimer + 1
  ELSE
    skip
  END;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg4 := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_tbcr14b
END;

R14b_CSAI_dataindreport =
PRE
  CSAI_STATE = CSAI_tbcr14b
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg4 := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --   Case 3
// -- * The seqnum is OLD or (the seqnum is ACCEPTABLE and the ecnum is VALID): 
// -- In this case the SAI sends a SAI_ERROR.report to the CSL component and discards 
// --  he Sa_DATA.indication message
// -------------------------------------------------------------------
R14c_CSAI_datainvalid_or_old =
PRE
 ( (CSAI_dist < 1) or ((CSAI_dist <= CSAI_N) & (CSAI_DELTA >= CSAI_K))) &
  CSAI_STATE = CSAI_tbcr14
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg4 := 0;
  CSAI_dist := 0;
  CSAI_DELTA := 0;
  //
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --   Case 4
// -- * The seqnum is NOT_ACCEPTABLE: In this case the SAI component sends a 
// -- Sa_DISCONNECT.request to ER-SL, a SAI_DISCONNECT.indication to the CSL component, 
// -- and then moves to Disconnected state
// -------------------------------------------------------------------
R14d_CSAI_abortconn =
PRE
 ( CSAI_dist > CSAI_N) &
  CSAI_STATE = CSAI_tbcr14
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Disconnect_request;
  //
  CSAI_STATE := CSAI_tbcr14d
END;

R14d_CSAI_notifydisconn =
PRE
  CSAI_STATE = CSAI_tbcr14d
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_DISCONNECT_indication;
  CSAI_sarg1 := 0;
  CSAI_sarg2 := 0;
  CSAI_sarg4 := 0;
  CSAI_ack_requestTimer := CSAI_max_ack_requestTimer;
  CSAI_ack_responseTimer := 0;
  CSAI_ack_reply := 0;
  CSAI_ack_request := 0;
  CSAI_currentEC := 0;
  CSAI_initTimer := 0;
  CSAI_OFFSET := 0;
  CSAI_DELTA := 0;
  CSAI_last_in := 0;
  CSAI_next_out := 0;
  CSAI_dist := 0;
  CSAI_outdatabuff := [];
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_STATE := CSAI_Disconnected
END;

RD1a_CSAI_disconndiscard =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DISCONNECT_request & 
  CSAI_STATE = CSAI_Disconnected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

RD1b_CSAI_datadiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DATA_request & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Disconnected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Disconnected
END;

RD1c_CSAI_discinddiscard =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Disconnect_indication & 
  CSAI_STATE = CSAI_Disconnected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

RD1d_CSAI_datainddiscard(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Data_indication & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  arg3 = first(tail(tail(CSAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(CSAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(CSAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(CSAI_eventsdatabuff)))))) &
  CSAI_STATE = CSAI_Disconnected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(CSAI_eventsdatabuff))))));
  CSAI_STATE := CSAI_Disconnected
END;

RD1e_CSAI_disconndiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Execution_Cycle_Start & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Disconnected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Disconnected
END;

RD2a_CSAI_datainddiscard(arg1,arg2,arg3,arg4,arg5,arg6) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Data_indication & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  arg3 = first(tail(tail(CSAI_eventsdatabuff))) &
  arg4 = first(tail(tail(tail(CSAI_eventsdatabuff)))) &
  arg5 = first(tail(tail(tail(tail(CSAI_eventsdatabuff))))) &
  arg6 = first(tail(tail(tail(tail(tail(CSAI_eventsdatabuff)))))) &
  CSAI_STATE = CSAI_Connecting
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(tail(tail(tail(tail(CSAI_eventsdatabuff))))));
  CSAI_STATE := CSAI_Connecting
END;

RD2b_CSAI_datareqdiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DATA_request & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Connecting
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Connecting
END;

RD3a_CSAI_datareqdiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_DATA_request & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Initializing
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Initializing
END;

RD3c_CSAI_execycstardiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Execution_Cycle_Start & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Initializing
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Initializing
END;

RD4a_CSAI_ecsdiscard(arg1,arg2) =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = CSAI_SA_Execution_Cycle_Start & 
  arg1 = first(CSAI_eventsdatabuff) &
  arg2 = first(tail(CSAI_eventsdatabuff)) &
  CSAI_STATE = CSAI_Connected
THEN
  skip;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_eventsdatabuff := tail(tail(CSAI_eventsdatabuff));
  CSAI_STATE := CSAI_Connected
END;

// -------------------------------------------------------------------
// --  Each time that in Connected state the set_ack_response expires,
// --  the SAI sends a SAI_ERROR.report to the CSL component
// --  (for further details see REQ_ACKs)
// -------------------------------------------------------------------
RTc_CSAI_okcsai =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = csai_tick & 
  CSAI_STATE = CSAI_Connected
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_csai;
  IF CSAI_ack_responseTimer < CSAI_max_ack_responseTimer  THEN
    CSAI_ack_responseTimer := CSAI_ack_responseTimer + 1
  ELSE
    skip
  END;
  IF CSAI_ack_requestTimer < CSAI_max_ack_requestTimer  THEN
    CSAI_ack_requestTimer := CSAI_ack_requestTimer + 1
  ELSE
    skip
  END;
  IF (CSAI_ack_requestTimer = CSAI_max_ack_requestTimer) & (CSAI_ack_responseTimer >= CSAI_max_ack_responseTimer)  THEN
    CSAI_ack_request := 1
  ELSE
    skip
  END;
  CSAI_currentEC := (CSAI_currentEC + 1) mod CSAI_Mec;
  CSAI_waitnextcycle := FALSE;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_tbcrtc
END;

RACK2_CSAI_ackresponserror =
PRE
 ( CSAI_ack_responseTimer = CSAI_max_ack_responseTimer) &
  CSAI_STATE = CSAI_tbcrtc
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CSAI_Error_report;
  CSAI_ack_responseTimer := CSAI_max_ack_responseTimer + 1;
  //
  CSAI_STATE := CSAI_tbcrack
END;

ROUTDATABUFF_CSAI_sendbuffered =
PRE
 ( CSAI_outdatabuff /= []) &
  CSAI_STATE = CSAI_tbcrack
THEN
  EUR_eventsfifobuff := EUR_eventsfifobuff <- CSAI_SA_Data_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- first(CSAI_outdatabuff);
  EUR_eventsdatabuff := EUR_eventsdatabuff <- first(tail(CSAI_outdatabuff));
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_ack_request;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_ack_reply;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_next_out;
  EUR_eventsdatabuff := EUR_eventsdatabuff <- CSAI_currentEC;
  CSAI_outdatabuff := tail(tail(CSAI_outdatabuff));
  CSAI_waitnextcycle := TRUE;
  CSAI_next_out := (CSAI_next_out + 1) mod CSAI_M;
  IF CSAI_ack_request = 1  THEN
    CSAI_ack_request := 0;
    CSAI_ack_requestTimer := 0;
    CSAI_ack_responseTimer := 0
  ELSE
    skip
  END;
  CSAI_ack_reply := 0;
  //
  CSAI_STATE := CSAI_Connected
END;

RTd_CSAI_continue =
PRE
 ( CSAI_ack_responseTimer /= CSAI_max_ack_responseTimer) &
  CSAI_STATE = CSAI_tbcrtc
THEN
  skip;
  //
  CSAI_STATE := CSAI_tbcrack
END;

RTe_CSAI_okisai =
PRE
 ( CSAI_outdatabuff = []) &
  CSAI_STATE = CSAI_tbcrack
THEN
  skip;
  //
  CSAI_STATE := CSAI_Connected
END;

// ------------------------
// -- clock cycles handling 
// ------------------------
RTf_CSAI_okcsai =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = csai_tick & 
  CSAI_STATE = CSAI_Disconnected
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_csai;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Disconnected
END;

RTg_CSAI_okcsai =
PRE
  CSAI_eventsfifobuff /= [] & 
  first(CSAI_eventsfifobuff) = csai_tick & 
  CSAI_STATE = CSAI_Connecting
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_csai;
  //
  CSAI_eventsfifobuff := tail(CSAI_eventsfifobuff);
  CSAI_STATE := CSAI_Connecting
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine CCSL
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// -------------------------------------------------------------------
// -- R2: When in Disconnected state is received a SAI_CONNECT.indication
// --     from the SAI component, the CSL sends a RBC_User_Connect_indication
// --     to the RBC component, starts both the sendTimer and the recTimer, 
// --     and moves to Connected state
// -------------------------------------------------------------------
R2_CCSL_userconnind =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_CONNECT_indication & 
  CCSL_STATE = CCSL_NOCOMMS
THEN
  CRBC_eventsfifobuff := CRBC_eventsfifobuff <- CRBC_User_Connect_indication;
  CCSL_receiveTimer := 0;
  CCSL_sendTimer := CCSL_max_sendTimer;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R3: When in Connected state is received a SAI_CONNECT.indication from 
// --     the SAI component (this is not supposed to occur), the message is discarded.
// -------------------------------------------------------------------
R3_CCSL_userconnind =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_CONNECT_indication & 
  CCSL_STATE = CCSL_COMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R4: When in Connected state is received a RBC_User_Data.request with 
// --     RBC_data from the RBC component, the CSL sends a SAI_DATA.request
// --     with such RBC_data to the SAI component
// -------------------------------------------------------------------
R4_CCSL_saidatareq(arg1) =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CRBC_User_Data_request & 
  arg1 = first(CCSL_eventsdatabuff) &
  CCSL_STATE = CCSL_COMMS
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_DATA_request;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- RBCdata;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- arg1;
  CCSL_sendTimer := 0;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_eventsdatabuff := tail(CCSL_eventsdatabuff);
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R5: Each time that in Connected state the sendTimer expires, the CSL
// --     sends a SAI_DATA.request with a life_sign to the SAI component
// -------------------------------------------------------------------
R5_CCSL_okccsl =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = ccsl_tick & 
 ( (CCSL_receiveTimer < CCSL_max_receiveTimer) & (CCSL_sendTimer = CCSL_max_sendTimer)) &
  CCSL_STATE = CCSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_ccsl;
  CCSL_sendTimer := 0;
  CCSL_receiveTimer := CCSL_receiveTimer + 1;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_tbcr5
END;

R5_CCSL_saidatareq =
PRE
  CCSL_STATE = CCSL_tbcr5
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_DATA_request;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- LifeSign;
  CSAI_eventsdatabuff := CSAI_eventsdatabuff <- 0;
  //
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R6: When in Connected state is received a SAI_DATA.indication with a
// --     life_sign from the SAI component, the CSL restarts the recTimer
// -------------------------------------------------------------------
R6_CCSL_handlelifesign(arg1,arg2) =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_DATA_indication & 
  arg1 = first(CCSL_eventsdatabuff) &
  arg2 = first(tail(CCSL_eventsdatabuff)) &
 ( arg1 = LifeSign) &
  CCSL_STATE = CCSL_COMMS
THEN
  CCSL_receiveTimer := 0;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_eventsdatabuff := tail(tail(CCSL_eventsdatabuff));
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R7: When in Connected state is received a SAI_DATA.indication with 
// --     SAI_data from the SAI component, the CSL sends a 
// --     RBC_User_Data.indication with such SAI_data to the RBC component 
// --     and restarts the recTimer
// -------------------------------------------------------------------
R7_CCSL_userdataind(arg1,arg2) =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_DATA_indication & 
  arg1 = first(CCSL_eventsdatabuff) &
  arg2 = first(tail(CCSL_eventsdatabuff)) &
 ( arg1 /= LifeSign) &
  CCSL_STATE = CCSL_COMMS
THEN
  CRBC_eventsfifobuff := CRBC_eventsfifobuff <- CRBC_User_Data_indication;
  CRBC_eventsdatabuff := CRBC_eventsdatabuff <- arg2;
  CCSL_receiveTimer := 0;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_eventsdatabuff := tail(tail(CCSL_eventsdatabuff));
  CCSL_STATE := CCSL_COMMS
END;

// -------------------------------------------------------------------
// -- R8: When in Connected state is received a SAI_DISCONNECT.indication
// --     from the SAI component, the CSL sends a RBC_User_Disconnect.indication
// --     to the RBC component and moves to Disconnected state
// -------------------------------------------------------------------
R8_CCSL_userdisconnind =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_DISCONNECT_indication & 
  CCSL_STATE = CCSL_COMMS
THEN
  CRBC_eventsfifobuff := CRBC_eventsfifobuff <- CRBC_User_Disconnect_indication;
  CCSL_receiveTimer := 0;
  CCSL_sendTimer := 0;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_NOCOMMS
END;

// -------------------------------------------------------------------
// -- R9: When in Connected state the recTimer expires, the CSL sends a 
// --     SAI_DISCONNECT.request to the SAI component, a RBC_User_Disconnect.indication
// --     to the RBC component and moves to Disconnected state
// -------------------------------------------------------------------
R9_CCSL_okccsl =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = ccsl_tick & 
 ( CCSL_receiveTimer = CCSL_max_receiveTimer) &
  CCSL_STATE = CCSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_ccsl;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_tbcr9
END;

R9_CCSL_saidisconnreq =
PRE
  CCSL_STATE = CCSL_tbcr9
THEN
  CSAI_eventsfifobuff := CSAI_eventsfifobuff <- CSAI_DISCONNECT_request;
  CCSL_receiveTimer := 0;
  CCSL_sendTimer := 0;
  //
  CCSL_STATE := CCSL_tbcr9a
END;

R9_CCSL_userdisconnind =
PRE
  CCSL_STATE = CCSL_tbcr9a
THEN
  CRBC_eventsfifobuff := CRBC_eventsfifobuff <- CRBC_User_Disconnect_indication;
  //
  CCSL_STATE := CCSL_NOCOMMS
END;

// -------------------------------------------------------------------
// -- RD1: When in Disconnected state the CSL does not accept any kind of message except
// --      for SAI_CONNECT.indication from the SAI component
// --
// -- RD2: When in Connected state the CSL discards only SAI_ERROR.report messages from
// --      the SAI component
// -------------------------------------------------------------------
RD1a_CCSL_discuserdata(arg1) =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CRBC_User_Data_request & 
  arg1 = first(CCSL_eventsdatabuff) &
  CCSL_STATE = CCSL_NOCOMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_eventsdatabuff := tail(CCSL_eventsdatabuff);
  CCSL_STATE := CCSL_NOCOMMS
END;

RD1b_CCSL_discdisconnind =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_DISCONNECT_indication & 
  CCSL_STATE = CCSL_NOCOMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_NOCOMMS
END;

RD1c_CCSL_discerrorreport =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_Error_report & 
  CCSL_STATE = CCSL_NOCOMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_NOCOMMS
END;

RD1d_CCSL_discdataind(arg1,arg2) =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_DATA_indication & 
  arg1 = first(CCSL_eventsdatabuff) &
  arg2 = first(tail(CCSL_eventsdatabuff)) &
  CCSL_STATE = CCSL_NOCOMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_eventsdatabuff := tail(tail(CCSL_eventsdatabuff));
  CCSL_STATE := CCSL_NOCOMMS
END;

RD2a_CCSL_usererror =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = CSAI_Error_report & 
  CCSL_STATE = CCSL_COMMS
THEN
  skip;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_COMMS
END;

// ------------------------
// -- clock cycles handling 
// ------------------------
RTa_CCSL_okccsl =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = ccsl_tick & 
  CCSL_STATE = CCSL_NOCOMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_ccsl;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_NOCOMMS
END;

RTb_CCSL_okccsl =
PRE
  CCSL_eventsfifobuff /= [] & 
  first(CCSL_eventsfifobuff) = ccsl_tick & 
 ( (CCSL_receiveTimer < CCSL_max_receiveTimer) & (CCSL_sendTimer < CCSL_max_sendTimer)) &
  CCSL_STATE = CCSL_COMMS
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_ccsl;
  CCSL_sendTimer := CCSL_sendTimer + 1;
  CCSL_receiveTimer := CCSL_receiveTimer + 1;
  //
  CCSL_eventsfifobuff := tail(CCSL_eventsfifobuff);
  CCSL_STATE := CCSL_COMMS
END;

/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 
//      State Machine CRBC
/////////////////////////////////////////////////////////////////// 
/////////////////////////////////////////////////////////////////// 

// -- increment S counter at every time slop
R1_CRBCS_tick =
PRE
  CRBC_eventsfifobuff /= [] & 
  first(CRBC_eventsfifobuff) = crbc_tick & 
  CRBC_STATE = CRBC_wait
THEN
  Timer_eventsfifobuff := Timer_eventsfifobuff <- ok_crbc;
  //
  CRBC_eventsfifobuff := tail(CRBC_eventsfifobuff);
  CRBC_STATE := CRBC_wait
END;

// -- do not handle connect indications
R4_CRBC_discard_CI =
PRE
  CRBC_eventsfifobuff /= [] & 
  first(CRBC_eventsfifobuff) = CRBC_User_Connect_indication & 
  CRBC_STATE = CRBC_wait
THEN
  skip;
  //
  CRBC_eventsfifobuff := tail(CRBC_eventsfifobuff);
  CRBC_STATE := CRBC_wait
END;

// -- do not handle disconnect indications
R5_CRBC_discard_DI =
PRE
  CRBC_eventsfifobuff /= [] & 
  first(CRBC_eventsfifobuff) = CRBC_User_Disconnect_indication & 
  CRBC_STATE = CRBC_wait
THEN
  skip;
  //
  CRBC_eventsfifobuff := tail(CRBC_eventsfifobuff);
  CRBC_STATE := CRBC_wait
END;

// -- do not handle data indications
R6a_CRBC_discard_UD(arg1) =
PRE
  CRBC_eventsfifobuff /= [] & 
  first(CRBC_eventsfifobuff) = CRBC_User_Data_indication & 
  arg1 = first(CRBC_eventsdatabuff) &
  CRBC_STATE = CRBC_wait
THEN
  skip;
  //
  CRBC_eventsfifobuff := tail(CRBC_eventsfifobuff);
  CRBC_eventsdatabuff := tail(CRBC_eventsdatabuff);
  CRBC_STATE := CRBC_wait
END;

// -- never triggered , used just for CADP compatibility.
R7_CRBC_justforsync_DR =
PRE
  CRBC_STATE = CRBC_sending
THEN
  CCSL_eventsfifobuff := CCSL_eventsfifobuff <- CRBC_User_Data_request;
  CCSL_eventsdatabuff := CCSL_eventsdatabuff <- 0;
  //
  CRBC_STATE := CRBC_wait
END


END
