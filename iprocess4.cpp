#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class IReader {
   public:
      virtual ~IReader() {}
      virtual void read() = 0;
};
class IWriter {
   public:
      virtual ~IWriter() {}
      virtual void write() = 0;
};

class MyReader : public IReader {
   public:
      MyReader() {}
      virtual ~MyReader() {}
      void read() override {
         std::cout << "MyReader read()\n";
      }
 };
 
class MyWriter : public IWriter{
   public:
      MyWriter() {}
      virtual ~MyWriter() {}
      void write() override {
         std::cout << "MyWriter write()\n";
      }
 };
 
 
 class EncryptService {
   public:
      EncryptService() {}
      virtual ~EncryptService() {}
      
      void encrypt(boost::shared_ptr<IReader> r, boost::shared_ptr<IWriter> w) {
         r->read();
         w->write();
      }
};

int main()
{
   EncryptService  en;
   en.encrypt(boost::make_shared<MyReader>(), boost::make_shared<MyWriter>());
   
   
   return 0;
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 