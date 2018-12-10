#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"
#include "BInteger.cpp"

#ifndef Cruise_finite_k_H
#define Cruise_finite_k_H

using namespace std;

class Cruise_finite_k {
    
    class RSset : public BObject {
    public:
        
        enum RSset_type {
            RSnone,
            RSpos,
            RSneg,
            RSequal
        };
        
        RSset_type value;
        
        RSset(){}
        
        RSset(RSset_type type) {
            this->value = type;
        }
        
        BBoolean equal(const RSset& o) {
            return value == o.value;
        }
        
        BBoolean unequal(const RSset& o) {
            return value != o.value;
        }
        
        friend bool operator ==(const RSset& p1, const RSset& p2) {
            return p1.value == p2.value;
        }
        
        friend bool operator !=(const RSset& p1, const RSset& p2) {
            return p1.value != p2.value;
        }
        
        int hashCode() const {
            return static_cast<int>(value);
        }
    };
    
    class ODset : public BObject {
    public:
        
        enum ODset_type {
            ODnone,
            ODclose,
            ODveryclose
        };
        
        ODset_type value;
        
        ODset(){}
        
        ODset(ODset_type type) {
            this->value = type;
        }
        
        BBoolean equal(const ODset& o) {
            return value == o.value;
        }
        
        BBoolean unequal(const ODset& o) {
            return value != o.value;
        }
        
        friend bool operator ==(const ODset& p1, const ODset& p2) {
            return p1.value == p2.value;
        }
        
        friend bool operator !=(const ODset& p1, const ODset& p2) {
            return p1.value != p2.value;
        }
        
        int hashCode() const {
            return static_cast<int>(value);
        }
    };
    
    
private:
    
    
#define _RSset (BSet<RSset >((RSset(RSset::RSnone)), (RSset(RSset::RSpos)), (RSset(RSset::RSneg)), (RSset(RSset::RSequal))))
#define _ODset (BSet<ODset >((ODset(ODset::ODnone)), (ODset(ODset::ODclose)), (ODset(ODset::ODveryclose))))
    
    BBoolean CruiseAllowed;
    BBoolean CruiseActive;
    BBoolean VehicleAtCruiseSpeed;
    BBoolean VehicleCanKeepSpeed;
    BBoolean VehicleTryKeepSpeed;
    BBoolean SpeedAboveMax;
    BBoolean VehicleTryKeepTimeGap;
    BBoolean CruiseSpeedAtMax;
    BBoolean ObstaclePresent;
    ODset ObstacleDistance;
    RSset ObstacleRelativeSpeed;
    BBoolean ObstacleStatusJustChanged;
    BBoolean CCInitialisationInProgress;
    BBoolean CruiseSpeedChangeInProgress;
    BInteger NumberOfSetCruise;
    
    bool initialized = false;
    
public:
    
    Cruise_finite_k(){}
    
    void initialize() {
        if(initialized) {
            throw runtime_error("Machine is already initialized");
        }
        BBoolean _ld_CruiseAllowed = static_cast<BBoolean >(CruiseAllowed);
        BBoolean _ld_CruiseActive = static_cast<BBoolean >(CruiseActive);
        BBoolean _ld_VehicleAtCruiseSpeed = static_cast<BBoolean >(VehicleAtCruiseSpeed);
        BBoolean _ld_VehicleCanKeepSpeed = static_cast<BBoolean >(VehicleCanKeepSpeed);
        BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
        BBoolean _ld_SpeedAboveMax = static_cast<BBoolean >(SpeedAboveMax);
        BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
        BInteger _ld_NumberOfSetCruise = static_cast<BInteger >(NumberOfSetCruise);
        BBoolean _ld_CruiseSpeedAtMax = static_cast<BBoolean >(CruiseSpeedAtMax);
        ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
        BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
        BBoolean _ld_CCInitialisationInProgress = static_cast<BBoolean >(CCInitialisationInProgress);
        BBoolean _ld_CruiseSpeedChangeInProgress = static_cast<BBoolean >(CruiseSpeedChangeInProgress);
        for(int _0_i = 0; _0_i < ((BOOL).size()); _0_i++) {
            BBoolean op = static_cast<BBoolean >(*(std::next((BOOL).begin(), _0_i)));
            for(int _1_i = 0; _1_i < (_RSset.size()); _1_i++) {
                RSset ors = static_cast<RSset >(*(std::next(_RSset.begin(), _1_i)));
                if((BOOL).elementOf(op)._and(_RSset.elementOf(ors))._and(op.equal((BBoolean(false))).equivalent(ors.equal((RSset(RSset::RSnone))))).booleanValue()) {
                    BBoolean _ld_ObstaclePresent = static_cast<BBoolean >(ObstaclePresent);
                    RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
                    ObstaclePresent = static_cast<BBoolean >(op);
                    ObstacleRelativeSpeed = static_cast<RSset >(ors);
                    break;
                }
            }
        }
        CruiseAllowed = static_cast<BBoolean >((BBoolean(false)));
        CruiseActive = static_cast<BBoolean >((BBoolean(false)));
        VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(false)));
        VehicleCanKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
        VehicleTryKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
        SpeedAboveMax = static_cast<BBoolean >((BBoolean(false)));
        VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
        NumberOfSetCruise = static_cast<BInteger >((BInteger(0)));
        CruiseSpeedAtMax = static_cast<BBoolean >((BBoolean(false)));
        ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
        ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(false)));
        CCInitialisationInProgress = static_cast<BBoolean >((BBoolean(false)));
        CruiseSpeedChangeInProgress = static_cast<BBoolean >((BBoolean(false)));
        initialized = true;
    }
    
    void CruiseBecomesNotAllowed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
            BBoolean _ld_CruiseAllowed = static_cast<BBoolean >(CruiseAllowed);
            BBoolean _ld_CruiseActive = static_cast<BBoolean >(CruiseActive);
            BBoolean _ld_VehicleCanKeepSpeed = static_cast<BBoolean >(VehicleCanKeepSpeed);
            BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
            BBoolean _ld_VehicleAtCruiseSpeed = static_cast<BBoolean >(VehicleAtCruiseSpeed);
            BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
            BBoolean _ld_CruiseSpeedAtMax = static_cast<BBoolean >(CruiseSpeedAtMax);
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BInteger _ld_NumberOfSetCruise = static_cast<BInteger >(NumberOfSetCruise);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            BBoolean _ld_CCInitialisationInProgress = static_cast<BBoolean >(CCInitialisationInProgress);
            BBoolean _ld_CruiseSpeedChangeInProgress = static_cast<BBoolean >(CruiseSpeedChangeInProgress);
            CruiseAllowed = static_cast<BBoolean >((BBoolean(false)));
            CruiseActive = static_cast<BBoolean >((BBoolean(false)));
            VehicleCanKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleTryKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
            CruiseSpeedAtMax = static_cast<BBoolean >((BBoolean(false)));
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
            NumberOfSetCruise = static_cast<BInteger >((BInteger(0)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(false)));
            CCInitialisationInProgress = static_cast<BBoolean >((BBoolean(false)));
            CruiseSpeedChangeInProgress = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CruiseBecomesAllowed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseAllowed.equal((BBoolean(false)))).booleanValue()) {
            CruiseAllowed = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void SetCruiseSpeed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
            BBoolean _ld_CruiseActive = static_cast<BBoolean >(CruiseActive);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            VehicleCanKeepSpeed = static_cast<BBoolean >((BOOL).nondeterminism());
            if((SpeedAboveMax.equal((BBoolean(false)))).booleanValue()) {
                BBoolean _ld_VehicleAtCruiseSpeed = static_cast<BBoolean >(VehicleAtCruiseSpeed);
                CruiseSpeedAtMax = static_cast<BBoolean >((BOOL).nondeterminism());
                VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(true)));
            } else {
                CruiseSpeedAtMax = static_cast<BBoolean >((BBoolean(true)));
            }
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                CruiseSpeedChangeInProgress = static_cast<BBoolean >((BBoolean(true)));
            } else {
                CCInitialisationInProgress = static_cast<BBoolean >((BBoolean(true)));
            }
            if((NumberOfSetCruise.less((BInteger(10)))).booleanValue()) {
                NumberOfSetCruise = static_cast<BInteger >(NumberOfSetCruise.plus((BInteger(1))));
            }
            CruiseActive = static_cast<BBoolean >((BBoolean(true)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CCInitialisationFinished() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CCInitialisationInProgress.equal((BBoolean(true)))).booleanValue()) {
            for(int _0_i = 0; _0_i < ((BOOL).size()); _0_i++) {
                BBoolean vtks = static_cast<BBoolean >(*(std::next((BOOL).begin(), _0_i)));
                for(int _1_i = 0; _1_i < ((BOOL).size()); _1_i++) {
                    BBoolean vtktg = static_cast<BBoolean >(*(std::next((BOOL).begin(), _1_i)));
                    if((BOOL).elementOf(vtks)._and((BOOL).elementOf(vtktg))._and(vtks.equal((BBoolean(true)))._or(vtktg.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstaclePresent.equal((BBoolean(false))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).implies(vtktg.equal((BBoolean(false))))).booleanValue()) {
                        BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
                        BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
                        VehicleTryKeepTimeGap = static_cast<BBoolean >(vtktg);
                        VehicleTryKeepSpeed = static_cast<BBoolean >(vtks);
                        break;
                    }
                }
            }
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CCInitialisationDelayFinished() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CCInitialisationInProgress.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
            CCInitialisationInProgress = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CruiseSpeedChangeFinished() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))).booleanValue()) {
            for(int _0_i = 0; _0_i < ((BOOL).size()); _0_i++) {
                BBoolean vtks = static_cast<BBoolean >(*(std::next((BOOL).begin(), _0_i)));
                for(int _1_i = 0; _1_i < ((BOOL).size()); _1_i++) {
                    BBoolean vtktg = static_cast<BBoolean >(*(std::next((BOOL).begin(), _1_i)));
                    if((BOOL).elementOf(vtks)._and((BOOL).elementOf(vtktg))._and(vtks.equal((BBoolean(true)))._or(vtktg.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true)))))._and(ObstaclePresent.equal((BBoolean(false))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).implies(vtktg.equal((BBoolean(false))))).booleanValue()) {
                        BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
                        BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
                        VehicleTryKeepTimeGap = static_cast<BBoolean >(vtktg);
                        VehicleTryKeepSpeed = static_cast<BBoolean >(vtks);
                        break;
                    }
                }
            }
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CruiseSpeedChangeDelayFinished() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
            CruiseSpeedChangeInProgress = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void CruiseOff() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
            BBoolean _ld_CruiseActive = static_cast<BBoolean >(CruiseActive);
            BBoolean _ld_VehicleCanKeepSpeed = static_cast<BBoolean >(VehicleCanKeepSpeed);
            BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
            BBoolean _ld_VehicleAtCruiseSpeed = static_cast<BBoolean >(VehicleAtCruiseSpeed);
            BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
            BBoolean _ld_CruiseSpeedAtMax = static_cast<BBoolean >(CruiseSpeedAtMax);
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BInteger _ld_NumberOfSetCruise = static_cast<BInteger >(NumberOfSetCruise);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            BBoolean _ld_CCInitialisationInProgress = static_cast<BBoolean >(CCInitialisationInProgress);
            BBoolean _ld_CruiseSpeedChangeInProgress = static_cast<BBoolean >(CruiseSpeedChangeInProgress);
            CruiseActive = static_cast<BBoolean >((BBoolean(false)));
            VehicleCanKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleTryKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(false)));
            VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
            CruiseSpeedAtMax = static_cast<BBoolean >((BBoolean(false)));
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
            NumberOfSetCruise = static_cast<BInteger >((BInteger(0)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(false)));
            CCInitialisationInProgress = static_cast<BBoolean >((BBoolean(false)));
            CruiseSpeedChangeInProgress = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ExternalForcesBecomesExtreme() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((VehicleCanKeepSpeed.equal((BBoolean(true)))).booleanValue()) {
            VehicleCanKeepSpeed = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ExternalForcesBecomesNormal() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseActive.equal((BBoolean(true)))._and(VehicleCanKeepSpeed.equal((BBoolean(false))))).booleanValue()) {
            VehicleCanKeepSpeed = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void VehicleLeavesCruiseSpeed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((VehicleAtCruiseSpeed.equal((BBoolean(true)))._and(VehicleCanKeepSpeed.equal((BBoolean(false)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))))._or(VehicleTryKeepSpeed.equal((BBoolean(false))))).booleanValue()) {
            VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void VehicleReachesCruiseSpeed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((CruiseActive.equal((BBoolean(true)))._and(VehicleAtCruiseSpeed.equal((BBoolean(false))))._and(SpeedAboveMax.equal((BBoolean(false))))).booleanValue()) {
            VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void VehicleExceedsMaxCruiseSpeed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((SpeedAboveMax.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(false)))._or(VehicleCanKeepSpeed.equal((BBoolean(false))))._or(ObstacleStatusJustChanged.equal((BBoolean(false)))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false))))._not()))).booleanValue()) {
            BBoolean _ld_SpeedAboveMax = static_cast<BBoolean >(SpeedAboveMax);
            BBoolean _ld_VehicleAtCruiseSpeed = static_cast<BBoolean >(VehicleAtCruiseSpeed);
            SpeedAboveMax = static_cast<BBoolean >((BBoolean(true)));
            VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void VehicleFallsBelowMaxCruiseSpeed() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((SpeedAboveMax.equal((BBoolean(true)))).booleanValue()) {
            BBoolean _ld_SpeedAboveMax = static_cast<BBoolean >(SpeedAboveMax);
            if((CruiseActive.equal((BBoolean(true)))._and(CruiseSpeedAtMax.equal((BBoolean(true))))).booleanValue()) {
                VehicleAtCruiseSpeed = static_cast<BBoolean >((BBoolean(true)));
            }
            SpeedAboveMax = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleDistanceBecomesVeryClose() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))))).booleanValue()) {
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODveryclose)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleDistanceBecomesClose() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstaclePresent.equal((BBoolean(true)))._and(CruiseActive.equal((BBoolean(true))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))))._or(ObstacleDistance.equal((ODset(ODset::ODnone)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))))))).booleanValue()) {
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue()) {
                VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
            }
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODclose)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleDistanceBecomesBig() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))))).booleanValue()) {
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
            VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleStartsTravelFaster() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstaclePresent.equal((BBoolean(true)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))))).booleanValue()) {
            RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            }
            if((ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).booleanValue()) {
                VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
            }
            ObstacleRelativeSpeed = static_cast<RSset >((RSset(RSset::RSpos)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleStopsTravelFaster() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue()) {
            RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            }
            ObstacleRelativeSpeed = static_cast<RSset >((RSset(RSset::RSequal)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleStartsTravelSlower() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))).booleanValue()) {
            RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            }
            ObstacleRelativeSpeed = static_cast<RSset >((RSset(RSset::RSneg)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleStopsTravelSlower() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))).booleanValue()) {
            RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            }
            ObstacleRelativeSpeed = static_cast<RSset >((RSset(RSset::RSequal)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleAppearsWhenCruiseActive() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstaclePresent.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(true))))).booleanValue()) {
            BBoolean _ld_ObstaclePresent = static_cast<BBoolean >(ObstaclePresent);
            BBoolean _ld_ObstacleStatusJustChanged = static_cast<BBoolean >(ObstacleStatusJustChanged);
            ObstacleRelativeSpeed = static_cast<RSset >(_RSset.complement((BSet<RSset >((RSset(RSset::RSnone))))).nondeterminism());
            ObstacleDistance = static_cast<ODset >(_ODset.complement((BSet<ODset >((ODset(ODset::ODnone))))).nondeterminism());
            ObstaclePresent = static_cast<BBoolean >((BBoolean(true)));
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleAppearsWhenCruiseInactive() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstaclePresent.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(false))))).booleanValue()) {
            BBoolean _ld_ObstaclePresent = static_cast<BBoolean >(ObstaclePresent);
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            ObstacleRelativeSpeed = static_cast<RSset >(_RSset.complement((BSet<RSset >((RSset(RSset::RSnone))))).nondeterminism());
            ObstaclePresent = static_cast<BBoolean >((BBoolean(true)));
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleDisappears() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstaclePresent.equal((BBoolean(true)))).booleanValue()) {
            BBoolean _ld_ObstaclePresent = static_cast<BBoolean >(ObstaclePresent);
            RSset _ld_ObstacleRelativeSpeed = static_cast<RSset >(ObstacleRelativeSpeed);
            ODset _ld_ObstacleDistance = static_cast<ODset >(ObstacleDistance);
            BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(true)));
            }
            ObstaclePresent = static_cast<BBoolean >((BBoolean(false)));
            ObstacleRelativeSpeed = static_cast<RSset >((RSset(RSset::RSnone)));
            ObstacleDistance = static_cast<ODset >((ODset(ODset::ODnone)));
            VehicleTryKeepTimeGap = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void VehicleManageObstacle() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleStatusJustChanged.equal((BBoolean(true)))).booleanValue()) {
            for(int _0_i = 0; _0_i < ((BOOL).size()); _0_i++) {
                BBoolean vtks = static_cast<BBoolean >(*(std::next((BOOL).begin(), _0_i)));
                for(int _1_i = 0; _1_i < ((BOOL).size()); _1_i++) {
                    BBoolean vtktg = static_cast<BBoolean >(*(std::next((BOOL).begin(), _1_i)));
                    if((BOOL).elementOf(vtks)._and((BOOL).elementOf(vtktg))._and(vtks.equal((BBoolean(true)))._or(vtktg.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstaclePresent.equal((BBoolean(false))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))._and(ObstacleDistance.equal((ODset(ODset::ODnone)))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).implies(vtktg.equal((BBoolean(false))))).booleanValue()) {
                        BBoolean _ld_VehicleTryKeepTimeGap = static_cast<BBoolean >(VehicleTryKeepTimeGap);
                        BBoolean _ld_VehicleTryKeepSpeed = static_cast<BBoolean >(VehicleTryKeepSpeed);
                        VehicleTryKeepTimeGap = static_cast<BBoolean >(vtktg);
                        VehicleTryKeepSpeed = static_cast<BBoolean >(vtks);
                        break;
                    }
                }
            }
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
    void ObstacleBecomesOld() {
        if(!initialized) {
            throw runtime_error("Machine was not initialized");
        }
        if((ObstacleStatusJustChanged.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose)))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose)))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
            ObstacleStatusJustChanged = static_cast<BBoolean >((BBoolean(false)));
        } else {
            throw runtime_error("Invocation of the operation is not possible");
        }
    }
    
};

int main() {
    clock_t start,finish;
    double time;
    Cruise_finite_k controller;
    controller.initialize();
    start = clock();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelSlower();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStopsTravelFaster();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.CruiseOff();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.ExternalForcesBecomesExtreme();
    controller.CCInitialisationFinished();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.CruiseSpeedChangeDelayFinished();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationDelayFinished();
    controller.CCInitialisationFinished();
    controller.CruiseOff();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.ObstacleStartsTravelSlower();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStartsTravelSlower();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.ObstacleDistanceBecomesClose();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleBecomesOld();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ExternalForcesBecomesExtreme();
    controller.VehicleManageObstacle();
    controller.VehicleManageObstacle();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStopsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesExtreme();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelSlower();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.ObstacleDisappears();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseOff();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelSlower();
    controller.CruiseBecomesAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.CCInitialisationDelayFinished();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CCInitialisationFinished();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CCInitialisationDelayFinished();
    controller.CCInitialisationFinished();
    controller.CruiseOff();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleManageObstacle();
    controller.VehicleManageObstacle();
    controller.ExternalForcesBecomesNormal();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.ExternalForcesBecomesExtreme();
    controller.CCInitialisationDelayFinished();
    controller.ExternalForcesBecomesNormal();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDistanceBecomesVeryClose();
    controller.CruiseOff();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleDistanceBecomesClose();
    controller.VehicleManageObstacle();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleStopsTravelFaster();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleStartsTravelSlower();
    controller.CCInitialisationFinished();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleManageObstacle();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDistanceBecomesClose();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.VehicleManageObstacle();
    controller.CCInitialisationDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.VehicleManageObstacle();
    controller.ObstacleBecomesOld();
    controller.ExternalForcesBecomesExtreme();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleDisappears();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesExtreme();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.ObstacleStopsTravelSlower();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.VehicleLeavesCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.ExternalForcesBecomesExtreme();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.VehicleManageObstacle();
    controller.CCInitialisationDelayFinished();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.ObstacleStartsTravelFaster();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelSlower();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.CruiseSpeedChangeFinished();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationDelayFinished();
    controller.ObstacleStartsTravelFaster();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.CCInitialisationDelayFinished();
    controller.ObstacleDistanceBecomesBig();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleStopsTravelFaster();
    controller.ObstacleStartsTravelSlower();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.CCInitialisationDelayFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.ExternalForcesBecomesNormal();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleDistanceBecomesBig();
    controller.CruiseOff();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesExtreme();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.CruiseOff();
    controller.ObstacleDisappears();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeFinished();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.VehicleManageObstacle();
    controller.ExternalForcesBecomesNormal();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationDelayFinished();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ExternalForcesBecomesNormal();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelFaster();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleStartsTravelSlower();
    controller.CruiseOff();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.ExternalForcesBecomesNormal();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.ObstacleStartsTravelSlower();
    controller.ObstacleStopsTravelSlower();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.CCInitialisationFinished();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ObstacleDistanceBecomesClose();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.ObstacleDistanceBecomesBig();
    controller.ExternalForcesBecomesExtreme();
    controller.VehicleLeavesCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.ExternalForcesBecomesNormal();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleBecomesOld();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.ObstacleDisappears();
    controller.ExternalForcesBecomesExtreme();
    controller.CruiseOff();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.VehicleManageObstacle();
    controller.ObstacleStopsTravelFaster();
    controller.CCInitialisationFinished();
    controller.ObstacleStartsTravelSlower();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.SetCruiseSpeed();
    controller.CCInitialisationDelayFinished();
    controller.CCInitialisationDelayFinished();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.ObstacleDisappears();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.ExternalForcesBecomesNormal();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleStartsTravelSlower();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleDistanceBecomesClose();
    controller.CCInitialisationFinished();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.CCInitialisationFinished();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.CCInitialisationFinished();
    controller.CCInitialisationDelayFinished();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeFinished();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CCInitialisationDelayFinished();
    controller.VehicleManageObstacle();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelSlower();
    controller.SetCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.CruiseOff();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleManageObstacle();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleManageObstacle();
    controller.ObstacleStopsTravelFaster();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStartsTravelSlower();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CCInitialisationFinished();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeDelayFinished();
    controller.ObstacleStartsTravelFaster();
    controller.CruiseOff();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStopsTravelSlower();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.CCInitialisationFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDistanceBecomesVeryClose();
    controller.VehicleManageObstacle();
    controller.CruiseOff();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.VehicleManageObstacle();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleBecomesOld();
    controller.SetCruiseSpeed();
    controller.CCInitialisationDelayFinished();
    controller.CCInitialisationDelayFinished();
    controller.ObstacleDistanceBecomesClose();
    controller.CruiseSpeedChangeDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CCInitialisationDelayFinished();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStopsTravelSlower();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ExternalForcesBecomesNormal();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.CruiseOff();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleStopsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.CruiseBecomesAllowed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleStopsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.CCInitialisationFinished();
    controller.VehicleManageObstacle();
    controller.CruiseOff();
    controller.ObstacleStartsTravelSlower();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.SetCruiseSpeed();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseOff();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CCInitialisationFinished();
    controller.ObstacleBecomesOld();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelSlower();
    controller.CCInitialisationFinished();
    controller.ExternalForcesBecomesNormal();
    controller.CruiseBecomesNotAllowed();
    controller.CruiseBecomesAllowed();
    controller.SetCruiseSpeed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.CruiseOff();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleStartsTravelFaster();
    controller.ObstacleStopsTravelFaster();
    controller.CruiseBecomesNotAllowed();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.VehicleExceedsMaxCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.CruiseBecomesNotAllowed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.ObstacleDisappears();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseInactive();
    controller.CruiseBecomesAllowed();
    controller.ObstacleDisappears();
    controller.SetCruiseSpeed();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.ExternalForcesBecomesExtreme();
    controller.CCInitialisationFinished();
    controller.ObstacleDisappears();
    controller.VehicleFallsBelowMaxCruiseSpeed();
    controller.SetCruiseSpeed();
    controller.VehicleManageObstacle();
    controller.ObstacleAppearsWhenCruiseActive();
    controller.CruiseSpeedChangeDelayFinished();
    controller.ObstacleBecomesOld();
    controller.CruiseSpeedChangeFinished();
    controller.CruiseSpeedChangeFinished();
    controller.ObstacleDistanceBecomesClose();
    controller.ObstacleDistanceBecomesBig();
    controller.SetCruiseSpeed();
    controller.VehicleLeavesCruiseSpeed();
    controller.ObstacleStopsTravelFaster();
    controller.CCInitialisationFinished();
    controller.CruiseBecomesNotAllowed();
    finish = clock();
    time = (double(finish)-double(start))/CLOCKS_PER_SEC;
    printf("%f\n", time);
    return 0;
}
#endif

