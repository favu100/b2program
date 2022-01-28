import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BStruct;
import de.hhu.stups.btypes.BSet;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BObject;
import de.hhu.stups.btypes.BInteger;
import de.hhu.stups.btypes.BBoolean;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.ArrayList;
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


public class nota_v2 {


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


    public static class _Struct1 extends BStruct {
        private BSet<SID> sid;
        private RM_ERROR_CODES err;

        public _Struct1(BSet<SID> sid, RM_ERROR_CODES err) {
            this.sid = sid;
            this.err = err;
        }

        public BSet<SID> get_sid() {
            return this.sid;
        }

        public RM_ERROR_CODES get_err() {
            return this.err;
        }

        public _Struct1 override_sid(BSet<SID> sid) {
            return new _Struct1(sid, err);
        }

        public _Struct1 override_err(RM_ERROR_CODES err) {
            return new _Struct1(sid, err);
        }

        public BBoolean equal(_Struct1 o) {
            return new BBoolean(this.sid == o.sid && this.err == o.err);
        }

        public BBoolean unequal(_Struct1 o) {
            return new BBoolean(this.sid != o.sid || this.err != o.err);
        }

        public String toString() {
            return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct1)) {
                return false;
            }
            _Struct1 o = (_Struct1) other;
            return this.sid == o.sid && this.err == o.err;
        }

        public int hashCode() {
            return Objects.hash(sid, err);
        }
    }

    public static class _Struct5 extends BStruct {
        private BSet<SOCKET> soc;
        private IN_ERROR_CODES err;

        public _Struct5(BSet<SOCKET> soc, IN_ERROR_CODES err) {
            this.soc = soc;
            this.err = err;
        }

        public BSet<SOCKET> get_soc() {
            return this.soc;
        }

        public IN_ERROR_CODES get_err() {
            return this.err;
        }

        public _Struct5 override_soc(BSet<SOCKET> soc) {
            return new _Struct5(soc, err);
        }

        public _Struct5 override_err(IN_ERROR_CODES err) {
            return new _Struct5(soc, err);
        }

        public BBoolean equal(_Struct5 o) {
            return new BBoolean(this.soc == o.soc && this.err == o.err);
        }

        public BBoolean unequal(_Struct5 o) {
            return new BBoolean(this.soc != o.soc || this.err != o.err);
        }

        public String toString() {
            return "(" + "soc : " + this.soc + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct5)) {
                return false;
            }
            _Struct5 o = (_Struct5) other;
            return this.soc == o.soc && this.err == o.err;
        }

        public int hashCode() {
            return Objects.hash(soc, err);
        }
    }

    public static class _Struct3 extends BStruct {
        private BSet<SID> sid;
        private IN_ERROR_CODES err;

        public _Struct3(BSet<SID> sid, IN_ERROR_CODES err) {
            this.sid = sid;
            this.err = err;
        }

        public BSet<SID> get_sid() {
            return this.sid;
        }

        public IN_ERROR_CODES get_err() {
            return this.err;
        }

        public _Struct3 override_sid(BSet<SID> sid) {
            return new _Struct3(sid, err);
        }

        public _Struct3 override_err(IN_ERROR_CODES err) {
            return new _Struct3(sid, err);
        }

        public BBoolean equal(_Struct3 o) {
            return new BBoolean(this.sid == o.sid && this.err == o.err);
        }

        public BBoolean unequal(_Struct3 o) {
            return new BBoolean(this.sid != o.sid || this.err != o.err);
        }

        public String toString() {
            return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct3)) {
                return false;
            }
            _Struct3 o = (_Struct3) other;
            return this.sid == o.sid && this.err == o.err;
        }

        public int hashCode() {
            return Objects.hash(sid, err);
        }
    }



    public enum INTERCONNECTNODE implements BObject {
        node1, 
        node2;

        public BBoolean equal(INTERCONNECTNODE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(INTERCONNECTNODE o) {
            return new BBoolean(this != o);
        }
    }

    public enum SOCKET implements BObject {
        socket1, 
        socket2;

        public BBoolean equal(SOCKET o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(SOCKET o) {
            return new BBoolean(this != o);
        }
    }

    public enum SERVICE implements BObject {
        service1, 
        service2;

        public BBoolean equal(SERVICE o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(SERVICE o) {
            return new BBoolean(this != o);
        }
    }

    public enum RESOURCEMANAGER implements BObject {
        resource1, 
        resource2;

        public BBoolean equal(RESOURCEMANAGER o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(RESOURCEMANAGER o) {
            return new BBoolean(this != o);
        }
    }

    public enum SID implements BObject {
        SID1, 
        SID2;

        public BBoolean equal(SID o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(SID o) {
            return new BBoolean(this != o);
        }
    }

    public enum RM_ERROR_CODES implements BObject {
        RM_SERVICE_FOUND, 
        RM_SERVICE_NOT_FOUND;

        public BBoolean equal(RM_ERROR_CODES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(RM_ERROR_CODES o) {
            return new BBoolean(this != o);
        }
    }

    public enum IN_ERROR_CODES implements BObject {
        IN_REGISTRATION_OK, 
        IN_REGISTRATION_FAILED, 
        IN_DEREGISTRATION_OK, 
        IN_DEREGISTRATION_FAILED, 
        IN_NO_SOCKET_CONNECTION, 
        IN_SOCKET_CONNECTION_OK, 
        IN_NO_AVAILABLE_SERVICE, 
        IN_SERVICE_AVAILABLE, 
        IN_TARGET_SOCKET_GRANTED, 
        IN_TARGET_SOCKET_NOT_GRANTED;

        public BBoolean equal(IN_ERROR_CODES o) {
            return new BBoolean(this == o);
        }

        public BBoolean unequal(IN_ERROR_CODES o) {
            return new BBoolean(this != o);
        }
    }

    private static BSet<INTERCONNECTNODE> _INTERCONNECTNODE = new BSet<INTERCONNECTNODE>(INTERCONNECTNODE.node1, INTERCONNECTNODE.node2);
    private static BSet<SOCKET> _SOCKET = new BSet<SOCKET>(SOCKET.socket1, SOCKET.socket2);
    private static BSet<SERVICE> _SERVICE = new BSet<SERVICE>(SERVICE.service1, SERVICE.service2);
    private static BSet<RESOURCEMANAGER> _RESOURCEMANAGER = new BSet<RESOURCEMANAGER>(RESOURCEMANAGER.resource1, RESOURCEMANAGER.resource2);
    private static BSet<SID> _SID = new BSet<SID>(SID.SID1, SID.SID2);
    private static BSet<RM_ERROR_CODES> _RM_ERROR_CODES = new BSet<RM_ERROR_CODES>(RM_ERROR_CODES.RM_SERVICE_FOUND, RM_ERROR_CODES.RM_SERVICE_NOT_FOUND);
    private static BSet<IN_ERROR_CODES> _IN_ERROR_CODES = new BSet<IN_ERROR_CODES>(IN_ERROR_CODES.IN_REGISTRATION_OK, IN_ERROR_CODES.IN_REGISTRATION_FAILED, IN_ERROR_CODES.IN_DEREGISTRATION_OK, IN_ERROR_CODES.IN_DEREGISTRATION_FAILED, IN_ERROR_CODES.IN_NO_SOCKET_CONNECTION, IN_ERROR_CODES.IN_SOCKET_CONNECTION_OK, IN_ERROR_CODES.IN_NO_AVAILABLE_SERVICE, IN_ERROR_CODES.IN_SERVICE_AVAILABLE, IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED, IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED);

    private BSet<INTERCONNECTNODE> interconnectNodes;
    private BSet<SOCKET> sockets;
    private BSet<SERVICE> services;
    private BSet<RESOURCEMANAGER> resourceManagers;
    private BSet<SID> sids;
    private BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;
    private BRelation<SERVICE, SID> rm_sids;
    private BRelation<SID, INTERCONNECTNODE> in_localServices;
    private BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
    private BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;
    private BRelation<SOCKET, SID> soc_to;
    private BRelation<SOCKET, SID> soc_from;
    private BRelation<SERVICE, SID> svc_serviceID;
    private BRelation<SERVICE, BSet<SOCKET>> svc_sockets;
    private BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode;
    private BRelation<SERVICE, BBoolean> svc_registered;

    public nota_v2() {
        interconnectNodes = new BSet<INTERCONNECTNODE>();
        sockets = new BSet<SOCKET>();
        services = new BSet<SERVICE>();
        resourceManagers = new BSet<RESOURCEMANAGER>();
        sids = new BSet<SID>();
        rm_services = new BRelation<RESOURCEMANAGER, BSet<SERVICE>>();
        rm_sids = new BRelation<SERVICE, SID>();
        in_localServices = new BRelation<SID, INTERCONNECTNODE>();
        in_sockets = new BRelation<SOCKET, INTERCONNECTNODE>();
        in_resourceManager = new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>();
        soc_to = new BRelation<SOCKET, SID>();
        soc_from = new BRelation<SOCKET, SID>();
        svc_serviceID = new BRelation<SERVICE, SID>();
        svc_sockets = new BRelation<SERVICE, BSet<SOCKET>>();
        svc_ICNode = new BRelation<SERVICE, INTERCONNECTNODE>();
        svc_registered = new BRelation<SERVICE, BBoolean>();
    }

    public nota_v2(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SOCKET> sockets, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers, BSet<SID> sids, BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services, BRelation<SERVICE, SID> rm_sids, BRelation<SID, INTERCONNECTNODE> in_localServices, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager, BRelation<SOCKET, SID> soc_to, BRelation<SOCKET, SID> soc_from, BRelation<SERVICE, SID> svc_serviceID, BRelation<SERVICE, BSet<SOCKET>> svc_sockets, BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode, BRelation<SERVICE, BBoolean> svc_registered) {
        this.interconnectNodes = interconnectNodes;
        this.sockets = sockets;
        this.services = services;
        this.resourceManagers = resourceManagers;
        this.sids = sids;
        this.rm_services = rm_services;
        this.rm_sids = rm_sids;
        this.in_localServices = in_localServices;
        this.in_sockets = in_sockets;
        this.in_resourceManager = in_resourceManager;
        this.soc_to = soc_to;
        this.soc_from = soc_from;
        this.svc_serviceID = svc_serviceID;
        this.svc_sockets = svc_sockets;
        this.svc_ICNode = svc_ICNode;
        this.svc_registered = svc_registered;
    }

    public INTERCONNECTNODE constructor_interconnectNode(INTERCONNECTNODE newic) {
        INTERCONNECTNODE oid = null;
        BSet<INTERCONNECTNODE> _ld_interconnectNodes = interconnectNodes;
        interconnectNodes = _ld_interconnectNodes.union(new BSet<INTERCONNECTNODE>(newic));
        in_resourceManager = in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(newic,new BSet<RESOURCEMANAGER>())));
        oid = newic;

        return oid;
    }

    public RESOURCEMANAGER constructor_resourceManager(RESOURCEMANAGER newrm) {
        RESOURCEMANAGER oid = null;
        BSet<RESOURCEMANAGER> _ld_resourceManagers = resourceManagers;
        resourceManagers = _ld_resourceManagers.union(new BSet<RESOURCEMANAGER>(newrm));
        rm_services = rm_services.override(new BRelation<RESOURCEMANAGER, BSet<SERVICE>>(new BTuple<RESOURCEMANAGER, BSet<SERVICE>>(newrm,new BSet<SERVICE>())));
        oid = newrm;

        return oid;
    }

    public SERVICE constructor_service(INTERCONNECTNODE ii, SERVICE newsvc) {
        SERVICE oid = null;
        BSet<SERVICE> _ld_services = services;
        services = _ld_services.union(new BSet<SERVICE>(newsvc));
        svc_registered = svc_registered.override(new BRelation<SERVICE, BBoolean>(new BTuple<SERVICE, BBoolean>(newsvc,new BBoolean(false))));
        svc_sockets = svc_sockets.override(new BRelation<SERVICE, BSet<SOCKET>>(new BTuple<SERVICE, BSet<SOCKET>>(newsvc,new BSet<SOCKET>())));
        svc_ICNode = svc_ICNode.override(new BRelation<SERVICE, INTERCONNECTNODE>(new BTuple<SERVICE, INTERCONNECTNODE>(newsvc,ii)));
        svc_serviceID = new BRelation<SERVICE, SID>();
        oid = newsvc;

        return oid;
    }

    public SOCKET constructor_socket(INTERCONNECTNODE ii, SID srcsid, SID targsid, SOCKET newsoc) {
        SOCKET oid = null;
        BSet<SOCKET> _ld_sockets = sockets;
        sockets = _ld_sockets.union(new BSet<SOCKET>(newsoc));
        oid = newsoc;
        in_sockets = in_sockets.override(new BRelation<SOCKET, INTERCONNECTNODE>(new BTuple<SOCKET, INTERCONNECTNODE>(newsoc,ii)));
        soc_to = soc_to.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,srcsid)));
        soc_from = soc_from.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,targsid)));

        return oid;
    }

    public void rm_register(RESOURCEMANAGER self, SERVICE ss, INTERCONNECTNODE ii) {
    }

    public void rm_deregister(RESOURCEMANAGER self, SERVICE ss, INTERCONNECTNODE ii) {
    }

    public _Struct1 rm_getSid(RESOURCEMANAGER self, SERVICE ss) {
        BSet<SID> sid = null;
        RM_ERROR_CODES err = null;
        err = RM_ERROR_CODES.RM_SERVICE_FOUND;
        sid = new BSet<SID>(rm_sids.functionCall(ss));

        return new _Struct1(sid, err);
    }

    public _Struct1 rm_getSid_Not_Found(RESOURCEMANAGER self, SERVICE ss) {
        BSet<SID> sid = null;
        RM_ERROR_CODES err = null;
        sid = _SID.difference(_SID);
        err = RM_ERROR_CODES.RM_SERVICE_NOT_FOUND;

        return new _Struct1(sid, err);
    }

    public void in_announceResourceManager(INTERCONNECTNODE self, RESOURCEMANAGER rm) {
        in_resourceManager = in_resourceManager.override(new BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER>>(self,in_resourceManager.functionCall(self).union(new BSet<RESOURCEMANAGER>(rm)))));

    }

    public _Struct3 in_register_success(INTERCONNECTNODE self, SERVICE ss, SID si) {
        BSet<SID> sid = null;
        IN_ERROR_CODES err = null;
        BRelation<SID, INTERCONNECTNODE> _ld_in_localServices = in_localServices;
        BSet<SID> _ld_sids = sids;
        sids = _ld_sids.union(new BSet<SID>(si));
        in_localServices = _ld_in_localServices.union(new BRelation<SID, INTERCONNECTNODE>(new BTuple<>(si, self)));
        err = IN_ERROR_CODES.IN_REGISTRATION_OK;
        sid = new BSet<SID>(si);

        return new _Struct3(sid, err);
    }

    public _Struct3 in_register_failed(INTERCONNECTNODE self, SERVICE ss) {
        BSet<SID> sid = null;
        IN_ERROR_CODES err = null;
        sid = _SID.difference(_SID);
        err = IN_ERROR_CODES.IN_REGISTRATION_FAILED;

        return new _Struct3(sid, err);
    }

    public _Struct5 in_requestTargetSocket_Granted(INTERCONNECTNODE self, INTERCONNECTNODE ii, SOCKET srcsoc, SID srcsid, SID targsid, SOCKET newsoc) {
        BSet<SOCKET> soc = null;
        IN_ERROR_CODES err = null;
        BSet<SOCKET> _ld_sockets = sockets;
        BRelation<SOCKET, INTERCONNECTNODE> _ld_in_sockets = in_sockets;
        sockets = _ld_sockets.union(new BSet<SOCKET>(newsoc));
        soc = new BSet<SOCKET>(newsoc);
        err = IN_ERROR_CODES.IN_TARGET_SOCKET_GRANTED;
        in_sockets = _ld_in_sockets.union(new BRelation<SOCKET, INTERCONNECTNODE>(new BTuple<>(newsoc, self)));
        soc_to = soc_to.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,srcsid)));
        soc_from = soc_from.override(new BRelation<SOCKET, SID>(new BTuple<SOCKET, SID>(newsoc,targsid)));

        return new _Struct5(soc, err);
    }

    public _Struct5 in_requestTargetSocket_NotGranted(INTERCONNECTNODE self, INTERCONNECTNODE ii, SOCKET srcsoc, SID srcsid, SID targsid) {
        BSet<SOCKET> soc = null;
        IN_ERROR_CODES err = null;
        soc = _SOCKET.difference(_SOCKET);
        err = IN_ERROR_CODES.IN_TARGET_SOCKET_NOT_GRANTED;

        return new _Struct5(soc, err);
    }

    public void svc_register(SERVICE self) {
        svc_registered = svc_registered.override(new BRelation<SERVICE, BBoolean>(new BTuple<SERVICE, BBoolean>(self,new BBoolean(true))));

    }

    public BSet<INTERCONNECTNODE> _get_interconnectNodes() {
        return interconnectNodes;
    }

    public BSet<SOCKET> _get_sockets() {
        return sockets;
    }

    public BSet<SERVICE> _get_services() {
        return services;
    }

    public BSet<RESOURCEMANAGER> _get_resourceManagers() {
        return resourceManagers;
    }

    public BSet<SID> _get_sids() {
        return sids;
    }

    public BRelation<RESOURCEMANAGER, BSet<SERVICE>> _get_rm_services() {
        return rm_services;
    }

    public BRelation<SERVICE, SID> _get_rm_sids() {
        return rm_sids;
    }

    public BRelation<SID, INTERCONNECTNODE> _get_in_localServices() {
        return in_localServices;
    }

    public BRelation<SOCKET, INTERCONNECTNODE> _get_in_sockets() {
        return in_sockets;
    }

    public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> _get_in_resourceManager() {
        return in_resourceManager;
    }

    public BRelation<SOCKET, SID> _get_soc_to() {
        return soc_to;
    }

    public BRelation<SOCKET, SID> _get_soc_from() {
        return soc_from;
    }

    public BRelation<SERVICE, SID> _get_svc_serviceID() {
        return svc_serviceID;
    }

    public BRelation<SERVICE, BSet<SOCKET>> _get_svc_sockets() {
        return svc_sockets;
    }

    public BRelation<SERVICE, INTERCONNECTNODE> _get_svc_ICNode() {
        return svc_ICNode;
    }

    public BRelation<SERVICE, BBoolean> _get_svc_registered() {
        return svc_registered;
    }

    public BSet<INTERCONNECTNODE> _get__INTERCONNECTNODE() {
        return _INTERCONNECTNODE;
    }

    public BSet<SOCKET> _get__SOCKET() {
        return _SOCKET;
    }

    public BSet<SERVICE> _get__SERVICE() {
        return _SERVICE;
    }

    public BSet<RESOURCEMANAGER> _get__RESOURCEMANAGER() {
        return _RESOURCEMANAGER;
    }

    public BSet<SID> _get__SID() {
        return _SID;
    }

    public BSet<RM_ERROR_CODES> _get__RM_ERROR_CODES() {
        return _RM_ERROR_CODES;
    }

    public BSet<IN_ERROR_CODES> _get__IN_ERROR_CODES() {
        return _IN_ERROR_CODES;
    }


    public BSet<INTERCONNECTNODE> _tr_constructor_interconnectNode() {
        BSet<INTERCONNECTNODE> _ic_set_0 = new BSet<INTERCONNECTNODE>();
        for(INTERCONNECTNODE _ic_newic_1 : _INTERCONNECTNODE.difference(interconnectNodes)) {
            _ic_set_0 = _ic_set_0.union(new BSet<INTERCONNECTNODE>(_ic_newic_1));

        }
        return _ic_set_0;
    }

    public BSet<RESOURCEMANAGER> _tr_constructor_resourceManager() {
        BSet<RESOURCEMANAGER> _ic_set_1 = new BSet<RESOURCEMANAGER>();
        for(RESOURCEMANAGER _ic_newrm_1 : _RESOURCEMANAGER.difference(resourceManagers)) {
            if((new BBoolean(rm_services.domain().notElementOf(_ic_newrm_1).booleanValue() && resourceManagers.equal(new BSet<RESOURCEMANAGER>()).booleanValue())).booleanValue()) {
                _ic_set_1 = _ic_set_1.union(new BSet<RESOURCEMANAGER>(_ic_newrm_1));
            }

        }
        return _ic_set_1;
    }

    public BSet<BTuple<INTERCONNECTNODE, SERVICE>> _tr_constructor_service() {
        BSet<BTuple<INTERCONNECTNODE, SERVICE>> _ic_set_2 = new BSet<BTuple<INTERCONNECTNODE, SERVICE>>();
        for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
            for(SERVICE _ic_newsvc_1 : _SERVICE.difference(services)) {
                _ic_set_2 = _ic_set_2.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple<>(_ic_ii_1, _ic_newsvc_1)));

            }
        }
        return _ic_set_2;
    }

    public BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> _tr_constructor_socket() {
        BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> _ic_set_3 = new BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>();
        for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
            for(SID _ic_srcsid_1 : sids) {
                for(SID _ic_targsid_1 : sids) {
                    for(SOCKET _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                        _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>(new BTuple<>(new BTuple<>(new BTuple<>(_ic_ii_1, _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));

                    }
                }
            }
        }
        return _ic_set_3;
    }

    public BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _tr_rm_register() {
        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _ic_set_4 = new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                    _ic_set_4 = _ic_set_4.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple<>(new BTuple<>(_ic_self_1, _ic_ss_1), _ic_ii_1)));

                }
            }
        }
        return _ic_set_4;
    }

    public BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _tr_rm_deregister() {
        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _ic_set_5 = new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple<>(new BTuple<>(_ic_self_1, _ic_ss_1), _ic_ii_1)));

                }
            }
        }
        return _ic_set_5;
    }

    public BSet<BTuple<RESOURCEMANAGER, SERVICE>> _tr_rm_getSid() {
        BSet<BTuple<RESOURCEMANAGER, SERVICE>> _ic_set_6 = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                if((rm_sids.domain().elementOf(_ic_ss_1)).booleanValue()) {
                    _ic_set_6 = _ic_set_6.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple<>(_ic_self_1, _ic_ss_1)));
                }

            }
        }
        return _ic_set_6;
    }

    public BSet<BTuple<RESOURCEMANAGER, SERVICE>> _tr_rm_getSid_Not_Found() {
        BSet<BTuple<RESOURCEMANAGER, SERVICE>> _ic_set_7 = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                _ic_set_7 = _ic_set_7.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple<>(_ic_self_1, _ic_ss_1)));

            }
        }
        return _ic_set_7;
    }

    public BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _tr_in_announceResourceManager() {
        BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _ic_set_8 = new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(RESOURCEMANAGER _ic_rm_1 : resourceManagers) {
                if((in_resourceManager.functionCall(_ic_self_1).equal(new BSet<RESOURCEMANAGER>())).booleanValue()) {
                    _ic_set_8 = _ic_set_8.union(new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>(new BTuple<>(_ic_self_1, _ic_rm_1)));
                }

            }
        }
        return _ic_set_8;
    }

    public BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> _tr_in_register_success() {
        BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> _ic_set_9 = new BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(SERVICE _ic_ss_1 : services) {
                for(SID _ic_si_1 : _SID.difference(sids)) {
                    if((in_localServices.domain().elementOf(_ic_si_1).not()).booleanValue()) {
                        _ic_set_9 = _ic_set_9.union(new BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>(new BTuple<>(new BTuple<>(_ic_self_1, _ic_ss_1), _ic_si_1)));
                    }

                }
            }
        }
        return _ic_set_9;
    }

    public BSet<BTuple<INTERCONNECTNODE, SERVICE>> _tr_in_register_failed() {
        BSet<BTuple<INTERCONNECTNODE, SERVICE>> _ic_set_10 = new BSet<BTuple<INTERCONNECTNODE, SERVICE>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(SERVICE _ic_ss_1 : services) {
                _ic_set_10 = _ic_set_10.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple<>(_ic_self_1, _ic_ss_1)));

            }
        }
        return _ic_set_10;
    }

    public BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _tr_in_requestTargetSocket_Granted() {
        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _ic_set_11 = new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                for(SOCKET _ic_srcsoc_1 : sockets) {
                    for(SID _ic_srcsid_1 : sids) {
                        for(SID _ic_targsid_1 : sids) {
                            for(SOCKET _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                                if((new BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue())).booleanValue()) {
                                    _ic_set_11 = _ic_set_11.union(new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>(new BTuple<>(new BTuple<>(new BTuple<>(new BTuple<>(new BTuple<>(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));
                                }

                            }
                        }
                    }
                }
            }
        }
        return _ic_set_11;
    }

    public BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> _tr_in_requestTargetSocket_NotGranted() {
        BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> _ic_set_12 = new BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                for(SOCKET _ic_srcsoc_1 : sockets) {
                    for(SID _ic_srcsid_1 : sids) {
                        for(SID _ic_targsid_1 : sids) {
                            if((new BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue())).booleanValue()) {
                                _ic_set_12 = _ic_set_12.union(new BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>(new BTuple<>(new BTuple<>(new BTuple<>(new BTuple<>(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1)));
                            }

                        }
                    }
                }
            }
        }
        return _ic_set_12;
    }

    public BSet<SERVICE> _tr_svc_register() {
        BSet<SERVICE> _ic_set_13 = new BSet<SERVICE>();
        for(SERVICE _ic_self_1 : services) {
            if((svc_registered.functionCall(_ic_self_1).equal(new BBoolean(false))).booleanValue()) {
                _ic_set_13 = _ic_set_13.union(new BSet<SERVICE>(_ic_self_1));
            }

        }
        return _ic_set_13;
    }

    public boolean _check_inv_1() {
        return interconnectNodes.subset(_INTERCONNECTNODE).booleanValue();
    }

    public boolean _check_inv_2() {
        return sockets.subset(_SOCKET).booleanValue();
    }

    public boolean _check_inv_3() {
        return services.subset(_SERVICE).booleanValue();
    }

    public boolean _check_inv_4() {
        return resourceManagers.subset(_RESOURCEMANAGER).booleanValue();
    }

    public boolean _check_inv_5() {
        return sids.subset(_SID).booleanValue();
    }

    public boolean _check_inv_6() {
        return rm_services.checkDomain(resourceManagers).and(rm_services.checkRange(services.pow())).and(rm_services.isFunction()).and(rm_services.isTotal(resourceManagers)).booleanValue();
    }

    public boolean _check_inv_7() {
        BBoolean _ic_boolean_14 = new BBoolean(true);
        for(RESOURCEMANAGER _ic_a1_1 : rm_services.domain()) {
            for(RESOURCEMANAGER _ic_a2_1 : rm_services.domain()) {
                if(!(new BBoolean(!_ic_a1_1.unequal(_ic_a2_1).booleanValue() || rm_services.functionCall(_ic_a1_1).intersect(rm_services.functionCall(_ic_a2_1)).equal(new BSet<SERVICE>()).booleanValue())).booleanValue()) {
                    _ic_boolean_14 = new BBoolean(false);
                    break;
                }

            }
        }

        return _ic_boolean_14.booleanValue();
    }

    public boolean _check_inv_8() {
        return rm_sids.checkDomain(services).and(rm_sids.checkRange(sids)).and(rm_sids.isFunction()).and(rm_sids.isPartial(services)).and(rm_sids.isInjection()).booleanValue();
    }

    public boolean _check_inv_9() {
        return in_localServices.checkDomain(sids).and(in_localServices.checkRange(interconnectNodes)).and(in_localServices.isFunction()).and(in_localServices.isTotal(sids)).booleanValue();
    }

    public boolean _check_inv_10() {
        return in_sockets.checkDomain(sockets).and(in_sockets.checkRange(interconnectNodes)).and(in_sockets.isFunction()).and(in_sockets.isTotal(sockets)).booleanValue();
    }

    public boolean _check_inv_11() {
        return in_resourceManager.checkDomain(interconnectNodes).and(in_resourceManager.checkRange(resourceManagers.pow())).and(in_resourceManager.isFunction()).and(in_resourceManager.isTotal(interconnectNodes)).booleanValue();
    }

    public boolean _check_inv_12() {
        return soc_to.checkDomain(sockets).and(soc_to.checkRange(sids)).and(soc_to.isFunction()).and(soc_to.isTotal(sockets)).booleanValue();
    }

    public boolean _check_inv_13() {
        return soc_from.checkDomain(sockets).and(soc_from.checkRange(sids)).and(soc_from.isFunction()).and(soc_from.isTotal(sockets)).booleanValue();
    }

    public boolean _check_inv_14() {
        return svc_serviceID.checkDomain(services).and(svc_serviceID.checkRange(sids)).and(svc_serviceID.isFunction()).and(svc_serviceID.isPartial(services)).booleanValue();
    }

    public boolean _check_inv_15() {
        return svc_sockets.checkDomain(services).and(svc_sockets.checkRange(sockets.pow())).and(svc_sockets.isFunction()).and(svc_sockets.isTotal(services)).booleanValue();
    }

    public boolean _check_inv_16() {
        return svc_ICNode.checkDomain(services).and(svc_ICNode.checkRange(interconnectNodes)).and(svc_ICNode.isFunction()).and(svc_ICNode.isTotal(services)).booleanValue();
    }

    public boolean _check_inv_17() {
        return svc_registered.checkDomain(services).and(svc_registered.checkRange(BUtils.BOOL)).and(svc_registered.isFunction()).and(svc_registered.isTotal(services)).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(!resourceManagers.equal(new BSet<RESOURCEMANAGER>()).not().booleanValue() || resourceManagers.card().equal(new BInteger(1)).booleanValue()).booleanValue();
    }

    public nota_v2 _copy() {
        return new nota_v2(interconnectNodes, sockets, services, resourceManagers, sids, rm_services, rm_sids, in_localServices, in_sockets, in_resourceManager, soc_to, soc_from, svc_serviceID, svc_sockets, svc_ICNode, svc_registered);
    }

    @Override
    public boolean equals(Object o) {
        nota_v2 o1 = this;
        nota_v2 o2 = (nota_v2) o;
        return o1._get_interconnectNodes().equals(o2._get_interconnectNodes()) && o1._get_sockets().equals(o2._get_sockets()) && o1._get_services().equals(o2._get_services()) && o1._get_resourceManagers().equals(o2._get_resourceManagers()) && o1._get_sids().equals(o2._get_sids()) && o1._get_rm_services().equals(o2._get_rm_services()) && o1._get_rm_sids().equals(o2._get_rm_sids()) && o1._get_in_localServices().equals(o2._get_in_localServices()) && o1._get_in_sockets().equals(o2._get_in_sockets()) && o1._get_in_resourceManager().equals(o2._get_in_resourceManager()) && o1._get_soc_to().equals(o2._get_soc_to()) && o1._get_soc_from().equals(o2._get_soc_from()) && o1._get_svc_serviceID().equals(o2._get_svc_serviceID()) && o1._get_svc_sockets().equals(o2._get_svc_sockets()) && o1._get_svc_ICNode().equals(o2._get_svc_ICNode()) && o1._get_svc_registered().equals(o2._get_svc_registered());
    }



    @Override
    public int hashCode() {
        return this._hashCode_1();
    }

    public int _hashCode_1() {
        int result = 1;
        result = (1543 * result) ^ ((this._get_interconnectNodes()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_services()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_resourceManagers()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_sids()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rm_services()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_rm_sids()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_localServices()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_in_resourceManager()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_soc_to()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_soc_from()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_serviceID()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_sockets()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_ICNode()).hashCode() << 1);
        result = (1543 * result) ^ ((this._get_svc_registered()).hashCode() << 1);
        return result;
    }

    public int _hashCode_2() {
        int result = 1;
        result = (6151 * result) ^ ((this._get_interconnectNodes()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_services()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_resourceManagers()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_sids()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rm_services()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_rm_sids()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_localServices()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_in_resourceManager()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_soc_to()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_soc_from()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_serviceID()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_sockets()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_ICNode()).hashCode() << 1);
        result = (6151 * result) ^ ((this._get_svc_registered()).hashCode() << 1);
        return result;
    }

    @Override
    public String toString() {
        return String.join("\n", "_get_interconnectNodes: " + (this._get_interconnectNodes()).toString(), "_get_sockets: " + (this._get_sockets()).toString(), "_get_services: " + (this._get_services()).toString(), "_get_resourceManagers: " + (this._get_resourceManagers()).toString(), "_get_sids: " + (this._get_sids()).toString(), "_get_rm_services: " + (this._get_rm_services()).toString(), "_get_rm_sids: " + (this._get_rm_sids()).toString(), "_get_in_localServices: " + (this._get_in_localServices()).toString(), "_get_in_sockets: " + (this._get_in_sockets()).toString(), "_get_in_resourceManager: " + (this._get_in_resourceManager()).toString(), "_get_soc_to: " + (this._get_soc_to()).toString(), "_get_soc_from: " + (this._get_soc_from()).toString(), "_get_svc_serviceID: " + (this._get_svc_serviceID()).toString(), "_get_svc_sockets: " + (this._get_svc_sockets()).toString(), "_get_svc_ICNode: " + (this._get_svc_ICNode()).toString(), "_get_svc_registered: " + (this._get_svc_registered()).toString());
    }

    @SuppressWarnings("unchecked")
    private static Set<nota_v2> generateNextStates(Object guardLock, nota_v2 state, boolean isCaching, Map<String, Set<String>> invariantDependency, Map<nota_v2, Set<String>> dependentInvariant, Map<String, Set<String>> guardDependency, Map<nota_v2, Set<String>> dependentGuard, Map<nota_v2, PersistentHashMap> guardCache, Map<nota_v2, nota_v2> parents, Map<nota_v2, String> stateAccessedVia, AtomicInteger transitions) {
        Set<nota_v2> result = new HashSet<>();
        if(isCaching) {
            PersistentHashMap parentsGuard = guardCache.get(parents.get(state));
            PersistentHashMap newCache = parentsGuard == null ? PersistentHashMap.EMPTY : parentsGuard;
            Set<String> dependentGuardsOfState = dependentGuard.get(state);
            Object cachedValue = null;
            boolean dependentGuardsBoolean = true;
            BSet<INTERCONNECTNODE> _trid_1;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_constructor_interconnectNode");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_constructor_interconnectNode");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_1 = state._tr_constructor_interconnectNode();
            } else {
                _trid_1 = (BSet<INTERCONNECTNODE>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_constructor_interconnectNode", _trid_1);
            for(INTERCONNECTNODE param : _trid_1) {
                INTERCONNECTNODE _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.constructor_interconnectNode(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("constructor_interconnectNode"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("constructor_interconnectNode"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_interconnectNode");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<RESOURCEMANAGER> _trid_2;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_constructor_resourceManager");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_constructor_resourceManager");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_2 = state._tr_constructor_resourceManager();
            } else {
                _trid_2 = (BSet<RESOURCEMANAGER>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_constructor_resourceManager", _trid_2);
            for(RESOURCEMANAGER param : _trid_2) {
                RESOURCEMANAGER _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.constructor_resourceManager(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("constructor_resourceManager"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("constructor_resourceManager"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_resourceManager");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_3;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_constructor_service");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_constructor_service");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_3 = state._tr_constructor_service();
            } else {
                _trid_3 = (BSet<BTuple<INTERCONNECTNODE, SERVICE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_constructor_service", _trid_3);
            for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_3) {
                SERVICE _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.constructor_service(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("constructor_service"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("constructor_service"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_service");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> _trid_4;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_constructor_socket");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_constructor_socket");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_4 = state._tr_constructor_socket();
            } else {
                _trid_4 = (BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_constructor_socket", _trid_4);
            for(BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET> param : _trid_4) {
                SOCKET _tmp_1 = param.projection2();
                BTuple<BTuple<INTERCONNECTNODE, SID>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<INTERCONNECTNODE, SID> _tmp_4 = _tmp_2.projection1();
                SID _tmp_5 = _tmp_4.projection2();
                INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("constructor_socket"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("constructor_socket"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_socket");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_5;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_rm_register");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_rm_register");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_5 = state._tr_rm_register();
            } else {
                _trid_5 = (BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_rm_register", _trid_5);
            for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_5) {
                INTERCONNECTNODE _tmp_1 = param.projection2();
                BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("rm_register"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("rm_register"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_register");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_6;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_rm_deregister");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_rm_deregister");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_6 = state._tr_rm_deregister();
            } else {
                _trid_6 = (BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_rm_deregister", _trid_6);
            for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_6) {
                INTERCONNECTNODE _tmp_1 = param.projection2();
                BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("rm_deregister"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("rm_deregister"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_deregister");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_7;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_rm_getSid");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_rm_getSid");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_7 = state._tr_rm_getSid();
            } else {
                _trid_7 = (BSet<BTuple<RESOURCEMANAGER, SERVICE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_rm_getSid", _trid_7);
            for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_7) {
                SERVICE _tmp_1 = param.projection2();
                RESOURCEMANAGER _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_getSid(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("rm_getSid"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("rm_getSid"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_getSid");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_8;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_rm_getSid_Not_Found");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_rm_getSid_Not_Found");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_8 = state._tr_rm_getSid_Not_Found();
            } else {
                _trid_8 = (BSet<BTuple<RESOURCEMANAGER, SERVICE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_rm_getSid_Not_Found", _trid_8);
            for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_8) {
                SERVICE _tmp_1 = param.projection2();
                RESOURCEMANAGER _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("rm_getSid_Not_Found"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("rm_getSid_Not_Found"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_getSid_Not_Found");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _trid_9;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_in_announceResourceManager");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_in_announceResourceManager");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_9 = state._tr_in_announceResourceManager();
            } else {
                _trid_9 = (BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_in_announceResourceManager", _trid_9);
            for(BTuple<INTERCONNECTNODE, RESOURCEMANAGER> param : _trid_9) {
                RESOURCEMANAGER _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("in_announceResourceManager"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("in_announceResourceManager"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_announceResourceManager");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> _trid_10;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_in_register_success");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_in_register_success");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_10 = state._tr_in_register_success();
            } else {
                _trid_10 = (BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_in_register_success", _trid_10);
            for(BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID> param : _trid_10) {
                SID _tmp_1 = param.projection2();
                BTuple<INTERCONNECTNODE, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("in_register_success"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("in_register_success"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_register_success");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_11;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_in_register_failed");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_in_register_failed");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_11 = state._tr_in_register_failed();
            } else {
                _trid_11 = (BSet<BTuple<INTERCONNECTNODE, SERVICE>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_in_register_failed", _trid_11);
            for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_11) {
                SERVICE _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_register_failed(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("in_register_failed"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("in_register_failed"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_register_failed");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _trid_12;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_in_requestTargetSocket_Granted");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_in_requestTargetSocket_Granted");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_12 = state._tr_in_requestTargetSocket_Granted();
            } else {
                _trid_12 = (BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_in_requestTargetSocket_Granted", _trid_12);
            for(BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET> param : _trid_12) {
                SOCKET _tmp_1 = param.projection2();
                BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> _tmp_4 = _tmp_2.projection1();
                SID _tmp_5 = _tmp_4.projection2();
                BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> _tmp_6 = _tmp_4.projection1();
                SOCKET _tmp_7 = _tmp_6.projection2();
                BTuple<INTERCONNECTNODE, INTERCONNECTNODE> _tmp_8 = _tmp_6.projection1();
                INTERCONNECTNODE _tmp_9 = _tmp_8.projection2();
                INTERCONNECTNODE _tmp_10 = _tmp_8.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("in_requestTargetSocket_Granted"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("in_requestTargetSocket_Granted"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_requestTargetSocket_Granted");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> _trid_13;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_in_requestTargetSocket_NotGranted");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_in_requestTargetSocket_NotGranted");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
            } else {
                _trid_13 = (BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_in_requestTargetSocket_NotGranted", _trid_13);
            for(BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> param : _trid_13) {
                SID _tmp_1 = param.projection2();
                BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> _tmp_4 = _tmp_2.projection1();
                SOCKET _tmp_5 = _tmp_4.projection2();
                BTuple<INTERCONNECTNODE, INTERCONNECTNODE> _tmp_6 = _tmp_4.projection1();
                INTERCONNECTNODE _tmp_7 = _tmp_6.projection2();
                INTERCONNECTNODE _tmp_8 = _tmp_6.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("in_requestTargetSocket_NotGranted"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("in_requestTargetSocket_NotGranted"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_requestTargetSocket_NotGranted");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<SERVICE> _trid_14;
            if(dependentGuardsOfState != null) {
                cachedValue = GET.invoke(parentsGuard, "_tr_svc_register");
                dependentGuardsBoolean = dependentGuardsOfState.contains("_tr_svc_register");
            }

            if(dependentGuardsOfState == null || dependentGuardsBoolean || parentsGuard == null || cachedValue == null) {
                _trid_14 = state._tr_svc_register();
            } else {
                _trid_14 = (BSet<SERVICE>) cachedValue;
            }
            newCache = (PersistentHashMap) ASSOC.invoke(newCache, "_tr_svc_register", _trid_14);
            for(SERVICE param : _trid_14) {
                SERVICE _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.svc_register(_tmp_1);
                synchronized(guardLock) {
                    if(!dependentInvariant.containsKey(copiedState)) {
                        dependentInvariant.put(copiedState, invariantDependency.get("svc_register"));
                    }
                    if(!dependentGuard.containsKey(copiedState)) {
                        dependentGuard.put(copiedState, guardDependency.get("svc_register"));
                    }
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "svc_register");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

            synchronized(guardLock) {
                guardCache.put(state, newCache);
            }
        } else {
            BSet<INTERCONNECTNODE> _trid_1 = state._tr_constructor_interconnectNode();
            for(INTERCONNECTNODE param : _trid_1) {
                INTERCONNECTNODE _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.constructor_interconnectNode(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_interconnectNode");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<RESOURCEMANAGER> _trid_2 = state._tr_constructor_resourceManager();
            for(RESOURCEMANAGER param : _trid_2) {
                RESOURCEMANAGER _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.constructor_resourceManager(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_resourceManager");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_3 = state._tr_constructor_service();
            for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_3) {
                SERVICE _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.constructor_service(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_service");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> _trid_4 = state._tr_constructor_socket();
            for(BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET> param : _trid_4) {
                SOCKET _tmp_1 = param.projection2();
                BTuple<BTuple<INTERCONNECTNODE, SID>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<INTERCONNECTNODE, SID> _tmp_4 = _tmp_2.projection1();
                SID _tmp_5 = _tmp_4.projection2();
                INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "constructor_socket");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_5 = state._tr_rm_register();
            for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_5) {
                INTERCONNECTNODE _tmp_1 = param.projection2();
                BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_register");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_6 = state._tr_rm_deregister();
            for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_6) {
                INTERCONNECTNODE _tmp_1 = param.projection2();
                BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_deregister");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_7 = state._tr_rm_getSid();
            for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_7) {
                SERVICE _tmp_1 = param.projection2();
                RESOURCEMANAGER _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_getSid(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_getSid");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_8 = state._tr_rm_getSid_Not_Found();
            for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_8) {
                SERVICE _tmp_1 = param.projection2();
                RESOURCEMANAGER _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "rm_getSid_Not_Found");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _trid_9 = state._tr_in_announceResourceManager();
            for(BTuple<INTERCONNECTNODE, RESOURCEMANAGER> param : _trid_9) {
                RESOURCEMANAGER _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_announceResourceManager");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> _trid_10 = state._tr_in_register_success();
            for(BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID> param : _trid_10) {
                SID _tmp_1 = param.projection2();
                BTuple<INTERCONNECTNODE, SERVICE> _tmp_2 = param.projection1();
                SERVICE _tmp_3 = _tmp_2.projection2();
                INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_register_success");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_11 = state._tr_in_register_failed();
            for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_11) {
                SERVICE _tmp_1 = param.projection2();
                INTERCONNECTNODE _tmp_2 = param.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_register_failed(_tmp_2, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_register_failed");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _trid_12 = state._tr_in_requestTargetSocket_Granted();
            for(BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET> param : _trid_12) {
                SOCKET _tmp_1 = param.projection2();
                BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> _tmp_4 = _tmp_2.projection1();
                SID _tmp_5 = _tmp_4.projection2();
                BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> _tmp_6 = _tmp_4.projection1();
                SOCKET _tmp_7 = _tmp_6.projection2();
                BTuple<INTERCONNECTNODE, INTERCONNECTNODE> _tmp_8 = _tmp_6.projection1();
                INTERCONNECTNODE _tmp_9 = _tmp_8.projection2();
                INTERCONNECTNODE _tmp_10 = _tmp_8.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_requestTargetSocket_Granted");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
            for(BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID> param : _trid_13) {
                SID _tmp_1 = param.projection2();
                BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID> _tmp_2 = param.projection1();
                SID _tmp_3 = _tmp_2.projection2();
                BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET> _tmp_4 = _tmp_2.projection1();
                SOCKET _tmp_5 = _tmp_4.projection2();
                BTuple<INTERCONNECTNODE, INTERCONNECTNODE> _tmp_6 = _tmp_4.projection1();
                INTERCONNECTNODE _tmp_7 = _tmp_6.projection2();
                INTERCONNECTNODE _tmp_8 = _tmp_6.projection1();

                nota_v2 copiedState = state._copy();
                copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "in_requestTargetSocket_NotGranted");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }
            BSet<SERVICE> _trid_14 = state._tr_svc_register();
            for(SERVICE param : _trid_14) {
                SERVICE _tmp_1 = param;

                nota_v2 copiedState = state._copy();
                copiedState.svc_register(_tmp_1);
                synchronized(guardLock) {
                    if(!parents.containsKey(copiedState)) {
                        parents.put(copiedState, state);
                    }
                    if(!stateAccessedVia.containsKey(copiedState)) {
                        stateAccessedVia.put(copiedState, "svc_register");
                    }
                }
                result.add(copiedState);
                transitions.getAndIncrement();
            }

        }
        return result;
    }


    public static boolean checkInvariants(Object guardLock, nota_v2 state, boolean isCaching, Map<nota_v2, Set<String>> dependentInvariant) {
        if(isCaching) {
            Set<String> dependentInvariantsOfState;
            synchronized(guardLock) {
                dependentInvariantsOfState = dependentInvariant.get(state);
            }
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
            if(dependentInvariantsOfState.contains("_check_inv_13")) {
                if(!state._check_inv_13()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_14")) {
                if(!state._check_inv_14()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_15")) {
                if(!state._check_inv_15()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_16")) {
                if(!state._check_inv_16()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_17")) {
                if(!state._check_inv_17()) {
                    return false;
                }
            }
            if(dependentInvariantsOfState.contains("_check_inv_18")) {
                if(!state._check_inv_18()) {
                    return false;
                }
            }
            return true;
        }
        return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18());
    }

    private static void printResult(int states, int transitions, boolean deadlockDetected, boolean invariantViolated, List<nota_v2> counterExampleState, Map<nota_v2, nota_v2> parents, Map<nota_v2, String> stateAccessedVia) {

        if(invariantViolated || deadlockDetected) {
            if(deadlockDetected) {
                System.out.println("DEADLOCK DETECTED");
            }
            if(invariantViolated) {
                System.out.println("INVARIANT VIOLATED");
            }
            System.out.println("COUNTER EXAMPLE TRACE: ");
            StringBuilder sb = new StringBuilder();
            if(counterExampleState.size() >= 1) {
                nota_v2 currentState = counterExampleState.get(0);
                while(currentState != null) {
                    sb.insert(0, currentState.toString());
                    sb.insert(0, "\n");
                    sb.insert(0, stateAccessedVia.get(currentState));
                    sb.insert(0, "\n\n");
                    currentState = parents.get(currentState);
                }
            }
            System.out.println(sb.toString());

        }
        if(!deadlockDetected && !invariantViolated) {
            System.out.println("MODEL CHECKING SUCCESSFUL");
        }
        System.out.println("Number of States: " + states);
        System.out.println("Number of Transitions: " + transitions);
    }

    private static nota_v2 next(LinkedList<nota_v2> collection, Object lock, Type type) {
        synchronized(lock) {
            return switch(type) {
                case BFS -> collection.removeFirst();
                case DFS -> collection.removeLast();
                case MIXED -> collection.size() % 2 == 0 ? collection.removeFirst() : collection.removeLast();
            };
        }
    }

    private static void modelCheckSingleThreaded(Type type, boolean isCaching, boolean isDebug) {
        Object lock = new Object();
        Object guardLock = new Object();

        nota_v2 machine = new nota_v2();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);

        Set<nota_v2> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<nota_v2> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<nota_v2, Set<String>> dependentInvariant = new HashMap<>();
        Map<nota_v2, Set<String>> dependentGuard = new HashMap<>();
        Map<nota_v2, PersistentHashMap> guardCache = new HashMap<>();
        Map<nota_v2, nota_v2> parents = new HashMap<>();
        Map<nota_v2, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("in_register_success", new HashSet<>(Arrays.asList("_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("in_announceResourceManager", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("in_requestTargetSocket_Granted", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12")));
            invariantDependency.put("constructor_service", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8")));
            invariantDependency.put("constructor_socket", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12")));
            invariantDependency.put("in_requestTargetSocket_NotGranted", new HashSet<>(Arrays.asList()));
            invariantDependency.put("constructor_interconnectNode", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11")));
            invariantDependency.put("rm_getSid", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_deregister", new HashSet<>(Arrays.asList()));
            invariantDependency.put("constructor_resourceManager", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11")));
            invariantDependency.put("in_register_failed", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_register", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_getSid_Not_Found", new HashSet<>(Arrays.asList()));
            invariantDependency.put("svc_register", new HashSet<>(Arrays.asList("_check_inv_17")));
            guardDependency.put("in_register_success", new HashSet<>(Arrays.asList("_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("in_announceResourceManager", new HashSet<>(Arrays.asList("_tr_in_announceResourceManager")));
            guardDependency.put("in_requestTargetSocket_Granted", new HashSet<>(Arrays.asList("_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("constructor_service", new HashSet<>(Arrays.asList("_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister")));
            guardDependency.put("constructor_socket", new HashSet<>(Arrays.asList("_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("in_requestTargetSocket_NotGranted", new HashSet<>(Arrays.asList()));
            guardDependency.put("constructor_interconnectNode", new HashSet<>(Arrays.asList("_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager")));
            guardDependency.put("rm_getSid", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_deregister", new HashSet<>(Arrays.asList()));
            guardDependency.put("constructor_resourceManager", new HashSet<>(Arrays.asList("_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager")));
            guardDependency.put("in_register_failed", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_register", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_getSid_Not_Found", new HashSet<>(Arrays.asList()));
            guardDependency.put("svc_register", new HashSet<>(Arrays.asList("_tr_svc_register")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<nota_v2> counterExampleState = new ArrayList<>();
        parents.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            nota_v2 state = next(collection, lock, type);

            Set<nota_v2> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

            nextStates.forEach(nextState -> {
                if(!states.contains(nextState)) {
                    numberStates.getAndIncrement();
                    states.add(nextState);
                    collection.add(nextState);
                    if(numberStates.get() % 5000 == 0) {
                        System.out.println("VISITED STATES: " + numberStates.get());
                        System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                        System.out.println("-------------------");
                    }
                }
            });

            if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                invariantViolated.set(true);
                stopThreads.set(true);
                counterExampleState.add(state);
            }

            if(nextStates.isEmpty()) {
                deadlockDetected.set(true);
                stopThreads.set(true);
            }

        }
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }


    private static void modelCheckMultiThreaded(Type type, int threads, boolean isCaching, boolean isDebug) {
        Object lock = new Object();
        Object guardLock = new Object();
        Object waitLock = new Object();
        ThreadPoolExecutor threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads);

        nota_v2 machine = new nota_v2();


        AtomicBoolean invariantViolated = new AtomicBoolean(false);
        AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        AtomicBoolean stopThreads = new AtomicBoolean(false);
        AtomicInteger possibleQueueChanges = new AtomicInteger(0);

        Set<nota_v2> states = new HashSet<>();
        states.add(machine);
        AtomicInteger numberStates = new AtomicInteger(1);

        LinkedList<nota_v2> collection = new LinkedList<>();
        collection.add(machine);

        Map<String, Set<String>> invariantDependency = new HashMap<>();
        Map<String, Set<String>> guardDependency = new HashMap<>();
        Map<nota_v2, Set<String>> dependentInvariant = new HashMap<>();
        Map<nota_v2, Set<String>> dependentGuard = new HashMap<>();
        Map<nota_v2, PersistentHashMap> guardCache = new HashMap<>();
        Map<nota_v2, nota_v2> parents = new HashMap<>();
        Map<nota_v2, String> stateAccessedVia = new HashMap<>();
        if(isCaching) {
            invariantDependency.put("in_register_success", new HashSet<>(Arrays.asList("_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9")));
            invariantDependency.put("in_announceResourceManager", new HashSet<>(Arrays.asList("_check_inv_11")));
            invariantDependency.put("in_requestTargetSocket_Granted", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12")));
            invariantDependency.put("constructor_service", new HashSet<>(Arrays.asList("_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8")));
            invariantDependency.put("constructor_socket", new HashSet<>(Arrays.asList("_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12")));
            invariantDependency.put("in_requestTargetSocket_NotGranted", new HashSet<>(Arrays.asList()));
            invariantDependency.put("constructor_interconnectNode", new HashSet<>(Arrays.asList("_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11")));
            invariantDependency.put("rm_getSid", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_deregister", new HashSet<>(Arrays.asList()));
            invariantDependency.put("constructor_resourceManager", new HashSet<>(Arrays.asList("_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11")));
            invariantDependency.put("in_register_failed", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_register", new HashSet<>(Arrays.asList()));
            invariantDependency.put("rm_getSid_Not_Found", new HashSet<>(Arrays.asList()));
            invariantDependency.put("svc_register", new HashSet<>(Arrays.asList("_check_inv_17")));
            guardDependency.put("in_register_success", new HashSet<>(Arrays.asList("_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("in_announceResourceManager", new HashSet<>(Arrays.asList("_tr_in_announceResourceManager")));
            guardDependency.put("in_requestTargetSocket_Granted", new HashSet<>(Arrays.asList("_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("constructor_service", new HashSet<>(Arrays.asList("_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister")));
            guardDependency.put("constructor_socket", new HashSet<>(Arrays.asList("_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket")));
            guardDependency.put("in_requestTargetSocket_NotGranted", new HashSet<>(Arrays.asList()));
            guardDependency.put("constructor_interconnectNode", new HashSet<>(Arrays.asList("_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager")));
            guardDependency.put("rm_getSid", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_deregister", new HashSet<>(Arrays.asList()));
            guardDependency.put("constructor_resourceManager", new HashSet<>(Arrays.asList("_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager")));
            guardDependency.put("in_register_failed", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_register", new HashSet<>(Arrays.asList()));
            guardDependency.put("rm_getSid_Not_Found", new HashSet<>(Arrays.asList()));
            guardDependency.put("svc_register", new HashSet<>(Arrays.asList("_tr_svc_register")));
            dependentInvariant.put(machine, new HashSet<>());
        }
        List<nota_v2> counterExampleState = new ArrayList<>();
        parents.put(machine, null);
        stateAccessedVia.put(machine, null);

        AtomicInteger transitions = new AtomicInteger(0);

        while(!collection.isEmpty() && !stopThreads.get()) {
            possibleQueueChanges.incrementAndGet();
            nota_v2 state = next(collection, lock, type);
            Runnable task = () -> {
                Set<nota_v2> nextStates = generateNextStates(guardLock, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);

                nextStates.forEach(nextState -> {
                    synchronized(lock) {
                        if(!states.contains(nextState)) {
                            numberStates.getAndIncrement();
                            states.add(nextState);
                            collection.add(nextState);
                            if(numberStates.get() % 5000 == 0) {
                                if( isDebug || numberStates.get() % 50000 == 0) {
                                    System.out.println("VISITED STATES: " + numberStates.get());
                                    System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                    System.out.println("-------------------");
                                }
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

                if(!checkInvariants(guardLock, state, isCaching, dependentInvariant)) {
                    invariantViolated.set(true);
                    stopThreads.set(true);
                    counterExampleState.add(state);
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
        printResult(numberStates.get(), transitions.get(), deadlockDetected.get(), invariantViolated.get(), counterExampleState, parents, stateAccessedVia);
    }

    public static void debugPrint (String msg, Boolean isDebug) {
       if (isDebug) {
          System.out.println(msg);
       }
    }

    public static void main(String[] args) {
        if(args.length > 4) {
            System.out.println("Expecting 3 command-line arguments: STRATEGY THREADS CACHING DEBUG");
            return;
        }
        Type type = Type.MIXED;
        int threads = 0;
        boolean isCaching = false;
        boolean isDebug = false;

        if(args.length > 0) { 
            if("mixed".equals(args[0])) {
                type = Type.MIXED;
            } else if("bf".equals(args[0])) {
                type = Type.BFS;
            } else if ("df".equals(args[0])) {
                type = Type.DFS;
            } else {
                System.out.println("Value for command-line argument STRATEGY is wrong.");
                System.out.println("Expecting mixed, bf or df.");
                return;
            }
        }
        if(args.length > 1) { 
            try {
                threads = Integer.parseInt(args[1]);
            } catch(NumberFormatException e) {
                System.out.println("Value for command-line argument THREADS is not a number.");
                return;
            }
            if(threads <= 0) {
                System.out.println("Value for command-line argument THREADS must be positive.");
                return;
            }
        }
        if(args.length > 2) { 
            try {
                isCaching = Boolean.parseBoolean(args[2]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument CACHING is not a boolean.");
                return;
            }
        }
        if(args.length > 3) { 
            try {
                isDebug = Boolean.parseBoolean(args[3]);
            } catch(Exception e) {
                System.out.println("Value for command-line argument DEBUG is not a boolean.");
                return;
            }
        }

        debugPrint("Starting Modelchecking, STRATEGY=" + type + "THREADS=" + threads + ", CACHING=" + isCaching, isDebug);
        if(threads == 1) {
            modelCheckSingleThreaded(type, isCaching, isDebug);
        } else {
            modelCheckMultiThreaded(type, threads, isCaching, isDebug);
        }
    }




}
