#include <iostream>

int foo1(int n) {
	return n * 10;
}

double foo2(double n) {
	return n * 10.11;
}
int main()
{
	
	decltype(foo1(100))		n1;
	
	static_assert(std::is_same<decltype(foo2(100)), double>::value, "...");
	
	
	
	return 0;
}