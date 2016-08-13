#include <iostream>


enum ANIMAL {
     DOG
   , CAT
   , TIGER
   , LION
};

enum CAR {
     TOYOTA
   , FORD
   , CHEVY
   , HONDA
};


enum class Country {
     USA
   , GERMANY
   , CANADA
   , FRANCE
   , JAPAN
};

enum class Major {
     ART
   , BIOLOGY
   , CHEMISTRY
   , ENGINEERING
   , FINANCE
};



enum class E_MY_FAVOURITE_FRUITS : unsigned char
{
    E_APPLE        = 0x01,
    E_WATERMELON   = 0x02,
    E_COCONUT      = 0x04,
    E_STRAWBERRY   = 0x08,
    E_CHERRY       = 0x10,
    E_PINEAPPLE    = 0x20,
    E_BANANA       = 0x40,
    E_MANGO        = 0x80,
    E_DEVIL_FRUIT  = 0x100, // Warning!: constant value truncated
};

    //conventional enums implicitly convert to int without being scoped
void test1()
{
   //-------------------------------------------------
   // normal enum
   //-----------------------------------------------------
   // implicitly convert to int
   int cat = ANIMAL::CAT;
   int ford = CAR::FORD;
   
   // bad example but compiles
   if (cat == ford) {
        std::cout << "Bad example\n";
   }
   
   if (ANIMAL::CAT == CAR::FORD) {
        std::cout << "Bad example\n";
   }
   

   //-------------------------------------------------
   // scoped, (and safer) enum
   //-----------------------------------------------------
   // this does not compile
   //int usa = Country::USA;
   
   Country usa = Country::USA;
   Major   art = Major::ART;
   
   // this does not compile
   #if 0
   if (usa == art) {
   
   }
   #endif
   
   
}



int main()
{
   // Bad example of enum
   

   
   return 0;
 }
   
   