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
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef Train1_Lukas_POR_v3_H
#define Train1_Lukas_POR_v3_H

using namespace std;

class Train1_Lukas_POR_v3 {

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
                    I
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
                    }
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
                    R8
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
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        struct Hash {
            public:
                size_t operator()(const Train1_Lukas_POR_v3& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const Train1_Lukas_POR_v3& obj1, const Train1_Lukas_POR_v3& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

    private:

        BRelation<ROUTES, BLOCKS > fst;
        BRelation<ROUTES, BLOCKS > lst;
        BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > > nxt;
        BRelation<BLOCKS, ROUTES > rtbl;


        #define _BLOCKS (BSet<BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I))))
        #define _ROUTES (BSet<ROUTES >((ROUTES(ROUTES::R1)), (ROUTES(ROUTES::R2)), (ROUTES(ROUTES::R3)), (ROUTES(ROUTES::R4)), (ROUTES(ROUTES::R5)), (ROUTES(ROUTES::R6)), (ROUTES(ROUTES::R7)), (ROUTES(ROUTES::R8))))

        BSet<BLOCKS > LBT;
        BRelation<BLOCKS, BLOCKS > TRK;
        BSet<ROUTES > frm;
        BSet<BLOCKS > OCC;
        BSet<BLOCKS > resbl;
        BSet<ROUTES > resrt;
        BRelation<BLOCKS, ROUTES > rsrtbl;


    public:

        Train1_Lukas_POR_v3() {
            fst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::A)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::A)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::H)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::I)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::F)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::F)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::F))))));
            lst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::F)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::F)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::F)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::A)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::A)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::H)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::I))))));
            nxt = (BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >((BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R1)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R2)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R3)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::G)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R4)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::G)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R5)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R6)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R7)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::G)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::H)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R8)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::G)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::I))))))))));
            rtbl = (BRelation<BLOCKS, ROUTES >((BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::A)), (ROUTES(ROUTES::R1)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::A)), (ROUTES(ROUTES::R2)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::A)), (ROUTES(ROUTES::R5)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::A)), (ROUTES(ROUTES::R6)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::B)), (ROUTES(ROUTES::R1)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::B)), (ROUTES(ROUTES::R2)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::B)), (ROUTES(ROUTES::R5)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::B)), (ROUTES(ROUTES::R6)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::C)), (ROUTES(ROUTES::R1)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::C)), (ROUTES(ROUTES::R5)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::D)), (ROUTES(ROUTES::R2)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::D)), (ROUTES(ROUTES::R6)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R2)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R3)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R4)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R6)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R7)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::E)), (ROUTES(ROUTES::R8)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R2)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R3)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R4)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R6)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R7)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::F)), (ROUTES(ROUTES::R8)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::G)), (ROUTES(ROUTES::R3)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::G)), (ROUTES(ROUTES::R4)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::G)), (ROUTES(ROUTES::R4)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::G)), (ROUTES(ROUTES::R7)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::G)), (ROUTES(ROUTES::R8)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::H)), (ROUTES(ROUTES::R3)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::H)), (ROUTES(ROUTES::R7)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::I)), (ROUTES(ROUTES::R4)))), (BTuple<BLOCKS, ROUTES >((BLOCKS(BLOCKS::I)), (ROUTES(ROUTES::R8))))));
            resrt = (BSet<ROUTES >());
            resbl = (BSet<BLOCKS >());
            rsrtbl = (BRelation<BLOCKS, ROUTES >());
            OCC = (BSet<BLOCKS >());
            TRK = (BRelation<BLOCKS, BLOCKS >());
            frm = (BSet<ROUTES >());
            LBT = (BSet<BLOCKS >());
        }

        Train1_Lukas_POR_v3(const BRelation<ROUTES, BLOCKS >& fst, const BRelation<ROUTES, BLOCKS >& lst, const BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >& nxt, const BRelation<BLOCKS, ROUTES >& rtbl, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<ROUTES >& frm, const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& resbl, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
            this->fst = fst;
            this->lst = lst;
            this->nxt = nxt;
            this->rtbl = rtbl;
            this->LBT = LBT;
            this->TRK = TRK;
            this->frm = frm;
            this->OCC = OCC;
            this->resbl = resbl;
            this->resrt = resrt;
            this->rsrtbl = rsrtbl;
        }

        void route_reservation(const ROUTES& r) {
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<ROUTES > _ld_resrt = resrt;
            BSet<BLOCKS > _ld_resbl = resbl;
            resrt = _ld_resrt._union((BSet<ROUTES >(r)));
            rsrtbl = _ld_rsrtbl._union(rtbl.rangeRestriction((BSet<ROUTES >(r))));
            resbl = _ld_resbl._union(rtbl.inverse().relationImage((BSet<ROUTES >(r))));

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
            BSet<ROUTES> _ic_set_0 = BSet<ROUTES>();
            for(ROUTES _ic_r_1 : _ROUTES.difference(resrt)) {
                if(((BBoolean(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).intersect(resbl).equal((BSet<BLOCKS >())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_0 = _ic_set_0._union(BSet<ROUTES>(_ic_r_1));
                }

            }
            return _ic_set_0;
        }

        BSet<ROUTES> _tr_route_freeing() const {
            BSet<ROUTES> _ic_set_1 = BSet<ROUTES>();
            for(ROUTES _ic_r_1 : resrt.difference(rsrtbl.range())) {
                _ic_set_1 = _ic_set_1._union(BSet<ROUTES>(_ic_r_1));

            }
            return _ic_set_1;
        }

        BSet<ROUTES> _tr_FRONT_MOVE_1() const {
            BSet<ROUTES> _ic_set_2 = BSet<ROUTES>();
            for(ROUTES _ic_r_1 : frm) {
                if(((BBoolean((BBoolean(resbl.difference(OCC).elementOf(fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(rsrtbl.functionCall(fst.functionCall(_ic_r_1))).booleanValue())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_2 = _ic_set_2._union(BSet<ROUTES>(_ic_r_1));
                }

            }
            return _ic_set_2;
        }

        BSet<BLOCKS> _tr_FRONT_MOVE_2() const {
            BSet<BLOCKS> _ic_set_3 = BSet<BLOCKS>();
            for(BLOCKS _ic_b_1 : OCC.intersect(TRK.domain())) {
                if(((BBoolean(OCC.notElementOf(TRK.functionCall(_ic_b_1)).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_3 = _ic_set_3._union(BSet<BLOCKS>(_ic_b_1));
                }

            }
            return _ic_set_3;
        }

        BSet<BLOCKS> _tr_BACK_MOVE_1() const {
            BSet<BLOCKS> _ic_set_4 = BSet<BLOCKS>();
            for(BLOCKS _ic_b_1 : LBT.difference(TRK.domain())) {
                if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                    _ic_set_4 = _ic_set_4._union(BSet<BLOCKS>(_ic_b_1));
                }

            }
            return _ic_set_4;
        }

        BSet<BLOCKS> _tr_BACK_MOVE_2() const {
            BSet<BLOCKS> _ic_set_5 = BSet<BLOCKS>();
            for(BLOCKS _ic_b_1 : LBT.intersect(TRK.domain())) {
                if(((BBoolean(OCC.elementOf(TRK.functionCall(_ic_b_1)).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_5 = _ic_set_5._union(BSet<BLOCKS>(_ic_b_1));
                }

            }
            return _ic_set_5;
        }

        BSet<ROUTES> _tr_point_positionning() const {
            BSet<ROUTES> _ic_set_6 = BSet<ROUTES>();
            for(ROUTES _ic_r_1 : resrt.difference(frm)) {
                if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                    _ic_set_6 = _ic_set_6._union(BSet<ROUTES>(_ic_r_1));
                }

            }
            return _ic_set_6;
        }

        BSet<ROUTES> _tr_route_formation() const {
            BSet<ROUTES> _ic_set_7 = BSet<ROUTES>();
            for(ROUTES _ic_r_1 : resrt.difference(frm)) {
                if(((BBoolean(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))))).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                    _ic_set_7 = _ic_set_7._union(BSet<ROUTES>(_ic_r_1));
                }

            }
            return _ic_set_7;
        }

        bool _check_inv_1() const {
            return (((TRK.checkDomain(_BLOCKS))._and((TRK.checkRange(_BLOCKS)))._and((TRK.isFunction()))._and((TRK.isPartial(_BLOCKS)))._and((TRK.isInjection())))).booleanValue();
        }

        bool _check_inv_2() const {
            BBoolean _ic_boolean_8 = BBoolean(true);
            for(ROUTES _ic_r_1 : resrt.difference(frm)) {
                for(BSet<ROUTES > _ic_a_1 : {(BSet<ROUTES >(_ic_r_1))}) {
                    if(!(rtbl.rangeRestriction(_ic_a_1).equal(rsrtbl.rangeRestriction(_ic_a_1))).booleanValue()) {
                        _ic_boolean_8 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_8).booleanValue();
        }

        bool _check_inv_3() const {
            BBoolean _ic_boolean_10 = BBoolean(true);
            for(BLOCKS _ic_x_1 : TRK.domain()) {
                for(BLOCKS _ic_y_1 : TRK.relationImage((BSet<BLOCKS >(_ic_x_1)))) {
                    BBoolean _ic_boolean_9 = BBoolean(false);
                    for(ROUTES _ic_r_1 : _ROUTES) {
                        if((nxt.functionCall(_ic_r_1).elementOf((BTuple<BLOCKS, BLOCKS >(_ic_x_1, _ic_y_1)))).booleanValue()) {
                            _ic_boolean_9 = BBoolean(true);
                            break;
                        }

                    }

                    if(!(_ic_boolean_9).booleanValue()) {
                        _ic_boolean_10 = BBoolean(false);
                        break;
                    }

                }
            }

            return (_ic_boolean_10).booleanValue();
        }

        bool _check_inv_4() const {
            BBoolean _ic_boolean_11 = BBoolean(true);
            for(ROUTES _ic_r_1 : frm) {
                for(BSet<BLOCKS > _ic_a_1 : {rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))}) {
                    if(!(nxt.functionCall(_ic_r_1).domainRestriction(_ic_a_1).equal(TRK.domainRestriction(_ic_a_1))).booleanValue()) {
                        _ic_boolean_11 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_11).booleanValue();
        }

        bool _check_inv_5() const {
            return (LBT.subset(OCC)).booleanValue();
        }

        bool _check_inv_6() const {
            BBoolean _ic_boolean_12 = BBoolean(true);
            for(BLOCKS _ic_a_1 : rsrtbl.domain()) {
                for(BLOCKS _ic_b_1 : LBT) {
                    for(ROUTES _ic_c_1 : {rsrtbl.functionCall(_ic_b_1)}) {
                        for(BRelation<BLOCKS, BLOCKS > _ic_d_1 : {nxt.functionCall(_ic_c_1)}) {
                            if(!((BBoolean(!(BBoolean(_ic_d_1.range().elementOf(_ic_b_1).booleanValue() && _ic_a_1.equal(_ic_d_1.inverse().functionCall(_ic_b_1)).booleanValue())).booleanValue() || rsrtbl.functionCall(_ic_a_1).unequal(_ic_c_1).booleanValue()))).booleanValue()) {
                                _ic_boolean_12 = BBoolean(false);
                                break;
                            }

                        }

                    }

                }
            }

            return (_ic_boolean_12).booleanValue();
        }

        bool _check_inv_7() const {
            return (((rsrtbl.checkDomain(resbl))._and((rsrtbl.checkRange(resrt)))._and((rsrtbl.isFunction()))._and((rsrtbl.isTotal(resbl))))).booleanValue();
        }

        bool _check_inv_8() const {
            return (rsrtbl.subset(rtbl)).booleanValue();
        }

        bool _check_inv_9() const {
            return (OCC.subset(resbl)).booleanValue();
        }

        bool _check_inv_10() const {
            BBoolean _ic_boolean_13 = BBoolean(true);
            for(ROUTES _ic_r_1 : _ROUTES) {
                for(BRelation<BLOCKS, BLOCKS > _ic_a_1 : {nxt.functionCall(_ic_r_1)}) {
                    for(BSet<BLOCKS > _ic_b_1 : {rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))}) {
                        for(BSet<BLOCKS > _ic_c_1 : {_ic_b_1.difference(OCC)}) {
                            if(!((BBoolean((BBoolean(_ic_a_1.relationImage(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference(_ic_b_1)).intersect(_ic_c_1).equal((BSet<BLOCKS >())).booleanValue() && _ic_a_1.relationImage(_ic_b_1).subset(_ic_b_1).booleanValue())).booleanValue() && _ic_a_1.relationImage(_ic_c_1).subset(_ic_c_1).booleanValue()))).booleanValue()) {
                                _ic_boolean_13 = BBoolean(false);
                                break;
                            }

                        }

                    }

                }

            }

            return (_ic_boolean_13).booleanValue();
        }

        bool _check_inv_11() const {
            return (frm.subset(resrt)).booleanValue();
        }

        bool _check_inv_12() const {
            return (rsrtbl.relationImage(OCC).subset(frm)).booleanValue();
        }

        Train1_Lukas_POR_v3 _copy() const {
            return Train1_Lukas_POR_v3(fst, lst, nxt, rtbl, LBT, TRK, frm, OCC, resbl, resrt, rsrtbl);
        }

        friend bool operator ==(const Train1_Lukas_POR_v3& o1, const Train1_Lukas_POR_v3& o2) {
            return o1._get_LBT() == o2._get_LBT() && o1._get_TRK() == o2._get_TRK() && o1._get_frm() == o2._get_frm() && o1._get_OCC() == o2._get_OCC() && o1._get_resbl() == o2._get_resbl() && o1._get_resrt() == o2._get_resrt() && o1._get_rsrtbl() == o2._get_rsrtbl();
        }

        friend bool operator !=(const Train1_Lukas_POR_v3& o1, const Train1_Lukas_POR_v3& o2) {
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

        friend std::ostream& operator<<(std::ostream &strm, const Train1_Lukas_POR_v3 &machine) {
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


static std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> generateNextStates(std::mutex& guardMutex, const Train1_Lukas_POR_v3& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& dependentGuard, std::unordered_map<Train1_Lukas_POR_v3, immer::map<string, boost::any>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& guardCache, std::unordered_map<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& parents, std::unordered_map<Train1_Lukas_POR_v3, string, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& stateAccessedVia, std::atomic<int>& transitions) {
    std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> result = std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>();
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
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_route_reservation"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_route_reservation") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_1 = state._tr_route_reservation();
        } else {
            _trid_1 = boost::any_cast<BSet<Train1_Lukas_POR_v3::ROUTES>>(cachedValue);
        }
        newCache = newCache.set("_tr_route_reservation", _trid_1);
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_1) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_reservation(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["route_reservation"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["route_reservation"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_reservation"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_route_freeing"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_route_freeing") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_2 = state._tr_route_freeing();
        } else {
            _trid_2 = boost::any_cast<BSet<Train1_Lukas_POR_v3::ROUTES>>(cachedValue);
        }
        newCache = newCache.set("_tr_route_freeing", _trid_2);
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_2) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_freeing(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["route_freeing"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["route_freeing"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_freeing"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_FRONT_MOVE_1"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_FRONT_MOVE_1") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_3 = state._tr_FRONT_MOVE_1();
        } else {
            _trid_3 = boost::any_cast<BSet<Train1_Lukas_POR_v3::ROUTES>>(cachedValue);
        }
        newCache = newCache.set("_tr_FRONT_MOVE_1", _trid_3);
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_3) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.FRONT_MOVE_1(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["FRONT_MOVE_1"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["FRONT_MOVE_1"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "FRONT_MOVE_1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_FRONT_MOVE_2"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_FRONT_MOVE_2") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_4 = state._tr_FRONT_MOVE_2();
        } else {
            _trid_4 = boost::any_cast<BSet<Train1_Lukas_POR_v3::BLOCKS>>(cachedValue);
        }
        newCache = newCache.set("_tr_FRONT_MOVE_2", _trid_4);
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_4) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.FRONT_MOVE_2(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["FRONT_MOVE_2"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["FRONT_MOVE_2"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "FRONT_MOVE_2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_5;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_BACK_MOVE_1"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_BACK_MOVE_1") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_5 = state._tr_BACK_MOVE_1();
        } else {
            _trid_5 = boost::any_cast<BSet<Train1_Lukas_POR_v3::BLOCKS>>(cachedValue);
        }
        newCache = newCache.set("_tr_BACK_MOVE_1", _trid_5);
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_5) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.BACK_MOVE_1(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["BACK_MOVE_1"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["BACK_MOVE_1"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "BACK_MOVE_1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_6;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_BACK_MOVE_2"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_BACK_MOVE_2") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_6 = state._tr_BACK_MOVE_2();
        } else {
            _trid_6 = boost::any_cast<BSet<Train1_Lukas_POR_v3::BLOCKS>>(cachedValue);
        }
        newCache = newCache.set("_tr_BACK_MOVE_2", _trid_6);
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_6) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.BACK_MOVE_2(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["BACK_MOVE_2"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["BACK_MOVE_2"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "BACK_MOVE_2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_7;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_point_positionning"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_point_positionning") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_7 = state._tr_point_positionning();
        } else {
            _trid_7 = boost::any_cast<BSet<Train1_Lukas_POR_v3::ROUTES>>(cachedValue);
        }
        newCache = newCache.set("_tr_point_positionning", _trid_7);
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_7) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.point_positionning(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["point_positionning"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["point_positionning"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "point_positionning"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_8;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_route_formation"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_route_formation") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_8 = state._tr_route_formation();
        } else {
            _trid_8 = boost::any_cast<BSet<Train1_Lukas_POR_v3::ROUTES>>(cachedValue);
        }
        newCache = newCache.set("_tr_route_formation", _trid_8);
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_8) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_formation(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["route_formation"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["route_formation"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_formation"});
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
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_1 = state._tr_route_reservation();
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_1) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_reservation(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_reservation"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_2 = state._tr_route_freeing();
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_2) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_freeing(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_freeing"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_3 = state._tr_FRONT_MOVE_1();
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_3) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.FRONT_MOVE_1(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "FRONT_MOVE_1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2();
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_4) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.FRONT_MOVE_2(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "FRONT_MOVE_2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_5 = state._tr_BACK_MOVE_1();
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_5) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.BACK_MOVE_1(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "BACK_MOVE_1"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::BLOCKS> _trid_6 = state._tr_BACK_MOVE_2();
        for(const Train1_Lukas_POR_v3::BLOCKS& param : _trid_6) {
            Train1_Lukas_POR_v3::BLOCKS _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.BACK_MOVE_2(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "BACK_MOVE_2"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_7 = state._tr_point_positionning();
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_7) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.point_positionning(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "point_positionning"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<Train1_Lukas_POR_v3::ROUTES> _trid_8 = state._tr_route_formation();
        for(const Train1_Lukas_POR_v3::ROUTES& param : _trid_8) {
            Train1_Lukas_POR_v3::ROUTES _tmp_1 = param;

            Train1_Lukas_POR_v3 copiedState = state._copy();
            copiedState.route_formation(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "route_formation"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated, Train1_Lukas_POR_v3& counterExampleState, std::unordered_map<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& parents, std::unordered_map<Train1_Lukas_POR_v3, string, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& stateAccessedVia) {
    if(deadlockDetected || invariantViolated) {
        if(deadlockDetected) {
            cout << "DEADLOCK DETECTED" << "\n";
        }
        if(invariantViolated) {
            cout << "INVARIANT VIOLATED" << "\n";
        }
        cout << "COUNTER EXAMPLE TRACE: " << "\n";

        Train1_Lukas_POR_v3 currentState = counterExampleState;
        std::string trace = "";
        while(parents.find(currentState) != parents.end()) {
            std::stringstream stringStream;
            stringStream << currentState;
            trace.insert(0, stringStream.str());
            trace.insert(0, "\n");
            trace.insert(0, stateAccessedVia[currentState]);
            trace.insert(0, "\n\n");
            currentState = parents[currentState];
        }
        cout << trace;
    }

    if(!deadlockDetected && !invariantViolated) {
        cout << "MODEL CHECKING SUCCESSFUL" << "\n";
    }
    cout << "Number of States: " << states << "\n";
    cout << "Number of Transitions: " << transitions << "\n";
}

static bool checkInvariants(std::mutex& guardMutex, const Train1_Lukas_POR_v3& state, bool isCaching, std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>& dependentInvariant) {
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
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12());
}

static Train1_Lukas_POR_v3 next(std::list<Train1_Lukas_POR_v3>& collection, std::mutex& mutex, Train1_Lukas_POR_v3::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case Train1_Lukas_POR_v3::BFS: {
            Train1_Lukas_POR_v3 state = collection.front();
            collection.pop_front();
            return state;
        }
        case Train1_Lukas_POR_v3::DFS: {
            Train1_Lukas_POR_v3 state = collection.back();
            collection.pop_back();
            return state;
        }
        case Train1_Lukas_POR_v3::MIXED: {
            if(collection.size() % 2 == 0) {
                Train1_Lukas_POR_v3 state = collection.front();
                collection.pop_front();
                return state;
            } else {
                Train1_Lukas_POR_v3 state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(Train1_Lukas_POR_v3::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    Train1_Lukas_POR_v3 machine = Train1_Lukas_POR_v3();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> states = std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Train1_Lukas_POR_v3> collection = std::list<Train1_Lukas_POR_v3>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> dependentInvariant;
    std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> dependentGuard;
    std::unordered_map<Train1_Lukas_POR_v3, immer::map<string, boost::any>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> guardCache;
    std::unordered_map<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> parents;
    std::unordered_map<Train1_Lukas_POR_v3, string, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"point_positionning", {"_check_inv_3", "_check_inv_1", "_check_inv_4"}});
        invariantDependency.insert({"route_reservation", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"}});
        invariantDependency.insert({"FRONT_MOVE_1", {"_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"BACK_MOVE_1", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"FRONT_MOVE_2", {"_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"route_formation", {"_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
        invariantDependency.insert({"route_freeing", {"_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
        invariantDependency.insert({"BACK_MOVE_2", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        guardDependency.insert({"point_positionning", {"_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"route_reservation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"FRONT_MOVE_1", {"_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"BACK_MOVE_1", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"FRONT_MOVE_2", {"_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"route_formation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"}});
        guardDependency.insert({"route_freeing", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"BACK_MOVE_2", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    Train1_Lukas_POR_v3 counterExampleState;

    while(!collection.empty() && !stopThreads) {
        Train1_Lukas_POR_v3 state = next(collection, mutex, type);

        std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);
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

        if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
            invariantViolated = true;
            stopThreads = true;
            counterExampleState = state;
        }

        if(nextStates.empty()) {
            deadlockDetected = true;
            stopThreads = true;
            counterExampleState = state;
        }

    }
    printResult(numberStates, transitions, deadlockDetected, invariantViolated, counterExampleState, parents, stateAccessedVia);
}

static void modelCheckMultiThreaded(Train1_Lukas_POR_v3::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    Train1_Lukas_POR_v3 machine = Train1_Lukas_POR_v3();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> states = std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<Train1_Lukas_POR_v3> collection = std::list<Train1_Lukas_POR_v3>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> dependentInvariant;
    std::unordered_map<Train1_Lukas_POR_v3, std::unordered_set<string>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> dependentGuard;
    std::unordered_map<Train1_Lukas_POR_v3, immer::map<string, boost::any>, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> guardCache;
    std::unordered_map<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> parents;
    std::unordered_map<Train1_Lukas_POR_v3, string, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"point_positionning", {"_check_inv_3", "_check_inv_1", "_check_inv_4"}});
        invariantDependency.insert({"route_reservation", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"}});
        invariantDependency.insert({"FRONT_MOVE_1", {"_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"BACK_MOVE_1", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"FRONT_MOVE_2", {"_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"route_formation", {"_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
        invariantDependency.insert({"route_freeing", {"_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
        invariantDependency.insert({"BACK_MOVE_2", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        guardDependency.insert({"point_positionning", {"_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"route_reservation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"FRONT_MOVE_1", {"_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"BACK_MOVE_1", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"FRONT_MOVE_2", {"_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"route_formation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"}});
        guardDependency.insert({"route_freeing", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        guardDependency.insert({"BACK_MOVE_2", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    Train1_Lukas_POR_v3 counterExampleState;

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        Train1_Lukas_POR_v3 state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<Train1_Lukas_POR_v3, Train1_Lukas_POR_v3::Hash, Train1_Lukas_POR_v3::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);


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
                counterExampleState = state;
            }

            if(!checkInvariants(guardMutex, state, isCaching, dependentInvariant)) {
                invariantViolated = true;
                stopThreads = true;
                counterExampleState = state;
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
    printResult(numberStates, transitions, deadlockDetected, invariantViolated, counterExampleState, parents, stateAccessedVia);
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "Number of arguments errorneous\n";
        return -1;
    }
    string strategy = argv[1];
    string numberThreads = argv[2];
    string caching = argv[3];

    Train1_Lukas_POR_v3::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = Train1_Lukas_POR_v3::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = Train1_Lukas_POR_v3::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = Train1_Lukas_POR_v3::Type::DFS;
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

    if(threads == 1) {
        modelCheckSingleThreaded(type, isCaching);
    } else {
        modelCheckMultiThreaded(type, threads, isCaching);
    }
    return 0;
}



#endif