#include <iostream>

inline double add(double a, double b){
    return a+b;
}

inline double subtract(double a, double b){
    return a-b;
}

inline double divide(double a, double b){
    if(b==0){
        std::cout << "Zabranjeno dijeljenje s nulom" << std::endl;
        return 0;
    }
    return a/b;
}

inline double multiply(double a, double b){
    return a*b;
}

int main(){
    using j = double(*)(double, double);
    j i[4] = {add, subtract, divide, multiply};
    int a; int b; int l;
    std::cin >> a;
    std::cin >> b;
    std::cin >> l;
    std::cout << i[l](a,b) << std::endl;
}