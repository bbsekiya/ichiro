#include <map>
#include <string>
class a
{
public:
     a()
     {
       pointerMap["func1"] = &a::func1;
       pointerMap["func2"] = &a::func2;
     }

     void invoke(const std::string& name, int x, int y) {
       if(pointerMap[name])
         (this->*pointerMap[name])(x, y);
     }

private:
     void func1(int a, int b) {};
     void func2(int a, int b) {};
     std::map<std::string, void (a::*)(int, int)> pointerMap;
};

int main () {
  a o;
  o.invoke("func1", 1, 2);
}