#include <iostream>
#include <vector>
#include <utility>
#include <map>



void saveData(const std::vector<uint32_t>& data)
{
   std::vector<uint8_t> out;
   
   for (auto it=data.cbegin(); it!=data.cend(); it++) {
      uint16_t d = *it &0x0000FFFF;
      printf("%08x\n", (*it & 0x0000FFFF));
      
      //printf("1st = %04x, 2nd = %04x\n", ((*it &0x0000FFFF) >> 8), ((*it &0x000000FF)));
      out.push_back(((*it &0x0000FFFF) >> 8));
      out.push_back(((*it &0x000000FF)));
   }
   
   for (auto it=out.cbegin(); it!=out.cend(); it++) {
      printf("*it = %x\n",*it);
   }

}

struct Data {
   uint32_t    d1;
   uint32_t    d2;
};

void structToVector()
{
   std::cout << "\n********************** structToVector **************\n";
   Data  d;
   d.d1 = 0x00001000;
   d.d2 = 0x00001001;
   
   auto const ptr = reinterpret_cast<uint8_t*>(&d);

   std::vector<uint8_t> out( ptr, ptr + sizeof(Data) );
 
     for (auto it=out.cbegin(); it!=out.cend(); it++) {
      printf("*it = %x\n",*it);
   }
}

class Stats
{
   public:
      Stats() {}
      virtual ~Stats() {}
      
      void endMissing() {
      
      
      }
      
};

 
class MyClass
{
   public:
      MyClass() {}
      virtual ~MyClass() {}
      enum class STATE {INIT, START, MIDDLE, END};
      enum class MISSED_MARKER {NONE, START, END};
   private:
      std::map<std::pair<STATE, uint32_t>, MISSED_MARKER> errorMap;
      
      MISSED_MARKER stats(uint32_t data) {
      
         auto it = errorMap.find(std::make_pair(STATE::START, 0));
         
         if (*it == MISSED_MARKER::NONE)
         
         return MISSED_MARKER::NONE;
       }
};

  

int main()
{
   std::vector<uint32_t> m =
      {
           0x000B0820
         , 0x0081000
         , 0xFF41001
         , 0x000B840
      };
      
   saveData(m);
   
   
   structToVector();
   
   
   return 0;
}