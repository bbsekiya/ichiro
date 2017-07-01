#include <iostream>



auto f()->int {
	return 5;
}






int main()
{
	auto x1 = f();
	static_assert(std::is_same<int, decltype(x1)>::value, "not same");
	
	std::cout << "x1 = " << x1  << std::endl;
	
	
	return 0;
}