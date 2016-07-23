#include <map>
#include <string>
#include <map>
#include <iostream>
#include <boost/tuple/tuple.hpp>




class Convert
{
   public:
      Convert() : m_State(STATE::SYNC) {
         m_Function[STATE::SYNC] = &Convert::initFunc;
         m_Function[STATE::START] = &Convert::processSTART;
         m_Function[STATE::STARTEND] = &Convert::processSTART;
         m_Function[STATE::MIDDLE] = &Convert::middleFunc;
         m_Function[STATE::END] = &Convert::endFunc;
      }
      virtual ~Convert() {}
      
      enum class STATE {
         SYNC, START,  STARTEND, MIDDLE, END
      };
      
      void put() {
      
         std::vector<uint32_t> m = {
             0x000af320,0x00000007,0x00000006,0x00000005,0x00000009
            ,0x0000b0820,7,6,5,0x00000009    //start
            ,0x0000b0820,7,6,5,0x00000009
            ,0x0000b08A0,7,6,5,0x00000009    //startend
            ,0x0000b0880,7,6,5,0x00000009    //end
            ,0x0000b08A0,7,6,5,0x00000009    //startend
           
            
         };
         
         for (auto it=m.cbegin(); it!=m.cend(); it++) {
         
            invoke(m_State, *it);
         }
      }

private:

     // invoke a specific function based on the context dictated by the input
     void invoke(STATE s, uint32_t data) {
       if(m_Function[s])
         (this->*m_Function[s])(data);
     }
     
      
      STATE state(uint32_t data)
      {
         STATE    next;
         switch(data)
         {
            case 0x000b0820:
            case 0x000b08a0:
               next = STATE::START;
               
               break;
            case 0x000b0880:
               next = STATE::END;
               break;
            case 0x000b0840:
               next = STATE::MIDDLE;
               break;
            default:
               next = m_State;
               break;
         }
               
         return next;
      }
      
      void initFunc(uint32_t data) {
         printf("[initFunc] data = %08x\n", data);
         
         //until START/STARTEND is encountered, keep reading the data
         //if END or MIDDEL is found, since there had been no START,
         //ignore
         m_State = state(data);
         
      };
      
      // Process START Segment 
      // Get Header info (times)
      // Get Data
      // Under a normal condition, expect next SEGMENT marker to be MIDDLE or END
      // If START or STARTEND is encountered here, assume MIDDLE/END was missed by the recorder
      void processSTART(uint32_t data) {
              printf("[startFunc] data = %08x\n", data);
         if (data == 0x00000007 && m_Time.size() == 0) m_Time.push_back(data);
         else if (data == 0x00000006 && m_Time.size() == 1) m_Time.push_back(data);
         else if (data == 0x00000005 && m_Time.size() == 2) m_Time.push_back(data);
         // if time vector checks, construct Header
         // then accumuate data, ignore everything else
         // except another segment marker 
         else if (data == 0x00000009) {
            m_Data.push_back(data);
         }
         else {
            m_State = state(data);
         }
         
        

 };     

      void endFunc(uint32_t data) {
         printf("[endFunc] data = %08x\n", data);
         if (data == 0x00000009) {
            m_Data.push_back(data);
         }         
         else {
            m_State = state(data);
         }
         
      };    

      
      void middleFunc(uint32_t data) {
         printf("[middleFunc] data = %08x\n", data);
          if (data == 0x00000009) {
            m_Data.push_back(data);
         }         
        
         if (data == 0x000b0820 || data==0x000b08a0) {
            m_State = STATE::START;
         }   
         else if (data == 0x0000b08A0) {
            m_State == STATE::END;
         }
        
      };     
      
     
     std::map<STATE, void (Convert::*)(uint32_t)> m_Function;
     
     STATE  m_State;
     
     std::vector<uint32_t> m_Time;
     std::vector<uint32_t> m_Data;
     
};

int main () {
  Convert o;
  o.put();
}