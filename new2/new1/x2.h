#include <iostream>
#include "myfunc.h"

class X2 {
	public:
		X2() {}
		virtual ~X2() {}
		
		void func() {
			myfunc();
		}
};
