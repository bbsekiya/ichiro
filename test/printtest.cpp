#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class MyClass
{
   public:
      explicit MyClass(const std::string& s) : m_S(s) {}
      virtual ~MyClass() {}
      
      MyClass(const MyClass& that) : m_S(that.m_S) {
      std::cout << "--- copy constructor ---\n";
      }
      
     
      MyClass& operator=(const MyClass& that) {
         if (this != &that) {
            m_S = that.m_S;
            std::cout << "--- assignment operator ---\n";
         }  
         return *this;
      }
      
      MyClass(MyClass&& that) : m_S(std::move(that.m_S)) {
         std::cout << "--- move constructor ---\n";
         that.m_S = ""; //should NOT use nullptr ... undefined behavior
            
      }
      
      MyClass& operator=(MyClass&& that) {
         if (this != &that) {
            m_S = std::move(that.m_S);
            that.m_S = "";  //should NOT use nullptr ... undefined behavior
            
              std::cout << "--- move assignment operator ---\n";
         }
         return *this;
       }       
   private:
      std::string m_S;
 };
int main()
{
   
   std::vector<MyClass> m;

   //std::string t = nullptr; // NO!!
   
   MyClass  s("test");
   
   
  
  std::cout << "\n------------------- copy/move test -----------------\n";
   
   std::cout << "(1)\n";
   MyClass s2 = s;   //copy constructor  // initialization
   
    std::cout << "(2)\n";
    MyClass s3(s);    //copy constructor
  
    
    std::cout << "(3)\n";
    s2 = s3;  // copy assignment operator
   
   std::cout << "(4)\n";
   MyClass x1 = std::move(s);
   
   std::cout << "(5)\n";
   MyClass  x2(std::move(s));
   
   std::cout << "(6)\n";
   x1 = std::move(x2);
   
   
    std::cout << "\n------------------- push_back/emplace_back test -----------------\n";
   
   MyClass  p("ABC");
   std::cout << "*** 1 ***\n";
   m.push_back(p);
   
   std::cout << "*** 2 ***\n";
   m.push_back(std::move(p));
  
   std::cout << "*** 3 ***\n";
   m.emplace_back(p);
   
   std::cout << "*** 4 ***\n";
   m.emplace_back(std::move(p));
  
    
   #if 0
   
   std::cout << "*** 2 ***\n";
   m.push_back(MyClass("XXX"));
   
   std::cout << "*** 2.1 ***\n";
   m.push_back(MyClass(p));
   
   std::cout << "*** 2.2 ***\n";
   m.push_back(std::move(MyClass("XXX")));
   

   
   std::cout << "*** 3 ***\n";
   m.push_back(std::move(p));
   
   std::cout << "*** 4 ***\n";
   m.emplace_back(MyClass("XXX"));
   
   std::cout << "*** 5 ***\n";
   m.emplace_back(std::move(p));
  
   std::cout << "*** 6 ***\n";
   m.emplace_back(MyClass(std::move(p)));
#endif

  return 0;
}