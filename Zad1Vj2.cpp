
#include <iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b) {
	return (a > b) ? a : b;
}

template<typename T>
void my_maxT(T a, T b) {
	auto g = (a > b) ? a : b;
	std::cout << b << std::endl;
}

int main()
{
	//Pretpostavka: kad bi MAX(a,b) bio pravilno napisan a = 5, b = 10 i c = 6
	// inline i makro funkcija obavljaju istu funkciju, ali za makro funkciju se ++i se poziva 2 puta pa se povecava za 2 dok se za inline funkciju ++i poziva samo jednom i povecava se samo jednom
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;
	int i = 3;
	std::cout << a << b << c << std::endl;
	std::cout << i << std::endl;
	std::cout << MAX(++i, 2) << std::endl;
	std::cout << i << std::endl;
	std::cout << my_max(++i, 2) << std::endl;
	std::cout << i << std::endl;
	my_maxT(3, 5);
	my_maxT(3.5, 5.5);
	my_maxT('a', 'b');
	my_maxT("jabuka", "banana");
}


