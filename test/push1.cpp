#include <iostream>
#include <vector>

class MyClass1
{
   public:
      MyClass1() {}
      virtual ~MyClass1() {}

#if 0
      MyClass1(const MyClass1& that) = delete;
      MyClass1& operator=(const MyClass1& that) = delete;
#endif

#if 0     
      MyClass1( MyClass1&& that) = default;
      MyClass1& operator=( MyClass1&& that) = default;

     
#endif
      
#if 1
      MyClass1(const MyClass1& that)  {
         std::cout << "--- MyClass copy constructor ---------\n";
      }
      
      MyClass1& operator=(const MyClass1& that) {
         std::cout << "--- MyClass assignment operator ---------\n";
         
         return *this;
      }
#endif
 

#if 0
       MyClass1(MyClass1&& that) {
         std::cout << "--- MyClass move constructor ---------\n";
         
      }
      
      MyClass1& operator=(MyClass1&& that) {
         std::cout << "--- MyClass move assignment operator ---------\n";
         if (this != &that) {
          
         }
         return *this;
      }
 #endif
 
   private:
      
};




int main()
{
   std::vector<MyClass1> v1;
   v1.reserve(100);
    
   MyClass1       m1; 
   v1.push_back(std::move(m1));
   
  
  
   return 0;
 }
 
     