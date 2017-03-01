#include <iostream>

// specialization

template <typename T>
struct Neko {
   static void myNeko() {
      std::cout << "------------ Neko -------------\n";
    }
};

template <>
struct Neko<const char*> {
   static void myNeko() {
      std::cout << "------------ Neko : const char*  -------------\n";
    }
};
 
template <>
struct Neko<double> {
   static void myNeko() {
      std::cout << "------------ Neko : double  -------------\n";
    }
};
int main()
{
   Neko<int>::myNeko();
   Neko<const char*>::myNeko();
   Neko<double>::myNeko();
   
   std::cout << "\n--------------- partial specialization -----------\n";
   
  
   
   return 0;
}
