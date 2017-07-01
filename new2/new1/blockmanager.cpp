#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>
#include <cstring>

class DataBlockManagerOld {
	public:
		DataBlockManagerOld(uint32_t version=3): m_Version(version){}
		virtual ~DataBlockManagerOld() {}
		
		void initHeader() {
			
			
		}
	private:
		uint32_t 	m_Version = 3;

};

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

namespace root {
	
		struct PrimaryHeaderBlock {
			uint32_t	m_Sync = 0xdeadbeef;
			char		m_Name[32];
			
			PrimaryHeaderBlock() {
				strncpy(m_Name, "Leslie", 6);
				m_Name[6] = 0;
			}
		};
		
		struct ChannelHeaderBlock {
			uint32_t	m_Channel1;
			uint32_t	m_Channel2;
		};
		
	class DataBlockManager {
		public:
			virtual ~DataBlockManager() {}
			virtual void initHeader() = 0;
			virtual void setHeader() = 0;
			virtual void setMessage() = 0;
	};
}

namespace version2 {
	
		struct HeaderBlock {
			root::PrimaryHeaderBlock	m_PrimaryHeaderBlock;
			uint32_t					m_Index;
			std::vector<root::ChannelHeaderBlock> m_ChannelHeaderBlock;
		};
		
		class DataBlockManager : public root::DataBlockManager {
			public:
				DataBlockManager() {}
				virtual ~DataBlockManager() {}
				
				void initHeader() override {
					std::cout << "------ version2: initHeader() --------\n";
				}
				
				void setHeader() override {
					std::cout << "------ version2: setHeader() --------\n";
					
				}
				
				void setMessage() override {
					std::cout << "------- version2 : setMessage() ----------\n";
				}
				
		};

}


namespace version3 {
	
		struct HeaderBlock {
			root::PrimaryHeaderBlock	m_PrimaryHeaderBlock;
			uint32_t					m_Index = 120;
			std::vector<root::ChannelHeaderBlock> m_ChannelHeaderBlock;
		};
		
		struct MessageBlock {
			uint32_t	m_Message1;
			uint32_t	m_Message2;
			std::vector<uint16_t>	m_DataWords;
		};
		
		struct DataBlock {
			uint32_t	m_Data1;
			std::vector<MessageBlock> m_Messages;
		};
		
		class DataBlockManager : public root::DataBlockManager {
			public:
				DataBlockManager() {}
				virtual ~DataBlockManager() {}
				
				void initHeader() override {
					
					std::cout << "------ version3: initHeader() --------\n";

					std::vector<uint8_t> v;
					
					HeaderBlock header_block;
					header_block.m_PrimaryHeaderBlock.m_Sync = 0x12345678;
					printf("(1) header_block.m_PrimaryHeaderBlock.m_Sync = %08x\n", header_block.m_PrimaryHeaderBlock.m_Sync);
					
					pack(v, header_block.m_PrimaryHeaderBlock);
					
					header_block.m_PrimaryHeaderBlock.m_Sync = 0xdeadabcd;
					printf("(2) header_block.m_PrimaryHeaderBlock.m_Sync = %08x\n", header_block.m_PrimaryHeaderBlock.m_Sync);
					
					unpack(v, header_block.m_PrimaryHeaderBlock);
					printf("(3) header_block.m_PrimaryHeaderBlock.m_Sync = %08x\n", header_block.m_PrimaryHeaderBlock.m_Sync);
					
					append(v, header_block.m_Index);
					printf("(4) header_block.m_PrimaryHeaderBlock.m_Sync = %08x\n", header_block.m_PrimaryHeaderBlock.m_Sync);
					printf("(4) header_block.m_PrimaryHeaderBlock.m_Index = %d\n", header_block.m_Index);
					
				}
				
				void setHeader() override {
					std::cout << "------ version3 : setHeader() --------\n";
					
				}
				void setMessage() override {
					std::cout << "------- version3 : setMessage() ----------\n";
				}
		};

}


int main()
{
	version3::DataBlockManager  manager3;
	
	manager3.initHeader();
	
	
	return 0;
}