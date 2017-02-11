#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>


struct IData {
	uint32_t		m_IData1;
	uint32_t		m_IData2;
	uint32_t		m_IData3;
	
};
static_assert(sizeof(IData) == 12, "IData size != 12");

struct IData	idata[8];

#pragma pack(push, 4)
struct Data {
	uint32_t	m_Data1;
	struct IData* m_PIData;
} Data_t;
static_assert(sizeof(Data) == 12, "Data size != 12");
#pragma pack(pop)


#pragma pack(push, 4)
struct Data2 {
	uint32_t	m_Data1;
	std::vector<uint8_t> v;
	
} ;
//static_assert(sizeof(Data) == 12, "Data size != 12");
#pragma pack(pop)

#pragma pack(push, 4)
struct ddd
{
  std::vector<IData> points;
};
#pragma pack(pop)

int main()
{
	
	
	Data	d;
	
	std::cout << "sizeof(Data) : " << sizeof(Data) << std::endl;
	std::cout << "sizeof(Data_t) : " << sizeof(Data_t) << std::endl;

	std::cout << "sizeof(d) : " << sizeof(d) << std::endl;
	
	d.m_Data1 = 10;
	
	idata[0].m_IData1 = 100;
	idata[0].m_IData2 = 200;
	idata[0].m_IData3 = 300;
	idata[1].m_IData1 = 100;
	idata[1].m_IData2 = 200;
	idata[1].m_IData3 = 300;
	
	d.m_PIData = &idata[0];
	
	std::cout << "sizeof(d) : " << sizeof(d) << std::endl;
	
	
	std::cout << "sizeof(Data2) : " << sizeof(Data2) << std::endl;
	
	std::cout << "sizeof(ddd) : " << sizeof(ddd) << std::endl;
	
	
	return 0;
}
	