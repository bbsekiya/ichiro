#include <iostream>

#if 0
In order to take the rvalue reference, it should be non-const, 
since the contents of the constructor argument will be moved and typically this 
is an operation that changes the state of the operand (although not in your particular case):

Circle(Circle&& c){ }

Also, you are seeing a copy elision here:

Circle c3(Circle(4));

so the move constructor doesn't get invoked. This is a standard compiler optimization that may or may not happen. If you were to construct a Circle like this:

Circle c3(std::move(c1));

then you would invoke the move constructor.
#endif'


class MyTest
{
   public:
      MyTest(const std::string& s) : m_S(s) {
         lcount++;
      }
      MyTest(std::string&& s) :m_S(std::move(s)) {
         MyTest::rcount++;
      }
      virtual ~MyTest() {}
      
      static size_t lcount;
      static size_t rcount;
     
   private:
      std::string m_S;
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
   