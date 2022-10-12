#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::{IntoBool, BBooleanT};
use btypes::bboolean::BBoolean;
use btypes::binteger::BInteger;
use btypes::brelation::BRelation;
use btypes::bstruct::BStruct;
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct5 {
    soc: BSet<SOCKET>,
    err: IN_ERROR_CODES,
}

impl fmt::Display for _Struct5 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "soc: {},err: {}", self.soc ,self.err)
    }
}

impl BObject for _Struct5 {}
impl BStruct for _Struct5 {}

impl _Struct5 {
    pub fn new(mut soc: BSet<SOCKET>, mut err: IN_ERROR_CODES) -> _Struct5 {
        let mut m: _Struct5 = Default::default();
        m.soc = soc;m.err = err;
        return m;
    }

    pub fn get_soc(&self) -> BSet<SOCKET> {
        return self.soc.clone();
    }

    pub fn get_err(&self) -> IN_ERROR_CODES {
        return self.err.clone();
    }

    pub fn override_soc(&self, soc: BSet<SOCKET>) -> _Struct5 {
        return _Struct5::new(soc.clone(), self.err.clone());
    }


    pub fn override_err(&self, err: IN_ERROR_CODES) -> _Struct5 {
        return _Struct5::new(self.soc.clone(), err.clone());
    }


    pub fn equal(
    &self, other: &_Struct5) -> BBoolean {
        return BBoolean::new(self.soc == other.soc && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct5) -> BBoolean {
        return BBoolean::new(self.soc != other.soc || self.err != other.err);
    }

}

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct1 {
    sid: BSet<SID>,
    err: RM_ERROR_CODES,
}

impl fmt::Display for _Struct1 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "sid: {},err: {}", self.sid ,self.err)
    }
}

impl BObject for _Struct1 {}
impl BStruct for _Struct1 {}

impl _Struct1 {
    pub fn new(mut sid: BSet<SID>, mut err: RM_ERROR_CODES) -> _Struct1 {
        let mut m: _Struct1 = Default::default();
        m.sid = sid;m.err = err;
        return m;
    }

    pub fn get_sid(&self) -> BSet<SID> {
        return self.sid.clone();
    }

    pub fn get_err(&self) -> RM_ERROR_CODES {
        return self.err.clone();
    }

    pub fn override_sid(&self, sid: BSet<SID>) -> _Struct1 {
        return _Struct1::new(sid.clone(), self.err.clone());
    }


    pub fn override_err(&self, err: RM_ERROR_CODES) -> _Struct1 {
        return _Struct1::new(self.sid.clone(), err.clone());
    }


    pub fn equal(
    &self, other: &_Struct1) -> BBoolean {
        return BBoolean::new(self.sid == other.sid && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct1) -> BBoolean {
        return BBoolean::new(self.sid != other.sid || self.err != other.err);
    }

}

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct3 {
    sid: BSet<SID>,
    err: IN_ERROR_CODES,
}

impl fmt::Display for _Struct3 {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "sid: {},err: {}", self.sid ,self.err)
    }
}

impl BObject for _Struct3 {}
impl BStruct for _Struct3 {}

impl _Struct3 {
    pub fn new(mut sid: BSet<SID>, mut err: IN_ERROR_CODES) -> _Struct3 {
        let mut m: _Struct3 = Default::default();
        m.sid = sid;m.err = err;
        return m;
    }

    pub fn get_sid(&self) -> BSet<SID> {
        return self.sid.clone();
    }

    pub fn get_err(&self) -> IN_ERROR_CODES {
        return self.err.clone();
    }

    pub fn override_sid(&self, sid: BSet<SID>) -> _Struct3 {
        return _Struct3::new(sid.clone(), self.err.clone());
    }


    pub fn override_err(&self, err: IN_ERROR_CODES) -> _Struct3 {
        return _Struct3::new(self.sid.clone(), err.clone());
    }


    pub fn equal(
    &self, other: &_Struct3) -> BBoolean {
        return BBoolean::new(self.sid == other.sid && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct3) -> BBoolean {
        return BBoolean::new(self.sid != other.sid || self.err != other.err);
    }

}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum INTERCONNECTNODE {
    node1, 
    node2
}
impl INTERCONNECTNODE {
    pub fn equal(&self, other: &INTERCONNECTNODE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &INTERCONNECTNODE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for INTERCONNECTNODE {}
impl Default for INTERCONNECTNODE {
    fn default() -> Self { INTERCONNECTNODE::node1 }
}
impl fmt::Display for INTERCONNECTNODE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           INTERCONNECTNODE::node1 => write!(f, "node1"),
           INTERCONNECTNODE::node2 => write!(f, "node2"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SOCKET {
    socket1, 
    socket2
}
impl SOCKET {
    pub fn equal(&self, other: &SOCKET) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &SOCKET) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for SOCKET {}
impl Default for SOCKET {
    fn default() -> Self { SOCKET::socket1 }
}
impl fmt::Display for SOCKET {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           SOCKET::socket1 => write!(f, "socket1"),
           SOCKET::socket2 => write!(f, "socket2"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE {
    service1, 
    service2
}
impl SERVICE {
    pub fn equal(&self, other: &SERVICE) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &SERVICE) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for SERVICE {}
impl Default for SERVICE {
    fn default() -> Self { SERVICE::service1 }
}
impl fmt::Display for SERVICE {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           SERVICE::service1 => write!(f, "service1"),
           SERVICE::service2 => write!(f, "service2"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RESOURCEMANAGER {
    resource1, 
    resource2
}
impl RESOURCEMANAGER {
    pub fn equal(&self, other: &RESOURCEMANAGER) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &RESOURCEMANAGER) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for RESOURCEMANAGER {}
impl Default for RESOURCEMANAGER {
    fn default() -> Self { RESOURCEMANAGER::resource1 }
}
impl fmt::Display for RESOURCEMANAGER {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           RESOURCEMANAGER::resource1 => write!(f, "resource1"),
           RESOURCEMANAGER::resource2 => write!(f, "resource2"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SID {
    SID1, 
    SID2
}
impl SID {
    pub fn equal(&self, other: &SID) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &SID) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for SID {}
impl Default for SID {
    fn default() -> Self { SID::SID1 }
}
impl fmt::Display for SID {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           SID::SID1 => write!(f, "SID1"),
           SID::SID2 => write!(f, "SID2"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RM_ERROR_CODES {
    RM_SERVICE_FOUND, 
    RM_SERVICE_NOT_FOUND
}
impl RM_ERROR_CODES {
    pub fn equal(&self, other: &RM_ERROR_CODES) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &RM_ERROR_CODES) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for RM_ERROR_CODES {}
impl Default for RM_ERROR_CODES {
    fn default() -> Self { RM_ERROR_CODES::RM_SERVICE_FOUND }
}
impl fmt::Display for RM_ERROR_CODES {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           RM_ERROR_CODES::RM_SERVICE_FOUND => write!(f, "RM_SERVICE_FOUND"),
           RM_ERROR_CODES::RM_SERVICE_NOT_FOUND => write!(f, "RM_SERVICE_NOT_FOUND"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum IN_ERROR_CODES {
    IN_REGISTRATION_OK, 
    IN_REGISTRATION_FAILED, 
    IN_DEREGISTRATION_OK, 
    IN_DEREGISTRATION_FAILED, 
    IN_NO_SOCKET_CONNECTION, 
    IN_SOCKET_CONNECTION_OK, 
    IN_NO_AVAILABLE_SERVICE, 
    IN_SERVICE_AVAILABLE, 
    IN_TARGET_SOCKET_GRANTED, 
    IN_TARGET_SOCKET_NOT_GRANTED
}
impl IN_ERROR_CODES {
    pub fn equal(&self, other: &IN_ERROR_CODES) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &IN_ERROR_CODES) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for IN_ERROR_CODES {}
impl Default for IN_ERROR_CODES {
    fn default() -> Self { IN_ERROR_CODES::IN_REGISTRATION_OK }
}
impl fmt::Display for IN_ERROR_CODES {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           IN_ERROR_CODES::IN_REGISTRATION_OK => write!(f, "IN_REGISTRATION_OK"),
           IN_ERROR_CODES::IN_REGISTRATION_FAILED => write!(f, "IN_REGISTRATION_FAILED"),
           IN_ERROR_CODES::IN_DEREGISTRATION_OK => write!(f, "IN_DEREGISTRATION_OK"),
           IN_ERROR_CODES::IN_DEREGISTRATION_FAILED => write!(f, "IN_DEREGISTRATION_FAILED"),
           IN_ERROR_CODES::IN_NO_SOCKET_CONNECTION => write!(f, "IN_NO_SOCKET_CONNECTION"),
           IN_ERROR_CODES::IN_SOCKET_CONNECTION_OK => write!(f, "IN_SOCKET_CONNECTION_OK"),
           IN_ERROR_CODES::IN_NO_AVAILABLE_SERVICE => write!(f, "IN_NO_AVAILABLE_SERVICE"),
           IN_ERROR_CODES::IN_SERVICE_AVAILABLE => write!(f, "IN_SERVICE_AVAILABLE"),
           IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED => write!(f, "IN_TARGET_SOCKET_GRANTED"),
           IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED => write!(f, "IN_TARGET_SOCKET_NOT_GRANTED"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct nota_v2 {
    interconnectNodes: BSet<INTERCONNECTNODE>,
    sockets: BSet<SOCKET>,
    services: BSet<SERVICE>,
    resourceManagers: BSet<RESOURCEMANAGER>,
    sids: BSet<SID>,
    rm_services: BRelation<RESOURCEMANAGER, BSet<SERVICE>>,
    rm_sids: BRelation<SERVICE, SID>,
    in_localServices: BRelation<SID, INTERCONNECTNODE>,
    in_sockets: BRelation<SOCKET, INTERCONNECTNODE>,
    in_resourceManager: BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>,
    soc_to: BRelation<SOCKET, SID>,
    soc_from: BRelation<SOCKET, SID>,
    svc_serviceID: BRelation<SERVICE, SID>,
    svc_sockets: BRelation<SERVICE, BSet<SOCKET>>,
    svc_ICNode: BRelation<SERVICE, INTERCONNECTNODE>,
    svc_registered: BRelation<SERVICE, BBoolean>,
    _INTERCONNECTNODE: BSet<INTERCONNECTNODE>,
    _SOCKET: BSet<SOCKET>,
    _SERVICE: BSet<SERVICE>,
    _RESOURCEMANAGER: BSet<RESOURCEMANAGER>,
    _SID: BSet<SID>,
    _RM_ERROR_CODES: BSet<RM_ERROR_CODES>,
    _IN_ERROR_CODES: BSet<IN_ERROR_CODES>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_interconnectNode: Option<BSet<INTERCONNECTNODE>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_resourceManager: Option<BSet<RESOURCEMANAGER>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_service: Option<BSet<BTuple<INTERCONNECTNODE, SERVICE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_socket: Option<BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_register: Option<BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_deregister: Option<BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_getSid: Option<BSet<BTuple<RESOURCEMANAGER, SERVICE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_getSid_Not_Found: Option<BSet<BTuple<RESOURCEMANAGER, SERVICE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_announceResourceManager: Option<BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_register_success: Option<BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_register_failed: Option<BSet<BTuple<INTERCONNECTNODE, SERVICE>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_requestTargetSocket_Granted: Option<BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_requestTargetSocket_NotGranted: Option<BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_svc_register: Option<BSet<SERVICE>>,}

impl fmt::Display for nota_v2 {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "nota_v2: (".to_owned();
        result += &format!("_get_interconnectNodes: {}, ", self._get_interconnectNodes());
        result += &format!("_get_sockets: {}, ", self._get_sockets());
        result += &format!("_get_services: {}, ", self._get_services());
        result += &format!("_get_resourceManagers: {}, ", self._get_resourceManagers());
        result += &format!("_get_sids: {}, ", self._get_sids());
        result += &format!("_get_rm_services: {}, ", self._get_rm_services());
        result += &format!("_get_rm_sids: {}, ", self._get_rm_sids());
        result += &format!("_get_in_localServices: {}, ", self._get_in_localServices());
        result += &format!("_get_in_sockets: {}, ", self._get_in_sockets());
        result += &format!("_get_in_resourceManager: {}, ", self._get_in_resourceManager());
        result += &format!("_get_soc_to: {}, ", self._get_soc_to());
        result += &format!("_get_soc_from: {}, ", self._get_soc_from());
        result += &format!("_get_svc_serviceID: {}, ", self._get_svc_serviceID());
        result += &format!("_get_svc_sockets: {}, ", self._get_svc_sockets());
        result += &format!("_get_svc_ICNode: {}, ", self._get_svc_ICNode());
        result += &format!("_get_svc_registered: {}, ", self._get_svc_registered());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl nota_v2 {

    pub fn new() -> nota_v2 {
        //values: ''
        let mut m: nota_v2 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._INTERCONNECTNODE = BSet::new(vec![INTERCONNECTNODE::node1, INTERCONNECTNODE::node2]);
        self._SOCKET = BSet::new(vec![SOCKET::socket1, SOCKET::socket2]);
        self._SERVICE = BSet::new(vec![SERVICE::service1, SERVICE::service2]);
        self._RESOURCEMANAGER = BSet::new(vec![RESOURCEMANAGER::resource1, RESOURCEMANAGER::resource2]);
        self._SID = BSet::new(vec![SID::SID1, SID::SID2]);
        self._RM_ERROR_CODES = BSet::new(vec![RM_ERROR_CODES::RM_SERVICE_FOUND, RM_ERROR_CODES::RM_SERVICE_NOT_FOUND]);
        self._IN_ERROR_CODES = BSet::new(vec![IN_ERROR_CODES::IN_REGISTRATION_OK, IN_ERROR_CODES::IN_REGISTRATION_FAILED, IN_ERROR_CODES::IN_DEREGISTRATION_OK, IN_ERROR_CODES::IN_DEREGISTRATION_FAILED, IN_ERROR_CODES::IN_NO_SOCKET_CONNECTION, IN_ERROR_CODES::IN_SOCKET_CONNECTION_OK, IN_ERROR_CODES::IN_NO_AVAILABLE_SERVICE, IN_ERROR_CODES::IN_SERVICE_AVAILABLE, IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED, IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED]);
        self.interconnectNodes = BSet::new(vec![]).clone().clone();
        self.sockets = BSet::new(vec![]).clone().clone();
        self.services = BSet::new(vec![]).clone().clone();
        self.resourceManagers = BSet::new(vec![]).clone().clone();
        self.sids = BSet::new(vec![]).clone().clone();
        self.rm_services = BRelation::new(vec![]).clone().clone();
        self.rm_sids = BRelation::new(vec![]).clone().clone();
        self.in_localServices = BRelation::new(vec![]).clone().clone();
        self.in_sockets = BRelation::new(vec![]).clone().clone();
        self.in_resourceManager = BRelation::new(vec![]).clone().clone();
        self.soc_to = BRelation::new(vec![]).clone().clone();
        self.soc_from = BRelation::new(vec![]).clone().clone();
        self.svc_serviceID = BRelation::new(vec![]).clone().clone();
        self.svc_sockets = BRelation::new(vec![]).clone().clone();
        self.svc_ICNode = BRelation::new(vec![]).clone().clone();
        self.svc_registered = BRelation::new(vec![]).clone().clone();
    }

    pub fn _get_interconnectNodes(&self) -> BSet<INTERCONNECTNODE> {
        return self.interconnectNodes.clone();
    }

    pub fn _get_sockets(&self) -> BSet<SOCKET> {
        return self.sockets.clone();
    }

    pub fn _get_services(&self) -> BSet<SERVICE> {
        return self.services.clone();
    }

    pub fn _get_resourceManagers(&self) -> BSet<RESOURCEMANAGER> {
        return self.resourceManagers.clone();
    }

    pub fn _get_sids(&self) -> BSet<SID> {
        return self.sids.clone();
    }

    pub fn _get_rm_services(&self) -> BRelation<RESOURCEMANAGER, BSet<SERVICE>> {
        return self.rm_services.clone();
    }

    pub fn _get_rm_sids(&self) -> BRelation<SERVICE, SID> {
        return self.rm_sids.clone();
    }

    pub fn _get_in_localServices(&self) -> BRelation<SID, INTERCONNECTNODE> {
        return self.in_localServices.clone();
    }

    pub fn _get_in_sockets(&self) -> BRelation<SOCKET, INTERCONNECTNODE> {
        return self.in_sockets.clone();
    }

    pub fn _get_in_resourceManager(&self) -> BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> {
        return self.in_resourceManager.clone();
    }

    pub fn _get_soc_to(&self) -> BRelation<SOCKET, SID> {
        return self.soc_to.clone();
    }

    pub fn _get_soc_from(&self) -> BRelation<SOCKET, SID> {
        return self.soc_from.clone();
    }

    pub fn _get_svc_serviceID(&self) -> BRelation<SERVICE, SID> {
        return self.svc_serviceID.clone();
    }

    pub fn _get_svc_sockets(&self) -> BRelation<SERVICE, BSet<SOCKET>> {
        return self.svc_sockets.clone();
    }

    pub fn _get_svc_ICNode(&self) -> BRelation<SERVICE, INTERCONNECTNODE> {
        return self.svc_ICNode.clone();
    }

    pub fn _get_svc_registered(&self) -> BRelation<SERVICE, BBoolean> {
        return self.svc_registered.clone();
    }

    pub fn _get__INTERCONNECTNODE(&self) -> BSet<INTERCONNECTNODE> {
        return self._INTERCONNECTNODE.clone();
    }

    pub fn _get__SOCKET(&self) -> BSet<SOCKET> {
        return self._SOCKET.clone();
    }

    pub fn _get__SERVICE(&self) -> BSet<SERVICE> {
        return self._SERVICE.clone();
    }

    pub fn _get__RESOURCEMANAGER(&self) -> BSet<RESOURCEMANAGER> {
        return self._RESOURCEMANAGER.clone();
    }

    pub fn _get__SID(&self) -> BSet<SID> {
        return self._SID.clone();
    }

    pub fn _get__RM_ERROR_CODES(&self) -> BSet<RM_ERROR_CODES> {
        return self._RM_ERROR_CODES.clone();
    }

    pub fn _get__IN_ERROR_CODES(&self) -> BSet<IN_ERROR_CODES> {
        return self._IN_ERROR_CODES.clone();
    }

    pub fn constructor_interconnectNode(&mut self, mut newic: INTERCONNECTNODE) -> INTERCONNECTNODE {
        let mut oid: Option<INTERCONNECTNODE> = Option::None;
        if (self._INTERCONNECTNODE.difference(&self.interconnectNodes).elementOf(&newic)).booleanValue() {
            let mut _ld_interconnectNodes = self.interconnectNodes.clone();
            self.interconnectNodes = _ld_interconnectNodes._union(&BSet::new(vec![newic])).clone().clone();
            self.in_resourceManager = self.in_resourceManager._override(&BRelation::<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>::new(vec![BTuple::new(newic,BSet::new(vec![]))]));
            oid = Option::Some(newic);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
        return oid.unwrap();
    }

    pub fn constructor_resourceManager(&mut self, mut newrm: RESOURCEMANAGER) -> RESOURCEMANAGER {
        let mut oid: Option<RESOURCEMANAGER> = Option::None;
        //pre_assert
        let mut _ld_resourceManagers = self.resourceManagers.clone();
        self.resourceManagers = _ld_resourceManagers._union(&BSet::new(vec![newrm])).clone().clone();
        self.rm_services = self.rm_services._override(&BRelation::<RESOURCEMANAGER, BSet<SERVICE>>::new(vec![BTuple::new(newrm,BSet::new(vec![]))]));
        oid = Option::Some(newrm);

        return oid.unwrap();
    }

    pub fn constructor_service(&mut self, mut ii: INTERCONNECTNODE, mut newsvc: SERVICE) -> SERVICE {
        let mut oid: Option<SERVICE> = Option::None;
        //pre_assert
        let mut _ld_services = self.services.clone();
        self.services = _ld_services._union(&BSet::new(vec![newsvc])).clone().clone();
        self.svc_registered = self.svc_registered._override(&BRelation::<SERVICE, BBoolean>::new(vec![BTuple::new(newsvc,BBoolean::new(false))]));
        self.svc_sockets = self.svc_sockets._override(&BRelation::<SERVICE, BSet<SOCKET>>::new(vec![BTuple::new(newsvc,BSet::new(vec![]))]));
        self.svc_ICNode = self.svc_ICNode._override(&BRelation::<SERVICE, INTERCONNECTNODE>::new(vec![BTuple::new(newsvc,ii)]));
        self.svc_serviceID = BRelation::new(vec![]).clone().clone();
        oid = Option::Some(newsvc);

        return oid.unwrap();
    }

    pub fn constructor_socket(&mut self, mut ii: INTERCONNECTNODE, mut srcsid: SID, mut targsid: SID, mut newsoc: SOCKET) -> SOCKET {
        let mut oid: Option<SOCKET> = Option::None;
        //pre_assert
        let mut _ld_sockets = self.sockets.clone();
        self.sockets = _ld_sockets._union(&BSet::new(vec![newsoc])).clone().clone();
        oid = Option::Some(newsoc);
        self.in_sockets = self.in_sockets._override(&BRelation::<SOCKET, INTERCONNECTNODE>::new(vec![BTuple::new(newsoc,ii)]));
        self.soc_to = self.soc_to._override(&BRelation::<SOCKET, SID>::new(vec![BTuple::new(newsoc,srcsid)]));
        self.soc_from = self.soc_from._override(&BRelation::<SOCKET, SID>::new(vec![BTuple::new(newsoc,targsid)]));

        return oid.unwrap();
    }

    pub fn rm_register(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE, mut ii: INTERCONNECTNODE) -> () {
        //pre_assert

    }

    pub fn rm_deregister(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE, mut ii: INTERCONNECTNODE) -> () {
        //pre_assert

    }

    pub fn rm_getSid(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE) -> _Struct1 {
        let mut sid: Option<BSet<SID>> = Option::None;
        let mut err: Option<RM_ERROR_CODES> = Option::None;
        //pre_assert
        err = Option::Some(RM_ERROR_CODES::RM_SERVICE_FOUND);
        sid = Option::Some(BSet::new(vec![self.rm_sids.functionCall(&ss)]).clone()).clone();

        return _Struct1::new(sid.unwrap(), err.unwrap());
    }

    pub fn rm_getSid_Not_Found(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE) -> _Struct1 {
        let mut sid: Option<BSet<SID>> = Option::None;
        let mut err: Option<RM_ERROR_CODES> = Option::None;
        //pre_assert
        sid = Option::Some(self._SID.difference(&self._SID).clone()).clone();
        err = Option::Some(RM_ERROR_CODES::RM_SERVICE_NOT_FOUND);

        return _Struct1::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_announceResourceManager(&mut self, mut _self: INTERCONNECTNODE, mut rm: RESOURCEMANAGER) -> () {
        //pre_assert
        self.in_resourceManager = self.in_resourceManager._override(&BRelation::<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>::new(vec![BTuple::new(_self,self.in_resourceManager.functionCall(&_self)._union(&BSet::new(vec![rm])))]));

    }

    pub fn in_register_success(&mut self, mut _self: INTERCONNECTNODE, mut ss: SERVICE, mut si: SID) -> _Struct3 {
        let mut sid: Option<BSet<SID>> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        let mut _ld_sids = self.sids.clone();

        let mut _ld_in_localServices = self.in_localServices.clone();
        self.sids = _ld_sids._union(&BSet::new(vec![si])).clone().clone();
        self.in_localServices = _ld_in_localServices._union(&BRelation::new(vec![BTuple::from_refs(&si, &_self)])).clone().clone();
        err = Option::Some(IN_ERROR_CODES::IN_REGISTRATION_OK);
        sid = Option::Some(BSet::new(vec![si]).clone()).clone();

        return _Struct3::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_register_failed(&mut self, mut _self: INTERCONNECTNODE, mut ss: SERVICE) -> _Struct3 {
        let mut sid: Option<BSet<SID>> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        sid = Option::Some(self._SID.difference(&self._SID).clone()).clone();
        err = Option::Some(IN_ERROR_CODES::IN_REGISTRATION_FAILED);

        return _Struct3::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_requestTargetSocket_Granted(&mut self, mut _self: INTERCONNECTNODE, mut ii: INTERCONNECTNODE, mut srcsoc: SOCKET, mut srcsid: SID, mut targsid: SID, mut newsoc: SOCKET) -> _Struct5 {
        let mut soc: Option<BSet<SOCKET>> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        let mut _ld_sockets = self.sockets.clone();
        let mut _ld_in_sockets = self.in_sockets.clone();
        self.sockets = _ld_sockets._union(&BSet::new(vec![newsoc])).clone().clone();
        soc = Option::Some(BSet::new(vec![newsoc]).clone()).clone();
        err = Option::Some(IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED);
        self.in_sockets = _ld_in_sockets._union(&BRelation::new(vec![BTuple::from_refs(&newsoc, &_self)])).clone().clone();
        self.soc_to = self.soc_to._override(&BRelation::<SOCKET, SID>::new(vec![BTuple::new(newsoc,srcsid)]));
        self.soc_from = self.soc_from._override(&BRelation::<SOCKET, SID>::new(vec![BTuple::new(newsoc,targsid)]));

        return _Struct5::new(soc.unwrap(), err.unwrap());
    }

    pub fn in_requestTargetSocket_NotGranted(&mut self, mut _self: INTERCONNECTNODE, mut ii: INTERCONNECTNODE, mut srcsoc: SOCKET, mut srcsid: SID, mut targsid: SID) -> _Struct5 {
        let mut soc: Option<BSet<SOCKET>> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        soc = Option::Some(self._SOCKET.difference(&self._SOCKET).clone()).clone();
        err = Option::Some(IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED);

        return _Struct5::new(soc.unwrap(), err.unwrap());
    }

    pub fn svc_register(&mut self, mut _self: SERVICE) -> () {
        //pre_assert
        self.svc_registered = self.svc_registered._override(&BRelation::<SERVICE, BBoolean>::new(vec![BTuple::new(_self,BBoolean::new(true))]));

    }

    pub fn _tr_constructor_interconnectNode(&mut self, is_caching: bool) -> BSet<INTERCONNECTNODE> {
        //transition
        if !is_caching || self._tr_cache_constructor_interconnectNode.is_none() {
            let mut _ic_set_0: BSet<INTERCONNECTNODE> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_newic_1 in self._INTERCONNECTNODE.difference(&self.interconnectNodes).clone().iter().cloned() {
                _ic_set_0 = _ic_set_0._union(&BSet::new(vec![_ic_newic_1]));

            }
            self._tr_cache_constructor_interconnectNode = Option::Some(_ic_set_0.clone());
            return _ic_set_0;
        } else {
            return self._tr_cache_constructor_interconnectNode.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_resourceManager(&mut self, is_caching: bool) -> BSet<RESOURCEMANAGER> {
        //transition
        if !is_caching || self._tr_cache_constructor_resourceManager.is_none() {
            let mut _ic_set_1: BSet<RESOURCEMANAGER> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_newrm_1 in self._RESOURCEMANAGER.difference(&self.resourceManagers).clone().iter().cloned() {
                if ((self.rm_services.domain().notElementOf(&_ic_newrm_1) && self.resourceManagers.equal(&BSet::new(vec![])))).booleanValue() {
                    _ic_set_1 = _ic_set_1._union(&BSet::new(vec![_ic_newrm_1]));
                }

            }
            self._tr_cache_constructor_resourceManager = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_constructor_resourceManager.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_service(&mut self, is_caching: bool) -> BSet<BTuple<INTERCONNECTNODE, SERVICE>> {
        //transition
        if !is_caching || self._tr_cache_constructor_service.is_none() {
            let mut _ic_set_2: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_newsvc_1 in self._SERVICE.difference(&self.services).clone().iter().cloned() {
                    _ic_set_2 = _ic_set_2._union(&BSet::new(vec![BTuple::from_refs(&_ic_ii_1, &_ic_newsvc_1)]));

                }
            }
            self._tr_cache_constructor_service = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_constructor_service.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_socket(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> {
        //transition
        if !is_caching || self._tr_cache_constructor_socket.is_none() {
            let mut _ic_set_3: BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_srcsid_1 in self.sids.clone().iter().cloned() {
                    for _ic_targsid_1 in self.sids.clone().iter().cloned() {
                        for _ic_newsoc_1 in self._SOCKET.difference(&self.sockets).clone().iter().cloned() {
                            _ic_set_3 = _ic_set_3._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&_ic_ii_1, &_ic_srcsid_1), &_ic_targsid_1), &_ic_newsoc_1)]));

                        }
                    }
                }
            }
            self._tr_cache_constructor_socket = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_constructor_socket.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_register(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> {
        //transition
        if !is_caching || self._tr_cache_rm_register.is_none() {
            let mut _ic_set_4: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.resourceManagers.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                        _ic_set_4 = _ic_set_4._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&_ic_self_1, &_ic_ss_1), &_ic_ii_1)]));

                    }
                }
            }
            self._tr_cache_rm_register = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_rm_register.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_deregister(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> {
        //transition
        if !is_caching || self._tr_cache_rm_deregister.is_none() {
            let mut _ic_set_5: BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.resourceManagers.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                        _ic_set_5 = _ic_set_5._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&_ic_self_1, &_ic_ss_1), &_ic_ii_1)]));

                    }
                }
            }
            self._tr_cache_rm_deregister = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_rm_deregister.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_getSid(&mut self, is_caching: bool) -> BSet<BTuple<RESOURCEMANAGER, SERVICE>> {
        //transition
        if !is_caching || self._tr_cache_rm_getSid.is_none() {
            let mut _ic_set_6: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.resourceManagers.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    if (self.rm_sids.domain().elementOf(&_ic_ss_1)).booleanValue() {
                        _ic_set_6 = _ic_set_6._union(&BSet::new(vec![BTuple::from_refs(&_ic_self_1, &_ic_ss_1)]));
                    }

                }
            }
            self._tr_cache_rm_getSid = Option::Some(_ic_set_6.clone());
            return _ic_set_6;
        } else {
            return self._tr_cache_rm_getSid.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_getSid_Not_Found(&mut self, is_caching: bool) -> BSet<BTuple<RESOURCEMANAGER, SERVICE>> {
        //transition
        if !is_caching || self._tr_cache_rm_getSid_Not_Found.is_none() {
            let mut _ic_set_7: BSet<BTuple<RESOURCEMANAGER, SERVICE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.resourceManagers.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    _ic_set_7 = _ic_set_7._union(&BSet::new(vec![BTuple::from_refs(&_ic_self_1, &_ic_ss_1)]));

                }
            }
            self._tr_cache_rm_getSid_Not_Found = Option::Some(_ic_set_7.clone());
            return _ic_set_7;
        } else {
            return self._tr_cache_rm_getSid_Not_Found.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_announceResourceManager(&mut self, is_caching: bool) -> BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> {
        //transition
        if !is_caching || self._tr_cache_in_announceResourceManager.is_none() {
            let mut _ic_set_8: BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_rm_1 in self.resourceManagers.clone().iter().cloned() {
                    if (self.in_resourceManager.functionCall(&_ic_self_1).equal(&BSet::new(vec![]))).booleanValue() {
                        _ic_set_8 = _ic_set_8._union(&BSet::new(vec![BTuple::from_refs(&_ic_self_1, &_ic_rm_1)]));
                    }

                }
            }
            self._tr_cache_in_announceResourceManager = Option::Some(_ic_set_8.clone());
            return _ic_set_8;
        } else {
            return self._tr_cache_in_announceResourceManager.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_register_success(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> {
        //transition
        if !is_caching || self._tr_cache_in_register_success.is_none() {
            let mut _ic_set_9: BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    for _ic_si_1 in self._SID.difference(&self.sids).clone().iter().cloned() {
                        if (self.in_localServices.domain().elementOf(&_ic_si_1).not()).booleanValue() {
                            _ic_set_9 = _ic_set_9._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&_ic_self_1, &_ic_ss_1), &_ic_si_1)]));
                        }

                    }
                }
            }
            self._tr_cache_in_register_success = Option::Some(_ic_set_9.clone());
            return _ic_set_9;
        } else {
            return self._tr_cache_in_register_success.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_register_failed(&mut self, is_caching: bool) -> BSet<BTuple<INTERCONNECTNODE, SERVICE>> {
        //transition
        if !is_caching || self._tr_cache_in_register_failed.is_none() {
            let mut _ic_set_10: BSet<BTuple<INTERCONNECTNODE, SERVICE>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ss_1 in self.services.clone().iter().cloned() {
                    _ic_set_10 = _ic_set_10._union(&BSet::new(vec![BTuple::from_refs(&_ic_self_1, &_ic_ss_1)]));

                }
            }
            self._tr_cache_in_register_failed = Option::Some(_ic_set_10.clone());
            return _ic_set_10;
        } else {
            return self._tr_cache_in_register_failed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_requestTargetSocket_Granted(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> {
        //transition
        if !is_caching || self._tr_cache_in_requestTargetSocket_Granted.is_none() {
            let mut _ic_set_11: BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                    for _ic_srcsoc_1 in self.sockets.clone().iter().cloned() {
                        for _ic_srcsid_1 in self.sids.clone().iter().cloned() {
                            for _ic_targsid_1 in self.sids.clone().iter().cloned() {
                                for _ic_newsoc_1 in self._SOCKET.difference(&self.sockets).clone().iter().cloned() {
                                    if ((_ic_self_1.unequal(&_ic_ii_1) && self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1))).booleanValue() {
                                        _ic_set_11 = _ic_set_11._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&_ic_self_1, &_ic_ii_1), &_ic_srcsoc_1), &_ic_srcsid_1), &_ic_targsid_1), &_ic_newsoc_1)]));
                                    }

                                }
                            }
                        }
                    }
                }
            }
            self._tr_cache_in_requestTargetSocket_Granted = Option::Some(_ic_set_11.clone());
            return _ic_set_11;
        } else {
            return self._tr_cache_in_requestTargetSocket_Granted.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_requestTargetSocket_NotGranted(&mut self, is_caching: bool) -> BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> {
        //transition
        if !is_caching || self._tr_cache_in_requestTargetSocket_NotGranted.is_none() {
            let mut _ic_set_12: BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                    for _ic_srcsoc_1 in self.sockets.clone().iter().cloned() {
                        for _ic_srcsid_1 in self.sids.clone().iter().cloned() {
                            for _ic_targsid_1 in self.sids.clone().iter().cloned() {
                                if ((_ic_self_1.unequal(&_ic_ii_1) && self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1))).booleanValue() {
                                    _ic_set_12 = _ic_set_12._union(&BSet::new(vec![BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&BTuple::from_refs(&_ic_self_1, &_ic_ii_1), &_ic_srcsoc_1), &_ic_srcsid_1), &_ic_targsid_1)]));
                                }

                            }
                        }
                    }
                }
            }
            self._tr_cache_in_requestTargetSocket_NotGranted = Option::Some(_ic_set_12.clone());
            return _ic_set_12;
        } else {
            return self._tr_cache_in_requestTargetSocket_NotGranted.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_svc_register(&mut self, is_caching: bool) -> BSet<SERVICE> {
        //transition
        if !is_caching || self._tr_cache_svc_register.is_none() {
            let mut _ic_set_13: BSet<SERVICE> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_self_1 in self.services.clone().iter().cloned() {
                if (self.svc_registered.functionCall(&_ic_self_1).equal(&BBoolean::new(false))).booleanValue() {
                    _ic_set_13 = _ic_set_13._union(&BSet::new(vec![_ic_self_1]));
                }

            }
            self._tr_cache_svc_register = Option::Some(_ic_set_13.clone());
            return _ic_set_13;
        } else {
            return self._tr_cache_svc_register.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return self.interconnectNodes.subset(&self._INTERCONNECTNODE).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return self.sockets.subset(&self._SOCKET).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self.services.subset(&self._SERVICE).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return self.resourceManagers.subset(&self._RESOURCEMANAGER).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.sids.subset(&self._SID).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return self.rm_services.checkDomain(&self.resourceManagers).and(&self.rm_services.checkRange(&self.services.pow())).and(&self.rm_services.isFunction()).and(&self.rm_services.isTotal(&self.resourceManagers)).booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_14 = BBoolean::new(true);
        for _ic_a1_1 in self.rm_services.domain().clone().iter().cloned() {
            for _ic_a2_1 in self.rm_services.domain().clone().iter().cloned() {
                if !(_ic_a1_1.unequal(&_ic_a2_1).implies(&self.rm_services.functionCall(&_ic_a1_1).intersect(&self.rm_services.functionCall(&_ic_a2_1)).equal(&BSet::new(vec![])))).booleanValue() {
                    _ic_boolean_14 = BBoolean::new(false);
                    break;
                }

            }
        }

        return _ic_boolean_14.booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.rm_sids.checkDomain(&self.services).and(&self.rm_sids.checkRange(&self.sids)).and(&self.rm_sids.isFunction()).and(&self.rm_sids.isPartial(&self.services)).and(&self.rm_sids.isInjection()).booleanValue();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.in_localServices.checkDomain(&self.sids).and(&self.in_localServices.checkRange(&self.interconnectNodes)).and(&self.in_localServices.isFunction()).and(&self.in_localServices.isTotal(&self.sids)).booleanValue();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self.in_sockets.checkDomain(&self.sockets).and(&self.in_sockets.checkRange(&self.interconnectNodes)).and(&self.in_sockets.isFunction()).and(&self.in_sockets.isTotal(&self.sockets)).booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.in_resourceManager.checkDomain(&self.interconnectNodes).and(&self.in_resourceManager.checkRange(&self.resourceManagers.pow())).and(&self.in_resourceManager.isFunction()).and(&self.in_resourceManager.isTotal(&self.interconnectNodes)).booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self.soc_to.checkDomain(&self.sockets).and(&self.soc_to.checkRange(&self.sids)).and(&self.soc_to.isFunction()).and(&self.soc_to.isTotal(&self.sockets)).booleanValue();
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self.soc_from.checkDomain(&self.sockets).and(&self.soc_from.checkRange(&self.sids)).and(&self.soc_from.isFunction()).and(&self.soc_from.isTotal(&self.sockets)).booleanValue();
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self.svc_serviceID.checkDomain(&self.services).and(&self.svc_serviceID.checkRange(&self.sids)).and(&self.svc_serviceID.isFunction()).and(&self.svc_serviceID.isPartial(&self.services)).booleanValue();
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self.svc_sockets.checkDomain(&self.services).and(&self.svc_sockets.checkRange(&self.sockets.pow())).and(&self.svc_sockets.isFunction()).and(&self.svc_sockets.isTotal(&self.services)).booleanValue();
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self.svc_ICNode.checkDomain(&self.services).and(&self.svc_ICNode.checkRange(&self.interconnectNodes)).and(&self.svc_ICNode.isFunction()).and(&self.svc_ICNode.isTotal(&self.services)).booleanValue();
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.svc_registered.checkDomain(&self.services).and(&self.svc_registered.checkRange(&butils::BOOL)).and(&self.svc_registered.isFunction()).and(&self.svc_registered.isTotal(&self.services)).booleanValue();
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.resourceManagers.equal(&BSet::new(vec![])).not().implies(&self.resourceManagers.card().equal(&BInteger::new(1))).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_constructor_interconnectNode" => {self._tr_constructor_interconnectNode(false);},
                "_tr_constructor_resourceManager" => {self._tr_constructor_resourceManager(false);},
                "_tr_constructor_service" => {self._tr_constructor_service(false);},
                "_tr_constructor_socket" => {self._tr_constructor_socket(false);},
                "_tr_rm_register" => {self._tr_rm_register(false);},
                "_tr_rm_deregister" => {self._tr_rm_deregister(false);},
                "_tr_rm_getSid" => {self._tr_rm_getSid(false);},
                "_tr_rm_getSid_Not_Found" => {self._tr_rm_getSid_Not_Found(false);},
                "_tr_in_announceResourceManager" => {self._tr_in_announceResourceManager(false);},
                "_tr_in_register_success" => {self._tr_in_register_success(false);},
                "_tr_in_register_failed" => {self._tr_in_register_failed(false);},
                "_tr_in_requestTargetSocket_Granted" => {self._tr_in_requestTargetSocket_Granted(false);},
                "_tr_in_requestTargetSocket_NotGranted" => {self._tr_in_requestTargetSocket_NotGranted(false);},
                "_tr_svc_register" => {self._tr_svc_register(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut nota_v2,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(nota_v2, &'static str)> {
        let mut result = HashSet::<(nota_v2, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        let mut _trid_1 = state._tr_constructor_interconnectNode(isCaching);
        for param in _trid_1.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.constructor_interconnectNode(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("constructor_interconnectNode")); }
            result.insert((copiedState, "constructor_interconnectNode"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_2 = state._tr_constructor_resourceManager(isCaching);
        for param in _trid_2.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.constructor_resourceManager(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("constructor_resourceManager")); }
            result.insert((copiedState, "constructor_resourceManager"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_3 = state._tr_constructor_service(isCaching);
        for param in _trid_3.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.constructor_service(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("constructor_service")); }
            result.insert((copiedState, "constructor_service"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_4 = state._tr_constructor_socket(isCaching);
        for param in _trid_4.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_5 = _tmp_4.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_6 = _tmp_4.projection1();

            let mut copiedState = state.clone();
            copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("constructor_socket")); }
            result.insert((copiedState, "constructor_socket"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_5 = state._tr_rm_register(isCaching);
        for param in _trid_5.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();

            let mut copiedState = state.clone();
            copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("rm_register")); }
            result.insert((copiedState, "rm_register"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_6 = state._tr_rm_deregister(isCaching);
        for param in _trid_6.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();

            let mut copiedState = state.clone();
            copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("rm_deregister")); }
            result.insert((copiedState, "rm_deregister"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_7 = state._tr_rm_getSid(isCaching);
        for param in _trid_7.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.rm_getSid(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("rm_getSid")); }
            result.insert((copiedState, "rm_getSid"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_8 = state._tr_rm_getSid_Not_Found(isCaching);
        for param in _trid_8.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("rm_getSid_Not_Found")); }
            result.insert((copiedState, "rm_getSid_Not_Found"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_9 = state._tr_in_announceResourceManager(isCaching);
        for param in _trid_9.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("in_announceResourceManager")); }
            result.insert((copiedState, "in_announceResourceManager"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_10 = state._tr_in_register_success(isCaching);
        for param in _trid_10.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();

            let mut copiedState = state.clone();
            copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("in_register_success")); }
            result.insert((copiedState, "in_register_success"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_11 = state._tr_in_register_failed(isCaching);
        for param in _trid_11.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.in_register_failed(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("in_register_failed")); }
            result.insert((copiedState, "in_register_failed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_12 = state._tr_in_requestTargetSocket_Granted(isCaching);
        for param in _trid_12.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_5 = _tmp_4.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_6 = _tmp_4.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_7 = _tmp_6.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_8 = _tmp_6.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_9 = _tmp_8.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_10 = _tmp_8.projection1();

            let mut copiedState = state.clone();
            copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("in_requestTargetSocket_Granted")); }
            result.insert((copiedState, "in_requestTargetSocket_Granted"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_13 = state._tr_in_requestTargetSocket_NotGranted(isCaching);
        for param in _trid_13.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_3 = _tmp_2.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_4 = _tmp_2.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_5 = _tmp_4.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_6 = _tmp_4.projection1();
            //model_check_transition_param_assignment
            let mut _tmp_7 = _tmp_6.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_8 = _tmp_6.projection1();

            let mut copiedState = state.clone();
            copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("in_requestTargetSocket_NotGranted")); }
            result.insert((copiedState, "in_requestTargetSocket_NotGranted"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_14 = state._tr_svc_register(isCaching);
        for param in _trid_14.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.svc_register(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("svc_register")); }
            result.insert((copiedState, "svc_register"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &nota_v2, last_op: &'static str, isCaching: bool) -> bool {
        if isCaching {
            let dependent_invariants_of_state = Self::get_invariant_dependencies(last_op);
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_1") {
                if !state._check_inv_1() {
                    println!("_check_inv_1 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_2") {
                if !state._check_inv_2() {
                    println!("_check_inv_2 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_3") {
                if !state._check_inv_3() {
                    println!("_check_inv_3 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_4") {
                if !state._check_inv_4() {
                    println!("_check_inv_4 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_5") {
                if !state._check_inv_5() {
                    println!("_check_inv_5 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_6") {
                if !state._check_inv_6() {
                    println!("_check_inv_6 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_7") {
                if !state._check_inv_7() {
                    println!("_check_inv_7 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_8") {
                if !state._check_inv_8() {
                    println!("_check_inv_8 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_9") {
                if !state._check_inv_9() {
                    println!("_check_inv_9 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_10") {
                if !state._check_inv_10() {
                    println!("_check_inv_10 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_11") {
                if !state._check_inv_11() {
                    println!("_check_inv_11 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_12") {
                if !state._check_inv_12() {
                    println!("_check_inv_12 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_13") {
                if !state._check_inv_13() {
                    println!("_check_inv_13 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_14") {
                if !state._check_inv_14() {
                    println!("_check_inv_14 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_15") {
                if !state._check_inv_15() {
                    println!("_check_inv_15 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_16") {
                if !state._check_inv_16() {
                    println!("_check_inv_16 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_17") {
                if !state._check_inv_17() {
                    println!("_check_inv_17 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_18") {
                if !state._check_inv_18() {
                    println!("_check_inv_18 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(nota_v2, &'static str)>>>, mc_type: MC_TYPE) -> (nota_v2, &'static str) {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn get_guard_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "in_register_success" => vec!["_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"],
            //model_check_init_static
            "in_announceResourceManager" => vec!["_tr_in_announceResourceManager"],
            //model_check_init_static
            "in_requestTargetSocket_Granted" => vec!["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"],
            //model_check_init_static
            "constructor_service" => vec!["_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"],
            //model_check_init_static
            "constructor_socket" => vec!["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"],
            //model_check_init_static
            "in_requestTargetSocket_NotGranted" => vec![],
            //model_check_init_static
            "constructor_interconnectNode" => vec!["_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"],
            //model_check_init_static
            "rm_getSid" => vec![],
            //model_check_init_static
            "rm_deregister" => vec![],
            //model_check_init_static
            "constructor_resourceManager" => vec!["_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"],
            //model_check_init_static
            "in_register_failed" => vec![],
            //model_check_init_static
            "rm_register" => vec![],
            //model_check_init_static
            "rm_getSid_Not_Found" => vec![],
            //model_check_init_static
            "svc_register" => vec!["_tr_svc_register"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "in_register_success" => vec!["_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"],
            //model_check_init_static
            "in_announceResourceManager" => vec!["_check_inv_11"],
            //model_check_init_static
            "in_requestTargetSocket_Granted" => vec!["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"],
            //model_check_init_static
            "constructor_service" => vec!["_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"],
            //model_check_init_static
            "constructor_socket" => vec!["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"],
            //model_check_init_static
            "in_requestTargetSocket_NotGranted" => vec![],
            //model_check_init_static
            "constructor_interconnectNode" => vec!["_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"],
            //model_check_init_static
            "rm_getSid" => vec![],
            //model_check_init_static
            "rm_deregister" => vec![],
            //model_check_init_static
            "constructor_resourceManager" => vec!["_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"],
            //model_check_init_static
            "in_register_failed" => vec![],
            //model_check_init_static
            "rm_register" => vec![],
            //model_check_init_static
            "rm_getSid_Not_Found" => vec![],
            //model_check_init_static
            "svc_register" => vec!["_check_inv_17"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = nota_v2::new();

        let mut all_states = HashSet::<nota_v2>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(nota_v2, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine.clone(), ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;

        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, Arc::clone(&num_transitions));

            if !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if next_states.is_empty() {
                print!("DEADLOCK DETECTED");
                stop_threads = true;
            }

            next_states.into_iter()
                       .filter(|(next_state, _)| all_states.insert((*next_state).clone()))
                       .for_each(|(next_state, last_op)| states_to_process_mutex.lock().unwrap().push_back((next_state, last_op)));

            if all_states.len() % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }
        }
        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = nota_v2::new();

        let all_states = Arc::new(DashSet::<nota_v2>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(nota_v2, &'static str)>::new()));
        states_to_process_mutex.lock().unwrap().push_back((machine, ""));

        let num_transitions = Arc::new(AtomicU64::new(0));

        let mut stop_threads = false;
        let mut spawned_tasks: u64 = 0;
        let mut finished_tasks: u64 = 0;

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads && !states_to_process_mutex.lock().unwrap().is_empty() {
            let (mut state, last_op) = Self::next(Arc::clone(&states_to_process_mutex), mc_type);

            let states_to_process = Arc::clone(&states_to_process_mutex);
            let transitions = Arc::clone(&num_transitions);
            let states = Arc::clone(&all_states);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                if !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }
                //println!("Thread {:?} done", thread::current().id());
                let _ = tx.send(Ok(1));
            });

            spawned_tasks += 1;
            if spawned_tasks % 50000 == 0 {
                println!("VISITED STATES: {}", all_states.len());
                println!("EVALUATED TRANSITIONS: {}", num_transitions.load(Ordering::Acquire));
                println!("-------------------");
            }

            while states_to_process_mutex.lock().unwrap().is_empty() && spawned_tasks - finished_tasks > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                match rx.try_recv() {
                    Ok(val)  => match val {
                            Ok(_) => finished_tasks += 1,
                            Err(msg) => { println!("{}", msg); stop_threads = true; },
                        },
                    Err(_) => (),
                }
                if threadPool.panic_count() > 0 { stop_threads = true; }
            }
        }

        Self::print_result(all_states.len(), num_transitions.load(Ordering::Acquire), stop_threads);
    }

}


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    if threads == 1 {
        nota_v2::model_check_single_threaded(mc_type, is_caching);
    } else {
        nota_v2::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
