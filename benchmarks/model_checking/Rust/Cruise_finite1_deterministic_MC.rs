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

    pub fn get__RSset(&self) -> BSet<RSset> {
        return self._RSset.clone();
    }

    pub fn get__ODset(&self) -> BSet<ODset> {
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
        if (self.CCInitialisationInProgress.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
            self.CCInitialisationInProgress = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if (butils::BOOL.elementOf(&vtks).and(&butils::BOOL.elementOf(&vtktg)).and(&vtks.equal(&BBoolean::new(true)).or(&vtktg.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeDelayFinished(&mut self) -> () {
        if (self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
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
        if (self.CruiseActive.equal(&BBoolean::new(true)).and(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleCanKeepSpeed = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleLeavesCruiseSpeed(&mut self) -> () {
        if (self.VehicleAtCruiseSpeed.equal(&BBoolean::new(true)).and(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).or(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleReachesCruiseSpeed(&mut self) -> () {
        if (self.CruiseActive.equal(&BBoolean::new(true)).and(&self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))).and(&self.SpeedAboveMax.equal(&BBoolean::new(false)))).booleanValue() {
            self.VehicleAtCruiseSpeed = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleExceedsMaxCruiseSpeed(&mut self) -> () {
        if (self.SpeedAboveMax.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(false)).or(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))))).booleanValue() {
            self.SpeedAboveMax = BBoolean::new(true);
            self.VehicleAtCruiseSpeed = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn VehicleFallsBelowMaxCruiseSpeed(&mut self) -> () {
        if (self.SpeedAboveMax.equal(&BBoolean::new(true))).booleanValue() {
            self.SpeedAboveMax = BBoolean::new(false);
            if (self.CruiseActive.equal(&BBoolean::new(true)).and(&self.CruiseSpeedAtMax.equal(&BBoolean::new(true)))).booleanValue() {
                self.VehicleAtCruiseSpeed = BBoolean::new(true);
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesVeryClose(&mut self) -> () {
        if (self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg))).booleanValue() {
            self.ObstacleDistance = ODset::ODveryclose;
            self.ObstacleStatusJustChanged = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleDistanceBecomesClose(&mut self) -> () {
        if (self.ObstaclePresent.equal(&BBoolean::new(true)).and(&self.CruiseActive.equal(&BBoolean::new(true))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).or(&self.ObstacleDistance.equal(&ODset::ODnone).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg))))).booleanValue() {
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
        if (self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos))).booleanValue() {
            self.ObstacleStatusJustChanged = BBoolean::new(true);
            self.ObstacleDistance = ODset::ODnone;
            self.VehicleTryKeepTimeGap = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleStartsTravelFaster(&mut self) -> () {
        if (self.ObstaclePresent.equal(&BBoolean::new(true)).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal))).booleanValue() {
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
        if (butils::BOOL.elementOf(&vtks).and(&butils::BOOL.elementOf(&vtktg)).and(&vtks.equal(&BBoolean::new(true)).or(&vtktg.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleBecomesOld(&mut self) -> () {
        if (self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
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
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (_ic_vtks_1.equal(&BBoolean::new(true)).or(&_ic_vtktg_1.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).booleanValue() {
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
            let mut __tmp__val__ = self.CCInitialisationInProgress.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
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
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (_ic_vtks_1.equal(&BBoolean::new(true)).or(&_ic_vtktg_1.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).booleanValue() {
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
            let mut __tmp__val__ = self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
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
            let mut __tmp__val__ = self.CruiseActive.equal(&BBoolean::new(true)).and(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_ExternalForcesBecomesNormal = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ExternalForcesBecomesNormal.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleLeavesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleLeavesCruiseSpeed.is_none() {
            let mut __tmp__val__ = self.VehicleAtCruiseSpeed.equal(&BBoolean::new(true)).and(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).or(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_VehicleLeavesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleLeavesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleReachesCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleReachesCruiseSpeed.is_none() {
            let mut __tmp__val__ = self.CruiseActive.equal(&BBoolean::new(true)).and(&self.VehicleAtCruiseSpeed.equal(&BBoolean::new(false))).and(&self.SpeedAboveMax.equal(&BBoolean::new(false))).booleanValue();
            self._tr_cache_VehicleReachesCruiseSpeed = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_VehicleReachesCruiseSpeed.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_VehicleExceedsMaxCruiseSpeed(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_VehicleExceedsMaxCruiseSpeed.is_none() {
            let mut __tmp__val__ = self.SpeedAboveMax.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(false)).or(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))))).booleanValue();
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
            let mut __tmp__val__ = self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg)).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesVeryClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesVeryClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesClose(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesClose.is_none() {
            let mut __tmp__val__ = self.ObstaclePresent.equal(&BBoolean::new(true)).and(&self.CruiseActive.equal(&BBoolean::new(true))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).or(&self.ObstacleDistance.equal(&ODset::ODnone).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg)))).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesClose = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesClose.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleDistanceBecomesBig(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleDistanceBecomesBig.is_none() {
            let mut __tmp__val__ = self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos)).booleanValue();
            self._tr_cache_ObstacleDistanceBecomesBig = Option::Some(__tmp__val__);
            return __tmp__val__;
        } else {
            return self._tr_cache_ObstacleDistanceBecomesBig.as_ref().unwrap().clone();
        }
    }

    pub fn _tr_ObstacleStartsTravelFaster(&mut self, is_caching: bool) -> bool {
        //transition
        if !is_caching || self._tr_cache_ObstacleStartsTravelFaster.is_none() {
            let mut __tmp__val__ = self.ObstaclePresent.equal(&BBoolean::new(true)).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal)).booleanValue();
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
            for _ic_ors_1 in self._RSset.difference(&BSet::new(vec![RSset::RSnone])).clone().iter().cloned() {
                for _ic_od_1 in self._ODset.difference(&BSet::new(vec![ODset::ODnone])).clone().iter().cloned() {
                    if (self.ObstaclePresent.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(true)))).booleanValue() {
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
            for _ic_ors_1 in self._RSset.difference(&BSet::new(vec![RSset::RSnone])).clone().iter().cloned() {
                if (self.ObstaclePresent.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(false)))).booleanValue() {
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
            for _ic_vtks_1 in butils::BOOL.clone().iter().cloned() {
                for _ic_vtktg_1 in butils::BOOL.clone().iter().cloned() {
                    if (_ic_vtks_1.equal(&BBoolean::new(true)).or(&_ic_vtktg_1.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtktg_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&_ic_vtks_1.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&_ic_vtktg_1.equal(&BBoolean::new(false)))).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)))).booleanValue() {
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
            let mut __tmp__val__ = self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).booleanValue();
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
        return self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_31(&self) -> bool {
        //invariant
        return self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
    }

    pub fn _check_inv_32(&self) -> bool {
        //invariant
        return self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(false))).booleanValue();
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
        return self.CruiseActive.equal(&BBoolean::new(true)).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).not())).booleanValue();
    }

    pub fn _check_inv_36(&self) -> bool {
        //invariant
        return self.ObstacleDistance.equal(&ODset::ODnone).and(&self.CruiseActive.equal(&BBoolean::new(true))).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_37(&self) -> bool {
        //invariant
        return self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_38(&self) -> bool {
        //invariant
        return self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).booleanValue();
    }

    pub fn _check_inv_39(&self) -> bool {
        //invariant
        return self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CruiseActive.equal(&BBoolean::new(true))).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false)))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))).booleanValue();
    }

    fn invalidate_caches(&mut self, to_invalidate: &HashSet<&'static str>) {
        //calling the given functions without caching will recalculate them and cache them afterwards
        //if caching is enabled globally, this will just prefill those, if caching is
        for trans in to_invalidate.iter() {
            match *trans {
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
                          invariant_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_invariant_m: Arc<Mutex<HashMap<Cruise_finite1_deterministic_MC, HashSet<&str>>>>,
                          guard_dependency: &HashMap<&str, HashSet<&'static str>>,
                          dependent_guard_m: Arc<Mutex<HashMap<Cruise_finite1_deterministic_MC, HashSet<&str>>>>,
                          guardCache: Arc<Mutex<HashMap<Cruise_finite1_deterministic_MC, PersistentHashMap<&str, bool>>>>,
                          parents_m: Arc<Mutex<HashMap<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC>>>,
                          transitions: Arc<AtomicI64>) -> HashSet<Cruise_finite1_deterministic_MC> {
        let mut result = HashSet::<Cruise_finite1_deterministic_MC>::new();
        if isCaching {
            let mut parents_guard_o = parents_m.lock().unwrap().get(state).and_then(|p| guardCache.lock().unwrap().get(p).cloned());
            let mut newCache = if parents_guard_o.is_none() { PersistentHashMap::new() } else { parents_guard_o.as_ref().unwrap().clone() };
            //model_check_transition
            let mut _trid_1 = state._tr_CruiseBecomesNotAllowed(isCaching);
            if _trid_1 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseBecomesNotAllowed();
                match guard_dependency.get("CruiseBecomesNotAllowed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CruiseBecomesNotAllowed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CruiseBecomesNotAllowed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_2 = state._tr_CruiseBecomesAllowed(isCaching);
            if _trid_2 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseBecomesAllowed();
                match guard_dependency.get("CruiseBecomesAllowed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CruiseBecomesAllowed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CruiseBecomesAllowed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("SetCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("SetCruiseSpeed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("SetCruiseSpeed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("CCInitialisationFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CCInitialisationFinished").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CCInitialisationFinished").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_5 = state._tr_CCInitialisationDelayFinished(isCaching);
            if _trid_5 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CCInitialisationDelayFinished();
                match guard_dependency.get("CCInitialisationDelayFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CCInitialisationDelayFinished").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CCInitialisationDelayFinished").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("CruiseSpeedChangeFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CruiseSpeedChangeFinished").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CruiseSpeedChangeFinished").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_7 = state._tr_CruiseSpeedChangeDelayFinished(isCaching);
            if _trid_7 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseSpeedChangeDelayFinished();
                match guard_dependency.get("CruiseSpeedChangeDelayFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CruiseSpeedChangeDelayFinished").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CruiseSpeedChangeDelayFinished").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_8 = state._tr_CruiseOff(isCaching);
            if _trid_8 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseOff();
                match guard_dependency.get("CruiseOff") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("CruiseOff").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("CruiseOff").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_9 = state._tr_ExternalForcesBecomesExtreme(isCaching);
            if _trid_9 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ExternalForcesBecomesExtreme();
                match guard_dependency.get("ExternalForcesBecomesExtreme") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ExternalForcesBecomesExtreme").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ExternalForcesBecomesExtreme").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_10 = state._tr_ExternalForcesBecomesNormal(isCaching);
            if _trid_10 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ExternalForcesBecomesNormal();
                match guard_dependency.get("ExternalForcesBecomesNormal") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ExternalForcesBecomesNormal").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ExternalForcesBecomesNormal").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_11 = state._tr_VehicleLeavesCruiseSpeed(isCaching);
            if _trid_11 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleLeavesCruiseSpeed();
                match guard_dependency.get("VehicleLeavesCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("VehicleLeavesCruiseSpeed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("VehicleLeavesCruiseSpeed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_12 = state._tr_VehicleReachesCruiseSpeed(isCaching);
            if _trid_12 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleReachesCruiseSpeed();
                match guard_dependency.get("VehicleReachesCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("VehicleReachesCruiseSpeed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("VehicleReachesCruiseSpeed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed(isCaching);
            if _trid_13 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleExceedsMaxCruiseSpeed();
                match guard_dependency.get("VehicleExceedsMaxCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("VehicleExceedsMaxCruiseSpeed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("VehicleExceedsMaxCruiseSpeed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed(isCaching);
            if _trid_14 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                match guard_dependency.get("VehicleFallsBelowMaxCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("VehicleFallsBelowMaxCruiseSpeed").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("VehicleFallsBelowMaxCruiseSpeed").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose(isCaching);
            if _trid_15 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesVeryClose();
                match guard_dependency.get("ObstacleDistanceBecomesVeryClose") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleDistanceBecomesVeryClose").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleDistanceBecomesVeryClose").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_16 = state._tr_ObstacleDistanceBecomesClose(isCaching);
            if _trid_16 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesClose();
                match guard_dependency.get("ObstacleDistanceBecomesClose") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleDistanceBecomesClose").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleDistanceBecomesClose").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_17 = state._tr_ObstacleDistanceBecomesBig(isCaching);
            if _trid_17 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesBig();
                match guard_dependency.get("ObstacleDistanceBecomesBig") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleDistanceBecomesBig").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleDistanceBecomesBig").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_18 = state._tr_ObstacleStartsTravelFaster(isCaching);
            if _trid_18 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStartsTravelFaster();
                match guard_dependency.get("ObstacleStartsTravelFaster") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleStartsTravelFaster").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleStartsTravelFaster").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_19 = state._tr_ObstacleStopsTravelFaster(isCaching);
            if _trid_19 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStopsTravelFaster();
                match guard_dependency.get("ObstacleStopsTravelFaster") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleStopsTravelFaster").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleStopsTravelFaster").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_20 = state._tr_ObstacleStartsTravelSlower(isCaching);
            if _trid_20 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStartsTravelSlower();
                match guard_dependency.get("ObstacleStartsTravelSlower") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleStartsTravelSlower").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleStartsTravelSlower").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_21 = state._tr_ObstacleStopsTravelSlower(isCaching);
            if _trid_21 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStopsTravelSlower();
                match guard_dependency.get("ObstacleStopsTravelSlower") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleStopsTravelSlower").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleStopsTravelSlower").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("ObstacleAppearsWhenCruiseActive") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleAppearsWhenCruiseActive").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleAppearsWhenCruiseActive").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive(isCaching);
            for param in _trid_23.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                match guard_dependency.get("ObstacleAppearsWhenCruiseInactive") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleAppearsWhenCruiseInactive").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleAppearsWhenCruiseInactive").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_24 = state._tr_ObstacleDisappears(isCaching);
            if _trid_24 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDisappears();
                match guard_dependency.get("ObstacleDisappears") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleDisappears").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleDisappears").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("VehicleManageObstacle") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("VehicleManageObstacle").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("VehicleManageObstacle").unwrap().clone());
                    }
                    if !parents.contains_key(&copiedState) {
                        parents.insert(copiedState.clone(), state.clone());
                    }
                }
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_26 = state._tr_ObstacleBecomesOld(isCaching);
            if _trid_26 {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleBecomesOld();
                match guard_dependency.get("ObstacleBecomesOld") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                {
                    let mut dependent_invariant = dependent_invariant_m.lock().unwrap();
                    let mut dependent_guard = dependent_guard_m.lock().unwrap();
                    let mut parents = parents_m.lock().unwrap();

                    if !dependent_invariant.contains_key(&copiedState) {
                        dependent_invariant.insert(copiedState.clone(), invariant_dependency.get("ObstacleBecomesOld").unwrap().clone());
                    }
                    if !dependent_guard.contains_key(&copiedState) {
                        dependent_guard.insert(copiedState.clone(), guard_dependency.get("ObstacleBecomesOld").unwrap().clone());
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
            if state._tr_CruiseBecomesNotAllowed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseBecomesNotAllowed();
                match guard_dependency.get("CruiseBecomesNotAllowed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_CruiseBecomesAllowed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseBecomesAllowed();
                match guard_dependency.get("CruiseBecomesAllowed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("SetCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("CCInitialisationFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_CCInitialisationDelayFinished(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CCInitialisationDelayFinished();
                match guard_dependency.get("CCInitialisationDelayFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("CruiseSpeedChangeFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_CruiseSpeedChangeDelayFinished(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseSpeedChangeDelayFinished();
                match guard_dependency.get("CruiseSpeedChangeDelayFinished") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_CruiseOff(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.CruiseOff();
                match guard_dependency.get("CruiseOff") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ExternalForcesBecomesExtreme(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ExternalForcesBecomesExtreme();
                match guard_dependency.get("ExternalForcesBecomesExtreme") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ExternalForcesBecomesNormal(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ExternalForcesBecomesNormal();
                match guard_dependency.get("ExternalForcesBecomesNormal") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_VehicleLeavesCruiseSpeed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleLeavesCruiseSpeed();
                match guard_dependency.get("VehicleLeavesCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_VehicleReachesCruiseSpeed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleReachesCruiseSpeed();
                match guard_dependency.get("VehicleReachesCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_VehicleExceedsMaxCruiseSpeed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleExceedsMaxCruiseSpeed();
                match guard_dependency.get("VehicleExceedsMaxCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_VehicleFallsBelowMaxCruiseSpeed(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                match guard_dependency.get("VehicleFallsBelowMaxCruiseSpeed") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleDistanceBecomesVeryClose(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesVeryClose();
                match guard_dependency.get("ObstacleDistanceBecomesVeryClose") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleDistanceBecomesClose(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesClose();
                match guard_dependency.get("ObstacleDistanceBecomesClose") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleDistanceBecomesBig(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDistanceBecomesBig();
                match guard_dependency.get("ObstacleDistanceBecomesBig") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleStartsTravelFaster(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStartsTravelFaster();
                match guard_dependency.get("ObstacleStartsTravelFaster") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleStopsTravelFaster(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStopsTravelFaster();
                match guard_dependency.get("ObstacleStopsTravelFaster") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleStartsTravelSlower(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStartsTravelSlower();
                match guard_dependency.get("ObstacleStartsTravelSlower") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleStopsTravelSlower(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleStopsTravelSlower();
                match guard_dependency.get("ObstacleStopsTravelSlower") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("ObstacleAppearsWhenCruiseActive") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            let mut _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive(isCaching);
            for param in _trid_23.iter().cloned() {
                //model_check_transition_body
                //model_check_transition_param_assignment
                let mut _tmp_1 = param;

                let mut copiedState = state.clone();
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                match guard_dependency.get("ObstacleAppearsWhenCruiseInactive") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleDisappears(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleDisappears();
                match guard_dependency.get("ObstacleDisappears") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
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
                match guard_dependency.get("VehicleManageObstacle") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }
            //model_check_transition
            if state._tr_ObstacleBecomesOld(isCaching) {
                //model_check_transition_body
                let mut copiedState = state.clone();
                copiedState.ObstacleBecomesOld();
                match guard_dependency.get("ObstacleBecomesOld") { Some(map) => copiedState.invalidate_caches(map), _ => (),}
                result.insert(copiedState);
                transitions.fetch_add(1, Ordering::AcqRel);
            }

        }
        return result;
    }

    //model_check_evaluate_state

    //model_check_invariants
    pub fn checkInvariants(state: &Cruise_finite1_deterministic_MC,
                           isCaching: bool,
                           dependent_invariant_m: Arc<Mutex<HashMap<Cruise_finite1_deterministic_MC, HashSet<&str>>>> ) -> bool {
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
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_19") {
                if !state._check_inv_19() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_20") {
                if !state._check_inv_20() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_21") {
                if !state._check_inv_21() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_22") {
                if !state._check_inv_22() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_23") {
                if !state._check_inv_23() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_24") {
                if !state._check_inv_24() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_25") {
                if !state._check_inv_25() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_26") {
                if !state._check_inv_26() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_27") {
                if !state._check_inv_27() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_28") {
                if !state._check_inv_28() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_29") {
                if !state._check_inv_29() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_30") {
                if !state._check_inv_30() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_31") {
                if !state._check_inv_31() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_32") {
                if !state._check_inv_32() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_33") {
                if !state._check_inv_33() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_34") {
                if !state._check_inv_34() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_35") {
                if !state._check_inv_35() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_36") {
                if !state._check_inv_36() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_37") {
                if !state._check_inv_37() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_38") {
                if !state._check_inv_38() {
                    return false;
                }
            }
            //model_check_invariant
            if dependent_invariants_of_state.contains("_check_inv_39") {
                if !state._check_inv_39() {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25() || !state._check_inv_26() || !state._check_inv_27() || !state._check_inv_28() || !state._check_inv_29() || !state._check_inv_30() || !state._check_inv_31() || !state._check_inv_32() || !state._check_inv_33() || !state._check_inv_34() || !state._check_inv_35() || !state._check_inv_36() || !state._check_inv_37() || !state._check_inv_38() || !state._check_inv_39());
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
    fn next(collection_m: Arc<Mutex<LinkedList<Cruise_finite1_deterministic_MC>>>, mc_type: MC_TYPE) -> Cruise_finite1_deterministic_MC {
        let mut collection = collection_m.lock().unwrap();
        return match mc_type {
                MC_TYPE::BFS   => collection.pop_front().unwrap(),
                MC_TYPE::DFS   => collection.pop_back().unwrap(),
                MC_TYPE::MIXED => if collection.len() % 2 == 0 { collection.pop_front().unwrap() } else { collection.pop_back().unwrap() }
            };
    }

    fn model_check_single_threaded(mc_type: MC_TYPE, is_caching: bool) {
        let mut machine = Cruise_finite1_deterministic_MC::new();

        let invariant_violated = AtomicBool::new(false);
        let deadlock_detected = AtomicBool::new(false);
        let stop_threads = AtomicBool::new(false);

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() || !machine._check_inv_26() || !machine._check_inv_27() || !machine._check_inv_28() || !machine._check_inv_29() || !machine._check_inv_30() || !machine._check_inv_31() || !machine._check_inv_32() || !machine._check_inv_33() || !machine._check_inv_34() || !machine._check_inv_35() || !machine._check_inv_36() || !machine._check_inv_37() || !machine._check_inv_38() || !machine._check_inv_39() {
            invariant_violated.store(true, Ordering::Release);
        }

        let mut states = HashSet::<Cruise_finite1_deterministic_MC>::new();
        states.insert(machine.clone());
        let number_states = AtomicI64::new(1);

        let collection_m = Arc::new(Mutex::new(LinkedList::<Cruise_finite1_deterministic_MC>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, HashSet<&str>>::new()));
        let mut guard_cache = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("ObstacleStopsTravelSlower", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("SetCruiseSpeed", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("VehicleLeavesCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("VehicleFallsBelowMaxCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("CCInitialisationFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("VehicleReachesCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleAppearsWhenCruiseActive", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStartsTravelSlower", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("CruiseBecomesNotAllowed", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleAppearsWhenCruiseInactive", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("CCInitialisationDelayFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesClose", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStartsTravelFaster", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ExternalForcesBecomesExtreme", HashSet::from(["_check_inv_18", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("CruiseOff", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("CruiseSpeedChangeDelayFinished", HashSet::from(["_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStopsTravelFaster", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesVeryClose", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("VehicleManageObstacle", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("CruiseBecomesAllowed", HashSet::from(["_check_inv_1", "_check_inv_33"]));
            //model_check_init_static
            invariantDependency.insert("VehicleExceedsMaxCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("CruiseSpeedChangeFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDisappears", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("ExternalForcesBecomesNormal", HashSet::from(["_check_inv_18", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleBecomesOld", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesBig", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStopsTravelSlower", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("SetCruiseSpeed", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("VehicleLeavesCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("VehicleFallsBelowMaxCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CCInitialisationFinished", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("VehicleReachesCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleAppearsWhenCruiseActive", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStartsTravelSlower", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("CruiseBecomesNotAllowed", HashSet::from(["_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ObstacleAppearsWhenCruiseInactive", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("CCInitialisationDelayFinished", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesClose", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStartsTravelFaster", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("ExternalForcesBecomesExtreme", HashSet::from(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseOff", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("CruiseSpeedChangeDelayFinished", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStopsTravelFaster", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesVeryClose", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("VehicleManageObstacle", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseBecomesAllowed", HashSet::from(["_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"]));
            //model_check_init_static
            guardDependency.insert("VehicleExceedsMaxCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseSpeedChangeFinished", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDisappears", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ExternalForcesBecomesNormal", HashSet::from(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleBecomesOld", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesBig", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            dependent_invariant_m.lock().unwrap().insert(machine.clone(), HashSet::new());
            parents_m.lock().unwrap().remove(&machine);
        }

        let transitions = Arc::new(AtomicI64::new(0));

        while !stop_threads.load(Ordering::Acquire) && !collection_m.lock().unwrap().is_empty() {
            let mut state = Self::next(Arc::clone(&collection_m), mc_type);

            let next_states = Self::generateNextStates(&mut state, is_caching, &mut invariantDependency, Arc::clone(&dependent_invariant_m), &mut guardDependency, Arc::clone(&dependent_guard_m), Arc::clone(&guard_cache), Arc::clone(&parents_m), Arc::clone(&transitions));

            next_states.iter().for_each(|next_state| {
                if !states.contains(next_state) {
                    let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                    states.insert(next_state.clone());
                    collection_m.lock().unwrap().push_back(next_state.clone());
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

        let machine = Cruise_finite1_deterministic_MC::new();


        let invariant_violated_b = Arc::new(AtomicBool::new(false));
        let deadlock_detected_b = Arc::new(AtomicBool::new(false));
        let stop_threads_b = Arc::new(AtomicBool::new(false));
        let possible_queue_changes_b = Arc::new(AtomicI32::new(0));

        if !machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() || !machine._check_inv_26() || !machine._check_inv_27() || !machine._check_inv_28() || !machine._check_inv_29() || !machine._check_inv_30() || !machine._check_inv_31() || !machine._check_inv_32() || !machine._check_inv_33() || !machine._check_inv_34() || !machine._check_inv_35() || !machine._check_inv_36() || !machine._check_inv_37() || !machine._check_inv_38() || !machine._check_inv_39() {
                invariant_violated_b.store(true, Ordering::Release);
        }

        let states_m = Arc::new(Mutex::new(HashSet::<Cruise_finite1_deterministic_MC>::new()));
        states_m.lock().unwrap().insert(machine.clone());
        let number_states_arc = Arc::new(AtomicI64::new(1));

        let collection_m = Arc::new(Mutex::new(LinkedList::<Cruise_finite1_deterministic_MC>::new()));
        collection_m.lock().unwrap().push_back(machine.clone());

        let mut invariantDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut guardDependency = HashMap::<&str, HashSet<&'static str>>::new();
        let mut dependent_invariant_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, HashSet<&str>>::new()));
        let mut dependent_guard_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, HashSet<&str>>::new()));
        let mut guard_cache_b = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, PersistentHashMap<&'static str, bool>>::new()));
        let mut parents_m = Arc::new(Mutex::new(HashMap::<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC>::new()));

        if is_caching {
            //model_check_init_static
            invariantDependency.insert("ObstacleStopsTravelSlower", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("SetCruiseSpeed", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("VehicleLeavesCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("VehicleFallsBelowMaxCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("CCInitialisationFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("VehicleReachesCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleAppearsWhenCruiseActive", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStartsTravelSlower", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("CruiseBecomesNotAllowed", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleAppearsWhenCruiseInactive", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("CCInitialisationDelayFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesClose", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStartsTravelFaster", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ExternalForcesBecomesExtreme", HashSet::from(["_check_inv_18", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("CruiseOff", HashSet::from(["_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"]));
            //model_check_init_static
            invariantDependency.insert("CruiseSpeedChangeDelayFinished", HashSet::from(["_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleStopsTravelFaster", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesVeryClose", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            invariantDependency.insert("VehicleManageObstacle", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("CruiseBecomesAllowed", HashSet::from(["_check_inv_1", "_check_inv_33"]));
            //model_check_init_static
            invariantDependency.insert("VehicleExceedsMaxCruiseSpeed", HashSet::from(["_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"]));
            //model_check_init_static
            invariantDependency.insert("CruiseSpeedChangeFinished", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDisappears", HashSet::from(["_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"]));
            //model_check_init_static
            invariantDependency.insert("ExternalForcesBecomesNormal", HashSet::from(["_check_inv_18", "_check_inv_4"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleBecomesOld", HashSet::from(["_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"]));
            //model_check_init_static
            invariantDependency.insert("ObstacleDistanceBecomesBig", HashSet::from(["_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStopsTravelSlower", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("SetCruiseSpeed", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("VehicleLeavesCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("VehicleFallsBelowMaxCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CCInitialisationFinished", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("VehicleReachesCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleAppearsWhenCruiseActive", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStartsTravelSlower", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("CruiseBecomesNotAllowed", HashSet::from(["_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ObstacleAppearsWhenCruiseInactive", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("CCInitialisationDelayFinished", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesClose", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStartsTravelFaster", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("ExternalForcesBecomesExtreme", HashSet::from(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseOff", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("CruiseSpeedChangeDelayFinished", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleStopsTravelFaster", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesVeryClose", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("VehicleManageObstacle", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseBecomesAllowed", HashSet::from(["_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"]));
            //model_check_init_static
            guardDependency.insert("VehicleExceedsMaxCruiseSpeed", HashSet::from(["_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("CruiseSpeedChangeFinished", HashSet::from(["_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDisappears", HashSet::from(["_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"]));
            //model_check_init_static
            guardDependency.insert("ExternalForcesBecomesNormal", HashSet::from(["_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"]));
            //model_check_init_static
            guardDependency.insert("ObstacleBecomesOld", HashSet::from(["_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
            //model_check_init_static
            guardDependency.insert("ObstacleDistanceBecomesBig", HashSet::from(["_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"]));
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
                next_states.iter().for_each(|next_state| {
                    {
                        let mut states = states_m2.lock().unwrap();
                        let mut collection = collection_m2.lock().unwrap();
                        if !states.contains(next_state) {
                            let cnum_states = number_states.fetch_add(1, Ordering::AcqRel) + 1;
                            states.insert(next_state.clone());
                            collection.push_back(next_state.clone());
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
        Cruise_finite1_deterministic_MC::model_check_single_threaded(mc_type, is_caching);
    } else {
        Cruise_finite1_deterministic_MC::modelCheckMultiThreaded(mc_type, threads, is_caching);
    }
}
