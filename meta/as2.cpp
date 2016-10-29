#include <iostream>
#include <vector>


template <typename T>
class Base
{
   public:
      Base() {}
      virtual ~Base() {}
      Base (const Base& b) = default;
      Base& operator=(const Base& b) = default;
      Base (Base&& b) = default;
      Base& operator=(Base&& b) = default;
      
      void test(T t) {
         std::cout << "Base::test(" << t << ")  \n";
      }
};

template <typename T>
class Derived : public Base<T>
{
   public:
      Derived(const std::vector<int>& v) : Base<T>() , m_V(v) {
        //static_assert(s > 0, "s < 0");
      }
      virtual ~Derived() {}
      Derived (const Derived& b) = default;
      Derived& operator=(const Derived& b) = default;
      Derived (Derived&& b) = default;
      Derived& operator=(Derived&& b) = default;
      
      void test(T t1, T t2) {
         Base<T>::test(t1 + t2);
      }
      
   private:
      std::vector<int> m_V;
      //static const size_t s = m_V.size();
      
};


int main()
{
      std::vector<int> v {1,3,4,5};
      //const int l = v.size();
      
    
      Derived<int>     d(v);
      d.test(v[0], v[3]);
     
      
      int   x = 10;
      const int y = x;
      
      int x2;
      constexpr int y2 = 222;
      
      
      return 0;
}


