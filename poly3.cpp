#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class Base
{
   public:
      Base(int n1, int n2) : m_N1(n1), m_N2(n2) {
      
      }
      virtual ~Base() {}
      
      virtual   void display() const  {
         std::cout << "Base display\n";
      }
  
   private:
      int m_N1;
      int m_N2;
 };
 
 class Derived : public Base
 {
   public:
      Derived(int n1, int n2) : Base(n1, n2) {
      
      }
      virtual ~Derived() {}
      
      void display() const override {
         std::cout << "Derived display\n";
      }
      
     
};         
 
 

void test(boost::shared_ptr<Base> p)
{
   p->display();
}


int main()
{
   boost::shared_ptr<Derived> d1 = boost::make_shared<Derived>(1,2);
   test(d1);
   
  // boost::shared_ptr<Derived> d2 = boost::make_shared<Base>(1,2);
  //  test(d2);  
    
   boost::shared_ptr<Base> b1= boost::make_shared<Base>(1,2);
   test(b1);
   
   boost::shared_ptr<Base> b2 = boost::make_shared<Derived>(1,2);
   test(b2);
   
   return 0;
 }
