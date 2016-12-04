#include <vector>
#include <iostream>

struct Header {
	static const int n1;

	
};
const int Header::n1(100);


struct GHeader {
    int n1;
	GHeader() : n1(999) {}
	
};





int main()
{
	std::cout << "Header::n1 = " << Header::n1 << std::endl;
}