#include <iostream>


void my_sort(int arr[], int n, bool (*cmp)(int, int)){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
        if (cmp(arr[j],arr[j+1])==false){
              int temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1]=temp;
        }
        }
    }

}

inline bool ascending(int a, int b){
    return a <= b;
}

inline bool descending(int a, int b){
    return a >= b;
}



int main(){
        int a[]={9,8,7,6,5,4,3,2,1};
        int broj = sizeof(a)/sizeof(a[0]);
        std::cout << "Niz na pocetku" << std::endl;
        for (int i = 0; i < broj; i++){
            std::cout << a[i] << std::endl;
        }
        my_sort(a, broj, ascending);
        std::cout << "Niz uzlazno:" << std::endl;
        for (int i = 0; i < broj; i++){
            std::cout << a[i] << std::endl;
        }
        my_sort(a, broj, descending);
        std::cout << "Niz silazno:" << std::endl;
        for (int i = 0; i < broj; i++){
            std::cout << a[i] << std::endl;
        }
        
        



    return 0;
}