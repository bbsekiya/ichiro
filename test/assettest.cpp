#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template<typename T>
class Type
{
   public:
      Type(T t) {
         static_assert(std::is_same<T, unsigned int>::value, "bad T");
      }
      virtual ~Type() {}
      
  
};

template < class T, size_t length >
class String
{
   static_assert(length < 100, "length is too big");
   T str_data[length];
};
	 
struct Data {
   int   m_N;
}Data_t;
static_assert(sizeof(Data) == 4, "data size error");


template <typename T>
class MyClass
{
   public:
      explicit MyClass(boost::shared_ptr<const std::vector<Data> > p) {
        
        
         
      }
      virtual ~MyClass() {}
      
      void test(T t) {
      
      }
     
};


int main()
{

   Type<unsigned int> t(100);
   
   //String< int, 101 > a1;
   String< int, 90 > a2;

   
   Data  d;
   d.m_N = 999;
   
   
   
   return 0;
}
