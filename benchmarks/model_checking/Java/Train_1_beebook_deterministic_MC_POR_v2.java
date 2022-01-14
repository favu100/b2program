import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.Future;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;
import clojure.java.api.Clojure;
import clojure.lang.PersistentHashMap;
import clojure.lang.RT;
import clojure.lang.Var;
import java.util.Objects;
import java.util.Arrays;
import de.hhu.stups.btypes.PreconditionOrAssertionViolation;
import de.hhu.stups.btypes.StateNotReachableError;
import de.hhu.stups.btypes.BUtils;


public class Train_1_beebook_deterministic_MC_POR_v2 {


    private static final Var ASSOC;
    private static final Var GET;

    static {
        RT.var("clojure.core", "require").invoke(Clojure.read("clojure.set"));
        ASSOC = RT.var("clojure.core", "assoc");
        GET = RT.var("clojure.core", "get");
    }

    public static enum Type {
        BFS,
        DFS,
        MIXED
    }



    private static BRelation<ROUTES, BLOCKS> fst;
    private static BRelation<ROUTES, BLOCKS> lst;
    private static BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> nxt;
    private static BRelation<BLOCKS, ROUTES> rtbl;


    public enum BLOCKS implements BObject {
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
        N;

        public BBoolean equal(BLOCKS o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(BLOCKS o) {
            return new BBoolean(this != o);
        }
    }

    public enum ROUTES implements BObject {
        R1, 
        R2, 
        R3, 
        R4, 
        R5, 
        R6, 
        R7, 
        R8, 
        R9, 
        R10;

        public BBoolean equal(ROUTES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(ROUTES o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<BLOCKS> _BLOCKS = new BSet<BLOCKS>(BLOCKS.A, BLOCKS.B, BLOCKS.C, BLOCKS.D, BLOCKS.E, BLOCKS.F, BLOCKS.G, BLOCKS.H, BLOCKS.I, BLOCKS.J, BLOCKS.K, BLOCKS.L, BLOCKS.M, BLOCKS.N);
    private static BSet<ROUTES> _ROUTES = new BSet<ROUTES>(ROUTES.R1, ROUTES.R2, ROUTES.R3, ROUTES.R4, ROUTES.R5, ROUTES.R6, ROUTES.R7, ROUTES.R8, ROUTES.R9, ROUTES.R10);

    private BSet<BLOCKS> LBT;
    private BRelation<BLOCKS, BLOCKS> TRK;
    private BSet<ROUTES> frm;
    private BSet<BLOCKS> OCC;
    private BSet<BLOCKS> resbl;
    private BSet<ROUTES> resrt;
    private BRelation<BLOCKS, ROUTES> rsrtbl;

    static {
        fst = new BRelation<ROUTES, BLOCKS>(new BTuple<>(ROUTES.R1, BLOCKS.L), new BTuple<>(ROUTES.R2, BLOCKS.L), new BTuple<>(ROUTES.R3, BLOCKS.L), new BTuple<>(ROUTES.R4, BLOCKS.M), new BTuple<>(ROUTES.R5, BLOCKS.M), new BTuple<>(ROUTES.R6, BLOCKS.C), new BTuple<>(ROUTES.R7, BLOCKS.G), new BTuple<>(ROUTES.R8, BLOCKS.N), new BTuple<>(ROUTES.R9, BLOCKS.G), new BTuple<>(ROUTES.R10, BLOCKS.N));
        lst = new BRelation<ROUTES, BLOCKS>(new BTuple<>(ROUTES.R1, BLOCKS.C), new BTuple<>(ROUTES.R2, BLOCKS.G), new BTuple<>(ROUTES.R3, BLOCKS.N), new BTuple<>(ROUTES.R4, BLOCKS.G), new BTuple<>(ROUTES.R5, BLOCKS.N), new BTuple<>(ROUTES.R6, BLOCKS.L), new BTuple<>(ROUTES.R7, BLOCKS.L), new BTuple<>(ROUTES.R8, BLOCKS.L), new BTuple<>(ROUTES.R9, BLOCKS.M), new BTuple<>(ROUTES.R10, BLOCKS.M));
        nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple<>(ROUTES.R1, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.C))), new BTuple<>(ROUTES.R2, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.E), new BTuple<>(BLOCKS.E, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.G))), new BTuple<>(ROUTES.R3, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.N))), new BTuple<>(ROUTES.R4, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.M, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.G))), new BTuple<>(ROUTES.R5, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.M, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.N))), new BTuple<>(ROUTES.R6, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.C, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R7, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.G, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.E), new BTuple<>(BLOCKS.E, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R8, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.N, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R9, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.G, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.M))), new BTuple<>(ROUTES.R10, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.N, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.M))));
        BRelation<BLOCKS, ROUTES> _ic_set_0 = new BRelation<BLOCKS, ROUTES>();
        for(BLOCKS _ic_b_1 : _BLOCKS) {
            for(ROUTES _ic_r_1 : _ROUTES) {
                if((new BBoolean(nxt.domain().elementOf(_ic_r_1).booleanValue() && new BBoolean(nxt.functionCall(_ic_r_1).domain().elementOf(_ic_b_1).booleanValue() || nxt.functionCall(_ic_r_1).range().elementOf(_ic_b_1).booleanValue()).booleanValue())).booleanValue()) {
                    _ic_set_0 = _ic_set_0.union(new BRelation<BLOCKS, ROUTES>(new BTuple<>(_ic_b_1, _ic_r_1)));
                }

            }
        }

        rtbl = _ic_set_0;
    }

    public Train_1_beebook_deterministic_MC_POR_v2() {
        resrt = new BSet<ROUTES>();
        resbl = new BSet<BLOCKS>();
        rsrtbl = new BRelation<BLOCKS, ROUTES>();
        OCC = new BSet<BLOCKS>();
        TRK = new BRelation<BLOCKS, BLOCKS>();
        frm = new BSet<ROUTES>();
        LBT = new BSet<BLOCKS>();
    }

    public Train_1_beebook_deterministic_MC_POR_v2(BRelation<ROUTES, BLOCKS> fst, BRelation<ROUTES, BLOCKS> lst, BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> nxt, BRelation<BLOCKS, ROUTES> rtbl, BSet<BLOCKS> LBT, BRelation<BLOCKS, BLOCKS> TRK, BSet<ROUTES> frm, BSet<BLOCKS> OCC, BSet<BLOCKS> resbl, BSet<ROUTES> resrt, BRelation<BLOCKS, ROUTES> rsrtbl) {
        this.fst = fst;
        this.lst = lst;
        this.nxt = nxt;
        this.rtbl = rtbl;
        this.LBT = LBT;
        this.TRK = TRK;
        this.frm = frm;
        this.OCC = OCC;
        this.resbl = resbl;
        this.resrt = resrt;
        this.rsrtbl = rsrtbl;
    }

    public void route_reservation(ROUTES r) {
        BSet<ROUTES> _ld_resrt = resrt;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        resrt = _ld_resrt.union(new BSet<ROUTES>(r));
        rsrtbl = _ld_rsrtbl.union(rtbl.rangeRestriction(new BSet<ROUTES>(r)));
        resbl = _ld_resbl.union(rtbl.inverse().relationImage(new BSet<ROUTES>(r)));

    }

    public void route_freeing(ROUTES r) {
        BSet<ROUTES> _ld_resrt = resrt;
        BSet<ROUTES> _ld_frm = frm;
        resrt = _ld_resrt.difference(new BSet<ROUTES>(r));
        frm = _ld_frm.difference(new BSet<ROUTES>(r));

    }

    public void FRONT_MOVE_1(ROUTES r) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        OCC = _ld_OCC.union(new BSet<BLOCKS>(fst.functionCall(r)));
        LBT = _ld_LBT.union(new BSet<BLOCKS>(fst.functionCall(r)));

    }

    public void FRONT_MOVE_2(BLOCKS b) {
        OCC = OCC.union(new BSet<BLOCKS>(TRK.functionCall(b)));

    }

    public void BACK_MOVE_1(BLOCKS b) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        LBT = _ld_LBT.difference(new BSet<BLOCKS>(b));

    }

    public void BACK_MOVE_2(BLOCKS b) {
        BSet<BLOCKS> _ld_OCC = OCC;

        BSet<BLOCKS> _ld_LBT = LBT;
        BRelation<BLOCKS, ROUTES> _ld_rsrtbl = rsrtbl;
        BSet<BLOCKS> _ld_resbl = resbl;
        OCC = _ld_OCC.difference(new BSet<BLOCKS>(b));
        rsrtbl = _ld_rsrtbl.domainSubstraction(new BSet<BLOCKS>(b));
        resbl = _ld_resbl.difference(new BSet<BLOCKS>(b));
        LBT = _ld_LBT.difference(new BSet<BLOCKS>(b)).union(new BSet<BLOCKS>(TRK.functionCall(b)));

    }

    public void point_positionning(ROUTES r) {
        TRK = TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range()).union(nxt.functionCall(r));

    }

    public void route_formation(ROUTES r) {
        frm = frm.union(new BSet<ROUTES>(r));

    }

    public BRelation<ROUTES, BLOCKS> _get_fst() {
        return fst;
    }

    public BRelation<ROUTES, BLOCKS> _get_lst() {
        return lst;
    }

    public BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> _get_nxt() {
        return nxt;
    }

    public BRelation<BLOCKS, ROUTES> _get_rtbl() {
        return rtbl;
    }

    public BSet<BLOCKS> _get_LBT() {
        return LBT;
    }

    public BRelation<BLOCKS, BLOCKS> _get_TRK() {
        return TRK;
    }

    public BSet<ROUTES> _get_frm() {
        return frm;
    }

    public BSet<BLOCKS> _get_OCC() {
        return OCC;
    }

    public BSet<BLOCKS> _get_resbl() {
        return resbl;
    }

    public BSet<ROUTES> _get_resrt() {
        return resrt;
    }

    public BRelation<BLOCKS, ROUTES> _get_rsrtbl() {
        return rsrtbl;
    }

    public BSet<BLOCKS> _get__BLOCKS() {
        return _BLOCKS;
    }

    public BSet<ROUTES> _get__ROUTES() {
        return _ROUTES;
    }


    public BSet<ROUTES> _tr_route_reservation() {
        BSet<ROUTES> _ic_set_1 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : _ROUTES.difference(resrt)) {
            if((new BBoolean(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).intersect(resbl).equal(new BSet<BLOCKS>()).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_1;
    }

    public BSet<ROUTES> _tr_route_freeing() {
        BSet<ROUTES> _ic_set_2 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(rsrtbl.range())) {
            _ic_set_2 = _ic_set_2.union(new BSet<ROUTES>(_ic_r_1));

        }
        return _ic_set_2;
    }

    public BSet<ROUTES> _tr_FRONT_MOVE_1() {
        BSet<ROUTES> _ic_set_3 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : frm) {
            if((new BBoolean(new BBoolean(resbl.difference(OCC).elementOf(fst.functionCall(_ic_r_1)).booleanValue() && _ic_r_1.equal(rsrtbl.functionCall(fst.functionCall(_ic_r_1))).booleanValue()).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_3 = _ic_set_3.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_3;
    }

    public BSet<BLOCKS> _tr_FRONT_MOVE_2() {
        BSet<BLOCKS> _ic_set_4 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : OCC.intersect(TRK.domain())) {
            if((OCC.notElementOf(TRK.functionCall(_ic_b_1))).booleanValue()) {
                _ic_set_4 = _ic_set_4.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_4;
    }

    public BSet<BLOCKS> _tr_BACK_MOVE_1() {
        BSet<BLOCKS> _ic_set_5 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : LBT.difference(TRK.domain())) {
            if((new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                _ic_set_5 = _ic_set_5.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_5;
    }

    public BSet<BLOCKS> _tr_BACK_MOVE_2() {
        BSet<BLOCKS> _ic_set_6 = new BSet<BLOCKS>();
        for(BLOCKS _ic_b_1 : LBT.intersect(TRK.domain())) {
            if((new BBoolean(OCC.elementOf(TRK.functionCall(_ic_b_1)).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_6 = _ic_set_6.union(new BSet<BLOCKS>(_ic_b_1));
            }

        }
        return _ic_set_6;
    }

    public BSet<ROUTES> _tr_point_positionning() {
        BSet<ROUTES> _ic_set_7 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            if((new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range()))).booleanValue()) {
                _ic_set_7 = _ic_set_7.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_7;
    }

    public BSet<ROUTES> _tr_route_formation() {
        BSet<ROUTES> _ic_set_8 = new BSet<ROUTES>();
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            if((new BBoolean(nxt.functionCall(_ic_r_1).domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1))).equal(TRK.domainRestriction(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))).booleanValue() && new BSet<ROUTES>().equal(resrt.difference(rsrtbl.range())).booleanValue())).booleanValue()) {
                _ic_set_8 = _ic_set_8.union(new BSet<ROUTES>(_ic_r_1));
            }

        }
        return _ic_set_8;
    }

    public boolean _check_inv_1() {
        return TRK.checkDomain(_BLOCKS).and(TRK.checkRange(_BLOCKS)).and(TRK.isFunction()).and(TRK.isPartial(_BLOCKS)).and(TRK.isInjection()).booleanValue();
    }

    public boolean _check_inv_2() {
        BBoolean _ic_boolean_9 = new BBoolean(true);
        for(ROUTES _ic_r_1 : resrt.difference(frm)) {
            for(BSet<ROUTES> _ic_a_1 : Arrays.asList(new BSet<ROUTES>(_ic_r_1))) {
                if(!(rtbl.rangeRestriction(_ic_a_1).equal(rsrtbl.rangeRestriction(_ic_a_1))).booleanValue()) {
                    _ic_boolean_9 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_9.booleanValue();
    }

    public boolean _check_inv_3() {
        BBoolean _ic_boolean_11 = new BBoolean(true);
        for(BLOCKS _ic_x_1 : TRK.domain()) {
            for(BLOCKS _ic_y_1 : TRK.relationImage(new BSet<BLOCKS>(_ic_x_1))) {
                BBoolean _ic_boolean_10 = new BBoolean(false);
                for(ROUTES _ic_r_1 : _ROUTES) {
                    if((nxt.functionCall(_ic_r_1).elementOf(new BTuple<>(_ic_x_1, _ic_y_1))).booleanValue()) {
                        _ic_boolean_10 = new BBoolean(true);
                        break;
                    }

                }

                if(!(_ic_boolean_10).booleanValue()) {
                    _ic_boolean_11 = new BBoolean(false);
                    break;
                }

            }
        }

        return _ic_boolean_11.booleanValue();
    }

    public boolean _check_inv_4() {
        BBoolean _ic_boolean_12 = new BBoolean(true);
        for(ROUTES _ic_r_1 : frm) {
            for(BSet<BLOCKS> _ic_a_1 : Arrays.asList(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))) {
                if(!(nxt.functionCall(_ic_r_1).domainRestriction(_ic_a_1).equal(TRK.domainRestriction(_ic_a_1))).booleanValue()) {
                    _ic_boolean_12 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_12.booleanValue();
    }

    public boolean _check_inv_5() {
        return LBT.subset(OCC).booleanValue();
    }

    public boolean _check_inv_6() {
        BBoolean _ic_boolean_13 = new BBoolean(true);
        for(BLOCKS _ic_a_1 : rsrtbl.domain()) {
            for(BLOCKS _ic_b_1 : LBT) {
                for(ROUTES _ic_c_1 : Arrays.asList(rsrtbl.functionCall(_ic_b_1))) {
                    for(BRelation<BLOCKS, BLOCKS> _ic_d_1 : Arrays.asList(nxt.functionCall(_ic_c_1))) {
                        if(!(new BBoolean(!new BBoolean(_ic_d_1.range().elementOf(_ic_b_1).booleanValue() && _ic_a_1.equal(_ic_d_1.inverse().functionCall(_ic_b_1)).booleanValue()).booleanValue() || rsrtbl.functionCall(_ic_a_1).unequal(_ic_c_1).booleanValue())).booleanValue()) {
                            _ic_boolean_13 = new BBoolean(false);
                            break;
                        }

                    }

                }

            }
        }

        return _ic_boolean_13.booleanValue();
    }

    public boolean _check_inv_7() {
        return rsrtbl.checkDomain(resbl).and(rsrtbl.checkRange(resrt)).and(rsrtbl.isFunction()).and(rsrtbl.isTotal(resbl)).booleanValue();
    }

    public boolean _check_inv_8() {
        return rsrtbl.subset(rtbl).booleanValue();
    }

    public boolean _check_inv_9() {
        return OCC.subset(resbl).booleanValue();
    }

    public boolean _check_inv_10() {
        BBoolean _ic_boolean_14 = new BBoolean(true);
        for(ROUTES _ic_r_1 : _ROUTES) {
            for(BRelation<BLOCKS, BLOCKS> _ic_a_1 : Arrays.asList(nxt.functionCall(_ic_r_1))) {
                for(BSet<BLOCKS> _ic_b_1 : Arrays.asList(rsrtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)))) {
                    for(BSet<BLOCKS> _ic_c_1 : Arrays.asList(_ic_b_1.difference(OCC))) {
                        if(!(new BBoolean(new BBoolean(_ic_a_1.relationImage(rtbl.inverse().relationImage(new BSet<ROUTES>(_ic_r_1)).difference(_ic_b_1)).intersect(_ic_c_1).equal(new BSet<BLOCKS>()).booleanValue() && _ic_a_1.relationImage(_ic_b_1).subset(_ic_b_1).booleanValue()).booleanValue() && _ic_a_1.relationImage(_ic_c_1).subset(_ic_c_1).booleanValue())).booleanValue()) {
                            _ic_boolean_14 = new BBoolean(false);
                            break;
                        }

                    }

                }

            }

        }

        return _ic_boolean_14.booleanValue();
    }

    public boolean _check_inv_11() {
        return frm.subset(resrt).booleanValue();
    }

    public boolean _check_inv_12() {
        return rsrtbl.relationImage(OCC).subset(frm).booleanValue();
    }

    public Train_1_beebook_deterministic_MC_POR_v2 _copy() {
        return new Train_1_beebook_deterministic_MC_POR_v2(fst, lst, nxt, rtbl, LBT, TRK, frm, OCC, resbl, resrt, rsrtbl);
    }

    @Override
    public boolean equals(Object o) {
        Train_1_beebook_deterministic_MC_POR_v2 o1 = this;
        Train_1_beebook_deterministic_MC_POR_v2 o2 = (Train_1_beebook_deterministic_MC_POR_v2) o;
        return o1._get_LBT().equals(o2._get_LBT()) && o1._get_TRK().equals(o2._get_TRK()) && o1._get_frm().equals(o2._get_frm()) && o1._get_OCC().equals(o2._get_OCC()) && o1._get_resbl().equals(o2._get_resbl()) && o1._get_resrt().equals(o2._get_resrt()) && o1._get_rsrtbl().equals(o2._get_rsrtbl());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_LBT()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_TRK()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_frm()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_OCC()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resbl()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resrt()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rsrtbl()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_LBT: " + (this._get_LBT()).toString(), "_get_TRK: " + (this._get_TRK()).toString(), "_get_frm: " + (this._get_frm()).toString(), "_get_OCC: " + (this._get_OCC()).toString(), "_get_resbl: " + (this._get_resbl()).toString(), "_get_resrt: " + (this._get_resrt()).toString(), "_get_rsrtbl: " + (this._get_rsrtbl()).toString());
    }

    @SuppressWarnings("unchecked")
    private static Set<Train_1_beebook_deterministic_MC_POR_v2> generateNextStates(Object guardLock, Train_1_beebook_deterministic_MC_POR_v2 state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentGuard, Map<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap> guardCache, Map<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2> parents, AtomicInteger transitions) {
        Set<Train_1_beebook_deterministic_MC_POR_v2> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = null;
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            BSet<ROUTES> _trid_1;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_route_reservation");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_route_reservation");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_route_reservation();
            } else {
                _trid_1 = (BSet<ROUTES>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_route_reservation", _trid_1);
            for(ROUTES param : _trid_1) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_reservation(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("route_reservation"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("route_reservation"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_2;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_route_freeing");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_route_freeing");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_route_freeing();
            } else {
                _trid_2 = (BSet<ROUTES>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_route_freeing", _trid_2);
            for(ROUTES param : _trid_2) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_freeing(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("route_freeing"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("route_freeing"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_3;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_FRONT_MOVE_1");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_FRONT_MOVE_1");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_FRONT_MOVE_1();
            } else {
                _trid_3 = (BSet<ROUTES>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_FRONT_MOVE_1", _trid_3);
            for(ROUTES param : _trid_3) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.FRONT_MOVE_1(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("FRONT_MOVE_1"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("FRONT_MOVE_1"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_4;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_FRONT_MOVE_2");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_FRONT_MOVE_2");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_FRONT_MOVE_2();
            } else {
                _trid_4 = (BSet<BLOCKS>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_FRONT_MOVE_2", _trid_4);
            for(BLOCKS param : _trid_4) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.FRONT_MOVE_2(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("FRONT_MOVE_2"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("FRONT_MOVE_2"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_5;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_BACK_MOVE_1");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_BACK_MOVE_1");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_BACK_MOVE_1();
            } else {
                _trid_5 = (BSet<BLOCKS>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_BACK_MOVE_1", _trid_5);
            for(BLOCKS param : _trid_5) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.BACK_MOVE_1(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("BACK_MOVE_1"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("BACK_MOVE_1"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_6;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_BACK_MOVE_2");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_BACK_MOVE_2");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_BACK_MOVE_2();
            } else {
                _trid_6 = (BSet<BLOCKS>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_BACK_MOVE_2", _trid_6);
            for(BLOCKS param : _trid_6) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.BACK_MOVE_2(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("BACK_MOVE_2"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("BACK_MOVE_2"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_7;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_point_positionning");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_point_positionning");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_point_positionning();
            } else {
                _trid_7 = (BSet<ROUTES>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_point_positionning", _trid_7);
            for(ROUTES param : _trid_7) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.point_positionning(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("point_positionning"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("point_positionning"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_8;

            dependentGuardsOfState = dependentGuard.get(state);
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_route_formation");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_route_formation");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_route_formation();
            } else {
                _trid_8 = (BSet<ROUTES>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_route_formation", _trid_8);
            for(ROUTES param : _trid_8) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_formation(_tmp_1);
                if(!dependentInvariant.containsKey(copiedState)) {
                    dependentInvariant.put(copiedState, invariantDependency.get("route_formation"));
                }
                synchronized(guardLock) {
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("route_formation"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            guardCache.put(state, newCache);
        } else {
            BSet<ROUTES> _trid_1 = state._tr_route_reservation();
            for(ROUTES param : _trid_1) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_reservation(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_2 = state._tr_route_freeing();
            for(ROUTES param : _trid_2) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_freeing(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_3 = state._tr_FRONT_MOVE_1();
            for(ROUTES param : _trid_3) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.FRONT_MOVE_1(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_4 = state._tr_FRONT_MOVE_2();
            for(BLOCKS param : _trid_4) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.FRONT_MOVE_2(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_5 = state._tr_BACK_MOVE_1();
            for(BLOCKS param : _trid_5) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.BACK_MOVE_1(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BLOCKS> _trid_6 = state._tr_BACK_MOVE_2();
            for(BLOCKS param : _trid_6) {
                BLOCKS _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.BACK_MOVE_2(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_7 = state._tr_point_positionning();
            for(ROUTES param : _trid_7) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.point_positionning(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<ROUTES> _trid_8 = state._tr_route_formation();
            for(ROUTES param : _trid_8) {
                ROUTES _tmp_1 = param;

                Train_1_beebook_deterministic_MC_POR_v2 copiedState = state._copy();
                copiedState.route_formation(_tmp_1);
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Train_1_beebook_deterministic_MC_POR_v2 state, boolean isCaching, Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentInvariant) {
        if(isCaching) {
            Set<String> dependentInvariantsOfState = dependentInvariant.get(state);
            if(dependentInvariantsOfState.contains("_check_inv_1")) {
                if(!state._check_inv_1()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_2")) {
                if(!state._check_inv_2()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_3")) {
                if(!state._check_inv_3()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_4")) {
                if(!state._check_inv_4()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_5")) {
                if(!state._check_inv_5()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_6")) {
                if(!state._check_inv_6()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_7")) {
                if(!state._check_inv_7()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_8")) {
                if(!state._check_inv_8()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_9")) {
                if(!state._check_inv_9()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_10")) {
                if(!state._check_inv_10()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_11")) {
                if(!state._check_inv_11()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_12")) {
                if(!state._check_inv_12()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated) {
        if(deadlockDetected) {
            System.out.println("DEADLOCK DETECTED");
        }
        if(invariantViolated) {
            System.out.println("INVARIANT VIOLATED");
        }
        if(!deadlockDetected && !invariantViolated) {
            System.out.println("MODEL CHECKING SUCCESSFUL");
        }
        System.out.println("Number of States: " + states);
        System.out.println("Number of Transitions: " + transitions);
    }

    private static Train_1_beebook_deterministic_MC_POR_v2 next(LinkedList<Train_1_beebook_deterministic_MC_POR_v2> collection, Object lock, Type type) {
        synchronized(lock) {
            return switch(type) {
                case BFS -> collection.removeFirst();
                case DFS -> collection.removeLast();
                case MIXED -> collection.size() % 2 == 0 ? collection.removeFirst() : collection.removeLast();
            };
        }
    }

    private static void modelCheckSingleThreaded(Type type, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();

        Train_1_beebook_deterministic_MC_POR_v2 machine = new Train_1_beebook_deterministic_MC_POR_v2();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12()) {
            invariantViolated.set(true);
        }

        Set<Train_1_beebook_deterministic_MC_POR_v2> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<Train_1_beebook_deterministic_MC_POR_v2> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentInvariant = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentGuard = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap> guardCache = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("point_positionning", new HashSet<>(Arrays.asList("_check_inv_3", "_check_inv_1", "_check_inv_4")));
            invariantDependency.put("route_reservation", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11")));
            invariantDependency.put("FRONT_MOVE_1", new HashSet<>(Arrays.asList("_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("BACK_MOVE_1", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("FRONT_MOVE_2", new HashSet<>(Arrays.asList("_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("route_formation", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11")));
            invariantDependency.put("route_freeing", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11")));
            invariantDependency.put("BACK_MOVE_2", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            guardDependency.put("point_positionning", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("route_reservation", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2")));
            guardDependency.put("FRONT_MOVE_1", new HashSet<>(Arrays.asList("_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("BACK_MOVE_1", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("FRONT_MOVE_2", new HashSet<>(Arrays.asList("_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("route_formation", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning")));
            guardDependency.put("route_freeing", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2")));
            guardDependency.put("BACK_MOVE_2", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            Train_1_beebook_deterministic_MC_POR_v2 state = next(collection, lock, type);

            Set<Train_1_beebook_deterministic_MC_POR_v2> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

            nextStates.forEach(nextState -> {
                if(!states.contains(nextState)) {
                    numberStates.getAndIncrement();
                    states.add(nextState);
                    collection.add(nextState);
                    if(numberStates.get() % 50000 == 0) {
                        System.out.println("VISITED STATES: " + numberStates.get());
                        System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                        System.out.println("-------------------");
                    }
                }
            });

            if(nextStates.isEmpty()) {
                deadlockDetected.set(true);
                stopThreads.set(true);
            }

            if(!checkInvariants(state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
                stopThreads.set(true);
            }

        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get());
    }


    private static void modelCheckMultiThreaded(Type type, int threads, boolean isCaching) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();
        ThreadPoolExecutor threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);

        Train_1_beebook_deterministic_MC_POR_v2 machine = new Train_1_beebook_deterministic_MC_POR_v2();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        if(!machine._check_inv_1() || !machine._check_inv_2() || !machine._check_inv_3() || !machine._check_inv_4() || !machine._check_inv_5() || !machine._check_inv_6() || !machine._check_inv_7() || !machine._check_inv_8() || !machine._check_inv_9() || !machine._check_inv_10() || !machine._check_inv_11() || !machine._check_inv_12()) {
            invariantViolated.set(true);
        }

        Set<Train_1_beebook_deterministic_MC_POR_v2> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<Train_1_beebook_deterministic_MC_POR_v2> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentInvariant = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Set<String>> dependentGuard = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, PersistentHashMap> guardCache = new HashMap<>();
        Map<Train_1_beebook_deterministic_MC_POR_v2, Train_1_beebook_deterministic_MC_POR_v2> parents = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("point_positionning", new HashSet<>(Arrays.asList("_check_inv_3", "_check_inv_1", "_check_inv_4")));
            invariantDependency.put("route_reservation", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_8", "_check_inv_12", "_check_inv_9", "_check_inv_11")));
            invariantDependency.put("FRONT_MOVE_1", new HashSet<>(Arrays.asList("_check_inv_6", "_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("BACK_MOVE_1", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("FRONT_MOVE_2", new HashSet<>(Arrays.asList("_check_inv_10", "_check_inv_5", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("route_formation", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_4", "_check_inv_12", "_check_inv_11")));
            invariantDependency.put("route_freeing", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_7", "_check_inv_4", "_check_inv_12", "_check_inv_11")));
            invariantDependency.put("BACK_MOVE_2", new HashSet<>(Arrays.asList("_check_inv_2", "_check_inv_6", "_check_inv_10", "_check_inv_7", "_check_inv_4", "_check_inv_5", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            guardDependency.put("point_positionning", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("route_reservation", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2")));
            guardDependency.put("FRONT_MOVE_1", new HashSet<>(Arrays.asList("_tr_FRONT_MOVE_1", "_tr_BACK_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("BACK_MOVE_1", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("FRONT_MOVE_2", new HashSet<>(Arrays.asList("_tr_FRONT_MOVE_1", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            guardDependency.put("route_formation", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_point_positionning")));
            guardDependency.put("route_freeing", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_BACK_MOVE_2")));
            guardDependency.put("BACK_MOVE_2", new HashSet<>(Arrays.asList("_tr_route_formation", "_tr_FRONT_MOVE_1", "_tr_route_reservation", "_tr_route_freeing", "_tr_BACK_MOVE_1", "_tr_point_positionning", "_tr_FRONT_MOVE_2", "_tr_BACK_MOVE_2")));
            dependentInvariant.put(machine, new HashSet<>());
            parents.put(machine, null);
        }

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            Train_1_beebook_deterministic_MC_POR_v2 state = next(collection, lock, type);
            Runnable task = () -> {
                Set<Train_1_beebook_deterministic_MC_POR_v2> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, transitions);

                nextStates.forEach(nextState -> {
                    synchronized(lock) {
                        if(!states.contains(nextState)) {
                            numberStates.getAndIncrement();
                            states.add(nextState);
                            collection.add(nextState);
                            if(numberStates.get() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + numberStates.get());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    }
                });

                synchronized (lock) {
                    int running = possibleQueueChanges.decrementAndGet();
                    if (!collection.isEmpty() || running == 0) {
                        synchronized (waitLock) {
                            waitLock.notify();
                        }
                    }
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    stopThreads.set(true);
                }

                if(!checkInvariants(state, isCaching, dependentInvariant)) {
                    invariantViolated.set(true);
                    stopThreads.set(true);
                }


            };
            threadPool.submit(task);
            synchronized(waitLock) {
                if (collection.isEmpty() && possibleQueueChanges.get() > 0) {
                    try {
                        waitLock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }

        }
        threadPool.shutdown();
        try {
            threadPool.awaitTermination(5, TimeUnit.SECONDS);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get());
    }


    public static void main(String[] args) {
        if(args.length != 3) {
            System.out.println("Number of arguments errorneous");
            return;
        }
        String strategy = args[0];
        String numberThreads = args[1];
        String caching = args[2];

        Type type;

        if("mixed".equals(strategy)) {
            type = Type.MIXED;
        } else if("bf".equals(strategy)) {
            type = Type.BFS;
        } else if ("df".equals(strategy)) {
            type = Type.DFS;
        } else {
            System.out.println("Input for strategy is wrong.");
            return;
        }

        int threads = 0;
        try {
            threads = Integer.parseInt(numberThreads);
        } catch(NumberFormatException e) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }
        if(threads <= 0) {
            System.out.println("Input for number of threads is wrong.");
            return;
        }

        boolean isCaching = true;
        try {
            isCaching = Boolean.parseBoolean(caching);
        } catch(Exception e) {
            System.out.println("Input for caching is wrong.");
            return;
        }
        if(threads == 1) {
            modelCheckSingleThreaded(type, isCaching);
        } else {
            modelCheckMultiThreaded(type, threads, isCaching);
        }
    }




}
