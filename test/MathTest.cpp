#include"catch.hpp"
#include"../stefan/Math.hpp"

TEST_CASE("Absolute value", "[Math]") {

  SECTION("int") {
    REQUIRE(stefan::abs(0) == 0);
    REQUIRE(stefan::abs(5) == 5);
    REQUIRE(stefan::abs(-2) == 2);
  }

  SECTION("double") {
    REQUIRE(stefan::abs(0.0) == 0.0);
    REQUIRE(stefan::abs(5.0) == 5.0);
    REQUIRE(stefan::abs(-2.1) == 2.1);
    REQUIRE(stefan::abs(3.4) == 3.4);
    REQUIRE(stefan::abs(-273.432) == 273.432);
  }
    
}

TEST_CASE("Greatest common divisor", "[Math]") {

  SECTION("unsigned") {
    REQUIRE(stefan::gcd<unsigned>(5, 4) == 1);
    REQUIRE(stefan::gcd<unsigned>(4, 5) == 1);
    REQUIRE(stefan::gcd<unsigned>(12, 6) == 6);
    REQUIRE(stefan::gcd<unsigned>(12, 4) == 4);
    REQUIRE(stefan::gcd<unsigned>(8, 12) == 4);
    REQUIRE(stefan::gcd<unsigned>(0, 12) == 12);
    REQUIRE(stefan::gcd<unsigned>(12, 4) == 4);
  }

  SECTION("unsigned long long") {
    
  }
  
}
