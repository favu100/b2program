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
#include <btypes_primitives/BStruct.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BRelation.hpp>
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef nota_v2_H
#define nota_v2_H

using namespace std;

class nota_v2 {

    public:

        enum Type { BFS, DFS, MIXED };

        class INTERCONNECTNODE : public BObject {
            public:

                typedef INTERCONNECTNODE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum INTERCONNECTNODE_type {
                    node1, 
                    node2
                };

                INTERCONNECTNODE_type value;

                INTERCONNECTNODE(){}

                INTERCONNECTNODE(const INTERCONNECTNODE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const INTERCONNECTNODE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const INTERCONNECTNODE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const INTERCONNECTNODE& p1, const INTERCONNECTNODE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const INTERCONNECTNODE& p1, const INTERCONNECTNODE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const INTERCONNECTNODE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const INTERCONNECTNODE& e) {
                    switch(e.value) {
                        case node1: return strm << "node1";
                        case node2: return strm << "node2";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class SOCKET : public BObject {
            public:

                typedef SOCKET current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum SOCKET_type {
                    socket1, 
                    socket2
                };

                SOCKET_type value;

                SOCKET(){}

                SOCKET(const SOCKET_type& type) {
                    this->value = type;
                }

                BBoolean equal(const SOCKET& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const SOCKET& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const SOCKET& p1, const SOCKET& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const SOCKET& p1, const SOCKET& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const SOCKET& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const SOCKET& e) {
                    switch(e.value) {
                        case socket1: return strm << "socket1";
                        case socket2: return strm << "socket2";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class SERVICE : public BObject {
            public:

                typedef SERVICE current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum SERVICE_type {
                    service1, 
                    service2
                };

                SERVICE_type value;

                SERVICE(){}

                SERVICE(const SERVICE_type& type) {
                    this->value = type;
                }

                BBoolean equal(const SERVICE& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const SERVICE& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const SERVICE& p1, const SERVICE& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const SERVICE& p1, const SERVICE& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const SERVICE& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const SERVICE& e) {
                    switch(e.value) {
                        case service1: return strm << "service1";
                        case service2: return strm << "service2";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class RESOURCEMANAGER : public BObject {
            public:

                typedef RESOURCEMANAGER current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum RESOURCEMANAGER_type {
                    resource1, 
                    resource2
                };

                RESOURCEMANAGER_type value;

                RESOURCEMANAGER(){}

                RESOURCEMANAGER(const RESOURCEMANAGER_type& type) {
                    this->value = type;
                }

                BBoolean equal(const RESOURCEMANAGER& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const RESOURCEMANAGER& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const RESOURCEMANAGER& p1, const RESOURCEMANAGER& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const RESOURCEMANAGER& p1, const RESOURCEMANAGER& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const RESOURCEMANAGER& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const RESOURCEMANAGER& e) {
                    switch(e.value) {
                        case resource1: return strm << "resource1";
                        case resource2: return strm << "resource2";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class SID : public BObject {
            public:

                typedef SID current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum SID_type {
                    SID1, 
                    SID2
                };

                SID_type value;

                SID(){}

                SID(const SID_type& type) {
                    this->value = type;
                }

                BBoolean equal(const SID& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const SID& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const SID& p1, const SID& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const SID& p1, const SID& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const SID& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const SID& e) {
                    switch(e.value) {
                        case SID1: return strm << "SID1";
                        case SID2: return strm << "SID2";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class RM_ERROR_CODES : public BObject {
            public:

                typedef RM_ERROR_CODES current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum RM_ERROR_CODES_type {
                    RM_SERVICE_FOUND, 
                    RM_SERVICE_NOT_FOUND
                };

                RM_ERROR_CODES_type value;

                RM_ERROR_CODES(){}

                RM_ERROR_CODES(const RM_ERROR_CODES_type& type) {
                    this->value = type;
                }

                BBoolean equal(const RM_ERROR_CODES& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const RM_ERROR_CODES& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const RM_ERROR_CODES& p1, const RM_ERROR_CODES& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const RM_ERROR_CODES& p1, const RM_ERROR_CODES& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const RM_ERROR_CODES& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const RM_ERROR_CODES& e) {
                    switch(e.value) {
                        case RM_SERVICE_FOUND: return strm << "RM_SERVICE_FOUND";
                        case RM_SERVICE_NOT_FOUND: return strm << "RM_SERVICE_NOT_FOUND";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class IN_ERROR_CODES : public BObject {
            public:

                typedef IN_ERROR_CODES current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum IN_ERROR_CODES_type {
                    IN_REGISTRATION_OK, 
                    IN_REGISTRATION_FAILED, 
                    IN_DEREGISTRATION_OK, 
                    IN_DEREGISTRATION_FAILED, 
                    IN_NO_SOCKET_CONNECTION, 
                    IN_SOCKET_CONNECTION_OK, 
                    IN_NO_AVAILABLE_SERVICE, 
                    IN_SERVICE_AVAILABLE, 
                    IN_TARGET_SOCKET_GRANTED, 
                    IN_TARGET_SOCKET_NOT_GRANTED
                };

                IN_ERROR_CODES_type value;

                IN_ERROR_CODES(){}

                IN_ERROR_CODES(const IN_ERROR_CODES_type& type) {
                    this->value = type;
                }

                BBoolean equal(const IN_ERROR_CODES& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const IN_ERROR_CODES& o) const {
                    return value != o.value;
                }

                friend bool operator ==(const IN_ERROR_CODES& p1, const IN_ERROR_CODES& p2) {
                    return p1.value == p2.value;
                }

                friend bool operator !=(const IN_ERROR_CODES& p1, const IN_ERROR_CODES& p2) {
                    return p1.value != p2.value;
                }

                void operator =(const IN_ERROR_CODES& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const IN_ERROR_CODES& e) {
                    switch(e.value) {
                        case IN_REGISTRATION_OK: return strm << "IN_REGISTRATION_OK";
                        case IN_REGISTRATION_FAILED: return strm << "IN_REGISTRATION_FAILED";
                        case IN_DEREGISTRATION_OK: return strm << "IN_DEREGISTRATION_OK";
                        case IN_DEREGISTRATION_FAILED: return strm << "IN_DEREGISTRATION_FAILED";
                        case IN_NO_SOCKET_CONNECTION: return strm << "IN_NO_SOCKET_CONNECTION";
                        case IN_SOCKET_CONNECTION_OK: return strm << "IN_SOCKET_CONNECTION_OK";
                        case IN_NO_AVAILABLE_SERVICE: return strm << "IN_NO_AVAILABLE_SERVICE";
                        case IN_SERVICE_AVAILABLE: return strm << "IN_SERVICE_AVAILABLE";
                        case IN_TARGET_SOCKET_GRANTED: return strm << "IN_TARGET_SOCKET_GRANTED";
                        case IN_TARGET_SOCKET_NOT_GRANTED: return strm << "IN_TARGET_SOCKET_NOT_GRANTED";
                    }
                }

                int hashCode() const {
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
                }
        };

        class _Struct3 : public BStruct {
            private:
                BSet<SID > sid;
                IN_ERROR_CODES err;

            public:
                typedef _Struct3 current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                _Struct3(const BSet<SID >& sid, const IN_ERROR_CODES& err) {
                    this->sid = sid;
                    this->err = err;
                }

                BSet<SID > get_sid() {
                    return this->sid;
                }

                IN_ERROR_CODES get_err() {
                    return this->err;
                }

                _Struct3 override_sid(const BSet<SID >& sid) {
                    return _Struct3(sid, err);
                }

                _Struct3 override_err(const IN_ERROR_CODES& err) {
                    return _Struct3(sid, err);
                }

                _Struct3() {
                }

                void operator =(const _Struct3& other) {
                    this->sid = other.sid;
                    this->err = other.err;
                }

                BBoolean equal(const _Struct3& o) const {
                    return this->sid == o.sid && this->err == o.err;
                }

                BBoolean unequal(const _Struct3& o) const {
                    return this->sid != o.sid || this->err != o.err;
                }

                friend bool operator ==(const _Struct3& p1, const _Struct3& p2) {
                    return (p1.equal(p2)).booleanValue();
                }

                friend bool operator !=(const _Struct3& p1, const _Struct3& p2) {
                    return (p1.unequal(p2)).booleanValue();
                }

                friend std::ostream& operator<<(std::ostream &strm, const _Struct3& e) {
                    strm << "(";
                    strm << "sid : ";
                    strm << e.sid;
                    strm << "err : ";
                    strm << e.err;
                    strm << ")";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sid.hashCode() << 1);
                    result = 31 * result + (err.hashCode() << 1);
                    return result;
                }
        };

        class _Struct1 : public BStruct {
            private:
                BSet<SID > sid;
                RM_ERROR_CODES err;

            public:
                typedef _Struct1 current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                _Struct1(const BSet<SID >& sid, const RM_ERROR_CODES& err) {
                    this->sid = sid;
                    this->err = err;
                }

                BSet<SID > get_sid() {
                    return this->sid;
                }

                RM_ERROR_CODES get_err() {
                    return this->err;
                }

                _Struct1 override_sid(const BSet<SID >& sid) {
                    return _Struct1(sid, err);
                }

                _Struct1 override_err(const RM_ERROR_CODES& err) {
                    return _Struct1(sid, err);
                }

                _Struct1() {
                }

                void operator =(const _Struct1& other) {
                    this->sid = other.sid;
                    this->err = other.err;
                }

                BBoolean equal(const _Struct1& o) const {
                    return this->sid == o.sid && this->err == o.err;
                }

                BBoolean unequal(const _Struct1& o) const {
                    return this->sid != o.sid || this->err != o.err;
                }

                friend bool operator ==(const _Struct1& p1, const _Struct1& p2) {
                    return (p1.equal(p2)).booleanValue();
                }

                friend bool operator !=(const _Struct1& p1, const _Struct1& p2) {
                    return (p1.unequal(p2)).booleanValue();
                }

                friend std::ostream& operator<<(std::ostream &strm, const _Struct1& e) {
                    strm << "(";
                    strm << "sid : ";
                    strm << e.sid;
                    strm << "err : ";
                    strm << e.err;
                    strm << ")";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sid.hashCode() << 1);
                    result = 31 * result + (err.hashCode() << 1);
                    return result;
                }
        };

        class _Struct5 : public BStruct {
            private:
                BSet<SOCKET > soc;
                IN_ERROR_CODES err;

            public:
                typedef _Struct5 current_type;
                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                _Struct5(const BSet<SOCKET >& soc, const IN_ERROR_CODES& err) {
                    this->soc = soc;
                    this->err = err;
                }

                BSet<SOCKET > get_soc() {
                    return this->soc;
                }

                IN_ERROR_CODES get_err() {
                    return this->err;
                }

                _Struct5 override_soc(const BSet<SOCKET >& soc) {
                    return _Struct5(soc, err);
                }

                _Struct5 override_err(const IN_ERROR_CODES& err) {
                    return _Struct5(soc, err);
                }

                _Struct5() {
                }

                void operator =(const _Struct5& other) {
                    this->soc = other.soc;
                    this->err = other.err;
                }

                BBoolean equal(const _Struct5& o) const {
                    return this->soc == o.soc && this->err == o.err;
                }

                BBoolean unequal(const _Struct5& o) const {
                    return this->soc != o.soc || this->err != o.err;
                }

                friend bool operator ==(const _Struct5& p1, const _Struct5& p2) {
                    return (p1.equal(p2)).booleanValue();
                }

                friend bool operator !=(const _Struct5& p1, const _Struct5& p2) {
                    return (p1.unequal(p2)).booleanValue();
                }

                friend std::ostream& operator<<(std::ostream &strm, const _Struct5& e) {
                    strm << "(";
                    strm << "soc : ";
                    strm << e.soc;
                    strm << "err : ";
                    strm << e.err;
                    strm << ")";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (soc.hashCode() << 1);
                    result = 31 * result + (err.hashCode() << 1);
                    return result;
                }
        };

        struct Hash {
            public:
                size_t operator()(const nota_v2& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const nota_v2& obj1, const nota_v2& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

    private:



        #define _INTERCONNECTNODE (BSet<INTERCONNECTNODE >((INTERCONNECTNODE(INTERCONNECTNODE::node1)), (INTERCONNECTNODE(INTERCONNECTNODE::node2))))
        #define _SOCKET (BSet<SOCKET >((SOCKET(SOCKET::socket1)), (SOCKET(SOCKET::socket2))))
        #define _SERVICE (BSet<SERVICE >((SERVICE(SERVICE::service1)), (SERVICE(SERVICE::service2))))
        #define _RESOURCEMANAGER (BSet<RESOURCEMANAGER >((RESOURCEMANAGER(RESOURCEMANAGER::resource1)), (RESOURCEMANAGER(RESOURCEMANAGER::resource2))))
        #define _SID (BSet<SID >((SID(SID::SID1)), (SID(SID::SID2))))
        #define _RM_ERROR_CODES (BSet<RM_ERROR_CODES >((RM_ERROR_CODES(RM_ERROR_CODES::RM_SERVICE_FOUND)), (RM_ERROR_CODES(RM_ERROR_CODES::RM_SERVICE_NOT_FOUND))))
        #define _IN_ERROR_CODES (BSet<IN_ERROR_CODES >((IN_ERROR_CODES(IN_ERROR_CODES::IN_REGISTRATION_OK)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_REGISTRATION_FAILED)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_DEREGISTRATION_OK)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_DEREGISTRATION_FAILED)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_NO_SOCKET_CONNECTION)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_SOCKET_CONNECTION_OK)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_NO_AVAILABLE_SERVICE)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_SERVICE_AVAILABLE)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED)), (IN_ERROR_CODES(IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED))))

        BSet<INTERCONNECTNODE > interconnectNodes;
        BSet<SOCKET > sockets;
        BSet<SERVICE > services;
        BSet<RESOURCEMANAGER > resourceManagers;
        BSet<SID > sids;
        BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;
        BRelation<SERVICE, SID > rm_sids;
        BRelation<SID, INTERCONNECTNODE > in_localServices;
        BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
        BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;
        BRelation<SOCKET, SID > soc_to;
        BRelation<SOCKET, SID > soc_from;
        BRelation<SERVICE, SID > svc_serviceID;
        BRelation<SERVICE, BSet<SOCKET > > svc_sockets;
        BRelation<SERVICE, INTERCONNECTNODE > svc_ICNode;
        BRelation<SERVICE, BBoolean > svc_registered;


    public:

        nota_v2() {
            interconnectNodes = (BSet<INTERCONNECTNODE >());
            sockets = (BSet<SOCKET >());
            services = (BSet<SERVICE >());
            resourceManagers = (BSet<RESOURCEMANAGER >());
            sids = (BSet<SID >());
            rm_services = (BRelation<RESOURCEMANAGER, BSet<SERVICE > >());
            rm_sids = (BRelation<SERVICE, SID >());
            in_localServices = (BRelation<SID, INTERCONNECTNODE >());
            in_sockets = (BRelation<SOCKET, INTERCONNECTNODE >());
            in_resourceManager = (BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >());
            soc_to = (BRelation<SOCKET, SID >());
            soc_from = (BRelation<SOCKET, SID >());
            svc_serviceID = (BRelation<SERVICE, SID >());
            svc_sockets = (BRelation<SERVICE, BSet<SOCKET > >());
            svc_ICNode = (BRelation<SERVICE, INTERCONNECTNODE >());
            svc_registered = (BRelation<SERVICE, BBoolean >());
        }

        nota_v2(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SOCKET >& sockets, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers, const BSet<SID >& sids, const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services, const BRelation<SERVICE, SID >& rm_sids, const BRelation<SID, INTERCONNECTNODE >& in_localServices, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager, const BRelation<SOCKET, SID >& soc_to, const BRelation<SOCKET, SID >& soc_from, const BRelation<SERVICE, SID >& svc_serviceID, const BRelation<SERVICE, BSet<SOCKET > >& svc_sockets, const BRelation<SERVICE, INTERCONNECTNODE >& svc_ICNode, const BRelation<SERVICE, BBoolean >& svc_registered) {
            this->interconnectNodes = interconnectNodes;
            this->sockets = sockets;
            this->services = services;
            this->resourceManagers = resourceManagers;
            this->sids = sids;
            this->rm_services = rm_services;
            this->rm_sids = rm_sids;
            this->in_localServices = in_localServices;
            this->in_sockets = in_sockets;
            this->in_resourceManager = in_resourceManager;
            this->soc_to = soc_to;
            this->soc_from = soc_from;
            this->svc_serviceID = svc_serviceID;
            this->svc_sockets = svc_sockets;
            this->svc_ICNode = svc_ICNode;
            this->svc_registered = svc_registered;
        }

        INTERCONNECTNODE constructor_interconnectNode(const INTERCONNECTNODE& newic) {
            INTERCONNECTNODE oid;
            BSet<INTERCONNECTNODE > _ld_interconnectNodes = interconnectNodes;
            interconnectNodes = _ld_interconnectNodes._union((BSet<INTERCONNECTNODE >(newic)));
            in_resourceManager = in_resourceManager.override(BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER >>(BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER >>(newic,((BSet<RESOURCEMANAGER >())))));
            oid = newic;

            return oid;
        }

        RESOURCEMANAGER constructor_resourceManager(const RESOURCEMANAGER& newrm) {
            RESOURCEMANAGER oid;
            BSet<RESOURCEMANAGER > _ld_resourceManagers = resourceManagers;
            resourceManagers = _ld_resourceManagers._union((BSet<RESOURCEMANAGER >(newrm)));
            rm_services = rm_services.override(BRelation<RESOURCEMANAGER, BSet<SERVICE >>(BTuple<RESOURCEMANAGER, BSet<SERVICE >>(newrm,((BSet<SERVICE >())))));
            oid = newrm;

            return oid;
        }

        SERVICE constructor_service(const INTERCONNECTNODE& ii, const SERVICE& newsvc) {
            SERVICE oid;
            BSet<SERVICE > _ld_services = services;
            services = _ld_services._union((BSet<SERVICE >(newsvc)));
            svc_registered = svc_registered.override(BRelation<SERVICE, BBoolean>(BTuple<SERVICE, BBoolean>(newsvc,((BBoolean(false))))));
            svc_sockets = svc_sockets.override(BRelation<SERVICE, BSet<SOCKET >>(BTuple<SERVICE, BSet<SOCKET >>(newsvc,((BSet<SOCKET >())))));
            svc_ICNode = svc_ICNode.override(BRelation<SERVICE, INTERCONNECTNODE>(BTuple<SERVICE, INTERCONNECTNODE>(newsvc,(ii))));
            svc_serviceID = (BRelation<SERVICE, SID >());
            oid = newsvc;

            return oid;
        }

        SOCKET constructor_socket(const INTERCONNECTNODE& ii, const SID& srcsid, const SID& targsid, const SOCKET& newsoc) {
            SOCKET oid;
            BSet<SOCKET > _ld_sockets = sockets;
            sockets = _ld_sockets._union((BSet<SOCKET >(newsoc)));
            oid = newsoc;
            in_sockets = in_sockets.override(BRelation<SOCKET, INTERCONNECTNODE>(BTuple<SOCKET, INTERCONNECTNODE>(newsoc,(ii))));
            soc_to = soc_to.override(BRelation<SOCKET, SID>(BTuple<SOCKET, SID>(newsoc,(srcsid))));
            soc_from = soc_from.override(BRelation<SOCKET, SID>(BTuple<SOCKET, SID>(newsoc,(targsid))));

            return oid;
        }

        void rm_register(const RESOURCEMANAGER& self, const SERVICE& ss, const INTERCONNECTNODE& ii) {
        }

        void rm_deregister(const RESOURCEMANAGER& self, const SERVICE& ss, const INTERCONNECTNODE& ii) {
        }

        _Struct1 rm_getSid(const RESOURCEMANAGER& self, const SERVICE& ss) {
            BSet<SID > sid;
            RM_ERROR_CODES err;
            err = (RM_ERROR_CODES(RM_ERROR_CODES::RM_SERVICE_FOUND));
            sid = (BSet<SID >(rm_sids.functionCall(ss)));

            return (_Struct1(sid, err));
        }

        _Struct1 rm_getSid_Not_Found(const RESOURCEMANAGER& self, const SERVICE& ss) {
            BSet<SID > sid;
            RM_ERROR_CODES err;
            sid = _SID.difference(_SID);
            err = (RM_ERROR_CODES(RM_ERROR_CODES::RM_SERVICE_NOT_FOUND));

            return (_Struct1(sid, err));
        }

        void in_announceResourceManager(const INTERCONNECTNODE& self, const RESOURCEMANAGER& rm) {
            in_resourceManager = in_resourceManager.override(BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER >>(BTuple<INTERCONNECTNODE, BSet<RESOURCEMANAGER >>(self,(in_resourceManager.functionCall(self)._union((BSet<RESOURCEMANAGER >(rm)))))));

        }

        _Struct3 in_register_success(const INTERCONNECTNODE& self, const SERVICE& ss, const SID& si) {
            BSet<SID > sid;
            IN_ERROR_CODES err;
            BSet<SID > _ld_sids = sids;
            BRelation<SID, INTERCONNECTNODE > _ld_in_localServices = in_localServices;
            sids = _ld_sids._union((BSet<SID >(si)));
            in_localServices = _ld_in_localServices._union((BRelation<SID, INTERCONNECTNODE >((BTuple<SID, INTERCONNECTNODE >(si, self)))));
            err = (IN_ERROR_CODES(IN_ERROR_CODES::IN_REGISTRATION_OK));
            sid = (BSet<SID >(si));

            return (_Struct3(sid, err));
        }

        _Struct3 in_register_failed(const INTERCONNECTNODE& self, const SERVICE& ss) {
            BSet<SID > sid;
            IN_ERROR_CODES err;
            sid = _SID.difference(_SID);
            err = (IN_ERROR_CODES(IN_ERROR_CODES::IN_REGISTRATION_FAILED));

            return (_Struct3(sid, err));
        }

        _Struct5 in_requestTargetSocket_Granted(const INTERCONNECTNODE& self, const INTERCONNECTNODE& ii, const SOCKET& srcsoc, const SID& srcsid, const SID& targsid, const SOCKET& newsoc) {
            BSet<SOCKET > soc;
            IN_ERROR_CODES err;
            BRelation<SOCKET, INTERCONNECTNODE > _ld_in_sockets = in_sockets;
            BSet<SOCKET > _ld_sockets = sockets;
            sockets = _ld_sockets._union((BSet<SOCKET >(newsoc)));
            soc = (BSet<SOCKET >(newsoc));
            err = (IN_ERROR_CODES(IN_ERROR_CODES::IN_TARGET_SOCKET_GRANTED));
            in_sockets = _ld_in_sockets._union((BRelation<SOCKET, INTERCONNECTNODE >((BTuple<SOCKET, INTERCONNECTNODE >(newsoc, self)))));
            soc_to = soc_to.override(BRelation<SOCKET, SID>(BTuple<SOCKET, SID>(newsoc,(srcsid))));
            soc_from = soc_from.override(BRelation<SOCKET, SID>(BTuple<SOCKET, SID>(newsoc,(targsid))));

            return (_Struct5(soc, err));
        }

        _Struct5 in_requestTargetSocket_NotGranted(const INTERCONNECTNODE& self, const INTERCONNECTNODE& ii, const SOCKET& srcsoc, const SID& srcsid, const SID& targsid) {
            BSet<SOCKET > soc;
            IN_ERROR_CODES err;
            soc = _SOCKET.difference(_SOCKET);
            err = (IN_ERROR_CODES(IN_ERROR_CODES::IN_TARGET_SOCKET_NOT_GRANTED));

            return (_Struct5(soc, err));
        }

        void svc_register(const SERVICE& self) {
            svc_registered = svc_registered.override(BRelation<SERVICE, BBoolean>(BTuple<SERVICE, BBoolean>(self,((BBoolean(true))))));

        }

        BSet<INTERCONNECTNODE > _get_interconnectNodes() const {
            return interconnectNodes;
        }

        BSet<SOCKET > _get_sockets() const {
            return sockets;
        }

        BSet<SERVICE > _get_services() const {
            return services;
        }

        BSet<RESOURCEMANAGER > _get_resourceManagers() const {
            return resourceManagers;
        }

        BSet<SID > _get_sids() const {
            return sids;
        }

        BRelation<RESOURCEMANAGER, BSet<SERVICE > > _get_rm_services() const {
            return rm_services;
        }

        BRelation<SERVICE, SID > _get_rm_sids() const {
            return rm_sids;
        }

        BRelation<SID, INTERCONNECTNODE > _get_in_localServices() const {
            return in_localServices;
        }

        BRelation<SOCKET, INTERCONNECTNODE > _get_in_sockets() const {
            return in_sockets;
        }

        BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > _get_in_resourceManager() const {
            return in_resourceManager;
        }

        BRelation<SOCKET, SID > _get_soc_to() const {
            return soc_to;
        }

        BRelation<SOCKET, SID > _get_soc_from() const {
            return soc_from;
        }

        BRelation<SERVICE, SID > _get_svc_serviceID() const {
            return svc_serviceID;
        }

        BRelation<SERVICE, BSet<SOCKET > > _get_svc_sockets() const {
            return svc_sockets;
        }

        BRelation<SERVICE, INTERCONNECTNODE > _get_svc_ICNode() const {
            return svc_ICNode;
        }

        BRelation<SERVICE, BBoolean > _get_svc_registered() const {
            return svc_registered;
        }

        BSet<INTERCONNECTNODE > _get__INTERCONNECTNODE() const {
            return _INTERCONNECTNODE;
        }

        BSet<SOCKET > _get__SOCKET() const {
            return _SOCKET;
        }

        BSet<SERVICE > _get__SERVICE() const {
            return _SERVICE;
        }

        BSet<RESOURCEMANAGER > _get__RESOURCEMANAGER() const {
            return _RESOURCEMANAGER;
        }

        BSet<SID > _get__SID() const {
            return _SID;
        }

        BSet<RM_ERROR_CODES > _get__RM_ERROR_CODES() const {
            return _RM_ERROR_CODES;
        }

        BSet<IN_ERROR_CODES > _get__IN_ERROR_CODES() const {
            return _IN_ERROR_CODES;
        }


        BSet<INTERCONNECTNODE> _tr_constructor_interconnectNode() const {
            BSet<INTERCONNECTNODE> _ic_set_0 = BSet<INTERCONNECTNODE>();
            for(INTERCONNECTNODE _ic_newic_1 : _INTERCONNECTNODE.difference(interconnectNodes)) {
                _ic_set_0 = _ic_set_0._union(BSet<INTERCONNECTNODE>(_ic_newic_1));

            }
            return _ic_set_0;
        }

        BSet<RESOURCEMANAGER> _tr_constructor_resourceManager() const {
            BSet<RESOURCEMANAGER> _ic_set_1 = BSet<RESOURCEMANAGER>();
            for(RESOURCEMANAGER _ic_newrm_1 : _RESOURCEMANAGER.difference(resourceManagers)) {
                if(((BBoolean(rm_services.domain().notElementOf(_ic_newrm_1).booleanValue() && resourceManagers.equal((BSet<RESOURCEMANAGER >())).booleanValue()))).booleanValue()) {
                    _ic_set_1 = _ic_set_1._union(BSet<RESOURCEMANAGER>(_ic_newrm_1));
                }

            }
            return _ic_set_1;
        }

        BSet<BTuple<INTERCONNECTNODE, SERVICE >> _tr_constructor_service() const {
            BSet<BTuple<INTERCONNECTNODE, SERVICE >> _ic_set_2 = BSet<BTuple<INTERCONNECTNODE, SERVICE >>();
            for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                for(SERVICE _ic_newsvc_1 : _SERVICE.difference(services)) {
                    _ic_set_2 = _ic_set_2._union(BSet<BTuple<INTERCONNECTNODE, SERVICE >>((BTuple<INTERCONNECTNODE, SERVICE >(_ic_ii_1, _ic_newsvc_1))));

                }
            }
            return _ic_set_2;
        }

        BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >> _tr_constructor_socket() const {
            BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >> _ic_set_3 = BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >>();
            for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                for(SID _ic_srcsid_1 : sids) {
                    for(SID _ic_targsid_1 : sids) {
                        for(SOCKET _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                            _ic_set_3 = _ic_set_3._union(BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >>((BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >((BTuple<BTuple<INTERCONNECTNODE, SID >, SID >((BTuple<INTERCONNECTNODE, SID >(_ic_ii_1, _ic_srcsid_1)), _ic_targsid_1)), _ic_newsoc_1))));

                        }
                    }
                }
            }
            return _ic_set_3;
        }

        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _tr_rm_register() const {
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _ic_set_4 = BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>();
            for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
                for(SERVICE _ic_ss_1 : services) {
                    for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                        _ic_set_4 = _ic_set_4._union(BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>((BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1)), _ic_ii_1))));

                    }
                }
            }
            return _ic_set_4;
        }

        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _tr_rm_deregister() const {
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _ic_set_5 = BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>();
            for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
                for(SERVICE _ic_ss_1 : services) {
                    for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                        _ic_set_5 = _ic_set_5._union(BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>((BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1)), _ic_ii_1))));

                    }
                }
            }
            return _ic_set_5;
        }

        BSet<BTuple<RESOURCEMANAGER, SERVICE >> _tr_rm_getSid() const {
            BSet<BTuple<RESOURCEMANAGER, SERVICE >> _ic_set_6 = BSet<BTuple<RESOURCEMANAGER, SERVICE >>();
            for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
                for(SERVICE _ic_ss_1 : services) {
                    if((rm_sids.domain().elementOf(_ic_ss_1)).booleanValue()) {
                        _ic_set_6 = _ic_set_6._union(BSet<BTuple<RESOURCEMANAGER, SERVICE >>((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1))));
                    }

                }
            }
            return _ic_set_6;
        }

        BSet<BTuple<RESOURCEMANAGER, SERVICE >> _tr_rm_getSid_Not_Found() const {
            BSet<BTuple<RESOURCEMANAGER, SERVICE >> _ic_set_7 = BSet<BTuple<RESOURCEMANAGER, SERVICE >>();
            for(RESOURCEMANAGER _ic_self_1 : resourceManagers) {
                for(SERVICE _ic_ss_1 : services) {
                    _ic_set_7 = _ic_set_7._union(BSet<BTuple<RESOURCEMANAGER, SERVICE >>((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1))));

                }
            }
            return _ic_set_7;
        }

        BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >> _tr_in_announceResourceManager() const {
            BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >> _ic_set_8 = BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >>();
            for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
                for(RESOURCEMANAGER _ic_rm_1 : resourceManagers) {
                    if((in_resourceManager.functionCall(_ic_self_1).equal((BSet<RESOURCEMANAGER >()))).booleanValue()) {
                        _ic_set_8 = _ic_set_8._union(BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >>((BTuple<INTERCONNECTNODE, RESOURCEMANAGER >(_ic_self_1, _ic_rm_1))));
                    }

                }
            }
            return _ic_set_8;
        }

        BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >> _tr_in_register_success() const {
            BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >> _ic_set_9 = BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >>();
            for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
                for(SERVICE _ic_ss_1 : services) {
                    for(SID _ic_si_1 : _SID.difference(sids)) {
                        if((in_localServices.domain().elementOf(_ic_si_1)._not()).booleanValue()) {
                            _ic_set_9 = _ic_set_9._union(BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >>((BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >((BTuple<INTERCONNECTNODE, SERVICE >(_ic_self_1, _ic_ss_1)), _ic_si_1))));
                        }

                    }
                }
            }
            return _ic_set_9;
        }

        BSet<BTuple<INTERCONNECTNODE, SERVICE >> _tr_in_register_failed() const {
            BSet<BTuple<INTERCONNECTNODE, SERVICE >> _ic_set_10 = BSet<BTuple<INTERCONNECTNODE, SERVICE >>();
            for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
                for(SERVICE _ic_ss_1 : services) {
                    _ic_set_10 = _ic_set_10._union(BSet<BTuple<INTERCONNECTNODE, SERVICE >>((BTuple<INTERCONNECTNODE, SERVICE >(_ic_self_1, _ic_ss_1))));

                }
            }
            return _ic_set_10;
        }

        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >> _tr_in_requestTargetSocket_Granted() const {
            BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >> _ic_set_11 = BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >>();
            for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
                for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                    for(SOCKET _ic_srcsoc_1 : sockets) {
                        for(SID _ic_srcsid_1 : sids) {
                            for(SID _ic_targsid_1 : sids) {
                                for(SOCKET _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                                    if(((BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue()))).booleanValue()) {
                                        _ic_set_11 = _ic_set_11._union(BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >>((BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >((BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >((BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >((BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >((BTuple<INTERCONNECTNODE, INTERCONNECTNODE >(_ic_self_1, _ic_ii_1)), _ic_srcsoc_1)), _ic_srcsid_1)), _ic_targsid_1)), _ic_newsoc_1))));
                                    }

                                }
                            }
                        }
                    }
                }
            }
            return _ic_set_11;
        }

        BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >> _tr_in_requestTargetSocket_NotGranted() const {
            BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >> _ic_set_12 = BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >>();
            for(INTERCONNECTNODE _ic_self_1 : interconnectNodes) {
                for(INTERCONNECTNODE _ic_ii_1 : interconnectNodes) {
                    for(SOCKET _ic_srcsoc_1 : sockets) {
                        for(SID _ic_srcsid_1 : sids) {
                            for(SID _ic_targsid_1 : sids) {
                                if(((BBoolean(_ic_self_1.unequal(_ic_ii_1).booleanValue() && in_sockets.functionCall(_ic_srcsoc_1).equal(_ic_ii_1).booleanValue()))).booleanValue()) {
                                    _ic_set_12 = _ic_set_12._union(BSet<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >>((BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >((BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >((BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >((BTuple<INTERCONNECTNODE, INTERCONNECTNODE >(_ic_self_1, _ic_ii_1)), _ic_srcsoc_1)), _ic_srcsid_1)), _ic_targsid_1))));
                                }

                            }
                        }
                    }
                }
            }
            return _ic_set_12;
        }

        BSet<SERVICE> _tr_svc_register() const {
            BSet<SERVICE> _ic_set_13 = BSet<SERVICE>();
            for(SERVICE _ic_self_1 : services) {
                if((svc_registered.functionCall(_ic_self_1).equal((BBoolean(false)))).booleanValue()) {
                    _ic_set_13 = _ic_set_13._union(BSet<SERVICE>(_ic_self_1));
                }

            }
            return _ic_set_13;
        }

        bool _check_inv_1() const {
            return (interconnectNodes.subset(_INTERCONNECTNODE)).booleanValue();
        }

        bool _check_inv_2() const {
            return (sockets.subset(_SOCKET)).booleanValue();
        }

        bool _check_inv_3() const {
            return (services.subset(_SERVICE)).booleanValue();
        }

        bool _check_inv_4() const {
            return (resourceManagers.subset(_RESOURCEMANAGER)).booleanValue();
        }

        bool _check_inv_5() const {
            return (sids.subset(_SID)).booleanValue();
        }

        bool _check_inv_6() const {
            return (((rm_services.checkDomain(resourceManagers))._and((rm_services.checkRange(services.pow())))._and((rm_services.isFunction()))._and((rm_services.isTotal(resourceManagers))))).booleanValue();
        }

        bool _check_inv_7() const {
            BBoolean _ic_boolean_14 = BBoolean(true);
            for(RESOURCEMANAGER _ic_a1_1 : rm_services.domain()) {
                for(RESOURCEMANAGER _ic_a2_1 : rm_services.domain()) {
                    if(!((BBoolean(!_ic_a1_1.unequal(_ic_a2_1).booleanValue() || rm_services.functionCall(_ic_a1_1).intersect(rm_services.functionCall(_ic_a2_1)).equal((BSet<SERVICE >())).booleanValue()))).booleanValue()) {
                        _ic_boolean_14 = BBoolean(false);
                        break;
                    }

                }
            }

            return (_ic_boolean_14).booleanValue();
        }

        bool _check_inv_8() const {
            return (((rm_sids.checkDomain(services))._and((rm_sids.checkRange(sids)))._and((rm_sids.isFunction()))._and((rm_sids.isPartial(services)))._and((rm_sids.isInjection())))).booleanValue();
        }

        bool _check_inv_9() const {
            return (((in_localServices.checkDomain(sids))._and((in_localServices.checkRange(interconnectNodes)))._and((in_localServices.isFunction()))._and((in_localServices.isTotal(sids))))).booleanValue();
        }

        bool _check_inv_10() const {
            return (((in_sockets.checkDomain(sockets))._and((in_sockets.checkRange(interconnectNodes)))._and((in_sockets.isFunction()))._and((in_sockets.isTotal(sockets))))).booleanValue();
        }

        bool _check_inv_11() const {
            return (((in_resourceManager.checkDomain(interconnectNodes))._and((in_resourceManager.checkRange(resourceManagers.pow())))._and((in_resourceManager.isFunction()))._and((in_resourceManager.isTotal(interconnectNodes))))).booleanValue();
        }

        bool _check_inv_12() const {
            return (((soc_to.checkDomain(sockets))._and((soc_to.checkRange(sids)))._and((soc_to.isFunction()))._and((soc_to.isTotal(sockets))))).booleanValue();
        }

        bool _check_inv_13() const {
            return (((soc_from.checkDomain(sockets))._and((soc_from.checkRange(sids)))._and((soc_from.isFunction()))._and((soc_from.isTotal(sockets))))).booleanValue();
        }

        bool _check_inv_14() const {
            return (((svc_serviceID.checkDomain(services))._and((svc_serviceID.checkRange(sids)))._and((svc_serviceID.isFunction()))._and((svc_serviceID.isPartial(services))))).booleanValue();
        }

        bool _check_inv_15() const {
            return (((svc_sockets.checkDomain(services))._and((svc_sockets.checkRange(sockets.pow())))._and((svc_sockets.isFunction()))._and((svc_sockets.isTotal(services))))).booleanValue();
        }

        bool _check_inv_16() const {
            return (((svc_ICNode.checkDomain(services))._and((svc_ICNode.checkRange(interconnectNodes)))._and((svc_ICNode.isFunction()))._and((svc_ICNode.isTotal(services))))).booleanValue();
        }

        bool _check_inv_17() const {
            return (((svc_registered.checkDomain(services))._and((svc_registered.checkRange((BOOL))))._and((svc_registered.isFunction()))._and((svc_registered.isTotal(services))))).booleanValue();
        }

        bool _check_inv_18() const {
            return ((BBoolean(!resourceManagers.equal((BSet<RESOURCEMANAGER >()))._not().booleanValue() || resourceManagers.card().equal((BInteger(1))).booleanValue()))).booleanValue();
        }

        nota_v2 _copy() const {
            return nota_v2(interconnectNodes, sockets, services, resourceManagers, sids, rm_services, rm_sids, in_localServices, in_sockets, in_resourceManager, soc_to, soc_from, svc_serviceID, svc_sockets, svc_ICNode, svc_registered);
        }

        friend bool operator ==(const nota_v2& o1, const nota_v2& o2) {
            return o1._get_interconnectNodes() == o2._get_interconnectNodes() && o1._get_sockets() == o2._get_sockets() && o1._get_services() == o2._get_services() && o1._get_resourceManagers() == o2._get_resourceManagers() && o1._get_sids() == o2._get_sids() && o1._get_rm_services() == o2._get_rm_services() && o1._get_rm_sids() == o2._get_rm_sids() && o1._get_in_localServices() == o2._get_in_localServices() && o1._get_in_sockets() == o2._get_in_sockets() && o1._get_in_resourceManager() == o2._get_in_resourceManager() && o1._get_soc_to() == o2._get_soc_to() && o1._get_soc_from() == o2._get_soc_from() && o1._get_svc_serviceID() == o2._get_svc_serviceID() && o1._get_svc_sockets() == o2._get_svc_sockets() && o1._get_svc_ICNode() == o2._get_svc_ICNode() && o1._get_svc_registered() == o2._get_svc_registered();
        }

        friend bool operator !=(const nota_v2& o1, const nota_v2& o2) {
            return o1._get_interconnectNodes() != o2._get_interconnectNodes() || o1._get_sockets() != o2._get_sockets() || o1._get_services() != o2._get_services() || o1._get_resourceManagers() != o2._get_resourceManagers() || o1._get_sids() != o2._get_sids() || o1._get_rm_services() != o2._get_rm_services() || o1._get_rm_sids() != o2._get_rm_sids() || o1._get_in_localServices() != o2._get_in_localServices() || o1._get_in_sockets() != o2._get_in_sockets() || o1._get_in_resourceManager() != o2._get_in_resourceManager() || o1._get_soc_to() != o2._get_soc_to() || o1._get_soc_from() != o2._get_soc_from() || o1._get_svc_serviceID() != o2._get_svc_serviceID() || o1._get_svc_sockets() != o2._get_svc_sockets() || o1._get_svc_ICNode() != o2._get_svc_ICNode() || o1._get_svc_registered() != o2._get_svc_registered();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_interconnectNodes()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_sockets()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_services()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_resourceManagers()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_sids()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_rm_services()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_rm_sids()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_in_localServices()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_in_sockets()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_in_resourceManager()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_soc_to()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_soc_from()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_svc_serviceID()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_svc_sockets()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_svc_ICNode()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_svc_registered()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_interconnectNodes()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_sockets()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_services()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_resourceManagers()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_sids()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_rm_services()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_rm_sids()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_in_localServices()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_in_sockets()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_in_resourceManager()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_soc_to()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_soc_from()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_svc_serviceID()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_svc_sockets()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_svc_ICNode()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_svc_registered()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const nota_v2 &machine) {
          strm << "_get_interconnectNodes: " << machine._get_interconnectNodes() << "\n";
          strm << "_get_sockets: " << machine._get_sockets() << "\n";
          strm << "_get_services: " << machine._get_services() << "\n";
          strm << "_get_resourceManagers: " << machine._get_resourceManagers() << "\n";
          strm << "_get_sids: " << machine._get_sids() << "\n";
          strm << "_get_rm_services: " << machine._get_rm_services() << "\n";
          strm << "_get_rm_sids: " << machine._get_rm_sids() << "\n";
          strm << "_get_in_localServices: " << machine._get_in_localServices() << "\n";
          strm << "_get_in_sockets: " << machine._get_in_sockets() << "\n";
          strm << "_get_in_resourceManager: " << machine._get_in_resourceManager() << "\n";
          strm << "_get_soc_to: " << machine._get_soc_to() << "\n";
          strm << "_get_soc_from: " << machine._get_soc_from() << "\n";
          strm << "_get_svc_serviceID: " << machine._get_svc_serviceID() << "\n";
          strm << "_get_svc_sockets: " << machine._get_svc_sockets() << "\n";
          strm << "_get_svc_ICNode: " << machine._get_svc_ICNode() << "\n";
          strm << "_get_svc_registered: " << machine._get_svc_registered() << "\n";
          return strm;
        }


};


static std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> generateNextStates(std::mutex& guardMutex, const nota_v2& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual>& dependentGuard, std::unordered_map<nota_v2, immer::map<string, boost::any>, nota_v2::Hash, nota_v2::HashEqual>& guardCache, std::unordered_map<nota_v2, nota_v2, nota_v2::Hash, nota_v2::HashEqual>& parents, std::unordered_map<nota_v2, string, nota_v2::Hash, nota_v2::HashEqual>& stateAccessedVia, std::atomic<int>& transitions) {
    std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> result = std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual>();
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
        BSet<nota_v2::INTERCONNECTNODE> _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_constructor_interconnectNode"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_constructor_interconnectNode") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_1 = state._tr_constructor_interconnectNode();
        } else {
            _trid_1 = boost::any_cast<BSet<nota_v2::INTERCONNECTNODE>>(cachedValue);
        }
        newCache = newCache.set("_tr_constructor_interconnectNode", _trid_1);
        for(const nota_v2::INTERCONNECTNODE& param : _trid_1) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.constructor_interconnectNode(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["constructor_interconnectNode"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["constructor_interconnectNode"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_interconnectNode"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<nota_v2::RESOURCEMANAGER> _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_constructor_resourceManager"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_constructor_resourceManager") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_2 = state._tr_constructor_resourceManager();
        } else {
            _trid_2 = boost::any_cast<BSet<nota_v2::RESOURCEMANAGER>>(cachedValue);
        }
        newCache = newCache.set("_tr_constructor_resourceManager", _trid_2);
        for(const nota_v2::RESOURCEMANAGER& param : _trid_2) {
            nota_v2::RESOURCEMANAGER _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.constructor_resourceManager(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["constructor_resourceManager"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["constructor_resourceManager"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_resourceManager"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_constructor_service"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_constructor_service") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_3 = state._tr_constructor_service();
        } else {
            _trid_3 = boost::any_cast<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_constructor_service", _trid_3);
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_3) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.constructor_service(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["constructor_service"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["constructor_service"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_service"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_constructor_socket"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_constructor_socket") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_4 = state._tr_constructor_socket();
        } else {
            _trid_4 = boost::any_cast<BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>>(cachedValue);
        }
        newCache = newCache.set("_tr_constructor_socket", _trid_4);
        for(const BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >& param : _trid_4) {
            nota_v2::SOCKET _tmp_1 = param.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID > _tmp_4 = _tmp_2.projection1();
            nota_v2::SID _tmp_5 = _tmp_4.projection2();
            nota_v2::INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["constructor_socket"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["constructor_socket"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_socket"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_5;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_rm_register"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_rm_register") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_5 = state._tr_rm_register();
        } else {
            _trid_5 = boost::any_cast<BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_rm_register", _trid_5);
        for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_5) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
            BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["rm_register"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["rm_register"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_register"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_6;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_rm_deregister"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_rm_deregister") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_6 = state._tr_rm_deregister();
        } else {
            _trid_6 = boost::any_cast<BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_rm_deregister", _trid_6);
        for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_6) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
            BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["rm_deregister"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["rm_deregister"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_deregister"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_7;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_rm_getSid"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_rm_getSid") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_7 = state._tr_rm_getSid();
        } else {
            _trid_7 = boost::any_cast<BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_rm_getSid", _trid_7);
        for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_7) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_getSid(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["rm_getSid"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["rm_getSid"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_getSid"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_8;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_rm_getSid_Not_Found"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_rm_getSid_Not_Found") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_8 = state._tr_rm_getSid_Not_Found();
        } else {
            _trid_8 = boost::any_cast<BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_rm_getSid_Not_Found", _trid_8);
        for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_8) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["rm_getSid_Not_Found"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["rm_getSid_Not_Found"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_getSid_Not_Found"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >> _trid_9;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_in_announceResourceManager"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_in_announceResourceManager") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_9 = state._tr_in_announceResourceManager();
        } else {
            _trid_9 = boost::any_cast<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >>>(cachedValue);
        }
        newCache = newCache.set("_tr_in_announceResourceManager", _trid_9);
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >& param : _trid_9) {
            nota_v2::RESOURCEMANAGER _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["in_announceResourceManager"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["in_announceResourceManager"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_announceResourceManager"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >> _trid_10;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_in_register_success"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_in_register_success") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_10 = state._tr_in_register_success();
        } else {
            _trid_10 = boost::any_cast<BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >>>(cachedValue);
        }
        newCache = newCache.set("_tr_in_register_success", _trid_10);
        for(const BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >& param : _trid_10) {
            nota_v2::SID _tmp_1 = param.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["in_register_success"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["in_register_success"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_register_success"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_11;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_in_register_failed"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_in_register_failed") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_11 = state._tr_in_register_failed();
        } else {
            _trid_11 = boost::any_cast<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>>(cachedValue);
        }
        newCache = newCache.set("_tr_in_register_failed", _trid_11);
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_11) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_register_failed(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["in_register_failed"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["in_register_failed"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_register_failed"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_12;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_in_requestTargetSocket_Granted"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_in_requestTargetSocket_Granted") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_12 = state._tr_in_requestTargetSocket_Granted();
        } else {
            _trid_12 = boost::any_cast<BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>>(cachedValue);
        }
        newCache = newCache.set("_tr_in_requestTargetSocket_Granted", _trid_12);
        for(const BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >& param : _trid_12) {
            nota_v2::SOCKET _tmp_1 = param.projection2();
            BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID > _tmp_4 = _tmp_2.projection1();
            nota_v2::SID _tmp_5 = _tmp_4.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET > _tmp_6 = _tmp_4.projection1();
            nota_v2::SOCKET _tmp_7 = _tmp_6.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE > _tmp_8 = _tmp_6.projection1();
            nota_v2::INTERCONNECTNODE _tmp_9 = _tmp_8.projection2();
            nota_v2::INTERCONNECTNODE _tmp_10 = _tmp_8.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["in_requestTargetSocket_Granted"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["in_requestTargetSocket_Granted"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_requestTargetSocket_Granted"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >> _trid_13;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_in_requestTargetSocket_NotGranted"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_in_requestTargetSocket_NotGranted") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
        } else {
            _trid_13 = boost::any_cast<BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >>>(cachedValue);
        }
        newCache = newCache.set("_tr_in_requestTargetSocket_NotGranted", _trid_13);
        for(const BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >& param : _trid_13) {
            nota_v2::SID _tmp_1 = param.projection2();
            BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET > _tmp_4 = _tmp_2.projection1();
            nota_v2::SOCKET _tmp_5 = _tmp_4.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE > _tmp_6 = _tmp_4.projection1();
            nota_v2::INTERCONNECTNODE _tmp_7 = _tmp_6.projection2();
            nota_v2::INTERCONNECTNODE _tmp_8 = _tmp_6.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["in_requestTargetSocket_NotGranted"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["in_requestTargetSocket_NotGranted"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_requestTargetSocket_NotGranted"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<nota_v2::SERVICE> _trid_14;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_svc_register"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_svc_register") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || !parentsExist) {
            _trid_14 = state._tr_svc_register();
        } else {
            _trid_14 = boost::any_cast<BSet<nota_v2::SERVICE>>(cachedValue);
        }
        newCache = newCache.set("_tr_svc_register", _trid_14);
        for(const nota_v2::SERVICE& param : _trid_14) {
            nota_v2::SERVICE _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.svc_register(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["svc_register"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["svc_register"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "svc_register"});
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
        BSet<nota_v2::INTERCONNECTNODE> _trid_1 = state._tr_constructor_interconnectNode();
        for(const nota_v2::INTERCONNECTNODE& param : _trid_1) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.constructor_interconnectNode(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_interconnectNode"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<nota_v2::RESOURCEMANAGER> _trid_2 = state._tr_constructor_resourceManager();
        for(const nota_v2::RESOURCEMANAGER& param : _trid_2) {
            nota_v2::RESOURCEMANAGER _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.constructor_resourceManager(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_resourceManager"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_3 = state._tr_constructor_service();
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_3) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.constructor_service(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_service"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_4 = state._tr_constructor_socket();
        for(const BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >& param : _trid_4) {
            nota_v2::SOCKET _tmp_1 = param.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID > _tmp_4 = _tmp_2.projection1();
            nota_v2::SID _tmp_5 = _tmp_4.projection2();
            nota_v2::INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "constructor_socket"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_5 = state._tr_rm_register();
        for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_5) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
            BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_register"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_6 = state._tr_rm_deregister();
        for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_6) {
            nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
            BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_deregister"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_7 = state._tr_rm_getSid();
        for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_7) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_getSid(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_getSid"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_8 = state._tr_rm_getSid_Not_Found();
        for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_8) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "rm_getSid_Not_Found"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >> _trid_9 = state._tr_in_announceResourceManager();
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >& param : _trid_9) {
            nota_v2::RESOURCEMANAGER _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_announceResourceManager"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >> _trid_10 = state._tr_in_register_success();
        for(const BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >& param : _trid_10) {
            nota_v2::SID _tmp_1 = param.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE > _tmp_2 = param.projection1();
            nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
            nota_v2::INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_register_success"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_11 = state._tr_in_register_failed();
        for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_11) {
            nota_v2::SERVICE _tmp_1 = param.projection2();
            nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_register_failed(_tmp_2, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_register_failed"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_12 = state._tr_in_requestTargetSocket_Granted();
        for(const BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >& param : _trid_12) {
            nota_v2::SOCKET _tmp_1 = param.projection2();
            BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID > _tmp_4 = _tmp_2.projection1();
            nota_v2::SID _tmp_5 = _tmp_4.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET > _tmp_6 = _tmp_4.projection1();
            nota_v2::SOCKET _tmp_7 = _tmp_6.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE > _tmp_8 = _tmp_6.projection1();
            nota_v2::INTERCONNECTNODE _tmp_9 = _tmp_8.projection2();
            nota_v2::INTERCONNECTNODE _tmp_10 = _tmp_8.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_requestTargetSocket_Granted"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >> _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
        for(const BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >& param : _trid_13) {
            nota_v2::SID _tmp_1 = param.projection2();
            BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID > _tmp_2 = param.projection1();
            nota_v2::SID _tmp_3 = _tmp_2.projection2();
            BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET > _tmp_4 = _tmp_2.projection1();
            nota_v2::SOCKET _tmp_5 = _tmp_4.projection2();
            BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE > _tmp_6 = _tmp_4.projection1();
            nota_v2::INTERCONNECTNODE _tmp_7 = _tmp_6.projection2();
            nota_v2::INTERCONNECTNODE _tmp_8 = _tmp_6.projection1();

            nota_v2 copiedState = state._copy();
            copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "in_requestTargetSocket_NotGranted"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        BSet<nota_v2::SERVICE> _trid_14 = state._tr_svc_register();
        for(const nota_v2::SERVICE& param : _trid_14) {
            nota_v2::SERVICE _tmp_1 = param;

            nota_v2 copiedState = state._copy();
            copiedState.svc_register(_tmp_1);
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "svc_register"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated, nota_v2& counterExampleState, std::unordered_map<nota_v2, nota_v2, nota_v2::Hash, nota_v2::HashEqual>& parents, std::unordered_map<nota_v2, string, nota_v2::Hash, nota_v2::HashEqual>& stateAccessedVia) {
    if(deadlockDetected || invariantViolated) {
        if(deadlockDetected) {
            cout << "DEADLOCK DETECTED" << "\n";
        }
        if(invariantViolated) {
            cout << "INVARIANT VIOLATED" << "\n";
        }
        cout << "COUNTER EXAMPLE TRACE: " << "\n";

        nota_v2 currentState = counterExampleState;
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

static bool checkInvariants(std::mutex& guardMutex, const nota_v2& state, bool isCaching, std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual>& dependentInvariant) {
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
        if(dependentInvariantsOfState.find("_check_inv_13") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_13()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_14") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_14()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_15") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_15()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_16") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_16()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_17") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_17()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_18") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_18()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18());
}

static nota_v2 next(std::list<nota_v2>& collection, std::mutex& mutex, nota_v2::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case nota_v2::BFS: {
            nota_v2 state = collection.front();
            collection.pop_front();
            return state;
        }
        case nota_v2::DFS: {
            nota_v2 state = collection.back();
            collection.pop_back();
            return state;
        }
        case nota_v2::MIXED: {
            if(collection.size() % 2 == 0) {
                nota_v2 state = collection.front();
                collection.pop_front();
                return state;
            } else {
                nota_v2 state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(nota_v2::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    nota_v2 machine = nota_v2();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> states = std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<nota_v2> collection = std::list<nota_v2>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual> dependentInvariant;
    std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual> dependentGuard;
    std::unordered_map<nota_v2, immer::map<string, boost::any>, nota_v2::Hash, nota_v2::HashEqual> guardCache;
    std::unordered_map<nota_v2, nota_v2, nota_v2::Hash, nota_v2::HashEqual> parents;
    std::unordered_map<nota_v2, string, nota_v2::Hash, nota_v2::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"in_register_success", {"_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"in_announceResourceManager", {"_check_inv_11"}});
        invariantDependency.insert({"in_requestTargetSocket_Granted", {"_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"}});
        invariantDependency.insert({"constructor_service", {"_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"}});
        invariantDependency.insert({"constructor_socket", {"_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"}});
        invariantDependency.insert({"in_requestTargetSocket_NotGranted", {}});
        invariantDependency.insert({"constructor_interconnectNode", {"_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"}});
        invariantDependency.insert({"rm_getSid", {}});
        invariantDependency.insert({"rm_deregister", {}});
        invariantDependency.insert({"constructor_resourceManager", {"_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"}});
        invariantDependency.insert({"in_register_failed", {}});
        invariantDependency.insert({"rm_register", {}});
        invariantDependency.insert({"rm_getSid_Not_Found", {}});
        invariantDependency.insert({"svc_register", {"_check_inv_17"}});
        guardDependency.insert({"in_register_success", {"_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"in_announceResourceManager", {"_tr_in_announceResourceManager"}});
        guardDependency.insert({"in_requestTargetSocket_Granted", {"_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"constructor_service", {"_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"}});
        guardDependency.insert({"constructor_socket", {"_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"in_requestTargetSocket_NotGranted", {}});
        guardDependency.insert({"constructor_interconnectNode", {"_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"}});
        guardDependency.insert({"rm_getSid", {}});
        guardDependency.insert({"rm_deregister", {}});
        guardDependency.insert({"constructor_resourceManager", {"_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"}});
        guardDependency.insert({"in_register_failed", {}});
        guardDependency.insert({"rm_register", {}});
        guardDependency.insert({"rm_getSid_Not_Found", {}});
        guardDependency.insert({"svc_register", {"_tr_svc_register"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    nota_v2 counterExampleState;

    while(!collection.empty() && !stopThreads) {
        nota_v2 state = next(collection, mutex, type);

        std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);
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

static void modelCheckMultiThreaded(nota_v2::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    nota_v2 machine = nota_v2();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> states = std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<nota_v2> collection = std::list<nota_v2>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual> dependentInvariant;
    std::unordered_map<nota_v2, std::unordered_set<string>, nota_v2::Hash, nota_v2::HashEqual> dependentGuard;
    std::unordered_map<nota_v2, immer::map<string, boost::any>, nota_v2::Hash, nota_v2::HashEqual> guardCache;
    std::unordered_map<nota_v2, nota_v2, nota_v2::Hash, nota_v2::HashEqual> parents;
    std::unordered_map<nota_v2, string, nota_v2::Hash, nota_v2::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"in_register_success", {"_check_inv_5", "_check_inv_14", "_check_inv_13", "_check_inv_8", "_check_inv_12", "_check_inv_9"}});
        invariantDependency.insert({"in_announceResourceManager", {"_check_inv_11"}});
        invariantDependency.insert({"in_requestTargetSocket_Granted", {"_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"}});
        invariantDependency.insert({"constructor_service", {"_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_3", "_check_inv_6", "_check_inv_14", "_check_inv_8"}});
        invariantDependency.insert({"constructor_socket", {"_check_inv_15", "_check_inv_2", "_check_inv_10", "_check_inv_13", "_check_inv_12"}});
        invariantDependency.insert({"in_requestTargetSocket_NotGranted", {}});
        invariantDependency.insert({"constructor_interconnectNode", {"_check_inv_16", "_check_inv_1", "_check_inv_10", "_check_inv_9", "_check_inv_11"}});
        invariantDependency.insert({"rm_getSid", {}});
        invariantDependency.insert({"rm_deregister", {}});
        invariantDependency.insert({"constructor_resourceManager", {"_check_inv_18", "_check_inv_6", "_check_inv_7", "_check_inv_4", "_check_inv_11"}});
        invariantDependency.insert({"in_register_failed", {}});
        invariantDependency.insert({"rm_register", {}});
        invariantDependency.insert({"rm_getSid_Not_Found", {}});
        invariantDependency.insert({"svc_register", {"_check_inv_17"}});
        guardDependency.insert({"in_register_success", {"_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"in_announceResourceManager", {"_tr_in_announceResourceManager"}});
        guardDependency.insert({"in_requestTargetSocket_Granted", {"_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"constructor_service", {"_tr_constructor_service", "_tr_rm_getSid", "_tr_in_register_success", "_tr_svc_register", "_tr_in_register_failed", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister"}});
        guardDependency.insert({"constructor_socket", {"_tr_in_requestTargetSocket_Granted", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket"}});
        guardDependency.insert({"in_requestTargetSocket_NotGranted", {}});
        guardDependency.insert({"constructor_interconnectNode", {"_tr_constructor_service", "_tr_in_register_success", "_tr_in_requestTargetSocket_Granted", "_tr_in_register_failed", "_tr_rm_register", "_tr_in_requestTargetSocket_NotGranted", "_tr_constructor_socket", "_tr_rm_deregister", "_tr_constructor_interconnectNode", "_tr_in_announceResourceManager"}});
        guardDependency.insert({"rm_getSid", {}});
        guardDependency.insert({"rm_deregister", {}});
        guardDependency.insert({"constructor_resourceManager", {"_tr_rm_getSid", "_tr_constructor_resourceManager", "_tr_rm_register", "_tr_rm_getSid_Not_Found", "_tr_rm_deregister", "_tr_in_announceResourceManager"}});
        guardDependency.insert({"in_register_failed", {}});
        guardDependency.insert({"rm_register", {}});
        guardDependency.insert({"rm_getSid_Not_Found", {}});
        guardDependency.insert({"svc_register", {"_tr_svc_register"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    nota_v2 counterExampleState;

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        nota_v2 state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);


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

    nota_v2::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = nota_v2::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = nota_v2::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = nota_v2::Type::DFS;
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