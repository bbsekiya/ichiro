#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class MyClass
{
   public:
      MyClass() {}
      virtual ~MyClass() {}
      
      void put(boost::shared_ptr<const std::vector<int> > p) {
      
         
         
         for (auto it=p->cbegin(); it!=p->cend(); it++) {
            //std::cout << "*it = " << *it << std::endl;
            m_OutputPtr->push_back(std::move(*it));
            m_Oit = m_OutputPtr->end() - 1;
            
            std::cout << "*m_Oit = " << *m_Oit << std::endl;
            
            analyze();
            if (m_OutputPtr->size() == 5) {
            
               std::cout << "\n---------------- OUTPUT -------------------\n";
               for (auto it=m_OutputPtr->begin(); it!=m_OutputPtr->end(); it++) {
                  std::cout << *it << std::endl;
               }
               std::cout << std::endl << std::endl;
               
               m_OutputPtr->clear();
               m_Oit = m_OutputPtr->begin();
               
            
            }
         }
         
      }
      
   private:
      
      void analyze() {
         if (*(m_OutputPtr->end() -1) == 5) {
            std::cout << "analyze() input = " << *(m_Oit) << " size = " << m_OutputPtr->size() << std::endl;
         }   
      }
      
      boost::shared_ptr<std::vector<int> > m_OutputPtr = boost::make_shared<std::vector<int> >();
      std::vector<int>::iterator m_Oit = m_OutputPtr->begin();
      
      
};

int main()
{
   const std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
   boost::shared_ptr<const std::vector<int> > p = boost::make_shared<const std::vector<int> >(v);
   
   MyClass  m;
   m.put(p);
   m.put(p);
   
   
   
   return 0;
}
