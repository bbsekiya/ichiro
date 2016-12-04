#include <iostream>
#include <type_traits>
#include <algorithm>



//auto has_xxx = is_valid([](auto t)->decltype(t.xxx){});


template <typename T, typename = decltype(&T::xxx)>
static std::true_type has_xxx_impl(int);

template <typename T>
static std::false_type has_xxx_impl(...);

template <typename T>
struct has_xxx : decltype(has_xxx_impl<T>(int{})) {
};

struct Foo {
	int xxx;
};


struct Foo2 {
	double xxx;
};





int main()
{

	static_assert(has_xxx<Foo>::value, "not xxx");
	
	static_assert(has_xxx<Foo2>::value, "not xxx");

	return 0;
}