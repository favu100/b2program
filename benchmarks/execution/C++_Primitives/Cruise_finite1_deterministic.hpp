#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BInteger.hpp>

#ifndef Cruise_finite1_deterministic_H
#define Cruise_finite1_deterministic_H

using namespace std;

class Cruise_finite1_deterministic {

    public:

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
        Cruise_finite1_deterministic() {
            CruiseAllowed = (BBoolean(false));
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

        void CruiseBecomesNotAllowed() {
            if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
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
            } else {
                throw StateNotReachableError();
            }

        }

        void CruiseBecomesAllowed() {
            if((CruiseAllowed.equal((BBoolean(false)))).booleanValue()) {
                CruiseAllowed = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void SetCruiseSpeed(const BBoolean& vcks, const BBoolean& csam) {
            if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
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
            } else {
                throw StateNotReachableError();
            }


        }

        void CCInitialisationFinished(const BBoolean& vtks, const BBoolean& vtktg) {
            if((CCInitialisationInProgress.equal((BBoolean(true)))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            } else {
                throw StateNotReachableError();
            }


        }

        void CCInitialisationDelayFinished() {
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CCInitialisationInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue()) {
                CCInitialisationInProgress = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void CruiseSpeedChangeFinished(const BBoolean& vtks, const BBoolean& vtktg) {
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BOOL).elementOf(vtks).booleanValue() && (BOOL).elementOf(vtktg).booleanValue())).booleanValue() && (BBoolean((BBoolean((BBoolean(vtks.equal((BBoolean(true))).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || vtks.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtks.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue()))).booleanValue()) {
                if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))).booleanValue()) {
                    VehicleTryKeepTimeGap = vtktg;
                    VehicleTryKeepSpeed = vtks;
                } else {
                    throw StateNotReachableError();
                }

            } else {
                throw StateNotReachableError();
            }

        }

        void CruiseSpeedChangeDelayFinished() {
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue()) {
                CruiseSpeedChangeInProgress = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void CruiseOff() {
            if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
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
            } else {
                throw StateNotReachableError();
            }

        }

        void ExternalForcesBecomesExtreme() {
            if((VehicleCanKeepSpeed.equal((BBoolean(true)))).booleanValue()) {
                VehicleCanKeepSpeed = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

        }

        void ExternalForcesBecomesNormal() {
            if(((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                VehicleCanKeepSpeed = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void VehicleLeavesCruiseSpeed() {
            if(((BBoolean((BBoolean(VehicleAtCruiseSpeed.equal((BBoolean(true))).booleanValue() && (BBoolean(VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue() && VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

        }

        void VehicleReachesCruiseSpeed() {
            if(((BBoolean((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && VehicleAtCruiseSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() && SpeedAboveMax.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void VehicleExceedsMaxCruiseSpeed() {
            if(((BBoolean(SpeedAboveMax.equal((BBoolean(false))).booleanValue() && (BBoolean((BBoolean(CruiseActive.equal((BBoolean(false))).booleanValue() || VehicleCanKeepSpeed.equal((BBoolean(false))).booleanValue())).booleanValue() || (BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue()))._not().booleanValue())).booleanValue()))).booleanValue()) {
                SpeedAboveMax = (BBoolean(true));
                VehicleAtCruiseSpeed = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

        }

        void VehicleFallsBelowMaxCruiseSpeed() {
            if((SpeedAboveMax.equal((BBoolean(true)))).booleanValue()) {
                SpeedAboveMax = (BBoolean(false));
                if(((BBoolean(CruiseActive.equal((BBoolean(true))).booleanValue() && CruiseSpeedAtMax.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                    VehicleAtCruiseSpeed = (BBoolean(true));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleDistanceBecomesVeryClose() {
            if(((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue()))).booleanValue()) {
                ObstacleDistance = (ODset(ODset::ODveryclose));
                ObstacleStatusJustChanged = (BBoolean(true));
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleDistanceBecomesClose() {
            if(((BBoolean((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue())).booleanValue() || (BBoolean(ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue())).booleanValue())).booleanValue()))).booleanValue()) {
                ObstacleDistance = (ODset(ODset::ODclose));
                ObstacleStatusJustChanged = (BBoolean(true));
                if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue()) {
                    VehicleTryKeepTimeGap = (BBoolean(false));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleDistanceBecomesBig() {
            if(((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue()))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
                ObstacleDistance = (ODset(ODset::ODnone));
                VehicleTryKeepTimeGap = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleStartsTravelFaster() {
            if(((BBoolean(ObstaclePresent.equal((BBoolean(true))).booleanValue() && ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue()))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSpos));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
                if((ObstacleDistance.unequal((ODset(ODset::ODveryclose)))).booleanValue()) {
                    VehicleTryKeepTimeGap = (BBoolean(false));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleStopsTravelFaster() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos)))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSequal));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleStartsTravelSlower() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSequal)))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSneg));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleStopsTravelSlower() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSneg)))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSequal));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleAppearsWhenCruiseActive(const RSset& ors, const ODset& od) {
            if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(true))).booleanValue()))).booleanValue()) {
                ObstaclePresent = (BBoolean(true));
                ObstacleStatusJustChanged = (BBoolean(true));
                ObstacleRelativeSpeed = ors;
                ObstacleDistance = od;
            } else {
                throw StateNotReachableError();
            }


        }

        void ObstacleAppearsWhenCruiseInactive(const RSset& ors) {
            if(((BBoolean(ObstaclePresent.equal((BBoolean(false))).booleanValue() && CruiseActive.equal((BBoolean(false))).booleanValue()))).booleanValue()) {
                ObstaclePresent = (BBoolean(true));
                ObstacleRelativeSpeed = ors;
                ObstacleDistance = (ODset(ODset::ODnone));
            } else {
                throw StateNotReachableError();
            }


        }

        void ObstacleDisappears() {
            if((ObstaclePresent.equal((BBoolean(true)))).booleanValue()) {
                ObstaclePresent = (BBoolean(false));
                ObstacleRelativeSpeed = (RSset(RSset::RSnone));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
                ObstacleDistance = (ODset(ODset::ODnone));
                VehicleTryKeepTimeGap = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

        }

        void VehicleManageObstacle(const BBoolean& vtks, const BBoolean& vtktg) {
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BOOL).elementOf(vtks).booleanValue() && (BOOL).elementOf(vtktg).booleanValue())).booleanValue() && (BBoolean((BBoolean((BBoolean(vtks.equal((BBoolean(true))).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || vtks.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || vtks.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || vtktg.equal((BBoolean(false))).booleanValue())).booleanValue()))).booleanValue()) {
                if((ObstacleStatusJustChanged.equal((BBoolean(true)))).booleanValue()) {
                    VehicleTryKeepTimeGap = vtktg;
                    VehicleTryKeepSpeed = vtks;
                } else {
                    throw StateNotReachableError();
                }

            } else {
                throw StateNotReachableError();
            }

        }

        void ObstacleBecomesOld() {
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(false));
            } else {
                throw StateNotReachableError();
            }

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

        friend std::ostream& operator<<(std::ostream &strm, const Cruise_finite1_deterministic &machine) {
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


#endif