#include <iostream>
#include <algorithm>
#include <memory>

template <typename T, typename F = std::less<typename T::value_type> >
void mySort(T& t, F f = F()) {
	std::sort(t.begin(), t.end(), f);
}

template <typename T>
void print(const T& t) {
	for (auto& e : t) {
		std::cout << e << " ";
	}
	std::cout << std::endl << std::endl << std::endl;
}

class MyClass {
	public:
		MyClass() : MyClass(0,0) {}
		MyClass(int n) : MyClass(n, 0) {}
		MyClass(int n1, int n2) : m_N1(n1), m_N2(n2) {}
		virtual ~MyClass() {}
	private:
		int m_N1, m_N2;
};

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique2(Args&& ...args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
	std::vector<int> v { 3,10,55,100,31,0,11,555};
	
	print(v);
	mySort(v);
	print(v);
	
	mySort(v, std::greater<int>());
	print(v);
	
	std::cout << "\n------------------ NEXT ------------------\n";
	
	int n = 3.24;
	int n2(3.33);
	
	
	int n10 {100};
	
	
	std::cout << "\n----------- MAKE UNIQUE -------\n";
	
	
	
	auto p = make_unique2<MyClass>();
	auto p2 = make_unique2<MyClass>(100);
	auto p3 = make_unique2<MyClass>(10,20);
	
		
	return 0;
}
	
	