#include <iostream>
#include <vector>
#include <string>


#if 0
template <typename T>
typedef std::vector<T> MyVector ;
#endif

template <typename T>
using MyVector = std::vector<T>;


template <typename T>
class Analyze
{
   public:
      Analyze() {}
      Analyze(T t) : m_T(t) {}
      
      T t() const {
         return m_T + m_N;
      }
   private:
      T m_T  = 0;
      int m_N = 100;
      
};


int main()
{
   MyVector<int>     m = {1,2,3,4,5};
   
   MyVector<std::string> s = {"aaa", "bbb", "cccc"};
   
   for (auto it=m.cbegin(); it!=m.cend(); it++) {
      std::cout << *it << std::endl;
    }
    
    for (auto it=s.cbegin(); it!=s.cend(); it++) {
      std::cout << *it << std::endl;
    }
   
   Analyze<int>  a;
   std::cout << "a.t() = " << a.t() << std::endl;
   
   
   return 0;
}
