#include <map>
#include <string>
#include <map>
#include <iostream>
#include <boost/tuple/tuple.hpp>

class Convert
{
   public:
      Convert()  {
       pointerMap["func1"] = &Convert::func1;
       pointerMap["func2"] = &Convert::func2;
      }
      virtual ~Convert() {}
      
      enum class STATE {
           INIT, START1, START2, MIDDLE, END
      };
      
     void invoke(const std::string& name, int x, int y) {
       if(pointerMap[name])
         (this->*pointerMap[name])(x, y);
     }

private:
     void func1(int Convert, int b) {};
     void func2(int Convert, int b) {};
     
     void nextState(uint32_t) {
     
     }
     std::map<std::string, void (Convert::*)(int, int)> pointerMap;
     boost::tuple<uint32_t, STATE, STATE> m_Trans;
     
};

int main () {
  Convert o;
  o.invoke("func1", 1, 2);
}