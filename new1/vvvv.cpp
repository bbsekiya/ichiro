#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>


class Base
{
	public:
		Base() {}
};

class Derived: public Base
{
	public:
		Derived(int n) : Base(), m_N(n) {}
		virtual ~Derived() {}
		
		int n() const { return m_N; }
	private:
		int m_N = 0;
};

class Derived2 : public Base
{
	public:
		Derived2(std::string s) : Base(), m_S(s) {}
		virtual ~Derived2() {}
		
		std::string s() const { return m_S; }
	private:
		std::string m_S = "";
};


int main()
{
	std::vector<boost::shared_ptr<Base>> v;
	boost::shared_ptr<Derived> d1 = boost::make_shared<Derived>(100);
	d1->n();
	v.push_back(d1);
	v[0]->n();
	
	
	#if 0
	v.push_back(boost::make_shared<Derived>(100));
	v.push_back(boost::make_shared<Derived2>("ABC"));
	
	std::cout << v[0]->n() << std::endl;
	std::cout << v[1]->s() << std::endl;
	#endif
	
	return 0;
}