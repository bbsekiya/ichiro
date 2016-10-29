#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <string>
#include <vector>
#include <algorithm>





boost::tuple<std::string, int, int> getMyTup() {

   return boost::make_tuple("AAA", 0, 100);
}

#if 0

template <typename T>
decltype(auto) getBack(T&& t) {
   return boost::get<boost::tuple_size<
      std::remove_reference_t<T> >::value -1)
      std::forward<T>(t));
}

#endif





int main()
{
   const auto ret = getMyTup();
   
   std::cout << boost::get<0>(ret) << std::endl;
   std::cout << boost::get<1>(ret) << std::endl;
   std::cout << boost::get<2>(ret) << std::endl;
   
   std::cout << "\n\n-------------------------\n\n";
   
   std::vector<boost::tuple<std::string, int, int> > v 
   {
        {"ZZZZ", 9, 999}
      , {"AAA", 0, 100}
      , {"CCCCCC", 4, 333}
   };
   
   //std::sort(v.begin(), v.end());
   
   for (const auto& t : v) {
      std::cout << boost::get<0>(t) << " - " << boost::get<1>(t) << " - _"
         << boost::get<2>(t) << std::endl;
   }
   
   
   
   

   return 0;
}