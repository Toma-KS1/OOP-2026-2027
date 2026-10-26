#include <vector>
#include <algorithm>
#include <iostream>








int main() {
    // a ima 5 elemenata, b ima jedan element
    //std::vector<int> a(5); 
    //std::vector<int> b{5};
    int n;
    std::cout << "Unesi broj dana: ";
    std::cin >> n;
    std::vector<float> tempe{};
    tempe.resize(n);
    float x;
    int brojac = 0;
    while (brojac<n){
        std::cin >> x;
        tempe[brojac] = x;
        brojac++;
    }
    std::vector<float> promtemp{};
    tempe.resize(n);
    for (auto it = tempe.begin(); it != tempe.end(); ++it){
        if (it != tempe.begin()){
            promtemp.push_back(*it - *(it-1));
        }
    }
    std::cout << "Promjene:";
    for (const auto& broj : promtemp) std::cout << broj << " ";
    std::cout << std::endl;
    std::vector<float> izvjestaj{};
    for (const auto& broj : tempe){
        izvjestaj.push_back(broj);
    }
    if (izvjestaj.size()<7){
        auto it = tempe.back();
        while (izvjestaj.size()<7){
            izvjestaj.push_back(it);
        }
    }
    izvjestaj.resize(7);
    std::cout << "Izvjestaj: ";
    for (const auto& broj : izvjestaj) std::cout << broj << " ";
    //for (const auto& broj : a) std::cout << broj << " ";
    //for (const auto& broj : b) std::cout << broj << " ";
}