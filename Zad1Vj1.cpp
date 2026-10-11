#include <iostream>
#include <iomanip>

int main() {
	int a{};
	int b{};
	std::cin >> a >> b;
	std::cout << "Zbroj:" << a + b << '\n';
	std::cout << "Ar. sredina:" <<  (a+b)/2.0 << '\n';
	std::cout << "b vece od a:" << bool(a<b) << '\n';
}