#include <iostream>

namespace geo
{
    double PI = 3.14;
}

double area(double r){
    return geo::PI*r*r;
}

double area(double a, double b){
    return a*b;
}

int area(int a){
    return a*a;
}

void print_line(char c = '-', int length = 30){
    std::cout << std::string(length, c) << '\n';
}

int main() {
      // Pretpostavka: za area(5) je a*a, za area(5.0) je PI*r*r, za area(2,3) je a*b a za area('A') ce se A prevest u broj pa racunati a*a
      std::cout << area(5) << std::endl;
      std::cout << area(5.0) << std::endl;
      std::cout << area(2,3) << std::endl;
      std::cout << area('A') << std::endl;
      return 0;
}