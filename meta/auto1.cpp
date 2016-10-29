#include <iostream>

template <typename T>
void f(T param) {

}






int main()
{
   f(100);
   
   f ((1,2,3));
   
   
   
   static_assert(std::is_same<decltype(x), int>::value, "int");
   
   int   y=(100,300);  
   std::cout << "y = " << y << std::endl;
 
   
   
 
   //f( {1,2,3,4} );
   
   
   
   return 0;
}
