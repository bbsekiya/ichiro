#include <iostream>

template <typename T>
struct Variable { static T member = 5; };

template <typename T>
struct Typedef { using member = int; };

template <typename T>
void Fn(void) {
   typename T::member m = 5;
   std::cout << "Fn:  m = " << m << std::endl;
}

int main()
{

   return 0;
}
   

