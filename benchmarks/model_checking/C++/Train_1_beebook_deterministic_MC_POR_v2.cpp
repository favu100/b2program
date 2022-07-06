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
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef Train_1_beebook_deterministic_MC_POR_v2_H
#define Train_1_beebook_deterministic_MC_POR_v2_H

using namespace std;

class Train_1_beebook_deterministic_MC_POR_v2 {

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
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };


        struct Hash {
            public:
                size_t operator()(const Train_1_beebook_deterministic_MC_POR_v2& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const Train_1_beebook_deterministic_MC_POR_v2& obj1, const Train_1_beebook_deterministic_MC_POR_v2& obj2) const {
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


        #define _BLOCKS (BSet<BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::N))))
        #define _ROUTES (BSet<ROUTES >((ROUTES(ROUTES::R1)), (ROUTES(ROUTES::R2)), (ROUTES(ROUTES::R3)), (ROUTES(ROUTES::R4)), (ROUTES(ROUTES::R5)), (ROUTES(ROUTES::R6)), (ROUTES(ROUTES::R7)), (ROUTES(ROUTES::R8)), (ROUTES(ROUTES::R9)), (ROUTES(ROUTES::R10))))

        BSet<BLOCKS > LBT;
        BRelation<BLOCKS, BLOCKS > TRK;
        BSet<ROUTES > frm;
        BSet<BLOCKS > OCC;
        BSet<BLOCKS > resbl;
        BSet<ROUTES > resrt;
        BRelation<BLOCKS, ROUTES > rsrtbl;

        mutable boost::optional<BSet<ROUTES>> _tr_cache_route_reservation;
        mutable boost::optional<BSet<ROUTES>> _tr_cache_route_freeing;
        mutable boost::optional<BSet<ROUTES>> _tr_cache_FRONT_MOVE_1;
        mutable boost::optional<BSet<BLOCKS>> _tr_cache_FRONT_MOVE_2;
        mutable boost::optional<BSet<BLOCKS>> _tr_cache_BACK_MOVE_1;
        mutable boost::optional<BSet<BLOCKS>> _tr_cache_BACK_MOVE_2;
        mutable boost::optional<BSet<ROUTES>> _tr_cache_point_positionning;
        mutable boost::optional<BSet<ROUTES>> _tr_cache_route_formation;

    public:

        std::string stateAccessedVia;

        Train_1_beebook_deterministic_MC_POR_v2() {
            nxt = (BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >((BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R1)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R2)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R3)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R4)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R5)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R6)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R7)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R8)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R9)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R10)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M))))))))));
            fst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::N))))));
            lst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::M))))));
            BRelation<BLOCKS, ROUTES > _ic_set_0 = BRelation<BLOCKS, ROUTES >();
            for(const BLOCKS& _ic_b_1 : _BLOCKS) {
                for(const ROUTES& _ic_r_1 : _ROUTES) {
                    if(((BBoolean(nxt.domain().elementOf(_ic_r_1).booleanValue() && (BBoolean(nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() || nxt.functionCall(_ic_r_1).range().elementOf(_ic_b_1).booleanValue())).booleanValue()))).booleanValue()) {
                        _ic_set_0 = _ic_set_0._union(BRelation<BLOCKS, ROUTES >((BTuple<BLOCKS, ROUTES >(_ic_b_1, _ic_r_1))));
                    }

                }
            }

            rtbl = _ic_set_0;
            resrt = (BSet<ROUTES >());
            resbl = (BSet<BLOCKS >());
            rsrtbl = (BRelation<BLOCKS, ROUTES >());
            OCC = (BSet<BLOCKS >());
            TRK = (BRelation<BLOCKS, BLOCKS >());
            frm = (BSet<ROUTES >());
            LBT = (BSet<BLOCKS >());
        }

        Train_1_beebook_deterministic_MC_POR_v2(const BRelation<ROUTES, BLOCKS >& fst, const BRelation<ROUTES, BLOCKS >& lst, const BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >& nxt, const BRelation<BLOCKS, ROUTES >& rtbl, const BSet<BLOCKS >& LBT, const BRelation<BLOCKS, BLOCKS >& TRK, const BSet<ROUTES >& frm, const BSet<BLOCKS >& OCC, const BSet<BLOCKS >& resbl, const BSet<ROUTES >& resrt, const BRelation<BLOCKS, ROUTES >& rsrtbl) {
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


        BSet<ROUTES> _tr_route_reservation(bool isCaching) const {
            if (this->_tr_cache_route_reservation == boost::none){
                BSet<ROUTES> _ic_set_1 = BSet<ROUTES>();
                for(const ROUTES& _ic_r_1 : _ROUTES.difference(resrt)) {
                    if(((BBoolean(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).intersect(resbl).equal((BSet<BLOCKS >())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                        _ic_set_1 = _ic_set_1._union(BSet<ROUTES>(_ic_r_1));
                    }

                }
                if (isCaching) this->_tr_cache_route_reservation = _ic_set_1;
                else return _ic_set_1;
            }
            return this->_tr_cache_route_reservation.get();
        }

        BSet<ROUTES> _tr_route_freeing(bool isCaching) const {
            if (this->_tr_cache_route_freeing == boost::none){
                BSet<ROUTES> _ic_set_2 = BSet<ROUTES>();
                for(const ROUTES& _ic_r_1 : resrt.difference(rsrtbl.range())) {
                    _ic_set_2 = _ic_set_2._union(BSet<ROUTES>(_ic_r_1));

                }
                if (isCaching) this->_tr_cache_route_freeing = _ic_set_2;
                else return _ic_set_2;
            }
            return this->_tr_cache_route_freeing.get();
        }

        BSet<ROUTES> _tr_FRONT_MOVE_1(bool isCaching) const {
            if (this->_tr_cache_FRONT_MOVE_1 == boost::none){
                BSet<ROUTES> _ic_set_3 = BSet<ROUTES>();
                for(const ROUTES& _ic_r_1 : frm) {
                    if(((BBoolean((BBoolean(resbl.difference(OCC).elementOf(fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(rsrtbl.functionCall(fst.functionCall(_ic_r_1))).booleanValue())).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                        _ic_set_3 = _ic_set_3._union(BSet<ROUTES>(_ic_r_1));
                    }

                }
                if (isCaching) this->_tr_cache_FRONT_MOVE_1 = _ic_set_3;
                else return _ic_set_3;
            }
            return this->_tr_cache_FRONT_MOVE_1.get();
        }

        BSet<BLOCKS> _tr_FRONT_MOVE_2(bool isCaching) const {
            if (this->_tr_cache_FRONT_MOVE_2 == boost::none){
                BSet<BLOCKS> _ic_set_4 = BSet<BLOCKS>();
                for(const BLOCKS& _ic_b_1 : OCC.intersect(TRK.domain())) {
                    if((OCC.notElementOf(TRK.functionCall(_ic_b_1))).booleanValue()) {
                        _ic_set_4 = _ic_set_4._union(BSet<BLOCKS>(_ic_b_1));
                    }

                }
                if (isCaching) this->_tr_cache_FRONT_MOVE_2 = _ic_set_4;
                else return _ic_set_4;
            }
            return this->_tr_cache_FRONT_MOVE_2.get();
        }

        BSet<BLOCKS> _tr_BACK_MOVE_1(bool isCaching) const {
            if (this->_tr_cache_BACK_MOVE_1 == boost::none){
                BSet<BLOCKS> _ic_set_5 = BSet<BLOCKS>();
                for(const BLOCKS& _ic_b_1 : LBT.difference(TRK.domain())) {
                    if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                        _ic_set_5 = _ic_set_5._union(BSet<BLOCKS>(_ic_b_1));
                    }

                }
                if (isCaching) this->_tr_cache_BACK_MOVE_1 = _ic_set_5;
                else return _ic_set_5;
            }
            return this->_tr_cache_BACK_MOVE_1.get();
        }

        BSet<BLOCKS> _tr_BACK_MOVE_2(bool isCaching) const {
            if (this->_tr_cache_BACK_MOVE_2 == boost::none){
                BSet<BLOCKS> _ic_set_6 = BSet<BLOCKS>();
                for(const BLOCKS& _ic_b_1 : LBT.intersect(TRK.domain())) {
                    if(((BBoolean(OCC.elementOf(TRK.functionCall(_ic_b_1)).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                        _ic_set_6 = _ic_set_6._union(BSet<BLOCKS>(_ic_b_1));
                    }

                }
                if (isCaching) this->_tr_cache_BACK_MOVE_2 = _ic_set_6;
                else return _ic_set_6;
            }
            return this->_tr_cache_BACK_MOVE_2.get();
        }

        BSet<ROUTES> _tr_point_positionning(bool isCaching) const {
            if (this->_tr_cache_point_positionning == boost::none){
                BSet<ROUTES> _ic_set_7 = BSet<ROUTES>();
                for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                    if(((BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                        _ic_set_7 = _ic_set_7._union(BSet<ROUTES>(_ic_r_1));
                    }

                }
                if (isCaching) this->_tr_cache_point_positionning = _ic_set_7;
                else return _ic_set_7;
            }
            return this->_tr_cache_point_positionning.get();
        }

        BSet<ROUTES> _tr_route_formation(bool isCaching) const {
            if (this->_tr_cache_route_formation == boost::none){
                BSet<ROUTES> _ic_set_8 = BSet<ROUTES>();
                for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                    if(((BBoolean(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))))).booleanValue() && (BSet<ROUTES >()).equal(resrt.difference(rsrtbl.range())).booleanValue()))).booleanValue()) {
                        _ic_set_8 = _ic_set_8._union(BSet<ROUTES>(_ic_r_1));
                    }

                }
                if (isCaching) this->_tr_cache_route_formation = _ic_set_8;
                else return _ic_set_8;
            }
            return this->_tr_cache_route_formation.get();
        }

        bool _check_inv_1() const {
            return (((TRK.checkDomain(_BLOCKS))._and((TRK.checkRange(_BLOCKS)))._and((TRK.isFunction()))._and((TRK.isPartial(_BLOCKS)))._and((TRK.isInjection())))).booleanValue();
        }

        bool _check_inv_2() const {
            BBoolean _ic_boolean_9 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : resrt.difference(frm)) {
                for(const BSet<ROUTES >& _ic_a_1 : {(BSet<ROUTES >(_ic_r_1))}) {
                    if(!(rtbl.rangeRestriction(_ic_a_1).equal(rsrtbl.rangeRestriction(_ic_a_1))).booleanValue()) {
                        _ic_boolean_9 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_9).booleanValue();
        }

        bool _check_inv_3() const {
            BBoolean _ic_boolean_11 = BBoolean(true);
            for(const BLOCKS& _ic_x_1 : TRK.domain()) {
                for(const BLOCKS& _ic_y_1 : TRK.relationImage((BSet<BLOCKS >(_ic_x_1)))) {
                    BBoolean _ic_boolean_10 = BBoolean(false);
                    for(const ROUTES& _ic_r_1 : _ROUTES) {
                        if((nxt.functionCall(_ic_r_1).elementOf((BTuple<BLOCKS, BLOCKS >(_ic_x_1, _ic_y_1)))).booleanValue()) {
                            _ic_boolean_10 = BBoolean(true);
                            break;
                        }

                    }

                    if(!(_ic_boolean_10).booleanValue()) {
                        _ic_boolean_11 = BBoolean(false);
                        break;
                    }

                }
            }

            return (_ic_boolean_11).booleanValue();
        }

        bool _check_inv_4() const {
            BBoolean _ic_boolean_12 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : frm) {
                for(const BSet<BLOCKS >& _ic_a_1 : {rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))}) {
                    if(!(nxt.functionCall(_ic_r_1).domainRestriction(_ic_a_1).equal(TRK.domainRestriction(_ic_a_1))).booleanValue()) {
                        _ic_boolean_12 = BBoolean(false);
                        break;
                    }

                }

            }

            return (_ic_boolean_12).booleanValue();
        }

        bool _check_inv_5() const {
            return (LBT.subset(OCC)).booleanValue();
        }

        bool _check_inv_6() const {
            BBoolean _ic_boolean_13 = BBoolean(true);
            for(const BLOCKS& _ic_a_1 : rsrtbl.domain()) {
                for(const BLOCKS& _ic_b_1 : LBT) {
                    for(const ROUTES& _ic_c_1 : {rsrtbl.functionCall(_ic_b_1)}) {
                        for(const BRelation<BLOCKS, BLOCKS >& _ic_d_1 : {nxt.functionCall(_ic_c_1)}) {
                            if(!((BBoolean(!(BBoolean(_ic_d_1.range().elementOf(_ic_b_1).booleanValue() && _ic_a_1.equal(_ic_d_1.inverse().functionCall(_ic_b_1)).booleanValue())).booleanValue() || rsrtbl.functionCall(_ic_a_1).unequal(_ic_c_1).booleanValue()))).booleanValue()) {
                                _ic_boolean_13 = BBoolean(false);
                                break;
                            }

                        }

                    }

                }
            }

            return (_ic_boolean_13).booleanValue();
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
            BBoolean _ic_boolean_14 = BBoolean(true);
            for(const ROUTES& _ic_r_1 : _ROUTES) {
                for(const BRelation<BLOCKS, BLOCKS >& _ic_a_1 : {nxt.functionCall(_ic_r_1)}) {
                    for(const BSet<BLOCKS >& _ic_b_1 : {rsrtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1)))}) {
                        for(const BSet<BLOCKS >& _ic_c_1 : {_ic_b_1.difference(OCC)}) {
                            if(!((BBoolean((BBoolean(_ic_a_1.relationImage(rtbl.inverse().relationImage((BSet<ROUTES >(_ic_r_1))).difference(_ic_b_1)).intersect(_ic_c_1).equal((BSet<BLOCKS >())).booleanValue() && _ic_a_1.relationImage(_ic_b_1).subset(_ic_b_1).booleanValue())).booleanValue() && _ic_a_1.relationImage(_ic_c_1).subset(_ic_c_1).booleanValue()))).booleanValue()) {
                                _ic_boolean_14 = BBoolean(false);
                                break;
                            }

                        }

                    }

                }

            }

            return (_ic_boolean_14).booleanValue();
        }

        bool _check_inv_11() const {
            return (frm.subset(resrt)).booleanValue();
        }

        bool _check_inv_12() const {
            return (rsrtbl.relationImage(OCC).subset(frm)).booleanValue();
        }

        static constexpr unsigned int strHash(const char *s, int off = 0) {
            return !s[off] ? 5381 : (strHash(s, off+1)*33) ^ s[off];
        }

        Train_1_beebook_deterministic_MC_POR_v2 _copy(unordered_set<string> toInvalidate) const {
            static const char* allTransitions[] = {"_tr_route_reservation", "_tr_route_freeing", "_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_1", "_tr_BACK_MOVE_2", "_tr_point_positionning", "_tr_route_formation"};

            Train_1_beebook_deterministic_MC_POR_v2 result = Train_1_beebook_deterministic_MC_POR_v2(fst, lst, nxt, rtbl, LBT, TRK, frm, OCC, resbl, resrt, rsrtbl);

            for (const auto &item : allTransitions) {
                if(toInvalidate.find(item) == toInvalidate.end()) {
                    switch(strHash(item)) {
                        case strHash("_tr_route_reservation"): result._tr_cache_route_reservation = this->_tr_cache_route_reservation; break;
                        case strHash("_tr_route_freeing"): result._tr_cache_route_freeing = this->_tr_cache_route_freeing; break;
                        case strHash("_tr_FRONT_MOVE_1"): result._tr_cache_FRONT_MOVE_1 = this->_tr_cache_FRONT_MOVE_1; break;
                        case strHash("_tr_FRONT_MOVE_2"): result._tr_cache_FRONT_MOVE_2 = this->_tr_cache_FRONT_MOVE_2; break;
                        case strHash("_tr_BACK_MOVE_1"): result._tr_cache_BACK_MOVE_1 = this->_tr_cache_BACK_MOVE_1; break;
                        case strHash("_tr_BACK_MOVE_2"): result._tr_cache_BACK_MOVE_2 = this->_tr_cache_BACK_MOVE_2; break;
                        case strHash("_tr_point_positionning"): result._tr_cache_point_positionning = this->_tr_cache_point_positionning; break;
                        case strHash("_tr_route_formation"): result._tr_cache_route_formation = this->_tr_cache_route_formation; break;
                        default: cout << "Transition " << item << " not found!";
                    }
                }
            }
            return result;
        }

        friend bool operator ==(const Train_1_beebook_deterministic_MC_POR_v2& o1, const Train_1_beebook_deterministic_MC_POR_v2& o2) {
            return o1._get_LBT() == o2._get_LBT() && o1._get_TRK() == o2._get_TRK() && o1._get_frm() == o2._get_frm() && o1._get_OCC() == o2._get_OCC() && o1._get_resbl() == o2._get_resbl() && o1._get_resrt() == o2._get_resrt() && o1._get_rsrtbl() == o2._get_rsrtbl();
        }

        friend bool operator !=(const Train_1_beebook_deterministic_MC_POR_v2& o1, const Train_1_beebook_deterministic_MC_POR_v2& o2) {
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

        friend std::ostream& operator<<(std::ostream &strm, const Train_1_beebook_deterministic_MC_POR_v2 &machine) {
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
        Train_1_beebook_deterministic_MC_POR_v2::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<Train_1_beebook_deterministic_MC_POR_v2> unvisitedStates;
        std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex guardMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        Train_1_beebook_deterministic_MC_POR_v2 counterExampleState;

        std::unordered_map<string, std::unordered_set<string>> invariantDependency;
        std::unordered_map<string, std::unordered_set<string>> guardDependency;
        std::unordered_map<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(Train_1_beebook_deterministic_MC_POR_v2::Type type, int threads, bool isCaching, bool isDebug) {
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
            Train_1_beebook_deterministic_MC_POR_v2 machine = Train_1_beebook_deterministic_MC_POR_v2();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            if (isCaching) {
                initCache(machine);
            }

            while(!unvisitedStates.empty()) {
                Train_1_beebook_deterministic_MC_POR_v2 state = next();

                std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> nextStates = generateNextStates(state);
                transitions += nextStates.size();

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
            Train_1_beebook_deterministic_MC_POR_v2 machine = Train_1_beebook_deterministic_MC_POR_v2();
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
                Train_1_beebook_deterministic_MC_POR_v2 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> nextStates = generateNextStates(state);
                    transitions += nextStates.size();

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

        void initCache(Train_1_beebook_deterministic_MC_POR_v2& machine) {
            invariantDependency.insert({"point_positionning", {"_check_inv_3", "_check_inv_1", "_check_inv_4"}});
            invariantDependency.insert({"route_reservation", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11"}});
            invariantDependency.insert({"FRONT_MOVE_1", {"_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
            invariantDependency.insert({"BACK_MOVE_1", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
            invariantDependency.insert({"FRONT_MOVE_2", {"_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9"}});
            invariantDependency.insert({"route_formation", {"_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
            invariantDependency.insert({"route_freeing", {"_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11"}});
            invariantDependency.insert({"BACK_MOVE_2", {"_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
            invariantDependency.insert({"", {}});
            guardDependency.insert({"point_positionning", {"_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"route_reservation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"FRONT_MOVE_1", {"_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"BACK_MOVE_1", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"FRONT_MOVE_2", {"_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"route_formation", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning"}});
            guardDependency.insert({"route_freeing", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2"}});
            guardDependency.insert({"BACK_MOVE_2", {"_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2"}});
        }


    private:
        Train_1_beebook_deterministic_MC_POR_v2 next() {
            std::unique_lock<std::mutex> lock(mutex);
            switch(type) {
                case Train_1_beebook_deterministic_MC_POR_v2::BFS: {
                    Train_1_beebook_deterministic_MC_POR_v2 state = unvisitedStates.front();
                    unvisitedStates.pop_front();
                    return state;
                }
                case Train_1_beebook_deterministic_MC_POR_v2::DFS: {
                    Train_1_beebook_deterministic_MC_POR_v2 state = unvisitedStates.back();
                    unvisitedStates.pop_back();
                    return state;
                }
                case Train_1_beebook_deterministic_MC_POR_v2::MIXED: {
                    if(unvisitedStates.size() % 2 == 0) {
                        Train_1_beebook_deterministic_MC_POR_v2 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    } else {
                        Train_1_beebook_deterministic_MC_POR_v2 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                }
            }
        }

        std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> generateNextStates(const Train_1_beebook_deterministic_MC_POR_v2& state) {
            std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual> result = std::unordered_set<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2::Hash, Train_1_beebook_deterministic_MC_POR_v2::HashEqual>();
            BSet<Train_1_beebook_deterministic_MC_POR_v2::ROUTES> _trid_1 = state._tr_route_reservation(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::ROUTES& param : _trid_1) {
                Train_1_beebook_deterministic_MC_POR_v2::ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["route_reservation"]);
                copiedState.route_reservation(_tmp_1);
                copiedState.stateAccessedVia = "route_reservation";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::ROUTES> _trid_2 = state._tr_route_freeing(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::ROUTES& param : _trid_2) {
                Train_1_beebook_deterministic_MC_POR_v2::ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["route_freeing"]);
                copiedState.route_freeing(_tmp_1);
                copiedState.stateAccessedVia = "route_freeing";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::ROUTES> _trid_3 = state._tr_FRONT_MOVE_1(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::ROUTES& param : _trid_3) {
                Train_1_beebook_deterministic_MC_POR_v2::ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["FRONT_MOVE_1"]);
                copiedState.FRONT_MOVE_1(_tmp_1);
                copiedState.stateAccessedVia = "FRONT_MOVE_1";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::BLOCKS& param : _trid_4) {
                Train_1_beebook_deterministic_MC_POR_v2::BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["FRONT_MOVE_2"]);
                copiedState.FRONT_MOVE_2(_tmp_1);
                copiedState.stateAccessedVia = "FRONT_MOVE_2";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::BLOCKS> _trid_5 = state._tr_BACK_MOVE_1(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::BLOCKS& param : _trid_5) {
                Train_1_beebook_deterministic_MC_POR_v2::BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["BACK_MOVE_1"]);
                copiedState.BACK_MOVE_1(_tmp_1);
                copiedState.stateAccessedVia = "BACK_MOVE_1";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::BLOCKS> _trid_6 = state._tr_BACK_MOVE_2(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::BLOCKS& param : _trid_6) {
                Train_1_beebook_deterministic_MC_POR_v2::BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["BACK_MOVE_2"]);
                copiedState.BACK_MOVE_2(_tmp_1);
                copiedState.stateAccessedVia = "BACK_MOVE_2";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::ROUTES> _trid_7 = state._tr_point_positionning(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::ROUTES& param : _trid_7) {
                Train_1_beebook_deterministic_MC_POR_v2::ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["point_positionning"]);
                copiedState.point_positionning(_tmp_1);
                copiedState.stateAccessedVia = "point_positionning";
                result.insert(copiedState);
            }
            BSet<Train_1_beebook_deterministic_MC_POR_v2::ROUTES> _trid_8 = state._tr_route_formation(isCaching);
            for(const Train_1_beebook_deterministic_MC_POR_v2::ROUTES& param : _trid_8) {
                Train_1_beebook_deterministic_MC_POR_v2::ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy(guardDependency["route_formation"]);
                copiedState.route_formation(_tmp_1);
                copiedState.stateAccessedVia = "route_formation";
                result.insert(copiedState);
            }

            return result;
        }

        bool invariantViolated(const Train_1_beebook_deterministic_MC_POR_v2& state) {
            if(isCaching) {
                std::unordered_set<string> dependentInvariantsOfState = invariantDependency[state.stateAccessedVia];
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
                return false;
            }
            return !(state._check_inv_1() && state._check_inv_2() && state._check_inv_3() && state._check_inv_4() && state._check_inv_5() && state._check_inv_6() && state._check_inv_7() && state._check_inv_8() && state._check_inv_9() && state._check_inv_10() && state._check_inv_11() && state._check_inv_12());
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

    Train_1_beebook_deterministic_MC_POR_v2::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v2::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v2::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = Train_1_beebook_deterministic_MC_POR_v2::Type::DFS;
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