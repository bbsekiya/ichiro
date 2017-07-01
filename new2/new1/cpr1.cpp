#include <iostream>
#include <type_traits>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


template <typename T>
void ret(T& t) {
	typename std::remove_pointer<T>::type U;
	
	t = boost::make_shared<U>();
}


#if 0	
template <typename ...T>
void make_more(T ...args) {
	
}
#endif


class MyClass {
	public:
		MyClass(){}
		MyClass(int n1) : m_N1(n1) {}
		MyClass(int n1, int n2) : m_N1(n1), m_N2(n2) {}
		virtual ~MyClass() {}
		
		int n1() const { return m_N1; }
		int n2() const { return m_N2; }
		
		
	private:
		int	m_N1 = 0;
		int m_N2 = 0;

};


int main()
{
	boost::shared_ptr<int> p0;
	
	p0 = boost::make_shared<int>();
	// new_shared(p0,10);
	
	//ret(p0);
	
	return 0;
}


#if 0
template <typename T>
void print_type_info(const T&) {
	if constexpr(std::is_integral<T>::value) {
		std::cout << "is integral\n";
	} else {
		std::cout << "is not integral\n";
	}
}

int main()
{
	print_type_info(5);
	
	print_type_info(2.5);
	
	return 0;
}
#endif
