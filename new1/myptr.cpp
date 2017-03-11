#include <iostream>

struct MyPtr {
	#if 1
	explicit operator bool() const {
		//some condition
		return true; // or falose
	}
	#endif
	
	#if 0
	operator bool() const {
		return true;
	}
	#endif
};


void func(bool b) {
	
};
	

int main()
{
	MyPtr	p;
	
	if (p) {
		std::cout << "p is true\n";
	}
	else {
		std::cout << "p is false\n";
	}
	
	
	func(p);
	
	
	return 0;
}