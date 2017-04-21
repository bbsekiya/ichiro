#include <iostream>
#include <vector>
#include <algorithm>


void purr() { std::cout << "purr\n"; }
void meow() { std::cout << "meow\n"; }

int x1() { return 1; }
double d1() { return 99.99; }


void woof( void (*fp)() ) {
	(*fp)();
}

#if 0
void woof2(auto (*fp)() {
	
}
#endif

auto lambda2 = [](const int& n) { return n * 10; };

int main()
{
	void (*fp)() = &purr;
	
	woof(fp);
	
	fp = &meow;
	
	woof(fp);
	
	
	auto (*fp2)() = &purr;
	woof(fp2);
	
	auto (*fp3)() = &x1;
	
	std::cout << "\n-----------------------------------------\n\n";
	
	std::vector<int> v = {10,2,3,8,9,44,4,100,999};
	
	std::sort(v.begin(), v.end());
	
	std::transform(v.begin(), v.end(), v.begin(), [](const int& n){ return n+1000; });

	for (const auto& i : v) {
		std::cout << i << " , " ;
	}
	std::cout << "\n--------------------------------\n\n";
	
	auto lambda = [](const int& n) { return n * 2; };
	std::transform(v.begin(), v.end(), v.begin(), lambda);
	
	
	for (const auto& i : v) {
		std::cout << i << " , " ;
	}
	
	std::cout << std::endl;
	
	
std::cout << "\n--------------------------------\n\n";
	
	std::transform(v.begin(), v.end(), v.begin(), lambda2);
	
	
	for (const auto& i : v) {
		std::cout << i << " , " ;
	}
	
	std::cout << std::endl;	
	return 0;
}
	

