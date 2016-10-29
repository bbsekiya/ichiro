#include <iostream>
#include <string>
#include <type_traits>
#include <cassert>


struct Test {
   //static constexpr std::string s1 = "ABC";
   
    static constexpr  double n1 = 999.99;
   
   
};

constexpr double half(double x) {
   return x / 2;
}


int main()
{
   //static_assert(std::is_literal_type<std::string>::value, "not literal");
   
   static_assert(std::is_literal_type<double>::value, "not literal");

   
   constexpr double x = half(10);
   static_assert(x == 5, "error 1");
   
   const double y = 10;
   constexpr double z = half(y);
   static_assert(z == 5, "error 2");
   
   const double y2 = 10;
   const double z2 = half(y2);
   assert(z2 == 5);
   

   
   
   return 0;
 }
 