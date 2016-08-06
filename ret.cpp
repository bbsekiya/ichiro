#include <iostream>
#include <string>
#include <vector>


struct Data {
   int   m_T1 = 100;
   int   m_T2 = 200;
};




int main()
{
   std::vector<int> v = {100,3,4,53,1001};
   
   auto x = v[0];
   x = 300;
   std::cout << "v[0] = " << v[0] << std::endl;
   
   decltype(v[0]) y = v[0];
   y = 200;
    std::cout << "v[0] = " << v[0] << std::endl;
  
   
   Data  d;
   std::cout << "d.m_T1 = " << d.m_T1 << " d.m_T2 = " << d.m_T2 << std::endl;
   std::cout << "sizeof(Data::m_T1) = " << sizeof(Data::m_T1) << std::endl;
   
   
   
   return 0;
 }