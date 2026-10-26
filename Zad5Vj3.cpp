#include <iostream>
#include <string>

std::string with_separators(std::string digits) {
    std::size_t start = (!digits.empty() && digits[0] == '-') ? 1 : 0;
    int brojac = 0;
    for (int i = static_cast<int>(digits.size()) - 1;
         i >= static_cast<int>(start); --i) {
        ++brojac;
        if (brojac == 3 && i > static_cast<int>(start)) {
            digits.insert(i, 1, '.');
            brojac = 0;
        }
    }
    return digits;
}

std::string without_separators(std::string text) {
    std::size_t poz;
    while ((poz = text.find('.')) != std::string::npos) {
        text.erase(poz, 1);
    }
    return text;
}

int main() {
    std::string s1 = "-1234567";
    std::string s2 = with_separators(s1);
    std::string s3 = "1234567";
    std::string s4 = with_separators(s3);
    std::string s5 = "100000";
    std::string s6 = with_separators(s5);
    std::cout << s3 << " -> " << s4 << "     ";
    std::cout << s1 << " -> " << s2 << std::endl;
    std::cout << s5 << " -> " << s6 << "     ";
    std::cout << s4 << " -> " << without_separators(s4) << std::endl;
    return 0;
}