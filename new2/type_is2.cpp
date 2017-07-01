#include <iostream>

template <typename T>
struct type_is {
   using type = T;
};

template <bool, typename T, typename>
struct IF : type_is<T> {};

template <typename T, typename U>
struct IF <false, T, U> : type_is<U> {};

struct MyClass1 {
   int   n1 = 100;
};

struct MyClass2 {
   int   n1 = 1;
   int   n2 = 2;
};

int main()
{
   constexpr int   n = 200;
   IF <(n > 100), MyClass2, MyClass1>::type a1;
   a1.n2 = 9;
   
   return 0;
}


