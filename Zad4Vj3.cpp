#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& korisnik, std::string& domena) {
    std::size_t at = email.find('@');
    if (at == std::string::npos) return false;
    if (email.rfind('@') != at) return false;

    if (at == 0) return false;
    if (at == email.size() - 1) return false;

    std::size_t tocka = email.find('.', at + 1);
    if (tocka == std::string::npos) return false;
    if (tocka == email.size() - 1) return false;

    korisnik   = email.substr(0, at);
    domena = email.substr(at + 1); 
    return true;
}

int main() {
    std::string email;
    std::cout << "Unesi e-mail adresu: ";
    std::getline(std::cin, email);

    std::string korisnik, domena;
    if (split_email(email, korisnik, domena)) {
        std::cout << "Korisnik: " << korisnik << std::endl;
        std::cout << "Domena: " << domena << std::endl;
    } else {
        std::cout << "Neispravna e-mail adresa." << std::endl;
    }
    return 0;
}