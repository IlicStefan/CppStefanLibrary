#ifndef MATH_HPP
#define MATH_HPP

#include<utility>

namespace stefan {

  template<typename UnsignedInteger>
  UnsignedInteger gcd(UnsignedInteger a, UnsignedInteger b) {
    while(b != UnsignedInteger(0)) {
      a = a % b;
      std::swap(a, b);
    }

    return a;
  }
  
  template<typename Number>
  Number abs(const Number & number) {
    return number >= Number(0) ? number : - number;
  }
  
} // stefan

#endif // MATH_HPP
