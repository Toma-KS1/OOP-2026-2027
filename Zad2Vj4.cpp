#include <iostream>
#include <vector>
#include <algorithm>

struct Song {
    std::string title;
    std::string artist;
    int year;
    int plays;
    void print_song(const Song& s) {
          std::cout << "Naslov: " << s.title << std::endl;
    }
    
};

int main() {
    std::vector <Song> pjesme = {
        {"Pjesma 1", "Izvodac 1", 2020, 100},
        {"Pjesma 2", "Izvodac 2", 2021, 200},
        {"Pjesma 3", "Izvodac 3", 2022, 300}
    };
    std::sort(pjesme.begin(), pjesme.end(),
        [](const Song& a, const Song& b) { 
            if (a.year == b.year) {
                return a.title > b.title;
            }
            return a.year < b.year; });

    for (auto& s : pjesme) {
        s.print_song(s);
    }
    std::cout << "Unesite izvodaca: ";
    std::string izvodac;
    std::getline(std::cin, izvodac);
    int brojac = 0;
    std::string najstarija;
    int najstarijagod = 5000;
    for (auto& s : pjesme) {
        if (s.artist == izvodac) {
            if (brojac == 0) {
                najstarija = s.title;
                najstarijagod = s.year;
                brojac++;
            }
            else if (s.year < najstarijagod) {
                najstarijagod = s.year;
                najstarija = s.title;
            }
            else {
                brojac++;
            }

        }
    }
    if (brojac == 0) {
        std::cout << "Taj izvodac nema pjesmu" << std::endl;
    } else {
        std::cout << brojac << ", " << najstarija << std::endl;
    }
    Song najslusanija;
    najslusanija.plays = 0;
    for (auto& s : pjesme) {
        if (s.plays > najslusanija.plays) {
            najslusanija = s;
        }
    }
    najslusanija.print_song(najslusanija);
    return 0;
}