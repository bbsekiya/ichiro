#include <iostream>
#include <type_traits>
#include <vector>

template <typename T>
void foo(T t, std::true_type) {
	std::cout << "integral\n";
}

template <typename T>
void foo(T t, std::false_type) {
	std::cout << "Not integral\n";
}

template <typename T>
void bar(T t) {
	foo(t, typename std::is_integral<T>::type());
}

template <size_t N>
void foo(const int (&arr)[N], const int* p) {
	std::cout << "Array of " << N << ", distance " << p - &arr[0] << std::endl;
}

template <typename C>
void foo(const C& c, typename C::const_iterator i) {
	std::cout << "Container of size " << c.size() <<
		", distance = " << i - c.cbegin() << std::endl;
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value, double>:: type
foo(const T& t) {
	std::cout << "foo with enable if\n";
	return t;
}

int main()
{
	int 	n = 100;
	double	d = 888.88;
	
	bar(n);
	bar(d);
	bar(2000);
	bar(333.333);
	
	
	int k[] = {10,20,30,40,50};
	int* p = &k[3];
	foo(k, p);
	
	std::vector<int> v(k, k + 5);
	foo(v, v.cbegin() + 4);
	
	std::cout << "\n --1----------- enable_it ---------------\n";
	
	auto y1 = foo(100);
	static_assert(std::is_same<decltype(y1), double>::value, "y1 not double");
	std::cout << "y1 = " << y1 << std::endl;
	
	
	//auto y2 = foo(10.8);
	//static_assert(std::is_same<decltype(y2), double>::value, "y1 not double");

	return 0;
}




