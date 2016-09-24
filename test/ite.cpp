#include <iostream>
#include <algorithm>


void func(std::vector<int>::const_iterator it)
{



}


void func(std::vector<int>::const_reverse_iterator it)
{



}

int main()
{
   std::vector<int>   m;
   
   auto it = m.cbegin();
   auto rt = m.crbegin();
   
   func(it);

   func(rt);
   
   return 0;
}