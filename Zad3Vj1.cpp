#include <iostream>

int& find_max(int arr[], int n){
    int najveci = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > arr[najveci]) {
            najveci = i;
        }
    }
    return arr[najveci];
}


int main() {
    int numbers[] = {4, -7, 12, 0, 9, -3};
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << "Broj " << i+1 << " = " << numbers[i] << std::endl;
        if (numbers[i] < 0) {
            numbers[i] = -numbers[i];
        }
    }
    find_max(numbers, sizeof(numbers)/sizeof(numbers[0])) = 0;
    for (int i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        std::cout << "Broj " << i+1 << " = " << numbers[i] << std::endl;
    }
    return 0;
}