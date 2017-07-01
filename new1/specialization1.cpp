#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class MyClass {
};

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

template <typename T>
struct Inu {
   static void myInu() {
      std::cout << "--------- myInu -----------\n";
   }
};


template <typename T>
struct Inu<T*> {
   static void myInu() {
      std::cout << "-------------- myInu T* ------------\n";
   }
};

template <typename T>
struct Inu<boost::shared_ptr<T> > {
   static void myInu() {
      std::cout << "-------------- myInu boost::shared_ptr<T> ------------\n";
   }
};
template <typename T>
struct Inu<boost::shared_ptr<const T> > {
   static void myInu() {
      std::cout << "-------------- myInu boost::shared_ptr<const T> ------------\n";
   }
};
int main()
{
   Neko<int>::myNeko();
   Neko<const char*>::myNeko();
   Neko<double>::myNeko();
   
   std::cout << "\n--------------- partial specialization -----------\n";
   
   Inu<int>::myInu();
   Inu<char*>::myInu();
   
  
   Inu<MyClass>::myInu();
   
   
   Inu<boost::shared_ptr<MyClass> >::myInu();
   Inu<boost::shared_ptr<const MyClass> >::myInu();
 
   return 0;
}
