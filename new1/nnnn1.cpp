#include <iostream>
#include <type_traits>



template<bool IsIntegral> 
struct BarImpl {
    template<class T> 
	static void bar(const T&) {
        std::cout << "Generic" << std::endl;
    }
    static void bar(const std::string&) {
        std::cout << "Specialization for std::string" << std::endl;
    }
};

template<> 
struct BarImpl<true> {
    template<class T> static void bar(const T&) {
        std::cout << "Specialization for integral type" << std::endl;
    }
    static void bar(bool) {
        std::cout << "Specialization for bool" << std::endl;
    }
};

struct Foo {
    template<class T> void bar(const T& input) {
        BarImpl<std::is_integral<T>::value>::bar(input);
    }
};

//====================================================================


template <typename T, typename U>
constexpr auto pick(std::true_type, T x, U y) {
	return x;
}

template <typename T, typename U>
constexpr auto pick(std::false_type, T x, U y){
	return y;
}

template <typename T, typename U>
constexpr auto pick2(T x, U y){
	return x;
}

int main()
{
	int n1 = pick(std::is_integral<int>::type(), 100, 200.20);
	std::cout << "n1 = " << n1 << std::endl;
	
	double d1 = pick(std::is_integral<double>::type(), 100, 200.20);
	std::cout << "d1 = " << d1 << std::endl;
	
	//int n2 = pick(true, 100, 200.20);
	
	
	//auto n1 = pick<std::is_integral<int>::value>(10,222);
	
	return 0;
}