#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class MyClass
{
	public:
		MyClass(int n) : m_N(n) {}
		virtual ~MyClass(){}
	
		MyClass(const MyClass& that) = delete;
		MyClass& operator=(const MyClass& that) = delete;
		
		MyClass(MyClass&& that) = delete;
		MyClass& operator=(MyClass&& that) = delete;

#if 0	
		MyClass(const MyClass& that) : m_N(that.m_N) {
			std::cout << "copy constructor\n";
		}
			
		MyClass& operator=(const MyClass& that) {
         if (this != &that) {
            m_N = that.m_N;
            std::cout << "--- assignment operator ---\n";
         }  
         return *this;
		}
		
		
		MyClass(MyClass&& that) : m_N(std::move(that.m_N)) {
			that.m_N = 0;
			std::cout << "move constructor\n";
		}
		 MyClass& operator=(MyClass&& that) {
         if (this != &that) {
            m_N = std::move(that.m_N);
            that.m_N = 0;
              std::cout << "--- move assignment operator ---\n";
         }
         return *this;
       }
	
#endif

		int n() const {
			return m_N;
		}
		void setN(int n) {
			m_N = n;
		}
		
	private:
		int m_N = 0;
};



int main()
{
	MyClass		m(100);
	std::cout << "m.n() = " << m.n() << std::endl;

	#if 0
	MyClass c = m;
	
	std::cout << "m.n() = " << m.n() << std::endl;
	std::cout << "c.n() = " << c.n() << std::endl;
	
	MyClass n = std::move(m);
	std::cout << "m.n() = " << m.n() << std::endl;
	std::cout << "n.n() = " << n.n() << std::endl;
	#endif
	
	
	boost::shared_ptr<MyClass> p1 = boost::make_shared<MyClass>(200);
	boost::shared_ptr<MyClass> c1 = p1;
	if (p1 == nullptr) {
		std::cout << "(afer copy) p1 == nullptr\n";
		exit(1);
	}
	
	
	std::cout << "p1->n() = " << p1->n() << std::endl;
	std::cout << "c1->n() = " << c1->n() << std::endl;
	
	
	boost::shared_ptr<MyClass> m1 = std::move(p1);
	if (p1 == nullptr) {
		std::cout << "(afer move) p1 == nullptr\n";
		exit(1);
	}
	std::cout << "p1->n() = " << p1->n() << std::endl;
	std::cout << "m1->n() = " << m1->n() << std::endl;
	
	
	
	return 0;
}
