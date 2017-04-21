#include <iostream>
#include <string>




template <int ...Vals>
struct Ints {
	
	void func() {
		std::cout << "func() " << std::endl;
		Ints<Vals...>::func();
	}
	
};

template <int V>
struct Int {
	Int() {
		std::cout << "Int constructor : V = " << V << std::endl;
	}
};

template <std::string& s>
void func() {
	std::cout << "func() : s = " << s << std::endl;
}

std::string t = "123456789";

template <size_t t>
void func1() {
	std::cout << "func1() : t = " << t << std::endl;
}

template <double d>
void func2() {
	std::cout << "double2() : d = " << d << std::endl;
}



int main()
{
	Int<100> i;
	
	std::string s = "abcdef";
	func<t>();
	
	//func<s>();
	
	func1<100>();
	const int x1 = 9999;
	func1<x1>();
	
	const double d1 = 999.99;
	
	
	
	
	Ints<10,2,4,77,99> ins;
	
	
	return 0;
}