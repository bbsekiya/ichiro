#include <iostream>

//--- primary template for non-void types
template <typename T>
struct is_void : std::false_type{};

//--- specializations recognize each of the four void types
template <>
struct is_void<void> : std::true_type {};


int main()
{
	static_assert(!is_void<int>::value, "int is not void");
	
	static_assert(is_void<void>::value, "void is void");
	
	
	return 0;
}