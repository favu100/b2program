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
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef Train_1_beebook_deterministic_MC_POR_v3_H
#define Train_1_beebook_deterministic_MC_POR_v3_H

using namespace std;

class Train_1_beebook_deterministic_MC_POR_v3 {

    public:

        enum Type { BFS, DFS, MIXED };

        class BLOCKS : public BObject {
            public:

                typedef BLOCKS current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum BLOCKS_type {
                    A, 
                    B, 
                    C, 
                    D, 
                    E, 
                    F, 
                    G, 
                    H, 
                    I, 
                    J, 
                    K, 
                    L, 
                    M, 
                    N
                };

                BLOCKS_type value;

                BLOCKS(){}

                BLOCKS(const BLOCKS_type& type) {
                    this->value = type;
                }

                BBoolean equal(const BLOCKS& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const BLOCKS& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const BLOCKS& p1, const BLOCKS& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const BLOCKS& p1, const BLOCKS& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const BLOCKS& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const BLOCKS& e) {
                    switch(e.value) {
                        case A: return strm << "A";
                        case B: return strm << "B";
                        case C: return strm << "C";
                        case D: return strm << "D";
                        case E: return strm << "E";
                        case F: return strm << "F";
                        case G: return strm << "G";
                        case H: return strm << "H";
                        case I: return strm << "I";
                        case J: return strm << "J";
                        case K: return strm << "K";
                        case L: return strm << "L";
                        case M: return strm << "M";
                        case N: return strm << "N";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class ROUTES : public BObject {
            public:

                typedef ROUTES current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum ROUTES_type {
                    R1, 
                    R2, 
                    R3, 
                    R4, 
                    R5, 
                    R6, 
                    R7, 
                    R8, 
                    R9, 
                    R10
                };

                ROUTES_type value;

                ROUTES(){}

                ROUTES(const ROUTES_type& type) {
                    this->value = type;
                }

                BBoolean equal(const ROUTES& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const ROUTES& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const ROUTES& p1, const ROUTES& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const ROUTES& p1, const ROUTES& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const ROUTES& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const ROUTES& e) {
                    switch(e.value) {
                        case R1: return strm << "R1";
                        case R2: return strm << "R2";
                        case R3: return strm << "R3";
                        case R4: return strm << "R4";
                        case R5: return strm << "R5";
                        case R6: return strm << "R6";
                        case R7: return strm << "R7";
                        case R8: return strm << "R8";
                        case R9: return strm << "R9";
                        case R10: return strm << "R10";
                    }
                    return strm;
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


        struct Hash {
            public:
                size_t operator()(const Train_1_beebook_deterministic_MC_POR_v3& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const Train_1_beebook_deterministic_MC_POR_v3& obj1, const Train_1_beebook_deterministic_MC_POR_v3& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_route_reservation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_route_reservation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_route_reservation& obj1, const _ProjectionRead_route_reservation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_route_reservation(const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_route_reservation& o1, const _ProjectionRead_route_reservation& o2) {
                    return o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_route_reservation& o1, const _ProjectionRead_route_reservation& o2) {
                    return o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_route_reservation& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_route_reservation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_route_reservation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_route_reservation& obj1, const _ProjectionRead__tr_route_reservation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_route_reservation(const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_route_reservation& o1, const _ProjectionRead__tr_route_reservation& o2) {
                    return o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_route_reservation& o1, const _ProjectionRead__tr_route_reservation& o2) {
                    return o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_route_reservation& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "resbl: " << e.resbl;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_route_reservation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_route_reservation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_route_reservation& obj1, const _ProjectionWrite_route_reservation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionWrite_route_reservation(const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionWrite_route_reservation& o1, const _ProjectionWrite_route_reservation& o2) {
                    return o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionWrite_route_reservation& o1, const _ProjectionWrite_route_reservation& o2) {
                    return o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_route_reservation& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_route_freeing {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_route_freeing& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_route_freeing& obj1, const _ProjectionRead_route_freeing& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_route_freeing(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_route_freeing& o1, const _ProjectionRead_route_freeing& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_route_freeing& o1, const _ProjectionRead_route_freeing& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_route_freeing& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_route_freeing {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_route_freeing& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_route_freeing& obj1, const _ProjectionRead__tr_route_freeing& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_route_freeing(const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_route_freeing& o1, const _ProjectionRead__tr_route_freeing& o2) {
                    return o1.resrt == (o2.resrt) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_route_freeing& o1, const _ProjectionRead__tr_route_freeing& o2) {
                    return o1.resrt != (o2.resrt) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_route_freeing& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_route_freeing {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_route_freeing& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_route_freeing& obj1, const _ProjectionWrite_route_freeing& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;

                _ProjectionWrite_route_freeing(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt) {
                    this->frm = frm;
                    this->resrt = resrt;
                }

                friend bool operator ==(const _ProjectionWrite_route_freeing& o1, const _ProjectionWrite_route_freeing& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt);
                }

                friend bool operator !=(const _ProjectionWrite_route_freeing& o1, const _ProjectionWrite_route_freeing& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_route_freeing& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_FRONT_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_FRONT_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_FRONT_MOVE_1& obj1, const _ProjectionRead_FRONT_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;
                BSet<BLOCKS > LBT;

                _ProjectionRead_FRONT_MOVE_1(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl, const BSet<BLOCKS >& LBT) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                    this->LBT = LBT;
                }

                friend bool operator ==(const _ProjectionRead_FRONT_MOVE_1& o1, const _ProjectionRead_FRONT_MOVE_1& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl) && o1.LBT == (o2.LBT);
                }

                friend bool operator !=(const _ProjectionRead_FRONT_MOVE_1& o1, const _ProjectionRead_FRONT_MOVE_1& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl) || o1.LBT != (o2.LBT);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_FRONT_MOVE_1& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_FRONT_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_FRONT_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_FRONT_MOVE_1& obj1, const _ProjectionRead__tr_FRONT_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_FRONT_MOVE_1(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_FRONT_MOVE_1& o1, const _ProjectionRead__tr_FRONT_MOVE_1& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_FRONT_MOVE_1& o1, const _ProjectionRead__tr_FRONT_MOVE_1& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_FRONT_MOVE_1& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", "; 
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "resbl: " << e.resbl;
                    strm << ", "; 
                    strm << "OCC: " << e.OCC;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_FRONT_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_FRONT_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_FRONT_MOVE_1& obj1, const _ProjectionWrite_FRONT_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<BLOCKS > OCC;
                BSet<BLOCKS > LBT;

                _ProjectionWrite_FRONT_MOVE_1(const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& LBT) {
                    this->OCC = OCC;
                    this->LBT = LBT;
                }

                friend bool operator ==(const _ProjectionWrite_FRONT_MOVE_1& o1, const _ProjectionWrite_FRONT_MOVE_1& o2) {
                    return o1.OCC == (o2.OCC) && o1.LBT == (o2.LBT);
                }

                friend bool operator !=(const _ProjectionWrite_FRONT_MOVE_1& o1, const _ProjectionWrite_FRONT_MOVE_1& o2) {
                    return o1.OCC != (o2.OCC) || o1.LBT != (o2.LBT);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_FRONT_MOVE_1& e) {
                    strm << "{";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_FRONT_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_FRONT_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_FRONT_MOVE_2& obj1, const _ProjectionRead_FRONT_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > OCC;

                _ProjectionRead_FRONT_MOVE_2(const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& OCC) {
                    this->TRK = TRK;
                    this->OCC = OCC;
                }

                friend bool operator ==(const _ProjectionRead_FRONT_MOVE_2& o1, const _ProjectionRead_FRONT_MOVE_2& o2) {
                    return o1.TRK == (o2.TRK) && o1.OCC == (o2.OCC);
                }

                friend bool operator !=(const _ProjectionRead_FRONT_MOVE_2& o1, const _ProjectionRead_FRONT_MOVE_2& o2) {
                    return o1.TRK != (o2.TRK) || o1.OCC != (o2.OCC);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_FRONT_MOVE_2& e) {
                    strm << "{";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_FRONT_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_FRONT_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_FRONT_MOVE_2& obj1, const _ProjectionRead__tr_FRONT_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > OCC;

                _ProjectionRead__tr_FRONT_MOVE_2(const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& OCC) {
                    this->TRK = TRK;
                    this->OCC = OCC;
                }

                friend bool operator ==(const _ProjectionRead__tr_FRONT_MOVE_2& o1, const _ProjectionRead__tr_FRONT_MOVE_2& o2) {
                    return o1.TRK == (o2.TRK) && o1.OCC == (o2.OCC);
                }

                friend bool operator !=(const _ProjectionRead__tr_FRONT_MOVE_2& o1, const _ProjectionRead__tr_FRONT_MOVE_2& o2) {
                    return o1.TRK != (o2.TRK) || o1.OCC != (o2.OCC);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_FRONT_MOVE_2& e) {
                    strm << "{";
                    strm << "TRK: " << e.TRK;
                    strm << ", "; 
                    strm << "OCC: " << e.OCC;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_FRONT_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_FRONT_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_FRONT_MOVE_2& obj1, const _ProjectionWrite_FRONT_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<BLOCKS > OCC;

                _ProjectionWrite_FRONT_MOVE_2(const BSet<BLOCKS >& OCC) {
                    this->OCC = OCC;
                }

                friend bool operator ==(const _ProjectionWrite_FRONT_MOVE_2& o1, const _ProjectionWrite_FRONT_MOVE_2& o2) {
                    return o1.OCC == (o2.OCC);
                }

                friend bool operator !=(const _ProjectionWrite_FRONT_MOVE_2& o1, const _ProjectionWrite_FRONT_MOVE_2& o2) {
                    return o1.OCC != (o2.OCC);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_FRONT_MOVE_2& e) {
                    strm << "{";
                    strm << "OCC: " << e.OCC;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (OCC.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_BACK_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_BACK_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_BACK_MOVE_1& obj1, const _ProjectionRead_BACK_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BSet<BLOCKS > LBT;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_BACK_MOVE_1(const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->LBT = LBT;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_BACK_MOVE_1& o1, const _ProjectionRead_BACK_MOVE_1& o2) {
                    return o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.LBT == (o2.LBT) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_BACK_MOVE_1& o1, const _ProjectionRead_BACK_MOVE_1& o2) {
                    return o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.LBT != (o2.LBT) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_BACK_MOVE_1& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_BACK_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_BACK_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_BACK_MOVE_1& obj1, const _ProjectionRead__tr_BACK_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > LBT;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_BACK_MOVE_1(const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->LBT = LBT;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_BACK_MOVE_1& o1, const _ProjectionRead__tr_BACK_MOVE_1& o2) {
                    return o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.LBT == (o2.LBT) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_BACK_MOVE_1& o1, const _ProjectionRead__tr_BACK_MOVE_1& o2) {
                    return o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.LBT != (o2.LBT) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_BACK_MOVE_1& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "TRK: " << e.TRK;
                    strm << ", "; 
                    strm << "LBT: " << e.LBT;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_BACK_MOVE_1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_BACK_MOVE_1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_BACK_MOVE_1& obj1, const _ProjectionWrite_BACK_MOVE_1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;
                BSet<BLOCKS > LBT;

                _ProjectionWrite_BACK_MOVE_1(const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl, const BSet<BLOCKS >& LBT) {
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                    this->LBT = LBT;
                }

                friend bool operator ==(const _ProjectionWrite_BACK_MOVE_1& o1, const _ProjectionWrite_BACK_MOVE_1& o2) {
                    return o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl) && o1.LBT == (o2.LBT);
                }

                friend bool operator !=(const _ProjectionWrite_BACK_MOVE_1& o1, const _ProjectionWrite_BACK_MOVE_1& o2) {
                    return o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl) || o1.LBT != (o2.LBT);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_BACK_MOVE_1& e) {
                    strm << "{";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_BACK_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_BACK_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_BACK_MOVE_2& obj1, const _ProjectionRead_BACK_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BSet<BLOCKS > LBT;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_BACK_MOVE_2(const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->LBT = LBT;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_BACK_MOVE_2& o1, const _ProjectionRead_BACK_MOVE_2& o2) {
                    return o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.LBT == (o2.LBT) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_BACK_MOVE_2& o1, const _ProjectionRead_BACK_MOVE_2& o2) {
                    return o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.LBT != (o2.LBT) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_BACK_MOVE_2& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_BACK_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_BACK_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_BACK_MOVE_2& obj1, const _ProjectionRead__tr_BACK_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BSet<BLOCKS > OCC;
                BSet<BLOCKS > LBT;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_BACK_MOVE_2(const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->OCC = OCC;
                    this->LBT = LBT;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_BACK_MOVE_2& o1, const _ProjectionRead__tr_BACK_MOVE_2& o2) {
                    return o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.OCC == (o2.OCC) && o1.LBT == (o2.LBT) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_BACK_MOVE_2& o1, const _ProjectionRead__tr_BACK_MOVE_2& o2) {
                    return o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.OCC != (o2.OCC) || o1.LBT != (o2.LBT) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_BACK_MOVE_2& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "TRK: " << e.TRK;
                    strm << ", "; 
                    strm << "OCC: " << e.OCC;
                    strm << ", "; 
                    strm << "LBT: " << e.LBT;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_BACK_MOVE_2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_BACK_MOVE_2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_BACK_MOVE_2& obj1, const _ProjectionWrite_BACK_MOVE_2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;
                BSet<BLOCKS > LBT;

                _ProjectionWrite_BACK_MOVE_2(const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl, const BSet<BLOCKS >& LBT) {
                    this->resbl = resbl;
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                    this->LBT = LBT;
                }

                friend bool operator ==(const _ProjectionWrite_BACK_MOVE_2& o1, const _ProjectionWrite_BACK_MOVE_2& o2) {
                    return o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl) && o1.LBT == (o2.LBT);
                }

                friend bool operator !=(const _ProjectionWrite_BACK_MOVE_2& o1, const _ProjectionWrite_BACK_MOVE_2& o2) {
                    return o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl) || o1.LBT != (o2.LBT);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_BACK_MOVE_2& e) {
                    strm << "{";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_point_positionning {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_point_positionning& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_point_positionning& obj1, const _ProjectionRead_point_positionning& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_point_positionning(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_point_positionning& o1, const _ProjectionRead_point_positionning& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_point_positionning& o1, const _ProjectionRead_point_positionning& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_point_positionning& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_point_positionning {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_point_positionning& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_point_positionning& obj1, const _ProjectionRead__tr_point_positionning& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_point_positionning(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_point_positionning& o1, const _ProjectionRead__tr_point_positionning& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_point_positionning& o1, const _ProjectionRead__tr_point_positionning& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_point_positionning& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", "; 
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_point_positionning {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_point_positionning& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_point_positionning& obj1, const _ProjectionWrite_point_positionning& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BLOCKS, BLOCKS > TRK;

                _ProjectionWrite_point_positionning(const BRelation<BLOCKS, BLOCKS >& TRK) {
                    this->TRK = TRK;
                }

                friend bool operator ==(const _ProjectionWrite_point_positionning& o1, const _ProjectionWrite_point_positionning& o2) {
                    return o1.TRK == (o2.TRK);
                }

                friend bool operator !=(const _ProjectionWrite_point_positionning& o1, const _ProjectionWrite_point_positionning& o2) {
                    return o1.TRK != (o2.TRK);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_point_positionning& e) {
                    strm << "{";
                    strm << "TRK: " << e.TRK;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TRK.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_route_formation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_route_formation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_route_formation& obj1, const _ProjectionRead_route_formation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead_route_formation(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead_route_formation& o1, const _ProjectionRead_route_formation& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead_route_formation& o1, const _ProjectionRead_route_formation& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_route_formation& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_route_formation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_route_formation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_route_formation& obj1, const _ProjectionRead__tr_route_formation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, BLOCKS > TRK;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__tr_route_formation(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, BLOCKS >& TRK, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->TRK = TRK;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__tr_route_formation& o1, const _ProjectionRead__tr_route_formation& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.TRK == (o2.TRK) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__tr_route_formation& o1, const _ProjectionRead__tr_route_formation& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.TRK != (o2.TRK) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_route_formation& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", "; 
                    strm << "resrt: " << e.resrt;
                    strm << ", "; 
                    strm << "TRK: " << e.TRK;
                    strm << ", "; 
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_route_formation {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_route_formation& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_route_formation& obj1, const _ProjectionWrite_route_formation& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<ROUTES > frm;

                _ProjectionWrite_route_formation(const BSet<ROUTES >& frm) {
                    this->frm = frm;
                }

                friend bool operator ==(const _ProjectionWrite_route_formation& o1, const _ProjectionWrite_route_formation& o2) {
                    return o1.frm == (o2.frm);
                }

                friend bool operator !=(const _ProjectionWrite_route_formation& o1, const _ProjectionWrite_route_formation& o2) {
                    return o1.frm != (o2.frm);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_route_formation& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
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

                BSet<ROUTES > resrt;
                BSet<BLOCKS > resbl;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_1(const BSet<ROUTES >& resrt, const BSet<BLOCKS >& resbl, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->resrt = resrt;
                    this->resbl = resbl;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.resrt == (o2.resrt) && o1.resbl == (o2.resbl) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.resrt != (o2.resrt) || o1.resbl != (o2.resbl) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_2(const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BSet<BLOCKS > resbl;
                BSet<BLOCKS > OCC;

                _ProjectionRead__check_inv_3(const BSet<BLOCKS >& resbl, const BSet<BLOCKS >& OCC) {
                    this->resbl = resbl;
                    this->OCC = OCC;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.resbl == (o2.resbl) && o1.OCC == (o2.OCC);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.resbl != (o2.resbl) || o1.OCC != (o2.OCC);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "resbl: " << e.resbl;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resbl.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
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

                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_4(const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_5(const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_6(const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BRelation<BLOCKS, BLOCKS > TRK;

                _ProjectionRead__check_inv_7(const BRelation<BLOCKS, BLOCKS >& TRK) {
                    this->TRK = TRK;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.TRK == (o2.TRK);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.TRK != (o2.TRK);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "TRK: " << e.TRK;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TRK.hashCode() << 1);
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

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;

                _ProjectionRead__check_inv_8(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt) {
                    this->frm = frm;
                    this->resrt = resrt;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
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

                BSet<ROUTES > frm;
                BSet<BLOCKS > OCC;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_9(const BSet<ROUTES >& frm, const BSet<BLOCKS >& OCC, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->OCC = OCC;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.frm == (o2.frm) && o1.OCC == (o2.OCC) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.frm != (o2.frm) || o1.OCC != (o2.OCC) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BSet<ROUTES > frm;
                BSet<ROUTES > resrt;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_10(const BSet<ROUTES >& frm, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->resrt = resrt;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.frm == (o2.frm) && o1.resrt == (o2.resrt) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.frm != (o2.frm) || o1.resrt != (o2.resrt) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "resrt: " << e.resrt;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (resrt.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BRelation<BLOCKS, BLOCKS > TRK;

                _ProjectionRead__check_inv_11(const BRelation<BLOCKS, BLOCKS >& TRK) {
                    this->TRK = TRK;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.TRK == (o2.TRK);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.TRK != (o2.TRK);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_11& e) {
                    strm << "{";
                    strm << "TRK: " << e.TRK;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (TRK.hashCode() << 1);
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

                BSet<ROUTES > frm;
                BRelation<BLOCKS, BLOCKS > TRK;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_12(const BSet<ROUTES >& frm, const BRelation<BLOCKS, BLOCKS >& TRK, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->frm = frm;
                    this->TRK = TRK;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.frm == (o2.frm) && o1.TRK == (o2.TRK) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.frm != (o2.frm) || o1.TRK != (o2.TRK) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_12& e) {
                    strm << "{";
                    strm << "frm: " << e.frm;
                    strm << ", ";
                    strm << "TRK: " << e.TRK;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (frm.hashCode() << 1);
                    result = 31 * result + (TRK.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
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

                BSet<BLOCKS > OCC;
                BSet<BLOCKS > LBT;

                _ProjectionRead__check_inv_13(const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& LBT) {
                    this->OCC = OCC;
                    this->LBT = LBT;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.OCC == (o2.OCC) && o1.LBT == (o2.LBT);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.OCC != (o2.OCC) || o1.LBT != (o2.LBT);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_13& e) {
                    strm << "{";
                    strm << "OCC: " << e.OCC;
                    strm << ", ";
                    strm << "LBT: " << e.LBT;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (OCC.hashCode() << 1);
                    result = 31 * result + (LBT.hashCode() << 1);
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

                BSet<BLOCKS > LBT;
                BRelation<BLOCKS, ROUTES > rsrtbl;

                _ProjectionRead__check_inv_14(const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
                    this->LBT = LBT;
                    this->rsrtbl = rsrtbl;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.LBT == (o2.LBT) && o1.rsrtbl == (o2.rsrtbl);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.LBT != (o2.LBT) || o1.rsrtbl != (o2.rsrtbl);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_14& e) {
                    strm << "{";
                    strm << "LBT: " << e.LBT;
                    strm << ", ";
                    strm << "rsrtbl: " << e.rsrtbl;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (LBT.hashCode() << 1);
                    result = 31 * result + (rsrtbl.hashCode() << 1);
                    return result;
                }

        };



    private:

        BRelation<ROUTES, BLOCKS > fst;
        BRelation<ROUTES, BLOCKS > lst;
        BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > > nxt;
        BRelation<BLOCKS, ROUTES > rtbl;
        BRelation<ROUTES, BLOCKS > __aux_constant_1;


        #define _BLOCKS (BSet<BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::N))))
        #define _ROUTES (BSet<ROUTES >((ROUTES(ROUTES::R1)), (ROUTES(ROUTES::R2)), (ROUTES(ROUTES::R3)), (ROUTES(ROUTES::R4)), (ROUTES(ROUTES::R5)), (ROUTES(ROUTES::R6)), (ROUTES(ROUTES::R7)), (ROUTES(ROUTES::R8)), (ROUTES(ROUTES::R9)), (ROUTES(ROUTES::R10))))

        BSet<BLOCKS > LBT;
        BRelation<BLOCKS, BLOCKS > TRK;
        BSet<ROUTES > frm;
        BSet<BLOCKS > OCC;
        BSet<BLOCKS > resbl;
        BSet<ROUTES > resrt;
        BRelation<BLOCKS, ROUTES > rsrtbl;


    public:

        std::string stateAccessedVia;

        Train_1_beebook_deterministic_MC_POR_v3() {
            fst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::N))))));
            lst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::M))))));
            nxt = (BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >((BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R1)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R2)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R3)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R4)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R5)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R6)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R7)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R8)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R9)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R10)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M))))))))));
            BRelation<BLOCKS, ROUTES > _ic_set_0 = BRelation<BLOCKS, ROUTES >();
            for(const BLOCKS& _ic_b_1 : _BLOCKS) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    if(((BBoolean((nxt.isInDomain(_ic_r_1)).booleanValue() && (BBoolean((nxt.functionCall(_ic_r_1).isInDomain(_ic_b_1)).booleanValue() || (nxt.functionCall(_ic_r_1).isInRange(_ic_b_1)).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_0 = _ic_set_0._union(BRelation<BLOCKS, ROUTES >((BTuple<BLOCKS, ROUTES >(_ic_b_1, _ic_r_1))));
                    }

                }

            }

            rtbl = _ic_set_0;
            __aux_constant_1 = rtbl.inverse();
            BBoolean _ic_boolean_1 = BBoolean(true);
            if(((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue()))).booleanValue()) {
                for(const BRelation<BLOCKS, BLOCKS >& _ic__opt_1_1 : nxt.range()) {
                    if(!(((_ic__opt_1_1.checkDomain(_BLOCKS))._and((_ic__opt_1_1.checkRange(_BLOCKS)))._and((_ic__opt_1_1.isFunction()))._and((_ic__opt_1_1.isPartial(_BLOCKS)))._and((_ic__opt_1_1.isInjection())))).booleanValue()) {
                        _ic_boolean_1 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_2 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue()))).booleanValue()) {
                for(const BTuple<BLOCKS, ROUTES >& _ic__opt_2_1 : fst.inverse()) {
                    if(!(rtbl.elementOf(_ic__opt_2_1)).booleanValue()) {
                        _ic_boolean_2 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_3 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue()))).booleanValue()) {
                for(const BTuple<BLOCKS, ROUTES >& _ic__opt_3_1 : lst.inverse()) {
                    if(!(rtbl.elementOf(_ic__opt_3_1)).booleanValue()) {
                        _ic_boolean_3 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_4 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue()))).booleanValue()) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    if(!(fst.functionCall(_ic_r_1).unequal(lst.functionCall(_ic_r_1))).booleanValue()) {
                        _ic_boolean_4 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_6 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue()))).booleanValue()) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    BBoolean _ic_boolean_5 = BBoolean(true);
                    for(const BSet<BLOCKS >& _ic_S_1 : nxt.functionCall(_ic_r_1).range().pow()) {
                        if(!((BBoolean(!_ic_S_1.subset(nxt.functionCall(_ic_r_1).relationImage(_ic_S_1)).booleanValue() || _ic_S_1.equal((BSet<BLOCKS >())).booleanValue()))).booleanValue()) {
                            _ic_boolean_5 = BBoolean(false);
                            break;
                        }

                    }

                    if(!(_ic_boolean_5).booleanValue()) {
                        _ic_boolean_6 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_7 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue()))).booleanValue()) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    if(!(((nxt.functionCall(_ic_r_1).checkDomain(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference((BSet<BLOCKS >(lst.functionCall(_ic_r_1))))))._and((nxt.functionCall(_ic_r_1).checkRange(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference((BSet<BLOCKS >(fst.functionCall(_ic_r_1)))))))._and((nxt.functionCall(_ic_r_1).isFunction()))._and((nxt.functionCall(_ic_r_1).isTotal(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference((BSet<BLOCKS >(lst.functionCall(_ic_r_1)))))))._and((nxt.functionCall(_ic_r_1).isBijection(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference((BSet<BLOCKS >(fst.functionCall(_ic_r_1))))))))).booleanValue()) {
                        _ic_boolean_7 = BBoolean(false);
                        break;
                    }

                }
            }

            BBoolean _ic_boolean_8 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue())).booleanValue() && _ic_boolean_7.booleanValue()))).booleanValue()) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    for(const ROUTES& _ic_s_1 : _ROUTES) {
                        if(!((BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || (BBoolean((BSet<BLOCKS >(fst.functionCall(_ic_s_1), lst.functionCall(_ic_s_1))).elementOf(fst.functionCall(_ic_r_1)).booleanValue() || (rtbl.inverse().isNotInRelationalImage(fst.functionCall(_ic_r_1), (BSet<ROUTES >(_ic_s_1)))).booleanValue())).booleanValue()))).booleanValue()) {
                            _ic_boolean_8 = BBoolean(false);
                            break;
                        }

                    }

                }
            }

            BBoolean _ic_boolean_9 = BBoolean(true);
            if(((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue())).booleanValue() && _ic_boolean_7.booleanValue())).booleanValue() && _ic_boolean_8.booleanValue()))).booleanValue()) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    for(const ROUTES& _ic_s_1 : _ROUTES) {
                        if(!((BBoolean(!_ic_r_1.unequal(_ic_s_1).booleanValue() || (BBoolean((BSet<BLOCKS >(fst.functionCall(_ic_s_1), lst.functionCall(_ic_s_1))).elementOf(lst.functionCall(_ic_r_1)).booleanValue() || (rtbl.inverse().isNotInRelationalImage(lst.functionCall(_ic_r_1), (BSet<ROUTES >(_ic_s_1)))).booleanValue())).booleanValue()))).booleanValue()) {
                            _ic_boolean_9 = BBoolean(false);
                            break;
                        }

                    }

                }
            }

            if(!((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean((BBoolean(rtbl.domain().equal(_BLOCKS).booleanValue() && rtbl.range().equal(_ROUTES).booleanValue())).booleanValue() && nxt.domain().equal(_ROUTES).booleanValue())).booleanValue() && _ic_boolean_1.booleanValue())).booleanValue() && ((fst.checkDomain(_ROUTES))._and((fst.checkRange(_BLOCKS)))._and((fst.isFunction()))._and((fst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && ((lst.checkDomain(_ROUTES))._and((lst.checkRange(_BLOCKS)))._and((lst.isFunction()))._and((lst.isTotal(_ROUTES)))).booleanValue())).booleanValue() && _ic_boolean_2.booleanValue())).booleanValue() && _ic_boolean_3.booleanValue())).booleanValue() && _ic_boolean_4.booleanValue())).booleanValue() && _ic_boolean_6.booleanValue())).booleanValue() && _ic_boolean_7.booleanValue())).booleanValue() && _ic_boolean_8.booleanValue())).booleanValue() && _ic_boolean_9.booleanValue()))).booleanValue()) {
                throw std::runtime_error("Contradiction in PROPERTIES detected!");
            }
            resrt = (BSet<ROUTES >());
            resbl = (BSet<BLOCKS >());
            rsrtbl = (BRelation<BLOCKS, ROUTES >());
            OCC = (BSet<BLOCKS >());
            TRK = (BRelation<BLOCKS, BLOCKS >());
            frm = (BSet<ROUTES >());
            LBT = (BSet<BLOCKS >());
        }

        Train_1_beebook_deterministic_MC_POR_v3(const Train_1_beebook_deterministic_MC_POR_v3& copy) {
            this->fst = copy.fst;
            this->lst = copy.lst;
            this->nxt = copy.nxt;
            this->rtbl = copy.rtbl;
            this->__aux_constant_1 = copy.__aux_constant_1;
            this->LBT = copy.LBT;
            this->TRK = copy.TRK;
            this->frm = copy.frm;
            this->OCC = copy.OCC;
            this->resbl = copy.resbl;
            this->resrt = copy.resrt;
            this->rsrtbl = copy.rsrtbl;
        }

        void route_reservation(const ROUTES& r) {
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<ROUTES > _ld_resrt = resrt;
            BSet<BLOCKS > _ld_resbl = resbl;
            resrt = _ld_resrt._union((BSet<ROUTES >(r)));
            rsrtbl = _ld_rsrtbl._union(rtbl.rangeRestriction((BSet<ROUTES >(r))));
            resbl = _ld_resbl._union(__aux_constant_1.relationImage((BSet<ROUTES >(r))));

        }

        void route_freeing(const ROUTES& r) {
            BSet<ROUTES > _ld_frm = frm;
            BSet<ROUTES > _ld_resrt = resrt;
            resrt = _ld_resrt.difference((BSet<ROUTES >(r)));
            frm = _ld_frm.difference((BSet<ROUTES >(r)));

        }

        void FRONT_MOVE_1(const ROUTES& r) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            OCC = _ld_OCC._union((BSet<BLOCKS >(fst.functionCall(r))));
            LBT = _ld_LBT._union((BSet<BLOCKS >(fst.functionCall(r))));

        }

        void FRONT_MOVE_2(const BLOCKS& b) {
            OCC = OCC._union((BSet<BLOCKS >(TRK.functionCall(b))));

        }

        void BACK_MOVE_1(const BLOCKS& b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)));

        }

        void BACK_MOVE_2(const BLOCKS& b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)))._union((BSet<BLOCKS >(TRK.functionCall(b))));

        }

        void point_positionning(const ROUTES& r) {
            TRK = TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range())._union(nxt.functionCall(r));

        }

        void route_formation(const ROUTES& r) {
            frm = frm._union((BSet<ROUTES >(r)));

        }

        BRelation<ROUTES, BLOCKS > _get_fst() const {
            return fst;
        }

        BRelation<ROUTES, BLOCKS > _get_lst() const {
            return lst;
        }

        BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > > _get_nxt() const {
            return nxt;
        }

        BRelation<BLOCKS, ROUTES > _get_rtbl() const {
            return rtbl;
        }

        BRelation<ROUTES, BLOCKS > _get___aux_constant_1() const {
            return __aux_constant_1;
        }

        BSet<BLOCKS > _get_LBT() const {
            return LBT;
        }

        BRelation<BLOCKS, BLOCKS > _get_TRK() const {
            return TRK;
        }

        BSet<ROUTES > _get_frm() const {
            return frm;
        }

        BSet<BLOCKS > _get_OCC() const {
            return OCC;
        }

        BSet<BLOCKS > _get_resbl() const {
            return resbl;
        }

        BSet<ROUTES > _get_resrt() const {
            return resrt;
        }

        BRelation<BLOCKS, ROUTES > _get_rsrtbl() const {
            return rsrtbl;
        }

        BSet<BLOCKS > _get__BLOCKS() const {
            return _BLOCKS;
        }

        BSet<ROUTES > _get__ROUTES() const {
            return _ROUTES;
        }


        BSet<ROUTES> _tr_route_reservation() const {
            BSet<ROUTES> _ic_set_10 = BSet<ROUTES>();
            for(const ROUTES& _ic_r_1 : _ROUTES.difference(resrt)) {
                if(((BBoolean(__aux_constant_1.relationImage((BSet<ROUTES >(_ic_r_1))).intersect(resbl).equal((BSet<BLOCKS >())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_10 = _ic_set_10._union(BSet<ROUTES>(_ic_r_1));
                }

            }

            return _ic_set_10;
        }

        BSet<ROUTES> _tr_route_freeing() const {
            BSet<ROUTES> _ic_set_11 = BSet<ROUTES>();
            for(const ROUTES& _ic_r_1 : resrt.difference(rsrtbl.range())) {
                _ic_set_11 = _ic_set_11._union(BSet<ROUTES>(_ic_r_1));

            }

            return _ic_set_11;
        }

        BSet<ROUTES> _tr_FRONT_MOVE_1() const {
            BSet<ROUTES> _ic_set_12 = BSet<ROUTES>();
            for(const ROUTES& _ic_r_1 : frm) {
                if(((BBoolean((BBoolean(resbl.difference(OCC).elementOf(fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(rsrtbl.functionCall(fst.functionCall(_ic_r_1))).booleanValue())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_12 = _ic_set_12._union(BSet<ROUTES>(_ic_r_1));
                }

            }

            return _ic_set_12;
        }

        BSet<BLOCKS> _tr_FRONT_MOVE_2() const {
            BSet<BLOCKS> _ic_set_13 = BSet<BLOCKS>();
            for(const BLOCKS& _ic_b_1 : OCC.intersect(TRK.domain())) {
                if((OCC.notElementOf(TRK.functionCall(_ic_b_1))).booleanValue()) {
                    _ic_set_13 = _ic_set_13._union(BSet<BLOCKS>(_ic_b_1));
                }

            }

            return _ic_set_13;
        }

        BSet<BLOCKS> _tr_BACK_MOVE_1() const {
            BSet<BLOCKS> _ic_set_14 = BSet<BLOCKS>();
            for(const BLOCKS& _ic_b_1 : LBT.difference(TRK.domain())) {
                if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                    _ic_set_14 = _ic_set_14._union(BSet<BLOCKS>(_ic_b_1));
                }

            }

            return _ic_set_14;
        }

        BSet<BLOCKS> _tr_BACK_MOVE_2() const {
            BSet<BLOCKS> _ic_set_15 = BSet<BLOCKS>();
            for(const BLOCKS& _ic_b_1 : LBT.intersect(TRK.domain())) {
                if(((BBoolean(OCC.elementOf(TRK.functionCall(_ic_b_1)).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_15 = _ic_set_15._union(BSet<BLOCKS>(_ic_b_1));
                }

            }

            return _ic_set_15;
        }

        BSet<ROUTES> _tr_point_positionning() const {
            BSet<ROUTES> _ic_set_16 = BSet<ROUTES>();
            for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                    _ic_set_16 = _ic_set_16._union(BSet<ROUTES>(_ic_r_1));
                }

            }

            return _ic_set_16;
        }

        BSet<ROUTES> _tr_route_formation() const {
            BSet<ROUTES> _ic_set_17 = BSet<ROUTES>();
            for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                if(((BBoolean(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))))).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_17 = _ic_set_17._union(BSet<ROUTES>(_ic_r_1));
                }

            }

            return _ic_set_17;
        }

        _ProjectionRead_point_positionning _projected_state_for_point_positionning() const {
            return _ProjectionRead_point_positionning(frm,resrt,TRK,rsrtbl);
        }

        _ProjectionRead_route_reservation _projected_state_for_route_reservation() const {
            return _ProjectionRead_route_reservation(resrt,resbl,rsrtbl);
        }

        _ProjectionRead_FRONT_MOVE_1 _projected_state_for_FRONT_MOVE_1() const {
            return _ProjectionRead_FRONT_MOVE_1(frm,resrt,resbl,OCC,rsrtbl,LBT);
        }

        _ProjectionRead_BACK_MOVE_1 _projected_state_for_BACK_MOVE_1() const {
            return _ProjectionRead_BACK_MOVE_1(resrt,TRK,resbl,OCC,LBT,rsrtbl);
        }

        _ProjectionRead_FRONT_MOVE_2 _projected_state_for_FRONT_MOVE_2() const {
            return _ProjectionRead_FRONT_MOVE_2(TRK,OCC);
        }

        _ProjectionRead_route_formation _projected_state_for_route_formation() const {
            return _ProjectionRead_route_formation(frm,resrt,TRK,rsrtbl);
        }

        _ProjectionRead_route_freeing _projected_state_for_route_freeing() const {
            return _ProjectionRead_route_freeing(frm,resrt,rsrtbl);
        }

        _ProjectionRead_BACK_MOVE_2 _projected_state_for_BACK_MOVE_2() const {
            return _ProjectionRead_BACK_MOVE_2(resrt,TRK,resbl,OCC,LBT,rsrtbl);
        }

        _ProjectionRead__tr_route_formation _projected_state_for__tr_route_formation() const {
            return _ProjectionRead__tr_route_formation(frm,resrt,TRK,rsrtbl);
        }

        _ProjectionRead__tr_FRONT_MOVE_1 _projected_state_for__tr_FRONT_MOVE_1() const {
            return _ProjectionRead__tr_FRONT_MOVE_1(frm,resrt,resbl,OCC,rsrtbl);
        }

        _ProjectionRead__tr_route_reservation _projected_state_for__tr_route_reservation() const {
            return _ProjectionRead__tr_route_reservation(resrt,resbl,rsrtbl);
        }

        _ProjectionRead__tr_route_freeing _projected_state_for__tr_route_freeing() const {
            return _ProjectionRead__tr_route_freeing(resrt,rsrtbl);
        }

        _ProjectionRead__tr_BACK_MOVE_1 _projected_state_for__tr_BACK_MOVE_1() const {
            return _ProjectionRead__tr_BACK_MOVE_1(resrt,TRK,LBT,rsrtbl);
        }

        _ProjectionRead__tr_point_positionning _projected_state_for__tr_point_positionning() const {
            return _ProjectionRead__tr_point_positionning(frm,resrt,rsrtbl);
        }

        _ProjectionRead__tr_FRONT_MOVE_2 _projected_state_for__tr_FRONT_MOVE_2() const {
            return _ProjectionRead__tr_FRONT_MOVE_2(TRK,OCC);
        }

        _ProjectionRead__tr_BACK_MOVE_2 _projected_state_for__tr_BACK_MOVE_2() const {
            return _ProjectionRead__tr_BACK_MOVE_2(resrt,TRK,OCC,LBT,rsrtbl);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(OCC,rsrtbl);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(frm,resrt,rsrtbl);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(TRK);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(OCC,rsrtbl);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(rsrtbl);
        }

        _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() const {
            return _ProjectionRead__check_inv_14(LBT,rsrtbl);
        }

        _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() const {
            return _ProjectionRead__check_inv_13(OCC,LBT);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(frm,resrt);
        }

        _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() const {
            return _ProjectionRead__check_inv_12(frm,TRK,rsrtbl);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(frm,OCC,rsrtbl);
        }

        _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() const {
            return _ProjectionRead__check_inv_11(TRK);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(rsrtbl);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(resbl,OCC);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(resrt,resbl,rsrtbl);
        }

        _ProjectionWrite_point_positionning _update_for_point_positionning() const {
            return _ProjectionWrite_point_positionning(TRK);
        }

        _ProjectionWrite_route_reservation _update_for_route_reservation() const {
            return _ProjectionWrite_route_reservation(resrt,resbl,rsrtbl);
        }

        _ProjectionWrite_FRONT_MOVE_1 _update_for_FRONT_MOVE_1() const {
            return _ProjectionWrite_FRONT_MOVE_1(OCC,LBT);
        }

        _ProjectionWrite_BACK_MOVE_1 _update_for_BACK_MOVE_1() const {
            return _ProjectionWrite_BACK_MOVE_1(resbl,OCC,rsrtbl,LBT);
        }

        _ProjectionWrite_FRONT_MOVE_2 _update_for_FRONT_MOVE_2() const {
            return _ProjectionWrite_FRONT_MOVE_2(OCC);
        }

        _ProjectionWrite_route_formation _update_for_route_formation() const {
            return _ProjectionWrite_route_formation(frm);
        }

        _ProjectionWrite_route_freeing _update_for_route_freeing() const {
            return _ProjectionWrite_route_freeing(frm,resrt);
        }

        _ProjectionWrite_BACK_MOVE_2 _update_for_BACK_MOVE_2() const {
            return _ProjectionWrite_BACK_MOVE_2(resbl,OCC,rsrtbl,LBT);
        }

        void _apply_update_for_point_positionning(const _ProjectionWrite_point_positionning& update) {
            this->TRK = update.TRK;
        }

        void _apply_update_for_route_reservation(const _ProjectionWrite_route_reservation& update) {
            this->resrt = update.resrt;
            this->resbl = update.resbl;
            this->rsrtbl = update.rsrtbl;
        }

        void _apply_update_for_FRONT_MOVE_1(const _ProjectionWrite_FRONT_MOVE_1& update) {
            this->OCC = update.OCC;
            this->LBT = update.LBT;
        }

        void _apply_update_for_BACK_MOVE_1(const _ProjectionWrite_BACK_MOVE_1& update) {
            this->resbl = update.resbl;
            this->OCC = update.OCC;
            this->rsrtbl = update.rsrtbl;
            this->LBT = update.LBT;
        }

        void _apply_update_for_FRONT_MOVE_2(const _ProjectionWrite_FRONT_MOVE_2& update) {
            this->OCC = update.OCC;
        }

        void _apply_update_for_route_formation(const _ProjectionWrite_route_formation& update) {
            this->frm = update.frm;
        }

        void _apply_update_for_route_freeing(const _ProjectionWrite_route_freeing& update) {
            this->frm = update.frm;
            this->resrt = update.resrt;
        }

        void _apply_update_for_BACK_MOVE_2(const _ProjectionWrite_BACK_MOVE_2& update) {
            this->resbl = update.resbl;
            this->OCC = update.OCC;
            this->rsrtbl = update.rsrtbl;
            this->LBT = update.LBT;
        }

        bool _check_inv_1() const {
            return (((rsrtbl.checkDomain(resbl))._and((rsrtbl.checkRange(resrt)))._and((rsrtbl.isFunction()))._and((rsrtbl.isTotal(resbl))))).booleanValue();
        }

        bool _check_inv_2() const {
            BBoolean _ic_boolean_18 = BBoolean(true);
            for(const BTuple<BLOCKS, ROUTES >& _ic__opt_4_1 : rsrtbl) {
                if(!(rtbl.elementOf(_ic__opt_4_1)).booleanValue()) {
                    _ic_boolean_18 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_18).booleanValue();
        }

        bool _check_inv_3() const {
            BBoolean _ic_boolean_19 = BBoolean(true);
            for(const BLOCKS& _ic__opt_5_1 : OCC) {
                if(!(resbl.elementOf(_ic__opt_5_1)).booleanValue()) {
                    _ic_boolean_19 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_19).booleanValue();
        }

        bool _check_inv_4() const {
            BBoolean _ic_boolean_20 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : _ROUTES) {
                if(!(nxt.functionCall(_ic_r_1).relationImage(__aux_constant_1.relationImage((BSet<ROUTES >(_ic_r_1))).difference(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))))).intersect(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference(OCC)).equal((BSet<BLOCKS >()))).booleanValue()) {
                    _ic_boolean_20 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_20).booleanValue();
        }

        bool _check_inv_5() const {
            BBoolean _ic_boolean_22 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : _ROUTES) {
                BBoolean _ic_boolean_21 = BBoolean(true);
                for(const BLOCKS& _ic__opt_6_1 : nxt.functionCall(_ic_r_1).relationImage(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))))) {
                    if(!((rsrtbl.inverse().isInRelationalImage(_ic__opt_6_1, (BSet<ROUTES >(_ic_r_1))))).booleanValue()) {
                        _ic_boolean_21 = BBoolean(false);
                        break;
                    }

                }

                if(!(_ic_boolean_21).booleanValue()) {
                    _ic_boolean_22 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_22).booleanValue();
        }

        bool _check_inv_6() const {
            BBoolean _ic_boolean_24 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : _ROUTES) {
                BBoolean _ic_boolean_23 = BBoolean(true);
                for(const BLOCKS& _ic__opt_7_1 : nxt.functionCall(_ic_r_1).relationImage(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference(OCC))) {
                    if(!((BBoolean((rsrtbl.inverse().isInRelationalImage(_ic__opt_7_1, (BSet<ROUTES >(_ic_r_1)))).booleanValue() && OCC.notElementOf(_ic__opt_7_1).booleanValue()))).booleanValue()) {
                        _ic_boolean_23 = BBoolean(false);
                        break;
                    }

                }

                if(!(_ic_boolean_23).booleanValue()) {
                    _ic_boolean_24 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_24).booleanValue();
        }

        bool _check_inv_7() const {
            return (((TRK.checkDomain(_BLOCKS))._and((TRK.checkRange(_BLOCKS)))._and((TRK.isFunction()))._and((TRK.isPartial(_BLOCKS)))._and((TRK.isInjection())))).booleanValue();
        }

        bool _check_inv_8() const {
            BBoolean _ic_boolean_25 = BBoolean(true);
            for(const ROUTES& _ic__opt_8_1 : frm) {
                if(!(resrt.elementOf(_ic__opt_8_1)).booleanValue()) {
                    _ic_boolean_25 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_25).booleanValue();
        }

        bool _check_inv_9() const {
            BBoolean _ic_boolean_26 = BBoolean(true);
            for(const ROUTES& _ic__opt_9_1 : rsrtbl.relationImage(OCC)) {
                if(!(frm.elementOf(_ic__opt_9_1)).booleanValue()) {
                    _ic_boolean_26 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_26).booleanValue();
        }

        bool _check_inv_10() const {
            BBoolean _ic_boolean_27 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                if(!(rtbl.rangeRestriction((BSet<ROUTES >(_ic_r_1))).equal(rsrtbl.rangeRestriction((BSet<ROUTES >(_ic_r_1))))).booleanValue()) {
                    _ic_boolean_27 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_27).booleanValue();
        }

        bool _check_inv_11() const {
            BBoolean _ic_boolean_29 = BBoolean(true);
            for(const BLOCKS& _ic_x_1 : _BLOCKS) {
                for(const BLOCKS& _ic_y_1 : _BLOCKS) {
                    BBoolean _ic_boolean_28 = BBoolean(false);
                    for(const ROUTES& _ic_r_1 : _ROUTES) {
                        if((nxt.functionCall(_ic_r_1).elementOf((BTuple<BLOCKS, BLOCKS >(_ic_x_1, _ic_y_1)))).booleanValue()) {
                            _ic_boolean_28 = BBoolean(true);
                            break;
                        }

                    }

                    if(!((BBoolean(!TRK.elementOf((BTuple<BLOCKS, BLOCKS >(_ic_x_1, _ic_y_1))).booleanValue() || _ic_boolean_28.booleanValue()))).booleanValue()) {
                        _ic_boolean_29 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_29).booleanValue();
        }

        bool _check_inv_12() const {
            BBoolean _ic_boolean_30 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : frm) {
                if(!(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))))).booleanValue()) {
                    _ic_boolean_30 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_30).booleanValue();
        }

        bool _check_inv_13() const {
            BBoolean _ic_boolean_31 = BBoolean(true);
            for(const BLOCKS& _ic__opt_10_1 : LBT) {
                if(!(OCC.elementOf(_ic__opt_10_1)).booleanValue()) {
                    _ic_boolean_31 = BBoolean(false);
                    break;
                }

            }

            return (_ic_boolean_31).booleanValue();
        }

        bool _check_inv_14() const {
            BBoolean _ic_boolean_32 = BBoolean(true);
            for(const BLOCKS& _ic_a_1 : _BLOCKS) {
                for(const BLOCKS& _ic_b_1 : LBT) {
                    if(!((BBoolean(!(BBoolean((BBoolean((nxt.functionCall(rsrtbl.functionCall(_ic_b_1)).isInRange(_ic_b_1)).booleanValue() && _ic_a_1.equal(nxt.functionCall(rsrtbl.functionCall(_ic_b_1)).inverse().functionCall(_ic_b_1)).booleanValue())).booleanValue() && (rsrtbl.isInDomain(_ic_a_1)).booleanValue())).booleanValue() || rsrtbl.functionCall(_ic_a_1).unequal(rsrtbl.functionCall(_ic_b_1)).booleanValue()))).booleanValue()) {
                        _ic_boolean_32 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_32).booleanValue();
        }

        Train_1_beebook_deterministic_MC_POR_v3 _copy() const {
            return Train_1_beebook_deterministic_MC_POR_v3(*this);
        }

        friend bool operator ==(const Train_1_beebook_deterministic_MC_POR_v3& o1, const Train_1_beebook_deterministic_MC_POR_v3& o2) {
            return o1._get_LBT() == o2._get_LBT() && o1._get_TRK() == o2._get_TRK() && o1._get_frm() == o2._get_frm() && o1._get_OCC() == o2._get_OCC() && o1._get_resbl() == o2._get_resbl() && o1._get_resrt() == o2._get_resrt() && o1._get_rsrtbl() == o2._get_rsrtbl();
        }

        friend bool operator !=(const Train_1_beebook_deterministic_MC_POR_v3& o1, const Train_1_beebook_deterministic_MC_POR_v3& o2) {
            return o1._get_LBT() != o2._get_LBT() || o1._get_TRK() != o2._get_TRK() || o1._get_frm() != o2._get_frm() || o1._get_OCC() != o2._get_OCC() || o1._get_resbl() != o2._get_resbl() || o1._get_resrt() != o2._get_resrt() || o1._get_rsrtbl() != o2._get_rsrtbl();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_LBT()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_TRK()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_frm()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_OCC()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_resbl()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_resrt()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_rsrtbl()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_LBT()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_TRK()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_frm()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_OCC()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_resbl()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_resrt()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_rsrtbl()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const Train_1_beebook_deterministic_MC_POR_v3 &machine) {
          strm << "_get_LBT: " << machine._get_LBT() << "\n";
          strm << "_get_TRK: " << machine._get_TRK() << "\n";
          strm << "_get_frm: " << machine._get_frm() << "\n";
          strm << "_get_OCC: " << machine._get_OCC() << "\n";
          strm << "_get_resbl: " << machine._get_resbl() << "\n";
          strm << "_get_resrt: " << machine._get_resrt() << "\n";
          strm << "_get_rsrtbl: " << machine._get_rsrtbl() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        Train_1_beebook_deterministic_MC_POR_v3::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<Train_1_beebook_deterministic_MC_POR_v3> unvisitedStates;
        std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Train_1_beebook_deterministic_MC_POR_v3 counterExampleState;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHashEqual> _OpCache_route_reservation;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_reservation,  BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_reservation::HashEqual> _OpCache_tr_route_reservation;
        std::mutex _ProjectionRead_route_reservation_mutex;
        std::mutex _ProjectionRead__tr_route_reservation_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHashEqual> _OpCache_route_freeing;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_freeing,  BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_freeing::HashEqual> _OpCache_tr_route_freeing;
        std::mutex _ProjectionRead_route_freeing_mutex;
        std::mutex _ProjectionRead__tr_route_freeing_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHashEqual> _OpCache_FRONT_MOVE_1;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_1,  BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_1::HashEqual> _OpCache_tr_FRONT_MOVE_1;
        std::mutex _ProjectionRead_FRONT_MOVE_1_mutex;
        std::mutex _ProjectionRead__tr_FRONT_MOVE_1_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHashEqual> _OpCache_FRONT_MOVE_2;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_2,  BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_2::HashEqual> _OpCache_tr_FRONT_MOVE_2;
        std::mutex _ProjectionRead_FRONT_MOVE_2_mutex;
        std::mutex _ProjectionRead__tr_FRONT_MOVE_2_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHashEqual> _OpCache_BACK_MOVE_1;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_1,  BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_1::HashEqual> _OpCache_tr_BACK_MOVE_1;
        std::mutex _ProjectionRead_BACK_MOVE_1_mutex;
        std::mutex _ProjectionRead__tr_BACK_MOVE_1_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>::SetHashEqual> _OpCache_BACK_MOVE_2;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_2,  BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_2::HashEqual> _OpCache_tr_BACK_MOVE_2;
        std::mutex _ProjectionRead_BACK_MOVE_2_mutex;
        std::mutex _ProjectionRead__tr_BACK_MOVE_2_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHashEqual> _OpCache_point_positionning;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_point_positionning,  BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_point_positionning::HashEqual> _OpCache_tr_point_positionning;
        std::mutex _ProjectionRead_point_positionning_mutex;
        std::mutex _ProjectionRead__tr_point_positionning_mutex;

        std::unordered_map<BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::HashEqual>, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHash, BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>::SetHashEqual> _OpCache_route_formation;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_formation,  BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES>, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_formation::HashEqual> _OpCache_tr_route_formation;
        std::mutex _ProjectionRead_route_formation_mutex;
        std::mutex _ProjectionRead__tr_route_formation_mutex;

        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_1, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_2, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_3, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_3::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_4, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_4::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_5, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_5::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_6, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_6::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_7, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_7::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_8, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_8::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_9, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_9::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_10, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_10::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_11, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_11::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_11::HashEqual> _InvCache__check_inv_11;
        std::mutex _ProjectionRead__check_inv_11_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_12, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_12::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_12::HashEqual> _InvCache__check_inv_12;
        std::mutex _ProjectionRead__check_inv_12_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_13, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_13::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_13::HashEqual> _InvCache__check_inv_13;
        std::mutex _ProjectionRead__check_inv_13_mutex;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_14, bool, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_14::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_14::HashEqual> _InvCache__check_inv_14;
        std::mutex _ProjectionRead__check_inv_14_mutex;

        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(Train_1_beebook_deterministic_MC_POR_v3::Type type, int threads, bool isCaching, bool isDebug) {
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
            Train_1_beebook_deterministic_MC_POR_v3 machine = Train_1_beebook_deterministic_MC_POR_v3();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                Train_1_beebook_deterministic_MC_POR_v3 state = next();

                std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> nextStates = generateNextStates(state);

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
            Train_1_beebook_deterministic_MC_POR_v3 machine = Train_1_beebook_deterministic_MC_POR_v3();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            std::atomic<bool> stopThreads(false);
            std::atomic<int> possibleQueueChanges;
            possibleQueueChanges = 0;

            while(!unvisitedStates.empty() && !stopThreads.load()) {
                possibleQueueChanges.fetch_add(1);
                Train_1_beebook_deterministic_MC_POR_v3 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> nextStates = generateNextStates(state);

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
                        std::unique_lock<std::mutex> lock(mutex);
                        if (!unvisitedStates.empty() || possibleQueueChanges.load() == 0) {
                            {
                                std::unique_lock<std::mutex> lock(waitMutex);
                                waitCV.notify_one();
                            }
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
        Train_1_beebook_deterministic_MC_POR_v3 next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case Train_1_beebook_deterministic_MC_POR_v3::BFS: {
                        Train_1_beebook_deterministic_MC_POR_v3 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case Train_1_beebook_deterministic_MC_POR_v3::DFS: {
                        Train_1_beebook_deterministic_MC_POR_v3 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case Train_1_beebook_deterministic_MC_POR_v3::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            Train_1_beebook_deterministic_MC_POR_v3 state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            Train_1_beebook_deterministic_MC_POR_v3 state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3 state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> generateNextStates(const Train_1_beebook_deterministic_MC_POR_v3& state) {
            std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual> result = std::unordered_set<Train_1_beebook_deterministic_MC_POR_v3, Train_1_beebook_deterministic_MC_POR_v3::Hash, Train_1_beebook_deterministic_MC_POR_v3::HashEqual>();
            if(isCaching) {
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_reservation read__tr_route_reservation_state = state._projected_state_for__tr_route_reservation();
                auto _trid_1_ptr = _OpCache_tr_route_reservation.find(read__tr_route_reservation_state);
                if(_trid_1_ptr == _OpCache_tr_route_reservation.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_1 = state._tr_route_reservation();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_route_reservation_lock(_ProjectionRead__tr_route_reservation_mutex);
                        _OpCache_tr_route_reservation.insert({read__tr_route_reservation_state, _trid_1});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_1) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation readState = state._projected_state_for_route_reservation();

                        auto _OpCache_with_parameter_route_reservation_ptr = _OpCache_route_reservation.find(param);
                        if(_OpCache_with_parameter_route_reservation_ptr == _OpCache_route_reservation.end()) {
                            copiedState.route_reservation(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = copiedState._update_for_route_reservation();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::HashEqual> _OpCache_with_parameter_route_reservation;
                            _OpCache_with_parameter_route_reservation.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_reservation_lock(_ProjectionRead_route_reservation_mutex);
                                _OpCache_route_reservation.insert({param, _OpCache_with_parameter_route_reservation});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::HashEqual> _OpCache_with_parameter_route_reservation = _OpCache_with_parameter_route_reservation_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_reservation.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_reservation.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_reservation(writeState);
                            } else {
                                copiedState.route_reservation(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = copiedState._update_for_route_reservation();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_reservation_lock(_ProjectionRead_route_reservation_mutex);
                                    _OpCache_with_parameter_route_reservation.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_reservation";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_1 = _trid_1_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_1) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation readState = state._projected_state_for_route_reservation();

                        auto _OpCache_with_parameter_route_reservation_ptr = _OpCache_route_reservation.find(param);
                        if(_OpCache_with_parameter_route_reservation_ptr == _OpCache_route_reservation.end()) {
                            copiedState.route_reservation(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = copiedState._update_for_route_reservation();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::HashEqual> _OpCache_with_parameter_route_reservation;
                            _OpCache_with_parameter_route_reservation.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_reservation_lock(_ProjectionRead_route_reservation_mutex);
                                _OpCache_route_reservation.insert({param, _OpCache_with_parameter_route_reservation});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_reservation::HashEqual> _OpCache_with_parameter_route_reservation = _OpCache_with_parameter_route_reservation_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_reservation.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_reservation.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_reservation(writeState);
                            } else {
                                copiedState.route_reservation(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_reservation writeState = copiedState._update_for_route_reservation();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_reservation_lock(_ProjectionRead_route_reservation_mutex);
                                    _OpCache_with_parameter_route_reservation.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_reservation";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_freeing read__tr_route_freeing_state = state._projected_state_for__tr_route_freeing();
                auto _trid_2_ptr = _OpCache_tr_route_freeing.find(read__tr_route_freeing_state);
                if(_trid_2_ptr == _OpCache_tr_route_freeing.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_2 = state._tr_route_freeing();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_route_freeing_lock(_ProjectionRead__tr_route_freeing_mutex);
                        _OpCache_tr_route_freeing.insert({read__tr_route_freeing_state, _trid_2});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_2) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing readState = state._projected_state_for_route_freeing();

                        auto _OpCache_with_parameter_route_freeing_ptr = _OpCache_route_freeing.find(param);
                        if(_OpCache_with_parameter_route_freeing_ptr == _OpCache_route_freeing.end()) {
                            copiedState.route_freeing(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = copiedState._update_for_route_freeing();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::HashEqual> _OpCache_with_parameter_route_freeing;
                            _OpCache_with_parameter_route_freeing.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_freeing_lock(_ProjectionRead_route_freeing_mutex);
                                _OpCache_route_freeing.insert({param, _OpCache_with_parameter_route_freeing});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::HashEqual> _OpCache_with_parameter_route_freeing = _OpCache_with_parameter_route_freeing_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_freeing.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_freeing.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_freeing(writeState);
                            } else {
                                copiedState.route_freeing(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = copiedState._update_for_route_freeing();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_freeing_lock(_ProjectionRead_route_freeing_mutex);
                                    _OpCache_with_parameter_route_freeing.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_freeing";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_2 = _trid_2_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_2) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing readState = state._projected_state_for_route_freeing();

                        auto _OpCache_with_parameter_route_freeing_ptr = _OpCache_route_freeing.find(param);
                        if(_OpCache_with_parameter_route_freeing_ptr == _OpCache_route_freeing.end()) {
                            copiedState.route_freeing(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = copiedState._update_for_route_freeing();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::HashEqual> _OpCache_with_parameter_route_freeing;
                            _OpCache_with_parameter_route_freeing.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_freeing_lock(_ProjectionRead_route_freeing_mutex);
                                _OpCache_route_freeing.insert({param, _OpCache_with_parameter_route_freeing});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_freeing::HashEqual> _OpCache_with_parameter_route_freeing = _OpCache_with_parameter_route_freeing_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_freeing.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_freeing.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_freeing(writeState);
                            } else {
                                copiedState.route_freeing(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_freeing writeState = copiedState._update_for_route_freeing();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_freeing_lock(_ProjectionRead_route_freeing_mutex);
                                    _OpCache_with_parameter_route_freeing.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_freeing";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_1 read__tr_FRONT_MOVE_1_state = state._projected_state_for__tr_FRONT_MOVE_1();
                auto _trid_3_ptr = _OpCache_tr_FRONT_MOVE_1.find(read__tr_FRONT_MOVE_1_state);
                if(_trid_3_ptr == _OpCache_tr_FRONT_MOVE_1.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_3 = state._tr_FRONT_MOVE_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_FRONT_MOVE_1_lock(_ProjectionRead__tr_FRONT_MOVE_1_mutex);
                        _OpCache_tr_FRONT_MOVE_1.insert({read__tr_FRONT_MOVE_1_state, _trid_3});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_3) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1 readState = state._projected_state_for_FRONT_MOVE_1();

                        auto _OpCache_with_parameter_FRONT_MOVE_1_ptr = _OpCache_FRONT_MOVE_1.find(param);
                        if(_OpCache_with_parameter_FRONT_MOVE_1_ptr == _OpCache_FRONT_MOVE_1.end()) {
                            copiedState.FRONT_MOVE_1(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = copiedState._update_for_FRONT_MOVE_1();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::HashEqual> _OpCache_with_parameter_FRONT_MOVE_1;
                            _OpCache_with_parameter_FRONT_MOVE_1.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_1_lock(_ProjectionRead_FRONT_MOVE_1_mutex);
                                _OpCache_FRONT_MOVE_1.insert({param, _OpCache_with_parameter_FRONT_MOVE_1});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::HashEqual> _OpCache_with_parameter_FRONT_MOVE_1 = _OpCache_with_parameter_FRONT_MOVE_1_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_FRONT_MOVE_1.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_FRONT_MOVE_1.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_FRONT_MOVE_1(writeState);
                            } else {
                                copiedState.FRONT_MOVE_1(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = copiedState._update_for_FRONT_MOVE_1();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_1_lock(_ProjectionRead_FRONT_MOVE_1_mutex);
                                    _OpCache_with_parameter_FRONT_MOVE_1.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "FRONT_MOVE_1";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_3 = _trid_3_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_3) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1 readState = state._projected_state_for_FRONT_MOVE_1();

                        auto _OpCache_with_parameter_FRONT_MOVE_1_ptr = _OpCache_FRONT_MOVE_1.find(param);
                        if(_OpCache_with_parameter_FRONT_MOVE_1_ptr == _OpCache_FRONT_MOVE_1.end()) {
                            copiedState.FRONT_MOVE_1(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = copiedState._update_for_FRONT_MOVE_1();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::HashEqual> _OpCache_with_parameter_FRONT_MOVE_1;
                            _OpCache_with_parameter_FRONT_MOVE_1.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_1_lock(_ProjectionRead_FRONT_MOVE_1_mutex);
                                _OpCache_FRONT_MOVE_1.insert({param, _OpCache_with_parameter_FRONT_MOVE_1});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_1::HashEqual> _OpCache_with_parameter_FRONT_MOVE_1 = _OpCache_with_parameter_FRONT_MOVE_1_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_FRONT_MOVE_1.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_FRONT_MOVE_1.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_FRONT_MOVE_1(writeState);
                            } else {
                                copiedState.FRONT_MOVE_1(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_1 writeState = copiedState._update_for_FRONT_MOVE_1();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_1_lock(_ProjectionRead_FRONT_MOVE_1_mutex);
                                    _OpCache_with_parameter_FRONT_MOVE_1.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "FRONT_MOVE_1";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_FRONT_MOVE_2 read__tr_FRONT_MOVE_2_state = state._projected_state_for__tr_FRONT_MOVE_2();
                auto _trid_4_ptr = _OpCache_tr_FRONT_MOVE_2.find(read__tr_FRONT_MOVE_2_state);
                if(_trid_4_ptr == _OpCache_tr_FRONT_MOVE_2.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_FRONT_MOVE_2_lock(_ProjectionRead__tr_FRONT_MOVE_2_mutex);
                        _OpCache_tr_FRONT_MOVE_2.insert({read__tr_FRONT_MOVE_2_state, _trid_4});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_4) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2 readState = state._projected_state_for_FRONT_MOVE_2();

                        auto _OpCache_with_parameter_FRONT_MOVE_2_ptr = _OpCache_FRONT_MOVE_2.find(param);
                        if(_OpCache_with_parameter_FRONT_MOVE_2_ptr == _OpCache_FRONT_MOVE_2.end()) {
                            copiedState.FRONT_MOVE_2(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = copiedState._update_for_FRONT_MOVE_2();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::HashEqual> _OpCache_with_parameter_FRONT_MOVE_2;
                            _OpCache_with_parameter_FRONT_MOVE_2.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_2_lock(_ProjectionRead_FRONT_MOVE_2_mutex);
                                _OpCache_FRONT_MOVE_2.insert({param, _OpCache_with_parameter_FRONT_MOVE_2});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::HashEqual> _OpCache_with_parameter_FRONT_MOVE_2 = _OpCache_with_parameter_FRONT_MOVE_2_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_FRONT_MOVE_2.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_FRONT_MOVE_2.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_FRONT_MOVE_2(writeState);
                            } else {
                                copiedState.FRONT_MOVE_2(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = copiedState._update_for_FRONT_MOVE_2();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_2_lock(_ProjectionRead_FRONT_MOVE_2_mutex);
                                    _OpCache_with_parameter_FRONT_MOVE_2.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "FRONT_MOVE_2";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_4 = _trid_4_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_4) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2 readState = state._projected_state_for_FRONT_MOVE_2();

                        auto _OpCache_with_parameter_FRONT_MOVE_2_ptr = _OpCache_FRONT_MOVE_2.find(param);
                        if(_OpCache_with_parameter_FRONT_MOVE_2_ptr == _OpCache_FRONT_MOVE_2.end()) {
                            copiedState.FRONT_MOVE_2(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = copiedState._update_for_FRONT_MOVE_2();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::HashEqual> _OpCache_with_parameter_FRONT_MOVE_2;
                            _OpCache_with_parameter_FRONT_MOVE_2.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_2_lock(_ProjectionRead_FRONT_MOVE_2_mutex);
                                _OpCache_FRONT_MOVE_2.insert({param, _OpCache_with_parameter_FRONT_MOVE_2});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_FRONT_MOVE_2::HashEqual> _OpCache_with_parameter_FRONT_MOVE_2 = _OpCache_with_parameter_FRONT_MOVE_2_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_FRONT_MOVE_2.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_FRONT_MOVE_2.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_FRONT_MOVE_2(writeState);
                            } else {
                                copiedState.FRONT_MOVE_2(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_FRONT_MOVE_2 writeState = copiedState._update_for_FRONT_MOVE_2();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_FRONT_MOVE_2_lock(_ProjectionRead_FRONT_MOVE_2_mutex);
                                    _OpCache_with_parameter_FRONT_MOVE_2.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "FRONT_MOVE_2";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_1 read__tr_BACK_MOVE_1_state = state._projected_state_for__tr_BACK_MOVE_1();
                auto _trid_5_ptr = _OpCache_tr_BACK_MOVE_1.find(read__tr_BACK_MOVE_1_state);
                if(_trid_5_ptr == _OpCache_tr_BACK_MOVE_1.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_5 = state._tr_BACK_MOVE_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_BACK_MOVE_1_lock(_ProjectionRead__tr_BACK_MOVE_1_mutex);
                        _OpCache_tr_BACK_MOVE_1.insert({read__tr_BACK_MOVE_1_state, _trid_5});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_5) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1 readState = state._projected_state_for_BACK_MOVE_1();

                        auto _OpCache_with_parameter_BACK_MOVE_1_ptr = _OpCache_BACK_MOVE_1.find(param);
                        if(_OpCache_with_parameter_BACK_MOVE_1_ptr == _OpCache_BACK_MOVE_1.end()) {
                            copiedState.BACK_MOVE_1(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = copiedState._update_for_BACK_MOVE_1();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::HashEqual> _OpCache_with_parameter_BACK_MOVE_1;
                            _OpCache_with_parameter_BACK_MOVE_1.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_1_lock(_ProjectionRead_BACK_MOVE_1_mutex);
                                _OpCache_BACK_MOVE_1.insert({param, _OpCache_with_parameter_BACK_MOVE_1});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::HashEqual> _OpCache_with_parameter_BACK_MOVE_1 = _OpCache_with_parameter_BACK_MOVE_1_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_BACK_MOVE_1.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_BACK_MOVE_1.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_BACK_MOVE_1(writeState);
                            } else {
                                copiedState.BACK_MOVE_1(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = copiedState._update_for_BACK_MOVE_1();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_1_lock(_ProjectionRead_BACK_MOVE_1_mutex);
                                    _OpCache_with_parameter_BACK_MOVE_1.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "BACK_MOVE_1";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_5 = _trid_5_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_5) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1 readState = state._projected_state_for_BACK_MOVE_1();

                        auto _OpCache_with_parameter_BACK_MOVE_1_ptr = _OpCache_BACK_MOVE_1.find(param);
                        if(_OpCache_with_parameter_BACK_MOVE_1_ptr == _OpCache_BACK_MOVE_1.end()) {
                            copiedState.BACK_MOVE_1(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = copiedState._update_for_BACK_MOVE_1();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::HashEqual> _OpCache_with_parameter_BACK_MOVE_1;
                            _OpCache_with_parameter_BACK_MOVE_1.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_1_lock(_ProjectionRead_BACK_MOVE_1_mutex);
                                _OpCache_BACK_MOVE_1.insert({param, _OpCache_with_parameter_BACK_MOVE_1});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_1::HashEqual> _OpCache_with_parameter_BACK_MOVE_1 = _OpCache_with_parameter_BACK_MOVE_1_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_BACK_MOVE_1.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_BACK_MOVE_1.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_BACK_MOVE_1(writeState);
                            } else {
                                copiedState.BACK_MOVE_1(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_1 writeState = copiedState._update_for_BACK_MOVE_1();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_1_lock(_ProjectionRead_BACK_MOVE_1_mutex);
                                    _OpCache_with_parameter_BACK_MOVE_1.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "BACK_MOVE_1";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_BACK_MOVE_2 read__tr_BACK_MOVE_2_state = state._projected_state_for__tr_BACK_MOVE_2();
                auto _trid_6_ptr = _OpCache_tr_BACK_MOVE_2.find(read__tr_BACK_MOVE_2_state);
                if(_trid_6_ptr == _OpCache_tr_BACK_MOVE_2.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_6 = state._tr_BACK_MOVE_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_BACK_MOVE_2_lock(_ProjectionRead__tr_BACK_MOVE_2_mutex);
                        _OpCache_tr_BACK_MOVE_2.insert({read__tr_BACK_MOVE_2_state, _trid_6});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_6) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2 readState = state._projected_state_for_BACK_MOVE_2();

                        auto _OpCache_with_parameter_BACK_MOVE_2_ptr = _OpCache_BACK_MOVE_2.find(param);
                        if(_OpCache_with_parameter_BACK_MOVE_2_ptr == _OpCache_BACK_MOVE_2.end()) {
                            copiedState.BACK_MOVE_2(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = copiedState._update_for_BACK_MOVE_2();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::HashEqual> _OpCache_with_parameter_BACK_MOVE_2;
                            _OpCache_with_parameter_BACK_MOVE_2.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_2_lock(_ProjectionRead_BACK_MOVE_2_mutex);
                                _OpCache_BACK_MOVE_2.insert({param, _OpCache_with_parameter_BACK_MOVE_2});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::HashEqual> _OpCache_with_parameter_BACK_MOVE_2 = _OpCache_with_parameter_BACK_MOVE_2_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_BACK_MOVE_2.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_BACK_MOVE_2.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_BACK_MOVE_2(writeState);
                            } else {
                                copiedState.BACK_MOVE_2(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = copiedState._update_for_BACK_MOVE_2();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_2_lock(_ProjectionRead_BACK_MOVE_2_mutex);
                                    _OpCache_with_parameter_BACK_MOVE_2.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "BACK_MOVE_2";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_6 = _trid_6_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_6) {
                        Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2 readState = state._projected_state_for_BACK_MOVE_2();

                        auto _OpCache_with_parameter_BACK_MOVE_2_ptr = _OpCache_BACK_MOVE_2.find(param);
                        if(_OpCache_with_parameter_BACK_MOVE_2_ptr == _OpCache_BACK_MOVE_2.end()) {
                            copiedState.BACK_MOVE_2(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = copiedState._update_for_BACK_MOVE_2();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::HashEqual> _OpCache_with_parameter_BACK_MOVE_2;
                            _OpCache_with_parameter_BACK_MOVE_2.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_2_lock(_ProjectionRead_BACK_MOVE_2_mutex);
                                _OpCache_BACK_MOVE_2.insert({param, _OpCache_with_parameter_BACK_MOVE_2});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_BACK_MOVE_2::HashEqual> _OpCache_with_parameter_BACK_MOVE_2 = _OpCache_with_parameter_BACK_MOVE_2_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_BACK_MOVE_2.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_BACK_MOVE_2.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_BACK_MOVE_2(writeState);
                            } else {
                                copiedState.BACK_MOVE_2(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_BACK_MOVE_2 writeState = copiedState._update_for_BACK_MOVE_2();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_BACK_MOVE_2_lock(_ProjectionRead_BACK_MOVE_2_mutex);
                                    _OpCache_with_parameter_BACK_MOVE_2.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "BACK_MOVE_2";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_point_positionning read__tr_point_positionning_state = state._projected_state_for__tr_point_positionning();
                auto _trid_7_ptr = _OpCache_tr_point_positionning.find(read__tr_point_positionning_state);
                if(_trid_7_ptr == _OpCache_tr_point_positionning.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_7 = state._tr_point_positionning();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_point_positionning_lock(_ProjectionRead__tr_point_positionning_mutex);
                        _OpCache_tr_point_positionning.insert({read__tr_point_positionning_state, _trid_7});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_7) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning readState = state._projected_state_for_point_positionning();

                        auto _OpCache_with_parameter_point_positionning_ptr = _OpCache_point_positionning.find(param);
                        if(_OpCache_with_parameter_point_positionning_ptr == _OpCache_point_positionning.end()) {
                            copiedState.point_positionning(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = copiedState._update_for_point_positionning();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::HashEqual> _OpCache_with_parameter_point_positionning;
                            _OpCache_with_parameter_point_positionning.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_point_positionning_lock(_ProjectionRead_point_positionning_mutex);
                                _OpCache_point_positionning.insert({param, _OpCache_with_parameter_point_positionning});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::HashEqual> _OpCache_with_parameter_point_positionning = _OpCache_with_parameter_point_positionning_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_point_positionning.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_point_positionning.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = writeState_ptr->second;
                                copiedState._apply_update_for_point_positionning(writeState);
                            } else {
                                copiedState.point_positionning(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = copiedState._update_for_point_positionning();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_point_positionning_lock(_ProjectionRead_point_positionning_mutex);
                                    _OpCache_with_parameter_point_positionning.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "point_positionning";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_7 = _trid_7_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_7) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning readState = state._projected_state_for_point_positionning();

                        auto _OpCache_with_parameter_point_positionning_ptr = _OpCache_point_positionning.find(param);
                        if(_OpCache_with_parameter_point_positionning_ptr == _OpCache_point_positionning.end()) {
                            copiedState.point_positionning(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = copiedState._update_for_point_positionning();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::HashEqual> _OpCache_with_parameter_point_positionning;
                            _OpCache_with_parameter_point_positionning.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_point_positionning_lock(_ProjectionRead_point_positionning_mutex);
                                _OpCache_point_positionning.insert({param, _OpCache_with_parameter_point_positionning});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_point_positionning::HashEqual> _OpCache_with_parameter_point_positionning = _OpCache_with_parameter_point_positionning_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_point_positionning.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_point_positionning.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = writeState_ptr->second;
                                copiedState._apply_update_for_point_positionning(writeState);
                            } else {
                                copiedState.point_positionning(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_point_positionning writeState = copiedState._update_for_point_positionning();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_point_positionning_lock(_ProjectionRead_point_positionning_mutex);
                                    _OpCache_with_parameter_point_positionning.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "point_positionning";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__tr_route_formation read__tr_route_formation_state = state._projected_state_for__tr_route_formation();
                auto _trid_8_ptr = _OpCache_tr_route_formation.find(read__tr_route_formation_state);
                if(_trid_8_ptr == _OpCache_tr_route_formation.end()) {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_8 = state._tr_route_formation();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_route_formation_lock(_ProjectionRead__tr_route_formation_mutex);
                        _OpCache_tr_route_formation.insert({read__tr_route_formation_state, _trid_8});
                    }
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_8) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation readState = state._projected_state_for_route_formation();

                        auto _OpCache_with_parameter_route_formation_ptr = _OpCache_route_formation.find(param);
                        if(_OpCache_with_parameter_route_formation_ptr == _OpCache_route_formation.end()) {
                            copiedState.route_formation(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = copiedState._update_for_route_formation();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::HashEqual> _OpCache_with_parameter_route_formation;
                            _OpCache_with_parameter_route_formation.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_formation_lock(_ProjectionRead_route_formation_mutex);
                                _OpCache_route_formation.insert({param, _OpCache_with_parameter_route_formation});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::HashEqual> _OpCache_with_parameter_route_formation = _OpCache_with_parameter_route_formation_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_formation.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_formation.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_formation(writeState);
                            } else {
                                copiedState.route_formation(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = copiedState._update_for_route_formation();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_formation_lock(_ProjectionRead_route_formation_mutex);
                                    _OpCache_with_parameter_route_formation.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_formation";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                } else {
                    BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_8 = _trid_8_ptr->second;
                    for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_8) {
                        Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                        Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                        Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation readState = state._projected_state_for_route_formation();

                        auto _OpCache_with_parameter_route_formation_ptr = _OpCache_route_formation.find(param);
                        if(_OpCache_with_parameter_route_formation_ptr == _OpCache_route_formation.end()) {
                            copiedState.route_formation(_tmp_1);
                            Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = copiedState._update_for_route_formation();
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::HashEqual> _OpCache_with_parameter_route_formation;
                            _OpCache_with_parameter_route_formation.insert({readState, writeState});
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_route_formation_lock(_ProjectionRead_route_formation_mutex);
                                _OpCache_route_formation.insert({param, _OpCache_with_parameter_route_formation});
                            }

                        } else {
                            std::unordered_map<Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::Hash, Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead_route_formation::HashEqual> _OpCache_with_parameter_route_formation = _OpCache_with_parameter_route_formation_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_route_formation.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_route_formation.end()) {
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = writeState_ptr->second;
                                copiedState._apply_update_for_route_formation(writeState);
                            } else {
                                copiedState.route_formation(_tmp_1);
                                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionWrite_route_formation writeState = copiedState._update_for_route_formation();
                                {
                                    std::unique_lock<std::mutex> _ProjectionRead_route_formation_lock(_ProjectionRead_route_formation_mutex);
                                    _OpCache_with_parameter_route_formation.insert({readState, writeState});
                                }
                            }
                        }

                        copiedState.stateAccessedVia = "route_formation";
                        result.insert(copiedState);
                        transitions += 1;
                    }
                }

            } else {
                BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_1 = state._tr_route_reservation();
                for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_1) {
                    Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_reservation(_tmp_1);
                    copiedState.stateAccessedVia = "route_reservation";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_2 = state._tr_route_freeing();
                for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_2) {
                    Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_freeing(_tmp_1);
                    copiedState.stateAccessedVia = "route_freeing";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_3 = state._tr_FRONT_MOVE_1();
                for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_3) {
                    Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.FRONT_MOVE_1(_tmp_1);
                    copiedState.stateAccessedVia = "FRONT_MOVE_1";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2();
                for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_4) {
                    Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.FRONT_MOVE_2(_tmp_1);
                    copiedState.stateAccessedVia = "FRONT_MOVE_2";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_5 = state._tr_BACK_MOVE_1();
                for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_5) {
                    Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.BACK_MOVE_1(_tmp_1);
                    copiedState.stateAccessedVia = "BACK_MOVE_1";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::BLOCKS> _trid_6 = state._tr_BACK_MOVE_2();
                for(const Train_1_beebook_deterministic_MC_POR_v3::BLOCKS& param : _trid_6) {
                    Train_1_beebook_deterministic_MC_POR_v3::BLOCKS _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.BACK_MOVE_2(_tmp_1);
                    copiedState.stateAccessedVia = "BACK_MOVE_2";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_7 = state._tr_point_positionning();
                for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_7) {
                    Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.point_positionning(_tmp_1);
                    copiedState.stateAccessedVia = "point_positionning";
                    result.insert(copiedState);
                    transitions += 1;
                }
                BSet<Train_1_beebook_deterministic_MC_POR_v3::ROUTES> _trid_8 = state._tr_route_formation();
                for(const Train_1_beebook_deterministic_MC_POR_v3::ROUTES& param : _trid_8) {
                    Train_1_beebook_deterministic_MC_POR_v3::ROUTES _tmp_1 = param;

                    Train_1_beebook_deterministic_MC_POR_v3 copiedState = state._copy();
                    copiedState.route_formation(_tmp_1);
                    copiedState.stateAccessedVia = "route_formation";
                    result.insert(copiedState);
                    transitions += 1;
                }

            }
            return result;
        }

        bool invariantViolated(const Train_1_beebook_deterministic_MC_POR_v3& state) {
            bool _check_inv_1;
            if(isCaching) {
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
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
                Train_1_beebook_deterministic_MC_POR_v3::_ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
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

    Train_1_beebook_deterministic_MC_POR_v3::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v3::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v3::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v3::Type::DFS;
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