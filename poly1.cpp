#include <iostream>
#include <vector>

class Message
{
   public:
      Message() {
      }
      virtual ~Message() {}
      
     void push_back(int n) {
         buffer.push_back(n);
     }
     std::vector<int> message() {
         return buffer;
      }
   private:
      std::vector<int> buffer;
};
     

struct Data {
   int   x1 = 100;
   int   x2 = 200;
   char  buf[1025] = {0};
   
   Data(int s1, int s2) : x1(s1), x2(s2) {
   }
   virtual ~Data() {}
 
   void reset() {
      x1 = 100;
      x2 = 200;
      memcpy(buf, 0, sizeof(buf));
   }
};

class HData : public Data 
{
   public:
      HData(int s1, int s2) : Data(s1, s2) {
      
      }
      virtual ~HData() {}
    
    void write(const std::vector<int>& m) {
      
    }
};



int main()
{
   Message  m;
   for (int i=0; i<10; i++) {
      m.push_back(i);
   }
   
   HData    h(100,200);
   h.write(m.message());
   

   
   

   return 0;
} 