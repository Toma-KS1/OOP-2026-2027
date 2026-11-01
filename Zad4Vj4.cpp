#include <iostream>
#include <vector>
#include <algorithm>

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(std::string& password){
    PasswordInfo info;
    info.length = password.length();
    info.digits = 0;
    info.uppercase = 0;
    info.special = 0;
    info.digits = std::count_if(password.begin(), password.end(), [](char c) { return std::isdigit(c); });
    info.uppercase = std::count_if(password.begin(), password.end(), [](char c) { return std::isupper(c); });
    info.special = std::count_if(password.begin(), password.end(), [](char c) { return std::ispunct(c); });
    return info;
}

bool is_strong(const PasswordInfo& info) {
    return (info.length >= 10 && info.digits >= 1 && info.uppercase >= 1 && info.special >= 1);
}

int main() {
    std::string password1 = "lozinka123";
    std::string password2 = "Lozinka123!";
    PasswordInfo info1 = analyze(password1);
    PasswordInfo info2 = analyze(password2);
    if ( is_strong(info1) ) {
        std::cout << password1 << ": duljina " << info1.length << ", znamenke " << info1.digits << ", velika " << info1.uppercase << ", posebni " << info1.special << " -> jaka" << std::endl;
    } else {
        std::cout << password1 << ": duljina " << info1.length << ", znamenke " << info1.digits << ", velika " << info1.uppercase << ", posebni " << info1.special << " -> slaba" << std::endl;
    }
    if ( is_strong(info2) ) {
        std::cout << password2 << ": duljina " << info2.length << ", znamenke " << info2.digits << ", velika " << info2.uppercase << ", posebni " << info2.special << " -> jaka" << std::endl;
    } else {
        std::cout << password2 << ": duljina " << info2.length << ", znamenke " << info2.digits << ", velika " << info2.uppercase << ", posebni " << info2.special << " -> slaba" << std::endl;
    }
    return 0;
}