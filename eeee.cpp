#include <iostream>

namespace eeee {

enum class MYSTATE {
   START, END
};


}

namespace bbbb {

using MYSTATE = eeee::MYSTATE;


}


int main()
{
   using MYSTATE = eeee::MYSTATE;
   
   MYSTATE   s = MYSTATE::START;
   
   switch(s)
   {
      case MYSTATE::START:
         break;
   }
      


   return 0;
}