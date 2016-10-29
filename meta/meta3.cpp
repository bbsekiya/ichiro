#include <iostream>
#include <type_traits>
#include <string>

template <typename T>
struct type_is { using type = T; };

//primary template assumes the bool is true
// if true, type is T
template<bool, typename T, typename>
struct IF : type_is<T> {};

//partial specialization recognizes false
template <typename T, typename U>
struct IF<false, T, U> : type_is<U> {};

int main()
{

  using t1 = IF<true, int, std::string>::type;
  
  using t2 = IF<false, int, std::string>::type;
  
  
  t1 n1 = 100;
  
  t2 n2 = "xxx";
  
  
  
  
  
   
  
  

   return 0;
}