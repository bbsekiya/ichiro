#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

struct Temp {
   int n1 = 100;
};

void func(boost::shared_ptr<const Temp>& p) {

   
}


int main()
{
   boost::shared_ptr<const Temp> p = boost::make_shared<const Temp>();
   
   auto o = std::move(*p);
   std::remove_const<decltype(o)>::type p2;
   std::cout << "p2.n1 = " << p2.n1 << std::endl;
   p2.n1 = 999;
   std::cout << "p2.n1 = " << p2.n1 << std::endl;
   p = boost::make_shared<const Temp>(p2);
   std::cout << "p->n1 = " << p->n1 << std::endl;
   
   
   return 0;
}