#include <iostream>
#include <vector>

void input_vector(std::vector<int>& v){
	int i = 5;
	while (i != 0) {
		std::cin >> i;
		if (i == 0) { return; }
		v.push_back(i);
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
	}
}

void print_vector(std::vector<int>& v) {
	for (const auto& broj : v) std::cout << broj << std::endl;
	for (auto it = v.rbegin(); it != v.rend(); ++it) std::cout << *it << std::endl;
}






int main() {
	std::vector<int> brojevi{};
	brojevi.reserve(100);
	input_vector(brojevi);
	brojevi.shrink_to_fit();
	std::cout << brojevi.capacity() << std::endl;
	print_vector(brojevi);

	return 0;
}