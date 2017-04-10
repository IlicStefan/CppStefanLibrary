#ifndef MATH_HPP
#define MATH_HPP

#include<utility>

namespace stefan {

  /**
   * Find greatest common divisor of two positive integers.
   */
  template<typename UnsignedInteger>
  UnsignedInteger gcd(UnsignedInteger a, UnsignedInteger b) {
    while(b != UnsignedInteger(0)) {
      UnsignedInteger tmp = a % b;
      a = std::move(b);
      b = std::move(tmp);
    }

    return a;
  }
  
  /**
   * Find absolute value of given integer number.
   */
  template<typename Integer>
  Integer abs(const Integer & number) {
    return number >= Integer(0) ? number : - number;
  }
  
} // stefan

#endif // MATH_HPP
