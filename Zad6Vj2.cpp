#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct Student {
    std::string ime;
    std::string jmbag;
    int godina;
    int ects;
    double prosjek;
};
void ispisi_studenta(Student& s) {
    std::cout << std::left << std::setw(12) << s.ime
              << " JMBAG: " << s.jmbag
              << " Godina: "  << s.godina
              << " ECTS: "  << s.ects
              << " Prosjek: "   << s.prosjek
              << '\n';
}
void uvecaj_godinu(Student& s) {
    ++s.godina;
}
void filter_students(Student s[], int n,
                     void (*action)(Student&),
                     bool (*cond)(const Student&))
{
    for (int i = 0; i < n; i++)
        if (cond(s[i]))
            action(s[i]);
}

int main() {
    Student studenti[] = {
        {"Ana",  "0036500001", 1, 42, 4.1},
        {"Marko", "0036500002", 1,  0, 2.0},
        {"Ivana", "0036500003", 1, 60, 3.8},
        {"Petar",  "0036500004", 1, 48, 3.2},
        {"Lucija", "0036500005", 1, 30, 3.9},
        {"Tomislav","0036500006",1, 20, 2.7},
    };
    int n = sizeof(studenti) / sizeof(studenti[0]);
    std::cout << "Svi studenti s prve godine koji su polozili barem jedan ispit" << std::endl;
    filter_students(studenti, n,
        ispisi_studenta,
        [](const Student& s) { return s.godina == 1 && s.ects > 0; });

    std::cout << "Svi studenti s prosjekom vecim od 3.5" << std::endl;
    filter_students(studenti, n,
        ispisi_studenta,
        [](const Student& s) { return s.prosjek > 3.5; });

    std::cout << "Povecaj godinu studija svim studentima koji su polozili barem 45 ECTS bodova" << std::endl;
    filter_students(studenti, n,
        uvecaj_godinu,
        [](const Student& s) { return s.ects >= 45; });
    std::cout << "Nakon povecane godine" << std::endl;
    for (int i = 0; i < n; i++)
        ispisi_studenta(studenti[i]);

    return 0;
}