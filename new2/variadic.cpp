#include <iostream>


//------------------------------------------------------\\\
// is the type T is one of the following types?

// --- primary template; is T the same as any of the types U?
// declare interface only
template <typename T, typename ...U>
struct is_one_of;


// --- base #1: specialization recognizes empty list of types
template <typename T>
struct is_one_of<T> : std::false_type {};

// ---- base #2: specialization recognizes match at head of list types
template <typename T, typename ...U>
struct is_one_of<T, T, U...> : std::true_type {};

// --- specialization recognizes mismatch at head of list of types
template <typename T1, typename T2, typename ...U>
struct is_one_of<T1, T2, U...> : is_one_of<T1, U...> {};


int main()
{
	static_assert(!is_one_of<int>::value, "int");
	static_assert(is_one_of<int, int>::value, "int int");
	static_assert(!is_one_of<double, int>::value, "double int");
	static_assert(!is_one_of<double, int, int>::value, "double int int");
	
	static_assert(is_one_of<int,int,double>::value, "int, int, double");
	
	static_assert(is_one_of<int,char,double, int>::value, "int, char int, double, int");
	
	static_assert(!is_one_of<int, double, char, uint64_t>::value, "int double char uint9=64_t");
	
	//no type deductions
	static_assert(!is_one_of<int, const int>::value, "int const int");
	
	static_assert(!is_one_of<int, double, const uint64_t, const double>:: value, "...");
	
	static_assert(!is_one_of<const int, int, int, double>:: value, "...");
	
	static_assert(is_one_of<const int, int, const uint64_t, const int>::value, "...");
	
	
	
	
	
	
	return 0;
}