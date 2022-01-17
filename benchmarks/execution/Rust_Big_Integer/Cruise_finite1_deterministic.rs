#![ allow( dead_code, unused_imports, unused_mut, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bboolean::BBoolean;
use btypes::binteger::BInteger;
use btypes::bset::BSet;
use btypes::bobject::BObject;


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

#[derive(Default, Debug)]
pub struct Cruise_finite1_deterministic {
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
}

impl Cruise_finite1_deterministic {

    pub fn new() -> Cruise_finite1_deterministic {
        //values: ''
        let mut m: Cruise_finite1_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        self._RSset = BSet::new(vec![RSset::RSnone, RSset::RSpos, RSset::RSneg, RSset::RSequal]);
        self._ODset = BSet::new(vec![ODset::ODnone, ODset::ODclose, ODset::ODveryclose]);
        self.CruiseAllowed = BBoolean::new(false);
        self.CruiseActive = BBoolean::new(false);
        self.VehicleAtCruiseSpeed = BBoolean::new(false);
        self.VehicleCanKeepSpeed = BBoolean::new(false);
        self.VehicleTryKeepSpeed = BBoolean::new(false);
        self.SpeedAboveMax = BBoolean::new(false);
        self.VehicleTryKeepTimeGap = BBoolean::new(false);
        self.NumberOfSetCruise = BInteger::new(b"0");
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
            self.NumberOfSetCruise = BInteger::new(b"0");
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
        if (self.CruiseAllowed.equal(&BBoolean::new(true))).booleanValue() {
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
            if (_ld_NumberOfSetCruise.less(&BInteger::new(b"1"))).booleanValue() {
                self.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(&BInteger::new(b"1"));
            } 
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CCInitialisationFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if (self.CCInitialisationInProgress.equal(&BBoolean::new(true))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CCInitialisationDelayFinished(&mut self) -> () {
        if (self.CCInitialisationInProgress.equal(&BBoolean::new(true)).and(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).or(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&self.VehicleTryKeepSpeed.equal(&BBoolean::new(true))))).booleanValue() {
            self.CCInitialisationInProgress = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if (butils::BOOL.elementOf(&vtks).and(&butils::BOOL.elementOf(&vtktg)).and(&vtks.equal(&BBoolean::new(true)).or(&vtktg.equal(&BBoolean::new(true))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true)))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false))))).booleanValue() {
            if (self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true))).booleanValue() {
                self.VehicleTryKeepTimeGap = vtktg;
                self.VehicleTryKeepSpeed = vtks;
            } else {
                panic!("ERROR: called SELECT-function with incompatible parameters!");
            }
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
            self.NumberOfSetCruise = BInteger::new(b"0");
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
        if (self.SpeedAboveMax.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(false)).or(&self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))).or(&self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).not()))).booleanValue() {
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
        if (self.ObstaclePresent.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(true)))).booleanValue() {
            self.ObstaclePresent = BBoolean::new(true);
            self.ObstacleStatusJustChanged = BBoolean::new(true);
            self.ObstacleRelativeSpeed = ors;
            self.ObstacleDistance = od;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleAppearsWhenCruiseInactive(&mut self, mut ors: RSset) -> () {
        if (self.ObstaclePresent.equal(&BBoolean::new(false)).and(&self.CruiseActive.equal(&BBoolean::new(false)))).booleanValue() {
            self.ObstaclePresent = BBoolean::new(true);
            self.ObstacleRelativeSpeed = ors;
            self.ObstacleDistance = ODset::ODnone;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
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
        if (butils::BOOL.elementOf(&vtks).and(&butils::BOOL.elementOf(&vtktg)).and(&vtks.equal(&BBoolean::new(true)).or(&vtktg.equal(&BBoolean::new(true))).or(&self.CCInitialisationInProgress.equal(&BBoolean::new(true))).or(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))).and(&self.ObstaclePresent.equal(&BBoolean::new(false)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleDistance.equal(&ODset::ODnone).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODclose).and(&self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleDistance.equal(&ODset::ODveryclose).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtktg.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).and(&self.CCInitialisationInProgress.equal(&BBoolean::new(false))).and(&self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(&vtks.equal(&BBoolean::new(true)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSequal).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSneg).and(&self.ObstacleDistance.equal(&ODset::ODnone)).implies(&vtktg.equal(&BBoolean::new(false)))).and(&self.ObstacleRelativeSpeed.equal(&RSset::RSpos).and(&self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(&vtktg.equal(&BBoolean::new(false))))).booleanValue() {
            if (self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))).booleanValue() {
                self.VehicleTryKeepTimeGap = vtktg;
                self.VehicleTryKeepSpeed = vtks;
            } else {
                panic!("ERROR: called SELECT-function with incompatible parameters!");
            }
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
}

