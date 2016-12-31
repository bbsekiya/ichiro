#include <iostream>

template <typename T>
struct IsChar {
	enum { value = 0 };
};

template <>
struct IsChar<char> {
	enum { value = 1 };
};

template <typename T>
struct NoCV {
	using type = T;
};


template <typename T>
struct NoCV<const T> {
	using type = T;
};


template <typename T>
struct IsAnyChar {
	enum {value = IsChar<typename NoCV<T>::type>::value};
};
	

int main()
{
	char a;
	const char b = a;
	
	
	
	static_assert(std::is_same<NoCV<char>::type, decltype(a)>::value, "not same");
	
	static_assert(std::is_same<NoCV<const char>::type, decltype(a)>::value, "not same");

	//static_assert(std::is_same<NoCV<char>::type, decltype(b)>::value, "not same");

	//static_assert(std::is_same<NoCV<const char>::type, decltype(b)>::value, "not same");
	
	std::cout << IsAnyChar<char>::value << std::endl;
	std::cout << IsAnyChar<const char>::value << std::endl;
	

return 0;
}

