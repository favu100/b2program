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
#include <future>
#include <boost/asio/post.hpp>
#include <boost/asio/thread_pool.hpp>
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/VariantViolation.hpp>
#include <btypes_primitives/LoopInvariantViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef prob_oneway8seq_H
#define prob_oneway8seq_H

using namespace std;

class prob_oneway8seq {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const prob_oneway8seq& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const prob_oneway8seq& obj1, const prob_oneway8seq& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_move0 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move0& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move0& obj1, const _ProjectionRead_move0& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move0(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move0& o1, const _ProjectionRead_move0& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move0& o1, const _ProjectionRead_move0& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move0& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move0 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move0& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move0& obj1, const _ProjectionRead__tr_move0& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move0(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move0& o1, const _ProjectionRead__tr_move0& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move0& o1, const _ProjectionRead__tr_move0& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move0& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move0 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move0& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move0& obj1, const _ProjectionWrite_move0& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger RB;
                BInteger RA;

                _ProjectionWrite_move0(const BInteger& P0, const BInteger& RB, const BInteger& RA) {
                    this->P0 = P0;
                    this->RB = RB;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move0& o1, const _ProjectionWrite_move0& o2) {
                    return o1.P0 == (o2.P0) && o1.RB == (o2.RB) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move0& o1, const _ProjectionWrite_move0& o2) {
                    return o1.P0 != (o2.P0) || o1.RB != (o2.RB) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move0& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move1& obj1, const _ProjectionRead_move1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move1(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move1& o1, const _ProjectionRead_move1& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move1& o1, const _ProjectionRead_move1& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move1& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move1& obj1, const _ProjectionRead__tr_move1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move1(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move1& o1, const _ProjectionRead__tr_move1& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move1& o1, const _ProjectionRead__tr_move1& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move1& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move1& obj1, const _ProjectionWrite_move1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P1;
                BInteger RA;

                _ProjectionWrite_move1(const BInteger& RB, const BInteger& P1, const BInteger& RA) {
                    this->RB = RB;
                    this->P1 = P1;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move1& o1, const _ProjectionWrite_move1& o2) {
                    return o1.RB == (o2.RB) && o1.P1 == (o2.P1) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move1& o1, const _ProjectionWrite_move1& o2) {
                    return o1.RB != (o2.RB) || o1.P1 != (o2.P1) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move1& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move2& obj1, const _ProjectionRead_move2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move2(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move2& o1, const _ProjectionRead_move2& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move2& o1, const _ProjectionRead_move2& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move2& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move2& obj1, const _ProjectionRead__tr_move2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move2(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move2& o1, const _ProjectionRead__tr_move2& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move2& o1, const _ProjectionRead__tr_move2& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move2& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move2& obj1, const _ProjectionWrite_move2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P2;
                BInteger RA;

                _ProjectionWrite_move2(const BInteger& RB, const BInteger& P2, const BInteger& RA) {
                    this->RB = RB;
                    this->P2 = P2;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move2& o1, const _ProjectionWrite_move2& o2) {
                    return o1.RB == (o2.RB) && o1.P2 == (o2.P2) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move2& o1, const _ProjectionWrite_move2& o2) {
                    return o1.RB != (o2.RB) || o1.P2 != (o2.P2) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move2& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move3 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move3& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move3& obj1, const _ProjectionRead_move3& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move3(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move3& o1, const _ProjectionRead_move3& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move3& o1, const _ProjectionRead_move3& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move3& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move3 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move3& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move3& obj1, const _ProjectionRead__tr_move3& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move3(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move3& o1, const _ProjectionRead__tr_move3& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move3& o1, const _ProjectionRead__tr_move3& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move3& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move3 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move3& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move3& obj1, const _ProjectionWrite_move3& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P3;
                BInteger RA;

                _ProjectionWrite_move3(const BInteger& RB, const BInteger& P3, const BInteger& RA) {
                    this->RB = RB;
                    this->P3 = P3;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move3& o1, const _ProjectionWrite_move3& o2) {
                    return o1.RB == (o2.RB) && o1.P3 == (o2.P3) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move3& o1, const _ProjectionWrite_move3& o2) {
                    return o1.RB != (o2.RB) || o1.P3 != (o2.P3) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move3& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move4 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move4& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move4& obj1, const _ProjectionRead_move4& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move4(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move4& o1, const _ProjectionRead_move4& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move4& o1, const _ProjectionRead_move4& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move4& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move4 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move4& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move4& obj1, const _ProjectionRead__tr_move4& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move4(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move4& o1, const _ProjectionRead__tr_move4& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move4& o1, const _ProjectionRead__tr_move4& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move4& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move4 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move4& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move4& obj1, const _ProjectionWrite_move4& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P4;
                BInteger RA;

                _ProjectionWrite_move4(const BInteger& RB, const BInteger& P4, const BInteger& RA) {
                    this->RB = RB;
                    this->P4 = P4;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move4& o1, const _ProjectionWrite_move4& o2) {
                    return o1.RB == (o2.RB) && o1.P4 == (o2.P4) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move4& o1, const _ProjectionWrite_move4& o2) {
                    return o1.RB != (o2.RB) || o1.P4 != (o2.P4) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move4& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move5 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move5& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move5& obj1, const _ProjectionRead_move5& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move5(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move5& o1, const _ProjectionRead_move5& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move5& o1, const _ProjectionRead_move5& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move5& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move5 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move5& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move5& obj1, const _ProjectionRead__tr_move5& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move5(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move5& o1, const _ProjectionRead__tr_move5& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move5& o1, const _ProjectionRead__tr_move5& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move5& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move5 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move5& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move5& obj1, const _ProjectionWrite_move5& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P5;
                BInteger RA;

                _ProjectionWrite_move5(const BInteger& RB, const BInteger& P5, const BInteger& RA) {
                    this->RB = RB;
                    this->P5 = P5;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move5& o1, const _ProjectionWrite_move5& o2) {
                    return o1.RB == (o2.RB) && o1.P5 == (o2.P5) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move5& o1, const _ProjectionWrite_move5& o2) {
                    return o1.RB != (o2.RB) || o1.P5 != (o2.P5) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move5& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move6 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move6& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move6& obj1, const _ProjectionRead_move6& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move6(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move6& o1, const _ProjectionRead_move6& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move6& o1, const _ProjectionRead_move6& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move6& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move6 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move6& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move6& obj1, const _ProjectionRead__tr_move6& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move6(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move6& o1, const _ProjectionRead__tr_move6& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move6& o1, const _ProjectionRead__tr_move6& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move6& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move6 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move6& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move6& obj1, const _ProjectionWrite_move6& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P6;
                BInteger RA;

                _ProjectionWrite_move6(const BInteger& RB, const BInteger& P6, const BInteger& RA) {
                    this->RB = RB;
                    this->P6 = P6;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move6& o1, const _ProjectionWrite_move6& o2) {
                    return o1.RB == (o2.RB) && o1.P6 == (o2.P6) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move6& o1, const _ProjectionWrite_move6& o2) {
                    return o1.RB != (o2.RB) || o1.P6 != (o2.P6) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move6& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_move7 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_move7& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_move7& obj1, const _ProjectionRead_move7& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead_move7(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead_move7& o1, const _ProjectionRead_move7& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead_move7& o1, const _ProjectionRead_move7& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_move7& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;
                    strm << ", ";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_move7 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_move7& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_move7& obj1, const _ProjectionRead__tr_move7& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;
                BInteger RA;
                BInteger RB;

                _ProjectionRead__tr_move7(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                    this->RA = RA;
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__tr_move7& o1, const _ProjectionRead__tr_move7& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7) && o1.RA == (o2.RA) && o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__tr_move7& o1, const _ProjectionRead__tr_move7& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7) || o1.RA != (o2.RA) || o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_move7& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;
                    strm << ", "; 
                    strm << "RA: " << e.RA;
                    strm << ", "; 
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_move7 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_move7& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_move7& obj1, const _ProjectionWrite_move7& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger RB;
                BInteger P7;
                BInteger RA;

                _ProjectionWrite_move7(const BInteger& RB, const BInteger& P7, const BInteger& RA) {
                    this->RB = RB;
                    this->P7 = P7;
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionWrite_move7& o1, const _ProjectionWrite_move7& o2) {
                    return o1.RB == (o2.RB) && o1.P7 == (o2.P7) && o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionWrite_move7& o1, const _ProjectionWrite_move7& o2) {
                    return o1.RB != (o2.RB) || o1.P7 != (o2.P7) || o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_move7& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;
                    strm << ", ";
                    strm << "P7: " << e.P7;
                    strm << ", ";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    result = 31 * result + (RA.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_arrived {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_arrived& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_arrived& obj1, const _ProjectionRead_arrived& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;

                _ProjectionRead_arrived(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                }

                friend bool operator ==(const _ProjectionRead_arrived& o1, const _ProjectionRead_arrived& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7);
                }

                friend bool operator !=(const _ProjectionRead_arrived& o1, const _ProjectionRead_arrived& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_arrived& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", ";
                    strm << "P1: " << e.P1;
                    strm << ", ";
                    strm << "P2: " << e.P2;
                    strm << ", ";
                    strm << "P3: " << e.P3;
                    strm << ", ";
                    strm << "P4: " << e.P4;
                    strm << ", ";
                    strm << "P5: " << e.P5;
                    strm << ", ";
                    strm << "P6: " << e.P6;
                    strm << ", ";
                    strm << "P7: " << e.P7;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_arrived {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_arrived& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_arrived& obj1, const _ProjectionRead__tr_arrived& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger P0;
                BInteger P1;
                BInteger P2;
                BInteger P3;
                BInteger P4;
                BInteger P5;
                BInteger P6;
                BInteger P7;

                _ProjectionRead__tr_arrived(const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7) {
                    this->P0 = P0;
                    this->P1 = P1;
                    this->P2 = P2;
                    this->P3 = P3;
                    this->P4 = P4;
                    this->P5 = P5;
                    this->P6 = P6;
                    this->P7 = P7;
                }

                friend bool operator ==(const _ProjectionRead__tr_arrived& o1, const _ProjectionRead__tr_arrived& o2) {
                    return o1.P0 == (o2.P0) && o1.P1 == (o2.P1) && o1.P2 == (o2.P2) && o1.P3 == (o2.P3) && o1.P4 == (o2.P4) && o1.P5 == (o2.P5) && o1.P6 == (o2.P6) && o1.P7 == (o2.P7);
                }

                friend bool operator !=(const _ProjectionRead__tr_arrived& o1, const _ProjectionRead__tr_arrived& o2) {
                    return o1.P0 != (o2.P0) || o1.P1 != (o2.P1) || o1.P2 != (o2.P2) || o1.P3 != (o2.P3) || o1.P4 != (o2.P4) || o1.P5 != (o2.P5) || o1.P6 != (o2.P6) || o1.P7 != (o2.P7);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_arrived& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;
                    strm << ", "; 
                    strm << "P1: " << e.P1;
                    strm << ", "; 
                    strm << "P2: " << e.P2;
                    strm << ", "; 
                    strm << "P3: " << e.P3;
                    strm << ", "; 
                    strm << "P4: " << e.P4;
                    strm << ", "; 
                    strm << "P5: " << e.P5;
                    strm << ", "; 
                    strm << "P6: " << e.P6;
                    strm << ", "; 
                    strm << "P7: " << e.P7;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
                    result = 31 * result + (P1.hashCode() << 1);
                    result = 31 * result + (P2.hashCode() << 1);
                    result = 31 * result + (P3.hashCode() << 1);
                    result = 31 * result + (P4.hashCode() << 1);
                    result = 31 * result + (P5.hashCode() << 1);
                    result = 31 * result + (P6.hashCode() << 1);
                    result = 31 * result + (P7.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_arrived {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_arrived& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_arrived& obj1, const _ProjectionWrite_arrived& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_arrived() {
                }

                friend bool operator ==(const _ProjectionWrite_arrived& o1, const _ProjectionWrite_arrived& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_arrived& o1, const _ProjectionWrite_arrived& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_arrived& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
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

                BInteger P0;

                _ProjectionRead__check_inv_1(const BInteger& P0) {
                    this->P0 = P0;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.P0 == (o2.P0);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.P0 != (o2.P0);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "P0: " << e.P0;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P0.hashCode() << 1);
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

                BInteger P1;

                _ProjectionRead__check_inv_2(const BInteger& P1) {
                    this->P1 = P1;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.P1 == (o2.P1);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.P1 != (o2.P1);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "P1: " << e.P1;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P1.hashCode() << 1);
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

                BInteger P2;

                _ProjectionRead__check_inv_3(const BInteger& P2) {
                    this->P2 = P2;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.P2 == (o2.P2);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.P2 != (o2.P2);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "P2: " << e.P2;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P2.hashCode() << 1);
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

                BInteger P3;

                _ProjectionRead__check_inv_4(const BInteger& P3) {
                    this->P3 = P3;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.P3 == (o2.P3);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.P3 != (o2.P3);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "P3: " << e.P3;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P3.hashCode() << 1);
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

                BInteger P4;

                _ProjectionRead__check_inv_5(const BInteger& P4) {
                    this->P4 = P4;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.P4 == (o2.P4);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.P4 != (o2.P4);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "P4: " << e.P4;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P4.hashCode() << 1);
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

                BInteger P5;

                _ProjectionRead__check_inv_6(const BInteger& P5) {
                    this->P5 = P5;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.P5 == (o2.P5);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.P5 != (o2.P5);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "P5: " << e.P5;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P5.hashCode() << 1);
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

                BInteger P6;

                _ProjectionRead__check_inv_7(const BInteger& P6) {
                    this->P6 = P6;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.P6 == (o2.P6);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.P6 != (o2.P6);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "P6: " << e.P6;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P6.hashCode() << 1);
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

                BInteger P7;

                _ProjectionRead__check_inv_8(const BInteger& P7) {
                    this->P7 = P7;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.P7 == (o2.P7);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.P7 != (o2.P7);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "P7: " << e.P7;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (P7.hashCode() << 1);
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

                BInteger RA;

                _ProjectionRead__check_inv_9(const BInteger& RA) {
                    this->RA = RA;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.RA == (o2.RA);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.RA != (o2.RA);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "RA: " << e.RA;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RA.hashCode() << 1);
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

                BInteger RB;

                _ProjectionRead__check_inv_10(const BInteger& RB) {
                    this->RB = RB;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.RB == (o2.RB);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.RB != (o2.RB);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "RB: " << e.RB;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (RB.hashCode() << 1);
                    return result;
                }

        };



    private:

        BRelation<BInteger, BInteger > T0;
        BRelation<BInteger, BInteger > T1;
        BRelation<BInteger, BInteger > T2;
        BRelation<BInteger, BInteger > T3;
        BRelation<BInteger, BInteger > T4;
        BRelation<BInteger, BInteger > T5;
        BRelation<BInteger, BInteger > T6;
        BRelation<BInteger, BInteger > T7;
        BRelation<BInteger, BInteger > A0;
        BRelation<BInteger, BInteger > A1;
        BRelation<BInteger, BInteger > A2;
        BRelation<BInteger, BInteger > A3;
        BRelation<BInteger, BInteger > A4;
        BRelation<BInteger, BInteger > A5;
        BRelation<BInteger, BInteger > A6;
        BRelation<BInteger, BInteger > A7;
        BRelation<BInteger, BInteger > B0;
        BRelation<BInteger, BInteger > B1;
        BRelation<BInteger, BInteger > B2;
        BRelation<BInteger, BInteger > B3;
        BRelation<BInteger, BInteger > B4;
        BRelation<BInteger, BInteger > B5;
        BRelation<BInteger, BInteger > B6;
        BRelation<BInteger, BInteger > B7;
        BInteger LA;
        BInteger LB;



        BInteger P0;
        BInteger P1;
        BInteger P2;
        BInteger P3;
        BInteger P4;
        BInteger P5;
        BInteger P6;
        BInteger P7;
        BInteger RA;
        BInteger RB;


    public:

        std::string stateAccessedVia;

        prob_oneway8seq() {
            T0 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(9)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(10)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(13)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(15)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(20)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(23))))));
            T1 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(3)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(9)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(10)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(13)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(15)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(20)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(24))))));
            T2 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(5)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(27)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(11)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(13)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(16)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(20)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(25))))));
            T3 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(7)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(27)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(11)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(13)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(16)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(20)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(26))))));
            T4 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(23)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(22)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(17)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(18)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(11)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(9)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(2))))));
            T5 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(24)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(22)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(17)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(18)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(11)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(9)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(4))))));
            T6 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(25)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(22)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(17)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(18)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(12)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(27)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(6))))));
            T7 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(26)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(22)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(17)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(18)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(12)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(27)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(8))))));
            A0 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A1 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A2 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A3 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A4 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A5 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A6 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            A7 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B0 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B1 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B2 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B3 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B4 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(0)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B5 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B6 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(1)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            B7 = (BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >((BInteger(0)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(1)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(2)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(3)), (BInteger(1)).negative())), (BTuple<BInteger, BInteger >((BInteger(4)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(5)), (BInteger(0)))), (BTuple<BInteger, BInteger >((BInteger(6)), (BInteger(0))))));
            LA = (BInteger(7));
            LB = (BInteger(7));
            if(!((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(((T0.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T0.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T0.isFunction()))._and((T0.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue() && ((T1.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T1.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T1.isFunction()))._and((T1.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T2.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T2.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T2.isFunction()))._and((T2.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T3.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T3.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T3.isFunction()))._and((T3.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T4.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T4.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T4.isFunction()))._and((T4.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T5.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T5.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T5.isFunction()))._and((T5.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T6.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T6.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T6.isFunction()))._and((T6.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((T7.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((T7.checkRange((BSet<BInteger>::interval((BInteger(1)),(BInteger(27)))))))._and((T7.isFunction()))._and((T7.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A0.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A0.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A0.isFunction()))._and((A0.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A1.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A1.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A1.isFunction()))._and((A1.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A2.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A2.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A2.isFunction()))._and((A2.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A3.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A3.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A3.isFunction()))._and((A3.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A4.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A4.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A4.isFunction()))._and((A4.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A5.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A5.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A5.isFunction()))._and((A5.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A6.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A6.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A6.isFunction()))._and((A6.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((A7.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((A7.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((A7.isFunction()))._and((A7.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B0.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B0.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B0.isFunction()))._and((B0.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B1.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B1.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B1.isFunction()))._and((B1.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B2.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B2.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B2.isFunction()))._and((B2.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B3.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B3.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B3.isFunction()))._and((B3.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B4.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B4.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B4.isFunction()))._and((B4.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B5.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B5.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B5.isFunction()))._and((B5.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B6.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B6.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B6.isFunction()))._and((B6.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && ((B7.checkDomain((BSet<BInteger>::interval((BInteger(0)),(BInteger(6))))))._and((B7.checkRange((BSet<BInteger>::interval((BInteger(1)).negative(),(BInteger(1)))))))._and((B7.isFunction()))._and((B7.isTotal((BSet<BInteger>::interval((BInteger(0)),(BInteger(6)))))))).booleanValue())).booleanValue() && T0.functionCall((BInteger(0))).equal((BInteger(1))).booleanValue())).booleanValue() && T0.functionCall((BInteger(1))).equal((BInteger(9))).booleanValue())).booleanValue() && T0.functionCall((BInteger(2))).equal((BInteger(10))).booleanValue())).booleanValue() && T0.functionCall((BInteger(3))).equal((BInteger(13))).booleanValue())).booleanValue() && T0.functionCall((BInteger(4))).equal((BInteger(15))).booleanValue())).booleanValue() && T0.functionCall((BInteger(5))).equal((BInteger(20))).booleanValue())).booleanValue() && T0.functionCall((BInteger(6))).equal((BInteger(23))).booleanValue())).booleanValue() && T1.functionCall((BInteger(0))).equal((BInteger(3))).booleanValue())).booleanValue() && T1.functionCall((BInteger(1))).equal((BInteger(9))).booleanValue())).booleanValue() && T1.functionCall((BInteger(2))).equal((BInteger(10))).booleanValue())).booleanValue() && T1.functionCall((BInteger(3))).equal((BInteger(13))).booleanValue())).booleanValue() && T1.functionCall((BInteger(4))).equal((BInteger(15))).booleanValue())).booleanValue() && T1.functionCall((BInteger(5))).equal((BInteger(20))).booleanValue())).booleanValue() && T1.functionCall((BInteger(6))).equal((BInteger(24))).booleanValue())).booleanValue() && T2.functionCall((BInteger(0))).equal((BInteger(5))).booleanValue())).booleanValue() && T2.functionCall((BInteger(1))).equal((BInteger(27))).booleanValue())).booleanValue() && T2.functionCall((BInteger(2))).equal((BInteger(11))).booleanValue())).booleanValue() && T2.functionCall((BInteger(3))).equal((BInteger(13))).booleanValue())).booleanValue() && T2.functionCall((BInteger(4))).equal((BInteger(16))).booleanValue())).booleanValue() && T2.functionCall((BInteger(5))).equal((BInteger(20))).booleanValue())).booleanValue() && T2.functionCall((BInteger(6))).equal((BInteger(25))).booleanValue())).booleanValue() && T3.functionCall((BInteger(0))).equal((BInteger(7))).booleanValue())).booleanValue() && T3.functionCall((BInteger(1))).equal((BInteger(27))).booleanValue())).booleanValue() && T3.functionCall((BInteger(2))).equal((BInteger(11))).booleanValue())).booleanValue() && T3.functionCall((BInteger(3))).equal((BInteger(13))).booleanValue())).booleanValue() && T3.functionCall((BInteger(4))).equal((BInteger(16))).booleanValue())).booleanValue() && T3.functionCall((BInteger(5))).equal((BInteger(20))).booleanValue())).booleanValue() && T3.functionCall((BInteger(6))).equal((BInteger(26))).booleanValue())).booleanValue() && T4.functionCall((BInteger(0))).equal((BInteger(23))).booleanValue())).booleanValue() && T4.functionCall((BInteger(1))).equal((BInteger(22))).booleanValue())).booleanValue() && T4.functionCall((BInteger(2))).equal((BInteger(17))).booleanValue())).booleanValue() && T4.functionCall((BInteger(3))).equal((BInteger(18))).booleanValue())).booleanValue() && T4.functionCall((BInteger(4))).equal((BInteger(11))).booleanValue())).booleanValue() && T4.functionCall((BInteger(5))).equal((BInteger(9))).booleanValue())).booleanValue() && T4.functionCall((BInteger(6))).equal((BInteger(2))).booleanValue())).booleanValue() && T5.functionCall((BInteger(0))).equal((BInteger(24))).booleanValue())).booleanValue() && T5.functionCall((BInteger(1))).equal((BInteger(22))).booleanValue())).booleanValue() && T5.functionCall((BInteger(2))).equal((BInteger(17))).booleanValue())).booleanValue() && T5.functionCall((BInteger(3))).equal((BInteger(18))).booleanValue())).booleanValue() && T5.functionCall((BInteger(4))).equal((BInteger(11))).booleanValue())).booleanValue() && T5.functionCall((BInteger(5))).equal((BInteger(9))).booleanValue())).booleanValue() && T5.functionCall((BInteger(6))).equal((BInteger(4))).booleanValue())).booleanValue() && T6.functionCall((BInteger(0))).equal((BInteger(25))).booleanValue())).booleanValue() && T6.functionCall((BInteger(1))).equal((BInteger(22))).booleanValue())).booleanValue() && T6.functionCall((BInteger(2))).equal((BInteger(17))).booleanValue())).booleanValue() && T6.functionCall((BInteger(3))).equal((BInteger(18))).booleanValue())).booleanValue() && T6.functionCall((BInteger(4))).equal((BInteger(12))).booleanValue())).booleanValue() && T6.functionCall((BInteger(5))).equal((BInteger(27))).booleanValue())).booleanValue() && T6.functionCall((BInteger(6))).equal((BInteger(6))).booleanValue())).booleanValue() && T7.functionCall((BInteger(0))).equal((BInteger(26))).booleanValue())).booleanValue() && T7.functionCall((BInteger(1))).equal((BInteger(22))).booleanValue())).booleanValue() && T7.functionCall((BInteger(2))).equal((BInteger(17))).booleanValue())).booleanValue() && T7.functionCall((BInteger(3))).equal((BInteger(18))).booleanValue())).booleanValue() && T7.functionCall((BInteger(4))).equal((BInteger(12))).booleanValue())).booleanValue() && T7.functionCall((BInteger(5))).equal((BInteger(27))).booleanValue())).booleanValue() && T7.functionCall((BInteger(6))).equal((BInteger(8))).booleanValue())).booleanValue() && A0.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A0.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && A0.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A0.functionCall((BInteger(3))).equal((BInteger(1))).booleanValue())).booleanValue() && A0.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A0.functionCall((BInteger(5))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A0.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A1.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A1.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && A1.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A1.functionCall((BInteger(3))).equal((BInteger(1))).booleanValue())).booleanValue() && A1.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A1.functionCall((BInteger(5))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A1.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A2.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A2.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && A2.functionCall((BInteger(2))).equal((BInteger(1))).booleanValue())).booleanValue() && A2.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A2.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A2.functionCall((BInteger(5))).equal((BInteger(1))).booleanValue())).booleanValue() && A2.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A3.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A3.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && A3.functionCall((BInteger(2))).equal((BInteger(1))).booleanValue())).booleanValue() && A3.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A3.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A3.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && A3.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A4.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A4.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && A4.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A4.functionCall((BInteger(3))).equal((BInteger(0))).booleanValue())).booleanValue() && A4.functionCall((BInteger(4))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A4.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && A4.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A5.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A5.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && A5.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A5.functionCall((BInteger(3))).equal((BInteger(0))).booleanValue())).booleanValue() && A5.functionCall((BInteger(4))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A5.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && A5.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A6.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && A6.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && A7.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && A7.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && A7.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && A7.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && A7.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && A7.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && A7.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B0.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B0.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && B0.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B0.functionCall((BInteger(3))).equal((BInteger(1))).booleanValue())).booleanValue() && B0.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B0.functionCall((BInteger(5))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B0.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B1.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B1.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && B1.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B1.functionCall((BInteger(3))).equal((BInteger(1))).booleanValue())).booleanValue() && B1.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B1.functionCall((BInteger(5))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B1.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B2.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B2.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && B2.functionCall((BInteger(2))).equal((BInteger(1))).booleanValue())).booleanValue() && B2.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B2.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B2.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && B2.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B3.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B3.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && B3.functionCall((BInteger(2))).equal((BInteger(1))).booleanValue())).booleanValue() && B3.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B3.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B3.functionCall((BInteger(5))).equal((BInteger(1))).booleanValue())).booleanValue() && B3.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B4.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B4.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && B4.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B4.functionCall((BInteger(3))).equal((BInteger(0)).negative()).booleanValue())).booleanValue() && B4.functionCall((BInteger(4))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B4.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && B4.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B5.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B5.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && B5.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B5.functionCall((BInteger(3))).equal((BInteger(0))).booleanValue())).booleanValue() && B5.functionCall((BInteger(4))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B5.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && B5.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B6.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B6.functionCall((BInteger(1))).equal((BInteger(1))).booleanValue())).booleanValue() && B6.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B6.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B6.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B6.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && B6.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(0))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(1))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(2))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(3))).equal((BInteger(1)).negative()).booleanValue())).booleanValue() && B7.functionCall((BInteger(4))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(5))).equal((BInteger(0))).booleanValue())).booleanValue() && B7.functionCall((BInteger(6))).equal((BInteger(0))).booleanValue()))).booleanValue()) {
                throw std::runtime_error("Contradiction in PROPERTIES detected!");
            }
            P0 = (BInteger(0));
            P1 = (BInteger(0));
            P2 = (BInteger(0));
            P3 = (BInteger(0));
            P4 = (BInteger(0));
            P5 = (BInteger(0));
            P6 = (BInteger(0));
            P7 = (BInteger(0));
            RA = (BInteger(1));
            RB = (BInteger(1));
        }

        prob_oneway8seq(const BRelation<BInteger, BInteger >& T0, const BRelation<BInteger, BInteger >& T1, const BRelation<BInteger, BInteger >& T2, const BRelation<BInteger, BInteger >& T3, const BRelation<BInteger, BInteger >& T4, const BRelation<BInteger, BInteger >& T5, const BRelation<BInteger, BInteger >& T6, const BRelation<BInteger, BInteger >& T7, const BRelation<BInteger, BInteger >& A0, const BRelation<BInteger, BInteger >& A1, const BRelation<BInteger, BInteger >& A2, const BRelation<BInteger, BInteger >& A3, const BRelation<BInteger, BInteger >& A4, const BRelation<BInteger, BInteger >& A5, const BRelation<BInteger, BInteger >& A6, const BRelation<BInteger, BInteger >& A7, const BRelation<BInteger, BInteger >& B0, const BRelation<BInteger, BInteger >& B1, const BRelation<BInteger, BInteger >& B2, const BRelation<BInteger, BInteger >& B3, const BRelation<BInteger, BInteger >& B4, const BRelation<BInteger, BInteger >& B5, const BRelation<BInteger, BInteger >& B6, const BRelation<BInteger, BInteger >& B7, const BInteger& LA, const BInteger& LB, const BInteger& P0, const BInteger& P1, const BInteger& P2, const BInteger& P3, const BInteger& P4, const BInteger& P5, const BInteger& P6, const BInteger& P7, const BInteger& RA, const BInteger& RB) {
            this->T0 = T0;
            this->T1 = T1;
            this->T2 = T2;
            this->T3 = T3;
            this->T4 = T4;
            this->T5 = T5;
            this->T6 = T6;
            this->T7 = T7;
            this->A0 = A0;
            this->A1 = A1;
            this->A2 = A2;
            this->A3 = A3;
            this->A4 = A4;
            this->A5 = A5;
            this->A6 = A6;
            this->A7 = A7;
            this->B0 = B0;
            this->B1 = B1;
            this->B2 = B2;
            this->B3 = B3;
            this->B4 = B4;
            this->B5 = B5;
            this->B6 = B6;
            this->B7 = B7;
            this->LA = LA;
            this->LB = LB;
            this->P0 = P0;
            this->P1 = P1;
            this->P2 = P2;
            this->P3 = P3;
            this->P4 = P4;
            this->P5 = P5;
            this->P6 = P6;
            this->P7 = P7;
            this->RA = RA;
            this->RB = RB;
        }

        void move0() {
            P0 = P0.plus((BInteger(1)));
            RA = RA.plus(A0.functionCall(P0));
            RB = RB.plus(B0.functionCall(P0));

        }

        void move1() {
            P1 = P1.plus((BInteger(1)));
            RA = RA.plus(A1.functionCall(P1));
            RB = RB.plus(B1.functionCall(P1));

        }

        void move2() {
            P2 = P2.plus((BInteger(1)));
            RA = RA.plus(A2.functionCall(P2));
            RB = RB.plus(B2.functionCall(P2));

        }

        void move3() {
            P3 = P3.plus((BInteger(1)));
            RA = RA.plus(A3.functionCall(P3));
            RB = RB.plus(B3.functionCall(P3));

        }

        void move4() {
            P4 = P4.plus((BInteger(1)));
            RA = RA.plus(A4.functionCall(P4));
            RB = RB.plus(B4.functionCall(P4));

        }

        void move5() {
            P5 = P5.plus((BInteger(1)));
            RA = RA.plus(A5.functionCall(P5));
            RB = RB.plus(B5.functionCall(P5));

        }

        void move6() {
            P6 = P6.plus((BInteger(1)));
            RA = RA.plus(A6.functionCall(P6));
            RB = RB.plus(B6.functionCall(P6));

        }

        void move7() {
            P7 = P7.plus((BInteger(1)));
            RA = RA.plus(A7.functionCall(P7));
            RB = RB.plus(B7.functionCall(P7));

        }

        void arrived() {
        }

        BRelation<BInteger, BInteger > _get_T0() const {
            return T0;
        }

        BRelation<BInteger, BInteger > _get_T1() const {
            return T1;
        }

        BRelation<BInteger, BInteger > _get_T2() const {
            return T2;
        }

        BRelation<BInteger, BInteger > _get_T3() const {
            return T3;
        }

        BRelation<BInteger, BInteger > _get_T4() const {
            return T4;
        }

        BRelation<BInteger, BInteger > _get_T5() const {
            return T5;
        }

        BRelation<BInteger, BInteger > _get_T6() const {
            return T6;
        }

        BRelation<BInteger, BInteger > _get_T7() const {
            return T7;
        }

        BRelation<BInteger, BInteger > _get_A0() const {
            return A0;
        }

        BRelation<BInteger, BInteger > _get_A1() const {
            return A1;
        }

        BRelation<BInteger, BInteger > _get_A2() const {
            return A2;
        }

        BRelation<BInteger, BInteger > _get_A3() const {
            return A3;
        }

        BRelation<BInteger, BInteger > _get_A4() const {
            return A4;
        }

        BRelation<BInteger, BInteger > _get_A5() const {
            return A5;
        }

        BRelation<BInteger, BInteger > _get_A6() const {
            return A6;
        }

        BRelation<BInteger, BInteger > _get_A7() const {
            return A7;
        }

        BRelation<BInteger, BInteger > _get_B0() const {
            return B0;
        }

        BRelation<BInteger, BInteger > _get_B1() const {
            return B1;
        }

        BRelation<BInteger, BInteger > _get_B2() const {
            return B2;
        }

        BRelation<BInteger, BInteger > _get_B3() const {
            return B3;
        }

        BRelation<BInteger, BInteger > _get_B4() const {
            return B4;
        }

        BRelation<BInteger, BInteger > _get_B5() const {
            return B5;
        }

        BRelation<BInteger, BInteger > _get_B6() const {
            return B6;
        }

        BRelation<BInteger, BInteger > _get_B7() const {
            return B7;
        }

        BInteger _get_LA() const {
            return LA;
        }

        BInteger _get_LB() const {
            return LB;
        }

        BInteger _get_P0() const {
            return P0;
        }

        BInteger _get_P1() const {
            return P1;
        }

        BInteger _get_P2() const {
            return P2;
        }

        BInteger _get_P3() const {
            return P3;
        }

        BInteger _get_P4() const {
            return P4;
        }

        BInteger _get_P5() const {
            return P5;
        }

        BInteger _get_P6() const {
            return P6;
        }

        BInteger _get_P7() const {
            return P7;
        }

        BInteger _get_RA() const {
            return RA;
        }

        BInteger _get_RB() const {
            return RB;
        }


        bool _tr_move0() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P0.less((BInteger(6))).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T0.functionCall(P0.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A0.functionCall(P0.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B0.functionCall(P0.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move1() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P1.less((BInteger(6))).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T1.functionCall(P1.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A1.functionCall(P1.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B1.functionCall(P1.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move2() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P2.less((BInteger(6))).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T2.functionCall(P2.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A2.functionCall(P2.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B2.functionCall(P2.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move3() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P3.less((BInteger(6))).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T3.functionCall(P3.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A3.functionCall(P3.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B3.functionCall(P3.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move4() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P4.less((BInteger(6))).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T4.functionCall(P4.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A4.functionCall(P4.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B4.functionCall(P4.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move5() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P5.less((BInteger(6))).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && T5.functionCall(P5.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A5.functionCall(P5.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B5.functionCall(P5.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move6() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P6.less((BInteger(6))).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T6.functionCall(P6.plus((BInteger(1)))).unequal(T7.functionCall(P7)).booleanValue())).booleanValue() && RA.plus(A6.functionCall(P6.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B6.functionCall(P6.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_move7() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P7.less((BInteger(6))).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T0.functionCall(P0)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T1.functionCall(P1)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T2.functionCall(P2)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T3.functionCall(P3)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T4.functionCall(P4)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T5.functionCall(P5)).booleanValue())).booleanValue() && T7.functionCall(P7.plus((BInteger(1)))).unequal(T6.functionCall(P6)).booleanValue())).booleanValue() && RA.plus(A7.functionCall(P7.plus((BInteger(1))))).lessEqual(LA).booleanValue())).booleanValue() && RB.plus(B7.functionCall(P7.plus((BInteger(1))))).lessEqual(LB).booleanValue()))).booleanValue();
        }

        bool _tr_arrived() const {
            return ((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(P0.equal((BInteger(6))).booleanValue() && P1.equal((BInteger(6))).booleanValue())).booleanValue() && P2.equal((BInteger(6))).booleanValue())).booleanValue() && P3.equal((BInteger(6))).booleanValue())).booleanValue() && P4.equal((BInteger(6))).booleanValue())).booleanValue() && P5.equal((BInteger(6))).booleanValue())).booleanValue() && P6.equal((BInteger(6))).booleanValue())).booleanValue() && P7.equal((BInteger(6))).booleanValue()))).booleanValue();
        }

        _ProjectionRead_move5 _projected_state_for_move5() const {
            return _ProjectionRead_move5(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move6 _projected_state_for_move6() const {
            return _ProjectionRead_move6(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_arrived _projected_state_for_arrived() const {
            return _ProjectionRead_arrived(P0,P1,P2,P3,P4,P5,P6,P7);
        }

        _ProjectionRead_move7 _projected_state_for_move7() const {
            return _ProjectionRead_move7(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move1 _projected_state_for_move1() const {
            return _ProjectionRead_move1(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move2 _projected_state_for_move2() const {
            return _ProjectionRead_move2(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move3 _projected_state_for_move3() const {
            return _ProjectionRead_move3(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move4 _projected_state_for_move4() const {
            return _ProjectionRead_move4(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead_move0 _projected_state_for_move0() const {
            return _ProjectionRead_move0(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move7 _projected_state_for__tr_move7() const {
            return _ProjectionRead__tr_move7(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_arrived _projected_state_for__tr_arrived() const {
            return _ProjectionRead__tr_arrived(P0,P1,P2,P3,P4,P5,P6,P7);
        }

        _ProjectionRead__tr_move3 _projected_state_for__tr_move3() const {
            return _ProjectionRead__tr_move3(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move4 _projected_state_for__tr_move4() const {
            return _ProjectionRead__tr_move4(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move5 _projected_state_for__tr_move5() const {
            return _ProjectionRead__tr_move5(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move6 _projected_state_for__tr_move6() const {
            return _ProjectionRead__tr_move6(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move0 _projected_state_for__tr_move0() const {
            return _ProjectionRead__tr_move0(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move1 _projected_state_for__tr_move1() const {
            return _ProjectionRead__tr_move1(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__tr_move2 _projected_state_for__tr_move2() const {
            return _ProjectionRead__tr_move2(P0,P1,P2,P3,P4,P5,P6,P7,RA,RB);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(P1);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(P2);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(P0);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(P5);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(RB);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(P6);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(P3);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(P4);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(P7);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(RA);
        }

        _ProjectionWrite_move5 _update_for_move5() const {
            return _ProjectionWrite_move5(RB,P5,RA);
        }

        _ProjectionWrite_move6 _update_for_move6() const {
            return _ProjectionWrite_move6(RB,P6,RA);
        }

        _ProjectionWrite_arrived _update_for_arrived() const {
            return _ProjectionWrite_arrived();
        }

        _ProjectionWrite_move7 _update_for_move7() const {
            return _ProjectionWrite_move7(RB,P7,RA);
        }

        _ProjectionWrite_move1 _update_for_move1() const {
            return _ProjectionWrite_move1(RB,P1,RA);
        }

        _ProjectionWrite_move2 _update_for_move2() const {
            return _ProjectionWrite_move2(RB,P2,RA);
        }

        _ProjectionWrite_move3 _update_for_move3() const {
            return _ProjectionWrite_move3(RB,P3,RA);
        }

        _ProjectionWrite_move4 _update_for_move4() const {
            return _ProjectionWrite_move4(RB,P4,RA);
        }

        _ProjectionWrite_move0 _update_for_move0() const {
            return _ProjectionWrite_move0(P0,RB,RA);
        }

        void _apply_update_for_move5(const _ProjectionWrite_move5& update) {
            this->RB = update.RB;
            this->P5 = update.P5;
            this->RA = update.RA;
        }

        void _apply_update_for_move6(const _ProjectionWrite_move6& update) {
            this->RB = update.RB;
            this->P6 = update.P6;
            this->RA = update.RA;
        }

        void _apply_update_for_arrived(const _ProjectionWrite_arrived& update) {
        }

        void _apply_update_for_move7(const _ProjectionWrite_move7& update) {
            this->RB = update.RB;
            this->P7 = update.P7;
            this->RA = update.RA;
        }

        void _apply_update_for_move1(const _ProjectionWrite_move1& update) {
            this->RB = update.RB;
            this->P1 = update.P1;
            this->RA = update.RA;
        }

        void _apply_update_for_move2(const _ProjectionWrite_move2& update) {
            this->RB = update.RB;
            this->P2 = update.P2;
            this->RA = update.RA;
        }

        void _apply_update_for_move3(const _ProjectionWrite_move3& update) {
            this->RB = update.RB;
            this->P3 = update.P3;
            this->RA = update.RA;
        }

        void _apply_update_for_move4(const _ProjectionWrite_move4& update) {
            this->RB = update.RB;
            this->P4 = update.P4;
            this->RA = update.RA;
        }

        void _apply_update_for_move0(const _ProjectionWrite_move0& update) {
            this->P0 = update.P0;
            this->RB = update.RB;
            this->RA = update.RA;
        }

        bool _check_inv_1() const {
            return ((BBoolean(P0.greaterEqual((BInteger(0))).booleanValue() && P0.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_2() const {
            return ((BBoolean(P1.greaterEqual((BInteger(0))).booleanValue() && P1.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_3() const {
            return ((BBoolean(P2.greaterEqual((BInteger(0))).booleanValue() && P2.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_4() const {
            return ((BBoolean(P3.greaterEqual((BInteger(0))).booleanValue() && P3.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_5() const {
            return ((BBoolean(P4.greaterEqual((BInteger(0))).booleanValue() && P4.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_6() const {
            return ((BBoolean(P5.greaterEqual((BInteger(0))).booleanValue() && P5.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_7() const {
            return ((BBoolean(P6.greaterEqual((BInteger(0))).booleanValue() && P6.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_8() const {
            return ((BBoolean(P7.greaterEqual((BInteger(0))).booleanValue() && P7.lessEqual((BInteger(6))).booleanValue()))).booleanValue();
        }

        bool _check_inv_9() const {
            return ((BBoolean(RA.greaterEqual((BInteger(0))).booleanValue() && RA.lessEqual((BInteger(8))).booleanValue()))).booleanValue();
        }

        bool _check_inv_10() const {
            return ((BBoolean(RB.greaterEqual((BInteger(0))).booleanValue() && RB.lessEqual((BInteger(8))).booleanValue()))).booleanValue();
        }

        prob_oneway8seq _copy() const {
            return prob_oneway8seq(T0, T1, T2, T3, T4, T5, T6, T7, A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, B2, B3, B4, B5, B6, B7, LA, LB, P0, P1, P2, P3, P4, P5, P6, P7, RA, RB);
        }

        friend bool operator ==(const prob_oneway8seq& o1, const prob_oneway8seq& o2) {
            return o1._get_P0() == o2._get_P0() && o1._get_P1() == o2._get_P1() && o1._get_P2() == o2._get_P2() && o1._get_P3() == o2._get_P3() && o1._get_P4() == o2._get_P4() && o1._get_P5() == o2._get_P5() && o1._get_P6() == o2._get_P6() && o1._get_P7() == o2._get_P7() && o1._get_RA() == o2._get_RA() && o1._get_RB() == o2._get_RB();
        }

        friend bool operator !=(const prob_oneway8seq& o1, const prob_oneway8seq& o2) {
            return o1._get_P0() != o2._get_P0() || o1._get_P1() != o2._get_P1() || o1._get_P2() != o2._get_P2() || o1._get_P3() != o2._get_P3() || o1._get_P4() != o2._get_P4() || o1._get_P5() != o2._get_P5() || o1._get_P6() != o2._get_P6() || o1._get_P7() != o2._get_P7() || o1._get_RA() != o2._get_RA() || o1._get_RB() != o2._get_RB();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_P0()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P1()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P2()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P3()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P4()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P5()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P6()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_P7()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_RA()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_RB()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_P0()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P1()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P2()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P3()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P4()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P5()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P6()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_P7()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_RA()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_RB()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const prob_oneway8seq &machine) {
          strm << "_get_P0: " << machine._get_P0() << "\n";
          strm << "_get_P1: " << machine._get_P1() << "\n";
          strm << "_get_P2: " << machine._get_P2() << "\n";
          strm << "_get_P3: " << machine._get_P3() << "\n";
          strm << "_get_P4: " << machine._get_P4() << "\n";
          strm << "_get_P5: " << machine._get_P5() << "\n";
          strm << "_get_P6: " << machine._get_P6() << "\n";
          strm << "_get_P7: " << machine._get_P7() << "\n";
          strm << "_get_RA: " << machine._get_RA() << "\n";
          strm << "_get_RB: " << machine._get_RB() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        prob_oneway8seq::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<prob_oneway8seq> unvisitedStates;
        std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        prob_oneway8seq counterExampleState;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move0, prob_oneway8seq::_ProjectionWrite_move0, prob_oneway8seq::_ProjectionRead_move0::Hash, prob_oneway8seq::_ProjectionRead_move0::HashEqual>> _OpCache_move0;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move0, bool, prob_oneway8seq::_ProjectionRead__tr_move0::Hash, prob_oneway8seq::_ProjectionRead__tr_move0::HashEqual> _OpCache_tr_move0;
        std::mutex _ProjectionRead_move0_mutex;
        std::mutex _ProjectionRead__tr_move0_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move1, prob_oneway8seq::_ProjectionWrite_move1, prob_oneway8seq::_ProjectionRead_move1::Hash, prob_oneway8seq::_ProjectionRead_move1::HashEqual>> _OpCache_move1;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move1, bool, prob_oneway8seq::_ProjectionRead__tr_move1::Hash, prob_oneway8seq::_ProjectionRead__tr_move1::HashEqual> _OpCache_tr_move1;
        std::mutex _ProjectionRead_move1_mutex;
        std::mutex _ProjectionRead__tr_move1_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move2, prob_oneway8seq::_ProjectionWrite_move2, prob_oneway8seq::_ProjectionRead_move2::Hash, prob_oneway8seq::_ProjectionRead_move2::HashEqual>> _OpCache_move2;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move2, bool, prob_oneway8seq::_ProjectionRead__tr_move2::Hash, prob_oneway8seq::_ProjectionRead__tr_move2::HashEqual> _OpCache_tr_move2;
        std::mutex _ProjectionRead_move2_mutex;
        std::mutex _ProjectionRead__tr_move2_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move3, prob_oneway8seq::_ProjectionWrite_move3, prob_oneway8seq::_ProjectionRead_move3::Hash, prob_oneway8seq::_ProjectionRead_move3::HashEqual>> _OpCache_move3;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move3, bool, prob_oneway8seq::_ProjectionRead__tr_move3::Hash, prob_oneway8seq::_ProjectionRead__tr_move3::HashEqual> _OpCache_tr_move3;
        std::mutex _ProjectionRead_move3_mutex;
        std::mutex _ProjectionRead__tr_move3_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move4, prob_oneway8seq::_ProjectionWrite_move4, prob_oneway8seq::_ProjectionRead_move4::Hash, prob_oneway8seq::_ProjectionRead_move4::HashEqual>> _OpCache_move4;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move4, bool, prob_oneway8seq::_ProjectionRead__tr_move4::Hash, prob_oneway8seq::_ProjectionRead__tr_move4::HashEqual> _OpCache_tr_move4;
        std::mutex _ProjectionRead_move4_mutex;
        std::mutex _ProjectionRead__tr_move4_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move5, prob_oneway8seq::_ProjectionWrite_move5, prob_oneway8seq::_ProjectionRead_move5::Hash, prob_oneway8seq::_ProjectionRead_move5::HashEqual>> _OpCache_move5;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move5, bool, prob_oneway8seq::_ProjectionRead__tr_move5::Hash, prob_oneway8seq::_ProjectionRead__tr_move5::HashEqual> _OpCache_tr_move5;
        std::mutex _ProjectionRead_move5_mutex;
        std::mutex _ProjectionRead__tr_move5_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move6, prob_oneway8seq::_ProjectionWrite_move6, prob_oneway8seq::_ProjectionRead_move6::Hash, prob_oneway8seq::_ProjectionRead_move6::HashEqual>> _OpCache_move6;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move6, bool, prob_oneway8seq::_ProjectionRead__tr_move6::Hash, prob_oneway8seq::_ProjectionRead__tr_move6::HashEqual> _OpCache_tr_move6;
        std::mutex _ProjectionRead_move6_mutex;
        std::mutex _ProjectionRead__tr_move6_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_move7, prob_oneway8seq::_ProjectionWrite_move7, prob_oneway8seq::_ProjectionRead_move7::Hash, prob_oneway8seq::_ProjectionRead_move7::HashEqual>> _OpCache_move7;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_move7, bool, prob_oneway8seq::_ProjectionRead__tr_move7::Hash, prob_oneway8seq::_ProjectionRead__tr_move7::HashEqual> _OpCache_tr_move7;
        std::mutex _ProjectionRead_move7_mutex;
        std::mutex _ProjectionRead__tr_move7_mutex;

        std::unordered_map<bool, std::unordered_map<prob_oneway8seq::_ProjectionRead_arrived, prob_oneway8seq::_ProjectionWrite_arrived, prob_oneway8seq::_ProjectionRead_arrived::Hash, prob_oneway8seq::_ProjectionRead_arrived::HashEqual>> _OpCache_arrived;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__tr_arrived, bool, prob_oneway8seq::_ProjectionRead__tr_arrived::Hash, prob_oneway8seq::_ProjectionRead__tr_arrived::HashEqual> _OpCache_tr_arrived;
        std::mutex _ProjectionRead_arrived_mutex;
        std::mutex _ProjectionRead__tr_arrived_mutex;

        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_1, bool, prob_oneway8seq::_ProjectionRead__check_inv_1::Hash, prob_oneway8seq::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_2, bool, prob_oneway8seq::_ProjectionRead__check_inv_2::Hash, prob_oneway8seq::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_3, bool, prob_oneway8seq::_ProjectionRead__check_inv_3::Hash, prob_oneway8seq::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_4, bool, prob_oneway8seq::_ProjectionRead__check_inv_4::Hash, prob_oneway8seq::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_5, bool, prob_oneway8seq::_ProjectionRead__check_inv_5::Hash, prob_oneway8seq::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_6, bool, prob_oneway8seq::_ProjectionRead__check_inv_6::Hash, prob_oneway8seq::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_7, bool, prob_oneway8seq::_ProjectionRead__check_inv_7::Hash, prob_oneway8seq::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_8, bool, prob_oneway8seq::_ProjectionRead__check_inv_8::Hash, prob_oneway8seq::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_9, bool, prob_oneway8seq::_ProjectionRead__check_inv_9::Hash, prob_oneway8seq::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<prob_oneway8seq::_ProjectionRead__check_inv_10, bool, prob_oneway8seq::_ProjectionRead__check_inv_10::Hash, prob_oneway8seq::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;

        std::unordered_map<prob_oneway8seq, prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(prob_oneway8seq::Type type, int threads, bool isCaching, bool isDebug) {
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
            prob_oneway8seq machine = prob_oneway8seq();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                prob_oneway8seq state = next();

                std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> nextStates = generateNextStates(state);

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
            prob_oneway8seq machine = prob_oneway8seq();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads;
            stopThreads = false;
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            std::atomic<bool> waitFlag;
            waitFlag = true;

            while(!unvisitedStates.empty() && !stopThreads) {
                possibleQueueChanges += 1;
                prob_oneway8seq state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> nextStates = generateNextStates(state);

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
                    if(unvisitedStates.empty() && possibleQueueChanges > 0) {
                        waitCV.wait(lock, [&] {
                            return waitFlag == false;
                        });
                    }
                }
            }
            workers.join();
            printResult();
        }


    private:
        prob_oneway8seq next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case prob_oneway8seq::BFS: {
                        prob_oneway8seq state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case prob_oneway8seq::DFS: {
                        prob_oneway8seq state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case prob_oneway8seq::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            prob_oneway8seq state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            prob_oneway8seq state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                prob_oneway8seq state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> generateNextStates(const prob_oneway8seq& state) {
            std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual> result = std::unordered_set<prob_oneway8seq, prob_oneway8seq::Hash, prob_oneway8seq::HashEqual>();
            if(isCaching) {
                prob_oneway8seq::_ProjectionRead__tr_move0 read__tr_move0_state = state._projected_state_for__tr_move0();
                bool _trid_1;
                auto _obj__trid_1_ptr = _OpCache_tr_move0.find(read__tr_move0_state);
                if(_obj__trid_1_ptr == _OpCache_tr_move0.end()) {
                    _trid_1 = state._tr_move0();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move0_lock(_ProjectionRead__tr_move0_mutex);
                        _OpCache_tr_move0.insert({read__tr_move0_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move0 readState = state._projected_state_for_move0();

                    auto _OpCache_with_parameter_move0_ptr = _OpCache_move0.find(_trid_1);
                    if(_OpCache_with_parameter_move0_ptr == _OpCache_move0.end()) {
                        copiedState.move0();
                        prob_oneway8seq::_ProjectionWrite_move0 writeState = copiedState._update_for_move0();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move0, prob_oneway8seq::_ProjectionWrite_move0, prob_oneway8seq::_ProjectionRead_move0::Hash, prob_oneway8seq::_ProjectionRead_move0::HashEqual> _OpCache_with_parameter_move0;
                        _OpCache_with_parameter_move0.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move0_lock(_ProjectionRead_move0_mutex);
                            _OpCache_move0.insert({_trid_1, _OpCache_with_parameter_move0});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move0, prob_oneway8seq::_ProjectionWrite_move0, prob_oneway8seq::_ProjectionRead_move0::Hash, prob_oneway8seq::_ProjectionRead_move0::HashEqual> _OpCache_with_parameter_move0 = _OpCache_with_parameter_move0_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move0.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move0.end()) {
                            prob_oneway8seq::_ProjectionWrite_move0 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move0(writeState);
                        } else {
                            copiedState.move0();
                            prob_oneway8seq::_ProjectionWrite_move0 writeState = copiedState._update_for_move0();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move0_lock(_ProjectionRead_move0_mutex);
                                _OpCache_with_parameter_move0.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move0";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move1 read__tr_move1_state = state._projected_state_for__tr_move1();
                bool _trid_2;
                auto _obj__trid_2_ptr = _OpCache_tr_move1.find(read__tr_move1_state);
                if(_obj__trid_2_ptr == _OpCache_tr_move1.end()) {
                    _trid_2 = state._tr_move1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move1_lock(_ProjectionRead__tr_move1_mutex);
                        _OpCache_tr_move1.insert({read__tr_move1_state, _trid_2});
                    }
                } else {
                    _trid_2 = _obj__trid_2_ptr->second;
                }
                if(_trid_2) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move1 readState = state._projected_state_for_move1();

                    auto _OpCache_with_parameter_move1_ptr = _OpCache_move1.find(_trid_2);
                    if(_OpCache_with_parameter_move1_ptr == _OpCache_move1.end()) {
                        copiedState.move1();
                        prob_oneway8seq::_ProjectionWrite_move1 writeState = copiedState._update_for_move1();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move1, prob_oneway8seq::_ProjectionWrite_move1, prob_oneway8seq::_ProjectionRead_move1::Hash, prob_oneway8seq::_ProjectionRead_move1::HashEqual> _OpCache_with_parameter_move1;
                        _OpCache_with_parameter_move1.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move1_lock(_ProjectionRead_move1_mutex);
                            _OpCache_move1.insert({_trid_2, _OpCache_with_parameter_move1});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move1, prob_oneway8seq::_ProjectionWrite_move1, prob_oneway8seq::_ProjectionRead_move1::Hash, prob_oneway8seq::_ProjectionRead_move1::HashEqual> _OpCache_with_parameter_move1 = _OpCache_with_parameter_move1_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move1.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move1.end()) {
                            prob_oneway8seq::_ProjectionWrite_move1 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move1(writeState);
                        } else {
                            copiedState.move1();
                            prob_oneway8seq::_ProjectionWrite_move1 writeState = copiedState._update_for_move1();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move1_lock(_ProjectionRead_move1_mutex);
                                _OpCache_with_parameter_move1.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move1";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move2 read__tr_move2_state = state._projected_state_for__tr_move2();
                bool _trid_3;
                auto _obj__trid_3_ptr = _OpCache_tr_move2.find(read__tr_move2_state);
                if(_obj__trid_3_ptr == _OpCache_tr_move2.end()) {
                    _trid_3 = state._tr_move2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move2_lock(_ProjectionRead__tr_move2_mutex);
                        _OpCache_tr_move2.insert({read__tr_move2_state, _trid_3});
                    }
                } else {
                    _trid_3 = _obj__trid_3_ptr->second;
                }
                if(_trid_3) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move2 readState = state._projected_state_for_move2();

                    auto _OpCache_with_parameter_move2_ptr = _OpCache_move2.find(_trid_3);
                    if(_OpCache_with_parameter_move2_ptr == _OpCache_move2.end()) {
                        copiedState.move2();
                        prob_oneway8seq::_ProjectionWrite_move2 writeState = copiedState._update_for_move2();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move2, prob_oneway8seq::_ProjectionWrite_move2, prob_oneway8seq::_ProjectionRead_move2::Hash, prob_oneway8seq::_ProjectionRead_move2::HashEqual> _OpCache_with_parameter_move2;
                        _OpCache_with_parameter_move2.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move2_lock(_ProjectionRead_move2_mutex);
                            _OpCache_move2.insert({_trid_3, _OpCache_with_parameter_move2});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move2, prob_oneway8seq::_ProjectionWrite_move2, prob_oneway8seq::_ProjectionRead_move2::Hash, prob_oneway8seq::_ProjectionRead_move2::HashEqual> _OpCache_with_parameter_move2 = _OpCache_with_parameter_move2_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move2.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move2.end()) {
                            prob_oneway8seq::_ProjectionWrite_move2 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move2(writeState);
                        } else {
                            copiedState.move2();
                            prob_oneway8seq::_ProjectionWrite_move2 writeState = copiedState._update_for_move2();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move2_lock(_ProjectionRead_move2_mutex);
                                _OpCache_with_parameter_move2.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move2";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move3 read__tr_move3_state = state._projected_state_for__tr_move3();
                bool _trid_4;
                auto _obj__trid_4_ptr = _OpCache_tr_move3.find(read__tr_move3_state);
                if(_obj__trid_4_ptr == _OpCache_tr_move3.end()) {
                    _trid_4 = state._tr_move3();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move3_lock(_ProjectionRead__tr_move3_mutex);
                        _OpCache_tr_move3.insert({read__tr_move3_state, _trid_4});
                    }
                } else {
                    _trid_4 = _obj__trid_4_ptr->second;
                }
                if(_trid_4) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move3 readState = state._projected_state_for_move3();

                    auto _OpCache_with_parameter_move3_ptr = _OpCache_move3.find(_trid_4);
                    if(_OpCache_with_parameter_move3_ptr == _OpCache_move3.end()) {
                        copiedState.move3();
                        prob_oneway8seq::_ProjectionWrite_move3 writeState = copiedState._update_for_move3();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move3, prob_oneway8seq::_ProjectionWrite_move3, prob_oneway8seq::_ProjectionRead_move3::Hash, prob_oneway8seq::_ProjectionRead_move3::HashEqual> _OpCache_with_parameter_move3;
                        _OpCache_with_parameter_move3.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move3_lock(_ProjectionRead_move3_mutex);
                            _OpCache_move3.insert({_trid_4, _OpCache_with_parameter_move3});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move3, prob_oneway8seq::_ProjectionWrite_move3, prob_oneway8seq::_ProjectionRead_move3::Hash, prob_oneway8seq::_ProjectionRead_move3::HashEqual> _OpCache_with_parameter_move3 = _OpCache_with_parameter_move3_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move3.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move3.end()) {
                            prob_oneway8seq::_ProjectionWrite_move3 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move3(writeState);
                        } else {
                            copiedState.move3();
                            prob_oneway8seq::_ProjectionWrite_move3 writeState = copiedState._update_for_move3();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move3_lock(_ProjectionRead_move3_mutex);
                                _OpCache_with_parameter_move3.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move3";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move4 read__tr_move4_state = state._projected_state_for__tr_move4();
                bool _trid_5;
                auto _obj__trid_5_ptr = _OpCache_tr_move4.find(read__tr_move4_state);
                if(_obj__trid_5_ptr == _OpCache_tr_move4.end()) {
                    _trid_5 = state._tr_move4();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move4_lock(_ProjectionRead__tr_move4_mutex);
                        _OpCache_tr_move4.insert({read__tr_move4_state, _trid_5});
                    }
                } else {
                    _trid_5 = _obj__trid_5_ptr->second;
                }
                if(_trid_5) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move4 readState = state._projected_state_for_move4();

                    auto _OpCache_with_parameter_move4_ptr = _OpCache_move4.find(_trid_5);
                    if(_OpCache_with_parameter_move4_ptr == _OpCache_move4.end()) {
                        copiedState.move4();
                        prob_oneway8seq::_ProjectionWrite_move4 writeState = copiedState._update_for_move4();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move4, prob_oneway8seq::_ProjectionWrite_move4, prob_oneway8seq::_ProjectionRead_move4::Hash, prob_oneway8seq::_ProjectionRead_move4::HashEqual> _OpCache_with_parameter_move4;
                        _OpCache_with_parameter_move4.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move4_lock(_ProjectionRead_move4_mutex);
                            _OpCache_move4.insert({_trid_5, _OpCache_with_parameter_move4});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move4, prob_oneway8seq::_ProjectionWrite_move4, prob_oneway8seq::_ProjectionRead_move4::Hash, prob_oneway8seq::_ProjectionRead_move4::HashEqual> _OpCache_with_parameter_move4 = _OpCache_with_parameter_move4_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move4.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move4.end()) {
                            prob_oneway8seq::_ProjectionWrite_move4 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move4(writeState);
                        } else {
                            copiedState.move4();
                            prob_oneway8seq::_ProjectionWrite_move4 writeState = copiedState._update_for_move4();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move4_lock(_ProjectionRead_move4_mutex);
                                _OpCache_with_parameter_move4.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move4";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move5 read__tr_move5_state = state._projected_state_for__tr_move5();
                bool _trid_6;
                auto _obj__trid_6_ptr = _OpCache_tr_move5.find(read__tr_move5_state);
                if(_obj__trid_6_ptr == _OpCache_tr_move5.end()) {
                    _trid_6 = state._tr_move5();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move5_lock(_ProjectionRead__tr_move5_mutex);
                        _OpCache_tr_move5.insert({read__tr_move5_state, _trid_6});
                    }
                } else {
                    _trid_6 = _obj__trid_6_ptr->second;
                }
                if(_trid_6) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move5 readState = state._projected_state_for_move5();

                    auto _OpCache_with_parameter_move5_ptr = _OpCache_move5.find(_trid_6);
                    if(_OpCache_with_parameter_move5_ptr == _OpCache_move5.end()) {
                        copiedState.move5();
                        prob_oneway8seq::_ProjectionWrite_move5 writeState = copiedState._update_for_move5();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move5, prob_oneway8seq::_ProjectionWrite_move5, prob_oneway8seq::_ProjectionRead_move5::Hash, prob_oneway8seq::_ProjectionRead_move5::HashEqual> _OpCache_with_parameter_move5;
                        _OpCache_with_parameter_move5.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move5_lock(_ProjectionRead_move5_mutex);
                            _OpCache_move5.insert({_trid_6, _OpCache_with_parameter_move5});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move5, prob_oneway8seq::_ProjectionWrite_move5, prob_oneway8seq::_ProjectionRead_move5::Hash, prob_oneway8seq::_ProjectionRead_move5::HashEqual> _OpCache_with_parameter_move5 = _OpCache_with_parameter_move5_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move5.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move5.end()) {
                            prob_oneway8seq::_ProjectionWrite_move5 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move5(writeState);
                        } else {
                            copiedState.move5();
                            prob_oneway8seq::_ProjectionWrite_move5 writeState = copiedState._update_for_move5();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move5_lock(_ProjectionRead_move5_mutex);
                                _OpCache_with_parameter_move5.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move5";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move6 read__tr_move6_state = state._projected_state_for__tr_move6();
                bool _trid_7;
                auto _obj__trid_7_ptr = _OpCache_tr_move6.find(read__tr_move6_state);
                if(_obj__trid_7_ptr == _OpCache_tr_move6.end()) {
                    _trid_7 = state._tr_move6();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move6_lock(_ProjectionRead__tr_move6_mutex);
                        _OpCache_tr_move6.insert({read__tr_move6_state, _trid_7});
                    }
                } else {
                    _trid_7 = _obj__trid_7_ptr->second;
                }
                if(_trid_7) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move6 readState = state._projected_state_for_move6();

                    auto _OpCache_with_parameter_move6_ptr = _OpCache_move6.find(_trid_7);
                    if(_OpCache_with_parameter_move6_ptr == _OpCache_move6.end()) {
                        copiedState.move6();
                        prob_oneway8seq::_ProjectionWrite_move6 writeState = copiedState._update_for_move6();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move6, prob_oneway8seq::_ProjectionWrite_move6, prob_oneway8seq::_ProjectionRead_move6::Hash, prob_oneway8seq::_ProjectionRead_move6::HashEqual> _OpCache_with_parameter_move6;
                        _OpCache_with_parameter_move6.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move6_lock(_ProjectionRead_move6_mutex);
                            _OpCache_move6.insert({_trid_7, _OpCache_with_parameter_move6});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move6, prob_oneway8seq::_ProjectionWrite_move6, prob_oneway8seq::_ProjectionRead_move6::Hash, prob_oneway8seq::_ProjectionRead_move6::HashEqual> _OpCache_with_parameter_move6 = _OpCache_with_parameter_move6_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move6.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move6.end()) {
                            prob_oneway8seq::_ProjectionWrite_move6 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move6(writeState);
                        } else {
                            copiedState.move6();
                            prob_oneway8seq::_ProjectionWrite_move6 writeState = copiedState._update_for_move6();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move6_lock(_ProjectionRead_move6_mutex);
                                _OpCache_with_parameter_move6.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move6";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_move7 read__tr_move7_state = state._projected_state_for__tr_move7();
                bool _trid_8;
                auto _obj__trid_8_ptr = _OpCache_tr_move7.find(read__tr_move7_state);
                if(_obj__trid_8_ptr == _OpCache_tr_move7.end()) {
                    _trid_8 = state._tr_move7();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_move7_lock(_ProjectionRead__tr_move7_mutex);
                        _OpCache_tr_move7.insert({read__tr_move7_state, _trid_8});
                    }
                } else {
                    _trid_8 = _obj__trid_8_ptr->second;
                }
                if(_trid_8) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_move7 readState = state._projected_state_for_move7();

                    auto _OpCache_with_parameter_move7_ptr = _OpCache_move7.find(_trid_8);
                    if(_OpCache_with_parameter_move7_ptr == _OpCache_move7.end()) {
                        copiedState.move7();
                        prob_oneway8seq::_ProjectionWrite_move7 writeState = copiedState._update_for_move7();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move7, prob_oneway8seq::_ProjectionWrite_move7, prob_oneway8seq::_ProjectionRead_move7::Hash, prob_oneway8seq::_ProjectionRead_move7::HashEqual> _OpCache_with_parameter_move7;
                        _OpCache_with_parameter_move7.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_move7_lock(_ProjectionRead_move7_mutex);
                            _OpCache_move7.insert({_trid_8, _OpCache_with_parameter_move7});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_move7, prob_oneway8seq::_ProjectionWrite_move7, prob_oneway8seq::_ProjectionRead_move7::Hash, prob_oneway8seq::_ProjectionRead_move7::HashEqual> _OpCache_with_parameter_move7 = _OpCache_with_parameter_move7_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_move7.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_move7.end()) {
                            prob_oneway8seq::_ProjectionWrite_move7 writeState = writeState_ptr->second;
                            copiedState._apply_update_for_move7(writeState);
                        } else {
                            copiedState.move7();
                            prob_oneway8seq::_ProjectionWrite_move7 writeState = copiedState._update_for_move7();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_move7_lock(_ProjectionRead_move7_mutex);
                                _OpCache_with_parameter_move7.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "move7";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                prob_oneway8seq::_ProjectionRead__tr_arrived read__tr_arrived_state = state._projected_state_for__tr_arrived();
                bool _trid_9;
                auto _obj__trid_9_ptr = _OpCache_tr_arrived.find(read__tr_arrived_state);
                if(_obj__trid_9_ptr == _OpCache_tr_arrived.end()) {
                    _trid_9 = state._tr_arrived();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_arrived_lock(_ProjectionRead__tr_arrived_mutex);
                        _OpCache_tr_arrived.insert({read__tr_arrived_state, _trid_9});
                    }
                } else {
                    _trid_9 = _obj__trid_9_ptr->second;
                }
                if(_trid_9) {
                    prob_oneway8seq copiedState = state._copy();
                    prob_oneway8seq::_ProjectionRead_arrived readState = state._projected_state_for_arrived();

                    auto _OpCache_with_parameter_arrived_ptr = _OpCache_arrived.find(_trid_9);
                    if(_OpCache_with_parameter_arrived_ptr == _OpCache_arrived.end()) {
                        copiedState.arrived();
                        prob_oneway8seq::_ProjectionWrite_arrived writeState = copiedState._update_for_arrived();
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_arrived, prob_oneway8seq::_ProjectionWrite_arrived, prob_oneway8seq::_ProjectionRead_arrived::Hash, prob_oneway8seq::_ProjectionRead_arrived::HashEqual> _OpCache_with_parameter_arrived;
                        _OpCache_with_parameter_arrived.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_arrived_lock(_ProjectionRead_arrived_mutex);
                            _OpCache_arrived.insert({_trid_9, _OpCache_with_parameter_arrived});
                        }

                    } else {
                        std::unordered_map<prob_oneway8seq::_ProjectionRead_arrived, prob_oneway8seq::_ProjectionWrite_arrived, prob_oneway8seq::_ProjectionRead_arrived::Hash, prob_oneway8seq::_ProjectionRead_arrived::HashEqual> _OpCache_with_parameter_arrived = _OpCache_with_parameter_arrived_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_arrived.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_arrived.end()) {
                            prob_oneway8seq::_ProjectionWrite_arrived writeState = writeState_ptr->second;
                            copiedState._apply_update_for_arrived(writeState);
                        } else {
                            copiedState.arrived();
                            prob_oneway8seq::_ProjectionWrite_arrived writeState = copiedState._update_for_arrived();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_arrived_lock(_ProjectionRead_arrived_mutex);
                                _OpCache_with_parameter_arrived.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "arrived";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            } else {
                if(state._tr_move0()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move0();
                    copiedState.stateAccessedVia = "move0";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move1()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move1();
                    copiedState.stateAccessedVia = "move1";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move2()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move2();
                    copiedState.stateAccessedVia = "move2";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move3()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move3();
                    copiedState.stateAccessedVia = "move3";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move4()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move4();
                    copiedState.stateAccessedVia = "move4";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move5()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move5();
                    copiedState.stateAccessedVia = "move5";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move6()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move6();
                    copiedState.stateAccessedVia = "move6";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_move7()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.move7();
                    copiedState.stateAccessedVia = "move7";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_arrived()) {
                    prob_oneway8seq copiedState = state._copy();
                    copiedState.arrived();
                    copiedState.stateAccessedVia = "arrived";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const prob_oneway8seq& state) {
            bool _check_inv_1;
            if(isCaching) {
                prob_oneway8seq::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
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
                prob_oneway8seq::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
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
                prob_oneway8seq::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
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
                prob_oneway8seq::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
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
                prob_oneway8seq::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
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
                prob_oneway8seq::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
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
                prob_oneway8seq::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
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
                prob_oneway8seq::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
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
                prob_oneway8seq::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
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
                prob_oneway8seq::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
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

    prob_oneway8seq::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = prob_oneway8seq::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = prob_oneway8seq::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = prob_oneway8seq::Type::DFS;
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