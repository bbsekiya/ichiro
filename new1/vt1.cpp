#include <iostream>


template <typename T>
void print(const T& t) {
   std::cout << "tonly: " << t << " ";
}



template <typename T1, typename ...T2>
void print(const T1& t1, const T2& ...t2) {

   
   std::cout << "t1:t2 " << t1 << " : ";
   print(t2...);
}


template <typename T>
void channelInfo(T&& t) {
   T channel = t;
}

template <typename T1, typename ...T2>
void channelInfo(T1&& t1, T2&& ...t2) {
   T1 command1 = t1;
   channelInfo(t2...);
}


int main()
{
   print(1);
   std::cout << "\n";
   print(1,2,3);
   std::cout << "\n";
   
   
   return 0;
 }
   