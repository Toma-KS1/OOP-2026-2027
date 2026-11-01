#include <iostream>
#include <vector>
#include <algorithm>

bool starts_with(const std::string& s, const std::string& prefix) {
    return std::equal (prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix) {
    return std::equal (suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    int i = 0;
    std::vector<std::string> dat = {
        "vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt" , "vjezba03.cpp"
    };
    for (const auto& s : dat) {
        if (ends_with(s, ".cpp")) {
            i++;
        }
    }
    for (const auto& s : dat) {
        if (starts_with(s, "vjezba")) {
            dat.erase(std::remove(dat.begin(), dat.end(), s), dat.end());
        }
    }
    std::cout << ".cpp datoteka: " << i << std::endl;
    for (const auto& s : dat) {
        std::cout << s << " ";
    }
    return 0;
}