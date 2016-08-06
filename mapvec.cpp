#include <iostream>
#include <map>
#include <vector>

class MyClass
{
   public:
      MyClass() {}
      virtual ~MyClass() {
         
         
      
      }
      
      bool init() {
        
        
         m_Data.insert(std::make_pair(DATA::D20_1, v_t() ) );
         m_Data.insert(std::make_pair(DATA::D20_2, v_t() ) );
         m_Data.insert(std::make_pair(DATA::D20_3, v_t() ) );
         m_Data.insert(std::make_pair(DATA::D24, v_t() ) );
         
         
      }

   private:
      enum class DATA {
         D20_1, D20_2, D20_3, D24
      };
      typedef std::vector<int> v_t;
      typedef std::map<DATA, v_t> data_t;

      void readData(data_t d) {
         
         for (int i=0; i<10; i++) {
            
         }
         
           
      }
      
      
      data_t m_Data;
 };
 
 
 
 int main()
 {
   MyClass  m;
   
   m.init();
   
   return 0;
   
 }