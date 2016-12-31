#include <iostream>


template <typename T>
struct Data {
	T		m_Data1;
	T		m_Data2;
	
	Data(T t1, T t2) : m_Data1(t1), m_Data2(t2) {}
	
	Data(const Data& that) : m_Data1(that.m_Data1), m_Data2(that.m_Data2) {
		std::cout << "....Data copy ...\n";
	}
	
	Data(Data&& that) : m_Data1(std::move(that.m_Data1)), m_Data2(std::move(that.m_Data2)) {
		that.m_Data1 = 0;
		that.m_Data2 = 0;
		std::cout << ".... Data move ....\n";
	}
	
};

template <typename T>
auto&& func(T&& t) {
//T&& func(T&& t) {
	return std::forward<T>(t);
}


template <typename T>
auto&& func1(T&& t) {
//T&& func(T&& t) {
	return std::forward<T>(t).m_Data1;
}


int main()
{
	Data<int>	d(100, 200);
	

	
	Data<int> d2 = func(std::move(d)) ;
	std::cout << "d2.m_Data1 = " << d2.m_Data1 << std::endl;
	std::cout << "d.m_Data1 = " << d.m_Data1 << std::endl;
	
	
	std::cout << "\n ----------------------------\n";
	
	Data<int>	d3(333, 444);

	int y1 = func1(d3);
	std::cout << "y1 = " << y1 << std::endl;
	std::cout << "d3.m_Data1 = " << d3.m_Data1 << std::endl;
	
	


	return 0;
}
