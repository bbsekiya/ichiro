#include <iostream>

template <typename T>
void ppp(const T& t) {
	std::cout << "T only : " << t << std::endl << std::endl;
}

template <typename T1, typename ...T2>
void ppp(const T1& t1, const T2& ...t2)  {
	std::cout <<"T1-T2 : :" << t1 << std::endl;
	ppp(t2...);
}


int main()
{
		ppp(10);
		std::cout << "\n==================\n";
		ppp(1,2);		
		std::cout << "\n==================\n";
		
		ppp(1,2,3,4);		
		std::cout << "\n==================\n";
		
		return 0;
}