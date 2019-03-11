
MACHINE obsw_M001
SETS /* deferred */
  PACKET_START_ADDRESSES_IN_TC_BUFFER;
  PACKET_START_ADDRESSES_IN_TC_POOL;
  PACKET_START_ADDRESSES_IN_TM_BUFFER;
  PACKET_START_ADDRESSES_IN_TM_POOL;
  TC_SET;
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
    EVENT INITIALISATION = /* of machine obsw_M001 */
    THEN
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
    REFINES
      EVENT INITIALISATION = /* of machine obsw_M000 */
      THEN
        skip
      END
    END
OPERATIONS
  env_Receive_TC(tc,tc_pointer) =
    EVENT env_Receive_TC = /* of machine obsw_M001 */
    ANY tc,tc_pointer
    WHERE
        /* @grd_vacant_tc_buffer_address  */ tc_pointer /: dom(TCbuffer)
    THEN
         TCbuffer := TCbuffer <+ {tc_pointer |-> tc}
    REFINES
      EVENT env_Receive_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Poll_TC(tc_handler,tc_pointer) =
    EVENT Poll_TC = /* of machine obsw_M001 */
    ANY tc_handler,tc_pointer
    WHERE
        /* @grd_tc_pointer  */ tc_pointer : dom(TCbuffer)
      & /* @grd_vacant_tc_pool_address  */ tc_handler /: dom(TCpool)
    THEN
         TCpool := TCpool <+ {tc_handler |-> TCbuffer(tc_pointer)}
      ||
         TCbuffer := {tc_pointer} <<| TCbuffer
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Unchecked}
    REFINES
      EVENT Poll_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Accept_TC(tc_handler) =
    EVENT Accept_TC = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_valid_tc  */ TCpool(tc_handler) : VALID_TCS
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Unchecked
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Accepted}
    END;

  Reject_TC(tc_handler) =
    EVENT Reject_TC = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Unchecked
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Rejected}
    END;

  Report_TC_Acceptance(tc_handler,tm,tm_handler) =
    EVENT Report_TC_Acceptance = /* of machine obsw_M001 */
    ANY tc_handler,tm,tm_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Accepted
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Waiting_for_Execution}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    REFINES
      EVENT Report_on_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Skip_TC_Acceptance_Report(tc_handler) =
    EVENT Skip_TC_Acceptance_Report = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Accepted
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Waiting_for_Execution}
    END;

  Report_TC_Rejection(tc_handler,tm,tm_handler) =
    EVENT Report_TC_Rejection = /* of machine obsw_M001 */
    ANY tc_handler,tm,tm_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Rejected
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    REFINES
      EVENT Report_on_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Skip_TC_Rejection_Report(tc_handler) =
    EVENT Skip_TC_Rejection_Report = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Rejected
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Execute_TC_Successfully(tc_handler) =
    EVENT Execute_TC_Successfully = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_pool  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Successfully_Executed}
    END;

  Reset_TM_Buffer(tc_handler) =
    EVENT Reset_TM_Buffer = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TMbuffer := {}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Successfully_Executed}
    REFINES
      EVENT Reset_TM_Buffer = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Fail_TC_Execution(tc_handler) =
    EVENT Fail_TC_Execution = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Waiting_for_Execution
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Execution_Failed}
    END;

  Report_TC_Execution_Success(tc_handler,tm,tm_handler) =
    EVENT Report_TC_Execution_Success = /* of machine obsw_M001 */
    ANY tc_handler,tm,tm_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Successfully_Executed
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    REFINES
      EVENT Report_on_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Skip_TC_Success_Report(tc_handler) =
    EVENT Skip_TC_Success_Report = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Successfully_Executed
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Report_TC_Execution_Failure(tc_handler,tm,tm_handler) =
    EVENT Report_TC_Execution_Failure = /* of machine obsw_M001 */
    ANY tc_handler,tm,tm_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Execution_Failed
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    REFINES
      EVENT Report_on_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Skip_TC_Failure_Report(tc_handler) =
    EVENT Skip_TC_Failure_Report = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Execution_Failed
    THEN
         TCstatus := TCstatus <+ {tc_handler |-> TC_Removable}
    END;

  Drop_TC(tc_handler) =
    EVENT Drop_TC = /* of machine obsw_M001 */
    ANY tc_handler
    WHERE
        /* @grd_tc_handler  */ tc_handler : dom(TCpool)
      & /* @grd_tc_status_defined  */ tc_handler : dom(TCstatus)
      & /* @grd_tc_status_value  */ TCstatus(tc_handler) = TC_Removable
    THEN
         TCpool := {tc_handler} <<| TCpool
      ||
         TCstatus := {tc_handler} <<| TCstatus
    REFINES
      EVENT Drop_TC = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Produce_TM(tm,tm_handler) =
    EVENT Produce_TM = /* of machine obsw_M001 */
    ANY tm,tm_handler
    WHERE
        /* @grd_vacant_tm_pool_address  */ tm_handler /: dom(TMpool)
    THEN
         TMpool := TMpool <+ {tm_handler |-> tm}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Effective}
    REFINES
      EVENT Produce_TM = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Pass_TM(tm_handler,tm_pointer) =
    EVENT Pass_TM = /* of machine obsw_M001 */
    ANY tm_handler,tm_pointer
    WHERE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_vacant_tm_buffer_address  */ tm_pointer /: dom(TMbuffer)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Effective
    THEN
         TMbuffer := TMbuffer <+ {tm_pointer |-> TMpool(tm_handler)}
      ||
         TMstatus := TMstatus <+ {tm_handler |-> TM_Removable}
    REFINES
      EVENT Pass_TM = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  Cancel_TM(tm_handler) =
    EVENT Cancel_TM = /* of machine obsw_M001 */
    ANY tm_handler
    WHERE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Effective
    THEN
         TMstatus := TMstatus <+ {tm_handler |-> TM_Removable}
    END;

  Drop_TM(tm_handler) =
    EVENT Drop_TM = /* of machine obsw_M001 */
    ANY tm_handler
    WHERE
        /* @grd_tm_handler  */ tm_handler : dom(TMpool)
      & /* @grd_tm_status_defined  */ tm_handler : dom(TMstatus)
      & /* @grd_tm_status_value  */ TMstatus(tm_handler) = TM_Removable
    THEN
         TMpool := {tm_handler} <<| TMpool
      ||
         TMstatus := {tm_handler} <<| TMstatus
    REFINES
      EVENT Drop_TM = /* of machine obsw_M000 */
      THEN
        skip
      END
    END;

  env_Deliver_TM(tm_pointer) =
    EVENT env_Deliver_TM = /* of machine obsw_M001 */
    ANY tm_pointer
    WHERE
        /* @grd_tm_pointer  */ tm_pointer : dom(TMbuffer)
    THEN
         TMbuffer := {tm_pointer} <<| TMbuffer
    REFINES
      EVENT env_Deliver_TM = /* of machine obsw_M000 */
      THEN
        skip
      END
    END
END
