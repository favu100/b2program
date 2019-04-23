#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BTuple.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"
#include "BInteger.cpp"
#include "BRelation.cpp"

#ifndef Train_1_beebook_deterministic_H
#define Train_1_beebook_deterministic_H

using namespace std;

class Train_1_beebook_deterministic {

    public:
        class BLOCKS : public BObject {
            public:

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

                BBoolean equal(const BLOCKS& o) {
                    return value == o.value;
                }

                BBoolean unequal(const BLOCKS& o) {
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
                    return static_cast<int>(value);
                }
        };

        class ROUTES : public BObject {
            public:

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

                BBoolean equal(const ROUTES& o) {
                    return value == o.value;
                }

                BBoolean unequal(const ROUTES& o) {
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
                    return static_cast<int>(value);
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
        BSet<BInteger > visited;

    public:

        Train_1_beebook_deterministic() {
            fst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::N))))));
            lst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1)), (BLOCKS(BLOCKS::C)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4)), (BLOCKS(BLOCKS::G)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5)), (BLOCKS(BLOCKS::N)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8)), (BLOCKS(BLOCKS::L)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9)), (BLOCKS(BLOCKS::M)))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10)), (BLOCKS(BLOCKS::M))))));
            nxt = (BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >((BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R1)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::C)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R2)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R3)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R4)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::G)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R5)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::N)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R6)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::C)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R7)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::E)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R8)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::D)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D)), (BLOCKS(BLOCKS::B)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B)), (BLOCKS(BLOCKS::A)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A)), (BLOCKS(BLOCKS::L)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R9)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G)), (BLOCKS(BLOCKS::F)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F)), (BLOCKS(BLOCKS::K)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M)))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R10)), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N)), (BLOCKS(BLOCKS::J)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J)), (BLOCKS(BLOCKS::I)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I)), (BLOCKS(BLOCKS::H)))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H)), (BLOCKS(BLOCKS::M))))))))));
            BRelation<BLOCKS, ROUTES > _ic_set_0 = BRelation<BLOCKS, ROUTES >();
            for(BLOCKS _ic_b : _BLOCKS) {
                for(ROUTES _ic_r : _ROUTES) {
                    if((_BLOCKS.elementOf(_ic_b)._and(_ROUTES.elementOf(_ic_r))._and(nxt.domain().elementOf(_ic_r)._and(nxt.functionCall(_ic_r).domain().elementOf(_ic_b)._or(nxt.functionCall(_ic_r).range().elementOf(_ic_b))))).booleanValue()) {
                        _ic_set_0 = _ic_set_0._union(BRelation<BLOCKS, ROUTES >((BTuple<BLOCKS, ROUTES >(_ic_b, _ic_r))));
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
            visited = (BSet<BInteger >());
        }

        void route_reservation(const ROUTES& r) {
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BInteger > _ld_visited = visited;
            BSet<ROUTES > _ld_resrt = resrt;
            BSet<BLOCKS > _ld_resbl = resbl;
            resrt = _ld_resrt._union((BSet<ROUTES >(r)));
            rsrtbl = _ld_rsrtbl._union(rtbl.rangeRestriction((BSet<ROUTES >(r))));
            resbl = _ld_resbl._union(rtbl.inverse().relationImage((BSet<ROUTES >(r))));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(1)))));
        }

        void route_freeing(const ROUTES& r) {
            BSet<ROUTES > _ld_frm = frm;
            BSet<BInteger > _ld_visited = visited;
            BSet<ROUTES > _ld_resrt = resrt;
            resrt = _ld_resrt.difference((BSet<ROUTES >(r)));
            frm = _ld_frm.difference((BSet<ROUTES >(r)));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(2)))));
        }

        void FRONT_MOVE_1(const ROUTES& r) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BSet<BInteger > _ld_visited = visited;
            OCC = _ld_OCC._union((BSet<BLOCKS >(fst.functionCall(r))));
            LBT = _ld_LBT._union((BSet<BLOCKS >(fst.functionCall(r))));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(3)))));
        }

        void FRONT_MOVE_2(const BLOCKS& b) {
            BSet<BLOCKS > _ld_OCC = OCC;
            BSet<BInteger > _ld_visited = visited;
            OCC = _ld_OCC._union((BSet<BLOCKS >(TRK.functionCall(b))));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(4)))));
        }

        void BACK_MOVE_1(const BLOCKS& b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BInteger > _ld_visited = visited;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(5)))));
        }

        void BACK_MOVE_2(const BLOCKS& b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BInteger > _ld_visited = visited;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)))._union((BSet<BLOCKS >(TRK.functionCall(b))));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(6)))));
        }

        void point_positionning(const ROUTES& r) {
            BSet<BInteger > _ld_visited = visited;
            BRelation<BLOCKS, BLOCKS > _ld_TRK = TRK;
            TRK = _ld_TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range())._union(nxt.functionCall(r));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(7)))));
        }

        void route_formation(const ROUTES& r) {
            BSet<ROUTES > _ld_frm = frm;
            BSet<BInteger > _ld_visited = visited;
            frm = _ld_frm._union((BSet<ROUTES >(r)));
            visited = _ld_visited._union((BSet<BInteger >((BInteger(8)))));
        }

};


#endif