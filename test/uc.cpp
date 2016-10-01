#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>
#include <string>

class Analyzer
{
   public:
      template <typename T>
      explicit Analyzer(T&& v) {
         analyze(std::forward<T>(v));
      }
      
      #if 0
       Analyzer(const std::vector<int>& v) : m_V(v) {
         
      }
      #endif
      
      virtual ~Analyzer() {}
      
      void display() const {
         for (auto it=m_V.cbegin(); it!=m_V.cend(); it++) {
            std::cout << "*it = " << *it << std::endl;
         }
      }
      
      
   private:
      void analyze(std::vector<int>& v) {
         std::cout << "--------- analyze(std::vector<int>& v) -------------\n";
         
         v[0] = 999;
         m_V = std::move(v);
      }
      
      void analyze(const std::vector<int>& v) {
         std::cout << "--------- analyze(const std::vector<int>& v) -------------\n";
         
         m_V = v;
      }
      
      
      std::vector<int> m_V;

};

void func(const int& n)
{
   
   std::cout << "void func(const int& n) : " << n << "\n";
}



int main()
{
   std::vector<int> v {10,20,30,40,50};
   
   Analyzer    a(v);
   a.display();
   
   Analyzer    a2(std::vector<int>{2,4,6,8});
   a2.display();
   
   
   #if 0
   int   n = 100;
   
   func(n);
   func(int(200));
   func(300);
   #endif
   
   
   
   
   return 0;
}

