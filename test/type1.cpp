#include <iostream>
#include <type_traits>

int func(...) { return 0; }

template <typename T>
typename std::enable_if<std::is_integral<T>::value, int>::type
func(T val) {
   return 1;
}

int func(float n) {
   return 2;
};


int main()
{
   
   
   std::cout << "func(nullptr) = " << func(nullptr) << std::endl;
   std::cout << "func(2) = " << func(2) << std::endl;
 
   std::cout << "func(1.f) = " << func(1.f) << std::endl;
   std::cout << "func(2,0) = " << func(2.0) << std::endl;
   
  
   
   
   return 0;
}
