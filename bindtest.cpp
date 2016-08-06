#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>





int main()
{
   std::vector<int> m = {1,3,10,100,40,50,80,999};
   
   size_t c = count_if(m.cbegin(), m.cend(), bind(std::less<>(), _1, 35));
   
   std::cout << "c = " << c << std::endl;

   return 0;

   
  }