#include <iostream>
#include <cmath>


int main()
{
   uint64_t x1 = 2 * std::pow(10, 6);
   std::cout << "x1 = " << x1 << std::endl;
   
   double d1 = 0.123456;
   
   uint64_t x2 = static_cast<uint64_t>(d1 * std::pow(10, 6));
   std::cout << "x2 = " << x2 << std::endl;
   
   return 0;
 }
   