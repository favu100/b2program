/* C. Venkatramani and T.-c. Chiueh. Design, implementation, and evaluation of a
   software-based real-time ethernet protocol. ACM SIGCOMM Computer Communication Review, 25(4), 1995 */
/* Manually translated from Event-B to B*/
MACHINE rether
SETS /* enumerated */
  Nodes={node1,node2,node3,node4,node5};
  Slots={slot1,slot2,slot3,slot4}
CONCRETE_CONSTANTS
  RT_Slots,
  nextNodes,
  nextSlots
ABSTRACT_VARIABLES
  RT_count,
  grants,
  open_reservations,
  time,
  token
/* PROMOTED OPERATIONS
  elapse_time,
  reserve,
  release,
  grant,
  no_grant,
  use_RT_Slot,
  use_NRT_Slot,
  pass_token */
PROPERTIES
    /*rether_ctx1:axm1 */ nextSlots : Slots --> Slots
  & /*rether_ctx1:axm2 */ RT_Slots <<: Slots
  & /*rether_ctx1:axm3 */ nextNodes : Nodes --> Nodes
  & /*rether_ctx1a:axm4 */ nextSlots = {slot1 |-> slot2,slot2 |-> slot3,slot3 |-> slot1,slot4 |-> slot1}
  & /*rether_ctx1a:axm5 */ RT_Slots = {slot1,slot2}
  & /*rether_ctx1a:axm6 */ nextNodes = {node1 |-> node2,node2 |-> node3,node3 |-> node4,node4 |-> node1,node5 |-> node1}
INVARIANT
    time : Slots
  & token : Nodes
  & /*rether_mch1:inv3 */ open_reservations : Nodes +-> Slots
  & /*rether_mch1:inv4 */ grants : Nodes +-> Slots
  & /*rether_mch1:inv6 */ RT_count : NAT
INITIALISATION
    BEGIN
         time := slot1
      ||
         token := node1
      ||
         open_reservations := {}
      ||
         grants := {}
      ||
         RT_count := card(RT_Slots)
    END

OPERATIONS
  elapse_time(next,slot) =
    PRE
        next : Slots
      & slot : Slots
      & /*rether_mch1:grd1 */ slot |-> next : nextSlots
      & /*rether_mch1:grd2 */ slot = time
    THEN
      time := next
    END;

  reserve(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ node /: dom(open_reservations)
      & /*rether_mch1:grd2 */ slot /: ran(open_reservations)
      & /*rether_mch1:grd3 */ (node |-> slot) /: open_reservations
      & /*rether_mch1:grd4 */ node /: dom(grants)
      & /*rether_mch1:grd5 */ slot /: ran(grants)
    THEN
      open_reservations := open_reservations \/ {node |-> slot}
    END;

  release(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ node |-> slot : grants
    THEN
      grants := grants \ {node |-> slot}
        ||
      RT_count := RT_count + 1
    END;

  grant(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ node : dom(open_reservations)
      & /*rether_mch1:grd2 */ slot : ran(open_reservations)
      & /*rether_mch1:grd3 */ node |-> slot : open_reservations
      & /*rether_mch1:grd4 */ RT_count > 0
    THEN
      open_reservations := open_reservations \ {node |-> slot}
        ||
      grants := grants \/ {node |-> slot}
        ||
      RT_count := RT_count - 1
    END;

  no_grant(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ node : dom(open_reservations)
      & /*rether_mch1:grd2 */ slot : ran(open_reservations)
      & /*rether_mch1:grd3 */ node |-> slot : open_reservations
    THEN
      open_reservations := open_reservations \ {node |-> slot}
    END;

  use_RT_Slot(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ node |-> slot : grants
      & /*rether_mch1:grd2 */ slot = time
      & /*rether_mch1:grd3 */ node = token
    THEN
      skip
    END;

  use_NRT_Slot(node,slot) =
    PRE
        node : Nodes
      & slot : Slots
      & /*rether_mch1:grd1 */ (node |-> slot) /: grants
      & /*rether_mch1:grd2 */ slot = time
      & /*rether_mch1:grd3 */ node /: dom(grants)
      & /*rether_mch1:grd4 */ slot /: ran(grants)
      & /*rether_mch1:grd5 */ node = token
    THEN
        skip
    END;

  pass_token(node) =
    PRE
        node : Nodes &
        /*rether_mch1:grd1 */ node = token
    THEN
       token := nextNodes(node)
    END
END
