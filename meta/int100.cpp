#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

struct HelloInterface {
   virtual ~HelloInterface() {}
   virtual void outputMessage() = 0;
};

struct HelloCoutImpl1 : HelloInterface {
   void outputMessage() override {
      std::cout << "--- HelloCoutImpl1 ---\n";
   }
};

struct HelloCoutImpl2 : HelloInterface {
   void outputMessage() override {
      std::cout << "--- HelloCoutImpl2 ---\n";
   }
};
class HelloWorld
{
   public:
      
       HelloWorld(boost::shared_ptr<HelloInterface> i) : m_Hello(i) {}
      //HelloWorld(HelloInterface&& h) : m_Hello(std::move(h)) {}

      virtual ~HelloWorld() {}
      
      void outputMessage()  const {
         m_Hello->outputMessage();
      }
   private:
      boost::shared_ptr<HelloInterface> m_Hello;
};


int main()
{
    boost::shared_ptr<HelloInterface> h1 = boost::make_shared<HelloCoutImpl1>();
    boost::shared_ptr<HelloInterface> h2 = boost::make_shared<HelloCoutImpl2>();;
    
    HelloWorld     hello1(h1);
    HelloWorld     hello2(h2);
    
    hello1.outputMessage();
    hello2.outputMessage();
    
   HelloWorld     hello3(boost::make_shared<HelloCoutImpl1>());
      return 0;
}
      