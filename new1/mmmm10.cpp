#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>

class MyClass
{
	public:
		MyClass() : m_Data(boost::make_shared<std::vector<int> >()) {
		
		}
		virtual ~MyClass() {}
		
		
	private:
		boost::shared_ptr<std::vector<int> > m_Data;
};


int main()
{
	MyClass		m;
	
	auto vptr = boost::make_shared<std::vector<int> >();
	
	return 0;
}