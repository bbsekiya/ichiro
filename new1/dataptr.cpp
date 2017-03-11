#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class Data {

};

namespace data {

class DataSetter {
	public:
		virtual ~DataSetter() {}
		virtual void set(boost::shared_ptr<const Data>& p)  = 0;
};		
			

namespace version2 {
	class DataSetter : public data::DataSetter
	{
		public:
			DataSetter() {}
			virtual ~DataSetter() {}
			void set(boost::shared_ptr<const Data>& p) override {
				std::cout << "------ version2 : set ----------\n";
			}
	};

}

namespace version3 {
	class DataSetter : public data::DataSetter
	{
		public:
			DataSetter() {}
			virtual ~DataSetter() {}
			void set(boost::shared_ptr<const Data>& p) override {
				std::cout << "------ version2 : set ----------\n";
			}
	};

}
}



class ConvertData
{
	public:
		ConvertData(const uint32_t n=3) {
			if (n == 2) {
				dataSetter = boost::make_shared<data::version2::DataSetter>();
			} else if n(==3) {
				dataSetter = boost::make_shared<data::version3::DataSetter>();
			}
			else {
				//throw
			}
			
		}
		virtual ~ConvertData() {}
		
		void put(boost::shared_ptr<const Data>& p) {
			dataSetter->set(p);
		}
		
	private:
		boost::shared_ptr<data::DataSetter>	dataSetter;
};



int main()
{
	ConvertData		d1;
	boost::shared_ptr<const Data>	p = boost::make_shared<Data>();
	
	
	d1.put(p);
	
	ConvertData d3(3);
	
	d3.put(p);
	
	
}




	