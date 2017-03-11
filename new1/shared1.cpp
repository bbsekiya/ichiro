#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


int main()
{
	auto p = boost::make_shared<int>(10);
	
	p = boost::make_shared<int>(17);
	
	std::cout << "*p = " << *p << std::endl;
	std::cout << "p.use_count() = " << p.use_count() << std::endl;
	
	auto p2 = p;
	std::cout << "p.use_count() = " << p.use_count() << std::endl;
	std::cout << "p2.use_count() = " << p2.use_count() << std::endl;
	
	p = boost::make_shared<int>(8888);
	std::cout << "p.use_count() = " << p.use_count() << std::endl;
	std::cout << "p2.use_count() = " << p2.use_count() << std::endl;
	
	std::cout << "\n---------- const test ------------------\n";
	
	const auto p10 = boost::make_shared<int>(1000);
	std::cout << "p10.use_count() = " << p10.use_count() << std::endl;
	//p10 = p;
	//p10 = boost::make_shared<int>(2000);
	auto p11 = p10;
	std::cout << "p10.use_count() = " << p10.use_count() << std::endl;
	std::cout << "p11.use_count() = " << p11.use_count() << std::endl;
	p11 = p;

	
	
	
	
	return 0;
}