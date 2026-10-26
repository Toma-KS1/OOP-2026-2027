#include <iostream>
#include <string>
#include <vector>

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
    std::string text;
    std::getline(std::cin, text);
    std::vector<std::string> rijeci = split_words(text);
    std::cout << "broj rijeci: " << rijeci.size() << std::endl;
    if (!rijeci.empty()) {
        const std::string* najduza = &rijeci[0];
        for (const auto& w : rijeci) {
            if (w.size() > najduza->size()) najduza = &w;
        }
        std::cout << "najdulja: " << *najduza << std::endl;
    }
    std::string povezani;
    for (auto it = rijeci.rbegin(); it != rijeci.rend(); ++it) {
        if (!povezani.empty()) povezani += '-';
        povezani += *it;
    }
    std::cout << povezani << std::endl;
    if (!rijeci.empty()) {
        const std::string* prva = &rijeci[0];
        for (const auto& w : rijeci) {
            if (w < *prva) prva = &w;
        }
        std::cout << "prva po abecedi: " << *prva << std::endl;
    }
    return 0;
}