#include <iostream>


void fun(int& n) {
   std::cout << "--- fun(int& n) ---\n";
   
   
}

void fun(int&& n) {
   std::cout << "--- fun(int&& n) ---\n";
}

void fun(const int& n) {
   std::cout << "--- fun(const int& n) ---\n";
}


template <typename T>
void f(T&& t) {
   fun(std::forward<T>(t));
}



int main()
{
   int n = 100;
   f(n);
   const int cn = n;
   const int& rn = n;
   f(cn);
   f(rn);
   f(299);
   
   std::cout << "----------------------------\n";
   fun(n);
   fun(300);
   fun(std::move(n));
   
   
   
   
   return 0;
}