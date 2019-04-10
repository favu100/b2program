#include <iostream>
#include <string>
#include <map>
#include "BObject.cpp"

#ifndef BRECORD_H
#define BRECORD_H

class BRecord : public BObject {

	private:
	    std::map<std::string, BObject> map;
	    int counter;

	public:
	    typedef void value_type;

        BRecord(const std::map<std::string, BObject>& map) {
            this->map = map;
            this->counter = map.size();
        }

        template<typename... Args>
        BRecord(const Args&... args) {
            this->map = std::map<std::string, BObject>();
            this->counter = 0;
            initialize_map(args...);
        }

        void initialize_map() {
        }

        template<typename... Args>
        void initialize_map(const BObject& value, const Args&... args) {
            this->map.insert(std::pair<std::string,BObject>(std::to_string(counter),value));
            this->counter++;
            initialize_map(args...);
        }

        BRecord() {
            this->map = std::map<std::string, BObject>();
            this->counter = 0;
        }

        int size() {
            return map.size();
        }

        bool isEmpty() {
            return map.empty();
        }

        /*
        bool containsKey(string key) {
            return map.find(key) != map.end();
        }

        bool containsValue(BObject value) {
            return map.containsValue(value);
        }
        */

        BObject get(std::string key) {
            return map[key];
        }

        BObject getAt(std::string key) {
            return map[key];
        }

        /*
        public BObject put(java.lang.String key, BObject value) {
            throw new UnsupportedOperationException();
        }

        public BObject putAt(java.lang.String key, Object value) {
            throw new UnsupportedOperationException();
        }

        public BObject remove(Object key) {
            throw new UnsupportedOperationException();
        }

        public void putAll(Map<? extends java.lang.String, ? extends BObject> m) {
            throw new UnsupportedOperationException();
        }

        public void clear() {
            throw new UnsupportedOperationException();
        }
        */

        /*
        public java.util.Set<java.lang.String> keySet() {
            return map.keySet();
        }

        public Collection<BObject> values() {
            return map.values();
        }

        public java.util.Set<Entry<java.lang.String, BObject>> entrySet() {
            return map.entrySet();
        }
        */

        friend bool operator !=(const BRecord& o1, const BRecord& o2) {
            return o1.map != o2.map;
        }

        friend bool operator ==(const BRecord& o1, const BRecord& o2) {
            return o1.map != o2.map;
        }

        int hashCode() {
            //TODO
            return 0;
        }

        //TODO: Implement << operator
        /*public java.lang.String toString() {
            Iterator<java.util.Map.Entry<java.lang.String, BObject>> it = this
                    .entrySet().iterator();
            StringBuffer sb = new StringBuffer();
            sb.append("rec(");
            while (it.hasNext()) {
                Map.Entry<java.lang.String, BObject> entry = (java.util.Map.Entry<java.lang.String, BObject>) it
                        .next();
                sb.append(entry.getKey());
                sb.append(": ");
                sb.append(entry.getValue());
                if (it.hasNext()) {
                    sb.append(", ");
                }
            }
            sb.append(")");
            return sb.toString();
        }*/

        /*
        public static Map<java.lang.String, BObject> newStorage() {
            return new LinkedHashMap<java.lang.String, BObject>();
        }*/
};
#endif
