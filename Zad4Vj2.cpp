#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)){
      for (int i = 0; i < n; i++){
        arr[i]=f(arr[i]);
      }
}

int twice(int a){
    return (a*2);
}

int main(){
    //Lambda s kontekstom se ne moze predati funkciji zato sto se kontekst nece pamtiti
    int suma = 0;
    int produkt = 1;
    int prag = 5;
    int s = 0;
        int a[]={9,8,7,6,5,4,3,2,1};
        int broj = sizeof(a)/sizeof(a[0]);
        auto lambda = [](int a){return a%2==0 ? a/2 : a*2;};
        auto lambdaa = [&suma, &produkt](int a[], int broj){
             for (int i = 0; i < broj; i++){
                suma+=a[i];
                produkt*=a[i];
             }
        };
        auto lambdaaa = [prag, &s](int a[], int broj){
             for (int i = 0; i < broj; i++){
                if (a[i]>prag){
                    s+=a[i];
                }
             }
        };
        lambdaa(a, broj);
        lambdaaa(a, broj);
        std::cout << suma << std::endl;
        std::cout << produkt << std::endl;
        std::cout << s << std::endl;
        std::cout << "Prije funkcije: " << std::endl;
        for (int i = 0; i < broj; i++){
            std::cout << a[i] << std::endl;
        }
        my_transform(a, broj, lambda);
        std::cout << "Nakon funkcije: " << std::endl;
        for (int i = 0; i < broj; i++){
            std::cout << a[i] << std::endl;
        }
        return 0;
}