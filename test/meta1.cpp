#include <iostream>
#include <climits>

template <int N>
struct abs2 {
   static_assert(N!=INT_MIN, "N!=INT_MIN");
   //static constexpr int value = (N<0) ? - N : N;
   static const int value = (N<0) ? - N : N;

};



int main()
{
   
   std::cout << abs2<3>::value << std::endl;
   
   std::cout << abs2<-10>::value << std::endl;
 
   return 0;
}
   
   