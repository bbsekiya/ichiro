#include <iostream>


#include <functional>

#include <type_traits>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


template <typename T>
void funcA(T t) {
	t*=2;
}

template <typename T>
void funcB(const T t) {
	
}

template <typename T>
void func0(T& t) {
	t*=2;
}


template <typename T>
void func1(const T& t) {
	
}

template <typename T>
void mmm(T val, std::function<void (T)> f) {
	f(val);
}

template <typename T>
void foo(const T& t){
	std::cout << "--- foo(const T&) ---\n";
}

template <typename T>
void foo(const T* t) {
	std::cout << "--- foo(const T* t) ---\n";
}

template <typename T>
void helper(const T& t, std::false_type) {
	std::cout << "not a pointer\n";
}
template <typename T>
void helper(const T&, std::true_type) {
	std::cout << "pointer\n";
}

template <typename T>
void mmmm2(const T& t) {
	helper(t, typename std::is_pointer<T>::type());
}

struct MyStruct {
	int n1 = 9999;
	MyStruct(int n) : n1(n) {}
};
void put(boost::shared_ptr<const MyStruct>& p) {
		std::cout << "p->n1 = " << p->n1 << std::endl;
		
}



int main()
{
	boost::shared_ptr<const MyStruct> q = boost::make_shared<const MyStruct>(100);
	put(q);
	
	
	std::function<void (int)> fn = [](int x) {std::cout << "x = " << x << std::endl;};
	mmm(12345, fn);
	
	int *p = nullptr;
	foo(p);
	
	const int* p2 = nullptr;
	foo(p2);
	
	
	int n = 100;
	foo(n);
	
	int& n1 = n;
	foo(n1);
	const int& n2 = n1;
	foo(n2);
	
	
	
	
	
	int a = 10;
	const int b = 20;
	
	funcA(a);
	funcA(b);
	
	funcB(a);
	funcB(b);
	
	func0(a);
	//func0(b);
	
	func1(a);
	func1(b);
	
	
	
	std::cout << "\n------------- mmmm2 -------------\n";
	int	x = 100;
	mmmm2(x);
	
	int *px = &x;
	mmmm2(px);
	
	const int* px2 = &x;
	mmmm2(px2);
	
	
	
	return 0;
}
	