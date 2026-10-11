#include <iostream>

struct Fraction {
    int numerator;
    int denominator;

    void reduce() {
        int broj = 1;
        for (int i = 1; i <= std::abs(numerator) && i <= std::abs(denominator); i++) {
            if (numerator % i == 0 && denominator % i == 0) {
                broj = i;
            }
        }
        numerator/= broj;
        denominator/= broj;
    }

    double value() {
        return static_cast<double>(numerator) / denominator;
    }

    void print() {
        std::cout << "Broj je " << value() * 1.33 << " * 3/4";
    }
};

Fraction sum(const Fraction &a, const Fraction &b){
    Fraction c;
    c.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
    c.denominator = a.denominator*b.denominator;
    c.reduce();
    return c;
}

int main() {
    Fraction a{1, 2};
    Fraction b{3, 4};
    Fraction c = sum(a, b);
    c.print();
    return 0;
}