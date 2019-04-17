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

                string name;

                colors(){}

                colors(colors_type type, string name) {
                    this->value = type;
                    this->name = name;
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

                friend std::ostream& operator<<(std::ostream &strm, const colors& e) {
                  return strm << e.name;
                }

                int hashCode() const {
                    return static_cast<int>(value);
                }
        };

    private:



        #define _colors (BSet<colors >((colors(colors::red, "red")), (colors(colors::redyellow, "redyellow")), (colors(colors::yellow, "yellow")), (colors(colors::green, "green"))))

        colors tl_cars;
        colors tl_peds;

    public:

        TrafficLight() {
            tl_cars = (colors(colors::red, "red"));
            tl_peds = (colors(colors::red, "red"));
        }

        void cars_ry() {
            if((tl_cars.equal((colors(colors::red, "red")))._and(tl_peds.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_cars = (colors(colors::redyellow, "redyellow"));
            }
        }

        void cars_y() {
            if((tl_cars.equal((colors(colors::green, "green")))._and(tl_peds.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_cars = (colors(colors::yellow, "yellow"));
            }
        }

        void cars_g() {
            if((tl_cars.equal((colors(colors::redyellow, "redyellow")))._and(tl_peds.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_cars = (colors(colors::green, "green"));
            }
        }

        void cars_r() {
            if((tl_cars.equal((colors(colors::yellow, "yellow")))._and(tl_peds.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_cars = (colors(colors::red, "red"));
            }
        }

        void peds_r() {
            if((tl_peds.equal((colors(colors::green, "green")))._and(tl_cars.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_peds = (colors(colors::red, "red"));
            }
        }

        void peds_g() {
            if((tl_peds.equal((colors(colors::red, "red")))._and(tl_cars.equal((colors(colors::red, "red"))))).booleanValue()) {
                tl_peds = (colors(colors::green, "green"));
            }
        }

};


#endif