#include <iostream>


#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

struct toString {
	template <typename T>
	std::string operator()(T t) const {
		std::stringstream ss;
		ss << "value:" << t;
		return ss.str();
	}
};
	



int main()
{
		std::vector<int> v {100,300,500,9999};
		std::vector<int> u;
		u.resize(v.size());
		
		std::transform(v.cbegin(), v.cend(), u.begin(), [](int n)->int { return ++n; });
		
		for (auto it=u.cbegin(); it!=u.cend(); it++) {
			std::cout << *it << std::endl;
		}
		
		std::cout << toString{}(3) << std::endl;
		std::cout << toString{}(5.3343) << std::endl;
		
		
		return 0;
}
