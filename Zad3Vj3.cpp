#include <vector>
#include <algorithm>
#include <iostream>
#include <array>


constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours){
        double broj = 0.0;
        for (auto it = hours.begin(); it != hours.end(); ++it){
            broj=broj+*it;
        }
        return broj;
}

int best_day(const std::array<double, DAYS>& hours){
    int najdan = 0; 
    for (std::size_t i = 1; i < hours.size(); ++i) {
        if (hours[i] > hours[najdan]) {
            najdan = static_cast<int>(i);
        }
    }
    return najdan+1;

}





int main() {
    std::array<double, DAYS> tjedan1;
    double x;
    for (int i = 0; i < DAYS; i++){
        std::cout << "Unesi broj sati: " << std::endl;
        std::cin >> x;
        tjedan1[i]=x;
    }
    double broj = total(tjedan1);
    std::cout << broj << std::endl;
    int najdan = best_day(tjedan1);
    std::cout << najdan << std::endl;
    std::array<double, DAYS> tjedan2;
    tjedan2.fill(1.5);
    bool jednakost =(tjedan1==tjedan2);
    std::cout << "Jednaki?: " << jednakost << std::endl;
    bool manji = (tjedan1 < tjedan2);
    std::cout << "Tjedan1 manji?: " << manji << std::endl;
    std::swap(tjedan1, tjedan2);
    std::cout << "tjedan1: " << total(tjedan1) << std::endl;
    std::cout << "tjedan2: " << total(tjedan2) << std::endl;




    return 0;
}