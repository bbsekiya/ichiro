#include <iostream>

template <typename T>
void func(T t) {
	std::cout << "func(T t) \n";
}

template <>
void func(long t) {
	std::cout << "func(long t)\n";
}


#if 0
constexpr long func(long n) {
	return n * 1000;
}
#endif


#if 0
template <typename T>
void meow() {}

template <typename T>
void meow(T* t) {}
#endif

template <typename T>
struct Meow {
	static void doThis() {
		std::cout << "doThis()\n";
	}
};

template <typename T>
struct Meow<T*> {
	static void doThis() {
		std::cout << "doThis() : T*\n";
	}
};

  


int main()
{
	func<int>(100);
	
	func<long>(1L);
	
	func(0L);
	
	//meow();
	
	//meow(static_cast<double*>(nullptr)) ;
	
	Meow<int>::doThis();
	
	Meow<double*>::doThis();
	
	
	return 0;
}
