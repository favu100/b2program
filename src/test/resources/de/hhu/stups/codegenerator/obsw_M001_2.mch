/* Dubravka Ilic, Linas Laibinis, Timo Latvala, Elena Troubitsyna, and Kimmo Varpaaniemi. Deployment in the Space Sector. In Industrial Deployment of System Engineering Methods, pages 45–62. Springer, 2013. */
/* Modified version with cardinality of 2 for all deferred sets, and instantiation VALID_TCS = {TC_SET1}*/
MACHINE obsw_M001_2
SETS /* deferred */
  PACKET_START_ADDRESSES_IN_TC_BUFFER;
  PACKET_START_ADDRESSES_IN_TC_POOL;
  PACKET_START_ADDRESSES_IN_TM_BUFFER;
  PACKET_START_ADDRESSES_IN_TM_POOL;
  TC_SET = {TC_SET1,TC_SET2};
  TM_SET
 ; /* enumerated */
  TC_STATUSES={TC_Unchecked,TC_Accepted,TC_Rejected,TC_Waiting_for_Execution,TC_Successfully_Executed,TC_Execution_Failed,TC_Removable};
  TM_STATUSES={TM_Effective,TM_Removable}
CONCRETE_CONSTANTS
  VALID_TCS
ABSTRACT_VARIABLES
  TCstatus,
  TMstatus,
  TCbuffer,
  TCpool,
  TMbuffer,
  TMpool
/* PROMOTED OPERATIONS
  env_Receive_TC,
  Poll_TC,
  Accept_TC,
  Reject_TC,
  Report_TC_Acceptance,
  Skip_TC_Acceptance_Report,
  Report_TC_Rejection,
  Skip_TC_Rejection_Report,
  Execute_TC_Successfully,
  Reset_TM_Buffer,
  Fail_TC_Execution,
  Report_TC_Execution_Success,
  Skip_TC_Success_Report,
  Report_TC_Execution_Failure,
  Skip_TC_Failure_Report,
  Drop_TC,
  Produce_TM,
  Pass_TM,
  Cancel_TM,
  Drop_TM,
  env_Deliver_TM */
PROPERTIES
    card(TC_SET) = 2 &
    card(TM_SET) = 2 &
    card(PACKET_START_ADDRESSES_IN_TM_POOL) = 2 &
    card(PACKET_START_ADDRESSES_IN_TM_BUFFER) = 2 &
    card(PACKET_START_ADDRESSES_IN_TC_POOL) = 2 &
    card(PACKET_START_ADDRESSES_IN_TC_BUFFER) = 2 &
    VALID_TCS = {TC_SET1} &
    /* @axm_invalid_tcs  */ TC_SET \ VALID_TCS /= {}
INVARIANT
    /* @inv_TCstatus  */ TCstatus : PACKET_START_ADDRESSES_IN_TC_POOL +-> TC_STATUSES
  & /* @inv_TCdom  */ dom(TCstatus) = dom(TCpool)
  & /* @inv_valid_tc_status  */ !tc_handler.(tc_handler : dom(TCstatus) & TCstatus(tc_handler) : {TC_Accepted,TC_Waiting_for_Execution,TC_Successfully_Executed,TC_Execution_Failed} => TCpool(tc_handler) : VALID_TCS)
  & /* @inv_TMstatus  */ TMstatus : PACKET_START_ADDRESSES_IN_TM_POOL +-> TM_STATUSES
  & /* @inv_TMdom  */ dom(TMstatus) = dom(TMpool)
  & /* @inv_TCbuffer  */ TCbuffer : PACKET_START_ADDRESSES_IN_TC_BUFFER +-> TC_SET
  & /* @inv_TMbuffer  */ TMbuffer : PACKET_START_ADDRESSES_IN_TM_BUFFER +-> TM_SET
  & /* @inv_TCpool  */ TCpool : PACKET_START_ADDRESSES_IN_TC_POOL +-> TC_SET
  & /* @inv_TMpool  */ TMpool : PACKET_START_ADDRESSES_IN_TM_POOL +-> TM_SET
INITIALISATION
    BEGIN
         TCbuffer := {}
      ||
         TMbuffer := {}
      ||
         TCpool := {}
      ||
         TMpool := {}
      ||
         TCstatus := {}
      ||
         TMstatus := {}
    END
OPERATIONS
  env_Receive_TC(tc,tc_pointer) =
    PRE
        /* @grd_vacant_tc_buffer_address  */ tc_pointer /: dom(TCbuffer) &
        tc_pointer : PACKET_START_ADDRESSES_IN_TC_BUFFER &
        tc : TC_SET
    THEN
         TCbuffer := TCbuffer <+ {tc_pointer |-> tc}
    END;

  Poll_TC(tc_handler,tc_pointer) =
    PRE
        /* @grd_tc_pointer  */ tc_pointer : dom(TCbuffer)
      & /* @grd_vacant_tc_pool_address  */ tc_handler /: dom(TCpool)
      & tc_handler : PACKET_START_ADDRESSES_IN_TC_POOL
    THEN
         TCpool := TCpool <+ {tc_handler |-> TCbuffer(tc_pointer)}
      ||
         TCbuffer := {tc_pointer} <<| TCbuffer
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Unchecked}
    END;

  Accept_TC(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_valid_tc  */ TCpool(tc_handler) : VALID_TCS
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Unchecked
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Accepted}
    END;

  Reject_TC(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Unchecked
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Rejected}
    END;

  Report_TC_Acceptance(tc_handler,tm,tm_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Accepted
      & tm : TM_SET
      & tm_handler : PACKET_START_ADDRESSES_IN_TM_POOL
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Waiting_for_Execution}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    END;

  Skip_TC_Acceptance_Report(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Accepted
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Waiting_for_Execution}
    END;

  Report_TC_Rejection(tc_handler,tm,tm_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Rejected
      & tm : TM_SET
      & tm_handler : PACKET_START_ADDRESSES_IN_TM_POOL
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    END;

  Skip_TC_Rejection_Report(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Rejected
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Execute_TC_Successfully(tc_handler) =
    PRE
        /* @grd_tc_pool  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Successfully_Executed}
    END;

  Reset_TM_Buffer(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TMbuffer := {}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Successfully_Executed}
    END;

  Fail_TC_Execution(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Execution_Failed}
    END;

  Report_TC_Execution_Success(tc_handler,tm,tm_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Successfully_Executed
      & tm : TM_SET
      & tm_handler : PACKET_START_ADDRESSES_IN_TM_POOL
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    END;

  Skip_TC_Success_Report(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Successfully_Executed
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Report_TC_Execution_Failure(tc_handler,tm,tm_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Execution_Failed
      & tm : TM_SET
      & tm_handler : PACKET_START_ADDRESSES_IN_TM_POOL
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    END;

  Skip_TC_Failure_Report(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Execution_Failed
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Drop_TC(tc_handler) =
    PRE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Removable
    THEN
         TCpool := {tc_handler} <<| TCpool
      ||
         TCstatus := {tc_handler} <<| TCstatus
    END;

  Produce_TM(tm,tm_handler) =
    PRE
        /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & tm : TM_SET
      & tm_handler : PACKET_START_ADDRESSES_IN_TM_POOL
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    END;

  Pass_TM(tm_handler,tm_pointer) =
    PRE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_vacant_tm_buffer_address  */ tm_pointer /: dom(TMbuffer)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Effective
      & tm_pointer : PACKET_START_ADDRESSES_IN_TM_BUFFER
    THEN
         TMbuffer := TMbuffer <+ {tm_pointer |-> TMpool(tm_handler)}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Removable}
    END;

  Cancel_TM(tm_handler) =
    PRE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Effective
    THEN
         TMstatus := TMstatus <+ {tm_handler |-> TM_Removable}
    END;

  Drop_TM(tm_handler) =
    PRE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Removable
    THEN
         TMpool := {tm_handler} <<| TMpool
      ||
         TMstatus := {tm_handler} <<| TMstatus
    END;

  env_Deliver_TM(tm_pointer) =
    PRE
        /* @grd_tm_pointer  */ tm_pointer : dom(TMbuffer)
    THEN
         TMbuffer := {tm_pointer} <<| TMbuffer
    END
END
