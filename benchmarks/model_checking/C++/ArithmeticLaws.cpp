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
#include <btypes_primitives/BInteger.hpp>
#include <btypes_primitives/BTuple.hpp>

#ifndef ArithmeticLaws_H
#define ArithmeticLaws_H

using namespace std;

class ArithmeticLaws {

    public:

        enum Type { BFS, DFS, MIXED };



        struct Hash {
            public:
                size_t operator()(const ArithmeticLaws& obj) const {
                    return obj.hashCode();
                }
        };

        struct HashEqual {
            public:
                bool operator()(const ArithmeticLaws& obj1, const ArithmeticLaws& obj2) const {
                    if (obj1 == obj2)
                        return true;
                    else
                        return false;
                    }
            };

    private:




        BInteger x;
        BInteger y;
        BInteger z;


    public:

        ArithmeticLaws() {
            x = (BInteger(3)).negative();
            y = (BInteger(3)).negative();
            z = (BInteger(3)).negative();
        }

        ArithmeticLaws(const BInteger& x, const BInteger& y, const BInteger& z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        void IncX() {
            x = x.plus((BInteger(1)));

        }

        void IncY() {
            y = y.plus((BInteger(1)));

        }

        void IncZ() {
            z = z.plus((BInteger(1)));

        }

        void Reset() {
            x = (BInteger(3)).negative();
            y = (BInteger(3)).negative();
            z = (BInteger(3)).negative();
        }

        BInteger _get_x() const {
            return x;
        }

        BInteger _get_y() const {
            return y;
        }

        BInteger _get_z() const {
            return z;
        }


        bool _tr_IncX() const {
            return (x.less((BInteger(50)))).booleanValue();
        }

        bool _tr_IncY() const {
            return (y.less((BInteger(9)))).booleanValue();
        }

        bool _tr_IncZ() const {
            return (z.less((BInteger(4)))).booleanValue();
        }

        bool _tr_Reset() const {
            return true;
        }

        bool _check_inv_1() const {
            return ((x.isInteger())).booleanValue();
        }

        bool _check_inv_2() const {
            return ((y.isInteger())).booleanValue();
        }

        bool _check_inv_3() const {
            return ((z.isInteger())).booleanValue();
        }

        bool _check_inv_4() const {
            return (x.multiply(y).equal(y.multiply(x))).booleanValue();
        }

        bool _check_inv_5() const {
            return (x.multiply(y.plus(z)).equal(x.multiply(y).plus(x.multiply(z)))).booleanValue();
        }

        bool _check_inv_6() const {
            return (x.plus(y).equal(y.plus(x))).booleanValue();
        }

        bool _check_inv_7() const {
            return (x.multiply((BInteger(1))).equal(x)).booleanValue();
        }

        bool _check_inv_8() const {
            return ((BInteger(1)).multiply(x).equal(x)).booleanValue();
        }

        bool _check_inv_9() const {
            return (x.multiply((BInteger(0))).equal((BInteger(0)))).booleanValue();
        }

        bool _check_inv_10() const {
            return ((BInteger(0)).multiply(x).equal((BInteger(0)))).booleanValue();
        }

        bool _check_inv_11() const {
            return (x.plus(y).plus(z).equal(x.plus(y.plus(z)))).booleanValue();
        }

        bool _check_inv_12() const {
            return (x.multiply(y).multiply(z).equal(x.multiply(y.multiply(z)))).booleanValue();
        }

        bool _check_inv_13() const {
            return ((BInteger(2)).multiply(x).equal(x.plus(x))).booleanValue();
        }

        bool _check_inv_14() const {
            return (x.power((BInteger(2))).equal(x.multiply(x))).booleanValue();
        }

        bool _check_inv_15() const {
            return ((BBoolean(!x.greaterEqual((BInteger(0))).booleanValue() || (BBoolean((!x.divide((BInteger(2))).multiply((BInteger(2))).equal(x).booleanValue() || x.modulo((BInteger(2))).equal((BInteger(0))).booleanValue()) && (!x.modulo((BInteger(2))).equal((BInteger(0))).booleanValue() || x.divide((BInteger(2))).multiply((BInteger(2))).equal(x).booleanValue()))).booleanValue()))).booleanValue();
        }

        bool _check_inv_16() const {
            return ((BBoolean(!x.greater((BInteger(0))).booleanValue() || (BInteger(2)).power(x).equal((BInteger(2)).multiply((BInteger(2)).power(x.minus((BInteger(1)))))).booleanValue()))).booleanValue();
        }

        bool _check_inv_17() const {
            return ((BBoolean(!x.greater((BInteger(0))).booleanValue() || (BInteger(2)).power((BInteger(10)).multiply(x)).equal((BInteger(2)).multiply((BInteger(2)).power((BInteger(10)).multiply(x).minus((BInteger(1)))))).booleanValue()))).booleanValue();
        }

        bool _check_inv_18() const {
            return ((BBoolean(!x.greater((BInteger(0))).booleanValue() || (BInteger(3)).power((BInteger(10)).multiply(x)).equal((BInteger(3)).multiply((BInteger(3)).power((BInteger(10)).multiply(x).minus((BInteger(1)))))).booleanValue()))).booleanValue();
        }

        bool _check_inv_19() const {
            BSet<BInteger > _ic_set_4 = BSet<BInteger >();
            if(((BBoolean((BBoolean(x.greaterEqual((BInteger(0))).booleanValue() && y.greater((BInteger(0))).booleanValue())).booleanValue() && x.modulo(y).equal(x.minus(y.multiply(x.divide(y)))).booleanValue()))).booleanValue()) {
                for(BInteger _ic_q_1 : (BSet<BInteger>::interval((BInteger(0)),x))) {
                    if((x.less(y.multiply(_ic_q_1.plus((BInteger(1)))))).booleanValue()) {
                        _ic_set_4 = _ic_set_4._union(BSet<BInteger >(_ic_q_1));
                    }

                }
            }

            return ((BBoolean(!y.unequal((BInteger(0))).booleanValue() || (BBoolean((BBoolean(x.negative().divide(y).equal(x.divide(y).negative()).booleanValue() && x.divide(y.negative()).equal(x.divide(y).negative()).booleanValue())).booleanValue() && (BBoolean(!(BBoolean(x.greaterEqual((BInteger(0))).booleanValue() && y.greater((BInteger(0))).booleanValue())).booleanValue() || (BBoolean(x.modulo(y).equal(x.minus(y.multiply(x.divide(y)))).booleanValue() && x.divide(y).equal(_ic_set_4.min()).booleanValue())).booleanValue())).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _check_inv_20() const {
            return ((BBoolean(x.greater(y).booleanValue() || x.lessEqual(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_21() const {
            return ((BBoolean((BBoolean(x.greater(y).booleanValue() || x.equal(y).booleanValue())).booleanValue() || x.less(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_22() const {
            return ((BBoolean(x.greaterEqual(y).booleanValue() || x.less(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_23() const {
            return ((BBoolean(x.greaterEqual(y).booleanValue() || x.lessEqual(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_24() const {
            return ((BBoolean(x.greater(y).booleanValue() && x.lessEqual(y).booleanValue()))._not()).booleanValue();
        }

        bool _check_inv_25() const {
            return ((BBoolean(x.less(y).booleanValue() && y.less(x).booleanValue()))._not()).booleanValue();
        }

        bool _check_inv_26() const {
            return (x.minus(x).equal((BInteger(0)))).booleanValue();
        }

        bool _check_inv_27() const {
            return ((BBoolean((!x.equal(y).booleanValue() || x.minus(y).equal((BInteger(0))).booleanValue()) && (!x.minus(y).equal((BInteger(0))).booleanValue() || x.equal(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_28() const {
            return ((BBoolean((!x.greater(y).booleanValue() || x.greaterEqual(y.plus((BInteger(1)))).booleanValue()) && (!x.greaterEqual(y.plus((BInteger(1)))).booleanValue() || x.greater(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_29() const {
            return ((BBoolean((!x.less(y).booleanValue() || x.lessEqual(y.minus((BInteger(1)))).booleanValue()) && (!x.lessEqual(y.minus((BInteger(1)))).booleanValue() || x.less(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_30() const {
            return ((BBoolean((!(BBoolean(x.less(y).booleanValue() || y.less(x).booleanValue())).booleanValue() || x.unequal(y).booleanValue()) && (!x.unequal(y).booleanValue() || (BBoolean(x.less(y).booleanValue() || y.less(x).booleanValue())).booleanValue())))).booleanValue();
        }

        bool _check_inv_31() const {
            return ((BBoolean(!(BBoolean(x.less(y).booleanValue() && y.lessEqual(z).booleanValue())).booleanValue() || x.less(z).booleanValue()))).booleanValue();
        }

        bool _check_inv_32() const {
            return ((BBoolean(!(BBoolean(x.less(y).booleanValue() && y.less(z).booleanValue())).booleanValue() || x.less(z).booleanValue()))).booleanValue();
        }

        bool _check_inv_33() const {
            return ((BBoolean(!(BBoolean(x.lessEqual(y).booleanValue() && y.less(z).booleanValue())).booleanValue() || x.less(z).booleanValue()))).booleanValue();
        }

        bool _check_inv_34() const {
            return ((BBoolean(!(BBoolean(x.lessEqual(y).booleanValue() && y.lessEqual(z).booleanValue())).booleanValue() || x.lessEqual(z).booleanValue()))).booleanValue();
        }

        bool _check_inv_35() const {
            return ((BBoolean(!(BBoolean(x.lessEqual(y).booleanValue() && y.lessEqual(x).booleanValue())).booleanValue() || x.equal(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_36() const {
            return ((BBoolean((!x.equal(y).booleanValue() || y.equal(x).booleanValue()) && (!y.equal(x).booleanValue() || x.equal(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_37() const {
            return ((BBoolean((!x.unequal(y).booleanValue() || y.unequal(x).booleanValue()) && (!y.unequal(x).booleanValue() || x.unequal(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_38() const {
            return ((BBoolean((!x.less(y).booleanValue() || y.greater(x).booleanValue()) && (!y.greater(x).booleanValue() || x.less(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_39() const {
            return ((BBoolean((!x.greater(y).booleanValue() || y.less(x).booleanValue()) && (!y.less(x).booleanValue() || x.greater(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_40() const {
            return ((BBoolean((!x.lessEqual(y).booleanValue() || y.greaterEqual(x).booleanValue()) && (!y.greaterEqual(x).booleanValue() || x.lessEqual(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_41() const {
            return ((BBoolean((!x.greaterEqual(y).booleanValue() || y.lessEqual(x).booleanValue()) && (!y.lessEqual(x).booleanValue() || x.greaterEqual(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_42() const {
            return ((BBoolean((!x.less(y)._not().booleanValue() || x.greaterEqual(y).booleanValue()) && (!x.greaterEqual(y).booleanValue() || x.less(y)._not().booleanValue())))).booleanValue();
        }

        bool _check_inv_43() const {
            return ((BBoolean((!x.lessEqual(y)._not().booleanValue() || x.greater(y).booleanValue()) && (!x.greater(y).booleanValue() || x.lessEqual(y)._not().booleanValue())))).booleanValue();
        }

        bool _check_inv_44() const {
            return ((BBoolean(!(BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue())).booleanValue() || (BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _check_inv_45() const {
            return ((BBoolean((!(BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue())).booleanValue() || (BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue())).booleanValue()) && (!(BBoolean(y.equal(x).booleanValue() || z.equal(x).booleanValue())).booleanValue() || (BBoolean(x.equal(y).booleanValue() || x.equal(z).booleanValue())).booleanValue())))).booleanValue();
        }

        bool _check_inv_46() const {
            return ((BBoolean(!(BBoolean((!x.equal(y).booleanValue() || x.equal(z).booleanValue()) && (!x.equal(z).booleanValue() || x.equal(y).booleanValue()))).booleanValue() || (BBoolean(y.equal(z).booleanValue() || x.unequal(y).booleanValue())).booleanValue()))).booleanValue();
        }

        bool _check_inv_47() const {
            return (x.minus(y).minus(x).plus(y).equal((BInteger(0)))).booleanValue();
        }

        bool _check_inv_48() const {
            return (x.multiply(x).greaterEqual((BInteger(0)))).booleanValue();
        }

        bool _check_inv_49() const {
            return ((BBoolean((!x.multiply(x).equal((BInteger(0))).booleanValue() || x.equal((BInteger(0))).booleanValue()) && (!x.equal((BInteger(0))).booleanValue() || x.multiply(x).equal((BInteger(0))).booleanValue())))).booleanValue();
        }

        bool _check_inv_50() const {
            return (x.multiply(x).equal(x.negative().multiply(x.negative()))).booleanValue();
        }

        bool _check_inv_51() const {
            return ((BBoolean((!x.lessEqual(y).booleanValue() || (BSet<BInteger >(x, y)).min().equal(x).booleanValue()) && (!(BSet<BInteger >(x, y)).min().equal(x).booleanValue() || x.lessEqual(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_52() const {
            return ((BBoolean((!x.lessEqual(y).booleanValue() || (BSet<BInteger >(x, y)).max().equal(y).booleanValue()) && (!(BSet<BInteger >(x, y)).max().equal(y).booleanValue() || x.lessEqual(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_53() const {
            return ((BBoolean((!x.less(y).booleanValue() || (BSet<BInteger >(x, y)).max().unequal(x).booleanValue()) && (!(BSet<BInteger >(x, y)).max().unequal(x).booleanValue() || x.less(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_54() const {
            return ((BBoolean((!x.less(y).booleanValue() || (BSet<BInteger >(x, y)).min().unequal(y).booleanValue()) && (!(BSet<BInteger >(x, y)).min().unequal(y).booleanValue() || x.less(y).booleanValue())))).booleanValue();
        }

        bool _check_inv_55() const {
            return ((BBoolean(!(BBoolean(x.greaterEqual((BInteger(0))).booleanValue() && y.greater((BInteger(0))).booleanValue())).booleanValue() || x.divide(y).multiply(y).equal(x.minus(x.modulo(y))).booleanValue()))).booleanValue();
        }

        bool _check_inv_56() const {
            BInteger _ic_integer_5 = BInteger(0);
            if(((BBoolean((BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue())).booleanValue() && y.unequal(z).booleanValue()))).booleanValue()) {
                for(BInteger _ic_zz_1 : (BSet<BInteger >(x, y, z))) {
                    _ic_integer_5 = _ic_integer_5.plus(_ic_zz_1);

                }
            }

            return ((BBoolean(!(BBoolean((BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue())).booleanValue() && y.unequal(z).booleanValue())).booleanValue() || _ic_integer_5.equal(x.plus(y).plus(z)).booleanValue()))).booleanValue();
        }

        bool _check_inv_57() const {
            BInteger _ic_integer_6 = BInteger(1);
            if(((BBoolean((BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue())).booleanValue() && y.unequal(z).booleanValue()))).booleanValue()) {
                for(BInteger _ic_zz_1 : (BSet<BInteger >(x, y, z))) {
                    _ic_integer_6 = _ic_integer_6.multiply(_ic_zz_1);

                }
            }

            return ((BBoolean(!(BBoolean((BBoolean(x.unequal(y).booleanValue() && x.unequal(z).booleanValue())).booleanValue() && y.unequal(z).booleanValue())).booleanValue() || _ic_integer_6.equal(x.multiply(y).multiply(z)).booleanValue()))).booleanValue();
        }

        bool _check_inv_58() const {
            BInteger _ic_integer_7 = BInteger(0);
            for(BInteger _ic_zz_1 : (BSet<BInteger >(x))) {
                _ic_integer_7 = _ic_integer_7.plus(_ic_zz_1);

            }

            return (_ic_integer_7.equal(x)).booleanValue();
        }

        bool _check_inv_59() const {
            BInteger _ic_integer_8 = BInteger(1);
            for(BInteger _ic_zz_1 : (BSet<BInteger >(x))) {
                _ic_integer_8 = _ic_integer_8.multiply(_ic_zz_1);

            }

            return (_ic_integer_8.equal(x)).booleanValue();
        }

        bool _check_inv_60() const {
            return (x.succ().equal(x.plus((BInteger(1))))).booleanValue();
        }

        bool _check_inv_61() const {
            return (x.pred().equal(x.minus((BInteger(1))))).booleanValue();
        }

        bool _check_inv_62() const {
            return (x.less(x.succ())).booleanValue();
        }

        bool _check_inv_63() const {
            return (x.greater(x.pred())).booleanValue();
        }

        bool _check_inv_64() const {
            return (x.succ().pred().equal(x)).booleanValue();
        }

        bool _check_inv_65() const {
            return (x.plus(y.succ()).equal(x.plus(y).succ())).booleanValue();
        }

        bool _check_inv_66() const {
            return (x.multiply(y.succ()).equal(x.plus(x.multiply(y)))).booleanValue();
        }

        bool _check_inv_67() const {
            return ((BBoolean(!x.greaterEqual((BInteger(0))).booleanValue() || (BInteger(1)).power(x).equal((BInteger(1))).booleanValue()))).booleanValue();
        }

        bool _check_inv_68() const {
            return (x.power((BInteger(1))).equal(x)).booleanValue();
        }

        bool _check_inv_69() const {
            return (x.power((BInteger(0))).equal((BInteger(1)))).booleanValue();
        }

        bool _check_inv_70() const {
            return ((BBoolean(!x.greater((BInteger(0))).booleanValue() || (BInteger(0)).power(x).equal((BInteger(0))).booleanValue()))).booleanValue();
        }

        bool _check_inv_71() const {
            return ((BBoolean(!z.greaterEqual((BInteger(0))).booleanValue() || x.multiply(y).power(z).equal(x.power(z).multiply(y.power(z))).booleanValue()))).booleanValue();
        }

        bool _check_inv_72() const {
            return ((BBoolean(!(BBoolean(y.greaterEqual((BInteger(0))).booleanValue() && z.greaterEqual((BInteger(0))).booleanValue())).booleanValue() || x.power(y.plus(z)).equal(x.power(y).multiply(x.power(z))).booleanValue()))).booleanValue();
        }

        bool _check_inv_73() const {
            return ((BBoolean(!(BBoolean(y.greaterEqual((BInteger(0))).booleanValue() && z.greaterEqual((BInteger(0))).booleanValue())).booleanValue() || x.power(y.multiply(z)).equal(x.power(y).power(z)).booleanValue()))).booleanValue();
        }

        bool _check_inv_74() const {
            return ((BSet<BInteger >(x)).min().equal(x)).booleanValue();
        }

        bool _check_inv_75() const {
            return ((BBoolean(!x.lessEqual(y).booleanValue() || (BSet<BInteger >(x, y)).min().equal(x).booleanValue()))).booleanValue();
        }

        bool _check_inv_76() const {
            return ((BBoolean(!y.lessEqual(x).booleanValue() || (BSet<BInteger >(x, y)).min().equal(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_77() const {
            return ((BSet<BInteger >(x))._union((BSet<BInteger >(y, z))).min().equal((BSet<BInteger >((BSet<BInteger >(x)).min(), (BSet<BInteger >(y, z)).min())).min())).booleanValue();
        }

        bool _check_inv_78() const {
            return ((BSet<BInteger >(y, z))._union((BSet<BInteger >(x))).min().equal((BSet<BInteger >((BSet<BInteger >(y, z)).min(), x)).min())).booleanValue();
        }

        bool _check_inv_79() const {
            return ((BSet<BInteger >(x)).max().equal(x)).booleanValue();
        }

        bool _check_inv_80() const {
            return ((BBoolean(!y.lessEqual(x).booleanValue() || (BSet<BInteger >(x, y)).max().equal(x).booleanValue()))).booleanValue();
        }

        bool _check_inv_81() const {
            return ((BBoolean(!x.lessEqual(y).booleanValue() || (BSet<BInteger >(x, y)).max().equal(y).booleanValue()))).booleanValue();
        }

        bool _check_inv_82() const {
            return ((BSet<BInteger >(x))._union((BSet<BInteger >(y, z))).max().equal((BSet<BInteger >((BSet<BInteger >(x)).max(), (BSet<BInteger >(y, z)).max())).max())).booleanValue();
        }

        bool _check_inv_83() const {
            return ((BSet<BInteger >(y, z))._union((BSet<BInteger >(x))).max().equal((BSet<BInteger >((BSet<BInteger >(y, z)).max(), x)).max())).booleanValue();
        }

        ArithmeticLaws _copy() const {
            return ArithmeticLaws(x, y, z);
        }

        friend bool operator ==(const ArithmeticLaws& o1, const ArithmeticLaws& o2) {
            return o1._get_x() == o2._get_x() && o1._get_y() == o2._get_y() && o1._get_z() == o2._get_z();
        }

        friend bool operator !=(const ArithmeticLaws& o1, const ArithmeticLaws& o2) {
            return o1._get_x() != o2._get_x() || o1._get_y() != o2._get_y() || o1._get_z() != o2._get_z();
        }

        int hashCode() const {
            return this->_hashCode_1();
        }

        int _hashCode_1() const {
            int result = 1;
            result = (1543 * result) ^ ((this->_get_x()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_y()).hashCode() << 1);
            result = (1543 * result) ^ ((this->_get_z()).hashCode() << 1);
            return result;
        }

        int _hashCode_2() const {
            int result = 1;
            result = (6151 * result) ^ ((this->_get_x()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_y()).hashCode() << 1);
            result = (6151 * result) ^ ((this->_get_z()).hashCode() << 1);
            return result;
        }

        friend std::ostream& operator<<(std::ostream &strm, const ArithmeticLaws &machine) {
          strm << "_get_x: " << machine._get_x() << "\n";
          strm << "_get_y: " << machine._get_y() << "\n";
          strm << "_get_z: " << machine._get_z() << "\n";
          return strm;
        }


};


static std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> generateNextStates(std::mutex& guardMutex, const ArithmeticLaws& state, bool isCaching, std::unordered_map<string, std::unordered_set<string>>& invariantDependency, std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& dependentInvariant, std::unordered_map<string, std::unordered_set<string>>& guardDependency, std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& dependentGuard, std::unordered_map<ArithmeticLaws, immer::map<string, boost::any>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& guardCache, std::unordered_map<ArithmeticLaws, ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& parents, std::unordered_map<ArithmeticLaws, string, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& stateAccessedVia, std::atomic<int>& transitions) {
    std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> result = std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>();
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
        bool _trid_1;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_IncX"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_IncX") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_1 = state._tr_IncX();
        } else {
            _trid_1 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_IncX", _trid_1);
        if(_trid_1) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncX();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["IncX"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["IncX"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncX"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_2;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_IncY"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_IncY") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_2 = state._tr_IncY();
        } else {
            _trid_2 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_IncY", _trid_2);
        if(_trid_2) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncY();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["IncY"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["IncY"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncY"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_3;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_IncZ"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_IncZ") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_3 = state._tr_IncZ();
        } else {
            _trid_3 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_IncZ", _trid_3);
        if(_trid_3) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncZ();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["IncZ"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["IncZ"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncZ"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        bool _trid_4;
        if(dependentGuardsExist) {
            cachedValue = parentsGuard["_tr_Reset"];
            dependentGuardsBoolean = (dependentGuardsOfState.find("_tr_Reset") != dependentGuardsOfState.end());
        }
        if(dependentGuardsExist || dependentGuardsBoolean || parentsExist) {
            _trid_4 = state._tr_Reset();
        } else {
            _trid_4 = boost::any_cast<bool>(cachedValue);
        }
        newCache = newCache.set("_tr_Reset", _trid_4);
        if(_trid_4) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.Reset();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(dependentInvariant.find(copiedState) == dependentInvariant.end()) {
                    dependentInvariant.insert({copiedState, invariantDependency["Reset"]});
                }
                if(dependentGuard.find(copiedState) == dependentGuard.end()) {
                    dependentGuard.insert({copiedState, guardDependency["Reset"]});
                }
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "Reset"});
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
        if(state._tr_IncX()) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncX();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncX"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_IncY()) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncY();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncY"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_IncZ()) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.IncZ();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "IncZ"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }
        if(state._tr_Reset()) {
            ArithmeticLaws copiedState = state._copy();
            copiedState.Reset();
            {
                std::unique_lock<std::mutex> lock(guardMutex);
                if(parents.find(copiedState) == parents.end()) {
                    parents.insert({copiedState, state});
                }
                if(stateAccessedVia.find(copiedState) == stateAccessedVia.end()) {
                    stateAccessedVia.insert({copiedState, "Reset"});
                }
            }
            result.insert(copiedState);
            transitions += 1;
        }

    }
    return result;
}

static void printResult(int states, int transitions, bool deadlockDetected, bool invariantViolated, ArithmeticLaws& counterExampleState, std::unordered_map<ArithmeticLaws, ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& parents, std::unordered_map<ArithmeticLaws, string, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& stateAccessedVia) {
    if(deadlockDetected || invariantViolated) {
        if(deadlockDetected) {
            cout << "DEADLOCK DETECTED" << "\n";
        }
        if(invariantViolated) {
            cout << "INVARIANT VIOLATED" << "\n";
        }
        cout << "COUNTER EXAMPLE TRACE: " << "\n";

        ArithmeticLaws currentState = counterExampleState;
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

static bool checkInvariants(std::mutex& guardMutex, const ArithmeticLaws& state, bool isCaching, std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>& dependentInvariant) {
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
        if(dependentInvariantsOfState.find("_check_inv_19") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_19()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_20") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_20()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_21") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_21()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_22") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_22()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_23") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_23()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_24") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_24()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_25") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_25()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_26") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_26()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_27") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_27()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_28") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_28()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_29") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_29()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_30") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_30()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_31") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_31()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_32") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_32()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_33") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_33()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_34") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_34()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_35") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_35()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_36") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_36()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_37") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_37()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_38") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_38()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_39") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_39()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_40") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_40()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_41") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_41()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_42") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_42()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_43") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_43()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_44") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_44()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_45") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_45()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_46") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_46()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_47") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_47()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_48") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_48()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_49") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_49()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_50") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_50()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_51") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_51()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_52") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_52()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_53") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_53()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_54") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_54()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_55") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_55()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_56") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_56()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_57") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_57()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_58") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_58()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_59") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_59()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_60") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_60()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_61") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_61()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_62") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_62()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_63") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_63()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_64") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_64()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_65") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_65()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_66") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_66()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_67") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_67()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_68") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_68()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_69") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_69()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_70") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_70()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_71") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_71()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_72") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_72()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_73") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_73()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_74") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_74()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_75") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_75()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_76") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_76()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_77") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_77()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_78") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_78()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_79") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_79()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_80") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_80()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_81") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_81()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_82") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_82()) {
                return false;
            }
        }
        if(dependentInvariantsOfState.find("_check_inv_83") == dependentInvariantsOfState.end()) {
            if(!state._check_inv_83()) {
                return false;
            }
        }
        return true;
    }
    return !(!state._check_inv_1() || !state._check_inv_2() || !state._check_inv_3() || !state._check_inv_4() || !state._check_inv_5() || !state._check_inv_6() || !state._check_inv_7() || !state._check_inv_8() || !state._check_inv_9() || !state._check_inv_10() || !state._check_inv_11() || !state._check_inv_12() || !state._check_inv_13() || !state._check_inv_14() || !state._check_inv_15() || !state._check_inv_16() || !state._check_inv_17() || !state._check_inv_18() || !state._check_inv_19() || !state._check_inv_20() || !state._check_inv_21() || !state._check_inv_22() || !state._check_inv_23() || !state._check_inv_24() || !state._check_inv_25() || !state._check_inv_26() || !state._check_inv_27() || !state._check_inv_28() || !state._check_inv_29() || !state._check_inv_30() || !state._check_inv_31() || !state._check_inv_32() || !state._check_inv_33() || !state._check_inv_34() || !state._check_inv_35() || !state._check_inv_36() || !state._check_inv_37() || !state._check_inv_38() || !state._check_inv_39() || !state._check_inv_40() || !state._check_inv_41() || !state._check_inv_42() || !state._check_inv_43() || !state._check_inv_44() || !state._check_inv_45() || !state._check_inv_46() || !state._check_inv_47() || !state._check_inv_48() || !state._check_inv_49() || !state._check_inv_50() || !state._check_inv_51() || !state._check_inv_52() || !state._check_inv_53() || !state._check_inv_54() || !state._check_inv_55() || !state._check_inv_56() || !state._check_inv_57() || !state._check_inv_58() || !state._check_inv_59() || !state._check_inv_60() || !state._check_inv_61() || !state._check_inv_62() || !state._check_inv_63() || !state._check_inv_64() || !state._check_inv_65() || !state._check_inv_66() || !state._check_inv_67() || !state._check_inv_68() || !state._check_inv_69() || !state._check_inv_70() || !state._check_inv_71() || !state._check_inv_72() || !state._check_inv_73() || !state._check_inv_74() || !state._check_inv_75() || !state._check_inv_76() || !state._check_inv_77() || !state._check_inv_78() || !state._check_inv_79() || !state._check_inv_80() || !state._check_inv_81() || !state._check_inv_82() || !state._check_inv_83());
}

static ArithmeticLaws next(std::list<ArithmeticLaws>& collection, std::mutex& mutex, ArithmeticLaws::Type type) {
    std::unique_lock<std::mutex> lock(mutex);
    switch(type) {
        case ArithmeticLaws::BFS: {
            ArithmeticLaws state = collection.front();
            collection.pop_front();
            return state;
        }
        case ArithmeticLaws::DFS: {
            ArithmeticLaws state = collection.back();
            collection.pop_back();
            return state;
        }
        case ArithmeticLaws::MIXED: {
            if(collection.size() % 2 == 0) {
                ArithmeticLaws state = collection.front();
                collection.pop_front();
                return state;
            } else {
                ArithmeticLaws state = collection.back();
                collection.pop_back();
                return state;
            }
        }
    };
}

static void modelCheckSingleThreaded(ArithmeticLaws::Type type, bool isCaching) {
    std::mutex mutex;
    std::mutex guardMutex;

    ArithmeticLaws machine = ArithmeticLaws();

    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> states = std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<ArithmeticLaws> collection = std::list<ArithmeticLaws>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> dependentInvariant;
    std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> dependentGuard;
    std::unordered_map<ArithmeticLaws, immer::map<string, boost::any>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> guardCache;
    std::unordered_map<ArithmeticLaws, ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> parents;
    std::unordered_map<ArithmeticLaws, string, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"IncX", {"_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_50", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70"}});
        invariantDependency.insert({"IncY", {"_check_inv_19", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_6", "_check_inv_43", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_45", "_check_inv_44", "_check_inv_2", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_25", "_check_inv_24", "_check_inv_23", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71"}});
        invariantDependency.insert({"Reset", {"_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_2", "_check_inv_50", "_check_inv_3", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70"}});
        invariantDependency.insert({"IncZ", {"_check_inv_32", "_check_inv_31", "_check_inv_5", "_check_inv_73", "_check_inv_57", "_check_inv_46", "_check_inv_12", "_check_inv_56", "_check_inv_45", "_check_inv_34", "_check_inv_78", "_check_inv_11", "_check_inv_44", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_72", "_check_inv_3", "_check_inv_82", "_check_inv_71"}});
        guardDependency.insert({"IncX", {"_tr_IncX"}});
        guardDependency.insert({"IncY", {"_tr_IncY"}});
        guardDependency.insert({"Reset", {"_tr_IncX", "_tr_IncY", "_tr_IncZ"}});
        guardDependency.insert({"IncZ", {"_tr_IncZ"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    ArithmeticLaws counterExampleState;

    while(!collection.empty() && !stopThreads) {
        ArithmeticLaws state = next(collection, mutex, type);

        std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);
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

static void modelCheckMultiThreaded(ArithmeticLaws::Type type, int threads, bool isCaching) {
    std::mutex mutex;
    std::mutex waitMutex;
    std::mutex guardMutex;
    std::condition_variable waitCV;

    ArithmeticLaws machine = ArithmeticLaws();


    std::atomic<bool> invariantViolated;
    invariantViolated = false;
    std::atomic<bool> deadlockDetected;
    deadlockDetected = false;
    std::atomic<bool> stopThreads;
    stopThreads = false;

    std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> states = std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual>();
    states.insert(machine);
    std::atomic<int> numberStates;
    numberStates = 1;

    std::list<ArithmeticLaws> collection = std::list<ArithmeticLaws>();
    collection.push_back(machine);

    std::atomic<int> transitions;
    transitions = 0;

    std::atomic<int> possibleQueueChanges;
    possibleQueueChanges = 0;

    std::atomic<bool> waitFlag;
    waitFlag = true;

    std::unordered_map<string, std::unordered_set<string>> invariantDependency;
    std::unordered_map<string, std::unordered_set<string>> guardDependency;
    std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> dependentInvariant;
    std::unordered_map<ArithmeticLaws, std::unordered_set<string>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> dependentGuard;
    std::unordered_map<ArithmeticLaws, immer::map<string, boost::any>, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> guardCache;
    std::unordered_map<ArithmeticLaws, ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> parents;
    std::unordered_map<ArithmeticLaws, string, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> stateAccessedVia;
    if(isCaching) {
        invariantDependency.insert({"IncX", {"_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_50", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70"}});
        invariantDependency.insert({"IncY", {"_check_inv_19", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_6", "_check_inv_43", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_45", "_check_inv_44", "_check_inv_2", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_25", "_check_inv_24", "_check_inv_23", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71"}});
        invariantDependency.insert({"Reset", {"_check_inv_18", "_check_inv_17", "_check_inv_16", "_check_inv_15", "_check_inv_59", "_check_inv_19", "_check_inv_10", "_check_inv_54", "_check_inv_53", "_check_inv_52", "_check_inv_51", "_check_inv_14", "_check_inv_58", "_check_inv_13", "_check_inv_57", "_check_inv_12", "_check_inv_56", "_check_inv_11", "_check_inv_55", "_check_inv_61", "_check_inv_60", "_check_inv_49", "_check_inv_48", "_check_inv_6", "_check_inv_43", "_check_inv_7", "_check_inv_42", "_check_inv_4", "_check_inv_41", "_check_inv_5", "_check_inv_40", "_check_inv_47", "_check_inv_46", "_check_inv_8", "_check_inv_45", "_check_inv_9", "_check_inv_44", "_check_inv_2", "_check_inv_50", "_check_inv_3", "_check_inv_1", "_check_inv_39", "_check_inv_38", "_check_inv_37", "_check_inv_32", "_check_inv_76", "_check_inv_31", "_check_inv_75", "_check_inv_30", "_check_inv_74", "_check_inv_73", "_check_inv_36", "_check_inv_35", "_check_inv_79", "_check_inv_34", "_check_inv_78", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_82", "_check_inv_81", "_check_inv_80", "_check_inv_29", "_check_inv_28", "_check_inv_27", "_check_inv_26", "_check_inv_21", "_check_inv_65", "_check_inv_20", "_check_inv_64", "_check_inv_63", "_check_inv_62", "_check_inv_25", "_check_inv_69", "_check_inv_24", "_check_inv_68", "_check_inv_23", "_check_inv_67", "_check_inv_22", "_check_inv_66", "_check_inv_72", "_check_inv_71", "_check_inv_70"}});
        invariantDependency.insert({"IncZ", {"_check_inv_32", "_check_inv_31", "_check_inv_5", "_check_inv_73", "_check_inv_57", "_check_inv_46", "_check_inv_12", "_check_inv_56", "_check_inv_45", "_check_inv_34", "_check_inv_78", "_check_inv_11", "_check_inv_44", "_check_inv_33", "_check_inv_77", "_check_inv_83", "_check_inv_72", "_check_inv_3", "_check_inv_82", "_check_inv_71"}});
        guardDependency.insert({"IncX", {"_tr_IncX"}});
        guardDependency.insert({"IncY", {"_tr_IncY"}});
        guardDependency.insert({"Reset", {"_tr_IncX", "_tr_IncY", "_tr_IncZ"}});
        guardDependency.insert({"IncZ", {"_tr_IncZ"}});
        dependentInvariant.insert({machine, std::unordered_set<string>()});
    }
    ArithmeticLaws counterExampleState;

    boost::asio::thread_pool workers(threads);

    while(!collection.empty() && !stopThreads) {
        possibleQueueChanges += 1;
        ArithmeticLaws state = next(collection, mutex, type);
        std::packaged_task<void()> task([&, state] {
            std::unordered_set<ArithmeticLaws, ArithmeticLaws::Hash, ArithmeticLaws::HashEqual> nextStates = generateNextStates(guardMutex, state, isCaching, invariantDependency, dependentInvariant, guardDependency, dependentGuard, guardCache, parents, stateAccessedVia, transitions);


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

    ArithmeticLaws::Type type;

    if(std::string("mixed").compare(strategy) == 0) {
        type = ArithmeticLaws::Type::MIXED;
    } else if(std::string("bf").compare(strategy) == 0) {
        type = ArithmeticLaws::Type::BFS;
    } else if (std::string("df").compare(strategy) == 0) {
        type = ArithmeticLaws::Type::DFS;
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