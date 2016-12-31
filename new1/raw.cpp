#include <iostream>
#include <stdio.h>



int main()
{
	char* raw = nullptr;
	
	uint32_t* 	body = nullptr;
	
	char	data[] = "012345678901";
	
	for (auto i=0; i<sizeof(data) - 1; i++) {
		printf("%x : %c  -  %x : %c\n", data[i], *(data + i), data[i], *(data + i));
	}
	
	
	body = static_cast<uint32_t*>(static_cast<void*>(&data[0]));
	raw = static_cast<char*>(static_cast<void*>(&body[0]));
	
	for (uint32_t i=0; i<3; i++) {
		printf("body[i] = %x : %x\n", body[i], *(body + i));
	}
	
	std::cout << "\n -------- raw -----------\n";
	for (uint32_t i=0; i<12; i++) {
		printf("%x : %x\n", raw[i], *(raw+i));
	}
	
	return 0;
}