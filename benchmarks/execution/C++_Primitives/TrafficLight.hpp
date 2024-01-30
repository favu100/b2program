#include <iostream>
#include <string>
#include <btypes_primitives/BUtils.hpp>
#include <btypes_primitives/StateNotReachableError.hpp>
#include <btypes_primitives/PreconditionOrAssertionViolation.hpp>
#include <btypes_primitives/BSet.hpp>
#include <btypes_primitives/BBoolean.hpp>
#include <btypes_primitives/BObject.hpp>

#ifndef TrafficLight_H
#define TrafficLight_H

using namespace std;

class TrafficLight {

    public:

        class colors : public BObject {
            public:

                typedef colors current_type;
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

                BBoolean equal(const colors& o) const {
                    return value == o.value;
                }

                BBoolean unequal(const colors& o) const {
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
                    return (31 * 1) ^ (static_cast<int>(value) << 1);
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
            if(((BBoolean(tl_cars.equal((colors(colors::red))).booleanValue() && tl_peds.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_cars = (colors(colors::redyellow));
            } else {
                throw StateNotReachableError();
            }

        }

        void cars_y() {
            if(((BBoolean(tl_cars.equal((colors(colors::green))).booleanValue() && tl_peds.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_cars = (colors(colors::yellow));
            } else {
                throw StateNotReachableError();
            }

        }

        void cars_g() {
            if(((BBoolean(tl_cars.equal((colors(colors::redyellow))).booleanValue() && tl_peds.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_cars = (colors(colors::green));
            } else {
                throw StateNotReachableError();
            }

        }

        void cars_r() {
            if(((BBoolean(tl_cars.equal((colors(colors::yellow))).booleanValue() && tl_peds.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_cars = (colors(colors::red));
            } else {
                throw StateNotReachableError();
            }

        }

        void peds_r() {
            if(((BBoolean(tl_peds.equal((colors(colors::green))).booleanValue() && tl_cars.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_peds = (colors(colors::red));
            } else {
                throw StateNotReachableError();
            }

        }

        void peds_g() {
            if(((BBoolean(tl_peds.equal((colors(colors::red))).booleanValue() && tl_cars.equal((colors(colors::red))).booleanValue()))).booleanValue()) {
                tl_peds = (colors(colors::green));
            } else {
                throw StateNotReachableError();
            }

        }

        colors getCars() {
            colors out;
            out = tl_cars;
            return out;
        }

        colors getPeds() {
            colors out;
            out = tl_peds;
            return out;
        }

        colors _get_tl_cars() const {
            return tl_cars;
        }

        colors _get_tl_peds() const {
            return tl_peds;
        }

        BSet<colors > _get__colors() const {
            return _colors;
        }

        friend std::ostream& operator<<(std::ostream &strm, const TrafficLight &machine) {
          strm << "_get_tl_cars: " << machine._get_tl_cars() << "\n";
          strm << "_get_tl_peds: " << machine._get_tl_peds() << "\n";
          return strm;
        }

};


#endif