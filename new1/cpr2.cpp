#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

template <typename T>
void func(boost::shared_ptr<T>& p) {
	p = boost::make_shared<T>();
}


template <typename T1, typename T2>
void func(boost::shared_ptr<T1>& p, T2 n1) {
	p = boost::make_shared<T1>(n1);
}



/*
std::make_shared is declared like this:

template< class T, class... Args >
shared_ptr<T> make_shared( Args&&... args );

As such, std::make_shared<T, TArgs...> will result in a function taking rvalue references, which won't bind to args.... A simple fix for this is to force it to take lvalue references by collapsing the reference:

creator_ = std::bind(&std::make_shared<T,TArgs&...>, args...);
//                                            ^

An alternative is to use a lambda instead, which is more readable:

creator_ = [=](){return std::make_shared<T>(args...);};
*/


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
/*

std::make_shared is declared like this:

template< class T, class... Args >
shared_ptr<T> make_shared( Args&&... args );

As such, std::make_shared<T, TArgs...> will result in a function taking rvalue references, which won't bind to args.... A simple fix for this is to force it to take lvalue references by collapsing the reference:

creator_ = std::bind(&std::make_shared<T,TArgs&...>, args...);
//                                            ^

An alternative is to use a lambda instead, which is more readable:

creator_ = [=](){return std::make_shared<T>(args...);};

#*/

#if 0

template <typename T1, typename T2>
void func(boost::shared_ptr<T1>& p, T2 n1) {
	p = boost::make_shared<T1>(n1);
}

#endif


template <typename T, typename... ARGS> 
void func2(boost::shared_ptr<T>&p, ARGS... args)	{
	p = boost::make_shared<T>(args...);
}


int main()
{
	boost::shared_ptr<MyClass> p0;	
	func2(p0);
	std::cout << "p0->n1() = " << p0->n1() << "  p0->n2() = " << p0->n2() << std::endl;
	
	boost::shared_ptr<MyClass> p1;	
	func2(p1, 100);
	std::cout << "p1->n1() = " << p1->n1() << "  p1->n2() = " << p1->n2() << std::endl;
	
	
	return 0;
}