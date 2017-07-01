#include <string>
#include <memory>
#include <iostream>


struct ChannelHeader {
	uint32_t	m_C1 = 100;
};


struct Header {
	 ChannelHeader *m_ChannelHeader;
};

int main()
{
	Header	h;
		std::cout << "sizeof(h) : " << sizeof(h) << std::endl;

	std::cout << "sizeof(Header) : " << sizeof(Header) << std::endl;
	
	h.m_ChannelHeader = new ChannelHeader[8];
	
	std::cout << "sizeof(h) : " << sizeof(h) << std::endl;

	return 0;
}