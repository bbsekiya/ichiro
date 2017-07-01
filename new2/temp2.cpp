#include <iostream>

template <typename T>
struct Rank {
   static constexpr size_t value = 0u;
};

template <typename U, size_t N>
struct Rank<U[N]> {
   static constexpr size_t value = 1u + Rank<U>::value;
};

struct TempStruct {
   int n = 100;
};
int main()
{
   using array_t1 = int[10][20][30];
   std::cout << Rank<array_t1>::value << std::endl;
   
   
   std::cout << Rank<int>::value << std::endl;
   std::cout << Rank<double>::value << std::endl;
   std::cout << Rank<TempStruct>::value << std::endl;

   using array_t2 = char[32];
   std::cout << Rank<array_t2>::value << std::endl;
   
   
   return 0;
 }