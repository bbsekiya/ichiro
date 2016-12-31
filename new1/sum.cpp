#include <iostream>

template <size_t N>
struct Sum {
	enum { value = N + Sum<N - 1>::value };
};

template <>
struct Sum<1> {
	enum { value = 1 };
};

template <size_t N>
struct Pow {
	double operator()(double x) const {
		return N * x;
	}
};


int main()
{
	std::cout << "Sum<1>::value = " << Sum<1>::value << std::endl;
	std::cout << "Sum<2>::value = " << Sum<2>::value << std::endl;
	std::cout << "Sum<3>::value = " << Sum<3>::value << std::endl;
	std::cout << "Sum<4>::value = " << Sum<4>::value << std::endl << std::endl;
	
	std::cout << "Pow<2>(2.0) = " << Pow<2>()(2.0) << std::endl;
	std::cout << "Pow<10>(3.0) = " << Pow<10>()(3.0) << std::endl;

	return 0;
}
	