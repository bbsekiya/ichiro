#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


std::vector<uint8_t> makeVector(const std::size_t size) {
   return std::vector<uint8_t>(size);
}

#define MAX_CHANNEL     10

struct ChannelInfo {
   uint32_t    m_Ch1 = 100;
   uint32_t    m_Ch2 = 200;
};

struct ChannelInfo   channels[MAX_CHANNEL];


struct HeaderInfo {
   uint32_t    m_H1 = 66;
   uint32_t    m_H2 = 67;
   
   struct ChannelInfo* m_Channels;
   
};

int main()
{
   auto v = makeVector(10);
   std::cout << "v.size() = " << v.size() << std::endl;
   
   HeaderInfo  header;
   header.m_Channels = &channels[0];
   
   std::cout << "sizeof(header) = " << sizeof(header) << std::endl;
   
   return 0;
} 
   


