/*
I. Oliver. Experiences in Using B and UML in Industrial Development. In Proceedings Formal Specification and Development in B, B’07, page 248–251, 2007.
*/
MACHINE nota

/* these represent the classes */
/* effectively these also include their addresses, which in an
   OO context in their object ID. Note that also SERVICE also
   includes the properties of those service objects, ie: the ID of
   a service is more complicated than just an object id */



SETS
 INTERCONNECTNODE ;
 SOCKET ;
 SERVICE ;     
 RESOURCEMANAGER ;
 SID ;
 
/* error codes */
 RM_ERROR_CODES = { RM_SERVICE_FOUND, RM_SERVICE_NOT_FOUND } ;
 IN_ERROR_CODES = { IN_REGISTRATION_OK, IN_REGISTRATION_FAILED,
                    IN_DEREGISTRATION_OK, IN_DEREGISTRATION_FAILED,
                    IN_NO_SOCKET_CONNECTION, IN_SOCKET_CONNECTION_OK,
                    IN_NO_AVAILABLE_SERVICE, IN_SERVICE_AVAILABLE,
                    IN_TARGET_SOCKET_GRANTED, IN_TARGET_SOCKET_NOT_GRANTED }
    


DEFINITIONS
 disjoint(f) == !(a1,a2) . ( a1:dom(f) & a2:dom(f) & a1/=a2=>f(a1)/\f(a2)={} )

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
 interconnectNodes : POW( INTERCONNECTNODE ) &
 sockets : POW( SOCKET ) &
 services : POW( SERVICE ) &
 resourceManagers :  POW( RESOURCEMANAGER ) &
 sids : POW( SID ) &

 /*and now the invariants of the classes*/
 /*see page 99 of PUSSEE Book for explanations about the functions --> >+> etc  */

 rm_services : resourceManagers-->POW(services) &   /* 0..1 -> 0..n */
 disjoint(rm_services) &
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
 oid <-- constructor_interconnectNode =
 BEGIN
  ANY
   newic
  WHERE
   newic : INTERCONNECTNODE - interconnectNodes 
  THEN
   interconnectNodes := interconnectNodes \/ { newic } ||
   in_resourceManager(newic) := {} ||
   oid := newic
  END
 END ;

 oid <-- constructor_resourceManager =
 PRE
  resourceManagers = {}
 THEN
  ANY
   newrm
  WHERE
   newrm : RESOURCEMANAGER - resourceManagers &
   newrm /: dom(rm_services)
  THEN
   resourceManagers := resourceManagers \/ { newrm } ||
   rm_services(newrm) := {}  ||
   oid := newrm
  END
 END ;

 oid <-- constructor_service(ii) =
 PRE 
  ii : interconnectNodes
 THEN
  ANY
   newsvc
  WHERE
   newsvc : SERVICE - services
  THEN
   services := services \/ { newsvc } ||
   svc_registered(newsvc) := FALSE ||
   svc_sockets(newsvc) := {} ||
   svc_ICNode(newsvc) := ii ||
   svc_serviceID := {} ||
   oid := newsvc
  END
 END ;

/* generic constructor for socket Superclass*/
 oid <-- constructor_socket(ii,srcsid,targsid) =
 PRE
  ii : interconnectNodes &
  srcsid : sids &
  targsid : sids
 THEN
  ANY
   newsoc
  WHERE
   newsoc : SOCKET - sockets
  THEN
   sockets := sockets \/ { newsoc } ||
   oid := newsoc ||
   in_sockets(newsoc) := ii ||
   soc_to(newsoc) :=  srcsid  ||
   soc_from(newsoc) :=  targsid 
  END
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
  ss : services 
 THEN
  CHOICE
   err := RM_SERVICE_FOUND ||
   sid := {rm_sids(ss)} 
  OR
   sid := {} ||
   err := RM_SERVICE_NOT_FOUND
  END
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



 sid,err <-- in_register(self,ss) =
 PRE
  self : interconnectNodes &
  ss : services 
 THEN
  CHOICE
   ANY
    si
   WHERE
    si : SID - sids &
    not(si : dom(in_localServices))
   THEN
    sids := sids \/ { si } ||
    in_localServices := in_localServices \/ { si|->self } ||
    err := IN_REGISTRATION_OK ||
    sid := {si}
   END
  OR
   sid := {} ||
   err := IN_REGISTRATION_FAILED
  END
 END ;


soc,err <-- in_requestTargetSocket(self,ii,srcsoc,srcsid,targsid) =
PRE
 self : interconnectNodes &
 ii : interconnectNodes &
 self /= ii &
 srcsoc : sockets &
 in_sockets(srcsoc) = ii &
 srcsid : sids &
 targsid : sids
THEN
 CHOICE
  ANY
   newsoc
  WHERE
   newsoc : SOCKET - sockets 
  THEN
   sockets := sockets \/ { newsoc } ||
   soc := { newsoc } ||
   err := IN_TARGET_SOCKET_GRANTED || 
   in_sockets := in_sockets \/ { newsoc |-> self } ||
   soc_to(newsoc) := srcsid ||
   soc_from(newsoc) := targsid
  END
 OR
  soc := {} ||
  err := IN_TARGET_SOCKET_NOT_GRANTED
 END 
END ;

/*

 err <-- in_deregister(self,ss) =
 PRE
  self : interconnectNodes &
  ss : services &
  ss : ran( in_localServices )
 THEN
  CHOICE
   err := IN_DEREGISTRATION_OK ||
   in_localServices := in_localServices - { self|->ss }
  OR
   err := IN_DEREGISTRATION_FAILED
  END
 END ;

 sid,err <-- in_getSid(self,ss) =
 PRE
  self : interconnectNodes &
  ss : services
 THEN
  CHOICE
   ANY
    si
   WHERE
    si : sids
   THEN
    sid := {si} ||
    err := IN_SERVICE_AVAILABLE
   END
  OR
   err := IN_NO_AVAILABLE_SERVICE ||
   sid := {}
  END
 END ;

 soc,err <-- in_connect(self,srcservice,targsid) =
  PRE
   self : interconnectNodes &
   srcservice : services &
   targsid : sids &
   srcservice : ran( in_localServices )
  THEN
   CHOICE
    ANY
     so
    WHERE
     so : SOCKETS - sockets
    THEN
     err := IN_SOCKET_CONNECTION_OK ||
     soc := {so} ||
     in_sockets := in_sockets \/ { self|->so }
    END
   OR
    err := IN_NO_SOCKET_CONNECTION ||
    soc := {}
   END
  END ;
  
*/ 
 svc_register(self) =
  PRE
   self : services &
   svc_registered(self) = FALSE
  THEN
   CHOICE
    svc_registered(self) := TRUE
   OR
    svc_registered(self) := FALSE
   END
  END




END
