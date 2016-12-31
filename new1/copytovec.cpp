#include <iostream>
#include <vector>


// td::vector<ValueType> vec(a, a + n);



int main()
{
	char source[] = "1234567890";
	char *mem = &source[0];
	
	std::cout << "*mem = " << *mem << std::endl;
	
	std::vector<uint8_t> vec(mem, mem+10);
	
	for (auto it=vec.cbegin(); it!=vec.cend(); it++) {
			std::cout << *it << std::endl;
	}
	
	return 0;
}
	