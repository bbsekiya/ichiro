#include <iostream>
#include <climits>
#include <type_traits>
#include <vector>
#include <array>


template <int N>
struct abs2 {
   static_assert(N!=INT_MIN, "N!=INT_MIN");
   //static constexpr int value = (N<0) ? - N : N;
   static const int value = (N<0) ? - N : N;

};

template <unsigned M, unsigned N>
struct gcd2 {
   static int const value = gcd2<N, M%N>::value;
};

//specialization ; base case
template <unsigned M>
struct gcd2<M,0> {
   static_assert(M!=0, "M!=0");
   static int const value = M;
};

   


template <typename T>
using myVec = std::vector<T>;


template <typename T>
void g(const myVec<T>& v) {
   static_assert(std::is_same<myVec<T>, std::vector<T> >::value, "not same type");
   
   std::cout << "g(const myVec<T>&v : v.size() = " << v.size() << std::endl;
}

template <typename T>
void foo(T x) {
   puts(__PRETTY_FUNCTION__);
}



template <typename TYPE, size_t SIZE>
void foo10(std::array<TYPE, SIZE>& a) {

   puts(__PRETTY_FUNCTION__);
   
   
}


#if 0
template <typename R, typename A, typename B>
void foo20(R (*fptr)(A, B)) {
   puts(__PRETTY_FUNCTION__);
   
   R fn = flptr;
   
   
   
}

#endif



   
int main()
{
   
   std::cout << abs2<3>::value << std::endl;
   
   std::cout << abs2<-10>::value << std::endl;
 
   std::cout << "gcd2<M,N>::value = " << gcd2<48, 36>::value << std::endl;
   
   
   std::cout << "std::is_void<int>::value = " << std::is_void<int>::value << std::endl;
   
   std::cout << "std::is_void<void>::value = " << std::is_void<void>::value << std::endl;

   //std::cout << "std::is_void<int> = " << std::is_void<int> << std::endl;
   
   static_assert(std::is_same<myVec<int>, std::vector<int> >::value, "not same");
   
   myVec<int>     x = {1,2,3,4};
   g(x);
   
   foo(10);
   foo(std::string("XX"));
   std::string s("AAA");
   foo(s);
   foo("aaa");
   
   uint32_t    a1 = 100u;
   
   std::array<int, 10> a100 = {1,2,3,4,5,6,7,8,9,10};
   
   foo10(a100);
   
   std::array<std::string, 10> a200 = {"aaa", "bbb"};
   foo10(a200);
   
   
   //foo20( +[](double x, double y)->double { return x*x + y; });
   

   
   return 0;
}
   
   