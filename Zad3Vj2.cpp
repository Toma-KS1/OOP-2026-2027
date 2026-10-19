#include <iostream>

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n - i - 1; j++){
        if (cmp(arr[j],arr[j+1])==false){
              T temp = arr[j];
              arr[j] = arr[j+1];
              arr[j+1]=temp;
        }
        }
    }

}

template <typename T>
inline bool ascending(T a, T b){
    return a <= b;
}

template <typename T>
inline bool descending(T a, T b){
    return a >= b;
}



int main(){
        //Ne radi ascending is prijašnjeg zadatka zato što radi po principu int a ne double, zato treba riješiti kao function template
        int c[]={9,8,7,6,5,4,3,2,1};
        int brojj = sizeof(c)/sizeof(c[0]);
        std::cout << "Niz na pocetku" << std::endl;
        for (int i = 0; i < brojj; i++){
            std::cout << c[i] << std::endl;
        }
        my_sort(c, brojj, ascending);
        std::cout << "Niz uzlazno:" << std::endl;
        for (int i = 0; i < brojj; i++){
            std::cout << c[i] << std::endl;
        }
        my_sort(c, brojj, descending);
        std::cout << "Niz silazno:" << std::endl;
        for (int i = 0; i < brojj; i++){
            std::cout << c[i] << std::endl;
        }
        double a[]={9.5,8.6,7.3,6.1,5.8,4.2,3.3,2.8,1.9};
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
        char b[]={'a','c','d','e','f','g','h'};
        int broj2 = sizeof(b)/sizeof(b[0]);
        std::cout << "Niz na pocetku" << std::endl;
        for (int i = 0; i < broj2; i++){
            std::cout << b[i] << std::endl;
        }
        my_sort(b, broj2, ascending);
        std::cout << "Niz uzlazno:" << std::endl;
        for (int i = 0; i < broj2; i++){
            std::cout << b[i] << std::endl;
        }
        my_sort(b, broj2, descending);
        std::cout << "Niz silazno:" << std::endl;
        for (int i = 0; i < broj2; i++){
            std::cout << b[i] << std::endl;
        }
        
        



    return 0;
}