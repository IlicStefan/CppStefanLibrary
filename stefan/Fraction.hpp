#ifndef FRACTION_HPP_
#define FRACTION_HPP_

#include<iostream>
#include<stdexcept>
#include<utility>
#include"Math.hpp"

namespace stefan {
  
  template<typename Integer>
  class Fraction {
    
  public:

    explicit Fraction(const Integer & numerator = Integer(0),
		      const Integer & denominator = Integer(1))
      : m_numerator(numerator),
	m_denominator(denominator)
    {
      fixData();
    }
    
    const Integer & getNumerator() const {
      return m_numerator;
    }
    
    const Integer & getDenominator() const {
      return m_denominator;
    }

    // Creating two methods setNumerator() and setDenominator() can make
    // a confusion in the client code.
    // For example:
    // Fraction a(14, 15);
    // a.setNumerator(5);
    // a.setDenominator(7);
    // cout << a << endl; \\ Will print 1/7 !! (because of gcd() function).
    // or:
    // Fraction a(14, 15);
    // a.setDenominator(7);
    // a.setNumerator(5);
    // cout << a << endl; \\ Will print 5/1 !!
    void setFraction(const Integer & numerator, const Integer & denominator) {
      m_numerator = numerator;
      m_denominator = denominator;
      fixData();
    }
    
    void setFraction(const Integer & numerator, Integer && denominator) {
      m_numerator = numerator;
      m_denominator = std::move(denominator);
      fixData();
    }
    
    void setFraction(Integer && numerator, const Integer & denominator) {
      m_numerator = std::move(numerator);
      m_denominator = denominator;
      fixData();
    }
    
    void setFraction(Integer && numerator, Integer && denominator) {
      m_numerator = std::move(numerator);
      m_denominator = std::move(denominator);
      fixData();
    }
    
    std::ostream & print(std::ostream & ostr) const {
      return ostr << getNumerator() << '/' << getDenominator();
    }
    
    std::istream & read(std::istream & istr) {
      char c;
      istr >> m_numerator >> c >> m_denominator;
      if(c != '/')
	istr.setstate(std::ios::failbit);
      else
	fixData();
      
      return istr;
    }
    
    Fraction operator + (const Fraction & fraction) const {
      return Fraction(getNumerator() * fraction.getDenominator()
		      + getDenominator() * fraction.getNumerator(),
		      getDenominator() * fraction.getDenominator());
    }
    
    Fraction operator - (const Fraction & fraction) const {
      return Fraction(getNumerator() * fraction.getDenominator()
		      - getDenominator() * fraction.getNumerator(),
		      getDenominator() * fraction.getDenominator());
    }
    
    Fraction operator * (const Fraction & fraction) const {
      return Fraction(getNumerator() * fraction.getNumerator(),
		      getDenominator() * fraction.getDenominator());
    }
    
    Fraction operator / (const Fraction & fraction) const {
      return Fraction(getNumerator() * fraction.getDenominator(),
		      getDenominator() * fraction.getNumerator());
    }

    Fraction operator - () const {
      return Fraction(- getNumerator(), getDenominator());
    }

    Fraction & operator += (const Fraction & fraction) {
      m_numerator = getNumerator() * fraction.getDenominator()
	+ getDenominator() * fraction.getNumerator();
      m_denominator = getDenominator() * fraction.getDenominator();
      fixData();
      return *this;
    }

    Fraction & operator -= (const Fraction & fraction) const {
      m_numerator = getNumerator() * fraction.getDenominator()
	- getDenominator() * fraction.getNumerator();
      m_denominator = getDenominator() * fraction.getDenominator();
      fixData();
      return *this;
    }
    
    Fraction & operator *= (const Fraction & fraction) const {
      m_numerator = getNumerator() * fraction.getNumerator();
      m_denominator = getDenominator() * fraction.getDenominator();
      fixData();
      return *this;
    }
    
    Fraction & operator /= (const Fraction & fraction) const {
      m_numerator = getNumerator() * fraction.getDenominator();
      m_denominator = getDenominator() * fraction.getNumerator();
      fixData();
      return *this;
    }

    // Reciprocal of a fraction.
    Fraction operator ~ () const {
      return Fraction(getDenominator(), getNumerator());
    }
    
    bool operator == (const Fraction & fraction) const {
      return getNumerator() == fraction.getNumerator()
	&& getDenominator() == fraction.getDenominator();
    }

    bool operator != (const Fraction & fraction) const {
      return !(*this == fraction);
    }

    bool operator <= (const Fraction & fraction) const {
      return getNumerator() * fraction.getDenominator()
	<= getDenominator() * fraction.getNumerator();
    }

    bool operator < (const Fraction & fraction) const {
      return getNumerator() * fraction.getDenominator()
	< getDenominator() * fraction.getNumerator();
    }

    bool operator >= (const Fraction & fraction) const {
      return getNumerator() * fraction.getDenominator()
	>= getDenominator() * fraction.getNumerator();
    }
    
    bool operator > (const Fraction & fraction) const {
      return getNumerator() * fraction.getDenominator()
	> getDenominator() * fraction.getNumerator();
    }

    Fraction & operator ++ () {
      m_numerator += m_denominator;

      return *this;
    }

    Fraction operator ++ (int) {
      Fraction fraction = *this;
      m_numerator += m_denominator;

      return fraction;
    }

    Fraction & operator -- () {
      m_numerator += m_denominator;

      return *this;
    }

    Fraction operator -- (int) {
      Fraction fraction = *this;
      m_numerator += m_denominator;
      
      return fraction;
    }
    
  private:

    void fixData() {
      if(m_denominator == Integer(0))
	throw std::logic_error("Denominator cannot be zero!");

      // Denominator must be a positive integer.
      if(m_denominator < Integer(0)) {
	m_numerator = - m_numerator;
	m_denominator = - m_denominator;
      }

      // In fraction gcd(|numerator|, denominator) must be 1.
      Integer tmp = gcd(abs(m_numerator), m_denominator);
      if(tmp > Integer(1)) {
	m_numerator /= tmp;
	m_denominator /= tmp;
      }
    }
    
    Integer m_numerator;
    Integer m_denominator;
  };    

  template<typename Integer>
  std::ostream & operator << (std::ostream & ostr,
			      const Fraction<Integer> & fraction) {
    return fraction.print(ostr);
  }    

  template<typename Integer>
  std::istream & operator >> (std::istream & istr,
			      Fraction<Integer> & fraction) {
    return fraction.read(istr);
  }
  
} // stefan

#endif // FRACTION_HPP_
