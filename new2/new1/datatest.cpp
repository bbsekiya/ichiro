#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <cstring>

template <typename T>
void pack(std::vector<uint8_t>&buffer, const T& h1) {
	auto const ptr = (uint8_t*)(&h1);
	buffer = std::vector<uint8_t>{ptr, ptr+sizeof(h1) };
}

template <typename T>
void unpack(const std::vector<uint8_t>&buffer, T& h2) {
	std::copy(buffer.cbegin(), buffer.cend(), reinterpret_cast<uint8_t*>(&h2));
}

template <typename T>
void append(std::vector<uint8_t>&buffer, const T& h1) {
	auto const ptr = (uint8_t*)(&h1);
	auto source_buffer = std::vector<uint8_t>{
		ptr, ptr + sizeof(h1) };
	buffer.insert(std::end(buffer), std::begin(source_buffer), std::end(source_buffer));
}

struct PrimaryHeader {
	uint32_t	m_Sync = 0xdeadbeef;
	//std::array<char, 32> m_Name;
	char	m_Name[32];
	
	PrimaryHeader() {
		strncpy(m_Name, "ABC", 3);
		m_Name[4] = 0;
	}
};

struct ChannelHeader {
	uint32_t	m_Ch1 = 100;
	uint32_t	m_Ch2 = 200;
};

struct Header {
	PrimaryHeader	m_PrimaryHeader;
	uint32_t		m_HeaderNum = 999;
	std::vector<ChannelHeader> m_ChannelHeader;
};


int main()
{
	std::cout << "sizeof(PrimaryHeader) : " << sizeof(PrimaryHeader) << std::endl;
	std::cout << "sizeof(Header) : " << sizeof(Header) << std::endl;
	
	std::vector<uint8_t> v;
	Header	h;
	#if 1
	h.m_PrimaryHeader.m_Sync = 0x12345678;
	strncpy(h.m_PrimaryHeader.m_Name, "SEKIYA", 6);
	h.m_PrimaryHeader.m_Name[7] = 0;
	h.m_HeaderNum = 888;
	
	#endif

	pack(v, h);
	std::cout << "v.size() = " << v.size()  << std::endl;
	
	
	Header	h2;
	
	unpack(v, h2);
	printf("h2.m_PrimaryHeader.m_Sync = %08x\n", h2.m_PrimaryHeader.m_Sync);
	printf("h2.m_PrimaryHeader.m_Name = %s\n", h2.m_PrimaryHeader.m_Name);

	printf("h2.m_HeaderNum = %d\n", h2.m_HeaderNum);
	

	
	
	
	
	
	
	return 0;
}

