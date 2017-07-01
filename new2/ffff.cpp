#include <iostream>
#include <iterator>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


struct Temp {
   int   n1 = 100;
   int   n2 = 200;
};

int main()
{
   
   Temp  t[8] = {nullptr};
   
   Temp  a;
   
  
   t[0] = a;
   t[1] = a;

   int it = std::distance(std::begin(t), std::end(t));   
   std::cout <<  "it = " << it << std::endl;


   return 0;
 }