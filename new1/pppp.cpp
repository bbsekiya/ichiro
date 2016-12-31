#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>

struct Global {
	uint32_t		m_N1 = 100;
	uint32_t		m_N2 = 200;
};

template <typename T>
void setGlobal(std::vector<T>& v)
{
	static_assert(std::is_integral<T>::value, "not integral");
	Global		g;
	
	auto const ptr = static_cast<T*>(static_cast<void*>(&g));
	v = std::vector<T> {ptr, ptr + sizeof(g)};
}




template <size_t T>
size_t func() {
	return T * T;
}


int main()
{
	std::cout << "func<10>() = " << func<10>() << std::endl;
	
	std::vector<uint8_t> v;
	setGlobal<uint8_t>(v);
	
	for (auto it=v.cbegin(); it!=v.cend(); it++) {
		printf("*it = %08x\n", *it);
	}
	
	std::vector<uint32_t> v2;
	setGlobal<uint32_t>(v2);
	
	#if 0
	std::vector<std::string> v3;
	setGlobal<std::string>(v3);
	#endif
	
	



	return 0;
}


	



