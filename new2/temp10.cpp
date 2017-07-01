#include <iostream>

template <typename T>
struct Temp {
	T	n1;
};

int main()
{
	int	n = 100;
	
	if (n == 100) {
		Temp<int>		t1;
	} else {
		Temp<double>	t2;
	}
		

	return 0;
}