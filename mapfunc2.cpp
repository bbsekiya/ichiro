#include <map>
#include <string>

class Convert
{
   public:
      Convert()  {
       pointerMap["func1"] = &Convert::func1;
       pointerMap["func2"] = &Convert::func2;
      }
      virtual ~Convert() {}
      
     void invoke(const std::string& name, int x, int y) {
       if(pointerMap[name])
         (this->*pointerMap[name])(x, y);
     }

private:
     void func1(int Convert, int b) {};
     void func2(int Convert, int b) {};
     std::map<std::string, void (Convert::*)(int, int)> pointerMap;
};

int main () {
  Convert o;
  o.invoke("func1", 1, 2);
}