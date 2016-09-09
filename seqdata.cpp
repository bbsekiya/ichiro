#include <iostream>
#include <vector>

namespace state {
enum class STATE {
   INIT, START, END
};
}

struct Data {
   uint32_t    m_Data;
   state::STATE       m_State;
   bool        m_Valid;
   Data(uint32_t d, state::STATE s, bool v) :
      m_Data(d), m_State(s), m_Valid(v) {}
      
} typedef Data_t;

void displayState(state::STATE s)
{
   switch(s)
   {
      case state::STATE::INIT:
         std::cout << "s = INIT \n";
         break;
      case state::STATE::START:
         std::cout << "s = START \n";
         break;
      case state::STATE::END:
         std::cout << "s = END\n";
   }
}


int main()
{
    state::STATE     INIT = state::STATE::INIT;
    
      state::STATE     START = state::STATE::START;

   std::vector<Data_t> v {
      {Data(100, INIT, 1)}
      , {Data(200, START, 0)}
   
   
   };
   
   for (auto it=v.cbegin(); it!=v.cend(); it++) {
      uint32_t d = it->m_Data;
      state::STATE   s = it->m_State;
      bool b = it->m_Valid;
      
      std::cout << "d = " << d << std::endl;
      displayState(s);
      std::cout << "b = " << b << std::endl << std::endl;
      
      
   }
   
   return 0;
}
