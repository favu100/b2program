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

#ifndef sort_m2_data1000_MC_H
#define sort_m2_data1000_MC_H

using namespace std;

class sort_m2_data1000_MC {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const sort_m2_data1000_MC& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const sort_m2_data1000_MC& obj1, const sort_m2_data1000_MC& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

        class _ProjectionRead_progress {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_progress& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_progress& obj1, const _ProjectionRead_progress& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead_progress(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead_progress& o1, const _ProjectionRead_progress& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead_progress& o1, const _ProjectionRead_progress& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_progress& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", ";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_progress {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_progress& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_progress& obj1, const _ProjectionRead__tr_progress& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger j;
                BInteger k;

                _ProjectionRead__tr_progress(const BInteger& j, const BInteger& k) {
                    this->j = j;
                    this->k = k;
                }

                friend bool operator ==(const _ProjectionRead__tr_progress& o1, const _ProjectionRead__tr_progress& o2) {
                    return o1.j == (o2.j) && o1.k == (o2.k);
                }

                friend bool operator !=(const _ProjectionRead__tr_progress& o1, const _ProjectionRead__tr_progress& o2) {
                    return o1.j != (o2.j) || o1.k != (o2.k);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_progress& e) {
                    strm << "{";
                    strm << "j: " << e.j;
                    strm << ", "; 
                    strm << "k: " << e.k;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_progress {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_progress& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_progress& obj1, const _ProjectionWrite_progress& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionWrite_progress(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionWrite_progress& o1, const _ProjectionWrite_progress& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionWrite_progress& o1, const _ProjectionWrite_progress& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_progress& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", ";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_prog1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_prog1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_prog1& obj1, const _ProjectionRead_prog1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead_prog1(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead_prog1& o1, const _ProjectionRead_prog1& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead_prog1& o1, const _ProjectionRead_prog1& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_prog1& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", ";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_prog1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_prog1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_prog1& obj1, const _ProjectionRead__tr_prog1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead__tr_prog1(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead__tr_prog1& o1, const _ProjectionRead__tr_prog1& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead__tr_prog1& o1, const _ProjectionRead__tr_prog1& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_prog1& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", "; 
                    strm << "j: " << e.j;
                    strm << ", "; 
                    strm << "k: " << e.k;
                    strm << ", "; 
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_prog1 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_prog1& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_prog1& obj1, const _ProjectionWrite_prog1& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger j;
                BInteger l;

                _ProjectionWrite_prog1(const BInteger& j, const BInteger& l) {
                    this->j = j;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionWrite_prog1& o1, const _ProjectionWrite_prog1& o2) {
                    return o1.j == (o2.j) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionWrite_prog1& o1, const _ProjectionWrite_prog1& o2) {
                    return o1.j != (o2.j) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_prog1& e) {
                    strm << "{";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_prog2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_prog2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_prog2& obj1, const _ProjectionRead_prog2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead_prog2(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead_prog2& o1, const _ProjectionRead_prog2& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead_prog2& o1, const _ProjectionRead_prog2& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_prog2& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", ";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_prog2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_prog2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_prog2& obj1, const _ProjectionRead__tr_prog2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead__tr_prog2(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead__tr_prog2& o1, const _ProjectionRead__tr_prog2& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead__tr_prog2& o1, const _ProjectionRead__tr_prog2& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_prog2& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", "; 
                    strm << "j: " << e.j;
                    strm << ", "; 
                    strm << "k: " << e.k;
                    strm << ", "; 
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_prog2 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_prog2& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_prog2& obj1, const _ProjectionWrite_prog2& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger j;
                BInteger l;

                _ProjectionWrite_prog2(const BInteger& j, const BInteger& l) {
                    this->j = j;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionWrite_prog2& o1, const _ProjectionWrite_prog2& o2) {
                    return o1.j == (o2.j) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionWrite_prog2& o1, const _ProjectionWrite_prog2& o2) {
                    return o1.j != (o2.j) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_prog2& e) {
                    strm << "{";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_final_evt {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_final_evt& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_final_evt& obj1, const _ProjectionRead_final_evt& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger k;

                _ProjectionRead_final_evt(const BInteger& k) {
                    this->k = k;
                }

                friend bool operator ==(const _ProjectionRead_final_evt& o1, const _ProjectionRead_final_evt& o2) {
                    return o1.k == (o2.k);
                }

                friend bool operator !=(const _ProjectionRead_final_evt& o1, const _ProjectionRead_final_evt& o2) {
                    return o1.k != (o2.k);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_final_evt& e) {
                    strm << "{";
                    strm << "k: " << e.k;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (k.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_final_evt {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_final_evt& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_final_evt& obj1, const _ProjectionRead__tr_final_evt& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BInteger k;

                _ProjectionRead__tr_final_evt(const BInteger& k) {
                    this->k = k;
                }

                friend bool operator ==(const _ProjectionRead__tr_final_evt& o1, const _ProjectionRead__tr_final_evt& o2) {
                    return o1.k == (o2.k);
                }

                friend bool operator !=(const _ProjectionRead__tr_final_evt& o1, const _ProjectionRead__tr_final_evt& o2) {
                    return o1.k != (o2.k);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_final_evt& e) {
                    strm << "{";
                    strm << "k: " << e.k;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (k.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_final_evt {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_final_evt& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_final_evt& obj1, const _ProjectionWrite_final_evt& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_final_evt() {
                }

                friend bool operator ==(const _ProjectionWrite_final_evt& o1, const _ProjectionWrite_final_evt& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_final_evt& o1, const _ProjectionWrite_final_evt& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_final_evt& e) {
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

                BInteger j;
                BInteger k;

                _ProjectionRead__check_inv_1(const BInteger& j, const BInteger& k) {
                    this->j = j;
                    this->k = k;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.j == (o2.j) && o1.k == (o2.k);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.j != (o2.j) || o1.k != (o2.k);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
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

                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead__check_inv_2(const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
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

                BRelation<BInteger, BInteger > g;
                BInteger j;
                BInteger k;
                BInteger l;

                _ProjectionRead__check_inv_3(const BRelation<BInteger, BInteger >& g, const BInteger& j, const BInteger& k, const BInteger& l) {
                    this->g = g;
                    this->j = j;
                    this->k = k;
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.g == (o2.g) && o1.j == (o2.j) && o1.k == (o2.k) && o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.g != (o2.g) || o1.j != (o2.j) || o1.k != (o2.k) || o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "g: " << e.g;
                    strm << ", ";
                    strm << "j: " << e.j;
                    strm << ", ";
                    strm << "k: " << e.k;
                    strm << ", ";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
                    result = 31 * result + (j.hashCode() << 1);
                    result = 31 * result + (k.hashCode() << 1);
                    result = 31 * result + (l.hashCode() << 1);
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

                BRelation<BInteger, BInteger > g;

                _ProjectionRead__check_inv_4(const BRelation<BInteger, BInteger >& g) {
                    this->g = g;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.g == (o2.g);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.g != (o2.g);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "g: " << e.g;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
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

                BRelation<BInteger, BInteger > g;

                _ProjectionRead__check_inv_5(const BRelation<BInteger, BInteger >& g) {
                    this->g = g;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.g == (o2.g);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.g != (o2.g);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "g: " << e.g;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (g.hashCode() << 1);
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

                BInteger k;

                _ProjectionRead__check_inv_6(const BInteger& k) {
                    this->k = k;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.k == (o2.k);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.k != (o2.k);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "k: " << e.k;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (k.hashCode() << 1);
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

                BInteger l;

                _ProjectionRead__check_inv_7(const BInteger& l) {
                    this->l = l;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.l == (o2.l);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.l != (o2.l);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "l: " << e.l;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (l.hashCode() << 1);
                    return result;
                }

        };



    private:

        BInteger n;
        BRelation<BInteger, BInteger > f;
        BSet<BInteger > __aux_constant_2;
        BSet<BInteger > __aux_constant_1;



        BInteger j;
        BInteger k;
        BInteger l;
        BRelation<BInteger, BInteger > g;


    public:

        std::string stateAccessedVia;

        sort_m2_data1000_MC() {
            n = (BInteger(1000));
            BRelation<BInteger, BInteger > _ic_set_0 = BRelation<BInteger, BInteger >();
            for(const BInteger& _ic_i_1 : (BSet<BInteger>::interval((BInteger(1)),n))) {
                _ic_set_0 = _ic_set_0._union(BRelation<BInteger, BInteger>(BTuple<BInteger, BInteger>(_ic_i_1, (BInteger(15000)).minus(_ic_i_1))));

            }

            f = _ic_set_0;
            __aux_constant_2 = f.range();
            __aux_constant_1 = (BSet<BInteger>::interval((BInteger(1)),n));
            if(!((BBoolean((BBoolean((n.isInteger()).booleanValue() && n.greater((BInteger(0))).booleanValue())).booleanValue() && ((f.checkDomain((BSet<BInteger>::interval((BInteger(1)),n))))._and((f.checkRangeNatural()))._and((f.isFunction()))._and((f.isTotal((BSet<BInteger>::interval((BInteger(1)),n)))))).booleanValue()))).booleanValue()) {
                throw std::runtime_error("Contradiction in PROPERTIES detected!");
            }
            g = f;
            k = (BInteger(1));
            l = (BInteger(1));
            j = (BInteger(1));
        }

        sort_m2_data1000_MC(const sort_m2_data1000_MC& copy) {
            this->n = copy.n;
            this->f = copy.f;
            this->__aux_constant_2 = copy.__aux_constant_2;
            this->__aux_constant_1 = copy.__aux_constant_1;
            this->j = copy.j;
            this->k = copy.k;
            this->l = copy.l;
            this->g = copy.g;
        }

        void progress() {
            BRelation<BInteger, BInteger > _ld_g = g;
            BInteger _ld_k = k;
            BInteger _ld_l = l;
            g = _ld_g.override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_k, _ld_g.functionCall(_ld_l))))).override((BRelation<BInteger, BInteger >((BTuple<BInteger, BInteger >(_ld_l, _ld_g.functionCall(_ld_k)))))));
            k = _ld_k.plus((BInteger(1)));
            j = _ld_k.plus((BInteger(1)));
            l = _ld_k.plus((BInteger(1)));

        }

        void prog1() {
            BInteger _ld_j = j;
            BInteger _ld_l = l;
            l = _ld_l;
            j = _ld_j.plus((BInteger(1)));

        }

        void prog2() {
            BInteger _ld_j = j;
            j = _ld_j.plus((BInteger(1)));
            l = _ld_j.plus((BInteger(1)));

        }

        void final_evt() {
        }

        BInteger _get_n() const {
            return n;
        }

        BRelation<BInteger, BInteger > _get_f() const {
            return f;
        }

        BSet<BInteger > _get___aux_constant_2() const {
            return __aux_constant_2;
        }

        BSet<BInteger > _get___aux_constant_1() const {
            return __aux_constant_1;
        }

        BInteger _get_j() const {
            return j;
        }

        BInteger _get_k() const {
            return k;
        }

        BInteger _get_l() const {
            return l;
        }

        BRelation<BInteger, BInteger > _get_g() const {
            return g;
        }


        bool _tr_progress() const {
            return ((BBoolean(k.unequal(n).booleanValue() && j.equal(n).booleanValue()))).booleanValue();
        }

        bool _tr_prog1() const {
            return ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).lessEqual(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
        }

        bool _tr_prog2() const {
            return ((BBoolean((BBoolean(k.unequal(n).booleanValue() && j.unequal(n).booleanValue())).booleanValue() && g.functionCall(l).greater(g.functionCall(j.plus((BInteger(1))))).booleanValue()))).booleanValue();
        }

        bool _tr_final_evt() const {
            return (k.equal(n)).booleanValue();
        }

        _ProjectionRead_prog2 _projected_state_for_prog2() const {
            return _ProjectionRead_prog2(g,j,k,l);
        }

        _ProjectionRead_prog1 _projected_state_for_prog1() const {
            return _ProjectionRead_prog1(g,j,k,l);
        }

        _ProjectionRead_progress _projected_state_for_progress() const {
            return _ProjectionRead_progress(g,j,k,l);
        }

        _ProjectionRead_final_evt _projected_state_for_final_evt() const {
            return _ProjectionRead_final_evt(k);
        }

        _ProjectionRead__tr_final_evt _projected_state_for__tr_final_evt() const {
            return _ProjectionRead__tr_final_evt(k);
        }

        _ProjectionRead__tr_progress _projected_state_for__tr_progress() const {
            return _ProjectionRead__tr_progress(j,k);
        }

        _ProjectionRead__tr_prog1 _projected_state_for__tr_prog1() const {
            return _ProjectionRead__tr_prog1(g,j,k,l);
        }

        _ProjectionRead__tr_prog2 _projected_state_for__tr_prog2() const {
            return _ProjectionRead__tr_prog2(g,j,k,l);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(j,k,l);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(g,j,k,l);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(j,k);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(k);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(l);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(g);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(g);
        }

        _ProjectionWrite_prog2 _update_for_prog2() const {
            return _ProjectionWrite_prog2(j,l);
        }

        _ProjectionWrite_prog1 _update_for_prog1() const {
            return _ProjectionWrite_prog1(j,l);
        }

        _ProjectionWrite_progress _update_for_progress() const {
            return _ProjectionWrite_progress(g,j,k,l);
        }

        _ProjectionWrite_final_evt _update_for_final_evt() const {
            return _ProjectionWrite_final_evt();
        }

        void _apply_update_for_prog2(const _ProjectionWrite_prog2& update) {
            this->j = update.j;
            this->l = update.l;
        }

        void _apply_update_for_prog1(const _ProjectionWrite_prog1& update) {
            this->j = update.j;
            this->l = update.l;
        }

        void _apply_update_for_progress(const _ProjectionWrite_progress& update) {
            this->g = update.g;
            this->j = update.j;
            this->k = update.k;
            this->l = update.l;
        }

        void _apply_update_for_final_evt(const _ProjectionWrite_final_evt& update) {
        }

        bool _check_inv_1() const {
            return ((BBoolean(j.greaterEqual(k).booleanValue() && j.lessEqual(n).booleanValue()))).booleanValue();
        }

        bool _check_inv_2() const {
            return ((BBoolean(l.greaterEqual(k).booleanValue() && l.lessEqual(j).booleanValue()))).booleanValue();
        }

        bool _check_inv_3() const {
            return (g.functionCall(l).equal(g.relationImage((BSet<BInteger>::interval(k,j))).min())).booleanValue();
        }

        bool _check_inv_4() const {
            return (((g.checkDomain(__aux_constant_1))._and((g.checkRangeNatural()))._and((g.isFunction()))._and((g.isTotal(__aux_constant_1))))).booleanValue();
        }

        bool _check_inv_5() const {
            return (g.range().equal(__aux_constant_2)).booleanValue();
        }

        bool _check_inv_6() const {
            return ((BBoolean(k.greaterEqual((BInteger(1))).booleanValue() && k.lessEqual(n).booleanValue()))).booleanValue();
        }

        bool _check_inv_7() const {
            return ((l.isNatural())).booleanValue();
        }

        sort_m2_data1000_MC _copy() const {
            return sort_m2_data1000_MC(*this);
        }

        friend bool operator ==(const sort_m2_data1000_MC& o1, const sort_m2_data1000_MC& o2) {
            return o1._get_j() == o2._get_j() && o1._get_k() == o2._get_k() && o1._get_l() == o2._get_l() && o1._get_g() == o2._get_g();
        }

        friend bool operator !=(const sort_m2_data1000_MC& o1, const sort_m2_data1000_MC& o2) {
            return o1._get_j() != o2._get_j() || o1._get_k() != o2._get_k() || o1._get_l() != o2._get_l() || o1._get_g() != o2._get_g();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_j()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_k()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_l()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_g()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_j()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_k()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_l()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_g()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const sort_m2_data1000_MC& machine) {
          strm << "_get_j: " << machine._get_j() << "\n";
          strm << "_get_k: " << machine._get_k() << "\n";
          strm << "_get_l: " << machine._get_l() << "\n";
          strm << "_get_g: " << machine._get_g() << "\n";
          return strm;
        }


};


class ModelChecker {
    private:
        sort_m2_data1000_MC::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<sort_m2_data1000_MC> unvisitedStates;
        std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        sort_m2_data1000_MC counterExampleState;

        std::unordered_map<bool, std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_progress, sort_m2_data1000_MC::_ProjectionWrite_progress, sort_m2_data1000_MC::_ProjectionRead_progress::Hash, sort_m2_data1000_MC::_ProjectionRead_progress::HashEqual>> _OpCache_progress;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__tr_progress, bool, sort_m2_data1000_MC::_ProjectionRead__tr_progress::Hash, sort_m2_data1000_MC::_ProjectionRead__tr_progress::HashEqual> _OpCache_tr_progress;
        std::mutex _ProjectionRead_progress_mutex;
        std::mutex _ProjectionRead__tr_progress_mutex;

        std::unordered_map<bool, std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog1, sort_m2_data1000_MC::_ProjectionWrite_prog1, sort_m2_data1000_MC::_ProjectionRead_prog1::Hash, sort_m2_data1000_MC::_ProjectionRead_prog1::HashEqual>> _OpCache_prog1;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__tr_prog1, bool, sort_m2_data1000_MC::_ProjectionRead__tr_prog1::Hash, sort_m2_data1000_MC::_ProjectionRead__tr_prog1::HashEqual> _OpCache_tr_prog1;
        std::mutex _ProjectionRead_prog1_mutex;
        std::mutex _ProjectionRead__tr_prog1_mutex;

        std::unordered_map<bool, std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog2, sort_m2_data1000_MC::_ProjectionWrite_prog2, sort_m2_data1000_MC::_ProjectionRead_prog2::Hash, sort_m2_data1000_MC::_ProjectionRead_prog2::HashEqual>> _OpCache_prog2;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__tr_prog2, bool, sort_m2_data1000_MC::_ProjectionRead__tr_prog2::Hash, sort_m2_data1000_MC::_ProjectionRead__tr_prog2::HashEqual> _OpCache_tr_prog2;
        std::mutex _ProjectionRead_prog2_mutex;
        std::mutex _ProjectionRead__tr_prog2_mutex;

        std::unordered_map<bool, std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_final_evt, sort_m2_data1000_MC::_ProjectionWrite_final_evt, sort_m2_data1000_MC::_ProjectionRead_final_evt::Hash, sort_m2_data1000_MC::_ProjectionRead_final_evt::HashEqual>> _OpCache_final_evt;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__tr_final_evt, bool, sort_m2_data1000_MC::_ProjectionRead__tr_final_evt::Hash, sort_m2_data1000_MC::_ProjectionRead__tr_final_evt::HashEqual> _OpCache_tr_final_evt;
        std::mutex _ProjectionRead_final_evt_mutex;
        std::mutex _ProjectionRead__tr_final_evt_mutex;

        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_1, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_1::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_2, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_2::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_3, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_3::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_4, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_4::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_5, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_5::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_6, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_6::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<sort_m2_data1000_MC::_ProjectionRead__check_inv_7, bool, sort_m2_data1000_MC::_ProjectionRead__check_inv_7::Hash, sort_m2_data1000_MC::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;

        std::unordered_map<sort_m2_data1000_MC, sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(sort_m2_data1000_MC::Type type, int threads, bool isCaching, bool isDebug) {
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
            sort_m2_data1000_MC machine = sort_m2_data1000_MC();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                sort_m2_data1000_MC state = next();

                std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(state);

                for(const sort_m2_data1000_MC& nextState : nextStates) {
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
            sort_m2_data1000_MC machine = sort_m2_data1000_MC();
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
                sort_m2_data1000_MC state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> nextStates = generateNextStates(state);

                    for(const sort_m2_data1000_MC& nextState : nextStates) {
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
        sort_m2_data1000_MC next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case sort_m2_data1000_MC::BFS: {
                        sort_m2_data1000_MC state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case sort_m2_data1000_MC::DFS: {
                        sort_m2_data1000_MC state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case sort_m2_data1000_MC::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            sort_m2_data1000_MC state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            sort_m2_data1000_MC state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
                sort_m2_data1000_MC state = unvisitedStates.front();
                unvisitedStates.pop_front();
                return state;
            };
        }

        std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> generateNextStates(const sort_m2_data1000_MC& state) {
            std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual> result = std::unordered_set<sort_m2_data1000_MC, sort_m2_data1000_MC::Hash, sort_m2_data1000_MC::HashEqual>();
            if(isCaching) {
                sort_m2_data1000_MC::_ProjectionRead__tr_progress read__tr_progress_state = state._projected_state_for__tr_progress();
                bool _trid_1 = false;
                auto _obj__trid_1_ptr = _OpCache_tr_progress.find(read__tr_progress_state);
                if(_obj__trid_1_ptr == _OpCache_tr_progress.end()) {
                    _trid_1 = state._tr_progress();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_progress_lock(_ProjectionRead__tr_progress_mutex);
                        _OpCache_tr_progress.insert({read__tr_progress_state, _trid_1});
                    }
                } else {
                    _trid_1 = _obj__trid_1_ptr->second;
                }
                if(_trid_1) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    sort_m2_data1000_MC::_ProjectionRead_progress readState = state._projected_state_for_progress();

                    auto _OpCache_with_parameter_progress_ptr = _OpCache_progress.find(_trid_1);
                    if(_OpCache_with_parameter_progress_ptr == _OpCache_progress.end()) {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_progress_lock(_ProjectionRead_progress_mutex);
                            copiedState.progress();
                            sort_m2_data1000_MC::_ProjectionWrite_progress writeState = copiedState._update_for_progress();
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_progress, sort_m2_data1000_MC::_ProjectionWrite_progress, sort_m2_data1000_MC::_ProjectionRead_progress::Hash, sort_m2_data1000_MC::_ProjectionRead_progress::HashEqual> _OpCache_with_parameter_progress = std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_progress, sort_m2_data1000_MC::_ProjectionWrite_progress, sort_m2_data1000_MC::_ProjectionRead_progress::Hash, sort_m2_data1000_MC::_ProjectionRead_progress::HashEqual>();
                            _OpCache_with_parameter_progress.insert({readState, writeState});
                            _OpCache_progress.insert({_trid_1, _OpCache_with_parameter_progress});
                        }
                    } else {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_progress_lock(_ProjectionRead_progress_mutex);
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_progress, sort_m2_data1000_MC::_ProjectionWrite_progress, sort_m2_data1000_MC::_ProjectionRead_progress::Hash, sort_m2_data1000_MC::_ProjectionRead_progress::HashEqual> _OpCache_with_parameter_progress = _OpCache_with_parameter_progress_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_progress.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_progress.end()) {
                                sort_m2_data1000_MC::_ProjectionWrite_progress writeState = writeState_ptr->second;
                                copiedState._apply_update_for_progress(writeState);
                            } else {
                                copiedState.progress();
                                sort_m2_data1000_MC::_ProjectionWrite_progress writeState = copiedState._update_for_progress();
                                _OpCache_with_parameter_progress.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "progress";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                sort_m2_data1000_MC::_ProjectionRead__tr_prog1 read__tr_prog1_state = state._projected_state_for__tr_prog1();
                bool _trid_2 = false;
                auto _obj__trid_2_ptr = _OpCache_tr_prog1.find(read__tr_prog1_state);
                if(_obj__trid_2_ptr == _OpCache_tr_prog1.end()) {
                    _trid_2 = state._tr_prog1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_prog1_lock(_ProjectionRead__tr_prog1_mutex);
                        _OpCache_tr_prog1.insert({read__tr_prog1_state, _trid_2});
                    }
                } else {
                    _trid_2 = _obj__trid_2_ptr->second;
                }
                if(_trid_2) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    sort_m2_data1000_MC::_ProjectionRead_prog1 readState = state._projected_state_for_prog1();

                    auto _OpCache_with_parameter_prog1_ptr = _OpCache_prog1.find(_trid_2);
                    if(_OpCache_with_parameter_prog1_ptr == _OpCache_prog1.end()) {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_prog1_lock(_ProjectionRead_prog1_mutex);
                            copiedState.prog1();
                            sort_m2_data1000_MC::_ProjectionWrite_prog1 writeState = copiedState._update_for_prog1();
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog1, sort_m2_data1000_MC::_ProjectionWrite_prog1, sort_m2_data1000_MC::_ProjectionRead_prog1::Hash, sort_m2_data1000_MC::_ProjectionRead_prog1::HashEqual> _OpCache_with_parameter_prog1 = std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog1, sort_m2_data1000_MC::_ProjectionWrite_prog1, sort_m2_data1000_MC::_ProjectionRead_prog1::Hash, sort_m2_data1000_MC::_ProjectionRead_prog1::HashEqual>();
                            _OpCache_with_parameter_prog1.insert({readState, writeState});
                            _OpCache_prog1.insert({_trid_2, _OpCache_with_parameter_prog1});
                        }
                    } else {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_prog1_lock(_ProjectionRead_prog1_mutex);
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog1, sort_m2_data1000_MC::_ProjectionWrite_prog1, sort_m2_data1000_MC::_ProjectionRead_prog1::Hash, sort_m2_data1000_MC::_ProjectionRead_prog1::HashEqual> _OpCache_with_parameter_prog1 = _OpCache_with_parameter_prog1_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_prog1.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_prog1.end()) {
                                sort_m2_data1000_MC::_ProjectionWrite_prog1 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_prog1(writeState);
                            } else {
                                copiedState.prog1();
                                sort_m2_data1000_MC::_ProjectionWrite_prog1 writeState = copiedState._update_for_prog1();
                                _OpCache_with_parameter_prog1.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "prog1";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                sort_m2_data1000_MC::_ProjectionRead__tr_prog2 read__tr_prog2_state = state._projected_state_for__tr_prog2();
                bool _trid_3 = false;
                auto _obj__trid_3_ptr = _OpCache_tr_prog2.find(read__tr_prog2_state);
                if(_obj__trid_3_ptr == _OpCache_tr_prog2.end()) {
                    _trid_3 = state._tr_prog2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_prog2_lock(_ProjectionRead__tr_prog2_mutex);
                        _OpCache_tr_prog2.insert({read__tr_prog2_state, _trid_3});
                    }
                } else {
                    _trid_3 = _obj__trid_3_ptr->second;
                }
                if(_trid_3) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    sort_m2_data1000_MC::_ProjectionRead_prog2 readState = state._projected_state_for_prog2();

                    auto _OpCache_with_parameter_prog2_ptr = _OpCache_prog2.find(_trid_3);
                    if(_OpCache_with_parameter_prog2_ptr == _OpCache_prog2.end()) {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_prog2_lock(_ProjectionRead_prog2_mutex);
                            copiedState.prog2();
                            sort_m2_data1000_MC::_ProjectionWrite_prog2 writeState = copiedState._update_for_prog2();
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog2, sort_m2_data1000_MC::_ProjectionWrite_prog2, sort_m2_data1000_MC::_ProjectionRead_prog2::Hash, sort_m2_data1000_MC::_ProjectionRead_prog2::HashEqual> _OpCache_with_parameter_prog2 = std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog2, sort_m2_data1000_MC::_ProjectionWrite_prog2, sort_m2_data1000_MC::_ProjectionRead_prog2::Hash, sort_m2_data1000_MC::_ProjectionRead_prog2::HashEqual>();
                            _OpCache_with_parameter_prog2.insert({readState, writeState});
                            _OpCache_prog2.insert({_trid_3, _OpCache_with_parameter_prog2});
                        }
                    } else {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_prog2_lock(_ProjectionRead_prog2_mutex);
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_prog2, sort_m2_data1000_MC::_ProjectionWrite_prog2, sort_m2_data1000_MC::_ProjectionRead_prog2::Hash, sort_m2_data1000_MC::_ProjectionRead_prog2::HashEqual> _OpCache_with_parameter_prog2 = _OpCache_with_parameter_prog2_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_prog2.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_prog2.end()) {
                                sort_m2_data1000_MC::_ProjectionWrite_prog2 writeState = writeState_ptr->second;
                                copiedState._apply_update_for_prog2(writeState);
                            } else {
                                copiedState.prog2();
                                sort_m2_data1000_MC::_ProjectionWrite_prog2 writeState = copiedState._update_for_prog2();
                                _OpCache_with_parameter_prog2.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "prog2";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                sort_m2_data1000_MC::_ProjectionRead__tr_final_evt read__tr_final_evt_state = state._projected_state_for__tr_final_evt();
                bool _trid_4 = false;
                auto _obj__trid_4_ptr = _OpCache_tr_final_evt.find(read__tr_final_evt_state);
                if(_obj__trid_4_ptr == _OpCache_tr_final_evt.end()) {
                    _trid_4 = state._tr_final_evt();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_final_evt_lock(_ProjectionRead__tr_final_evt_mutex);
                        _OpCache_tr_final_evt.insert({read__tr_final_evt_state, _trid_4});
                    }
                } else {
                    _trid_4 = _obj__trid_4_ptr->second;
                }
                if(_trid_4) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    sort_m2_data1000_MC::_ProjectionRead_final_evt readState = state._projected_state_for_final_evt();

                    auto _OpCache_with_parameter_final_evt_ptr = _OpCache_final_evt.find(_trid_4);
                    if(_OpCache_with_parameter_final_evt_ptr == _OpCache_final_evt.end()) {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_final_evt_lock(_ProjectionRead_final_evt_mutex);
                            copiedState.final_evt();
                            sort_m2_data1000_MC::_ProjectionWrite_final_evt writeState = copiedState._update_for_final_evt();
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_final_evt, sort_m2_data1000_MC::_ProjectionWrite_final_evt, sort_m2_data1000_MC::_ProjectionRead_final_evt::Hash, sort_m2_data1000_MC::_ProjectionRead_final_evt::HashEqual> _OpCache_with_parameter_final_evt = std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_final_evt, sort_m2_data1000_MC::_ProjectionWrite_final_evt, sort_m2_data1000_MC::_ProjectionRead_final_evt::Hash, sort_m2_data1000_MC::_ProjectionRead_final_evt::HashEqual>();
                            _OpCache_with_parameter_final_evt.insert({readState, writeState});
                            _OpCache_final_evt.insert({_trid_4, _OpCache_with_parameter_final_evt});
                        }
                    } else {
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_final_evt_lock(_ProjectionRead_final_evt_mutex);
                            std::unordered_map<sort_m2_data1000_MC::_ProjectionRead_final_evt, sort_m2_data1000_MC::_ProjectionWrite_final_evt, sort_m2_data1000_MC::_ProjectionRead_final_evt::Hash, sort_m2_data1000_MC::_ProjectionRead_final_evt::HashEqual> _OpCache_with_parameter_final_evt = _OpCache_with_parameter_final_evt_ptr->second;
                            auto writeState_ptr = _OpCache_with_parameter_final_evt.find(readState);
                            if(writeState_ptr != _OpCache_with_parameter_final_evt.end()) {
                                sort_m2_data1000_MC::_ProjectionWrite_final_evt writeState = writeState_ptr->second;
                                copiedState._apply_update_for_final_evt(writeState);
                            } else {
                                copiedState.final_evt();
                                sort_m2_data1000_MC::_ProjectionWrite_final_evt writeState = copiedState._update_for_final_evt();
                                _OpCache_with_parameter_final_evt.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "final_evt";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            } else {
                if(state._tr_progress()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.progress();
                    copiedState.stateAccessedVia = "progress";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_prog1()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog1();
                    copiedState.stateAccessedVia = "prog1";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_prog2()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.prog2();
                    copiedState.stateAccessedVia = "prog2";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                if(state._tr_final_evt()) {
                    sort_m2_data1000_MC copiedState = state._copy();
                    copiedState.final_evt();
                    copiedState.stateAccessedVia = "final_evt";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const sort_m2_data1000_MC& state) {
            bool _check_inv_1 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                    auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                    if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                        _check_inv_1 = state._check_inv_1();
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    } else {
                        _check_inv_1 = _obj__check_inv_1_ptr->second;
                    }
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            bool _check_inv_2 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                    auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                    if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                        _check_inv_2 = state._check_inv_2();
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    } else {
                        _check_inv_2 = _obj__check_inv_2_ptr->second;
                    }
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
              return true;
            }
            bool _check_inv_3 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_3_lock(_ProjectionRead__check_inv_3_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                    auto _obj__check_inv_3_ptr = _InvCache__check_inv_3.find(read__check_inv_3_state);
                    if(_obj__check_inv_3_ptr == _InvCache__check_inv_3.end()) {
                        _check_inv_3 = state._check_inv_3();
                        _InvCache__check_inv_3.insert({read__check_inv_3_state, _check_inv_3});
                    } else {
                        _check_inv_3 = _obj__check_inv_3_ptr->second;
                    }
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
              return true;
            }
            bool _check_inv_4 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_4_lock(_ProjectionRead__check_inv_4_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                    auto _obj__check_inv_4_ptr = _InvCache__check_inv_4.find(read__check_inv_4_state);
                    if(_obj__check_inv_4_ptr == _InvCache__check_inv_4.end()) {
                        _check_inv_4 = state._check_inv_4();
                        _InvCache__check_inv_4.insert({read__check_inv_4_state, _check_inv_4});
                    } else {
                        _check_inv_4 = _obj__check_inv_4_ptr->second;
                    }
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
              return true;
            }
            bool _check_inv_5 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_5_lock(_ProjectionRead__check_inv_5_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                    auto _obj__check_inv_5_ptr = _InvCache__check_inv_5.find(read__check_inv_5_state);
                    if(_obj__check_inv_5_ptr == _InvCache__check_inv_5.end()) {
                        _check_inv_5 = state._check_inv_5();
                        _InvCache__check_inv_5.insert({read__check_inv_5_state, _check_inv_5});
                    } else {
                        _check_inv_5 = _obj__check_inv_5_ptr->second;
                    }
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
              return true;
            }
            bool _check_inv_6 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_6_lock(_ProjectionRead__check_inv_6_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                    auto _obj__check_inv_6_ptr = _InvCache__check_inv_6.find(read__check_inv_6_state);
                    if(_obj__check_inv_6_ptr == _InvCache__check_inv_6.end()) {
                        _check_inv_6 = state._check_inv_6();
                        _InvCache__check_inv_6.insert({read__check_inv_6_state, _check_inv_6});
                    } else {
                        _check_inv_6 = _obj__check_inv_6_ptr->second;
                    }
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
              return true;
            }
            bool _check_inv_7 = true;
            if(isCaching) {
                {
                    std::unique_lock<std::mutex> _ProjectionRead__check_inv_7_lock(_ProjectionRead__check_inv_7_mutex);
                    sort_m2_data1000_MC::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                    auto _obj__check_inv_7_ptr = _InvCache__check_inv_7.find(read__check_inv_7_state);
                    if(_obj__check_inv_7_ptr == _InvCache__check_inv_7.end()) {
                        _check_inv_7 = state._check_inv_7();
                        _InvCache__check_inv_7.insert({read__check_inv_7_state, _check_inv_7});
                    } else {
                        _check_inv_7 = _obj__check_inv_7_ptr->second;
                    }
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
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

    sort_m2_data1000_MC::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = sort_m2_data1000_MC::Type::DFS;
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