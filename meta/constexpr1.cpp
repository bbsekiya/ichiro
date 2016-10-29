#include <iostream>


struct Temp {
   const int n1 = 100;
   static  int s1;
   
   static constexpr int c1 = 999;
   
   Temp() {
      static_assert(c1 == 999, "error1");
   }
   
   
};

int Temp::s1 = 333;


int main()
{
   const int x = 100;
   static_assert(x == 100, "error");
   
   constexpr int y = 200;
   static_assert(y == 200, "error : y");
   
   Temp     t;
   //static_assert(t.n1 == 100, "error");
   std::cout << "t.n1 = " << t.n1 << std::endl;
   
   //static_assert(Temp::s1 == 333, "error : Temp::s1");
   std::cout << "Temp::s1 = " << Temp::s1 << std::endl;
   
   static_assert(t.c1 == 999, "t.c1 == 999");
   std::cout << "t.c1 = " << t.c1 << std::endl;
   
   return 0;
}
