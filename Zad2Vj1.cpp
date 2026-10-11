#include <iostream>

int main() {
    int ime = {};
    int prezime = {};
    int godrod = {};
    int pocetakprezime = {};
    int i = 0;
    int j = 0;
    std::string imeiprezime;
    std::cout << "Godina rodenja: ";
    std::cin >> godrod;
    std::cin.ignore();
    std::cout << "Ime i prezime: ";
    std::getline(std::cin, imeiprezime);
    int dob = 2026-godrod;
    for (auto& ch : imeiprezime) {
        i++;
        j++;
        if (ch == ' '){
            pocetakprezime = i;
            j--;
        }
    }
    std::cout << "Inicijale: " << imeiprezime[0] << ". " << imeiprezime[pocetakprezime] << ".\n";
    std::cout << "Broj znakova bez razmaka: " << j << "\n";
    std::cout << "Dob: " << dob;
    return 0;
}