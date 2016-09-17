#include <iostream>
#include <vector>


int main()
{
   std::vector<int> v = {1,2,3,4,5,6,7};
   
   auto it = v.cbegin() + 4;
   
   std::cout << "*it = " << *it << std::endl;
   
   std::cout << "std::distance(v.cbegin(), it) = " << std::distance(v.cbegin(), it) << std::endl;
   
   int index = std::distance(v.cbegin(), it);
   
   std::cout << "v[index] = " << v[index] << std::endl;
   
   return 0;
}
   