#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> rijeci;
    std::size_t i = 0;
    while (i < text.size()) {
        while (i < text.size() && text[i] == ' ') ++i;
        if (i >= text.size()) break;
        std::size_t end = text.find(' ', i);
        if (end == std::string::npos) end = text.size();
        rijeci.push_back(text.substr(i, end - i));
        i = end;
    }
    return rijeci;
}

int main() {
    std::vector<std::string> rijecnik = {
        "programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije", "jednostavan", "za", "pocetnike" 
    };
    int i = 0;
    std::vector<std::string> nepoznate;
    std::sort(rijecnik.begin(), rijecnik.end());
    std::string recenica;
    std::cout << "Recenica: ";
    std::getline(std::cin, recenica);
    std::vector<std::string> rijeci = split_words(recenica);
    auto izbrisi = [](const char& c) { return c == '.' || c == ','; };
    for (auto& rijec : rijeci) {
        rijec.erase(std::remove_if(rijec.begin(), rijec.end(), izbrisi), rijec.end());
        for (char& c : rijec) {
            c = std::tolower(c);
        }
    }
    for (auto& rijec : rijeci) {
        bool pronadjena = std::binary_search(rijecnik.begin(), rijecnik.end(), rijec);
        if (!pronadjena) {
            nepoznate.push_back(rijec);
            i++;
        }
    }
    std::cout << "nepoznatih rijeci: " << i;
    for (auto& rijec : nepoznate) {
        std::cout << " " << rijec;
    }

}