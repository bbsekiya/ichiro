#include <iostream>

// primary template for distinct types
template <typename T, typename U>
struct is_same : std::false_type {};

// partial specialization recognizes distinct types
template <typename T>
struct is_same<T, T> : std::true_type {};



int main()
{
	
	constexpr int m1 = 100;
	
	
	
	std::cout << " const? : " << std::is_const<int>::value << std::endl;
	
	static_assert(is_same<int, int>::value, "int - int");
	
	static_assert(!is_same<int, char>::value, "int - char");
	
	constexpr int n = 100;
	
	// int - const int
	static_assert(!is_same<int, decltype(n)>::value, "int - decltype(n)");
	
	static_assert(is_same<const int, decltype(n)>::value, "int - decltype(n)");
	
	static_assert(!is_same<double, int>::value, "double - int");
	
	return 0;
}