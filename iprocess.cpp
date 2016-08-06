#include <iostream>

class IProcess 
{
   public:
      virtual ~IProcess() {}
   
   protected:
      virtual void  method1() = 0;
      virtual void  method2() = 0;
};

class MyClass : public IProcess
{
   public:
      MyClass() {}
      virtual ~MyClass() {}
      
      void test1() {
         std::cout << "------ test1() \n";
         method1();
         method2();
      }
    protected:
    
   
    
      void method1() {
         std::cout << "method1\n";
       }
    void method2() {
         std::cout << "method2\n";
       }
  
   
      
       
       
};

int main()
{
   MyClass     m;
   
   m.test1();
   
   #if 0
  IProcess *p = new MyClass;
  p->method1();
  #endif
  
  
   
   return 0;
}