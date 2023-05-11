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


//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RSset {
    #[default]
    RSnone = 0, 
    RSpos = 1, 
    RSneg = 2, 
    RSequal = 3
}

impl RSset {
    pub fn equal(&self, other: &RSset) -> bool { *self == *other }
    pub fn unequal(&self, other: &RSset) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::RSnone, 
            1 => Self::RSpos, 
            2 => Self::RSneg, 
            3 => Self::RSequal, 
            _ => panic!("RSset index out of range! {:?}", idx)
        }
    }
}

impl SetItem<4> for RSset {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_RSset = BSet<RSset, 4>;
//set_enum_declaration done

//set_enum_declaration
#[derive(Default, Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum ODset {
    #[default]
    ODnone = 0, 
    ODclose = 1, 
    ODveryclose = 2
}

impl ODset {
    pub fn equal(&self, other: &ODset) -> bool { *self == *other }
    pub fn unequal(&self, other: &ODset) -> bool { *self != *other }
    pub const fn to_idx(self) -> usize { self as usize }
    pub fn from_idx(idx: usize) -> Self {
        match idx {
            0 => Self::ODnone, 
            1 => Self::ODclose, 
            2 => Self::ODveryclose, 
            _ => panic!("ODset index out of range! {:?}", idx)
        }
    }
}

impl SetItem<3> for ODset {
    fn as_idx(&self) -> usize { self.to_idx() }
    fn from_idx(idx: usize) -> Self { Self::from_idx(idx) }
}

type set_ODset = BSet<ODset, 3>;
//set_enum_declaration done


#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Cruise_finite1_deterministic_MC {
    /*declarations*/CruiseAllowed: BBoolean,
    CruiseActive: BBoolean,
    VehicleAtCruiseSpeed: BBoolean,
    VehicleCanKeepSpeed: BBoolean,
    VehicleTryKeepSpeed: BBoolean,
    SpeedAboveMax: BBoolean,
    VehicleTryKeepTimeGap: BBoolean,
    CruiseSpeedAtMax: BBoolean,
    ObstaclePresent: BBoolean,
    ObstacleDistance: ODset,
    ObstacleRelativeSpeed: RSset,
    ObstacleStatusJustChanged: BBoolean,
    CCInitialisationInProgress: BBoolean,
    CruiseSpeedChangeInProgress: BBoolean,
    NumberOfSetCruise: BInteger,
    /*sets*//*set_declaration*/_RSset: set_RSset,
    /*set_declaration*/_ODset: set_ODset,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseBecomesNotAllowed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseBecomesAllowed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_SetCruiseSpeed: Option<HashSet<(BBoolean, BBoolean)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CCInitialisationFinished: Option<HashSet<(BBoolean, BBoolean)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CCInitialisationDelayFinished: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseSpeedChangeFinished: Option<HashSet<(BBoolean, BBoolean)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseSpeedChangeDelayFinished: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseOff: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ExternalForcesBecomesExtreme: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ExternalForcesBecomesNormal: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleLeavesCruiseSpeed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleReachesCruiseSpeed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleExceedsMaxCruiseSpeed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleFallsBelowMaxCruiseSpeed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleDistanceBecomesVeryClose: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleDistanceBecomesClose: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleDistanceBecomesBig: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleStartsTravelFaster: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleStopsTravelFaster: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleStartsTravelSlower: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleStopsTravelSlower: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleAppearsWhenCruiseActive: Option<HashSet<(RSset, ODset)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleAppearsWhenCruiseInactive: Option<HashSet<RSset>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleDisappears: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleManageObstacle: Option<HashSet<(BBoolean, BBoolean)>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleBecomesOld: Option<bool>,}


impl Cruise_finite1_deterministic_MC {

    pub fn new() -> Cruise_finite1_deterministic_MC {
        //values: ''
        let mut m: Cruise_finite1_deterministic_MC = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._RSset = bset![RSset, /*enum_call*/RSset::RSnone, /*enum_call*/RSset::RSpos, /*enum_call*/RSset::RSneg, /*enum_call*/RSset::RSequal];
    //set_initialization
    self._ODset = bset![ODset, /*enum_call*/ODset::ODnone, /*enum_call*/ODset::ODclose, /*enum_call*/ODset::ODveryclose];
        /*properties*/
        /*body*/self.CruiseAllowed = true;
    self.CruiseActive = false;
    self.VehicleAtCruiseSpeed = false;
    self.VehicleCanKeepSpeed = false;
    self.VehicleTryKeepSpeed = false;
    self.SpeedAboveMax = false;
    self.VehicleTryKeepTimeGap = false;
    self.NumberOfSetCruise = 0;
    self.CruiseSpeedAtMax = false;
    self.ObstacleDistance = /*enum_call*/ODset::ODnone;
    self.ObstacleStatusJustChanged = false;
    self.CCInitialisationInProgress = false;
    self.CruiseSpeedChangeInProgress = false;
    self.ObstaclePresent = false;
    self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSnone;
        /*includesInitialization*/
    }

    pub fn get_CruiseAllowed(&self) -> BBoolean {
        return self.CruiseAllowed.clone();
    }

    pub fn get_CruiseActive(&self) -> BBoolean {
        return self.CruiseActive.clone();
    }

    pub fn get_VehicleAtCruiseSpeed(&self) -> BBoolean {
        return self.VehicleAtCruiseSpeed.clone();
    }

    pub fn get_VehicleCanKeepSpeed(&self) -> BBoolean {
        return self.VehicleCanKeepSpeed.clone();
    }

    pub fn get_VehicleTryKeepSpeed(&self) -> BBoolean {
        return self.VehicleTryKeepSpeed.clone();
    }

    pub fn get_SpeedAboveMax(&self) -> BBoolean {
        return self.SpeedAboveMax.clone();
    }

    pub fn get_VehicleTryKeepTimeGap(&self) -> BBoolean {
        return self.VehicleTryKeepTimeGap.clone();
    }

    pub fn get_CruiseSpeedAtMax(&self) -> BBoolean {
        return self.CruiseSpeedAtMax.clone();
    }

    pub fn get_ObstaclePresent(&self) -> BBoolean {
        return self.ObstaclePresent.clone();
    }

    pub fn get_ObstacleDistance(&self) -> ODset {
        return self.ObstacleDistance.clone();
    }

    pub fn get_ObstacleRelativeSpeed(&self) -> RSset {
        return self.ObstacleRelativeSpeed.clone();
    }

    pub fn get_ObstacleStatusJustChanged(&self) -> BBoolean {
        return self.ObstacleStatusJustChanged.clone();
    }

    pub fn get_CCInitialisationInProgress(&self) -> BBoolean {
        return self.CCInitialisationInProgress.clone();
    }

    pub fn get_CruiseSpeedChangeInProgress(&self) -> BBoolean {
        return self.CruiseSpeedChangeInProgress.clone();
    }

    pub fn get_NumberOfSetCruise(&self) -> BInteger {
        return self.NumberOfSetCruise.clone();
    }

    pub fn get__RSset(&self) -> set_RSset {
        return self._RSset.clone();
    }

    pub fn get__ODset(&self) -> set_ODset {
        return self._ODset.clone();
    }

    pub fn CruiseBecomesNotAllowed(&mut self) -> () {
        //select
        if self.CruiseAllowed.equal(&true) {
            self.CruiseAllowed = false;
            self.CruiseActive = false;
            self.VehicleCanKeepSpeed = false;
            self.VehicleTryKeepSpeed = false;
            self.VehicleAtCruiseSpeed = false;
            self.VehicleTryKeepTimeGap = false;
            self.CruiseSpeedAtMax = false;
            self.ObstacleDistance = /*enum_call*/ODset::ODnone;
            self.NumberOfSetCruise = 0;
            self.ObstacleStatusJustChanged = false;
            self.CCInitialisationInProgress = false;
            self.CruiseSpeedChangeInProgress = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseBecomesAllowed(&mut self) -> () {
        //select
        if self.CruiseAllowed.equal(&false) {
            self.CruiseAllowed = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn SetCruiseSpeed(&mut self, mut vcks: BBoolean, mut csam: BBoolean) -> () {
        //pre_assert
        let mut _ld_NumberOfSetCruise = self.NumberOfSetCruise.clone();
        let mut _ld_CruiseActive = self.CruiseActive.clone();
        self.CruiseActive = true;
        self.VehicleCanKeepSpeed = vcks;
        //if
        if self.SpeedAboveMax.equal(&false) {
            self.VehicleAtCruiseSpeed = true;
            self.CruiseSpeedAtMax = csam;
        } //else
        else {
            self.CruiseSpeedAtMax = true;
        }
        self.ObstacleStatusJustChanged = true;
        //if
        if _ld_CruiseActive.equal(&true) {
            self.CruiseSpeedChangeInProgress = true;
        } //else
        else {
            self.CCInitialisationInProgress = true;
        }
        //if
        if _ld_NumberOfSetCruise.less(&1) {
            self.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(&1);
        } 

    }

    pub fn CCInitialisationFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //pre_assert
        self.VehicleTryKeepTimeGap = vtktg;
        self.VehicleTryKeepSpeed = vtks;

    }

    pub fn CCInitialisationDelayFinished(&mut self) -> () {
        //select
        if (((((self.CCInitialisationInProgress.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true))) {
            self.CCInitialisationInProgress = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //select
        if (((((((((((BOOL.elementOf(&vtks) && BOOL.elementOf(&vtktg)) && (((vtks.equal(&true) || vtktg.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CCInitialisationInProgress.equal(&true))) && self.ObstaclePresent.equal(&false).implies(|| vtktg.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| vtks.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtks.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| vtktg.equal(&false))) && self.CruiseSpeedChangeInProgress.equal(&true)) {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeDelayFinished(&mut self) -> () {
        //select
        if (((((self.CruiseSpeedChangeInProgress.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CCInitialisationInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true))) {
            self.CruiseSpeedChangeInProgress = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseOff(&mut self) -> () {
        //select
        if self.CruiseActive.equal(&true) {
            self.CruiseActive = false;
            self.VehicleCanKeepSpeed = false;
            self.VehicleTryKeepSpeed = false;
            self.VehicleAtCruiseSpeed = false;
            self.VehicleTryKeepTimeGap = false;
            self.CruiseSpeedAtMax = false;
            self.ObstacleDistance = /*enum_call*/ODset::ODnone;
            self.NumberOfSetCruise = 0;
            self.ObstacleStatusJustChanged = false;
            self.CCInitialisationInProgress = false;
            self.CruiseSpeedChangeInProgress = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ExternalForcesBecomesExtreme(&mut self) -> () {
        //select
        if self.VehicleCanKeepSpeed.equal(&true) {
            self.VehicleCanKeepSpeed = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ExternalForcesBecomesNormal(&mut self) -> () {
        //select
        if (self.CruiseActive.equal(&true) && self.VehicleCanKeepSpeed.equal(&false)) {
            self.VehicleCanKeepSpeed = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleLeavesCruiseSpeed(&mut self) -> () {
        //select
        if ((self.VehicleAtCruiseSpeed.equal(&true) && (self.VehicleCanKeepSpeed.equal(&false) && self.VehicleTryKeepSpeed.equal(&true))) || self.VehicleTryKeepSpeed.equal(&false)) {
            self.VehicleAtCruiseSpeed = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleReachesCruiseSpeed(&mut self) -> () {
        //select
        if ((self.CruiseActive.equal(&true) && self.VehicleAtCruiseSpeed.equal(&false)) && self.SpeedAboveMax.equal(&false)) {
            self.VehicleAtCruiseSpeed = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleExceedsMaxCruiseSpeed(&mut self) -> () {
        //select
        if (self.SpeedAboveMax.equal(&false) && ((self.CruiseActive.equal(&false) || self.VehicleCanKeepSpeed.equal(&false)) || ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)))) {
            self.SpeedAboveMax = true;
            self.VehicleAtCruiseSpeed = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleFallsBelowMaxCruiseSpeed(&mut self) -> () {
        //select
        if self.SpeedAboveMax.equal(&true) {
            self.SpeedAboveMax = false;
            //if
            if (self.CruiseActive.equal(&true) && self.CruiseSpeedAtMax.equal(&true)) {
                self.VehicleAtCruiseSpeed = true;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesVeryClose(&mut self) -> () {
        //select
        if (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg)) {
            self.ObstacleDistance = /*enum_call*/ODset::ODveryclose;
            self.ObstacleStatusJustChanged = true;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesClose(&mut self) -> () {
        //select
        if ((self.ObstaclePresent.equal(&true) && self.CruiseActive.equal(&true)) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos)) || (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg)))) {
            self.ObstacleDistance = /*enum_call*/ODset::ODclose;
            self.ObstacleStatusJustChanged = true;
            //if
            if self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) {
                self.VehicleTryKeepTimeGap = false;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesBig(&mut self) -> () {
        //select
        if (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos)) {
            self.ObstacleStatusJustChanged = true;
            self.ObstacleDistance = /*enum_call*/ODset::ODnone;
            self.VehicleTryKeepTimeGap = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStartsTravelFaster(&mut self) -> () {
        //select
        if (self.ObstaclePresent.equal(&true) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal)) {
            self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSpos;
            //if
            if self.CruiseActive.equal(&true) {
                self.ObstacleStatusJustChanged = true;
            } 
            //if
            if self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose) {
                self.VehicleTryKeepTimeGap = false;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStopsTravelFaster(&mut self) -> () {
        //select
        if self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) {
            self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSequal;
            //if
            if self.CruiseActive.equal(&true) {
                self.ObstacleStatusJustChanged = true;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStartsTravelSlower(&mut self) -> () {
        //select
        if self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) {
            self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSneg;
            //if
            if self.CruiseActive.equal(&true) {
                self.ObstacleStatusJustChanged = true;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStopsTravelSlower(&mut self) -> () {
        //select
        if self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) {
            self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSequal;
            //if
            if self.CruiseActive.equal(&true) {
                self.ObstacleStatusJustChanged = true;
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleAppearsWhenCruiseActive(&mut self, mut ors: RSset, mut od: ODset) -> () {
        //pre_assert
        self.ObstaclePresent = true;
        self.ObstacleStatusJustChanged = true;
        self.ObstacleRelativeSpeed = ors;
        self.ObstacleDistance = od;

    }

    pub fn ObstacleAppearsWhenCruiseInactive(&mut self, mut ors: RSset) -> () {
        //pre_assert
        self.ObstaclePresent = true;
        self.ObstacleRelativeSpeed = ors;
        self.ObstacleDistance = /*enum_call*/ODset::ODnone;

    }

    pub fn ObstacleDisappears(&mut self) -> () {
        //select
        if self.ObstaclePresent.equal(&true) {
            self.ObstaclePresent = false;
            self.ObstacleRelativeSpeed = /*enum_call*/RSset::RSnone;
            //if
            if self.CruiseActive.equal(&true) {
                self.ObstacleStatusJustChanged = true;
            } 
            self.ObstacleDistance = /*enum_call*/ODset::ODnone;
            self.VehicleTryKeepTimeGap = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleManageObstacle(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //select
        if (((((((((((BOOL.elementOf(&vtks) && BOOL.elementOf(&vtktg)) && (((vtks.equal(&true) || vtktg.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstaclePresent.equal(&false).implies(|| vtktg.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| vtks.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtks.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| vtktg.equal(&false))) && self.ObstacleStatusJustChanged.equal(&true)) {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleBecomesOld(&mut self) -> () {
        //select
        if (((((self.ObstacleStatusJustChanged.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true))) {
            self.ObstacleStatusJustChanged = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_CruiseBecomesNotAllowed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseBecomesNotAllowed.is_none() {
            let mut __tmp__val__ = self.CruiseAllowed.equal(&true);
            self._tr_cache_CruiseBecomesNotAllowed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseBecomesNotAllowed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseBecomesAllowed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseBecomesAllowed.is_none() {
            let mut __tmp__val__ = self.CruiseAllowed.equal(&false);
            self._tr_cache_CruiseBecomesAllowed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseBecomesAllowed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_SetCruiseSpeed(&mut self, is_caching: bool) -> HashSet<(BBoolean, BBoolean)> {
        //transition
        if !is_caching || self._tr_cache_SetCruiseSpeed.is_none() {
            let mut _ic_set_2: HashSet<(BBoolean, BBoolean)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_vcks_1 in BOOL.clone().iter() {
                //iteration_construct_enumeration
                for _ic_csam_1 in BOOL.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if self.CruiseAllowed.equal(&true) {
                        _ic_set_2.insert((_ic_vcks_1.clone(), _ic_csam_1.clone()));
                    }

                }
            }
            self._tr_cache_SetCruiseSpeed = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_SetCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CCInitialisationFinished(&mut self, is_caching: bool) -> HashSet<(BBoolean, BBoolean)> {
        //transition
        if !is_caching || self._tr_cache_CCInitialisationFinished.is_none() {
            let mut _ic_set_3: HashSet<(BBoolean, BBoolean)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_vtks_1 in BOOL.clone().iter() {
                //iteration_construct_enumeration
                for _ic_vtktg_1 in BOOL.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if ((((((((((((_ic_vtks_1.equal(&true) || _ic_vtktg_1.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true)) && self.ObstaclePresent.equal(&false).implies(|| _ic_vtktg_1.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| _ic_vtks_1.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtks_1.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| _ic_vtktg_1.equal(&false))) && self.CCInitialisationInProgress.equal(&true)) {
                        _ic_set_3.insert((_ic_vtks_1.clone(), _ic_vtktg_1.clone()));
                    }

                }
            }
            self._tr_cache_CCInitialisationFinished = Option::Some(_ic_set_3.clone());
            return _ic_set_3;
        } else {
            return self._tr_cache_CCInitialisationFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CCInitialisationDelayFinished(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CCInitialisationDelayFinished.is_none() {
            let mut __tmp__val__ = (((((self.CCInitialisationInProgress.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true)));
            self._tr_cache_CCInitialisationDelayFinished = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CCInitialisationDelayFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseSpeedChangeFinished(&mut self, is_caching: bool) -> HashSet<(BBoolean, BBoolean)> {
        //transition
        if !is_caching || self._tr_cache_CruiseSpeedChangeFinished.is_none() {
            let mut _ic_set_5: HashSet<(BBoolean, BBoolean)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_vtks_1 in BOOL.clone().iter() {
                //iteration_construct_enumeration
                for _ic_vtktg_1 in BOOL.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if ((((((((((((_ic_vtks_1.equal(&true) || _ic_vtktg_1.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) && self.ObstaclePresent.equal(&false).implies(|| _ic_vtktg_1.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| _ic_vtks_1.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| _ic_vtks_1.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| _ic_vtktg_1.equal(&false))) && self.CruiseSpeedChangeInProgress.equal(&true)) {
                        _ic_set_5.insert((_ic_vtks_1.clone(), _ic_vtktg_1.clone()));
                    }

                }
            }
            self._tr_cache_CruiseSpeedChangeFinished = Option::Some(_ic_set_5.clone());
            return _ic_set_5;
        } else {
            return self._tr_cache_CruiseSpeedChangeFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseSpeedChangeDelayFinished(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseSpeedChangeDelayFinished.is_none() {
            let mut __tmp__val__ = (((((self.CruiseSpeedChangeInProgress.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CCInitialisationInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true)));
            self._tr_cache_CruiseSpeedChangeDelayFinished = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseSpeedChangeDelayFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseOff(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseOff.is_none() {
            let mut __tmp__val__ = self.CruiseActive.equal(&true);
            self._tr_cache_CruiseOff = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseOff.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ExternalForcesBecomesExtreme(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ExternalForcesBecomesExtreme.is_none() {
            let mut __tmp__val__ = self.VehicleCanKeepSpeed.equal(&true);
            self._tr_cache_ExternalForcesBecomesExtreme = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ExternalForcesBecomesExtreme.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ExternalForcesBecomesNormal(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ExternalForcesBecomesNormal.is_none() {
            let mut __tmp__val__ = (self.CruiseActive.equal(&true) && self.VehicleCanKeepSpeed.equal(&false));
            self._tr_cache_ExternalForcesBecomesNormal = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ExternalForcesBecomesNormal.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleLeavesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleLeavesCruiseSpeed.is_none() {
            let mut __tmp__val__ = ((self.VehicleAtCruiseSpeed.equal(&true) && (self.VehicleCanKeepSpeed.equal(&false) && self.VehicleTryKeepSpeed.equal(&true))) || self.VehicleTryKeepSpeed.equal(&false));
            self._tr_cache_VehicleLeavesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleLeavesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleReachesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleReachesCruiseSpeed.is_none() {
            let mut __tmp__val__ = ((self.CruiseActive.equal(&true) && self.VehicleAtCruiseSpeed.equal(&false)) && self.SpeedAboveMax.equal(&false));
            self._tr_cache_VehicleReachesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleReachesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleExceedsMaxCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleExceedsMaxCruiseSpeed.is_none() {
            let mut __tmp__val__ = (self.SpeedAboveMax.equal(&false) && ((self.CruiseActive.equal(&false) || self.VehicleCanKeepSpeed.equal(&false)) || ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false))));
            self._tr_cache_VehicleExceedsMaxCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleExceedsMaxCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleFallsBelowMaxCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleFallsBelowMaxCruiseSpeed.is_none() {
            let mut __tmp__val__ = self.SpeedAboveMax.equal(&true);
            self._tr_cache_VehicleFallsBelowMaxCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleFallsBelowMaxCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesVeryClose(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesVeryClose.is_none() {
            let mut __tmp__val__ = (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg));
            self._tr_cache_ObstacleDistanceBecomesVeryClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesVeryClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesClose(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesClose.is_none() {
            let mut __tmp__val__ = ((self.ObstaclePresent.equal(&true) && self.CruiseActive.equal(&true)) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos)) || (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg))));
            self._tr_cache_ObstacleDistanceBecomesClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesBig(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesBig.is_none() {
            let mut __tmp__val__ = (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos));
            self._tr_cache_ObstacleDistanceBecomesBig = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesBig.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStartsTravelFaster(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStartsTravelFaster.is_none() {
            let mut __tmp__val__ = (self.ObstaclePresent.equal(&true) && self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal));
            self._tr_cache_ObstacleStartsTravelFaster = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStartsTravelFaster.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStopsTravelFaster(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStopsTravelFaster.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos);
            self._tr_cache_ObstacleStopsTravelFaster = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStopsTravelFaster.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStartsTravelSlower(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStartsTravelSlower.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal);
            self._tr_cache_ObstacleStartsTravelSlower = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStartsTravelSlower.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStopsTravelSlower(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStopsTravelSlower.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg);
            self._tr_cache_ObstacleStopsTravelSlower = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStopsTravelSlower.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleAppearsWhenCruiseActive(&mut self, is_caching: bool) -> HashSet<(RSset, ODset)> {
        //transition
        if !is_caching || self._tr_cache_ObstacleAppearsWhenCruiseActive.is_none() {
            let mut _ic_set_21: HashSet<(RSset, ODset)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_ors_1 in self._RSset.difference(&bset![RSset, /*enum_call*/RSset::RSnone]).clone().iter() {
                //iteration_construct_enumeration
                for _ic_od_1 in self._ODset.difference(&bset![ODset, /*enum_call*/ODset::ODnone]).clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if (self.ObstaclePresent.equal(&false) && self.CruiseActive.equal(&true)) {
                        _ic_set_21.insert((_ic_ors_1.clone(), _ic_od_1.clone()));
                    }

                }
            }
            self._tr_cache_ObstacleAppearsWhenCruiseActive = Option::Some(_ic_set_21.clone());
            return _ic_set_21;
        } else {
            return self._tr_cache_ObstacleAppearsWhenCruiseActive.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleAppearsWhenCruiseInactive(&mut self, is_caching: bool) -> HashSet<RSset> {
        //transition
        if !is_caching || self._tr_cache_ObstacleAppearsWhenCruiseInactive.is_none() {
            let mut _ic_set_22: HashSet<RSset> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_ors_1 in self._RSset.difference(&bset![RSset, /*enum_call*/RSset::RSnone]).clone().iter() {
                //parameter_combination_predicate TODO: FASTER
                if (self.ObstaclePresent.equal(&false) && self.CruiseActive.equal(&false)) {
                    _ic_set_22.insert(_ic_ors_1);
                }

            }
            self._tr_cache_ObstacleAppearsWhenCruiseInactive = Option::Some(_ic_set_22.clone());
            return _ic_set_22;
        } else {
            return self._tr_cache_ObstacleAppearsWhenCruiseInactive.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDisappears(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDisappears.is_none() {
            let mut __tmp__val__ = self.ObstaclePresent.equal(&true);
            self._tr_cache_ObstacleDisappears = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDisappears.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleManageObstacle(&mut self, is_caching: bool) -> HashSet<(BBoolean, BBoolean)> {
        //transition
        if !is_caching || self._tr_cache_VehicleManageObstacle.is_none() {
            let mut _ic_set_24: HashSet<(BBoolean, BBoolean)> = HashSet::new();
            //transition, parameters, no condidtion
            //iteration_construct_enumeration
            for _ic_vtks_1 in BOOL.clone().iter() {
                //iteration_construct_enumeration
                for _ic_vtktg_1 in BOOL.clone().iter() {
                    //parameter_combination_predicate TODO: FASTER
                    if ((((((((((((_ic_vtks_1.equal(&true) || _ic_vtktg_1.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true)) && self.ObstaclePresent.equal(&false).implies(|| _ic_vtktg_1.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| _ic_vtks_1.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtktg_1.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| _ic_vtks_1.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| _ic_vtktg_1.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| _ic_vtktg_1.equal(&false))) && self.ObstacleStatusJustChanged.equal(&true)) {
                        _ic_set_24.insert((_ic_vtks_1.clone(), _ic_vtktg_1.clone()));
                    }

                }
            }
            self._tr_cache_VehicleManageObstacle = Option::Some(_ic_set_24.clone());
            return _ic_set_24;
        } else {
            return self._tr_cache_VehicleManageObstacle.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleBecomesOld(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleBecomesOld.is_none() {
            let mut __tmp__val__ = (((((self.ObstacleStatusJustChanged.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true)));
            self._tr_cache_ObstacleBecomesOld = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleBecomesOld.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.CruiseAllowed);
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.CruiseActive);
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.VehicleAtCruiseSpeed);
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.VehicleCanKeepSpeed);
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.VehicleTryKeepSpeed);
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.SpeedAboveMax);
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.VehicleTryKeepTimeGap);
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.CruiseSpeedAtMax);
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.NumberOfSetCruise.isNatural();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return set_BInteger::interval(&0, &1).elementOf(&self.NumberOfSetCruise);
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.ObstaclePresent);
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._ODset.elementOf(&self.ObstacleDistance);
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self._RSset.elementOf(&self.ObstacleRelativeSpeed);
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.ObstacleStatusJustChanged);
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.CCInitialisationInProgress);
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return BOOL.elementOf(&self.CruiseSpeedChangeInProgress);
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.VehicleAtCruiseSpeed.equal(&false));
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.VehicleCanKeepSpeed.equal(&false));
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.VehicleTryKeepSpeed.equal(&false));
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self.NumberOfSetCruise.equal(&0).equivalent(&self.CruiseActive.equal(&false));
    }

    pub fn _check_inv_21(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.VehicleTryKeepTimeGap.equal(&false));
    }

    pub fn _check_inv_22(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.CruiseSpeedAtMax.equal(&false));
    }

    pub fn _check_inv_23(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone));
    }

    pub fn _check_inv_24(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.ObstacleStatusJustChanged.equal(&false));
    }

    pub fn _check_inv_25(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.CCInitialisationInProgress.equal(&false));
    }

    pub fn _check_inv_26(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&false).implies(|| self.CruiseSpeedChangeInProgress.equal(&false));
    }

    pub fn _check_inv_27(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&false).implies(|| self.VehicleTryKeepTimeGap.equal(&false));
    }

    pub fn _check_inv_28(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&false).implies(|| self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone));
    }

    pub fn _check_inv_29(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&false).equivalent(&self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSnone));
    }

    pub fn _check_inv_30(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| self.VehicleTryKeepTimeGap.equal(&false));
    }

    pub fn _check_inv_31(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| self.VehicleTryKeepTimeGap.equal(&false));
    }

    pub fn _check_inv_32(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| self.VehicleTryKeepTimeGap.equal(&false));
    }

    pub fn _check_inv_33(&self) -> bool {
        //invariant
        return self.CruiseAllowed.equal(&false).implies(|| self.CruiseActive.equal(&false));
    }

    pub fn _check_inv_34(&self) -> bool {
        //invariant
        return self.SpeedAboveMax.equal(&true).implies(|| self.VehicleAtCruiseSpeed.equal(&false));
    }

    pub fn _check_inv_35(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&true).implies(|| ((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).not()));
    }

    pub fn _check_inv_36(&self) -> bool {
        //invariant
        return ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone) && self.CruiseActive.equal(&true)) && ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false))).implies(|| self.VehicleTryKeepSpeed.equal(&true));
    }

    pub fn _check_inv_37(&self) -> bool {
        //invariant
        return ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false))).implies(|| self.VehicleTryKeepTimeGap.equal(&true));
    }

    pub fn _check_inv_38(&self) -> bool {
        //invariant
        return (self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false))).implies(|| self.VehicleTryKeepTimeGap.equal(&true));
    }

    pub fn _check_inv_39(&self) -> bool {
        //invariant
        return (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CruiseActive.equal(&true)) && ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false))).implies(|| self.VehicleTryKeepSpeed.equal(&true));
    }

    fn invalidate_caches(&mut self, to_invalidate: Vec<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        for trans in to_invalidate {
            match trans {
                "_tr_CruiseBecomesNotAllowed" => {self._tr_CruiseBecomesNotAllowed(false);},
                "_tr_CruiseBecomesAllowed" => {self._tr_CruiseBecomesAllowed(false);},
                "_tr_SetCruiseSpeed" => {self._tr_SetCruiseSpeed(false);},
                "_tr_CCInitialisationFinished" => {self._tr_CCInitialisationFinished(false);},
                "_tr_CCInitialisationDelayFinished" => {self._tr_CCInitialisationDelayFinished(false);},
                "_tr_CruiseSpeedChangeFinished" => {self._tr_CruiseSpeedChangeFinished(false);},
                "_tr_CruiseSpeedChangeDelayFinished" => {self._tr_CruiseSpeedChangeDelayFinished(false);},
                "_tr_CruiseOff" => {self._tr_CruiseOff(false);},
                "_tr_ExternalForcesBecomesExtreme" => {self._tr_ExternalForcesBecomesExtreme(false);},
                "_tr_ExternalForcesBecomesNormal" => {self._tr_ExternalForcesBecomesNormal(false);},
                "_tr_VehicleLeavesCruiseSpeed" => {self._tr_VehicleLeavesCruiseSpeed(false);},
                "_tr_VehicleReachesCruiseSpeed" => {self._tr_VehicleReachesCruiseSpeed(false);},
                "_tr_VehicleExceedsMaxCruiseSpeed" => {self._tr_VehicleExceedsMaxCruiseSpeed(false);},
                "_tr_VehicleFallsBelowMaxCruiseSpeed" => {self._tr_VehicleFallsBelowMaxCruiseSpeed(false);},
                "_tr_ObstacleDistanceBecomesVeryClose" => {self._tr_ObstacleDistanceBecomesVeryClose(false);},
                "_tr_ObstacleDistanceBecomesClose" => {self._tr_ObstacleDistanceBecomesClose(false);},
                "_tr_ObstacleDistanceBecomesBig" => {self._tr_ObstacleDistanceBecomesBig(false);},
                "_tr_ObstacleStartsTravelFaster" => {self._tr_ObstacleStartsTravelFaster(false);},
                "_tr_ObstacleStopsTravelFaster" => {self._tr_ObstacleStopsTravelFaster(false);},
                "_tr_ObstacleStartsTravelSlower" => {self._tr_ObstacleStartsTravelSlower(false);},
                "_tr_ObstacleStopsTravelSlower" => {self._tr_ObstacleStopsTravelSlower(false);},
                "_tr_ObstacleAppearsWhenCruiseActive" => {self._tr_ObstacleAppearsWhenCruiseActive(false);},
                "_tr_ObstacleAppearsWhenCruiseInactive" => {self._tr_ObstacleAppearsWhenCruiseInactive(false);},
                "_tr_ObstacleDisappears" => {self._tr_ObstacleDisappears(false);},
                "_tr_VehicleManageObstacle" => {self._tr_VehicleManageObstacle(false);},
                "_tr_ObstacleBecomesOld" => {self._tr_ObstacleBecomesOld(false);},
                _ => {},
            }
        }
    }

    //model_check_next_states
    fn generateNextStates(state: &mut Cruise_finite1_deterministic_MC,
                          isCaching: bool,
                          transitions: Arc<AtomicU64>) -> HashSet<(Cruise_finite1_deterministic_MC, &'static str)> {
        let mut result = HashSet::<(Cruise_finite1_deterministic_MC, &'static str)>::new();
        let mut evaluated_transitions: u64 = 0;
        //model_check_transition
        if state._tr_CruiseBecomesNotAllowed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.CruiseBecomesNotAllowed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CruiseBecomesNotAllowed")); }
            result.insert((copiedState, "CruiseBecomesNotAllowed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_CruiseBecomesAllowed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.CruiseBecomesAllowed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CruiseBecomesAllowed")); }
            result.insert((copiedState, "CruiseBecomesAllowed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_3 = state._tr_SetCruiseSpeed(isCaching);
        for param in _trid_3.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("SetCruiseSpeed")); }
            result.insert((copiedState, "SetCruiseSpeed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_4 = state._tr_CCInitialisationFinished(isCaching);
        for param in _trid_4.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CCInitialisationFinished")); }
            result.insert((copiedState, "CCInitialisationFinished"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_CCInitialisationDelayFinished(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.CCInitialisationDelayFinished();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CCInitialisationDelayFinished")); }
            result.insert((copiedState, "CCInitialisationDelayFinished"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_6 = state._tr_CruiseSpeedChangeFinished(isCaching);
        for param in _trid_6.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CruiseSpeedChangeFinished")); }
            result.insert((copiedState, "CruiseSpeedChangeFinished"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_CruiseSpeedChangeDelayFinished(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.CruiseSpeedChangeDelayFinished();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CruiseSpeedChangeDelayFinished")); }
            result.insert((copiedState, "CruiseSpeedChangeDelayFinished"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_CruiseOff(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.CruiseOff();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("CruiseOff")); }
            result.insert((copiedState, "CruiseOff"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ExternalForcesBecomesExtreme(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ExternalForcesBecomesExtreme();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ExternalForcesBecomesExtreme")); }
            result.insert((copiedState, "ExternalForcesBecomesExtreme"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ExternalForcesBecomesNormal(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ExternalForcesBecomesNormal();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ExternalForcesBecomesNormal")); }
            result.insert((copiedState, "ExternalForcesBecomesNormal"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_VehicleLeavesCruiseSpeed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.VehicleLeavesCruiseSpeed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("VehicleLeavesCruiseSpeed")); }
            result.insert((copiedState, "VehicleLeavesCruiseSpeed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_VehicleReachesCruiseSpeed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.VehicleReachesCruiseSpeed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("VehicleReachesCruiseSpeed")); }
            result.insert((copiedState, "VehicleReachesCruiseSpeed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_VehicleExceedsMaxCruiseSpeed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.VehicleExceedsMaxCruiseSpeed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("VehicleExceedsMaxCruiseSpeed")); }
            result.insert((copiedState, "VehicleExceedsMaxCruiseSpeed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_VehicleFallsBelowMaxCruiseSpeed(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.VehicleFallsBelowMaxCruiseSpeed();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("VehicleFallsBelowMaxCruiseSpeed")); }
            result.insert((copiedState, "VehicleFallsBelowMaxCruiseSpeed"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleDistanceBecomesVeryClose(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleDistanceBecomesVeryClose();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleDistanceBecomesVeryClose")); }
            result.insert((copiedState, "ObstacleDistanceBecomesVeryClose"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleDistanceBecomesClose(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleDistanceBecomesClose();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleDistanceBecomesClose")); }
            result.insert((copiedState, "ObstacleDistanceBecomesClose"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleDistanceBecomesBig(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleDistanceBecomesBig();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleDistanceBecomesBig")); }
            result.insert((copiedState, "ObstacleDistanceBecomesBig"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleStartsTravelFaster(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleStartsTravelFaster();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleStartsTravelFaster")); }
            result.insert((copiedState, "ObstacleStartsTravelFaster"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleStopsTravelFaster(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleStopsTravelFaster();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleStopsTravelFaster")); }
            result.insert((copiedState, "ObstacleStopsTravelFaster"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleStartsTravelSlower(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleStartsTravelSlower();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleStartsTravelSlower")); }
            result.insert((copiedState, "ObstacleStartsTravelSlower"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleStopsTravelSlower(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleStopsTravelSlower();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleStopsTravelSlower")); }
            result.insert((copiedState, "ObstacleStopsTravelSlower"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive(isCaching);
        for param in _trid_22.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleAppearsWhenCruiseActive")); }
            result.insert((copiedState, "ObstacleAppearsWhenCruiseActive"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive(isCaching);
        for param in _trid_23.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param;

            let mut copiedState = state.clone();
            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleAppearsWhenCruiseInactive")); }
            result.insert((copiedState, "ObstacleAppearsWhenCruiseInactive"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleDisappears(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleDisappears();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleDisappears")); }
            result.insert((copiedState, "ObstacleDisappears"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        let mut _trid_25 = state._tr_VehicleManageObstacle(isCaching);
        for param in _trid_25.iter().cloned() {
            //model_check_transition_body
            //model_check_transition_param_assignment
            let mut _tmp_1 = param.projection2();
            //model_check_transition_param_assignment
            let mut _tmp_2 = param.projection1();

            let mut copiedState = state.clone();
            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("VehicleManageObstacle")); }
            result.insert((copiedState, "VehicleManageObstacle"));
            evaluated_transitions += 1;
        }
        //model_check_transition
        if state._tr_ObstacleBecomesOld(isCaching) {
            //model_check_transition_body
            let mut copiedState = state.clone();
            copiedState.ObstacleBecomesOld();
            if isCaching { copiedState.invalidate_caches(Self::get_guard_dependencies("ObstacleBecomesOld")); }
            result.insert((copiedState, "ObstacleBecomesOld"));
            evaluated_transitions += 1;
        }


        transitions.fetch_add(evaluated_transitions, Ordering::AcqRel);
        return result;
    }

    //model_check_invariants
    pub fn checkInvariants(state: &Cruise_finite1_deterministic_MC, last_op: &'static str, isCaching: bool) -> bool {
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
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_19") {
                if !state._check_inv_19() {
                    println!("_check_inv_19 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_20") {
                if !state._check_inv_20() {
                    println!("_check_inv_20 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_21") {
                if !state._check_inv_21() {
                    println!("_check_inv_21 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_22") {
                if !state._check_inv_22() {
                    println!("_check_inv_22 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_23") {
                if !state._check_inv_23() {
                    println!("_check_inv_23 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_24") {
                if !state._check_inv_24() {
                    println!("_check_inv_24 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_25") {
                if !state._check_inv_25() {
                    println!("_check_inv_25 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_26") {
                if !state._check_inv_26() {
                    println!("_check_inv_26 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_27") {
                if !state._check_inv_27() {
                    println!("_check_inv_27 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_28") {
                if !state._check_inv_28() {
                    println!("_check_inv_28 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_29") {
                if !state._check_inv_29() {
                    println!("_check_inv_29 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_30") {
                if !state._check_inv_30() {
                    println!("_check_inv_30 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_31") {
                if !state._check_inv_31() {
                    println!("_check_inv_31 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_32") {
                if !state._check_inv_32() {
                    println!("_check_inv_32 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_33") {
                if !state._check_inv_33() {
                    println!("_check_inv_33 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_34") {
                if !state._check_inv_34() {
                    println!("_check_inv_34 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_35") {
                if !state._check_inv_35() {
                    println!("_check_inv_35 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_36") {
                if !state._check_inv_36() {
                    println!("_check_inv_36 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_37") {
                if !state._check_inv_37() {
                    println!("_check_inv_37 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_38") {
                if !state._check_inv_38() {
                    println!("_check_inv_38 failed!");
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains(&"_check_inv_39") {
                if !state._check_inv_39() {
                    println!("_check_inv_39 failed!");
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25() || !state._check_inv_26() || !state._check_inv_27() || !state._check_inv_28() || !state._check_inv_29() || !state._check_inv_30() || !state._check_inv_31() || !state._check_inv_32() || !state._check_inv_33() || !state._check_inv_34() || !state._check_inv_35() || !state._check_inv_36() || !state._check_inv_37() || !state._check_inv_38() || !state._check_inv_39());
    }

    //model_check_print
    fn print_result(states: usize, transitions: u64, error_detected: bool) {
        if !error_detected { println!("MODEL CHECKING SUCCESSFUL"); }
        println!("Number of States: {}", states);
        println!("Number of Transitions: {}", transitions);
    }

    //model_check_main
    fn next(collection_m: Arc<Mutex<LinkedList<(Cruise_finite1_deterministic_MC, &'static str)>>>, mc_type: MC_TYPE) -> (Cruise_finite1_deterministic_MC, &'static str) {
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
            "ObstacleStopsTravelSlower" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"],
            //model_check_init_static
            "SetCruiseSpeed" => vec!["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "VehicleLeavesCruiseSpeed" => vec!["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "VehicleFallsBelowMaxCruiseSpeed" => vec!["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "CCInitialisationFinished" => vec!["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "VehicleReachesCruiseSpeed" => vec!["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "ObstacleAppearsWhenCruiseActive" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "ObstacleStartsTravelSlower" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"],
            //model_check_init_static
            "CruiseBecomesNotAllowed" => vec!["_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "ObstacleAppearsWhenCruiseInactive" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "CCInitialisationDelayFinished" => vec!["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            //model_check_init_static
            "ObstacleDistanceBecomesClose" => vec!["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            //model_check_init_static
            "ObstacleStartsTravelFaster" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"],
            //model_check_init_static
            "ExternalForcesBecomesExtreme" => vec!["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "CruiseOff" => vec!["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "CruiseSpeedChangeDelayFinished" => vec!["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            //model_check_init_static
            "ObstacleStopsTravelFaster" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"],
            //model_check_init_static
            "ObstacleDistanceBecomesVeryClose" => vec!["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            //model_check_init_static
            "VehicleManageObstacle" => vec!["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "CruiseBecomesAllowed" => vec!["_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"],
            //model_check_init_static
            "VehicleExceedsMaxCruiseSpeed" => vec!["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "CruiseSpeedChangeFinished" => vec!["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "ObstacleDisappears" => vec!["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"],
            //model_check_init_static
            "ExternalForcesBecomesNormal" => vec!["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"],
            //model_check_init_static
            "ObstacleBecomesOld" => vec!["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            //model_check_init_static
            "ObstacleDistanceBecomesBig" => vec!["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"],
            _ => vec![],
        }
    }

    fn get_invariant_dependencies(op: &'static str) -> Vec<&str> {
        return match op {
            //model_check_init_static
            "ObstacleStopsTravelSlower" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"],
            //model_check_init_static
            "SetCruiseSpeed" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"],
            //model_check_init_static
            "VehicleLeavesCruiseSpeed" => vec!["_check_inv_17", "_check_inv_3", "_check_inv_34"],
            //model_check_init_static
            "VehicleFallsBelowMaxCruiseSpeed" => vec!["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"],
            //model_check_init_static
            "CCInitialisationFinished" => vec!["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"],
            //model_check_init_static
            "VehicleReachesCruiseSpeed" => vec!["_check_inv_17", "_check_inv_3", "_check_inv_34"],
            //model_check_init_static
            "ObstacleAppearsWhenCruiseActive" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"],
            //model_check_init_static
            "ObstacleStartsTravelSlower" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"],
            //model_check_init_static
            "CruiseBecomesNotAllowed" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"],
            //model_check_init_static
            "ObstacleAppearsWhenCruiseInactive" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"],
            //model_check_init_static
            "CCInitialisationDelayFinished" => vec!["_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"],
            //model_check_init_static
            "ObstacleDistanceBecomesClose" => vec!["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"],
            //model_check_init_static
            "ObstacleStartsTravelFaster" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"],
            //model_check_init_static
            "ExternalForcesBecomesExtreme" => vec!["_check_inv_18", "_check_inv_4"],
            //model_check_init_static
            "CruiseOff" => vec!["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"],
            //model_check_init_static
            "CruiseSpeedChangeDelayFinished" => vec!["_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"],
            //model_check_init_static
            "ObstacleStopsTravelFaster" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"],
            //model_check_init_static
            "ObstacleDistanceBecomesVeryClose" => vec!["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"],
            //model_check_init_static
            "VehicleManageObstacle" => vec!["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"],
            //model_check_init_static
            "CruiseBecomesAllowed" => vec!["_check_inv_1", "_check_inv_33"],
            //model_check_init_static
            "VehicleExceedsMaxCruiseSpeed" => vec!["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"],
            //model_check_init_static
            "CruiseSpeedChangeFinished" => vec!["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"],
            //model_check_init_static
            "ObstacleDisappears" => vec!["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"],
            //model_check_init_static
            "ExternalForcesBecomesNormal" => vec!["_check_inv_18", "_check_inv_4"],
            //model_check_init_static
            "ObstacleBecomesOld" => vec!["_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"],
            //model_check_init_static
            "ObstacleDistanceBecomesBig" => vec!["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"],
            _ => vec![],
        }
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool, no_dead: bool, no_inv: bool) {
        let mut machine = Cruise_finite1_deterministic_MC::new();

        let mut all_states = HashSet::<Cruise_finite1_deterministic_MC>::new();
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Cruise_finite1_deterministic_MC, &'static str)>::new()));
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

        let machine = Cruise_finite1_deterministic_MC::new();

        let all_states = Arc::new(DashSet::<Cruise_finite1_deterministic_MC>::new());
        all_states.insert(machine.clone());

        let states_to_process_mutex = Arc::new(Mutex::new(LinkedList::<(Cruise_finite1_deterministic_MC, &'static str)>::new()));
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
        Cruise_finite1_deterministic_MC::model_check_single_threaded(mc_type, is_caching, no_dead, no_inv);
    } else {
        Cruise_finite1_deterministic_MC::modelCheckMultiThreaded(mc_type, threads, is_caching, no_dead, no_inv);
    }
}
