import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import de.hhu.stups.btypes.BUtils;

public class Train_1_beebook_deterministic {

    private final BRelation<ROUTES, BLOCKS> fst;
    private final BRelation<ROUTES, BLOCKS> lst;
    private final BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>> nxt;
    private final BRelation<BLOCKS, ROUTES> rtbl;


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

    private BSet<BLOCKS> _BLOCKS = new BSet<BLOCKS>(BLOCKS.A, BLOCKS.B, BLOCKS.C, BLOCKS.D, BLOCKS.E, BLOCKS.F, BLOCKS.G, BLOCKS.H, BLOCKS.I, BLOCKS.J, BLOCKS.K, BLOCKS.L, BLOCKS.M, BLOCKS.N);
    private BSet<ROUTES> _ROUTES = new BSet<ROUTES>(ROUTES.R1, ROUTES.R2, ROUTES.R3, ROUTES.R4, ROUTES.R5, ROUTES.R6, ROUTES.R7, ROUTES.R8, ROUTES.R9, ROUTES.R10);

    private BSet<BLOCKS> LBT;
    private BRelation<BLOCKS, BLOCKS> TRK;
    private BSet<ROUTES> frm;
    private BSet<BLOCKS> OCC;
    private BSet<BLOCKS> resbl;
    private BSet<ROUTES> resrt;
    private BRelation<BLOCKS, ROUTES> rsrtbl;

    public Train_1_beebook_deterministic() {
        fst = new BRelation<ROUTES, BLOCKS>(new BTuple<>(ROUTES.R1, BLOCKS.L), new BTuple<>(ROUTES.R2, BLOCKS.L), new BTuple<>(ROUTES.R3, BLOCKS.L), new BTuple<>(ROUTES.R4, BLOCKS.M), new BTuple<>(ROUTES.R5, BLOCKS.M), new BTuple<>(ROUTES.R6, BLOCKS.C), new BTuple<>(ROUTES.R7, BLOCKS.G), new BTuple<>(ROUTES.R8, BLOCKS.N), new BTuple<>(ROUTES.R9, BLOCKS.G), new BTuple<>(ROUTES.R10, BLOCKS.N));
        lst = new BRelation<ROUTES, BLOCKS>(new BTuple<>(ROUTES.R1, BLOCKS.C), new BTuple<>(ROUTES.R2, BLOCKS.G), new BTuple<>(ROUTES.R3, BLOCKS.N), new BTuple<>(ROUTES.R4, BLOCKS.G), new BTuple<>(ROUTES.R5, BLOCKS.N), new BTuple<>(ROUTES.R6, BLOCKS.L), new BTuple<>(ROUTES.R7, BLOCKS.L), new BTuple<>(ROUTES.R8, BLOCKS.L), new BTuple<>(ROUTES.R9, BLOCKS.M), new BTuple<>(ROUTES.R10, BLOCKS.M));
        nxt = new BRelation<ROUTES, BRelation<BLOCKS, BLOCKS>>(new BTuple<>(ROUTES.R1, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.C))), new BTuple<>(ROUTES.R2, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.E), new BTuple<>(BLOCKS.E, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.G))), new BTuple<>(ROUTES.R3, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.L, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.N))), new BTuple<>(ROUTES.R4, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.M, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.G))), new BTuple<>(ROUTES.R5, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.M, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.N))), new BTuple<>(ROUTES.R6, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.C, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R7, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.G, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.E), new BTuple<>(BLOCKS.E, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R8, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.N, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.D), new BTuple<>(BLOCKS.D, BLOCKS.B), new BTuple<>(BLOCKS.B, BLOCKS.A), new BTuple<>(BLOCKS.A, BLOCKS.L))), new BTuple<>(ROUTES.R9, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.G, BLOCKS.F), new BTuple<>(BLOCKS.F, BLOCKS.K), new BTuple<>(BLOCKS.K, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.M))), new BTuple<>(ROUTES.R10, new BRelation<BLOCKS, BLOCKS>(new BTuple<>(BLOCKS.N, BLOCKS.J), new BTuple<>(BLOCKS.J, BLOCKS.I), new BTuple<>(BLOCKS.I, BLOCKS.H), new BTuple<>(BLOCKS.H, BLOCKS.M))));
        BRelation<BLOCKS, ROUTES> _ic_set_0 = new BRelation<>();
        for(BLOCKS _ic_b : _BLOCKS) {
            for(ROUTES _ic_r : _ROUTES) {
                 if((_BLOCKS.elementOf(_ic_b).and(_ROUTES.elementOf(_ic_r)).and(nxt.domain().elementOf(_ic_r).and(nxt.functionCall(_ic_r).domain().elementOf(_ic_b).or(nxt.functionCall(_ic_r).range().elementOf(_ic_b))))).booleanValue()) {
                     _ic_set_0 = _ic_set_0.union(new BRelation<>(new BTuple<>(_ic_b, _ic_r)));
                 }
            }
        }
        rtbl = _ic_set_0;
        resrt = new BSet<ROUTES>();
        resbl = new BSet<BLOCKS>();
        rsrtbl = new BRelation<BLOCKS, ROUTES>();
        OCC = new BSet<BLOCKS>();
        TRK = new BRelation<BLOCKS, BLOCKS>();
        frm = new BSet<ROUTES>();
        LBT = new BSet<BLOCKS>();
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
        BSet<BLOCKS> _ld_OCC = OCC;

        OCC = _ld_OCC.union(new BSet<BLOCKS>(TRK.functionCall(b)));
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
        BRelation<BLOCKS, BLOCKS> _ld_TRK = TRK;
        TRK = _ld_TRK.domainSubstraction(nxt.functionCall(r).domain()).rangeSubstraction(nxt.functionCall(r).range()).union(nxt.functionCall(r));
    }

    public void route_formation(ROUTES r) {
        BSet<ROUTES> _ld_frm = frm;
        frm = _ld_frm.union(new BSet<ROUTES>(r));
    }



}
