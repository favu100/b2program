#include <iostream>
#include <string>
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
#include <boost/any.hpp>
#include <boost/optional.hpp>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/VariantViolation.hpp>
#include <btypes_primitives/LoopInvariantViolation.hpp>
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

        class _ProjectionRead_constructor_interconnectNode {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_constructor_interconnectNode& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_constructor_interconnectNode& obj1, const _ProjectionRead_constructor_interconnectNode& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;

                _ProjectionRead_constructor_interconnectNode(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_resourceManager = in_resourceManager;
                }

                friend bool operator ==(const _ProjectionRead_constructor_interconnectNode& o1, const _ProjectionRead_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_resourceManager == (o2.in_resourceManager);
                }

                friend bool operator !=(const _ProjectionRead_constructor_interconnectNode& o1, const _ProjectionRead_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_resourceManager != (o2.in_resourceManager);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_constructor_interconnectNode& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_resourceManager: " << e.in_resourceManager;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_constructor_interconnectNode {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_constructor_interconnectNode& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_constructor_interconnectNode& obj1, const _ProjectionRead__tr_constructor_interconnectNode& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;

                _ProjectionRead__tr_constructor_interconnectNode(const BSet<INTERCONNECTNODE >& interconnectNodes) {
                    this->interconnectNodes = interconnectNodes;
                }

                friend bool operator ==(const _ProjectionRead__tr_constructor_interconnectNode& o1, const _ProjectionRead__tr_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes);
                }

                friend bool operator !=(const _ProjectionRead__tr_constructor_interconnectNode& o1, const _ProjectionRead__tr_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_constructor_interconnectNode& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_constructor_interconnectNode {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_constructor_interconnectNode& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_constructor_interconnectNode& obj1, const _ProjectionWrite_constructor_interconnectNode& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;

                _ProjectionWrite_constructor_interconnectNode(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_resourceManager = in_resourceManager;
                }

                friend bool operator ==(const _ProjectionWrite_constructor_interconnectNode& o1, const _ProjectionWrite_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_resourceManager == (o2.in_resourceManager);
                }

                friend bool operator !=(const _ProjectionWrite_constructor_interconnectNode& o1, const _ProjectionWrite_constructor_interconnectNode& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_resourceManager != (o2.in_resourceManager);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_constructor_interconnectNode& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_resourceManager: " << e.in_resourceManager;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_constructor_resourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_constructor_resourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_constructor_resourceManager& obj1, const _ProjectionRead_constructor_resourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead_constructor_resourceManager(const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->rm_services = rm_services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead_constructor_resourceManager& o1, const _ProjectionRead_constructor_resourceManager& o2) {
                    return o1.rm_services == (o2.rm_services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead_constructor_resourceManager& o1, const _ProjectionRead_constructor_resourceManager& o2) {
                    return o1.rm_services != (o2.rm_services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_constructor_resourceManager& e) {
                    strm << "{";
                    strm << "rm_services: " << e.rm_services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rm_services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_constructor_resourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_constructor_resourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_constructor_resourceManager& obj1, const _ProjectionRead__tr_constructor_resourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__tr_constructor_resourceManager(const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->rm_services = rm_services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__tr_constructor_resourceManager& o1, const _ProjectionRead__tr_constructor_resourceManager& o2) {
                    return o1.rm_services == (o2.rm_services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__tr_constructor_resourceManager& o1, const _ProjectionRead__tr_constructor_resourceManager& o2) {
                    return o1.rm_services != (o2.rm_services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_constructor_resourceManager& e) {
                    strm << "{";
                    strm << "rm_services: " << e.rm_services;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rm_services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_constructor_resourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_constructor_resourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_constructor_resourceManager& obj1, const _ProjectionWrite_constructor_resourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionWrite_constructor_resourceManager(const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->rm_services = rm_services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionWrite_constructor_resourceManager& o1, const _ProjectionWrite_constructor_resourceManager& o2) {
                    return o1.rm_services == (o2.rm_services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionWrite_constructor_resourceManager& o1, const _ProjectionWrite_constructor_resourceManager& o2) {
                    return o1.rm_services != (o2.rm_services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_constructor_resourceManager& e) {
                    strm << "{";
                    strm << "rm_services: " << e.rm_services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rm_services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_constructor_service {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_constructor_service& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_constructor_service& obj1, const _ProjectionRead_constructor_service& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SERVICE, BBoolean > svc_registered;
                BRelation<SERVICE, BSet<SOCKET > > svc_sockets;
                BSet<SERVICE > services;
                BRelation<SERVICE, INTERCONNECTNODE > svc_ICNode;

                _ProjectionRead_constructor_service(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SERVICE, BBoolean >& svc_registered, const BRelation<SERVICE, BSet<SOCKET > >& svc_sockets, const BSet<SERVICE >& services, const BRelation<SERVICE, INTERCONNECTNODE >& svc_ICNode) {
                    this->interconnectNodes = interconnectNodes;
                    this->svc_registered = svc_registered;
                    this->svc_sockets = svc_sockets;
                    this->services = services;
                    this->svc_ICNode = svc_ICNode;
                }

                friend bool operator ==(const _ProjectionRead_constructor_service& o1, const _ProjectionRead_constructor_service& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.svc_registered == (o2.svc_registered) && o1.svc_sockets == (o2.svc_sockets) && o1.services == (o2.services) && o1.svc_ICNode == (o2.svc_ICNode);
                }

                friend bool operator !=(const _ProjectionRead_constructor_service& o1, const _ProjectionRead_constructor_service& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.svc_registered != (o2.svc_registered) || o1.svc_sockets != (o2.svc_sockets) || o1.services != (o2.services) || o1.svc_ICNode != (o2.svc_ICNode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_constructor_service& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "svc_registered: " << e.svc_registered;
                    strm << ", ";
                    strm << "svc_sockets: " << e.svc_sockets;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "svc_ICNode: " << e.svc_ICNode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (svc_registered.hashCode() << 1);
                    result = 31 * result + (svc_sockets.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (svc_ICNode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_constructor_service {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_constructor_service& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_constructor_service& obj1, const _ProjectionRead__tr_constructor_service& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;

                _ProjectionRead__tr_constructor_service(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__tr_constructor_service& o1, const _ProjectionRead__tr_constructor_service& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__tr_constructor_service& o1, const _ProjectionRead__tr_constructor_service& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_constructor_service& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_constructor_service {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_constructor_service& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_constructor_service& obj1, const _ProjectionWrite_constructor_service& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BBoolean > svc_registered;
                BRelation<SERVICE, BSet<SOCKET > > svc_sockets;
                BSet<SERVICE > services;
                BRelation<SERVICE, SID > svc_serviceID;
                BRelation<SERVICE, INTERCONNECTNODE > svc_ICNode;

                _ProjectionWrite_constructor_service(const BRelation<SERVICE, BBoolean >& svc_registered, const BRelation<SERVICE, BSet<SOCKET > >& svc_sockets, const BSet<SERVICE >& services, const BRelation<SERVICE, SID >& svc_serviceID, const BRelation<SERVICE, INTERCONNECTNODE >& svc_ICNode) {
                    this->svc_registered = svc_registered;
                    this->svc_sockets = svc_sockets;
                    this->services = services;
                    this->svc_serviceID = svc_serviceID;
                    this->svc_ICNode = svc_ICNode;
                }

                friend bool operator ==(const _ProjectionWrite_constructor_service& o1, const _ProjectionWrite_constructor_service& o2) {
                    return o1.svc_registered == (o2.svc_registered) && o1.svc_sockets == (o2.svc_sockets) && o1.services == (o2.services) && o1.svc_serviceID == (o2.svc_serviceID) && o1.svc_ICNode == (o2.svc_ICNode);
                }

                friend bool operator !=(const _ProjectionWrite_constructor_service& o1, const _ProjectionWrite_constructor_service& o2) {
                    return o1.svc_registered != (o2.svc_registered) || o1.svc_sockets != (o2.svc_sockets) || o1.services != (o2.services) || o1.svc_serviceID != (o2.svc_serviceID) || o1.svc_ICNode != (o2.svc_ICNode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_constructor_service& e) {
                    strm << "{";
                    strm << "svc_registered: " << e.svc_registered;
                    strm << ", ";
                    strm << "svc_sockets: " << e.svc_sockets;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "svc_serviceID: " << e.svc_serviceID;
                    strm << ", ";
                    strm << "svc_ICNode: " << e.svc_ICNode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_registered.hashCode() << 1);
                    result = 31 * result + (svc_sockets.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (svc_serviceID.hashCode() << 1);
                    result = 31 * result + (svc_ICNode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_constructor_socket {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_constructor_socket& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_constructor_socket& obj1, const _ProjectionRead_constructor_socket& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BRelation<SOCKET, SID > soc_to;
                BRelation<SOCKET, SID > soc_from;
                BSet<SOCKET > sockets;

                _ProjectionRead_constructor_socket(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BRelation<SOCKET, SID >& soc_to, const BRelation<SOCKET, SID >& soc_from, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_sockets = in_sockets;
                    this->soc_to = soc_to;
                    this->soc_from = soc_from;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead_constructor_socket& o1, const _ProjectionRead_constructor_socket& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_sockets == (o2.in_sockets) && o1.soc_to == (o2.soc_to) && o1.soc_from == (o2.soc_from) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead_constructor_socket& o1, const _ProjectionRead_constructor_socket& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_sockets != (o2.in_sockets) || o1.soc_to != (o2.soc_to) || o1.soc_from != (o2.soc_from) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_constructor_socket& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "soc_to: " << e.soc_to;
                    strm << ", ";
                    strm << "soc_from: " << e.soc_from;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (soc_to.hashCode() << 1);
                    result = 31 * result + (soc_from.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_constructor_socket {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_constructor_socket& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_constructor_socket& obj1, const _ProjectionRead__tr_constructor_socket& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SOCKET > sockets;

                _ProjectionRead__tr_constructor_socket(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__tr_constructor_socket& o1, const _ProjectionRead__tr_constructor_socket& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__tr_constructor_socket& o1, const _ProjectionRead__tr_constructor_socket& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_constructor_socket& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", "; 
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_constructor_socket {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_constructor_socket& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_constructor_socket& obj1, const _ProjectionWrite_constructor_socket& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BRelation<SOCKET, SID > soc_to;
                BRelation<SOCKET, SID > soc_from;
                BSet<SOCKET > sockets;

                _ProjectionWrite_constructor_socket(const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BRelation<SOCKET, SID >& soc_to, const BRelation<SOCKET, SID >& soc_from, const BSet<SOCKET >& sockets) {
                    this->in_sockets = in_sockets;
                    this->soc_to = soc_to;
                    this->soc_from = soc_from;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionWrite_constructor_socket& o1, const _ProjectionWrite_constructor_socket& o2) {
                    return o1.in_sockets == (o2.in_sockets) && o1.soc_to == (o2.soc_to) && o1.soc_from == (o2.soc_from) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionWrite_constructor_socket& o1, const _ProjectionWrite_constructor_socket& o2) {
                    return o1.in_sockets != (o2.in_sockets) || o1.soc_to != (o2.soc_to) || o1.soc_from != (o2.soc_from) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_constructor_socket& e) {
                    strm << "{";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "soc_to: " << e.soc_to;
                    strm << ", ";
                    strm << "soc_from: " << e.soc_from;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (soc_to.hashCode() << 1);
                    result = 31 * result + (soc_from.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_rm_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_rm_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_rm_register& obj1, const _ProjectionRead_rm_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead_rm_register(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead_rm_register& o1, const _ProjectionRead_rm_register& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead_rm_register& o1, const _ProjectionRead_rm_register& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_rm_register& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_rm_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_rm_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_rm_register& obj1, const _ProjectionRead__tr_rm_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__tr_rm_register(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__tr_rm_register& o1, const _ProjectionRead__tr_rm_register& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__tr_rm_register& o1, const _ProjectionRead__tr_rm_register& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_rm_register& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "services: " << e.services;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_rm_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_rm_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_rm_register& obj1, const _ProjectionWrite_rm_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_rm_register() {
                }

                friend bool operator ==(const _ProjectionWrite_rm_register& o1, const _ProjectionWrite_rm_register& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_rm_register& o1, const _ProjectionWrite_rm_register& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_rm_register& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_rm_deregister {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_rm_deregister& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_rm_deregister& obj1, const _ProjectionRead_rm_deregister& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead_rm_deregister(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead_rm_deregister& o1, const _ProjectionRead_rm_deregister& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead_rm_deregister& o1, const _ProjectionRead_rm_deregister& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_rm_deregister& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_rm_deregister {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_rm_deregister& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_rm_deregister& obj1, const _ProjectionRead__tr_rm_deregister& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__tr_rm_deregister(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__tr_rm_deregister& o1, const _ProjectionRead__tr_rm_deregister& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__tr_rm_deregister& o1, const _ProjectionRead__tr_rm_deregister& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_rm_deregister& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "services: " << e.services;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_rm_deregister {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_rm_deregister& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_rm_deregister& obj1, const _ProjectionWrite_rm_deregister& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_rm_deregister() {
                }

                friend bool operator ==(const _ProjectionWrite_rm_deregister& o1, const _ProjectionWrite_rm_deregister& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_rm_deregister& o1, const _ProjectionWrite_rm_deregister& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_rm_deregister& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_rm_getSid {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_rm_getSid& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_rm_getSid& obj1, const _ProjectionRead_rm_getSid& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;
                BRelation<SERVICE, SID > rm_sids;

                _ProjectionRead_rm_getSid(const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers, const BRelation<SERVICE, SID >& rm_sids) {
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                    this->rm_sids = rm_sids;
                }

                friend bool operator ==(const _ProjectionRead_rm_getSid& o1, const _ProjectionRead_rm_getSid& o2) {
                    return o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers) && o1.rm_sids == (o2.rm_sids);
                }

                friend bool operator !=(const _ProjectionRead_rm_getSid& o1, const _ProjectionRead_rm_getSid& o2) {
                    return o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers) || o1.rm_sids != (o2.rm_sids);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_rm_getSid& e) {
                    strm << "{";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;
                    strm << ", ";
                    strm << "rm_sids: " << e.rm_sids;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    result = 31 * result + (rm_sids.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_rm_getSid {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_rm_getSid& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_rm_getSid& obj1, const _ProjectionRead__tr_rm_getSid& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;
                BRelation<SERVICE, SID > rm_sids;

                _ProjectionRead__tr_rm_getSid(const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers, const BRelation<SERVICE, SID >& rm_sids) {
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                    this->rm_sids = rm_sids;
                }

                friend bool operator ==(const _ProjectionRead__tr_rm_getSid& o1, const _ProjectionRead__tr_rm_getSid& o2) {
                    return o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers) && o1.rm_sids == (o2.rm_sids);
                }

                friend bool operator !=(const _ProjectionRead__tr_rm_getSid& o1, const _ProjectionRead__tr_rm_getSid& o2) {
                    return o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers) || o1.rm_sids != (o2.rm_sids);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_rm_getSid& e) {
                    strm << "{";
                    strm << "services: " << e.services;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;
                    strm << ", "; 
                    strm << "rm_sids: " << e.rm_sids;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    result = 31 * result + (rm_sids.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_rm_getSid {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_rm_getSid& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_rm_getSid& obj1, const _ProjectionWrite_rm_getSid& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_rm_getSid() {
                }

                friend bool operator ==(const _ProjectionWrite_rm_getSid& o1, const _ProjectionWrite_rm_getSid& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_rm_getSid& o1, const _ProjectionWrite_rm_getSid& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_rm_getSid& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_rm_getSid_Not_Found {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_rm_getSid_Not_Found& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_rm_getSid_Not_Found& obj1, const _ProjectionRead_rm_getSid_Not_Found& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead_rm_getSid_Not_Found(const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead_rm_getSid_Not_Found& o1, const _ProjectionRead_rm_getSid_Not_Found& o2) {
                    return o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead_rm_getSid_Not_Found& o1, const _ProjectionRead_rm_getSid_Not_Found& o2) {
                    return o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_rm_getSid_Not_Found& e) {
                    strm << "{";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_rm_getSid_Not_Found {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_rm_getSid_Not_Found& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_rm_getSid_Not_Found& obj1, const _ProjectionRead__tr_rm_getSid_Not_Found& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__tr_rm_getSid_Not_Found(const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__tr_rm_getSid_Not_Found& o1, const _ProjectionRead__tr_rm_getSid_Not_Found& o2) {
                    return o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__tr_rm_getSid_Not_Found& o1, const _ProjectionRead__tr_rm_getSid_Not_Found& o2) {
                    return o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_rm_getSid_Not_Found& e) {
                    strm << "{";
                    strm << "services: " << e.services;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_rm_getSid_Not_Found {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_rm_getSid_Not_Found& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_rm_getSid_Not_Found& obj1, const _ProjectionWrite_rm_getSid_Not_Found& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_rm_getSid_Not_Found() {
                }

                friend bool operator ==(const _ProjectionWrite_rm_getSid_Not_Found& o1, const _ProjectionWrite_rm_getSid_Not_Found& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_rm_getSid_Not_Found& o1, const _ProjectionWrite_rm_getSid_Not_Found& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_rm_getSid_Not_Found& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_in_announceResourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_in_announceResourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_in_announceResourceManager& obj1, const _ProjectionRead_in_announceResourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead_in_announceResourceManager(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_resourceManager = in_resourceManager;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead_in_announceResourceManager& o1, const _ProjectionRead_in_announceResourceManager& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_resourceManager == (o2.in_resourceManager) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead_in_announceResourceManager& o1, const _ProjectionRead_in_announceResourceManager& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_resourceManager != (o2.in_resourceManager) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_in_announceResourceManager& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_resourceManager: " << e.in_resourceManager;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_in_announceResourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_in_announceResourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_in_announceResourceManager& obj1, const _ProjectionRead__tr_in_announceResourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__tr_in_announceResourceManager(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_resourceManager = in_resourceManager;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__tr_in_announceResourceManager& o1, const _ProjectionRead__tr_in_announceResourceManager& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_resourceManager == (o2.in_resourceManager) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__tr_in_announceResourceManager& o1, const _ProjectionRead__tr_in_announceResourceManager& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_resourceManager != (o2.in_resourceManager) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_in_announceResourceManager& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "in_resourceManager: " << e.in_resourceManager;
                    strm << ", "; 
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_in_announceResourceManager {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_in_announceResourceManager& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_in_announceResourceManager& obj1, const _ProjectionWrite_in_announceResourceManager& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;

                _ProjectionWrite_in_announceResourceManager(const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager) {
                    this->in_resourceManager = in_resourceManager;
                }

                friend bool operator ==(const _ProjectionWrite_in_announceResourceManager& o1, const _ProjectionWrite_in_announceResourceManager& o2) {
                    return o1.in_resourceManager == (o2.in_resourceManager);
                }

                friend bool operator !=(const _ProjectionWrite_in_announceResourceManager& o1, const _ProjectionWrite_in_announceResourceManager& o2) {
                    return o1.in_resourceManager != (o2.in_resourceManager);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_in_announceResourceManager& e) {
                    strm << "{";
                    strm << "in_resourceManager: " << e.in_resourceManager;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_in_register_success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_in_register_success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_in_register_success& obj1, const _ProjectionRead_in_register_success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SID, INTERCONNECTNODE > in_localServices;
                BSet<SERVICE > services;

                _ProjectionRead_in_register_success(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SID, INTERCONNECTNODE >& in_localServices, const BSet<SERVICE >& services) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_localServices = in_localServices;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead_in_register_success& o1, const _ProjectionRead_in_register_success& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_localServices == (o2.in_localServices) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead_in_register_success& o1, const _ProjectionRead_in_register_success& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_localServices != (o2.in_localServices) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_in_register_success& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_localServices: " << e.in_localServices;
                    strm << ", ";
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_localServices.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_in_register_success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_in_register_success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_in_register_success& obj1, const _ProjectionRead__tr_in_register_success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SID, INTERCONNECTNODE > in_localServices;
                BSet<SERVICE > services;

                _ProjectionRead__tr_in_register_success(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SID, INTERCONNECTNODE >& in_localServices, const BSet<SERVICE >& services) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_localServices = in_localServices;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__tr_in_register_success& o1, const _ProjectionRead__tr_in_register_success& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_localServices == (o2.in_localServices) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__tr_in_register_success& o1, const _ProjectionRead__tr_in_register_success& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_localServices != (o2.in_localServices) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_in_register_success& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", "; 
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "in_localServices: " << e.in_localServices;
                    strm << ", "; 
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_localServices.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_in_register_success {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_in_register_success& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_in_register_success& obj1, const _ProjectionWrite_in_register_success& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BRelation<SID, INTERCONNECTNODE > in_localServices;

                _ProjectionWrite_in_register_success(const BSet<SID >& sids, const BRelation<SID, INTERCONNECTNODE >& in_localServices) {
                    this->sids = sids;
                    this->in_localServices = in_localServices;
                }

                friend bool operator ==(const _ProjectionWrite_in_register_success& o1, const _ProjectionWrite_in_register_success& o2) {
                    return o1.sids == (o2.sids) && o1.in_localServices == (o2.in_localServices);
                }

                friend bool operator !=(const _ProjectionWrite_in_register_success& o1, const _ProjectionWrite_in_register_success& o2) {
                    return o1.sids != (o2.sids) || o1.in_localServices != (o2.in_localServices);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_in_register_success& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "in_localServices: " << e.in_localServices;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (in_localServices.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_in_register_failed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_in_register_failed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_in_register_failed& obj1, const _ProjectionRead_in_register_failed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;

                _ProjectionRead_in_register_failed(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead_in_register_failed& o1, const _ProjectionRead_in_register_failed& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead_in_register_failed& o1, const _ProjectionRead_in_register_failed& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_in_register_failed& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_in_register_failed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_in_register_failed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_in_register_failed& obj1, const _ProjectionRead__tr_in_register_failed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;

                _ProjectionRead__tr_in_register_failed(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__tr_in_register_failed& o1, const _ProjectionRead__tr_in_register_failed& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__tr_in_register_failed& o1, const _ProjectionRead__tr_in_register_failed& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_in_register_failed& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_in_register_failed {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_in_register_failed& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_in_register_failed& obj1, const _ProjectionWrite_in_register_failed& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_in_register_failed() {
                }

                friend bool operator ==(const _ProjectionWrite_in_register_failed& o1, const _ProjectionWrite_in_register_failed& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_in_register_failed& o1, const _ProjectionWrite_in_register_failed& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_in_register_failed& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_in_requestTargetSocket_Granted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_in_requestTargetSocket_Granted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_in_requestTargetSocket_Granted& obj1, const _ProjectionRead_in_requestTargetSocket_Granted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SID > sids;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BRelation<SOCKET, SID > soc_to;
                BRelation<SOCKET, SID > soc_from;
                BSet<SOCKET > sockets;

                _ProjectionRead_in_requestTargetSocket_Granted(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SID >& sids, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BRelation<SOCKET, SID >& soc_to, const BRelation<SOCKET, SID >& soc_from, const BSet<SOCKET >& sockets) {
                    this->interconnectNodes = interconnectNodes;
                    this->sids = sids;
                    this->in_sockets = in_sockets;
                    this->soc_to = soc_to;
                    this->soc_from = soc_from;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead_in_requestTargetSocket_Granted& o1, const _ProjectionRead_in_requestTargetSocket_Granted& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.sids == (o2.sids) && o1.in_sockets == (o2.in_sockets) && o1.soc_to == (o2.soc_to) && o1.soc_from == (o2.soc_from) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead_in_requestTargetSocket_Granted& o1, const _ProjectionRead_in_requestTargetSocket_Granted& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.sids != (o2.sids) || o1.in_sockets != (o2.in_sockets) || o1.soc_to != (o2.soc_to) || o1.soc_from != (o2.soc_from) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_in_requestTargetSocket_Granted& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "soc_to: " << e.soc_to;
                    strm << ", ";
                    strm << "soc_from: " << e.soc_from;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (soc_to.hashCode() << 1);
                    result = 31 * result + (soc_from.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_in_requestTargetSocket_Granted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_in_requestTargetSocket_Granted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_in_requestTargetSocket_Granted& obj1, const _ProjectionRead__tr_in_requestTargetSocket_Granted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BSet<SOCKET > sockets;

                _ProjectionRead__tr_in_requestTargetSocket_Granted(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_sockets = in_sockets;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__tr_in_requestTargetSocket_Granted& o1, const _ProjectionRead__tr_in_requestTargetSocket_Granted& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_sockets == (o2.in_sockets) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__tr_in_requestTargetSocket_Granted& o1, const _ProjectionRead__tr_in_requestTargetSocket_Granted& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_sockets != (o2.in_sockets) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_in_requestTargetSocket_Granted& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", "; 
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", "; 
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_in_requestTargetSocket_Granted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_in_requestTargetSocket_Granted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_in_requestTargetSocket_Granted& obj1, const _ProjectionWrite_in_requestTargetSocket_Granted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BRelation<SOCKET, SID > soc_to;
                BRelation<SOCKET, SID > soc_from;
                BSet<SOCKET > sockets;

                _ProjectionWrite_in_requestTargetSocket_Granted(const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BRelation<SOCKET, SID >& soc_to, const BRelation<SOCKET, SID >& soc_from, const BSet<SOCKET >& sockets) {
                    this->in_sockets = in_sockets;
                    this->soc_to = soc_to;
                    this->soc_from = soc_from;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionWrite_in_requestTargetSocket_Granted& o1, const _ProjectionWrite_in_requestTargetSocket_Granted& o2) {
                    return o1.in_sockets == (o2.in_sockets) && o1.soc_to == (o2.soc_to) && o1.soc_from == (o2.soc_from) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionWrite_in_requestTargetSocket_Granted& o1, const _ProjectionWrite_in_requestTargetSocket_Granted& o2) {
                    return o1.in_sockets != (o2.in_sockets) || o1.soc_to != (o2.soc_to) || o1.soc_from != (o2.soc_from) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_in_requestTargetSocket_Granted& e) {
                    strm << "{";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "soc_to: " << e.soc_to;
                    strm << ", ";
                    strm << "soc_from: " << e.soc_from;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (soc_to.hashCode() << 1);
                    result = 31 * result + (soc_from.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead_in_requestTargetSocket_NotGranted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_in_requestTargetSocket_NotGranted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_in_requestTargetSocket_NotGranted& obj1, const _ProjectionRead_in_requestTargetSocket_NotGranted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BSet<SOCKET > sockets;

                _ProjectionRead_in_requestTargetSocket_NotGranted(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_sockets = in_sockets;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead_in_requestTargetSocket_NotGranted& o1, const _ProjectionRead_in_requestTargetSocket_NotGranted& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_sockets == (o2.in_sockets) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead_in_requestTargetSocket_NotGranted& o1, const _ProjectionRead_in_requestTargetSocket_NotGranted& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_sockets != (o2.in_sockets) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_in_requestTargetSocket_NotGranted& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_in_requestTargetSocket_NotGranted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& obj1, const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BSet<SOCKET > sockets;

                _ProjectionRead__tr_in_requestTargetSocket_NotGranted(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_sockets = in_sockets;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& o1, const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_sockets == (o2.in_sockets) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& o1, const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_sockets != (o2.in_sockets) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_in_requestTargetSocket_NotGranted& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", "; 
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", "; 
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", "; 
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_in_requestTargetSocket_NotGranted {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_in_requestTargetSocket_NotGranted& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_in_requestTargetSocket_NotGranted& obj1, const _ProjectionWrite_in_requestTargetSocket_NotGranted& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };


                _ProjectionWrite_in_requestTargetSocket_NotGranted() {
                }

                friend bool operator ==(const _ProjectionWrite_in_requestTargetSocket_NotGranted& o1, const _ProjectionWrite_in_requestTargetSocket_NotGranted& o2) {
                    return true;
                }

                friend bool operator !=(const _ProjectionWrite_in_requestTargetSocket_NotGranted& o1, const _ProjectionWrite_in_requestTargetSocket_NotGranted& o2) {
                    return true;
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_in_requestTargetSocket_NotGranted& e) {
                    strm << "{";
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    return result;
                }

        };

        class _ProjectionRead_svc_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead_svc_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead_svc_register& obj1, const _ProjectionRead_svc_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BBoolean > svc_registered;
                BSet<SERVICE > services;

                _ProjectionRead_svc_register(const BRelation<SERVICE, BBoolean >& svc_registered, const BSet<SERVICE >& services) {
                    this->svc_registered = svc_registered;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead_svc_register& o1, const _ProjectionRead_svc_register& o2) {
                    return o1.svc_registered == (o2.svc_registered) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead_svc_register& o1, const _ProjectionRead_svc_register& o2) {
                    return o1.svc_registered != (o2.svc_registered) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead_svc_register& e) {
                    strm << "{";
                    strm << "svc_registered: " << e.svc_registered;
                    strm << ", ";
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_registered.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__tr_svc_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__tr_svc_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__tr_svc_register& obj1, const _ProjectionRead__tr_svc_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BBoolean > svc_registered;
                BSet<SERVICE > services;

                _ProjectionRead__tr_svc_register(const BRelation<SERVICE, BBoolean >& svc_registered, const BSet<SERVICE >& services) {
                    this->svc_registered = svc_registered;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__tr_svc_register& o1, const _ProjectionRead__tr_svc_register& o2) {
                    return o1.svc_registered == (o2.svc_registered) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__tr_svc_register& o1, const _ProjectionRead__tr_svc_register& o2) {
                    return o1.svc_registered != (o2.svc_registered) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__tr_svc_register& e) {
                    strm << "{";
                    strm << "svc_registered: " << e.svc_registered;
                    strm << ", "; 
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_registered.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }
        };

        class _ProjectionWrite_svc_register {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionWrite_svc_register& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionWrite_svc_register& obj1, const _ProjectionWrite_svc_register& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BBoolean > svc_registered;

                _ProjectionWrite_svc_register(const BRelation<SERVICE, BBoolean >& svc_registered) {
                    this->svc_registered = svc_registered;
                }

                friend bool operator ==(const _ProjectionWrite_svc_register& o1, const _ProjectionWrite_svc_register& o2) {
                    return o1.svc_registered == (o2.svc_registered);
                }

                friend bool operator !=(const _ProjectionWrite_svc_register& o1, const _ProjectionWrite_svc_register& o2) {
                    return o1.svc_registered != (o2.svc_registered);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionWrite_svc_register& e) {
                    strm << "{";
                    strm << "svc_registered: " << e.svc_registered;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_registered.hashCode() << 1);
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

                BSet<INTERCONNECTNODE > interconnectNodes;

                _ProjectionRead__check_inv_1(const BSet<INTERCONNECTNODE >& interconnectNodes) {
                    this->interconnectNodes = interconnectNodes;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_1& o1, const _ProjectionRead__check_inv_1& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_1& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
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

                BSet<SOCKET > sockets;

                _ProjectionRead__check_inv_2(const BSet<SOCKET >& sockets) {
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_2& o1, const _ProjectionRead__check_inv_2& o2) {
                    return o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_2& e) {
                    strm << "{";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sockets.hashCode() << 1);
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

                BSet<SERVICE > services;

                _ProjectionRead__check_inv_3(const BSet<SERVICE >& services) {
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_3& o1, const _ProjectionRead__check_inv_3& o2) {
                    return o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_3& e) {
                    strm << "{";
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (services.hashCode() << 1);
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

                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__check_inv_4(const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_4& o1, const _ProjectionRead__check_inv_4& o2) {
                    return o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_4& e) {
                    strm << "{";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resourceManagers.hashCode() << 1);
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

                BSet<SID > sids;

                _ProjectionRead__check_inv_5(const BSet<SID >& sids) {
                    this->sids = sids;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.sids == (o2.sids);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_5& o1, const _ProjectionRead__check_inv_5& o2) {
                    return o1.sids != (o2.sids);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_5& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
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

                BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;
                BSet<SERVICE > services;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__check_inv_6(const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services, const BSet<SERVICE >& services, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->rm_services = rm_services;
                    this->services = services;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.rm_services == (o2.rm_services) && o1.services == (o2.services) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_6& o1, const _ProjectionRead__check_inv_6& o2) {
                    return o1.rm_services != (o2.rm_services) || o1.services != (o2.services) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_6& e) {
                    strm << "{";
                    strm << "rm_services: " << e.rm_services;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rm_services.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
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

                BRelation<RESOURCEMANAGER, BSet<SERVICE > > rm_services;

                _ProjectionRead__check_inv_7(const BRelation<RESOURCEMANAGER, BSet<SERVICE > >& rm_services) {
                    this->rm_services = rm_services;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.rm_services == (o2.rm_services);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_7& o1, const _ProjectionRead__check_inv_7& o2) {
                    return o1.rm_services != (o2.rm_services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_7& e) {
                    strm << "{";
                    strm << "rm_services: " << e.rm_services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (rm_services.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_8 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_8& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_8& obj1, const _ProjectionRead__check_inv_8& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<SERVICE > services;
                BRelation<SERVICE, SID > rm_sids;

                _ProjectionRead__check_inv_8(const BSet<SID >& sids, const BSet<SERVICE >& services, const BRelation<SERVICE, SID >& rm_sids) {
                    this->sids = sids;
                    this->services = services;
                    this->rm_sids = rm_sids;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.sids == (o2.sids) && o1.services == (o2.services) && o1.rm_sids == (o2.rm_sids);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_8& o1, const _ProjectionRead__check_inv_8& o2) {
                    return o1.sids != (o2.sids) || o1.services != (o2.services) || o1.rm_sids != (o2.rm_sids);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_8& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "rm_sids: " << e.rm_sids;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (rm_sids.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_9 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_9& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_9& obj1, const _ProjectionRead__check_inv_9& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SID, INTERCONNECTNODE > in_localServices;

                _ProjectionRead__check_inv_9(const BSet<SID >& sids, const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SID, INTERCONNECTNODE >& in_localServices) {
                    this->sids = sids;
                    this->interconnectNodes = interconnectNodes;
                    this->in_localServices = in_localServices;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.sids == (o2.sids) && o1.interconnectNodes == (o2.interconnectNodes) && o1.in_localServices == (o2.in_localServices);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_9& o1, const _ProjectionRead__check_inv_9& o2) {
                    return o1.sids != (o2.sids) || o1.interconnectNodes != (o2.interconnectNodes) || o1.in_localServices != (o2.in_localServices);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_9& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_localServices: " << e.in_localServices;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_localServices.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_10 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_10& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_10& obj1, const _ProjectionRead__check_inv_10& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<SOCKET, INTERCONNECTNODE > in_sockets;
                BSet<SOCKET > sockets;

                _ProjectionRead__check_inv_10(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<SOCKET, INTERCONNECTNODE >& in_sockets, const BSet<SOCKET >& sockets) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_sockets = in_sockets;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_sockets == (o2.in_sockets) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_10& o1, const _ProjectionRead__check_inv_10& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_sockets != (o2.in_sockets) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_10& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_sockets: " << e.in_sockets;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_sockets.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_11 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_11& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_11& obj1, const _ProjectionRead__check_inv_11& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > > in_resourceManager;
                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__check_inv_11(const BSet<INTERCONNECTNODE >& interconnectNodes, const BRelation<INTERCONNECTNODE, BSet<RESOURCEMANAGER > >& in_resourceManager, const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->interconnectNodes = interconnectNodes;
                    this->in_resourceManager = in_resourceManager;
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.in_resourceManager == (o2.in_resourceManager) && o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_11& o1, const _ProjectionRead__check_inv_11& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.in_resourceManager != (o2.in_resourceManager) || o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_11& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "in_resourceManager: " << e.in_resourceManager;
                    strm << ", ";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (in_resourceManager.hashCode() << 1);
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_12 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_12& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_12& obj1, const _ProjectionRead__check_inv_12& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BRelation<SOCKET, SID > soc_to;
                BSet<SOCKET > sockets;

                _ProjectionRead__check_inv_12(const BSet<SID >& sids, const BRelation<SOCKET, SID >& soc_to, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->soc_to = soc_to;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.sids == (o2.sids) && o1.soc_to == (o2.soc_to) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_12& o1, const _ProjectionRead__check_inv_12& o2) {
                    return o1.sids != (o2.sids) || o1.soc_to != (o2.soc_to) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_12& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "soc_to: " << e.soc_to;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (soc_to.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_13 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_13& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_13& obj1, const _ProjectionRead__check_inv_13& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BRelation<SOCKET, SID > soc_from;
                BSet<SOCKET > sockets;

                _ProjectionRead__check_inv_13(const BSet<SID >& sids, const BRelation<SOCKET, SID >& soc_from, const BSet<SOCKET >& sockets) {
                    this->sids = sids;
                    this->soc_from = soc_from;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.sids == (o2.sids) && o1.soc_from == (o2.soc_from) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_13& o1, const _ProjectionRead__check_inv_13& o2) {
                    return o1.sids != (o2.sids) || o1.soc_from != (o2.soc_from) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_13& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "soc_from: " << e.soc_from;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (soc_from.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_14 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_14& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_14& obj1, const _ProjectionRead__check_inv_14& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<SID > sids;
                BSet<SERVICE > services;
                BRelation<SERVICE, SID > svc_serviceID;

                _ProjectionRead__check_inv_14(const BSet<SID >& sids, const BSet<SERVICE >& services, const BRelation<SERVICE, SID >& svc_serviceID) {
                    this->sids = sids;
                    this->services = services;
                    this->svc_serviceID = svc_serviceID;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.sids == (o2.sids) && o1.services == (o2.services) && o1.svc_serviceID == (o2.svc_serviceID);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_14& o1, const _ProjectionRead__check_inv_14& o2) {
                    return o1.sids != (o2.sids) || o1.services != (o2.services) || o1.svc_serviceID != (o2.svc_serviceID);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_14& e) {
                    strm << "{";
                    strm << "sids: " << e.sids;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "svc_serviceID: " << e.svc_serviceID;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (sids.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (svc_serviceID.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_15 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_15& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_15& obj1, const _ProjectionRead__check_inv_15& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BSet<SOCKET > > svc_sockets;
                BSet<SERVICE > services;
                BSet<SOCKET > sockets;

                _ProjectionRead__check_inv_15(const BRelation<SERVICE, BSet<SOCKET > >& svc_sockets, const BSet<SERVICE >& services, const BSet<SOCKET >& sockets) {
                    this->svc_sockets = svc_sockets;
                    this->services = services;
                    this->sockets = sockets;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.svc_sockets == (o2.svc_sockets) && o1.services == (o2.services) && o1.sockets == (o2.sockets);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_15& o1, const _ProjectionRead__check_inv_15& o2) {
                    return o1.svc_sockets != (o2.svc_sockets) || o1.services != (o2.services) || o1.sockets != (o2.sockets);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_15& e) {
                    strm << "{";
                    strm << "svc_sockets: " << e.svc_sockets;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "sockets: " << e.sockets;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_sockets.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (sockets.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_16 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_16& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_16& obj1, const _ProjectionRead__check_inv_16& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<INTERCONNECTNODE > interconnectNodes;
                BSet<SERVICE > services;
                BRelation<SERVICE, INTERCONNECTNODE > svc_ICNode;

                _ProjectionRead__check_inv_16(const BSet<INTERCONNECTNODE >& interconnectNodes, const BSet<SERVICE >& services, const BRelation<SERVICE, INTERCONNECTNODE >& svc_ICNode) {
                    this->interconnectNodes = interconnectNodes;
                    this->services = services;
                    this->svc_ICNode = svc_ICNode;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.interconnectNodes == (o2.interconnectNodes) && o1.services == (o2.services) && o1.svc_ICNode == (o2.svc_ICNode);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_16& o1, const _ProjectionRead__check_inv_16& o2) {
                    return o1.interconnectNodes != (o2.interconnectNodes) || o1.services != (o2.services) || o1.svc_ICNode != (o2.svc_ICNode);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_16& e) {
                    strm << "{";
                    strm << "interconnectNodes: " << e.interconnectNodes;
                    strm << ", ";
                    strm << "services: " << e.services;
                    strm << ", ";
                    strm << "svc_ICNode: " << e.svc_ICNode;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (interconnectNodes.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    result = 31 * result + (svc_ICNode.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_17 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_17& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_17& obj1, const _ProjectionRead__check_inv_17& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BRelation<SERVICE, BBoolean > svc_registered;
                BSet<SERVICE > services;

                _ProjectionRead__check_inv_17(const BRelation<SERVICE, BBoolean >& svc_registered, const BSet<SERVICE >& services) {
                    this->svc_registered = svc_registered;
                    this->services = services;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.svc_registered == (o2.svc_registered) && o1.services == (o2.services);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_17& o1, const _ProjectionRead__check_inv_17& o2) {
                    return o1.svc_registered != (o2.svc_registered) || o1.services != (o2.services);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_17& e) {
                    strm << "{";
                    strm << "svc_registered: " << e.svc_registered;
                    strm << ", ";
                    strm << "services: " << e.services;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (svc_registered.hashCode() << 1);
                    result = 31 * result + (services.hashCode() << 1);
                    return result;
                }

        };

        class _ProjectionRead__check_inv_18 {

            public:
                struct Hash {
                    public:
                        size_t operator()(const _ProjectionRead__check_inv_18& obj) const {
                            return obj.hashCode();
                        }
                };

                struct HashEqual {
                    public:
                        bool operator()(const _ProjectionRead__check_inv_18& obj1, const _ProjectionRead__check_inv_18& obj2) const {
                            if (obj1 == obj2)
                                return true;
                            else
                                return false;
                            }
                    };

                BSet<RESOURCEMANAGER > resourceManagers;

                _ProjectionRead__check_inv_18(const BSet<RESOURCEMANAGER >& resourceManagers) {
                    this->resourceManagers = resourceManagers;
                }

                friend bool operator ==(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.resourceManagers == (o2.resourceManagers);
                }

                friend bool operator !=(const _ProjectionRead__check_inv_18& o1, const _ProjectionRead__check_inv_18& o2) {
                    return o1.resourceManagers != (o2.resourceManagers);
                }

                friend std::ostream& operator<<(std::ostream &strm, const _ProjectionRead__check_inv_18& e) {
                    strm << "{";
                    strm << "resourceManagers: " << e.resourceManagers;;
                    strm << "}";
                    return strm;
                }

                int hashCode() const {
                    int result = 1;
                    result = 31 * result + (resourceManagers.hashCode() << 1);
                    return result;
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

        std::string stateAccessedVia;

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
            for(const INTERCONNECTNODE& _ic_newic_1 : _INTERCONNECTNODE.difference(interconnectNodes)) {
                _ic_set_0 = _ic_set_0._union(BSet<INTERCONNECTNODE>(_ic_newic_1));

            }
            return _ic_set_0;
        }

        BSet<RESOURCEMANAGER> _tr_constructor_resourceManager() const {
            BSet<RESOURCEMANAGER> _ic_set_1 = BSet<RESOURCEMANAGER>();
            for(const RESOURCEMANAGER& _ic_newrm_1 : _RESOURCEMANAGER.difference(resourceManagers)) {
                if(((BBoolean(rm_services.domain().notElementOf(_ic_newrm_1).booleanValue() && resourceManagers.equal((BSet<RESOURCEMANAGER >())).booleanValue()))).booleanValue()) {
                    _ic_set_1 = _ic_set_1._union(BSet<RESOURCEMANAGER>(_ic_newrm_1));
                }

            }
            return _ic_set_1;
        }

        BSet<BTuple<INTERCONNECTNODE, SERVICE >> _tr_constructor_service() const {
            BSet<BTuple<INTERCONNECTNODE, SERVICE >> _ic_set_2 = BSet<BTuple<INTERCONNECTNODE, SERVICE >>();
            for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                for(const SERVICE& _ic_newsvc_1 : _SERVICE.difference(services)) {
                    _ic_set_2 = _ic_set_2._union(BSet<BTuple<INTERCONNECTNODE, SERVICE >>((BTuple<INTERCONNECTNODE, SERVICE >(_ic_ii_1, _ic_newsvc_1))));

                }
            }
            return _ic_set_2;
        }

        BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >> _tr_constructor_socket() const {
            BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >> _ic_set_3 = BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >>();
            for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                for(const SID& _ic_srcsid_1 : sids) {
                    for(const SID& _ic_targsid_1 : sids) {
                        for(const SOCKET& _ic_newsoc_1 : _SOCKET.difference(sockets)) {
                            _ic_set_3 = _ic_set_3._union(BSet<BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >>((BTuple<BTuple<BTuple<INTERCONNECTNODE, SID >, SID >, SOCKET >((BTuple<BTuple<INTERCONNECTNODE, SID >, SID >((BTuple<INTERCONNECTNODE, SID >(_ic_ii_1, _ic_srcsid_1)), _ic_targsid_1)), _ic_newsoc_1))));

                        }
                    }
                }
            }
            return _ic_set_3;
        }

        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _tr_rm_register() const {
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _ic_set_4 = BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>();
            for(const RESOURCEMANAGER& _ic_self_1 : resourceManagers) {
                for(const SERVICE& _ic_ss_1 : services) {
                    for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                        _ic_set_4 = _ic_set_4._union(BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>((BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1)), _ic_ii_1))));

                    }
                }
            }
            return _ic_set_4;
        }

        BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _tr_rm_deregister() const {
            BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >> _ic_set_5 = BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>();
            for(const RESOURCEMANAGER& _ic_self_1 : resourceManagers) {
                for(const SERVICE& _ic_ss_1 : services) {
                    for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                        _ic_set_5 = _ic_set_5._union(BSet<BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >>((BTuple<BTuple<RESOURCEMANAGER, SERVICE >, INTERCONNECTNODE >((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1)), _ic_ii_1))));

                    }
                }
            }
            return _ic_set_5;
        }

        BSet<BTuple<RESOURCEMANAGER, SERVICE >> _tr_rm_getSid() const {
            BSet<BTuple<RESOURCEMANAGER, SERVICE >> _ic_set_6 = BSet<BTuple<RESOURCEMANAGER, SERVICE >>();
            for(const RESOURCEMANAGER& _ic_self_1 : resourceManagers) {
                for(const SERVICE& _ic_ss_1 : services) {
                    if((rm_sids.domain().elementOf(_ic_ss_1)).booleanValue()) {
                        _ic_set_6 = _ic_set_6._union(BSet<BTuple<RESOURCEMANAGER, SERVICE >>((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1))));
                    }

                }
            }
            return _ic_set_6;
        }

        BSet<BTuple<RESOURCEMANAGER, SERVICE >> _tr_rm_getSid_Not_Found() const {
            BSet<BTuple<RESOURCEMANAGER, SERVICE >> _ic_set_7 = BSet<BTuple<RESOURCEMANAGER, SERVICE >>();
            for(const RESOURCEMANAGER& _ic_self_1 : resourceManagers) {
                for(const SERVICE& _ic_ss_1 : services) {
                    _ic_set_7 = _ic_set_7._union(BSet<BTuple<RESOURCEMANAGER, SERVICE >>((BTuple<RESOURCEMANAGER, SERVICE >(_ic_self_1, _ic_ss_1))));

                }
            }
            return _ic_set_7;
        }

        BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >> _tr_in_announceResourceManager() const {
            BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >> _ic_set_8 = BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >>();
            for(const INTERCONNECTNODE& _ic_self_1 : interconnectNodes) {
                for(const RESOURCEMANAGER& _ic_rm_1 : resourceManagers) {
                    if((in_resourceManager.functionCall(_ic_self_1).equal((BSet<RESOURCEMANAGER >()))).booleanValue()) {
                        _ic_set_8 = _ic_set_8._union(BSet<BTuple<INTERCONNECTNODE, RESOURCEMANAGER >>((BTuple<INTERCONNECTNODE, RESOURCEMANAGER >(_ic_self_1, _ic_rm_1))));
                    }

                }
            }
            return _ic_set_8;
        }

        BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >> _tr_in_register_success() const {
            BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >> _ic_set_9 = BSet<BTuple<BTuple<INTERCONNECTNODE, SERVICE >, SID >>();
            for(const INTERCONNECTNODE& _ic_self_1 : interconnectNodes) {
                for(const SERVICE& _ic_ss_1 : services) {
                    for(const SID& _ic_si_1 : _SID.difference(sids)) {
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
            for(const INTERCONNECTNODE& _ic_self_1 : interconnectNodes) {
                for(const SERVICE& _ic_ss_1 : services) {
                    _ic_set_10 = _ic_set_10._union(BSet<BTuple<INTERCONNECTNODE, SERVICE >>((BTuple<INTERCONNECTNODE, SERVICE >(_ic_self_1, _ic_ss_1))));

                }
            }
            return _ic_set_10;
        }

        BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >> _tr_in_requestTargetSocket_Granted() const {
            BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >> _ic_set_11 = BSet<BTuple<BTuple<BTuple<BTuple<BTuple<INTERCONNECTNODE, INTERCONNECTNODE >, SOCKET >, SID >, SID >, SOCKET >>();
            for(const INTERCONNECTNODE& _ic_self_1 : interconnectNodes) {
                for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                    for(const SOCKET& _ic_srcsoc_1 : sockets) {
                        for(const SID& _ic_srcsid_1 : sids) {
                            for(const SID& _ic_targsid_1 : sids) {
                                for(const SOCKET& _ic_newsoc_1 : _SOCKET.difference(sockets)) {
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
            for(const INTERCONNECTNODE& _ic_self_1 : interconnectNodes) {
                for(const INTERCONNECTNODE& _ic_ii_1 : interconnectNodes) {
                    for(const SOCKET& _ic_srcsoc_1 : sockets) {
                        for(const SID& _ic_srcsid_1 : sids) {
                            for(const SID& _ic_targsid_1 : sids) {
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
            for(const SERVICE& _ic_self_1 : services) {
                if((svc_registered.functionCall(_ic_self_1).equal((BBoolean(false)))).booleanValue()) {
                    _ic_set_13 = _ic_set_13._union(BSet<SERVICE>(_ic_self_1));
                }

            }
            return _ic_set_13;
        }

        _ProjectionRead_in_register_success _projected_state_for_in_register_success() const {
            return _ProjectionRead_in_register_success(sids,interconnectNodes,in_localServices,services);
        }

        _ProjectionRead_in_announceResourceManager _projected_state_for_in_announceResourceManager() const {
            return _ProjectionRead_in_announceResourceManager(interconnectNodes,in_resourceManager,resourceManagers);
        }

        _ProjectionRead_in_requestTargetSocket_Granted _projected_state_for_in_requestTargetSocket_Granted() const {
            return _ProjectionRead_in_requestTargetSocket_Granted(interconnectNodes,sids,in_sockets,soc_to,soc_from,sockets);
        }

        _ProjectionRead_constructor_service _projected_state_for_constructor_service() const {
            return _ProjectionRead_constructor_service(interconnectNodes,svc_registered,svc_sockets,services,svc_ICNode);
        }

        _ProjectionRead_constructor_socket _projected_state_for_constructor_socket() const {
            return _ProjectionRead_constructor_socket(sids,interconnectNodes,in_sockets,soc_to,soc_from,sockets);
        }

        _ProjectionRead_in_requestTargetSocket_NotGranted _projected_state_for_in_requestTargetSocket_NotGranted() const {
            return _ProjectionRead_in_requestTargetSocket_NotGranted(sids,interconnectNodes,in_sockets,sockets);
        }

        _ProjectionRead_constructor_interconnectNode _projected_state_for_constructor_interconnectNode() const {
            return _ProjectionRead_constructor_interconnectNode(interconnectNodes,in_resourceManager);
        }

        _ProjectionRead_rm_getSid _projected_state_for_rm_getSid() const {
            return _ProjectionRead_rm_getSid(services,resourceManagers,rm_sids);
        }

        _ProjectionRead_rm_deregister _projected_state_for_rm_deregister() const {
            return _ProjectionRead_rm_deregister(interconnectNodes,services,resourceManagers);
        }

        _ProjectionRead_constructor_resourceManager _projected_state_for_constructor_resourceManager() const {
            return _ProjectionRead_constructor_resourceManager(rm_services,resourceManagers);
        }

        _ProjectionRead_in_register_failed _projected_state_for_in_register_failed() const {
            return _ProjectionRead_in_register_failed(interconnectNodes,services);
        }

        _ProjectionRead_rm_register _projected_state_for_rm_register() const {
            return _ProjectionRead_rm_register(interconnectNodes,services,resourceManagers);
        }

        _ProjectionRead_rm_getSid_Not_Found _projected_state_for_rm_getSid_Not_Found() const {
            return _ProjectionRead_rm_getSid_Not_Found(services,resourceManagers);
        }

        _ProjectionRead_svc_register _projected_state_for_svc_register() const {
            return _ProjectionRead_svc_register(svc_registered,services);
        }

        _ProjectionRead__tr_constructor_resourceManager _projected_state_for__tr_constructor_resourceManager() const {
            return _ProjectionRead__tr_constructor_resourceManager(rm_services,resourceManagers);
        }

        _ProjectionRead__tr_in_register_failed _projected_state_for__tr_in_register_failed() const {
            return _ProjectionRead__tr_in_register_failed(interconnectNodes,services);
        }

        _ProjectionRead__tr_rm_register _projected_state_for__tr_rm_register() const {
            return _ProjectionRead__tr_rm_register(interconnectNodes,services,resourceManagers);
        }

        _ProjectionRead__tr_rm_getSid_Not_Found _projected_state_for__tr_rm_getSid_Not_Found() const {
            return _ProjectionRead__tr_rm_getSid_Not_Found(services,resourceManagers);
        }

        _ProjectionRead__tr_in_requestTargetSocket_NotGranted _projected_state_for__tr_in_requestTargetSocket_NotGranted() const {
            return _ProjectionRead__tr_in_requestTargetSocket_NotGranted(sids,interconnectNodes,in_sockets,sockets);
        }

        _ProjectionRead__tr_constructor_socket _projected_state_for__tr_constructor_socket() const {
            return _ProjectionRead__tr_constructor_socket(sids,interconnectNodes,sockets);
        }

        _ProjectionRead__tr_rm_deregister _projected_state_for__tr_rm_deregister() const {
            return _ProjectionRead__tr_rm_deregister(interconnectNodes,services,resourceManagers);
        }

        _ProjectionRead__tr_in_announceResourceManager _projected_state_for__tr_in_announceResourceManager() const {
            return _ProjectionRead__tr_in_announceResourceManager(interconnectNodes,in_resourceManager,resourceManagers);
        }

        _ProjectionRead__tr_constructor_service _projected_state_for__tr_constructor_service() const {
            return _ProjectionRead__tr_constructor_service(interconnectNodes,services);
        }

        _ProjectionRead__tr_rm_getSid _projected_state_for__tr_rm_getSid() const {
            return _ProjectionRead__tr_rm_getSid(services,resourceManagers,rm_sids);
        }

        _ProjectionRead__tr_in_register_success _projected_state_for__tr_in_register_success() const {
            return _ProjectionRead__tr_in_register_success(sids,interconnectNodes,in_localServices,services);
        }

        _ProjectionRead__tr_svc_register _projected_state_for__tr_svc_register() const {
            return _ProjectionRead__tr_svc_register(svc_registered,services);
        }

        _ProjectionRead__tr_in_requestTargetSocket_Granted _projected_state_for__tr_in_requestTargetSocket_Granted() const {
            return _ProjectionRead__tr_in_requestTargetSocket_Granted(sids,interconnectNodes,in_sockets,sockets);
        }

        _ProjectionRead__tr_constructor_interconnectNode _projected_state_for__tr_constructor_interconnectNode() const {
            return _ProjectionRead__tr_constructor_interconnectNode(interconnectNodes);
        }

        _ProjectionRead__check_inv_18 _projected_state_for__check_inv_18() const {
            return _ProjectionRead__check_inv_18(resourceManagers);
        }

        _ProjectionRead__check_inv_17 _projected_state_for__check_inv_17() const {
            return _ProjectionRead__check_inv_17(svc_registered,services);
        }

        _ProjectionRead__check_inv_16 _projected_state_for__check_inv_16() const {
            return _ProjectionRead__check_inv_16(interconnectNodes,services,svc_ICNode);
        }

        _ProjectionRead__check_inv_15 _projected_state_for__check_inv_15() const {
            return _ProjectionRead__check_inv_15(svc_sockets,services,sockets);
        }

        _ProjectionRead__check_inv_6 _projected_state_for__check_inv_6() const {
            return _ProjectionRead__check_inv_6(rm_services,services,resourceManagers);
        }

        _ProjectionRead__check_inv_10 _projected_state_for__check_inv_10() const {
            return _ProjectionRead__check_inv_10(interconnectNodes,in_sockets,sockets);
        }

        _ProjectionRead__check_inv_7 _projected_state_for__check_inv_7() const {
            return _ProjectionRead__check_inv_7(rm_services);
        }

        _ProjectionRead__check_inv_4 _projected_state_for__check_inv_4() const {
            return _ProjectionRead__check_inv_4(resourceManagers);
        }

        _ProjectionRead__check_inv_5 _projected_state_for__check_inv_5() const {
            return _ProjectionRead__check_inv_5(sids);
        }

        _ProjectionRead__check_inv_14 _projected_state_for__check_inv_14() const {
            return _ProjectionRead__check_inv_14(sids,services,svc_serviceID);
        }

        _ProjectionRead__check_inv_13 _projected_state_for__check_inv_13() const {
            return _ProjectionRead__check_inv_13(sids,soc_from,sockets);
        }

        _ProjectionRead__check_inv_8 _projected_state_for__check_inv_8() const {
            return _ProjectionRead__check_inv_8(sids,services,rm_sids);
        }

        _ProjectionRead__check_inv_12 _projected_state_for__check_inv_12() const {
            return _ProjectionRead__check_inv_12(sids,soc_to,sockets);
        }

        _ProjectionRead__check_inv_9 _projected_state_for__check_inv_9() const {
            return _ProjectionRead__check_inv_9(sids,interconnectNodes,in_localServices);
        }

        _ProjectionRead__check_inv_11 _projected_state_for__check_inv_11() const {
            return _ProjectionRead__check_inv_11(interconnectNodes,in_resourceManager,resourceManagers);
        }

        _ProjectionRead__check_inv_2 _projected_state_for__check_inv_2() const {
            return _ProjectionRead__check_inv_2(sockets);
        }

        _ProjectionRead__check_inv_3 _projected_state_for__check_inv_3() const {
            return _ProjectionRead__check_inv_3(services);
        }

        _ProjectionRead__check_inv_1 _projected_state_for__check_inv_1() const {
            return _ProjectionRead__check_inv_1(interconnectNodes);
        }

        _ProjectionWrite_in_register_success _update_for_in_register_success() const {
            return _ProjectionWrite_in_register_success(sids,in_localServices);
        }

        _ProjectionWrite_in_announceResourceManager _update_for_in_announceResourceManager() const {
            return _ProjectionWrite_in_announceResourceManager(in_resourceManager);
        }

        _ProjectionWrite_in_requestTargetSocket_Granted _update_for_in_requestTargetSocket_Granted() const {
            return _ProjectionWrite_in_requestTargetSocket_Granted(in_sockets,soc_to,soc_from,sockets);
        }

        _ProjectionWrite_constructor_service _update_for_constructor_service() const {
            return _ProjectionWrite_constructor_service(svc_registered,svc_sockets,services,svc_serviceID,svc_ICNode);
        }

        _ProjectionWrite_constructor_socket _update_for_constructor_socket() const {
            return _ProjectionWrite_constructor_socket(in_sockets,soc_to,soc_from,sockets);
        }

        _ProjectionWrite_in_requestTargetSocket_NotGranted _update_for_in_requestTargetSocket_NotGranted() const {
            return _ProjectionWrite_in_requestTargetSocket_NotGranted();
        }

        _ProjectionWrite_constructor_interconnectNode _update_for_constructor_interconnectNode() const {
            return _ProjectionWrite_constructor_interconnectNode(interconnectNodes,in_resourceManager);
        }

        _ProjectionWrite_rm_getSid _update_for_rm_getSid() const {
            return _ProjectionWrite_rm_getSid();
        }

        _ProjectionWrite_rm_deregister _update_for_rm_deregister() const {
            return _ProjectionWrite_rm_deregister();
        }

        _ProjectionWrite_constructor_resourceManager _update_for_constructor_resourceManager() const {
            return _ProjectionWrite_constructor_resourceManager(rm_services,resourceManagers);
        }

        _ProjectionWrite_in_register_failed _update_for_in_register_failed() const {
            return _ProjectionWrite_in_register_failed();
        }

        _ProjectionWrite_rm_register _update_for_rm_register() const {
            return _ProjectionWrite_rm_register();
        }

        _ProjectionWrite_rm_getSid_Not_Found _update_for_rm_getSid_Not_Found() const {
            return _ProjectionWrite_rm_getSid_Not_Found();
        }

        _ProjectionWrite_svc_register _update_for_svc_register() const {
            return _ProjectionWrite_svc_register(svc_registered);
        }

        void _apply_update_for_in_register_success(const _ProjectionWrite_in_register_success& update) {
            this->sids = update.sids;
            this->in_localServices = update.in_localServices;
        }

        void _apply_update_for_in_announceResourceManager(const _ProjectionWrite_in_announceResourceManager& update) {
            this->in_resourceManager = update.in_resourceManager;
        }

        void _apply_update_for_in_requestTargetSocket_Granted(const _ProjectionWrite_in_requestTargetSocket_Granted& update) {
            this->in_sockets = update.in_sockets;
            this->soc_to = update.soc_to;
            this->soc_from = update.soc_from;
            this->sockets = update.sockets;
        }

        void _apply_update_for_constructor_service(const _ProjectionWrite_constructor_service& update) {
            this->svc_registered = update.svc_registered;
            this->svc_sockets = update.svc_sockets;
            this->services = update.services;
            this->svc_serviceID = update.svc_serviceID;
            this->svc_ICNode = update.svc_ICNode;
        }

        void _apply_update_for_constructor_socket(const _ProjectionWrite_constructor_socket& update) {
            this->in_sockets = update.in_sockets;
            this->soc_to = update.soc_to;
            this->soc_from = update.soc_from;
            this->sockets = update.sockets;
        }

        void _apply_update_for_in_requestTargetSocket_NotGranted(const _ProjectionWrite_in_requestTargetSocket_NotGranted& update) {
        }

        void _apply_update_for_constructor_interconnectNode(const _ProjectionWrite_constructor_interconnectNode& update) {
            this->interconnectNodes = update.interconnectNodes;
            this->in_resourceManager = update.in_resourceManager;
        }

        void _apply_update_for_rm_getSid(const _ProjectionWrite_rm_getSid& update) {
        }

        void _apply_update_for_rm_deregister(const _ProjectionWrite_rm_deregister& update) {
        }

        void _apply_update_for_constructor_resourceManager(const _ProjectionWrite_constructor_resourceManager& update) {
            this->rm_services = update.rm_services;
            this->resourceManagers = update.resourceManagers;
        }

        void _apply_update_for_in_register_failed(const _ProjectionWrite_in_register_failed& update) {
        }

        void _apply_update_for_rm_register(const _ProjectionWrite_rm_register& update) {
        }

        void _apply_update_for_rm_getSid_Not_Found(const _ProjectionWrite_rm_getSid_Not_Found& update) {
        }

        void _apply_update_for_svc_register(const _ProjectionWrite_svc_register& update) {
            this->svc_registered = update.svc_registered;
        }

        bool _check_inv_1() const {
            BBoolean _ic_boolean_14 = BBoolean(true);
            for(const INTERCONNECTNODE& _ic__opt_1_1 : interconnectNodes) {
                if(!((BBoolean(!interconnectNodes.elementOf(_ic__opt_1_1).booleanValue() || _INTERCONNECTNODE.elementOf(_ic__opt_1_1).booleanValue()))).booleanValue()) {
                    _ic_boolean_14 = BBoolean(false);
                    break;
                }

            }
            return (_ic_boolean_14).booleanValue();
        }

        bool _check_inv_2() const {
            BBoolean _ic_boolean_15 = BBoolean(true);
            for(const SOCKET& _ic__opt_2_1 : sockets) {
                if(!((BBoolean(!sockets.elementOf(_ic__opt_2_1).booleanValue() || _SOCKET.elementOf(_ic__opt_2_1).booleanValue()))).booleanValue()) {
                    _ic_boolean_15 = BBoolean(false);
                    break;
                }

            }
            return (_ic_boolean_15).booleanValue();
        }

        bool _check_inv_3() const {
            BBoolean _ic_boolean_16 = BBoolean(true);
            for(const SERVICE& _ic__opt_3_1 : services) {
                if(!((BBoolean(!services.elementOf(_ic__opt_3_1).booleanValue() || _SERVICE.elementOf(_ic__opt_3_1).booleanValue()))).booleanValue()) {
                    _ic_boolean_16 = BBoolean(false);
                    break;
                }

            }
            return (_ic_boolean_16).booleanValue();
        }

        bool _check_inv_4() const {
            BBoolean _ic_boolean_17 = BBoolean(true);
            for(const RESOURCEMANAGER& _ic__opt_4_1 : resourceManagers) {
                if(!((BBoolean(!resourceManagers.elementOf(_ic__opt_4_1).booleanValue() || _RESOURCEMANAGER.elementOf(_ic__opt_4_1).booleanValue()))).booleanValue()) {
                    _ic_boolean_17 = BBoolean(false);
                    break;
                }

            }
            return (_ic_boolean_17).booleanValue();
        }

        bool _check_inv_5() const {
            BBoolean _ic_boolean_18 = BBoolean(true);
            for(const SID& _ic__opt_5_1 : sids) {
                if(!((BBoolean(!sids.elementOf(_ic__opt_5_1).booleanValue() || _SID.elementOf(_ic__opt_5_1).booleanValue()))).booleanValue()) {
                    _ic_boolean_18 = BBoolean(false);
                    break;
                }

            }
            return (_ic_boolean_18).booleanValue();
        }

        bool _check_inv_6() const {
            return (((rm_services.checkDomain(resourceManagers))._and((rm_services.checkRange(services.pow())))._and((rm_services.isFunction()))._and((rm_services.isTotal(resourceManagers))))).booleanValue();
        }

        bool _check_inv_7() const {
            BBoolean _ic_boolean_19 = BBoolean(true);
            for(const RESOURCEMANAGER& _ic_a1_1 : rm_services.domain()) {
                for(const RESOURCEMANAGER& _ic_a2_1 : rm_services.domain()) {
                    if(!((BBoolean(!(BBoolean((BBoolean(rm_services.domain().elementOf(_ic_a1_1).booleanValue() && rm_services.domain().elementOf(_ic_a2_1).booleanValue())).booleanValue() && _ic_a1_1.unequal(_ic_a2_1).booleanValue())).booleanValue() || rm_services.functionCall(_ic_a1_1).intersect(rm_services.functionCall(_ic_a2_1)).equal((BSet<SERVICE >())).booleanValue()))).booleanValue()) {
                        _ic_boolean_19 = BBoolean(false);
                        break;
                    }

                }
            }
            return (_ic_boolean_19).booleanValue();
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
            return (((svc_registered.checkDomain(services))._and((svc_registered.checkRangeBoolean()))._and((svc_registered.isFunction()))._and((svc_registered.isTotal(services))))).booleanValue();
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


class ModelChecker {
    private:
        nota_v2::Type type;
        int threads;
        bool isCaching;
        bool isDebug;

        std::list<nota_v2> unvisitedStates;
        std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> states;
        std::atomic<int> transitions;
        std::mutex mutex;
        std::mutex waitMutex;
        std::mutex cacheMutex;
        std::condition_variable waitCV;

        std::atomic<bool> invariantViolatedBool;
        std::atomic<bool> deadlockDetected;
        nota_v2 counterExampleState;

        std::unordered_map<BSet<nota_v2::INTERCONNECTNODE>, std::unordered_map<nota_v2::_ProjectionRead_constructor_interconnectNode, nota_v2::_ProjectionWrite_constructor_interconnectNode, nota_v2::_ProjectionRead_constructor_interconnectNode::Hash, nota_v2::_ProjectionRead_constructor_interconnectNode::HashEqual>, BSet<nota_v2::INTERCONNECTNODE>::SetHash, BSet<nota_v2::INTERCONNECTNODE>::SetHashEqual> _OpCache_constructor_interconnectNode;
        std::unordered_map<nota_v2::_ProjectionRead__tr_constructor_interconnectNode,  BSet<nota_v2::INTERCONNECTNODE>, nota_v2::_ProjectionRead__tr_constructor_interconnectNode::Hash, nota_v2::_ProjectionRead__tr_constructor_interconnectNode::HashEqual> _OpCache_tr_constructor_interconnectNode;
        std::mutex _ProjectionRead_constructor_interconnectNode_mutex;
        std::mutex _ProjectionRead__tr_constructor_interconnectNode_mutex;

        std::unordered_map<BSet<nota_v2::RESOURCEMANAGER>, std::unordered_map<nota_v2::_ProjectionRead_constructor_resourceManager, nota_v2::_ProjectionWrite_constructor_resourceManager, nota_v2::_ProjectionRead_constructor_resourceManager::Hash, nota_v2::_ProjectionRead_constructor_resourceManager::HashEqual>, BSet<nota_v2::RESOURCEMANAGER>::SetHash, BSet<nota_v2::RESOURCEMANAGER>::SetHashEqual> _OpCache_constructor_resourceManager;
        std::unordered_map<nota_v2::_ProjectionRead__tr_constructor_resourceManager,  BSet<nota_v2::RESOURCEMANAGER>, nota_v2::_ProjectionRead__tr_constructor_resourceManager::Hash, nota_v2::_ProjectionRead__tr_constructor_resourceManager::HashEqual> _OpCache_tr_constructor_resourceManager;
        std::mutex _ProjectionRead_constructor_resourceManager_mutex;
        std::mutex _ProjectionRead__tr_constructor_resourceManager_mutex;

        std::unordered_map<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>, std::unordered_map<nota_v2::_ProjectionRead_constructor_service, nota_v2::_ProjectionWrite_constructor_service, nota_v2::_ProjectionRead_constructor_service::Hash, nota_v2::_ProjectionRead_constructor_service::HashEqual>, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>::SetHash, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>::SetHashEqual> _OpCache_constructor_service;
        std::unordered_map<nota_v2::_ProjectionRead__tr_constructor_service,  BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>, nota_v2::_ProjectionRead__tr_constructor_service::Hash, nota_v2::_ProjectionRead__tr_constructor_service::HashEqual> _OpCache_tr_constructor_service;
        std::mutex _ProjectionRead_constructor_service_mutex;
        std::mutex _ProjectionRead__tr_constructor_service_mutex;

        std::unordered_map<BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>, std::unordered_map<nota_v2::_ProjectionRead_constructor_socket, nota_v2::_ProjectionWrite_constructor_socket, nota_v2::_ProjectionRead_constructor_socket::Hash, nota_v2::_ProjectionRead_constructor_socket::HashEqual>, BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>::SetHash, BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>::SetHashEqual> _OpCache_constructor_socket;
        std::unordered_map<nota_v2::_ProjectionRead__tr_constructor_socket,  BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>, nota_v2::_ProjectionRead__tr_constructor_socket::Hash, nota_v2::_ProjectionRead__tr_constructor_socket::HashEqual> _OpCache_tr_constructor_socket;
        std::mutex _ProjectionRead_constructor_socket_mutex;
        std::mutex _ProjectionRead__tr_constructor_socket_mutex;

        std::unordered_map<BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>, std::unordered_map<nota_v2::_ProjectionRead_rm_register, nota_v2::_ProjectionWrite_rm_register, nota_v2::_ProjectionRead_rm_register::Hash, nota_v2::_ProjectionRead_rm_register::HashEqual>, BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>::SetHash, BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>::SetHashEqual> _OpCache_rm_register;
        std::unordered_map<nota_v2::_ProjectionRead__tr_rm_register,  BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>, nota_v2::_ProjectionRead__tr_rm_register::Hash, nota_v2::_ProjectionRead__tr_rm_register::HashEqual> _OpCache_tr_rm_register;
        std::mutex _ProjectionRead_rm_register_mutex;
        std::mutex _ProjectionRead__tr_rm_register_mutex;

        std::unordered_map<BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>, std::unordered_map<nota_v2::_ProjectionRead_rm_deregister, nota_v2::_ProjectionWrite_rm_deregister, nota_v2::_ProjectionRead_rm_deregister::Hash, nota_v2::_ProjectionRead_rm_deregister::HashEqual>, BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>::SetHash, BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>::SetHashEqual> _OpCache_rm_deregister;
        std::unordered_map<nota_v2::_ProjectionRead__tr_rm_deregister,  BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >>, nota_v2::_ProjectionRead__tr_rm_deregister::Hash, nota_v2::_ProjectionRead__tr_rm_deregister::HashEqual> _OpCache_tr_rm_deregister;
        std::mutex _ProjectionRead_rm_deregister_mutex;
        std::mutex _ProjectionRead__tr_rm_deregister_mutex;

        std::unordered_map<BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>, std::unordered_map<nota_v2::_ProjectionRead_rm_getSid, nota_v2::_ProjectionWrite_rm_getSid, nota_v2::_ProjectionRead_rm_getSid::Hash, nota_v2::_ProjectionRead_rm_getSid::HashEqual>, BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>::SetHash, BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>::SetHashEqual> _OpCache_rm_getSid;
        std::unordered_map<nota_v2::_ProjectionRead__tr_rm_getSid,  BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>, nota_v2::_ProjectionRead__tr_rm_getSid::Hash, nota_v2::_ProjectionRead__tr_rm_getSid::HashEqual> _OpCache_tr_rm_getSid;
        std::mutex _ProjectionRead_rm_getSid_mutex;
        std::mutex _ProjectionRead__tr_rm_getSid_mutex;

        std::unordered_map<BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>, std::unordered_map<nota_v2::_ProjectionRead_rm_getSid_Not_Found, nota_v2::_ProjectionWrite_rm_getSid_Not_Found, nota_v2::_ProjectionRead_rm_getSid_Not_Found::Hash, nota_v2::_ProjectionRead_rm_getSid_Not_Found::HashEqual>, BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>::SetHash, BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>::SetHashEqual> _OpCache_rm_getSid_Not_Found;
        std::unordered_map<nota_v2::_ProjectionRead__tr_rm_getSid_Not_Found,  BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >>, nota_v2::_ProjectionRead__tr_rm_getSid_Not_Found::Hash, nota_v2::_ProjectionRead__tr_rm_getSid_Not_Found::HashEqual> _OpCache_tr_rm_getSid_Not_Found;
        std::mutex _ProjectionRead_rm_getSid_Not_Found_mutex;
        std::mutex _ProjectionRead__tr_rm_getSid_Not_Found_mutex;

        std::unordered_map<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >>, std::unordered_map<nota_v2::_ProjectionRead_in_announceResourceManager, nota_v2::_ProjectionWrite_in_announceResourceManager, nota_v2::_ProjectionRead_in_announceResourceManager::Hash, nota_v2::_ProjectionRead_in_announceResourceManager::HashEqual>, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >>::SetHash, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >>::SetHashEqual> _OpCache_in_announceResourceManager;
        std::unordered_map<nota_v2::_ProjectionRead__tr_in_announceResourceManager,  BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >>, nota_v2::_ProjectionRead__tr_in_announceResourceManager::Hash, nota_v2::_ProjectionRead__tr_in_announceResourceManager::HashEqual> _OpCache_tr_in_announceResourceManager;
        std::mutex _ProjectionRead_in_announceResourceManager_mutex;
        std::mutex _ProjectionRead__tr_in_announceResourceManager_mutex;

        std::unordered_map<BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >>, std::unordered_map<nota_v2::_ProjectionRead_in_register_success, nota_v2::_ProjectionWrite_in_register_success, nota_v2::_ProjectionRead_in_register_success::Hash, nota_v2::_ProjectionRead_in_register_success::HashEqual>, BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >>::SetHash, BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >>::SetHashEqual> _OpCache_in_register_success;
        std::unordered_map<nota_v2::_ProjectionRead__tr_in_register_success,  BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >>, nota_v2::_ProjectionRead__tr_in_register_success::Hash, nota_v2::_ProjectionRead__tr_in_register_success::HashEqual> _OpCache_tr_in_register_success;
        std::mutex _ProjectionRead_in_register_success_mutex;
        std::mutex _ProjectionRead__tr_in_register_success_mutex;

        std::unordered_map<BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>, std::unordered_map<nota_v2::_ProjectionRead_in_register_failed, nota_v2::_ProjectionWrite_in_register_failed, nota_v2::_ProjectionRead_in_register_failed::Hash, nota_v2::_ProjectionRead_in_register_failed::HashEqual>, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>::SetHash, BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>::SetHashEqual> _OpCache_in_register_failed;
        std::unordered_map<nota_v2::_ProjectionRead__tr_in_register_failed,  BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >>, nota_v2::_ProjectionRead__tr_in_register_failed::Hash, nota_v2::_ProjectionRead__tr_in_register_failed::HashEqual> _OpCache_tr_in_register_failed;
        std::mutex _ProjectionRead_in_register_failed_mutex;
        std::mutex _ProjectionRead__tr_in_register_failed_mutex;

        std::unordered_map<BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>, std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_Granted, nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::HashEqual>, BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>::SetHash, BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>::SetHashEqual> _OpCache_in_requestTargetSocket_Granted;
        std::unordered_map<nota_v2::_ProjectionRead__tr_in_requestTargetSocket_Granted,  BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >>, nota_v2::_ProjectionRead__tr_in_requestTargetSocket_Granted::Hash, nota_v2::_ProjectionRead__tr_in_requestTargetSocket_Granted::HashEqual> _OpCache_tr_in_requestTargetSocket_Granted;
        std::mutex _ProjectionRead_in_requestTargetSocket_Granted_mutex;
        std::mutex _ProjectionRead__tr_in_requestTargetSocket_Granted_mutex;

        std::unordered_map<BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >>, std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::HashEqual>, BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >>::SetHash, BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >>::SetHashEqual> _OpCache_in_requestTargetSocket_NotGranted;
        std::unordered_map<nota_v2::_ProjectionRead__tr_in_requestTargetSocket_NotGranted,  BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >>, nota_v2::_ProjectionRead__tr_in_requestTargetSocket_NotGranted::Hash, nota_v2::_ProjectionRead__tr_in_requestTargetSocket_NotGranted::HashEqual> _OpCache_tr_in_requestTargetSocket_NotGranted;
        std::mutex _ProjectionRead_in_requestTargetSocket_NotGranted_mutex;
        std::mutex _ProjectionRead__tr_in_requestTargetSocket_NotGranted_mutex;

        std::unordered_map<BSet<nota_v2::SERVICE>, std::unordered_map<nota_v2::_ProjectionRead_svc_register, nota_v2::_ProjectionWrite_svc_register, nota_v2::_ProjectionRead_svc_register::Hash, nota_v2::_ProjectionRead_svc_register::HashEqual>, BSet<nota_v2::SERVICE>::SetHash, BSet<nota_v2::SERVICE>::SetHashEqual> _OpCache_svc_register;
        std::unordered_map<nota_v2::_ProjectionRead__tr_svc_register,  BSet<nota_v2::SERVICE>, nota_v2::_ProjectionRead__tr_svc_register::Hash, nota_v2::_ProjectionRead__tr_svc_register::HashEqual> _OpCache_tr_svc_register;
        std::mutex _ProjectionRead_svc_register_mutex;
        std::mutex _ProjectionRead__tr_svc_register_mutex;

        std::unordered_map<nota_v2::_ProjectionRead__check_inv_1, bool, nota_v2::_ProjectionRead__check_inv_1::Hash, nota_v2::_ProjectionRead__check_inv_1::HashEqual> _InvCache__check_inv_1;
        std::mutex _ProjectionRead__check_inv_1_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_2, bool, nota_v2::_ProjectionRead__check_inv_2::Hash, nota_v2::_ProjectionRead__check_inv_2::HashEqual> _InvCache__check_inv_2;
        std::mutex _ProjectionRead__check_inv_2_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_3, bool, nota_v2::_ProjectionRead__check_inv_3::Hash, nota_v2::_ProjectionRead__check_inv_3::HashEqual> _InvCache__check_inv_3;
        std::mutex _ProjectionRead__check_inv_3_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_4, bool, nota_v2::_ProjectionRead__check_inv_4::Hash, nota_v2::_ProjectionRead__check_inv_4::HashEqual> _InvCache__check_inv_4;
        std::mutex _ProjectionRead__check_inv_4_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_5, bool, nota_v2::_ProjectionRead__check_inv_5::Hash, nota_v2::_ProjectionRead__check_inv_5::HashEqual> _InvCache__check_inv_5;
        std::mutex _ProjectionRead__check_inv_5_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_6, bool, nota_v2::_ProjectionRead__check_inv_6::Hash, nota_v2::_ProjectionRead__check_inv_6::HashEqual> _InvCache__check_inv_6;
        std::mutex _ProjectionRead__check_inv_6_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_7, bool, nota_v2::_ProjectionRead__check_inv_7::Hash, nota_v2::_ProjectionRead__check_inv_7::HashEqual> _InvCache__check_inv_7;
        std::mutex _ProjectionRead__check_inv_7_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_8, bool, nota_v2::_ProjectionRead__check_inv_8::Hash, nota_v2::_ProjectionRead__check_inv_8::HashEqual> _InvCache__check_inv_8;
        std::mutex _ProjectionRead__check_inv_8_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_9, bool, nota_v2::_ProjectionRead__check_inv_9::Hash, nota_v2::_ProjectionRead__check_inv_9::HashEqual> _InvCache__check_inv_9;
        std::mutex _ProjectionRead__check_inv_9_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_10, bool, nota_v2::_ProjectionRead__check_inv_10::Hash, nota_v2::_ProjectionRead__check_inv_10::HashEqual> _InvCache__check_inv_10;
        std::mutex _ProjectionRead__check_inv_10_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_11, bool, nota_v2::_ProjectionRead__check_inv_11::Hash, nota_v2::_ProjectionRead__check_inv_11::HashEqual> _InvCache__check_inv_11;
        std::mutex _ProjectionRead__check_inv_11_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_12, bool, nota_v2::_ProjectionRead__check_inv_12::Hash, nota_v2::_ProjectionRead__check_inv_12::HashEqual> _InvCache__check_inv_12;
        std::mutex _ProjectionRead__check_inv_12_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_13, bool, nota_v2::_ProjectionRead__check_inv_13::Hash, nota_v2::_ProjectionRead__check_inv_13::HashEqual> _InvCache__check_inv_13;
        std::mutex _ProjectionRead__check_inv_13_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_14, bool, nota_v2::_ProjectionRead__check_inv_14::Hash, nota_v2::_ProjectionRead__check_inv_14::HashEqual> _InvCache__check_inv_14;
        std::mutex _ProjectionRead__check_inv_14_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_15, bool, nota_v2::_ProjectionRead__check_inv_15::Hash, nota_v2::_ProjectionRead__check_inv_15::HashEqual> _InvCache__check_inv_15;
        std::mutex _ProjectionRead__check_inv_15_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_16, bool, nota_v2::_ProjectionRead__check_inv_16::Hash, nota_v2::_ProjectionRead__check_inv_16::HashEqual> _InvCache__check_inv_16;
        std::mutex _ProjectionRead__check_inv_16_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_17, bool, nota_v2::_ProjectionRead__check_inv_17::Hash, nota_v2::_ProjectionRead__check_inv_17::HashEqual> _InvCache__check_inv_17;
        std::mutex _ProjectionRead__check_inv_17_mutex;
        std::unordered_map<nota_v2::_ProjectionRead__check_inv_18, bool, nota_v2::_ProjectionRead__check_inv_18::Hash, nota_v2::_ProjectionRead__check_inv_18::HashEqual> _InvCache__check_inv_18;
        std::mutex _ProjectionRead__check_inv_18_mutex;

        std::unordered_map<nota_v2, nota_v2, nota_v2::Hash, nota_v2::HashEqual> parents;

    public:
        ModelChecker() {}

        ModelChecker(nota_v2::Type type, int threads, bool isCaching, bool isDebug) {
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
            nota_v2 machine = nota_v2();
            states.insert(machine);
            unvisitedStates.push_back(machine);

            while(!unvisitedStates.empty()) {
                nota_v2 state = next();

                std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> nextStates = generateNextStates(state);

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
            nota_v2 machine = nota_v2();
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
                nota_v2 state = next();
                std::packaged_task<void()> task([&, state] {
                    std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> nextStates = generateNextStates(state);

                    for(auto& nextState : nextStates) {
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
        nota_v2 next() {
            {
                std::unique_lock<std::mutex> lock(mutex);
                switch(type) {
                    case nota_v2::BFS: {
                        nota_v2 state = unvisitedStates.front();
                        unvisitedStates.pop_front();
                        return state;
                    }
                    case nota_v2::DFS: {
                        nota_v2 state = unvisitedStates.back();
                        unvisitedStates.pop_back();
                        return state;
                    }
                    case nota_v2::MIXED: {
                        if(unvisitedStates.size() % 2 == 0) {
                            nota_v2 state = unvisitedStates.front();
                            unvisitedStates.pop_front();
                            return state;
                        } else {
                            nota_v2 state = unvisitedStates.back();
                            unvisitedStates.pop_back();
                            return state;
                        }
                    }
                }
            };
        }

        std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> generateNextStates(const nota_v2& state) {
            std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual> result = std::unordered_set<nota_v2, nota_v2::Hash, nota_v2::HashEqual>();
            if(isCaching) {
                nota_v2::_ProjectionRead__tr_constructor_interconnectNode read__tr_constructor_interconnectNode_state = state._projected_state_for__tr_constructor_interconnectNode();
                BSet<nota_v2::INTERCONNECTNODE> _trid_1;
                auto _trid_1_ptr = _OpCache_tr_constructor_interconnectNode.find(read__tr_constructor_interconnectNode_state);
                if(_trid_1_ptr == _OpCache_tr_constructor_interconnectNode.end()) {
                    _trid_1 = state._tr_constructor_interconnectNode();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_constructor_interconnectNode_lock(_ProjectionRead__tr_constructor_interconnectNode_mutex);
                        _OpCache_tr_constructor_interconnectNode.insert({read__tr_constructor_interconnectNode_state, _trid_1});
                    }
                } else {
                    _trid_1 = _trid_1_ptr->second;
                }

                for(const nota_v2::INTERCONNECTNODE& param : _trid_1) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_constructor_interconnectNode readState = state._projected_state_for_constructor_interconnectNode();

                    auto _OpCache_with_parameter_constructor_interconnectNode_ptr = _OpCache_constructor_interconnectNode.find(param);
                    if(_OpCache_with_parameter_constructor_interconnectNode_ptr == _OpCache_constructor_interconnectNode.end()) {
                        copiedState.constructor_interconnectNode(_tmp_1);
                        nota_v2::_ProjectionWrite_constructor_interconnectNode writeState = copiedState._update_for_constructor_interconnectNode();
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_interconnectNode, nota_v2::_ProjectionWrite_constructor_interconnectNode, nota_v2::_ProjectionRead_constructor_interconnectNode::Hash, nota_v2::_ProjectionRead_constructor_interconnectNode::HashEqual> _OpCache_with_parameter_constructor_interconnectNode;
                        _OpCache_with_parameter_constructor_interconnectNode.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_constructor_interconnectNode_lock(_ProjectionRead_constructor_interconnectNode_mutex);
                            _OpCache_constructor_interconnectNode.insert({param, _OpCache_with_parameter_constructor_interconnectNode});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_interconnectNode, nota_v2::_ProjectionWrite_constructor_interconnectNode, nota_v2::_ProjectionRead_constructor_interconnectNode::Hash, nota_v2::_ProjectionRead_constructor_interconnectNode::HashEqual> _OpCache_with_parameter_constructor_interconnectNode = _OpCache_with_parameter_constructor_interconnectNode_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_constructor_interconnectNode.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_constructor_interconnectNode.end()) {
                            nota_v2::_ProjectionWrite_constructor_interconnectNode writeState = writeState_ptr->second;
                            copiedState._apply_update_for_constructor_interconnectNode(writeState);
                        } else {
                            copiedState.constructor_interconnectNode(_tmp_1);
                            nota_v2::_ProjectionWrite_constructor_interconnectNode writeState = copiedState._update_for_constructor_interconnectNode();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_constructor_interconnectNode_lock(_ProjectionRead_constructor_interconnectNode_mutex);
                                _OpCache_with_parameter_constructor_interconnectNode.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "constructor_interconnectNode";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_constructor_resourceManager read__tr_constructor_resourceManager_state = state._projected_state_for__tr_constructor_resourceManager();
                BSet<nota_v2::RESOURCEMANAGER> _trid_2;
                auto _trid_2_ptr = _OpCache_tr_constructor_resourceManager.find(read__tr_constructor_resourceManager_state);
                if(_trid_2_ptr == _OpCache_tr_constructor_resourceManager.end()) {
                    _trid_2 = state._tr_constructor_resourceManager();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_constructor_resourceManager_lock(_ProjectionRead__tr_constructor_resourceManager_mutex);
                        _OpCache_tr_constructor_resourceManager.insert({read__tr_constructor_resourceManager_state, _trid_2});
                    }
                } else {
                    _trid_2 = _trid_2_ptr->second;
                }

                for(const nota_v2::RESOURCEMANAGER& param : _trid_2) {
                    nota_v2::RESOURCEMANAGER _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_constructor_resourceManager readState = state._projected_state_for_constructor_resourceManager();

                    auto _OpCache_with_parameter_constructor_resourceManager_ptr = _OpCache_constructor_resourceManager.find(param);
                    if(_OpCache_with_parameter_constructor_resourceManager_ptr == _OpCache_constructor_resourceManager.end()) {
                        copiedState.constructor_resourceManager(_tmp_1);
                        nota_v2::_ProjectionWrite_constructor_resourceManager writeState = copiedState._update_for_constructor_resourceManager();
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_resourceManager, nota_v2::_ProjectionWrite_constructor_resourceManager, nota_v2::_ProjectionRead_constructor_resourceManager::Hash, nota_v2::_ProjectionRead_constructor_resourceManager::HashEqual> _OpCache_with_parameter_constructor_resourceManager;
                        _OpCache_with_parameter_constructor_resourceManager.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_constructor_resourceManager_lock(_ProjectionRead_constructor_resourceManager_mutex);
                            _OpCache_constructor_resourceManager.insert({param, _OpCache_with_parameter_constructor_resourceManager});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_resourceManager, nota_v2::_ProjectionWrite_constructor_resourceManager, nota_v2::_ProjectionRead_constructor_resourceManager::Hash, nota_v2::_ProjectionRead_constructor_resourceManager::HashEqual> _OpCache_with_parameter_constructor_resourceManager = _OpCache_with_parameter_constructor_resourceManager_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_constructor_resourceManager.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_constructor_resourceManager.end()) {
                            nota_v2::_ProjectionWrite_constructor_resourceManager writeState = writeState_ptr->second;
                            copiedState._apply_update_for_constructor_resourceManager(writeState);
                        } else {
                            copiedState.constructor_resourceManager(_tmp_1);
                            nota_v2::_ProjectionWrite_constructor_resourceManager writeState = copiedState._update_for_constructor_resourceManager();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_constructor_resourceManager_lock(_ProjectionRead_constructor_resourceManager_mutex);
                                _OpCache_with_parameter_constructor_resourceManager.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "constructor_resourceManager";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_constructor_service read__tr_constructor_service_state = state._projected_state_for__tr_constructor_service();
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_3;
                auto _trid_3_ptr = _OpCache_tr_constructor_service.find(read__tr_constructor_service_state);
                if(_trid_3_ptr == _OpCache_tr_constructor_service.end()) {
                    _trid_3 = state._tr_constructor_service();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_constructor_service_lock(_ProjectionRead__tr_constructor_service_mutex);
                        _OpCache_tr_constructor_service.insert({read__tr_constructor_service_state, _trid_3});
                    }
                } else {
                    _trid_3 = _trid_3_ptr->second;
                }

                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_3) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_constructor_service readState = state._projected_state_for_constructor_service();

                    auto _OpCache_with_parameter_constructor_service_ptr = _OpCache_constructor_service.find(param);
                    if(_OpCache_with_parameter_constructor_service_ptr == _OpCache_constructor_service.end()) {
                        copiedState.constructor_service(_tmp_2, _tmp_1);
                        nota_v2::_ProjectionWrite_constructor_service writeState = copiedState._update_for_constructor_service();
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_service, nota_v2::_ProjectionWrite_constructor_service, nota_v2::_ProjectionRead_constructor_service::Hash, nota_v2::_ProjectionRead_constructor_service::HashEqual> _OpCache_with_parameter_constructor_service;
                        _OpCache_with_parameter_constructor_service.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_constructor_service_lock(_ProjectionRead_constructor_service_mutex);
                            _OpCache_constructor_service.insert({param, _OpCache_with_parameter_constructor_service});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_service, nota_v2::_ProjectionWrite_constructor_service, nota_v2::_ProjectionRead_constructor_service::Hash, nota_v2::_ProjectionRead_constructor_service::HashEqual> _OpCache_with_parameter_constructor_service = _OpCache_with_parameter_constructor_service_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_constructor_service.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_constructor_service.end()) {
                            nota_v2::_ProjectionWrite_constructor_service writeState = writeState_ptr->second;
                            copiedState._apply_update_for_constructor_service(writeState);
                        } else {
                            copiedState.constructor_service(_tmp_2, _tmp_1);
                            nota_v2::_ProjectionWrite_constructor_service writeState = copiedState._update_for_constructor_service();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_constructor_service_lock(_ProjectionRead_constructor_service_mutex);
                                _OpCache_with_parameter_constructor_service.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "constructor_service";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_constructor_socket read__tr_constructor_socket_state = state._projected_state_for__tr_constructor_socket();
                BSet<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_4;
                auto _trid_4_ptr = _OpCache_tr_constructor_socket.find(read__tr_constructor_socket_state);
                if(_trid_4_ptr == _OpCache_tr_constructor_socket.end()) {
                    _trid_4 = state._tr_constructor_socket();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_constructor_socket_lock(_ProjectionRead__tr_constructor_socket_mutex);
                        _OpCache_tr_constructor_socket.insert({read__tr_constructor_socket_state, _trid_4});
                    }
                } else {
                    _trid_4 = _trid_4_ptr->second;
                }

                for(const BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >& param : _trid_4) {
                    nota_v2::SOCKET _tmp_1 = param.projection2();
                    BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID >, nota_v2::SID > _tmp_2 = param.projection1();
                    nota_v2::SID _tmp_3 = _tmp_2.projection2();
                    BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SID > _tmp_4 = _tmp_2.projection1();
                    nota_v2::SID _tmp_5 = _tmp_4.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_6 = _tmp_4.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_constructor_socket readState = state._projected_state_for_constructor_socket();

                    auto _OpCache_with_parameter_constructor_socket_ptr = _OpCache_constructor_socket.find(param);
                    if(_OpCache_with_parameter_constructor_socket_ptr == _OpCache_constructor_socket.end()) {
                        copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_constructor_socket writeState = copiedState._update_for_constructor_socket();
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_socket, nota_v2::_ProjectionWrite_constructor_socket, nota_v2::_ProjectionRead_constructor_socket::Hash, nota_v2::_ProjectionRead_constructor_socket::HashEqual> _OpCache_with_parameter_constructor_socket;
                        _OpCache_with_parameter_constructor_socket.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_constructor_socket_lock(_ProjectionRead_constructor_socket_mutex);
                            _OpCache_constructor_socket.insert({param, _OpCache_with_parameter_constructor_socket});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_constructor_socket, nota_v2::_ProjectionWrite_constructor_socket, nota_v2::_ProjectionRead_constructor_socket::Hash, nota_v2::_ProjectionRead_constructor_socket::HashEqual> _OpCache_with_parameter_constructor_socket = _OpCache_with_parameter_constructor_socket_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_constructor_socket.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_constructor_socket.end()) {
                            nota_v2::_ProjectionWrite_constructor_socket writeState = writeState_ptr->second;
                            copiedState._apply_update_for_constructor_socket(writeState);
                        } else {
                            copiedState.constructor_socket(_tmp_6, _tmp_5, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_constructor_socket writeState = copiedState._update_for_constructor_socket();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_constructor_socket_lock(_ProjectionRead_constructor_socket_mutex);
                                _OpCache_with_parameter_constructor_socket.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "constructor_socket";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_rm_register read__tr_rm_register_state = state._projected_state_for__tr_rm_register();
                BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_5;
                auto _trid_5_ptr = _OpCache_tr_rm_register.find(read__tr_rm_register_state);
                if(_trid_5_ptr == _OpCache_tr_rm_register.end()) {
                    _trid_5 = state._tr_rm_register();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_rm_register_lock(_ProjectionRead__tr_rm_register_mutex);
                        _OpCache_tr_rm_register.insert({read__tr_rm_register_state, _trid_5});
                    }
                } else {
                    _trid_5 = _trid_5_ptr->second;
                }

                for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_5) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_rm_register readState = state._projected_state_for_rm_register();

                    auto _OpCache_with_parameter_rm_register_ptr = _OpCache_rm_register.find(param);
                    if(_OpCache_with_parameter_rm_register_ptr == _OpCache_rm_register.end()) {
                        copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_rm_register writeState = copiedState._update_for_rm_register();
                        std::unordered_map<nota_v2::_ProjectionRead_rm_register, nota_v2::_ProjectionWrite_rm_register, nota_v2::_ProjectionRead_rm_register::Hash, nota_v2::_ProjectionRead_rm_register::HashEqual> _OpCache_with_parameter_rm_register;
                        _OpCache_with_parameter_rm_register.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_rm_register_lock(_ProjectionRead_rm_register_mutex);
                            _OpCache_rm_register.insert({param, _OpCache_with_parameter_rm_register});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_rm_register, nota_v2::_ProjectionWrite_rm_register, nota_v2::_ProjectionRead_rm_register::Hash, nota_v2::_ProjectionRead_rm_register::HashEqual> _OpCache_with_parameter_rm_register = _OpCache_with_parameter_rm_register_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_rm_register.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_rm_register.end()) {
                            nota_v2::_ProjectionWrite_rm_register writeState = writeState_ptr->second;
                            copiedState._apply_update_for_rm_register(writeState);
                        } else {
                            copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_rm_register writeState = copiedState._update_for_rm_register();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_rm_register_lock(_ProjectionRead_rm_register_mutex);
                                _OpCache_with_parameter_rm_register.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "rm_register";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_rm_deregister read__tr_rm_deregister_state = state._projected_state_for__tr_rm_deregister();
                BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_6;
                auto _trid_6_ptr = _OpCache_tr_rm_deregister.find(read__tr_rm_deregister_state);
                if(_trid_6_ptr == _OpCache_tr_rm_deregister.end()) {
                    _trid_6 = state._tr_rm_deregister();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_rm_deregister_lock(_ProjectionRead__tr_rm_deregister_mutex);
                        _OpCache_tr_rm_deregister.insert({read__tr_rm_deregister_state, _trid_6});
                    }
                } else {
                    _trid_6 = _trid_6_ptr->second;
                }

                for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_6) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_rm_deregister readState = state._projected_state_for_rm_deregister();

                    auto _OpCache_with_parameter_rm_deregister_ptr = _OpCache_rm_deregister.find(param);
                    if(_OpCache_with_parameter_rm_deregister_ptr == _OpCache_rm_deregister.end()) {
                        copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_rm_deregister writeState = copiedState._update_for_rm_deregister();
                        std::unordered_map<nota_v2::_ProjectionRead_rm_deregister, nota_v2::_ProjectionWrite_rm_deregister, nota_v2::_ProjectionRead_rm_deregister::Hash, nota_v2::_ProjectionRead_rm_deregister::HashEqual> _OpCache_with_parameter_rm_deregister;
                        _OpCache_with_parameter_rm_deregister.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_rm_deregister_lock(_ProjectionRead_rm_deregister_mutex);
                            _OpCache_rm_deregister.insert({param, _OpCache_with_parameter_rm_deregister});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_rm_deregister, nota_v2::_ProjectionWrite_rm_deregister, nota_v2::_ProjectionRead_rm_deregister::Hash, nota_v2::_ProjectionRead_rm_deregister::HashEqual> _OpCache_with_parameter_rm_deregister = _OpCache_with_parameter_rm_deregister_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_rm_deregister.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_rm_deregister.end()) {
                            nota_v2::_ProjectionWrite_rm_deregister writeState = writeState_ptr->second;
                            copiedState._apply_update_for_rm_deregister(writeState);
                        } else {
                            copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_rm_deregister writeState = copiedState._update_for_rm_deregister();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_rm_deregister_lock(_ProjectionRead_rm_deregister_mutex);
                                _OpCache_with_parameter_rm_deregister.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "rm_deregister";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_rm_getSid read__tr_rm_getSid_state = state._projected_state_for__tr_rm_getSid();
                BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_7;
                auto _trid_7_ptr = _OpCache_tr_rm_getSid.find(read__tr_rm_getSid_state);
                if(_trid_7_ptr == _OpCache_tr_rm_getSid.end()) {
                    _trid_7 = state._tr_rm_getSid();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_rm_getSid_lock(_ProjectionRead__tr_rm_getSid_mutex);
                        _OpCache_tr_rm_getSid.insert({read__tr_rm_getSid_state, _trid_7});
                    }
                } else {
                    _trid_7 = _trid_7_ptr->second;
                }

                for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_7) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_rm_getSid readState = state._projected_state_for_rm_getSid();

                    auto _OpCache_with_parameter_rm_getSid_ptr = _OpCache_rm_getSid.find(param);
                    if(_OpCache_with_parameter_rm_getSid_ptr == _OpCache_rm_getSid.end()) {
                        copiedState.rm_getSid(_tmp_2, _tmp_1);
                        nota_v2::_ProjectionWrite_rm_getSid writeState = copiedState._update_for_rm_getSid();
                        std::unordered_map<nota_v2::_ProjectionRead_rm_getSid, nota_v2::_ProjectionWrite_rm_getSid, nota_v2::_ProjectionRead_rm_getSid::Hash, nota_v2::_ProjectionRead_rm_getSid::HashEqual> _OpCache_with_parameter_rm_getSid;
                        _OpCache_with_parameter_rm_getSid.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_rm_getSid_lock(_ProjectionRead_rm_getSid_mutex);
                            _OpCache_rm_getSid.insert({param, _OpCache_with_parameter_rm_getSid});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_rm_getSid, nota_v2::_ProjectionWrite_rm_getSid, nota_v2::_ProjectionRead_rm_getSid::Hash, nota_v2::_ProjectionRead_rm_getSid::HashEqual> _OpCache_with_parameter_rm_getSid = _OpCache_with_parameter_rm_getSid_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_rm_getSid.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_rm_getSid.end()) {
                            nota_v2::_ProjectionWrite_rm_getSid writeState = writeState_ptr->second;
                            copiedState._apply_update_for_rm_getSid(writeState);
                        } else {
                            copiedState.rm_getSid(_tmp_2, _tmp_1);
                            nota_v2::_ProjectionWrite_rm_getSid writeState = copiedState._update_for_rm_getSid();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_rm_getSid_lock(_ProjectionRead_rm_getSid_mutex);
                                _OpCache_with_parameter_rm_getSid.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "rm_getSid";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_rm_getSid_Not_Found read__tr_rm_getSid_Not_Found_state = state._projected_state_for__tr_rm_getSid_Not_Found();
                BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_8;
                auto _trid_8_ptr = _OpCache_tr_rm_getSid_Not_Found.find(read__tr_rm_getSid_Not_Found_state);
                if(_trid_8_ptr == _OpCache_tr_rm_getSid_Not_Found.end()) {
                    _trid_8 = state._tr_rm_getSid_Not_Found();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_rm_getSid_Not_Found_lock(_ProjectionRead__tr_rm_getSid_Not_Found_mutex);
                        _OpCache_tr_rm_getSid_Not_Found.insert({read__tr_rm_getSid_Not_Found_state, _trid_8});
                    }
                } else {
                    _trid_8 = _trid_8_ptr->second;
                }

                for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_8) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_rm_getSid_Not_Found readState = state._projected_state_for_rm_getSid_Not_Found();

                    auto _OpCache_with_parameter_rm_getSid_Not_Found_ptr = _OpCache_rm_getSid_Not_Found.find(param);
                    if(_OpCache_with_parameter_rm_getSid_Not_Found_ptr == _OpCache_rm_getSid_Not_Found.end()) {
                        copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                        nota_v2::_ProjectionWrite_rm_getSid_Not_Found writeState = copiedState._update_for_rm_getSid_Not_Found();
                        std::unordered_map<nota_v2::_ProjectionRead_rm_getSid_Not_Found, nota_v2::_ProjectionWrite_rm_getSid_Not_Found, nota_v2::_ProjectionRead_rm_getSid_Not_Found::Hash, nota_v2::_ProjectionRead_rm_getSid_Not_Found::HashEqual> _OpCache_with_parameter_rm_getSid_Not_Found;
                        _OpCache_with_parameter_rm_getSid_Not_Found.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_rm_getSid_Not_Found_lock(_ProjectionRead_rm_getSid_Not_Found_mutex);
                            _OpCache_rm_getSid_Not_Found.insert({param, _OpCache_with_parameter_rm_getSid_Not_Found});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_rm_getSid_Not_Found, nota_v2::_ProjectionWrite_rm_getSid_Not_Found, nota_v2::_ProjectionRead_rm_getSid_Not_Found::Hash, nota_v2::_ProjectionRead_rm_getSid_Not_Found::HashEqual> _OpCache_with_parameter_rm_getSid_Not_Found = _OpCache_with_parameter_rm_getSid_Not_Found_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_rm_getSid_Not_Found.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_rm_getSid_Not_Found.end()) {
                            nota_v2::_ProjectionWrite_rm_getSid_Not_Found writeState = writeState_ptr->second;
                            copiedState._apply_update_for_rm_getSid_Not_Found(writeState);
                        } else {
                            copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                            nota_v2::_ProjectionWrite_rm_getSid_Not_Found writeState = copiedState._update_for_rm_getSid_Not_Found();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_rm_getSid_Not_Found_lock(_ProjectionRead_rm_getSid_Not_Found_mutex);
                                _OpCache_with_parameter_rm_getSid_Not_Found.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "rm_getSid_Not_Found";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_in_announceResourceManager read__tr_in_announceResourceManager_state = state._projected_state_for__tr_in_announceResourceManager();
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >> _trid_9;
                auto _trid_9_ptr = _OpCache_tr_in_announceResourceManager.find(read__tr_in_announceResourceManager_state);
                if(_trid_9_ptr == _OpCache_tr_in_announceResourceManager.end()) {
                    _trid_9 = state._tr_in_announceResourceManager();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_in_announceResourceManager_lock(_ProjectionRead__tr_in_announceResourceManager_mutex);
                        _OpCache_tr_in_announceResourceManager.insert({read__tr_in_announceResourceManager_state, _trid_9});
                    }
                } else {
                    _trid_9 = _trid_9_ptr->second;
                }

                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >& param : _trid_9) {
                    nota_v2::RESOURCEMANAGER _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_in_announceResourceManager readState = state._projected_state_for_in_announceResourceManager();

                    auto _OpCache_with_parameter_in_announceResourceManager_ptr = _OpCache_in_announceResourceManager.find(param);
                    if(_OpCache_with_parameter_in_announceResourceManager_ptr == _OpCache_in_announceResourceManager.end()) {
                        copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                        nota_v2::_ProjectionWrite_in_announceResourceManager writeState = copiedState._update_for_in_announceResourceManager();
                        std::unordered_map<nota_v2::_ProjectionRead_in_announceResourceManager, nota_v2::_ProjectionWrite_in_announceResourceManager, nota_v2::_ProjectionRead_in_announceResourceManager::Hash, nota_v2::_ProjectionRead_in_announceResourceManager::HashEqual> _OpCache_with_parameter_in_announceResourceManager;
                        _OpCache_with_parameter_in_announceResourceManager.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_in_announceResourceManager_lock(_ProjectionRead_in_announceResourceManager_mutex);
                            _OpCache_in_announceResourceManager.insert({param, _OpCache_with_parameter_in_announceResourceManager});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_in_announceResourceManager, nota_v2::_ProjectionWrite_in_announceResourceManager, nota_v2::_ProjectionRead_in_announceResourceManager::Hash, nota_v2::_ProjectionRead_in_announceResourceManager::HashEqual> _OpCache_with_parameter_in_announceResourceManager = _OpCache_with_parameter_in_announceResourceManager_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_in_announceResourceManager.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_in_announceResourceManager.end()) {
                            nota_v2::_ProjectionWrite_in_announceResourceManager writeState = writeState_ptr->second;
                            copiedState._apply_update_for_in_announceResourceManager(writeState);
                        } else {
                            copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                            nota_v2::_ProjectionWrite_in_announceResourceManager writeState = copiedState._update_for_in_announceResourceManager();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_in_announceResourceManager_lock(_ProjectionRead_in_announceResourceManager_mutex);
                                _OpCache_with_parameter_in_announceResourceManager.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "in_announceResourceManager";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_in_register_success read__tr_in_register_success_state = state._projected_state_for__tr_in_register_success();
                BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >> _trid_10;
                auto _trid_10_ptr = _OpCache_tr_in_register_success.find(read__tr_in_register_success_state);
                if(_trid_10_ptr == _OpCache_tr_in_register_success.end()) {
                    _trid_10 = state._tr_in_register_success();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_in_register_success_lock(_ProjectionRead__tr_in_register_success_mutex);
                        _OpCache_tr_in_register_success.insert({read__tr_in_register_success_state, _trid_10});
                    }
                } else {
                    _trid_10 = _trid_10_ptr->second;
                }

                for(const BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >& param : _trid_10) {
                    nota_v2::SID _tmp_1 = param.projection2();
                    BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_in_register_success readState = state._projected_state_for_in_register_success();

                    auto _OpCache_with_parameter_in_register_success_ptr = _OpCache_in_register_success.find(param);
                    if(_OpCache_with_parameter_in_register_success_ptr == _OpCache_in_register_success.end()) {
                        copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_in_register_success writeState = copiedState._update_for_in_register_success();
                        std::unordered_map<nota_v2::_ProjectionRead_in_register_success, nota_v2::_ProjectionWrite_in_register_success, nota_v2::_ProjectionRead_in_register_success::Hash, nota_v2::_ProjectionRead_in_register_success::HashEqual> _OpCache_with_parameter_in_register_success;
                        _OpCache_with_parameter_in_register_success.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_in_register_success_lock(_ProjectionRead_in_register_success_mutex);
                            _OpCache_in_register_success.insert({param, _OpCache_with_parameter_in_register_success});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_in_register_success, nota_v2::_ProjectionWrite_in_register_success, nota_v2::_ProjectionRead_in_register_success::Hash, nota_v2::_ProjectionRead_in_register_success::HashEqual> _OpCache_with_parameter_in_register_success = _OpCache_with_parameter_in_register_success_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_in_register_success.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_in_register_success.end()) {
                            nota_v2::_ProjectionWrite_in_register_success writeState = writeState_ptr->second;
                            copiedState._apply_update_for_in_register_success(writeState);
                        } else {
                            copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_in_register_success writeState = copiedState._update_for_in_register_success();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_in_register_success_lock(_ProjectionRead_in_register_success_mutex);
                                _OpCache_with_parameter_in_register_success.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "in_register_success";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_in_register_failed read__tr_in_register_failed_state = state._projected_state_for__tr_in_register_failed();
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_11;
                auto _trid_11_ptr = _OpCache_tr_in_register_failed.find(read__tr_in_register_failed_state);
                if(_trid_11_ptr == _OpCache_tr_in_register_failed.end()) {
                    _trid_11 = state._tr_in_register_failed();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_in_register_failed_lock(_ProjectionRead__tr_in_register_failed_mutex);
                        _OpCache_tr_in_register_failed.insert({read__tr_in_register_failed_state, _trid_11});
                    }
                } else {
                    _trid_11 = _trid_11_ptr->second;
                }

                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_11) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_in_register_failed readState = state._projected_state_for_in_register_failed();

                    auto _OpCache_with_parameter_in_register_failed_ptr = _OpCache_in_register_failed.find(param);
                    if(_OpCache_with_parameter_in_register_failed_ptr == _OpCache_in_register_failed.end()) {
                        copiedState.in_register_failed(_tmp_2, _tmp_1);
                        nota_v2::_ProjectionWrite_in_register_failed writeState = copiedState._update_for_in_register_failed();
                        std::unordered_map<nota_v2::_ProjectionRead_in_register_failed, nota_v2::_ProjectionWrite_in_register_failed, nota_v2::_ProjectionRead_in_register_failed::Hash, nota_v2::_ProjectionRead_in_register_failed::HashEqual> _OpCache_with_parameter_in_register_failed;
                        _OpCache_with_parameter_in_register_failed.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_in_register_failed_lock(_ProjectionRead_in_register_failed_mutex);
                            _OpCache_in_register_failed.insert({param, _OpCache_with_parameter_in_register_failed});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_in_register_failed, nota_v2::_ProjectionWrite_in_register_failed, nota_v2::_ProjectionRead_in_register_failed::Hash, nota_v2::_ProjectionRead_in_register_failed::HashEqual> _OpCache_with_parameter_in_register_failed = _OpCache_with_parameter_in_register_failed_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_in_register_failed.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_in_register_failed.end()) {
                            nota_v2::_ProjectionWrite_in_register_failed writeState = writeState_ptr->second;
                            copiedState._apply_update_for_in_register_failed(writeState);
                        } else {
                            copiedState.in_register_failed(_tmp_2, _tmp_1);
                            nota_v2::_ProjectionWrite_in_register_failed writeState = copiedState._update_for_in_register_failed();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_in_register_failed_lock(_ProjectionRead_in_register_failed_mutex);
                                _OpCache_with_parameter_in_register_failed.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "in_register_failed";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_in_requestTargetSocket_Granted read__tr_in_requestTargetSocket_Granted_state = state._projected_state_for__tr_in_requestTargetSocket_Granted();
                BSet<BTuple<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >, nota_v2::SOCKET >> _trid_12;
                auto _trid_12_ptr = _OpCache_tr_in_requestTargetSocket_Granted.find(read__tr_in_requestTargetSocket_Granted_state);
                if(_trid_12_ptr == _OpCache_tr_in_requestTargetSocket_Granted.end()) {
                    _trid_12 = state._tr_in_requestTargetSocket_Granted();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_in_requestTargetSocket_Granted_lock(_ProjectionRead__tr_in_requestTargetSocket_Granted_mutex);
                        _OpCache_tr_in_requestTargetSocket_Granted.insert({read__tr_in_requestTargetSocket_Granted_state, _trid_12});
                    }
                } else {
                    _trid_12 = _trid_12_ptr->second;
                }

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
                    nota_v2::_ProjectionRead_in_requestTargetSocket_Granted readState = state._projected_state_for_in_requestTargetSocket_Granted();

                    auto _OpCache_with_parameter_in_requestTargetSocket_Granted_ptr = _OpCache_in_requestTargetSocket_Granted.find(param);
                    if(_OpCache_with_parameter_in_requestTargetSocket_Granted_ptr == _OpCache_in_requestTargetSocket_Granted.end()) {
                        copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted writeState = copiedState._update_for_in_requestTargetSocket_Granted();
                        std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_Granted, nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::HashEqual> _OpCache_with_parameter_in_requestTargetSocket_Granted;
                        _OpCache_with_parameter_in_requestTargetSocket_Granted.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_in_requestTargetSocket_Granted_lock(_ProjectionRead_in_requestTargetSocket_Granted_mutex);
                            _OpCache_in_requestTargetSocket_Granted.insert({param, _OpCache_with_parameter_in_requestTargetSocket_Granted});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_Granted, nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_Granted::HashEqual> _OpCache_with_parameter_in_requestTargetSocket_Granted = _OpCache_with_parameter_in_requestTargetSocket_Granted_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_in_requestTargetSocket_Granted.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_in_requestTargetSocket_Granted.end()) {
                            nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted writeState = writeState_ptr->second;
                            copiedState._apply_update_for_in_requestTargetSocket_Granted(writeState);
                        } else {
                            copiedState.in_requestTargetSocket_Granted(_tmp_10, _tmp_9, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_in_requestTargetSocket_Granted writeState = copiedState._update_for_in_requestTargetSocket_Granted();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_in_requestTargetSocket_Granted_lock(_ProjectionRead_in_requestTargetSocket_Granted_mutex);
                                _OpCache_with_parameter_in_requestTargetSocket_Granted.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "in_requestTargetSocket_Granted";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_in_requestTargetSocket_NotGranted read__tr_in_requestTargetSocket_NotGranted_state = state._projected_state_for__tr_in_requestTargetSocket_NotGranted();
                BSet<BTuple<BTuple<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::INTERCONNECTNODE >, nota_v2::SOCKET >, nota_v2::SID >, nota_v2::SID >> _trid_13;
                auto _trid_13_ptr = _OpCache_tr_in_requestTargetSocket_NotGranted.find(read__tr_in_requestTargetSocket_NotGranted_state);
                if(_trid_13_ptr == _OpCache_tr_in_requestTargetSocket_NotGranted.end()) {
                    _trid_13 = state._tr_in_requestTargetSocket_NotGranted();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_in_requestTargetSocket_NotGranted_lock(_ProjectionRead__tr_in_requestTargetSocket_NotGranted_mutex);
                        _OpCache_tr_in_requestTargetSocket_NotGranted.insert({read__tr_in_requestTargetSocket_NotGranted_state, _trid_13});
                    }
                } else {
                    _trid_13 = _trid_13_ptr->second;
                }

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
                    nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted readState = state._projected_state_for_in_requestTargetSocket_NotGranted();

                    auto _OpCache_with_parameter_in_requestTargetSocket_NotGranted_ptr = _OpCache_in_requestTargetSocket_NotGranted.find(param);
                    if(_OpCache_with_parameter_in_requestTargetSocket_NotGranted_ptr == _OpCache_in_requestTargetSocket_NotGranted.end()) {
                        copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                        nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted writeState = copiedState._update_for_in_requestTargetSocket_NotGranted();
                        std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::HashEqual> _OpCache_with_parameter_in_requestTargetSocket_NotGranted;
                        _OpCache_with_parameter_in_requestTargetSocket_NotGranted.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_in_requestTargetSocket_NotGranted_lock(_ProjectionRead_in_requestTargetSocket_NotGranted_mutex);
                            _OpCache_in_requestTargetSocket_NotGranted.insert({param, _OpCache_with_parameter_in_requestTargetSocket_NotGranted});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::Hash, nota_v2::_ProjectionRead_in_requestTargetSocket_NotGranted::HashEqual> _OpCache_with_parameter_in_requestTargetSocket_NotGranted = _OpCache_with_parameter_in_requestTargetSocket_NotGranted_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_in_requestTargetSocket_NotGranted.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_in_requestTargetSocket_NotGranted.end()) {
                            nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted writeState = writeState_ptr->second;
                            copiedState._apply_update_for_in_requestTargetSocket_NotGranted(writeState);
                        } else {
                            copiedState.in_requestTargetSocket_NotGranted(_tmp_8, _tmp_7, _tmp_5, _tmp_3, _tmp_1);
                            nota_v2::_ProjectionWrite_in_requestTargetSocket_NotGranted writeState = copiedState._update_for_in_requestTargetSocket_NotGranted();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_in_requestTargetSocket_NotGranted_lock(_ProjectionRead_in_requestTargetSocket_NotGranted_mutex);
                                _OpCache_with_parameter_in_requestTargetSocket_NotGranted.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "in_requestTargetSocket_NotGranted";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                nota_v2::_ProjectionRead__tr_svc_register read__tr_svc_register_state = state._projected_state_for__tr_svc_register();
                BSet<nota_v2::SERVICE> _trid_14;
                auto _trid_14_ptr = _OpCache_tr_svc_register.find(read__tr_svc_register_state);
                if(_trid_14_ptr == _OpCache_tr_svc_register.end()) {
                    _trid_14 = state._tr_svc_register();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__tr_svc_register_lock(_ProjectionRead__tr_svc_register_mutex);
                        _OpCache_tr_svc_register.insert({read__tr_svc_register_state, _trid_14});
                    }
                } else {
                    _trid_14 = _trid_14_ptr->second;
                }

                for(const nota_v2::SERVICE& param : _trid_14) {
                    nota_v2::SERVICE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    nota_v2::_ProjectionRead_svc_register readState = state._projected_state_for_svc_register();

                    auto _OpCache_with_parameter_svc_register_ptr = _OpCache_svc_register.find(param);
                    if(_OpCache_with_parameter_svc_register_ptr == _OpCache_svc_register.end()) {
                        copiedState.svc_register(_tmp_1);
                        nota_v2::_ProjectionWrite_svc_register writeState = copiedState._update_for_svc_register();
                        std::unordered_map<nota_v2::_ProjectionRead_svc_register, nota_v2::_ProjectionWrite_svc_register, nota_v2::_ProjectionRead_svc_register::Hash, nota_v2::_ProjectionRead_svc_register::HashEqual> _OpCache_with_parameter_svc_register;
                        _OpCache_with_parameter_svc_register.insert({readState, writeState});
                        {
                            std::unique_lock<std::mutex> _ProjectionRead_svc_register_lock(_ProjectionRead_svc_register_mutex);
                            _OpCache_svc_register.insert({param, _OpCache_with_parameter_svc_register});
                        }

                    } else {
                        std::unordered_map<nota_v2::_ProjectionRead_svc_register, nota_v2::_ProjectionWrite_svc_register, nota_v2::_ProjectionRead_svc_register::Hash, nota_v2::_ProjectionRead_svc_register::HashEqual> _OpCache_with_parameter_svc_register = _OpCache_with_parameter_svc_register_ptr->second;
                        auto writeState_ptr = _OpCache_with_parameter_svc_register.find(readState);
                        if(writeState_ptr != _OpCache_with_parameter_svc_register.end()) {
                            nota_v2::_ProjectionWrite_svc_register writeState = writeState_ptr->second;
                            copiedState._apply_update_for_svc_register(writeState);
                        } else {
                            copiedState.svc_register(_tmp_1);
                            nota_v2::_ProjectionWrite_svc_register writeState = copiedState._update_for_svc_register();
                            {
                                std::unique_lock<std::mutex> _ProjectionRead_svc_register_lock(_ProjectionRead_svc_register_mutex);
                                _OpCache_with_parameter_svc_register.insert({readState, writeState});
                            }
                        }
                    }

                    copiedState.stateAccessedVia = "svc_register";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            } else {
                BSet<nota_v2::INTERCONNECTNODE> _trid_1 = state._tr_constructor_interconnectNode();
                for(const nota_v2::INTERCONNECTNODE& param : _trid_1) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_interconnectNode(_tmp_1);
                    copiedState.stateAccessedVia = "constructor_interconnectNode";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<nota_v2::RESOURCEMANAGER> _trid_2 = state._tr_constructor_resourceManager();
                for(const nota_v2::RESOURCEMANAGER& param : _trid_2) {
                    nota_v2::RESOURCEMANAGER _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_resourceManager(_tmp_1);
                    copiedState.stateAccessedVia = "constructor_resourceManager";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_3 = state._tr_constructor_service();
                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_3) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.constructor_service(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "constructor_service";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
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
                    copiedState.stateAccessedVia = "constructor_socket";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_5 = state._tr_rm_register();
                for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_5) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_register(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "rm_register";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >> _trid_6 = state._tr_rm_deregister();
                for(const BTuple<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >, nota_v2::INTERCONNECTNODE >& param : _trid_6) {
                    nota_v2::INTERCONNECTNODE _tmp_1 = param.projection2();
                    BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_deregister(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "rm_deregister";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_7 = state._tr_rm_getSid();
                for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_7) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_getSid(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "rm_getSid";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >> _trid_8 = state._tr_rm_getSid_Not_Found();
                for(const BTuple<nota_v2::RESOURCEMANAGER, nota_v2::SERVICE >& param : _trid_8) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::RESOURCEMANAGER _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.rm_getSid_Not_Found(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "rm_getSid_Not_Found";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >> _trid_9 = state._tr_in_announceResourceManager();
                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::RESOURCEMANAGER >& param : _trid_9) {
                    nota_v2::RESOURCEMANAGER _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.in_announceResourceManager(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "in_announceResourceManager";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >> _trid_10 = state._tr_in_register_success();
                for(const BTuple<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >, nota_v2::SID >& param : _trid_10) {
                    nota_v2::SID _tmp_1 = param.projection2();
                    BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE > _tmp_2 = param.projection1();
                    nota_v2::SERVICE _tmp_3 = _tmp_2.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_4 = _tmp_2.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.in_register_success(_tmp_4, _tmp_3, _tmp_1);
                    copiedState.stateAccessedVia = "in_register_success";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >> _trid_11 = state._tr_in_register_failed();
                for(const BTuple<nota_v2::INTERCONNECTNODE, nota_v2::SERVICE >& param : _trid_11) {
                    nota_v2::SERVICE _tmp_1 = param.projection2();
                    nota_v2::INTERCONNECTNODE _tmp_2 = param.projection1();

                    nota_v2 copiedState = state._copy();
                    copiedState.in_register_failed(_tmp_2, _tmp_1);
                    copiedState.stateAccessedVia = "in_register_failed";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
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
                    copiedState.stateAccessedVia = "in_requestTargetSocket_Granted";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
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
                    copiedState.stateAccessedVia = "in_requestTargetSocket_NotGranted";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }
                BSet<nota_v2::SERVICE> _trid_14 = state._tr_svc_register();
                for(const nota_v2::SERVICE& param : _trid_14) {
                    nota_v2::SERVICE _tmp_1 = param;

                    nota_v2 copiedState = state._copy();
                    copiedState.svc_register(_tmp_1);
                    copiedState.stateAccessedVia = "svc_register";
                    result.insert(copiedState);
                    {
                        std::unique_lock<std::mutex> lock(mutex);
                        transitions += 1;
                    }
                }

            }
            return result;
        }

        bool invariantViolated(const nota_v2& state) {
            bool _check_inv_1;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_1 read__check_inv_1_state = state._projected_state_for__check_inv_1();
                auto _obj__check_inv_1_ptr = _InvCache__check_inv_1.find(read__check_inv_1_state);
                if(_obj__check_inv_1_ptr == _InvCache__check_inv_1.end()) {
                    _check_inv_1 = state._check_inv_1();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_1_lock(_ProjectionRead__check_inv_1_mutex);
                        _InvCache__check_inv_1.insert({read__check_inv_1_state, _check_inv_1});
                    }
                } else {
                    _check_inv_1 = _obj__check_inv_1_ptr->second;
                }
            } else {
                _check_inv_1 = state._check_inv_1();
            }
            if(!_check_inv_1) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_1" << "\n";
              return true;
            }
            bool _check_inv_2;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_2 read__check_inv_2_state = state._projected_state_for__check_inv_2();
                auto _obj__check_inv_2_ptr = _InvCache__check_inv_2.find(read__check_inv_2_state);
                if(_obj__check_inv_2_ptr == _InvCache__check_inv_2.end()) {
                    _check_inv_2 = state._check_inv_2();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_2_lock(_ProjectionRead__check_inv_2_mutex);
                        _InvCache__check_inv_2.insert({read__check_inv_2_state, _check_inv_2});
                    }
                } else {
                    _check_inv_2 = _obj__check_inv_2_ptr->second;
                }
            } else {
                _check_inv_2 = state._check_inv_2();
            }
            if(!_check_inv_2) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_2" << "\n";
              return true;
            }
            bool _check_inv_3;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_3 read__check_inv_3_state = state._projected_state_for__check_inv_3();
                auto _obj__check_inv_3_ptr = _InvCache__check_inv_3.find(read__check_inv_3_state);
                if(_obj__check_inv_3_ptr == _InvCache__check_inv_3.end()) {
                    _check_inv_3 = state._check_inv_3();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_3_lock(_ProjectionRead__check_inv_3_mutex);
                        _InvCache__check_inv_3.insert({read__check_inv_3_state, _check_inv_3});
                    }
                } else {
                    _check_inv_3 = _obj__check_inv_3_ptr->second;
                }
            } else {
                _check_inv_3 = state._check_inv_3();
            }
            if(!_check_inv_3) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_3" << "\n";
              return true;
            }
            bool _check_inv_4;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_4 read__check_inv_4_state = state._projected_state_for__check_inv_4();
                auto _obj__check_inv_4_ptr = _InvCache__check_inv_4.find(read__check_inv_4_state);
                if(_obj__check_inv_4_ptr == _InvCache__check_inv_4.end()) {
                    _check_inv_4 = state._check_inv_4();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_4_lock(_ProjectionRead__check_inv_4_mutex);
                        _InvCache__check_inv_4.insert({read__check_inv_4_state, _check_inv_4});
                    }
                } else {
                    _check_inv_4 = _obj__check_inv_4_ptr->second;
                }
            } else {
                _check_inv_4 = state._check_inv_4();
            }
            if(!_check_inv_4) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_4" << "\n";
              return true;
            }
            bool _check_inv_5;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_5 read__check_inv_5_state = state._projected_state_for__check_inv_5();
                auto _obj__check_inv_5_ptr = _InvCache__check_inv_5.find(read__check_inv_5_state);
                if(_obj__check_inv_5_ptr == _InvCache__check_inv_5.end()) {
                    _check_inv_5 = state._check_inv_5();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_5_lock(_ProjectionRead__check_inv_5_mutex);
                        _InvCache__check_inv_5.insert({read__check_inv_5_state, _check_inv_5});
                    }
                } else {
                    _check_inv_5 = _obj__check_inv_5_ptr->second;
                }
            } else {
                _check_inv_5 = state._check_inv_5();
            }
            if(!_check_inv_5) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_5" << "\n";
              return true;
            }
            bool _check_inv_6;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_6 read__check_inv_6_state = state._projected_state_for__check_inv_6();
                auto _obj__check_inv_6_ptr = _InvCache__check_inv_6.find(read__check_inv_6_state);
                if(_obj__check_inv_6_ptr == _InvCache__check_inv_6.end()) {
                    _check_inv_6 = state._check_inv_6();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_6_lock(_ProjectionRead__check_inv_6_mutex);
                        _InvCache__check_inv_6.insert({read__check_inv_6_state, _check_inv_6});
                    }
                } else {
                    _check_inv_6 = _obj__check_inv_6_ptr->second;
                }
            } else {
                _check_inv_6 = state._check_inv_6();
            }
            if(!_check_inv_6) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_6" << "\n";
              return true;
            }
            bool _check_inv_7;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_7 read__check_inv_7_state = state._projected_state_for__check_inv_7();
                auto _obj__check_inv_7_ptr = _InvCache__check_inv_7.find(read__check_inv_7_state);
                if(_obj__check_inv_7_ptr == _InvCache__check_inv_7.end()) {
                    _check_inv_7 = state._check_inv_7();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_7_lock(_ProjectionRead__check_inv_7_mutex);
                        _InvCache__check_inv_7.insert({read__check_inv_7_state, _check_inv_7});
                    }
                } else {
                    _check_inv_7 = _obj__check_inv_7_ptr->second;
                }
            } else {
                _check_inv_7 = state._check_inv_7();
            }
            if(!_check_inv_7) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_7" << "\n";
              return true;
            }
            bool _check_inv_8;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_8 read__check_inv_8_state = state._projected_state_for__check_inv_8();
                auto _obj__check_inv_8_ptr = _InvCache__check_inv_8.find(read__check_inv_8_state);
                if(_obj__check_inv_8_ptr == _InvCache__check_inv_8.end()) {
                    _check_inv_8 = state._check_inv_8();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_8_lock(_ProjectionRead__check_inv_8_mutex);
                        _InvCache__check_inv_8.insert({read__check_inv_8_state, _check_inv_8});
                    }
                } else {
                    _check_inv_8 = _obj__check_inv_8_ptr->second;
                }
            } else {
                _check_inv_8 = state._check_inv_8();
            }
            if(!_check_inv_8) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_8" << "\n";
              return true;
            }
            bool _check_inv_9;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_9 read__check_inv_9_state = state._projected_state_for__check_inv_9();
                auto _obj__check_inv_9_ptr = _InvCache__check_inv_9.find(read__check_inv_9_state);
                if(_obj__check_inv_9_ptr == _InvCache__check_inv_9.end()) {
                    _check_inv_9 = state._check_inv_9();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_9_lock(_ProjectionRead__check_inv_9_mutex);
                        _InvCache__check_inv_9.insert({read__check_inv_9_state, _check_inv_9});
                    }
                } else {
                    _check_inv_9 = _obj__check_inv_9_ptr->second;
                }
            } else {
                _check_inv_9 = state._check_inv_9();
            }
            if(!_check_inv_9) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_9" << "\n";
              return true;
            }
            bool _check_inv_10;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_10 read__check_inv_10_state = state._projected_state_for__check_inv_10();
                auto _obj__check_inv_10_ptr = _InvCache__check_inv_10.find(read__check_inv_10_state);
                if(_obj__check_inv_10_ptr == _InvCache__check_inv_10.end()) {
                    _check_inv_10 = state._check_inv_10();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_10_lock(_ProjectionRead__check_inv_10_mutex);
                        _InvCache__check_inv_10.insert({read__check_inv_10_state, _check_inv_10});
                    }
                } else {
                    _check_inv_10 = _obj__check_inv_10_ptr->second;
                }
            } else {
                _check_inv_10 = state._check_inv_10();
            }
            if(!_check_inv_10) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_10" << "\n";
              return true;
            }
            bool _check_inv_11;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_11 read__check_inv_11_state = state._projected_state_for__check_inv_11();
                auto _obj__check_inv_11_ptr = _InvCache__check_inv_11.find(read__check_inv_11_state);
                if(_obj__check_inv_11_ptr == _InvCache__check_inv_11.end()) {
                    _check_inv_11 = state._check_inv_11();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_11_lock(_ProjectionRead__check_inv_11_mutex);
                        _InvCache__check_inv_11.insert({read__check_inv_11_state, _check_inv_11});
                    }
                } else {
                    _check_inv_11 = _obj__check_inv_11_ptr->second;
                }
            } else {
                _check_inv_11 = state._check_inv_11();
            }
            if(!_check_inv_11) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_11" << "\n";
              return true;
            }
            bool _check_inv_12;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_12 read__check_inv_12_state = state._projected_state_for__check_inv_12();
                auto _obj__check_inv_12_ptr = _InvCache__check_inv_12.find(read__check_inv_12_state);
                if(_obj__check_inv_12_ptr == _InvCache__check_inv_12.end()) {
                    _check_inv_12 = state._check_inv_12();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_12_lock(_ProjectionRead__check_inv_12_mutex);
                        _InvCache__check_inv_12.insert({read__check_inv_12_state, _check_inv_12});
                    }
                } else {
                    _check_inv_12 = _obj__check_inv_12_ptr->second;
                }
            } else {
                _check_inv_12 = state._check_inv_12();
            }
            if(!_check_inv_12) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_12" << "\n";
              return true;
            }
            bool _check_inv_13;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_13 read__check_inv_13_state = state._projected_state_for__check_inv_13();
                auto _obj__check_inv_13_ptr = _InvCache__check_inv_13.find(read__check_inv_13_state);
                if(_obj__check_inv_13_ptr == _InvCache__check_inv_13.end()) {
                    _check_inv_13 = state._check_inv_13();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_13_lock(_ProjectionRead__check_inv_13_mutex);
                        _InvCache__check_inv_13.insert({read__check_inv_13_state, _check_inv_13});
                    }
                } else {
                    _check_inv_13 = _obj__check_inv_13_ptr->second;
                }
            } else {
                _check_inv_13 = state._check_inv_13();
            }
            if(!_check_inv_13) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_13" << "\n";
              return true;
            }
            bool _check_inv_14;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_14 read__check_inv_14_state = state._projected_state_for__check_inv_14();
                auto _obj__check_inv_14_ptr = _InvCache__check_inv_14.find(read__check_inv_14_state);
                if(_obj__check_inv_14_ptr == _InvCache__check_inv_14.end()) {
                    _check_inv_14 = state._check_inv_14();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_14_lock(_ProjectionRead__check_inv_14_mutex);
                        _InvCache__check_inv_14.insert({read__check_inv_14_state, _check_inv_14});
                    }
                } else {
                    _check_inv_14 = _obj__check_inv_14_ptr->second;
                }
            } else {
                _check_inv_14 = state._check_inv_14();
            }
            if(!_check_inv_14) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_14" << "\n";
              return true;
            }
            bool _check_inv_15;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_15 read__check_inv_15_state = state._projected_state_for__check_inv_15();
                auto _obj__check_inv_15_ptr = _InvCache__check_inv_15.find(read__check_inv_15_state);
                if(_obj__check_inv_15_ptr == _InvCache__check_inv_15.end()) {
                    _check_inv_15 = state._check_inv_15();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_15_lock(_ProjectionRead__check_inv_15_mutex);
                        _InvCache__check_inv_15.insert({read__check_inv_15_state, _check_inv_15});
                    }
                } else {
                    _check_inv_15 = _obj__check_inv_15_ptr->second;
                }
            } else {
                _check_inv_15 = state._check_inv_15();
            }
            if(!_check_inv_15) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_15" << "\n";
              return true;
            }
            bool _check_inv_16;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_16 read__check_inv_16_state = state._projected_state_for__check_inv_16();
                auto _obj__check_inv_16_ptr = _InvCache__check_inv_16.find(read__check_inv_16_state);
                if(_obj__check_inv_16_ptr == _InvCache__check_inv_16.end()) {
                    _check_inv_16 = state._check_inv_16();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_16_lock(_ProjectionRead__check_inv_16_mutex);
                        _InvCache__check_inv_16.insert({read__check_inv_16_state, _check_inv_16});
                    }
                } else {
                    _check_inv_16 = _obj__check_inv_16_ptr->second;
                }
            } else {
                _check_inv_16 = state._check_inv_16();
            }
            if(!_check_inv_16) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_16" << "\n";
              return true;
            }
            bool _check_inv_17;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_17 read__check_inv_17_state = state._projected_state_for__check_inv_17();
                auto _obj__check_inv_17_ptr = _InvCache__check_inv_17.find(read__check_inv_17_state);
                if(_obj__check_inv_17_ptr == _InvCache__check_inv_17.end()) {
                    _check_inv_17 = state._check_inv_17();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_17_lock(_ProjectionRead__check_inv_17_mutex);
                        _InvCache__check_inv_17.insert({read__check_inv_17_state, _check_inv_17});
                    }
                } else {
                    _check_inv_17 = _obj__check_inv_17_ptr->second;
                }
            } else {
                _check_inv_17 = state._check_inv_17();
            }
            if(!_check_inv_17) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_17" << "\n";
              return true;
            }
            bool _check_inv_18;
            if(isCaching) {
                nota_v2::_ProjectionRead__check_inv_18 read__check_inv_18_state = state._projected_state_for__check_inv_18();
                auto _obj__check_inv_18_ptr = _InvCache__check_inv_18.find(read__check_inv_18_state);
                if(_obj__check_inv_18_ptr == _InvCache__check_inv_18.end()) {
                    _check_inv_18 = state._check_inv_18();
                    {
                        std::unique_lock<std::mutex> _ProjectionRead__check_inv_18_lock(_ProjectionRead__check_inv_18_mutex);
                        _InvCache__check_inv_18.insert({read__check_inv_18_state, _check_inv_18});
                    }
                } else {
                    _check_inv_18 = _obj__check_inv_18_ptr->second;
                }
            } else {
                _check_inv_18 = state._check_inv_18();
            }
            if(!_check_inv_18) {
              cout << "INVARIANT CONJUNCT VIOLATED: _check_inv_18" << "\n";
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

    bool isDebug = true;
    // TODO

    ModelChecker modelchecker(type, threads, isCaching, isDebug);
    modelchecker.modelCheck();

    return 0;
}



#endif