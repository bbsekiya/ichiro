#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>


class MyClass
{
	public:
		MyClass();
		
		virtual ~MyClass() {}
		
		void put(int n);
		
	private:
		int m_N = 0;
		
		struct Data;
		boost::scoped_ptr<Data> m_Data;
};

using data_v_t = std::vector<int>;
using ipe_t = boost::shared_ptr<data_v_t>;

struct MyClass::Data {
	//auto ip = nullptr;
	char* raw;
	
	Data() : raw(nullptr) 
	{}
};

MyClass::MyClass() : m_Data(new Data) {
	
}


void MyClass::put(int n) {
	data_v_t v;
	v.push_back(n);
	ipe_t p = boost::make_shared<data_v_t>(v);
	
	m_Data->raw = static_cast<char*>(static_cast<void*>(&n));
	
	printf("m_Data->raw = %08x]n", *(m_Data->raw));
	

}

int main()
{
	MyClass	m;
	
	m.put(15);
	
	auto ip = nullptr;
	
	
	return 0;
}

