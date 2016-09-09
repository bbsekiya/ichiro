#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class IP
{
   public:
      virtual ~IP() {}
      
      virtual void draw() = 0;
 };
 
 class D1 : public IP
 {
   public:
      D1() {}
      virtual ~D1() {}
      
      void draw() override {
         std::cout << "D1 draw\n";
      }
      
};

class D2 : public IP
 {
   public:
      D2() {}
      virtual ~D2() {}
      
      void draw() override {
         std::cout << "D2 draw\n";
      }
      
};
class Manager
{
   public:
      Manager() {}
      virtual ~Manager() {}
      
      void create(boost::shared_ptr<IP> p) {
         p->draw();
      }
 };
 
 int main()
 {
   Manager  m;
   boost::shared_ptr<D1> d = boost::make_shared<D1>();
   m.create(d);
   
   boost::shared_ptr<D2> d2 = boost::make_shared<D2>();
   m.create(d2);

   return 0;
}
         