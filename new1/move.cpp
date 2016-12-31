#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class MyClass
{
	public:
		MyClass(int n) : m_N(n) {}
		virtual ~MyClass(){}
		
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
	
	MyClass n = std::move(m);
	std::cout << "n.n() = " << m.n() << std::endl;

	return 0;
}
