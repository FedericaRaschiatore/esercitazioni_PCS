#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> 
#include <string>
#include <cstdlib> 
#include <ctime>   
#include "timecounter.h"


template <typename T>
void merge(T A[], int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;


    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (int i = 0; i < n1; i++) L[i] = A[p + i];
    for (int j = 0; j < n2; j++) R[j] = A[q + 1 + j];

    int i = 0, j = 0, k = p;


    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }


    while (i < n1) { A[k] = L[i]; i++; k++; }
    while (j < n2) { A[k] = R[j]; j++; k++; }
}


template <typename T>
void mergeSort(T A[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2; // Calcolo sicuro del punto medio
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {         
    srand(time(0));
    timecounter timer; 
    double tempo_totale = 0;
    double tempo_totale_sort = 0;

    for (int i = 0; i < 100; ++i) {
        int dimensione = rand() % 91 + 10; 
        std::vector<int> v; // Rimosso (dimensione) per evitare zeri iniziali
        v.reserve(dimensione);

        for (int j = 0; j < dimensione; ++j) {
            v.push_back(rand() % 2001 - 1000);
        }
        std::vector<int> v_copy = v;

        timer.tic();
        // Correzione chiamata: nome e parametri
        mergeSort(v.data(), 0, (int)v.size() - 1);
        tempo_totale += timer.toc();

        timer.tic();
        std::sort(v_copy.begin(), v_copy.end());
        tempo_totale_sort += timer.toc();
    }
        
    std::cout << "Tempo totale MergeSort: " << tempo_totale << " s\n";
    std::cout << "Tempo medio MergeSort: " << tempo_totale/100 << " s\n";
    std::cout << "Tempo totale std::sort: " << tempo_totale_sort << " s\n";
    
    // TEST STRINGHE
    std::vector<std::string> parole = {
        "zaino", "penna", "gomma", "matita", "acqua", 
        "forchetta", "pranzo", "quaderno", "libro", "bottiglia"
    };

    mergeSort(parole.data(), 0, (int)parole.size() - 1);

    std::cout << "Parole ordinate: ";
    for (const auto& s : parole) std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}