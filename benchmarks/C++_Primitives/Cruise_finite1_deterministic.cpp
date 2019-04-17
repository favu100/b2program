#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"
#include "BInteger.cpp"

#ifndef Cruise_finite1_deterministic_H
#define Cruise_finite1_deterministic_H

using namespace std;

class Cruise_finite1_deterministic {

    public:
        class RSset : public BObject {
            public:

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

                string name;

                RSset(){}

                RSset(RSset_type type, string name) {
                    this->value = type;
                    this->name = name;
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

                friend std::ostream& operator<<(std::ostream &strm, const RSset& e) {
                  return strm << e.name;
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

        class ODset : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum ODset_type {
                    ODnone, 
                    ODclose, 
                    ODveryclose
                };

                ODset_type value;

                string name;

                ODset(){}

                ODset(ODset_type type, string name) {
                    this->value = type;
                    this->name = name;
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

                friend std::ostream& operator<<(std::ostream &strm, const ODset& e) {
                  return strm << e.name;
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

    private:



        #define _RSset (BSet<RSset >((RSset(RSset::RSnone, "RSnone")), (RSset(RSset::RSpos, "RSpos")), (RSset(RSset::RSneg, "RSneg")), (RSset(RSset::RSequal, "RSequal"))))
        #define _ODset (BSet<ODset >((ODset(ODset::ODnone, "ODnone")), (ODset(ODset::ODclose, "ODclose")), (ODset(ODset::ODveryclose, "ODveryclose"))))

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
            ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
            ObstacleStatusJustChanged = (BBoolean(false));
            CCInitialisationInProgress = (BBoolean(false));
            CruiseSpeedChangeInProgress = (BBoolean(false));
            ObstaclePresent = (BBoolean(false));
            ObstacleRelativeSpeed = (RSset(RSset::RSnone, "RSnone"));
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
                ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
                NumberOfSetCruise = (BInteger(0));
                ObstacleStatusJustChanged = (BBoolean(false));
                CCInitialisationInProgress = (BBoolean(false));
                CruiseSpeedChangeInProgress = (BBoolean(false));
            }
        }

        void CruiseBecomesAllowed() {
            if((CruiseAllowed.equal((BBoolean(false)))).booleanValue()) {
                CruiseAllowed = (BBoolean(true));
            }
        }

        void SetCruiseSpeed(BBoolean vcks, BBoolean csam) {
            if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
                BInteger _ld_NumberOfSetCruise = NumberOfSetCruise;
                CruiseActive = (BBoolean(true));
                VehicleCanKeepSpeed = vcks;
                if((SpeedAboveMax.equal((BBoolean(false)))).booleanValue()) {
                    VehicleAtCruiseSpeed = (BBoolean(true));
                    CruiseSpeedAtMax = csam;
                } else {
                    CruiseSpeedAtMax = (BBoolean(true));
                }
                ObstacleStatusJustChanged = (BBoolean(true));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    CruiseSpeedChangeInProgress = (BBoolean(true));
                } else {
                    CCInitialisationInProgress = (BBoolean(true));
                }
                if((_ld_NumberOfSetCruise.less((BInteger(1)))).booleanValue()) {
                    NumberOfSetCruise = _ld_NumberOfSetCruise.plus((BInteger(1)));
                } 
            }
        }

        void CCInitialisationFinished(BBoolean vtks, BBoolean vtktg) {
            if((CCInitialisationInProgress.equal((BBoolean(true)))).booleanValue()) {
                VehicleTryKeepTimeGap = vtktg;
                VehicleTryKeepSpeed = vtks;
            }
        }

        void CCInitialisationDelayFinished() {
            if((CCInitialisationInProgress.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone"))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos, "RSpos"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
                CCInitialisationInProgress = (BBoolean(true));
            }
        }

        void CruiseSpeedChangeFinished(BBoolean vtks, BBoolean vtktg) {
            if(((BOOL).elementOf(vtks)._and((BOOL).elementOf(vtktg))._and(vtks.equal((BBoolean(true)))._or(vtktg.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true)))))._and(ObstaclePresent.equal((BBoolean(false))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone"))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos, "RSpos"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal, "RSequal")))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone")))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg, "RSneg")))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone")))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose")))).implies(vtktg.equal((BBoolean(false)))))).booleanValue()) {
                if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))).booleanValue()) {
                    VehicleTryKeepTimeGap = vtktg;
                    VehicleTryKeepSpeed = vtks;
                }
            }
        }

        void CruiseSpeedChangeDelayFinished() {
            if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(ObstacleStatusJustChanged.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone"))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos, "RSpos"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose"))))._and(ObstacleStatusJustChanged.equal((BBoolean(false))))._and(CCInitialisationInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
                CruiseSpeedChangeInProgress = (BBoolean(true));
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
                ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
                NumberOfSetCruise = (BInteger(0));
                ObstacleStatusJustChanged = (BBoolean(false));
                CCInitialisationInProgress = (BBoolean(false));
                CruiseSpeedChangeInProgress = (BBoolean(false));
            }
        }

        void ExternalForcesBecomesExtreme() {
            if((VehicleCanKeepSpeed.equal((BBoolean(true)))).booleanValue()) {
                VehicleCanKeepSpeed = (BBoolean(false));
            }
        }

        void ExternalForcesBecomesNormal() {
            if((CruiseActive.equal((BBoolean(true)))._and(VehicleCanKeepSpeed.equal((BBoolean(false))))).booleanValue()) {
                VehicleCanKeepSpeed = (BBoolean(true));
            }
        }

        void VehicleLeavesCruiseSpeed() {
            if((VehicleAtCruiseSpeed.equal((BBoolean(true)))._and(VehicleCanKeepSpeed.equal((BBoolean(false)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(VehicleTryKeepSpeed.equal((BBoolean(false))))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(false));
            }
        }

        void VehicleReachesCruiseSpeed() {
            if((CruiseActive.equal((BBoolean(true)))._and(VehicleAtCruiseSpeed.equal((BBoolean(false))))._and(SpeedAboveMax.equal((BBoolean(false))))).booleanValue()) {
                VehicleAtCruiseSpeed = (BBoolean(true));
            }
        }

        void VehicleExceedsMaxCruiseSpeed() {
            if((SpeedAboveMax.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(false)))._or(VehicleCanKeepSpeed.equal((BBoolean(false))))._or(ObstacleStatusJustChanged.equal((BBoolean(false)))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false))))._not()))).booleanValue()) {
                SpeedAboveMax = (BBoolean(true));
                VehicleAtCruiseSpeed = (BBoolean(false));
            }
        }

        void VehicleFallsBelowMaxCruiseSpeed() {
            if((SpeedAboveMax.equal((BBoolean(true)))).booleanValue()) {
                SpeedAboveMax = (BBoolean(false));
                if((CruiseActive.equal((BBoolean(true)))._and(CruiseSpeedAtMax.equal((BBoolean(true))))).booleanValue()) {
                    VehicleAtCruiseSpeed = (BBoolean(true));
                } 
            }
        }

        void ObstacleDistanceBecomesVeryClose() {
            if((ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg, "RSneg"))))).booleanValue()) {
                ObstacleDistance = (ODset(ODset::ODveryclose, "ODveryclose"));
                ObstacleStatusJustChanged = (BBoolean(true));
            }
        }

        void ObstacleDistanceBecomesClose() {
            if((ObstaclePresent.equal((BBoolean(true)))._and(CruiseActive.equal((BBoolean(true))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos"))))._or(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone")))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg, "RSneg"))))))).booleanValue()) {
                ObstacleDistance = (ODset(ODset::ODclose, "ODclose"));
                ObstacleStatusJustChanged = (BBoolean(true));
                if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))).booleanValue()) {
                    VehicleTryKeepTimeGap = (BBoolean(false));
                } 
            }
        }

        void ObstacleDistanceBecomesBig() {
            if((ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos"))))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(true));
                ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
                VehicleTryKeepTimeGap = (BBoolean(false));
            }
        }

        void ObstacleStartsTravelFaster() {
            if((ObstaclePresent.equal((BBoolean(true)))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal, "RSequal"))))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSpos, "RSpos"));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
                if((ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose")))).booleanValue()) {
                    VehicleTryKeepTimeGap = (BBoolean(false));
                } 
            }
        }

        void ObstacleStopsTravelFaster() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSequal, "RSequal"));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            }
        }

        void ObstacleStartsTravelSlower() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSequal, "RSequal")))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSneg, "RSneg"));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            }
        }

        void ObstacleStopsTravelSlower() {
            if((ObstacleRelativeSpeed.equal((RSset(RSset::RSneg, "RSneg")))).booleanValue()) {
                ObstacleRelativeSpeed = (RSset(RSset::RSequal, "RSequal"));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
            }
        }

        void ObstacleAppearsWhenCruiseActive(RSset ors, ODset od) {
            if((ObstaclePresent.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(true))))).booleanValue()) {
                ObstaclePresent = (BBoolean(true));
                ObstacleStatusJustChanged = (BBoolean(true));
                ObstacleRelativeSpeed = ors;
                ObstacleDistance = od;
            }
        }

        void ObstacleAppearsWhenCruiseInactive(RSset ors) {
            if((ObstaclePresent.equal((BBoolean(false)))._and(CruiseActive.equal((BBoolean(false))))).booleanValue()) {
                ObstaclePresent = (BBoolean(true));
                ObstacleRelativeSpeed = ors;
                ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
            }
        }

        void ObstacleDisappears() {
            if((ObstaclePresent.equal((BBoolean(true)))).booleanValue()) {
                ObstaclePresent = (BBoolean(false));
                ObstacleRelativeSpeed = (RSset(RSset::RSnone, "RSnone"));
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    ObstacleStatusJustChanged = (BBoolean(true));
                } 
                ObstacleDistance = (ODset(ODset::ODnone, "ODnone"));
                VehicleTryKeepTimeGap = (BBoolean(false));
            }
        }

        void VehicleManageObstacle(BBoolean vtks, BBoolean vtktg) {
            if(((BOOL).elementOf(vtks)._and((BOOL).elementOf(vtktg))._and(vtks.equal((BBoolean(true)))._or(vtktg.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstaclePresent.equal((BBoolean(false))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone"))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos, "RSpos"))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtktg.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose"))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(vtks.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal, "RSequal")))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone")))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg, "RSneg")))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone")))).implies(vtktg.equal((BBoolean(false)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose")))).implies(vtktg.equal((BBoolean(false)))))).booleanValue()) {
                if((ObstacleStatusJustChanged.equal((BBoolean(true)))).booleanValue()) {
                    VehicleTryKeepTimeGap = vtktg;
                    VehicleTryKeepSpeed = vtks;
                }
            }
        }

        void ObstacleBecomesOld() {
            if((ObstacleStatusJustChanged.equal((BBoolean(true)))._and(VehicleTryKeepSpeed.equal((BBoolean(true)))._or(VehicleTryKeepTimeGap.equal((BBoolean(true))))._or(CCInitialisationInProgress.equal((BBoolean(true))))._or(CruiseSpeedChangeInProgress.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODnone, "ODnone"))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODclose, "ODclose")))._and(ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos, "RSpos"))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleDistance.equal((ODset(ODset::ODveryclose, "ODveryclose")))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepTimeGap.equal((BBoolean(true)))))._and(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos, "RSpos")))._and(ObstacleDistance.unequal((ODset(ODset::ODveryclose, "ODveryclose"))))._and(CCInitialisationInProgress.equal((BBoolean(false))))._and(CruiseSpeedChangeInProgress.equal((BBoolean(false)))).implies(VehicleTryKeepSpeed.equal((BBoolean(true)))))).booleanValue()) {
                ObstacleStatusJustChanged = (BBoolean(false));
            }
        }

};


#endif