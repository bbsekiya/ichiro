#include <iostream>

struct MyTest
{

      MyTest(const std::string& s) : m_S(s) {
         lcount++;
      }
      MyTest(std::string&& s) :m_S(std::move(s)) {
         MyTest::rcount++;
      }
      virtual ~MyTest() {}
      
      std::string m_S;
      static size_t lcount;
      static size_t rcount;
};

size_t MyTest::lcount = 0;
size_t MyTest::rcount = 0;

int main()
{
   std::string d1("ABC");
   
  
   MyTest m1(d1);
   MyTest m2(d1);
   MyTest m3(d1);
   MyTest m4(d1);
   MyTest m5(d1);
   
 
   
   std::cout << "MyTest::lcount = " << MyTest::lcount << std::endl;
   std::cout << "MyTest::rcount = " << MyTest::rcount << std::endl;
   
   
  
   MyTest m6("abcde");
   MyTest m7(std::string("AAAA"));
   
     std::cout << "\n--------------------------\n";
     std::cout << "MyTest::lcount = " << MyTest::lcount << std::endl;
     
   std::cout << "MyTest::rcount = " << MyTest::rcount << std::endl;
   
   

   return 0;
}
   