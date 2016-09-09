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
      
      }
      
};

class Manager
{
   public:
      Manager() {}
      virtual ~Manager() {}
      
      void create(boost::shared_ptr<IP> p) {
      
      }
 };
 
 int main()
 {
   Manager  m;
   boost::shared_ptr<D1> d = boost::make_shared<D1>();
   
   
   return 0;
}
         