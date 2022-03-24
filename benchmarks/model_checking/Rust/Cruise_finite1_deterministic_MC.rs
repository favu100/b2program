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
use btypes::bset::BSet;
use btypes::bobject::BObject;
use btypes::btuple::BTuple;

#[derive(Clone, Copy)]
pub enum MC_TYPE { BFS, DFS, MIXED }


#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum RSset {
    RSnone, 
    RSpos, 
    RSneg, 
    RSequal
}
impl RSset {
    pub fn equal(&self, other: &RSset) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &RSset) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for RSset {}
impl Default for RSset {
    fn default() -> Self { RSset::RSnone }
}
impl fmt::Display for RSset {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           RSset::RSnone => write!(f, "RSnone"),
           RSset::RSpos => write!(f, "RSpos"),
           RSset::RSneg => write!(f, "RSneg"),
           RSset::RSequal => write!(f, "RSequal"),
       }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum ODset {
    ODnone, 
    ODclose, 
    ODveryclose
}
impl ODset {
    pub fn equal(&self, other: &ODset) -> BBoolean { BBoolean::new(*self == *other)}
    pub fn unequal(&self, other: &ODset) -> BBoolean { BBoolean::new(*self != *other)}
}
impl BObject for ODset {}
impl Default for ODset {
    fn default() -> Self { ODset::ODnone }
}
impl fmt::Display for ODset {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
       match *self {
           ODset::ODnone => write!(f, "ODnone"),
           ODset::ODclose => write!(f, "ODclose"),
           ODset::ODveryclose => write!(f, "ODveryclose"),
       }
    }
}

#[derive(Derivative)]
#[derivative(Clone, Default, Debug, Hash, PartialEq, Eq)]
pub struct Cruise_finite1_deterministic_MC {
    CruiseAllowed: BBoolean,
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
    _RSset: BSet<RSset>,
    _ODset: BSet<ODset>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseBecomesNotAllowed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseBecomesAllowed: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_SetCruiseSpeed: Option<BSet<BTuple<BBoolean, BBoolean>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CCInitialisationFinished: Option<BSet<BTuple<BBoolean, BBoolean>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CCInitialisationDelayFinished: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_CruiseSpeedChangeFinished: Option<BSet<BTuple<BBoolean, BBoolean>>>,
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
    _tr_cache_ObstacleAppearsWhenCruiseActive: Option<BSet<BTuple<RSset, ODset>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleAppearsWhenCruiseInactive: Option<BSet<RSset>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleDisappears: Option<bool>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_VehicleManageObstacle: Option<BSet<BTuple<BBoolean, BBoolean>>>,
    #[derivative(Hash="ignore", PartialEq="ignore")]
    _tr_cache_ObstacleBecomesOld: Option<bool>,}

impl fmt::Display for Cruise_finite1_deterministic_MC {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Cruise_finite1_deterministic_MC: (".to_owned();
        result += &format!("_get_CruiseAllowed: {}, ", self._get_CruiseAllowed());
        result += &format!("_get_CruiseActive: {}, ", self._get_CruiseActive());
        result += &format!("_get_VehicleAtCruiseSpeed: {}, ", self._get_VehicleAtCruiseSpeed());
        result += &format!("_get_VehicleCanKeepSpeed: {}, ", self._get_VehicleCanKeepSpeed());
        result += &format!("_get_VehicleTryKeepSpeed: {}, ", self._get_VehicleTryKeepSpeed());
        result += &format!("_get_SpeedAboveMax: {}, ", self._get_SpeedAboveMax());
        result += &format!("_get_VehicleTryKeepTimeGap: {}, ", self._get_VehicleTryKeepTimeGap());
        result += &format!("_get_CruiseSpeedAtMax: {}, ", self._get_CruiseSpeedAtMax());
        result += &format!("_get_ObstaclePresent: {}, ", self._get_ObstaclePresent());
        result += &format!("_get_ObstacleDistance: {}, ", self._get_ObstacleDistance());
        result += &format!("_get_ObstacleRelativeSpeed: {}, ", self._get_ObstacleRelativeSpeed());
        result += &format!("_get_ObstacleStatusJustChanged: {}, ", self._get_ObstacleStatusJustChanged());
        result += &format!("_get_CCInitialisationInProgress: {}, ", self._get_CCInitialisationInProgress());
        result += &format!("_get_CruiseSpeedChangeInProgress: {}, ", self._get_CruiseSpeedChangeInProgress());
        result += &format!("_get_NumberOfSetCruise: {}, ", self._get_NumberOfSetCruise());
        result = result + ")";
        return write!(f, "{}", result);
    }
}

impl Cruise_finite1_deterministic_MC {

    pub fn new() -> Cruise_finite1_deterministic_MC {
        //values: ''
        let mut m: Cruise_finite1_deterministic_MC = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._RSset = BSet::new(vec![RSset::RSnone, RSset::RSpos, RSset::RSneg, RSset::RSequal]);
        self._ODset = BSet::new(vec![ODset::ODnone, ODset::ODclose, ODset::ODveryclose]);
        self.CruiseAllowed = BBoolean::new(true);
        self.CruiseActive = BBoolean::new(false);
        self.VehicleAtCruiseSpeed = BBoolean::new(false);
        self.VehicleCanKeepSpeed = BBoolean::new(false);
        self.VehicleTryKeepSpeed = BBoolean::new(false);
        self.SpeedAboveMax = BBoolean::new(false);
        self.VehicleTryKeepTimeGap = BBoolean::new(false);
        self.NumberOfSetCruise = BInteger::new(0);
        self.CruiseSpeedAtMax = BBoolean::new(false);
        self.ObstacleDistance = ODset::ODnone;
        self.ObstacleStatusJustChanged = BBoolean::new(false);
        self.CCInitialisationInProgress = BBoolean::new(false);
        self.CruiseSpeedChangeInProgress = BBoolean::new(false);
        self.ObstaclePresent = BBoolean::new(false);
        self.ObstacleRelativeSpeed = RSset::RSnone;
    }

    pub fn _get_CruiseAllowed(&self) -> BBoolean {
        return self.CruiseAllowed.clone();
    }

    pub fn _get_CruiseActive(&self) -> BBoolean {
        return self.CruiseActive.clone();
    }

    pub fn _get_VehicleAtCruiseSpeed(&self) -> BBoolean {
        return self.VehicleAtCruiseSpeed.clone();
    }

    pub fn _get_VehicleCanKeepSpeed(&self) -> BBoolean {
        return self.VehicleCanKeepSpeed.clone();
    }

    pub fn _get_VehicleTryKeepSpeed(&self) -> BBoolean {
        return self.VehicleTryKeepSpeed.clone();
    }

    pub fn _get_SpeedAboveMax(&self) -> BBoolean {
        return self.SpeedAboveMax.clone();
    }

    pub fn _get_VehicleTryKeepTimeGap(&self) -> BBoolean {
        return self.VehicleTryKeepTimeGap.clone();
    }

    pub fn _get_CruiseSpeedAtMax(&self) -> BBoolean {
        return self.CruiseSpeedAtMax.clone();
    }

    pub fn _get_ObstaclePresent(&self) -> BBoolean {
        return self.ObstaclePresent.clone();
    }

    pub fn _get_ObstacleDistance(&self) -> ODset {
        return self.ObstacleDistance.clone();
    }

    pub fn _get_ObstacleRelativeSpeed(&self) -> RSset {
        return self.ObstacleRelativeSpeed.clone();
    }

    pub fn _get_ObstacleStatusJustChanged(&self) -> BBoolean {
        return self.ObstacleStatusJustChanged.clone();
    }

    pub fn _get_CCInitialisationInProgress(&self) -> BBoolean {
        return self.CCInitialisationInProgress.clone();
    }

    pub fn _get_CruiseSpeedChangeInProgress(&self) -> BBoolean {
        return self.CruiseSpeedChangeInProgress.clone();
    }

    pub fn _get_NumberOfSetCruise(&self) -> BInteger {
        return self.NumberOfSetCruise.clone();
    }

    pub fn _get__RSset(&self) -> BSet<RSset> {
        return self._RSset.clone();
    }

    pub fn _get__ODset(&self) -> BSet<ODset> {
        return self._ODset.clone();
    }

    pub fn CruiseBecomesNotAllowed(&mut self) -> () {
        if (self.CruiseAllowed.equal(&BBoolean::new(true))).booleanValue() {
            self.CruiseAllowed = BBoolean::new(false);
            self.CruiseActive = BBoolean::new(false);
            self.VehicleCanKeepSpeed = BBoolean::new(false);
            self.VehicleTryKeepSpeed = BBoolean::new(false);
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
            self.VehicleTryKeepTimeGap = BBoolean::new(false);
            self.CruiseSpeedAtMax = BBoolean::new(false);
            self.ObstacleDistance = ODset::ODnone;
            self.NumberOfSetCruise = BInteger::new(0);
            self.ObstacleStatusJustChanged = BBoolean::new(false);
            self.CCInitialisationInProgress = BBoolean::new(false);
            self.CruiseSpeedChangeInProgress = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseBecomesAllowed(&mut self) -> () {
        if (self.CruiseAllowed.equal(&BBoolean::new(false))).booleanValue() {
            self.CruiseAllowed = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn SetCruiseSpeed(&mut self, mut vcks: BBoolean, mut csam: BBoolean) -> () {
        //pre_assert
        let mut _ld_NumberOfSetCruise = self.NumberOfSetCruise.clone();
        let mut _ld_CruiseActive = self.CruiseActive.clone();
        self.CruiseActive = BBoolean::new(true);
        self.VehicleCanKeepSpeed = vcks;
        if (self.SpeedAboveMax.equal(&BBoolean::new(false))).booleanValue() {
            self.VehicleAtCruiseSpeed = BBoolean::new(true);
            self.CruiseSpeedAtMax = csam;
        } else {
            self.CruiseSpeedAtMax = BBoolean::new(true);
        }
        self.ObstacleStatusJustChanged = BBoolean::new(true);
        if (_ld_CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
            self.CruiseSpeedChangeInProgress = BBoolean::new(true);
        } else {
            self.CCInitialisationInProgress = BBoolean::new(true);
        }
        if (_ld_NumberOfSetCruise.less(&BInteger::new(1))).booleanValue() {
            self.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(&BInteger::new(1));
        } 

    }

    pub fn CCInitialisationFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //pre_assert
        self.VehicleTryKeepTimeGap = vtktg;
        self.VehicleTryKeepSpeed = vtks;

    }

    pub fn CCInitialisationDelayFinished(&mut self) -> () {
        if ((((((self.CCInitialisationInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
            self.CCInitialisationInProgress = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if ((((((((((((butils::BOOL.elementOf(&vtks) && butils::BOOL.elementOf(&vtktg)) && (((vtks.equal(&BBoolean::new(true)) || vtktg.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true)))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false)))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeDelayFinished(&mut self) -> () {
        if ((((((self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
            self.CruiseSpeedChangeInProgress = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseOff(&mut self) -> () {
        if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
            self.CruiseActive = BBoolean::new(false);
            self.VehicleCanKeepSpeed = BBoolean::new(false);
            self.VehicleTryKeepSpeed = BBoolean::new(false);
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
            self.VehicleTryKeepTimeGap = BBoolean::new(false);
            self.CruiseSpeedAtMax = BBoolean::new(false);
            self.ObstacleDistance = ODset::ODnone;
            self.NumberOfSetCruise = BInteger::new(0);
            self.ObstacleStatusJustChanged = BBoolean::new(false);
            self.CCInitialisationInProgress = BBoolean::new(false);
            self.CruiseSpeedChangeInProgress = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ExternalForcesBecomesExtreme(&mut self) -> () {
        if (self.VehicleCanKeepSpeed.equal(&BBoolean::new(true))).booleanValue() {
            self.VehicleCanKeepSpeed = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ExternalForcesBecomesNormal(&mut self) -> () {
        if ((self.CruiseActive.equal(&BBoolean::new(true)) && self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleCanKeepSpeed = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleLeavesCruiseSpeed(&mut self) -> () {
        if (((self.VehicleAtCruiseSpeed.equal(&BBoolean::new(true)) && (self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)) && self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) || self.VehicleTryKeepSpeed.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleReachesCruiseSpeed(&mut self) -> () {
        if (((self.CruiseActive.equal(&BBoolean::new(true)) && self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))) && self.SpeedAboveMax.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleAtCruiseSpeed = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleExceedsMaxCruiseSpeed(&mut self) -> () {
        if ((self.SpeedAboveMax.equal(&BBoolean::new(false)) && ((self.CruiseActive.equal(&BBoolean::new(false)) || self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))) || ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))))).booleanValue() {
            self.SpeedAboveMax = BBoolean::new(true);
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleFallsBelowMaxCruiseSpeed(&mut self) -> () {
        if (self.SpeedAboveMax.equal(&BBoolean::new(true))).booleanValue() {
            self.SpeedAboveMax = BBoolean::new(false);
            if ((self.CruiseActive.equal(&BBoolean::new(true)) && self.CruiseSpeedAtMax.equal(&BBoolean::new(true)))).booleanValue() {
                self.VehicleAtCruiseSpeed = BBoolean::new(true);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesVeryClose(&mut self) -> () {
        if ((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSneg))).booleanValue() {
            self.ObstacleDistance = ODset::ODveryclose;
            self.ObstacleStatusJustChanged = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesClose(&mut self) -> () {
        if (((self.ObstaclePresent.equal(&BBoolean::new(true)) && self.CruiseActive.equal(&BBoolean::new(true))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSpos)) || (self.ObstacleDistance.equal(&ODset::ODnone) && self.ObstacleRelativeSpeed.equal(&RSset::RSneg))))).booleanValue() {
            self.ObstacleDistance = ODset::ODclose;
            self.ObstacleStatusJustChanged = BBoolean::new(true);
            if (self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).booleanValue() {
                self.VehicleTryKeepTimeGap = BBoolean::new(false);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesBig(&mut self) -> () {
        if ((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSpos))).booleanValue() {
            self.ObstacleStatusJustChanged = BBoolean::new(true);
            self.ObstacleDistance = ODset::ODnone;
            self.VehicleTryKeepTimeGap = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStartsTravelFaster(&mut self) -> () {
        if ((self.ObstaclePresent.equal(&BBoolean::new(true)) && self.ObstacleRelativeSpeed.equal(&RSset::RSequal))).booleanValue() {
            self.ObstacleRelativeSpeed = RSset::RSpos;
            if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
                self.ObstacleStatusJustChanged = BBoolean::new(true);
            } 
            if (self.ObstacleDistance.unequal(&ODset::ODveryclose)).booleanValue() {
                self.VehicleTryKeepTimeGap = BBoolean::new(false);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStopsTravelFaster(&mut self) -> () {
        if (self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).booleanValue() {
            self.ObstacleRelativeSpeed = RSset::RSequal;
            if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
                self.ObstacleStatusJustChanged = BBoolean::new(true);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStartsTravelSlower(&mut self) -> () {
        if (self.ObstacleRelativeSpeed.equal(&RSset::RSequal)).booleanValue() {
            self.ObstacleRelativeSpeed = RSset::RSneg;
            if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
                self.ObstacleStatusJustChanged = BBoolean::new(true);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStopsTravelSlower(&mut self) -> () {
        if (self.ObstacleRelativeSpeed.equal(&RSset::RSneg)).booleanValue() {
            self.ObstacleRelativeSpeed = RSset::RSequal;
            if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
                self.ObstacleStatusJustChanged = BBoolean::new(true);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleAppearsWhenCruiseActive(&mut self, mut ors: RSset, mut od: ODset) -> () {
        //pre_assert
        self.ObstaclePresent = BBoolean::new(true);
        self.ObstacleStatusJustChanged = BBoolean::new(true);
        self.ObstacleRelativeSpeed = ors;
        self.ObstacleDistance = od;

    }

    pub fn ObstacleAppearsWhenCruiseInactive(&mut self, mut ors: RSset) -> () {
        //pre_assert
        self.ObstaclePresent = BBoolean::new(true);
        self.ObstacleRelativeSpeed = ors;
        self.ObstacleDistance = ODset::ODnone;

    }

    pub fn ObstacleDisappears(&mut self) -> () {
        if (self.ObstaclePresent.equal(&BBoolean::new(true))).booleanValue() {
            self.ObstaclePresent = BBoolean::new(false);
            self.ObstacleRelativeSpeed = RSset::RSnone;
            if (self.CruiseActive.equal(&BBoolean::new(true))).booleanValue() {
                self.ObstacleStatusJustChanged = BBoolean::new(true);
            } 
            self.ObstacleDistance = ODset::ODnone;
            self.VehicleTryKeepTimeGap = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleManageObstacle(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if ((((((((((((butils::BOOL.elementOf(&vtks) && butils::BOOL.elementOf(&vtktg)) && (((vtks.equal(&BBoolean::new(true)) || vtktg.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false)))) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleBecomesOld(&mut self) -> () {
        if ((((((self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
            self.ObstacleStatusJustChanged = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn _tr_CruiseBecomesNotAllowed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseBecomesNotAllowed.is_none() {
            let mut __tmp__val__ = self.CruiseAllowed.equal(&BBoolean::new(true)).booleanValue();
            self._tr_cache_CruiseBecomesNotAllowed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseBecomesNotAllowed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseBecomesAllowed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseBecomesAllowed.is_none() {
            let mut __tmp__val__ = self.CruiseAllowed.equal(&BBoolean::new(false)).booleanValue();
            self._tr_cache_CruiseBecomesAllowed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseBecomesAllowed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_SetCruiseSpeed(&mut self, is_caching: bool) -> BSet<BTuple<BBoolean, BBoolean>> {
        //transition
        if !is_caching || self._tr_cache_SetCruiseSpeed.is_none() {
            let mut _ic_set_2: BSet<BTuple<BBoolean, BBoolean>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_vcks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_csam_1 in butils::BOOL.clone().iter().cloned() {
                    if (self.CruiseAllowed.equal(&BBoolean::new(true))).booleanValue() {
                        _ic_set_2 = _ic_set_2._union(&BSet::new(vec![BTuple::from_refs(&_ic_vcks_1, &_ic_csam_1)]));
                    }

                }
            }
            self._tr_cache_SetCruiseSpeed = Option::Some(_ic_set_2.clone());
            return _ic_set_2;
        } else {
            return self._tr_cache_SetCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CCInitialisationFinished(&mut self, is_caching: bool) -> BSet<BTuple<BBoolean, BBoolean>> {
        //transition
        if !is_caching || self._tr_cache_CCInitialisationFinished.is_none() {
            let mut _ic_set_3: BSet<BTuple<BBoolean, BBoolean>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (((((((((((((_ic_vtks_1.equal(&BBoolean::new(true)) || _ic_vtktg_1.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).booleanValue() {
                        _ic_set_3 = _ic_set_3._union(&BSet::new(vec![BTuple::from_refs(&_ic_vtks_1, &_ic_vtktg_1)]));
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
            let mut __tmp__val__ = (((((self.CCInitialisationInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
            self._tr_cache_CCInitialisationDelayFinished = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CCInitialisationDelayFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseSpeedChangeFinished(&mut self, is_caching: bool) -> BSet<BTuple<BBoolean, BBoolean>> {
        //transition
        if !is_caching || self._tr_cache_CruiseSpeedChangeFinished.is_none() {
            let mut _ic_set_5: BSet<BTuple<BBoolean, BBoolean>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (((((((((((((_ic_vtks_1.equal(&BBoolean::new(true)) || _ic_vtktg_1.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).booleanValue() {
                        _ic_set_5 = _ic_set_5._union(&BSet::new(vec![BTuple::from_refs(&_ic_vtks_1, &_ic_vtktg_1)]));
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
            let mut __tmp__val__ = (((((self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
            self._tr_cache_CruiseSpeedChangeDelayFinished = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseSpeedChangeDelayFinished.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_CruiseOff(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_CruiseOff.is_none() {
            let mut __tmp__val__ = self.CruiseActive.equal(&BBoolean::new(true)).booleanValue();
            self._tr_cache_CruiseOff = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_CruiseOff.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ExternalForcesBecomesExtreme(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ExternalForcesBecomesExtreme.is_none() {
            let mut __tmp__val__ = self.VehicleCanKeepSpeed.equal(&BBoolean::new(true)).booleanValue();
            self._tr_cache_ExternalForcesBecomesExtreme = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ExternalForcesBecomesExtreme.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ExternalForcesBecomesNormal(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ExternalForcesBecomesNormal.is_none() {
            let mut __tmp__val__ = (self.CruiseActive.equal(&BBoolean::new(true)) && self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_ExternalForcesBecomesNormal = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ExternalForcesBecomesNormal.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleLeavesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleLeavesCruiseSpeed.is_none() {
            let mut __tmp__val__ = ((self.VehicleAtCruiseSpeed.equal(&BBoolean::new(true)) && (self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)) && self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) || self.VehicleTryKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_VehicleLeavesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleLeavesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleReachesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleReachesCruiseSpeed.is_none() {
            let mut __tmp__val__ = ((self.CruiseActive.equal(&BBoolean::new(true)) && self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))) && self.SpeedAboveMax.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_VehicleReachesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleReachesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleExceedsMaxCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleExceedsMaxCruiseSpeed.is_none() {
            let mut __tmp__val__ = (self.SpeedAboveMax.equal(&BBoolean::new(false)) && ((self.CruiseActive.equal(&BBoolean::new(false)) || self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))) || ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))))).booleanValue();
            self._tr_cache_VehicleExceedsMaxCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleExceedsMaxCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleFallsBelowMaxCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleFallsBelowMaxCruiseSpeed.is_none() {
            let mut __tmp__val__ = self.SpeedAboveMax.equal(&BBoolean::new(true)).booleanValue();
            self._tr_cache_VehicleFallsBelowMaxCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleFallsBelowMaxCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesVeryClose(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesVeryClose.is_none() {
            let mut __tmp__val__ = (self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSneg)).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesVeryClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesVeryClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesClose(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesClose.is_none() {
            let mut __tmp__val__ = ((self.ObstaclePresent.equal(&BBoolean::new(true)) && self.CruiseActive.equal(&BBoolean::new(true))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSpos)) || (self.ObstacleDistance.equal(&ODset::ODnone) && self.ObstacleRelativeSpeed.equal(&RSset::RSneg)))).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesBig(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesBig.is_none() {
            let mut __tmp__val__ = (self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesBig = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesBig.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStartsTravelFaster(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStartsTravelFaster.is_none() {
            let mut __tmp__val__ = (self.ObstaclePresent.equal(&BBoolean::new(true)) && self.ObstacleRelativeSpeed.equal(&RSset::RSequal)).booleanValue();
            self._tr_cache_ObstacleStartsTravelFaster = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStartsTravelFaster.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStopsTravelFaster(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStopsTravelFaster.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&RSset::RSpos).booleanValue();
            self._tr_cache_ObstacleStopsTravelFaster = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStopsTravelFaster.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStartsTravelSlower(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStartsTravelSlower.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&RSset::RSequal).booleanValue();
            self._tr_cache_ObstacleStartsTravelSlower = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStartsTravelSlower.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStopsTravelSlower(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStopsTravelSlower.is_none() {
            let mut __tmp__val__ = self.ObstacleRelativeSpeed.equal(&RSset::RSneg).booleanValue();
            self._tr_cache_ObstacleStopsTravelSlower = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleStopsTravelSlower.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleAppearsWhenCruiseActive(&mut self, is_caching: bool) -> BSet<BTuple<RSset, ODset>> {
        //transition
        if !is_caching || self._tr_cache_ObstacleAppearsWhenCruiseActive.is_none() {
            let mut _ic_set_21: BSet<BTuple<RSset, ODset>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_ors_1 in self._RSset.difference(&BSet::new(vec![RSset::RSnone])).clone().iter().cloned() {
                for _ic_od_1 in self._ODset.difference(&BSet::new(vec![ODset::ODnone])).clone().iter().cloned() {
                    if ((self.ObstaclePresent.equal(&BBoolean::new(false)) && self.CruiseActive.equal(&BBoolean::new(true)))).booleanValue() {
                        _ic_set_21 = _ic_set_21._union(&BSet::new(vec![BTuple::from_refs(&_ic_ors_1, &_ic_od_1)]));
                    }

                }
            }
            self._tr_cache_ObstacleAppearsWhenCruiseActive = Option::Some(_ic_set_21.clone());
            return _ic_set_21;
        } else {
            return self._tr_cache_ObstacleAppearsWhenCruiseActive.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleAppearsWhenCruiseInactive(&mut self, is_caching: bool) -> BSet<RSset> {
        //transition
        if !is_caching || self._tr_cache_ObstacleAppearsWhenCruiseInactive.is_none() {
            let mut _ic_set_22: BSet<RSset> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_ors_1 in self._RSset.difference(&BSet::new(vec![RSset::RSnone])).clone().iter().cloned() {
                if ((self.ObstaclePresent.equal(&BBoolean::new(false)) && self.CruiseActive.equal(&BBoolean::new(false)))).booleanValue() {
                    _ic_set_22 = _ic_set_22._union(&BSet::new(vec![_ic_ors_1]));
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
            let mut __tmp__val__ = self.ObstaclePresent.equal(&BBoolean::new(true)).booleanValue();
            self._tr_cache_ObstacleDisappears = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDisappears.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleManageObstacle(&mut self, is_caching: bool) -> BSet<BTuple<BBoolean, BBoolean>> {
        //transition
        if !is_caching || self._tr_cache_VehicleManageObstacle.is_none() {
            let mut _ic_set_24: BSet<BTuple<BBoolean, BBoolean>> = BSet::new(vec![]);
            //transition, parameters, no condidtion
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (((((((((((((_ic_vtks_1.equal(&BBoolean::new(true)) || _ic_vtktg_1.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)))).booleanValue() {
                        _ic_set_24 = _ic_set_24._union(&BSet::new(vec![BTuple::from_refs(&_ic_vtks_1, &_ic_vtktg_1)]));
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
            let mut __tmp__val__ = (((((self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
            self._tr_cache_ObstacleBecomesOld = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleBecomesOld.as_ref().unwrap().clone();
        }
    }

    pub fn _check_inv_1(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.CruiseAllowed).booleanValue();
    }

    pub fn _check_inv_2(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.CruiseActive).booleanValue();
    }

    pub fn _check_inv_3(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.VehicleAtCruiseSpeed).booleanValue();
    }

    pub fn _check_inv_4(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.VehicleCanKeepSpeed).booleanValue();
    }

    pub fn _check_inv_5(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.VehicleTryKeepSpeed).booleanValue();
    }

    pub fn _check_inv_6(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.SpeedAboveMax).booleanValue();
    }

    pub fn _check_inv_7(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.VehicleTryKeepTimeGap).booleanValue();
    }

    pub fn _check_inv_8(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.CruiseSpeedAtMax).booleanValue();
    }

    pub fn _check_inv_9(&self) -> bool {
        //invariant
        return self.NumberOfSetCruise.isNatural().booleanValue();
    }

    pub fn _check_inv_10(&self) -> bool {
        //invariant
        return BSet::<BInteger>::interval(&BInteger::new(0), &BInteger::new(1)).elementOf(&self.NumberOfSetCruise).booleanValue();
    }

    pub fn _check_inv_11(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.ObstaclePresent).booleanValue();
    }

    pub fn _check_inv_12(&self) -> bool {
        //invariant
        return self._ODset.elementOf(&self.ObstacleDistance).booleanValue();
    }

    pub fn _check_inv_13(&self) -> bool {
        //invariant
        return self._RSset.elementOf(&self.ObstacleRelativeSpeed).booleanValue();
    }

    pub fn _check_inv_14(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.ObstacleStatusJustChanged).booleanValue();
    }

    pub fn _check_inv_15(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.CCInitialisationInProgress).booleanValue();
    }

    pub fn _check_inv_16(&self) -> bool {
        //invariant
        return butils::BOOL.elementOf(&self.CruiseSpeedChangeInProgress).booleanValue();
    }

    pub fn _check_inv_17(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_18(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_19(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_20(&self) -> bool {
        //invariant
        return self.NumberOfSetCruise.equal(&BInteger::new(0)).equivalent(&self.CruiseActive.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_21(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_22(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.CruiseSpeedAtMax.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_23(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.ObstacleDistance.equal(&ODset::ODnone)).booleanValue();
    }

    pub fn _check_inv_24(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_25(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_26(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(false)).implies(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_27(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_28(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&self.ObstacleDistance.equal(&ODset::ODnone)).booleanValue();
    }

    pub fn _check_inv_29(&self) -> bool {
        //invariant
        return self.ObstaclePresent.equal(&BBoolean::new(false)).equivalent(&self.ObstacleRelativeSpeed.equal(&RSset::RSnone)).booleanValue();
    }

    pub fn _check_inv_30(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_31(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_32(&self) -> bool {
        //invariant
        return (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_33(&self) -> bool {
        //invariant
        return self.CruiseAllowed.equal(&BBoolean::new(false)).implies(&self.CruiseActive.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_34(&self) -> bool {
        //invariant
        return self.SpeedAboveMax.equal(&BBoolean::new(true)).implies(&self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_35(&self) -> bool {
        //invariant
        return self.CruiseActive.equal(&BBoolean::new(true)).implies(&((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).not())).booleanValue();
    }

    pub fn _check_inv_36(&self) -> bool {
        //invariant
        return ((self.ObstacleDistance.equal(&ODset::ODnone) && self.CruiseActive.equal(&BBoolean::new(true))) && ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_37(&self) -> bool {
        //invariant
        return ((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_38(&self) -> bool {
        //invariant
        return (self.ObstacleDistance.equal(&ODset::ODveryclose) && ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_39(&self) -> bool {
        //invariant
        return (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CruiseActive.equal(&BBoolean::new(true))) && ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))).booleanValue();
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

    //model_check_evaluate_state

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

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
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
                if !Self::checkInvariants(&state, last_op, is_caching) {
                    let _ = tx.send(Err("INVARIANT VIOLATED"));
                }

                let next_states = Self::generateNextStates(&mut state, is_caching, transitions);
                if next_states.is_empty() { let _ = tx.send(Err("DEADLOCK DETECTED")); }

                //println!("Thread {:?} executing", thread::current().id());
                next_states.into_iter()
                           .filter(|(next_state, _)| states.insert((*next_state).clone()))
                           .for_each(|(next_state, last_op)| states_to_process.lock().unwrap().push_back((next_state, last_op)));

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
                match rx.recv_timeout(Duration::from_secs(1)) {
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
        Cruise_finite1_deterministic_MC::model_check_single_threaded(mc_type, is_caching);
    } else {
        Cruise_finite1_deterministic_MC::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
