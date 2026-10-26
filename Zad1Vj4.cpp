#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v) {
	int i = 5;
	std::cout << "Unesite brojeve (0 za kraj): ";
	while (i != 0) {
		std::cin >> i;
		if (i == 0) { return; }
		v.push_back(i);
		//std::cout << v.size() << std::endl;
		//std::cout << v.capacity() << std::endl;
	}
}

int main() {
	std::vector<int> brojevi{};
	int k;
	brojevi.reserve(100);
	input_vector(brojevi);
	std::cout << "k: ";
	std::cin >> k;
	int poz;
	auto negativni = std::count_if(brojevi.begin(), brojevi.end(), [](int x) {return x < 0; });
	std::cout << "negativnih: " << negativni << std::endl;
	auto prvivisekratnik = std::find_if(brojevi.begin(), brojevi.end(), [k](int x) {return x % k == 0; });
	std::cout << "prvi visekratnik od " << k << ": " << *prvivisekratnik  << " (pozicija " << prvivisekratnik - brojevi.begin() << ")" << std::endl;
	auto max = std::max_element(brojevi.begin(), brojevi.end());
	auto min = std::min_element(brojevi.begin(), brojevi.end());
	std::cout << "min " << *min << " (pozicija " << min-brojevi.begin() << "), " << "max " << *max << " (pozicija " << max-brojevi.begin() << ")" << std::endl;
	brojevi.erase(std::remove_if(brojevi.begin(), brojevi.end(),[k](int x) { return x % k == 0; }), brojevi.end());
	std::cout << "bez visekratnika: ";
	for (const auto& broj : brojevi) std::cout << broj << " ";

}