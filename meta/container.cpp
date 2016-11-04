#include <iostream>
#include <array>
#include <vector>
#include <string>

constexpr int func(int n)
{
   return n > 10 ? n * 2 : n;
}
 
 constexpr int func2(int& n)
{
   return n;
}

int tmp() { return 100;};

template <int N>
constexpr int func3() {
   static_assert(N > 0, "nnnn");
   return N + func(N);
   
}

template <int N>
constexpr void vvvv() {
   static_assert(N>0,"lll");
}


int main()
{
   constexpr std::array<int,5> values {1,2,3,4,5};
   
   for (auto it=values.cbegin(); it!=values.cend(); it++) {
      std::cout << *it << std::endl;
   }
   
   //constexpr std::vector<int> v {1,2,3,4,5};
   
   constexpr int n = func(100);
   std::cout << "n = " << n << std::endl;
   std::cout << "func(100) = " << func(100) << std::endl;   
   constexpr int n2 = 3;
   std::cout << "func(n2) = " << func(n2) << std::endl;
     

   int y=90;
   std::cout << "func2(y= " << func2(y) << std::endl;
   
   
   std::cout << func3<10>() << std::endl;
   
   constexpr std::string mys("aaaaaaaaaaaaaaaaaaaa");
   
  
   return 0;
 }
 
 