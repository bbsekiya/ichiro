#include <iostream>

template <typename T>
struct type_is {
	using type = T;
};

template <typename T>
struct remove_const : type_is<T> {};

template <typename T>
struct remove_const<const T> : type_is<T>{};

int main()
{
	const int x1 = 10;
	const double y1 = 10;
	
	
	
	
	remove_const<decltype(x1)>::type a2 = x1;
	std::cout << "a2 = " << a2 << std::endl;
	a2++;
	
	remove_const<decltype(y1)>::type a3 = y1;
	a3*=2;
	
	std::cout << "a2=" << a2 << " a3=" << a3 << std::endl;
	

	
	return 0;
}