#include <iostream>
#if 0
template<typename T>
T adder(T v) {
  return v;
}

template<typename T, typename... Args>
T adder(T first, Args... args) {
  return first + adder(args...);
}

And here are a couple of ways we could call it:

long sum = adder(1, 2, 3, 8, 7);

std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
std::string ssum = adder(s1, s2, s3, s4);
#endif


template <typename T>
T adder(T t) {
	return t;
}

template <typename T, typename... Args>
T adder(T first, Args ...args) {
	return first + adder(args...);
}



int main()
{
	int x1 = adder(1,2,3,4,5,6,7,8,9);
	std::cout << "x1 = " << x1 << std::endl;
	
	std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
	std::string sum = adder(s1, s2, s3, s4);	
	std::cout << "sum = " << sum << std::endl;
	
	
	auto sum1 = adder(std::string("aaaaaaaaaa"), std::string("bbbbbbbbb")) ;
	std::cout << "sum1 = " << sum1 << std::endl;
	
	
	
	return 0;
}
