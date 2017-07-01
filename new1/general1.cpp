#include <iostream>
#include <vector>
#include <array>
#include <string>


template <typename T>
using myVector = std::vector<T>;

template <typename T, size_t N>
using myArray = std::array<T, N>;

template <typename T, typename U>
constexpr auto mult(const T& t, const U& u)->decltype(t * u){
   return t * u;
}

struct A {
   A() = delete;
   A(int n) { std::cout << "A(int n)" << std::endl; }
   A(const std::string& s) { std::cout << "A(const std::string& s)\n"; }
};

struct B : A {
   using A::A;
};


   

int main()
{
   myVector<int>     v1;
   myVector<double>  v2;
   
   myArray<int, 10>  a1;
   myArray<std::string, 20> a2;
   myArray<double, 4> a3;
   
   auto lambda = [](const int& n1, const int& n2) { return n1 + n2; };
   std::cout << lambda(100,300) << std::endl;
   
   int x = 10;
   int y = 20;

   auto l3 = [x, y = y + 1]() { return x + y; };
   std::cout << l3() << std::endl;
   
   

   B  b1(100);
   B  b2(std::string("ABC"));
   
   
   
   



   return 0;
 }