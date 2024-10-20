import de.hhu.stups.btypes.BRelation;
import de.hhu.stups.btypes.BStruct;
import de.hhu.stups.btypes.BTuple;
import de.hhu.stups.btypes.BSet;
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
import java.util.concurrent.ConcurrentHashMap;
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
import de.hhu.stups.btypes.LoopInvariantViolation;
import de.hhu.stups.btypes.VariantViolation;
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

    public nota_v2 parent;
    public String stateAccessedVia;

    public static class _ProjectionRead_constructor_interconnectNode {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;

        public _ProjectionRead_constructor_interconnectNode(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager) {
            this.interconnectNodes = interconnectNodes;
            this.in_resourceManager = in_resourceManager;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_resourceManager: " + this.in_resourceManager + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_constructor_interconnectNode)) {
                return false;
            }
            _ProjectionRead_constructor_interconnectNode o = (_ProjectionRead_constructor_interconnectNode) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_resourceManager.equals(o.in_resourceManager);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_resourceManager);
        }
    }

    public static class _ProjectionRead__tr_constructor_interconnectNode {

        public BSet<INTERCONNECTNODE> interconnectNodes;

        public _ProjectionRead__tr_constructor_interconnectNode(BSet<INTERCONNECTNODE> interconnectNodes) {
            this.interconnectNodes = interconnectNodes;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_constructor_interconnectNode)) {
                return false;
            }
            _ProjectionRead__tr_constructor_interconnectNode o = (_ProjectionRead__tr_constructor_interconnectNode) other;
            return this.interconnectNodes.equals(o.interconnectNodes);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes);
        }
    }

    public static class _ProjectionWrite_constructor_interconnectNode {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;

        public _ProjectionWrite_constructor_interconnectNode(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager) {
            this.interconnectNodes = interconnectNodes;
            this.in_resourceManager = in_resourceManager;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_resourceManager: " + this.in_resourceManager + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_constructor_interconnectNode)) {
                return false;
            }
            _ProjectionWrite_constructor_interconnectNode o = (_ProjectionWrite_constructor_interconnectNode) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_resourceManager.equals(o.in_resourceManager);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_resourceManager);
        }
    }

    public static class _ProjectionRead_constructor_resourceManager {

        public BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead_constructor_resourceManager(BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.rm_services = rm_services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "rm_services: " + this.rm_services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_constructor_resourceManager)) {
                return false;
            }
            _ProjectionRead_constructor_resourceManager o = (_ProjectionRead_constructor_resourceManager) other;
            return this.rm_services.equals(o.rm_services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(rm_services, resourceManagers);
        }
    }

    public static class _ProjectionRead__tr_constructor_resourceManager {

        public BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__tr_constructor_resourceManager(BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.rm_services = rm_services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "rm_services: " + this.rm_services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_constructor_resourceManager)) {
                return false;
            }
            _ProjectionRead__tr_constructor_resourceManager o = (_ProjectionRead__tr_constructor_resourceManager) other;
            return this.rm_services.equals(o.rm_services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(rm_services, resourceManagers);
        }
    }

    public static class _ProjectionWrite_constructor_resourceManager {

        public BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionWrite_constructor_resourceManager(BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.rm_services = rm_services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "rm_services: " + this.rm_services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_constructor_resourceManager)) {
                return false;
            }
            _ProjectionWrite_constructor_resourceManager o = (_ProjectionWrite_constructor_resourceManager) other;
            return this.rm_services.equals(o.rm_services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(rm_services, resourceManagers);
        }
    }

    public static class _ProjectionRead_constructor_service {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SERVICE, BBoolean> svc_registered;
        public BRelation<SERVICE, BSet<SOCKET>> svc_sockets;
        public BSet<SERVICE> services;
        public BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode;

        public _ProjectionRead_constructor_service(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SERVICE, BBoolean> svc_registered, BRelation<SERVICE, BSet<SOCKET>> svc_sockets, BSet<SERVICE> services, BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode) {
            this.interconnectNodes = interconnectNodes;
            this.svc_registered = svc_registered;
            this.svc_sockets = svc_sockets;
            this.services = services;
            this.svc_ICNode = svc_ICNode;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "svc_registered: " + this.svc_registered + "," + "svc_sockets: " + this.svc_sockets + "," + "services: " + this.services + "," + "svc_ICNode: " + this.svc_ICNode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_constructor_service)) {
                return false;
            }
            _ProjectionRead_constructor_service o = (_ProjectionRead_constructor_service) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.svc_registered.equals(o.svc_registered) && this.svc_sockets.equals(o.svc_sockets) && this.services.equals(o.services) && this.svc_ICNode.equals(o.svc_ICNode);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, svc_registered, svc_sockets, services, svc_ICNode);
        }
    }

    public static class _ProjectionRead__tr_constructor_service {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;

        public _ProjectionRead__tr_constructor_service(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_constructor_service)) {
                return false;
            }
            _ProjectionRead__tr_constructor_service o = (_ProjectionRead__tr_constructor_service) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services);
        }
    }

    public static class _ProjectionWrite_constructor_service {

        public BRelation<SERVICE, BBoolean> svc_registered;
        public BRelation<SERVICE, BSet<SOCKET>> svc_sockets;
        public BSet<SERVICE> services;
        public BRelation<SERVICE, SID> svc_serviceID;
        public BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode;

        public _ProjectionWrite_constructor_service(BRelation<SERVICE, BBoolean> svc_registered, BRelation<SERVICE, BSet<SOCKET>> svc_sockets, BSet<SERVICE> services, BRelation<SERVICE, SID> svc_serviceID, BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode) {
            this.svc_registered = svc_registered;
            this.svc_sockets = svc_sockets;
            this.services = services;
            this.svc_serviceID = svc_serviceID;
            this.svc_ICNode = svc_ICNode;
        }

        public String toString() {
            return "{" + "svc_registered: " + this.svc_registered + "," + "svc_sockets: " + this.svc_sockets + "," + "services: " + this.services + "," + "svc_serviceID: " + this.svc_serviceID + "," + "svc_ICNode: " + this.svc_ICNode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_constructor_service)) {
                return false;
            }
            _ProjectionWrite_constructor_service o = (_ProjectionWrite_constructor_service) other;
            return this.svc_registered.equals(o.svc_registered) && this.svc_sockets.equals(o.svc_sockets) && this.services.equals(o.services) && this.svc_serviceID.equals(o.svc_serviceID) && this.svc_ICNode.equals(o.svc_ICNode);
        }

        public int hashCode() {
            return Objects.hash(svc_registered, svc_sockets, services, svc_serviceID, svc_ICNode);
        }
    }

    public static class _ProjectionRead_constructor_socket {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BRelation<SOCKET, SID> soc_to;
        public BRelation<SOCKET, SID> soc_from;
        public BSet<SOCKET> sockets;

        public _ProjectionRead_constructor_socket(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BRelation<SOCKET, SID> soc_to, BRelation<SOCKET, SID> soc_from, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_sockets = in_sockets;
            this.soc_to = soc_to;
            this.soc_from = soc_from;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_sockets: " + this.in_sockets + "," + "soc_to: " + this.soc_to + "," + "soc_from: " + this.soc_from + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_constructor_socket)) {
                return false;
            }
            _ProjectionRead_constructor_socket o = (_ProjectionRead_constructor_socket) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_sockets.equals(o.in_sockets) && this.soc_to.equals(o.soc_to) && this.soc_from.equals(o.soc_from) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_sockets, soc_to, soc_from, sockets);
        }
    }

    public static class _ProjectionRead__tr_constructor_socket {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__tr_constructor_socket(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_constructor_socket)) {
                return false;
            }
            _ProjectionRead__tr_constructor_socket o = (_ProjectionRead__tr_constructor_socket) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, sockets);
        }
    }

    public static class _ProjectionWrite_constructor_socket {

        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BRelation<SOCKET, SID> soc_to;
        public BRelation<SOCKET, SID> soc_from;
        public BSet<SOCKET> sockets;

        public _ProjectionWrite_constructor_socket(BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BRelation<SOCKET, SID> soc_to, BRelation<SOCKET, SID> soc_from, BSet<SOCKET> sockets) {
            this.in_sockets = in_sockets;
            this.soc_to = soc_to;
            this.soc_from = soc_from;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "in_sockets: " + this.in_sockets + "," + "soc_to: " + this.soc_to + "," + "soc_from: " + this.soc_from + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_constructor_socket)) {
                return false;
            }
            _ProjectionWrite_constructor_socket o = (_ProjectionWrite_constructor_socket) other;
            return this.in_sockets.equals(o.in_sockets) && this.soc_to.equals(o.soc_to) && this.soc_from.equals(o.soc_from) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(in_sockets, soc_to, soc_from, sockets);
        }
    }

    public static class _ProjectionRead_rm_register {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead_rm_register(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_rm_register)) {
                return false;
            }
            _ProjectionRead_rm_register o = (_ProjectionRead_rm_register) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services, resourceManagers);
        }
    }

    public static class _ProjectionRead__tr_rm_register {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__tr_rm_register(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_rm_register)) {
                return false;
            }
            _ProjectionRead__tr_rm_register o = (_ProjectionRead__tr_rm_register) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services, resourceManagers);
        }
    }

    public static class _ProjectionWrite_rm_register {


        public _ProjectionWrite_rm_register() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_rm_register)) {
                return false;
            }
            _ProjectionWrite_rm_register o = (_ProjectionWrite_rm_register) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_rm_deregister {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead_rm_deregister(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_rm_deregister)) {
                return false;
            }
            _ProjectionRead_rm_deregister o = (_ProjectionRead_rm_deregister) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services, resourceManagers);
        }
    }

    public static class _ProjectionRead__tr_rm_deregister {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__tr_rm_deregister(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_rm_deregister)) {
                return false;
            }
            _ProjectionRead__tr_rm_deregister o = (_ProjectionRead__tr_rm_deregister) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services, resourceManagers);
        }
    }

    public static class _ProjectionWrite_rm_deregister {


        public _ProjectionWrite_rm_deregister() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_rm_deregister)) {
                return false;
            }
            _ProjectionWrite_rm_deregister o = (_ProjectionWrite_rm_deregister) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_rm_getSid {

        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;
        public BRelation<SERVICE, SID> rm_sids;

        public _ProjectionRead_rm_getSid(BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers, BRelation<SERVICE, SID> rm_sids) {
            this.services = services;
            this.resourceManagers = resourceManagers;
            this.rm_sids = rm_sids;
        }

        public String toString() {
            return "{" + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "," + "rm_sids: " + this.rm_sids + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_rm_getSid)) {
                return false;
            }
            _ProjectionRead_rm_getSid o = (_ProjectionRead_rm_getSid) other;
            return this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers) && this.rm_sids.equals(o.rm_sids);
        }

        public int hashCode() {
            return Objects.hash(services, resourceManagers, rm_sids);
        }
    }

    public static class _ProjectionRead__tr_rm_getSid {

        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;
        public BRelation<SERVICE, SID> rm_sids;

        public _ProjectionRead__tr_rm_getSid(BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers, BRelation<SERVICE, SID> rm_sids) {
            this.services = services;
            this.resourceManagers = resourceManagers;
            this.rm_sids = rm_sids;
        }

        public String toString() {
            return "{" + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "," + "rm_sids: " + this.rm_sids + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_rm_getSid)) {
                return false;
            }
            _ProjectionRead__tr_rm_getSid o = (_ProjectionRead__tr_rm_getSid) other;
            return this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers) && this.rm_sids.equals(o.rm_sids);
        }

        public int hashCode() {
            return Objects.hash(services, resourceManagers, rm_sids);
        }
    }

    public static class _ProjectionWrite_rm_getSid {


        public _ProjectionWrite_rm_getSid() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_rm_getSid)) {
                return false;
            }
            _ProjectionWrite_rm_getSid o = (_ProjectionWrite_rm_getSid) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_rm_getSid_Not_Found {

        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead_rm_getSid_Not_Found(BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_rm_getSid_Not_Found)) {
                return false;
            }
            _ProjectionRead_rm_getSid_Not_Found o = (_ProjectionRead_rm_getSid_Not_Found) other;
            return this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(services, resourceManagers);
        }
    }

    public static class _ProjectionRead__tr_rm_getSid_Not_Found {

        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__tr_rm_getSid_Not_Found(BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_rm_getSid_Not_Found)) {
                return false;
            }
            _ProjectionRead__tr_rm_getSid_Not_Found o = (_ProjectionRead__tr_rm_getSid_Not_Found) other;
            return this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(services, resourceManagers);
        }
    }

    public static class _ProjectionWrite_rm_getSid_Not_Found {


        public _ProjectionWrite_rm_getSid_Not_Found() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_rm_getSid_Not_Found)) {
                return false;
            }
            _ProjectionWrite_rm_getSid_Not_Found o = (_ProjectionWrite_rm_getSid_Not_Found) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_in_announceResourceManager {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead_in_announceResourceManager(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.in_resourceManager = in_resourceManager;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_resourceManager: " + this.in_resourceManager + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_in_announceResourceManager)) {
                return false;
            }
            _ProjectionRead_in_announceResourceManager o = (_ProjectionRead_in_announceResourceManager) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_resourceManager.equals(o.in_resourceManager) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_resourceManager, resourceManagers);
        }
    }

    public static class _ProjectionRead__tr_in_announceResourceManager {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__tr_in_announceResourceManager(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.in_resourceManager = in_resourceManager;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_resourceManager: " + this.in_resourceManager + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_in_announceResourceManager)) {
                return false;
            }
            _ProjectionRead__tr_in_announceResourceManager o = (_ProjectionRead__tr_in_announceResourceManager) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_resourceManager.equals(o.in_resourceManager) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_resourceManager, resourceManagers);
        }
    }

    public static class _ProjectionWrite_in_announceResourceManager {

        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;

        public _ProjectionWrite_in_announceResourceManager(BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager) {
            this.in_resourceManager = in_resourceManager;
        }

        public String toString() {
            return "{" + "in_resourceManager: " + this.in_resourceManager + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_in_announceResourceManager)) {
                return false;
            }
            _ProjectionWrite_in_announceResourceManager o = (_ProjectionWrite_in_announceResourceManager) other;
            return this.in_resourceManager.equals(o.in_resourceManager);
        }

        public int hashCode() {
            return Objects.hash(in_resourceManager);
        }
    }

    public static class _ProjectionRead_in_register_success {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SID, INTERCONNECTNODE> in_localServices;
        public BSet<SERVICE> services;

        public _ProjectionRead_in_register_success(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SID, INTERCONNECTNODE> in_localServices, BSet<SERVICE> services) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_localServices = in_localServices;
            this.services = services;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_localServices: " + this.in_localServices + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_in_register_success)) {
                return false;
            }
            _ProjectionRead_in_register_success o = (_ProjectionRead_in_register_success) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_localServices.equals(o.in_localServices) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_localServices, services);
        }
    }

    public static class _ProjectionRead__tr_in_register_success {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SID, INTERCONNECTNODE> in_localServices;
        public BSet<SERVICE> services;

        public _ProjectionRead__tr_in_register_success(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SID, INTERCONNECTNODE> in_localServices, BSet<SERVICE> services) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_localServices = in_localServices;
            this.services = services;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_localServices: " + this.in_localServices + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_in_register_success)) {
                return false;
            }
            _ProjectionRead__tr_in_register_success o = (_ProjectionRead__tr_in_register_success) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_localServices.equals(o.in_localServices) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_localServices, services);
        }
    }

    public static class _ProjectionWrite_in_register_success {

        public BSet<SID> sids;
        public BRelation<SID, INTERCONNECTNODE> in_localServices;

        public _ProjectionWrite_in_register_success(BSet<SID> sids, BRelation<SID, INTERCONNECTNODE> in_localServices) {
            this.sids = sids;
            this.in_localServices = in_localServices;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "in_localServices: " + this.in_localServices + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_in_register_success)) {
                return false;
            }
            _ProjectionWrite_in_register_success o = (_ProjectionWrite_in_register_success) other;
            return this.sids.equals(o.sids) && this.in_localServices.equals(o.in_localServices);
        }

        public int hashCode() {
            return Objects.hash(sids, in_localServices);
        }
    }

    public static class _ProjectionRead_in_register_failed {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;

        public _ProjectionRead_in_register_failed(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_in_register_failed)) {
                return false;
            }
            _ProjectionRead_in_register_failed o = (_ProjectionRead_in_register_failed) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services);
        }
    }

    public static class _ProjectionRead__tr_in_register_failed {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;

        public _ProjectionRead__tr_in_register_failed(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_in_register_failed)) {
                return false;
            }
            _ProjectionRead__tr_in_register_failed o = (_ProjectionRead__tr_in_register_failed) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services);
        }
    }

    public static class _ProjectionWrite_in_register_failed {


        public _ProjectionWrite_in_register_failed() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_in_register_failed)) {
                return false;
            }
            _ProjectionWrite_in_register_failed o = (_ProjectionWrite_in_register_failed) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_in_requestTargetSocket_Granted {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SID> sids;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BRelation<SOCKET, SID> soc_to;
        public BRelation<SOCKET, SID> soc_from;
        public BSet<SOCKET> sockets;

        public _ProjectionRead_in_requestTargetSocket_Granted(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SID> sids, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BRelation<SOCKET, SID> soc_to, BRelation<SOCKET, SID> soc_from, BSet<SOCKET> sockets) {
            this.interconnectNodes = interconnectNodes;
            this.sids = sids;
            this.in_sockets = in_sockets;
            this.soc_to = soc_to;
            this.soc_from = soc_from;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "sids: " + this.sids + "," + "in_sockets: " + this.in_sockets + "," + "soc_to: " + this.soc_to + "," + "soc_from: " + this.soc_from + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_in_requestTargetSocket_Granted)) {
                return false;
            }
            _ProjectionRead_in_requestTargetSocket_Granted o = (_ProjectionRead_in_requestTargetSocket_Granted) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.sids.equals(o.sids) && this.in_sockets.equals(o.in_sockets) && this.soc_to.equals(o.soc_to) && this.soc_from.equals(o.soc_from) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, sids, in_sockets, soc_to, soc_from, sockets);
        }
    }

    public static class _ProjectionRead__tr_in_requestTargetSocket_Granted {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__tr_in_requestTargetSocket_Granted(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_sockets = in_sockets;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_sockets: " + this.in_sockets + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_in_requestTargetSocket_Granted)) {
                return false;
            }
            _ProjectionRead__tr_in_requestTargetSocket_Granted o = (_ProjectionRead__tr_in_requestTargetSocket_Granted) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_sockets.equals(o.in_sockets) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_sockets, sockets);
        }
    }

    public static class _ProjectionWrite_in_requestTargetSocket_Granted {

        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BRelation<SOCKET, SID> soc_to;
        public BRelation<SOCKET, SID> soc_from;
        public BSet<SOCKET> sockets;

        public _ProjectionWrite_in_requestTargetSocket_Granted(BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BRelation<SOCKET, SID> soc_to, BRelation<SOCKET, SID> soc_from, BSet<SOCKET> sockets) {
            this.in_sockets = in_sockets;
            this.soc_to = soc_to;
            this.soc_from = soc_from;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "in_sockets: " + this.in_sockets + "," + "soc_to: " + this.soc_to + "," + "soc_from: " + this.soc_from + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_in_requestTargetSocket_Granted)) {
                return false;
            }
            _ProjectionWrite_in_requestTargetSocket_Granted o = (_ProjectionWrite_in_requestTargetSocket_Granted) other;
            return this.in_sockets.equals(o.in_sockets) && this.soc_to.equals(o.soc_to) && this.soc_from.equals(o.soc_from) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(in_sockets, soc_to, soc_from, sockets);
        }
    }

    public static class _ProjectionRead_in_requestTargetSocket_NotGranted {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BSet<SOCKET> sockets;

        public _ProjectionRead_in_requestTargetSocket_NotGranted(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_sockets = in_sockets;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_sockets: " + this.in_sockets + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_in_requestTargetSocket_NotGranted)) {
                return false;
            }
            _ProjectionRead_in_requestTargetSocket_NotGranted o = (_ProjectionRead_in_requestTargetSocket_NotGranted) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_sockets.equals(o.in_sockets) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_sockets, sockets);
        }
    }

    public static class _ProjectionRead__tr_in_requestTargetSocket_NotGranted {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__tr_in_requestTargetSocket_NotGranted(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_sockets = in_sockets;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_sockets: " + this.in_sockets + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_in_requestTargetSocket_NotGranted)) {
                return false;
            }
            _ProjectionRead__tr_in_requestTargetSocket_NotGranted o = (_ProjectionRead__tr_in_requestTargetSocket_NotGranted) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_sockets.equals(o.in_sockets) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_sockets, sockets);
        }
    }

    public static class _ProjectionWrite_in_requestTargetSocket_NotGranted {


        public _ProjectionWrite_in_requestTargetSocket_NotGranted() {
        }

        public String toString() {
            return "{}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_in_requestTargetSocket_NotGranted)) {
                return false;
            }
            _ProjectionWrite_in_requestTargetSocket_NotGranted o = (_ProjectionWrite_in_requestTargetSocket_NotGranted) other;
            return true;
        }

        public int hashCode() {
            return Objects.hash();
        }
    }

    public static class _ProjectionRead_svc_register {

        public BRelation<SERVICE, BBoolean> svc_registered;
        public BSet<SERVICE> services;

        public _ProjectionRead_svc_register(BRelation<SERVICE, BBoolean> svc_registered, BSet<SERVICE> services) {
            this.svc_registered = svc_registered;
            this.services = services;
        }

        public String toString() {
            return "{" + "svc_registered: " + this.svc_registered + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead_svc_register)) {
                return false;
            }
            _ProjectionRead_svc_register o = (_ProjectionRead_svc_register) other;
            return this.svc_registered.equals(o.svc_registered) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(svc_registered, services);
        }
    }

    public static class _ProjectionRead__tr_svc_register {

        public BRelation<SERVICE, BBoolean> svc_registered;
        public BSet<SERVICE> services;

        public _ProjectionRead__tr_svc_register(BRelation<SERVICE, BBoolean> svc_registered, BSet<SERVICE> services) {
            this.svc_registered = svc_registered;
            this.services = services;
        }

        public String toString() {
            return "{" + "svc_registered: " + this.svc_registered + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__tr_svc_register)) {
                return false;
            }
            _ProjectionRead__tr_svc_register o = (_ProjectionRead__tr_svc_register) other;
            return this.svc_registered.equals(o.svc_registered) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(svc_registered, services);
        }
    }

    public static class _ProjectionWrite_svc_register {

        public BRelation<SERVICE, BBoolean> svc_registered;

        public _ProjectionWrite_svc_register(BRelation<SERVICE, BBoolean> svc_registered) {
            this.svc_registered = svc_registered;
        }

        public String toString() {
            return "{" + "svc_registered: " + this.svc_registered + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionWrite_svc_register)) {
                return false;
            }
            _ProjectionWrite_svc_register o = (_ProjectionWrite_svc_register) other;
            return this.svc_registered.equals(o.svc_registered);
        }

        public int hashCode() {
            return Objects.hash(svc_registered);
        }
    }

    public static class _ProjectionRead__check_inv_1 {

        public BSet<INTERCONNECTNODE> interconnectNodes;

        public _ProjectionRead__check_inv_1(BSet<INTERCONNECTNODE> interconnectNodes) {
            this.interconnectNodes = interconnectNodes;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_1)) {
                return false;
            }
            _ProjectionRead__check_inv_1 o = (_ProjectionRead__check_inv_1) other;
            return this.interconnectNodes.equals(o.interconnectNodes);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes);
        }
    }

    public static class _ProjectionRead__check_inv_2 {

        public BSet<SOCKET> sockets;

        public _ProjectionRead__check_inv_2(BSet<SOCKET> sockets) {
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_2)) {
                return false;
            }
            _ProjectionRead__check_inv_2 o = (_ProjectionRead__check_inv_2) other;
            return this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sockets);
        }
    }

    public static class _ProjectionRead__check_inv_3 {

        public BSet<SERVICE> services;

        public _ProjectionRead__check_inv_3(BSet<SERVICE> services) {
            this.services = services;
        }

        public String toString() {
            return "{" + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_3)) {
                return false;
            }
            _ProjectionRead__check_inv_3 o = (_ProjectionRead__check_inv_3) other;
            return this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(services);
        }
    }

    public static class _ProjectionRead__check_inv_4 {

        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__check_inv_4(BSet<RESOURCEMANAGER> resourceManagers) {
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_4)) {
                return false;
            }
            _ProjectionRead__check_inv_4 o = (_ProjectionRead__check_inv_4) other;
            return this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(resourceManagers);
        }
    }

    public static class _ProjectionRead__check_inv_5 {

        public BSet<SID> sids;

        public _ProjectionRead__check_inv_5(BSet<SID> sids) {
            this.sids = sids;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_5)) {
                return false;
            }
            _ProjectionRead__check_inv_5 o = (_ProjectionRead__check_inv_5) other;
            return this.sids.equals(o.sids);
        }

        public int hashCode() {
            return Objects.hash(sids);
        }
    }

    public static class _ProjectionRead__check_inv_6 {

        public BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;
        public BSet<SERVICE> services;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__check_inv_6(BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services, BSet<SERVICE> services, BSet<RESOURCEMANAGER> resourceManagers) {
            this.rm_services = rm_services;
            this.services = services;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "rm_services: " + this.rm_services + "," + "services: " + this.services + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_6)) {
                return false;
            }
            _ProjectionRead__check_inv_6 o = (_ProjectionRead__check_inv_6) other;
            return this.rm_services.equals(o.rm_services) && this.services.equals(o.services) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(rm_services, services, resourceManagers);
        }
    }

    public static class _ProjectionRead__check_inv_7 {

        public BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services;

        public _ProjectionRead__check_inv_7(BRelation<RESOURCEMANAGER, BSet<SERVICE>> rm_services) {
            this.rm_services = rm_services;
        }

        public String toString() {
            return "{" + "rm_services: " + this.rm_services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_7)) {
                return false;
            }
            _ProjectionRead__check_inv_7 o = (_ProjectionRead__check_inv_7) other;
            return this.rm_services.equals(o.rm_services);
        }

        public int hashCode() {
            return Objects.hash(rm_services);
        }
    }

    public static class _ProjectionRead__check_inv_8 {

        public BSet<SID> sids;
        public BSet<SERVICE> services;
        public BRelation<SERVICE, SID> rm_sids;

        public _ProjectionRead__check_inv_8(BSet<SID> sids, BSet<SERVICE> services, BRelation<SERVICE, SID> rm_sids) {
            this.sids = sids;
            this.services = services;
            this.rm_sids = rm_sids;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "services: " + this.services + "," + "rm_sids: " + this.rm_sids + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_8)) {
                return false;
            }
            _ProjectionRead__check_inv_8 o = (_ProjectionRead__check_inv_8) other;
            return this.sids.equals(o.sids) && this.services.equals(o.services) && this.rm_sids.equals(o.rm_sids);
        }

        public int hashCode() {
            return Objects.hash(sids, services, rm_sids);
        }
    }

    public static class _ProjectionRead__check_inv_9 {

        public BSet<SID> sids;
        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SID, INTERCONNECTNODE> in_localServices;

        public _ProjectionRead__check_inv_9(BSet<SID> sids, BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SID, INTERCONNECTNODE> in_localServices) {
            this.sids = sids;
            this.interconnectNodes = interconnectNodes;
            this.in_localServices = in_localServices;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "interconnectNodes: " + this.interconnectNodes + "," + "in_localServices: " + this.in_localServices + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_9)) {
                return false;
            }
            _ProjectionRead__check_inv_9 o = (_ProjectionRead__check_inv_9) other;
            return this.sids.equals(o.sids) && this.interconnectNodes.equals(o.interconnectNodes) && this.in_localServices.equals(o.in_localServices);
        }

        public int hashCode() {
            return Objects.hash(sids, interconnectNodes, in_localServices);
        }
    }

    public static class _ProjectionRead__check_inv_10 {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<SOCKET, INTERCONNECTNODE> in_sockets;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__check_inv_10(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<SOCKET, INTERCONNECTNODE> in_sockets, BSet<SOCKET> sockets) {
            this.interconnectNodes = interconnectNodes;
            this.in_sockets = in_sockets;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_sockets: " + this.in_sockets + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_10)) {
                return false;
            }
            _ProjectionRead__check_inv_10 o = (_ProjectionRead__check_inv_10) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_sockets.equals(o.in_sockets) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_sockets, sockets);
        }
    }

    public static class _ProjectionRead__check_inv_11 {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager;
        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__check_inv_11(BSet<INTERCONNECTNODE> interconnectNodes, BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER>> in_resourceManager, BSet<RESOURCEMANAGER> resourceManagers) {
            this.interconnectNodes = interconnectNodes;
            this.in_resourceManager = in_resourceManager;
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "in_resourceManager: " + this.in_resourceManager + "," + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_11)) {
                return false;
            }
            _ProjectionRead__check_inv_11 o = (_ProjectionRead__check_inv_11) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.in_resourceManager.equals(o.in_resourceManager) && this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, in_resourceManager, resourceManagers);
        }
    }

    public static class _ProjectionRead__check_inv_12 {

        public BSet<SID> sids;
        public BRelation<SOCKET, SID> soc_to;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__check_inv_12(BSet<SID> sids, BRelation<SOCKET, SID> soc_to, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.soc_to = soc_to;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "soc_to: " + this.soc_to + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_12)) {
                return false;
            }
            _ProjectionRead__check_inv_12 o = (_ProjectionRead__check_inv_12) other;
            return this.sids.equals(o.sids) && this.soc_to.equals(o.soc_to) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, soc_to, sockets);
        }
    }

    public static class _ProjectionRead__check_inv_13 {

        public BSet<SID> sids;
        public BRelation<SOCKET, SID> soc_from;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__check_inv_13(BSet<SID> sids, BRelation<SOCKET, SID> soc_from, BSet<SOCKET> sockets) {
            this.sids = sids;
            this.soc_from = soc_from;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "soc_from: " + this.soc_from + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_13)) {
                return false;
            }
            _ProjectionRead__check_inv_13 o = (_ProjectionRead__check_inv_13) other;
            return this.sids.equals(o.sids) && this.soc_from.equals(o.soc_from) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(sids, soc_from, sockets);
        }
    }

    public static class _ProjectionRead__check_inv_14 {

        public BSet<SID> sids;
        public BSet<SERVICE> services;
        public BRelation<SERVICE, SID> svc_serviceID;

        public _ProjectionRead__check_inv_14(BSet<SID> sids, BSet<SERVICE> services, BRelation<SERVICE, SID> svc_serviceID) {
            this.sids = sids;
            this.services = services;
            this.svc_serviceID = svc_serviceID;
        }

        public String toString() {
            return "{" + "sids: " + this.sids + "," + "services: " + this.services + "," + "svc_serviceID: " + this.svc_serviceID + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_14)) {
                return false;
            }
            _ProjectionRead__check_inv_14 o = (_ProjectionRead__check_inv_14) other;
            return this.sids.equals(o.sids) && this.services.equals(o.services) && this.svc_serviceID.equals(o.svc_serviceID);
        }

        public int hashCode() {
            return Objects.hash(sids, services, svc_serviceID);
        }
    }

    public static class _ProjectionRead__check_inv_15 {

        public BRelation<SERVICE, BSet<SOCKET>> svc_sockets;
        public BSet<SERVICE> services;
        public BSet<SOCKET> sockets;

        public _ProjectionRead__check_inv_15(BRelation<SERVICE, BSet<SOCKET>> svc_sockets, BSet<SERVICE> services, BSet<SOCKET> sockets) {
            this.svc_sockets = svc_sockets;
            this.services = services;
            this.sockets = sockets;
        }

        public String toString() {
            return "{" + "svc_sockets: " + this.svc_sockets + "," + "services: " + this.services + "," + "sockets: " + this.sockets + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_15)) {
                return false;
            }
            _ProjectionRead__check_inv_15 o = (_ProjectionRead__check_inv_15) other;
            return this.svc_sockets.equals(o.svc_sockets) && this.services.equals(o.services) && this.sockets.equals(o.sockets);
        }

        public int hashCode() {
            return Objects.hash(svc_sockets, services, sockets);
        }
    }

    public static class _ProjectionRead__check_inv_16 {

        public BSet<INTERCONNECTNODE> interconnectNodes;
        public BSet<SERVICE> services;
        public BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode;

        public _ProjectionRead__check_inv_16(BSet<INTERCONNECTNODE> interconnectNodes, BSet<SERVICE> services, BRelation<SERVICE, INTERCONNECTNODE> svc_ICNode) {
            this.interconnectNodes = interconnectNodes;
            this.services = services;
            this.svc_ICNode = svc_ICNode;
        }

        public String toString() {
            return "{" + "interconnectNodes: " + this.interconnectNodes + "," + "services: " + this.services + "," + "svc_ICNode: " + this.svc_ICNode + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_16)) {
                return false;
            }
            _ProjectionRead__check_inv_16 o = (_ProjectionRead__check_inv_16) other;
            return this.interconnectNodes.equals(o.interconnectNodes) && this.services.equals(o.services) && this.svc_ICNode.equals(o.svc_ICNode);
        }

        public int hashCode() {
            return Objects.hash(interconnectNodes, services, svc_ICNode);
        }
    }

    public static class _ProjectionRead__check_inv_17 {

        public BRelation<SERVICE, BBoolean> svc_registered;
        public BSet<SERVICE> services;

        public _ProjectionRead__check_inv_17(BRelation<SERVICE, BBoolean> svc_registered, BSet<SERVICE> services) {
            this.svc_registered = svc_registered;
            this.services = services;
        }

        public String toString() {
            return "{" + "svc_registered: " + this.svc_registered + "," + "services: " + this.services + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_17)) {
                return false;
            }
            _ProjectionRead__check_inv_17 o = (_ProjectionRead__check_inv_17) other;
            return this.svc_registered.equals(o.svc_registered) && this.services.equals(o.services);
        }

        public int hashCode() {
            return Objects.hash(svc_registered, services);
        }
    }

    public static class _ProjectionRead__check_inv_18 {

        public BSet<RESOURCEMANAGER> resourceManagers;

        public _ProjectionRead__check_inv_18(BSet<RESOURCEMANAGER> resourceManagers) {
            this.resourceManagers = resourceManagers;
        }

        public String toString() {
            return "{" + "resourceManagers: " + this.resourceManagers + "}";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _ProjectionRead__check_inv_18)) {
                return false;
            }
            _ProjectionRead__check_inv_18 o = (_ProjectionRead__check_inv_18) other;
            return this.resourceManagers.equals(o.resourceManagers);
        }

        public int hashCode() {
            return Objects.hash(resourceManagers);
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
            return new BBoolean(this.soc.equals(o.soc) && this.err.equals(o.err));
        }

        public BBoolean unequal(_Struct5 o) {
            return new BBoolean(!(this.soc.equals(o.soc)) || !(this.err.equals(o.err)));
        }

        public String toString() {
            return "(" + "soc : " + this.soc + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct5)) {
                return false;
            }
            _Struct5 o = (_Struct5) other;
            return this.soc.equals(o.soc) && this.err.equals(o.err);
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
            return new BBoolean(this.sid.equals(o.sid) && this.err.equals(o.err));
        }

        public BBoolean unequal(_Struct3 o) {
            return new BBoolean(!(this.sid.equals(o.sid)) || !(this.err.equals(o.err)));
        }

        public String toString() {
            return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct3)) {
                return false;
            }
            _Struct3 o = (_Struct3) other;
            return this.sid.equals(o.sid) && this.err.equals(o.err);
        }

        public int hashCode() {
            return Objects.hash(sid, err);
        }
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
            return new BBoolean(this.sid.equals(o.sid) && this.err.equals(o.err));
        }

        public BBoolean unequal(_Struct1 o) {
            return new BBoolean(!(this.sid.equals(o.sid)) || !(this.err.equals(o.err)));
        }

        public String toString() {
            return "(" + "sid : " + this.sid + "," + "err : " + this.err + ")";
        }

        public boolean equals(Object other) {
            if(!(other instanceof _Struct1)) {
                return false;
            }
            _Struct1 o = (_Struct1) other;
            return this.sid.equals(o.sid) && this.err.equals(o.err);
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

    public nota_v2(nota_v2 copy) {
        this.interconnectNodes = copy.interconnectNodes;
        this.sockets = copy.sockets;
        this.services = copy.services;
        this.resourceManagers = copy.resourceManagers;
        this.sids = copy.sids;
        this.rm_services = copy.rm_services;
        this.rm_sids = copy.rm_sids;
        this.in_localServices = copy.in_localServices;
        this.in_sockets = copy.in_sockets;
        this.in_resourceManager = copy.in_resourceManager;
        this.soc_to = copy.soc_to;
        this.soc_from = copy.soc_from;
        this.svc_serviceID = copy.svc_serviceID;
        this.svc_sockets = copy.svc_sockets;
        this.svc_ICNode = copy.svc_ICNode;
        this.svc_registered = copy.svc_registered;
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
        in_localServices = _ld_in_localServices.union(new BRelation<SID, INTERCONNECTNODE>(new BTuple<SID, INTERCONNECTNODE>(si, self)));
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
        in_sockets = _ld_in_sockets.union(new BRelation<SOCKET, INTERCONNECTNODE>(new BTuple<SOCKET, INTERCONNECTNODE>(newsoc, self)));
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

    public nota_v2 _copy() {
        return new nota_v2(this);
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
        if(resourceManagers.equal(new BSet<RESOURCEMANAGER>()).booleanValue()) {
            for(RESOURCEMANAGER _ic_newrm_1 : _RESOURCEMANAGER.difference(resourceManagers)) {
                if((rm_services.isNotInDomain(_ic_newrm_1)).booleanValue()) {
                    _ic_set_1 = _ic_set_1.union(new BSet<RESOURCEMANAGER>(_ic_newrm_1));
                }

            }

        }
        return _ic_set_1;
    }

    public BSet<BTuple<INTERCONNECTNODE, SERVICE>> _tr_constructor_service() {
        BSet<BTuple<INTERCONNECTNODE, SERVICE>> _ic_set_2 = new BSet<BTuple<INTERCONNECTNODE, SERVICE>>();
        for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
            for(SERVICE _ic_newsvc_1 : _SERVICE.difference(services)) {
                _ic_set_2 = _ic_set_2.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple<INTERCONNECTNODE, SERVICE>(_ic_ii_1, _ic_newsvc_1)));

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
                        _ic_set_3 = _ic_set_3.union(new BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>(new BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>(new BTuple<BTuple<INTERCONNECTNODE, SID>, SID>(new BTuple<INTERCONNECTNODE, SID>(_ic_ii_1, _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));

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
                    _ic_set_4 = _ic_set_4.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>(new BTuple<RESOURCEMANAGER, SERVICE>(_ic_self_1, _ic_ss_1), _ic_ii_1)));

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
                    _ic_set_5 = _ic_set_5.union(new BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>(new BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>(new BTuple<RESOURCEMANAGER, SERVICE>(_ic_self_1, _ic_ss_1), _ic_ii_1)));

                }

            }

        }

        return _ic_set_5;
    }

    public BSet<BTuple<RESOURCEMANAGER, SERVICE>> _tr_rm_getSid() {
        BSet<BTuple<RESOURCEMANAGER, SERVICE>> _ic_set_6 = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                if((rm_sids.isInDomain(_ic_ss_1)).booleanValue()) {
                    _ic_set_6 = _ic_set_6.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple<RESOURCEMANAGER, SERVICE>(_ic_self_1, _ic_ss_1)));
                }

            }

        }

        return _ic_set_6;
    }

    public BSet<BTuple<RESOURCEMANAGER, SERVICE>> _tr_rm_getSid_Not_Found() {
        BSet<BTuple<RESOURCEMANAGER, SERVICE>> _ic_set_7 = new BSet<BTuple<RESOURCEMANAGER, SERVICE>>();
        for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
            for(SERVICE _ic_ss_1 : services) {
                _ic_set_7 = _ic_set_7.union(new BSet<BTuple<RESOURCEMANAGER, SERVICE>>(new BTuple<RESOURCEMANAGER, SERVICE>(_ic_self_1, _ic_ss_1)));

            }

        }

        return _ic_set_7;
    }

    public BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _tr_in_announceResourceManager() {
        BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _ic_set_8 = new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(RESOURCEMANAGER _ic_rm_1 : resourceManagers) {
                if((in_resourceManager.functionCall(_ic_self_1).equal(new BSet<RESOURCEMANAGER>())).booleanValue()) {
                    _ic_set_8 = _ic_set_8.union(new BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>(new BTuple<INTERCONNECTNODE, RESOURCEMANAGER>(_ic_self_1, _ic_rm_1)));
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
                    if((in_localServices.isInDomain(_ic_si_1).not()).booleanValue()) {
                        _ic_set_9 = _ic_set_9.union(new BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>(new BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>(new BTuple<INTERCONNECTNODE, SERVICE>(_ic_self_1, _ic_ss_1), _ic_si_1)));
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
                _ic_set_10 = _ic_set_10.union(new BSet<BTuple<INTERCONNECTNODE, SERVICE>>(new BTuple<INTERCONNECTNODE, SERVICE>(_ic_self_1, _ic_ss_1)));

            }

        }

        return _ic_set_10;
    }

    public BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _tr_in_requestTargetSocket_Granted() {
        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _ic_set_11 = new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>();
        for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
            for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                if(_ic_self_1.unequal(_ic_ii_1).booleanValue()) {
                    for(SOCKET _ic_srcsoc_1 : sockets) {
                        if(in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue()) {
                            for(SID _ic_srcsid_1 : sids) {
                                for(SID _ic_targsid_1 : sids) {
                                    for(SOCKET _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                                        _ic_set_11 = _ic_set_11.union(new BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>(new BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>(new BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>(new BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>(new BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>(new BTuple<INTERCONNECTNODE, INTERCONNECTNODE>(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1), _ic_newsoc_1)));

                                    }

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
                if(_ic_self_1.unequal(_ic_ii_1).booleanValue()) {
                    for(SOCKET _ic_srcsoc_1 : sockets) {
                        if(in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue()) {
                            for(SID _ic_srcsid_1 : sids) {
                                for(SID _ic_targsid_1 : sids) {
                                    _ic_set_12 = _ic_set_12.union(new BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>(new BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>(new BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>(new BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>(new BTuple<INTERCONNECTNODE, INTERCONNECTNODE>(_ic_self_1, _ic_ii_1), _ic_srcsoc_1), _ic_srcsid_1), _ic_targsid_1)));

                                }

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

    public _ProjectionRead_in_register_success _projected_state_for_in_register_success() {
        return new _ProjectionRead_in_register_success(sids,interconnectNodes,in_localServices,services);
    }

    public _ProjectionRead_in_announceResourceManager _projected_state_for_in_announceResourceManager() {
        return new _ProjectionRead_in_announceResourceManager(interconnectNodes,in_resourceManager,resourceManagers);
    }

    public _ProjectionRead_in_requestTargetSocket_Granted _projected_state_for_in_requestTargetSocket_Granted() {
        return new _ProjectionRead_in_requestTargetSocket_Granted(interconnectNodes,sids,in_sockets,soc_to,soc_from,sockets);
    }

    public _ProjectionRead_constructor_service _projected_state_for_constructor_service() {
        return new _ProjectionRead_constructor_service(interconnectNodes,svc_registered,svc_sockets,services,svc_ICNode);
    }

    public _ProjectionRead_constructor_socket _projected_state_for_constructor_socket() {
        return new _ProjectionRead_constructor_socket(sids,interconnectNodes,in_sockets,soc_to,soc_from,sockets);
    }

    public _ProjectionRead_in_requestTargetSocket_NotGranted _projected_state_for_in_requestTargetSocket_NotGranted() {
        return new _ProjectionRead_in_requestTargetSocket_NotGranted(sids,interconnectNodes,in_sockets,sockets);
    }

    public _ProjectionRead_constructor_interconnectNode _projected_state_for_constructor_interconnectNode() {
        return new _ProjectionRead_constructor_interconnectNode(interconnectNodes,in_resourceManager);
    }

    public _ProjectionRead_rm_getSid _projected_state_for_rm_getSid() {
        return new _ProjectionRead_rm_getSid(services,resourceManagers,rm_sids);
    }

    public _ProjectionRead_rm_deregister _projected_state_for_rm_deregister() {
        return new _ProjectionRead_rm_deregister(interconnectNodes,services,resourceManagers);
    }

    public _ProjectionRead_constructor_resourceManager _projected_state_for_constructor_resourceManager() {
        return new _ProjectionRead_constructor_resourceManager(rm_services,resourceManagers);
    }

    public _ProjectionRead_in_register_failed _projected_state_for_in_register_failed() {
        return new _ProjectionRead_in_register_failed(interconnectNodes,services);
    }

    public _ProjectionRead_rm_register _projected_state_for_rm_register() {
        return new _ProjectionRead_rm_register(interconnectNodes,services,resourceManagers);
    }

    public _ProjectionRead_rm_getSid_Not_Found _projected_state_for_rm_getSid_Not_Found() {
        return new _ProjectionRead_rm_getSid_Not_Found(services,resourceManagers);
    }

    public _ProjectionRead_svc_register _projected_state_for_svc_register() {
        return new _ProjectionRead_svc_register(svc_registered,services);
    }

    public _ProjectionRead__tr_constructor_resourceManager _projected_state_for__tr_constructor_resourceManager() {
        return new _ProjectionRead__tr_constructor_resourceManager(rm_services,resourceManagers);
    }

    public _ProjectionRead__tr_in_register_failed _projected_state_for__tr_in_register_failed() {
        return new _ProjectionRead__tr_in_register_failed(interconnectNodes,services);
    }

    public _ProjectionRead__tr_rm_register _projected_state_for__tr_rm_register() {
        return new _ProjectionRead__tr_rm_register(interconnectNodes,services,resourceManagers);
    }

    public _ProjectionRead__tr_rm_getSid_Not_Found _projected_state_for__tr_rm_getSid_Not_Found() {
        return new _ProjectionRead__tr_rm_getSid_Not_Found(services,resourceManagers);
    }

    public _ProjectionRead__tr_in_requestTargetSocket_NotGranted _projected_state_for__tr_in_requestTargetSocket_NotGranted() {
        return new _ProjectionRead__tr_in_requestTargetSocket_NotGranted(sids,interconnectNodes,in_sockets,sockets);
    }

    public _ProjectionRead__tr_constructor_socket _projected_state_for__tr_constructor_socket() {
        return new _ProjectionRead__tr_constructor_socket(sids,interconnectNodes,sockets);
    }

    public _ProjectionRead__tr_rm_deregister _projected_state_for__tr_rm_deregister() {
        return new _ProjectionRead__tr_rm_deregister(interconnectNodes,services,resourceManagers);
    }

    public _ProjectionRead__tr_in_announceResourceManager _projected_state_for__tr_in_announceResourceManager() {
        return new _ProjectionRead__tr_in_announceResourceManager(interconnectNodes,in_resourceManager,resourceManagers);
    }

    public _ProjectionRead__tr_constructor_service _projected_state_for__tr_constructor_service() {
        return new _ProjectionRead__tr_constructor_service(interconnectNodes,services);
    }

    public _ProjectionRead__tr_rm_getSid _projected_state_for__tr_rm_getSid() {
        return new _ProjectionRead__tr_rm_getSid(services,resourceManagers,rm_sids);
    }

    public _ProjectionRead__tr_in_register_success _projected_state_for__tr_in_register_success() {
        return new _ProjectionRead__tr_in_register_success(sids,interconnectNodes,in_localServices,services);
    }

    public _ProjectionRead__tr_svc_register _projected_state_for__tr_svc_register() {
        return new _ProjectionRead__tr_svc_register(svc_registered,services);
    }

    public _ProjectionRead__tr_in_requestTargetSocket_Granted _projected_state_for__tr_in_requestTargetSocket_Granted() {
        return new _ProjectionRead__tr_in_requestTargetSocket_Granted(sids,interconnectNodes,in_sockets,sockets);
    }

    public _ProjectionRead__tr_constructor_interconnectNode _projected_state_for__tr_constructor_interconnectNode() {
        return new _ProjectionRead__tr_constructor_interconnectNode(interconnectNodes);
    }

    public _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() {
        return new _ProjectionRead__check_inv_18(resourceManagers);
    }

    public _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() {
        return new _ProjectionRead__check_inv_17(svc_registered,services);
    }

    public _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() {
        return new _ProjectionRead__check_inv_16(interconnectNodes,services,svc_ICNode);
    }

    public _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() {
        return new _ProjectionRead__check_inv_15(svc_sockets,services,sockets);
    }

    public _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() {
        return new _ProjectionRead__check_inv_6(rm_services,services,resourceManagers);
    }

    public _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() {
        return new _ProjectionRead__check_inv_10(interconnectNodes,in_sockets,sockets);
    }

    public _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() {
        return new _ProjectionRead__check_inv_7(rm_services);
    }

    public _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() {
        return new _ProjectionRead__check_inv_4(resourceManagers);
    }

    public _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() {
        return new _ProjectionRead__check_inv_5(sids);
    }

    public _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() {
        return new _ProjectionRead__check_inv_14(sids,services,svc_serviceID);
    }

    public _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() {
        return new _ProjectionRead__check_inv_13(sids,soc_from,sockets);
    }

    public _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() {
        return new _ProjectionRead__check_inv_8(sids,services,rm_sids);
    }

    public _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() {
        return new _ProjectionRead__check_inv_12(sids,soc_to,sockets);
    }

    public _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() {
        return new _ProjectionRead__check_inv_9(sids,interconnectNodes,in_localServices);
    }

    public _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() {
        return new _ProjectionRead__check_inv_11(interconnectNodes,in_resourceManager,resourceManagers);
    }

    public _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() {
        return new _ProjectionRead__check_inv_2(sockets);
    }

    public _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() {
        return new _ProjectionRead__check_inv_3(services);
    }

    public _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() {
        return new _ProjectionRead__check_inv_1(interconnectNodes);
    }

    public _ProjectionWrite_in_register_success _update_for_in_register_success() {
        return new _ProjectionWrite_in_register_success(sids,in_localServices);
    }

    public _ProjectionWrite_in_announceResourceManager _update_for_in_announceResourceManager() {
        return new _ProjectionWrite_in_announceResourceManager(in_resourceManager);
    }

    public _ProjectionWrite_in_requestTargetSocket_Granted _update_for_in_requestTargetSocket_Granted() {
        return new _ProjectionWrite_in_requestTargetSocket_Granted(in_sockets,soc_to,soc_from,sockets);
    }

    public _ProjectionWrite_constructor_service _update_for_constructor_service() {
        return new _ProjectionWrite_constructor_service(svc_registered,svc_sockets,services,svc_serviceID,svc_ICNode);
    }

    public _ProjectionWrite_constructor_socket _update_for_constructor_socket() {
        return new _ProjectionWrite_constructor_socket(in_sockets,soc_to,soc_from,sockets);
    }

    public _ProjectionWrite_in_requestTargetSocket_NotGranted _update_for_in_requestTargetSocket_NotGranted() {
        return new _ProjectionWrite_in_requestTargetSocket_NotGranted();
    }

    public _ProjectionWrite_constructor_interconnectNode _update_for_constructor_interconnectNode() {
        return new _ProjectionWrite_constructor_interconnectNode(interconnectNodes,in_resourceManager);
    }

    public _ProjectionWrite_rm_getSid _update_for_rm_getSid() {
        return new _ProjectionWrite_rm_getSid();
    }

    public _ProjectionWrite_rm_deregister _update_for_rm_deregister() {
        return new _ProjectionWrite_rm_deregister();
    }

    public _ProjectionWrite_constructor_resourceManager _update_for_constructor_resourceManager() {
        return new _ProjectionWrite_constructor_resourceManager(rm_services,resourceManagers);
    }

    public _ProjectionWrite_in_register_failed _update_for_in_register_failed() {
        return new _ProjectionWrite_in_register_failed();
    }

    public _ProjectionWrite_rm_register _update_for_rm_register() {
        return new _ProjectionWrite_rm_register();
    }

    public _ProjectionWrite_rm_getSid_Not_Found _update_for_rm_getSid_Not_Found() {
        return new _ProjectionWrite_rm_getSid_Not_Found();
    }

    public _ProjectionWrite_svc_register _update_for_svc_register() {
        return new _ProjectionWrite_svc_register(svc_registered);
    }

    public void _apply_update_for_in_register_success(_ProjectionWrite_in_register_success update) {
        this.sids = update.sids;
        this.in_localServices = update.in_localServices;
    }

    public void _apply_update_for_in_announceResourceManager(_ProjectionWrite_in_announceResourceManager update) {
        this.in_resourceManager = update.in_resourceManager;
    }

    public void _apply_update_for_in_requestTargetSocket_Granted(_ProjectionWrite_in_requestTargetSocket_Granted update) {
        this.in_sockets = update.in_sockets;
        this.soc_to = update.soc_to;
        this.soc_from = update.soc_from;
        this.sockets = update.sockets;
    }

    public void _apply_update_for_constructor_service(_ProjectionWrite_constructor_service update) {
        this.svc_registered = update.svc_registered;
        this.svc_sockets = update.svc_sockets;
        this.services = update.services;
        this.svc_serviceID = update.svc_serviceID;
        this.svc_ICNode = update.svc_ICNode;
    }

    public void _apply_update_for_constructor_socket(_ProjectionWrite_constructor_socket update) {
        this.in_sockets = update.in_sockets;
        this.soc_to = update.soc_to;
        this.soc_from = update.soc_from;
        this.sockets = update.sockets;
    }

    public void _apply_update_for_in_requestTargetSocket_NotGranted(_ProjectionWrite_in_requestTargetSocket_NotGranted update) {
    }

    public void _apply_update_for_constructor_interconnectNode(_ProjectionWrite_constructor_interconnectNode update) {
        this.interconnectNodes = update.interconnectNodes;
        this.in_resourceManager = update.in_resourceManager;
    }

    public void _apply_update_for_rm_getSid(_ProjectionWrite_rm_getSid update) {
    }

    public void _apply_update_for_rm_deregister(_ProjectionWrite_rm_deregister update) {
    }

    public void _apply_update_for_constructor_resourceManager(_ProjectionWrite_constructor_resourceManager update) {
        this.rm_services = update.rm_services;
        this.resourceManagers = update.resourceManagers;
    }

    public void _apply_update_for_in_register_failed(_ProjectionWrite_in_register_failed update) {
    }

    public void _apply_update_for_rm_register(_ProjectionWrite_rm_register update) {
    }

    public void _apply_update_for_rm_getSid_Not_Found(_ProjectionWrite_rm_getSid_Not_Found update) {
    }

    public void _apply_update_for_svc_register(_ProjectionWrite_svc_register update) {
        this.svc_registered = update.svc_registered;
    }

    public boolean _check_inv_1() {
        BBoolean _ic_boolean_14 = new BBoolean(true);
        for(INTERCONNECTNODE _ic__opt_1_1 : interconnectNodes) {
            if(!(_INTERCONNECTNODE.elementOf(_ic__opt_1_1)).booleanValue()) {
                _ic_boolean_14 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_14.booleanValue();
    }

    public boolean _check_inv_2() {
        BBoolean _ic_boolean_15 = new BBoolean(true);
        for(SOCKET _ic__opt_2_1 : sockets) {
            if(!(_SOCKET.elementOf(_ic__opt_2_1)).booleanValue()) {
                _ic_boolean_15 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_15.booleanValue();
    }

    public boolean _check_inv_3() {
        BBoolean _ic_boolean_16 = new BBoolean(true);
        for(SERVICE _ic__opt_3_1 : services) {
            if(!(_SERVICE.elementOf(_ic__opt_3_1)).booleanValue()) {
                _ic_boolean_16 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_16.booleanValue();
    }

    public boolean _check_inv_4() {
        BBoolean _ic_boolean_17 = new BBoolean(true);
        for(RESOURCEMANAGER _ic__opt_4_1 : resourceManagers) {
            if(!(_RESOURCEMANAGER.elementOf(_ic__opt_4_1)).booleanValue()) {
                _ic_boolean_17 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_17.booleanValue();
    }

    public boolean _check_inv_5() {
        BBoolean _ic_boolean_18 = new BBoolean(true);
        for(SID _ic__opt_5_1 : sids) {
            if(!(_SID.elementOf(_ic__opt_5_1)).booleanValue()) {
                _ic_boolean_18 = new BBoolean(false);
                break;
            }

        }

        return _ic_boolean_18.booleanValue();
    }

    public boolean _check_inv_6() {
        return rm_services.checkDomain(resourceManagers).and(rm_services.checkRange(services.pow())).and(rm_services.isFunction()).and(rm_services.isTotal(resourceManagers)).booleanValue();
    }

    public boolean _check_inv_7() {
        BBoolean _ic_boolean_19 = new BBoolean(true);
        for(RESOURCEMANAGER _ic_a1_1 : rm_services.domain()) {
            for(RESOURCEMANAGER _ic_a2_1 : rm_services.domain()) {
                if(!(new BBoolean(!_ic_a1_1.unequal(_ic_a2_1).booleanValue() || rm_services.functionCall(_ic_a1_1).intersect(rm_services.functionCall(_ic_a2_1)).equal(new BSet<SERVICE>()).booleanValue())).booleanValue()) {
                    _ic_boolean_19 = new BBoolean(false);
                    break;
                }

            }

        }

        return _ic_boolean_19.booleanValue();
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
        return svc_registered.checkDomain(services).and(svc_registered.checkRangeBoolean()).and(svc_registered.isFunction()).and(svc_registered.isTotal(services)).booleanValue();
    }

    public boolean _check_inv_18() {
        return new BBoolean(!resourceManagers.equal(new BSet<RESOURCEMANAGER>()).not().booleanValue() || resourceManagers.card().equal(new BInteger(1)).booleanValue()).booleanValue();
    }


    private static class ModelChecker {
        private final Type type;
        private final int threads;
        private final boolean isCaching;
        private final boolean isDebug;

        private final LinkedList<nota_v2> unvisitedStates = new LinkedList<>();
        private final Set<nota_v2> states = ConcurrentHashMap.newKeySet();
        private AtomicInteger transitions = new AtomicInteger(0);
        private ThreadPoolExecutor threadPool;
        private Object waitLock = new Object();

        private AtomicBoolean invariantViolated = new AtomicBoolean(false);
        private AtomicBoolean deadlockDetected = new AtomicBoolean(false);
        private nota_v2 counterExampleState = null;

        PersistentHashMap _OpCache_constructor_interconnectNode = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_constructor_interconnectNode = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_constructor_resourceManager = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_constructor_resourceManager = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_constructor_service = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_constructor_service = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_constructor_socket = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_constructor_socket = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_rm_register = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_rm_register = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_rm_deregister = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_rm_deregister = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_rm_getSid = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_rm_getSid = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_rm_getSid_Not_Found = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_rm_getSid_Not_Found = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_in_announceResourceManager = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_in_announceResourceManager = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_in_register_success = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_in_register_success = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_in_register_failed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_in_register_failed = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_in_requestTargetSocket_Granted = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_in_requestTargetSocket_Granted = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_in_requestTargetSocket_NotGranted = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_in_requestTargetSocket_NotGranted = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_svc_register = PersistentHashMap.EMPTY;
        PersistentHashMap _OpCache_tr_svc_register = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_1 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_2 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_3 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_4 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_5 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_6 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_7 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_8 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_9 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_10 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_11 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_12 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_13 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_14 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_15 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_16 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_17 = PersistentHashMap.EMPTY;
        PersistentHashMap _InvCache__check_inv_18 = PersistentHashMap.EMPTY;

        public ModelChecker(final Type type, final int threads, final boolean isCaching, final boolean isDebug) {
            this.type = type;
            this.threads = threads;
            this.isCaching = isCaching;
            this.isDebug = isDebug;
        }

        public void modelCheck() {
            if (isDebug) {
                System.out.println("Starting Modelchecking, STRATEGY=" + type + ", THREADS=" + threads + ", CACHING=" + isCaching);
            }

            if (threads <= 1) {

                modelCheckSingleThreaded();
            } else {
                this.threadPool = (ThreadPoolExecutor) Executors.newFixedThreadPool(threads-1);
                modelCheckMultiThreaded();
            }
        }

        private void modelCheckSingleThreaded() {
            nota_v2 machine = new nota_v2();
            states.add(machine);
            unvisitedStates.add(machine);

            while(!unvisitedStates.isEmpty()) {
                nota_v2 state = next();

                Set<nota_v2> nextStates = generateNextStates(state);

                nextStates.forEach(nextState -> {
                    if(!states.contains(nextState)) {
                        states.add(nextState);
                        unvisitedStates.add(nextState);
                        if(isDebug && states.size() % 50000 == 0) {
                            System.out.println("VISITED STATES: " + states.size());
                            System.out.println("OPEN STATES: " + unvisitedStates.size());
                            System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                            System.out.println("-------------------");
                        }
                    }
                });

                if(invariantViolated(state)) {
                    invariantViolated.set(true);
                    counterExampleState = state;
                    break;
                }

                if(nextStates.isEmpty()) {
                    deadlockDetected.set(true);
                    counterExampleState = state;
                    break;
                }

            }
            printResult(states.size(), transitions.get());
        }

        private void modelCheckMultiThreaded() {
            nota_v2 machine = new nota_v2();
            states.add(machine);
            unvisitedStates.add(machine);

            AtomicBoolean stopThreads = new AtomicBoolean(false);
            AtomicInteger possibleQueueChanges = new AtomicInteger(0);

            while(!unvisitedStates.isEmpty() && !stopThreads.get()) {
                possibleQueueChanges.incrementAndGet();
                nota_v2 state = next();
                Runnable task = () -> {
                    Set<nota_v2> nextStates = generateNextStates(state);

                    nextStates.forEach(nextState -> {
                        if(states.add(nextState)) {
                            synchronized (unvisitedStates) {
                                unvisitedStates.add(nextState);
                            }
                            if(isDebug && states.size() % 50000 == 0) {
                                System.out.println("VISITED STATES: " + states.size());
                                System.out.println("OPEN STATES: " + unvisitedStates.size());
                                System.out.println("EVALUATED TRANSITIONS: " + transitions.get());
                                System.out.println("-------------------");
                            }
                        }
                    });

                    int running = possibleQueueChanges.decrementAndGet();
                    synchronized (unvisitedStates) {
                        if (!unvisitedStates.isEmpty() || running == 0) {
                            synchronized (waitLock) {
                                waitLock.notify();
                            }
                        }
                    }

                    if(invariantViolated(state)) {
                        invariantViolated.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }

                    if(nextStates.isEmpty()) {
                        deadlockDetected.set(true);
                        counterExampleState = state;
                        stopThreads.set(true);
                    }
                };
                threadPool.submit(task);
                synchronized(waitLock) {
                    if (unvisitedStates.isEmpty() && possibleQueueChanges.get() > 0) {
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
                threadPool.awaitTermination(24, TimeUnit.HOURS);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            printResult(states.size(), transitions.get());
        }

        private nota_v2 next() {
            synchronized(this.unvisitedStates) {
                return switch(type) {
                    case BFS -> this.unvisitedStates.removeFirst();
                    case DFS -> this.unvisitedStates.removeLast();
                    case MIXED -> this.unvisitedStates.size() % 2 == 0 ? this.unvisitedStates.removeFirst() : this.unvisitedStates.removeLast();
                };
            }
        }

        @SuppressWarnings("unchecked")
        private Set<nota_v2> generateNextStates(final nota_v2 state) {
            Set<nota_v2> result = new HashSet<>();
            if(isCaching) {
                _ProjectionRead__tr_constructor_interconnectNode read__tr_constructor_interconnectNode_state = state._projected_state_for__tr_constructor_interconnectNode();
                BSet<INTERCONNECTNODE> _trid_1 = (BSet<INTERCONNECTNODE>) GET.invoke(_OpCache_tr_constructor_interconnectNode, read__tr_constructor_interconnectNode_state);
                if(_trid_1 == null) {
                    _trid_1 = state._tr_constructor_interconnectNode();
                    _OpCache_tr_constructor_interconnectNode = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_constructor_interconnectNode, read__tr_constructor_interconnectNode_state, _trid_1);
                }
                for(INTERCONNECTNODE param : _trid_1) {
                    INTERCONNECTNODE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_constructor_interconnectNode readState = state._projected_state_for_constructor_interconnectNode();
                    PersistentHashMap _OpCache_with_parameter_constructor_interconnectNode = (PersistentHashMap) GET.invoke(_OpCache_constructor_interconnectNode, param);
                    if(_OpCache_with_parameter_constructor_interconnectNode != null) {
                        _ProjectionWrite_constructor_interconnectNode writeState = (_ProjectionWrite_constructor_interconnectNode) GET.invoke(_OpCache_with_parameter_constructor_interconnectNode, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_constructor_interconnectNode(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.constructor_interconnectNode(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_constructor_interconnectNode();
                            _OpCache_with_parameter_constructor_interconnectNode = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_constructor_interconnectNode, readState, writeState);
                            _OpCache_constructor_interconnectNode = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_interconnectNode, param, _OpCache_with_parameter_constructor_interconnectNode);
                        }

                    } else {
                        copiedState.constructor_interconnectNode(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_constructor_interconnectNode writeState = copiedState._update_for_constructor_interconnectNode();
                        _OpCache_with_parameter_constructor_interconnectNode = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_constructor_interconnectNode = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_interconnectNode, param, _OpCache_with_parameter_constructor_interconnectNode);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_constructor_resourceManager read__tr_constructor_resourceManager_state = state._projected_state_for__tr_constructor_resourceManager();
                BSet<RESOURCEMANAGER> _trid_2 = (BSet<RESOURCEMANAGER>) GET.invoke(_OpCache_tr_constructor_resourceManager, read__tr_constructor_resourceManager_state);
                if(_trid_2 == null) {
                    _trid_2 = state._tr_constructor_resourceManager();
                    _OpCache_tr_constructor_resourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_constructor_resourceManager, read__tr_constructor_resourceManager_state, _trid_2);
                }
                for(RESOURCEMANAGER param : _trid_2) {
                    RESOURCEMANAGER _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_constructor_resourceManager readState = state._projected_state_for_constructor_resourceManager();
                    PersistentHashMap _OpCache_with_parameter_constructor_resourceManager = (PersistentHashMap) GET.invoke(_OpCache_constructor_resourceManager, param);
                    if(_OpCache_with_parameter_constructor_resourceManager != null) {
                        _ProjectionWrite_constructor_resourceManager writeState = (_ProjectionWrite_constructor_resourceManager) GET.invoke(_OpCache_with_parameter_constructor_resourceManager, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_constructor_resourceManager(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.constructor_resourceManager(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_constructor_resourceManager();
                            _OpCache_with_parameter_constructor_resourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_constructor_resourceManager, readState, writeState);
                            _OpCache_constructor_resourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_resourceManager, param, _OpCache_with_parameter_constructor_resourceManager);
                        }

                    } else {
                        copiedState.constructor_resourceManager(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_constructor_resourceManager writeState = copiedState._update_for_constructor_resourceManager();
                        _OpCache_with_parameter_constructor_resourceManager = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_constructor_resourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_resourceManager, param, _OpCache_with_parameter_constructor_resourceManager);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_constructor_service read__tr_constructor_service_state = state._projected_state_for__tr_constructor_service();
                BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_3 = (BSet<BTuple<INTERCONNECTNODE, SERVICE>>) GET.invoke(_OpCache_tr_constructor_service, read__tr_constructor_service_state);
                if(_trid_3 == null) {
                    _trid_3 = state._tr_constructor_service();
                    _OpCache_tr_constructor_service = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_constructor_service, read__tr_constructor_service_state, _trid_3);
                }
                for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_3) {
                    SERVICE _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_constructor_service readState = state._projected_state_for_constructor_service();
                    PersistentHashMap _OpCache_with_parameter_constructor_service = (PersistentHashMap) GET.invoke(_OpCache_constructor_service, param);
                    if(_OpCache_with_parameter_constructor_service != null) {
                        _ProjectionWrite_constructor_service writeState = (_ProjectionWrite_constructor_service) GET.invoke(_OpCache_with_parameter_constructor_service, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_constructor_service(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.constructor_service(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_constructor_service();
                            _OpCache_with_parameter_constructor_service = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_constructor_service, readState, writeState);
                            _OpCache_constructor_service = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_service, param, _OpCache_with_parameter_constructor_service);
                        }

                    } else {
                        copiedState.constructor_service(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_constructor_service writeState = copiedState._update_for_constructor_service();
                        _OpCache_with_parameter_constructor_service = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_constructor_service = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_service, param, _OpCache_with_parameter_constructor_service);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_constructor_socket read__tr_constructor_socket_state = state._projected_state_for__tr_constructor_socket();
                BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>> _trid_4 = (BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET>>) GET.invoke(_OpCache_tr_constructor_socket, read__tr_constructor_socket_state);
                if(_trid_4 == null) {
                    _trid_4 = state._tr_constructor_socket();
                    _OpCache_tr_constructor_socket = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_constructor_socket, read__tr_constructor_socket_state, _trid_4);
                }
                for(BTuple<BTuple<BTuple<INTERCONNECTNODE, SID>, SID>, SOCKET> param : _trid_4) {
                    SOCKET _tmp_1 = param.projection2();
                    BTuple<BTuple<INTERCONNECTNODE, SID>, SID> _tmp_2 = param.projection1();
                    SID _tmp_3 = _tmp_2.projection2();
                    BTuple<INTERCONNECTNODE, SID> _tmp_4 = _tmp_2.projection1();
                    SID _tmp_5 = _tmp_4.projection2();
                    INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_constructor_socket readState = state._projected_state_for_constructor_socket();
                    PersistentHashMap _OpCache_with_parameter_constructor_socket = (PersistentHashMap) GET.invoke(_OpCache_constructor_socket, param);
                    if(_OpCache_with_parameter_constructor_socket != null) {
                        _ProjectionWrite_constructor_socket writeState = (_ProjectionWrite_constructor_socket) GET.invoke(_OpCache_with_parameter_constructor_socket, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_constructor_socket(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_constructor_socket();
                            _OpCache_with_parameter_constructor_socket = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_constructor_socket, readState, writeState);
                            _OpCache_constructor_socket = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_socket, param, _OpCache_with_parameter_constructor_socket);
                        }

                    } else {
                        copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_constructor_socket writeState = copiedState._update_for_constructor_socket();
                        _OpCache_with_parameter_constructor_socket = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_constructor_socket = (PersistentHashMap) ASSOC.invoke(_OpCache_constructor_socket, param, _OpCache_with_parameter_constructor_socket);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_rm_register read__tr_rm_register_state = state._projected_state_for__tr_rm_register();
                BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_5 = (BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>) GET.invoke(_OpCache_tr_rm_register, read__tr_rm_register_state);
                if(_trid_5 == null) {
                    _trid_5 = state._tr_rm_register();
                    _OpCache_tr_rm_register = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_rm_register, read__tr_rm_register_state, _trid_5);
                }
                for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_5) {
                    INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                    SERVICE _tmp_3 = _tmp_2.projection2();
                    RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_rm_register readState = state._projected_state_for_rm_register();
                    PersistentHashMap _OpCache_with_parameter_rm_register = (PersistentHashMap) GET.invoke(_OpCache_rm_register, param);
                    if(_OpCache_with_parameter_rm_register != null) {
                        _ProjectionWrite_rm_register writeState = (_ProjectionWrite_rm_register) GET.invoke(_OpCache_with_parameter_rm_register, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_rm_register(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_rm_register();
                            _OpCache_with_parameter_rm_register = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_rm_register, readState, writeState);
                            _OpCache_rm_register = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_register, param, _OpCache_with_parameter_rm_register);
                        }

                    } else {
                        copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_rm_register writeState = copiedState._update_for_rm_register();
                        _OpCache_with_parameter_rm_register = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_rm_register = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_register, param, _OpCache_with_parameter_rm_register);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_rm_deregister read__tr_rm_deregister_state = state._projected_state_for__tr_rm_deregister();
                BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>> _trid_6 = (BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE>>) GET.invoke(_OpCache_tr_rm_deregister, read__tr_rm_deregister_state);
                if(_trid_6 == null) {
                    _trid_6 = state._tr_rm_deregister();
                    _OpCache_tr_rm_deregister = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_rm_deregister, read__tr_rm_deregister_state, _trid_6);
                }
                for(BTuple<BTuple<RESOURCEMANAGER, SERVICE>, INTERCONNECTNODE> param : _trid_6) {
                    INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<RESOURCEMANAGER, SERVICE> _tmp_2 = param.projection1();
                    SERVICE _tmp_3 = _tmp_2.projection2();
                    RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_rm_deregister readState = state._projected_state_for_rm_deregister();
                    PersistentHashMap _OpCache_with_parameter_rm_deregister = (PersistentHashMap) GET.invoke(_OpCache_rm_deregister, param);
                    if(_OpCache_with_parameter_rm_deregister != null) {
                        _ProjectionWrite_rm_deregister writeState = (_ProjectionWrite_rm_deregister) GET.invoke(_OpCache_with_parameter_rm_deregister, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_rm_deregister(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_rm_deregister();
                            _OpCache_with_parameter_rm_deregister = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_rm_deregister, readState, writeState);
                            _OpCache_rm_deregister = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_deregister, param, _OpCache_with_parameter_rm_deregister);
                        }

                    } else {
                        copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_rm_deregister writeState = copiedState._update_for_rm_deregister();
                        _OpCache_with_parameter_rm_deregister = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_rm_deregister = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_deregister, param, _OpCache_with_parameter_rm_deregister);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_rm_getSid read__tr_rm_getSid_state = state._projected_state_for__tr_rm_getSid();
                BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_7 = (BSet<BTuple<RESOURCEMANAGER, SERVICE>>) GET.invoke(_OpCache_tr_rm_getSid, read__tr_rm_getSid_state);
                if(_trid_7 == null) {
                    _trid_7 = state._tr_rm_getSid();
                    _OpCache_tr_rm_getSid = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_rm_getSid, read__tr_rm_getSid_state, _trid_7);
                }
                for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_7) {
                    SERVICE _tmp_1 = param.projection2();
                    RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_rm_getSid readState = state._projected_state_for_rm_getSid();
                    PersistentHashMap _OpCache_with_parameter_rm_getSid = (PersistentHashMap) GET.invoke(_OpCache_rm_getSid, param);
                    if(_OpCache_with_parameter_rm_getSid != null) {
                        _ProjectionWrite_rm_getSid writeState = (_ProjectionWrite_rm_getSid) GET.invoke(_OpCache_with_parameter_rm_getSid, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_rm_getSid(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.rm_getSid(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_rm_getSid();
                            _OpCache_with_parameter_rm_getSid = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_rm_getSid, readState, writeState);
                            _OpCache_rm_getSid = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_getSid, param, _OpCache_with_parameter_rm_getSid);
                        }

                    } else {
                        copiedState.rm_getSid(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_rm_getSid writeState = copiedState._update_for_rm_getSid();
                        _OpCache_with_parameter_rm_getSid = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_rm_getSid = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_getSid, param, _OpCache_with_parameter_rm_getSid);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_rm_getSid_Not_Found read__tr_rm_getSid_Not_Found_state = state._projected_state_for__tr_rm_getSid_Not_Found();
                BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_8 = (BSet<BTuple<RESOURCEMANAGER, SERVICE>>) GET.invoke(_OpCache_tr_rm_getSid_Not_Found, read__tr_rm_getSid_Not_Found_state);
                if(_trid_8 == null) {
                    _trid_8 = state._tr_rm_getSid_Not_Found();
                    _OpCache_tr_rm_getSid_Not_Found = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_rm_getSid_Not_Found, read__tr_rm_getSid_Not_Found_state, _trid_8);
                }
                for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_8) {
                    SERVICE _tmp_1 = param.projection2();
                    RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_rm_getSid_Not_Found readState = state._projected_state_for_rm_getSid_Not_Found();
                    PersistentHashMap _OpCache_with_parameter_rm_getSid_Not_Found = (PersistentHashMap) GET.invoke(_OpCache_rm_getSid_Not_Found, param);
                    if(_OpCache_with_parameter_rm_getSid_Not_Found != null) {
                        _ProjectionWrite_rm_getSid_Not_Found writeState = (_ProjectionWrite_rm_getSid_Not_Found) GET.invoke(_OpCache_with_parameter_rm_getSid_Not_Found, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_rm_getSid_Not_Found(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_rm_getSid_Not_Found();
                            _OpCache_with_parameter_rm_getSid_Not_Found = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_rm_getSid_Not_Found, readState, writeState);
                            _OpCache_rm_getSid_Not_Found = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_getSid_Not_Found, param, _OpCache_with_parameter_rm_getSid_Not_Found);
                        }

                    } else {
                        copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_rm_getSid_Not_Found writeState = copiedState._update_for_rm_getSid_Not_Found();
                        _OpCache_with_parameter_rm_getSid_Not_Found = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_rm_getSid_Not_Found = (PersistentHashMap) ASSOC.invoke(_OpCache_rm_getSid_Not_Found, param, _OpCache_with_parameter_rm_getSid_Not_Found);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_in_announceResourceManager read__tr_in_announceResourceManager_state = state._projected_state_for__tr_in_announceResourceManager();
                BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _trid_9 = (BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>>) GET.invoke(_OpCache_tr_in_announceResourceManager, read__tr_in_announceResourceManager_state);
                if(_trid_9 == null) {
                    _trid_9 = state._tr_in_announceResourceManager();
                    _OpCache_tr_in_announceResourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_in_announceResourceManager, read__tr_in_announceResourceManager_state, _trid_9);
                }
                for(BTuple<INTERCONNECTNODE, RESOURCEMANAGER> param : _trid_9) {
                    RESOURCEMANAGER _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_in_announceResourceManager readState = state._projected_state_for_in_announceResourceManager();
                    PersistentHashMap _OpCache_with_parameter_in_announceResourceManager = (PersistentHashMap) GET.invoke(_OpCache_in_announceResourceManager, param);
                    if(_OpCache_with_parameter_in_announceResourceManager != null) {
                        _ProjectionWrite_in_announceResourceManager writeState = (_ProjectionWrite_in_announceResourceManager) GET.invoke(_OpCache_with_parameter_in_announceResourceManager, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_in_announceResourceManager(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_in_announceResourceManager();
                            _OpCache_with_parameter_in_announceResourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_in_announceResourceManager, readState, writeState);
                            _OpCache_in_announceResourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_in_announceResourceManager, param, _OpCache_with_parameter_in_announceResourceManager);
                        }

                    } else {
                        copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_in_announceResourceManager writeState = copiedState._update_for_in_announceResourceManager();
                        _OpCache_with_parameter_in_announceResourceManager = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_in_announceResourceManager = (PersistentHashMap) ASSOC.invoke(_OpCache_in_announceResourceManager, param, _OpCache_with_parameter_in_announceResourceManager);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_in_register_success read__tr_in_register_success_state = state._projected_state_for__tr_in_register_success();
                BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>> _trid_10 = (BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID>>) GET.invoke(_OpCache_tr_in_register_success, read__tr_in_register_success_state);
                if(_trid_10 == null) {
                    _trid_10 = state._tr_in_register_success();
                    _OpCache_tr_in_register_success = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_in_register_success, read__tr_in_register_success_state, _trid_10);
                }
                for(BTuple<BTuple<INTERCONNECTNODE, SERVICE>, SID> param : _trid_10) {
                    SID _tmp_1 = param.projection2();
                    BTuple<INTERCONNECTNODE, SERVICE> _tmp_2 = param.projection1();
                    SERVICE _tmp_3 = _tmp_2.projection2();
                    INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_in_register_success readState = state._projected_state_for_in_register_success();
                    PersistentHashMap _OpCache_with_parameter_in_register_success = (PersistentHashMap) GET.invoke(_OpCache_in_register_success, param);
                    if(_OpCache_with_parameter_in_register_success != null) {
                        _ProjectionWrite_in_register_success writeState = (_ProjectionWrite_in_register_success) GET.invoke(_OpCache_with_parameter_in_register_success, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_in_register_success(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_in_register_success();
                            _OpCache_with_parameter_in_register_success = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_in_register_success, readState, writeState);
                            _OpCache_in_register_success = (PersistentHashMap) ASSOC.invoke(_OpCache_in_register_success, param, _OpCache_with_parameter_in_register_success);
                        }

                    } else {
                        copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_in_register_success writeState = copiedState._update_for_in_register_success();
                        _OpCache_with_parameter_in_register_success = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_in_register_success = (PersistentHashMap) ASSOC.invoke(_OpCache_in_register_success, param, _OpCache_with_parameter_in_register_success);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_in_register_failed read__tr_in_register_failed_state = state._projected_state_for__tr_in_register_failed();
                BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_11 = (BSet<BTuple<INTERCONNECTNODE, SERVICE>>) GET.invoke(_OpCache_tr_in_register_failed, read__tr_in_register_failed_state);
                if(_trid_11 == null) {
                    _trid_11 = state._tr_in_register_failed();
                    _OpCache_tr_in_register_failed = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_in_register_failed, read__tr_in_register_failed_state, _trid_11);
                }
                for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_11) {
                    SERVICE _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_in_register_failed readState = state._projected_state_for_in_register_failed();
                    PersistentHashMap _OpCache_with_parameter_in_register_failed = (PersistentHashMap) GET.invoke(_OpCache_in_register_failed, param);
                    if(_OpCache_with_parameter_in_register_failed != null) {
                        _ProjectionWrite_in_register_failed writeState = (_ProjectionWrite_in_register_failed) GET.invoke(_OpCache_with_parameter_in_register_failed, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_in_register_failed(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.in_register_failed(_tmp_2, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_in_register_failed();
                            _OpCache_with_parameter_in_register_failed = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_in_register_failed, readState, writeState);
                            _OpCache_in_register_failed = (PersistentHashMap) ASSOC.invoke(_OpCache_in_register_failed, param, _OpCache_with_parameter_in_register_failed);
                        }

                    } else {
                        copiedState.in_register_failed(_tmp_2, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_in_register_failed writeState = copiedState._update_for_in_register_failed();
                        _OpCache_with_parameter_in_register_failed = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_in_register_failed = (PersistentHashMap) ASSOC.invoke(_OpCache_in_register_failed, param, _OpCache_with_parameter_in_register_failed);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_in_requestTargetSocket_Granted read__tr_in_requestTargetSocket_Granted_state = state._projected_state_for__tr_in_requestTargetSocket_Granted();
                BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>> _trid_12 = (BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>, SOCKET>>) GET.invoke(_OpCache_tr_in_requestTargetSocket_Granted, read__tr_in_requestTargetSocket_Granted_state);
                if(_trid_12 == null) {
                    _trid_12 = state._tr_in_requestTargetSocket_Granted();
                    _OpCache_tr_in_requestTargetSocket_Granted = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_in_requestTargetSocket_Granted, read__tr_in_requestTargetSocket_Granted_state, _trid_12);
                }
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
                    _ProjectionRead_in_requestTargetSocket_Granted readState = state._projected_state_for_in_requestTargetSocket_Granted();
                    PersistentHashMap _OpCache_with_parameter_in_requestTargetSocket_Granted = (PersistentHashMap) GET.invoke(_OpCache_in_requestTargetSocket_Granted, param);
                    if(_OpCache_with_parameter_in_requestTargetSocket_Granted != null) {
                        _ProjectionWrite_in_requestTargetSocket_Granted writeState = (_ProjectionWrite_in_requestTargetSocket_Granted) GET.invoke(_OpCache_with_parameter_in_requestTargetSocket_Granted, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_in_requestTargetSocket_Granted(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_in_requestTargetSocket_Granted();
                            _OpCache_with_parameter_in_requestTargetSocket_Granted = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_in_requestTargetSocket_Granted, readState, writeState);
                            _OpCache_in_requestTargetSocket_Granted = (PersistentHashMap) ASSOC.invoke(_OpCache_in_requestTargetSocket_Granted, param, _OpCache_with_parameter_in_requestTargetSocket_Granted);
                        }

                    } else {
                        copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_in_requestTargetSocket_Granted writeState = copiedState._update_for_in_requestTargetSocket_Granted();
                        _OpCache_with_parameter_in_requestTargetSocket_Granted = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_in_requestTargetSocket_Granted = (PersistentHashMap) ASSOC.invoke(_OpCache_in_requestTargetSocket_Granted, param, _OpCache_with_parameter_in_requestTargetSocket_Granted);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_in_requestTargetSocket_NotGranted read__tr_in_requestTargetSocket_NotGranted_state = state._projected_state_for__tr_in_requestTargetSocket_NotGranted();
                BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>> _trid_13 = (BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE>, SOCKET>, SID>, SID>>) GET.invoke(_OpCache_tr_in_requestTargetSocket_NotGranted, read__tr_in_requestTargetSocket_NotGranted_state);
                if(_trid_13 == null) {
                    _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
                    _OpCache_tr_in_requestTargetSocket_NotGranted = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_in_requestTargetSocket_NotGranted, read__tr_in_requestTargetSocket_NotGranted_state, _trid_13);
                }
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
                    _ProjectionRead_in_requestTargetSocket_NotGranted readState = state._projected_state_for_in_requestTargetSocket_NotGranted();
                    PersistentHashMap _OpCache_with_parameter_in_requestTargetSocket_NotGranted = (PersistentHashMap) GET.invoke(_OpCache_in_requestTargetSocket_NotGranted, param);
                    if(_OpCache_with_parameter_in_requestTargetSocket_NotGranted != null) {
                        _ProjectionWrite_in_requestTargetSocket_NotGranted writeState = (_ProjectionWrite_in_requestTargetSocket_NotGranted) GET.invoke(_OpCache_with_parameter_in_requestTargetSocket_NotGranted, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_in_requestTargetSocket_NotGranted(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_in_requestTargetSocket_NotGranted();
                            _OpCache_with_parameter_in_requestTargetSocket_NotGranted = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_in_requestTargetSocket_NotGranted, readState, writeState);
                            _OpCache_in_requestTargetSocket_NotGranted = (PersistentHashMap) ASSOC.invoke(_OpCache_in_requestTargetSocket_NotGranted, param, _OpCache_with_parameter_in_requestTargetSocket_NotGranted);
                        }

                    } else {
                        copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_in_requestTargetSocket_NotGranted writeState = copiedState._update_for_in_requestTargetSocket_NotGranted();
                        _OpCache_with_parameter_in_requestTargetSocket_NotGranted = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_in_requestTargetSocket_NotGranted = (PersistentHashMap) ASSOC.invoke(_OpCache_in_requestTargetSocket_NotGranted, param, _OpCache_with_parameter_in_requestTargetSocket_NotGranted);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                _ProjectionRead__tr_svc_register read__tr_svc_register_state = state._projected_state_for__tr_svc_register();
                BSet<SERVICE> _trid_14 = (BSet<SERVICE>) GET.invoke(_OpCache_tr_svc_register, read__tr_svc_register_state);
                if(_trid_14 == null) {
                    _trid_14 = state._tr_svc_register();
                    _OpCache_tr_svc_register = (PersistentHashMap) ASSOC.invoke(_OpCache_tr_svc_register, read__tr_svc_register_state, _trid_14);
                }
                for(SERVICE param : _trid_14) {
                    SERVICE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    _ProjectionRead_svc_register readState = state._projected_state_for_svc_register();
                    PersistentHashMap _OpCache_with_parameter_svc_register = (PersistentHashMap) GET.invoke(_OpCache_svc_register, param);
                    if(_OpCache_with_parameter_svc_register != null) {
                        _ProjectionWrite_svc_register writeState = (_ProjectionWrite_svc_register) GET.invoke(_OpCache_with_parameter_svc_register, readState);
                        if(writeState != null) {
                            copiedState._apply_update_for_svc_register(writeState);
                            copiedState.parent = state;
                        } else {
                            copiedState.svc_register(_tmp_1);
                            copiedState.parent = state;
                            writeState = copiedState._update_for_svc_register();
                            _OpCache_with_parameter_svc_register = (PersistentHashMap) ASSOC.invoke(_OpCache_with_parameter_svc_register, readState, writeState);
                            _OpCache_svc_register = (PersistentHashMap) ASSOC.invoke(_OpCache_svc_register, param, _OpCache_with_parameter_svc_register);
                        }

                    } else {
                        copiedState.svc_register(_tmp_1);
                        copiedState.parent = state;
                        _ProjectionWrite_svc_register writeState = copiedState._update_for_svc_register();
                        _OpCache_with_parameter_svc_register = (PersistentHashMap) ASSOC.invoke(PersistentHashMap.EMPTY, readState, writeState);
                        _OpCache_svc_register = (PersistentHashMap) ASSOC.invoke(_OpCache_svc_register, param, _OpCache_with_parameter_svc_register);
                    }
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            } else {
                BSet<INTERCONNECTNODE> _trid_1 = state._tr_constructor_interconnectNode();
                for(INTERCONNECTNODE param : _trid_1) {
                    INTERCONNECTNODE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_interconnectNode(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<RESOURCEMANAGER> _trid_2 = state._tr_constructor_resourceManager();
                for(RESOURCEMANAGER param : _trid_2) {
                    RESOURCEMANAGER _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_resourceManager(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_3 = state._tr_constructor_service();
                for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_3) {
                    SERVICE _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_service(_tmp_2, _tmp_1);
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
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_7 = state._tr_rm_getSid();
                for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_7) {
                    SERVICE _tmp_1 = param.projection2();
                    RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_getSid(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<RESOURCEMANAGER, SERVICE>> _trid_8 = state._tr_rm_getSid_Not_Found();
                for(BTuple<RESOURCEMANAGER, SERVICE> param : _trid_8) {
                    SERVICE _tmp_1 = param.projection2();
                    RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER>> _trid_9 = state._tr_in_announceResourceManager();
                for(BTuple<INTERCONNECTNODE, RESOURCEMANAGER> param : _trid_9) {
                    RESOURCEMANAGER _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
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
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<BTuple<INTERCONNECTNODE, SERVICE>> _trid_11 = state._tr_in_register_failed();
                for(BTuple<INTERCONNECTNODE, SERVICE> param : _trid_11) {
                    SERVICE _tmp_1 = param.projection2();
                    INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.in_register_failed(_tmp_2, _tmp_1);
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
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }
                BSet<SERVICE> _trid_14 = state._tr_svc_register();
                for(SERVICE param : _trid_14) {
                    SERVICE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.svc_register(_tmp_1);
                    result.add(copiedState);
                    transitions.getAndIncrement();

                }

            }
            return result;
        }

        private boolean invariantViolated(final nota_v2 state) {
            boolean _check_inv_1;
            if(isCaching) {
                _ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                Object _obj__check_inv_1 = GET.invoke(_InvCache__check_inv_1, read__check_inv_1_state);
                if(_obj__check_inv_1 == null) {
                    _check_inv_1 = state._check_inv_1();
                    _InvCache__check_inv_1 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_1, read__check_inv_1_state, _check_inv_1);
                } else {
                    _check_inv_1 = (boolean) _obj__check_inv_1;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_1");
                return true;
            }
            boolean _check_inv_2;
            if(isCaching) {
                _ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                Object _obj__check_inv_2 = GET.invoke(_InvCache__check_inv_2, read__check_inv_2_state);
                if(_obj__check_inv_2 == null) {
                    _check_inv_2 = state._check_inv_2();
                    _InvCache__check_inv_2 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_2, read__check_inv_2_state, _check_inv_2);
                } else {
                    _check_inv_2 = (boolean) _obj__check_inv_2;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_2");
                return true;
            }
            boolean _check_inv_3;
            if(isCaching) {
                _ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                Object _obj__check_inv_3 = GET.invoke(_InvCache__check_inv_3, read__check_inv_3_state);
                if(_obj__check_inv_3 == null) {
                    _check_inv_3 = state._check_inv_3();
                    _InvCache__check_inv_3 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_3, read__check_inv_3_state, _check_inv_3);
                } else {
                    _check_inv_3 = (boolean) _obj__check_inv_3;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_3");
                return true;
            }
            boolean _check_inv_4;
            if(isCaching) {
                _ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                Object _obj__check_inv_4 = GET.invoke(_InvCache__check_inv_4, read__check_inv_4_state);
                if(_obj__check_inv_4 == null) {
                    _check_inv_4 = state._check_inv_4();
                    _InvCache__check_inv_4 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_4, read__check_inv_4_state, _check_inv_4);
                } else {
                    _check_inv_4 = (boolean) _obj__check_inv_4;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_4");
                return true;
            }
            boolean _check_inv_5;
            if(isCaching) {
                _ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                Object _obj__check_inv_5 = GET.invoke(_InvCache__check_inv_5, read__check_inv_5_state);
                if(_obj__check_inv_5 == null) {
                    _check_inv_5 = state._check_inv_5();
                    _InvCache__check_inv_5 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_5, read__check_inv_5_state, _check_inv_5);
                } else {
                    _check_inv_5 = (boolean) _obj__check_inv_5;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_5");
                return true;
            }
            boolean _check_inv_6;
            if(isCaching) {
                _ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                Object _obj__check_inv_6 = GET.invoke(_InvCache__check_inv_6, read__check_inv_6_state);
                if(_obj__check_inv_6 == null) {
                    _check_inv_6 = state._check_inv_6();
                    _InvCache__check_inv_6 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_6, read__check_inv_6_state, _check_inv_6);
                } else {
                    _check_inv_6 = (boolean) _obj__check_inv_6;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_6");
                return true;
            }
            boolean _check_inv_7;
            if(isCaching) {
                _ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                Object _obj__check_inv_7 = GET.invoke(_InvCache__check_inv_7, read__check_inv_7_state);
                if(_obj__check_inv_7 == null) {
                    _check_inv_7 = state._check_inv_7();
                    _InvCache__check_inv_7 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_7, read__check_inv_7_state, _check_inv_7);
                } else {
                    _check_inv_7 = (boolean) _obj__check_inv_7;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_7");
                return true;
            }
            boolean _check_inv_8;
            if(isCaching) {
                _ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                Object _obj__check_inv_8 = GET.invoke(_InvCache__check_inv_8, read__check_inv_8_state);
                if(_obj__check_inv_8 == null) {
                    _check_inv_8 = state._check_inv_8();
                    _InvCache__check_inv_8 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_8, read__check_inv_8_state, _check_inv_8);
                } else {
                    _check_inv_8 = (boolean) _obj__check_inv_8;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_8");
                return true;
            }
            boolean _check_inv_9;
            if(isCaching) {
                _ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                Object _obj__check_inv_9 = GET.invoke(_InvCache__check_inv_9, read__check_inv_9_state);
                if(_obj__check_inv_9 == null) {
                    _check_inv_9 = state._check_inv_9();
                    _InvCache__check_inv_9 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_9, read__check_inv_9_state, _check_inv_9);
                } else {
                    _check_inv_9 = (boolean) _obj__check_inv_9;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_9");
                return true;
            }
            boolean _check_inv_10;
            if(isCaching) {
                _ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                Object _obj__check_inv_10 = GET.invoke(_InvCache__check_inv_10, read__check_inv_10_state);
                if(_obj__check_inv_10 == null) {
                    _check_inv_10 = state._check_inv_10();
                    _InvCache__check_inv_10 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_10, read__check_inv_10_state, _check_inv_10);
                } else {
                    _check_inv_10 = (boolean) _obj__check_inv_10;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_10");
                return true;
            }
            boolean _check_inv_11;
            if(isCaching) {
                _ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                Object _obj__check_inv_11 = GET.invoke(_InvCache__check_inv_11, read__check_inv_11_state);
                if(_obj__check_inv_11 == null) {
                    _check_inv_11 = state._check_inv_11();
                    _InvCache__check_inv_11 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_11, read__check_inv_11_state, _check_inv_11);
                } else {
                    _check_inv_11 = (boolean) _obj__check_inv_11;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_11");
                return true;
            }
            boolean _check_inv_12;
            if(isCaching) {
                _ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                Object _obj__check_inv_12 = GET.invoke(_InvCache__check_inv_12, read__check_inv_12_state);
                if(_obj__check_inv_12 == null) {
                    _check_inv_12 = state._check_inv_12();
                    _InvCache__check_inv_12 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_12, read__check_inv_12_state, _check_inv_12);
                } else {
                    _check_inv_12 = (boolean) _obj__check_inv_12;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_12");
                return true;
            }
            boolean _check_inv_13;
            if(isCaching) {
                _ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                Object _obj__check_inv_13 = GET.invoke(_InvCache__check_inv_13, read__check_inv_13_state);
                if(_obj__check_inv_13 == null) {
                    _check_inv_13 = state._check_inv_13();
                    _InvCache__check_inv_13 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_13, read__check_inv_13_state, _check_inv_13);
                } else {
                    _check_inv_13 = (boolean) _obj__check_inv_13;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_13");
                return true;
            }
            boolean _check_inv_14;
            if(isCaching) {
                _ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                Object _obj__check_inv_14 = GET.invoke(_InvCache__check_inv_14, read__check_inv_14_state);
                if(_obj__check_inv_14 == null) {
                    _check_inv_14 = state._check_inv_14();
                    _InvCache__check_inv_14 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_14, read__check_inv_14_state, _check_inv_14);
                } else {
                    _check_inv_14 = (boolean) _obj__check_inv_14;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_14");
                return true;
            }
            boolean _check_inv_15;
            if(isCaching) {
                _ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                Object _obj__check_inv_15 = GET.invoke(_InvCache__check_inv_15, read__check_inv_15_state);
                if(_obj__check_inv_15 == null) {
                    _check_inv_15 = state._check_inv_15();
                    _InvCache__check_inv_15 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_15, read__check_inv_15_state, _check_inv_15);
                } else {
                    _check_inv_15 = (boolean) _obj__check_inv_15;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_15");
                return true;
            }
            boolean _check_inv_16;
            if(isCaching) {
                _ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                Object _obj__check_inv_16 = GET.invoke(_InvCache__check_inv_16, read__check_inv_16_state);
                if(_obj__check_inv_16 == null) {
                    _check_inv_16 = state._check_inv_16();
                    _InvCache__check_inv_16 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_16, read__check_inv_16_state, _check_inv_16);
                } else {
                    _check_inv_16 = (boolean) _obj__check_inv_16;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_16");
                return true;
            }
            boolean _check_inv_17;
            if(isCaching) {
                _ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                Object _obj__check_inv_17 = GET.invoke(_InvCache__check_inv_17, read__check_inv_17_state);
                if(_obj__check_inv_17 == null) {
                    _check_inv_17 = state._check_inv_17();
                    _InvCache__check_inv_17 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_17, read__check_inv_17_state, _check_inv_17);
                } else {
                    _check_inv_17 = (boolean) _obj__check_inv_17;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_17");
                return true;
            }
            boolean _check_inv_18;
            if(isCaching) {
                _ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                Object _obj__check_inv_18 = GET.invoke(_InvCache__check_inv_18, read__check_inv_18_state);
                if(_obj__check_inv_18 == null) {
                    _check_inv_18 = state._check_inv_18();
                    _InvCache__check_inv_18 = (PersistentHashMap) ASSOC.invoke(_InvCache__check_inv_18, read__check_inv_18_state, _check_inv_18);
                } else {
                    _check_inv_18 = (boolean) _obj__check_inv_18;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
                System.out.println("INVARIANT CONJUNCT VIOLATED: _check_inv_18");
                return true;
            }
            return false;
        }

        private void printResult(final int states, final int transitions) {
            if(invariantViolated.get() || deadlockDetected.get()) {
                if(deadlockDetected.get()) {
                    System.out.println("DEADLOCK DETECTED");
                } else {
                    System.out.println("INVARIANT VIOLATED");
                }

                System.out.println("COUNTER EXAMPLE TRACE: ");
                StringBuilder sb = new StringBuilder();
                while(counterExampleState != null) {
                    sb.insert(0, counterExampleState);
                    sb.insert(0, "\n");
                    if(counterExampleState.stateAccessedVia != null) {
                        sb.insert(0, counterExampleState.stateAccessedVia);
                    }
                    sb.insert(0, "\n\n");
                    counterExampleState = counterExampleState.parent;
                }
                System.out.println(sb);
            } else {
                System.out.println("MODEL CHECKING SUCCESSFUL");
            }

            System.out.println("Number of States: " + states);
            System.out.println("Number of Transitions: " + transitions);
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

        System.out.println("Starting Model Checking, Search: "+type+", Threads: "+threads+", Caching: "+isCaching);
        long start = java.lang.System.currentTimeMillis();
        ModelChecker modelchecker = new ModelChecker(type, threads, isCaching, isDebug);
        modelchecker.modelCheck();
        long stop = java.lang.System.currentTimeMillis();
        System.out.println("Model Checking Time: "+ (stop-start) + " ms");
    }




}
