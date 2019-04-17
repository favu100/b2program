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

                string name;

                BLOCKS(){}

                BLOCKS(BLOCKS_type type, string name) {
                    this->value = type;
                    this->name = name;
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

                friend std::ostream& operator<<(std::ostream &strm, const BLOCKS& e) {
                  return strm << e.name;
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

                string name;

                ROUTES(){}

                ROUTES(ROUTES_type type, string name) {
                    this->value = type;
                    this->name = name;
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

                friend std::ostream& operator<<(std::ostream &strm, const ROUTES& e) {
                  return strm << e.name;
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


        #define _BLOCKS (BSet<BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::C, "C")), (BLOCKS(BLOCKS::D, "D")), (BLOCKS(BLOCKS::E, "E")), (BLOCKS(BLOCKS::F, "F")), (BLOCKS(BLOCKS::G, "G")), (BLOCKS(BLOCKS::H, "H")), (BLOCKS(BLOCKS::I, "I")), (BLOCKS(BLOCKS::J, "J")), (BLOCKS(BLOCKS::K, "K")), (BLOCKS(BLOCKS::L, "L")), (BLOCKS(BLOCKS::M, "M")), (BLOCKS(BLOCKS::N, "N"))))
        #define _ROUTES (BSet<ROUTES >((ROUTES(ROUTES::R1, "R1")), (ROUTES(ROUTES::R2, "R2")), (ROUTES(ROUTES::R3, "R3")), (ROUTES(ROUTES::R4, "R4")), (ROUTES(ROUTES::R5, "R5")), (ROUTES(ROUTES::R6, "R6")), (ROUTES(ROUTES::R7, "R7")), (ROUTES(ROUTES::R8, "R8")), (ROUTES(ROUTES::R9, "R9")), (ROUTES(ROUTES::R10, "R10"))))

        BSet<BLOCKS > LBT;
        BRelation<BLOCKS, BLOCKS > TRK;
        BSet<ROUTES > frm;
        BSet<BLOCKS > OCC;
        BSet<BLOCKS > resbl;
        BSet<ROUTES > resrt;
        BRelation<BLOCKS, ROUTES > rsrtbl;

    public:

        Train_1_beebook_deterministic() {
            fst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1, "R1")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2, "R2")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3, "R3")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4, "R4")), (BLOCKS(BLOCKS::M, "M")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5, "R5")), (BLOCKS(BLOCKS::M, "M")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6, "R6")), (BLOCKS(BLOCKS::C, "C")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7, "R7")), (BLOCKS(BLOCKS::G, "G")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8, "R8")), (BLOCKS(BLOCKS::N, "N")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9, "R9")), (BLOCKS(BLOCKS::G, "G")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10, "R10")), (BLOCKS(BLOCKS::N, "N"))))));
            lst = (BRelation<ROUTES, BLOCKS >((BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R1, "R1")), (BLOCKS(BLOCKS::C, "C")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R2, "R2")), (BLOCKS(BLOCKS::G, "G")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R3, "R3")), (BLOCKS(BLOCKS::N, "N")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R4, "R4")), (BLOCKS(BLOCKS::G, "G")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R5, "R5")), (BLOCKS(BLOCKS::N, "N")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R6, "R6")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R7, "R7")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R8, "R8")), (BLOCKS(BLOCKS::L, "L")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R9, "R9")), (BLOCKS(BLOCKS::M, "M")))), (BTuple<ROUTES, BLOCKS >((ROUTES(ROUTES::R10, "R10")), (BLOCKS(BLOCKS::M, "M"))))));
            nxt = (BRelation<ROUTES, BRelation<BLOCKS, BLOCKS > >((BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R1, "R1")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L, "L")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::C, "C")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R2, "R2")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L, "L")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::D, "D")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D, "D")), (BLOCKS(BLOCKS::E, "E")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E, "E")), (BLOCKS(BLOCKS::F, "F")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F, "F")), (BLOCKS(BLOCKS::G, "G")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R3, "R3")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::L, "L")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::D, "D")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D, "D")), (BLOCKS(BLOCKS::K, "K")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K, "K")), (BLOCKS(BLOCKS::J, "J")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J, "J")), (BLOCKS(BLOCKS::N, "N")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R4, "R4")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M, "M")), (BLOCKS(BLOCKS::H, "H")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H, "H")), (BLOCKS(BLOCKS::I, "I")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I, "I")), (BLOCKS(BLOCKS::K, "K")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K, "K")), (BLOCKS(BLOCKS::F, "F")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F, "F")), (BLOCKS(BLOCKS::G, "G")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R5, "R5")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::M, "M")), (BLOCKS(BLOCKS::H, "H")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H, "H")), (BLOCKS(BLOCKS::I, "I")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I, "I")), (BLOCKS(BLOCKS::J, "J")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J, "J")), (BLOCKS(BLOCKS::N, "N")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R6, "R6")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::C, "C")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::L, "L")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R7, "R7")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G, "G")), (BLOCKS(BLOCKS::F, "F")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F, "F")), (BLOCKS(BLOCKS::E, "E")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::E, "E")), (BLOCKS(BLOCKS::D, "D")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D, "D")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::L, "L")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R8, "R8")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N, "N")), (BLOCKS(BLOCKS::J, "J")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J, "J")), (BLOCKS(BLOCKS::K, "K")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K, "K")), (BLOCKS(BLOCKS::D, "D")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::D, "D")), (BLOCKS(BLOCKS::B, "B")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::B, "B")), (BLOCKS(BLOCKS::A, "A")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::A, "A")), (BLOCKS(BLOCKS::L, "L")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R9, "R9")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::G, "G")), (BLOCKS(BLOCKS::F, "F")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::F, "F")), (BLOCKS(BLOCKS::K, "K")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::K, "K")), (BLOCKS(BLOCKS::I, "I")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I, "I")), (BLOCKS(BLOCKS::H, "H")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H, "H")), (BLOCKS(BLOCKS::M, "M")))))))), (BTuple<ROUTES, BRelation<BLOCKS, BLOCKS > >((ROUTES(ROUTES::R10, "R10")), (BRelation<BLOCKS, BLOCKS >((BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::N, "N")), (BLOCKS(BLOCKS::J, "J")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::J, "J")), (BLOCKS(BLOCKS::I, "I")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::I, "I")), (BLOCKS(BLOCKS::H, "H")))), (BTuple<BLOCKS, BLOCKS >((BLOCKS(BLOCKS::H, "H")), (BLOCKS(BLOCKS::M, "M"))))))))));
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
        }

        void route_reservation(ROUTES r) {
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<ROUTES > _ld_resrt = resrt;
            BSet<BLOCKS > _ld_resbl = resbl;
            resrt = _ld_resrt._union((BSet<ROUTES >(r)));
            rsrtbl = _ld_rsrtbl._union(rtbl.rangeRestriction((BSet<ROUTES >(r))));
            resbl = _ld_resbl._union(rtbl.inverse().relationImage((BSet<ROUTES >(r))));
        }

        void route_freeing(ROUTES r) {
            BSet<ROUTES > _ld_frm = frm;
            BSet<ROUTES > _ld_resrt = resrt;
            resrt = _ld_resrt.difference((BSet<ROUTES >(r)));
            frm = _ld_frm.difference((BSet<ROUTES >(r)));
        }

        void FRONT_MOVE_1(ROUTES r) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            OCC = _ld_OCC._union((BSet<BLOCKS >(fst.functionCall(r))));
            LBT = _ld_LBT._union((BSet<BLOCKS >(fst.functionCall(r))));
        }

        void FRONT_MOVE_2(BLOCKS b) {
            BSet<BLOCKS > _ld_OCC = OCC;
            OCC = _ld_OCC._union((BSet<BLOCKS >(TRK.functionCall(b))));
        }

        void BACK_MOVE_1(BLOCKS b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)));
        }

        void BACK_MOVE_2(BLOCKS b) {
            BSet<BLOCKS > _ld_LBT = LBT;
            BSet<BLOCKS > _ld_OCC = OCC;
            BRelation<BLOCKS, ROUTES > _ld_rsrtbl = rsrtbl;
            BSet<BLOCKS > _ld_resbl = resbl;
            OCC = _ld_OCC.difference((BSet<BLOCKS >(b)));
            rsrtbl = _ld_rsrtbl.domainSubstraction((BSet<BLOCKS >(b)));
            resbl = _ld_resbl.difference((BSet<BLOCKS >(b)));
            LBT = _ld_LBT.difference((BSet<BLOCKS >(b)))._union((BSet<BLOCKS >(TRK.functionCall(b))));
        }

        void point_positionning(ROUTES r) {
            BRelation<BLOCKS, BLOCKS > _ld_TRK = TRK;
            TRK = _ld_TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range())._union(nxt.functionCall(r));
        }

        void route_formation(ROUTES r) {
            BSet<ROUTES > _ld_frm = frm;
            frm = _ld_frm._union((BSet<ROUTES >(r)));
        }

};


#endif