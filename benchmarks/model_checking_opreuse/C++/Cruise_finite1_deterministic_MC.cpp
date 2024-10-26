#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <immer/map.hpp>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <atomic>
#include <any>
#include <mutex>
#include <shared_mutex>
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/VariantViolation.hpp>
#include <btypes_primitives/LoopInvariantViolation.hpp>
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
                    return strm;
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
                    return strm;
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

        class _ProjectionRead_CruiseBecomesNotAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CruiseBecomesNotAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CruiseBecomesNotAllowed& obj1, const _ProjectionRead_CruiseBecomesNotAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead_CruiseBecomesNotAllowed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead_CruiseBecomesNotAllowed& o1, const _ProjectionRead_CruiseBecomesNotAllowed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead_CruiseBecomesNotAllowed& o1, const _ProjectionRead_CruiseBecomesNotAllowed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CruiseBecomesNotAllowed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CruiseBecomesNotAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CruiseBecomesNotAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CruiseBecomesNotAllowed& obj1, const _ProjectionRead__tr_CruiseBecomesNotAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead__tr_CruiseBecomesNotAllowed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead__tr_CruiseBecomesNotAllowed& o1, const _ProjectionRead__tr_CruiseBecomesNotAllowed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead__tr_CruiseBecomesNotAllowed& o1, const _ProjectionRead__tr_CruiseBecomesNotAllowed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CruiseBecomesNotAllowed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CruiseBecomesNotAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CruiseBecomesNotAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CruiseBecomesNotAllowed& obj1, const _ProjectionWrite_CruiseBecomesNotAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean CruiseSpeedAtMax;
                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean CruiseAllowed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BInteger NumberOfSetCruise;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                BBoolean VehicleCanKeepSpeed;
                ODset ObstacleDistance;

                _ProjectionWrite_CruiseBecomesNotAllowed(const BBoolean& VehicleTryKeepSpeed, const BBoolean& CruiseSpeedAtMax, const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& CruiseAllowed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BInteger& NumberOfSetCruise, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const BBoolean& VehicleCanKeepSpeed, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->CruiseAllowed = CruiseAllowed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->NumberOfSetCruise = NumberOfSetCruise;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_CruiseBecomesNotAllowed& o1, const _ProjectionWrite_CruiseBecomesNotAllowed& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax) && o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.CruiseAllowed == (o2.CruiseAllowed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.NumberOfSetCruise == (o2.NumberOfSetCruise) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_CruiseBecomesNotAllowed& o1, const _ProjectionWrite_CruiseBecomesNotAllowed& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax) || o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.CruiseAllowed != (o2.CruiseAllowed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.NumberOfSetCruise != (o2.NumberOfSetCruise) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CruiseBecomesNotAllowed& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CruiseBecomesAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CruiseBecomesAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CruiseBecomesAllowed& obj1, const _ProjectionRead_CruiseBecomesAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead_CruiseBecomesAllowed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead_CruiseBecomesAllowed& o1, const _ProjectionRead_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead_CruiseBecomesAllowed& o1, const _ProjectionRead_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CruiseBecomesAllowed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CruiseBecomesAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CruiseBecomesAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CruiseBecomesAllowed& obj1, const _ProjectionRead__tr_CruiseBecomesAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead__tr_CruiseBecomesAllowed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead__tr_CruiseBecomesAllowed& o1, const _ProjectionRead__tr_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead__tr_CruiseBecomesAllowed& o1, const _ProjectionRead__tr_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CruiseBecomesAllowed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CruiseBecomesAllowed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CruiseBecomesAllowed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CruiseBecomesAllowed& obj1, const _ProjectionWrite_CruiseBecomesAllowed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionWrite_CruiseBecomesAllowed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionWrite_CruiseBecomesAllowed& o1, const _ProjectionWrite_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionWrite_CruiseBecomesAllowed& o1, const _ProjectionWrite_CruiseBecomesAllowed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CruiseBecomesAllowed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_SetCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_SetCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_SetCruiseSpeed& obj1, const _ProjectionRead_SetCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean CruiseAllowed;
                BBoolean SpeedAboveMax;
                BInteger NumberOfSetCruise;

                _ProjectionRead_SetCruiseSpeed(const BBoolean& CruiseActive, const BBoolean& CruiseAllowed, const BBoolean& SpeedAboveMax, const BInteger& NumberOfSetCruise) {
                    this->CruiseActive = CruiseActive;
                    this->CruiseAllowed = CruiseAllowed;
                    this->SpeedAboveMax = SpeedAboveMax;
                    this->NumberOfSetCruise = NumberOfSetCruise;
                }

                friend bool operator ==(const _ProjectionRead_SetCruiseSpeed& o1, const _ProjectionRead_SetCruiseSpeed& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.CruiseAllowed == (o2.CruiseAllowed) && o1.SpeedAboveMax == (o2.SpeedAboveMax) && o1.NumberOfSetCruise == (o2.NumberOfSetCruise);
                }

                friend bool operator !=(const _ProjectionRead_SetCruiseSpeed& o1, const _ProjectionRead_SetCruiseSpeed& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.CruiseAllowed != (o2.CruiseAllowed) || o1.SpeedAboveMax != (o2.SpeedAboveMax) || o1.NumberOfSetCruise != (o2.NumberOfSetCruise);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_SetCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;
                    strm << ", ";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_SetCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_SetCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_SetCruiseSpeed& obj1, const _ProjectionRead__tr_SetCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead__tr_SetCruiseSpeed(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead__tr_SetCruiseSpeed& o1, const _ProjectionRead__tr_SetCruiseSpeed& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead__tr_SetCruiseSpeed& o1, const _ProjectionRead__tr_SetCruiseSpeed& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_SetCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_SetCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_SetCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_SetCruiseSpeed& obj1, const _ProjectionWrite_SetCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedAtMax;
                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BInteger NumberOfSetCruise;
                BBoolean CruiseSpeedChangeInProgress;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionWrite_SetCruiseSpeed(const BBoolean& CruiseSpeedAtMax, const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BInteger& NumberOfSetCruise, const BBoolean& CruiseSpeedChangeInProgress, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->NumberOfSetCruise = NumberOfSetCruise;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionWrite_SetCruiseSpeed& o1, const _ProjectionWrite_SetCruiseSpeed& o2) {
                    return o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax) && o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.NumberOfSetCruise == (o2.NumberOfSetCruise) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionWrite_SetCruiseSpeed& o1, const _ProjectionWrite_SetCruiseSpeed& o2) {
                    return o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax) || o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.NumberOfSetCruise != (o2.NumberOfSetCruise) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_SetCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CCInitialisationFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CCInitialisationFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CCInitialisationFinished& obj1, const _ProjectionRead_CCInitialisationFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CCInitialisationInProgress;
                BBoolean ObstacleStatusJustChanged;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead_CCInitialisationFinished(const BBoolean& CCInitialisationInProgress, const BBoolean& ObstacleStatusJustChanged, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead_CCInitialisationFinished& o1, const _ProjectionRead_CCInitialisationFinished& o2) {
                    return o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead_CCInitialisationFinished& o1, const _ProjectionRead_CCInitialisationFinished& o2) {
                    return o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CCInitialisationFinished& e) {
                    strm << "{";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CCInitialisationFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CCInitialisationFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CCInitialisationFinished& obj1, const _ProjectionRead__tr_CCInitialisationFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CCInitialisationInProgress;
                BBoolean ObstacleStatusJustChanged;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__tr_CCInitialisationFinished(const BBoolean& CCInitialisationInProgress, const BBoolean& ObstacleStatusJustChanged, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__tr_CCInitialisationFinished& o1, const _ProjectionRead__tr_CCInitialisationFinished& o2) {
                    return o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__tr_CCInitialisationFinished& o1, const _ProjectionRead__tr_CCInitialisationFinished& o2) {
                    return o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CCInitialisationFinished& e) {
                    strm << "{";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CCInitialisationFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CCInitialisationFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CCInitialisationFinished& obj1, const _ProjectionWrite_CCInitialisationFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionWrite_CCInitialisationFinished(const BBoolean& VehicleTryKeepSpeed, const BBoolean& VehicleTryKeepTimeGap) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionWrite_CCInitialisationFinished& o1, const _ProjectionWrite_CCInitialisationFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionWrite_CCInitialisationFinished& o1, const _ProjectionWrite_CCInitialisationFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CCInitialisationFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CCInitialisationDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CCInitialisationDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CCInitialisationDelayFinished& obj1, const _ProjectionRead_CCInitialisationDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean CCInitialisationInProgress;
                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead_CCInitialisationDelayFinished(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& CCInitialisationInProgress, const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_CCInitialisationDelayFinished& o1, const _ProjectionRead_CCInitialisationDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_CCInitialisationDelayFinished& o1, const _ProjectionRead_CCInitialisationDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CCInitialisationDelayFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CCInitialisationDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CCInitialisationDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CCInitialisationDelayFinished& obj1, const _ProjectionRead__tr_CCInitialisationDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean CCInitialisationInProgress;
                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__tr_CCInitialisationDelayFinished(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& CCInitialisationInProgress, const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_CCInitialisationDelayFinished& o1, const _ProjectionRead__tr_CCInitialisationDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_CCInitialisationDelayFinished& o1, const _ProjectionRead__tr_CCInitialisationDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CCInitialisationDelayFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CCInitialisationDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CCInitialisationDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CCInitialisationDelayFinished& obj1, const _ProjectionWrite_CCInitialisationDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CCInitialisationInProgress;

                _ProjectionWrite_CCInitialisationDelayFinished(const BBoolean& CCInitialisationInProgress) {
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                }

                friend bool operator ==(const _ProjectionWrite_CCInitialisationDelayFinished& o1, const _ProjectionWrite_CCInitialisationDelayFinished& o2) {
                    return o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress);
                }

                friend bool operator !=(const _ProjectionWrite_CCInitialisationDelayFinished& o1, const _ProjectionWrite_CCInitialisationDelayFinished& o2) {
                    return o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CCInitialisationDelayFinished& e) {
                    strm << "{";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CruiseSpeedChangeFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CruiseSpeedChangeFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CruiseSpeedChangeFinished& obj1, const _ProjectionRead_CruiseSpeedChangeFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead_CruiseSpeedChangeFinished(const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead_CruiseSpeedChangeFinished& o1, const _ProjectionRead_CruiseSpeedChangeFinished& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead_CruiseSpeedChangeFinished& o1, const _ProjectionRead_CruiseSpeedChangeFinished& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CruiseSpeedChangeFinished& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CruiseSpeedChangeFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CruiseSpeedChangeFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CruiseSpeedChangeFinished& obj1, const _ProjectionRead__tr_CruiseSpeedChangeFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__tr_CruiseSpeedChangeFinished(const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__tr_CruiseSpeedChangeFinished& o1, const _ProjectionRead__tr_CruiseSpeedChangeFinished& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__tr_CruiseSpeedChangeFinished& o1, const _ProjectionRead__tr_CruiseSpeedChangeFinished& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CruiseSpeedChangeFinished& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CruiseSpeedChangeFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CruiseSpeedChangeFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CruiseSpeedChangeFinished& obj1, const _ProjectionWrite_CruiseSpeedChangeFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionWrite_CruiseSpeedChangeFinished(const BBoolean& VehicleTryKeepSpeed, const BBoolean& VehicleTryKeepTimeGap) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionWrite_CruiseSpeedChangeFinished& o1, const _ProjectionWrite_CruiseSpeedChangeFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionWrite_CruiseSpeedChangeFinished& o1, const _ProjectionWrite_CruiseSpeedChangeFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CruiseSpeedChangeFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CruiseSpeedChangeDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CruiseSpeedChangeDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CruiseSpeedChangeDelayFinished& obj1, const _ProjectionRead_CruiseSpeedChangeDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead_CruiseSpeedChangeDelayFinished(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_CruiseSpeedChangeDelayFinished& o1, const _ProjectionRead_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_CruiseSpeedChangeDelayFinished& o1, const _ProjectionRead_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CruiseSpeedChangeDelayFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CruiseSpeedChangeDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& obj1, const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__tr_CruiseSpeedChangeDelayFinished(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& o1, const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& o1, const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CruiseSpeedChangeDelayFinished& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CruiseSpeedChangeDelayFinished {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CruiseSpeedChangeDelayFinished& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CruiseSpeedChangeDelayFinished& obj1, const _ProjectionWrite_CruiseSpeedChangeDelayFinished& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionWrite_CruiseSpeedChangeDelayFinished(const BBoolean& CruiseSpeedChangeInProgress) {
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionWrite_CruiseSpeedChangeDelayFinished& o1, const _ProjectionWrite_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionWrite_CruiseSpeedChangeDelayFinished& o1, const _ProjectionWrite_CruiseSpeedChangeDelayFinished& o2) {
                    return o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CruiseSpeedChangeDelayFinished& e) {
                    strm << "{";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_CruiseOff {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_CruiseOff& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_CruiseOff& obj1, const _ProjectionRead_CruiseOff& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;

                _ProjectionRead_CruiseOff(const BBoolean& CruiseActive) {
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead_CruiseOff& o1, const _ProjectionRead_CruiseOff& o2) {
                    return o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead_CruiseOff& o1, const _ProjectionRead_CruiseOff& o2) {
                    return o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_CruiseOff& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_CruiseOff {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_CruiseOff& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_CruiseOff& obj1, const _ProjectionRead__tr_CruiseOff& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;

                _ProjectionRead__tr_CruiseOff(const BBoolean& CruiseActive) {
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead__tr_CruiseOff& o1, const _ProjectionRead__tr_CruiseOff& o2) {
                    return o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead__tr_CruiseOff& o1, const _ProjectionRead__tr_CruiseOff& o2) {
                    return o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_CruiseOff& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_CruiseOff {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_CruiseOff& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_CruiseOff& obj1, const _ProjectionWrite_CruiseOff& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean CruiseSpeedAtMax;
                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BInteger NumberOfSetCruise;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                BBoolean VehicleCanKeepSpeed;
                ODset ObstacleDistance;

                _ProjectionWrite_CruiseOff(const BBoolean& VehicleTryKeepSpeed, const BBoolean& CruiseSpeedAtMax, const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BInteger& NumberOfSetCruise, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const BBoolean& VehicleCanKeepSpeed, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->NumberOfSetCruise = NumberOfSetCruise;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_CruiseOff& o1, const _ProjectionWrite_CruiseOff& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax) && o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.NumberOfSetCruise == (o2.NumberOfSetCruise) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_CruiseOff& o1, const _ProjectionWrite_CruiseOff& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax) || o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.NumberOfSetCruise != (o2.NumberOfSetCruise) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_CruiseOff& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ExternalForcesBecomesExtreme {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ExternalForcesBecomesExtreme& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ExternalForcesBecomesExtreme& obj1, const _ProjectionRead_ExternalForcesBecomesExtreme& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead_ExternalForcesBecomesExtreme(const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead_ExternalForcesBecomesExtreme& o1, const _ProjectionRead_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead_ExternalForcesBecomesExtreme& o1, const _ProjectionRead_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ExternalForcesBecomesExtreme& e) {
                    strm << "{";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ExternalForcesBecomesExtreme {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ExternalForcesBecomesExtreme& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ExternalForcesBecomesExtreme& obj1, const _ProjectionRead__tr_ExternalForcesBecomesExtreme& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__tr_ExternalForcesBecomesExtreme(const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_ExternalForcesBecomesExtreme& o1, const _ProjectionRead__tr_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_ExternalForcesBecomesExtreme& o1, const _ProjectionRead__tr_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ExternalForcesBecomesExtreme& e) {
                    strm << "{";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ExternalForcesBecomesExtreme {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ExternalForcesBecomesExtreme& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ExternalForcesBecomesExtreme& obj1, const _ProjectionWrite_ExternalForcesBecomesExtreme& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleCanKeepSpeed;

                _ProjectionWrite_ExternalForcesBecomesExtreme(const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionWrite_ExternalForcesBecomesExtreme& o1, const _ProjectionWrite_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionWrite_ExternalForcesBecomesExtreme& o1, const _ProjectionWrite_ExternalForcesBecomesExtreme& o2) {
                    return o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ExternalForcesBecomesExtreme& e) {
                    strm << "{";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ExternalForcesBecomesNormal {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ExternalForcesBecomesNormal& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ExternalForcesBecomesNormal& obj1, const _ProjectionRead_ExternalForcesBecomesNormal& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead_ExternalForcesBecomesNormal(const BBoolean& CruiseActive, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead_ExternalForcesBecomesNormal& o1, const _ProjectionRead_ExternalForcesBecomesNormal& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead_ExternalForcesBecomesNormal& o1, const _ProjectionRead_ExternalForcesBecomesNormal& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ExternalForcesBecomesNormal& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ExternalForcesBecomesNormal {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ExternalForcesBecomesNormal& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ExternalForcesBecomesNormal& obj1, const _ProjectionRead__tr_ExternalForcesBecomesNormal& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__tr_ExternalForcesBecomesNormal(const BBoolean& CruiseActive, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_ExternalForcesBecomesNormal& o1, const _ProjectionRead__tr_ExternalForcesBecomesNormal& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_ExternalForcesBecomesNormal& o1, const _ProjectionRead__tr_ExternalForcesBecomesNormal& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ExternalForcesBecomesNormal& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ExternalForcesBecomesNormal {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ExternalForcesBecomesNormal& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ExternalForcesBecomesNormal& obj1, const _ProjectionWrite_ExternalForcesBecomesNormal& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleCanKeepSpeed;

                _ProjectionWrite_ExternalForcesBecomesNormal(const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionWrite_ExternalForcesBecomesNormal& o1, const _ProjectionWrite_ExternalForcesBecomesNormal& o2) {
                    return o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionWrite_ExternalForcesBecomesNormal& o1, const _ProjectionWrite_ExternalForcesBecomesNormal& o2) {
                    return o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ExternalForcesBecomesNormal& e) {
                    strm << "{";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_VehicleLeavesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_VehicleLeavesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_VehicleLeavesCruiseSpeed& obj1, const _ProjectionRead_VehicleLeavesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead_VehicleLeavesCruiseSpeed(const BBoolean& VehicleTryKeepSpeed, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead_VehicleLeavesCruiseSpeed& o1, const _ProjectionRead_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead_VehicleLeavesCruiseSpeed& o1, const _ProjectionRead_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_VehicleLeavesCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_VehicleLeavesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& obj1, const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__tr_VehicleLeavesCruiseSpeed(const BBoolean& VehicleTryKeepSpeed, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& o1, const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& o1, const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_VehicleLeavesCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", "; 
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", "; 
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_VehicleLeavesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_VehicleLeavesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_VehicleLeavesCruiseSpeed& obj1, const _ProjectionWrite_VehicleLeavesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;

                _ProjectionWrite_VehicleLeavesCruiseSpeed(const BBoolean& VehicleAtCruiseSpeed) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                }

                friend bool operator ==(const _ProjectionWrite_VehicleLeavesCruiseSpeed& o1, const _ProjectionWrite_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed);
                }

                friend bool operator !=(const _ProjectionWrite_VehicleLeavesCruiseSpeed& o1, const _ProjectionWrite_VehicleLeavesCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_VehicleLeavesCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_VehicleReachesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_VehicleReachesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_VehicleReachesCruiseSpeed& obj1, const _ProjectionRead_VehicleReachesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean SpeedAboveMax;

                _ProjectionRead_VehicleReachesCruiseSpeed(const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& SpeedAboveMax) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead_VehicleReachesCruiseSpeed& o1, const _ProjectionRead_VehicleReachesCruiseSpeed& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead_VehicleReachesCruiseSpeed& o1, const _ProjectionRead_VehicleReachesCruiseSpeed& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_VehicleReachesCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_VehicleReachesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_VehicleReachesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_VehicleReachesCruiseSpeed& obj1, const _ProjectionRead__tr_VehicleReachesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;
                BBoolean SpeedAboveMax;

                _ProjectionRead__tr_VehicleReachesCruiseSpeed(const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed, const BBoolean& SpeedAboveMax) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead__tr_VehicleReachesCruiseSpeed& o1, const _ProjectionRead__tr_VehicleReachesCruiseSpeed& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead__tr_VehicleReachesCruiseSpeed& o1, const _ProjectionRead__tr_VehicleReachesCruiseSpeed& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_VehicleReachesCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", "; 
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_VehicleReachesCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_VehicleReachesCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_VehicleReachesCruiseSpeed& obj1, const _ProjectionWrite_VehicleReachesCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;

                _ProjectionWrite_VehicleReachesCruiseSpeed(const BBoolean& VehicleAtCruiseSpeed) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                }

                friend bool operator ==(const _ProjectionWrite_VehicleReachesCruiseSpeed& o1, const _ProjectionWrite_VehicleReachesCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed);
                }

                friend bool operator !=(const _ProjectionWrite_VehicleReachesCruiseSpeed& o1, const _ProjectionWrite_VehicleReachesCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_VehicleReachesCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_VehicleExceedsMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& obj1, const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean SpeedAboveMax;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean CruiseSpeedChangeInProgress;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead_VehicleExceedsMaxCruiseSpeed(const BBoolean& CruiseActive, const BBoolean& SpeedAboveMax, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& CruiseSpeedChangeInProgress, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->SpeedAboveMax = SpeedAboveMax;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.SpeedAboveMax == (o2.SpeedAboveMax) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.SpeedAboveMax != (o2.SpeedAboveMax) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_VehicleExceedsMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& obj1, const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean SpeedAboveMax;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean CruiseSpeedChangeInProgress;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed(const BBoolean& CruiseActive, const BBoolean& SpeedAboveMax, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& CruiseSpeedChangeInProgress, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->SpeedAboveMax = SpeedAboveMax;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.SpeedAboveMax == (o2.SpeedAboveMax) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.SpeedAboveMax != (o2.SpeedAboveMax) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;
                    strm << ", "; 
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", "; 
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_VehicleExceedsMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& obj1, const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;
                BBoolean SpeedAboveMax;

                _ProjectionWrite_VehicleExceedsMaxCruiseSpeed(const BBoolean& VehicleAtCruiseSpeed, const BBoolean& SpeedAboveMax) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& o1, const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& obj1, const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedAtMax;
                BBoolean CruiseActive;
                BBoolean SpeedAboveMax;

                _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed(const BBoolean& CruiseSpeedAtMax, const BBoolean& CruiseActive, const BBoolean& SpeedAboveMax) {
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                    this->CruiseActive = CruiseActive;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax) && o1.CruiseActive == (o2.CruiseActive) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax) || o1.CruiseActive != (o2.CruiseActive) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& obj1, const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean SpeedAboveMax;

                _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed(const BBoolean& SpeedAboveMax) {
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& obj1, const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;
                BBoolean SpeedAboveMax;

                _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed(const BBoolean& VehicleAtCruiseSpeed, const BBoolean& SpeedAboveMax) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& o1, const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleDistanceBecomesVeryClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleDistanceBecomesVeryClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleDistanceBecomesVeryClose& obj1, const _ProjectionRead_ObstacleDistanceBecomesVeryClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                ODset ObstacleDistance;

                _ProjectionRead_ObstacleDistanceBecomesVeryClose(const RSset& ObstacleRelativeSpeed, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionRead_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionRead_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleDistanceBecomesVeryClose& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& obj1, const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                ODset ObstacleDistance;

                _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose(const RSset& ObstacleRelativeSpeed, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleDistanceBecomesVeryClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& obj1, const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleDistanceBecomesVeryClose(const BBoolean& ObstacleStatusJustChanged, const ODset& ObstacleDistance) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& o1, const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleDistanceBecomesClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleDistanceBecomesClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleDistanceBecomesClose& obj1, const _ProjectionRead_ObstacleDistanceBecomesClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;
                BBoolean ObstaclePresent;
                ODset ObstacleDistance;

                _ProjectionRead_ObstacleDistanceBecomesClose(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive, const BBoolean& ObstaclePresent, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleDistanceBecomesClose& o1, const _ProjectionRead_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleDistanceBecomesClose& o1, const _ProjectionRead_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleDistanceBecomesClose& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleDistanceBecomesClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesClose& obj1, const _ProjectionRead__tr_ObstacleDistanceBecomesClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;
                BBoolean ObstaclePresent;
                ODset ObstacleDistance;

                _ProjectionRead__tr_ObstacleDistanceBecomesClose(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive, const BBoolean& ObstaclePresent, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleDistanceBecomesClose& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleDistanceBecomesClose& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleDistanceBecomesClose& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleDistanceBecomesClose {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleDistanceBecomesClose& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleDistanceBecomesClose& obj1, const _ProjectionWrite_ObstacleDistanceBecomesClose& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleDistanceBecomesClose(const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleDistanceBecomesClose& o1, const _ProjectionWrite_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleDistanceBecomesClose& o1, const _ProjectionWrite_ObstacleDistanceBecomesClose& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleDistanceBecomesClose& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleDistanceBecomesBig {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleDistanceBecomesBig& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleDistanceBecomesBig& obj1, const _ProjectionRead_ObstacleDistanceBecomesBig& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                ODset ObstacleDistance;

                _ProjectionRead_ObstacleDistanceBecomesBig(const RSset& ObstacleRelativeSpeed, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleDistanceBecomesBig& o1, const _ProjectionRead_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleDistanceBecomesBig& o1, const _ProjectionRead_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleDistanceBecomesBig& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleDistanceBecomesBig {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesBig& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleDistanceBecomesBig& obj1, const _ProjectionRead__tr_ObstacleDistanceBecomesBig& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                ODset ObstacleDistance;

                _ProjectionRead__tr_ObstacleDistanceBecomesBig(const RSset& ObstacleRelativeSpeed, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleDistanceBecomesBig& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleDistanceBecomesBig& o1, const _ProjectionRead__tr_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleDistanceBecomesBig& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleDistanceBecomesBig {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleDistanceBecomesBig& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleDistanceBecomesBig& obj1, const _ProjectionWrite_ObstacleDistanceBecomesBig& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleDistanceBecomesBig(const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleDistanceBecomesBig& o1, const _ProjectionWrite_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleDistanceBecomesBig& o1, const _ProjectionWrite_ObstacleDistanceBecomesBig& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleDistanceBecomesBig& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleStartsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleStartsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleStartsTravelFaster& obj1, const _ProjectionRead_ObstacleStartsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;
                BBoolean ObstaclePresent;
                ODset ObstacleDistance;

                _ProjectionRead_ObstacleStartsTravelFaster(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive, const BBoolean& ObstaclePresent, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleStartsTravelFaster& o1, const _ProjectionRead_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleStartsTravelFaster& o1, const _ProjectionRead_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleStartsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleStartsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleStartsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleStartsTravelFaster& obj1, const _ProjectionRead__tr_ObstacleStartsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;

                _ProjectionRead__tr_ObstacleStartsTravelFaster(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleStartsTravelFaster& o1, const _ProjectionRead__tr_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleStartsTravelFaster& o1, const _ProjectionRead__tr_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleStartsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleStartsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleStartsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleStartsTravelFaster& obj1, const _ProjectionWrite_ObstacleStartsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionWrite_ObstacleStartsTravelFaster(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleStartsTravelFaster& o1, const _ProjectionWrite_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleStartsTravelFaster& o1, const _ProjectionWrite_ObstacleStartsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleStartsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleStopsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleStopsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleStopsTravelFaster& obj1, const _ProjectionRead_ObstacleStopsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;

                _ProjectionRead_ObstacleStopsTravelFaster(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleStopsTravelFaster& o1, const _ProjectionRead_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleStopsTravelFaster& o1, const _ProjectionRead_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleStopsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleStopsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleStopsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleStopsTravelFaster& obj1, const _ProjectionRead__tr_ObstacleStopsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;

                _ProjectionRead__tr_ObstacleStopsTravelFaster(const RSset& ObstacleRelativeSpeed) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleStopsTravelFaster& o1, const _ProjectionRead__tr_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleStopsTravelFaster& o1, const _ProjectionRead__tr_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleStopsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleStopsTravelFaster {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleStopsTravelFaster& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleStopsTravelFaster& obj1, const _ProjectionWrite_ObstacleStopsTravelFaster& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;

                _ProjectionWrite_ObstacleStopsTravelFaster(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleStopsTravelFaster& o1, const _ProjectionWrite_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleStopsTravelFaster& o1, const _ProjectionWrite_ObstacleStopsTravelFaster& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleStopsTravelFaster& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleStartsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleStartsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleStartsTravelSlower& obj1, const _ProjectionRead_ObstacleStartsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;

                _ProjectionRead_ObstacleStartsTravelSlower(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleStartsTravelSlower& o1, const _ProjectionRead_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleStartsTravelSlower& o1, const _ProjectionRead_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleStartsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleStartsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleStartsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleStartsTravelSlower& obj1, const _ProjectionRead__tr_ObstacleStartsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;

                _ProjectionRead__tr_ObstacleStartsTravelSlower(const RSset& ObstacleRelativeSpeed) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleStartsTravelSlower& o1, const _ProjectionRead__tr_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleStartsTravelSlower& o1, const _ProjectionRead__tr_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleStartsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleStartsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleStartsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleStartsTravelSlower& obj1, const _ProjectionWrite_ObstacleStartsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;

                _ProjectionWrite_ObstacleStartsTravelSlower(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleStartsTravelSlower& o1, const _ProjectionWrite_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleStartsTravelSlower& o1, const _ProjectionWrite_ObstacleStartsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleStartsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleStopsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleStopsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleStopsTravelSlower& obj1, const _ProjectionRead_ObstacleStopsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;

                _ProjectionRead_ObstacleStopsTravelSlower(const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleStopsTravelSlower& o1, const _ProjectionRead_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleStopsTravelSlower& o1, const _ProjectionRead_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleStopsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleStopsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleStopsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleStopsTravelSlower& obj1, const _ProjectionRead__tr_ObstacleStopsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;

                _ProjectionRead__tr_ObstacleStopsTravelSlower(const RSset& ObstacleRelativeSpeed) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleStopsTravelSlower& o1, const _ProjectionRead__tr_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleStopsTravelSlower& o1, const _ProjectionRead__tr_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleStopsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleStopsTravelSlower {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleStopsTravelSlower& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleStopsTravelSlower& obj1, const _ProjectionWrite_ObstacleStopsTravelSlower& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;

                _ProjectionWrite_ObstacleStopsTravelSlower(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleStopsTravelSlower& o1, const _ProjectionWrite_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleStopsTravelSlower& o1, const _ProjectionWrite_ObstacleStopsTravelSlower& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleStopsTravelSlower& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleAppearsWhenCruiseActive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleAppearsWhenCruiseActive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleAppearsWhenCruiseActive& obj1, const _ProjectionRead_ObstacleAppearsWhenCruiseActive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstaclePresent;

                _ProjectionRead_ObstacleAppearsWhenCruiseActive(const BBoolean& CruiseActive, const BBoolean& ObstaclePresent) {
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionRead_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionRead_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleAppearsWhenCruiseActive& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& obj1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstaclePresent;

                _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive(const BBoolean& CruiseActive, const BBoolean& ObstaclePresent) {
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleAppearsWhenCruiseActive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& obj1, const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean ObstacleStatusJustChanged;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleAppearsWhenCruiseActive(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& ObstacleStatusJustChanged, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& o1, const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleAppearsWhenCruiseInactive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& obj1, const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstaclePresent;

                _ProjectionRead_ObstacleAppearsWhenCruiseInactive(const BBoolean& CruiseActive, const BBoolean& ObstaclePresent) {
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleAppearsWhenCruiseInactive& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& obj1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstaclePresent;

                _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive(const BBoolean& CruiseActive, const BBoolean& ObstaclePresent) {
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleAppearsWhenCruiseInactive {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& obj1, const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleAppearsWhenCruiseInactive(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& o1, const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleDisappears {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleDisappears& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleDisappears& obj1, const _ProjectionRead_ObstacleDisappears& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstaclePresent;

                _ProjectionRead_ObstacleDisappears(const BBoolean& CruiseActive, const BBoolean& ObstaclePresent) {
                    this->CruiseActive = CruiseActive;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleDisappears& o1, const _ProjectionRead_ObstacleDisappears& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleDisappears& o1, const _ProjectionRead_ObstacleDisappears& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleDisappears& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleDisappears {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleDisappears& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleDisappears& obj1, const _ProjectionRead__tr_ObstacleDisappears& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstaclePresent;

                _ProjectionRead__tr_ObstacleDisappears(const BBoolean& ObstaclePresent) {
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleDisappears& o1, const _ProjectionRead__tr_ObstacleDisappears& o2) {
                    return o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleDisappears& o1, const _ProjectionRead__tr_ObstacleDisappears& o2) {
                    return o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleDisappears& e) {
                    strm << "{";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleDisappears {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleDisappears& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleDisappears& obj1, const _ProjectionWrite_ObstacleDisappears& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean ObstacleStatusJustChanged;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionWrite_ObstacleDisappears(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& ObstacleStatusJustChanged, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleDisappears& o1, const _ProjectionWrite_ObstacleDisappears& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleDisappears& o1, const _ProjectionWrite_ObstacleDisappears& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleDisappears& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_VehicleManageObstacle {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_VehicleManageObstacle& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_VehicleManageObstacle& obj1, const _ProjectionRead_VehicleManageObstacle& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead_VehicleManageObstacle(const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead_VehicleManageObstacle& o1, const _ProjectionRead_VehicleManageObstacle& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead_VehicleManageObstacle& o1, const _ProjectionRead_VehicleManageObstacle& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_VehicleManageObstacle& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_VehicleManageObstacle {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_VehicleManageObstacle& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_VehicleManageObstacle& obj1, const _ProjectionRead__tr_VehicleManageObstacle& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                ODset ObstacleDistance;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__tr_VehicleManageObstacle(const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const ODset& ObstacleDistance, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__tr_VehicleManageObstacle& o1, const _ProjectionRead__tr_VehicleManageObstacle& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__tr_VehicleManageObstacle& o1, const _ProjectionRead__tr_VehicleManageObstacle& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_VehicleManageObstacle& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_VehicleManageObstacle {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_VehicleManageObstacle& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_VehicleManageObstacle& obj1, const _ProjectionWrite_VehicleManageObstacle& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionWrite_VehicleManageObstacle(const BBoolean& VehicleTryKeepSpeed, const BBoolean& VehicleTryKeepTimeGap) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionWrite_VehicleManageObstacle& o1, const _ProjectionWrite_VehicleManageObstacle& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionWrite_VehicleManageObstacle& o1, const _ProjectionWrite_VehicleManageObstacle& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_VehicleManageObstacle& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_ObstacleBecomesOld {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_ObstacleBecomesOld& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_ObstacleBecomesOld& obj1, const _ProjectionRead_ObstacleBecomesOld& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead_ObstacleBecomesOld(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead_ObstacleBecomesOld& o1, const _ProjectionRead_ObstacleBecomesOld& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead_ObstacleBecomesOld& o1, const _ProjectionRead_ObstacleBecomesOld& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_ObstacleBecomesOld& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_ObstacleBecomesOld {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_ObstacleBecomesOld& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_ObstacleBecomesOld& obj1, const _ProjectionRead__tr_ObstacleBecomesOld& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__tr_ObstacleBecomesOld(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__tr_ObstacleBecomesOld& o1, const _ProjectionRead__tr_ObstacleBecomesOld& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__tr_ObstacleBecomesOld& o1, const _ProjectionRead__tr_ObstacleBecomesOld& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_ObstacleBecomesOld& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", "; 
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", "; 
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", "; 
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", "; 
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", "; 
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", "; 
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_ObstacleBecomesOld {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_ObstacleBecomesOld& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_ObstacleBecomesOld& obj1, const _ProjectionWrite_ObstacleBecomesOld& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;

                _ProjectionWrite_ObstacleBecomesOld(const BBoolean& ObstacleStatusJustChanged) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionWrite_ObstacleBecomesOld& o1, const _ProjectionWrite_ObstacleBecomesOld& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionWrite_ObstacleBecomesOld& o1, const _ProjectionWrite_ObstacleBecomesOld& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_ObstacleBecomesOld& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_1& obj1, const _ProjectionRead__check_inv_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseAllowed;

                _ProjectionRead__check_inv_1(const BBoolean& CruiseAllowed) {
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_2& obj1, const _ProjectionRead__check_inv_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;

                _ProjectionRead__check_inv_2(const BBoolean& CruiseActive) {
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_3 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_3& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_3& obj1, const _ProjectionRead__check_inv_3& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;

                _ProjectionRead__check_inv_3(const BBoolean& VehicleAtCruiseSpeed) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_4 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_4& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_4& obj1, const _ProjectionRead__check_inv_4& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__check_inv_4(const BBoolean& VehicleCanKeepSpeed) {
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_5 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_5& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_5& obj1, const _ProjectionRead__check_inv_5& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;

                _ProjectionRead__check_inv_5(const BBoolean& VehicleTryKeepSpeed) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_6 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_6& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_6& obj1, const _ProjectionRead__check_inv_6& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean SpeedAboveMax;

                _ProjectionRead__check_inv_6(const BBoolean& SpeedAboveMax) {
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_7 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_7& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_7& obj1, const _ProjectionRead__check_inv_7& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepTimeGap;

                _ProjectionRead__check_inv_7(const BBoolean& VehicleTryKeepTimeGap) {
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_8 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_8& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_8& obj1, const _ProjectionRead__check_inv_8& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedAtMax;

                _ProjectionRead__check_inv_8(const BBoolean& CruiseSpeedAtMax) {
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_9 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_9& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_9& obj1, const _ProjectionRead__check_inv_9& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger NumberOfSetCruise;

                _ProjectionRead__check_inv_9(const BInteger& NumberOfSetCruise) {
                    this->NumberOfSetCruise = NumberOfSetCruise;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.NumberOfSetCruise == (o2.NumberOfSetCruise);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.NumberOfSetCruise != (o2.NumberOfSetCruise);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_10 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_10& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_10& obj1, const _ProjectionRead__check_inv_10& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger NumberOfSetCruise;

                _ProjectionRead__check_inv_10(const BInteger& NumberOfSetCruise) {
                    this->NumberOfSetCruise = NumberOfSetCruise;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.NumberOfSetCruise == (o2.NumberOfSetCruise);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.NumberOfSetCruise != (o2.NumberOfSetCruise);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_11 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_11& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_11& obj1, const _ProjectionRead__check_inv_11& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstaclePresent;

                _ProjectionRead__check_inv_11(const BBoolean& ObstaclePresent) {
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_11& e) {
                    strm << "{";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_12 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_12& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_12& obj1, const _ProjectionRead__check_inv_12& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                ODset ObstacleDistance;

                _ProjectionRead__check_inv_12(const ODset& ObstacleDistance) {
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_12& e) {
                    strm << "{";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_13 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_13& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_13& obj1, const _ProjectionRead__check_inv_13& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;

                _ProjectionRead__check_inv_13(const RSset& ObstacleRelativeSpeed) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_13& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_14 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_14& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_14& obj1, const _ProjectionRead__check_inv_14& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;

                _ProjectionRead__check_inv_14(const BBoolean& ObstacleStatusJustChanged) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_14& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_15 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_15& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_15& obj1, const _ProjectionRead__check_inv_15& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CCInitialisationInProgress;

                _ProjectionRead__check_inv_15(const BBoolean& CCInitialisationInProgress) {
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_15& e) {
                    strm << "{";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_16 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_16& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_16& obj1, const _ProjectionRead__check_inv_16& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__check_inv_16(const BBoolean& CruiseSpeedChangeInProgress) {
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_16& e) {
                    strm << "{";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_17 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_17& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_17& obj1, const _ProjectionRead__check_inv_17& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleAtCruiseSpeed;

                _ProjectionRead__check_inv_17(const BBoolean& CruiseActive, const BBoolean& VehicleAtCruiseSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_17& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_18 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_18& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_18& obj1, const _ProjectionRead__check_inv_18& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleCanKeepSpeed;

                _ProjectionRead__check_inv_18(const BBoolean& CruiseActive, const BBoolean& VehicleCanKeepSpeed) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleCanKeepSpeed = VehicleCanKeepSpeed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleCanKeepSpeed == (o2.VehicleCanKeepSpeed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleCanKeepSpeed != (o2.VehicleCanKeepSpeed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_18& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleCanKeepSpeed: " << e.VehicleCanKeepSpeed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleCanKeepSpeed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_19 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_19& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_19& obj1, const _ProjectionRead__check_inv_19& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean CruiseActive;

                _ProjectionRead__check_inv_19(const BBoolean& VehicleTryKeepSpeed, const BBoolean& CruiseActive) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_19& o1, const _ProjectionRead__check_inv_19& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_19& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_20 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_20& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_20& obj1, const _ProjectionRead__check_inv_20& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BInteger NumberOfSetCruise;

                _ProjectionRead__check_inv_20(const BBoolean& CruiseActive, const BInteger& NumberOfSetCruise) {
                    this->CruiseActive = CruiseActive;
                    this->NumberOfSetCruise = NumberOfSetCruise;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.NumberOfSetCruise == (o2.NumberOfSetCruise);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_20& o1, const _ProjectionRead__check_inv_20& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.NumberOfSetCruise != (o2.NumberOfSetCruise);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_20& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "NumberOfSetCruise: " << e.NumberOfSetCruise;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (NumberOfSetCruise.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_21 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_21& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_21& obj1, const _ProjectionRead__check_inv_21& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionRead__check_inv_21(const BBoolean& CruiseActive, const BBoolean& VehicleTryKeepTimeGap) {
                    this->CruiseActive = CruiseActive;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_21& o1, const _ProjectionRead__check_inv_21& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_21& o1, const _ProjectionRead__check_inv_21& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_21& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_22 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_22& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_22& obj1, const _ProjectionRead__check_inv_22& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseSpeedAtMax;
                BBoolean CruiseActive;

                _ProjectionRead__check_inv_22(const BBoolean& CruiseSpeedAtMax, const BBoolean& CruiseActive) {
                    this->CruiseSpeedAtMax = CruiseSpeedAtMax;
                    this->CruiseActive = CruiseActive;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_22& o1, const _ProjectionRead__check_inv_22& o2) {
                    return o1.CruiseSpeedAtMax == (o2.CruiseSpeedAtMax) && o1.CruiseActive == (o2.CruiseActive);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_22& o1, const _ProjectionRead__check_inv_22& o2) {
                    return o1.CruiseSpeedAtMax != (o2.CruiseSpeedAtMax) || o1.CruiseActive != (o2.CruiseActive);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_22& e) {
                    strm << "{";
                    strm << "CruiseSpeedAtMax: " << e.CruiseSpeedAtMax;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseSpeedAtMax.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_23 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_23& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_23& obj1, const _ProjectionRead__check_inv_23& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_23(const BBoolean& CruiseActive, const ODset& ObstacleDistance) {
                    this->CruiseActive = CruiseActive;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_23& o1, const _ProjectionRead__check_inv_23& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_23& o1, const _ProjectionRead__check_inv_23& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_23& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_24 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_24& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_24& obj1, const _ProjectionRead__check_inv_24& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean ObstacleStatusJustChanged;

                _ProjectionRead__check_inv_24(const BBoolean& CruiseActive, const BBoolean& ObstacleStatusJustChanged) {
                    this->CruiseActive = CruiseActive;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_24& o1, const _ProjectionRead__check_inv_24& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_24& o1, const _ProjectionRead__check_inv_24& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_24& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_25 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_25& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_25& obj1, const _ProjectionRead__check_inv_25& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean CCInitialisationInProgress;

                _ProjectionRead__check_inv_25(const BBoolean& CruiseActive, const BBoolean& CCInitialisationInProgress) {
                    this->CruiseActive = CruiseActive;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_25& o1, const _ProjectionRead__check_inv_25& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_25& o1, const _ProjectionRead__check_inv_25& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_25& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_26 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_26& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_26& obj1, const _ProjectionRead__check_inv_26& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__check_inv_26(const BBoolean& CruiseActive, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->CruiseActive = CruiseActive;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_26& o1, const _ProjectionRead__check_inv_26& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_26& o1, const _ProjectionRead__check_inv_26& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_26& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_27 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_27& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_27& obj1, const _ProjectionRead__check_inv_27& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstaclePresent;
                BBoolean VehicleTryKeepTimeGap;

                _ProjectionRead__check_inv_27(const BBoolean& ObstaclePresent, const BBoolean& VehicleTryKeepTimeGap) {
                    this->ObstaclePresent = ObstaclePresent;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_27& o1, const _ProjectionRead__check_inv_27& o2) {
                    return o1.ObstaclePresent == (o2.ObstaclePresent) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_27& o1, const _ProjectionRead__check_inv_27& o2) {
                    return o1.ObstaclePresent != (o2.ObstaclePresent) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_27& e) {
                    strm << "{";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_28 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_28& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_28& obj1, const _ProjectionRead__check_inv_28& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstaclePresent;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_28(const BBoolean& ObstaclePresent, const ODset& ObstacleDistance) {
                    this->ObstaclePresent = ObstaclePresent;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_28& o1, const _ProjectionRead__check_inv_28& o2) {
                    return o1.ObstaclePresent == (o2.ObstaclePresent) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_28& o1, const _ProjectionRead__check_inv_28& o2) {
                    return o1.ObstaclePresent != (o2.ObstaclePresent) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_28& e) {
                    strm << "{";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_29 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_29& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_29& obj1, const _ProjectionRead__check_inv_29& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstaclePresent;

                _ProjectionRead__check_inv_29(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstaclePresent) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstaclePresent = ObstaclePresent;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_29& o1, const _ProjectionRead__check_inv_29& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstaclePresent == (o2.ObstaclePresent);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_29& o1, const _ProjectionRead__check_inv_29& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstaclePresent != (o2.ObstaclePresent);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_29& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstaclePresent: " << e.ObstaclePresent;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstaclePresent.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_30 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_30& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_30& obj1, const _ProjectionRead__check_inv_30& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_30(const RSset& ObstacleRelativeSpeed, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_30& o1, const _ProjectionRead__check_inv_30& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_30& o1, const _ProjectionRead__check_inv_30& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_30& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_31 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_31& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_31& obj1, const _ProjectionRead__check_inv_31& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_31(const RSset& ObstacleRelativeSpeed, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_31& o1, const _ProjectionRead__check_inv_31& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_31& o1, const _ProjectionRead__check_inv_31& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_31& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_32 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_32& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_32& obj1, const _ProjectionRead__check_inv_32& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean VehicleTryKeepTimeGap;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_32(const RSset& ObstacleRelativeSpeed, const BBoolean& VehicleTryKeepTimeGap, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_32& o1, const _ProjectionRead__check_inv_32& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_32& o1, const _ProjectionRead__check_inv_32& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_32& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_33 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_33& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_33& obj1, const _ProjectionRead__check_inv_33& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean CruiseActive;
                BBoolean CruiseAllowed;

                _ProjectionRead__check_inv_33(const BBoolean& CruiseActive, const BBoolean& CruiseAllowed) {
                    this->CruiseActive = CruiseActive;
                    this->CruiseAllowed = CruiseAllowed;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_33& o1, const _ProjectionRead__check_inv_33& o2) {
                    return o1.CruiseActive == (o2.CruiseActive) && o1.CruiseAllowed == (o2.CruiseAllowed);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_33& o1, const _ProjectionRead__check_inv_33& o2) {
                    return o1.CruiseActive != (o2.CruiseActive) || o1.CruiseAllowed != (o2.CruiseAllowed);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_33& e) {
                    strm << "{";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "CruiseAllowed: " << e.CruiseAllowed;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (CruiseAllowed.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_34 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_34& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_34& obj1, const _ProjectionRead__check_inv_34& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleAtCruiseSpeed;
                BBoolean SpeedAboveMax;

                _ProjectionRead__check_inv_34(const BBoolean& VehicleAtCruiseSpeed, const BBoolean& SpeedAboveMax) {
                    this->VehicleAtCruiseSpeed = VehicleAtCruiseSpeed;
                    this->SpeedAboveMax = SpeedAboveMax;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_34& o1, const _ProjectionRead__check_inv_34& o2) {
                    return o1.VehicleAtCruiseSpeed == (o2.VehicleAtCruiseSpeed) && o1.SpeedAboveMax == (o2.SpeedAboveMax);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_34& o1, const _ProjectionRead__check_inv_34& o2) {
                    return o1.VehicleAtCruiseSpeed != (o2.VehicleAtCruiseSpeed) || o1.SpeedAboveMax != (o2.SpeedAboveMax);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_34& e) {
                    strm << "{";
                    strm << "VehicleAtCruiseSpeed: " << e.VehicleAtCruiseSpeed;
                    strm << ", ";
                    strm << "SpeedAboveMax: " << e.SpeedAboveMax;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleAtCruiseSpeed.hashCode() << 1);
                    result = 31 * result + (SpeedAboveMax.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_35 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_35& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_35& obj1, const _ProjectionRead__check_inv_35& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean CruiseActive;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;

                _ProjectionRead__check_inv_35(const BBoolean& VehicleTryKeepSpeed, const BBoolean& CruiseActive, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_35& o1, const _ProjectionRead__check_inv_35& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_35& o1, const _ProjectionRead__check_inv_35& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_35& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_36 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_36& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_36& obj1, const _ProjectionRead__check_inv_36& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                BBoolean CruiseActive;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_36(const BBoolean& VehicleTryKeepSpeed, const BBoolean& CruiseActive, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_36& o1, const _ProjectionRead__check_inv_36& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_36& o1, const _ProjectionRead__check_inv_36& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_36& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_37 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_37& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_37& obj1, const _ProjectionRead__check_inv_37& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                RSset ObstacleRelativeSpeed;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_37(const RSset& ObstacleRelativeSpeed, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_37& o1, const _ProjectionRead__check_inv_37& o2) {
                    return o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_37& o1, const _ProjectionRead__check_inv_37& o2) {
                    return o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_37& e) {
                    strm << "{";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_38 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_38& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_38& obj1, const _ProjectionRead__check_inv_38& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean VehicleTryKeepTimeGap;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_38(const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& VehicleTryKeepTimeGap, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->VehicleTryKeepTimeGap = VehicleTryKeepTimeGap;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_38& o1, const _ProjectionRead__check_inv_38& o2) {
                    return o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.VehicleTryKeepTimeGap == (o2.VehicleTryKeepTimeGap) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_38& o1, const _ProjectionRead__check_inv_38& o2) {
                    return o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.VehicleTryKeepTimeGap != (o2.VehicleTryKeepTimeGap) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_38& e) {
                    strm << "{";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "VehicleTryKeepTimeGap: " << e.VehicleTryKeepTimeGap;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (VehicleTryKeepTimeGap.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_39 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_39& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_39& obj1, const _ProjectionRead__check_inv_39& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BBoolean VehicleTryKeepSpeed;
                RSset ObstacleRelativeSpeed;
                BBoolean CruiseActive;
                BBoolean ObstacleStatusJustChanged;
                BBoolean CCInitialisationInProgress;
                BBoolean CruiseSpeedChangeInProgress;
                ODset ObstacleDistance;

                _ProjectionRead__check_inv_39(const BBoolean& VehicleTryKeepSpeed, const RSset& ObstacleRelativeSpeed, const BBoolean& CruiseActive, const BBoolean& ObstacleStatusJustChanged, const BBoolean& CCInitialisationInProgress, const BBoolean& CruiseSpeedChangeInProgress, const ODset& ObstacleDistance) {
                    this->VehicleTryKeepSpeed = VehicleTryKeepSpeed;
                    this->ObstacleRelativeSpeed = ObstacleRelativeSpeed;
                    this->CruiseActive = CruiseActive;
                    this->ObstacleStatusJustChanged = ObstacleStatusJustChanged;
                    this->CCInitialisationInProgress = CCInitialisationInProgress;
                    this->CruiseSpeedChangeInProgress = CruiseSpeedChangeInProgress;
                    this->ObstacleDistance = ObstacleDistance;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_39& o1, const _ProjectionRead__check_inv_39& o2) {
                    return o1.VehicleTryKeepSpeed == (o2.VehicleTryKeepSpeed) && o1.ObstacleRelativeSpeed == (o2.ObstacleRelativeSpeed) && o1.CruiseActive == (o2.CruiseActive) && o1.ObstacleStatusJustChanged == (o2.ObstacleStatusJustChanged) && o1.CCInitialisationInProgress == (o2.CCInitialisationInProgress) && o1.CruiseSpeedChangeInProgress == (o2.CruiseSpeedChangeInProgress) && o1.ObstacleDistance == (o2.ObstacleDistance);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_39& o1, const _ProjectionRead__check_inv_39& o2) {
                    return o1.VehicleTryKeepSpeed != (o2.VehicleTryKeepSpeed) || o1.ObstacleRelativeSpeed != (o2.ObstacleRelativeSpeed) || o1.CruiseActive != (o2.CruiseActive) || o1.ObstacleStatusJustChanged != (o2.ObstacleStatusJustChanged) || o1.CCInitialisationInProgress != (o2.CCInitialisationInProgress) || o1.CruiseSpeedChangeInProgress != (o2.CruiseSpeedChangeInProgress) || o1.ObstacleDistance != (o2.ObstacleDistance);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_39& e) {
                    strm << "{";
                    strm << "VehicleTryKeepSpeed: " << e.VehicleTryKeepSpeed;
                    strm << ", ";
                    strm << "ObstacleRelativeSpeed: " << e.ObstacleRelativeSpeed;
                    strm << ", ";
                    strm << "CruiseActive: " << e.CruiseActive;
                    strm << ", ";
                    strm << "ObstacleStatusJustChanged: " << e.ObstacleStatusJustChanged;
                    strm << ", ";
                    strm << "CCInitialisationInProgress: " << e.CCInitialisationInProgress;
                    strm << ", ";
                    strm << "CruiseSpeedChangeInProgress: " << e.CruiseSpeedChangeInProgress;
                    strm << ", ";
                    strm << "ObstacleDistance: " << e.ObstacleDistance;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (VehicleTryKeepSpeed.hashCode() << 1);
                    result = 31 * result + (ObstacleRelativeSpeed.hashCode() << 1);
                    result = 31 * result + (CruiseActive.hashCode() << 1);
                    result = 31 * result + (ObstacleStatusJustChanged.hashCode() << 1);
                    result = 31 * result + (CCInitialisationInProgress.hashCode() << 1);
                    result = 31 * result + (CruiseSpeedChangeInProgress.hashCode() << 1);
                    result = 31 * result + (ObstacleDistance.hashCode() << 1);
                    return result;
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

        Cruise_finite1_deterministic_MC(const Cruise_finite1_deterministic_MC& copy) {
            this->CruiseAllowed = copy.CruiseAllowed;
            this->CruiseActive = copy.CruiseActive;
            this->VehicleAtCruiseSpeed = copy.VehicleAtCruiseSpeed;
            this->VehicleCanKeepSpeed = copy.VehicleCanKeepSpeed;
            this->VehicleTryKeepSpeed = copy.VehicleTryKeepSpeed;
            this->SpeedAboveMax = copy.SpeedAboveMax;
            this->VehicleTryKeepTimeGap = copy.VehicleTryKeepTimeGap;
            this->CruiseSpeedAtMax = copy.CruiseSpeedAtMax;
            this->ObstaclePresent = copy.ObstaclePresent;
            this->ObstacleDistance = copy.ObstacleDistance;
            this->ObstacleRelativeSpeed = copy.ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = copy.ObstacleStatusJustChanged;
            this->CCInitialisationInProgress = copy.CCInitialisationInProgress;
            this->CruiseSpeedChangeInProgress = copy.CruiseSpeedChangeInProgress;
            this->NumberOfSetCruise = copy.NumberOfSetCruise;
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
            if((CruiseAllowed.equal((BBoolean(true)))).booleanValue()) {
                for(const BBoolean& _ic_vcks_1 : (BOOL)) {
                    for(const BBoolean& _ic_csam_1 : (BOOL)) {
                        _ic_set_2 = _ic_set_2._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vcks_1, _ic_csam_1))));

                    }

                }

            }
            return _ic_set_2;
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_CCInitialisationFinished() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_3 = BSet<BTuple<BBoolean, BBoolean >>();
            if((CCInitialisationInProgress.equal((BBoolean(true)))).booleanValue()) {
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue()))).booleanValue()) {
                            _ic_set_3 = _ic_set_3._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

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
            if((CruiseSpeedChangeInProgress.equal((BBoolean(true)))).booleanValue()) {
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && ObstacleStatusJustChanged.equal((BBoolean(false))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue()))).booleanValue()) {
                            _ic_set_5 = _ic_set_5._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

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
            if((ObstaclePresent.equal((BBoolean(false)))).booleanValue()) {
                if((CruiseActive.equal((BBoolean(true)))).booleanValue()) {
                    for(const RSset& _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                        for(const ODset& _ic_od_1 : _ODset.difference((BSet<ODset >((ODset(ODset::ODnone)))))) {
                            _ic_set_21 = _ic_set_21._union(BSet<BTuple<RSset, ODset >>((BTuple<RSset, ODset >(_ic_ors_1, _ic_od_1))));

                        }

                    }

                }
            }
            return _ic_set_21;
        }

        BSet<RSset> _tr_ObstacleAppearsWhenCruiseInactive() const {
            BSet<RSset> _ic_set_22 = BSet<RSset>();
            if((ObstaclePresent.equal((BBoolean(false)))).booleanValue()) {
                if((CruiseActive.equal((BBoolean(false)))).booleanValue()) {
                    for(const RSset& _ic_ors_1 : _RSset.difference((BSet<RSset >((RSset(RSset::RSnone)))))) {
                        _ic_set_22 = _ic_set_22._union(BSet<RSset>(_ic_ors_1));

                    }

                }
            }
            return _ic_set_22;
        }

        bool _tr_ObstacleDisappears() const {
            return (ObstaclePresent.equal((BBoolean(true)))).booleanValue();
        }

        BSet<BTuple<BBoolean, BBoolean >> _tr_VehicleManageObstacle() const {
            BSet<BTuple<BBoolean, BBoolean >> _ic_set_24 = BSet<BTuple<BBoolean, BBoolean >>();
            if((ObstacleStatusJustChanged.equal((BBoolean(true)))).booleanValue()) {
                for(const BBoolean& _ic_vtks_1 : (BOOL)) {
                    for(const BBoolean& _ic_vtktg_1 : (BOOL)) {
                        if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(_ic_vtks_1.equal((BBoolean(true))).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() && (BBoolean(!ObstaclePresent.equal((BBoolean(false))).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || _ic_vtks_1.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSequal))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSneg))).booleanValue() && ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() || _ic_vtktg_1.equal((BBoolean(false))).booleanValue())).booleanValue()))).booleanValue()) {
                            _ic_set_24 = _ic_set_24._union(BSet<BTuple<BBoolean, BBoolean >>((BTuple<BBoolean, BBoolean >(_ic_vtks_1, _ic_vtktg_1))));
                        }

                    }

                }

            }
            return _ic_set_24;
        }

        bool _tr_ObstacleBecomesOld() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(ObstacleStatusJustChanged.equal((BBoolean(true))).booleanValue() && (BBoolean((BBoolean((BBoolean(VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue() || CCInitialisationInProgress.equal((BBoolean(true))).booleanValue())).booleanValue() || CruiseSpeedChangeInProgress.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!ObstacleDistance.equal((ODset(ODset::ODnone))).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODclose))).booleanValue() && ObstacleRelativeSpeed.unequal((RSset(RSset::RSpos))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean(ObstacleDistance.equal((ODset(ODset::ODveryclose))).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepTimeGap.equal((BBoolean(true))).booleanValue())).booleanValue())).booleanValue() && (BBoolean(!(BBoolean((BBoolean((BBoolean(ObstacleRelativeSpeed.equal((RSset(RSset::RSpos))).booleanValue() && ObstacleDistance.unequal((ODset(ODset::ODveryclose))).booleanValue())).booleanValue() && CCInitialisationInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() && CruiseSpeedChangeInProgress.equal((BBoolean(false))).booleanValue())).booleanValue() || VehicleTryKeepSpeed.equal((BBoolean(true))).booleanValue())).booleanValue()))).booleanValue();
        }

        _ProjectionRead_ObstacleStopsTravelSlower _projected_state_for_ObstacleStopsTravelSlower() const {
            return _ProjectionRead_ObstacleStopsTravelSlower(ObstacleRelativeSpeed,CruiseActive);
        }

        _ProjectionRead_SetCruiseSpeed _projected_state_for_SetCruiseSpeed() const {
            return _ProjectionRead_SetCruiseSpeed(CruiseActive,CruiseAllowed,SpeedAboveMax,NumberOfSetCruise);
        }

        _ProjectionRead_VehicleLeavesCruiseSpeed _projected_state_for_VehicleLeavesCruiseSpeed() const {
            return _ProjectionRead_VehicleLeavesCruiseSpeed(VehicleTryKeepSpeed,VehicleAtCruiseSpeed,VehicleCanKeepSpeed);
        }

        _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed _projected_state_for_VehicleFallsBelowMaxCruiseSpeed() const {
            return _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed(CruiseSpeedAtMax,CruiseActive,SpeedAboveMax);
        }

        _ProjectionRead_CCInitialisationFinished _projected_state_for_CCInitialisationFinished() const {
            return _ProjectionRead_CCInitialisationFinished(CCInitialisationInProgress,ObstacleStatusJustChanged,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead_VehicleReachesCruiseSpeed _projected_state_for_VehicleReachesCruiseSpeed() const {
            return _ProjectionRead_VehicleReachesCruiseSpeed(CruiseActive,VehicleAtCruiseSpeed,SpeedAboveMax);
        }

        _ProjectionRead_ObstacleAppearsWhenCruiseActive _projected_state_for_ObstacleAppearsWhenCruiseActive() const {
            return _ProjectionRead_ObstacleAppearsWhenCruiseActive(CruiseActive,ObstaclePresent);
        }

        _ProjectionRead_ObstacleStartsTravelSlower _projected_state_for_ObstacleStartsTravelSlower() const {
            return _ProjectionRead_ObstacleStartsTravelSlower(ObstacleRelativeSpeed,CruiseActive);
        }

        _ProjectionRead_CruiseBecomesNotAllowed _projected_state_for_CruiseBecomesNotAllowed() const {
            return _ProjectionRead_CruiseBecomesNotAllowed(CruiseAllowed);
        }

        _ProjectionRead_ObstacleAppearsWhenCruiseInactive _projected_state_for_ObstacleAppearsWhenCruiseInactive() const {
            return _ProjectionRead_ObstacleAppearsWhenCruiseInactive(CruiseActive,ObstaclePresent);
        }

        _ProjectionRead_CCInitialisationDelayFinished _projected_state_for_CCInitialisationDelayFinished() const {
            return _ProjectionRead_CCInitialisationDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CCInitialisationInProgress,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead_ObstacleDistanceBecomesClose _projected_state_for_ObstacleDistanceBecomesClose() const {
            return _ProjectionRead_ObstacleDistanceBecomesClose(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
        }

        _ProjectionRead_ObstacleStartsTravelFaster _projected_state_for_ObstacleStartsTravelFaster() const {
            return _ProjectionRead_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
        }

        _ProjectionRead_ExternalForcesBecomesExtreme _projected_state_for_ExternalForcesBecomesExtreme() const {
            return _ProjectionRead_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
        }

        _ProjectionRead_CruiseOff _projected_state_for_CruiseOff() const {
            return _ProjectionRead_CruiseOff(CruiseActive);
        }

        _ProjectionRead_CruiseSpeedChangeDelayFinished _projected_state_for_CruiseSpeedChangeDelayFinished() const {
            return _ProjectionRead_CruiseSpeedChangeDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead_ObstacleStopsTravelFaster _projected_state_for_ObstacleStopsTravelFaster() const {
            return _ProjectionRead_ObstacleStopsTravelFaster(ObstacleRelativeSpeed,CruiseActive);
        }

        _ProjectionRead_ObstacleDistanceBecomesVeryClose _projected_state_for_ObstacleDistanceBecomesVeryClose() const {
            return _ProjectionRead_ObstacleDistanceBecomesVeryClose(ObstacleRelativeSpeed,ObstacleDistance);
        }

        _ProjectionRead_VehicleManageObstacle _projected_state_for_VehicleManageObstacle() const {
            return _ProjectionRead_VehicleManageObstacle(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead_CruiseBecomesAllowed _projected_state_for_CruiseBecomesAllowed() const {
            return _ProjectionRead_CruiseBecomesAllowed(CruiseAllowed);
        }

        _ProjectionRead_VehicleExceedsMaxCruiseSpeed _projected_state_for_VehicleExceedsMaxCruiseSpeed() const {
            return _ProjectionRead_VehicleExceedsMaxCruiseSpeed(CruiseActive,SpeedAboveMax,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
        }

        _ProjectionRead_CruiseSpeedChangeFinished _projected_state_for_CruiseSpeedChangeFinished() const {
            return _ProjectionRead_CruiseSpeedChangeFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead_ObstacleDisappears _projected_state_for_ObstacleDisappears() const {
            return _ProjectionRead_ObstacleDisappears(CruiseActive,ObstaclePresent);
        }

        _ProjectionRead_ExternalForcesBecomesNormal _projected_state_for_ExternalForcesBecomesNormal() const {
            return _ProjectionRead_ExternalForcesBecomesNormal(CruiseActive,VehicleCanKeepSpeed);
        }

        _ProjectionRead_ObstacleBecomesOld _projected_state_for_ObstacleBecomesOld() const {
            return _ProjectionRead_ObstacleBecomesOld(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead_ObstacleDistanceBecomesBig _projected_state_for_ObstacleDistanceBecomesBig() const {
            return _ProjectionRead_ObstacleDistanceBecomesBig(ObstacleRelativeSpeed,ObstacleDistance);
        }

        _ProjectionRead__tr_ObstacleStopsTravelSlower _projected_state_for__tr_ObstacleStopsTravelSlower() const {
            return _ProjectionRead__tr_ObstacleStopsTravelSlower(ObstacleRelativeSpeed);
        }

        _ProjectionRead__tr_ObstacleDistanceBecomesClose _projected_state_for__tr_ObstacleDistanceBecomesClose() const {
            return _ProjectionRead__tr_ObstacleDistanceBecomesClose(ObstacleRelativeSpeed,CruiseActive,ObstaclePresent,ObstacleDistance);
        }

        _ProjectionRead__tr_ExternalForcesBecomesExtreme _projected_state_for__tr_ExternalForcesBecomesExtreme() const {
            return _ProjectionRead__tr_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
        }

        _ProjectionRead__tr_ObstacleStartsTravelSlower _projected_state_for__tr_ObstacleStartsTravelSlower() const {
            return _ProjectionRead__tr_ObstacleStartsTravelSlower(ObstacleRelativeSpeed);
        }

        _ProjectionRead__tr_VehicleReachesCruiseSpeed _projected_state_for__tr_VehicleReachesCruiseSpeed() const {
            return _ProjectionRead__tr_VehicleReachesCruiseSpeed(CruiseActive,VehicleAtCruiseSpeed,SpeedAboveMax);
        }

        _ProjectionRead__tr_CruiseOff _projected_state_for__tr_CruiseOff() const {
            return _ProjectionRead__tr_CruiseOff(CruiseActive);
        }

        _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed _projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed() const {
            return _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed(SpeedAboveMax);
        }

        _ProjectionRead__tr_ObstacleBecomesOld _projected_state_for__tr_ObstacleBecomesOld() const {
            return _ProjectionRead__tr_ObstacleBecomesOld(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose _projected_state_for__tr_ObstacleDistanceBecomesVeryClose() const {
            return _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose(ObstacleRelativeSpeed,ObstacleDistance);
        }

        _ProjectionRead__tr_ObstacleStopsTravelFaster _projected_state_for__tr_ObstacleStopsTravelFaster() const {
            return _ProjectionRead__tr_ObstacleStopsTravelFaster(ObstacleRelativeSpeed);
        }

        _ProjectionRead__tr_SetCruiseSpeed _projected_state_for__tr_SetCruiseSpeed() const {
            return _ProjectionRead__tr_SetCruiseSpeed(CruiseAllowed);
        }

        _ProjectionRead__tr_VehicleManageObstacle _projected_state_for__tr_VehicleManageObstacle() const {
            return _ProjectionRead__tr_VehicleManageObstacle(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__tr_CruiseBecomesAllowed _projected_state_for__tr_CruiseBecomesAllowed() const {
            return _ProjectionRead__tr_CruiseBecomesAllowed(CruiseAllowed);
        }

        _ProjectionRead__tr_ObstacleDistanceBecomesBig _projected_state_for__tr_ObstacleDistanceBecomesBig() const {
            return _ProjectionRead__tr_ObstacleDistanceBecomesBig(ObstacleRelativeSpeed,ObstacleDistance);
        }

        _ProjectionRead__tr_CruiseBecomesNotAllowed _projected_state_for__tr_CruiseBecomesNotAllowed() const {
            return _ProjectionRead__tr_CruiseBecomesNotAllowed(CruiseAllowed);
        }

        _ProjectionRead__tr_ExternalForcesBecomesNormal _projected_state_for__tr_ExternalForcesBecomesNormal() const {
            return _ProjectionRead__tr_ExternalForcesBecomesNormal(CruiseActive,VehicleCanKeepSpeed);
        }

        _ProjectionRead__tr_CruiseSpeedChangeFinished _projected_state_for__tr_CruiseSpeedChangeFinished() const {
            return _ProjectionRead__tr_CruiseSpeedChangeFinished(ObstacleStatusJustChanged,CCInitialisationInProgress,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__tr_ObstacleDisappears _projected_state_for__tr_ObstacleDisappears() const {
            return _ProjectionRead__tr_ObstacleDisappears(ObstaclePresent);
        }

        _ProjectionRead__tr_CCInitialisationFinished _projected_state_for__tr_CCInitialisationFinished() const {
            return _ProjectionRead__tr_CCInitialisationFinished(CCInitialisationInProgress,ObstacleStatusJustChanged,ObstacleDistance,ObstacleRelativeSpeed,ObstaclePresent,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__tr_CCInitialisationDelayFinished _projected_state_for__tr_CCInitialisationDelayFinished() const {
            return _ProjectionRead__tr_CCInitialisationDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CCInitialisationInProgress,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__tr_CruiseSpeedChangeDelayFinished _projected_state_for__tr_CruiseSpeedChangeDelayFinished() const {
            return _ProjectionRead__tr_CruiseSpeedChangeDelayFinished(VehicleTryKeepSpeed,ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__tr_VehicleLeavesCruiseSpeed _projected_state_for__tr_VehicleLeavesCruiseSpeed() const {
            return _ProjectionRead__tr_VehicleLeavesCruiseSpeed(VehicleTryKeepSpeed,VehicleAtCruiseSpeed,VehicleCanKeepSpeed);
        }

        _ProjectionRead__tr_ObstacleStartsTravelFaster _projected_state_for__tr_ObstacleStartsTravelFaster() const {
            return _ProjectionRead__tr_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,ObstaclePresent);
        }

        _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive _projected_state_for__tr_ObstacleAppearsWhenCruiseActive() const {
            return _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive(CruiseActive,ObstaclePresent);
        }

        _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed _projected_state_for__tr_VehicleExceedsMaxCruiseSpeed() const {
            return _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed(CruiseActive,SpeedAboveMax,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
        }

        _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive _projected_state_for__tr_ObstacleAppearsWhenCruiseInactive() const {
            return _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive(CruiseActive,ObstaclePresent);
        }

        _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() const {
            return _ProjectionRead__check_inv_18(CruiseActive,VehicleCanKeepSpeed);
        }

        _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() const {
            return _ProjectionRead__check_inv_17(CruiseActive,VehicleAtCruiseSpeed);
        }

        _ProjectionRead__check_inv_39 _projected_state_for__check_inv_39() const {
            return _ProjectionRead__check_inv_39(VehicleTryKeepSpeed,ObstacleRelativeSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() const {
            return _ProjectionRead__check_inv_16(CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__check_inv_38 _projected_state_for__check_inv_38() const {
            return _ProjectionRead__check_inv_38(ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() const {
            return _ProjectionRead__check_inv_15(CCInitialisationInProgress);
        }

        _ProjectionRead__check_inv_37 _projected_state_for__check_inv_37() const {
            return _ProjectionRead__check_inv_37(ObstacleRelativeSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__check_inv_19 _projected_state_for__check_inv_19() const {
            return _ProjectionRead__check_inv_19(VehicleTryKeepSpeed,CruiseActive);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(NumberOfSetCruise);
        }

        _ProjectionRead__check_inv_32 _projected_state_for__check_inv_32() const {
            return _ProjectionRead__check_inv_32(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        _ProjectionRead__check_inv_31 _projected_state_for__check_inv_31() const {
            return _ProjectionRead__check_inv_31(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        _ProjectionRead__check_inv_30 _projected_state_for__check_inv_30() const {
            return _ProjectionRead__check_inv_30(ObstacleRelativeSpeed,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() const {
            return _ProjectionRead__check_inv_14(ObstacleStatusJustChanged);
        }

        _ProjectionRead__check_inv_36 _projected_state_for__check_inv_36() const {
            return _ProjectionRead__check_inv_36(VehicleTryKeepSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,CruiseSpeedChangeInProgress,ObstacleDistance);
        }

        _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() const {
            return _ProjectionRead__check_inv_13(ObstacleRelativeSpeed);
        }

        _ProjectionRead__check_inv_35 _projected_state_for__check_inv_35() const {
            return _ProjectionRead__check_inv_35(VehicleTryKeepSpeed,CruiseActive,ObstacleStatusJustChanged,CCInitialisationInProgress,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() const {
            return _ProjectionRead__check_inv_12(ObstacleDistance);
        }

        _ProjectionRead__check_inv_34 _projected_state_for__check_inv_34() const {
            return _ProjectionRead__check_inv_34(VehicleAtCruiseSpeed,SpeedAboveMax);
        }

        _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() const {
            return _ProjectionRead__check_inv_11(ObstaclePresent);
        }

        _ProjectionRead__check_inv_33 _projected_state_for__check_inv_33() const {
            return _ProjectionRead__check_inv_33(CruiseActive,CruiseAllowed);
        }

        _ProjectionRead__check_inv_29 _projected_state_for__check_inv_29() const {
            return _ProjectionRead__check_inv_29(ObstacleRelativeSpeed,ObstaclePresent);
        }

        _ProjectionRead__check_inv_28 _projected_state_for__check_inv_28() const {
            return _ProjectionRead__check_inv_28(ObstaclePresent,ObstacleDistance);
        }

        _ProjectionRead__check_inv_27 _projected_state_for__check_inv_27() const {
            return _ProjectionRead__check_inv_27(ObstaclePresent,VehicleTryKeepTimeGap);
        }

        _ProjectionRead__check_inv_26 _projected_state_for__check_inv_26() const {
            return _ProjectionRead__check_inv_26(CruiseActive,CruiseSpeedChangeInProgress);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(SpeedAboveMax);
        }

        _ProjectionRead__check_inv_21 _projected_state_for__check_inv_21() const {
            return _ProjectionRead__check_inv_21(CruiseActive,VehicleTryKeepTimeGap);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(VehicleTryKeepTimeGap);
        }

        _ProjectionRead__check_inv_20 _projected_state_for__check_inv_20() const {
            return _ProjectionRead__check_inv_20(CruiseActive,NumberOfSetCruise);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(VehicleCanKeepSpeed);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(VehicleTryKeepSpeed);
        }

        _ProjectionRead__check_inv_25 _projected_state_for__check_inv_25() const {
            return _ProjectionRead__check_inv_25(CruiseActive,CCInitialisationInProgress);
        }

        _ProjectionRead__check_inv_24 _projected_state_for__check_inv_24() const {
            return _ProjectionRead__check_inv_24(CruiseActive,ObstacleStatusJustChanged);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(CruiseSpeedAtMax);
        }

        _ProjectionRead__check_inv_23 _projected_state_for__check_inv_23() const {
            return _ProjectionRead__check_inv_23(CruiseActive,ObstacleDistance);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(NumberOfSetCruise);
        }

        _ProjectionRead__check_inv_22 _projected_state_for__check_inv_22() const {
            return _ProjectionRead__check_inv_22(CruiseSpeedAtMax,CruiseActive);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(CruiseActive);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(VehicleAtCruiseSpeed);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(CruiseAllowed);
        }

        _ProjectionWrite_ObstacleStopsTravelSlower _update_for_ObstacleStopsTravelSlower() const {
            return _ProjectionWrite_ObstacleStopsTravelSlower(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
        }

        _ProjectionWrite_SetCruiseSpeed _update_for_SetCruiseSpeed() const {
            return _ProjectionWrite_SetCruiseSpeed(CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed);
        }

        _ProjectionWrite_VehicleLeavesCruiseSpeed _update_for_VehicleLeavesCruiseSpeed() const {
            return _ProjectionWrite_VehicleLeavesCruiseSpeed(VehicleAtCruiseSpeed);
        }

        _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed _update_for_VehicleFallsBelowMaxCruiseSpeed() const {
            return _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed(VehicleAtCruiseSpeed,SpeedAboveMax);
        }

        _ProjectionWrite_CCInitialisationFinished _update_for_CCInitialisationFinished() const {
            return _ProjectionWrite_CCInitialisationFinished(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
        }

        _ProjectionWrite_VehicleReachesCruiseSpeed _update_for_VehicleReachesCruiseSpeed() const {
            return _ProjectionWrite_VehicleReachesCruiseSpeed(VehicleAtCruiseSpeed);
        }

        _ProjectionWrite_ObstacleAppearsWhenCruiseActive _update_for_ObstacleAppearsWhenCruiseActive() const {
            return _ProjectionWrite_ObstacleAppearsWhenCruiseActive(ObstacleRelativeSpeed,ObstaclePresent,ObstacleStatusJustChanged,ObstacleDistance);
        }

        _ProjectionWrite_ObstacleStartsTravelSlower _update_for_ObstacleStartsTravelSlower() const {
            return _ProjectionWrite_ObstacleStartsTravelSlower(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
        }

        _ProjectionWrite_CruiseBecomesNotAllowed _update_for_CruiseBecomesNotAllowed() const {
            return _ProjectionWrite_CruiseBecomesNotAllowed(VehicleTryKeepSpeed,CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,CruiseAllowed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed,ObstacleDistance);
        }

        _ProjectionWrite_ObstacleAppearsWhenCruiseInactive _update_for_ObstacleAppearsWhenCruiseInactive() const {
            return _ProjectionWrite_ObstacleAppearsWhenCruiseInactive(ObstacleRelativeSpeed,ObstaclePresent,ObstacleDistance);
        }

        _ProjectionWrite_CCInitialisationDelayFinished _update_for_CCInitialisationDelayFinished() const {
            return _ProjectionWrite_CCInitialisationDelayFinished(CCInitialisationInProgress);
        }

        _ProjectionWrite_ObstacleDistanceBecomesClose _update_for_ObstacleDistanceBecomesClose() const {
            return _ProjectionWrite_ObstacleDistanceBecomesClose(ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        _ProjectionWrite_ObstacleStartsTravelFaster _update_for_ObstacleStartsTravelFaster() const {
            return _ProjectionWrite_ObstacleStartsTravelFaster(ObstacleRelativeSpeed,ObstacleStatusJustChanged,VehicleTryKeepTimeGap);
        }

        _ProjectionWrite_ExternalForcesBecomesExtreme _update_for_ExternalForcesBecomesExtreme() const {
            return _ProjectionWrite_ExternalForcesBecomesExtreme(VehicleCanKeepSpeed);
        }

        _ProjectionWrite_CruiseOff _update_for_CruiseOff() const {
            return _ProjectionWrite_CruiseOff(VehicleTryKeepSpeed,CruiseSpeedAtMax,CruiseActive,VehicleAtCruiseSpeed,ObstacleStatusJustChanged,CCInitialisationInProgress,NumberOfSetCruise,VehicleTryKeepTimeGap,CruiseSpeedChangeInProgress,VehicleCanKeepSpeed,ObstacleDistance);
        }

        _ProjectionWrite_CruiseSpeedChangeDelayFinished _update_for_CruiseSpeedChangeDelayFinished() const {
            return _ProjectionWrite_CruiseSpeedChangeDelayFinished(CruiseSpeedChangeInProgress);
        }

        _ProjectionWrite_ObstacleStopsTravelFaster _update_for_ObstacleStopsTravelFaster() const {
            return _ProjectionWrite_ObstacleStopsTravelFaster(ObstacleRelativeSpeed,ObstacleStatusJustChanged);
        }

        _ProjectionWrite_ObstacleDistanceBecomesVeryClose _update_for_ObstacleDistanceBecomesVeryClose() const {
            return _ProjectionWrite_ObstacleDistanceBecomesVeryClose(ObstacleStatusJustChanged,ObstacleDistance);
        }

        _ProjectionWrite_VehicleManageObstacle _update_for_VehicleManageObstacle() const {
            return _ProjectionWrite_VehicleManageObstacle(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
        }

        _ProjectionWrite_CruiseBecomesAllowed _update_for_CruiseBecomesAllowed() const {
            return _ProjectionWrite_CruiseBecomesAllowed(CruiseAllowed);
        }

        _ProjectionWrite_VehicleExceedsMaxCruiseSpeed _update_for_VehicleExceedsMaxCruiseSpeed() const {
            return _ProjectionWrite_VehicleExceedsMaxCruiseSpeed(VehicleAtCruiseSpeed,SpeedAboveMax);
        }

        _ProjectionWrite_CruiseSpeedChangeFinished _update_for_CruiseSpeedChangeFinished() const {
            return _ProjectionWrite_CruiseSpeedChangeFinished(VehicleTryKeepSpeed,VehicleTryKeepTimeGap);
        }

        _ProjectionWrite_ObstacleDisappears _update_for_ObstacleDisappears() const {
            return _ProjectionWrite_ObstacleDisappears(ObstacleRelativeSpeed,ObstaclePresent,ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        _ProjectionWrite_ExternalForcesBecomesNormal _update_for_ExternalForcesBecomesNormal() const {
            return _ProjectionWrite_ExternalForcesBecomesNormal(VehicleCanKeepSpeed);
        }

        _ProjectionWrite_ObstacleBecomesOld _update_for_ObstacleBecomesOld() const {
            return _ProjectionWrite_ObstacleBecomesOld(ObstacleStatusJustChanged);
        }

        _ProjectionWrite_ObstacleDistanceBecomesBig _update_for_ObstacleDistanceBecomesBig() const {
            return _ProjectionWrite_ObstacleDistanceBecomesBig(ObstacleStatusJustChanged,VehicleTryKeepTimeGap,ObstacleDistance);
        }

        void _apply_update_for_ObstacleStopsTravelSlower(const _ProjectionWrite_ObstacleStopsTravelSlower& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        }

        void _apply_update_for_SetCruiseSpeed(const _ProjectionWrite_SetCruiseSpeed& update) {
            this->CruiseSpeedAtMax = update.CruiseSpeedAtMax;
            this->CruiseActive = update.CruiseActive;
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->CCInitialisationInProgress = update.CCInitialisationInProgress;
            this->NumberOfSetCruise = update.NumberOfSetCruise;
            this->CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
            this->VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        }

        void _apply_update_for_VehicleLeavesCruiseSpeed(const _ProjectionWrite_VehicleLeavesCruiseSpeed& update) {
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        }

        void _apply_update_for_VehicleFallsBelowMaxCruiseSpeed(const _ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed& update) {
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
            this->SpeedAboveMax = update.SpeedAboveMax;
        }

        void _apply_update_for_CCInitialisationFinished(const _ProjectionWrite_CCInitialisationFinished& update) {
            this->VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        }

        void _apply_update_for_VehicleReachesCruiseSpeed(const _ProjectionWrite_VehicleReachesCruiseSpeed& update) {
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
        }

        void _apply_update_for_ObstacleAppearsWhenCruiseActive(const _ProjectionWrite_ObstacleAppearsWhenCruiseActive& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstaclePresent = update.ObstaclePresent;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_ObstacleStartsTravelSlower(const _ProjectionWrite_ObstacleStartsTravelSlower& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        }

        void _apply_update_for_CruiseBecomesNotAllowed(const _ProjectionWrite_CruiseBecomesNotAllowed& update) {
            this->VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
            this->CruiseSpeedAtMax = update.CruiseSpeedAtMax;
            this->CruiseActive = update.CruiseActive;
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
            this->CruiseAllowed = update.CruiseAllowed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->CCInitialisationInProgress = update.CCInitialisationInProgress;
            this->NumberOfSetCruise = update.NumberOfSetCruise;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
            this->CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
            this->VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_ObstacleAppearsWhenCruiseInactive(const _ProjectionWrite_ObstacleAppearsWhenCruiseInactive& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstaclePresent = update.ObstaclePresent;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_CCInitialisationDelayFinished(const _ProjectionWrite_CCInitialisationDelayFinished& update) {
            this->CCInitialisationInProgress = update.CCInitialisationInProgress;
        }

        void _apply_update_for_ObstacleDistanceBecomesClose(const _ProjectionWrite_ObstacleDistanceBecomesClose& update) {
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_ObstacleStartsTravelFaster(const _ProjectionWrite_ObstacleStartsTravelFaster& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        }

        void _apply_update_for_ExternalForcesBecomesExtreme(const _ProjectionWrite_ExternalForcesBecomesExtreme& update) {
            this->VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        }

        void _apply_update_for_CruiseOff(const _ProjectionWrite_CruiseOff& update) {
            this->VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
            this->CruiseSpeedAtMax = update.CruiseSpeedAtMax;
            this->CruiseActive = update.CruiseActive;
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->CCInitialisationInProgress = update.CCInitialisationInProgress;
            this->NumberOfSetCruise = update.NumberOfSetCruise;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
            this->CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
            this->VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_CruiseSpeedChangeDelayFinished(const _ProjectionWrite_CruiseSpeedChangeDelayFinished& update) {
            this->CruiseSpeedChangeInProgress = update.CruiseSpeedChangeInProgress;
        }

        void _apply_update_for_ObstacleStopsTravelFaster(const _ProjectionWrite_ObstacleStopsTravelFaster& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        }

        void _apply_update_for_ObstacleDistanceBecomesVeryClose(const _ProjectionWrite_ObstacleDistanceBecomesVeryClose& update) {
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_VehicleManageObstacle(const _ProjectionWrite_VehicleManageObstacle& update) {
            this->VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        }

        void _apply_update_for_CruiseBecomesAllowed(const _ProjectionWrite_CruiseBecomesAllowed& update) {
            this->CruiseAllowed = update.CruiseAllowed;
        }

        void _apply_update_for_VehicleExceedsMaxCruiseSpeed(const _ProjectionWrite_VehicleExceedsMaxCruiseSpeed& update) {
            this->VehicleAtCruiseSpeed = update.VehicleAtCruiseSpeed;
            this->SpeedAboveMax = update.SpeedAboveMax;
        }

        void _apply_update_for_CruiseSpeedChangeFinished(const _ProjectionWrite_CruiseSpeedChangeFinished& update) {
            this->VehicleTryKeepSpeed = update.VehicleTryKeepSpeed;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
        }

        void _apply_update_for_ObstacleDisappears(const _ProjectionWrite_ObstacleDisappears& update) {
            this->ObstacleRelativeSpeed = update.ObstacleRelativeSpeed;
            this->ObstaclePresent = update.ObstaclePresent;
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        void _apply_update_for_ExternalForcesBecomesNormal(const _ProjectionWrite_ExternalForcesBecomesNormal& update) {
            this->VehicleCanKeepSpeed = update.VehicleCanKeepSpeed;
        }

        void _apply_update_for_ObstacleBecomesOld(const _ProjectionWrite_ObstacleBecomesOld& update) {
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
        }

        void _apply_update_for_ObstacleDistanceBecomesBig(const _ProjectionWrite_ObstacleDistanceBecomesBig& update) {
            this->ObstacleStatusJustChanged = update.ObstacleStatusJustChanged;
            this->VehicleTryKeepTimeGap = update.VehicleTryKeepTimeGap;
            this->ObstacleDistance = update.ObstacleDistance;
        }

        bool _check_inv_1() const {
            return ((CruiseAllowed.isBoolean())).booleanValue();
        }

        bool _check_inv_2() const {
            return ((CruiseActive.isBoolean())).booleanValue();
        }

        bool _check_inv_3() const {
            return ((VehicleAtCruiseSpeed.isBoolean())).booleanValue();
        }

        bool _check_inv_4() const {
            return ((VehicleCanKeepSpeed.isBoolean())).booleanValue();
        }

        bool _check_inv_5() const {
            return ((VehicleTryKeepSpeed.isBoolean())).booleanValue();
        }

        bool _check_inv_6() const {
            return ((SpeedAboveMax.isBoolean())).booleanValue();
        }

        bool _check_inv_7() const {
            return ((VehicleTryKeepTimeGap.isBoolean())).booleanValue();
        }

        bool _check_inv_8() const {
            return ((CruiseSpeedAtMax.isBoolean())).booleanValue();
        }

        bool _check_inv_9() const {
            return ((NumberOfSetCruise.isNatural())).booleanValue();
        }

        bool _check_inv_10() const {
            return ((BBoolean(NumberOfSetCruise.greaterEqual((BInteger(0))).booleanValue() && NumberOfSetCruise.lessEqual((BInteger(1))).booleanValue()))).booleanValue();
        }

        bool _check_inv_11() const {
            return ((ObstaclePresent.isBoolean())).booleanValue();
        }

        bool _check_inv_12() const {
            return (_ODset.elementOf(ObstacleDistance)).booleanValue();
        }

        bool _check_inv_13() const {
            return (_RSset.elementOf(ObstacleRelativeSpeed)).booleanValue();
        }

        bool _check_inv_14() const {
            return ((ObstacleStatusJustChanged.isBoolean())).booleanValue();
        }

        bool _check_inv_15() const {
            return ((CCInitialisationInProgress.isBoolean())).booleanValue();
        }

        bool _check_inv_16() const {
            return ((CruiseSpeedChangeInProgress.isBoolean())).booleanValue();
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
            return Cruise_finite1_deterministic_MC(*this);
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
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Cruise_finite1_deterministic_MC counterExampleState;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::HashEqual>> _OpCache_CruiseBecomesNotAllowed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesNotAllowed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesNotAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesNotAllowed::HashEqual> _OpCache_tr_CruiseBecomesNotAllowed;
        std::mutex _ProjectionRead_CruiseBecomesNotAllowed_mutex;
        std::mutex _ProjectionRead__tr_CruiseBecomesNotAllowed_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::HashEqual>> _OpCache_CruiseBecomesAllowed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesAllowed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesAllowed::HashEqual> _OpCache_tr_CruiseBecomesAllowed;
        std::mutex _ProjectionRead_CruiseBecomesAllowed_mutex;
        std::mutex _ProjectionRead__tr_CruiseBecomesAllowed_mutex;

        std::unordered_map<BSet<BTuple<BBoolean, BBoolean >>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::HashEqual>, BSet<BTuple<BBoolean, BBoolean >>::SetHash, BSet<BTuple<BBoolean, BBoolean >>::SetHashEqual> _OpCache_SetCruiseSpeed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_SetCruiseSpeed,  BSet<BTuple<BBoolean, BBoolean >>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_SetCruiseSpeed::HashEqual> _OpCache_tr_SetCruiseSpeed;
        std::mutex _ProjectionRead_SetCruiseSpeed_mutex;
        std::mutex _ProjectionRead__tr_SetCruiseSpeed_mutex;

        std::unordered_map<BSet<BTuple<BBoolean, BBoolean >>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::HashEqual>, BSet<BTuple<BBoolean, BBoolean >>::SetHash, BSet<BTuple<BBoolean, BBoolean >>::SetHashEqual> _OpCache_CCInitialisationFinished;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationFinished,  BSet<BTuple<BBoolean, BBoolean >>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationFinished::HashEqual> _OpCache_tr_CCInitialisationFinished;
        std::mutex _ProjectionRead_CCInitialisationFinished_mutex;
        std::mutex _ProjectionRead__tr_CCInitialisationFinished_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::HashEqual>> _OpCache_CCInitialisationDelayFinished;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationDelayFinished, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationDelayFinished::HashEqual> _OpCache_tr_CCInitialisationDelayFinished;
        std::mutex _ProjectionRead_CCInitialisationDelayFinished_mutex;
        std::mutex _ProjectionRead__tr_CCInitialisationDelayFinished_mutex;

        std::unordered_map<BSet<BTuple<BBoolean, BBoolean >>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::HashEqual>, BSet<BTuple<BBoolean, BBoolean >>::SetHash, BSet<BTuple<BBoolean, BBoolean >>::SetHashEqual> _OpCache_CruiseSpeedChangeFinished;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeFinished,  BSet<BTuple<BBoolean, BBoolean >>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeFinished::HashEqual> _OpCache_tr_CruiseSpeedChangeFinished;
        std::mutex _ProjectionRead_CruiseSpeedChangeFinished_mutex;
        std::mutex _ProjectionRead__tr_CruiseSpeedChangeFinished_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::HashEqual>> _OpCache_CruiseSpeedChangeDelayFinished;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeDelayFinished, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeDelayFinished::HashEqual> _OpCache_tr_CruiseSpeedChangeDelayFinished;
        std::mutex _ProjectionRead_CruiseSpeedChangeDelayFinished_mutex;
        std::mutex _ProjectionRead__tr_CruiseSpeedChangeDelayFinished_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::HashEqual>> _OpCache_CruiseOff;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseOff, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseOff::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseOff::HashEqual> _OpCache_tr_CruiseOff;
        std::mutex _ProjectionRead_CruiseOff_mutex;
        std::mutex _ProjectionRead__tr_CruiseOff_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::HashEqual>> _OpCache_ExternalForcesBecomesExtreme;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesExtreme, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesExtreme::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesExtreme::HashEqual> _OpCache_tr_ExternalForcesBecomesExtreme;
        std::mutex _ProjectionRead_ExternalForcesBecomesExtreme_mutex;
        std::mutex _ProjectionRead__tr_ExternalForcesBecomesExtreme_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::HashEqual>> _OpCache_ExternalForcesBecomesNormal;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesNormal, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesNormal::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesNormal::HashEqual> _OpCache_tr_ExternalForcesBecomesNormal;
        std::mutex _ProjectionRead_ExternalForcesBecomesNormal_mutex;
        std::mutex _ProjectionRead__tr_ExternalForcesBecomesNormal_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::HashEqual>> _OpCache_VehicleLeavesCruiseSpeed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleLeavesCruiseSpeed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleLeavesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleLeavesCruiseSpeed::HashEqual> _OpCache_tr_VehicleLeavesCruiseSpeed;
        std::mutex _ProjectionRead_VehicleLeavesCruiseSpeed_mutex;
        std::mutex _ProjectionRead__tr_VehicleLeavesCruiseSpeed_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::HashEqual>> _OpCache_VehicleReachesCruiseSpeed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleReachesCruiseSpeed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleReachesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleReachesCruiseSpeed::HashEqual> _OpCache_tr_VehicleReachesCruiseSpeed;
        std::mutex _ProjectionRead_VehicleReachesCruiseSpeed_mutex;
        std::mutex _ProjectionRead__tr_VehicleReachesCruiseSpeed_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::HashEqual>> _OpCache_VehicleExceedsMaxCruiseSpeed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed::HashEqual> _OpCache_tr_VehicleExceedsMaxCruiseSpeed;
        std::mutex _ProjectionRead_VehicleExceedsMaxCruiseSpeed_mutex;
        std::mutex _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::HashEqual>> _OpCache_VehicleFallsBelowMaxCruiseSpeed;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed::HashEqual> _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed;
        std::mutex _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed_mutex;
        std::mutex _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::HashEqual>> _OpCache_ObstacleDistanceBecomesVeryClose;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose::HashEqual> _OpCache_tr_ObstacleDistanceBecomesVeryClose;
        std::mutex _ProjectionRead_ObstacleDistanceBecomesVeryClose_mutex;
        std::mutex _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::HashEqual>> _OpCache_ObstacleDistanceBecomesClose;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesClose, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesClose::HashEqual> _OpCache_tr_ObstacleDistanceBecomesClose;
        std::mutex _ProjectionRead_ObstacleDistanceBecomesClose_mutex;
        std::mutex _ProjectionRead__tr_ObstacleDistanceBecomesClose_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::HashEqual>> _OpCache_ObstacleDistanceBecomesBig;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesBig, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesBig::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesBig::HashEqual> _OpCache_tr_ObstacleDistanceBecomesBig;
        std::mutex _ProjectionRead_ObstacleDistanceBecomesBig_mutex;
        std::mutex _ProjectionRead__tr_ObstacleDistanceBecomesBig_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::HashEqual>> _OpCache_ObstacleStartsTravelFaster;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelFaster, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelFaster::HashEqual> _OpCache_tr_ObstacleStartsTravelFaster;
        std::mutex _ProjectionRead_ObstacleStartsTravelFaster_mutex;
        std::mutex _ProjectionRead__tr_ObstacleStartsTravelFaster_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::HashEqual>> _OpCache_ObstacleStopsTravelFaster;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelFaster, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelFaster::HashEqual> _OpCache_tr_ObstacleStopsTravelFaster;
        std::mutex _ProjectionRead_ObstacleStopsTravelFaster_mutex;
        std::mutex _ProjectionRead__tr_ObstacleStopsTravelFaster_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::HashEqual>> _OpCache_ObstacleStartsTravelSlower;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelSlower, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelSlower::HashEqual> _OpCache_tr_ObstacleStartsTravelSlower;
        std::mutex _ProjectionRead_ObstacleStartsTravelSlower_mutex;
        std::mutex _ProjectionRead__tr_ObstacleStartsTravelSlower_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::HashEqual>> _OpCache_ObstacleStopsTravelSlower;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelSlower, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelSlower::HashEqual> _OpCache_tr_ObstacleStopsTravelSlower;
        std::mutex _ProjectionRead_ObstacleStopsTravelSlower_mutex;
        std::mutex _ProjectionRead__tr_ObstacleStopsTravelSlower_mutex;

        std::unordered_map<BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::HashEqual>, BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >>::SetHash, BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >>::SetHashEqual> _OpCache_ObstacleAppearsWhenCruiseActive;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive,  BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive::HashEqual> _OpCache_tr_ObstacleAppearsWhenCruiseActive;
        std::mutex _ProjectionRead_ObstacleAppearsWhenCruiseActive_mutex;
        std::mutex _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive_mutex;

        std::unordered_map<BSet<Cruise_finite1_deterministic_MC::RSset>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::HashEqual>, BSet<Cruise_finite1_deterministic_MC::RSset>::SetHash, BSet<Cruise_finite1_deterministic_MC::RSset>::SetHashEqual> _OpCache_ObstacleAppearsWhenCruiseInactive;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive,  BSet<Cruise_finite1_deterministic_MC::RSset>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive::HashEqual> _OpCache_tr_ObstacleAppearsWhenCruiseInactive;
        std::mutex _ProjectionRead_ObstacleAppearsWhenCruiseInactive_mutex;
        std::mutex _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::HashEqual>> _OpCache_ObstacleDisappears;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDisappears, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDisappears::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDisappears::HashEqual> _OpCache_tr_ObstacleDisappears;
        std::mutex _ProjectionRead_ObstacleDisappears_mutex;
        std::mutex _ProjectionRead__tr_ObstacleDisappears_mutex;

        std::unordered_map<BSet<BTuple<BBoolean, BBoolean >>, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::HashEqual>, BSet<BTuple<BBoolean, BBoolean >>::SetHash, BSet<BTuple<BBoolean, BBoolean >>::SetHashEqual> _OpCache_VehicleManageObstacle;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleManageObstacle,  BSet<BTuple<BBoolean, BBoolean >>, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleManageObstacle::HashEqual> _OpCache_tr_VehicleManageObstacle;
        std::mutex _ProjectionRead_VehicleManageObstacle_mutex;
        std::mutex _ProjectionRead__tr_VehicleManageObstacle_mutex;

        std::unordered_map<bool, std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::HashEqual>> _OpCache_ObstacleBecomesOld;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleBecomesOld, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleBecomesOld::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleBecomesOld::HashEqual> _OpCache_tr_ObstacleBecomesOld;
        std::mutex _ProjectionRead_ObstacleBecomesOld_mutex;
        std::mutex _ProjectionRead__tr_ObstacleBecomesOld_mutex;

        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_1, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_1::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_2, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_2::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_3, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_3::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_4, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_4::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_5, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_5::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_6, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_6::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_7, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_7::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_8, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_8::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_9, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_9::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_10, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_10::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_11, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_11::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_11::HashEqual> _InvCache__check_inv_11;
        std::mutex _ProjectionRead__check_inv_11_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_12, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_12::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_12::HashEqual> _InvCache__check_inv_12;
        std::mutex _ProjectionRead__check_inv_12_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_13, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_13::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_13::HashEqual> _InvCache__check_inv_13;
        std::mutex _ProjectionRead__check_inv_13_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_14, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_14::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_14::HashEqual> _InvCache__check_inv_14;
        std::mutex _ProjectionRead__check_inv_14_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_15, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_15::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_15::HashEqual> _InvCache__check_inv_15;
        std::mutex _ProjectionRead__check_inv_15_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_16, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_16::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_16::HashEqual> _InvCache__check_inv_16;
        std::mutex _ProjectionRead__check_inv_16_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_17, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_17::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_17::HashEqual> _InvCache__check_inv_17;
        std::mutex _ProjectionRead__check_inv_17_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_18, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_18::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_18::HashEqual> _InvCache__check_inv_18;
        std::mutex _ProjectionRead__check_inv_18_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_19, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_19::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_19::HashEqual> _InvCache__check_inv_19;
        std::mutex _ProjectionRead__check_inv_19_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_20, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_20::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_20::HashEqual> _InvCache__check_inv_20;
        std::mutex _ProjectionRead__check_inv_20_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_21, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_21::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_21::HashEqual> _InvCache__check_inv_21;
        std::mutex _ProjectionRead__check_inv_21_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_22, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_22::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_22::HashEqual> _InvCache__check_inv_22;
        std::mutex _ProjectionRead__check_inv_22_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_23, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_23::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_23::HashEqual> _InvCache__check_inv_23;
        std::mutex _ProjectionRead__check_inv_23_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_24, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_24::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_24::HashEqual> _InvCache__check_inv_24;
        std::mutex _ProjectionRead__check_inv_24_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_25, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_25::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_25::HashEqual> _InvCache__check_inv_25;
        std::mutex _ProjectionRead__check_inv_25_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_26, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_26::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_26::HashEqual> _InvCache__check_inv_26;
        std::mutex _ProjectionRead__check_inv_26_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_27, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_27::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_27::HashEqual> _InvCache__check_inv_27;
        std::mutex _ProjectionRead__check_inv_27_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_28, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_28::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_28::HashEqual> _InvCache__check_inv_28;
        std::mutex _ProjectionRead__check_inv_28_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_29, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_29::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_29::HashEqual> _InvCache__check_inv_29;
        std::mutex _ProjectionRead__check_inv_29_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_30, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_30::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_30::HashEqual> _InvCache__check_inv_30;
        std::mutex _ProjectionRead__check_inv_30_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_31, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_31::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_31::HashEqual> _InvCache__check_inv_31;
        std::mutex _ProjectionRead__check_inv_31_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_32, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_32::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_32::HashEqual> _InvCache__check_inv_32;
        std::mutex _ProjectionRead__check_inv_32_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_33, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_33::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_33::HashEqual> _InvCache__check_inv_33;
        std::mutex _ProjectionRead__check_inv_33_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_34, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_34::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_34::HashEqual> _InvCache__check_inv_34;
        std::mutex _ProjectionRead__check_inv_34_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_35, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_35::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_35::HashEqual> _InvCache__check_inv_35;
        std::mutex _ProjectionRead__check_inv_35_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_36, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_36::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_36::HashEqual> _InvCache__check_inv_36;
        std::mutex _ProjectionRead__check_inv_36_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_37, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_37::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_37::HashEqual> _InvCache__check_inv_37;
        std::mutex _ProjectionRead__check_inv_37_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_38, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_38::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_38::HashEqual> _InvCache__check_inv_38;
        std::mutex _ProjectionRead__check_inv_38_mutex;
        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_39, bool, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_39::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_39::HashEqual> _InvCache__check_inv_39;
        std::mutex _ProjectionRead__check_inv_39_mutex;

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
                boost::asio::thread_pool workers(threads-1); // threads indicates the number of workers (without the coordinator)
                modelCheckMultiThreaded(workers);
            }
        }

        void modelCheckSingleThreaded() {
            Cruise_finite1_deterministic_MC machine = Cruise_finite1_deterministic_MC();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                Cruise_finite1_deterministic_MC state = next();

                std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(state);

                for(auto& nextState : nextStates) {
                    if(states.find(nextState) == states.end()) {
                        states.insert(nextState);
                        parents.insert({nextState, state});
                        unvisitedStates.push_back(nextState);
                        if(isDebug && states.size() % 50000 == 0) {
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

            std::atomic<bool> stopThreads(false);
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            while(!unvisitedStates.empty() && !stopThreads.load()) {
                possibleQueueChanges.fetch_add(1);
                Cruise_finite1_deterministic_MC state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
                        {
                            std::unique_lock<std::mutex> lock(mutex);
                            if(states.find(nextState) == states.end()) {
                                states.insert(nextState);
                                parents.insert({nextState, state});
                                unvisitedStates.push_back(nextState);
                                if(isDebug && states.size() % 50000 == 0) {
                                    cout << "VISITED STATES: " << states.size() << "\n";
                                    cout << "EVALUATED TRANSITIONS: " << transitions << "\n";
                                    cout << "-------------------" << "\n";
                                }
                            }
                        }
                    }

                    possibleQueueChanges.fetch_sub(1);
                    {
                        std::unique_lock<std::mutex> lock(waitMutex);
                        if (!unvisitedStates.empty() || possibleQueueChanges.load() == 0) {
                            waitCV.notify_one();
                        }
                    }


                    if(invariantViolated(state)) {
                        invariantViolatedBool = true;
                        counterExampleState = state;
                        stopThreads.store(true);
                    }

                    if(nextStates.empty()) {
                        deadlockDetected = true;
                        counterExampleState = state;
                        stopThreads.store(true);
                    }

                });

                boost::asio::post(workers, std::move(task));

                {
                    std::unique_lock<std::mutex> lock(waitMutex);
                    waitCV.wait(lock, [&] {
                        return !unvisitedStates.empty() || possibleQueueChanges == 0;
                    });
                }
            }
            workers.join();
            printResult();
        }


    private:
        Cruise_finite1_deterministic_MC next() {
            {
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
                }
                Cruise_finite1_deterministic_MC state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> generateNextStates(const Cruise_finite1_deterministic_MC& state) {
            std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual> result = std::unordered_set<Cruise_finite1_deterministic_MC, Cruise_finite1_deterministic_MC::Hash, Cruise_finite1_deterministic_MC::HashEqual>();
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesNotAllowed read__tr_CruiseBecomesNotAllowed_state = state._projected_state_for__tr_CruiseBecomesNotAllowed();
                bool _trid_1;
                auto _obj__trid_1_ptr = _OpCache_tr_CruiseBecomesNotAllowed.find(read__tr_CruiseBecomesNotAllowed_state);
                if(_obj__trid_1_ptr == _OpCache_tr_CruiseBecomesNotAllowed.end()) {
                    _trid_1 = state._tr_CruiseBecomesNotAllowed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CruiseBecomesNotAllowed_lock(_ProjectionRead__tr_CruiseBecomesNotAllowed_mutex);
                        _OpCache_tr_CruiseBecomesNotAllowed.insert({read__tr_CruiseBecomesNotAllowed_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed readState = state._projected_state_for_CruiseBecomesNotAllowed();

                    auto _OpCache_with_parameter_CruiseBecomesNotAllowed_ptr = _OpCache_CruiseBecomesNotAllowed.find(_trid_1);
                    if(_OpCache_with_parameter_CruiseBecomesNotAllowed_ptr == _OpCache_CruiseBecomesNotAllowed.end()) {
                        copiedState.CruiseBecomesNotAllowed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed writeState = copiedState._update_for_CruiseBecomesNotAllowed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::HashEqual> _OpCache_with_parameter_CruiseBecomesNotAllowed;
                        _OpCache_with_parameter_CruiseBecomesNotAllowed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_CruiseBecomesNotAllowed_lock(_ProjectionRead_CruiseBecomesNotAllowed_mutex);
                            _OpCache_CruiseBecomesNotAllowed.insert({_trid_1, _OpCache_with_parameter_CruiseBecomesNotAllowed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesNotAllowed::HashEqual> _OpCache_with_parameter_CruiseBecomesNotAllowed = _OpCache_with_parameter_CruiseBecomesNotAllowed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_CruiseBecomesNotAllowed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_CruiseBecomesNotAllowed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_CruiseBecomesNotAllowed(writeState);
                        } else {
                            copiedState.CruiseBecomesNotAllowed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesNotAllowed writeState = copiedState._update_for_CruiseBecomesNotAllowed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseBecomesNotAllowed_lock(_ProjectionRead_CruiseBecomesNotAllowed_mutex);
                                _OpCache_with_parameter_CruiseBecomesNotAllowed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "CruiseBecomesNotAllowed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseBecomesAllowed read__tr_CruiseBecomesAllowed_state = state._projected_state_for__tr_CruiseBecomesAllowed();
                bool _trid_2;
                auto _obj__trid_2_ptr = _OpCache_tr_CruiseBecomesAllowed.find(read__tr_CruiseBecomesAllowed_state);
                if(_obj__trid_2_ptr == _OpCache_tr_CruiseBecomesAllowed.end()) {
                    _trid_2 = state._tr_CruiseBecomesAllowed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CruiseBecomesAllowed_lock(_ProjectionRead__tr_CruiseBecomesAllowed_mutex);
                        _OpCache_tr_CruiseBecomesAllowed.insert({read__tr_CruiseBecomesAllowed_state, _trid_2});
                    }
                } else {
                    _trid_2 = _obj__trid_2_ptr->second;
                }
                if(_trid_2) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed readState = state._projected_state_for_CruiseBecomesAllowed();

                    auto _OpCache_with_parameter_CruiseBecomesAllowed_ptr = _OpCache_CruiseBecomesAllowed.find(_trid_2);
                    if(_OpCache_with_parameter_CruiseBecomesAllowed_ptr == _OpCache_CruiseBecomesAllowed.end()) {
                        copiedState.CruiseBecomesAllowed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed writeState = copiedState._update_for_CruiseBecomesAllowed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::HashEqual> _OpCache_with_parameter_CruiseBecomesAllowed;
                        _OpCache_with_parameter_CruiseBecomesAllowed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_CruiseBecomesAllowed_lock(_ProjectionRead_CruiseBecomesAllowed_mutex);
                            _OpCache_CruiseBecomesAllowed.insert({_trid_2, _OpCache_with_parameter_CruiseBecomesAllowed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseBecomesAllowed::HashEqual> _OpCache_with_parameter_CruiseBecomesAllowed = _OpCache_with_parameter_CruiseBecomesAllowed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_CruiseBecomesAllowed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_CruiseBecomesAllowed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_CruiseBecomesAllowed(writeState);
                        } else {
                            copiedState.CruiseBecomesAllowed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseBecomesAllowed writeState = copiedState._update_for_CruiseBecomesAllowed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseBecomesAllowed_lock(_ProjectionRead_CruiseBecomesAllowed_mutex);
                                _OpCache_with_parameter_CruiseBecomesAllowed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "CruiseBecomesAllowed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_SetCruiseSpeed read__tr_SetCruiseSpeed_state = state._projected_state_for__tr_SetCruiseSpeed();
                auto _trid_3_ptr = _OpCache_tr_SetCruiseSpeed.find(read__tr_SetCruiseSpeed_state);
                if(_trid_3_ptr == _OpCache_tr_SetCruiseSpeed.end()) {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_3 = state._tr_SetCruiseSpeed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_SetCruiseSpeed_lock(_ProjectionRead__tr_SetCruiseSpeed_mutex);
                        _OpCache_tr_SetCruiseSpeed.insert({read__tr_SetCruiseSpeed_state, _trid_3});
                    }
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed readState = state._projected_state_for_SetCruiseSpeed();

                        auto _OpCache_with_parameter_SetCruiseSpeed_ptr = _OpCache_SetCruiseSpeed.find(param);
                        if(_OpCache_with_parameter_SetCruiseSpeed_ptr == _OpCache_SetCruiseSpeed.end()) {
                            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = copiedState._update_for_SetCruiseSpeed();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::HashEqual> _OpCache_with_parameter_SetCruiseSpeed;
                            _OpCache_with_parameter_SetCruiseSpeed.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_SetCruiseSpeed_lock(_ProjectionRead_SetCruiseSpeed_mutex);
                                _OpCache_SetCruiseSpeed.insert({param, _OpCache_with_parameter_SetCruiseSpeed});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::HashEqual> _OpCache_with_parameter_SetCruiseSpeed = _OpCache_with_parameter_SetCruiseSpeed_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_SetCruiseSpeed.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_SetCruiseSpeed.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = writeState_ptr->second;
                                copiedState._apply_update_for_SetCruiseSpeed(writeState);
                            } else {
                                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = copiedState._update_for_SetCruiseSpeed();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_SetCruiseSpeed_lock(_ProjectionRead_SetCruiseSpeed_mutex);
                                    _OpCache_with_parameter_SetCruiseSpeed.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "SetCruiseSpeed";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_3 = _trid_3_ptr->second;
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed readState = state._projected_state_for_SetCruiseSpeed();

                        auto _OpCache_with_parameter_SetCruiseSpeed_ptr = _OpCache_SetCruiseSpeed.find(param);
                        if(_OpCache_with_parameter_SetCruiseSpeed_ptr == _OpCache_SetCruiseSpeed.end()) {
                            copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = copiedState._update_for_SetCruiseSpeed();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::HashEqual> _OpCache_with_parameter_SetCruiseSpeed;
                            _OpCache_with_parameter_SetCruiseSpeed.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_SetCruiseSpeed_lock(_ProjectionRead_SetCruiseSpeed_mutex);
                                _OpCache_SetCruiseSpeed.insert({param, _OpCache_with_parameter_SetCruiseSpeed});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_SetCruiseSpeed::HashEqual> _OpCache_with_parameter_SetCruiseSpeed = _OpCache_with_parameter_SetCruiseSpeed_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_SetCruiseSpeed.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_SetCruiseSpeed.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = writeState_ptr->second;
                                copiedState._apply_update_for_SetCruiseSpeed(writeState);
                            } else {
                                copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_SetCruiseSpeed writeState = copiedState._update_for_SetCruiseSpeed();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_SetCruiseSpeed_lock(_ProjectionRead_SetCruiseSpeed_mutex);
                                    _OpCache_with_parameter_SetCruiseSpeed.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "SetCruiseSpeed";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationFinished read__tr_CCInitialisationFinished_state = state._projected_state_for__tr_CCInitialisationFinished();
                auto _trid_4_ptr = _OpCache_tr_CCInitialisationFinished.find(read__tr_CCInitialisationFinished_state);
                if(_trid_4_ptr == _OpCache_tr_CCInitialisationFinished.end()) {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_4 = state._tr_CCInitialisationFinished();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CCInitialisationFinished_lock(_ProjectionRead__tr_CCInitialisationFinished_mutex);
                        _OpCache_tr_CCInitialisationFinished.insert({read__tr_CCInitialisationFinished_state, _trid_4});
                    }
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished readState = state._projected_state_for_CCInitialisationFinished();

                        auto _OpCache_with_parameter_CCInitialisationFinished_ptr = _OpCache_CCInitialisationFinished.find(param);
                        if(_OpCache_with_parameter_CCInitialisationFinished_ptr == _OpCache_CCInitialisationFinished.end()) {
                            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = copiedState._update_for_CCInitialisationFinished();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::HashEqual> _OpCache_with_parameter_CCInitialisationFinished;
                            _OpCache_with_parameter_CCInitialisationFinished.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationFinished_lock(_ProjectionRead_CCInitialisationFinished_mutex);
                                _OpCache_CCInitialisationFinished.insert({param, _OpCache_with_parameter_CCInitialisationFinished});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::HashEqual> _OpCache_with_parameter_CCInitialisationFinished = _OpCache_with_parameter_CCInitialisationFinished_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_CCInitialisationFinished.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_CCInitialisationFinished.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = writeState_ptr->second;
                                copiedState._apply_update_for_CCInitialisationFinished(writeState);
                            } else {
                                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = copiedState._update_for_CCInitialisationFinished();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationFinished_lock(_ProjectionRead_CCInitialisationFinished_mutex);
                                    _OpCache_with_parameter_CCInitialisationFinished.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "CCInitialisationFinished";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_4 = _trid_4_ptr->second;
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished readState = state._projected_state_for_CCInitialisationFinished();

                        auto _OpCache_with_parameter_CCInitialisationFinished_ptr = _OpCache_CCInitialisationFinished.find(param);
                        if(_OpCache_with_parameter_CCInitialisationFinished_ptr == _OpCache_CCInitialisationFinished.end()) {
                            copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = copiedState._update_for_CCInitialisationFinished();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::HashEqual> _OpCache_with_parameter_CCInitialisationFinished;
                            _OpCache_with_parameter_CCInitialisationFinished.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationFinished_lock(_ProjectionRead_CCInitialisationFinished_mutex);
                                _OpCache_CCInitialisationFinished.insert({param, _OpCache_with_parameter_CCInitialisationFinished});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationFinished::HashEqual> _OpCache_with_parameter_CCInitialisationFinished = _OpCache_with_parameter_CCInitialisationFinished_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_CCInitialisationFinished.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_CCInitialisationFinished.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = writeState_ptr->second;
                                copiedState._apply_update_for_CCInitialisationFinished(writeState);
                            } else {
                                copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationFinished writeState = copiedState._update_for_CCInitialisationFinished();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationFinished_lock(_ProjectionRead_CCInitialisationFinished_mutex);
                                    _OpCache_with_parameter_CCInitialisationFinished.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "CCInitialisationFinished";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CCInitialisationDelayFinished read__tr_CCInitialisationDelayFinished_state = state._projected_state_for__tr_CCInitialisationDelayFinished();
                bool _trid_5;
                auto _obj__trid_5_ptr = _OpCache_tr_CCInitialisationDelayFinished.find(read__tr_CCInitialisationDelayFinished_state);
                if(_obj__trid_5_ptr == _OpCache_tr_CCInitialisationDelayFinished.end()) {
                    _trid_5 = state._tr_CCInitialisationDelayFinished();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CCInitialisationDelayFinished_lock(_ProjectionRead__tr_CCInitialisationDelayFinished_mutex);
                        _OpCache_tr_CCInitialisationDelayFinished.insert({read__tr_CCInitialisationDelayFinished_state, _trid_5});
                    }
                } else {
                    _trid_5 = _obj__trid_5_ptr->second;
                }
                if(_trid_5) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished readState = state._projected_state_for_CCInitialisationDelayFinished();

                    auto _OpCache_with_parameter_CCInitialisationDelayFinished_ptr = _OpCache_CCInitialisationDelayFinished.find(_trid_5);
                    if(_OpCache_with_parameter_CCInitialisationDelayFinished_ptr == _OpCache_CCInitialisationDelayFinished.end()) {
                        copiedState.CCInitialisationDelayFinished();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished writeState = copiedState._update_for_CCInitialisationDelayFinished();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::HashEqual> _OpCache_with_parameter_CCInitialisationDelayFinished;
                        _OpCache_with_parameter_CCInitialisationDelayFinished.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationDelayFinished_lock(_ProjectionRead_CCInitialisationDelayFinished_mutex);
                            _OpCache_CCInitialisationDelayFinished.insert({_trid_5, _OpCache_with_parameter_CCInitialisationDelayFinished});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CCInitialisationDelayFinished::HashEqual> _OpCache_with_parameter_CCInitialisationDelayFinished = _OpCache_with_parameter_CCInitialisationDelayFinished_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_CCInitialisationDelayFinished.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_CCInitialisationDelayFinished.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished writeState = writeState_ptr->second;
                            copiedState._apply_update_for_CCInitialisationDelayFinished(writeState);
                        } else {
                            copiedState.CCInitialisationDelayFinished();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CCInitialisationDelayFinished writeState = copiedState._update_for_CCInitialisationDelayFinished();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CCInitialisationDelayFinished_lock(_ProjectionRead_CCInitialisationDelayFinished_mutex);
                                _OpCache_with_parameter_CCInitialisationDelayFinished.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "CCInitialisationDelayFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeFinished read__tr_CruiseSpeedChangeFinished_state = state._projected_state_for__tr_CruiseSpeedChangeFinished();
                auto _trid_6_ptr = _OpCache_tr_CruiseSpeedChangeFinished.find(read__tr_CruiseSpeedChangeFinished_state);
                if(_trid_6_ptr == _OpCache_tr_CruiseSpeedChangeFinished.end()) {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_6 = state._tr_CruiseSpeedChangeFinished();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CruiseSpeedChangeFinished_lock(_ProjectionRead__tr_CruiseSpeedChangeFinished_mutex);
                        _OpCache_tr_CruiseSpeedChangeFinished.insert({read__tr_CruiseSpeedChangeFinished_state, _trid_6});
                    }
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished readState = state._projected_state_for_CruiseSpeedChangeFinished();

                        auto _OpCache_with_parameter_CruiseSpeedChangeFinished_ptr = _OpCache_CruiseSpeedChangeFinished.find(param);
                        if(_OpCache_with_parameter_CruiseSpeedChangeFinished_ptr == _OpCache_CruiseSpeedChangeFinished.end()) {
                            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeFinished;
                            _OpCache_with_parameter_CruiseSpeedChangeFinished.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeFinished_lock(_ProjectionRead_CruiseSpeedChangeFinished_mutex);
                                _OpCache_CruiseSpeedChangeFinished.insert({param, _OpCache_with_parameter_CruiseSpeedChangeFinished});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeFinished = _OpCache_with_parameter_CruiseSpeedChangeFinished_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_CruiseSpeedChangeFinished.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_CruiseSpeedChangeFinished.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = writeState_ptr->second;
                                copiedState._apply_update_for_CruiseSpeedChangeFinished(writeState);
                            } else {
                                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeFinished_lock(_ProjectionRead_CruiseSpeedChangeFinished_mutex);
                                    _OpCache_with_parameter_CruiseSpeedChangeFinished.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "CruiseSpeedChangeFinished";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_6 = _trid_6_ptr->second;
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished readState = state._projected_state_for_CruiseSpeedChangeFinished();

                        auto _OpCache_with_parameter_CruiseSpeedChangeFinished_ptr = _OpCache_CruiseSpeedChangeFinished.find(param);
                        if(_OpCache_with_parameter_CruiseSpeedChangeFinished_ptr == _OpCache_CruiseSpeedChangeFinished.end()) {
                            copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeFinished;
                            _OpCache_with_parameter_CruiseSpeedChangeFinished.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeFinished_lock(_ProjectionRead_CruiseSpeedChangeFinished_mutex);
                                _OpCache_CruiseSpeedChangeFinished.insert({param, _OpCache_with_parameter_CruiseSpeedChangeFinished});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeFinished = _OpCache_with_parameter_CruiseSpeedChangeFinished_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_CruiseSpeedChangeFinished.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_CruiseSpeedChangeFinished.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = writeState_ptr->second;
                                copiedState._apply_update_for_CruiseSpeedChangeFinished(writeState);
                            } else {
                                copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeFinished writeState = copiedState._update_for_CruiseSpeedChangeFinished();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeFinished_lock(_ProjectionRead_CruiseSpeedChangeFinished_mutex);
                                    _OpCache_with_parameter_CruiseSpeedChangeFinished.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "CruiseSpeedChangeFinished";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseSpeedChangeDelayFinished read__tr_CruiseSpeedChangeDelayFinished_state = state._projected_state_for__tr_CruiseSpeedChangeDelayFinished();
                bool _trid_7;
                auto _obj__trid_7_ptr = _OpCache_tr_CruiseSpeedChangeDelayFinished.find(read__tr_CruiseSpeedChangeDelayFinished_state);
                if(_obj__trid_7_ptr == _OpCache_tr_CruiseSpeedChangeDelayFinished.end()) {
                    _trid_7 = state._tr_CruiseSpeedChangeDelayFinished();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CruiseSpeedChangeDelayFinished_lock(_ProjectionRead__tr_CruiseSpeedChangeDelayFinished_mutex);
                        _OpCache_tr_CruiseSpeedChangeDelayFinished.insert({read__tr_CruiseSpeedChangeDelayFinished_state, _trid_7});
                    }
                } else {
                    _trid_7 = _obj__trid_7_ptr->second;
                }
                if(_trid_7) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished readState = state._projected_state_for_CruiseSpeedChangeDelayFinished();

                    auto _OpCache_with_parameter_CruiseSpeedChangeDelayFinished_ptr = _OpCache_CruiseSpeedChangeDelayFinished.find(_trid_7);
                    if(_OpCache_with_parameter_CruiseSpeedChangeDelayFinished_ptr == _OpCache_CruiseSpeedChangeDelayFinished.end()) {
                        copiedState.CruiseSpeedChangeDelayFinished();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished writeState = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeDelayFinished;
                        _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeDelayFinished_lock(_ProjectionRead_CruiseSpeedChangeDelayFinished_mutex);
                            _OpCache_CruiseSpeedChangeDelayFinished.insert({_trid_7, _OpCache_with_parameter_CruiseSpeedChangeDelayFinished});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseSpeedChangeDelayFinished::HashEqual> _OpCache_with_parameter_CruiseSpeedChangeDelayFinished = _OpCache_with_parameter_CruiseSpeedChangeDelayFinished_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished writeState = writeState_ptr->second;
                            copiedState._apply_update_for_CruiseSpeedChangeDelayFinished(writeState);
                        } else {
                            copiedState.CruiseSpeedChangeDelayFinished();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseSpeedChangeDelayFinished writeState = copiedState._update_for_CruiseSpeedChangeDelayFinished();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseSpeedChangeDelayFinished_lock(_ProjectionRead_CruiseSpeedChangeDelayFinished_mutex);
                                _OpCache_with_parameter_CruiseSpeedChangeDelayFinished.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "CruiseSpeedChangeDelayFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_CruiseOff read__tr_CruiseOff_state = state._projected_state_for__tr_CruiseOff();
                bool _trid_8;
                auto _obj__trid_8_ptr = _OpCache_tr_CruiseOff.find(read__tr_CruiseOff_state);
                if(_obj__trid_8_ptr == _OpCache_tr_CruiseOff.end()) {
                    _trid_8 = state._tr_CruiseOff();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_CruiseOff_lock(_ProjectionRead__tr_CruiseOff_mutex);
                        _OpCache_tr_CruiseOff.insert({read__tr_CruiseOff_state, _trid_8});
                    }
                } else {
                    _trid_8 = _obj__trid_8_ptr->second;
                }
                if(_trid_8) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff readState = state._projected_state_for_CruiseOff();

                    auto _OpCache_with_parameter_CruiseOff_ptr = _OpCache_CruiseOff.find(_trid_8);
                    if(_OpCache_with_parameter_CruiseOff_ptr == _OpCache_CruiseOff.end()) {
                        copiedState.CruiseOff();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff writeState = copiedState._update_for_CruiseOff();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::HashEqual> _OpCache_with_parameter_CruiseOff;
                        _OpCache_with_parameter_CruiseOff.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_CruiseOff_lock(_ProjectionRead_CruiseOff_mutex);
                            _OpCache_CruiseOff.insert({_trid_8, _OpCache_with_parameter_CruiseOff});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_CruiseOff::HashEqual> _OpCache_with_parameter_CruiseOff = _OpCache_with_parameter_CruiseOff_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_CruiseOff.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_CruiseOff.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff writeState = writeState_ptr->second;
                            copiedState._apply_update_for_CruiseOff(writeState);
                        } else {
                            copiedState.CruiseOff();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_CruiseOff writeState = copiedState._update_for_CruiseOff();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_CruiseOff_lock(_ProjectionRead_CruiseOff_mutex);
                                _OpCache_with_parameter_CruiseOff.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "CruiseOff";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesExtreme read__tr_ExternalForcesBecomesExtreme_state = state._projected_state_for__tr_ExternalForcesBecomesExtreme();
                bool _trid_9;
                auto _obj__trid_9_ptr = _OpCache_tr_ExternalForcesBecomesExtreme.find(read__tr_ExternalForcesBecomesExtreme_state);
                if(_obj__trid_9_ptr == _OpCache_tr_ExternalForcesBecomesExtreme.end()) {
                    _trid_9 = state._tr_ExternalForcesBecomesExtreme();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ExternalForcesBecomesExtreme_lock(_ProjectionRead__tr_ExternalForcesBecomesExtreme_mutex);
                        _OpCache_tr_ExternalForcesBecomesExtreme.insert({read__tr_ExternalForcesBecomesExtreme_state, _trid_9});
                    }
                } else {
                    _trid_9 = _obj__trid_9_ptr->second;
                }
                if(_trid_9) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme readState = state._projected_state_for_ExternalForcesBecomesExtreme();

                    auto _OpCache_with_parameter_ExternalForcesBecomesExtreme_ptr = _OpCache_ExternalForcesBecomesExtreme.find(_trid_9);
                    if(_OpCache_with_parameter_ExternalForcesBecomesExtreme_ptr == _OpCache_ExternalForcesBecomesExtreme.end()) {
                        copiedState.ExternalForcesBecomesExtreme();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme writeState = copiedState._update_for_ExternalForcesBecomesExtreme();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::HashEqual> _OpCache_with_parameter_ExternalForcesBecomesExtreme;
                        _OpCache_with_parameter_ExternalForcesBecomesExtreme.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ExternalForcesBecomesExtreme_lock(_ProjectionRead_ExternalForcesBecomesExtreme_mutex);
                            _OpCache_ExternalForcesBecomesExtreme.insert({_trid_9, _OpCache_with_parameter_ExternalForcesBecomesExtreme});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesExtreme::HashEqual> _OpCache_with_parameter_ExternalForcesBecomesExtreme = _OpCache_with_parameter_ExternalForcesBecomesExtreme_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ExternalForcesBecomesExtreme.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ExternalForcesBecomesExtreme.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ExternalForcesBecomesExtreme(writeState);
                        } else {
                            copiedState.ExternalForcesBecomesExtreme();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesExtreme writeState = copiedState._update_for_ExternalForcesBecomesExtreme();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ExternalForcesBecomesExtreme_lock(_ProjectionRead_ExternalForcesBecomesExtreme_mutex);
                                _OpCache_with_parameter_ExternalForcesBecomesExtreme.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ExternalForcesBecomesExtreme";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ExternalForcesBecomesNormal read__tr_ExternalForcesBecomesNormal_state = state._projected_state_for__tr_ExternalForcesBecomesNormal();
                bool _trid_10;
                auto _obj__trid_10_ptr = _OpCache_tr_ExternalForcesBecomesNormal.find(read__tr_ExternalForcesBecomesNormal_state);
                if(_obj__trid_10_ptr == _OpCache_tr_ExternalForcesBecomesNormal.end()) {
                    _trid_10 = state._tr_ExternalForcesBecomesNormal();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ExternalForcesBecomesNormal_lock(_ProjectionRead__tr_ExternalForcesBecomesNormal_mutex);
                        _OpCache_tr_ExternalForcesBecomesNormal.insert({read__tr_ExternalForcesBecomesNormal_state, _trid_10});
                    }
                } else {
                    _trid_10 = _obj__trid_10_ptr->second;
                }
                if(_trid_10) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal readState = state._projected_state_for_ExternalForcesBecomesNormal();

                    auto _OpCache_with_parameter_ExternalForcesBecomesNormal_ptr = _OpCache_ExternalForcesBecomesNormal.find(_trid_10);
                    if(_OpCache_with_parameter_ExternalForcesBecomesNormal_ptr == _OpCache_ExternalForcesBecomesNormal.end()) {
                        copiedState.ExternalForcesBecomesNormal();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal writeState = copiedState._update_for_ExternalForcesBecomesNormal();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::HashEqual> _OpCache_with_parameter_ExternalForcesBecomesNormal;
                        _OpCache_with_parameter_ExternalForcesBecomesNormal.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ExternalForcesBecomesNormal_lock(_ProjectionRead_ExternalForcesBecomesNormal_mutex);
                            _OpCache_ExternalForcesBecomesNormal.insert({_trid_10, _OpCache_with_parameter_ExternalForcesBecomesNormal});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ExternalForcesBecomesNormal::HashEqual> _OpCache_with_parameter_ExternalForcesBecomesNormal = _OpCache_with_parameter_ExternalForcesBecomesNormal_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ExternalForcesBecomesNormal.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ExternalForcesBecomesNormal.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ExternalForcesBecomesNormal(writeState);
                        } else {
                            copiedState.ExternalForcesBecomesNormal();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ExternalForcesBecomesNormal writeState = copiedState._update_for_ExternalForcesBecomesNormal();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ExternalForcesBecomesNormal_lock(_ProjectionRead_ExternalForcesBecomesNormal_mutex);
                                _OpCache_with_parameter_ExternalForcesBecomesNormal.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ExternalForcesBecomesNormal";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleLeavesCruiseSpeed read__tr_VehicleLeavesCruiseSpeed_state = state._projected_state_for__tr_VehicleLeavesCruiseSpeed();
                bool _trid_11;
                auto _obj__trid_11_ptr = _OpCache_tr_VehicleLeavesCruiseSpeed.find(read__tr_VehicleLeavesCruiseSpeed_state);
                if(_obj__trid_11_ptr == _OpCache_tr_VehicleLeavesCruiseSpeed.end()) {
                    _trid_11 = state._tr_VehicleLeavesCruiseSpeed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_VehicleLeavesCruiseSpeed_lock(_ProjectionRead__tr_VehicleLeavesCruiseSpeed_mutex);
                        _OpCache_tr_VehicleLeavesCruiseSpeed.insert({read__tr_VehicleLeavesCruiseSpeed_state, _trid_11});
                    }
                } else {
                    _trid_11 = _obj__trid_11_ptr->second;
                }
                if(_trid_11) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed readState = state._projected_state_for_VehicleLeavesCruiseSpeed();

                    auto _OpCache_with_parameter_VehicleLeavesCruiseSpeed_ptr = _OpCache_VehicleLeavesCruiseSpeed.find(_trid_11);
                    if(_OpCache_with_parameter_VehicleLeavesCruiseSpeed_ptr == _OpCache_VehicleLeavesCruiseSpeed.end()) {
                        copiedState.VehicleLeavesCruiseSpeed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed writeState = copiedState._update_for_VehicleLeavesCruiseSpeed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleLeavesCruiseSpeed;
                        _OpCache_with_parameter_VehicleLeavesCruiseSpeed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_VehicleLeavesCruiseSpeed_lock(_ProjectionRead_VehicleLeavesCruiseSpeed_mutex);
                            _OpCache_VehicleLeavesCruiseSpeed.insert({_trid_11, _OpCache_with_parameter_VehicleLeavesCruiseSpeed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleLeavesCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleLeavesCruiseSpeed = _OpCache_with_parameter_VehicleLeavesCruiseSpeed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_VehicleLeavesCruiseSpeed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_VehicleLeavesCruiseSpeed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_VehicleLeavesCruiseSpeed(writeState);
                        } else {
                            copiedState.VehicleLeavesCruiseSpeed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleLeavesCruiseSpeed writeState = copiedState._update_for_VehicleLeavesCruiseSpeed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleLeavesCruiseSpeed_lock(_ProjectionRead_VehicleLeavesCruiseSpeed_mutex);
                                _OpCache_with_parameter_VehicleLeavesCruiseSpeed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "VehicleLeavesCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleReachesCruiseSpeed read__tr_VehicleReachesCruiseSpeed_state = state._projected_state_for__tr_VehicleReachesCruiseSpeed();
                bool _trid_12;
                auto _obj__trid_12_ptr = _OpCache_tr_VehicleReachesCruiseSpeed.find(read__tr_VehicleReachesCruiseSpeed_state);
                if(_obj__trid_12_ptr == _OpCache_tr_VehicleReachesCruiseSpeed.end()) {
                    _trid_12 = state._tr_VehicleReachesCruiseSpeed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_VehicleReachesCruiseSpeed_lock(_ProjectionRead__tr_VehicleReachesCruiseSpeed_mutex);
                        _OpCache_tr_VehicleReachesCruiseSpeed.insert({read__tr_VehicleReachesCruiseSpeed_state, _trid_12});
                    }
                } else {
                    _trid_12 = _obj__trid_12_ptr->second;
                }
                if(_trid_12) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed readState = state._projected_state_for_VehicleReachesCruiseSpeed();

                    auto _OpCache_with_parameter_VehicleReachesCruiseSpeed_ptr = _OpCache_VehicleReachesCruiseSpeed.find(_trid_12);
                    if(_OpCache_with_parameter_VehicleReachesCruiseSpeed_ptr == _OpCache_VehicleReachesCruiseSpeed.end()) {
                        copiedState.VehicleReachesCruiseSpeed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed writeState = copiedState._update_for_VehicleReachesCruiseSpeed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleReachesCruiseSpeed;
                        _OpCache_with_parameter_VehicleReachesCruiseSpeed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_VehicleReachesCruiseSpeed_lock(_ProjectionRead_VehicleReachesCruiseSpeed_mutex);
                            _OpCache_VehicleReachesCruiseSpeed.insert({_trid_12, _OpCache_with_parameter_VehicleReachesCruiseSpeed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleReachesCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleReachesCruiseSpeed = _OpCache_with_parameter_VehicleReachesCruiseSpeed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_VehicleReachesCruiseSpeed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_VehicleReachesCruiseSpeed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_VehicleReachesCruiseSpeed(writeState);
                        } else {
                            copiedState.VehicleReachesCruiseSpeed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleReachesCruiseSpeed writeState = copiedState._update_for_VehicleReachesCruiseSpeed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleReachesCruiseSpeed_lock(_ProjectionRead_VehicleReachesCruiseSpeed_mutex);
                                _OpCache_with_parameter_VehicleReachesCruiseSpeed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "VehicleReachesCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed read__tr_VehicleExceedsMaxCruiseSpeed_state = state._projected_state_for__tr_VehicleExceedsMaxCruiseSpeed();
                bool _trid_13;
                auto _obj__trid_13_ptr = _OpCache_tr_VehicleExceedsMaxCruiseSpeed.find(read__tr_VehicleExceedsMaxCruiseSpeed_state);
                if(_obj__trid_13_ptr == _OpCache_tr_VehicleExceedsMaxCruiseSpeed.end()) {
                    _trid_13 = state._tr_VehicleExceedsMaxCruiseSpeed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed_lock(_ProjectionRead__tr_VehicleExceedsMaxCruiseSpeed_mutex);
                        _OpCache_tr_VehicleExceedsMaxCruiseSpeed.insert({read__tr_VehicleExceedsMaxCruiseSpeed_state, _trid_13});
                    }
                } else {
                    _trid_13 = _obj__trid_13_ptr->second;
                }
                if(_trid_13) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed readState = state._projected_state_for_VehicleExceedsMaxCruiseSpeed();

                    auto _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed_ptr = _OpCache_VehicleExceedsMaxCruiseSpeed.find(_trid_13);
                    if(_OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed_ptr == _OpCache_VehicleExceedsMaxCruiseSpeed.end()) {
                        copiedState.VehicleExceedsMaxCruiseSpeed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed writeState = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed;
                        _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_VehicleExceedsMaxCruiseSpeed_lock(_ProjectionRead_VehicleExceedsMaxCruiseSpeed_mutex);
                            _OpCache_VehicleExceedsMaxCruiseSpeed.insert({_trid_13, _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleExceedsMaxCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed = _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_VehicleExceedsMaxCruiseSpeed(writeState);
                        } else {
                            copiedState.VehicleExceedsMaxCruiseSpeed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleExceedsMaxCruiseSpeed writeState = copiedState._update_for_VehicleExceedsMaxCruiseSpeed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleExceedsMaxCruiseSpeed_lock(_ProjectionRead_VehicleExceedsMaxCruiseSpeed_mutex);
                                _OpCache_with_parameter_VehicleExceedsMaxCruiseSpeed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "VehicleExceedsMaxCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed read__tr_VehicleFallsBelowMaxCruiseSpeed_state = state._projected_state_for__tr_VehicleFallsBelowMaxCruiseSpeed();
                bool _trid_14;
                auto _obj__trid_14_ptr = _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed.find(read__tr_VehicleFallsBelowMaxCruiseSpeed_state);
                if(_obj__trid_14_ptr == _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed.end()) {
                    _trid_14 = state._tr_VehicleFallsBelowMaxCruiseSpeed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed_lock(_ProjectionRead__tr_VehicleFallsBelowMaxCruiseSpeed_mutex);
                        _OpCache_tr_VehicleFallsBelowMaxCruiseSpeed.insert({read__tr_VehicleFallsBelowMaxCruiseSpeed_state, _trid_14});
                    }
                } else {
                    _trid_14 = _obj__trid_14_ptr->second;
                }
                if(_trid_14) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed readState = state._projected_state_for_VehicleFallsBelowMaxCruiseSpeed();

                    auto _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed_ptr = _OpCache_VehicleFallsBelowMaxCruiseSpeed.find(_trid_14);
                    if(_OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed_ptr == _OpCache_VehicleFallsBelowMaxCruiseSpeed.end()) {
                        copiedState.VehicleFallsBelowMaxCruiseSpeed();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed writeState = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed;
                        _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed_lock(_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed_mutex);
                            _OpCache_VehicleFallsBelowMaxCruiseSpeed.insert({_trid_14, _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed::HashEqual> _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed = _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_VehicleFallsBelowMaxCruiseSpeed(writeState);
                        } else {
                            copiedState.VehicleFallsBelowMaxCruiseSpeed();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleFallsBelowMaxCruiseSpeed writeState = copiedState._update_for_VehicleFallsBelowMaxCruiseSpeed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleFallsBelowMaxCruiseSpeed_lock(_ProjectionRead_VehicleFallsBelowMaxCruiseSpeed_mutex);
                                _OpCache_with_parameter_VehicleFallsBelowMaxCruiseSpeed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "VehicleFallsBelowMaxCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose read__tr_ObstacleDistanceBecomesVeryClose_state = state._projected_state_for__tr_ObstacleDistanceBecomesVeryClose();
                bool _trid_15;
                auto _obj__trid_15_ptr = _OpCache_tr_ObstacleDistanceBecomesVeryClose.find(read__tr_ObstacleDistanceBecomesVeryClose_state);
                if(_obj__trid_15_ptr == _OpCache_tr_ObstacleDistanceBecomesVeryClose.end()) {
                    _trid_15 = state._tr_ObstacleDistanceBecomesVeryClose();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleDistanceBecomesVeryClose_lock(_ProjectionRead__tr_ObstacleDistanceBecomesVeryClose_mutex);
                        _OpCache_tr_ObstacleDistanceBecomesVeryClose.insert({read__tr_ObstacleDistanceBecomesVeryClose_state, _trid_15});
                    }
                } else {
                    _trid_15 = _obj__trid_15_ptr->second;
                }
                if(_trid_15) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose readState = state._projected_state_for_ObstacleDistanceBecomesVeryClose();

                    auto _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose_ptr = _OpCache_ObstacleDistanceBecomesVeryClose.find(_trid_15);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesVeryClose_ptr == _OpCache_ObstacleDistanceBecomesVeryClose.end()) {
                        copiedState.ObstacleDistanceBecomesVeryClose();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose writeState = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose;
                        _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesVeryClose_lock(_ProjectionRead_ObstacleDistanceBecomesVeryClose_mutex);
                            _OpCache_ObstacleDistanceBecomesVeryClose.insert({_trid_15, _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesVeryClose::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose = _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleDistanceBecomesVeryClose(writeState);
                        } else {
                            copiedState.ObstacleDistanceBecomesVeryClose();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesVeryClose writeState = copiedState._update_for_ObstacleDistanceBecomesVeryClose();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesVeryClose_lock(_ProjectionRead_ObstacleDistanceBecomesVeryClose_mutex);
                                _OpCache_with_parameter_ObstacleDistanceBecomesVeryClose.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesVeryClose";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesClose read__tr_ObstacleDistanceBecomesClose_state = state._projected_state_for__tr_ObstacleDistanceBecomesClose();
                bool _trid_16;
                auto _obj__trid_16_ptr = _OpCache_tr_ObstacleDistanceBecomesClose.find(read__tr_ObstacleDistanceBecomesClose_state);
                if(_obj__trid_16_ptr == _OpCache_tr_ObstacleDistanceBecomesClose.end()) {
                    _trid_16 = state._tr_ObstacleDistanceBecomesClose();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleDistanceBecomesClose_lock(_ProjectionRead__tr_ObstacleDistanceBecomesClose_mutex);
                        _OpCache_tr_ObstacleDistanceBecomesClose.insert({read__tr_ObstacleDistanceBecomesClose_state, _trid_16});
                    }
                } else {
                    _trid_16 = _obj__trid_16_ptr->second;
                }
                if(_trid_16) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose readState = state._projected_state_for_ObstacleDistanceBecomesClose();

                    auto _OpCache_with_parameter_ObstacleDistanceBecomesClose_ptr = _OpCache_ObstacleDistanceBecomesClose.find(_trid_16);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesClose_ptr == _OpCache_ObstacleDistanceBecomesClose.end()) {
                        copiedState.ObstacleDistanceBecomesClose();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose writeState = copiedState._update_for_ObstacleDistanceBecomesClose();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesClose;
                        _OpCache_with_parameter_ObstacleDistanceBecomesClose.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesClose_lock(_ProjectionRead_ObstacleDistanceBecomesClose_mutex);
                            _OpCache_ObstacleDistanceBecomesClose.insert({_trid_16, _OpCache_with_parameter_ObstacleDistanceBecomesClose});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesClose::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesClose = _OpCache_with_parameter_ObstacleDistanceBecomesClose_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleDistanceBecomesClose.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleDistanceBecomesClose.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleDistanceBecomesClose(writeState);
                        } else {
                            copiedState.ObstacleDistanceBecomesClose();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesClose writeState = copiedState._update_for_ObstacleDistanceBecomesClose();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesClose_lock(_ProjectionRead_ObstacleDistanceBecomesClose_mutex);
                                _OpCache_with_parameter_ObstacleDistanceBecomesClose.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesClose";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDistanceBecomesBig read__tr_ObstacleDistanceBecomesBig_state = state._projected_state_for__tr_ObstacleDistanceBecomesBig();
                bool _trid_17;
                auto _obj__trid_17_ptr = _OpCache_tr_ObstacleDistanceBecomesBig.find(read__tr_ObstacleDistanceBecomesBig_state);
                if(_obj__trid_17_ptr == _OpCache_tr_ObstacleDistanceBecomesBig.end()) {
                    _trid_17 = state._tr_ObstacleDistanceBecomesBig();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleDistanceBecomesBig_lock(_ProjectionRead__tr_ObstacleDistanceBecomesBig_mutex);
                        _OpCache_tr_ObstacleDistanceBecomesBig.insert({read__tr_ObstacleDistanceBecomesBig_state, _trid_17});
                    }
                } else {
                    _trid_17 = _obj__trid_17_ptr->second;
                }
                if(_trid_17) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig readState = state._projected_state_for_ObstacleDistanceBecomesBig();

                    auto _OpCache_with_parameter_ObstacleDistanceBecomesBig_ptr = _OpCache_ObstacleDistanceBecomesBig.find(_trid_17);
                    if(_OpCache_with_parameter_ObstacleDistanceBecomesBig_ptr == _OpCache_ObstacleDistanceBecomesBig.end()) {
                        copiedState.ObstacleDistanceBecomesBig();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig writeState = copiedState._update_for_ObstacleDistanceBecomesBig();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesBig;
                        _OpCache_with_parameter_ObstacleDistanceBecomesBig.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesBig_lock(_ProjectionRead_ObstacleDistanceBecomesBig_mutex);
                            _OpCache_ObstacleDistanceBecomesBig.insert({_trid_17, _OpCache_with_parameter_ObstacleDistanceBecomesBig});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDistanceBecomesBig::HashEqual> _OpCache_with_parameter_ObstacleDistanceBecomesBig = _OpCache_with_parameter_ObstacleDistanceBecomesBig_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleDistanceBecomesBig.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleDistanceBecomesBig.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleDistanceBecomesBig(writeState);
                        } else {
                            copiedState.ObstacleDistanceBecomesBig();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDistanceBecomesBig writeState = copiedState._update_for_ObstacleDistanceBecomesBig();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleDistanceBecomesBig_lock(_ProjectionRead_ObstacleDistanceBecomesBig_mutex);
                                _OpCache_with_parameter_ObstacleDistanceBecomesBig.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesBig";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelFaster read__tr_ObstacleStartsTravelFaster_state = state._projected_state_for__tr_ObstacleStartsTravelFaster();
                bool _trid_18;
                auto _obj__trid_18_ptr = _OpCache_tr_ObstacleStartsTravelFaster.find(read__tr_ObstacleStartsTravelFaster_state);
                if(_obj__trid_18_ptr == _OpCache_tr_ObstacleStartsTravelFaster.end()) {
                    _trid_18 = state._tr_ObstacleStartsTravelFaster();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleStartsTravelFaster_lock(_ProjectionRead__tr_ObstacleStartsTravelFaster_mutex);
                        _OpCache_tr_ObstacleStartsTravelFaster.insert({read__tr_ObstacleStartsTravelFaster_state, _trid_18});
                    }
                } else {
                    _trid_18 = _obj__trid_18_ptr->second;
                }
                if(_trid_18) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster readState = state._projected_state_for_ObstacleStartsTravelFaster();

                    auto _OpCache_with_parameter_ObstacleStartsTravelFaster_ptr = _OpCache_ObstacleStartsTravelFaster.find(_trid_18);
                    if(_OpCache_with_parameter_ObstacleStartsTravelFaster_ptr == _OpCache_ObstacleStartsTravelFaster.end()) {
                        copiedState.ObstacleStartsTravelFaster();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster writeState = copiedState._update_for_ObstacleStartsTravelFaster();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::HashEqual> _OpCache_with_parameter_ObstacleStartsTravelFaster;
                        _OpCache_with_parameter_ObstacleStartsTravelFaster.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleStartsTravelFaster_lock(_ProjectionRead_ObstacleStartsTravelFaster_mutex);
                            _OpCache_ObstacleStartsTravelFaster.insert({_trid_18, _OpCache_with_parameter_ObstacleStartsTravelFaster});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelFaster::HashEqual> _OpCache_with_parameter_ObstacleStartsTravelFaster = _OpCache_with_parameter_ObstacleStartsTravelFaster_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleStartsTravelFaster.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleStartsTravelFaster.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleStartsTravelFaster(writeState);
                        } else {
                            copiedState.ObstacleStartsTravelFaster();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelFaster writeState = copiedState._update_for_ObstacleStartsTravelFaster();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleStartsTravelFaster_lock(_ProjectionRead_ObstacleStartsTravelFaster_mutex);
                                _OpCache_with_parameter_ObstacleStartsTravelFaster.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleStartsTravelFaster";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelFaster read__tr_ObstacleStopsTravelFaster_state = state._projected_state_for__tr_ObstacleStopsTravelFaster();
                bool _trid_19;
                auto _obj__trid_19_ptr = _OpCache_tr_ObstacleStopsTravelFaster.find(read__tr_ObstacleStopsTravelFaster_state);
                if(_obj__trid_19_ptr == _OpCache_tr_ObstacleStopsTravelFaster.end()) {
                    _trid_19 = state._tr_ObstacleStopsTravelFaster();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleStopsTravelFaster_lock(_ProjectionRead__tr_ObstacleStopsTravelFaster_mutex);
                        _OpCache_tr_ObstacleStopsTravelFaster.insert({read__tr_ObstacleStopsTravelFaster_state, _trid_19});
                    }
                } else {
                    _trid_19 = _obj__trid_19_ptr->second;
                }
                if(_trid_19) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster readState = state._projected_state_for_ObstacleStopsTravelFaster();

                    auto _OpCache_with_parameter_ObstacleStopsTravelFaster_ptr = _OpCache_ObstacleStopsTravelFaster.find(_trid_19);
                    if(_OpCache_with_parameter_ObstacleStopsTravelFaster_ptr == _OpCache_ObstacleStopsTravelFaster.end()) {
                        copiedState.ObstacleStopsTravelFaster();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster writeState = copiedState._update_for_ObstacleStopsTravelFaster();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::HashEqual> _OpCache_with_parameter_ObstacleStopsTravelFaster;
                        _OpCache_with_parameter_ObstacleStopsTravelFaster.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleStopsTravelFaster_lock(_ProjectionRead_ObstacleStopsTravelFaster_mutex);
                            _OpCache_ObstacleStopsTravelFaster.insert({_trid_19, _OpCache_with_parameter_ObstacleStopsTravelFaster});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelFaster::HashEqual> _OpCache_with_parameter_ObstacleStopsTravelFaster = _OpCache_with_parameter_ObstacleStopsTravelFaster_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleStopsTravelFaster.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleStopsTravelFaster.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleStopsTravelFaster(writeState);
                        } else {
                            copiedState.ObstacleStopsTravelFaster();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelFaster writeState = copiedState._update_for_ObstacleStopsTravelFaster();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleStopsTravelFaster_lock(_ProjectionRead_ObstacleStopsTravelFaster_mutex);
                                _OpCache_with_parameter_ObstacleStopsTravelFaster.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleStopsTravelFaster";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStartsTravelSlower read__tr_ObstacleStartsTravelSlower_state = state._projected_state_for__tr_ObstacleStartsTravelSlower();
                bool _trid_20;
                auto _obj__trid_20_ptr = _OpCache_tr_ObstacleStartsTravelSlower.find(read__tr_ObstacleStartsTravelSlower_state);
                if(_obj__trid_20_ptr == _OpCache_tr_ObstacleStartsTravelSlower.end()) {
                    _trid_20 = state._tr_ObstacleStartsTravelSlower();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleStartsTravelSlower_lock(_ProjectionRead__tr_ObstacleStartsTravelSlower_mutex);
                        _OpCache_tr_ObstacleStartsTravelSlower.insert({read__tr_ObstacleStartsTravelSlower_state, _trid_20});
                    }
                } else {
                    _trid_20 = _obj__trid_20_ptr->second;
                }
                if(_trid_20) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower readState = state._projected_state_for_ObstacleStartsTravelSlower();

                    auto _OpCache_with_parameter_ObstacleStartsTravelSlower_ptr = _OpCache_ObstacleStartsTravelSlower.find(_trid_20);
                    if(_OpCache_with_parameter_ObstacleStartsTravelSlower_ptr == _OpCache_ObstacleStartsTravelSlower.end()) {
                        copiedState.ObstacleStartsTravelSlower();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower writeState = copiedState._update_for_ObstacleStartsTravelSlower();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::HashEqual> _OpCache_with_parameter_ObstacleStartsTravelSlower;
                        _OpCache_with_parameter_ObstacleStartsTravelSlower.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleStartsTravelSlower_lock(_ProjectionRead_ObstacleStartsTravelSlower_mutex);
                            _OpCache_ObstacleStartsTravelSlower.insert({_trid_20, _OpCache_with_parameter_ObstacleStartsTravelSlower});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStartsTravelSlower::HashEqual> _OpCache_with_parameter_ObstacleStartsTravelSlower = _OpCache_with_parameter_ObstacleStartsTravelSlower_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleStartsTravelSlower.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleStartsTravelSlower.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleStartsTravelSlower(writeState);
                        } else {
                            copiedState.ObstacleStartsTravelSlower();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStartsTravelSlower writeState = copiedState._update_for_ObstacleStartsTravelSlower();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleStartsTravelSlower_lock(_ProjectionRead_ObstacleStartsTravelSlower_mutex);
                                _OpCache_with_parameter_ObstacleStartsTravelSlower.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleStartsTravelSlower";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleStopsTravelSlower read__tr_ObstacleStopsTravelSlower_state = state._projected_state_for__tr_ObstacleStopsTravelSlower();
                bool _trid_21;
                auto _obj__trid_21_ptr = _OpCache_tr_ObstacleStopsTravelSlower.find(read__tr_ObstacleStopsTravelSlower_state);
                if(_obj__trid_21_ptr == _OpCache_tr_ObstacleStopsTravelSlower.end()) {
                    _trid_21 = state._tr_ObstacleStopsTravelSlower();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleStopsTravelSlower_lock(_ProjectionRead__tr_ObstacleStopsTravelSlower_mutex);
                        _OpCache_tr_ObstacleStopsTravelSlower.insert({read__tr_ObstacleStopsTravelSlower_state, _trid_21});
                    }
                } else {
                    _trid_21 = _obj__trid_21_ptr->second;
                }
                if(_trid_21) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower readState = state._projected_state_for_ObstacleStopsTravelSlower();

                    auto _OpCache_with_parameter_ObstacleStopsTravelSlower_ptr = _OpCache_ObstacleStopsTravelSlower.find(_trid_21);
                    if(_OpCache_with_parameter_ObstacleStopsTravelSlower_ptr == _OpCache_ObstacleStopsTravelSlower.end()) {
                        copiedState.ObstacleStopsTravelSlower();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower writeState = copiedState._update_for_ObstacleStopsTravelSlower();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::HashEqual> _OpCache_with_parameter_ObstacleStopsTravelSlower;
                        _OpCache_with_parameter_ObstacleStopsTravelSlower.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleStopsTravelSlower_lock(_ProjectionRead_ObstacleStopsTravelSlower_mutex);
                            _OpCache_ObstacleStopsTravelSlower.insert({_trid_21, _OpCache_with_parameter_ObstacleStopsTravelSlower});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleStopsTravelSlower::HashEqual> _OpCache_with_parameter_ObstacleStopsTravelSlower = _OpCache_with_parameter_ObstacleStopsTravelSlower_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleStopsTravelSlower.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleStopsTravelSlower.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleStopsTravelSlower(writeState);
                        } else {
                            copiedState.ObstacleStopsTravelSlower();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleStopsTravelSlower writeState = copiedState._update_for_ObstacleStopsTravelSlower();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleStopsTravelSlower_lock(_ProjectionRead_ObstacleStopsTravelSlower_mutex);
                                _OpCache_with_parameter_ObstacleStopsTravelSlower.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleStopsTravelSlower";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive read__tr_ObstacleAppearsWhenCruiseActive_state = state._projected_state_for__tr_ObstacleAppearsWhenCruiseActive();
                auto _trid_22_ptr = _OpCache_tr_ObstacleAppearsWhenCruiseActive.find(read__tr_ObstacleAppearsWhenCruiseActive_state);
                if(_trid_22_ptr == _OpCache_tr_ObstacleAppearsWhenCruiseActive.end()) {
                    BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleAppearsWhenCruiseActive_lock(_ProjectionRead__tr_ObstacleAppearsWhenCruiseActive_mutex);
                        _OpCache_tr_ObstacleAppearsWhenCruiseActive.insert({read__tr_ObstacleAppearsWhenCruiseActive_state, _trid_22});
                    }
                    for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
                        Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
                        Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive readState = state._projected_state_for_ObstacleAppearsWhenCruiseActive();

                        auto _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr = _OpCache_ObstacleAppearsWhenCruiseActive.find(param);
                        if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr == _OpCache_ObstacleAppearsWhenCruiseActive.end()) {
                            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive;
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseActive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseActive_mutex);
                                _OpCache_ObstacleAppearsWhenCruiseActive.insert({param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = writeState_ptr->second;
                                copiedState._apply_update_for_ObstacleAppearsWhenCruiseActive(writeState);
                            } else {
                                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseActive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseActive_mutex);
                                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseActive";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22 = _trid_22_ptr->second;
                    for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
                        Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
                        Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive readState = state._projected_state_for_ObstacleAppearsWhenCruiseActive();

                        auto _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr = _OpCache_ObstacleAppearsWhenCruiseActive.find(param);
                        if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr == _OpCache_ObstacleAppearsWhenCruiseActive.end()) {
                            copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive;
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseActive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseActive_mutex);
                                _OpCache_ObstacleAppearsWhenCruiseActive.insert({param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseActive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = writeState_ptr->second;
                                copiedState._apply_update_for_ObstacleAppearsWhenCruiseActive(writeState);
                            } else {
                                copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseActive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseActive();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseActive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseActive_mutex);
                                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseActive.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseActive";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive read__tr_ObstacleAppearsWhenCruiseInactive_state = state._projected_state_for__tr_ObstacleAppearsWhenCruiseInactive();
                auto _trid_23_ptr = _OpCache_tr_ObstacleAppearsWhenCruiseInactive.find(read__tr_ObstacleAppearsWhenCruiseInactive_state);
                if(_trid_23_ptr == _OpCache_tr_ObstacleAppearsWhenCruiseInactive.end()) {
                    BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive_lock(_ProjectionRead__tr_ObstacleAppearsWhenCruiseInactive_mutex);
                        _OpCache_tr_ObstacleAppearsWhenCruiseInactive.insert({read__tr_ObstacleAppearsWhenCruiseInactive_state, _trid_23});
                    }
                    for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
                        Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive readState = state._projected_state_for_ObstacleAppearsWhenCruiseInactive();

                        auto _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr = _OpCache_ObstacleAppearsWhenCruiseInactive.find(param);
                        if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr == _OpCache_ObstacleAppearsWhenCruiseInactive.end()) {
                            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive;
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseInactive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseInactive_mutex);
                                _OpCache_ObstacleAppearsWhenCruiseInactive.insert({param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = writeState_ptr->second;
                                copiedState._apply_update_for_ObstacleAppearsWhenCruiseInactive(writeState);
                            } else {
                                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseInactive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseInactive_mutex);
                                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseInactive";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23 = _trid_23_ptr->second;
                    for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
                        Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive readState = state._projected_state_for_ObstacleAppearsWhenCruiseInactive();

                        auto _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr = _OpCache_ObstacleAppearsWhenCruiseInactive.find(param);
                        if(_OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr == _OpCache_ObstacleAppearsWhenCruiseInactive.end()) {
                            copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive;
                            _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseInactive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseInactive_mutex);
                                _OpCache_ObstacleAppearsWhenCruiseInactive.insert({param, _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleAppearsWhenCruiseInactive::HashEqual> _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = writeState_ptr->second;
                                copiedState._apply_update_for_ObstacleAppearsWhenCruiseInactive(writeState);
                            } else {
                                copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleAppearsWhenCruiseInactive writeState = copiedState._update_for_ObstacleAppearsWhenCruiseInactive();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_ObstacleAppearsWhenCruiseInactive_lock(_ProjectionRead_ObstacleAppearsWhenCruiseInactive_mutex);
                                    _OpCache_with_parameter_ObstacleAppearsWhenCruiseInactive.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseInactive";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleDisappears read__tr_ObstacleDisappears_state = state._projected_state_for__tr_ObstacleDisappears();
                bool _trid_24;
                auto _obj__trid_24_ptr = _OpCache_tr_ObstacleDisappears.find(read__tr_ObstacleDisappears_state);
                if(_obj__trid_24_ptr == _OpCache_tr_ObstacleDisappears.end()) {
                    _trid_24 = state._tr_ObstacleDisappears();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleDisappears_lock(_ProjectionRead__tr_ObstacleDisappears_mutex);
                        _OpCache_tr_ObstacleDisappears.insert({read__tr_ObstacleDisappears_state, _trid_24});
                    }
                } else {
                    _trid_24 = _obj__trid_24_ptr->second;
                }
                if(_trid_24) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears readState = state._projected_state_for_ObstacleDisappears();

                    auto _OpCache_with_parameter_ObstacleDisappears_ptr = _OpCache_ObstacleDisappears.find(_trid_24);
                    if(_OpCache_with_parameter_ObstacleDisappears_ptr == _OpCache_ObstacleDisappears.end()) {
                        copiedState.ObstacleDisappears();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears writeState = copiedState._update_for_ObstacleDisappears();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::HashEqual> _OpCache_with_parameter_ObstacleDisappears;
                        _OpCache_with_parameter_ObstacleDisappears.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleDisappears_lock(_ProjectionRead_ObstacleDisappears_mutex);
                            _OpCache_ObstacleDisappears.insert({_trid_24, _OpCache_with_parameter_ObstacleDisappears});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleDisappears::HashEqual> _OpCache_with_parameter_ObstacleDisappears = _OpCache_with_parameter_ObstacleDisappears_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleDisappears.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleDisappears.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleDisappears(writeState);
                        } else {
                            copiedState.ObstacleDisappears();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleDisappears writeState = copiedState._update_for_ObstacleDisappears();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleDisappears_lock(_ProjectionRead_ObstacleDisappears_mutex);
                                _OpCache_with_parameter_ObstacleDisappears.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleDisappears";
                    result.insert(copiedState);
                    transitions += 1;
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_VehicleManageObstacle read__tr_VehicleManageObstacle_state = state._projected_state_for__tr_VehicleManageObstacle();
                auto _trid_25_ptr = _OpCache_tr_VehicleManageObstacle.find(read__tr_VehicleManageObstacle_state);
                if(_trid_25_ptr == _OpCache_tr_VehicleManageObstacle.end()) {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_25 = state._tr_VehicleManageObstacle();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_VehicleManageObstacle_lock(_ProjectionRead__tr_VehicleManageObstacle_mutex);
                        _OpCache_tr_VehicleManageObstacle.insert({read__tr_VehicleManageObstacle_state, _trid_25});
                    }
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle readState = state._projected_state_for_VehicleManageObstacle();

                        auto _OpCache_with_parameter_VehicleManageObstacle_ptr = _OpCache_VehicleManageObstacle.find(param);
                        if(_OpCache_with_parameter_VehicleManageObstacle_ptr == _OpCache_VehicleManageObstacle.end()) {
                            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = copiedState._update_for_VehicleManageObstacle();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::HashEqual> _OpCache_with_parameter_VehicleManageObstacle;
                            _OpCache_with_parameter_VehicleManageObstacle.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleManageObstacle_lock(_ProjectionRead_VehicleManageObstacle_mutex);
                                _OpCache_VehicleManageObstacle.insert({param, _OpCache_with_parameter_VehicleManageObstacle});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::HashEqual> _OpCache_with_parameter_VehicleManageObstacle = _OpCache_with_parameter_VehicleManageObstacle_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_VehicleManageObstacle.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_VehicleManageObstacle.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = writeState_ptr->second;
                                copiedState._apply_update_for_VehicleManageObstacle(writeState);
                            } else {
                                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = copiedState._update_for_VehicleManageObstacle();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_VehicleManageObstacle_lock(_ProjectionRead_VehicleManageObstacle_mutex);
                                    _OpCache_with_parameter_VehicleManageObstacle.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "VehicleManageObstacle";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<BTuple<BBoolean, BBoolean >> _trid_25 = _trid_25_ptr->second;
                    for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
                        BBoolean _tmp_1 = param.projection2();
                        BBoolean _tmp_2 = param.projection1();

                        Cruise_finite1_deterministic_MC copiedState = state._copy();
                        Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle readState = state._projected_state_for_VehicleManageObstacle();

                        auto _OpCache_with_parameter_VehicleManageObstacle_ptr = _OpCache_VehicleManageObstacle.find(param);
                        if(_OpCache_with_parameter_VehicleManageObstacle_ptr == _OpCache_VehicleManageObstacle.end()) {
                            copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = copiedState._update_for_VehicleManageObstacle();
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::HashEqual> _OpCache_with_parameter_VehicleManageObstacle;
                            _OpCache_with_parameter_VehicleManageObstacle.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_VehicleManageObstacle_lock(_ProjectionRead_VehicleManageObstacle_mutex);
                                _OpCache_VehicleManageObstacle.insert({param, _OpCache_with_parameter_VehicleManageObstacle});
                            }

                        } else {
                            std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_VehicleManageObstacle::HashEqual> _OpCache_with_parameter_VehicleManageObstacle = _OpCache_with_parameter_VehicleManageObstacle_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_VehicleManageObstacle.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_VehicleManageObstacle.end()) {
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = writeState_ptr->second;
                                copiedState._apply_update_for_VehicleManageObstacle(writeState);
                            } else {
                                copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                                Cruise_finite1_deterministic_MC::_ProjectionWrite_VehicleManageObstacle writeState = copiedState._update_for_VehicleManageObstacle();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_VehicleManageObstacle_lock(_ProjectionRead_VehicleManageObstacle_mutex);
                                    _OpCache_with_parameter_VehicleManageObstacle.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "VehicleManageObstacle";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Cruise_finite1_deterministic_MC::_ProjectionRead__tr_ObstacleBecomesOld read__tr_ObstacleBecomesOld_state = state._projected_state_for__tr_ObstacleBecomesOld();
                bool _trid_26;
                auto _obj__trid_26_ptr = _OpCache_tr_ObstacleBecomesOld.find(read__tr_ObstacleBecomesOld_state);
                if(_obj__trid_26_ptr == _OpCache_tr_ObstacleBecomesOld.end()) {
                    _trid_26 = state._tr_ObstacleBecomesOld();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_ObstacleBecomesOld_lock(_ProjectionRead__tr_ObstacleBecomesOld_mutex);
                        _OpCache_tr_ObstacleBecomesOld.insert({read__tr_ObstacleBecomesOld_state, _trid_26});
                    }
                } else {
                    _trid_26 = _obj__trid_26_ptr->second;
                }
                if(_trid_26) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld readState = state._projected_state_for_ObstacleBecomesOld();

                    auto _OpCache_with_parameter_ObstacleBecomesOld_ptr = _OpCache_ObstacleBecomesOld.find(_trid_26);
                    if(_OpCache_with_parameter_ObstacleBecomesOld_ptr == _OpCache_ObstacleBecomesOld.end()) {
                        copiedState.ObstacleBecomesOld();
                        Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld writeState = copiedState._update_for_ObstacleBecomesOld();
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::HashEqual> _OpCache_with_parameter_ObstacleBecomesOld;
                        _OpCache_with_parameter_ObstacleBecomesOld.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_ObstacleBecomesOld_lock(_ProjectionRead_ObstacleBecomesOld_mutex);
                            _OpCache_ObstacleBecomesOld.insert({_trid_26, _OpCache_with_parameter_ObstacleBecomesOld});
                        }

                    } else {
                        std::unordered_map<Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::Hash, Cruise_finite1_deterministic_MC::_ProjectionRead_ObstacleBecomesOld::HashEqual> _OpCache_with_parameter_ObstacleBecomesOld = _OpCache_with_parameter_ObstacleBecomesOld_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_ObstacleBecomesOld.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_ObstacleBecomesOld.end()) {
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld writeState = writeState_ptr->second;
                            copiedState._apply_update_for_ObstacleBecomesOld(writeState);
                        } else {
                            copiedState.ObstacleBecomesOld();
                            Cruise_finite1_deterministic_MC::_ProjectionWrite_ObstacleBecomesOld writeState = copiedState._update_for_ObstacleBecomesOld();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_ObstacleBecomesOld_lock(_ProjectionRead_ObstacleBecomesOld_mutex);
                                _OpCache_with_parameter_ObstacleBecomesOld.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "ObstacleBecomesOld";
                    result.insert(copiedState);
                    transitions += 1;
                }

            } else {
                if(state._tr_CruiseBecomesNotAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesNotAllowed();
                    copiedState.stateAccessedVia = "CruiseBecomesNotAllowed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_CruiseBecomesAllowed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseBecomesAllowed();
                    copiedState.stateAccessedVia = "CruiseBecomesAllowed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BBoolean, BBoolean >> _trid_3 = state._tr_SetCruiseSpeed();
                for(const BTuple<BBoolean, BBoolean >& param : _trid_3) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.SetCruiseSpeed(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "SetCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BBoolean, BBoolean >> _trid_4 = state._tr_CCInitialisationFinished();
                for(const BTuple<BBoolean, BBoolean >& param : _trid_4) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationFinished(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "CCInitialisationFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_CCInitialisationDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CCInitialisationDelayFinished();
                    copiedState.stateAccessedVia = "CCInitialisationDelayFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BBoolean, BBoolean >> _trid_6 = state._tr_CruiseSpeedChangeFinished();
                for(const BTuple<BBoolean, BBoolean >& param : _trid_6) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeFinished(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "CruiseSpeedChangeFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_CruiseSpeedChangeDelayFinished()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseSpeedChangeDelayFinished();
                    copiedState.stateAccessedVia = "CruiseSpeedChangeDelayFinished";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_CruiseOff()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.CruiseOff();
                    copiedState.stateAccessedVia = "CruiseOff";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ExternalForcesBecomesExtreme()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesExtreme();
                    copiedState.stateAccessedVia = "ExternalForcesBecomesExtreme";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ExternalForcesBecomesNormal()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ExternalForcesBecomesNormal();
                    copiedState.stateAccessedVia = "ExternalForcesBecomesNormal";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_VehicleLeavesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleLeavesCruiseSpeed();
                    copiedState.stateAccessedVia = "VehicleLeavesCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_VehicleReachesCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleReachesCruiseSpeed();
                    copiedState.stateAccessedVia = "VehicleReachesCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_VehicleExceedsMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleExceedsMaxCruiseSpeed();
                    copiedState.stateAccessedVia = "VehicleExceedsMaxCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_VehicleFallsBelowMaxCruiseSpeed()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleFallsBelowMaxCruiseSpeed();
                    copiedState.stateAccessedVia = "VehicleFallsBelowMaxCruiseSpeed";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleDistanceBecomesVeryClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesVeryClose();
                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesVeryClose";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleDistanceBecomesClose()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesClose();
                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesClose";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleDistanceBecomesBig()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDistanceBecomesBig();
                    copiedState.stateAccessedVia = "ObstacleDistanceBecomesBig";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleStartsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelFaster();
                    copiedState.stateAccessedVia = "ObstacleStartsTravelFaster";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleStopsTravelFaster()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelFaster();
                    copiedState.stateAccessedVia = "ObstacleStopsTravelFaster";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleStartsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStartsTravelSlower();
                    copiedState.stateAccessedVia = "ObstacleStartsTravelSlower";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleStopsTravelSlower()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleStopsTravelSlower();
                    copiedState.stateAccessedVia = "ObstacleStopsTravelSlower";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >> _trid_22 = state._tr_ObstacleAppearsWhenCruiseActive();
                for(const BTuple<Cruise_finite1_deterministic_MC::RSset, Cruise_finite1_deterministic_MC::ODset >& param : _trid_22) {
                    Cruise_finite1_deterministic_MC::ODset _tmp_1 = param.projection2();
                    Cruise_finite1_deterministic_MC::RSset _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseActive(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseActive";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Cruise_finite1_deterministic_MC::RSset> _trid_23 = state._tr_ObstacleAppearsWhenCruiseInactive();
                for(const Cruise_finite1_deterministic_MC::RSset& param : _trid_23) {
                    Cruise_finite1_deterministic_MC::RSset _tmp_1 = param;

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleAppearsWhenCruiseInactive(_tmp_1);
                    copiedState.stateAccessedVia = "ObstacleAppearsWhenCruiseInactive";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleDisappears()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleDisappears();
                    copiedState.stateAccessedVia = "ObstacleDisappears";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<BTuple<BBoolean, BBoolean >> _trid_25 = state._tr_VehicleManageObstacle();
                for(const BTuple<BBoolean, BBoolean >& param : _trid_25) {
                    BBoolean _tmp_1 = param.projection2();
                    BBoolean _tmp_2 = param.projection1();

                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.VehicleManageObstacle(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "VehicleManageObstacle";
                    result.insert(copiedState);
                    transitions += 1;
                }
                if(state._tr_ObstacleBecomesOld()) {
                    Cruise_finite1_deterministic_MC copiedState = state._copy();
                    copiedState.ObstacleBecomesOld();
                    copiedState.stateAccessedVia = "ObstacleBecomesOld";
                    result.insert(copiedState);
                    transitions += 1;
                }

            }
            return result;
        }

        bool invariantViolated(const Cruise_finite1_deterministic_MC& state) {
            bool _check_inv_1;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                    _check_inv_1 = state._check_inv_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    }
                } else {
                    _check_inv_1 = _obj__check_inv_1_ptr->second;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            bool _check_inv_2;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                    _check_inv_2 = state._check_inv_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    }
                } else {
                    _check_inv_2 = _obj__check_inv_2_ptr->second;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
              return true;
            }
            bool _check_inv_3;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                auto _obj__check_inv_3_ptr = _InvCache__check_inv_3.find(read__check_inv_3_state);
                if(_obj__check_inv_3_ptr == _InvCache__check_inv_3.end()) {
                    _check_inv_3 = state._check_inv_3();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_3_lock(_ProjectionRead__check_inv_3_mutex);
                        _InvCache__check_inv_3.insert({read__check_inv_3_state, _check_inv_3});
                    }
                } else {
                    _check_inv_3 = _obj__check_inv_3_ptr->second;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
              return true;
            }
            bool _check_inv_4;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                auto _obj__check_inv_4_ptr = _InvCache__check_inv_4.find(read__check_inv_4_state);
                if(_obj__check_inv_4_ptr == _InvCache__check_inv_4.end()) {
                    _check_inv_4 = state._check_inv_4();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_4_lock(_ProjectionRead__check_inv_4_mutex);
                        _InvCache__check_inv_4.insert({read__check_inv_4_state, _check_inv_4});
                    }
                } else {
                    _check_inv_4 = _obj__check_inv_4_ptr->second;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
              return true;
            }
            bool _check_inv_5;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                auto _obj__check_inv_5_ptr = _InvCache__check_inv_5.find(read__check_inv_5_state);
                if(_obj__check_inv_5_ptr == _InvCache__check_inv_5.end()) {
                    _check_inv_5 = state._check_inv_5();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_5_lock(_ProjectionRead__check_inv_5_mutex);
                        _InvCache__check_inv_5.insert({read__check_inv_5_state, _check_inv_5});
                    }
                } else {
                    _check_inv_5 = _obj__check_inv_5_ptr->second;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
              return true;
            }
            bool _check_inv_6;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                auto _obj__check_inv_6_ptr = _InvCache__check_inv_6.find(read__check_inv_6_state);
                if(_obj__check_inv_6_ptr == _InvCache__check_inv_6.end()) {
                    _check_inv_6 = state._check_inv_6();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_6_lock(_ProjectionRead__check_inv_6_mutex);
                        _InvCache__check_inv_6.insert({read__check_inv_6_state, _check_inv_6});
                    }
                } else {
                    _check_inv_6 = _obj__check_inv_6_ptr->second;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
              return true;
            }
            bool _check_inv_7;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                auto _obj__check_inv_7_ptr = _InvCache__check_inv_7.find(read__check_inv_7_state);
                if(_obj__check_inv_7_ptr == _InvCache__check_inv_7.end()) {
                    _check_inv_7 = state._check_inv_7();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_7_lock(_ProjectionRead__check_inv_7_mutex);
                        _InvCache__check_inv_7.insert({read__check_inv_7_state, _check_inv_7});
                    }
                } else {
                    _check_inv_7 = _obj__check_inv_7_ptr->second;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
              return true;
            }
            bool _check_inv_8;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                auto _obj__check_inv_8_ptr = _InvCache__check_inv_8.find(read__check_inv_8_state);
                if(_obj__check_inv_8_ptr == _InvCache__check_inv_8.end()) {
                    _check_inv_8 = state._check_inv_8();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_8_lock(_ProjectionRead__check_inv_8_mutex);
                        _InvCache__check_inv_8.insert({read__check_inv_8_state, _check_inv_8});
                    }
                } else {
                    _check_inv_8 = _obj__check_inv_8_ptr->second;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
              return true;
            }
            bool _check_inv_9;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                auto _obj__check_inv_9_ptr = _InvCache__check_inv_9.find(read__check_inv_9_state);
                if(_obj__check_inv_9_ptr == _InvCache__check_inv_9.end()) {
                    _check_inv_9 = state._check_inv_9();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_9_lock(_ProjectionRead__check_inv_9_mutex);
                        _InvCache__check_inv_9.insert({read__check_inv_9_state, _check_inv_9});
                    }
                } else {
                    _check_inv_9 = _obj__check_inv_9_ptr->second;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
              return true;
            }
            bool _check_inv_10;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                auto _obj__check_inv_10_ptr = _InvCache__check_inv_10.find(read__check_inv_10_state);
                if(_obj__check_inv_10_ptr == _InvCache__check_inv_10.end()) {
                    _check_inv_10 = state._check_inv_10();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_10_lock(_ProjectionRead__check_inv_10_mutex);
                        _InvCache__check_inv_10.insert({read__check_inv_10_state, _check_inv_10});
                    }
                } else {
                    _check_inv_10 = _obj__check_inv_10_ptr->second;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
              return true;
            }
            bool _check_inv_11;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                auto _obj__check_inv_11_ptr = _InvCache__check_inv_11.find(read__check_inv_11_state);
                if(_obj__check_inv_11_ptr == _InvCache__check_inv_11.end()) {
                    _check_inv_11 = state._check_inv_11();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_11_lock(_ProjectionRead__check_inv_11_mutex);
                        _InvCache__check_inv_11.insert({read__check_inv_11_state, _check_inv_11});
                    }
                } else {
                    _check_inv_11 = _obj__check_inv_11_ptr->second;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
              return true;
            }
            bool _check_inv_12;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                auto _obj__check_inv_12_ptr = _InvCache__check_inv_12.find(read__check_inv_12_state);
                if(_obj__check_inv_12_ptr == _InvCache__check_inv_12.end()) {
                    _check_inv_12 = state._check_inv_12();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_12_lock(_ProjectionRead__check_inv_12_mutex);
                        _InvCache__check_inv_12.insert({read__check_inv_12_state, _check_inv_12});
                    }
                } else {
                    _check_inv_12 = _obj__check_inv_12_ptr->second;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
              return true;
            }
            bool _check_inv_13;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                auto _obj__check_inv_13_ptr = _InvCache__check_inv_13.find(read__check_inv_13_state);
                if(_obj__check_inv_13_ptr == _InvCache__check_inv_13.end()) {
                    _check_inv_13 = state._check_inv_13();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_13_lock(_ProjectionRead__check_inv_13_mutex);
                        _InvCache__check_inv_13.insert({read__check_inv_13_state, _check_inv_13});
                    }
                } else {
                    _check_inv_13 = _obj__check_inv_13_ptr->second;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
              return true;
            }
            bool _check_inv_14;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                auto _obj__check_inv_14_ptr = _InvCache__check_inv_14.find(read__check_inv_14_state);
                if(_obj__check_inv_14_ptr == _InvCache__check_inv_14.end()) {
                    _check_inv_14 = state._check_inv_14();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_14_lock(_ProjectionRead__check_inv_14_mutex);
                        _InvCache__check_inv_14.insert({read__check_inv_14_state, _check_inv_14});
                    }
                } else {
                    _check_inv_14 = _obj__check_inv_14_ptr->second;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
              return true;
            }
            bool _check_inv_15;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                auto _obj__check_inv_15_ptr = _InvCache__check_inv_15.find(read__check_inv_15_state);
                if(_obj__check_inv_15_ptr == _InvCache__check_inv_15.end()) {
                    _check_inv_15 = state._check_inv_15();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_15_lock(_ProjectionRead__check_inv_15_mutex);
                        _InvCache__check_inv_15.insert({read__check_inv_15_state, _check_inv_15});
                    }
                } else {
                    _check_inv_15 = _obj__check_inv_15_ptr->second;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
              return true;
            }
            bool _check_inv_16;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                auto _obj__check_inv_16_ptr = _InvCache__check_inv_16.find(read__check_inv_16_state);
                if(_obj__check_inv_16_ptr == _InvCache__check_inv_16.end()) {
                    _check_inv_16 = state._check_inv_16();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_16_lock(_ProjectionRead__check_inv_16_mutex);
                        _InvCache__check_inv_16.insert({read__check_inv_16_state, _check_inv_16});
                    }
                } else {
                    _check_inv_16 = _obj__check_inv_16_ptr->second;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
              return true;
            }
            bool _check_inv_17;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                auto _obj__check_inv_17_ptr = _InvCache__check_inv_17.find(read__check_inv_17_state);
                if(_obj__check_inv_17_ptr == _InvCache__check_inv_17.end()) {
                    _check_inv_17 = state._check_inv_17();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_17_lock(_ProjectionRead__check_inv_17_mutex);
                        _InvCache__check_inv_17.insert({read__check_inv_17_state, _check_inv_17});
                    }
                } else {
                    _check_inv_17 = _obj__check_inv_17_ptr->second;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
              return true;
            }
            bool _check_inv_18;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                auto _obj__check_inv_18_ptr = _InvCache__check_inv_18.find(read__check_inv_18_state);
                if(_obj__check_inv_18_ptr == _InvCache__check_inv_18.end()) {
                    _check_inv_18 = state._check_inv_18();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_18_lock(_ProjectionRead__check_inv_18_mutex);
                        _InvCache__check_inv_18.insert({read__check_inv_18_state, _check_inv_18});
                    }
                } else {
                    _check_inv_18 = _obj__check_inv_18_ptr->second;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
              return true;
            }
            bool _check_inv_19;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_19 read__check_inv_19_state = state._projected_state_for__check_inv_19();
                auto _obj__check_inv_19_ptr = _InvCache__check_inv_19.find(read__check_inv_19_state);
                if(_obj__check_inv_19_ptr == _InvCache__check_inv_19.end()) {
                    _check_inv_19 = state._check_inv_19();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_19_lock(_ProjectionRead__check_inv_19_mutex);
                        _InvCache__check_inv_19.insert({read__check_inv_19_state, _check_inv_19});
                    }
                } else {
                    _check_inv_19 = _obj__check_inv_19_ptr->second;
                }
            } else {
                _check_inv_19 = state._check_inv_19();
            }
            if(!_check_inv_19) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_19" << "\n";
              return true;
            }
            bool _check_inv_20;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_20 read__check_inv_20_state = state._projected_state_for__check_inv_20();
                auto _obj__check_inv_20_ptr = _InvCache__check_inv_20.find(read__check_inv_20_state);
                if(_obj__check_inv_20_ptr == _InvCache__check_inv_20.end()) {
                    _check_inv_20 = state._check_inv_20();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_20_lock(_ProjectionRead__check_inv_20_mutex);
                        _InvCache__check_inv_20.insert({read__check_inv_20_state, _check_inv_20});
                    }
                } else {
                    _check_inv_20 = _obj__check_inv_20_ptr->second;
                }
            } else {
                _check_inv_20 = state._check_inv_20();
            }
            if(!_check_inv_20) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_20" << "\n";
              return true;
            }
            bool _check_inv_21;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_21 read__check_inv_21_state = state._projected_state_for__check_inv_21();
                auto _obj__check_inv_21_ptr = _InvCache__check_inv_21.find(read__check_inv_21_state);
                if(_obj__check_inv_21_ptr == _InvCache__check_inv_21.end()) {
                    _check_inv_21 = state._check_inv_21();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_21_lock(_ProjectionRead__check_inv_21_mutex);
                        _InvCache__check_inv_21.insert({read__check_inv_21_state, _check_inv_21});
                    }
                } else {
                    _check_inv_21 = _obj__check_inv_21_ptr->second;
                }
            } else {
                _check_inv_21 = state._check_inv_21();
            }
            if(!_check_inv_21) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_21" << "\n";
              return true;
            }
            bool _check_inv_22;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_22 read__check_inv_22_state = state._projected_state_for__check_inv_22();
                auto _obj__check_inv_22_ptr = _InvCache__check_inv_22.find(read__check_inv_22_state);
                if(_obj__check_inv_22_ptr == _InvCache__check_inv_22.end()) {
                    _check_inv_22 = state._check_inv_22();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_22_lock(_ProjectionRead__check_inv_22_mutex);
                        _InvCache__check_inv_22.insert({read__check_inv_22_state, _check_inv_22});
                    }
                } else {
                    _check_inv_22 = _obj__check_inv_22_ptr->second;
                }
            } else {
                _check_inv_22 = state._check_inv_22();
            }
            if(!_check_inv_22) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_22" << "\n";
              return true;
            }
            bool _check_inv_23;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_23 read__check_inv_23_state = state._projected_state_for__check_inv_23();
                auto _obj__check_inv_23_ptr = _InvCache__check_inv_23.find(read__check_inv_23_state);
                if(_obj__check_inv_23_ptr == _InvCache__check_inv_23.end()) {
                    _check_inv_23 = state._check_inv_23();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_23_lock(_ProjectionRead__check_inv_23_mutex);
                        _InvCache__check_inv_23.insert({read__check_inv_23_state, _check_inv_23});
                    }
                } else {
                    _check_inv_23 = _obj__check_inv_23_ptr->second;
                }
            } else {
                _check_inv_23 = state._check_inv_23();
            }
            if(!_check_inv_23) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_23" << "\n";
              return true;
            }
            bool _check_inv_24;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_24 read__check_inv_24_state = state._projected_state_for__check_inv_24();
                auto _obj__check_inv_24_ptr = _InvCache__check_inv_24.find(read__check_inv_24_state);
                if(_obj__check_inv_24_ptr == _InvCache__check_inv_24.end()) {
                    _check_inv_24 = state._check_inv_24();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_24_lock(_ProjectionRead__check_inv_24_mutex);
                        _InvCache__check_inv_24.insert({read__check_inv_24_state, _check_inv_24});
                    }
                } else {
                    _check_inv_24 = _obj__check_inv_24_ptr->second;
                }
            } else {
                _check_inv_24 = state._check_inv_24();
            }
            if(!_check_inv_24) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_24" << "\n";
              return true;
            }
            bool _check_inv_25;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_25 read__check_inv_25_state = state._projected_state_for__check_inv_25();
                auto _obj__check_inv_25_ptr = _InvCache__check_inv_25.find(read__check_inv_25_state);
                if(_obj__check_inv_25_ptr == _InvCache__check_inv_25.end()) {
                    _check_inv_25 = state._check_inv_25();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_25_lock(_ProjectionRead__check_inv_25_mutex);
                        _InvCache__check_inv_25.insert({read__check_inv_25_state, _check_inv_25});
                    }
                } else {
                    _check_inv_25 = _obj__check_inv_25_ptr->second;
                }
            } else {
                _check_inv_25 = state._check_inv_25();
            }
            if(!_check_inv_25) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_25" << "\n";
              return true;
            }
            bool _check_inv_26;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_26 read__check_inv_26_state = state._projected_state_for__check_inv_26();
                auto _obj__check_inv_26_ptr = _InvCache__check_inv_26.find(read__check_inv_26_state);
                if(_obj__check_inv_26_ptr == _InvCache__check_inv_26.end()) {
                    _check_inv_26 = state._check_inv_26();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_26_lock(_ProjectionRead__check_inv_26_mutex);
                        _InvCache__check_inv_26.insert({read__check_inv_26_state, _check_inv_26});
                    }
                } else {
                    _check_inv_26 = _obj__check_inv_26_ptr->second;
                }
            } else {
                _check_inv_26 = state._check_inv_26();
            }
            if(!_check_inv_26) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_26" << "\n";
              return true;
            }
            bool _check_inv_27;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_27 read__check_inv_27_state = state._projected_state_for__check_inv_27();
                auto _obj__check_inv_27_ptr = _InvCache__check_inv_27.find(read__check_inv_27_state);
                if(_obj__check_inv_27_ptr == _InvCache__check_inv_27.end()) {
                    _check_inv_27 = state._check_inv_27();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_27_lock(_ProjectionRead__check_inv_27_mutex);
                        _InvCache__check_inv_27.insert({read__check_inv_27_state, _check_inv_27});
                    }
                } else {
                    _check_inv_27 = _obj__check_inv_27_ptr->second;
                }
            } else {
                _check_inv_27 = state._check_inv_27();
            }
            if(!_check_inv_27) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_27" << "\n";
              return true;
            }
            bool _check_inv_28;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_28 read__check_inv_28_state = state._projected_state_for__check_inv_28();
                auto _obj__check_inv_28_ptr = _InvCache__check_inv_28.find(read__check_inv_28_state);
                if(_obj__check_inv_28_ptr == _InvCache__check_inv_28.end()) {
                    _check_inv_28 = state._check_inv_28();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_28_lock(_ProjectionRead__check_inv_28_mutex);
                        _InvCache__check_inv_28.insert({read__check_inv_28_state, _check_inv_28});
                    }
                } else {
                    _check_inv_28 = _obj__check_inv_28_ptr->second;
                }
            } else {
                _check_inv_28 = state._check_inv_28();
            }
            if(!_check_inv_28) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_28" << "\n";
              return true;
            }
            bool _check_inv_29;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_29 read__check_inv_29_state = state._projected_state_for__check_inv_29();
                auto _obj__check_inv_29_ptr = _InvCache__check_inv_29.find(read__check_inv_29_state);
                if(_obj__check_inv_29_ptr == _InvCache__check_inv_29.end()) {
                    _check_inv_29 = state._check_inv_29();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_29_lock(_ProjectionRead__check_inv_29_mutex);
                        _InvCache__check_inv_29.insert({read__check_inv_29_state, _check_inv_29});
                    }
                } else {
                    _check_inv_29 = _obj__check_inv_29_ptr->second;
                }
            } else {
                _check_inv_29 = state._check_inv_29();
            }
            if(!_check_inv_29) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_29" << "\n";
              return true;
            }
            bool _check_inv_30;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_30 read__check_inv_30_state = state._projected_state_for__check_inv_30();
                auto _obj__check_inv_30_ptr = _InvCache__check_inv_30.find(read__check_inv_30_state);
                if(_obj__check_inv_30_ptr == _InvCache__check_inv_30.end()) {
                    _check_inv_30 = state._check_inv_30();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_30_lock(_ProjectionRead__check_inv_30_mutex);
                        _InvCache__check_inv_30.insert({read__check_inv_30_state, _check_inv_30});
                    }
                } else {
                    _check_inv_30 = _obj__check_inv_30_ptr->second;
                }
            } else {
                _check_inv_30 = state._check_inv_30();
            }
            if(!_check_inv_30) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_30" << "\n";
              return true;
            }
            bool _check_inv_31;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_31 read__check_inv_31_state = state._projected_state_for__check_inv_31();
                auto _obj__check_inv_31_ptr = _InvCache__check_inv_31.find(read__check_inv_31_state);
                if(_obj__check_inv_31_ptr == _InvCache__check_inv_31.end()) {
                    _check_inv_31 = state._check_inv_31();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_31_lock(_ProjectionRead__check_inv_31_mutex);
                        _InvCache__check_inv_31.insert({read__check_inv_31_state, _check_inv_31});
                    }
                } else {
                    _check_inv_31 = _obj__check_inv_31_ptr->second;
                }
            } else {
                _check_inv_31 = state._check_inv_31();
            }
            if(!_check_inv_31) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_31" << "\n";
              return true;
            }
            bool _check_inv_32;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_32 read__check_inv_32_state = state._projected_state_for__check_inv_32();
                auto _obj__check_inv_32_ptr = _InvCache__check_inv_32.find(read__check_inv_32_state);
                if(_obj__check_inv_32_ptr == _InvCache__check_inv_32.end()) {
                    _check_inv_32 = state._check_inv_32();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_32_lock(_ProjectionRead__check_inv_32_mutex);
                        _InvCache__check_inv_32.insert({read__check_inv_32_state, _check_inv_32});
                    }
                } else {
                    _check_inv_32 = _obj__check_inv_32_ptr->second;
                }
            } else {
                _check_inv_32 = state._check_inv_32();
            }
            if(!_check_inv_32) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_32" << "\n";
              return true;
            }
            bool _check_inv_33;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_33 read__check_inv_33_state = state._projected_state_for__check_inv_33();
                auto _obj__check_inv_33_ptr = _InvCache__check_inv_33.find(read__check_inv_33_state);
                if(_obj__check_inv_33_ptr == _InvCache__check_inv_33.end()) {
                    _check_inv_33 = state._check_inv_33();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_33_lock(_ProjectionRead__check_inv_33_mutex);
                        _InvCache__check_inv_33.insert({read__check_inv_33_state, _check_inv_33});
                    }
                } else {
                    _check_inv_33 = _obj__check_inv_33_ptr->second;
                }
            } else {
                _check_inv_33 = state._check_inv_33();
            }
            if(!_check_inv_33) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_33" << "\n";
              return true;
            }
            bool _check_inv_34;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_34 read__check_inv_34_state = state._projected_state_for__check_inv_34();
                auto _obj__check_inv_34_ptr = _InvCache__check_inv_34.find(read__check_inv_34_state);
                if(_obj__check_inv_34_ptr == _InvCache__check_inv_34.end()) {
                    _check_inv_34 = state._check_inv_34();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_34_lock(_ProjectionRead__check_inv_34_mutex);
                        _InvCache__check_inv_34.insert({read__check_inv_34_state, _check_inv_34});
                    }
                } else {
                    _check_inv_34 = _obj__check_inv_34_ptr->second;
                }
            } else {
                _check_inv_34 = state._check_inv_34();
            }
            if(!_check_inv_34) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_34" << "\n";
              return true;
            }
            bool _check_inv_35;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_35 read__check_inv_35_state = state._projected_state_for__check_inv_35();
                auto _obj__check_inv_35_ptr = _InvCache__check_inv_35.find(read__check_inv_35_state);
                if(_obj__check_inv_35_ptr == _InvCache__check_inv_35.end()) {
                    _check_inv_35 = state._check_inv_35();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_35_lock(_ProjectionRead__check_inv_35_mutex);
                        _InvCache__check_inv_35.insert({read__check_inv_35_state, _check_inv_35});
                    }
                } else {
                    _check_inv_35 = _obj__check_inv_35_ptr->second;
                }
            } else {
                _check_inv_35 = state._check_inv_35();
            }
            if(!_check_inv_35) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_35" << "\n";
              return true;
            }
            bool _check_inv_36;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_36 read__check_inv_36_state = state._projected_state_for__check_inv_36();
                auto _obj__check_inv_36_ptr = _InvCache__check_inv_36.find(read__check_inv_36_state);
                if(_obj__check_inv_36_ptr == _InvCache__check_inv_36.end()) {
                    _check_inv_36 = state._check_inv_36();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_36_lock(_ProjectionRead__check_inv_36_mutex);
                        _InvCache__check_inv_36.insert({read__check_inv_36_state, _check_inv_36});
                    }
                } else {
                    _check_inv_36 = _obj__check_inv_36_ptr->second;
                }
            } else {
                _check_inv_36 = state._check_inv_36();
            }
            if(!_check_inv_36) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_36" << "\n";
              return true;
            }
            bool _check_inv_37;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_37 read__check_inv_37_state = state._projected_state_for__check_inv_37();
                auto _obj__check_inv_37_ptr = _InvCache__check_inv_37.find(read__check_inv_37_state);
                if(_obj__check_inv_37_ptr == _InvCache__check_inv_37.end()) {
                    _check_inv_37 = state._check_inv_37();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_37_lock(_ProjectionRead__check_inv_37_mutex);
                        _InvCache__check_inv_37.insert({read__check_inv_37_state, _check_inv_37});
                    }
                } else {
                    _check_inv_37 = _obj__check_inv_37_ptr->second;
                }
            } else {
                _check_inv_37 = state._check_inv_37();
            }
            if(!_check_inv_37) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_37" << "\n";
              return true;
            }
            bool _check_inv_38;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_38 read__check_inv_38_state = state._projected_state_for__check_inv_38();
                auto _obj__check_inv_38_ptr = _InvCache__check_inv_38.find(read__check_inv_38_state);
                if(_obj__check_inv_38_ptr == _InvCache__check_inv_38.end()) {
                    _check_inv_38 = state._check_inv_38();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_38_lock(_ProjectionRead__check_inv_38_mutex);
                        _InvCache__check_inv_38.insert({read__check_inv_38_state, _check_inv_38});
                    }
                } else {
                    _check_inv_38 = _obj__check_inv_38_ptr->second;
                }
            } else {
                _check_inv_38 = state._check_inv_38();
            }
            if(!_check_inv_38) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_38" << "\n";
              return true;
            }
            bool _check_inv_39;
            if(isCaching) {
                Cruise_finite1_deterministic_MC::_ProjectionRead__check_inv_39 read__check_inv_39_state = state._projected_state_for__check_inv_39();
                auto _obj__check_inv_39_ptr = _InvCache__check_inv_39.find(read__check_inv_39_state);
                if(_obj__check_inv_39_ptr == _InvCache__check_inv_39.end()) {
                    _check_inv_39 = state._check_inv_39();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_39_lock(_ProjectionRead__check_inv_39_mutex);
                        _InvCache__check_inv_39.insert({read__check_inv_39_state, _check_inv_39});
                    }
                } else {
                    _check_inv_39 = _obj__check_inv_39_ptr->second;
                }
            } else {
                _check_inv_39 = state._check_inv_39();
            }
            if(!_check_inv_39) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_39" << "\n";
              return true;
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

    bool isDebug = false;

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif