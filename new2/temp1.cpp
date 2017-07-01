#include <iostream>

template <uint32_t M, uint32_t N>
struct Gcd {
   static constexpr uint32_t value = Gcd<N, M%N>::value;
};

template <uint32_t M>
struct Gcd<M, 0> {
   static_assert(M != 0, "M cannot be 0");
   static constexpr uint32_t value = M;
};


int main()
{
   std::cout << "value = " << Gcd<8,4>::value << std::endl;
   std::cout << "value = " << Gcd<100, 40>::value << std::endl;

   return 0;
}