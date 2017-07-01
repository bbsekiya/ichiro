#include <iostream>

template <typename T>
struct IsChar {
	enum { value = 0 };
};

template <>
struct IsChar<char> {
	enum { value = 1 };
};

template <>
struct IsChar<const char> {
	enum { value = 1 };
};



int main()
{
	std::cout << IsChar<int>::value << std::endl;
	std::cout << IsChar<char>::value << std::endl;
	
	std::cout << IsChar<const char>::value << std::endl;
		std::cout << IsChar<double>::value << std::endl;
	

	
	return 0;
}


