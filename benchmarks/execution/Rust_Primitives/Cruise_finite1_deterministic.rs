#![ allow( dead_code, unused, non_snake_case, non_camel_case_types, unused_assignments ) ]
use std::fmt;
use rand::{thread_rng, Rng};
use btypes::butils;
use btypes::bobject;
use btypes::bboolean::{IntoBool, BBooleanT};
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

#[derive(Clone, Default, Debug, Hash, PartialEq, Eq)]
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

impl fmt::Display for Cruise_finite1_deterministic {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let mut result = "Cruise_finite1_deterministic: (".to_owned();
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
            if (_ld_NumberOfSetCruise.less(&BInteger::new(1))).booleanValue() {
                self.NumberOfSetCruise = _ld_NumberOfSetCruise.plus(&BInteger::new(1));
            }
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

    }

    pub fn CCInitialisationFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //pre_assert
        if (self.CCInitialisationInProgress.equal(&BBoolean::new(true))).booleanValue() {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

    }

    pub fn CCInitialisationDelayFinished(&mut self) -> () {
        if ((((((self.CCInitialisationInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue()))).booleanValue() {
            self.CCInitialisationInProgress = BBoolean::new(true);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn CruiseSpeedChangeFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        if ((((((((((((*butils::BOOL).elementOf(&vtks) && (*butils::BOOL).elementOf(&vtktg)) && (((vtks.equal(&BBoolean::new(true)) || vtktg.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true)))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && self.ObstacleDistance.equal(&ODset::ODnone).implies(|| vtks.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| vtktg.equal(&BBoolean::new(true)).booleanValue())) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| vtktg.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| vtks.equal(&BBoolean::new(true)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue()))).booleanValue() {
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
        if ((((((self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.ObstacleStatusJustChanged.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&BBoolean::new(false))) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue()))).booleanValue() {
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
        if ((self.SpeedAboveMax.equal(&BBoolean::new(false)) && ((self.CruiseActive.equal(&BBoolean::new(false)) || self.VehicleCanKeepSpeed.equal(&BBoolean::new(false))) || ((self.ObstacleStatusJustChanged.equal(&BBoolean::new(false)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).not()))).booleanValue() {
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
        if ((self.ObstaclePresent.equal(&BBoolean::new(false)) && self.CruiseActive.equal(&BBoolean::new(true)))).booleanValue() {
            self.ObstaclePresent = BBoolean::new(true);
            self.ObstacleStatusJustChanged = BBoolean::new(true);
            self.ObstacleRelativeSpeed = ors;
            self.ObstacleDistance = od;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }

    pub fn ObstacleAppearsWhenCruiseInactive(&mut self, mut ors: RSset) -> () {
        //pre_assert
        if ((self.ObstaclePresent.equal(&BBoolean::new(false)) && self.CruiseActive.equal(&BBoolean::new(false)))).booleanValue() {
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
        if ((((((((((((*butils::BOOL).elementOf(&vtks) && (*butils::BOOL).elementOf(&vtktg)) && (((vtks.equal(&BBoolean::new(true)) || vtktg.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstaclePresent.equal(&BBoolean::new(false)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && self.ObstacleDistance.equal(&ODset::ODnone).implies(|| vtks.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| vtktg.equal(&BBoolean::new(true)).booleanValue())) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| vtktg.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| vtks.equal(&BBoolean::new(true)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSequal) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSneg) && self.ObstacleDistance.equal(&ODset::ODnone)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue())) && (self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)).implies(|| vtktg.equal(&BBoolean::new(false)).booleanValue()))).booleanValue() {
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
        if ((((((self.ObstacleStatusJustChanged.equal(&BBoolean::new(true)) && (((self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)) || self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true))) || self.CCInitialisationInProgress.equal(&BBoolean::new(true))) || self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(true)))) && self.ObstacleDistance.equal(&ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleDistance.equal(&ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&RSset::RSpos)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && ((self.ObstacleDistance.equal(&ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepTimeGap.equal(&BBoolean::new(true)).booleanValue())) && (((self.ObstacleRelativeSpeed.equal(&RSset::RSpos) && self.ObstacleDistance.unequal(&ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&BBoolean::new(false))) && self.CruiseSpeedChangeInProgress.equal(&BBoolean::new(false))).implies(|| self.VehicleTryKeepSpeed.equal(&BBoolean::new(true)).booleanValue()))).booleanValue() {
            self.ObstacleStatusJustChanged = BBoolean::new(false);
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}

