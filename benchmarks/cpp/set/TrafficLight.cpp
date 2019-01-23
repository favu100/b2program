#include <iostream>
#include <string>
#include "BUtils.cpp"
#include "BSet.cpp"
#include "BObject.cpp"
#include "BBoolean.cpp"

#ifndef TrafficLight_H
#define TrafficLight_H

using namespace std;

class TrafficLight {

    class colors : public BObject {
        public:

            enum colors_type {
                red, 
                redyellow, 
                yellow, 
                green
            };

            colors_type value;

            colors(){}

            colors(colors_type type) {
                this->value = type;
            }

            BBoolean equal(const colors& o) {
                return value == o.value;
            }

            BBoolean unequal(const colors& o) {
                return value != o.value;
            }

            friend bool operator ==(const colors& p1, const colors& p2) {
                return p1.value == p2.value;
            }

            friend bool operator !=(const colors& p1, const colors& p2) {
                return p1.value != p2.value;
            }

            int hashCode() const {
                return static_cast<int>(value);
            }
    };


    private:


        #define _colors (BSet<colors >((colors(colors::red)), (colors(colors::redyellow)), (colors(colors::yellow)), (colors(colors::green))))

        colors tl_cars;
        colors tl_peds;

    public:

        TrafficLight() {
            tl_cars = (colors(colors::red));
            tl_peds = (colors(colors::red));
        }

        void cars_ry() {
            if((tl_cars.equal((colors(colors::red)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::redyellow));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

        void cars_y() {
            if((tl_cars.equal((colors(colors::green)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::yellow));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

        void cars_g() {
            if((tl_cars.equal((colors(colors::redyellow)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::green));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

        void cars_r() {
            if((tl_cars.equal((colors(colors::yellow)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::red));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

        void peds_r() {
            if((tl_peds.equal((colors(colors::green)))._and(tl_cars.equal((colors(colors::red))))).booleanValue()) {
                tl_peds = (colors(colors::red));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

        void peds_g() {
            if((tl_peds.equal((colors(colors::red)))._and(tl_cars.equal((colors(colors::red))))).booleanValue()) {
                tl_peds = (colors(colors::green));
            } else {
                throw runtime_error("Invocation of the operation is not possible");
            }
        }

};
#endif

