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


#[derive(Default, Debug)]pub struct Cruise_finite1_deterministic {
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
}


impl Cruise_finite1_deterministic {

    pub fn new() -> Cruise_finite1_deterministic {
        //values: ''
        let mut m: Cruise_finite1_deterministic = Default::default();
        m.init();
        return m;
    }
    fn init(&mut self) {
        /*set_initializations*///set_initialization
    self._RSset = bset![RSset, /*enum_call*/RSset::RSnone, /*enum_call*/RSset::RSpos, /*enum_call*/RSset::RSneg, /*enum_call*/RSset::RSequal];
    //set_initialization
    self._ODset = bset![ODset, /*enum_call*/ODset::ODnone, /*enum_call*/ODset::ODclose, /*enum_call*/ODset::ODveryclose];
        /*properties*/
        /*body*/self.CruiseAllowed = false;
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
        //select
        if self.CruiseAllowed.equal(&true) {
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
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

    }

    pub fn CCInitialisationFinished(&mut self, mut vtks: BBoolean, mut vtktg: BBoolean) -> () {
        //pre_assert
        //select
        if self.CCInitialisationInProgress.equal(&true) {
            self.VehicleTryKeepTimeGap = vtktg;
            self.VehicleTryKeepSpeed = vtks;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

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
        if ((((((((((BOOL.elementOf(&vtks) && BOOL.elementOf(&vtktg)) && (((vtks.equal(&true) || vtktg.equal(&true)) || self.ObstacleStatusJustChanged.equal(&true)) || self.CCInitialisationInProgress.equal(&true))) && self.ObstaclePresent.equal(&false).implies(|| vtktg.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| vtks.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.ObstacleStatusJustChanged.equal(&false)) && self.CCInitialisationInProgress.equal(&false)).implies(|| vtks.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| vtktg.equal(&false))) {
            //select
            if self.CruiseSpeedChangeInProgress.equal(&true) {
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
        if (self.SpeedAboveMax.equal(&false) && ((self.CruiseActive.equal(&false) || self.VehicleCanKeepSpeed.equal(&false)) || ((self.ObstacleStatusJustChanged.equal(&false) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).not())) {
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
        //select
        if (self.ObstaclePresent.equal(&false) && self.CruiseActive.equal(&true)) {
            self.ObstaclePresent = true;
            self.ObstacleStatusJustChanged = true;
            self.ObstacleRelativeSpeed = ors;
            self.ObstacleDistance = od;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

    }

    pub fn ObstacleAppearsWhenCruiseInactive(&mut self, mut ors: RSset) -> () {
        //pre_assert
        //select
        if (self.ObstaclePresent.equal(&false) && self.CruiseActive.equal(&false)) {
            self.ObstaclePresent = true;
            self.ObstacleRelativeSpeed = ors;
            self.ObstacleDistance = /*enum_call*/ODset::ODnone;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }

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
        if ((((((((((BOOL.elementOf(&vtks) && BOOL.elementOf(&vtktg)) && (((vtks.equal(&true) || vtktg.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstaclePresent.equal(&false).implies(|| vtktg.equal(&false))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| vtks.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtktg.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| vtks.equal(&true))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSequal) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSneg) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone)).implies(|| vtktg.equal(&false))) && (self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)).implies(|| vtktg.equal(&false))) {
            //select
            if self.ObstacleStatusJustChanged.equal(&true) {
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
        //select
        if (((((self.ObstacleStatusJustChanged.equal(&true) && (((self.VehicleTryKeepSpeed.equal(&true) || self.VehicleTryKeepTimeGap.equal(&true)) || self.CCInitialisationInProgress.equal(&true)) || self.CruiseSpeedChangeInProgress.equal(&true))) && self.ObstacleDistance.equal(&/*enum_call*/ODset::ODnone).implies(|| self.VehicleTryKeepSpeed.equal(&true))) && (((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODclose) && self.ObstacleRelativeSpeed.unequal(&/*enum_call*/RSset::RSpos)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && ((self.ObstacleDistance.equal(&/*enum_call*/ODset::ODveryclose) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepTimeGap.equal(&true))) && (((self.ObstacleRelativeSpeed.equal(&/*enum_call*/RSset::RSpos) && self.ObstacleDistance.unequal(&/*enum_call*/ODset::ODveryclose)) && self.CCInitialisationInProgress.equal(&false)) && self.CruiseSpeedChangeInProgress.equal(&false)).implies(|| self.VehicleTryKeepSpeed.equal(&true))) {
            self.ObstacleStatusJustChanged = false;
        } else {
            panic!("ERROR: called SELECT-function with incompatible parameters!");
        }
    }
}


