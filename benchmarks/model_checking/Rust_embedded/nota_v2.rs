#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
//#![no_std] //std is enabled for the generated machine by default, since without it there is no println which makes unit-testing very difficult
use btypes::{bset, brel};
use btypes::bset::BSet;
use btypes::bset::SetItem;
use btypes::bset::PowSetItem;
use btypes::bset::PowAble;
use btypes::bset::NestedSet;
use btypes::brelation::BRelation;
use btypes::brelation::RelLeftItem;
use btypes::brelation::RelPowAble;
use btypes::bboolean::BBoolean;
use btypes::bboolean::BBool;
use btypes::bboolean::BOOL;
use btypes::binteger::BInteger;
use btypes::binteger::BInt;
use btypes::binteger::set_BInteger;
use btypes::btuple::BTuple;

use std::env;
use std::sync::atomic::{AtomicU64, Ordering};
use std::sync::{Arc, mpsc, Mutex};
use std::collections::{HashSet, LinkedList};
use dashmap::DashSet;
use threadpool::ThreadPool;
use std::sync::mpsc::channel;
use derivative::Derivative;
use std::time::{Duration};



#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct5 {
    soc: set_SOCKET,
    err: IN_ERROR_CODES,
}

impl _Struct5 {
    pub fn new(mut soc: set_SOCKET, mut err: IN_ERROR_CODES) -> _Struct5 {
        let mut m: _Struct5 = Default::default();
        //record_field_initialization
        m.soc = soc;//record_field_initialization
        m.err = err;
        return m;
    }

    //record_field_get
    pub fn get_soc(&self) -> set_SOCKET {
        return self.soc.clone();
    }

    //record_field_get
    pub fn get_err(&self) -> IN_ERROR_CODES {
        return self.err.clone();
    }

    //record_field_override
    pub fn override_soc(&self, soc: set_SOCKET) -> _Struct5 {
        return _Struct5::new(soc.clone(), self.err.clone());
    }


    //record_field_override
    pub fn override_err(&self, err: IN_ERROR_CODES) -> _Struct5 {
        return _Struct5::new(self.soc.clone(), err.clone());
    }


    pub fn equal(&self, other: &_Struct5) -> bool {
        return self.soc == other.soc && self.err == other.err;
    }

    pub fn unequal(&self, other: &_Struct5) -> bool {
        return self.soc != other.soc || self.err != other.err;
    }

}

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct1 {
    sid: set_SID,
    err: RM_ERROR_CODES,
}

impl _Struct1 {
    pub fn new(mut sid: set_SID, mut err: RM_ERROR_CODES) -> _Struct1 {
        let mut m: _Struct1 = Default::default();
        //record_field_initialization
        m.sid = sid;//record_field_initialization
        m.err = err;
        return m;
    }

    //record_field_get
    pub fn get_sid(&self) -> set_SID {
        return self.sid.clone();
    }

    //record_field_get
    pub fn get_err(&self) -> RM_ERROR_CODES {
        return self.err.clone();
    }

    //record_field_override
    pub fn override_sid(&self, sid: set_SID) -> _Struct1 {
        return _Struct1::new(sid.clone(), self.err.clone());
    }


    //record_field_override
    pub fn override_err(&self, err: RM_ERROR_CODES) -> _Struct1 {
        return _Struct1::new(self.sid.clone(), err.clone());
    }


    pub fn equal(&self, other: &_Struct1) -> bool {
        return self.sid == other.sid && self.err == other.err;
    }

    pub fn unequal(&self, other: &_Struct1) -> bool {
        return self.sid != other.sid || self.err != other.err;
    }

}

#[derive(Default, Debug, Clone, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct _Struct3 {
    sid: set_SID,
    err: IN_ERROR_CODES,
}

impl _Struct3 {
    pub fn new(mut sid: set_SID, mut err: IN_ERROR_CODES) -> _Struct3 {
        let mut m: _Struct3 = Default::default();
        //record_field_initialization
        m.sid = sid;//record_field_initialization
        m.err = err;
        return m;
    }

    //record_field_get
    pub fn get_sid(&self) -> set_SID {
        return self.sid.clone();
    }

    //record_field_get
    pub fn get_err(&self) -> IN_ERROR_CODES {
        return self.err.clone();
    }

    //record_field_override
    pub fn override_sid(&self, sid: set_SID) -> _Struct3 {
        return _Struct3::new(sid.clone(), self.err.clone());
    }


    //record_field_override
    pub fn override_err(&self, err: IN_ERROR_CODES) -> _Struct3 {
        return _Struct3::new(self.sid.clone(), err.clone());
    }


    pub fn equal(&self, other: &_Struct3) -> bool {
        return self.sid == other.sid && self.err == other.err;
    }

    pub fn unequal(&self, other: &_Struct3) -> bool {
        return self.sid != other.sid || self.err != other.err;
    }

}

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum INTERCONNECTNODE {
    #[default]
    node1 = 0, 
    node2 = 1
}

impl INTERCONNECTNODE {
    pub fn equal(&self, other: &INTERCONNECTNODE) -> bool { *self == *other }
    pub fn unequal(&self, other: &INTERCONNECTNODE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::node1, 
            1 => Self::node2, 
            _ => panic!("INTERCONNECTNODE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for INTERCONNECTNODE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_INTERCONNECTNODE = BSet<INTERCONNECTNODE, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SOCKET {
    #[default]
    socket1 = 0, 
    socket2 = 1
}

impl SOCKET {
    pub fn equal(&self, other: &SOCKET) -> bool { *self == *other }
    pub fn unequal(&self, other: &SOCKET) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::socket1, 
            1 => Self::socket2, 
            _ => panic!("SOCKET index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for SOCKET {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_SOCKET = BSet<SOCKET, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE {
    #[default]
    service1 = 0, 
    service2 = 1
}

impl SERVICE {
    pub fn equal(&self, other: &SERVICE) -> bool { *self == *other }
    pub fn unequal(&self, other: &SERVICE) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::service1, 
            1 => Self::service2, 
            _ => panic!("SERVICE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for SERVICE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_SERVICE = BSet<SERVICE, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RESOURCEMANAGER {
    #[default]
    resource1 = 0, 
    resource2 = 1
}

impl RESOURCEMANAGER {
    pub fn equal(&self, other: &RESOURCEMANAGER) -> bool { *self == *other }
    pub fn unequal(&self, other: &RESOURCEMANAGER) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::resource1, 
            1 => Self::resource2, 
            _ => panic!("RESOURCEMANAGER index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for RESOURCEMANAGER {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_RESOURCEMANAGER = BSet<RESOURCEMANAGER, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SID {
    #[default]
    SID1 = 0, 
    SID2 = 1
}

impl SID {
    pub fn equal(&self, other: &SID) -> bool { *self == *other }
    pub fn unequal(&self, other: &SID) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SID1, 
            1 => Self::SID2, 
            _ => panic!("SID index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for SID {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_SID = BSet<SID, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RM_ERROR_CODES {
    #[default]
    RM_SERVICE_FOUND = 0, 
    RM_SERVICE_NOT_FOUND = 1
}

impl RM_ERROR_CODES {
    pub fn equal(&self, other: &RM_ERROR_CODES) -> bool { *self == *other }
    pub fn unequal(&self, other: &RM_ERROR_CODES) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::RM_SERVICE_FOUND, 
            1 => Self::RM_SERVICE_NOT_FOUND, 
            _ => panic!("RM_ERROR_CODES index out of range! {:?}", idx)
        }
    }
}

impl SetItem<2> for RM_ERROR_CODES {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_RM_ERROR_CODES = BSet<RM_ERROR_CODES, 2>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum IN_ERROR_CODES {
    #[default]
    IN_REGISTRATION_OK = 0, 
    IN_REGISTRATION_FAILED = 1, 
    IN_DEREGISTRATION_OK = 2, 
    IN_DEREGISTRATION_FAILED = 3, 
    IN_NO_SOCKET_CONNECTION = 4, 
    IN_SOCKET_CONNECTION_OK = 5, 
    IN_NO_AVAILABLE_SERVICE = 6, 
    IN_SERVICE_AVAILABLE = 7, 
    IN_TARGET_SOCKET_GRANTED = 8, 
    IN_TARGET_SOCKET_NOT_GRANTED = 9
}

impl IN_ERROR_CODES {
    pub fn equal(&self, other: &IN_ERROR_CODES) -> bool { *self == *other }
    pub fn unequal(&self, other: &IN_ERROR_CODES) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::IN_REGISTRATION_OK, 
            1 => Self::IN_REGISTRATION_FAILED, 
            2 => Self::IN_DEREGISTRATION_OK, 
            3 => Self::IN_DEREGISTRATION_FAILED, 
            4 => Self::IN_NO_SOCKET_CONNECTION, 
            5 => Self::IN_SOCKET_CONNECTION_OK, 
            6 => Self::IN_NO_AVAILABLE_SERVICE, 
            7 => Self::IN_SERVICE_AVAILABLE, 
            8 => Self::IN_TARGET_SOCKET_GRANTED, 
            9 => Self::IN_TARGET_SOCKET_NOT_GRANTED, 
            _ => panic!("IN_ERROR_CODES index out of range! {:?}", idx)
        }
    }
}

impl SetItem<10> for IN_ERROR_CODES {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_IN_ERROR_CODES = BSet<IN_ERROR_CODES, 10>;
//set_enum_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SOCKET_X_INTERCONNECTNODE {
    #[default]
    socket1_node1 = 0, 
    socket1_node2 = 1, 
    socket2_node1 = 2, 
    socket2_node2 = 3
}
type rel_SOCKET_X_INTERCONNECTNODE = BRelation<SOCKET, { SOCKET::VARIANTS }, INTERCONNECTNODE, { INTERCONNECTNODE::VARIANTS }, 4>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RESOURCEMANAGER_X_SetSERVICE {
    #[default]
    resource1_SET__TES = 0, 
    resource1_SET_service1_TES = 1, 
    resource1_SET_service2_TES = 2, 
    resource1_SET_service1__service2_TES = 3, 
    resource2_SET__TES = 4, 
    resource2_SET_service1_TES = 5, 
    resource2_SET_service2_TES = 6, 
    resource2_SET_service1__service2_TES = 7
}
type rel_RESOURCEMANAGER_X_SetSERVICE = BRelation<RESOURCEMANAGER, { RESOURCEMANAGER::VARIANTS }, set_SERVICE, { set_SERVICE::VARIANTS }, 8>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum INTERCONNECTNODE_X_SetRESOURCEMANAGER {
    #[default]
    node1_SET__TES = 0, 
    node1_SET_resource1_TES = 1, 
    node1_SET_resource2_TES = 2, 
    node1_SET_resource1__resource2_TES = 3, 
    node2_SET__TES = 4, 
    node2_SET_resource1_TES = 5, 
    node2_SET_resource2_TES = 6, 
    node2_SET_resource1__resource2_TES = 7
}
type rel_INTERCONNECTNODE_X_SetRESOURCEMANAGER = BRelation<INTERCONNECTNODE, { INTERCONNECTNODE::VARIANTS }, set_RESOURCEMANAGER, { set_RESOURCEMANAGER::VARIANTS }, 8>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE_X_SID {
    #[default]
    service1_SID1 = 0, 
    service1_SID2 = 1, 
    service2_SID1 = 2, 
    service2_SID2 = 3
}
type rel_SERVICE_X_SID = BRelation<SERVICE, { SERVICE::VARIANTS }, SID, { SID::VARIANTS }, 4>;
//relation_declaration done









//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SID_X_INTERCONNECTNODE {
    #[default]
    SID1_node1 = 0, 
    SID1_node2 = 1, 
    SID2_node1 = 2, 
    SID2_node2 = 3
}
type rel_SID_X_INTERCONNECTNODE = BRelation<SID, { SID::VARIANTS }, INTERCONNECTNODE, { INTERCONNECTNODE::VARIANTS }, 4>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE_X_INTERCONNECTNODE {
    #[default]
    service1_node1 = 0, 
    service1_node2 = 1, 
    service2_node1 = 2, 
    service2_node2 = 3
}
type rel_SERVICE_X_INTERCONNECTNODE = BRelation<SERVICE, { SERVICE::VARIANTS }, INTERCONNECTNODE, { INTERCONNECTNODE::VARIANTS }, 4>;
//relation_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SOCKET_X_SID {
    #[default]
    socket1_SID1 = 0, 
    socket1_SID2 = 1, 
    socket2_SID1 = 2, 
    socket2_SID2 = 3
}
type rel_SOCKET_X_SID = BRelation<SOCKET, { SOCKET::VARIANTS }, SID, { SID::VARIANTS }, 4>;
//relation_declaration done



//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE_X_SetSOCKET {
    #[default]
    service1_SET__TES = 0, 
    service1_SET_socket1_TES = 1, 
    service1_SET_socket2_TES = 2, 
    service1_SET_socket1__socket2_TES = 3, 
    service2_SET__TES = 4, 
    service2_SET_socket1_TES = 5, 
    service2_SET_socket2_TES = 6, 
    service2_SET_socket1__socket2_TES = 7
}
type rel_SERVICE_X_SetSOCKET = BRelation<SERVICE, { SERVICE::VARIANTS }, set_SOCKET, { set_SOCKET::VARIANTS }, 8>;
//relation_declaration done



//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetRESOURCEMANAGER {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_resource1_TES_TES = 1, 
    SET_SET_resource2_TES_TES = 2, 
    SET_SET_resource1__resource2_TES_TES = 3
}
type set_SetRESOURCEMANAGER = BSet<set_RESOURCEMANAGER, 4>;

impl PowSetItem<4, 2> for RESOURCEMANAGER {
    type SetRepr = SetRESOURCEMANAGER;
    fn arr_to_idx(set: [bool; 2]) -> usize {
        match set {
            [false, false] => 0,
            [true, false] => 1,
            [false, true] => 2,
            [true, true] => 3,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 2] {
        match idx {
            0 => [false, false],
            1 => [true, false],
            2 => [false, true],
            3 => [true, true],
            _ => panic!("SetRESOURCEMANAGER index out of range! {:?}", idx)
        }
    }
}
impl SetRESOURCEMANAGER {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_resource1_TES_TES, 
            2 => Self::SET_SET_resource2_TES_TES, 
            3 => Self::SET_SET_resource1__resource2_TES_TES, 
            _ => panic!("SetRESOURCEMANAGER index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for SetRESOURCEMANAGER {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

//relation_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum SERVICE_X_BOOL {
    #[default]
    service1_BFALSE = 0, 
    service1_BTRUE = 1, 
    service2_BFALSE = 2, 
    service2_BTRUE = 3
}
type rel_SERVICE_X_BOOL = BRelation<SERVICE, { SERVICE::VARIANTS }, BBoolean, { BBoolean::VARIANTS }, 4>;
//relation_declaration done

//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetSERVICE {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_service1_TES_TES = 1, 
    SET_SET_service2_TES_TES = 2, 
    SET_SET_service1__service2_TES_TES = 3
}
type set_SetSERVICE = BSet<set_SERVICE, 4>;

impl PowSetItem<4, 2> for SERVICE {
    type SetRepr = SetSERVICE;
    fn arr_to_idx(set: [bool; 2]) -> usize {
        match set {
            [false, false] => 0,
            [true, false] => 1,
            [false, true] => 2,
            [true, true] => 3,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 2] {
        match idx {
            0 => [false, false],
            1 => [true, false],
            2 => [false, true],
            3 => [true, true],
            _ => panic!("SetSERVICE index out of range! {:?}", idx)
        }
    }
}
impl SetSERVICE {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_service1_TES_TES, 
            2 => Self::SET_SET_service2_TES_TES, 
            3 => Self::SET_SET_service1__service2_TES_TES, 
            _ => panic!("SetSERVICE index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for SetSERVICE {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done



//enum_set_declaration start
#[derive(Default, Debug, Clone, Copy)]
// each enum value corresponds to one BSet
pub enum SetSOCKET {
    #[default]
    SET_SET__TES_TES = 0, 
    SET_SET_socket1_TES_TES = 1, 
    SET_SET_socket2_TES_TES = 2, 
    SET_SET_socket1__socket2_TES_TES = 3
}
type set_SetSOCKET = BSet<set_SOCKET, 4>;

impl PowSetItem<4, 2> for SOCKET {
    type SetRepr = SetSOCKET;
    fn arr_to_idx(set: [bool; 2]) -> usize {
        match set {
            [false, false] => 0,
            [true, false] => 1,
            [false, true] => 2,
            [true, true] => 3,
            _ => panic!("Attempting to convert non-existing set to index!") // only happens if this is a const-set and code-generation missed a necessary value
        }
    }
    fn idx_to_arr(idx: usize) -> [bool; 2] {
        match idx {
            0 => [false, false],
            1 => [true, false],
            2 => [false, true],
            3 => [true, true],
            _ => panic!("SetSOCKET index out of range! {:?}", idx)
        }
    }
}
impl SetSOCKET {
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::SET_SET__TES_TES, 
            1 => Self::SET_SET_socket1_TES_TES, 
            2 => Self::SET_SET_socket2_TES_TES, 
            3 => Self::SET_SET_socket1__socket2_TES_TES, 
            _ => panic!("SetSOCKET index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for SetSOCKET {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

//enum_set_declaration done

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct nota_v2 {
    /*declarations*/interconnectNodes: set_INTERCONNECTNODE,
    sockets: set_SOCKET,
    services: set_SERVICE,
    resourceManagers: set_RESOURCEMANAGER,
    sids: set_SID,
    rm_services: rel_RESOURCEMANAGER_X_SetSERVICE,
    rm_sids: rel_SERVICE_X_SID,
    in_localServices: rel_SID_X_INTERCONNECTNODE,
    in_sockets: rel_SOCKET_X_INTERCONNECTNODE,
    in_resourceManager: rel_INTERCONNECTNODE_X_SetRESOURCEMANAGER,
    soc_to: rel_SOCKET_X_SID,
    soc_from: rel_SOCKET_X_SID,
    svc_serviceID: rel_SERVICE_X_SID,
    svc_sockets: rel_SERVICE_X_SetSOCKET,
    svc_ICNode: rel_SERVICE_X_INTERCONNECTNODE,
    svc_registered: rel_SERVICE_X_BOOL,
    /*sets*//*set_declaration*/_INTERCONNECTNODE: set_INTERCONNECTNODE,
    /*set_declaration*/_SOCKET: set_SOCKET,
    /*set_declaration*/_SERVICE: set_SERVICE,
    /*set_declaration*/_RESOURCEMANAGER: set_RESOURCEMANAGER,
    /*set_declaration*/_SID: set_SID,
    /*set_declaration*/_RM_ERROR_CODES: set_RM_ERROR_CODES,
    /*set_declaration*/_IN_ERROR_CODES: set_IN_ERROR_CODES,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_interconnectNode: Option<HashSet<INTERCONNECTNODE>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_resourceManager: Option<HashSet<RESOURCEMANAGER>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_service: Option<HashSet<(INTERCONNECTNODE, SERVICE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_constructor_socket: Option<HashSet<(((INTERCONNECTNODE, SID), SID), SOCKET)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_register: Option<HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_deregister: Option<HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_getSid: Option<HashSet<(RESOURCEMANAGER, SERVICE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_rm_getSid_Not_Found: Option<HashSet<(RESOURCEMANAGER, SERVICE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_announceResourceManager: Option<HashSet<(INTERCONNECTNODE, RESOURCEMANAGER)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_register_success: Option<HashSet<((INTERCONNECTNODE, SERVICE), SID)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_register_failed: Option<HashSet<(INTERCONNECTNODE, SERVICE)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_requestTargetSocket_Granted: Option<HashSet<(((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID), SOCKET)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_in_requestTargetSocket_NotGranted: Option<HashSet<((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_svc_register: Option<HashSet<SERVICE>>,}


impl nota_v2 {

    pub fn new() -> nota_v2 {
        //values: ''
        let mut m: nota_v2 = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._INTERCONNECTNODE = bset![INTERCONNECTNODE, /*enum_call*/INTERCONNECTNODE::node1, /*enum_call*/INTERCONNECTNODE::node2];
    //set_initialization
    self._SOCKET = bset![SOCKET, /*enum_call*/SOCKET::socket1, /*enum_call*/SOCKET::socket2];
    //set_initialization
    self._SERVICE = bset![SERVICE, /*enum_call*/SERVICE::service1, /*enum_call*/SERVICE::service2];
    //set_initialization
    self._RESOURCEMANAGER = bset![RESOURCEMANAGER, /*enum_call*/RESOURCEMANAGER::resource1, /*enum_call*/RESOURCEMANAGER::resource2];
    //set_initialization
    self._SID = bset![SID, /*enum_call*/SID::SID1, /*enum_call*/SID::SID2];
    //set_initialization
    self._RM_ERROR_CODES = bset![RM_ERROR_CODES, /*enum_call*/RM_ERROR_CODES::RM_SERVICE_FOUND, /*enum_call*/RM_ERROR_CODES::RM_SERVICE_NOT_FOUND];
    //set_initialization
    self._IN_ERROR_CODES = bset![IN_ERROR_CODES, /*enum_call*/IN_ERROR_CODES::IN_REGISTRATION_OK, /*enum_call*/IN_ERROR_CODES::IN_REGISTRATION_FAILED, /*enum_call*/IN_ERROR_CODES::IN_DEREGISTRATION_OK, /*enum_call*/IN_ERROR_CODES::IN_DEREGISTRATION_FAILED, /*enum_call*/IN_ERROR_CODES::IN_NO_SOCKET_CONNECTION, /*enum_call*/IN_ERROR_CODES::IN_SOCKET_CONNECTION_OK, /*enum_call*/IN_ERROR_CODES::IN_NO_AVAILABLE_SERVICE, /*enum_call*/IN_ERROR_CODES::IN_SERVICE_AVAILABLE, /*enum_call*/IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED, /*enum_call*/IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED];
        /*properties*/
        /*body*/self.interconnectNodes = bset![INTERCONNECTNODE].clone().clone();
    self.sockets = bset![SOCKET].clone().clone();
    self.services = bset![SERVICE].clone().clone();
    self.resourceManagers = bset![RESOURCEMANAGER].clone().clone();
    self.sids = bset![SID].clone().clone();
    self.rm_services = brel![rel_RESOURCEMANAGER_X_SetSERVICE].clone().clone();
    self.rm_sids = brel![rel_SERVICE_X_SID].clone().clone();
    self.in_localServices = brel![rel_SID_X_INTERCONNECTNODE].clone().clone();
    self.in_sockets = brel![rel_SOCKET_X_INTERCONNECTNODE].clone().clone();
    self.in_resourceManager = brel![rel_INTERCONNECTNODE_X_SetRESOURCEMANAGER].clone().clone();
    self.soc_to = brel![rel_SOCKET_X_SID].clone().clone();
    self.soc_from = brel![rel_SOCKET_X_SID].clone().clone();
    self.svc_serviceID = brel![rel_SERVICE_X_SID].clone().clone();
    self.svc_sockets = brel![rel_SERVICE_X_SetSOCKET].clone().clone();
    self.svc_ICNode = brel![rel_SERVICE_X_INTERCONNECTNODE].clone().clone();
    self.svc_registered = brel![rel_SERVICE_X_BOOL].clone().clone();
        /*includesInitialization*/
    }

    pub fn get_interconnectNodes(&self) -> set_INTERCONNECTNODE {
        return self.interconnectNodes.clone();
    }

    pub fn get_sockets(&self) -> set_SOCKET {
        return self.sockets.clone();
    }

    pub fn get_services(&self) -> set_SERVICE {
        return self.services.clone();
    }

    pub fn get_resourceManagers(&self) -> set_RESOURCEMANAGER {
        return self.resourceManagers.clone();
    }

    pub fn get_sids(&self) -> set_SID {
        return self.sids.clone();
    }

    pub fn get_rm_services(&self) -> rel_RESOURCEMANAGER_X_SetSERVICE {
        return self.rm_services.clone();
    }

    pub fn get_rm_sids(&self) -> rel_SERVICE_X_SID {
        return self.rm_sids.clone();
    }

    pub fn get_in_localServices(&self) -> rel_SID_X_INTERCONNECTNODE {
        return self.in_localServices.clone();
    }

    pub fn get_in_sockets(&self) -> rel_SOCKET_X_INTERCONNECTNODE {
        return self.in_sockets.clone();
    }

    pub fn get_in_resourceManager(&self) -> rel_INTERCONNECTNODE_X_SetRESOURCEMANAGER {
        return self.in_resourceManager.clone();
    }

    pub fn get_soc_to(&self) -> rel_SOCKET_X_SID {
        return self.soc_to.clone();
    }

    pub fn get_soc_from(&self) -> rel_SOCKET_X_SID {
        return self.soc_from.clone();
    }

    pub fn get_svc_serviceID(&self) -> rel_SERVICE_X_SID {
        return self.svc_serviceID.clone();
    }

    pub fn get_svc_sockets(&self) -> rel_SERVICE_X_SetSOCKET {
        return self.svc_sockets.clone();
    }

    pub fn get_svc_ICNode(&self) -> rel_SERVICE_X_INTERCONNECTNODE {
        return self.svc_ICNode.clone();
    }

    pub fn get_svc_registered(&self) -> rel_SERVICE_X_BOOL {
        return self.svc_registered.clone();
    }

    pub fn get__INTERCONNECTNODE(&self) -> set_INTERCONNECTNODE {
        return self._INTERCONNECTNODE.clone();
    }

    pub fn get__SOCKET(&self) -> set_SOCKET {
        return self._SOCKET.clone();
    }

    pub fn get__SERVICE(&self) -> set_SERVICE {
        return self._SERVICE.clone();
    }

    pub fn get__RESOURCEMANAGER(&self) -> set_RESOURCEMANAGER {
        return self._RESOURCEMANAGER.clone();
    }

    pub fn get__SID(&self) -> set_SID {
        return self._SID.clone();
    }

    pub fn get__RM_ERROR_CODES(&self) -> set_RM_ERROR_CODES {
        return self._RM_ERROR_CODES.clone();
    }

    pub fn get__IN_ERROR_CODES(&self) -> set_IN_ERROR_CODES {
        return self._IN_ERROR_CODES.clone();
    }

    pub fn constructor_interconnectNode(&mut self, mut newic: INTERCONNECTNODE) -> INTERCONNECTNODE {
        let mut oid: Option<INTERCONNECTNODE> = Option::None;
        //select
        if self._INTERCONNECTNODE.difference(&self.interconnectNodes).elementOf(&newic) {
            let mut _ld_interconnectNodes = self.interconnectNodes.clone();
            self.interconnectNodes = _ld_interconnectNodes.union(&bset![INTERCONNECTNODE, newic]).clone().clone();
            self.in_resourceManager = self.in_resourceManager._override_single(newic, bset![RESOURCEMANAGER]);
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
        self.resourceManagers = _ld_resourceManagers.union(&bset![RESOURCEMANAGER, newrm]).clone().clone();
        self.rm_services = self.rm_services._override_single(newrm, bset![SERVICE]);
        oid = Option::Some(newrm);

        return oid.unwrap();
    }

    pub fn constructor_service(&mut self, mut ii: INTERCONNECTNODE, mut newsvc: SERVICE) -> SERVICE {
        let mut oid: Option<SERVICE> = Option::None;
        //pre_assert
        let mut _ld_services = self.services.clone();
        self.services = _ld_services.union(&bset![SERVICE, newsvc]).clone().clone();
        self.svc_registered = self.svc_registered._override_single(newsvc, false);
        self.svc_sockets = self.svc_sockets._override_single(newsvc, bset![SOCKET]);
        self.svc_ICNode = self.svc_ICNode._override_single(newsvc, ii);
        self.svc_serviceID = brel![rel_SERVICE_X_SID].clone().clone();
        oid = Option::Some(newsvc);

        return oid.unwrap();
    }

    pub fn constructor_socket(&mut self, mut ii: INTERCONNECTNODE, mut srcsid: SID, mut targsid: SID, mut newsoc: SOCKET) -> SOCKET {
        let mut oid: Option<SOCKET> = Option::None;
        //pre_assert
        let mut _ld_sockets = self.sockets.clone();
        self.sockets = _ld_sockets.union(&bset![SOCKET, newsoc]).clone().clone();
        oid = Option::Some(newsoc);
        self.in_sockets = self.in_sockets._override_single(newsoc, ii);
        self.soc_to = self.soc_to._override_single(newsoc, srcsid);
        self.soc_from = self.soc_from._override_single(newsoc, targsid);

        return oid.unwrap();
    }

    pub fn rm_register(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE, mut ii: INTERCONNECTNODE) -> () {
        //pre_assert

    }

    pub fn rm_deregister(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE, mut ii: INTERCONNECTNODE) -> () {
        //pre_assert

    }

    pub fn rm_getSid(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE) -> _Struct1 {
        let mut sid: Option<set_SID> = Option::None;
        let mut err: Option<RM_ERROR_CODES> = Option::None;
        //pre_assert
        err = Option::Some(/*enum_call*/RM_ERROR_CODES::RM_SERVICE_FOUND);
        sid = Option::Some(bset![SID, self.rm_sids.functionCall(&ss)].clone()).clone();

        return /*record*/_Struct1::new(sid.unwrap(), err.unwrap());
    }

    pub fn rm_getSid_Not_Found(&mut self, mut _self: RESOURCEMANAGER, mut ss: SERVICE) -> _Struct1 {
        let mut sid: Option<set_SID> = Option::None;
        let mut err: Option<RM_ERROR_CODES> = Option::None;
        //pre_assert
        sid = Option::Some(self._SID.difference(&self._SID).clone()).clone();
        err = Option::Some(/*enum_call*/RM_ERROR_CODES::RM_SERVICE_NOT_FOUND);

        return /*record*/_Struct1::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_announceResourceManager(&mut self, mut _self: INTERCONNECTNODE, mut rm: RESOURCEMANAGER) -> () {
        //pre_assert
        self.in_resourceManager = self.in_resourceManager._override_single(_self, self.in_resourceManager.functionCall(&_self).union(&bset![RESOURCEMANAGER, rm]));

    }

    pub fn in_register_success(&mut self, mut _self: INTERCONNECTNODE, mut ss: SERVICE, mut si: SID) -> _Struct3 {
        let mut sid: Option<set_SID> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        let mut _ld_sids = self.sids.clone();

        let mut _ld_in_localServices = self.in_localServices.clone();
        self.sids = _ld_sids.union(&bset![SID, si]).clone().clone();
        self.in_localServices = _ld_in_localServices.union(&brel![rel_SID_X_INTERCONNECTNODE, (si.clone(), _self.clone())]).clone().clone();
        err = Option::Some(/*enum_call*/IN_ERROR_CODES::IN_REGISTRATION_OK);
        sid = Option::Some(bset![SID, si].clone()).clone();

        return /*record*/_Struct3::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_register_failed(&mut self, mut _self: INTERCONNECTNODE, mut ss: SERVICE) -> _Struct3 {
        let mut sid: Option<set_SID> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        sid = Option::Some(self._SID.difference(&self._SID).clone()).clone();
        err = Option::Some(/*enum_call*/IN_ERROR_CODES::IN_REGISTRATION_FAILED);

        return /*record*/_Struct3::new(sid.unwrap(), err.unwrap());
    }

    pub fn in_requestTargetSocket_Granted(&mut self, mut _self: INTERCONNECTNODE, mut ii: INTERCONNECTNODE, mut srcsoc: SOCKET, mut srcsid: SID, mut targsid: SID, mut newsoc: SOCKET) -> _Struct5 {
        let mut soc: Option<set_SOCKET> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        let mut _ld_sockets = self.sockets.clone();
        let mut _ld_in_sockets = self.in_sockets.clone();
        self.sockets = _ld_sockets.union(&bset![SOCKET, newsoc]).clone().clone();
        soc = Option::Some(bset![SOCKET, newsoc].clone()).clone();
        err = Option::Some(/*enum_call*/IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED);
        self.in_sockets = _ld_in_sockets.union(&brel![rel_SOCKET_X_INTERCONNECTNODE, (newsoc.clone(), _self.clone())]).clone().clone();
        self.soc_to = self.soc_to._override_single(newsoc, srcsid);
        self.soc_from = self.soc_from._override_single(newsoc, targsid);

        return /*record*/_Struct5::new(soc.unwrap(), err.unwrap());
    }

    pub fn in_requestTargetSocket_NotGranted(&mut self, mut _self: INTERCONNECTNODE, mut ii: INTERCONNECTNODE, mut srcsoc: SOCKET, mut srcsid: SID, mut targsid: SID) -> _Struct5 {
        let mut soc: Option<set_SOCKET> = Option::None;
        let mut err: Option<IN_ERROR_CODES> = Option::None;
        //pre_assert
        soc = Option::Some(self._SOCKET.difference(&self._SOCKET).clone()).clone();
        err = Option::Some(/*enum_call*/IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED);

        return /*record*/_Struct5::new(soc.unwrap(), err.unwrap());
    }

    pub fn svc_register(&mut self, mut _self: SERVICE) -> () {
        //pre_assert
        self.svc_registered = self.svc_registered._override_single(_self, true);

    }

    pub fn _tr_constructor_interconnectNode(&mut self, is_caching: bool) -> HashSet<INTERCONNECTNODE> {
        //transition
        if !is_caching || self._tr_cache_constructor_interconnectNode.is_none() {
            let mut _ic_set_0: HashSet<INTERCONNECTNODE> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_newic_1 in self._INTERCONNECTNODE.difference(&self.interconnectNodes).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                _ic_set_0.insert(_ic_newic_1);

            }
            self._tr_cache_constructor_interconnectNode = Option::Some(_ic_set_0.clone());
            return _ic_set_0;
        } else {
            return self._tr_cache_constructor_interconnectNode.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_resourceManager(&mut self, is_caching: bool) -> HashSet<RESOURCEMANAGER> {
        //transition
        if !is_caching || self._tr_cache_constructor_resourceManager.is_none() {
            let mut _ic_set_1: HashSet<RESOURCEMANAGER> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_newrm_1 in self._RESOURCEMANAGER.difference(&self.resourceManagers).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.rm_services.domain().notElementOf(&_ic_newrm_1) && self.resourceManagers.equal(&bset![RESOURCEMANAGER])) {
                    _ic_set_1.insert(_ic_newrm_1);
                }

            }
            self._tr_cache_constructor_resourceManager = Option::Some(_ic_set_1.clone());
            return _ic_set_1;
        } else {
            return self._tr_cache_constructor_resourceManager.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_service(&mut self, is_caching: bool) -> HashSet<(INTERCONNECTNODE, SERVICE)> {
        //transition
        if !is_caching || self._tr_cache_constructor_service.is_none() {
            let mut _ic_set_2: HashSet<(INTERCONNECTNODE, SERVICE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_newsvc_1 in self._SERVICE.difference(&self.services).clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    _ic_set_2.insert((_ic_ii_1.clone(), _ic_newsvc_1.clone()));

                }
            }
            self._tr_cache_constructor_service = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_constructor_service.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_constructor_socket(&mut self, is_caching: bool) -> HashSet<(((INTERCONNECTNODE, SID), SID), SOCKET)> {
        //transition
        if !is_caching || self._tr_cache_constructor_socket.is_none() {
            let mut _ic_set_3: HashSet<(((INTERCONNECTNODE, SID), SID), SOCKET)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_srcsid_1 in self.sids.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_targsid_1 in self.sids.clone().iter() {
                        //iteration_construct_enumeration
                        for _ic_newsoc_1 in self._SOCKET.difference(&self.sockets).clone().iter() {
                            //parameter_combination_predicate TODO: FASTER
                            _ic_set_3.insert((((_ic_ii_1.clone(), _ic_srcsid_1.clone()).clone(), _ic_targsid_1.clone()).clone(), _ic_newsoc_1.clone()));

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

    pub fn _tr_rm_register(&mut self, is_caching: bool) -> HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)> {
        //transition
        if !is_caching || self._tr_cache_rm_register.is_none() {
            let mut _ic_set_4: HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.resourceManagers.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                        //parameter_combination_predicate TODO: FASTER
                        _ic_set_4.insert(((_ic_self_1.clone(), _ic_ss_1.clone()).clone(), _ic_ii_1.clone()));

                    }
                }
            }
            self._tr_cache_rm_register = Option::Some(_ic_set_4.clone());
            return _ic_set_4;
        } else {
            return self._tr_cache_rm_register.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_deregister(&mut self, is_caching: bool) -> HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)> {
        //transition
        if !is_caching || self._tr_cache_rm_deregister.is_none() {
            let mut _ic_set_5: HashSet<((RESOURCEMANAGER, SERVICE), INTERCONNECTNODE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.resourceManagers.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                        //parameter_combination_predicate TODO: FASTER
                        _ic_set_5.insert(((_ic_self_1.clone(), _ic_ss_1.clone()).clone(), _ic_ii_1.clone()));

                    }
                }
            }
            self._tr_cache_rm_deregister = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_rm_deregister.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_getSid(&mut self, is_caching: bool) -> HashSet<(RESOURCEMANAGER, SERVICE)> {
        //transition
        if !is_caching || self._tr_cache_rm_getSid.is_none() {
            let mut _ic_set_6: HashSet<(RESOURCEMANAGER, SERVICE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.resourceManagers.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if self.rm_sids.domain().elementOf(&_ic_ss_1) {
                        _ic_set_6.insert((_ic_self_1.clone(), _ic_ss_1.clone()));
                    }

                }
            }
            self._tr_cache_rm_getSid = Option::Some(_ic_set_6.clone());
            return _ic_set_6;
        } else {
            return self._tr_cache_rm_getSid.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_rm_getSid_Not_Found(&mut self, is_caching: bool) -> HashSet<(RESOURCEMANAGER, SERVICE)> {
        //transition
        if !is_caching || self._tr_cache_rm_getSid_Not_Found.is_none() {
            let mut _ic_set_7: HashSet<(RESOURCEMANAGER, SERVICE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.resourceManagers.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    _ic_set_7.insert((_ic_self_1.clone(), _ic_ss_1.clone()));

                }
            }
            self._tr_cache_rm_getSid_Not_Found = Option::Some(_ic_set_7.clone());
            return _ic_set_7;
        } else {
            return self._tr_cache_rm_getSid_Not_Found.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_announceResourceManager(&mut self, is_caching: bool) -> HashSet<(INTERCONNECTNODE, RESOURCEMANAGER)> {
        //transition
        if !is_caching || self._tr_cache_in_announceResourceManager.is_none() {
            let mut _ic_set_8: HashSet<(INTERCONNECTNODE, RESOURCEMANAGER)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_rm_1 in self.resourceManagers.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if self.in_resourceManager.functionCall(&_ic_self_1).equal(&bset![RESOURCEMANAGER]) {
                        _ic_set_8.insert((_ic_self_1.clone(), _ic_rm_1.clone()));
                    }

                }
            }
            self._tr_cache_in_announceResourceManager = Option::Some(_ic_set_8.clone());
            return _ic_set_8;
        } else {
            return self._tr_cache_in_announceResourceManager.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_register_success(&mut self, is_caching: bool) -> HashSet<((INTERCONNECTNODE, SERVICE), SID)> {
        //transition
        if !is_caching || self._tr_cache_in_register_success.is_none() {
            let mut _ic_set_9: HashSet<((INTERCONNECTNODE, SERVICE), SID)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_si_1 in self._SID.difference(&self.sids).clone().iter() {
                        //parameter_combination_predicate TODO: FASTER
                        if self.in_localServices.domain().elementOf(&_ic_si_1).not() {
                            _ic_set_9.insert(((_ic_self_1.clone(), _ic_ss_1.clone()).clone(), _ic_si_1.clone()));
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

    pub fn _tr_in_register_failed(&mut self, is_caching: bool) -> HashSet<(INTERCONNECTNODE, SERVICE)> {
        //transition
        if !is_caching || self._tr_cache_in_register_failed.is_none() {
            let mut _ic_set_10: HashSet<(INTERCONNECTNODE, SERVICE)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ss_1 in self.services.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    _ic_set_10.insert((_ic_self_1.clone(), _ic_ss_1.clone()));

                }
            }
            self._tr_cache_in_register_failed = Option::Some(_ic_set_10.clone());
            return _ic_set_10;
        } else {
            return self._tr_cache_in_register_failed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_in_requestTargetSocket_Granted(&mut self, is_caching: bool) -> HashSet<(((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID), SOCKET)> {
        //transition
        if !is_caching || self._tr_cache_in_requestTargetSocket_Granted.is_none() {
            let mut _ic_set_11: HashSet<(((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID), SOCKET)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_srcsoc_1 in self.sockets.clone().iter() {
                        //iteration_construct_enumeration
                        for _ic_srcsid_1 in self.sids.clone().iter() {
                            //iteration_construct_enumeration
                            for _ic_targsid_1 in self.sids.clone().iter() {
                                //iteration_construct_enumeration
                                for _ic_newsoc_1 in self._SOCKET.difference(&self.sockets).clone().iter() {
                                    //parameter_combination_predicate TODO: FASTER
                                    if (_ic_self_1.unequal(&_ic_ii_1) && self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1)) {
                                        _ic_set_11.insert((((((_ic_self_1.clone(), _ic_ii_1.clone()).clone(), _ic_srcsoc_1.clone()).clone(), _ic_srcsid_1.clone()).clone(), _ic_targsid_1.clone()).clone(), _ic_newsoc_1.clone()));
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

    pub fn _tr_in_requestTargetSocket_NotGranted(&mut self, is_caching: bool) -> HashSet<((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID)> {
        //transition
        if !is_caching || self._tr_cache_in_requestTargetSocket_NotGranted.is_none() {
            let mut _ic_set_12: HashSet<((((INTERCONNECTNODE, INTERCONNECTNODE), SOCKET), SID), SID)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.interconnectNodes.clone().iter() {
                //iteration_construct_enumeration
                for _ic_ii_1 in self.interconnectNodes.clone().iter() {
                    //iteration_construct_enumeration
                    for _ic_srcsoc_1 in self.sockets.clone().iter() {
                        //iteration_construct_enumeration
                        for _ic_srcsid_1 in self.sids.clone().iter() {
                            //iteration_construct_enumeration
                            for _ic_targsid_1 in self.sids.clone().iter() {
                                //parameter_combination_predicate TODO: FASTER
                                if (_ic_self_1.unequal(&_ic_ii_1) && self.in_sockets.functionCall(&_ic_srcsoc_1).equal(&_ic_ii_1)) {
                                    _ic_set_12.insert(((((_ic_self_1.clone(), _ic_ii_1.clone()).clone(), _ic_srcsoc_1.clone()).clone(), _ic_srcsid_1.clone()).clone(), _ic_targsid_1.clone()));
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

    pub fn _tr_svc_register(&mut self, is_caching: bool) -> HashSet<SERVICE> {
        //transition
        if !is_caching || self._tr_cache_svc_register.is_none() {
            let mut _ic_set_13: HashSet<SERVICE> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_self_1 in self.services.clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if self.svc_registered.functionCall(&_ic_self_1).equal(&false) {
                    _ic_set_13.insert(_ic_self_1);
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
        return self.interconnectNodes.subset(&self._INTERCONNECTNODE);
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return self.sockets.subset(&self._SOCKET);
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return self.services.subset(&self._SERVICE);
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return self.resourceManagers.subset(&self._RESOURCEMANAGER);
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return self.sids.subset(&self._SID);
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return self.resourceManagers.check_domain_of(&self.rm_services).and(&self.services.pow().check_range_of(&self.rm_services)).and(&self.rm_services.isFunction()).and(&self.resourceManagers.check_total_of(&self.rm_services));
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        //quantified_predicate
        let mut _ic_boolean_14 = true;
        //iteration_construct_enumeration
        for _ic_a1_1 in self.rm_services.domain().clone().iter() {
            //iteration_construct_enumeration
            for _ic_a2_1 in self.rm_services.domain().clone().iter() {
                if !_ic_a1_1.unequal(&_ic_a2_1).implies(|| self.rm_services.functionCall(&_ic_a1_1).intersect(&self.rm_services.functionCall(&_ic_a2_1)).equal(&bset![SERVICE])) {
                    _ic_boolean_14 = false;
                    break;
                }

            }
        }

        return _ic_boolean_14;
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return self.services.check_domain_of(&self.rm_sids).and(&self.sids.check_range_of(&self.rm_sids)).and(&self.rm_sids.isFunction()).and(&self.services.check_partial_of(&self.rm_sids)).and(&self.rm_sids.isInjection());
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.sids.check_domain_of(&self.in_localServices).and(&self.interconnectNodes.check_range_of(&self.in_localServices)).and(&self.in_localServices.isFunction()).and(&self.sids.check_total_of(&self.in_localServices));
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return self.sockets.check_domain_of(&self.in_sockets).and(&self.interconnectNodes.check_range_of(&self.in_sockets)).and(&self.in_sockets.isFunction()).and(&self.sockets.check_total_of(&self.in_sockets));
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return self.interconnectNodes.check_domain_of(&self.in_resourceManager).and(&self.resourceManagers.pow().check_range_of(&self.in_resourceManager)).and(&self.in_resourceManager.isFunction()).and(&self.interconnectNodes.check_total_of(&self.in_resourceManager));
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self.sockets.check_domain_of(&self.soc_to).and(&self.sids.check_range_of(&self.soc_to)).and(&self.soc_to.isFunction()).and(&self.sockets.check_total_of(&self.soc_to));
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self.sockets.check_domain_of(&self.soc_from).and(&self.sids.check_range_of(&self.soc_from)).and(&self.soc_from.isFunction()).and(&self.sockets.check_total_of(&self.soc_from));
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return self.services.check_domain_of(&self.svc_serviceID).and(&self.sids.check_range_of(&self.svc_serviceID)).and(&self.svc_serviceID.isFunction()).and(&self.services.check_partial_of(&self.svc_serviceID));
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return self.services.check_domain_of(&self.svc_sockets).and(&self.sockets.pow().check_range_of(&self.svc_sockets)).and(&self.svc_sockets.isFunction()).and(&self.services.check_total_of(&self.svc_sockets));
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return self.services.check_domain_of(&self.svc_ICNode).and(&self.interconnectNodes.check_range_of(&self.svc_ICNode)).and(&self.svc_ICNode.isFunction()).and(&self.services.check_total_of(&self.svc_ICNode));
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.services.check_domain_of(&self.svc_registered).and(&BOOL.check_range_of(&self.svc_registered)).and(&self.svc_registered.isFunction()).and(&self.services.check_total_of(&self.svc_registered));
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.resourceManagers.equal(&bset![RESOURCEMANAGER]).not().implies(|| self.resourceManagers.card().equal(&1));
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

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
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

            if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
                println!("INVARIANT VIOLATED");
                stop_threads = true;
            }
            if !no_dead && next_states.is_empty() {
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

    fn modelCheckMultiThreaded(mc_type: MC_TYPE, threads: usize, is_caching: bool, no_dead: bool, no_inv: bool) {
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
                if !no_dead && next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

                if !no_inv && !Self::checkInvariants(&state, last_op, is_caching) {
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
    if args.len() < 4 { panic!("Number of arguments errorneous"); }

    let threads = args.get(2).unwrap().parse::<usize>().unwrap();
    if threads <= 0 { panic!("Input for number of threads is wrong."); }

    let is_caching = args.get(3).unwrap().parse::<bool>().unwrap();
    let mc_type = match args.get(1).unwrap().as_str() {
        "mixed" => MC_TYPE::MIXED,
        "bf" => MC_TYPE::BFS,
        "df" => MC_TYPE::DFS,
        _    => panic!("Input for strategy is wrong.")
    };

    let mut no_dead = false;
    let mut no_inv = false;

    if args.len() > 4 {
        for arg in args.iter().skip(4) {
            match arg.as_str() {
                "-nodead" => no_dead = true,
                "-noinv" => no_inv = true,
                _ => {}
            }
        }
    }

    if threads == 1 {
        nota_v2::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        nota_v2::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}
