#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // per sostituire inf in merge
#include <string>
#include <cstdlib> // Per rand() e srand()
#include <ctime>   // Per time()
#include "timecounter.h"

template <typename T>
int partition(T A[], int p, int r) {
    T x = A[r];          // Il pivot è l'ultimo elemento
    int i = p - 1;         // Indice degli elementi più piccoli del pivot

    for (int j = p; j <= r - 1; j++) {
        if (A[j] <= x) {
            i = i + 1;
            std::swap(A[i], A[j]);
        }
    }
    
    std::swap(A[i + 1], A[r]);
    
    return i + 1;
}

template <typename T>
void quickSort(T A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);

        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}




int main() {         
    srand(time(0));
    timecounter timer; 
    double tempo_totale = 0;
    double tempo_totale_sort=0;

    for (int i = 0; i < 100; ++i) {
        // Dimensione casuale tra 10 e 100
        int dimensione = rand() % 91 + 10; 
        std::vector<int> v;
        v.reserve(dimensione);

        // Riempire con numeri tra -1000 e 1000
        for (int j = 0; j < dimensione; ++j) {
            int valore = rand() % 2001 - 1000; 
            v.push_back(valore);
        }
        std::vector<int> v_copy = v;

        timer.tic();
        // Ordiniamo il vettore
        quickSort(v.data(), 0, v.size()-1);
        tempo_totale += timer.toc();

        timer.tic();
        std::sort( v_copy.begin(), v_copy.end() );
        tempo_totale_sort += timer.toc();
    }
        
    std::cout << "Tempo totale per 100 ordinamenti: " << tempo_totale << " secondi\n";
    std::cout << "Tempo medio per 100 ordinamenti: " << tempo_totale/100 << " secondi\n";  
    std::cout << "Tempo totale per 100 ordinamenti usando sort: " << tempo_totale_sort << " secondi\n";
    
    std::vector<std::string> parole = {
        "zaino", "penna", "gomma", "matita", "acqua", 
        "forchetta", "pranzo", "quaderno", "libro", "bottiglia"
    };

    quickSort(parole.data(), 0, (int)parole.size() -1);
    for (const std::string& p : parole) {
    std::cout << p << " ";
    }
    std::cout << std::endl;

    return 0;
}