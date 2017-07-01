#include <iostream>

template <typename T>
using remove_cv_t = typename std::remove_cv<T>::type;

template <typename T>
using is_void = std::is_same<remove_cv_t<T>, void>;


int main()
{
	const int n1 = 100;
	
	static_assert(!is_void<int>(), "n1 is not void");
	
	static_assert(!is_void<decltype(n1)>(), "n1 is not void");
	
	static_assert(is_void<void>(), "kdjalfjda");

	return 0;
}