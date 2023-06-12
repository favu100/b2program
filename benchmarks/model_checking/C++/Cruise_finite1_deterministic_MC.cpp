#include <iostream>
#include <string>
#include <immer/map.hpp>
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
#include <boost/optional.hpp>
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

        mutable boost::optional<bool> _tr_cache_CruiseBecomesNotAllowed;
        mutable boost::optional<bool> _tr_cache_CruiseBecomesAllowed;
        mutable boost::optional<BSet<BTuple<BBoolean, BBoolean >>> _tr_cache_SetCruiseSpeed;
        mutable boost::optional<BSet<BTuple<BBoolean, BBoolean >>> _tr_cache_CCInitialisationFinished;
        mutable boost::optional<bool> _tr_cache_CCInitialisationDelayFinished;
        mutable boost::optional<BSet<BTuple<BBoolean, BBoolean >>> _tr_cache_CruiseSpeedChangeFinished;
        mutable boost::optional<bool> _tr_cache_CruiseSpeedChangeDelayFinished;
        mutable boost::optional<bool> _tr_cache_CruiseOff;
        mutable boost::optional<bool> _tr_cache_ExternalForcesBecomesExtreme;
        mutable boost::optional<bool> _tr_cache_ExternalForcesBecomesNormal;
        mutable boost::optional<bool> _tr_cache_VehicleLeavesCruiseSpeed;
        mutable boost::optional<bool> _tr_cache_VehicleReachesCruiseSpeed;
        mutable boost::optional<bool> _tr_cache_VehicleExceedsMaxCruiseSpeed;
        mutable boost::optional<bool> _tr_cache_VehicleFallsBelowMaxCruiseSpeed;
        mutable boost::optional<bool> _tr_cache_ObstacleDistanceBecomesVeryClose;
        mutable boost::optional<bool> _tr_cache_ObstacleDistanceBecomesClose;
        mutable boost::optional<bool> _tr_cache_ObstacleDistanceBecomesBig;
        mutable boost::optional<bool> _tr_cache_ObstacleStartsTravelFaster;
        mutable boost::optional<bool> _tr_cache_ObstacleStopsTravelFaster;
        mutable boost::optional<bool> _tr_cache_ObstacleStartsTravelSlower;
        mutable boost::optional<bool> _tr_cache_ObstacleStopsTravelSlower;
        mutable boost::optional<BSet<BTuple<RSset, ODset >>> _tr_cache_ObstacleAppearsWhenCruiseActive;
        mutable boost::optional<BSet<RSset>> _tr_cache_ObstacleAppearsWhenCruiseInactive;
        mutable boost::optional<bool> _tr_cache_ObstacleDisappears;
        mutable boost::optional<BSet<BTuple<BBoolean, BBoolean >>> _tr_cache_VehicleManageObstacle;
        mutable boost::optional<bool> _tr_cache_ObstacleBecomesOld;

    public:

        std::string stateAccessedVia;

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


        bool _tr_CruiseBecomesNotAllowed(bool isCaching) const {
            if (this->_tr_cache_CruiseBecomesNotAllowed == boost::none){
                bool __tmp_result = (CruiseAllowed.equal((BBoolean(true)))).booleanValue();
                if (isCaching) this->_tr_cache_CruiseBecomesNotAllowed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_CruiseBecomesNotAllowed.get();
        }

        bool _tr_CruiseBecomesAllowed(bool isCaching) const {
            if (this->_tr_cache_CruiseBecomesAllowed == boost::none){
                bool __tmp_result = (CruiseAllowed.equal((BBoolean(false)))).booleanValue();
                if (isCaching) this->_tr_cache_CruiseBecomesAllowed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_CruiseBecomesAllowed.get();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_SetCruiseSpeed(bool isCaching) const {
            if (this->_tr_cache_SetCruiseSpeed == boost::none){
                BSet<BTuple<BBoolean, BBoolean >> _ic_set_2 = BSet<BTuple<BBoolean, BBoolean >>();
                for(const BBoolean& _ic_vcks_1 : (BOOL)) {
                    for(const BBoolean& _ic_csam_1 : (BOOL)) {
                        if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
                            _ic_set_2 = _ic_set_2._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vcks_1, _ic_csam_1))));
                        }

                    }
                }
                if (isCaching) this->_tr_cache_SetCruiseSpeed = _ic_set_2;
                else return _ic_set_2;
            }
            return this->_tr_cache_SetCruiseSpeed.get();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_CCInitialisationFinished(bool isCaching) const {
            if (this->_tr_cache_CCInitialisationFinished == boost::none){
                BSet<BTuple<BBoolean, BBoolean >> _ic_set_3 = BSet<BTuple<BBoolean, BBoolean >>();
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                            _ic_set_3 = _ic_set_3._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

                    }
                }
                if (isCaching) this->_tr_cache_CCInitialisationFinished = _ic_set_3;
                else return _ic_set_3;
            }
            return this->_tr_cache_CCInitialisationFinished.get();
        }

        bool _tr_CCInitialisationDelayFinished(bool isCaching) const {
            if (this->_tr_cache_CCInitialisationDelayFinished == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CCInitialisationInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_CCInitialisationDelayFinished = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_CCInitialisationDelayFinished.get();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_CruiseSpeedChangeFinished(bool isCaching) const {
            if (this->_tr_cache_CruiseSpeedChangeFinished == boost::none){
                BSet<BTuple<BBoolean, BBoolean >> _ic_set_5 = BSet<BTuple<BBoolean, BBoolean >>();
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                            _ic_set_5 = _ic_set_5._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

                    }
                }
                if (isCaching) this->_tr_cache_CruiseSpeedChangeFinished = _ic_set_5;
                else return _ic_set_5;
            }
            return this->_tr_cache_CruiseSpeedChangeFinished.get();
        }

        bool _tr_CruiseSpeedChangeDelayFinished(bool isCaching) const {
            if (this->_tr_cache_CruiseSpeedChangeDelayFinished == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_CruiseSpeedChangeDelayFinished = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_CruiseSpeedChangeDelayFinished.get();
        }

        bool _tr_CruiseOff(bool isCaching) const {
            if (this->_tr_cache_CruiseOff == boost::none){
                bool __tmp_result = (CruiseActive.equal((BBoolean(true)))).booleanValue();
                if (isCaching) this->_tr_cache_CruiseOff = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_CruiseOff.get();
        }

        bool _tr_ExternalForcesBecomesExtreme(bool isCaching) const {
            if (this->_tr_cache_ExternalForcesBecomesExtreme == boost::none){
                bool __tmp_result = (VehicleCanKeepSpeed.equal((BBoolean(true)))).booleanValue();
                if (isCaching) this->_tr_cache_ExternalForcesBecomesExtreme = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ExternalForcesBecomesExtreme.get();
        }

        bool _tr_ExternalForcesBecomesNormal(bool isCaching) const {
            if (this->_tr_cache_ExternalForcesBecomesNormal == boost::none){
                bool __tmp_result = ((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ExternalForcesBecomesNormal = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ExternalForcesBecomesNormal.get();
        }

        bool _tr_VehicleLeavesCruiseSpeed(bool isCaching) const {
            if (this->_tr_cache_VehicleLeavesCruiseSpeed == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(VehicleAtCruiseSpeed.equal((BBoolean(true))).booleanValue() && (BBoolean(VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue() && VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_VehicleLeavesCruiseSpeed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_VehicleLeavesCruiseSpeed.get();
        }

        bool _tr_VehicleReachesCruiseSpeed(bool isCaching) const {
            if (this->_tr_cache_VehicleReachesCruiseSpeed == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleAtCruiseSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() && SpeedAboveMax.equal((BBoolean(false))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_VehicleReachesCruiseSpeed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_VehicleReachesCruiseSpeed.get();
        }

        bool _tr_VehicleExceedsMaxCruiseSpeed(bool isCaching) const {
            if (this->_tr_cache_VehicleExceedsMaxCruiseSpeed == boost::none){
                bool __tmp_result = ((BBoolean(SpeedAboveMax.equal((BBoolean(false))).booleanValue() && (BBoolean((BBoolean(CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() || (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_VehicleExceedsMaxCruiseSpeed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_VehicleExceedsMaxCruiseSpeed.get();
        }

        bool _tr_VehicleFallsBelowMaxCruiseSpeed(bool isCaching) const {
            if (this->_tr_cache_VehicleFallsBelowMaxCruiseSpeed == boost::none){
                bool __tmp_result = (SpeedAboveMax.equal((BBoolean(true)))).booleanValue();
                if (isCaching) this->_tr_cache_VehicleFallsBelowMaxCruiseSpeed = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_VehicleFallsBelowMaxCruiseSpeed.get();
        }

        bool _tr_ObstacleDistanceBecomesVeryClose(bool isCaching) const {
            if (this->_tr_cache_ObstacleDistanceBecomesVeryClose == boost::none){
                bool __tmp_result = ((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleDistanceBecomesVeryClose = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleDistanceBecomesVeryClose.get();
        }

        bool _tr_ObstacleDistanceBecomesClose(bool isCaching) const {
            if (this->_tr_cache_ObstacleDistanceBecomesClose == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue())).booleanValue() || (BBoolean(ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleDistanceBecomesClose = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleDistanceBecomesClose.get();
        }

        bool _tr_ObstacleDistanceBecomesBig(bool isCaching) const {
            if (this->_tr_cache_ObstacleDistanceBecomesBig == boost::none){
                bool __tmp_result = ((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleDistanceBecomesBig = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleDistanceBecomesBig.get();
        }

        bool _tr_ObstacleStartsTravelFaster(bool isCaching) const {
            if (this->_tr_cache_ObstacleStartsTravelFaster == boost::none){
                bool __tmp_result = ((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleStartsTravelFaster = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleStartsTravelFaster.get();
        }

        bool _tr_ObstacleStopsTravelFaster(bool isCaching) const {
            if (this->_tr_cache_ObstacleStopsTravelFaster == boost::none){
                bool __tmp_result = (ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleStopsTravelFaster = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleStopsTravelFaster.get();
        }

        bool _tr_ObstacleStartsTravelSlower(bool isCaching) const {
            if (this->_tr_cache_ObstacleStartsTravelSlower == boost::none){
                bool __tmp_result = (ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleStartsTravelSlower = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleStartsTravelSlower.get();
        }

        bool _tr_ObstacleStopsTravelSlower(bool isCaching) const {
            if (this->_tr_cache_ObstacleStopsTravelSlower == boost::none){
                bool __tmp_result = (ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleStopsTravelSlower = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleStopsTravelSlower.get();
        }

        BSet<BTuple<RSset, ODset >> _tr_ObstacleAppearsWhenCruiseActive(bool isCaching) const {
            if (this->_tr_cache_ObstacleAppearsWhenCruiseActive == boost::none){
                BSet<BTuple<RSset, ODset >> _ic_set_21 = BSet<BTuple<RSset, ODset >>();
                for(const RSset& _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                    for(const ODset& _ic_od_1 : _ODset.difference((BSet<ODset >((ODset(ODset::ODnone)))))) {
                        if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                            _ic_set_21 = _ic_set_21._union(BSet<BTuple<RSset, ODset >>((BTuple<RSset, ODset >(_ic_ors_1, _ic_od_1))));
                        }

                    }
                }
                if (isCaching) this->_tr_cache_ObstacleAppearsWhenCruiseActive = _ic_set_21;
                else return _ic_set_21;
            }
            return this->_tr_cache_ObstacleAppearsWhenCruiseActive.get();
        }

        BSet<RSset> _tr_ObstacleAppearsWhenCruiseInactive(bool isCaching) const {
            if (this->_tr_cache_ObstacleAppearsWhenCruiseInactive == boost::none){
                BSet<RSset> _ic_set_22 = BSet<RSset>();
                for(const RSset& _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                    if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                        _ic_set_22 = _ic_set_22._union(BSet<RSset>(_ic_ors_1));
                    }

                }
                if (isCaching) this->_tr_cache_ObstacleAppearsWhenCruiseInactive = _ic_set_22;
                else return _ic_set_22;
            }
            return this->_tr_cache_ObstacleAppearsWhenCruiseInactive.get();
        }

        bool _tr_ObstacleDisappears(bool isCaching) const {
            if (this->_tr_cache_ObstacleDisappears == boost::none){
                bool __tmp_result = (ObstaclePresent.equal((BBoolean(true)))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleDisappears = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleDisappears.get();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_VehicleManageObstacle(bool isCaching) const {
            if (this->_tr_cache_VehicleManageObstacle == boost::none){
                BSet<BTuple<BBoolean, BBoolean >> _ic_set_24 = BSet<BTuple<BBoolean, BBoolean >>();
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                            _ic_set_24 = _ic_set_24._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

                    }
                }
                if (isCaching) this->_tr_cache_VehicleManageObstacle = _ic_set_24;
                else return _ic_set_24;
            }
            return this->_tr_cache_VehicleManageObstacle.get();
        }

        bool _tr_ObstacleBecomesOld(bool isCaching) const {
            if (this->_tr_cache_ObstacleBecomesOld == boost::none){
                bool __tmp_result = ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
                if (isCaching) this->_tr_cache_ObstacleBecomesOld = __tmp_result;
                else return __tmp_result;
            }
            return this->_tr_cache_ObstacleBecomesOld.get();
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

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        Cruise_finite1_deterministic_MC _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_CruiseBecomesNotAllowed", "_tr_CruiseBecomesAllowed", "_tr_SetCruiseSpeed", "_tr_CCInitialisationFinished", "_tr_CCInitialisationDelayFinished", "_tr_CruiseSpeedChangeFinished", "_tr_CruiseSpeedChangeDelayFinished", "_tr_CruiseOff", "_tr_ExternalForcesBecomesExtreme", "_tr_ExternalForcesBecomesNormal", "_tr_VehicleLeavesCruiseSpeed", "_tr_VehicleReachesCruiseSpeed", "_tr_VehicleExceedsMaxCruiseSpeed", "_tr_VehicleFallsBelowMaxCruiseSpeed", "_tr_ObstacleDistanceBecomesVeryClose", "_tr_ObstacleDistanceBecomesClose", "_tr_ObstacleDistanceBecomesBig", "_tr_ObstacleStartsTravelFaster", "_tr_ObstacleStopsTravelFaster", "_tr_ObstacleStartsTravelSlower", "_tr_ObstacleStopsTravelSlower", "_tr_ObstacleAppearsWhenCruiseActive", "_tr_ObstacleAppearsWhenCruiseInactive", "_tr_ObstacleDisappears", "_tr_VehicleManageObstacle", "_tr_ObstacleBecomesOld"};

            Cruise_finite1_deterministic_MC result = Cruise_finite1_deterministic_MC(CruiseAllowed, CruiseActive, VehicleAtCruiseSpeed, VehicleCanKeepSpeed, VehicleTryKeepSpeed, SpeedAboveMax, VehicleTryKeepTimeGap, CruiseSpeedAtMax, ObstaclePresent, ObstacleDistance, ObstacleRelativeSpeed, ObstacleStatusJustChanged, CCInitialisationInProgress, CruiseSpeedChangeInProgress, NumberOfSetCruise);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_CruiseBecomesNotAllowed"): result._tr_cache_CruiseBecomesNotAllowed = this->_tr_cache_CruiseBecomesNotAllowed; break;
                        case strHash("_tr_CruiseBecomesAllowed"): result._tr_cache_CruiseBecomesAllowed = this->_tr_cache_CruiseBecomesAllowed; break;
                        case strHash("_tr_SetCruiseSpeed"): result._tr_cache_SetCruiseSpeed = this->_tr_cache_SetCruiseSpeed; break;
                        case strHash("_tr_CCInitialisationFinished"): result._tr_cache_CCInitialisationFinished = this->_tr_cache_CCInitialisationFinished; break;
                        case strHash("_tr_CCInitialisationDelayFinished"): result._tr_cache_CCInitialisationDelayFinished = this->_tr_cache_CCInitialisationDelayFinished; break;
                        case strHash("_tr_CruiseSpeedChangeFinished"): result._tr_cache_CruiseSpeedChangeFinished = this->_tr_cache_CruiseSpeedChangeFinished; break;
                        case strHash("_tr_CruiseSpeedChangeDelayFinished"): result._tr_cache_CruiseSpeedChangeDelayFinished = this->_tr_cache_CruiseSpeedChangeDelayFinished; break;
                        case strHash("_tr_CruiseOff"): result._tr_cache_CruiseOff = this->_tr_cache_CruiseOff; break;
                        case strHash("_tr_ExternalForcesBecomesExtreme"): result._tr_cache_ExternalForcesBecomesExtreme = this->_tr_cache_ExternalForcesBecomesExtreme; break;
                        case strHash("_tr_ExternalForcesBecomesNormal"): result._tr_cache_ExternalForcesBecomesNormal = this->_tr_cache_ExternalForcesBecomesNormal; break;
                        case strHash("_tr_VehicleLeavesCruiseSpeed"): result._tr_cache_VehicleLeavesCruiseSpeed = this->_tr_cache_VehicleLeavesCruiseSpeed; break;
                        case strHash("_tr_VehicleReachesCruiseSpeed"): result._tr_cache_VehicleReachesCruiseSpeed = this->_tr_cache_VehicleReachesCruiseSpeed; break;
                        case strHash("_tr_VehicleExceedsMaxCruiseSpeed"): result._tr_cache_VehicleExceedsMaxCruiseSpeed = this->_tr_cache_VehicleExceedsMaxCruiseSpeed; break;
                        case strHash("_tr_VehicleFallsBelowMaxCruiseSpeed"): result._tr_cache_VehicleFallsBelowMaxCruiseSpeed = this->_tr_cache_VehicleFallsBelowMaxCruiseSpeed; break;
                        case strHash("_tr_ObstacleDistanceBecomesVeryClose"): result._tr_cache_ObstacleDistanceBecomesVeryClose = this->_tr_cache_ObstacleDistanceBecomesVeryClose; break;
                        case strHash("_tr_ObstacleDistanceBecomesClose"): result._tr_cache_ObstacleDistanceBecomesClose = this->_tr_cache_ObstacleDistanceBecomesClose; break;
                        case strHash("_tr_ObstacleDistanceBecomesBig"): result._tr_cache_ObstacleDistanceBecomesBig = this->_tr_cache_ObstacleDistanceBecomesBig; break;
                        case strHash("_tr_ObstacleStartsTravelFaster"): result._tr_cache_ObstacleStartsTravelFaster = this->_tr_cache_ObstacleStartsTravelFaster; break;
                        case strHash("_tr_ObstacleStopsTravelFaster"): result._tr_cache_ObstacleStopsTravelFaster = this->_tr_cache_ObstacleStopsTravelFaster; break;
                        case strHash("_tr_ObstacleStartsTravelSlower"): result._tr_cache_ObstacleStartsTravelSlower = this->_tr_cache_ObstacleStartsTravelSlower; break;
                        case strHash("_tr_ObstacleStopsTravelSlower"): result._tr_cache_ObstacleStopsTravelSlower = this->_tr_cache_ObstacleStopsTravelSlower; break;
                        case strHash("_tr_ObstacleAppearsWhenCruiseActive"): result._tr_cache_ObstacleAppearsWhenCruiseActive = this->_tr_cache_ObstacleAppearsWhenCruiseActive; break;
                        case strHash("_tr_ObstacleAppearsWhenCruiseInactive"): result._tr_cache_ObstacleAppearsWhenCruiseInactive = this->_tr_cache_ObstacleAppearsWhenCruiseInactive; break;
                        case strHash("_tr_ObstacleDisappears"): result._tr_cache_ObstacleDisappears = this->_tr_cache_ObstacleDisappears; break;
                        case strHash("_tr_VehicleManageObstacle"): result._tr_cache_VehicleManageObstacle = this->_tr_cache_VehicleManageObstacle; break;
                        case strHash("_tr_ObstacleBecomesOld"): result._tr_cache_ObstacleBecomesOld = this->_tr_cache_ObstacleBecomesOld; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
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


class ModelChecker {
    private:
        Cruise_finite1_deterministic_MC::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<Cruise_finite1_deterministic_MC> unvisitedStates;
        std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Cruise_finite1_deterministic_MC counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
        std::unordered_map<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(Cruise_finite1_deterministic_MC::Type type, int threads, bool isCaching, bool isDebug) {
            this->type = type;
            this->threads = threads;
            this->isCaching = isCaching;
            this->isDebug = isDebug;
            this->invariantViolatedBool = false;
            this->deadlockDetected = false;
            this->transitions = 0;
        }

        void modelCheck() {
            if (isDebug) {
                cout << "Starting Modelchecking, STRATEGY=" << type << ", THREADS=" << threads << ", CACHING=" << isCaching << "\n";
            }

            if (threads <= 1) {
                modelCheckSingleThreaded();
            } else {
                boost::asio::thread_pool workers(threads); // threads indicates the number of workers (without the coordinator)
                modelCheckMultiThreaded(workers);
            }
        }

        void modelCheckSingleThreaded() {
            Cruise_finite1_deterministic_MC machine = Cruise_finite1_deterministic_MC();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            if (isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.empty()) {
                Cruise_finite1_deterministic_MC state = next();

                std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
                    if(states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        parents.insert({nextState, state});
                        unvisitedStates.push_back(nextState);
                        if(states.size() % 50000 == 0) {
                            cout << "VISITED STATES: " << states.size() << "\n";
                            cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                            cout << "-------------------" << "\n";
                        }
                    }
                }

                if(invariantViolated(state)) {
                    invariantViolatedBool = true;
                    counterExampleState = state;
                    break;
                }

                if(nextStates.empty()) {
                    deadlockDetected = true;
                    counterExampleState = state;
                    break;
                }

            }
            printResult();
        }

        void modelCheckMultiThreaded(boost::asio::thread_pool& workers) {
            Cruise_finite1_deterministic_MC machine = Cruise_finite1_deterministic_MC();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads;
            stopThreads = false;
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            if(isCaching) {
                initCache(machine);
            }

            std::atomic<bool> waitFlag;
            waitFlag = true;

            while(!unvisitedStates.empty() && !stopThreads) {
                possibleQueueChanges += 1;
                Cruise_finite1_deterministic_MC state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
                        {
                            std::unique_lock<std::mutex> lock(mutex);
                            if(states.find(nextState) == states.end()) {
                                states.insert(nextState);
                                parents.insert({nextState, state});
                                unvisitedStates.push_back(nextState); // TODO: sync ?
                                if(isDebug && states.size() % 50000 == 0) {
                                    cout << "VISITED STATES: " << states.size() << "\n";
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
                        if (!unvisitedStates.empty() || running == 0) {
                            {
                                std::unique_lock<std::mutex> lock(waitMutex);
                                waitFlag = false;
                                waitCV.notify_one();
                            }
                        }
                    }

                    if(invariantViolated(state)) {
                        invariantViolatedBool = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                    if(nextStates.empty()) {
                        deadlockDetected = true;
                        counterExampleState = state;
                        stopThreads = true;
                    }

                });

                waitFlag = true;
                boost::asio::post(workers, std::move(task));

                {
                    std::unique_lock<std::mutex> lock(waitMutex);
                    while (unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }

        void initCache(Cruise_finite1_deterministic_MC& machine) {
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
            invariantDependency.insert({"", {}});
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
        }


    private:
        Cruise_finite1_deterministic_MC next() {
            std::unique_lock<std::mutex> lock(mutex);
            switch(type) {
                case Cruise_finite1_deterministic_MC::BFS: {
                    Cruise_finite1_deterministic_MC state = unvisitedStates.front();
                    unvisitedStates.pop_front();
                    return state;
                }
                case Cruise_finite1_deterministic_MC::DFS: {
                    Cruise_finite1_deterministic_MC state = unvisitedStates.back();
                    unvisitedStates.pop_back();
                    return state;
                }
                case Cruise_finite1_deterministic_MC::MIXED: {
                    if(unvisitedStates.size() % 2 == 0) {
                        Cruise_finite1_deterministic_MC state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    } else {
                        Cruise_finite1_deterministic_MC state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                }
            };
        }

        std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> generateNextStates(const Cruise_finite1_deterministic_MC& state) {
            std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> result = std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>();
            if(state._tr_CruiseBecomesNotAllowed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CruiseBecomesNotAllowed"]);
                copiedState.CruiseBecomesNotAllowed();
                copiedState.stateAccessedVia = "CruiseBecomesNotAllowed";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_CruiseBecomesAllowed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CruiseBecomesAllowed"]);
                copiedState.CruiseBecomesAllowed();
                copiedState.stateAccessedVia = "CruiseBecomesAllowed";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<BTuple<BBoolean, BBoolean >> _trid_3 = state._tr_SetCruiseSpeed(isCaching);
            for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
                BBoolean _tmp_1 = param.projection2();
                BBoolean _tmp_2 = param.projection1();

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["SetCruiseSpeed"]);
                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                copiedState.stateAccessedVia = "SetCruiseSpeed";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<BTuple<BBoolean, BBoolean >> _trid_4 = state._tr_CCInitialisationFinished(isCaching);
            for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
                BBoolean _tmp_1 = param.projection2();
                BBoolean _tmp_2 = param.projection1();

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CCInitialisationFinished"]);
                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                copiedState.stateAccessedVia = "CCInitialisationFinished";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_CCInitialisationDelayFinished(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CCInitialisationDelayFinished"]);
                copiedState.CCInitialisationDelayFinished();
                copiedState.stateAccessedVia = "CCInitialisationDelayFinished";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<BTuple<BBoolean, BBoolean >> _trid_6 = state._tr_CruiseSpeedChangeFinished(isCaching);
            for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
                BBoolean _tmp_1 = param.projection2();
                BBoolean _tmp_2 = param.projection1();

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CruiseSpeedChangeFinished"]);
                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                copiedState.stateAccessedVia = "CruiseSpeedChangeFinished";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_CruiseSpeedChangeDelayFinished(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CruiseSpeedChangeDelayFinished"]);
                copiedState.CruiseSpeedChangeDelayFinished();
                copiedState.stateAccessedVia = "CruiseSpeedChangeDelayFinished";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_CruiseOff(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["CruiseOff"]);
                copiedState.CruiseOff();
                copiedState.stateAccessedVia = "CruiseOff";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ExternalForcesBecomesExtreme(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ExternalForcesBecomesExtreme"]);
                copiedState.ExternalForcesBecomesExtreme();
                copiedState.stateAccessedVia = "ExternalForcesBecomesExtreme";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ExternalForcesBecomesNormal(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ExternalForcesBecomesNormal"]);
                copiedState.ExternalForcesBecomesNormal();
                copiedState.stateAccessedVia = "ExternalForcesBecomesNormal";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_VehicleLeavesCruiseSpeed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["VehicleLeavesCruiseSpeed"]);
                copiedState.VehicleLeavesCruiseSpeed();
                copiedState.stateAccessedVia = "VehicleLeavesCruiseSpeed";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_VehicleReachesCruiseSpeed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["VehicleReachesCruiseSpeed"]);
                copiedState.VehicleReachesCruiseSpeed();
                copiedState.stateAccessedVia = "VehicleReachesCruiseSpeed";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_VehicleExceedsMaxCruiseSpeed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["VehicleExceedsMaxCruiseSpeed"]);
                copiedState.VehicleExceedsMaxCruiseSpeed();
                copiedState.stateAccessedVia = "VehicleExceedsMaxCruiseSpeed";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_VehicleFallsBelowMaxCruiseSpeed(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["VehicleFallsBelowMaxCruiseSpeed"]);
                copiedState.VehicleFallsBelowMaxCruiseSpeed();
                copiedState.stateAccessedVia = "VehicleFallsBelowMaxCruiseSpeed";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleDistanceBecomesVeryClose(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleDistanceBecomesVeryClose"]);
                copiedState.ObstacleDistanceBecomesVeryClose();
                copiedState.stateAccessedVia = "ObstacleDistanceBecomesVeryClose";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleDistanceBecomesClose(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleDistanceBecomesClose"]);
                copiedState.ObstacleDistanceBecomesClose();
                copiedState.stateAccessedVia = "ObstacleDistanceBecomesClose";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleDistanceBecomesBig(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleDistanceBecomesBig"]);
                copiedState.ObstacleDistanceBecomesBig();
                copiedState.stateAccessedVia = "ObstacleDistanceBecomesBig";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleStartsTravelFaster(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleStartsTravelFaster"]);
                copiedState.ObstacleStartsTravelFaster();
                copiedState.stateAccessedVia = "ObstacleStartsTravelFaster";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleStopsTravelFaster(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleStopsTravelFaster"]);
                copiedState.ObstacleStopsTravelFaster();
                copiedState.stateAccessedVia = "ObstacleStopsTravelFaster";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleStartsTravelSlower(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleStartsTravelSlower"]);
                copiedState.ObstacleStartsTravelSlower();
                copiedState.stateAccessedVia = "ObstacleStartsTravelSlower";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleStopsTravelSlower(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleStopsTravelSlower"]);
                copiedState.ObstacleStopsTravelSlower();
                copiedState.stateAccessedVia = "ObstacleStopsTravelSlower";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive(isCaching);
            for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
                Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
                Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleAppearsWhenCruiseActive"]);
                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseActive";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive(isCaching);
            for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
                Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleAppearsWhenCruiseInactive"]);
                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseInactive";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleDisappears(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleDisappears"]);
                copiedState.ObstacleDisappears();
                copiedState.stateAccessedVia = "ObstacleDisappears";
                result.insert(copiedState);
                transitions += 1;
            }
            BSet<BTuple<BBoolean, BBoolean >> _trid_25 = state._tr_VehicleManageObstacle(isCaching);
            for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
                BBoolean _tmp_1 = param.projection2();
                BBoolean _tmp_2 = param.projection1();

                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["VehicleManageObstacle"]);
                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                copiedState.stateAccessedVia = "VehicleManageObstacle";
                result.insert(copiedState);
                transitions += 1;
            }
            if(state._tr_ObstacleBecomesOld(isCaching)) {
                Cruise_finite1_deterministic_MC copiedState = state._copy(guardDependency["ObstacleBecomesOld"]);
                copiedState.ObstacleBecomesOld();
                copiedState.stateAccessedVia = "ObstacleBecomesOld";
                result.insert(copiedState);
                transitions += 1;
            }

            return result;
        }

        bool invariantViolated(const Cruise_finite1_deterministic_MC& state) {
            std::unordered_set<string> dependentInvariantsOfState;
            if(isCaching) dependentInvariantsOfState = invariantDependency[state.stateAccessedVia];
            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_1") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_1()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_1()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_2") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_2()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_2()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_3") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_3()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_3()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_4") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_4()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_4()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_5") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_5()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_5()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_6") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_6()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_6()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_7") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_7()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_7()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_8") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_8()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_8()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_9") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_9()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_9()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_10") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_10()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_10()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_11") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_11()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_11()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_12") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_12()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_12()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_13") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_13()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_13()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_14") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_14()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_14()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_15") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_15()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_15()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_16") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_16()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_16()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_17") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_17()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_17()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_18") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_18()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_18()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_19") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_19()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_19()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_20") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_20()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_20()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_21") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_21()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_21()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_22") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_22()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_22()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_23") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_23()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_23()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_24") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_24()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_24()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_25") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_25()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_25()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_26") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_26()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_26" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_26()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_26" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_27") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_27()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_27" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_27()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_27" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_28") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_28()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_28" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_28()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_28" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_29") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_29()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_29" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_29()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_29" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_30") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_30()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_30" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_30()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_30" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_31") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_31()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_31" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_31()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_31" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_32") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_32()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_32" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_32()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_32" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_33") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_33()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_33" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_33()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_33" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_34") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_34()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_34" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_34()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_34" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_35") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_35()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_35" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_35()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_35" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_36") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_36()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_36" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_36()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_36" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_37") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_37()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_37" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_37()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_37" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_38") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_38()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_38" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_38()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_38" << "\n";
                  return true;
                }
            }

            if(isCaching) {
                if(dependentInvariantsOfState.find("_check_inv_39") == dependentInvariantsOfState.end()) {
                    if(!state._check_inv_39()) {
                        cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_39" << "\n";
                        return true;
                    }
                }
            } else {
                if(!state._check_inv_39()) {
                  cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_39" << "\n";
                  return true;
                }
            }

            return false;
        }


        void printResult() {
            if(deadlockDetected || invariantViolatedBool) {
                if(deadlockDetected) {
                    cout << "DEADLOCK DETECTED" << "\n";
                } else {
                    cout << "INVARIANT VIOLATED" << "\n";
                }

                cout << "COUNTER EXAMPLE TRACE: " << "\n";

                std::string trace = "";
                while(parents.find(counterExampleState) != parents.end()) {
                    std::stringstream stringStream;
                    stringStream << counterExampleState;
                    trace.insert(0, stringStream.str());
                    trace.insert(0, "\n");
                    trace.insert(0, counterExampleState.stateAccessedVia);
                    trace.insert(0, "\n\n");
                    counterExampleState = parents[counterExampleState];
                }
                cout << trace;
            } else {
                cout << "MODEL CHECKING SUCCESSFUL" << "\n";
            }

            cout << "Number of States: " << states.size() << "\n";
            cout << "Number of Transitions: " << transitions << "\n";
        }
};

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[1];
    string numberThreads = argv[2];
    string caching = argv[3];

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
    } else if(std::string("false").compare(caching) == 0) {
        isCaching = false;
    } else {
        cout << "Input for caching is wrong.\n";
        return - 1;
    }

    bool isDebug = true;
    // TODO

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif