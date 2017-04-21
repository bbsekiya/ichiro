#include <iostream>
#include "myfunc.h"

class X1 {
	public:
		X1() {}
		virtual ~X1() {}
		
		void func() {
			myfunc();
		}
};
