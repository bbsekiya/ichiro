#include <iostream>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>

class IProcess
{
   public:
      virtual ~IProcess() {}
      
      virtual void process() = 0;
      
  
};

class MyProcess1 : public IProcess
{
   public:
      MyProcess1() {}
      virtual ~MyProcess1() {}
     
      void process() override {
         std::cout << "MyProcess1 process()\n";
      }

 };
 
class MyProcess2 : public IProcess
{
   public:
      MyProcess2() {}
      virtual ~MyProcess2() {}
     
      void process() override {
         std::cout << "MyProcess2 process()\n";
      }

 };
// make_shared in the constructor initialize list ?

class MyManager
{
   public:
      MyManager(boost::shared_ptr<IProcess> p) : m_Process(p) {
      
      }
      virtual ~MyManager() {}
      
      void generate() {
         m_Process->process();
      }
      
   private:
      boost::shared_ptr<IProcess> m_Process;
 
};


int main()
{
   boost::shared_ptr<MyProcess1> p1 = boost::make_shared<MyProcess1>();
   boost::shared_ptr<MyProcess2> p2 = boost::make_shared<MyProcess2>();
 
   MyManager      m1(p1);
   m1.generate();
   
  
   MyManager      m2(p2);
   m2.generate();

   return 0;
 
 }
      
      