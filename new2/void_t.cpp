#include <iostream>

template <class ...>
using void_t = void;

template <class ...>
struct voider { using type = void; };

template <class... T0toTN>
using void_t2 = typename voider<T0toTN...>::type;


// primary template
template <class, class = void>
struct has_type_member : std::false_type {};

// partial specilization
template <class T>
struct has_type_member <T, void_t2<typename T::type>>
   : std::true_type {};
 
 
 voider<int>::type func1(){
   std::cout << "voider<int>::type func1()\n";
   
   
 }
 
 voider<double>::type func2(){
   std::cout << "voider<double>::type func2()\n";
   
   
 }
 
 voider<double, int, void, uint16_t>::type func3(){
   std::cout << "voider<double, int, void, uint16_t>::type func3()\n";
   
   
 }
 
int main()
{
   func1();
   
   
   
   return 0;
}
