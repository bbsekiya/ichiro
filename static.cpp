#include <iostream>

class MyClass
{
   public:
      MyClass() {}
      virtual ~MyClass() {}
      
      void put() {
         
         std::cout << "x = " << ++x << std::endl;
      }
      
   private:
      int      x = 0;
};



int main()
{
   MyClass  m1;
   m1.put();
   m1.put();
   
   
   MyClass m2;
   m2.put();
   
   MyClass m3;
   m3.put();
   
   return 0;
}