#include <iostream>
#include <algorithm>





int main()
{
	const double d1 = 1000.84;
	const double i1 = 10;
	
	auto x1 = std::max(d1, i1);
	std::cout << "x1 = " << x1 << std::endl;
	
	const int i2 = 2000;
	auto x2 = std::max(d1, static_cast<double>(i2));
	std::cout << "x2 = " << x2 << std::endl;
	

	
	return 0;
}