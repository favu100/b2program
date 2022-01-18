#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/any.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef Cruise_finite1_deterministic_MC_H
#define Cruise_finite1_deterministic_MC_H

using namespace std;

class Cruise_finite1_deterministic_MC {

    public:

        enum Type { BFS, DFS, MIXED };


        class RSset : public BObject {
            public:

                typedef RSset current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum RSset_type {
                    RSnone, 
                    RSpos, 
                    RSneg, 
                    RSequal
                };

                RSset_type value;

                RSset(){}

                RSset(const RSset_type& type) {
                    this->value = type;
                }

                BBoolean equal(const RSset& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const RSset& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const RSset& p1, const RSset& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const RSset& p1, const RSset& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const RSset& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const RSset& e) {
                    switch(e.value) {
                        case RSnone: return strm << "RSnone";
                        case RSpos: return strm << "RSpos";
                        case RSneg: return strm << "RSneg";
                        case RSequal: return strm << "RSequal";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class ODset : public BObject {
            public:

                typedef ODset current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum ODset_type {
                    ODnone, 
                    ODclose, 
                    ODveryclose
                };

                ODset_type value;

                ODset(){}

                ODset(const ODset_type& type) {
                    this->value = type;
                }

                BBoolean equal(const ODset& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const ODset& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const ODset& p1, const ODset& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const ODset& p1, const ODset& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const ODset& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const ODset& e) {
                    switch(e.value) {
                        case ODnone: return strm << "ODnone";
                        case ODclose: return strm << "ODclose";
                        case ODveryclose: return strm << "ODveryclose";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        struct Hash {
            public:
                size_t operator()(const Cruise_finite1_deterministic_MC& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const Cruise_finite1_deterministic_MC& obj1, const Cruise_finite1_deterministic_MC& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
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


    public:

        Cruise_finite1_deterministic_MC() {
            CruiseAllowed = (BBoolean(true));
            CruiseActive = (BBoolean(false));
            VehicleAtCruiseSpeed = (BBoolean(false));
            VehicleCanKeepSpeed = (BBoolean(false));
            VehicleTryKeepSpeed = (BBoolean(false));
            SpeedAboveMax = (BBoolean(false));
            VehicleTryKeepTimeGap = (BBoolean(false));
            NumberOfSetCruise = (BInteger(0));
            CruiseSpeedAtMax = (BBoolean(false));
            ObstacleDistance = (ODset(ODset::ODnone));
            ObstacleStatusJustChanged = (BBoolean(false));
            CCInitialisationInProgress = (BBoolean(false));
            CruiseSpeedChangeInProgress = (BBoolean(false));
            ObstaclePresent = (BBoolean(false));
            ObstacleRelativeSpeed = (RSset(RSset::RSnone));
        }

        Cruise_finite1_deterministic_MC(const BBoolean& CruiseAllowed, const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& VehicleCanKeepSpeed, const BBoolean& VehicleTryKeepSpeed, const BBoolean& SpeedAboveMax, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedAtMax, const BBoolean& ObstaclePresent, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& CruiseSpeedChangeInProgress, const BInteger& NumberOfSetCruise) {
            this->CruiseAllowed = CruiseAllowed;
            this->CruiseActive = CruiseActive;
            this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
            this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
            this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
            this->SpeedAboveMax = SpeedAboveMax;
            this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
            this->CruiseSpeedAtMax = CruiseSpeedAtMax;
            this->ObstaclePresent = ObstaclePresent;
            this->ObstacleDistance = ObstacleDistance;
            this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
            this->CCInitialisationInProgress = CCInitialisationInProgress;
            this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
            this->NumberOfSetCruise = NumberOfSetCruise;
        }

        void CruiseBecomesNotAllowed() {
            CruiseAllowed = (BBoolean(false));
            CruiseActive = (BBoolean(false));
            VehicleCanKeepSpeed = (BBoolean(false));
            VehicleTryKeepSpeed = (BBoolean(false));
            VehicleAtCruiseSpeed = (BBoolean(false));
            VehicleTryKeepTimeGap = (BBoolean(false));
            CruiseSpeedAtMax = (BBoolean(false));
            ObstacleDistance = (ODset(ODset::ODnone));
            NumberOfSetCruise = (BInteger(0));
            ObstacleStatusJustChanged = (BBoolean(false));
            CCInitialisationInProgress = (BBoolean(false));
            CruiseSpeedChangeInProgress = (BBoolean(false));

        }

        void CruiseBecomesAllowed() {
            CruiseAllowed = (BBoolean(true));

        }

        void SetCruiseSpeed(const BBoolean& vcks, const BBoolean& csam) {
            BInteger _ld_NumberOfSetCruise = NumberOfSetCruise;
            BBoolean _ld_CruiseActive = CruiseActive;
            CruiseActive = (BBoolean(true));
            VehicleCanKeepSpeed = vcks;
            if((SpeedAboveMax.equal((BBoolean(false)))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(true));
                CruiseSpeedAtMax = csam;
            } else {
                CruiseSpeedAtMax = (BBoolean(true));
            }
            ObstacleStatusJustChanged = (BBoolean(true));
            if((_ld_CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                CruiseSpeedChangeInProgress = (BBoolean(true));
            } else {
                CCInitialisationInProgress = (BBoolean(true));
            }
            if((_ld_NumberOfSetCruise.less((BInteger(1)))).booleanValue()) {
                NumberOfSetCruise = _ld_NumberOfSetCruise.plus((BInteger(1)));
            } 

        }

        void CCInitialisationFinished(const BBoolean& vtks, const BBoolean& vtktg) {
            VehicleTryKeepTimeGap = vtktg;
            VehicleTryKeepSpeed = vtks;

        }

        void CCInitialisationDelayFinished() {
            CCInitialisationInProgress = (BBoolean(true));

        }

        void CruiseSpeedChangeFinished(const BBoolean& vtks, const BBoolean& vtktg) {
            VehicleTryKeepTimeGap = vtktg;
            VehicleTryKeepSpeed = vtks;

        }

        void CruiseSpeedChangeDelayFinished() {
            CruiseSpeedChangeInProgress = (BBoolean(true));

        }

        void CruiseOff() {
            CruiseActive = (BBoolean(false));
            VehicleCanKeepSpeed = (BBoolean(false));
            VehicleTryKeepSpeed = (BBoolean(false));
            VehicleAtCruiseSpeed = (BBoolean(false));
            VehicleTryKeepTimeGap = (BBoolean(false));
            CruiseSpeedAtMax = (BBoolean(false));
            ObstacleDistance = (ODset(ODset::ODnone));
            NumberOfSetCruise = (BInteger(0));
            ObstacleStatusJustChanged = (BBoolean(false));
            CCInitialisationInProgress = (BBoolean(false));
            CruiseSpeedChangeInProgress = (BBoolean(false));

        }

        void ExternalForcesBecomesExtreme() {
            VehicleCanKeepSpeed = (BBoolean(false));

        }

        void ExternalForcesBecomesNormal() {
            VehicleCanKeepSpeed = (BBoolean(true));

        }

        void VehicleLeavesCruiseSpeed() {
            VehicleAtCruiseSpeed = (BBoolean(false));

        }

        void VehicleReachesCruiseSpeed() {
            VehicleAtCruiseSpeed = (BBoolean(true));

        }

        void VehicleExceedsMaxCruiseSpeed() {
            SpeedAboveMax = (BBoolean(true));
            VehicleAtCruiseSpeed = (BBoolean(false));

        }

        void VehicleFallsBelowMaxCruiseSpeed() {
            SpeedAboveMax = (BBoolean(false));
            if(((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && CruiseSpeedAtMax.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(true));
            } 

        }

        void ObstacleDistanceBecomesVeryClose() {
            ObstacleDistance = (ODset(ODset::ODveryclose));
            ObstacleStatusJustChanged = (BBoolean(true));

        }

        void ObstacleDistanceBecomesClose() {
            ObstacleDistance = (ODset(ODset::ODclose));
            ObstacleStatusJustChanged = (BBoolean(true));
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue()) {
                VehicleTryKeepTimeGap = (BBoolean(false));
            } 

        }

        void ObstacleDistanceBecomesBig() {
            ObstacleStatusJustChanged = (BBoolean(true));
            ObstacleDistance = (ODset(ODset::ODnone));
            VehicleTryKeepTimeGap = (BBoolean(false));

        }

        void ObstacleStartsTravelFaster() {
            ObstacleRelativeSpeed = (RSset(RSset::RSpos));
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
            } 
            if((ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).booleanValue()) {
                VehicleTryKeepTimeGap = (BBoolean(false));
            } 

        }

        void ObstacleStopsTravelFaster() {
            ObstacleRelativeSpeed = (RSset(RSset::RSequal));
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
            } 

        }

        void ObstacleStartsTravelSlower() {
            ObstacleRelativeSpeed = (RSset(RSset::RSneg));
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
            } 

        }

        void ObstacleStopsTravelSlower() {
            ObstacleRelativeSpeed = (RSset(RSset::RSequal));
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
            } 

        }

        void ObstacleAppearsWhenCruiseActive(const RSset& ors, const ODset& od) {
            ObstaclePresent = (BBoolean(true));
            ObstacleStatusJustChanged = (BBoolean(true));
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = od;

        }

        void ObstacleAppearsWhenCruiseInactive(const RSset& ors) {
            ObstaclePresent = (BBoolean(true));
            ObstacleRelativeSpeed = ors;
            ObstacleDistance = (ODset(ODset::ODnone));

        }

        void ObstacleDisappears() {
            ObstaclePresent = (BBoolean(false));
            ObstacleRelativeSpeed = (RSset(RSset::RSnone));
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
            } 
            ObstacleDistance = (ODset(ODset::ODnone));
            VehicleTryKeepTimeGap = (BBoolean(false));

        }

        void VehicleManageObstacle(const BBoolean& vtks, const BBoolean& vtktg) {
            VehicleTryKeepTimeGap = vtktg;
            VehicleTryKeepSpeed = vtks;

        }

        void ObstacleBecomesOld() {
            ObstacleStatusJustChanged = (BBoolean(false));

        }

        BBoolean _get_CruiseAllowed() const {
            return CruiseAllowed;
        }

        BBoolean _get_CruiseActive() const {
            return CruiseActive;
        }

        BBoolean _get_VehicleAtCruiseSpeed() const {
            return VehicleAtCruiseSpeed;
        }

        BBoolean _get_VehicleCanKeepSpeed() const {
            return VehicleCanKeepSpeed;
        }

        BBoolean _get_VehicleTryKeepSpeed() const {
            return VehicleTryKeepSpeed;
        }

        BBoolean _get_SpeedAboveMax() const {
            return SpeedAboveMax;
        }

        BBoolean _get_VehicleTryKeepTimeGap() const {
            return VehicleTryKeepTimeGap;
        }

        BBoolean _get_CruiseSpeedAtMax() const {
            return CruiseSpeedAtMax;
        }

        BBoolean _get_ObstaclePresent() const {
            return ObstaclePresent;
        }

        ODset _get_ObstacleDistance() const {
            return ObstacleDistance;
        }

        RSset _get_ObstacleRelativeSpeed() const {
            return ObstacleRelativeSpeed;
        }

        BBoolean _get_ObstacleStatusJustChanged() const {
            return ObstacleStatusJustChanged;
        }

        BBoolean _get_CCInitialisationInProgress() const {
            return CCInitialisationInProgress;
        }

        BBoolean _get_CruiseSpeedChangeInProgress() const {
            return CruiseSpeedChangeInProgress;
        }

        BInteger _get_NumberOfSetCruise() const {
            return NumberOfSetCruise;
        }

        BSet<RSset > _get__RSset() const {
            return _RSset;
        }

        BSet<ODset > _get__ODset() const {
            return _ODset;
        }


        bool _tr_CruiseBecomesNotAllowed() const {
            return (CruiseAllowed.equal((BBoolean(true)))).booleanValue();
        }

        bool _tr_CruiseBecomesAllowed() const {
            return (CruiseAllowed.equal((BBoolean(false)))).booleanValue();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_SetCruiseSpeed() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_2 = BSet<BTuple<BBoolean, BBoolean >>();
            for(BBoolean _ic_vcks_1 : (BOOL)) {
                for(BBoolean _ic_csam_1 : (BOOL)) {
                    if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
                        _ic_set_2 = _ic_set_2._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vcks_1, _ic_csam_1))));
                    }

                }
            }
            return _ic_set_2;
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_CCInitialisationFinished() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_3 = BSet<BTuple<BBoolean, BBoolean >>();
            for(BBoolean _ic_vtks_1 : (BOOL)) {
                for(BBoolean _ic_vtktg_1 : (BOOL)) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                        _ic_set_3 = _ic_set_3._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                    }

                }
            }
            return _ic_set_3;
        }

        bool _tr_CCInitialisationDelayFinished() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CCInitialisationInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_CruiseSpeedChangeFinished() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_5 = BSet<BTuple<BBoolean, BBoolean >>();
            for(BBoolean _ic_vtks_1 : (BOOL)) {
                for(BBoolean _ic_vtktg_1 : (BOOL)) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                        _ic_set_5 = _ic_set_5._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                    }

                }
            }
            return _ic_set_5;
        }

        bool _tr_CruiseSpeedChangeDelayFinished() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _tr_CruiseOff() const {
            return (CruiseActive.equal((BBoolean(true)))).booleanValue();
        }

        bool _tr_ExternalForcesBecomesExtreme() const {
            return (VehicleCanKeepSpeed.equal((BBoolean(true)))).booleanValue();
        }

        bool _tr_ExternalForcesBecomesNormal() const {
            return ((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_VehicleLeavesCruiseSpeed() const {
            return ((BBoolean((BBoolean(VehicleAtCruiseSpeed.equal((BBoolean(true))).booleanValue() && (BBoolean(VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue() && VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_VehicleReachesCruiseSpeed() const {
            return ((BBoolean((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleAtCruiseSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() && SpeedAboveMax.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _tr_VehicleExceedsMaxCruiseSpeed() const {
            return ((BBoolean(SpeedAboveMax.equal((BBoolean(false))).booleanValue() && (BBoolean((BBoolean(CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() || (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _tr_VehicleFallsBelowMaxCruiseSpeed() const {
            return (SpeedAboveMax.equal((BBoolean(true)))).booleanValue();
        }

        bool _tr_ObstacleDistanceBecomesVeryClose() const {
            return ((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue()))).booleanValue();
        }

        bool _tr_ObstacleDistanceBecomesClose() const {
            return ((BBoolean((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue())).booleanValue() || (BBoolean(ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _tr_ObstacleDistanceBecomesBig() const {
            return ((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue()))).booleanValue();
        }

        bool _tr_ObstacleStartsTravelFaster() const {
            return ((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue()))).booleanValue();
        }

        bool _tr_ObstacleStopsTravelFaster() const {
            return (ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue();
        }

        bool _tr_ObstacleStartsTravelSlower() const {
            return (ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))).booleanValue();
        }

        bool _tr_ObstacleStopsTravelSlower() const {
            return (ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))).booleanValue();
        }

        BSet<BTuple<RSset, ODset >> _tr_ObstacleAppearsWhenCruiseActive() const {
            BSet<BTuple<RSset, ODset >> _ic_set_21 = BSet<BTuple<RSset, ODset >>();
            for(RSset _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                for(ODset _ic_od_1 : _ODset.difference((BSet<ODset >((ODset(ODset::ODnone)))))) {
                    if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                        _ic_set_21 = _ic_set_21._union(BSet<BTuple<RSset, ODset >>((BTuple<RSset, ODset >(_ic_ors_1, _ic_od_1))));
                    }

                }
            }
            return _ic_set_21;
        }

        BSet<RSset> _tr_ObstacleAppearsWhenCruiseInactive() const {
            BSet<RSset> _ic_set_22 = BSet<RSset>();
            for(RSset _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                    _ic_set_22 = _ic_set_22._union(BSet<RSset>(_ic_ors_1));
                }

            }
            return _ic_set_22;
        }

        bool _tr_ObstacleDisappears() const {
            return (ObstaclePresent.equal((BBoolean(true)))).booleanValue();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_VehicleManageObstacle() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_24 = BSet<BTuple<BBoolean, BBoolean >>();
            for(BBoolean _ic_vtks_1 : (BOOL)) {
                for(BBoolean _ic_vtktg_1 : (BOOL)) {
                    if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                        _ic_set_24 = _ic_set_24._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                    }

                }
            }
            return _ic_set_24;
        }

        bool _tr_ObstacleBecomesOld() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _check_inv_1() const {
            return ((BOOL).elementOf(CruiseAllowed)).booleanValue();
        }

        bool _check_inv_2() const {
            return ((BOOL).elementOf(CruiseActive)).booleanValue();
        }

        bool _check_inv_3() const {
            return ((BOOL).elementOf(VehicleAtCruiseSpeed)).booleanValue();
        }

        bool _check_inv_4() const {
            return ((BOOL).elementOf(VehicleCanKeepSpeed)).booleanValue();
        }

        bool _check_inv_5() const {
            return ((BOOL).elementOf(VehicleTryKeepSpeed)).booleanValue();
        }

        bool _check_inv_6() const {
            return ((BOOL).elementOf(SpeedAboveMax)).booleanValue();
        }

        bool _check_inv_7() const {
            return ((BOOL).elementOf(VehicleTryKeepTimeGap)).booleanValue();
        }

        bool _check_inv_8() const {
            return ((BOOL).elementOf(CruiseSpeedAtMax)).booleanValue();
        }

        bool _check_inv_9() const {
            return ((NumberOfSetCruise.isNatural())).booleanValue();
        }

        bool _check_inv_10() const {
            return ((BSet<BInteger>::interval((BInteger(0)),(BInteger(1)))).elementOf(NumberOfSetCruise)).booleanValue();
        }

        bool _check_inv_11() const {
            return ((BOOL).elementOf(ObstaclePresent)).booleanValue();
        }

        bool _check_inv_12() const {
            return (_ODset.elementOf(ObstacleDistance)).booleanValue();
        }

        bool _check_inv_13() const {
            return (_RSset.elementOf(ObstacleRelativeSpeed)).booleanValue();
        }

        bool _check_inv_14() const {
            return ((BOOL).elementOf(ObstacleStatusJustChanged)).booleanValue();
        }

        bool _check_inv_15() const {
            return ((BOOL).elementOf(CCInitialisationInProgress)).booleanValue();
        }

        bool _check_inv_16() const {
            return ((BOOL).elementOf(CruiseSpeedChangeInProgress)).booleanValue();
        }

        bool _check_inv_17() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleAtCruiseSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_18() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_19() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_20() const {
            return ((BBoolean((!NumberOfSetCruise.equal((BInteger(0))).booleanValue() || CruiseActive.equal((BBoolean(false))).booleanValue()) && (!CruiseActive.equal((BBoolean(false))).booleanValue() || NumberOfSetCruise.equal((BInteger(0))).booleanValue())))).booleanValue();
        }

        bool _check_inv_21() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_22() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || CruiseSpeedAtMax.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_23() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue()))).booleanValue();
        }

        bool _check_inv_24() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_25() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || CCInitialisationInProgress.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_26() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(false))).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_27() const {
            return ((BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_28() const {
            return ((BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue()))).booleanValue();
        }

        bool _check_inv_29() const {
            return ((BBoolean((!ObstaclePresent.equal((BBoolean(false))).booleanValue() || ObstacleRelativeSpeed.equal((RSset(RSset::RSnone))).booleanValue()) && (!ObstacleRelativeSpeed.equal((RSset(RSset::RSnone))).booleanValue() || ObstaclePresent.equal((BBoolean(false))).booleanValue())))).booleanValue();
        }

        bool _check_inv_30() const {
            return ((BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_31() const {
            return ((BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_32() const {
            return ((BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_33() const {
            return ((BBoolean(!CruiseAllowed.equal((BBoolean(false))).booleanValue() || CruiseActive.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_34() const {
            return ((BBoolean(!SpeedAboveMax.equal((BBoolean(true))).booleanValue() || VehicleAtCruiseSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
        }

        bool _check_inv_35() const {
            return ((BBoolean(!CruiseActive.equal((BBoolean(true))).booleanValue() || (BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue()))._not().booleanValue())).booleanValue()))).booleanValue();
        }

        bool _check_inv_36() const {
            return ((BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _check_inv_37() const {
            return ((BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _check_inv_38() const {
            return ((BBoolean(!(BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        bool _check_inv_39() const {
            return ((BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue()))).booleanValue();
        }

        Cruise_finite1_deterministic_MC _copy() const {
            return Cruise_finite1_deterministic_MC(CruiseAllowed, CruiseActive, VehicleAtCruiseSpeed, VehicleCanKeepSpeed, VehicleTryKeepSpeed, SpeedAboveMax, VehicleTryKeepTimeGap, CruiseSpeedAtMax, ObstaclePresent, ObstacleDistance, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, NumberOfSetCruise);
        }

        friend bool operator ==(const Cruise_finite1_deterministic_MC& o1, const Cruise_finite1_deterministic_MC& o2) {
            return o1._get_CruiseAllowed() == o2._get_CruiseAllowed() && o1._get_CruiseActive() == o2._get_CruiseActive() && o1._get_VehicleAtCruiseSpeed() == o2._get_VehicleAtCruiseSpeed() && o1._get_VehicleCanKeepSpeed() == o2._get_VehicleCanKeepSpeed() && o1._get_VehicleTryKeepSpeed() == o2._get_VehicleTryKeepSpeed() && o1._get_SpeedAboveMax() == o2._get_SpeedAboveMax() && o1._get_VehicleTryKeepTimeGap() == o2._get_VehicleTryKeepTimeGap() && o1._get_CruiseSpeedAtMax() == o2._get_CruiseSpeedAtMax() && o1._get_ObstaclePresent() == o2._get_ObstaclePresent() && o1._get_ObstacleDistance() == o2._get_ObstacleDistance() && o1._get_ObstacleRelativeSpeed() == o2._get_ObstacleRelativeSpeed() && o1._get_ObstacleStatusJustChanged() == o2._get_ObstacleStatusJustChanged() && o1._get_CCInitialisationInProgress() == o2._get_CCInitialisationInProgress() && o1._get_CruiseSpeedChangeInProgress() == o2._get_CruiseSpeedChangeInProgress() && o1._get_NumberOfSetCruise() == o2._get_NumberOfSetCruise();
        }

        friend bool operator !=(const Cruise_finite1_deterministic_MC& o1, const Cruise_finite1_deterministic_MC& o2) {
            return o1._get_CruiseAllowed() != o2._get_CruiseAllowed() || o1._get_CruiseActive() != o2._get_CruiseActive() || o1._get_VehicleAtCruiseSpeed() != o2._get_VehicleAtCruiseSpeed() || o1._get_VehicleCanKeepSpeed() != o2._get_VehicleCanKeepSpeed() || o1._get_VehicleTryKeepSpeed() != o2._get_VehicleTryKeepSpeed() || o1._get_SpeedAboveMax() != o2._get_SpeedAboveMax() || o1._get_VehicleTryKeepTimeGap() != o2._get_VehicleTryKeepTimeGap() || o1._get_CruiseSpeedAtMax() != o2._get_CruiseSpeedAtMax() || o1._get_ObstaclePresent() != o2._get_ObstaclePresent() || o1._get_ObstacleDistance() != o2._get_ObstacleDistance() || o1._get_ObstacleRelativeSpeed() != o2._get_ObstacleRelativeSpeed() || o1._get_ObstacleStatusJustChanged() != o2._get_ObstacleStatusJustChanged() || o1._get_CCInitialisationInProgress() != o2._get_CCInitialisationInProgress() || o1._get_CruiseSpeedChangeInProgress() != o2._get_CruiseSpeedChangeInProgress() || o1._get_NumberOfSetCruise() != o2._get_NumberOfSetCruise();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_CruiseAllowed()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_CruiseActive()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_VehicleAtCruiseSpeed()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_VehicleCanKeepSpeed()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_VehicleTryKeepSpeed()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_SpeedAboveMax()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_VehicleTryKeepTimeGap()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_CruiseSpeedAtMax()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_ObstaclePresent()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_ObstacleDistance()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_ObstacleRelativeSpeed()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_ObstacleStatusJustChanged()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_CCInitialisationInProgress()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_CruiseSpeedChangeInProgress()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_NumberOfSetCruise()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_CruiseAllowed()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_CruiseActive()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_VehicleAtCruiseSpeed()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_VehicleCanKeepSpeed()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_VehicleTryKeepSpeed()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_SpeedAboveMax()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_VehicleTryKeepTimeGap()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_CruiseSpeedAtMax()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_ObstaclePresent()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_ObstacleDistance()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_ObstacleRelativeSpeed()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_ObstacleStatusJustChanged()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_CCInitialisationInProgress()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_CruiseSpeedChangeInProgress()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_NumberOfSetCruise()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const Cruise_finite1_deterministic_MC &machine) {
          strm << "_get_CruiseAllowed: " << machine._get_CruiseAllowed() << "\n";
          strm << "_get_CruiseActive: " << machine._get_CruiseActive() << "\n";
          strm << "_get_VehicleAtCruiseSpeed: " << machine._get_VehicleAtCruiseSpeed() << "\n";
          strm << "_get_VehicleCanKeepSpeed: " << machine._get_VehicleCanKeepSpeed() << "\n";
          strm << "_get_VehicleTryKeepSpeed: " << machine._get_VehicleTryKeepSpeed() << "\n";
          strm << "_get_SpeedAboveMax: " << machine._get_SpeedAboveMax() << "\n";
          strm << "_get_VehicleTryKeepTimeGap: " << machine._get_VehicleTryKeepTimeGap() << "\n";
          strm << "_get_CruiseSpeedAtMax: " << machine._get_CruiseSpeedAtMax() << "\n";
          strm << "_get_ObstaclePresent: " << machine._get_ObstaclePresent() << "\n";
          strm << "_get_ObstacleDistance: " << machine._get_ObstacleDistance() << "\n";
          strm << "_get_ObstacleRelativeSpeed: " << machine._get_ObstacleRelativeSpeed() << "\n";
          strm << "_get_ObstacleStatusJustChanged: " << machine._get_ObstacleStatusJustChanged() << "\n";
          strm << "_get_CCInitialisationInProgress: " << machine._get_CCInitialisationInProgress() << "\n";
          strm << "_get_CruiseSpeedChangeInProgress: " << machine._get_CruiseSpeedChangeInProgress() << "\n";
          strm << "_get_NumberOfSetCruise: " << machine._get_NumberOfSetCruise() << "\n";
          return strm;
        }


};


static std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> generateNextStates(std::mutex& guardMutex, const Cruise_finite1_deterministic_MC& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>& dependentGuard, std::unordered_map<Cruise_finite1_deterministic_MC, immer::map<string, boost::any>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>& guardCache, std::unordered_map<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>& parents, std::atomic<int>& transitions) {
    std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> result = std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>();
    if(isCaching) {
        immer::map<string, boost::any> parentsGuard;
        std::unordered_set<string> dependentGuardsOfState;
        bool parentsExist = false;
        bool dependentGuardsExist = false;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            parentsExist = (parents.find(state) != parents.end());
            dependentGuardsExist = (dependentGuard.find(state) != dependentGuard.end());
            if(parentsExist) {
                parentsGuard = guardCache[parents[state]];
            }
            if(dependentGuardsExist) {
                dependentGuardsOfState = dependentGuard[state];
            }
        }
        immer::map<string, boost::any> newCache = parentsGuard;
        boost::any cachedValue;
        bool dependentGuardsBoolean = true;
        bool _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CruiseBecomesNotAllowed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CruiseBecomesNotAllowed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_CruiseBecomesNotAllowed();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_CruiseBecomesNotAllowed", _trid_1);
        if(_trid_1) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseBecomesNotAllowed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CruiseBecomesNotAllowed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CruiseBecomesNotAllowed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CruiseBecomesAllowed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CruiseBecomesAllowed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_2 = state._tr_CruiseBecomesAllowed();
        } else {
            _trid_2 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_CruiseBecomesAllowed", _trid_2);
        if(_trid_2) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseBecomesAllowed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CruiseBecomesAllowed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CruiseBecomesAllowed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_SetCruiseSpeed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_SetCruiseSpeed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_3 = state._tr_SetCruiseSpeed();
        } else {
            _trid_3 = boost::any_cast<BSet<BTuple<BBoolean, BBoolean >>>(cachedValue);
        }
        newCache = newCache.set("_tr_SetCruiseSpeed", _trid_3);
        for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["SetCruiseSpeed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["SetCruiseSpeed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CCInitialisationFinished"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CCInitialisationFinished") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_4 = state._tr_CCInitialisationFinished();
        } else {
            _trid_4 = boost::any_cast<BSet<BTuple<BBoolean, BBoolean >>>(cachedValue);
        }
        newCache = newCache.set("_tr_CCInitialisationFinished", _trid_4);
        for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CCInitialisationFinished"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CCInitialisationFinished"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_5;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CCInitialisationDelayFinished"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CCInitialisationDelayFinished") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_5 = state._tr_CCInitialisationDelayFinished();
        } else {
            _trid_5 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_CCInitialisationDelayFinished", _trid_5);
        if(_trid_5) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CCInitialisationDelayFinished();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CCInitialisationDelayFinished"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CCInitialisationDelayFinished"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_6;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CruiseSpeedChangeFinished"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CruiseSpeedChangeFinished") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_6 = state._tr_CruiseSpeedChangeFinished();
        } else {
            _trid_6 = boost::any_cast<BSet<BTuple<BBoolean, BBoolean >>>(cachedValue);
        }
        newCache = newCache.set("_tr_CruiseSpeedChangeFinished", _trid_6);
        for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CruiseSpeedChangeFinished"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CruiseSpeedChangeFinished"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_7;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CruiseSpeedChangeDelayFinished"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CruiseSpeedChangeDelayFinished") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
        } else {
            _trid_7 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_CruiseSpeedChangeDelayFinished", _trid_7);
        if(_trid_7) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseSpeedChangeDelayFinished();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CruiseSpeedChangeDelayFinished"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CruiseSpeedChangeDelayFinished"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_8;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_CruiseOff"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_CruiseOff") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_8 = state._tr_CruiseOff();
        } else {
            _trid_8 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_CruiseOff", _trid_8);
        if(_trid_8) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseOff();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["CruiseOff"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["CruiseOff"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_9;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ExternalForcesBecomesExtreme"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ExternalForcesBecomesExtreme") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_9 = state._tr_ExternalForcesBecomesExtreme();
        } else {
            _trid_9 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ExternalForcesBecomesExtreme", _trid_9);
        if(_trid_9) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ExternalForcesBecomesExtreme();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ExternalForcesBecomesExtreme"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ExternalForcesBecomesExtreme"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_10;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ExternalForcesBecomesNormal"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ExternalForcesBecomesNormal") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_10 = state._tr_ExternalForcesBecomesNormal();
        } else {
            _trid_10 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ExternalForcesBecomesNormal", _trid_10);
        if(_trid_10) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ExternalForcesBecomesNormal();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ExternalForcesBecomesNormal"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ExternalForcesBecomesNormal"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_11;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_VehicleLeavesCruiseSpeed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_VehicleLeavesCruiseSpeed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
        } else {
            _trid_11 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_VehicleLeavesCruiseSpeed", _trid_11);
        if(_trid_11) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleLeavesCruiseSpeed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["VehicleLeavesCruiseSpeed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["VehicleLeavesCruiseSpeed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_12;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_VehicleReachesCruiseSpeed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_VehicleReachesCruiseSpeed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_12 = state._tr_VehicleReachesCruiseSpeed();
        } else {
            _trid_12 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_VehicleReachesCruiseSpeed", _trid_12);
        if(_trid_12) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleReachesCruiseSpeed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["VehicleReachesCruiseSpeed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["VehicleReachesCruiseSpeed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_13;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_VehicleExceedsMaxCruiseSpeed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_VehicleExceedsMaxCruiseSpeed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
        } else {
            _trid_13 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_VehicleExceedsMaxCruiseSpeed", _trid_13);
        if(_trid_13) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleExceedsMaxCruiseSpeed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["VehicleExceedsMaxCruiseSpeed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["VehicleExceedsMaxCruiseSpeed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_14;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_VehicleFallsBelowMaxCruiseSpeed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_VehicleFallsBelowMaxCruiseSpeed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
        } else {
            _trid_14 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_VehicleFallsBelowMaxCruiseSpeed", _trid_14);
        if(_trid_14) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleFallsBelowMaxCruiseSpeed();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["VehicleFallsBelowMaxCruiseSpeed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["VehicleFallsBelowMaxCruiseSpeed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_15;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleDistanceBecomesVeryClose"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleDistanceBecomesVeryClose") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
        } else {
            _trid_15 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleDistanceBecomesVeryClose", _trid_15);
        if(_trid_15) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesVeryClose();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleDistanceBecomesVeryClose"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleDistanceBecomesVeryClose"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_16;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleDistanceBecomesClose"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleDistanceBecomesClose") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_16 = state._tr_ObstacleDistanceBecomesClose();
        } else {
            _trid_16 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleDistanceBecomesClose", _trid_16);
        if(_trid_16) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesClose();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleDistanceBecomesClose"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleDistanceBecomesClose"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_17;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleDistanceBecomesBig"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleDistanceBecomesBig") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_17 = state._tr_ObstacleDistanceBecomesBig();
        } else {
            _trid_17 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleDistanceBecomesBig", _trid_17);
        if(_trid_17) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesBig();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleDistanceBecomesBig"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleDistanceBecomesBig"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_18;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleStartsTravelFaster"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleStartsTravelFaster") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_18 = state._tr_ObstacleStartsTravelFaster();
        } else {
            _trid_18 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleStartsTravelFaster", _trid_18);
        if(_trid_18) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStartsTravelFaster();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleStartsTravelFaster"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleStartsTravelFaster"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_19;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleStopsTravelFaster"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleStopsTravelFaster") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_19 = state._tr_ObstacleStopsTravelFaster();
        } else {
            _trid_19 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleStopsTravelFaster", _trid_19);
        if(_trid_19) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStopsTravelFaster();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleStopsTravelFaster"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleStopsTravelFaster"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_20;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleStartsTravelSlower"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleStartsTravelSlower") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_20 = state._tr_ObstacleStartsTravelSlower();
        } else {
            _trid_20 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleStartsTravelSlower", _trid_20);
        if(_trid_20) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStartsTravelSlower();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleStartsTravelSlower"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleStartsTravelSlower"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_21;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleStopsTravelSlower"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleStopsTravelSlower") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_21 = state._tr_ObstacleStopsTravelSlower();
        } else {
            _trid_21 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleStopsTravelSlower", _trid_21);
        if(_trid_21) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStopsTravelSlower();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleStopsTravelSlower"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleStopsTravelSlower"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleAppearsWhenCruiseActive"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleAppearsWhenCruiseActive") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
        } else {
            _trid_22 = boost::any_cast<BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >>>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleAppearsWhenCruiseActive", _trid_22);
        for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
            Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
            Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleAppearsWhenCruiseActive"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleAppearsWhenCruiseActive"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleAppearsWhenCruiseInactive"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleAppearsWhenCruiseInactive") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
        } else {
            _trid_23 = boost::any_cast<BSet<Cruise_finite1_deterministic_MC::RSset>>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleAppearsWhenCruiseInactive", _trid_23);
        for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
            Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleAppearsWhenCruiseInactive"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleAppearsWhenCruiseInactive"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_24;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleDisappears"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleDisappears") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_24 = state._tr_ObstacleDisappears();
        } else {
            _trid_24 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleDisappears", _trid_24);
        if(_trid_24) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDisappears();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleDisappears"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleDisappears"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_25;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_VehicleManageObstacle"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_VehicleManageObstacle") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_25 = state._tr_VehicleManageObstacle();
        } else {
            _trid_25 = boost::any_cast<BSet<BTuple<BBoolean, BBoolean >>>(cachedValue);
        }
        newCache = newCache.set("_tr_VehicleManageObstacle", _trid_25);
        for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["VehicleManageObstacle"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["VehicleManageObstacle"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_26;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_ObstacleBecomesOld"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_ObstacleBecomesOld") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_26 = state._tr_ObstacleBecomesOld();
        } else {
            _trid_26 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_ObstacleBecomesOld", _trid_26);
        if(_trid_26) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleBecomesOld();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["ObstacleBecomesOld"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["ObstacleBecomesOld"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

        {
            std::unique_lock<std::mutex> lock(guardMutex);
            guardCache.insert({state, newCache});
        }
    } else {
        if(state._tr_CruiseBecomesNotAllowed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseBecomesNotAllowed();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_CruiseBecomesAllowed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseBecomesAllowed();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_3 = state._tr_SetCruiseSpeed();
        for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_4 = state._tr_CCInitialisationFinished();
        for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_CCInitialisationDelayFinished()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CCInitialisationDelayFinished();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_6 = state._tr_CruiseSpeedChangeFinished();
        for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_CruiseSpeedChangeDelayFinished()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseSpeedChangeDelayFinished();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_CruiseOff()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.CruiseOff();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ExternalForcesBecomesExtreme()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ExternalForcesBecomesExtreme();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ExternalForcesBecomesNormal()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ExternalForcesBecomesNormal();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_VehicleLeavesCruiseSpeed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleLeavesCruiseSpeed();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_VehicleReachesCruiseSpeed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleReachesCruiseSpeed();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleExceedsMaxCruiseSpeed();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleFallsBelowMaxCruiseSpeed();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleDistanceBecomesVeryClose()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesVeryClose();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleDistanceBecomesClose()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesClose();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleDistanceBecomesBig()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDistanceBecomesBig();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleStartsTravelFaster()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStartsTravelFaster();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleStopsTravelFaster()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStopsTravelFaster();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleStartsTravelSlower()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStartsTravelSlower();
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleStopsTravelSlower()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleStopsTravelSlower();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
        for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
            Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
            Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
        for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
            Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleDisappears()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleDisappears();
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BBoolean, BBoolean >> _trid_25 = state._tr_VehicleManageObstacle();
        for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
            BBoolean _tmp_1 = param.projection2();
            BBoolean _tmp_2 = param.projection1();

            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_ObstacleBecomesOld()) {
            Cruise_finite1_deterministic_MC copiedState = state._copy();
            copiedState.ObstacleBecomesOld();
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated) {
    if(deadlockDetected) {
        cout << "DEADLOCK DETECTED" << "\n";
    }
    if(invariantViolated) {
        cout << "INVARIANT VIOLATED" << "\n";
    }
    if(!deadlockDetected && !invariantViolated) {
        cout << "MODEL CHECKING SUCCESSFUL" << "\n";
    }
    cout << "Number of States: " << states << "\n";
    cout << "Number of Transitions: " << transitions << "\n";
}

static bool checkInvariants(std::mutex& guardMutex, const Cruise_finite1_deterministic_MC& state, bool isCaching, std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>& dependentInvariant) {
    if(isCaching) {
        std::unordered_set<string> dependentInvariantsOfState;
        {
            std::unique_lock<std::mutex> lock(guardMutex);
            dependentInvariantsOfState = dependentInvariant[state];
        }
        if(dependentInvariantsOfState.find("_check_inv_1") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_1()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_2") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_2()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_3") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_3()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_4") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_4()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_5") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_5()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_6") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_6()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_7") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_7()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_8") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_8()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_9") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_9()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_10") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_10()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_11") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_11()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_12") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_12()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_13") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_13()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_14") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_14()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_15") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_15()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_16") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_16()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_17") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_17()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_18") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_18()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_19") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_19()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_20") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_20()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_21") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_21()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_22") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_22()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_23") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_23()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_24") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_24()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_25") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_25()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_26") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_26()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_27") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_27()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_28") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_28()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_29") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_29()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_30") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_30()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_31") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_31()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_32") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_32()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_33") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_33()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_34") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_34()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_35") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_35()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_36") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_36()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_37") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_37()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_38") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_38()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_39") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_39()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25() || !state._check_inv_26() || !state._check_inv_27() || !state._check_inv_28() || !state._check_inv_29() || !state._check_inv_30() || !state._check_inv_31() || !state._check_inv_32() || !state._check_inv_33() || !state._check_inv_34() || !state._check_inv_35() || !state._check_inv_36() || !state._check_inv_37() || !state._check_inv_38() || !state._check_inv_39());
}

static Cruise_finite1_deterministic_MC next(std::list<Cruise_finite1_deterministic_MC>& collection, std::mutex& mutex, Cruise_finite1_deterministic_MC::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case Cruise_finite1_deterministic_MC::BFS: {
            Cruise_finite1_deterministic_MC state = collection.front();
            collection.pop_front();
            return state;
        }
        case Cruise_finite1_deterministic_MC::DFS: {
            Cruise_finite1_deterministic_MC state = collection.back();
            collection.pop_back();
            return state;
        }
        case Cruise_finite1_deterministic_MC::MIXED: {
            if(collection.size() % 2 == 0) {
                Cruise_finite1_deterministic_MC state = collection.front();
                collection.pop_front();
                return state;
            } else {
                Cruise_finite1_deterministic_MC state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(Cruise_finite1_deterministic_MC::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    Cruise_finite1_deterministic_MC machine = Cruise_finite1_deterministic_MC();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() || !machine._check_inv_26() || !machine._check_inv_27() || !machine._check_inv_28() || !machine._check_inv_29() || !machine._check_inv_30() || !machine._check_inv_31() || !machine._check_inv_32() || !machine._check_inv_33() || !machine._check_inv_34() || !machine._check_inv_35() || !machine._check_inv_36() || !machine._check_inv_37() || !machine._check_inv_38() || !machine._check_inv_39()) {
        invariantViolated = true;
    }

    std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> states = std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Cruise_finite1_deterministic_MC> collection = std::list<Cruise_finite1_deterministic_MC>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> dependentInvariant;
    std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> dependentGuard;
    std::unordered_map<Cruise_finite1_deterministic_MC, immer::map<string, boost::any>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> guardCache;
    std::unordered_map<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"ObstacleStopsTravelSlower", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"SetCruiseSpeed", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"}});
        invariantDependency.insert({"VehicleLeavesCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_34"}});
        invariantDependency.insert({"VehicleFallsBelowMaxCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"}});
        invariantDependency.insert({"CCInitialisationFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"VehicleReachesCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_34"}});
        invariantDependency.insert({"ObstacleAppearsWhenCruiseActive", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"ObstacleStartsTravelSlower", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"CruiseBecomesNotAllowed", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"}});
        invariantDependency.insert({"ObstacleAppearsWhenCruiseInactive", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"CCInitialisationDelayFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleDistanceBecomesClose", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        invariantDependency.insert({"ObstacleStartsTravelFaster", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ExternalForcesBecomesExtreme", {"_check_inv_18", "_check_inv_4"}});
        invariantDependency.insert({"CruiseOff", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"}});
        invariantDependency.insert({"CruiseSpeedChangeDelayFinished", {"_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleStopsTravelFaster", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ObstacleDistanceBecomesVeryClose", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        invariantDependency.insert({"VehicleManageObstacle", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"CruiseBecomesAllowed", {"_check_inv_1", "_check_inv_33"}});
        invariantDependency.insert({"VehicleExceedsMaxCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"}});
        invariantDependency.insert({"CruiseSpeedChangeFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleDisappears", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"ExternalForcesBecomesNormal", {"_check_inv_18", "_check_inv_4"}});
        invariantDependency.insert({"ObstacleBecomesOld", {"_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ObstacleDistanceBecomesBig", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        guardDependency.insert({"ObstacleStopsTravelSlower", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"SetCruiseSpeed", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"VehicleLeavesCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"VehicleFallsBelowMaxCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CCInitialisationFinished", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"VehicleReachesCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleAppearsWhenCruiseActive", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ObstacleStartsTravelSlower", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"CruiseBecomesNotAllowed", {"_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ObstacleAppearsWhenCruiseInactive", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"CCInitialisationDelayFinished", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleDistanceBecomesClose", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleStartsTravelFaster", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"ExternalForcesBecomesExtreme", {"_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseOff", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"CruiseSpeedChangeDelayFinished", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleStopsTravelFaster", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"ObstacleDistanceBecomesVeryClose", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"VehicleManageObstacle", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseBecomesAllowed", {"_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"}});
        guardDependency.insert({"VehicleExceedsMaxCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseSpeedChangeFinished", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleDisappears", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ExternalForcesBecomesNormal", {"_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleBecomesOld", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleDistanceBecomesBig", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    while(!collection.empty() && !stopThreads) {
        Cruise_finite1_deterministic_MC state = next(collection, mutex, type);
        std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);
        for(auto nextState : nextStates) {
            if(states.find(nextState) == states.end()) {
                numberStates += 1;
                states.insert(nextState);
                collection.push_back(nextState);
                if(numberStates % 50000 == 0) {
                    cout << "VISITED STATES: " << numberStates << "\n";
                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                    cout << "-------------------" << "\n";
                }
            }
        }

        if(nextStates.empty()) {
            deadlockDetected = true;
            stopThreads = true;
        }

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

static void modelCheckMultiThreaded(Cruise_finite1_deterministic_MC::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    Cruise_finite1_deterministic_MC machine = Cruise_finite1_deterministic_MC();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12() || !machine._check_inv_13() || !machine._check_inv_14() || !machine._check_inv_15() || !machine._check_inv_16() || !machine._check_inv_17() || !machine._check_inv_18() || !machine._check_inv_19() || !machine._check_inv_20() || !machine._check_inv_21() || !machine._check_inv_22() || !machine._check_inv_23() || !machine._check_inv_24() || !machine._check_inv_25() || !machine._check_inv_26() || !machine._check_inv_27() || !machine._check_inv_28() || !machine._check_inv_29() || !machine._check_inv_30() || !machine._check_inv_31() || !machine._check_inv_32() || !machine._check_inv_33() || !machine._check_inv_34() || !machine._check_inv_35() || !machine._check_inv_36() || !machine._check_inv_37() || !machine._check_inv_38() || !machine._check_inv_39()) {
        invariantViolated = true;
    }

    std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> states = std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Cruise_finite1_deterministic_MC> collection = std::list<Cruise_finite1_deterministic_MC>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> dependentInvariant;
    std::unordered_map<Cruise_finite1_deterministic_MC, std::unordered_set<string>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> dependentGuard;
    std::unordered_map<Cruise_finite1_deterministic_MC, immer::map<string, boost::any>, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> guardCache;
    std::unordered_map<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> parents;
    if(isCaching) {
        invariantDependency.insert({"ObstacleStopsTravelSlower", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"SetCruiseSpeed", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_33", "_check_inv_26", "_check_inv_21", "_check_inv_20", "_check_inv_4", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"}});
        invariantDependency.insert({"VehicleLeavesCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_34"}});
        invariantDependency.insert({"VehicleFallsBelowMaxCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"}});
        invariantDependency.insert({"CCInitialisationFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"VehicleReachesCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_34"}});
        invariantDependency.insert({"ObstacleAppearsWhenCruiseActive", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"ObstacleStartsTravelSlower", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"CruiseBecomesNotAllowed", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3", "_check_inv_1"}});
        invariantDependency.insert({"ObstacleAppearsWhenCruiseInactive", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_36", "_check_inv_13", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"CCInitialisationDelayFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_36", "_check_inv_25", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleDistanceBecomesClose", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        invariantDependency.insert({"ObstacleStartsTravelFaster", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ExternalForcesBecomesExtreme", {"_check_inv_18", "_check_inv_4"}});
        invariantDependency.insert({"CruiseOff", {"_check_inv_18", "_check_inv_17", "_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_15", "_check_inv_37", "_check_inv_19", "_check_inv_10", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_12", "_check_inv_34", "_check_inv_33", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_7", "_check_inv_20", "_check_inv_4", "_check_inv_5", "_check_inv_25", "_check_inv_24", "_check_inv_8", "_check_inv_23", "_check_inv_9", "_check_inv_22", "_check_inv_2", "_check_inv_3"}});
        invariantDependency.insert({"CruiseSpeedChangeDelayFinished", {"_check_inv_39", "_check_inv_16", "_check_inv_38", "_check_inv_37", "_check_inv_26", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleStopsTravelFaster", {"_check_inv_29", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ObstacleDistanceBecomesVeryClose", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_31", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        invariantDependency.insert({"VehicleManageObstacle", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"CruiseBecomesAllowed", {"_check_inv_1", "_check_inv_33"}});
        invariantDependency.insert({"VehicleExceedsMaxCruiseSpeed", {"_check_inv_17", "_check_inv_3", "_check_inv_6", "_check_inv_34"}});
        invariantDependency.insert({"CruiseSpeedChangeFinished", {"_check_inv_39", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_19", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_5", "_check_inv_36", "_check_inv_35"}});
        invariantDependency.insert({"ObstacleDisappears", {"_check_inv_29", "_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_13", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23", "_check_inv_11"}});
        invariantDependency.insert({"ExternalForcesBecomesNormal", {"_check_inv_18", "_check_inv_4"}});
        invariantDependency.insert({"ObstacleBecomesOld", {"_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24"}});
        invariantDependency.insert({"ObstacleDistanceBecomesBig", {"_check_inv_39", "_check_inv_28", "_check_inv_38", "_check_inv_27", "_check_inv_37", "_check_inv_32", "_check_inv_21", "_check_inv_31", "_check_inv_7", "_check_inv_30", "_check_inv_14", "_check_inv_36", "_check_inv_35", "_check_inv_24", "_check_inv_12", "_check_inv_23"}});
        guardDependency.insert({"ObstacleStopsTravelSlower", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"SetCruiseSpeed", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"VehicleLeavesCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"VehicleFallsBelowMaxCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CCInitialisationFinished", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"VehicleReachesCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleAppearsWhenCruiseActive", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ObstacleStartsTravelSlower", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"CruiseBecomesNotAllowed", {"_tr_SetCruiseSpeed", "_tr_VehicleManageObstacle", "_tr_CruiseBecomesAllowed", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseBecomesNotAllowed", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ObstacleAppearsWhenCruiseInactive", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"CCInitialisationDelayFinished", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleDistanceBecomesClose", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleStartsTravelFaster", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"ExternalForcesBecomesExtreme", {"_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseOff", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_ExternalForcesBecomesNormal", "_tr_CruiseSpeedChangeFinished", "_tr_ExternalForcesBecomesExtreme", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleReachesCruiseSpeed", "_tr_CruiseOff", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"CruiseSpeedChangeDelayFinished", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleStopsTravelFaster", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose"}});
        guardDependency.insert({"ObstacleDistanceBecomesVeryClose", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"VehicleManageObstacle", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseBecomesAllowed", {"_tr_SetCruiseSpeed", "_tr_CruiseBecomesAllowed", "_tr_CruiseBecomesNotAllowed"}});
        guardDependency.insert({"VehicleExceedsMaxCruiseSpeed", {"_tr_VehicleReachesCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"CruiseSpeedChangeFinished", {"_tr_ObstacleBecomesOld", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleDisappears", {"_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStopsTravelSlower", "_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleDisappears", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleAppearsWhenCruiseInactive"}});
        guardDependency.insert({"ExternalForcesBecomesNormal", {"_tr_ExternalForcesBecomesNormal", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_ExternalForcesBecomesExtreme", "_tr_VehicleLeavesCruiseSpeed"}});
        guardDependency.insert({"ObstacleBecomesOld", {"_tr_VehicleManageObstacle", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        guardDependency.insert({"ObstacleDistanceBecomesBig", {"_tr_VehicleManageObstacle", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleDistanceBecomesClose", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_CruiseSpeedChangeFinished", "_tr_ObstacleBecomesOld", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeDelayFinished"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        Cruise_finite1_deterministic_MC state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);


            for(auto nextState : nextStates) {
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    if(states.find(nextState) == states.end()) {
                        numberStates += 1;
                        states.insert(nextState);
                        collection.push_back(nextState);
                        if(numberStates % 50000 == 0) {
                            cout << "VISITED STATES: " << numberStates << "\n";
                            cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                            cout << "-------------------" << "\n";
                        }
                    }
                }
            }

            {
                std::unique_lock<std::mutex> lock(mutex);
                possibleQueueChanges -= 1;
                int running = possibleQueueChanges;
                if (!collection.empty() || running == 0) {
                    {
                        std::unique_lock<std::mutex> lock(waitMutex);
                        waitFlag = false;
                        waitCV.notify_one();
                    }
                }
            }

            if(nextStates.empty()) {
                deadlockDetected = true;
                stopThreads = true;
            }

            if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
                invariantViolated = true;
                stopThreads = true;
            }


        });
        waitFlag = true;
        boost::asio::post(workers, std::move(task));

        {
            std::unique_lock<std::mutex> lock(waitMutex);
            if (collection.empty() && possibleQueueChanges > 0) {
                waitCV.wait(lock, [&] {
                    return waitFlag == false;
                });
            }
        }
    }
    workers.join();
    printResult(numberStates, transitions, deadlockDetected, invariantViolated);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[0];
    string numberThreads = argv[1];
    string caching = argv[2];

    Cruise_finite1_deterministic_MC::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = Cruise_finite1_deterministic_MC::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = Cruise_finite1_deterministic_MC::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = Cruise_finite1_deterministic_MC::Type::DFS;
    } else {
        cout << "Input for strategy is wrong.\n";
        return -1;
    }

    int threads = 0;
    try {
        threads = std::stoi(numberThreads);
    } catch(std::invalid_argument e) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    if(threads <= 0) {
        cout << "Input for number of threads is wrong.\n";
        return -1;
    }

    bool isCaching = true;


    if(std::string("true").compare(caching) == 0) {
        isCaching = true;
    } else if(std::string("false").compare(strategy) == 0) {
        isCaching = false;
    } else {
        cout << "Input for caching is wrong.\n";
        return - 1;
    }

    if(threads == 1) {
        modelCheckSingleThreaded(type, isCaching);
    } else {
        modelCheckMultiThreaded(type, threads, isCaching);
    }
    return 0;
}



#endif