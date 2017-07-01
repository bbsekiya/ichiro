#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>

struct Type1 {
	int		n1 = 100;
};

struct Type2 {
	double n1 = 1.1;
	double n2 = 2.1;
};

template <bool COND, typename TYPE=void>
using enable_if_t = typename std::enable_if<COND, TYPE>::type;


template<typename T>
enable_if_t<std::is_integral<T>::value, boost::shared_ptr<Type1>> f(T t){
    //integral version
	std::cout << "integral version\n";
	auto p = boost::make_shared<Type1>();
	p->n1 = t;
	return p;
}

template<typename T>
enable_if_t<std::is_floating_point<T>::value, boost::shared_ptr<Type2>> f(T t){
    //floating point version
	std::cout << "floating version\n";
	auto p = boost::make_shared<Type2>();
	p->n1 = t;
	p->n2 = t * 10;
	return p;
}



int main()
{
	constexpr int		n = 1000;
	constexpr double	d = 100.1;
	
	auto p1 = f(n);
	
	auto p2 = f(d);
	
	const std::string s = "abcd";
	
	f(s);
	
	return 0;
}