#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::env;
use std::sync::atomic::{AtomicI32, AtomicI64, AtomicBool, Ordering};
use std::sync::{Arc, Mutex};
use std::thread;
use std::collections::{HashMap, HashSet, LinkedList};
use im::HashMap as PersistentHashMap;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
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


    pub fn equal(&self, other: &_Struct5) -> BBoolean {
        return BBoolean::new(self.soc == other.soc && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct5) -> BBoolean {
        return BBoolean::new(self.soc != other.soc || self.err != other.err);
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


    pub fn equal(&self, other: &_Struct3) -> BBoolean {
        return BBoolean::new(self.sid == other.sid && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct3) -> BBoolean {
        return BBoolean::new(self.sid != other.sid || self.err != other.err);
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


    pub fn equal(&self, other: &_Struct1) -> BBoolean {
        return BBoolean::new(self.sid == other.sid && self.err == other.err);
    }

    pub fn unequal(&self, other: &_Struct1) -> BBoolean {
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

    pub fn get_interconnectNodes(&self) -> BSet<INTERCONNECTNODE> {
        return self.interconnectNodes.clone();
    }

    pub fn get_sockets(&self) -> BSet<SOCKET> {
        return self.sockets.clone();
    }

    pub fn get_services(&self) -> BSet<SERVICE> {
        return self.services.clone();
    }

    pub fn get_resourceManagers(&self) -> BSet<RESOURCEMANAGER> {
        return self.resourceManagers.clone();
    }

    pub fn get_sids(&self) -> BSet<SID> {
        return self.sids.clone();
    }

    pub fn get_rm_services(&self) -> BRelation<RESOURCEMANAGER, BSet<SERVICE>> {
        return self.rm_services.clone();
    }

    pub fn get_rm_sids(&self) -> BRelation<SERVICE, SID> {
        return self.rm_sids.clone();
    }

    pub fn get_in_localServices(&self) -> BRelation<SID, INTERCONNECTNODE> {
        return self.in_localServices.clone();
    }

    pub fn get_in_sockets(&self) -> BRelation<SOCKET, INTERCONNECTNODE> {
        return self.in_sockets.clone();
    }

    pub fn get_in_resourceManager(&self) -> BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> {
        return self.in_resourceManager.clone();
    }

    pub fn get_soc_to(&self) -> BRelation<SOCKET, SID> {
        return self.soc_to.clone();
    }

    pub fn get_soc_from(&self) -> BRelation<SOCKET, SID> {
        return self.soc_from.clone();
    }

    pub fn get_svc_serviceID(&self) -> BRelation<SERVICE, SID> {
        return self.svc_serviceID.clone();
    }

    pub fn get_svc_sockets(&self) -> BRelation<SERVICE, BSet<SOCKET>> {
        return self.svc_sockets.clone();
    }

    pub fn get_svc_ICNode(&self) -> BRelation<SERVICE, INTERCONNECTNODE> {
        return self.svc_ICNode.clone();
    }

    pub fn get_svc_registered(&self) -> BRelation<SERVICE, BBoolean> {
        return self.svc_registered.clone();
    }

    pub fn get__INTERCONNECTNODE(&self) -> BSet<INTERCONNECTNODE> {
        return self._INTERCONNECTNODE.clone();
    }

    pub fn get__SOCKET(&self) -> BSet<SOCKET> {
        return self._SOCKET.clone();
    }

    pub fn get__SERVICE(&self) -> BSet<SERVICE> {
        return self._SERVICE.clone();
    }

    pub fn get__RESOURCEMANAGER(&self) -> BSet<RESOURCEMANAGER> {
        return self._RESOURCEMANAGER.clone();
    }

    pub fn get__SID(&self) -> BSet<SID> {
        return self._SID.clone();
    }

    pub fn get__RM_ERROR_CODES(&self) -> BSet<RM_ERROR_CODES> {
        return self._RM_ERROR_CODES.clone();
    }

    pub fn get__IN_ERROR_CODES(&self) -> BSet<IN_ERROR_CODES> {
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
            for _ic_newrm_1 in self._RESOURCEMANAGER.difference(&self.resourceManagers).clone().iter().cloned() {
                if (self.rm_services.domain().notElementOf(&_ic_newrm_1).and(&self.resourceManagers.equal(&BSet::new(vec![])))).booleanValue() {
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
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                    for _ic_srcsoc_1 in self.sockets.clone().iter().cloned() {
                        for _ic_srcsid_1 in self.sids.clone().iter().cloned() {
                            for _ic_targsid_1 in self.sids.clone().iter().cloned() {
                                for _ic_newsoc_1 in self._SOCKET.difference(&self.sockets).clone().iter().cloned() {
                                    if (_ic_self_1.unequal(&_ic_ii_1).and(&self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1))).booleanValue() {
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
            for _ic_self_1 in self.interconnectNodes.clone().iter().cloned() {
                for _ic_ii_1 in self.interconnectNodes.clone().iter().cloned() {
                    for _ic_srcsoc_1 in self.sockets.clone().iter().cloned() {
                        for _ic_srcsid_1 in self.sids.clone().iter().cloned() {
                            for _ic_targsid_1 in self.sids.clone().iter().cloned() {
                                if (_ic_self_1.unequal(&_ic_ii_1).and(&self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1))).booleanValue() {
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

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
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
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<nota_v2, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<nota_v2, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<nota_v2, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<nota_v2, nota_v2>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<nota_v2> {
        let mut result = HashSet::<nota_v2>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_constructor_interconnectNode(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.constructor_interconnectNode(_tmp_1);
                match guard_dependency.get("constructor_interconnectNode") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("constructor_interconnectNode").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("constructor_interconnectNode").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_constructor_resourceManager(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.constructor_resourceManager(_tmp_1);
                match guard_dependency.get("constructor_resourceManager") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("constructor_resourceManager").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("constructor_resourceManager").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("constructor_service") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("constructor_service").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("constructor_service").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("constructor_socket") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("constructor_socket").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("constructor_socket").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_register") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("rm_register").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("rm_register").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_deregister") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("rm_deregister").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("rm_deregister").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_getSid") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("rm_getSid").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("rm_getSid").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_getSid_Not_Found") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("rm_getSid_Not_Found").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("rm_getSid_Not_Found").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_announceResourceManager") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("in_announceResourceManager").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("in_announceResourceManager").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_register_success") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("in_register_success").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("in_register_success").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_register_failed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("in_register_failed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("in_register_failed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_requestTargetSocket_Granted") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("in_requestTargetSocket_Granted").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("in_requestTargetSocket_Granted").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_requestTargetSocket_NotGranted") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("in_requestTargetSocket_NotGranted").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("in_requestTargetSocket_NotGranted").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_14 = state._tr_svc_register(isCaching);
            for param in _trid_14.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.svc_register(_tmp_1);
                match guard_dependency.get("svc_register") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("svc_register").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("svc_register").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

            guardCache.lock().unwrap().insert(state.clone(), newCache);
        } else {
            //model_check_transition
            let mut _trid_1 = state._tr_constructor_interconnectNode(isCaching);
            for param in _trid_1.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.constructor_interconnectNode(_tmp_1);
                match guard_dependency.get("constructor_interconnectNode") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_constructor_resourceManager(isCaching);
            for param in _trid_2.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.constructor_resourceManager(_tmp_1);
                match guard_dependency.get("constructor_resourceManager") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("constructor_service") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("constructor_socket") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_register") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_deregister") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_getSid") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("rm_getSid_Not_Found") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_announceResourceManager") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_register_success") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_register_failed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_requestTargetSocket_Granted") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("in_requestTargetSocket_NotGranted") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_14 = state._tr_svc_register(isCaching);
            for param in _trid_14.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.svc_register(_tmp_1);
                match guard_dependency.get("svc_register") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &nota_v2,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<nota_v2, HashSet<&str>>>> ) -> bool {
        let cached_invariants = dependent_invariant_m.lock().unwrap().get(&state).cloned();
        if cached_invariants.is_some() && isCaching {
            let dependent_invariants_of_state = cached_invariants.unwrap().clone();
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_1") {
                if !state._check_inv_1() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_2") {
                if !state._check_inv_2() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_3") {
                if !state._check_inv_3() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_4") {
                if !state._check_inv_4() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_5") {
                if !state._check_inv_5() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_6") {
                if !state._check_inv_6() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_7") {
                if !state._check_inv_7() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_8") {
                if !state._check_inv_8() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_9") {
                if !state._check_inv_9() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_10") {
                if !state._check_inv_10() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_11") {
                if !state._check_inv_11() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_12") {
                if !state._check_inv_12() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_13") {
                if !state._check_inv_13() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_14") {
                if !state._check_inv_14() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_15") {
                if !state._check_inv_15() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_16") {
                if !state._check_inv_16() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_17") {
                if !state._check_inv_17() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_18") {
                if !state._check_inv_18() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18());
    }

    //model_check_print
    fn print_result(states: i64, transitions: i64, deadlock_detected: bool, invariant_violated: bool) {
        if deadlock_detected { println!("DEADLOCK DETECTED"); }
        if invariant_violated { println!("INVARIANT VIOLATED"); }
        if !deadlock_detected && !invariant_violated { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<nota_v2>>>, mc_type: MC_TYPE) -> nota_v2 {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
            MC_TYPE::BFS   => collection.pop_front().unwrap(),
            MC_TYPE::DFS   => collection.pop_back().unwrap(),
            MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
        };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = nota_v2::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<nota_v2>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<nota_v2>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<nota_v2, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<nota_v2, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<nota_v2, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<nota_v2, nota_v2>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("in_register_success", HashSet::from(["_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("in_announceResourceManager", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("in_requestTargetSocket_Granted", HashSet::from(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("constructor_service", HashSet::from(["_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("constructor_socket", HashSet::from(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("in_requestTargetSocket_NotGranted", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("constructor_interconnectNode", HashSet::from(["_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("rm_getSid", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_deregister", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("constructor_resourceManager", HashSet::from(["_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("in_register_failed", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_register", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_getSid_Not_Found", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("svc_register", HashSet::from(["_check_inv_17"]));
            //model_check_init_static
            guardDependency.insert("in_register_success", HashSet::from(["_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("in_announceResourceManager", HashSet::from(["_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("in_requestTargetSocket_Granted", HashSet::from(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("constructor_service", HashSet::from(["_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"]));
            //model_check_init_static
            guardDependency.insert("constructor_socket", HashSet::from(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("in_requestTargetSocket_NotGranted", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("constructor_interconnectNode", HashSet::from(["_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("rm_getSid", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_deregister", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("constructor_resourceManager", HashSet::from(["_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("in_register_failed", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_register", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_getSid_Not_Found", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("svc_register", HashSet::from(["_tr_svc_register"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().cloned().for_each(|next_state| {
                if !states.contains(&next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state);
                    if cnum_states % 50000 == 0 {
                        println!("VISITED STATES: {}", cnum_states);
                        println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                        println!("-------------------");
                    }
                }
            });

            if next_states.is_empty() {
                deadlock_detected.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

            if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m)) {
                invariant_violated.store(true, Ordering::Release);
                stop_threads.store(true, Ordering::Release);
            }

        }
        Self::print_result(number_states.load(Ordering::Acquire), transitions.load(Ordering::Acquire), deadlock_detected.load(Ordering::Acquire), invariant_violated.load(Ordering::Acquire));
    }

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool) {
        let threadPool = ThreadPool::new(threads);

        let machine = nota_v2::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() {
            invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<nota_v2>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<nota_v2>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<nota_v2, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<nota_v2, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<nota_v2, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<nota_v2, nota_v2>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("in_register_success", HashSet::from(["_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"]));
            //model_check_init_static
            invariantDependency.insert("in_announceResourceManager", HashSet::from(["_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("in_requestTargetSocket_Granted", HashSet::from(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("constructor_service", HashSet::from(["_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"]));
            //model_check_init_static
            invariantDependency.insert("constructor_socket", HashSet::from(["_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"]));
            //model_check_init_static
            invariantDependency.insert("in_requestTargetSocket_NotGranted", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("constructor_interconnectNode", HashSet::from(["_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("rm_getSid", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_deregister", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("constructor_resourceManager", HashSet::from(["_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("in_register_failed", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_register", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("rm_getSid_Not_Found", HashSet::from([]));
            //model_check_init_static
            invariantDependency.insert("svc_register", HashSet::from(["_check_inv_17"]));
            //model_check_init_static
            guardDependency.insert("in_register_success", HashSet::from(["_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("in_announceResourceManager", HashSet::from(["_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("in_requestTargetSocket_Granted", HashSet::from(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("constructor_service", HashSet::from(["_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"]));
            //model_check_init_static
            guardDependency.insert("constructor_socket", HashSet::from(["_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"]));
            //model_check_init_static
            guardDependency.insert("in_requestTargetSocket_NotGranted", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("constructor_interconnectNode", HashSet::from(["_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("rm_getSid", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_deregister", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("constructor_resourceManager", HashSet::from(["_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"]));
            //model_check_init_static
            guardDependency.insert("in_register_failed", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_register", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("rm_getSid_Not_Found", HashSet::from([]));
            //model_check_init_static
            guardDependency.insert("svc_register", HashSet::from(["_tr_svc_register"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let num_transitions = Arc::new(AtomicI64::new(0));
        let invariant_dependency_arc = Arc::new(invariantDependency);
        let guard_dependency_arc = Arc::new(guardDependency);

        let (tx, rx) = channel();
        //println!("Thread {:?} starting threads", thread::current().id());
        while !stop_threads_b.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            possible_queue_changes_b.fetch_add(1, Ordering::AcqRel);
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let invariant_violated = Arc::clone(&invariant_violated_b);
            let deadlock_detected = Arc::clone(&deadlock_detected_b);
            let stop_threads = Arc::clone(&stop_threads_b);
            let possible_queue_changes = Arc::clone(&possible_queue_changes_b);
            let collection_m2 = Arc::clone(&collection_m);
            let invariant_dependency = Arc::clone(&invariant_dependency_arc);
            let guard_dependency = Arc::clone(&guard_dependency_arc);
            let dependent_invariant_m2 = Arc::clone(&dependent_invariant_m);
            let dependent_guard_m2 = Arc::clone(&dependent_guard_m);
            let parents_m2 = Arc::clone(&parents_m);
            let guard_cache = Arc::clone(&guard_cache_b);
            let transitions = Arc::clone(&num_transitions);
            let states_m2 = Arc::clone(&states_m);
            let number_states = Arc::clone(&number_states_arc);
            let tx = tx.clone();
            //println!("Thread {:?} spawning a thread", thread::current().id());
            threadPool.execute(move|| {
                let next_states = Self::generateNextStates(&mut state, is_caching, &invariant_dependency, Arc::clone(&dependent_invariant_m2), &guard_dependency, dependent_guard_m2, guard_cache, parents_m2, Arc::clone(&transitions));

                //println!("Thread {:?} executing", thread::current().id());
                next_states.iter().cloned().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(&next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state);
                            //println!("Thread {:?}: states in collection {}", thread::current().id(), collection.len());
                            if cnum_states % 50000 == 0 {
                                println!("VISITED STATES: {}", cnum_states);
                                println!("EVALUATED TRANSITIONS: {}", transitions.load(Ordering::Acquire));
                                println!("-------------------");
                            }
                        }
                    }
                });
                possible_queue_changes.fetch_sub(1, Ordering::AcqRel);

                if next_states.is_empty() {
                    deadlock_detected.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }

                if !Self::checkInvariants(&state, is_caching, Arc::clone(&dependent_invariant_m2)) {
                    invariant_violated.store(true, Ordering::Release);
                    stop_threads.store(true, Ordering::Release);
                }
                //println!("Thread {:?} done", thread::current().id());
                tx.send(1).expect("");
            });
            while collection_m.lock().unwrap().is_empty() && possible_queue_changes_b.load(Ordering::Acquire) > 0 {
                //println!("Thread {:?} (main) waiting for a thread to finish", thread::current().id());
                rx.recv().expect("Waiting for a thread to finish: ");
            }
        }

        Self::print_result(number_states_arc.load(Ordering::Acquire), num_transitions.load(Ordering::Acquire), deadlock_detected_b.load(Ordering::Acquire), invariant_violated_b.load(Ordering::Acquire));
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
