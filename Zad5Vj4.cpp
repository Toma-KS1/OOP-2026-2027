#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    std::string jmbag;
    std::string surname;
    int points;
};

int main() {
std::vector<Student> registered{ {"0302", "Kovac", 78}, {"0117", "Babic", 45},
{"0255", "Maric", 91}, {"0117", "Babic", 45},
{"0410", "Novak", 78}, {"0089", "Juric", 62},
{"0255", "Maric", 91}, {"0520", "Maric", 55},
{"0333", "Peric", 30}};

std::sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
    if (a.jmbag == b.jmbag) {
        return a.surname < b.surname;
    }
    return a.jmbag < b.jmbag;
});
registered.erase(std::unique(registered.begin(), registered.end(), [] (const Student& a, const Student& b) {
    return a.jmbag == b.jmbag;
}), registered.end());
int i = 0;
for (auto& s : registered) {
    i++;
}
int prag;
std::cout << "prijavlejnih: " << i << std::endl;
std::cout << "Prag: ";
std::cin >> prag; 
registered.erase(
    std::remove_if(registered.begin(), registered.end(),
                   [prag](const Student& s) { return s.points < prag; }),
    registered.end());
std::sort(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
    if (a.points == b.points) {
        return a.surname < b.surname;
    }
    return a.points > b.points;
});
i = 0;
for (auto& s : registered) {
    i++;
    std::cout << i << ". " << s.surname << " (" << s.jmbag << ") " << s.points << std::endl;
}
return 0;
}