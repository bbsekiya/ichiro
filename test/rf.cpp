#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <utility>

struct Data
{
   int   s;
   Data(int n) : s(n) {}
   
} typedef Data_t;


void doThis(int n) {
   std::cout << "n = " << n << std::endl;
}

void doThis(std::string s)
{
   std::cout << "s = " << s << std::endl;
}
class MyClass
{
   public:
      MyClass(int n) : m_N(n), m_S("") {
         m_DataPtr = boost::make_shared<Data>(n+1);
         if (m_DataPtr != nullptr) {
            std::cout << "in constructor...make_shared ...\n";
         }
      }
      virtual ~MyClass() {}
      
      boost::shared_ptr<const Data> dataPtr() {
         return m_DataPtr;
      }
      
      MyClass(const MyClass& other) {
         std::cout << "MyClass copy constructor\n";
         m_N = other.m_N;
         if (other.m_DataPtr != nullptr) {
            std::cout << "...make_shared ...\n";
            m_DataPtr = boost::make_shared<Data>(*other.m_DataPtr);
         }
      }
      
      MyClass(const MyClass&& other) : m_N(other.m_N), m_DataPtr(std::move(other.m_DataPtr)) {
         std::cout << "MyClass move constructor\n";
         
      }
      
      template <typename T>
      void pass(T&& p) {
         doThis(std::forward<T>(p));
      
      }
      
      std::string s() const {
         return m_S;
      }
      int n() const {
         return m_N;
      }
      
  
   private:
      
      int m_N;
      std::string m_S;
      
      boost::shared_ptr<Data> m_DataPtr;
};



int main()
{
   std::vector<MyClass>    v;
   MyClass  m1(100);
   v.push_back(m1);
   v.push_back(std::move(m1));
   
   std::cout << "m1.dataPtr()->s = " << m1.dataPtr()->s << std::endl;
   
   std::cout << "--------------- v.size() = " << v.size() << std::endl;
   
   
   m1.pass(100);
   m1.pass("ABC");
   return 0;
}
   