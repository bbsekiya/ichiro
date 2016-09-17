#include <iostream>
#include <array>



void func()
{
   constexpr std::size_t array_size = 100;
  
   const int   t;
   const int t2 = t;
   
   constexpr int t3 = t;
   
   //array_size = 200;
   
   const auto s = 100;
   std::array<int, s> m; // error
   
   constexpr auto s2 = 300;
   std::array<int, s2> m2; // error
}


int main()
{
   int a = 100;
   int b = 200;
   
   auto fld = [a,b](int x) { return a + b + x; };
   
   std::cout << fld(900) << std::endl;
   
   
   func();
   
   return 0;
}