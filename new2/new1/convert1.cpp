#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>


struct SubData {
	int	n1 = 10;
	int n2 = 20;
	int n3 = 30;
	SubData() {}
	SubData(int x1, int x2) : n1(x1), n2(x2) {}
};
static_assert(sizeof(SubData) == 12, "sizeof(SubData) != 12");

struct Data1 {
	int m1 = 1;
	std::vector<SubData> m_subdata;
};

struct Data2 {
	int m1 = 1;
	std::vector<boost::shared_ptr<SubData> > m_subdata;
};

#pragma pack(push, 1)
struct Data3 {
	int	 m1 = 100;
	SubData* sub_data;
};
#pragma pop

#pragma pack(push, 1)
struct Data4 {
	int	 m1 = 100;
	std::vector<SubData> sub_data;
};
#pragma pop

int main()
{
	Data1	d1;
	
	Data2	d2;
	
	std::cout << "sizeof(Data3) = " << sizeof(Data3) << std::endl;
	
	
	
	std::cout << "\n------------------ Data3 --------------------\n";
	Data3 d3;
	SubData	sub;
	
	std::cout << "sizeof(SubData) : " << sizeof(SubData) << std::endl;
	
	
	d3.sub_data = &sub;
	
	std::cout << "d3.m1 = " << d3.m1 << std::endl;
	std::cout << "d3.sub_data->n1 = " << d3.sub_data->n1 << std::endl;
	std::cout << "d3.sub_data->n2 = " << d3.sub_data->n2 << std::endl;
	std::cout << "d3.sub_data->n3 = " << d3.sub_data->n3 << std::endl;
	
	std::vector<uint8_t> dst;
	uint8_t* src = static_cast<uint8_t*>(static_cast<void*>(&d3));
	dst.insert(dst.end(), src, src + sizeof(Data3));
	
	
	std::cout << " dst.size() : " << dst.size() << std::endl;
	
	std::cout << "\n------------------ Data4 --------------------\n";
	
	Data4	d4;
	d4.sub_data.push_back(sub);
	std::cout << "d4.m1 = " << d4.m1 << std::endl;
	for (auto it=d4.sub_data.cbegin(); it!=d4.sub_data.cend(); it++) {
		
		std::cout << "it->n1 = " << it->n1 << std::endl;
		std::cout << "it->n2 = " << it->n2 << std::endl;
		std::cout << "it->n3 = " << it->n3 << std::endl;
		
	}
	
	
	
	
	
	return 0;
}
