#include <iostream>
#include <type_traits>

template <typename T>
void func(T&& t) {
	t *= 2;
}
template <typename T>
void func2(T t) {
	static_assert(std::is_signed<T>::value, "unsigned");
	
	//std::is_unsigned<A>::value 
}
	



int main()
{
	int n1 = 10;
	func2(n1);
	
	func2(-100.33);
	
	unsigned double d1 = 999.99;
	func2(d1);
	
	
	
	const int n2 = 20;
	//func(n2);
	
	return 0;
}