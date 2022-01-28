MACHINE nota_v2
// a simplified version of nota for B2Program

/* these represent the classes */
/* effectively these also include their addresses, which in an
   OO context in their object ID. Note that also SERVICE also
   includes the properties of those service objects, ie: the ID of
   a service is more complicated than just an object id */


SETS
 INTERCONNECTNODE = {node1,node2};
 SOCKET = {socket1,socket2};
 SERVICE = {service1,service2};     
 RESOURCEMANAGER = {resource1,resource2};
 SID = {SID1,SID2};
 
/* error codes */
 RM_ERROR_CODES = { RM_SERVICE_FOUND, RM_SERVICE_NOT_FOUND } ;
 IN_ERROR_CODES = { IN_REGISTRATION_OK, IN_REGISTRATION_FAILED,
                    IN_DEREGISTRATION_OK, IN_DEREGISTRATION_FAILED,
                    IN_NO_SOCKET_CONNECTION, IN_SOCKET_CONNECTION_OK,
                    IN_NO_AVAILABLE_SERVICE, IN_SERVICE_AVAILABLE,
                    IN_TARGET_SOCKET_GRANTED, IN_TARGET_SOCKET_NOT_GRANTED }
    


DEFINITIONS
 //disjoint(rm_services) == !(a1,a2) . ( a1:dom(rm_services) & a2:dom(rm_services) & a1/=a2=>rm_services(a1)/\rm_services(a2)={} );
 SET_PREF_DEFAULT_SETSIZE == 2;
 SET_PREF_MAX_OPERATIONS == 30;
 scope_INTERCONNECTNODE == 2;
 scope_SOCKET == 2;
 scope_SERVICE == 2;
 scope_RESOURCEMANAGER == 2;
 scope_SID == 2

VARIABLES
/* these represent the objects */
 interconnectNodes,
 sockets,
 services,
 resourceManagers,
 sids,
/*and now the defintion of the classes and their internal and eternal datastructures*/
 rm_services,
 rm_sids,
 in_localServices,
 in_sockets,
 in_resourceManager,
 soc_to,
 soc_from,
 svc_serviceID,
 svc_sockets,
 svc_ICNode,
 svc_registered
 
 
 
 
INVARIANT
 interconnectNodes <: INTERCONNECTNODE &
 sockets <: SOCKET &
 services <: SERVICE&
 resourceManagers <: RESOURCEMANAGER &
 sids <: SID &

 /*and now the invariants of the classes*/
 /*see page 99 of PUSSEE Book for explanations about the functions --> >+> etc  */

 rm_services : resourceManagers-->POW(services) &   /* 0..1 -> 0..n */
 !(a1,a2) . ( a1:dom(rm_services) & a2:dom(rm_services) & a1/=a2=>rm_services(a1)/\rm_services(a2)={} ) & // was disjoint(rm_services) &
 rm_sids     : services>+>sids &


 in_localServices : sids --> interconnectNodes &
 in_sockets : sockets --> interconnectNodes  &
 in_resourceManager : interconnectNodes --> POW( resourceManagers ) &





 soc_to : sockets-->sids &
 soc_from : sockets-->sids  &
 svc_serviceID : services+->sids &
 svc_sockets : services-->POW(sockets) &
 svc_ICNode : services--> interconnectNodes &
 svc_registered : services-->BOOL &


 /* invariants over the classes as a whole, ie: the triangles :) 
  !(ii, ss).( ( ii : interconnectNodes & ss : services & in_localServices(ii) = ss ) =>  in_sockets(ii) = svc_sockets(ss) )  & */
 /* only one resource manager in a system */
 /* at least for the moment, we might retrench this :-) in a more fault tolerant system */
 ( not(resourceManagers={}) => card(resourceManagers) = 1 ) 
 
 
 
INITIALISATION
 interconnectNodes := {} ||
 sockets := {} ||
 services := {} ||
 resourceManagers := {} ||
 sids := {} ||
 /*and now the initialisations of the classes/objects */
 rm_services := {} ||
 rm_sids := {}  ||
 in_localServices := {} ||
 in_sockets := {} ||
 in_resourceManager := {} ||
 soc_to := {} ||
 soc_from := {} ||
 svc_serviceID := {} ||
 svc_sockets := {} ||
 svc_ICNode := {} ||
 svc_registered := {}


/* constructors */

OPERATIONS
 oid <-- constructor_interconnectNode(newic) =
  SELECT
   newic : INTERCONNECTNODE - interconnectNodes 
  THEN
   interconnectNodes := interconnectNodes \/ { newic } ||
   in_resourceManager(newic) := {} ||
   oid := newic
 END ;

 oid <-- constructor_resourceManager(newrm) =
 PRE
   newrm : RESOURCEMANAGER - resourceManagers &
   newrm /: dom(rm_services) &
   resourceManagers = {}
 THEN
   resourceManagers := resourceManagers \/ { newrm } ||
   rm_services(newrm) := {}  ||
   oid := newrm
 END ;

 oid <-- constructor_service(ii,newsvc) =
 PRE 
  ii : interconnectNodes &
   newsvc : SERVICE - services
  THEN
   services := services \/ { newsvc } ||
   svc_registered(newsvc) := FALSE ||
   svc_sockets(newsvc) := {} ||
   svc_ICNode(newsvc) := ii ||
   svc_serviceID := {} ||
   oid := newsvc
 END ;

/* generic constructor for socket Superclass*/
 oid <-- constructor_socket(ii,srcsid,targsid,newsoc) =
 PRE
  ii : interconnectNodes &
  srcsid : sids &
  targsid : sids &
   newsoc : SOCKET - sockets
  THEN
   sockets := sockets \/ { newsoc } ||
   oid := newsoc ||
   in_sockets(newsoc) := ii ||
   soc_to(newsoc) :=  srcsid  ||
   soc_from(newsoc) :=  targsid 
 END ;




/* end of constrctors */

/* Resource manager operations */
rm_register(self,ss,ii) =
 PRE
  self : resourceManagers &
  ss : services &   /* this is the OBJECT */
  ii : interconnectNodes 
 THEN
  skip
 END ;
 
 rm_deregister(self,ss,ii) =
 PRE
  self : resourceManagers &
  ss : services &
  ii : interconnectNodes
 THEN
  skip
 END ;

 sid,err<--rm_getSid(self,ss) =
 PRE
  self : resourceManagers &
  ss : services &
  ss:dom(rm_sids) THEN // ADDED
   err := RM_SERVICE_FOUND ||
   sid := {rm_sids(ss)}  // ORIGINALLY WD ERROR
 END ;
 sid,err<--rm_getSid_Not_Found(self,ss) =
 PRE
  self : resourceManagers &
  ss : services 
 THEN
   sid := SID-SID ||
   err := RM_SERVICE_NOT_FOUND
 END ;

/* interconnectNode */

in_announceResourceManager(self,rm) =
 PRE
  self : interconnectNodes &
  rm   : resourceManagers &
  in_resourceManager(self) = {}

 THEN
  in_resourceManager(self) := in_resourceManager(self) \/ { rm }
 END ;


// Split for B2Program:
 sid,err <-- in_register_success(self,ss,si) =
 PRE
  self : interconnectNodes &
  ss : services &
    si : SID - sids &
    not(si : dom(in_localServices))
   THEN
    sids := sids \/ { si } ||
    in_localServices := in_localServices \/ { si|->self } ||
    err := IN_REGISTRATION_OK ||
    sid := {si}
  END;
 sid,err <-- in_register_failed(self,ss) =
 PRE
  self : interconnectNodes &
  ss : services
 THEN
   sid := SID - SID ||
   err := IN_REGISTRATION_FAILED
 END ;


// Split for B2Program:
soc,err <-- in_requestTargetSocket_Granted(self,ii,srcsoc,srcsid,targsid,newsoc) =
PRE
 self : interconnectNodes &
 ii : interconnectNodes &
 srcsoc : sockets &
 srcsid : sids &
 targsid : sids &
   newsoc : SOCKET - sockets  &
 self /= ii &
 in_sockets(srcsoc) = ii
  THEN
   sockets := sockets \/ { newsoc } ||
   soc := { newsoc } ||
   err := IN_TARGET_SOCKET_GRANTED || 
   in_sockets := in_sockets \/ { newsoc |-> self } ||
   soc_to(newsoc) := srcsid ||
   soc_from(newsoc) := targsid
END ;
soc,err <-- in_requestTargetSocket_NotGranted(self,ii,srcsoc,srcsid,targsid) =
PRE
 self : interconnectNodes &
 ii : interconnectNodes &
 srcsoc : sockets &
 srcsid : sids &
 targsid : sids &
 self /= ii &
 in_sockets(srcsoc) = ii
THEN
  soc := SOCKET-SOCKET ||
  err := IN_TARGET_SOCKET_NOT_GRANTED
 
END ;



 svc_register(self) =
  PRE
   self : services &
   svc_registered(self) = FALSE
  THEN
  // CHOICE  // not supported by B2Program
    svc_registered(self) := TRUE
   //OR
  //  svc_registered(self) := FALSE
  // END
  END




END
