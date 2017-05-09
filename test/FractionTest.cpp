#include"catch.hpp"
#include"../stefan/Fraction.hpp"
#include<stdexcept>
#include<string>
#include<sstream>

using namespace std;
using namespace stefan;

TEST_CASE("Fraction", "[Fraction]") {

  Fraction<int> f1;
  Fraction<int> f2(1);
  Fraction<int> f3(5);
  REQUIRE_THROWS_AS(Fraction<int>(0, 0), std::logic_error);
  REQUIRE_THROWS_AS(Fraction<int>(7, 0), std::logic_error);
  Fraction<int> f4(0, 2);
  Fraction<int> f5(1, 2);
  Fraction<int> f6(2, 4);
  Fraction<int> f7(2, 3);
  Fraction<int> f8(9, 3);
  Fraction<int> f9(4, 11);
  Fraction<int> f10(1, -5);
  Fraction<int> f11(-1, 5);
  SECTION("== and !=") {
    REQUIRE(f5 == Fraction<int>(1, 2));
    REQUIRE(f6 == Fraction<int>(1, 2));
    REQUIRE(f6 == f5);
    REQUIRE(f8 == Fraction<int>(3));
    REQUIRE(f6 != Fraction<int>(1, 4));
    REQUIRE(f2 != f3);
    REQUIRE(f4 == Fraction<int>(0, 3));
    REQUIRE(f4.getNumerator() == 0);
    REQUIRE(f4.getDenominator() == 1);
    REQUIRE(f4.getDenominator() != 2);
    REQUIRE(f10 == f11);
    REQUIRE(f10.getNumerator() == -1);
    REQUIRE(f11.getDenominator() == 5);
  }
  
  SECTION("+, -, ~, *, /") {
    REQUIRE(f3 - f5 == Fraction<int>(9, 2));
    REQUIRE(f5 + f7 == Fraction<int>(7, 6));
    REQUIRE(f4 + f5 == f5);
    REQUIRE(f8 * f4 == Fraction<int>(0));
    REQUIRE_THROWS_AS(f3 / f4, std::logic_error);
    REQUIRE_THROWS_AS(~f4, std::logic_error);
    REQUIRE(~f7 == Fraction<int>(3, 2));
    Fraction<int> tmp = f5 - f7;
    REQUIRE(tmp.getNumerator() == -1);
    REQUIRE(tmp.getDenominator() == 6);
  }

  SECTION("++, --") {
    Fraction<int> tmp1 = f7;
    Fraction<int> tmp2 = f7;
    REQUIRE(tmp1++ == Fraction<int>(2, 3));
    REQUIRE(++tmp2 == Fraction<int>(5, 3));
    REQUIRE(tmp1 == Fraction<int>(5, 3));
  }

  SECTION("<< and >>") {
    stringstream s1;
    s1 << Fraction<int>(2, 4);
    REQUIRE(s1.str() == "1/2");
    stringstream s2;
    s2 << "1/2 1^2 1/0";
    Fraction<int> tmp;
    s2 >> tmp;
    REQUIRE(s2.good());
    s2 >> tmp;
    REQUIRE(s2.fail());
    stringstream s3;
    s3.str("1/0");
    REQUIRE_THROWS_AS(s3 >> tmp, std::logic_error);
  }
  
}
