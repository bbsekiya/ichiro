#include <iostream>
#include <type_traits>

class Target
{

};

template <typename T>
struct wrong : std::false_type {};

struct assert_arg_is_derived_from_a {
   template <typename T = void>
   assert_arg_is_derived_from_a() {
      static_assert(wrong<T>::value, "argument must be derived from A");
   }
};

struct ok {};

template<typename T, typename U>
using check_arg1 = typename std::conditional<std::is_same<T, U>::value, int, float>::type;


template<typename T>
using check_arg2 = typename std::conditional<std::is_base_of<Target, T>::value
                     , ok
                     , assert_arg_is_derived_from_a>;
                     

int main()
{




   return 0;
}