#include <iostream>

struct Data {
   int      x1 = 0;
 }typedef d_t;

class D1 {
   public:
      D1() {}
      virtual ~D1() {}
   
      void populate(int s) {
         m_d.x1 = s;
      }
    
      d_t  mys() const {
         return m_d;
      }
      
   private:
      d_t    m_d;
     
 };
 
 int main()
 {
   Data  aaa1;
   
   D1    d1;
   
   
   std::cout << "aaa1.x1 = " << aaa1.x1 << std::endl;
   
   d1.populate(20);
   
   std::cout << "aaa1.x1 = " << aaa1.x1 << std::endl;
  
    std::cout << "d1.mys().x1 = " << d1.mys().x1 << std::endl;
 
   HData    *h1 = Data(333,444);
   
   Data     *d1 = HData(3,4);
   
   
   return 0;
 }