#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>



std::vector<int> make_vector(std::size_t n) {
	return std::vector<int>(n);
}

int main()
{
	#if 0
	boost::shared_ptr<int> p1 = nullptr;
	boost::shared_ptr<int> p2 = NULL;
	boost::shared_ptr<int> p3 = 0;
	//boost::shared_ptr<int> p4 = 99;
	
	//int a = nullptr;
	
	int x = 100;
	
	int y = std::forward<int>(x);
	
	x = 300;
	
	std::cout << "x = " << x << " y = " << y << std::endl;
	
	#endif
	
	
	
	auto v = make_vector(5);
	std::cout << "v.size() = " << v.size() << std::endl;
	
	for (auto it=v.cbegin(); it<v.cend(); it++ ) {
		std::cout << *it << std::endl;
	}
	
	//auto ptr = std::make_unique<int>();
	
	
	
	return 0;
}