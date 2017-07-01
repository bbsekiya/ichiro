#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

// inspect the function, NOT calling but just INSPECTING
// what is the return type

int foo1(int n) {
	return n + 100;
}

double foo2(double n) {
	return static_cast<double>(n * 100);
}

boost::shared_ptr<int> m1() {
	return boost::make_shared<int>(10);
}

boost::shared_ptr<const int> m2(int n) {
	return boost::make_shared<const int>(n);
}

int xxx();

int yyy(const std::vector<int>&  x);

int main()
{
	static_assert(std::is_same<decltype(xxx()), int>::value, "daljlagj");
	
	
	
	
	static_assert(std::is_same<decltype(foo1(std::declval<int>())), int>::value, "xxx");
	
	static_assert(std::is_same<decltype(foo2(std::declval<double>())), double>::value, "xxx");

	static_assert(std::is_same<decltype(m2(std::declval<int>())), decltype(m2(100))>::value, "ldjfla");
	
	static_assert(std::is_same<decltype(m2(std::declval<int>())), decltype(m2(n))>::value, "ldjfla");

	static_assert(!std::is_same<decltype(m2(std::declval<int>())), decltype(m1())>::value, "ldjfla");

	
	return 0;
}