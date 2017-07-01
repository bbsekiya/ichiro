#include <iostream>

template <typename T, T t>
struct integral_constant {
	static constexpr T value = t;
	

	// p1
	constexpr operator T() const noexcept {
		return value;
	}
	
	
	// p1()
	constexpr T operator()() const noexcept {
		return value;
	}

	
};


int main()
{
	
	auto p1 = integral_constant<int, 100>();
	
	std::cout << "integral_constant<int, 100>::value = " <<
		integral_constant<int, 100>::value << std::endl;
		
	std::cout << "p1() = " << p1() << std::endl;
	
	std::cout << "p1 = " << p1 << std::endl;
	
	// invalid template non-type parameter
	//auto p2 = integral_constant<double, 99.99>();
	return 0;
}
