#include <iostream>
#include <vector>

struct Data {
	int		n1 = 10;
	int		n2 = 20;
	
	Data(int s1, int s2) : n1(s1), n2(s2) {}
	
};

struct MyData {
	int		m_N1 = 100;
	
	std::vector<Data> v;
};



int main()
{
	MyData	m;
	m.v = {{1,2}, {3,4}};
	
	
	std::vector<uint8_t> v2;
	
	std::cout << "m.v.size() = " << m.v.size() << std::endl;
	
	
	
	
	return 0;
}