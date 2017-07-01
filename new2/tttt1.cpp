#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

struct MyTemp {
	int n = 999;
};

struct MyData {
	int n = 100;
};
typedef boost::shared_ptr<MyData> MyDataPtr;
typedef boost::shared_ptr<const MyData> ConstMyDataPtr;


struct TTT {
	int		n1 = 100;
	int		n2 = 200;
	TTT() {}
	TTT(int n) : n1(n) {}
	~TTT() {}
	
	void setN1(int n) { n1 = n; }
	int n() const { return n1; }

	void display() const {
		std::cout << "n1 = " << n1 << std::endl;
	}
	static constexpr int xxx = 111111;
};

int main()
{
	ConstMyDataPtr p = boost::make_shared<MyData>();
	
	MyData	m2;
	m2.n = 888;
	
	std::cout << "p->n = " << p->n << std::endl;

	p = boost::make_shared<MyData>(m2);
	std::cout << "p->n = " << p->n << std::endl;
	
	std::cout << "sizeof(TTT) : " << sizeof(TTT) << std::endl;
	
	std::cout << "\n============================================\n\n";
	
	auto p2 = boost::make_shared<const MyData>();
	p2 = boost::make_shared<MyData>();
	
	//p2->n = 999;
	
	
	return 0;
}