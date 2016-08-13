#include <iostream>
#include <map>
#include <vector>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class MyClass
{
   public:
      MyClass() {}
      virtual ~MyClass() {
         
         
      
      }
      
      bool init() {
      
         m_DataFileNames[DATA_TYPE::DATA20_1] = "file1";
         m_DataFileNames[DATA_TYPE::DATA20_2] = "file2";
         m_DataFileNames[DATA_TYPE::DATA20_3] = "file3";
         m_DataFileNames[DATA_TYPE::DATA24_1] = "file4";
         
         m_Data.insert(std::make_pair(DATA_TYPE::DATA20_1, v_t() ) );
         m_Data.insert(std::make_pair(DATA_TYPE::DATA20_2, v_t() ) );
         m_Data.insert(std::make_pair(DATA_TYPE::DATA20_3, v_t() ) );
         m_Data.insert(std::make_pair(DATA_TYPE::DATA24_1, v_t() ) );
         
         populateData(DATA_TYPE::DATA20_1);
         
          
         
      }

   private:
      enum class DATA_TYPE {
         DATA20_1, DATA20_2, DATA20_3, DATA24_1
      };
      std::map<DATA_TYPE, std::string> m_DataFileNames;
      
      
      typedef std::vector<int> v_t;
      typedef std::map<DATA_TYPE, v_t> data_t;
      
      
      
      
      void populateData(DATA_TYPE f) {
         
         
         auto it = std::find_if(m_DataFileNames.cbegin(), m_DataFileNames.cend(),
            [f](const std::pair<DATA_TYPE, std::string>& t)->bool {
               return t.first == f;
            });
         
         
         
         if (it != m_DataFileNames.cend()) {
         
            std::cout << "filename = " << it->second << std::endl;
            
            for (int i=0; i<10; i++) {
                m_Data[f].push_back(i);
            }
         }
         
         
         for (auto dt=m_Data[f].cbegin(); dt!=m_Data[f].cend(); dt++) {
            std::cout << "*dt = " << *dt << std::endl;
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