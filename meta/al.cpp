#include <iostream>

template <typename T>
class BaseAlgorithm : public T
{
   public:
      BaseAlgorithm() : T() {
      
      }
      virtual ~BaseAlgorithm() {}
      
      void algorithm() {
         T::step1();
         T::step2();
         T::step3();
      }
 };
 
 class TmpImp1 
 {
      public:
         virtual ~TmpImp1() {}
      
      protected:
         void step1() {
            std::cout << "TmpImp1 - step1()\n";
         }
         void step2() {
            std::cout << "TmpImp1 - step2()\n";
         }
         void step3() {
            std::cout << "TmpImp1 - step3()\n";
         }
 };

 
class TmpImp2
 {
      public:
         virtual ~TmpImp2() {}
      
      protected:
         void step1() {
            std::cout << "TmpImp2 - step1()\n";
         }
         void step2() {
            std::cout << "TmpImp2 - step2()\n";
         }
         void step3() {
            std::cout << "TmpImp2 - step3()\n";
         }
 };
        
 
 
 int main()
 {
   BaseAlgorithm<TmpImp1> a1;
   a1.algorithm();
   
   BaseAlgorithm<TmpImp2> a2;
   a2.algorithm();
   
   return 0;
 }
 