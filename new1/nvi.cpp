#include <vector>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class Shape
{
	public:
		Shape() {}
		virtual ~Shape() {}
		
		Shape(const Shape& that) = delete;
		
		
		// not a virtual function , see comments on do_draw()
		// This is for NVI design
		void draw() {
			std::cout << "non-virtual Shape::draw() \n";
			
			do_draw();
			
			std::cout << "End of draw()\n";
		}
		
	private:
		// private pure virtual for NVI 
		virtual void do_draw() = 0;
};	

class Square : public Shape
{
	public:
		Square() {}
		virtual ~Square() {}
	
	private:
		void do_draw() override final {
			std::cout << "Square::do_draw() \n";
		}
};


int main()
{
	boost::shared_ptr<Shape> p = boost::make_shared<Square>();
	
	p->draw();
	
	return 0;
}
	