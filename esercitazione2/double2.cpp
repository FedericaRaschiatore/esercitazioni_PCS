#include <iostream>
#include <cmath>
#include <algorithm> 

int main()
{
    static const int N = 10; 
    double arr[N]={1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0};
    double somma=sum(arr);
    double somma= std::accumulate(arr.begin(),arr.end(),0.0);
    double media=somma/N;
    std::cout << min(arr) <<"\n";
    std::cout << max(arr) <<"\n";
    std::cout << media <<"\n";
    double somma_scarti=0;
    for (int i=0; i<N, i++) {
        somma_scarti+=std::pow(arr[i]-media,2);
    }
    double dev= sqrt(somma_scarti/N);
    std::cout <<dev<< "\n";
    return 0;


}