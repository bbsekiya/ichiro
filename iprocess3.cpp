#include <iostream>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <string>

class IProcess
{
   public:
      virtual ~IProcess() {}
      
      virtual void send(const std::string& message) = 0;
      
  
};

class Email : public IProcess
{
   public:
      Email() {}
      virtual ~Email() {}
      
      void send(const std::string& message) override {
         std::cout << "Email send  : " << message << std::endl;
      
      }
 };

class SMS : public IProcess
{
   public:
      SMS() {}
      virtual ~SMS() {}
      
      void send(const std::string& message) override {
         std::cout << "SMS send : "  << message << std::endl;
      
      }
 };
 
 
 class DeviceManager
 {
   public:
      DeviceManager() {}
      ~DeviceManager() {}
      
      void send(const std::string& message, boost::shared_ptr<IProcess> p) {
         std::cout << "DeviceManager :send : " << message << std::endl;
     
         p->send(message);
      }
      
   private:
      boost::shared_ptr<IProcess> m_Device;
      
};



int   main()
{
   DeviceManager  d;
   boost::shared_ptr<Email> ep = boost::make_shared<Email>();
   d.send("This is a pen", ep);
   
   
   
   return 0;
}

