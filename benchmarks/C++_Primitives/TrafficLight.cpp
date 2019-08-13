#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BObject.hpp>
#include <btypes_primitives/BBoolean.hpp>

#ifndef TrafficLight_H
#define TrafficLight_H

using namespace std;

class TrafficLight {

    public:
        class colors : public BObject {
            public:

                typedef void value_type;
                typedef void left_type;
                typedef void right_type;

                enum colors_type {
                    red, 
                    redyellow, 
                    yellow, 
                    green
                };

                colors_type value;

                colors(){}

                colors(const colors_type& type) {
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

                void operator =(const colors& other) {
                    this->value = other.value;
                }

                friend std::ostream& operator<<(std::ostream &strm, const colors& e) {
                    switch(e.value) {
                        case red: return strm << "red";
                        case redyellow: return strm << "redyellow";
                        case yellow: return strm << "yellow";
                        case green: return strm << "green";
                    }
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
            }
        }

        void cars_y() {
            if((tl_cars.equal((colors(colors::green)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::yellow));
            }
        }

        void cars_g() {
            if((tl_cars.equal((colors(colors::redyellow)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::green));
            }
        }

        void cars_r() {
            if((tl_cars.equal((colors(colors::yellow)))._and(tl_peds.equal((colors(colors::red))))).booleanValue()) {
                tl_cars = (colors(colors::red));
            }
        }

        void peds_r() {
            if((tl_peds.equal((colors(colors::green)))._and(tl_cars.equal((colors(colors::red))))).booleanValue()) {
                tl_peds = (colors(colors::red));
            }
        }

        void peds_g() {
            if((tl_peds.equal((colors(colors::red)))._and(tl_cars.equal((colors(colors::red))))).booleanValue()) {
                tl_peds = (colors(colors::green));
            }
        }

};

#endif