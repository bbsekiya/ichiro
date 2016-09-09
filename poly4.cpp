#include <iostream>

class Base
{
   public:
      Base() {}
      virtual ~Base() {}
      
      virtual void display() const {
         std::cout << "Base display()\n";
      }
 };
 
 class Derived : public Base
 {
   public:
      Derived() : Base() {}
      virtual ~Derived() {}
      
      void display() const override {
         std::cout << "Derived display()\n";
      }

      void display2() const {
         std::cout << "Derived display2()\n";
      }
 };
 
void test(Base* p)
{
   p->display();
}



int main()
{
   Derived *d1 = new Derived;
   test(d1);
   
   d1->display2();
   
   
   
   //Derived *d2 = new Base;
   //test(d2);
   
   Base *b1 = new Base;
   test(b1);
   
   Base *b2 = new Derived;
   test(b2);
   
   //b2->display2();
   
   
   return 0;
}
 
 
   